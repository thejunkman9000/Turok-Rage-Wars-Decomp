// Milestone 1: Win32 window + Direct3D 11 swap chain, clear to a colour, message loop, frame hook.
// Build: powershell -File port\build.ps1   (32-bit x86, MSVC)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d11.h>
#include <stdio.h>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "user32.lib")

extern "C" void port_early_init(void);
extern "C" void port_game_init(void);
extern "C" void port_difftest(void);          // port/game_glue.c
extern "C" void port_game_frame(void);
extern "C" void port_present_hook(ID3D11DeviceContext* ctx);
extern "C" void renderer_init(ID3D11Device* d, ID3D11DeviceContext* c);
extern "C" void renderer_frame(ID3D11RenderTargetView* bb, int w, int h);

static ID3D11Device*           g_dev;
static ID3D11DeviceContext*    g_ctx;
static IDXGISwapChain*         g_sc;
static ID3D11RenderTargetView* g_rtv;
static int g_w = 1280, g_h = 720;
static void stage(const char* m) { FILE* f = fopen("port_stage.txt", "a"); if (f) { fprintf(f, "%s\n", m); fclose(f); } }

static void make_rtv() {
    ID3D11Texture2D* bb = nullptr;
    g_sc->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&bb);
    g_dev->CreateRenderTargetView(bb, nullptr, &g_rtv);
    bb->Release();
}

static LRESULT CALLBACK wndproc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
    case WM_DESTROY: PostQuitMessage(0); return 0;
    case WM_KEYDOWN: if (w == VK_ESCAPE) PostQuitMessage(0); return 0;
    case WM_SIZE:
        if (g_sc && w != SIZE_MINIMIZED) {
            g_w = LOWORD(l); g_h = HIWORD(l);
            if (g_rtv) { g_rtv->Release(); g_rtv = nullptr; }
            g_sc->ResizeBuffers(0, g_w, g_h, DXGI_FORMAT_UNKNOWN, 0);
            make_rtv();
        }
        return 0;
    }
    return DefWindowProcA(h, m, w, l);
}

int WINAPI WinMain(HINSTANCE inst, HINSTANCE, LPSTR, int show) {
    { HANDLE h = CreateFileA("port_early.txt", GENERIC_WRITE, FILE_SHARE_READ, nullptr, OPEN_ALWAYS, 0, nullptr);
      if (h != INVALID_HANDLE_VALUE) { char b[128]; DWORD n; void* hp = malloc(64); int l = wsprintfA(b, "WinMain start base=%p malloc=%p\r\n", GetModuleHandleA(nullptr), hp); WriteFile(h, b, l, &n, nullptr); CloseHandle(h); } }
    port_early_init();                                  // claim the guest address ranges before anything else allocates
    WNDCLASSA wc = {}; wc.lpfnWndProc = wndproc; wc.hInstance = inst; wc.lpszClassName = "TurokRW";
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    RegisterClassA(&wc);
    RECT r = {0, 0, g_w, g_h}; AdjustWindowRect(&r, WS_OVERLAPPEDWINDOW, FALSE);
    stage("early init done");
    HWND hwnd = CreateWindowA("TurokRW", "Turok: Rage Wars (port)", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                              CW_USEDEFAULT, CW_USEDEFAULT, r.right - r.left, r.bottom - r.top, nullptr, nullptr, inst, nullptr);
    DXGI_SWAP_CHAIN_DESC sd = {};
    sd.BufferCount = 2; sd.BufferDesc.Width = g_w; sd.BufferDesc.Height = g_h; sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; sd.OutputWindow = hwnd; sd.SampleDesc.Count = 1; sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    D3D_FEATURE_LEVEL fl;
    if (FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION,
                                            &sd, &g_sc, &g_dev, &fl, &g_ctx))) {
        MessageBoxA(hwnd, "Direct3D 11 device creation failed", "Turok port", MB_OK);
        return 1;
    }
    stage("d3d ok");
    make_rtv();
    renderer_init(g_dev, g_ctx);
    if (getenv("TUROK_DIFFTEST")) { port_difftest(); return 0; }
    if (!getenv("TUROK_SELFTEST")) port_game_init();
    stage("game init done");
    MSG msg = {};
    for (;;) {
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) return 0;
            TranslateMessage(&msg); DispatchMessageA(&msg);
        }
        port_game_frame();                                   // run one game frame (fills the display list)
        port_present_hook(g_ctx);
        renderer_frame(g_rtv, g_w, g_h);                     // draws the captured display list, blits it letterboxed
        g_sc->Present(0, DXGI_PRESENT_DO_NOT_WAIT);                  // no vsync wait: a locked/occluded display must not stall the game
        {   // 60 Hz pacing of our own
            static LARGE_INTEGER freq, next; LARGE_INTEGER now; QueryPerformanceCounter(&now);
            if (!freq.QuadPart) { QueryPerformanceFrequency(&freq); next = now; }
            next.QuadPart += freq.QuadPart / 60;
            if (next.QuadPart > now.QuadPart) Sleep((DWORD)((next.QuadPart - now.QuadPart) * 1000 / freq.QuadPart));
            else if (now.QuadPart - next.QuadPart > freq.QuadPart) next = now;
        }
    }
}
