#!/usr/bin/env python3
"""One-shot patch: adds the TUROK_MAPDUMP map-capture module to port/renderer.cpp (idempotent)."""
p = 'port/renderer.cpp'
s = open(p, newline='').read()
crlf = '\r\n' in s
s = s.replace('\r\n', '\n')
if 'capRecord' in s:
    raise SystemExit('already patched')

def rep(old, new, cnt=1):
    global s
    assert old in s, old[:60]
    s = s.replace(old, new, cnt)

rep("struct V { float cx, cy, cz, cw; float r, g, b, a; float s, t; };",
    "struct V { float cx, cy, cz, cw; float r, g, b, a; float s, t; float wx, wy, wz; };")
rep("float mv[10][16]; int mvTop; float proj[16]; float mvp[16]; bool mvpDirty;",
    "float mv[10][16]; int mvTop; float proj[16]; float mvp[16]; bool mvpDirty; float camInv[16]; bool camSet;")

cap = r'''
// ---- map capture (TUROK_MAPDUMP=1): accumulates the static world triangles of every frame (world space = vertex * modelview * inverse(first
// modelview load after the projection load), i.e. the camera matrix undone) and, when port_mapdump.txt appears (its first line is the
// output name), writes mapdump/<name>/map.obj + map.mtl (textures in mapdump/tex_*.tga).  A triangle is exported once it was seen in
// >= TUROK_MAPSEEN (default 3) frames at the same world position, which drops moving actors and the first-person weapon.
// port_mapreset.txt clears the accumulated triangles.
static std::map<ID3D11ShaderResourceView*, uint64_t> srvKey;
struct CapTri { float p[3][3]; float uv[3][2]; uint8_t c[3][4]; uint64_t tex; int seen; int lastFrame; };
static std::unordered_map<uint64_t, CapTri> capTris;
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
static void capRecord(const V* v[3], ID3D11ShaderResourceView* srv, float tw, float th, float uls, float ult, int frame) {
    CapTri t; memset(&t, 0, sizeof t);
    float sScale = S.texScaleS / 65536.f, tScale = S.texScaleT / 65536.f;
    uint64_t h = 1469598103934665603ull;
    for (int i = 0; i < 3; i++) {
        t.p[i][0] = v[i]->wx; t.p[i][1] = v[i]->wy; t.p[i][2] = v[i]->wz;
        t.uv[i][0] = (v[i]->s / 32.f * sScale - uls / 4.f) / tw; t.uv[i][1] = (v[i]->t / 32.f * tScale - ult / 4.f) / th;
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
'''
rep("static void pushVtx(const V& v,", cap + "\nstatic void pushVtx(const V& v,")
rep("    setupState(0);\n    const Tile& t = S.tile[S.texTile & 7];\n    if (batch.size() + 12",
    "    setupState(0);\n    const Tile& t = S.tile[S.texTile & 7];\n    if (capOn()) { const V* cv[3] = { v[0], v[1], v[2] }; capRecord(cv, cur.texOn ? cur.srv : nullptr, (float)curTexW, (float)curTexH, (float)t.uls, (float)t.ult, g_nfpub); }\n    if (batch.size() + 12")
rep("        o.s = (int16_t)rd16(p + 8); o.t = (int16_t)rd16(p + 10);\n",
    "        o.s = (int16_t)rd16(p + 8); o.t = (int16_t)rd16(p + 10);\n"
    "        if (capOn()) { const float* mv = S.mv[S.mvTop]; float vx = x * mv[0] + y * mv[4] + z * mv[8] + mv[12], vy = x * mv[1] + y * mv[5] + z * mv[9] + mv[13], vz = x * mv[2] + y * mv[6] + z * mv[10] + mv[14]; const float* c = S.camInv; o.wx = vx * c[0] + vy * c[4] + vz * c[8] + c[12]; o.wy = vx * c[1] + vy * c[5] + vz * c[9] + c[13]; o.wz = vx * c[2] + vy * c[6] + vz * c[10] + c[14]; }\n")
rep("            if (f & 4) { if (f & 2) memcpy(S.proj, m, 64); else matMul(m, S.proj, S.proj); }",
    "            if (f & 4) { if (f & 2) { memcpy(S.proj, m, 64); S.camSet = false; } else matMul(m, S.proj, S.proj); }")
rep("                if (f & 2) memcpy(S.mv[S.mvTop], m, 64); else matMul(m, S.mv[S.mvTop], S.mv[S.mvTop]);",
    "                if (f & 2) memcpy(S.mv[S.mvTop], m, 64); else matMul(m, S.mv[S.mvTop], S.mv[S.mvTop]);\n                if (capOn() && !S.camSet) { if (!matInv(S.mv[S.mvTop], S.camInv)) matIdent(S.camInv); S.camSet = true; }")
rep("matIdent(S.proj); for (int i = 0; i < 10; i++) matIdent(S.mv[i]); S.mvpDirty = true;",
    "matIdent(S.proj); matIdent(S.camInv); for (int i = 0; i < 10; i++) matIdent(S.mv[i]); S.mvpDirty = true;")
rep("    texCache[key] = sv; g_texdecodes++; return sv;",
    "    texCache[key] = sv; if (sv) srvKey[sv] = key; if (capOn()) capTexture(key, px, w, h); g_texdecodes++; return sv;")
rep("        if (g_dump) { fclose(g_dump); g_dump = nullptr; }\n        if (nframes == 299",
    "        if (g_dump) { fclose(g_dump); g_dump = nullptr; }\n"
    "        if (capOn() && (nframes & 15) == 0) { FILE* tf = fopen(\"port_mapdump.txt\", \"r\"); if (tf) { char nm[100] = \"map\"; if (fscanf(tf, \"%99s\", nm) != 1) strcpy(nm, \"map\"); fclose(tf); DeleteFileA(\"port_mapdump.txt\"); capWrite(nm); } if (GetFileAttributesA(\"port_mapreset.txt\") != INVALID_FILE_ATTRIBUTES) { DeleteFileA(\"port_mapreset.txt\"); capTris.clear(); } }\n"
    "        if (nframes == 299")
if crlf: s = s.replace('\n', '\r\n')
open(p, 'w', newline='').write(s)
print('patched')
