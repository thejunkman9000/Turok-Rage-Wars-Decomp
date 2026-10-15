// F3DEX2 display-list renderer for Direct3D 11.
// The game's RSP task (g_gfx_task) is captured by os_shim.c; every frame we walk its display list here and draw into an
// offscreen render target of INTERNAL_W x INTERNAL_H (independent of the N64's 480x360), then blit it letterboxed to the window.
// RDP state (tiles, TMEM, combiner, othermode) is tracked on the CPU; textures are decoded from an emulated TMEM into RGBA8.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <unordered_map>
#include <vector>
#pragma comment(lib, "d3dcompiler.lib")

extern "C" int port_scripted(void);      // game_glue.c: started by a test script (TUROK_SCRIPT=1): command / trigger files are polled only then
extern "C" unsigned char g_gfx_task[];
extern "C" volatile long g_gfx_task_ready;
extern "C" unsigned char* g_gfx_snap; extern "C" volatile long g_gfx_snap_valid;      // os_shim.c: RDRAM copy taken when the task was submitted (normal speed only)
extern "C" { CRITICAL_SECTION g_snap_lock; int g_snap_lock_ready; }                 // held while a task is captured and while its list is walked
static const uint8_t* g_snapNow;                                                     // the copy the current frame reads from, or null for live memory
extern "C" void port_dump_threads(void); extern "C" void port_dump_trace_pub(int);      // os_shim.c / game_glue.c: thread states and wait queues (printed on the port_dumpnow trigger)

static const int INTERNAL_W = 1920, INTERNAL_H = 1440;   // 4:3, 4x the N64 frame (480x360)
static float SCREEN_W = 480.f, SCREEN_H = 360.f;      // the game switches the colour image width between screens (480 in matches, 284 in menus): follows SETCIMG

static ID3D11Device* dev; static ID3D11DeviceContext* ctx;
static ID3D11Texture2D* rtTex; static ID3D11RenderTargetView* rtv; static ID3D11ShaderResourceView* rtSrv;
static ID3D11Texture2D* dsTex; static ID3D11DepthStencilView* dsv;
static ID3D11VertexShader* vs; static ID3D11PixelShader* ps; static ID3D11InputLayout* layout;
static ID3D11VertexShader* blitVs; static ID3D11PixelShader* blitPs;
static ID3D11Buffer* vbuf; static ID3D11Buffer* cbuf;
static ID3D11BlendState *bsOpaque, *bsAlpha, *bsNoColor;     // bsNoColor: colour writes off (partial depth clears)
static ID3D11DepthStencilState* dss[4];     // [test][write]
static ID3D11DepthStencilState* dssClear;   // always pass, write depth: a far-plane quad clears part of the z-buffer
static int g_zclear;                        // flush() is drawing such a quad
static ID3D11RasterizerState* rs;
static ID3D11SamplerState* samplers[2][3][3];
static ID3D11ShaderResourceView* whiteSrv;
static bool ready = false;

static uint32_t rd32(const uint8_t* p) { return _byteswap_ulong(*(const uint32_t*)p); }
static uint16_t rd16(const uint8_t* p) { return _byteswap_ushort(*(const uint16_t*)p); }

// ---------------------------------------------------------------------------------------------------------- shaders
static const char* HLSL = R"(
cbuffer CB : register(b0) {
    uint4 c0; uint4 a0; uint4 c1; uint4 a1;     // combiner inputs per cycle: (A,B,C,D)
    float4 prim; float4 env; float4 flags;      // flags: x=mode (0 combiner,1 vertex colour,2 copy) y=2-cycle z=alpha test w=texture on
    float4 fogc; float4 fogp;                   // fogc = fog colour; fogp.x = 1 when the blender's first cycle is (fog colour * factor + colour * (1 - factor)), fogp.y = 1: the factor is the fog colour's alpha instead of the shade alpha
};
Texture2D tex : register(t0); Texture2D tex1 : register(t1); SamplerState smp : register(s0);
struct VI { float4 pos : POSITION; float4 col : COLOR; float2 uv : TEXCOORD; };
struct PI { float4 pos : SV_POSITION; float4 col : COLOR; float2 uv : TEXCOORD; };
PI vsmain(VI i) { PI o; o.pos = i.pos; o.col = i.col; o.uv = i.uv; return o; }
float3 selA(uint s, float3 cb, float3 t0, float3 t1, float3 pr, float3 sh, float3 en) { return s==0?cb : s==1?t0 : s==2?t1 : s==3?pr : s==4?sh : s==5?en : s==6?float3(1,1,1) : s==7?float3(0.5,0.5,0.5) : float3(0,0,0); }
float3 selB(uint s, float3 cb, float3 t0, float3 t1, float3 pr, float3 sh, float3 en) { return s==0?cb : s==1?t0 : s==2?t1 : s==3?pr : s==4?sh : s==5?en : float3(0,0,0); }
float3 selC(uint s, float3 cb, float ca, float3 t0, float t0a, float3 t1, float t1a, float3 pr, float pra, float3 sh, float sha, float3 en, float ena) {
    return s==0?cb : s==1?t0 : s==2?t1 : s==3?pr : s==4?sh : s==5?en : s==7?float3(ca,ca,ca) : s==8?float3(t0a,t0a,t0a) : s==9?float3(t1a,t1a,t1a)
         : s==10?float3(pra,pra,pra) : s==11?float3(sha,sha,sha) : s==12?float3(ena,ena,ena) : float3(0,0,0); }
float3 selD(uint s, float3 cb, float3 t0, float3 t1, float3 pr, float3 sh, float3 en) { return s==0?cb : s==1?t0 : s==2?t1 : s==3?pr : s==4?sh : s==5?en : s==6?float3(1,1,1) : float3(0,0,0); }
float selAa(uint s, float ca, float t0a, float t1a, float pra, float sha, float ena) { return s==0?ca : s==1?t0a : s==2?t1a : s==3?pra : s==4?sha : s==5?ena : s==6?1.0 : 0.0; }
float selAc(uint s, float t0a, float t1a, float pra, float sha, float ena) { return s==1?t0a : s==2?t1a : s==3?pra : s==4?sha : s==5?ena : 0.0; }
float4 cycle(uint4 c, uint4 a, float4 comb, float4 t0, float4 t1, float4 sh) {
    float3 A = selA(c.x, comb.rgb, t0.rgb, t1.rgb, prim.rgb, sh.rgb, env.rgb);
    float3 B = selB(c.y, comb.rgb, t0.rgb, t1.rgb, prim.rgb, sh.rgb, env.rgb);
    float3 C = selC(c.z, comb.rgb, comb.a, t0.rgb, t0.a, t1.rgb, t1.a, prim.rgb, prim.a, sh.rgb, sh.a, env.rgb, env.a);
    float3 D = selD(c.w, comb.rgb, t0.rgb, t1.rgb, prim.rgb, sh.rgb, env.rgb);
    float aA = selAa(a.x, comb.a, t0.a, t1.a, prim.a, sh.a, env.a);
    float aB = selAa(a.y, comb.a, t0.a, t1.a, prim.a, sh.a, env.a);
    float aC = selAc(a.z, t0.a, t1.a, prim.a, sh.a, env.a);
    float aD = selAa(a.w, comb.a, t0.a, t1.a, prim.a, sh.a, env.a);
    return saturate(float4((A - B) * C + D, (aA - aB) * aC + aD));
}
float4 psmain(PI i) : SV_TARGET {
    float4 t0 = flags.w > 0.5 ? tex.Sample(smp, i.uv) : float4(1,1,1,1);
    float4 t1 = flags.w > 0.5 ? tex1.Sample(smp, i.uv) : float4(1,1,1,1);
    float4 o;
    if (flags.x > 1.5) o = t0;
    else if (flags.x > 0.5) o = i.col;
    else {
        o = cycle(c0, a0, float4(0,0,0,0), t0, t1, i.col);
        if (flags.y > 0.5) o = cycle(c1, a1, o, t0, t1, i.col);
    }
    if (fogp.x > 0.5 && flags.x < 1.5) o.rgb = lerp(o.rgb, fogc.rgb, fogp.y > 0.5 ? fogc.a : i.col.a);      // G_RM_FOG_SHADE_A / G_RM_FOG_PRIM_A: the fog factor is the vertex alpha the RSP replaced (G_FOG)
    if (o.a < flags.z) discard;
    return o;
}
struct BO { float4 pos : SV_POSITION; float2 uv : TEXCOORD; };
BO blitvs(uint id : SV_VertexID) { BO o; float2 p = float2((id << 1) & 2, id & 2); o.uv = p; o.pos = float4(p * float2(2, -2) + float2(-1, 1), 0, 1); return o; }
float4 blitps(BO i) : SV_TARGET { return tex.Sample(smp, i.uv); }
)";

struct Vtx { float x, y, z, w; float r, g, b, a; float u, v; };

static ID3DBlob* compile(const char* entry, const char* prof) {
    ID3DBlob *code = nullptr, *err = nullptr;
    HRESULT hr = D3DCompile(HLSL, strlen(HLSL), "turok.hlsl", nullptr, nullptr, entry, prof, 0, 0, &code, &err);
    if (FAILED(hr)) { FILE* lf = fopen("port_render.txt", "a"); if (lf) { fprintf(lf, "HLSL %s failed: %s\n", entry, err ? (char*)err->GetBufferPointer() : "?"); fclose(lf); } return nullptr; }
    if (err) err->Release();
    return code;
}

extern "C" void renderer_init(ID3D11Device* d, ID3D11DeviceContext* c) {
    dev = d; ctx = c;
    D3D11_TEXTURE2D_DESC td = {}; td.Width = INTERNAL_W; td.Height = INTERNAL_H; td.MipLevels = 1; td.ArraySize = 1; td.SampleDesc.Count = 1;
    td.Format = DXGI_FORMAT_R8G8B8A8_UNORM; td.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
    dev->CreateTexture2D(&td, nullptr, &rtTex); dev->CreateRenderTargetView(rtTex, nullptr, &rtv); dev->CreateShaderResourceView(rtTex, nullptr, &rtSrv);
    td.Format = DXGI_FORMAT_D32_FLOAT; td.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    dev->CreateTexture2D(&td, nullptr, &dsTex); dev->CreateDepthStencilView(dsTex, nullptr, &dsv);
    ID3DBlob* b;
    if (!(b = compile("vsmain", "vs_4_0"))) return;
    dev->CreateVertexShader(b->GetBufferPointer(), b->GetBufferSize(), nullptr, &vs);
    D3D11_INPUT_ELEMENT_DESC el[] = { {"POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
                                      {"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0},
                                      {"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 32, D3D11_INPUT_PER_VERTEX_DATA, 0} };
    dev->CreateInputLayout(el, 3, b->GetBufferPointer(), b->GetBufferSize(), &layout); b->Release();
    if (!(b = compile("psmain", "ps_4_0"))) return; dev->CreatePixelShader(b->GetBufferPointer(), b->GetBufferSize(), nullptr, &ps); b->Release();
    if (!(b = compile("blitvs", "vs_4_0"))) return; dev->CreateVertexShader(b->GetBufferPointer(), b->GetBufferSize(), nullptr, &blitVs); b->Release();
    if (!(b = compile("blitps", "ps_4_0"))) return; dev->CreatePixelShader(b->GetBufferPointer(), b->GetBufferSize(), nullptr, &blitPs); b->Release();
    D3D11_BUFFER_DESC bd = {}; bd.ByteWidth = 3 * 6000 * sizeof(Vtx); bd.Usage = D3D11_USAGE_DYNAMIC; bd.BindFlags = D3D11_BIND_VERTEX_BUFFER; bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    dev->CreateBuffer(&bd, nullptr, &vbuf);
    bd.ByteWidth = 16 * 16; bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER; dev->CreateBuffer(&bd, nullptr, &cbuf);
    D3D11_BLEND_DESC bl = {}; bl.RenderTarget[0].RenderTargetWriteMask = 15; dev->CreateBlendState(&bl, &bsOpaque);
    bl.RenderTarget[0].BlendEnable = TRUE; bl.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA; bl.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    bl.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD; bl.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE; bl.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO; bl.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    dev->CreateBlendState(&bl, &bsAlpha);
    bl = {}; bl.RenderTarget[0].RenderTargetWriteMask = 0; dev->CreateBlendState(&bl, &bsNoColor);
    for (int t = 0; t < 2; t++) for (int w = 0; w < 2; w++) {
        D3D11_DEPTH_STENCIL_DESC dd = {}; dd.DepthEnable = t; dd.DepthWriteMask = w ? D3D11_DEPTH_WRITE_MASK_ALL : D3D11_DEPTH_WRITE_MASK_ZERO; dd.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
        dev->CreateDepthStencilState(&dd, &dss[t * 2 + w]);
    }
    { D3D11_DEPTH_STENCIL_DESC dd = {}; dd.DepthEnable = TRUE; dd.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL; dd.DepthFunc = D3D11_COMPARISON_ALWAYS; dev->CreateDepthStencilState(&dd, &dssClear); }
    D3D11_RASTERIZER_DESC rd = {}; rd.FillMode = D3D11_FILL_SOLID; rd.CullMode = D3D11_CULL_NONE; rd.DepthClipEnable = TRUE; rd.ScissorEnable = TRUE; dev->CreateRasterizerState(&rd, &rs);
    static const D3D11_TEXTURE_ADDRESS_MODE am[3] = { D3D11_TEXTURE_ADDRESS_WRAP, D3D11_TEXTURE_ADDRESS_MIRROR, D3D11_TEXTURE_ADDRESS_CLAMP };
    for (int f = 0; f < 2; f++) for (int u = 0; u < 3; u++) for (int v = 0; v < 3; v++) {
        D3D11_SAMPLER_DESC sd = {}; sd.Filter = f ? D3D11_FILTER_MIN_MAG_MIP_LINEAR : D3D11_FILTER_MIN_MAG_MIP_POINT; sd.AddressU = am[u]; sd.AddressV = am[v]; sd.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
        sd.MaxLOD = D3D11_FLOAT32_MAX; sd.ComparisonFunc = D3D11_COMPARISON_NEVER; dev->CreateSamplerState(&sd, &samplers[f][u][v]);
    }
    uint32_t white = 0xFFFFFFFF; D3D11_SUBRESOURCE_DATA sr = { &white, 4, 4 }; td = {}; td.Width = td.Height = 1; td.MipLevels = td.ArraySize = 1; td.SampleDesc.Count = 1; td.Format = DXGI_FORMAT_R8G8B8A8_UNORM; td.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    ID3D11Texture2D* wt; dev->CreateTexture2D(&td, &sr, &wt); dev->CreateShaderResourceView(wt, nullptr, &whiteSrv); wt->Release();
    float black[4] = { 0, 0, 0, 1 }; ctx->ClearRenderTargetView(rtv, black); ctx->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH, 1.f, 0);
    InitializeCriticalSection(&g_snap_lock); g_snap_lock_ready = 1;
    ready = vs && ps && blitVs && blitPs && vbuf && cbuf; fprintf(stderr, "renderer: init %s\n", ready ? "ok" : "FAILED"); fflush(stderr);
}

// ---------------------------------------------------------------------------------------------------------- RDP / RSP state
static uint32_t segbase[16];
static int vtxlog_on() { static int v = -1; if (v < 0) v = getenv("TUROK_VTXLOG") ? 1 : 0; return v; }   // cached: this used to be a getenv per vertex command
static uint8_t g_zero[1 << 16];                                       // stands in for display-list addresses that do not point at guest memory
static const uint8_t* res(uint32_t a) {
    if (!(a & 0x80000000u)) a = 0x80000000u | (segbase[(a >> 24) & 0xF] + (a & 0xFFFFFF));
    if (a >= 0x80000000u && a < 0x80800000u) return g_snapNow ? g_snapNow + (a - 0x80000000u) : (const uint8_t*)(size_t)a;
    return g_zero;                                                       // garbage pointer (e.g. an object not initialised yet): read zeros instead of crashing
}
static int g_pickN, g_pickX[16], g_pickY[16], g_pickLeft;      // pixel picking (port_pick.txt): see emitTri
struct Tile { int fmt, siz, line, tmem, pal, cmT, maskT, shiftT, cmS, maskS, shiftS, uls, ult, lrs, lrt; };
struct Light { float r, g, b; float dx, dy, dz; };
struct V { float cx, cy, cz, cw; float r, g, b, a; float s, t; float wx, wy, wz; uint32_t ts, tt; short mx, my, mz; };      // ts/tt: G_TEXTURE scale in effect when the vertex was loaded (the RSP scales s/t at load time)
static struct {
    uint32_t geom, omL, omH, combW0, combW1;
    uint32_t cimg, zimg, timg, timgW; int timgFmt, timgSiz;
    uint32_t fill; float prim[4], env[4];
    Tile tile[8]; uint8_t tmem[4096]; int tluts;
    float mv[10][16]; int mvTop; float proj[16]; float mvp[16]; bool mvpDirty; float camInv[16]; bool camSet;
    int sc[4]; float vsc[4], vtr[4]; int numLights; Light lights[10]; uint8_t lightRaw[12][16];
    uint32_t texScaleS, texScaleT; int texTile, texOn;
    V vtx[64];
    bool dirty;
} S;
static std::vector<Vtx> batch;
static uint32_t curTexSrvKey; static ID3D11ShaderResourceView* curSrv; static ID3D11SamplerState* curSmp;
static std::map<uint64_t, ID3D11ShaderResourceView*> texCache;
static int g_rects, g_nfpub; static FILE* g_dump; static int g_tris, g_draws, g_texdecodes; static int g_ops[256]; static int g_opsIgnored[256]; static int g_fogBlendDraws; static std::map<uint64_t, int> g_fogHist;
static int g_fogMul, g_fogOff; static float g_fogCol[4] = { 0, 0, 0, 1 };      // G_MW_FOG (fm, fo) and G_SETFOGCOLOR: the RSP/RDP keep them across frames, so they live outside S (memset every frame)
static bool fogOn() {      // TUROK_NOFOG=1: fog off; TUROK_FOGAB=1: fog on in even renderer frames, off in odd ones (the same scene twice for A/B comparison)
    static int nofog = -1, ab = -1; if (nofog < 0) { nofog = getenv("TUROK_NOFOG") ? 1 : 0; ab = getenv("TUROK_FOGAB") ? 1 : 0; }
    return !nofog && !(ab && (g_nfpub & 1));
}
static int g_zmodeDraws[4]; static int g_vtxGeom[4]; static std::map<uint32_t, int> g_omHHist; static int g_texDraws, g_noPerspDraws, g_lodDraws, g_detailDraws;   // textured draws; of which without texture perspective (omH bit 19), with texture LOD (bit 16), with detail/sharpen (bits 17-18)
// vertices loaded with texgen (0x40000) / texgen linear (0x80000) / fog (0x10000) / lighting (0x20000) set; draws per RDP z-mode (0 opaque, 1 interpenetrating, 2 translucent, 3 decal)

static void matIdent(float* m) { memset(m, 0, 64); m[0] = m[5] = m[10] = m[15] = 1; }
static void matMul(const float* a, const float* b, float* o) {    // row-vector convention: o = a * b
    float t[16];
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) t[i * 4 + j] = a[i * 4] * b[j] + a[i * 4 + 1] * b[4 + j] + a[i * 4 + 2] * b[8 + j] + a[i * 4 + 3] * b[12 + j];
    memcpy(o, t, 64);
}
static void loadMtx(const uint8_t* p, float* m) {
    for (int i = 0; i < 16; i++) { int16_t ip = (int16_t)rd16(p + i * 2); uint16_t fp = rd16(p + 32 + i * 2); m[i] = ip + fp / 65536.f; }
}

// ---- texture decode from TMEM
static void tlutEntry(int idx, uint8_t* o) {
    uint16_t v = _byteswap_ushort(*(uint16_t*)&S.tmem[(0x800 + idx * 8) & 0xFFE]);
    if (S.tluts == 3) { o[0] = o[1] = o[2] = v >> 8; o[3] = v & 0xFF; }
    else { o[0] = ((v >> 11) & 31) * 255 / 31; o[1] = ((v >> 6) & 31) * 255 / 31; o[2] = ((v >> 1) & 31) * 255 / 31; o[3] = (v & 1) ? 255 : 0; }
}
static void decodeTexel(const Tile& t, int x, int y, uint8_t* o) {
    int lineBytes = t.line * 8, row = t.tmem * 8 + y * lineBytes, swap = (y & 1) ? 4 : 0;
    auto B = [&](int a) { return S.tmem[((a ^ swap)) & 0xFFF]; };
    if (t.siz == 2) {
        uint16_t v = (B(row + x * 2) << 8) | B(row + x * 2 + 1);
        if (t.fmt == 0) { o[0] = ((v >> 11) & 31) * 255 / 31; o[1] = ((v >> 6) & 31) * 255 / 31; o[2] = ((v >> 1) & 31) * 255 / 31; o[3] = (v & 1) ? 255 : 0; }
        else if (t.fmt == 3) { o[0] = o[1] = o[2] = v >> 8; o[3] = v & 0xFF; }
        else if (t.fmt == 2) tlutEntry(v & 0xFF, o);
        else { o[0] = o[1] = o[2] = v >> 8; o[3] = 255; }
    } else if (t.siz == 3) {
        int a = (row + x * 2) ^ swap;
        o[0] = S.tmem[a & 0x7FF]; o[1] = S.tmem[(a + 1) & 0x7FF]; o[2] = S.tmem[(a + 0x800) & 0xFFF]; o[3] = S.tmem[(a + 0x801) & 0xFFF];
    } else if (t.siz == 1) {
        uint8_t v = B(row + x);
        if (t.fmt == 2) tlutEntry(v, o);
        else if (t.fmt == 3) { o[0] = o[1] = o[2] = (v >> 4) * 17; o[3] = (v & 15) * 17; }
        else { o[0] = o[1] = o[2] = o[3] = v; }
    } else {
        uint8_t b = B(row + (x >> 1)); int n = (x & 1) ? (b & 15) : (b >> 4);
        if (t.fmt == 2) tlutEntry(t.pal * 16 + n, o);
        else if (t.fmt == 3) { o[0] = o[1] = o[2] = (n >> 1) * 255 / 7; o[3] = (n & 1) ? 255 : 0; }
        else { o[0] = o[1] = o[2] = o[3] = n * 17; }
    }
}
static void tileDims(const Tile& t, int& w, int& h) {
    w = ((t.lrs - t.uls) >> 2) + 1; h = ((t.lrt - t.ult) >> 2) + 1;
    if (t.maskS && (1 << t.maskS) > w) w = 1 << t.maskS;
    if (t.maskT && (1 << t.maskT) > h) h = 1 << t.maskT;
    if (w < 1) w = 1; if (h < 1) h = 1; if (w > 1024) w = 1024; if (h > 1024) h = 1024;
}
static std::map<ID3D11ShaderResourceView*, uint64_t> srvKey;
static int capOn();
static void capTexture(uint64_t key, const std::vector<uint8_t>& px, int w, int h);
static ID3D11ShaderResourceView* getTexture(const Tile& t, int w, int h) {
    uint64_t key = 1469598103934665603ull;
    auto mix = [&](uint64_t v) { key = (key ^ v) * 1099511628211ull; };
    mix(t.fmt); mix(t.siz); mix(t.line); mix(w); mix(h); mix(t.pal); mix(S.tluts);
    int bytes = t.line * 8 * h + 8; if (t.tmem * 8 + bytes > 4096) bytes = 4096 - t.tmem * 8;
    for (int i = 0; i < bytes; i++) mix(S.tmem[t.tmem * 8 + i]);
    if (t.fmt == 2) { int n = t.siz == 0 ? 16 : 256; for (int i = 0; i < n * 8; i++) mix(S.tmem[0x800 + (t.siz == 0 ? t.pal * 128 : 0) + i]); }
    auto it = texCache.find(key); if (it != texCache.end()) return it->second;
    std::vector<uint8_t> px((size_t)w * h * 4);
    for (int y = 0; y < h; y++) for (int x = 0; x < w; x++) decodeTexel(t, x, y, &px[((size_t)y * w + x) * 4]);
    { static int nl; if (nl++ < 12) { long sum = 0, nz = 0; for (size_t i = 0; i < px.size(); i += 4) { sum += px[i] + px[i + 1] + px[i + 2]; nz += px[i + 3] != 0; } fprintf(stderr, "texture %dx%d fmt %d siz %d line %d tmem %d: rgb sum %ld, opaque texels %ld\n", w, h, t.fmt, t.siz, t.line, t.tmem, sum, nz); fflush(stderr); } }
    { static int tl = -1, tln; if (tl < 0) tl = getenv("TUROK_TEXLOG") ? 1 : 0; if (tl && tln++ < 600) fprintf(stderr, "texdecode %dx%d fmt %d siz %d line %d tmem %d pal %d uls %d lrs %d ult %d lrt %d timg %08X\n", w, h, t.fmt, t.siz, t.line, t.tmem, t.pal, t.uls, t.lrs, t.ult, t.lrt, S.timg); }
    { static int nd; static int seen; static int only8 = getenv("TUROK_TEXDUMP8") != nullptr; static int big = getenv("TUROK_TEXDUMPBIG") != nullptr; static int wh_w = 0, wh_h = 0, wh_init = 0; if (!wh_init) { wh_init = 1; const char* e = getenv("TUROK_TEXDUMPWH"); if (e) sscanf(e, "%dx%d", &wh_w, &wh_h); } if (wh_w ? (w == wh_w && h == wh_h && nd < 40) : big ? (w >= 32 && h >= 16 && w != 288 && nd < 80) : only8 ? (w == 16 && h == 8 && nd < 12) : (nd < 80 && seen++ >= atoi(getenv("TUROK_TEXDUMP") ? getenv("TUROK_TEXDUMP") : "999999"))) { char fn[64]; fprintf(stderr, "texdump %d: %dx%d fmt %d siz %d line %d tmem %d pal %d uls %d lrs %d ult %d lrt %d maskS %d maskT %d timgW %d timgSiz %d key %llx\n", nd, w, h, t.fmt, t.siz, t.line, t.tmem, t.pal, t.uls, t.lrs, t.ult, t.lrt, t.maskS, t.maskT, S.timgW, S.timgSiz, (unsigned long long)key); sprintf(fn, "port/build/tex_%d.ppm", nd++); FILE* f = fopen(fn, "wb"); if (f) { fprintf(f, "P6 %d %d 255 ", w, h); for (size_t i = 0; i < px.size(); i += 4) fwrite(&px[i], 1, 3, f); fclose(f); } } }
    { static const char* ks = getenv("TUROK_TEXDUMPKEY");      // TUROK_TEXDUMPKEY=<hex key>[:<hex key>...]: write port/build/key_<key>.ppm for those cache keys (keys are printed by the PICK / UVLOG lines)
      if (ks) { char kb[32]; sprintf(kb, "%llx", (unsigned long long)key); if (strstr(ks, kb)) { char fn[96]; sprintf(fn, "port/build/key_%llx.ppm", (unsigned long long)key); FILE* f = fopen(fn, "wb"); if (f) { fprintf(f, "P6 %d %d 255 ", w, h); for (size_t i = 0; i < px.size(); i += 4) fwrite(&px[i], 1, 3, f); fclose(f); fprintf(stderr, "texdump key %llx: %dx%d fmt %d siz %d -> %s\n", (unsigned long long)key, w, h, t.fmt, t.siz, fn); } } } }
    D3D11_TEXTURE2D_DESC td = {}; td.Width = w; td.Height = h; td.MipLevels = td.ArraySize = 1; td.SampleDesc.Count = 1; td.Format = DXGI_FORMAT_R8G8B8A8_UNORM; td.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    D3D11_SUBRESOURCE_DATA sr = { px.data(), (UINT)w * 4, 0 }; ID3D11Texture2D* tx = nullptr; ID3D11ShaderResourceView* sv = nullptr;
    if (SUCCEEDED(dev->CreateTexture2D(&td, &sr, &tx))) { dev->CreateShaderResourceView(tx, nullptr, &sv); tx->Release(); }
    if (texCache.size() > 4000) { for (auto& kv : texCache) if (kv.second) kv.second->Release(); texCache.clear(); }
    texCache[key] = sv; if (sv) srvKey[sv] = key; if (capOn()) capTexture(key, px, w, h); g_texdecodes++; return sv;
}

// ---- batching
struct DState { uint32_t geom, omL, omH, cw0, cw1; float prim[4], env[4]; int mode; ID3D11ShaderResourceView* srv; ID3D11ShaderResourceView* srv1; ID3D11SamplerState* smp; bool texOn; int dbg[16]; };      // dbg: tile parameters for TUROK_UVLOG (addrU addrV w h uls ult lrs lrt maskS maskT cmS cmT fmt siz line texTile)
static DState cur; static bool curValid; static int curTexW = 1, curTexH = 1;

static void flush() {
    { static int once; if (!once++) { fprintf(stderr, "debug switches: notri=%d norect=%d\n", getenv("TUROK_NOTRI") != nullptr, getenv("TUROK_NORECT") != nullptr); fflush(stderr); } }
    if (batch.empty() || !ready) { batch.clear(); return; }
    { static int drawmax = -2; if (drawmax == -2) { const char* e = getenv("TUROK_DRAWMAX"); drawmax = e ? atoi(e) : -1; } if (drawmax >= 0 && g_draws >= drawmax) { batch.clear(); return; } }   // TUROK_DRAWMAX=n: only the first n draw calls of each frame (bisecting what blackens a screen)
    uint32_t cw0 = cur.cw0, cw1 = cur.cw1;
    uint32_t cb[16]; float cf[16];
    // combiner fields (see gbi.h GCCc0w0 / GCCc0w1 / GCCc1w0 / GCCc1w1)
    uint32_t a0 = (cw0 >> 20) & 15, c0 = (cw0 >> 15) & 31, Aa0 = (cw0 >> 12) & 7, Ac0 = (cw0 >> 9) & 7, a1 = (cw0 >> 5) & 15, c1 = cw0 & 31;
    uint32_t b0 = (cw1 >> 28) & 15, d0 = (cw1 >> 15) & 7, Ab0 = (cw1 >> 12) & 7, Ad0 = (cw1 >> 9) & 7;
    uint32_t b1 = (cw1 >> 24) & 15, Aa1 = (cw1 >> 21) & 7, Ac1 = (cw1 >> 18) & 7, d1 = (cw1 >> 6) & 7, Ab1 = (cw1 >> 3) & 7, Ad1 = cw1 & 7;
    cb[0] = a0; cb[1] = b0; cb[2] = c0; cb[3] = d0;  cb[4] = Aa0; cb[5] = Ab0; cb[6] = Ac0; cb[7] = Ad0;
    cb[8] = a1; cb[9] = b1; cb[10] = c1; cb[11] = d1; cb[12] = Aa1; cb[13] = Ab1; cb[14] = Ac1; cb[15] = Ad1;
    // the cbuffer layout is uint4 c0, a0, c1, a1, then float4 prim, env, flags
    uint32_t cbData[36];
    memcpy(cbData, cb, 16 * 4);
    float* fl = (float*)(cbData + 16);
    for (int i = 0; i < 4; i++) { fl[i] = cur.prim[i]; fl[4 + i] = cur.env[i]; fl[12 + i] = g_fogCol[i]; }
    { uint32_t L = cur.omL; int m1a = (L >> 30) & 3, m1b = (L >> 26) & 3, m2a = (L >> 22) & 3, m2b = (L >> 18) & 3;      // blender cycle 1: P = CLR_FOG, A = A_SHADE (2) / A_FOG (1), M = CLR_IN, B = 1-A
      bool fogMix = ((cur.omH >> 20) & 3) < 2 && m1a == 3 && (m1b == 2 || m1b == 1) && m2a == 0 && m2b == 0 && fogOn();
      fl[16] = fogMix ? 1.f : 0.f; fl[17] = (m1b == 1) ? 1.f : 0.f; fl[18] = fl[19] = 0.f; }
    int cycle = (cur.omH >> 20) & 3;
    fl[8] = (float)cur.mode; fl[9] = (cycle == 1) ? 1.f : 0.f;
    { static int no2 = -1; if (no2 < 0) no2 = getenv("TUROK_NO2CYC") ? 1 : 0; if (no2) fl[9] = 0.f; }   // TUROK_NO2CYC=1: run 2-cycle combiners as 1-cycle (bisecting shader paths)
    float thr = -1.f;
    if (cycle == 2) thr = 0.01f;
    else if ((cur.omL & 3) == 1) thr = 0.5f;
    else if (cur.omL & 0x3000) thr = 0.3f;
    if (cur.omL & 0x4000) thr = (thr > 0) ? 0.02f : -1.f;
    if (g_zclear) thr = -1.f;
    fl[10] = thr; fl[11] = cur.texOn ? 1.f : 0.f;
    D3D11_MAPPED_SUBRESOURCE m;
    ctx->Map(cbuf, 0, D3D11_MAP_WRITE_DISCARD, 0, &m); memcpy(m.pData, cbData, sizeof(cbData)); ctx->Unmap(cbuf, 0);
    ctx->Map(vbuf, 0, D3D11_MAP_WRITE_DISCARD, 0, &m); memcpy(m.pData, batch.data(), batch.size() * sizeof(Vtx)); ctx->Unmap(vbuf, 0);
    bool zb = (cur.geom & 1) != 0, zcmp = (cur.omL & 0x10) != 0, zupd = (cur.omL & 0x20) != 0;
    bool blend = (cur.omL & 0x4000) != 0 && cycle < 2;
    ctx->OMSetDepthStencilState(g_zclear ? dssClear : dss[((zb && zcmp) ? 2 : 0) + ((zb && zupd) ? 1 : 0)], 0);
    ctx->OMSetBlendState(g_zclear ? bsNoColor : (blend ? bsAlpha : bsOpaque), nullptr, 0xFFFFFFFF);
    ctx->PSSetShaderResources(0, 1, cur.texOn && cur.srv ? &cur.srv : &whiteSrv);
    ctx->PSSetShaderResources(1, 1, cur.texOn && cur.srv1 ? &cur.srv1 : (cur.texOn && cur.srv ? &cur.srv : &whiteSrv));
    ctx->PSSetSamplers(0, 1, &cur.smp);
    UINT stride = sizeof(Vtx), off = 0; ctx->IASetVertexBuffers(0, 1, &vbuf, &stride, &off);
    { D3D11_RECT r = { (LONG)(S.sc[0] * INTERNAL_W / (SCREEN_W * 4)), (LONG)(S.sc[1] * INTERNAL_H / (SCREEN_H * 4)), (LONG)(S.sc[2] * INTERNAL_W / (SCREEN_W * 4)), (LONG)(S.sc[3] * INTERNAL_H / (SCREEN_H * 4)) }; ctx->RSSetScissorRects(1, &r); }
    if (g_dump) {   /* one line per draw call in the port_dlnow dump: what was drawn, where, how */
        float x0 = 9, y0 = 9, x1 = -9, y1 = -9, r = 0, g = 0, b = 0, a = 0; for (const Vtx& v : batch) { if (v.x < x0) x0 = v.x; if (v.x > x1) x1 = v.x; if (v.y < y0) y0 = v.y; if (v.y > y1) y1 = v.y; r += v.r; g += v.g; b += v.b; a += v.a; }
        float n = (float)batch.size();
        fprintf(g_dump, "[draw tris=%d ndc %.2f,%.2f-%.2f,%.2f avg rgba %.2f %.2f %.2f %.2f tex=%d%s cw=%06X/%08X omL=%08X omH=%08X geom=%06X cycle=%d prim %.2f %.2f %.2f %.2f env %.2f %.2f %.2f %.2f zb=%d zcmp=%d zupd=%d blend=%d thr=%.2f]\n",
                (int)batch.size() / 3, x0, y0, x1, y1, r / n, g / n, b / n, a / n, cur.texOn ? 1 : 0, (cur.texOn && !cur.srv) ? "(nosrv)" : "", cw0, cw1, cur.omL, cur.omH, cur.geom, cycle,
                cur.prim[0], cur.prim[1], cur.prim[2], cur.prim[3], cur.env[0], cur.env[1], cur.env[2], cur.env[3], zb, zcmp, zupd, blend, thr);
    }
    { static int ul = -1, nul; if (ul < 0) ul = getenv("TUROK_UVLOG") ? 1 : 0;      // TUROK_UVLOG=1: textured draws whose UVs leave the texture on an axis that is clamped (the edge texel streaks)
      static int ulall = -1; if (ulall < 0) { const char* e = getenv("TUROK_UVLOG"); ulall = e ? atoi(e) : 0; }      // TUROK_UVLOG=2: log every textured draw of frame g_nfpub == 595
      if (ulall == 2 && cur.texOn && cur.srv && g_nfpub == 595) {
          float u0 = 1e9f, u1 = -1e9f, v0 = 1e9f, v1 = -1e9f; for (const Vtx& v : batch) { if (v.u < u0) u0 = v.u; if (v.u > u1) u1 = v.u; if (v.v < v0) v0 = v.v; if (v.v > v1) v1 = v.v; }
          const int* d = cur.dbg; fprintf(stderr, "UVDRAW u %.2f..%.2f v %.2f..%.2f tris %d | addr %d/%d tex %dx%d uls %d ult %d lrs %d lrt %d mask %d/%d cm %d/%d fmt %d siz %d line %d tile %d key %llx\n", u0, u1, v0, v1, (int)batch.size() / 3, d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], d[8], d[9], d[10], d[11], d[12], d[13], d[14], d[15], (unsigned long long)srvKey[cur.srv]); }
      if (ul && cur.texOn && cur.srv && nul < 120) {
          float u0 = 1e9f, u1 = -1e9f, v0 = 1e9f, v1 = -1e9f; for (const Vtx& v : batch) { if (v.u < u0) u0 = v.u; if (v.u > u1) u1 = v.u; if (v.v < v0) v0 = v.v; if (v.v > v1) v1 = v.v; }
          const int* d = cur.dbg; bool badU = d[0] == 2 && (u0 < -0.02f || u1 > 1.02f), badV = d[1] == 2 && (v0 < -0.02f || v1 > 1.02f);
          if (badU || badV) { nul++; fprintf(stderr, "UVCLAMP u %.2f..%.2f v %.2f..%.2f tris %d | addr %d/%d tex %dx%d uls %d ult %d lrs %d lrt %d mask %d/%d cm %d/%d fmt %d siz %d line %d tile %d srvkey %llx\n", u0, u1, v0, v1, (int)batch.size() / 3, d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], d[8], d[9], d[10], d[11], d[12], d[13], d[14], d[15], (unsigned long long)srvKey[cur.srv]); } } }
    { static int fl = -1, nfl; if (fl < 0) fl = getenv("TUROK_FOGLOG") ? 1 : 0;      // TUROK_FOGLOG=1: log the render modes of the first draws that have the fog geometry bit set (the renderer has no fog)
      if (fl && (cur.geom & 0x10000) && nfl < 40) { nfl++; fprintf(stderr, "FOGDRAW omL %08X omH %08X cw %08X %08X tris %d tex %d geom %06X\n", cur.omL, cur.omH, cw0, cw1, (int)batch.size() / 3, cur.texOn ? 1 : 0, cur.geom); }
      if (fl && (cur.geom & 0x10000)) g_fogHist[((uint64_t)cur.omL << 32) | (cur.omH & 0x300000) | (cur.texOn ? 1 : 0)] += (int)batch.size() / 3; }
    ctx->Draw((UINT)batch.size(), 0); g_draws++; g_zmodeDraws[(cur.omL >> 10) & 3]++;
    { uint32_t L = cur.omL; int c2 = ((cur.omH >> 20) & 3) == 1; bool fogBl = ((L >> 30) & 3) == 3 || ((L >> 22) & 3) == 3 || ((L >> 26) & 3) == 1 || (c2 && (((L >> 28) & 3) == 3 || ((L >> 20) & 3) == 3 || ((L >> 24) & 3) == 1)); if (fogBl) g_fogBlendDraws++; }
    if (cur.texOn) { g_omHHist[cur.omH]++; g_texDraws++; if (!(cur.omH & (1u << 19))) g_noPerspDraws++; if (cur.omH & (1u << 16)) g_lodDraws++; if (cur.omH & (3u << 17)) g_detailDraws++; }
    batch.clear();
}

static void setupState(int mode) {
    DState n = {}; n.geom = S.geom; n.omL = S.omL; n.omH = S.omH; n.cw0 = S.combW0; n.cw1 = S.combW1; n.mode = mode;
    memcpy(n.prim, S.prim, 16); memcpy(n.env, S.env, 16);
    int cycle = (S.omH >> 20) & 3; if (cycle == 2 && mode == 0) n.mode = 2;
    const Tile& t = S.tile[S.texTile & 7];
    n.texOn = S.texOn != 0 && mode != 1;
    if (n.texOn) {
        int w, h; tileDims(t, w, h); curTexW = w; curTexH = h;
        n.srv = getTexture(t, w, h);
        { uint32_t cw0 = S.combW0, cw1 = S.combW1; uint32_t f[16] = { (cw0 >> 20) & 15, (cw1 >> 28) & 15, (cw0 >> 15) & 31, (cw1 >> 15) & 7, (cw0 >> 12) & 7, (cw1 >> 12) & 7, (cw0 >> 9) & 7, (cw1 >> 9) & 7, (cw0 >> 5) & 15, (cw1 >> 24) & 15, cw0 & 31, (cw1 >> 6) & 7, (cw1 >> 21) & 7, (cw1 >> 3) & 7, (cw1 >> 18) & 7, cw1 & 7 };
          bool uses1 = false; for (int k = 0; k < 16; k++) if (f[k] == 2 || (k == 2 && f[k] == 9) || (k == 10 && f[k] == 9)) uses1 = true;
          if (uses1) { const Tile& t1 = S.tile[(S.texTile + 1) & 7]; int w1, h1; tileDims(t1, w1, h1); n.srv1 = getTexture(t1, w1, h1);
              { static int sl = -1, nsl; if (sl < 0) sl = getenv("TUROK_TEX1LOG") ? 1 : 0;      // TUROK_TEX1LOG=1: draws that sample a second tile (the UV of the first tile is used for both)
                if (sl && nsl < 60) { nsl++; fprintf(stderr, "TEX1 tile0 %dx%d uls %d ult %d lrs %d lrt %d mask %d/%d shift %d/%d cm %d/%d fmt %d siz | tile1 %dx%d uls %d ult %d lrs %d lrt %d mask %d/%d shift %d/%d cm %d/%d fmt %d siz %d | cw %08X %08X\n", w, h, t.uls, t.ult, t.lrs, t.lrt, t.maskS, t.maskT, t.shiftS, t.shiftT, t.cmS, t.cmT, t.fmt, w1, h1, t1.uls, t1.ult, t1.lrs, t1.lrt, t1.maskS, t1.maskT, t1.shiftS, t1.shiftT, t1.cmS, t1.cmT, t1.fmt, t1.siz, S.combW0, S.combW1); } } } else n.srv1 = nullptr; }
        int f = ((S.omH >> 12) & 3) != 0;
        int u = t.maskS == 0 ? 2 : (t.cmS & 2) ? 2 : (t.cmS & 1) ? 1 : 0, v = t.maskT == 0 ? 2 : (t.cmT & 2) ? 2 : (t.cmT & 1) ? 1 : 0;
        n.smp = samplers[f][u][v];
        { int d[16] = { u, v, w, h, t.uls, t.ult, t.lrs, t.lrt, t.maskS, t.maskT, t.cmS, t.cmT, t.fmt, t.siz, t.line, S.texTile & 7 }; memcpy(n.dbg, d, sizeof d); }
    } else n.smp = samplers[0][2][2];
    bool same = curValid && cur.geom == n.geom && cur.omL == n.omL && cur.omH == n.omH && cur.cw0 == n.cw0 && cur.cw1 == n.cw1 && cur.mode == n.mode &&
                !memcmp(cur.prim, n.prim, 16) && !memcmp(cur.env, n.env, 16) && cur.srv == n.srv && cur.srv1 == n.srv1 && cur.smp == n.smp && cur.texOn == n.texOn;
    if (!same) { flush(); cur = n; curValid = true; }
}


// ---- map capture (TUROK_MAPDUMP=1): accumulates the static world triangles of every frame (world space = vertex * modelview * inverse(first
// modelview load after the projection load), i.e. the camera matrix undone) and, when port_mapdump.txt appears (its first line is the
// output name), writes mapdump/<name>/map.obj + map.mtl (textures in mapdump/tex_*.tga).  A triangle is exported once it was seen in
// >= TUROK_MAPSEEN (default 3) frames at the same world position, which drops moving actors and the first-person weapon.
// port_mapreset.txt clears the accumulated triangles.
struct CapTri { float p[3][3]; float uv[3][2]; uint8_t c[3][4]; uint64_t tex; int seen; int lastFrame; };
static std::unordered_map<uint64_t, CapTri> capTris;
static bool g_frameCamSet; static float g_frameCam[3];
static int capOn() { static int v = -1; if (v < 0) v = getenv("TUROK_MAPDUMP") ? 1 : 0; return v; }
static bool matInv(const float* m, float* o) {
    double a[4][8];
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) { a[i][j] = m[i * 4 + j]; a[i][4 + j] = i == j; }
    for (int c = 0; c < 4; c++) {
        int piv = c; for (int r = c + 1; r < 4; r++) if (fabs(a[r][c]) > fabs(a[piv][c])) piv = r;
        if (fabs(a[piv][c]) < 1e-12) return false;
        if (piv != c) for (int j = 0; j < 8; j++) std::swap(a[c][j], a[piv][j]);
        double d = a[c][c]; for (int j = 0; j < 8; j++) a[c][j] /= d;
        for (int r = 0; r < 4; r++) if (r != c) { double f = a[r][c]; for (int j = 0; j < 8; j++) a[r][j] -= f * a[c][j]; }
    }
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) o[i * 4 + j] = (float)a[i][4 + j];
    return true;
}
static void capTexture(uint64_t key, const std::vector<uint8_t>& px, int w, int h) {
    CreateDirectoryA("mapdump", nullptr);
    char fn[96]; sprintf(fn, "mapdump/tex_%016llx.tga", (unsigned long long)key);
    FILE* f = fopen(fn, "wb"); if (!f) return;
    uint8_t hd[18] = { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, (uint8_t)(w & 255), (uint8_t)(w >> 8), (uint8_t)(h & 255), (uint8_t)(h >> 8), 32, 0x28 };   // top-left origin, BGRA
    fwrite(hd, 1, 18, f);
    for (size_t i = 0; i < px.size(); i += 4) { uint8_t q[4] = { px[i + 2], px[i + 1], px[i], px[i + 3] }; fwrite(q, 1, 4, f); }
    fclose(f);
}
static float g_uvFs = 1.f, g_uvFt = 1.f;      // tile shift fields as coordinate scales (RDP: s >> shift for shift 0..10, s << (16 - shift) for 11..15); set before the vertices / the rectangle of a draw are pushed
static float shiftFactor(int sh) { return sh == 0 ? 1.f : sh <= 10 ? 1.f / (float)(1 << sh) : (float)(1 << (16 - sh)); }
static void capRecord(const V* v[3], ID3D11ShaderResourceView* srv, float tw, float th, float uls, float ult, int frame) {
    CapTri t; memset(&t, 0, sizeof t);
    uint64_t h = 1469598103934665603ull;
    for (int i = 0; i < 3; i++) {
        t.p[i][0] = v[i]->wx; t.p[i][1] = v[i]->wy; t.p[i][2] = v[i]->wz;
        t.uv[i][0] = (v[i]->s / 32.f * g_uvFs - uls / 4.f) / tw; t.uv[i][1] = (v[i]->t / 32.f * g_uvFt - ult / 4.f) / th;      // v->s/t are final S10.5 (scaled at vertex load)
        t.c[i][0] = (uint8_t)(v[i]->r * 255.f + .5f); t.c[i][1] = (uint8_t)(v[i]->g * 255.f + .5f); t.c[i][2] = (uint8_t)(v[i]->b * 255.f + .5f); t.c[i][3] = (uint8_t)(v[i]->a * 255.f + .5f);
        for (int k = 0; k < 3; k++) h = (h ^ (uint64_t)(int64_t)lroundf(t.p[i][k] * 4.f)) * 1099511628211ull;
    }
    auto sk = srvKey.find(srv); t.tex = sk == srvKey.end() ? 0 : sk->second;
    h = (h ^ t.tex) * 1099511628211ull;
    auto it = capTris.find(h);
    if (it == capTris.end()) { t.seen = 1; t.lastFrame = frame; capTris[h] = t; }
    else if (it->second.lastFrame != frame) { it->second.seen++; it->second.lastFrame = frame; }
}
static void capWrite(const char* name) {
    static int minSeen = -1; if (minSeen < 0) { const char* e = getenv("TUROK_MAPSEEN"); minSeen = e ? atoi(e) : 3; }
    char dir[160]; CreateDirectoryA("mapdump", nullptr); sprintf(dir, "mapdump/%s", name); CreateDirectoryA(dir, nullptr);
    char fn[220]; sprintf(fn, "%s/map.obj", dir); FILE* o = fopen(fn, "w"); sprintf(fn, "%s/map.mtl", dir); FILE* m = fopen(fn, "w");
    if (!o || !m) { if (o) fclose(o); if (m) fclose(m); return; }
    fprintf(o, "mtllib map.mtl\n");
    std::map<uint64_t, std::vector<const CapTri*>> byTex; size_t n = 0;
    for (auto& kv : capTris) if (kv.second.seen >= minSeen) { byTex[kv.second.tex].push_back(&kv.second); n++; }
    int nv = 0;
    for (auto& g : byTex) {
        fprintf(m, "newmtl t%016llx\nKd 1 1 1\nmap_Kd ../tex_%016llx.tga\nmap_d ../tex_%016llx.tga\n\n", (unsigned long long)g.first, (unsigned long long)g.first, (unsigned long long)g.first);
        fprintf(o, "g t%016llx\nusemtl t%016llx\n", (unsigned long long)g.first, (unsigned long long)g.first);
        for (const CapTri* t : g.second) {
            for (int i = 0; i < 3; i++) fprintf(o, "v %.3f %.3f %.3f %.3f %.3f %.3f\nvt %.5f %.5f\n", t->p[i][0], t->p[i][1], t->p[i][2], t->c[i][0] / 255.f, t->c[i][1] / 255.f, t->c[i][2] / 255.f, t->uv[i][0], 1.f - t->uv[i][1]);
            fprintf(o, "f %d/%d %d/%d %d/%d\n", nv + 1, nv + 1, nv + 2, nv + 2, nv + 3, nv + 3); nv += 3;
        }
    }
    fclose(o); fclose(m);
    fprintf(stderr, "mapdump: wrote %s (%d static triangles of %d seen, %d textures)\n", name, (int)n, (int)capTris.size(), (int)byTex.size()); fflush(stderr);
}


// TUROK_MAPDUMP helper: port_vis.bin holds the arena's visibility matrix (map part 11 payload, K*K bytes of 0/1). The game copies it into RAM at level
// load; every 16 frames the copy is located (once) and overwritten with 1s so every sector is drawn and a capture sees the whole arena.
static void capVisAll(int nframes) {
    static std::vector<uint8_t> pat; static uint8_t* where = nullptr; static int tried = 0;
    if (pat.empty() && !tried) { tried = 1; FILE* f = fopen("port_vis.bin", "rb"); if (f) { uint8_t b[16384]; size_t n = fread(b, 1, sizeof b, f); fclose(f); pat.assign(b, b + n); } }
    if (pat.empty()) return;
    uint8_t* ram = (uint8_t*)0x80000000u; const size_t RAMSZ = 0x800000;
    if (where && memcmp(where, pat.data(), pat.size()) != 0 && memcmp(where, std::vector<uint8_t>(pat.size(), 1).data(), pat.size()) != 0) where = nullptr;
    if (!where && pat.size() >= 64) {
        const uint8_t* hit = nullptr;
        for (size_t i = 0; i + pat.size() <= RAMSZ; i += 4) { if (ram[i] == pat[0] && memcmp(ram + i, pat.data(), 64) == 0) { hit = ram + i; break; } }
        if (hit) { where = (uint8_t*)hit; fprintf(stderr, "visall: matrix at guest 0x%08x (%d bytes)\n", (unsigned)(0x80000000u + (where - ram)), (int)pat.size()); fflush(stderr); }
    }
    if (where) memset(where, 1, pat.size());
}

static void pushVtx(const V& v, float tw, float th, float uls, float ult, bool noPersp = false) {
    float invw = 1.f / v.cw;
    float nx = v.cx * invw, ny = v.cy * invw, nz = v.cz * invw;
    float px = (nx * S.vsc[0] + S.vtr[0]) * 0.25f, py = (-ny * S.vsc[1] * -1.f + S.vtr[1]) * 0.25f;     // 10.2 fixed point viewport
    py = (-ny * S.vsc[1] + S.vtr[1]) * 0.25f;                                                    // clip y is up, screen y is down
    float zs = S.vsc[2] != 0 ? (nz * S.vsc[2] + S.vtr[2]) / 1023.f : (nz * 0.5f + 0.5f);
    if (zs < 0) zs = 0; if (zs > 1) zs = 1;
    Vtx o; o.x = (px / SCREEN_W * 2.f - 1.f) * v.cw; o.y = (1.f - py / SCREEN_H * 2.f) * v.cw; o.z = zs * v.cw; o.w = v.cw;
    o.r = v.r; o.g = v.g; o.b = v.b; o.a = v.a;
    o.u = (v.s / 32.f * g_uvFs - uls / 4.f) / tw; o.v = (v.t / 32.f * g_uvFt - ult / 4.f) / th;      // v.s / v.t are final S10.5: scaled by G_TEXTURE when the vertex was loaded (the RSP does it at load time), or written as final values by G_MODIFYVTX
    batch.push_back(o);
}

static void emitTri(int i0, int i1, int i2) {
    { static int skip = getenv("TUROK_NOTRI") ? 1 : 0; if (skip) return; }
    V* v[3] = { &S.vtx[i0], &S.vtx[i1], &S.vtx[i2] };
    // near-plane clip (z >= -w, w > 0)
    V poly[6]; int n = 0;
    auto inside = [](const V& a) { return a.cw > 1e-5f && a.cz >= -a.cw; };
    for (int i = 0; i < 3; i++) {
        const V& a = *v[i]; const V& b = *v[(i + 1) % 3];
        bool ia = inside(a), ib = inside(b);
        if (ia) poly[n++] = a;
        if (ia != ib) {
            float da = a.cz + a.cw, db = b.cz + b.cw, t = da / (da - db); V r;
            r.cx = a.cx + (b.cx - a.cx) * t; r.cy = a.cy + (b.cy - a.cy) * t; r.cz = a.cz + (b.cz - a.cz) * t; r.cw = a.cw + (b.cw - a.cw) * t;
            r.r = a.r + (b.r - a.r) * t; r.g = a.g + (b.g - a.g) * t; r.b = a.b + (b.b - a.b) * t; r.a = a.a + (b.a - a.a) * t;
            r.s = a.s + (b.s - a.s) * t; r.t = a.t + (b.t - a.t) * t; poly[n++] = r;
        }
    }
    if (n < 3) return;
    // culling in screen space
    if (S.geom & 0x600) {
        float sx[3], sy[3];
        for (int i = 0; i < 3; i++) { sx[i] = poly[i].cx / poly[i].cw * S.vsc[0] * 0.25f; sy[i] = -poly[i].cy / poly[i].cw * S.vsc[1] * 0.25f; }
        float cross = (sx[1] - sx[0]) * (sy[2] - sy[0]) - (sx[2] - sx[0]) * (sy[1] - sy[0]);
        static int flip = getenv("TUROK_CULLFLIP") ? 1 : 0;
        bool front = (cross < 0) != (flip != 0);
        if ((S.geom & 0x400) && !front) return;
        if ((S.geom & 0x200) && front) return;
    }
    if (g_dump) fprintf(g_dump, "      [tri %d %d %d scr (%.1f %.1f %.3f) (%.1f %.1f %.3f) (%.1f %.1f %.3f) geom=%x]\n", i0, i1, i2, poly[0].cx / poly[0].cw * S.vsc[0] * 0.25f + S.vtr[0] * 0.25f, -poly[0].cy / poly[0].cw * S.vsc[1] * 0.25f + S.vtr[1] * 0.25f, poly[0].cz / poly[0].cw, poly[1].cx / poly[1].cw * S.vsc[0] * 0.25f + S.vtr[0] * 0.25f, -poly[1].cy / poly[1].cw * S.vsc[1] * 0.25f + S.vtr[1] * 0.25f, poly[1].cz / poly[1].cw, poly[2].cx / poly[2].cw * S.vsc[0] * 0.25f + S.vtr[0] * 0.25f, -poly[2].cy / poly[2].cw * S.vsc[1] * 0.25f + S.vtr[1] * 0.25f, poly[2].cz / poly[2].cw, (unsigned)S.geom);
    { static int nl2; if (nl2 < 12 && g_nfpub >= 590 && vtxlog_on()) { nl2++; fprintf(stderr, "tri v%d,%d,%d ndc (%.2f %.2f %.3f) (%.2f %.2f %.3f) (%.2f %.2f %.3f) n=%d tex=%d geom=%x\n", i0, i1, i2, poly[0].cx / poly[0].cw, poly[0].cy / poly[0].cw, poly[0].cz / poly[0].cw, poly[1].cx / poly[1].cw, poly[1].cy / poly[1].cw, poly[1].cz / poly[1].cw, poly[2].cx / poly[2].cw, poly[2].cy / poly[2].cw, poly[2].cz / poly[2].cw, n, S.texOn, S.geom); } }
    setupState(0);
    const Tile& t = S.tile[S.texTile & 7];
    if (g_pickN > 0 && g_pickLeft > 0 && cur.texOn) {      // port_pick.txt (pressfile step `pick:x:y;x:y`, 480x360 pixels): log the (clipped) triangles of the next frame that cover those pixels
        for (int f = 1; f + 1 < n; f++) {
            const V* q[3] = { &poly[0], &poly[f], &poly[f + 1] }; float sx[3], sy[3]; for (int i = 0; i < 3; i++) { sx[i] = q[i]->cx / q[i]->cw * S.vsc[0] * 0.25f + S.vtr[0] * 0.25f; sy[i] = -q[i]->cy / q[i]->cw * S.vsc[1] * 0.25f + S.vtr[1] * 0.25f; }
            for (int k = 0; k < g_pickN; k++) {
                float X = (float)g_pickX[k], Y = (float)g_pickY[k];
                auto edge = [&](int a, int b) { return (sx[b] - sx[a]) * (Y - sy[a]) - (sy[b] - sy[a]) * (X - sx[a]); };
                float e0 = edge(0, 1), e1 = edge(1, 2), e2 = edge(2, 0);
                if ((e0 >= 0 && e1 >= 0 && e2 >= 0) || (e0 <= 0 && e1 <= 0 && e2 <= 0)) { const int* d = cur.dbg; fprintf(stderr, "PICK (%d,%d) src pos (%d,%d,%d) (%d,%d,%d) (%d,%d,%d) src s,t (%d,%d) (%d,%d) (%d,%d) clipped s,t (%.0f,%.0f) (%.0f,%.0f) (%.0f,%.0f) scr (%.0f,%.0f) (%.0f,%.0f) (%.0f,%.0f) w %.1f %.1f %.1f scale %04X/%04X | addr %d/%d tex %dx%d uls %d ult %d lrs %d lrt %d mask %d/%d cm %d/%d fmt %d siz %d line %d tile %d key %llx\n", g_pickX[k], g_pickY[k], v[0]->mx, v[0]->my, v[0]->mz, v[1]->mx, v[1]->my, v[1]->mz, v[2]->mx, v[2]->my, v[2]->mz, (int)v[0]->s, (int)v[0]->t, (int)v[1]->s, (int)v[1]->t, (int)v[2]->s, (int)v[2]->t, q[0]->s, q[0]->t, q[1]->s, q[1]->t, q[2]->s, q[2]->t, sx[0], sy[0], sx[1], sy[1], sx[2], sy[2], q[0]->cw, q[1]->cw, q[2]->cw, S.texScaleS, S.texScaleT, d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], d[8], d[9], d[10], d[11], d[12], d[13], d[14], d[15], (unsigned long long)srvKey[cur.srv]); }
            }
        }
    }
    { static int dg = -1, ndg; if (dg < 0) dg = getenv("TUROK_DEGENLOG") ? 1 : 0;      // TUROK_DEGENLOG=1: textured triangles whose texture coordinates are degenerate on one axis although the triangle covers many pixels (the texture streaks)
      if (dg && cur.texOn && ndg < 60) {
          float sx[3], sy[3]; bool okw = true; for (int i = 0; i < 3; i++) { if (v[i]->cw <= 1e-5f) okw = false; else { sx[i] = v[i]->cx / v[i]->cw * S.vsc[0] * 0.25f; sy[i] = -v[i]->cy / v[i]->cw * S.vsc[1] * 0.25f; } }
          float ds = fmaxf(fabsf(v[0]->s - v[1]->s), fmaxf(fabsf(v[1]->s - v[2]->s), fabsf(v[0]->s - v[2]->s))), dt = fmaxf(fabsf(v[0]->t - v[1]->t), fmaxf(fabsf(v[1]->t - v[2]->t), fabsf(v[0]->t - v[2]->t)));
          float area = okw ? fabsf((sx[1] - sx[0]) * (sy[2] - sy[0]) - (sx[2] - sx[0]) * (sy[1] - sy[0])) * 0.5f : 0.f;
          if (okw && area > 40.f && (ds < 2.f || dt < 2.f)) { ndg++; fprintf(stderr, "DEGEN tri v%d,%d,%d s,t (%.0f,%.0f) (%.0f,%.0f) (%.0f,%.0f) screen area %.0f w %.1f %.1f %.1f scr (%.0f,%.0f) (%.0f,%.0f) (%.0f,%.0f) tex %dx%d key %llx frame %d" "\n", i0, i1, i2, v[0]->s, v[0]->t, v[1]->s, v[1]->t, v[2]->s, v[2]->t, area, v[0]->cw, v[1]->cw, v[2]->cw, sx[0] + S.vtr[0] * 0.25f, sy[0] + S.vtr[1] * 0.25f, sx[1] + S.vtr[0] * 0.25f, sy[1] + S.vtr[1] * 0.25f, sx[2] + S.vtr[0] * 0.25f, sy[2] + S.vtr[1] * 0.25f, curTexW, curTexH, (unsigned long long)srvKey[cur.srv], g_nfpub); } } }
    { static int ml = -1, nml, tot, bad; if (ml < 0) ml = getenv("TUROK_SCALELOG") ? 1 : 0;      // TUROK_SCALELOG=1: triangles whose vertices were loaded under a different G_TEXTURE scale than the one in effect at the draw
      if (ml && cur.texOn) { tot++; if (v[0]->ts != S.texScaleS || v[0]->tt != S.texScaleT || v[1]->ts != S.texScaleS || v[1]->tt != S.texScaleT || v[2]->ts != S.texScaleS || v[2]->tt != S.texScaleT) { bad++; if (nml++ < 12) fprintf(stderr, "SCALEMISMATCH vertex scales %04X/%04X %04X/%04X %04X/%04X now %04X/%04X (textured triangles so far %d, mismatching %d)\n", v[0]->ts, v[0]->tt, v[1]->ts, v[1]->tt, v[2]->ts, v[2]->tt, S.texScaleS, S.texScaleT, tot, bad); } } }
    { static int dl = -1, ndl; if (dl < 0) dl = getenv("TUROK_UVRAW") ? 1 : 0;      // TUROK_UVRAW=1: raw vertex s/t, G_TEXTURE scales and tile size of the first triangles that use a tiny 16x9 texture
      if (dl && cur.texOn && curTexW == 16 && curTexH == 9 && ndl < 12) { ndl++; fprintf(stderr, "UVRAW s,t (%d,%d) (%d,%d) (%d,%d) scale %04X/%04X tile %d size uls %d ult %d lrs %d lrt %d line %d fmt %d siz %d\n", (int)v[0]->s, (int)v[0]->t, (int)v[1]->s, (int)v[1]->t, (int)v[2]->s, (int)v[2]->t, S.texScaleS, S.texScaleT, S.texTile & 7, t.uls, t.ult, t.lrs, t.lrt, t.line, t.fmt, t.siz); } }
    g_uvFs = shiftFactor(t.shiftS); g_uvFt = shiftFactor(t.shiftT);
    if (capOn()) { const V* cv[3] = { v[0], v[1], v[2] }; capRecord(cv, cur.texOn ? cur.srv : nullptr, (float)curTexW, (float)curTexH, (float)t.uls, (float)t.ult, g_nfpub); }
    if (batch.size() + 12 > 3 * 6000) flush();
    for (int k = 1; k + 1 < n; k++) { pushVtx(poly[0], (float)curTexW, (float)curTexH, (float)t.uls, (float)t.ult); pushVtx(poly[k], (float)curTexW, (float)curTexH, (float)t.uls, (float)t.ult); pushVtx(poly[k + 1], (float)curTexW, (float)curTexH, (float)t.uls, (float)t.ult); g_tris++; }
}

static void loadVtx(uint32_t w0, uint32_t w1) {
    int n = (w0 >> 12) & 0xFF, v0 = ((w0 >> 1) & 0x7F) - n;
    if (v0 < 0 || v0 + n > 64) return;
    const uint8_t* p = res(w1);
    if (S.mvpDirty) { matMul(S.mv[S.mvTop], S.proj, S.mvp); S.mvpDirty = false; }
    for (int i = 0; i < n; i++, p += 16) {
        V& o = S.vtx[v0 + i];
        float x = (int16_t)rd16(p), y = (int16_t)rd16(p + 2), z = (int16_t)rd16(p + 4);
        if (S.geom & 0x40000) g_vtxGeom[0]++; if (S.geom & 0x80000) g_vtxGeom[1]++; if (S.geom & 0x10000) g_vtxGeom[2]++; if (S.geom & 0x20000) g_vtxGeom[3]++;
        const float* m = S.mvp;
        o.cx = x * m[0] + y * m[4] + z * m[8] + m[12]; o.cy = x * m[1] + y * m[5] + z * m[9] + m[13];
        o.cz = x * m[2] + y * m[6] + z * m[10] + m[14]; o.cw = x * m[3] + y * m[7] + z * m[11] + m[15];
        o.ts = S.texScaleS; o.tt = S.texScaleT; o.s = (int16_t)rd16(p + 8) * (o.ts / 65536.f); o.t = (int16_t)rd16(p + 10) * (o.tt / 65536.f);      // G_TEXTURE scales s/t at vertex load; G_MODIFYVTX later overwrites them with final values
        o.mx = (short)x; o.my = (short)y; o.mz = (short)z;
        if (capOn()) { const float* mv = S.mv[S.mvTop]; float vx = x * mv[0] + y * mv[4] + z * mv[8] + mv[12], vy = x * mv[1] + y * mv[5] + z * mv[9] + mv[13], vz = x * mv[2] + y * mv[6] + z * mv[10] + mv[14]; const float* c = S.camInv; o.wx = vx * c[0] + vy * c[4] + vz * c[8] + c[12]; o.wy = vx * c[1] + vy * c[5] + vz * c[9] + c[13]; o.wz = vx * c[2] + vy * c[6] + vz * c[10] + c[14]; }
        if (S.geom & 0x20000) {      // lighting: colour bytes are a normal
            const float* mv = S.mv[S.mvTop];
            float nx = (int8_t)p[12], ny = (int8_t)p[13], nz = (int8_t)p[14];
            float tx = nx * mv[0] + ny * mv[4] + nz * mv[8], ty = nx * mv[1] + ny * mv[5] + nz * mv[9], tz = nx * mv[2] + ny * mv[6] + nz * mv[10];
            float l = sqrtf(tx * tx + ty * ty + tz * tz); if (l > 0) { tx /= l; ty /= l; tz /= l; }
            float r = S.lights[S.numLights].r, g = S.lights[S.numLights].g, b = S.lights[S.numLights].b;
            for (int k = 0; k < S.numLights; k++) {
                float d = tx * S.lights[k].dx + ty * S.lights[k].dy + tz * S.lights[k].dz; if (d < 0) d = 0;
                r += S.lights[k].r * d; g += S.lights[k].g * d; b += S.lights[k].b * d;
            }
            o.r = r > 1 ? 1 : r; o.g = g > 1 ? 1 : g; o.b = b > 1 ? 1 : b;
        } else { o.r = p[12] / 255.f; o.g = p[13] / 255.f; o.b = p[14] / 255.f; }
        o.a = p[15] / 255.f;
        if ((S.geom & 0x10000) && fogOn()) {      // G_FOG: the RSP replaces the vertex alpha with the fog factor clamp(z_ndc * fm + fo, 0, 255); behind the camera the factor of the near plane applies
            float zn = o.cw > 1e-6f ? o.cz / o.cw : -1.f, f = zn * (float)g_fogMul + (float)g_fogOff;
            o.a = f <= 0.f ? 0.f : f >= 255.f ? 1.f : f / 255.f;
        }
        if (g_dump) fprintf(g_dump, "      [vtx %d: xyz %d %d %d st %d %d raw %02X %02X %02X %02X -> rgba %.2f %.2f %.2f %.2f w %.1f]\n", v0 + i, (int)x, (int)y, (int)z, (int)o.s, (int)o.t, p[12], p[13], p[14], p[15], o.r, o.g, o.b, o.a, o.cw);
        { static int nl; if (nl < 24 && g_nfpub >= 590 && vtxlog_on()) { nl++; fprintf(stderr, "vtx %d: pos %d %d %d clip %.2f %.2f %.2f %.2f rgba %.2f %.2f %.2f %.2f light=%d lights=%d\n", v0 + i, (int)x, (int)y, (int)z, o.cx, o.cy, o.cz, o.cw, o.r, o.g, o.b, o.a, (S.geom >> 17) & 1, S.numLights); } }
    }
}

static void fillRect(int x0, int y0, int x1, int y1) {      // screen pixels (inclusive, in 480x360 space)
    uint32_t col = S.fill;
    float r, g, b;
    uint16_t c16 = (uint16_t)(col >> 16);
    r = ((c16 >> 11) & 31) / 31.f; g = ((c16 >> 6) & 31) / 31.f; b = ((c16 >> 1) & 31) / 31.f;
    if (S.cimg == S.zimg) {
        flush();
        if (x0 <= 0 && y0 <= 0 && x1 >= SCREEN_W - 1 && y1 >= SCREEN_H - 1) { ctx->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH, 1.f, 0); return; }
        // split-screen viewports clear only their quadrant of the z-buffer (4-player: 240x178 fills); ignoring those left stale depth
        // from the previous frame, so every moving view lost most of its geometry to the fill colour (black / red sky)
        g_zclear = 1; setupState(1);
        float fx0 = x0 / SCREEN_W * 2 - 1, fx1 = (x1 + 1) / SCREEN_W * 2 - 1, fy0 = 1 - y0 / SCREEN_H * 2, fy1 = 1 - (y1 + 1) / SCREEN_H * 2;
        Vtx q[4]; for (int i = 0; i < 4; i++) { q[i].z = 1; q[i].w = 1; q[i].r = q[i].g = q[i].b = q[i].a = 1; q[i].u = q[i].v = 0; }
        q[0].x = fx0; q[0].y = fy0; q[1].x = fx1; q[1].y = fy0; q[2].x = fx1; q[2].y = fy1; q[3].x = fx0; q[3].y = fy1;
        batch.push_back(q[0]); batch.push_back(q[1]); batch.push_back(q[2]); batch.push_back(q[0]); batch.push_back(q[2]); batch.push_back(q[3]);
        flush(); g_zclear = 0;
        return;
    }
    {   // 1-cycle / 2-cycle rectangles go through the colour combiner and the blender on the RDP (only FILL mode writes the fill colour): the
        // boss shield / health bars are G_FILLRECTs with a PRIM combiner and came out in the (black) fill colour
        int cycle = (S.omH >> 20) & 3;
        if (cycle == 0 || cycle == 1) {
            uint32_t sg = S.geom; int st = S.texOn; S.geom &= ~1u; S.texOn = 0;   /* FORCE_BL stays: the underwater tint is a full-screen PRIM rectangle at alpha 0.5 (opaque it hid the level) */
            setupState(0);
            S.geom = sg; S.texOn = st;
            float fx0 = x0 / SCREEN_W * 2 - 1, fx1 = (x1 + 1) / SCREEN_W * 2 - 1, fy0 = 1 - y0 / SCREEN_H * 2, fy1 = 1 - (y1 + 1) / SCREEN_H * 2;
            Vtx q[4]; for (int i = 0; i < 4; i++) { q[i].z = 0; q[i].w = 1; q[i].r = q[i].g = q[i].b = q[i].a = 1; q[i].u = q[i].v = 0; }
            q[0].x = fx0; q[0].y = fy0; q[1].x = fx1; q[1].y = fy0; q[2].x = fx1; q[2].y = fy1; q[3].x = fx0; q[3].y = fy1;
            batch.push_back(q[0]); batch.push_back(q[1]); batch.push_back(q[2]); batch.push_back(q[0]); batch.push_back(q[2]); batch.push_back(q[3]);
            return;
        }
    }
    if (x0 <= 0 && y0 <= 0 && x1 >= SCREEN_W - 1 && y1 >= SCREEN_H - 1) { flush(); float c[4] = { r, g, b, 1 }; ctx->ClearRenderTargetView(rtv, c); return; }
    DState save = cur; bool sv = curValid;
    uint32_t sg = S.geom, sl = S.omL; S.geom &= ~1u; S.omL &= ~0x4000u;
    setupState(1);
    float fx0 = x0 / SCREEN_W * 2 - 1, fx1 = (x1 + 1) / SCREEN_W * 2 - 1, fy0 = 1 - y0 / SCREEN_H * 2, fy1 = 1 - (y1 + 1) / SCREEN_H * 2;
    Vtx q[4]; for (int i = 0; i < 4; i++) { q[i].z = 0; q[i].w = 1; q[i].r = r; q[i].g = g; q[i].b = b; q[i].a = 1; q[i].u = q[i].v = 0; }
    q[0].x = fx0; q[0].y = fy0; q[1].x = fx1; q[1].y = fy0; q[2].x = fx1; q[2].y = fy1; q[3].x = fx0; q[3].y = fy1;
    batch.push_back(q[0]); batch.push_back(q[1]); batch.push_back(q[2]); batch.push_back(q[0]); batch.push_back(q[2]); batch.push_back(q[3]);
    S.geom = sg; S.omL = sl; (void)save; (void)sv;
}

static void texRect(uint32_t w0, uint32_t w1, uint32_t h1w1, uint32_t h2w1) {
    { static int skip = getenv("TUROK_NORECT") ? 1 : 0; if (skip) return; }
    int xh = (w0 >> 12) & 0xFFF, yh = w0 & 0xFFF, tile = (w1 >> 24) & 7, xl = (w1 >> 12) & 0xFFF, yl = w1 & 0xFFF;   // xh,yh = lower right (10.2)
    float s0 = (int16_t)(h1w1 >> 16), t0 = (int16_t)(h1w1 & 0xFFFF), dsdx = (int16_t)(h2w1 >> 16), dtdy = (int16_t)(h2w1 & 0xFFFF);
    g_rects++; { static int nl; if (nl < 200 && g_nfpub >= 590 && vtxlog_on() && ++nl) { fprintf(stderr, "texrect: x %d..%d y %d..%d tile %d cycle %d\n", xl, xh, yl, yh, tile, (int)((S.omH >> 20) & 3)); fflush(stderr); } }
    int cycle = (S.omH >> 20) & 3; float sp = (cycle == 2) ? 0.25f : 1.f;
    int save = S.texTile; S.texTile = tile; uint32_t sg = S.geom, sl = S.omL, sh = S.omH; S.geom &= ~1u;
    if (dsdx == 1024 && dtdy == 1024) S.omH &= ~(3u << 12);      // 1:1 copies: point sampling reproduces the RDP's texel-centre fetch on the upscaled target (bilinear smeared a green line around the cached background patch of the main menu)
    setupState(cycle == 2 ? 2 : 0);
    const Tile& t = S.tile[tile & 7];
    float x0 = xl / 4.f, y0 = yl / 4.f, x1 = xh / 4.f, y1 = yh / 4.f;
    if (cycle >= 2) { x1 += 1; y1 += 1; }
    float s1 = s0 + (x1 - x0) * dsdx * sp / 1024.f * 32.f, t1 = t0 + (y1 - y0) * dtdy / 1024.f * 32.f;
    const float fS = shiftFactor(t.shiftS), fT = shiftFactor(t.shiftT);
    auto uvx = [&](float s) { return (s / 32.f * fS - t.uls / 4.f) / curTexW; }; auto uvy = [&](float tt) { return (tt / 32.f * fT - t.ult / 4.f) / curTexH; };
    float X0 = x0 / SCREEN_W * 2 - 1, X1 = x1 / SCREEN_W * 2 - 1, Y0 = 1 - y0 / SCREEN_H * 2, Y1 = 1 - y1 / SCREEN_H * 2;
    Vtx q[4]; for (int i = 0; i < 4; i++) { q[i].z = 0; q[i].w = 1; q[i].r = q[i].g = q[i].b = q[i].a = 1; }
    q[0].x = X0; q[0].y = Y0; q[0].u = uvx(s0); q[0].v = uvy(t0);
    q[1].x = X1; q[1].y = Y0; q[1].u = uvx(s1); q[1].v = uvy(t0);
    q[2].x = X1; q[2].y = Y1; q[2].u = uvx(s1); q[2].v = uvy(t1);
    q[3].x = X0; q[3].y = Y1; q[3].u = uvx(s0); q[3].v = uvy(t1);
    { static int nl; if (nl++ < 6) { fprintf(stderr, "  uv %.3f,%.3f - %.3f,%.3f  tex %dx%d uls %d ult %d dsdx %g dtdy %g\n", q[0].u, q[0].v, q[2].u, q[2].v, curTexW, curTexH, t.uls, t.ult, dsdx, dtdy); fflush(stderr); } }
    batch.push_back(q[0]); batch.push_back(q[1]); batch.push_back(q[2]); batch.push_back(q[0]); batch.push_back(q[2]); batch.push_back(q[3]);
    S.texTile = save; S.geom = sg; S.omL = sl; S.omH = sh;
}

static void loadBlock(uint32_t w0, uint32_t w1) {
    int uls = (w0 >> 12) & 0xFFF, ult = w0 & 0xFFF, tile = (w1 >> 24) & 7, lrs = (w1 >> 12) & 0xFFF, dxt = w1 & 0xFFF;
    int bpt = S.timgSiz == 0 ? 1 : S.timgSiz == 1 ? 1 : S.timgSiz == 2 ? 2 : 4;
    int texels = lrs + 1;
    int bytes = S.timgSiz == 0 ? (texels + 1) / 2 : texels * bpt;
    if (bytes > 4096) bytes = 4096;                          /* TMEM is 4 KB: a bigger load wraps on hardware, here it would read past the source buffer */
    uint32_t addr = S.timg + (S.timgSiz == 0 ? (ult * S.timgW + uls) / 2 : (ult * S.timgW + uls) * bpt);
    const uint8_t* src = res(addr); uint8_t* dst = S.tmem + S.tile[tile].tmem * 8;
    int words = (bytes + 7) / 8;
    for (int j = 0; j < words; j++) {
        int off = S.tile[tile].tmem * 8 + j * 8; if (off + 8 > 4096) break;
        int row = dxt ? (int)(((uint32_t)j * dxt) >> 11) : 0;
        if (row & 1) { memcpy(dst + j * 8, src + j * 8 + 4, 4); memcpy(dst + j * 8 + 4, src + j * 8, 4); } else memcpy(dst + j * 8, src + j * 8, 8);
    }
}
static void loadTile(uint32_t w0, uint32_t w1) {
    int uls = ((w0 >> 12) & 0xFFF) >> 2, ult = (w0 & 0xFFF) >> 2, tile = (w1 >> 24) & 7, lrs = ((w1 >> 12) & 0xFFF) >> 2, lrt = (w1 & 0xFFF) >> 2;
    int bpt = S.timgSiz == 2 ? 2 : S.timgSiz == 3 ? 4 : 1; int w = lrs - uls + 1, h = lrt - ult + 1;
    int rowBytes = S.timgSiz == 0 ? (w + 1) / 2 : w * bpt; int line = S.tile[tile].line * 8;
    int srcStride = S.timgSiz == 0 ? S.timgW / 2 : S.timgW * bpt;
    if (w <= 0 || h <= 0 || rowBytes > 4096) return;        /* lrs < uls: the RDP loads nothing; a negative size here became a giant memcpy (attract demo, 7th cycle) */
    uint32_t base = S.timg + (S.timgSiz == 0 ? uls / 2 : uls * bpt) + ult * srcStride;
    for (int r = 0; r < h; r++) {
        const uint8_t* src = res(base + r * srcStride); int off = S.tile[tile].tmem * 8 + r * line;
        if (off + rowBytes > 4096) break;
        memcpy(S.tmem + off, src, rowBytes);
        if (r & 1) for (int k = 0; k + 8 <= (rowBytes + 7) & ~7 && off + k + 8 <= 4096; k += 8) { uint8_t t4[4]; memcpy(t4, S.tmem + off + k, 4); memcpy(S.tmem + off + k, S.tmem + off + k + 4, 4); memcpy(S.tmem + off + k + 4, t4, 4); }
    }
}
static void loadTlut(uint32_t w0, uint32_t w1) {
    int tile = (w1 >> 24) & 7, count = ((w1 >> 14) & 0x3FF) + 1;
    const uint8_t* src = res(S.timg); int base = S.tile[tile].tmem * 8;
    for (int i = 0; i < count && base + i * 8 + 8 <= 4096; i++) for (int k = 0; k < 4; k++) memcpy(S.tmem + base + i * 8 + k * 2, src + i * 2, 2);
}

static long g_dlBudget;                                                              /* commands left for this frame: a self-referencing list (seen after the 7th attract demo) would otherwise spin the platform thread forever */
static void runDL(uint32_t addr, int depth) {
    if (depth > 18) return;      // F3DEX2 keeps an 18-entry display-list stack; the 4th split-screen view reaches its weapon list 13 deep
    const uint8_t* p = res(addr);
    for (int guard = 0; guard < 200000; guard++, p += 8) {
        { const uint8_t* ramBase = g_snapNow ? g_snapNow : (const uint8_t*)(size_t)0x80000000u; if (p >= ramBase && p + 8 > ramBase + 0x800000) return; }      /* a display list without an end command ran off the end of RAM */
        if (--g_dlBudget < 0) { static int warned; if (warned++ < 5) { fprintf(stderr, "renderer: display list runaway (depth %d), frame abandoned\n", depth); fflush(stderr); } return; }
        uint32_t w0 = rd32(p), w1 = rd32(p + 4); int op = w0 >> 24; g_ops[op]++; if (g_dump) fprintf(g_dump, "%*s%08X %08X\n", depth * 2, "", w0, w1);
        switch (op) {
        case 0xDF: return;
        case 0xDE: { uint32_t a = w1; int br = (w0 >> 16) & 1; if (g_dump) fprintf(g_dump, "DL %s %08X (depth %d)\n", br ? "branch" : "call", a, depth);
                     if (br) { p = res(a) - 8; break; }      // G_DL branch: continue in the new list without using a stack level (a recursive branch pushed the 4th player's weapon past the old depth-12 limit)
                     runDL(a, depth + 1); break; }
        case 0x01: loadVtx(w0, w1); break;
        case 0x02: {      // G_MODIFYVTX: overwrite colour / texture coordinates / screen position of a loaded vertex
            int off = (w0 >> 16) & 0xFF, idx = (w0 & 0xFFFF) / 2;
            if (idx >= 0 && idx < 64) {
                V& v = S.vtx[idx];
                if (off == 0x10) { v.r = ((w1 >> 24) & 255) / 255.f; v.g = ((w1 >> 16) & 255) / 255.f; v.b = ((w1 >> 8) & 255) / 255.f; v.a = (w1 & 255) / 255.f; }
                else if (off == 0x14) { v.s = (float)(int16_t)(w1 >> 16); v.t = (float)(int16_t)(w1 & 0xFFFF); { static int nm; if (g_nfpub >= 450 && nm++ < 60 && getenv("TUROK_MODVTXLOG")) { fprintf(stderr, "MODIFYVTX ST vtx %d s,t %d,%d with G_TEXTURE scale %04X/%04X\n", idx, (int)v.s, (int)v.t, S.texScaleS, S.texScaleT); } } }
                else if (off == 0x18) { float x = (float)(int16_t)(w1 >> 16), y = (float)(int16_t)(w1 & 0xFFFF); float vs0 = S.vsc[0] != 0 ? S.vsc[0] : 1.f, vs1 = S.vsc[1] != 0 ? S.vsc[1] : 1.f; v.cw = 1.f; v.cx = (x - S.vtr[0]) / vs0; v.cy = (S.vtr[1] - y) / vs1; }
                else if (off == 0x1C) { v.cz = 0.f; }
            }
            break; }
        case 0x05: emitTri(((w0 >> 16) & 0xFF) / 2, ((w0 >> 8) & 0xFF) / 2, (w0 & 0xFF) / 2); break;
        case 0x06: case 0x07:
            emitTri(((w0 >> 16) & 0xFF) / 2, ((w0 >> 8) & 0xFF) / 2, (w0 & 0xFF) / 2);
            emitTri(((w1 >> 16) & 0xFF) / 2, ((w1 >> 8) & 0xFF) / 2, (w1 & 0xFF) / 2); break;
        case 0xDA: {   // MTX
            int f = (w0 & 0xFF) ^ 1; float m[16]; loadMtx(res(w1), m); if (g_dump) { fprintf(g_dump, "      [mtx f=%d:"); for (int q = 0; q < 16; q++) fprintf(g_dump, " %.3f", m[q]); fprintf(g_dump, "]"); fprintf(g_dump, "%c", 10); } { static int nl; if (nl < 6 && g_nfpub >= 590 && vtxlog_on()) { nl++; fprintf(stderr, "mtx f=%d @%p:", f, (const void*)res(w1)); for (int i = 0; i < 16; i++) fprintf(stderr, " %.3g", m[i]); fprintf(stderr, "\n"); } }
            if (f & 4) { if (f & 2) { memcpy(S.proj, m, 64); S.camSet = false; if (capOn() && !g_frameCamSet) { const float* C = m; double A[3][4] = { { C[0], C[4], C[8], -C[12] }, { C[1], C[5], C[9], -C[13] }, { C[3], C[7], C[11], -C[15] } }; bool ok = true; for (int c = 0; c < 3 && ok; c++) { int pv = c; for (int r = c + 1; r < 3; r++) if (fabs(A[r][c]) > fabs(A[pv][c])) pv = r; if (fabs(A[pv][c]) < 1e-9) { ok = false; break; } for (int j = 0; j < 4; j++) std::swap(A[c][j], A[pv][j]); for (int r = 0; r < 3; r++) if (r != c) { double fct = A[r][c] / A[c][c]; for (int j = 0; j < 4; j++) A[r][j] -= fct * A[c][j]; } } if (ok) { g_frameCamSet = true; for (int c = 0; c < 3; c++) g_frameCam[c] = (float)(A[c][3] / A[c][c]); } } } else matMul(m, S.proj, S.proj); }
            else {
                if ((f & 1) && S.mvTop < 9) { memcpy(S.mv[S.mvTop + 1], S.mv[S.mvTop], 64); S.mvTop++; }
                if (f & 2) memcpy(S.mv[S.mvTop], m, 64); else matMul(m, S.mv[S.mvTop], S.mv[S.mvTop]);
                /* the game loads view*projection as the projection matrix and each object's world matrix as the modelview: world = vertex * modelview (camInv stays identity) */
            }
            S.mvpDirty = true; break; }
        case 0xD8: { int n = (w1 >> 6) & 0x3FF; if (n < 1) n = 1; S.mvTop -= n; if (S.mvTop < 0) S.mvTop = 0; S.mvpDirty = true; break; }
        case 0xD9: S.geom = (S.geom & (w0 & 0xFFFFFF)) | w1; break;
        case 0xD7: S.texOn = (w0 >> 1) & 0x7F; S.texTile = (w0 >> 8) & 7; S.texScaleS = w1 >> 16; S.texScaleT = w1 & 0xFFFF; break;
        case 0xDB: {
            int idx = (w0 >> 16) & 0xFF, off = w0 & 0xFFFF;
            if (idx == 6) segbase[(off >> 2) & 15] = w1 & 0xFFFFFF;
            else if (idx == 2) S.numLights = (int)(w1 / 24) > 7 ? 7 : (int)(w1 / 24);
            else if (idx == 8) { g_fogMul = (int16_t)(w1 >> 16); g_fogOff = (int16_t)(w1 & 0xFFFF); { static int nf; if (nf++ < 6 && getenv("TUROK_FOGLOG")) fprintf(stderr, "FOGFACTOR fm %d fo %d\n", g_fogMul, g_fogOff); } }      // G_MW_FOG
            break; }
        case 0xF8: g_fogCol[0] = (w1 >> 24) / 255.f; g_fogCol[1] = ((w1 >> 16) & 255) / 255.f; g_fogCol[2] = ((w1 >> 8) & 255) / 255.f; g_fogCol[3] = (w1 & 255) / 255.f; { static int nf; if (nf++ < 6 && getenv("TUROK_FOGLOG")) fprintf(stderr, "FOGCOLOR %08X\n", w1); } break;      // G_SETFOGCOLOR
        case 0xDC: {
            int idx = w0 & 0xFF, off = ((w0 >> 8) & 0xFF) * 8;
            const uint8_t* d = res(w1);
            if (idx == 8) { for (int i = 0; i < 4; i++) { S.vsc[i] = (int16_t)rd16(d + i * 2); S.vtr[i] = (int16_t)rd16(d + 8 + i * 2); } if (g_dump) { fprintf(g_dump, "      [viewport scale %g %g %g %g trans %g %g %g %g]", S.vsc[0], S.vsc[1], S.vsc[2], S.vsc[3], S.vtr[0], S.vtr[1], S.vtr[2], S.vtr[3]); fprintf(g_dump, "%c", 10); } { static int nv; if (nv++ < 12 && vtxlog_on()) fprintf(stderr, "viewport scale %g %g %g %g trans %g %g %g %g\n", S.vsc[0], S.vsc[1], S.vsc[2], S.vsc[3], S.vtr[0], S.vtr[1], S.vtr[2], S.vtr[3]); } }
            else if (idx == 10) {
                int slot = off / 24;
                if (slot >= 2 && slot <= 9) {      // LIGHT_n sits at n*24+24 (n = 1..): lights[n-1]; the ambient light follows the last one
                    Light& L = S.lights[slot - 2]; L.r = d[0] / 255.f; L.g = d[1] / 255.f; L.b = d[2] / 255.f;
                    { static int nl2; if (nl2 < 400 && getenv("TUROK_LIGHTLOG")) { nl2++; fprintf(stderr, "light slot %d: col %d %d %d dir %d %d %d (n=%d)\n", slot, d[0], d[1], d[2], (int8_t)d[8], (int8_t)d[9], (int8_t)d[10], S.numLights); } }
                    L.dx = (int8_t)d[8] / 127.f; L.dy = (int8_t)d[9] / 127.f; L.dz = (int8_t)d[10] / 127.f;
                }
            }
            break; }
        case 0xED: flush(); S.sc[0] = (w0 >> 12) & 0xFFF; S.sc[1] = w0 & 0xFFF; S.sc[2] = (w1 >> 12) & 0xFFF; S.sc[3] = w1 & 0xFFF; break;      // SETSCISSOR (10.2)
        case 0xE2: case 0xE3: {
            int len = (w0 & 0xFF) + 1, sft = 32 - (int)((w0 >> 8) & 0xFF) - len; uint32_t mask = (len >= 32 ? 0xFFFFFFFFu : ((1u << len) - 1)) << sft;
            uint32_t& r = (op == 0xE2) ? S.omL : S.omH; r = (r & ~mask) | (w1 & mask);
            if (op == 0xE3) S.tluts = (S.omH >> 14) & 3;
            break; }
        case 0xFC: S.combW0 = w0 & 0xFFFFFF; S.combW1 = w1; break;
        case 0xFA: S.prim[0] = (w1 >> 24) / 255.f; S.prim[1] = ((w1 >> 16) & 255) / 255.f; S.prim[2] = ((w1 >> 8) & 255) / 255.f; S.prim[3] = (w1 & 255) / 255.f; break;
        case 0xFB: S.env[0] = (w1 >> 24) / 255.f; S.env[1] = ((w1 >> 16) & 255) / 255.f; S.env[2] = ((w1 >> 8) & 255) / 255.f; S.env[3] = (w1 & 255) / 255.f; break;
        case 0xF7: S.fill = w1; break;
        case 0xFF: { float nw = (float)((w0 & 0xFFF) + 1); if (nw != SCREEN_W && nw >= 64) { flush(); SCREEN_W = nw; SCREEN_H = floorf(nw * 0.75f + 0.5f); } } S.cimg = (w1 & 0x80000000u) ? w1 : (0x80000000u | (segbase[(w1 >> 24) & 15] + (w1 & 0xFFFFFF))); break;
        case 0xFE: S.zimg = (w1 & 0x80000000u) ? w1 : (0x80000000u | (segbase[(w1 >> 24) & 15] + (w1 & 0xFFFFFF))); break;
        case 0xFD: S.timgFmt = (w0 >> 21) & 7; S.timgSiz = (w0 >> 19) & 3; S.timgW = (w0 & 0xFFF) + 1; S.timg = w1; break;
        case 0xF5: {
            Tile& t = S.tile[(w1 >> 24) & 7];
            t.fmt = (w0 >> 21) & 7; t.siz = (w0 >> 19) & 3; t.line = (w0 >> 9) & 0x1FF; t.tmem = w0 & 0x1FF;
            t.pal = (w1 >> 20) & 15; t.cmT = (w1 >> 18) & 3; t.maskT = (w1 >> 14) & 15; t.shiftT = (w1 >> 10) & 15; t.cmS = (w1 >> 8) & 3; t.maskS = (w1 >> 4) & 15; t.shiftS = w1 & 15;
            { static int nl, on = -1; if (on < 0) on = getenv("TUROK_TILEDBG") ? 1 : 0;      // TUROK_TILEDBG=1: log tiles that use a coordinate shift (the renderer ignores it) or mirror/clamp with a mask
              if (on && (t.shiftS || t.shiftT) && nl < 60) { nl++; fprintf(stderr, "SETTILE shift: tile %u fmt %d siz %d line %d tmem %d shiftS %d shiftT %d cmS %d cmT %d maskS %d maskT %d\n", (w1 >> 24) & 7, t.fmt, t.siz, t.line, t.tmem, t.shiftS, t.shiftT, t.cmS, t.cmT, t.maskS, t.maskT); } }
            break; }
        case 0xF2: { Tile& t = S.tile[(w1 >> 24) & 7]; t.uls = (w0 >> 12) & 0xFFF; t.ult = w0 & 0xFFF; t.lrs = (w1 >> 12) & 0xFFF; t.lrt = w1 & 0xFFF; break; }
        case 0xF3: loadBlock(w0, w1); break;
        case 0xF4: loadTile(w0, w1); break;
        case 0xF0: loadTlut(w0, w1); break;
        case 0xF6: fillRect((w1 >> 14) & 0x3FF, (w1 >> 2) & 0x3FF, ((w0 >> 12) & 0xFFF) >> 2, (w0 & 0xFFF) >> 2); break;
        case 0xE4: {
            const uint8_t* q = p + 8;
            if (g_dump) fprintf(g_dump, "      [texrect follow %08X %08X | %08X %08X]\n", rd32(q), rd32(q + 4), rd32(q + 8), rd32(q + 12));
            if (q[0] == 0xE1) { texRect(w0, w1, rd32(q + 4), rd32(q + 12)); p += 16; }      // gsSPTextureRectangle: E4 + E1 (s,t) + F1 (dsdx,dtdy)
            else texRect(w0, w1, 0, 0x04000400u);                                              // this game emits a bare E4: texture origin 0, one texel per pixel
            break;
        }
        default: g_opsIgnored[op]++; break;     // NOOP, SYNCs, RDPHALF, SETCONVERT, SETSCISSOR, SETPRIMDEPTH, SETFOGCOLOR, SETBLENDCOLOR ... (counted, printed in the frame log)
        }
    }
}

#include "renderer_selftest.inc"

// TUROK_SHOTS=<first>-<last>:<step>[:<divisor>] writes port\build\fs_<frame>.bmp (the rendered frame, downscaled by <divisor>, default 4) for every <step>th renderer frame in the range:
// frame-exact captures of moments that pass too fast for the external screenshot script (the fly-through at the start of a level)
static void shotSave(int frame, int dv) {
    static ID3D11Texture2D* stg;
    if (!stg) { D3D11_TEXTURE2D_DESC sd = {}; sd.Width = INTERNAL_W; sd.Height = INTERNAL_H; sd.MipLevels = 1; sd.ArraySize = 1; sd.SampleDesc.Count = 1; sd.Format = DXGI_FORMAT_R8G8B8A8_UNORM; sd.Usage = D3D11_USAGE_STAGING; sd.CPUAccessFlags = D3D11_CPU_ACCESS_READ; if (FAILED(dev->CreateTexture2D(&sd, nullptr, &stg))) return; }
    ctx->CopyResource(stg, rtTex);
    D3D11_MAPPED_SUBRESOURCE mp; if (FAILED(ctx->Map(stg, 0, D3D11_MAP_READ, 0, &mp))) return;
    int ow = INTERNAL_W / dv, oh = INTERNAL_H / dv, rb = (ow * 3 + 3) & ~3;
    std::vector<uint8_t> out(54 + (size_t)rb * oh, 0);
    uint32_t fsz = (uint32_t)out.size(), pofs = 54, hsz = 40, dsz = (uint32_t)(rb * oh); int32_t bw = ow, bh = oh; uint16_t pl = 1, bpp = 24;
    out[0] = 'B'; out[1] = 'M'; memcpy(&out[2], &fsz, 4); memcpy(&out[10], &pofs, 4); memcpy(&out[14], &hsz, 4); memcpy(&out[18], &bw, 4); memcpy(&out[22], &bh, 4); memcpy(&out[26], &pl, 2); memcpy(&out[28], &bpp, 2); memcpy(&out[34], &dsz, 4);
    for (int y = 0; y < oh; y++) {
        uint8_t* d = &out[54 + (size_t)rb * (oh - 1 - y)];
        for (int x = 0; x < ow; x++) {
            int r = 0, g = 0, b = 0;
            for (int j = 0; j < dv; j++) { const uint8_t* s = (const uint8_t*)mp.pData + (size_t)(y * dv + j) * mp.RowPitch + (size_t)x * dv * 4; for (int i = 0; i < dv; i++, s += 4) { r += s[0]; g += s[1]; b += s[2]; } }
            int n = dv * dv; d[x * 3] = (uint8_t)(b / n); d[x * 3 + 1] = (uint8_t)(g / n); d[x * 3 + 2] = (uint8_t)(r / n);
        }
    }
    ctx->Unmap(stg, 0);
    char fn[96]; sprintf(fn, "port\\build\\fs_%05d.bmp", frame); FILE* f = fopen(fn, "wb"); if (f) { fwrite(out.data(), 1, out.size(), f); fclose(f); }
}

extern "C" void renderer_frame(ID3D11RenderTargetView* bb, int w, int h) {
    if (!ready) return;
    static const bool selftest = getenv("TUROK_SELFTEST") != nullptr;
    if (selftest) selftest_present();
    static int nframes;
    EnterCriticalSection(&g_snap_lock);
    if (InterlockedExchange(&g_gfx_task_ready, 0)) {
        g_snapNow = g_gfx_snap_valid ? g_gfx_snap : nullptr;
        uint32_t dl = rd32(g_gfx_task + 0x30);
        memset(&S, 0, sizeof(S)); S.sc[2] = (int)(SCREEN_W * 4); S.sc[3] = (int)(SCREEN_H * 4); for (int i = 0; i < 4; i++) S.vsc[i] = (i == 0 ? 640.f : i == 1 ? 480.f : i == 2 ? 511.f : 0.f); S.vtr[0] = 640.f; S.vtr[1] = 480.f; S.vtr[2] = 511.f;
        g_frameCamSet = false; matIdent(S.proj); matIdent(S.camInv); for (int i = 0; i < 10; i++) matIdent(S.mv[i]); S.mvpDirty = true;
        memset(g_ops, 0, sizeof g_ops); curValid = false; batch.clear(); g_tris = g_draws = g_texdecodes = 0; memset(g_zmodeDraws, 0, sizeof g_zmodeDraws); memset(g_vtxGeom, 0, sizeof g_vtxGeom); g_texDraws = g_noPerspDraws = g_lodDraws = g_detailDraws = 0; g_omHHist.clear();
        ctx->OMSetRenderTargets(1, &rtv, dsv);
        D3D11_VIEWPORT vp = { 0, 0, (float)INTERNAL_W, (float)INTERNAL_H, 0, 1 }; ctx->RSSetViewports(1, &vp);
        ctx->RSSetState(rs); ctx->IASetInputLayout(layout); ctx->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        ctx->VSSetShader(vs, nullptr, 0); ctx->PSSetShader(ps, nullptr, 0); ctx->PSSetConstantBuffers(0, 1, &cbuf);
        g_nfpub = nframes;
        { static int df = -1; if (df < 0) { const char* e = getenv("TUROK_DLFRAME"); df = e ? atoi(e) : 0x7FFFFFF0; /* TUROK_DLFRAME=n: dump frames n..n+59 (was always on at 300: 60 x 600 KB written in the first seconds) */ } if (nframes >= df && nframes < df + 60) { char fn[64]; sprintf(fn, "port_dl_%d.txt", nframes - df); g_dump = fopen(fn, "w"); } }
        { if (g_pickLeft > 0) g_pickLeft--; if (port_scripted() && GetFileAttributesA("port_pick.txt") != INVALID_FILE_ATTRIBUTES) { char pb[256] = {0}; FILE* pf = fopen("port_pick.txt", "r"); if (pf) { if (fgets(pb, sizeof pb, pf)) {} fclose(pf); } DeleteFileA("port_pick.txt"); g_pickN = 0; const char* e = pb; while (*e && g_pickN < 16) { int a, b2, n = 0; if (sscanf(e, "%d:%d%n", &a, &b2, &n) < 2) break; g_pickX[g_pickN] = a; g_pickY[g_pickN++] = b2; e += n; if (*e == ';') e++; } if (g_pickN) { g_pickLeft = 2; fprintf(stderr, "PICK armed for %d pixels (first %d,%d) at frame %d\n", g_pickN, g_pickX[0], g_pickY[0], nframes); } } }
        { static int paf = -2; static char pab[256];      // TUROK_PICKAT=<frame>:x:y;x:y = arm the pixel pick at that renderer frame (moments that pass before the pick file could be written)
          if (paf == -2) { paf = -1; const char* e = getenv("TUROK_PICKAT"); int fr = 0, n = 0; if (e && sscanf(e, "%d:%n", &fr, &n) >= 1 && n > 0) { paf = fr; strncpy(pab, e + n, sizeof pab - 1); } }
          if (paf >= 0 && nframes == paf) { g_pickN = 0; const char* e = pab; while (*e && g_pickN < 16) { int a, b2, n = 0; if (sscanf(e, "%d:%d%n", &a, &b2, &n) < 2) break; g_pickX[g_pickN] = a; g_pickY[g_pickN++] = b2; e += n; if (*e == ';') e++; } if (g_pickN) { g_pickLeft = 2; fprintf(stderr, "PICK armed for %d pixels (first %d,%d) at frame %d\n", g_pickN, g_pickX[0], g_pickY[0], nframes); } } }
        { static int trig; if (trig == 0 && port_scripted() && GetFileAttributesA("port_dumpnow.txt") != INVALID_FILE_ATTRIBUTES) { DeleteFileA("port_dumpnow.txt"); trig = 3; port_dump_threads(); port_dump_trace_pub(400); { FILE* mf = fopen("port_mem.bin", "wb"); if (mf) { fwrite((void*)0x80661000u, 1, 0x12000, mf); fclose(mf); } { FILE* m2 = fopen("port_mem2.bin", "wb"); if (m2) { fwrite((void*)0x801D0C00u, 1, 0x3600, m2); fclose(m2); } } } } if (trig > 0 && !g_dump) { char fn[64]; sprintf(fn, "port_dlnow_%d.txt", 3 - trig); g_dump = fopen(fn, "w"); trig--; } }
        g_dlBudget = 4000000; runDL(dl, 0); flush();
        { static int s0 = -2, s1, ss = 1, sd = 4; if (s0 == -2) { s0 = -1; const char* e = getenv("TUROK_SHOTS"); if (e && sscanf(e, "%d-%d:%d:%d", &s0, &s1, &ss, &sd) >= 3) { if (ss < 1) ss = 1; if (sd < 1 || INTERNAL_W % sd) sd = 4; } else s0 = -1; }
          if (s0 >= 0 && nframes >= s0 && nframes <= s1 && (nframes - s0) % ss == 0) shotSave(nframes, sd); }
        if (g_dump) { fclose(g_dump); g_dump = nullptr; }
        if (capOn() && (nframes & 3) == 0) { FILE* cf = fopen("port_cam.tmp", "w"); if (cf) { fprintf(cf, "%.3f %.3f %.3f\n", g_frameCam[0], g_frameCam[1], g_frameCam[2]); fclose(cf); MoveFileExA("port_cam.tmp", "port_cam.txt", MOVEFILE_REPLACE_EXISTING); } }
        if (capOn() && GetFileAttributesA("port_poke.txt") != INVALID_FILE_ATTRIBUTES) { FILE* pf = fopen("port_poke.txt", "r"); if (pf) { unsigned ad; float v[3]; if (fscanf(pf, "%x %f %f %f", &ad, &v[0], &v[1], &v[2]) == 4) { for (int k = 0; k < 3; k++) { uint32_t u; memcpy(&u, &v[k], 4); u = _byteswap_ulong(u); memcpy((void*)(size_t)(ad + 4 * k), &u, 4); } } fclose(pf); DeleteFileA("port_poke.txt"); } }
        if (capOn() && GetFileAttributesA("port_ramdump.txt") != INVALID_FILE_ATTRIBUTES) { DeleteFileA("port_ramdump.txt"); FILE* rf = fopen("port_ram.bin", "wb"); if (rf) { fwrite((void*)0x80000000u, 1, 0x800000, rf); fclose(rf); } }
        if (capOn() && (nframes & 15) == 0) { FILE* tf = fopen("port_mapdump.txt", "r"); if (tf) { char nm[100] = "map"; if (fscanf(tf, "%99s", nm) != 1) strcpy(nm, "map"); fclose(tf); DeleteFileA("port_mapdump.txt"); capWrite(nm); } if (GetFileAttributesA("port_mapreset.txt") != INVALID_FILE_ATTRIBUTES) { DeleteFileA("port_mapreset.txt"); capTris.clear(); } }
        if (capOn() && (nframes & 15) == 8) capVisAll(nframes);
        if (nframes == 299 || nframes == 599) { fprintf(stderr, "ops:"); for (int i = 0; i < 256; i++) if (g_ops[i]) fprintf(stderr, " %02X:%d", i, g_ops[i]); fprintf(stderr, "\n"); }
        if (++nframes <= 5 || nframes % 300 == 0) { fprintf(stderr, "renderer: frame %d: %d triangles, %d draws, %d texture decodes (cache %d), zmode draws %d/%d/%d/%d, vertices texgen/linear/fog/light %d/%d/%d/%d, textured draws %d (no perspective %d, lod %d, detail/sharpen %d)\n", nframes, g_tris, g_draws, g_texdecodes, (int)texCache.size(), g_zmodeDraws[0], g_zmodeDraws[1], g_zmodeDraws[2], g_zmodeDraws[3], g_vtxGeom[0], g_vtxGeom[1], g_vtxGeom[2], g_vtxGeom[3], g_texDraws, g_noPerspDraws, g_lodDraws, g_detailDraws); for (auto& kv : g_omHHist) fprintf(stderr, "   textured draws with othermode-high %08X: %d\n", kv.first, kv.second);
            fprintf(stderr, "   draws whose blender uses the fog colour or fog alpha (since start): %d\n", g_fogBlendDraws);
            for (auto& kv : g_fogHist) fprintf(stderr, "   fog-geometry triangles with omL %08X cycle %d tex %d: %d\n", (unsigned)(kv.first >> 32), (int)((kv.first >> 20) & 3), (int)(kv.first & 1), kv.second);
            { char ib[512]; int ip = 0; for (int o = 0; o < 256 && ip < 480; o++) if (g_opsIgnored[o]) ip += snprintf(ib + ip, sizeof ib - ip, " %02X:%d", o, g_opsIgnored[o]); if (ip) fprintf(stderr, "   display list commands the renderer ignores (op:count since start):%s\n", ib); }
            fflush(stderr); }
    }
    LeaveCriticalSection(&g_snap_lock);
    // blit the internal frame (4:3) letterboxed into the window
    ctx->OMSetRenderTargets(1, &bb, nullptr);
    float black[4] = { 0, 0, 0, 1 }; ctx->ClearRenderTargetView(bb, black);
    float ww = (float)w, hh = (float)h, sc = ww / INTERNAL_W < hh / INTERNAL_H ? ww / INTERNAL_W : hh / INTERNAL_H;
    float vw = INTERNAL_W * sc, vh = INTERNAL_H * sc; D3D11_VIEWPORT vp = { (ww - vw) / 2, (hh - vh) / 2, vw, vh, 0, 1 }; ctx->RSSetViewports(1, &vp);
    { D3D11_RECT full = { 0, 0, w, h }; ctx->RSSetScissorRects(1, &full); }     // the last game draw's scissor (a portrait viewport on the player-select screens) must not clip the blit
    ctx->OMSetBlendState(bsOpaque, nullptr, 0xFFFFFFFF); ctx->OMSetDepthStencilState(dss[0], 0);
    ctx->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST); ctx->IASetInputLayout(nullptr);
    ctx->VSSetShader(blitVs, nullptr, 0); ctx->PSSetShader(blitPs, nullptr, 0);
    ctx->PSSetShaderResources(0, 1, &rtSrv); ctx->PSSetSamplers(0, 1, &samplers[1][2][2]);
    ctx->Draw(3, 0);
    ID3D11ShaderResourceView* nullSrv = nullptr; ctx->PSSetShaderResources(0, 1, &nullSrv);
}
