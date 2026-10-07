// Renderer self test (TUROK_SELFTEST=1): builds a small F3DEX2 display list in guest RAM and presents it every frame, so that the
// display-list interpreter, vertex transform, TMEM texture decode, combiner and blending can be checked without the game.
// Included from renderer.cpp.

static void put32(uint8_t* p, uint32_t v) { p[0] = (uint8_t)(v >> 24); p[1] = (uint8_t)(v >> 16); p[2] = (uint8_t)(v >> 8); p[3] = (uint8_t)v; }
static void put16(uint8_t* p, uint32_t v) { p[0] = (uint8_t)(v >> 8); p[1] = (uint8_t)v; }

static uint32_t comb(int a0, int b0, int c0, int d0, int Aa0, int Ab0, int Ac0, int Ad0, int a1, int b1, int c1, int d1, int Aa1, int Ab1, int Ac1, int Ad1, uint32_t* w1) {
    *w1 = ((uint32_t)b0 << 28) | ((uint32_t)b1 << 24) | ((uint32_t)Aa1 << 21) | ((uint32_t)Ac1 << 18) | ((uint32_t)d0 << 15) | ((uint32_t)Ab0 << 12) | ((uint32_t)Ad0 << 9) | ((uint32_t)d1 << 6) | ((uint32_t)Ab1 << 3) | (uint32_t)Ad1;
    return (0xFCu << 24) | ((uint32_t)a0 << 20) | ((uint32_t)c0 << 15) | ((uint32_t)Aa0 << 12) | ((uint32_t)Ac0 << 9) | ((uint32_t)a1 << 5) | (uint32_t)c1;
}

static void selftest_present() {
    static bool built = false;
    uint8_t* base = (uint8_t*)(size_t)0x80700000u;          // guest RAM (committed at start-up); the game thread is not running in this mode
    uint8_t* dl = base; uint8_t* vtx = base + 0x4000; uint8_t* tex = base + 0x5000; uint8_t* mtx = base + 0x5400; uint8_t* vp = base + 0x5500;
    if (!built) {
        built = true;
        // 8x8 RGBA5551 checkerboard (red / yellow)
        for (int y = 0; y < 8; y++) for (int x = 0; x < 8; x++) {
            bool c = ((x >> 1) + (y >> 1)) & 1; uint16_t px = c ? (31 << 11 | 31 << 6 | 0 << 1 | 1) : (31 << 11 | 4 << 6 | 4 << 1 | 1);
            put16(tex + (y * 8 + x) * 2, px);
        }
        // projection: scale 1/200 (s15.16): int part 0, fraction 0.005 * 65536 = 328; w row = 1.0
        memset(mtx, 0, 64);
        auto setm = [&](int i, float v) { int32_t fx = (int32_t)(v * 65536.0f); put16(mtx + i * 2, (uint32_t)(fx >> 16) & 0xFFFF); put16(mtx + 32 + i * 2, (uint32_t)fx & 0xFFFF); };
        setm(0, 0.005f); setm(5, 0.005f); setm(10, 0.005f); setm(15, 1.0f);
        // viewport: 480x360 screen in 10.2 fixed point
        put16(vp + 0, 960); put16(vp + 2, (uint32_t)(-720) & 0xFFFF); put16(vp + 4, 511); put16(vp + 6, 0); put16(vp + 8, 960); put16(vp + 10, 720); put16(vp + 12, 511); put16(vp + 14, 0);
        // vertices: 0-2 shaded triangle, 3-6 textured quad
        struct V { int x, y, z, s, t; uint8_t r, g, b, a; } v[7] = {
            { -150, -100, 0, 0, 0, 255, 0, 0, 255 }, { 150, -100, 0, 0, 0, 0, 255, 0, 255 }, { 0, 120, 0, 0, 0, 0, 0, 255, 255 },
            { -280, 80, 0, 0, 0, 255, 255, 255, 255 }, { -140, 80, 0, 256, 0, 255, 255, 255, 255 }, { -140, 190, 0, 256, 256, 255, 255, 255, 255 }, { -280, 190, 0, 0, 256, 255, 255, 255, 255 } };
        for (int i = 0; i < 7; i++) { uint8_t* p = vtx + i * 16; put16(p, (uint32_t)v[i].x & 0xFFFF); put16(p + 2, (uint32_t)v[i].y & 0xFFFF); put16(p + 4, (uint32_t)v[i].z & 0xFFFF); put16(p + 6, 0);
            put16(p + 8, (uint32_t)v[i].s & 0xFFFF); put16(p + 10, (uint32_t)v[i].t & 0xFFFF); p[12] = v[i].r; p[13] = v[i].g; p[14] = v[i].b; p[15] = v[i].a; }
        uint32_t* w = nullptr; uint8_t* q = dl;
        auto emit = [&](uint32_t a, uint32_t b) { put32(q, a); put32(q + 4, b); q += 8; };
        (void)w;
        emit(0xDB060000u, 0);                                           // segment 0 = 0
        emit(0xFF10011Fu, 0x80600000u);                                 // colour image
        emit(0xFE000000u, 0x80500000u);                                 // z image
        emit(0xF7000000u, 0x00430043u);                                 // fill colour (dark blue)
        emit(0xF6000000u | (479 * 4) << 12 | (359 * 4), 0);             // fill rect
        emit(0xDC080008u, (uint32_t)(size_t)vp);                        // viewport
        emit(0xDA380007u, (uint32_t)(size_t)mtx);                       // projection load
        emit(0xD9FFFFFFu, 0x00200004u);                                 // shade, smooth shading
        { uint32_t w1; uint32_t w0 = comb(15, 15, 31, 4, 7, 7, 7, 4, 15, 15, 31, 4, 7, 7, 7, 4, &w1); emit(w0, w1); }   // SHADE
        emit(0xD7000000u, 0xFFFFFFFFu);                                 // texture off
        emit(0x01000000u | (3 << 12) | ((0 + 3) << 1), (uint32_t)(size_t)vtx);
        emit(0x05000000u | (0 << 16) | (2 << 8) | 4, 0);                // triangle 0,1,2 (indices * 2)
        // textured quad: load the texture into TMEM via LOADBLOCK
        emit(0xFD100007u, (uint32_t)(size_t)tex);                       // texture image RGBA16, width 8
        emit(0xF5100000u | (2 << 9) | 0, 0x07000000u);                  // tile 7: RGBA16 line 2 tmem 0
        emit(0xE6000000u, 0);
        emit(0xF3000000u | (0 << 12) | 0, (7u << 24) | (63u << 12) | 0x400);   // load block 64 texels, dxt
        emit(0xE7000000u, 0);
        emit(0xF5100000u | (2 << 9) | 0, 0x00000000u);                  // tile 0: RGBA16 line 2 tmem 0, wrap
        emit(0xF2000000u, (0u << 24) | (28u << 12) | 28u);              // tile size 8x8
        emit(0xD7000002u, 0xFFFFFFFFu);                                 // texture on, tile 0
        emit(0xE3000C00u, 0x00002000u);                                 // bilinear off/on is not important
        { uint32_t w1; uint32_t w0 = comb(1, 15, 4, 7, 1, 7, 4, 7, 1, 15, 4, 7, 1, 7, 4, 7, &w1); emit(w0, w1); }   // TEXEL0 * SHADE
        emit(0x01000000u | (4 << 12) | ((3 + 4) << 1), (uint32_t)(size_t)(vtx + 3 * 16));
        emit(0x06000000u | (3 * 2 << 16) | (4 * 2 << 8) | (5 * 2), (3 * 2 << 16) | (5 * 2 << 8) | (6 * 2));   // two triangles (v indices relative to the buffer)
        emit(0xDF000000u, 0);
    }
    // a fake RSP task pointing at the display list
    put32(g_gfx_task + 0x30, 0x80700000u); put32(g_gfx_task + 0x34, 0x400);
    InterlockedExchange(&g_gfx_task_ready, 1);
}
