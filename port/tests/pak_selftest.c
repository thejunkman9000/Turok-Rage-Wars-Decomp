/* Host-side self test of the virtual Controller Pak (port/pak.c, port/pak_os.c): no game, no ROM.
 * Builds with port\tests\pak_selftest.ps1.  The test includes both sources so it can reach their internals; libultra's message queues and
 * access semaphore are stubbed (SI transfers complete at once, exactly as in the port), __osPfsGetStatus is the standard routine. */
#define PAK_STANDALONE_TEST
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include "../pak.c"
#include "../pak_os.c"

/* ---- stubs for the rest of libultra ---- */
s32 osRecvMesg(OSMesgQueue *mq, OSMesg *m, s32 flags) { (void)mq; (void)m; (void)flags; return 0; }
s32 __osSiRawStartDma(s32 dir, void *pif_ram) { pak_si_dma(dir, pif_ram); return 0; }
void __osSiGetAccess(void) {}
void __osSiRelAccess(void) {}
u32 func_00447BB0(u32 q, u32 p, u32 c, u32 a3) { (void)q; (void)p; (void)c; (void)a3; return 0; }
u32 func_00448308(u32 a0, u32 a1, u32 a2, u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; return 0; }
/* the ROM's __osPfsGetStatus (0x4479D0), written out */
s32 __osPfsGetStatus(OSMesgQueue *queue, int channel) {
    unsigned i; unsigned char pkt[6]; s32 ret = 0; unsigned st, er;
    G_LAST_CMD = 0;
    st32(G_PFS_PIF + 60, 1);
    for (i = 0; i < (unsigned)channel; i++) G_PFS_PIF[i] = 0;
    G_PFS_PIF[channel + 0] = 1; G_PFS_PIF[channel + 1] = 3; G_PFS_PIF[channel + 2] = 0; G_PFS_PIF[channel + 3] = 0xFF; G_PFS_PIF[channel + 4] = 0xFF; G_PFS_PIF[channel + 5] = 0xFF; G_PFS_PIF[channel + 6] = 0xFE;
    __osSiRawStartDma(1, (void *)G_PFS_PIF); osRecvMesg(queue, NULL, 1);
    __osSiRawStartDma(0, (void *)G_PFS_PIF); osRecvMesg(queue, NULL, 1);
    for (i = 0; i < 6; i++) pkt[i] = G_PFS_PIF[channel + i];
    er = (pkt[1] & 0xC0) >> 4; st = pkt[5];
    if (er) return er == 8 ? 1 : 1;
    if (st & 1) { if (st & 2) return 2; if (st & 4) return 4; return ret; }
    return 1;
}

static int g_fail, g_pass;
#define CHECK(c) do { if (c) g_pass++; else { g_fail++; printf("FAIL line %d: %s\n", __LINE__, #c); } } while (0)

static OSMesgQueue *Q = (OSMesgQueue *)0x80100000u;
static wchar_t g_tmp[MAX_PATH];

static void wr_all(const wchar_t *path, const unsigned char *d, size_t n) { HANDLE h = CreateFileW(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL); DWORD w; WriteFile(h, d, (DWORD)n, &w, NULL); CloseHandle(h); }
static unsigned char *rd_all(const wchar_t *path, size_t *n) {
    HANDLE h = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL); DWORD sz, got; unsigned char *b;
    if (h == INVALID_HANDLE_VALUE) { *n = (size_t)-1; return NULL; }
    sz = GetFileSize(h, NULL); b = (unsigned char *)malloc(sz + 1); ReadFile(h, b, sz, &got, NULL); CloseHandle(h); *n = sz; return b;
}
static void fill_pat(unsigned char *d, int seed) { int i; for (i = 0; i < 32; i++) d[i] = (unsigned char)(seed * 31 + i * 7 + 3); }

/* wipes all module state; env: TUROK_SAVEDIR=g_tmp, nothing else */
static void reset(const wchar_t *savedir) {
    int i;
    for (i = 0; i < g_nfiles; i++) { free(g_files[i].data); }
    memset(g_files, 0, sizeof g_files); g_nfiles = 0; memset(g_port, 0, sizeof g_port); memset(&g_cfg, 0, sizeof g_cfg); g_nini = 0; g_init_state = 0; g_shutdown = 0; g_test_conn = 15;
    memset(g_pif, 0, sizeof g_pif); g_nhs = 0;
    SetEnvironmentVariableW(L"TUROK_SAVEDIR", savedir);
    SetEnvironmentVariableW(L"TUROK_PAK", NULL); SetEnvironmentVariableW(L"TUROK_PJ64_SAVE", NULL);
    for (i = 1; i <= 4; i++) { wchar_t k[32]; swprintf(k, 32, L"TUROK_PAK%d", i); SetEnvironmentVariableW(k, NULL); swprintf(k, 32, L"TUROK_PAK%d_TYPE", i); SetEnvironmentVariableW(k, NULL); }
    SetEnvironmentVariableW(L"TUROK_PAK_INI", L"D:\\nonexistent\\turok_pak.ini");
}

/* ---- tests ---------------------------------------------------------------------------------------------------------------------------- */
static void test_crc(void) {
    int b, i; unsigned char d[32]; static const int bits[11] = { 0x01, 0x1A, 0x0D, 0x1C, 0x0E, 0x07, 0x19, 0x16, 0x0B, 0x1F, 0x15 };
    for (b = 0; b < 0x800; b++) {                                  /* the n64brew formulation: XOR of per-bit values for address bits 15..5 */
        unsigned a = (unsigned)b << 5, crc = 0; for (i = 0; i < 11; i++) if (a & (1u << (15 - i))) crc ^= (unsigned)bits[i];
        if (pak_crc5((unsigned)b) != crc) { CHECK(0 && "crc5 vs table"); break; }
    }
    CHECK(pak_crc5(1) == 0x15 && pak_crc5(0x7FF) == 0x0D && pak_crc5(0x600) == 0x1B);
    memset(d, 0, 32); CHECK(pak_crc8(d) == 0x00);
    memset(d, 1, 32); CHECK(pak_crc8(d) == 0xEB);                  /* the CRC libultra expects for the rumble motor-on block */
    memset(d, 0x80, 32); CHECK(pak_crc8(d) == 0xB8);
    memset(d, 0xFF, 32); CHECK(pak_crc8(d) == 0x0A);
    for (i = 0; i < 32; i++) d[i] = (unsigned char)i; CHECK(pak_crc8(d) == 0x33);
    for (i = 0; i < 32; i++) d[i] = (unsigned char)(i * 7 + 3); CHECK(pak_crc8(d) == 0x8E);
}
static void test_format(void) {
    unsigned char img[PAK_SIZE], s[24]; char why[80]; int i;
    for (i = 0; i < 24; i++) s[i] = (unsigned char)(i * 11);
    pak_format_image(img, s);
    CHECK(image_check(img, why, sizeof why));
    CHECK(img[0x101] == 0x71 && img[0x201] == 0x71 && !memcmp(img + 0x100, img + 0x200, 0x100));
    CHECK(!memcmp(img + 0x20, img + 0x60, 32) && !memcmp(img + 0x20, img + 0xC0, 32) && !memcmp(img + 0x20, img + 0x80, 32));
    CHECK(img[0x20 + 25] == 1 && img[0x20 + 26] == 1);
    CHECK(img[0x105] == 0 && img[0x10A] == 0 && img[0x10B] == 3 && img[0x1FF] == 3);
    CHECK(!is_blank(img));
    memset(img, 0, sizeof img); CHECK(is_blank(img)); memset(img, 0xFF, sizeof img); CHECK(is_blank(img));
}
/* build a libultra style request: skip bytes + handshake(s) in a 64-byte PIF image */
static int hs(unsigned char *p, int pos, int tx, int rx, const unsigned char *txd) { p[pos] = (unsigned char)tx; p[pos + 1] = (unsigned char)rx; if (txd) memcpy(p + pos + 2, txd, (size_t)tx & 0x3F); return pos + 2 + (tx & 0x3F) + (rx & 0x3F); }
static void test_pif(void) {
    unsigned char pif[64], tx[4]; int pos, c;
    reset(g_tmp); pak_ensure_init();
    /* identify on all four channels, libultra's 8-byte request format; port 3 without controller, port 2 with a rumble pak, port 4 without accessory */
    g_port[1].type = PAK_RUMBLE; g_port[3].type = PAK_NONE; g_test_conn = 15 & ~4;
    memset(pif, 0, 64); pos = 0; tx[0] = 0;
    for (c = 0; c < 4; c++) { pif[pos++] = 0xFF; pos = hs(pif, pos, 1, 3, tx); pif[pos++] = 0xFF; pif[c * 8 + 4] = pif[c * 8 + 5] = pif[c * 8 + 6] = 0xEE; }
    pif[pos] = 0xFE; pif[63] = 1;
    pak_si_dma(1, pif); CHECK((g_pif[63] & 1) == 0);
    memset(pif, 0xAA, 64); pak_si_dma(0, pif);
    CHECK(pif[2] == 0x03 && pif[4] == 0x05 && pif[5] == 0x00 && pif[6] == 3);                  /* port 1: standard controller, memory pak, new -> 3 */
    CHECK(pif[10] == 0x03 && pif[12] == 0x05 && pif[14] == 3);                                 /* port 2: rumble pak, new -> 3 */
    CHECK((pif[18] & 0xC0) == 0x80 && pif[20] == 0xEE && pif[21] == 0xEE && pif[22] == 0xEE);  /* port 3: no controller, reply bytes untouched */
    CHECK(pif[26] == 0x03 && pif[28] == 0x05 && pif[30] == 2);                                 /* port 4: no accessory -> 2 */
    pak_si_dma(0, pif);                                                                        /* a second read re-executes the list: the latch is gone */
    CHECK(pif[6] == 1 && pif[14] == 1 && pif[30] == 2);
    /* unknown command -> timeout flag */
    memset(pif, 0, 64); pos = 0; tx[0] = 0x77; pif[pos++] = 0xFF; pos = hs(pif, pos, 1, 3, tx); pif[pos++] = 0xFF; pif[pos] = 0xFE; pif[63] = 1;
    pak_si_dma(1, pif); pak_si_dma(0, pif); CHECK((pif[2] & 0xC0) == 0x40);
    /* asking for more bytes than the device sends: the PIF delivers what there is and flags a timeout */
    memset(pif, 0, 64); pos = 0; tx[0] = 0; pif[pos++] = 0xFF; pos = hs(pif, pos, 1, 5, tx); pif[63] = 1;
    pak_si_dma(1, pif); pak_si_dma(0, pif); CHECK((pif[2] & 0xC0) == 0x40 && pif[4] == 0x05);
    /* TX bit 7: skip - the reply space is left alone */
    memset(pif, 0, 64); pif[0] = 0xFF; pif[1] = 0x81; pif[2] = 3; pif[3] = 0; pif[4] = 0x11; pif[5] = 0x22; pif[6] = 0x33; pif[7] = 0xFE; pif[63] = 1;
    pak_si_dma(1, pif); pak_si_dma(0, pif); CHECK(pif[4] == 0x11 && pif[5] == 0x22 && pif[6] == 0x33 && (pif[2] & 0xC0) == 0);
    /* incomplete handshake at the end of the frame (its lengths do not fit) is ignored */
    memset(pif, 0, 64); pif[0] = 1; pif[1] = 0x3F; pif[2] = 0; pif[63] = 1; pak_si_dma(1, pif); CHECK(g_nhs == 0);
    /* at most five channels are parsed */
    memset(pif, 0, 64); pos = 0; for (c = 0; c < 6; c++) pos = hs(pif, pos, 1, 1, tx); pif[63] = 1; pak_si_dma(1, pif); CHECK(g_nhs == 5);
    /* a write DMA without the run bit does not re-parse; the old list stays */
    memset(pif, 0, 64); pif[0] = 0xFE; pak_si_dma(1, pif); CHECK(g_nhs == 5);
    /* 0x00 skips a channel: the next handshake belongs to the next port (port 2 here) */
    memset(pif, 0, 64); pos = 0; tx[0] = 0; pif[pos++] = 0x00; pif[pos++] = 0xFF; pos = hs(pif, pos, 1, 3, tx); pif[pos] = 0xFE; pif[63] = 1; g_test_conn = 15;
    pak_si_dma(1, pif); CHECK(g_nhs == 1 && g_hs[0].chan == 1);
}
static void blk_rw(int ch, int write, unsigned blk, unsigned char *data, unsigned char *crc_out, unsigned *err_out) {
    unsigned char pif[64], tx[35]; int pos = 0, i; unsigned a16 = (blk << 5) | pak_crc5(blk);
    memset(pif, 0, 64); for (i = 0; i < ch; i++) pif[pos++] = 0;
    tx[0] = write ? 3 : 2; tx[1] = (unsigned char)(a16 >> 8); tx[2] = (unsigned char)a16; if (write) memcpy(tx + 3, data, 32);
    pif[pos++] = 0xFF; pos = hs(pif, pos, write ? 35 : 3, write ? 1 : 33, tx); pif[pos] = 0xFE; pif[63] = 1;
    { int base = ch + 1; pak_si_dma(1, pif); pak_si_dma(0, pif); if (err_out) *err_out = pif[base + 1] & 0xC0;
      if (write) { if (crc_out) *crc_out = pif[base + 2 + 35]; } else { if (data) memcpy(data, pif + base + 2 + 3, 32); if (crc_out) *crc_out = pif[base + 2 + 3 + 32]; } }
}
static void ident(int ch, unsigned char *st) {
    unsigned char pif[64], tx[1] = { 0 }; int pos = 0, i; memset(pif, 0, 64); for (i = 0; i < ch; i++) pif[pos++] = 0;
    pif[pos++] = 0xFF; pos = hs(pif, pos, 1, 3, tx); pif[pos] = 0xFE; pif[63] = 1; pak_si_dma(1, pif); pak_si_dma(0, pif);
    *st = pif[ch + 6];                                              /* 0xFF, TX, RX, cmd, type hi, type lo, status */
}
static void test_devices(void) {
    unsigned char d[32], r[32], crc, st; unsigned err; int i;
    reset(g_tmp); pak_ensure_init();
    ident(0, &st); CHECK(st == 3);                                    /* power-on: accessory present, "new" */
    ident(0, &st); CHECK(st == 1);
    fill_pat(d, 1); blk_rw(0, 1, 0x20, d, &crc, &err); CHECK(err == 0 && crc == pak_crc8(d));
    blk_rw(0, 0, 0x20, r, &crc, &err); CHECK(err == 0 && !memcmp(d, r, 32) && crc == pak_crc8(r));
    blk_rw(0, 0, 0x3FF, r, &crc, &err); CHECK(crc == pak_crc8(r)); for (i = 0; i < 32; i++) CHECK(r[i] == 0);        /* last SRAM block, never written */
    fill_pat(d, 2); blk_rw(0, 1, 0x400, d, &crc, &err); CHECK(err == 0 && crc == pak_crc8(d));   /* writes beyond the SRAM are acknowledged and dropped */
    blk_rw(0, 0, 0x400, r, &crc, &err); for (i = 0; i < 32; i++) CHECK(r[i] == 0);
    /* address CRC error: reads as no pak (zeros, CRC 0xFF), write refused with the complemented CRC, error bit in the next identify */
    {   unsigned char pif[64], tx[3]; int pos = 0; unsigned a16 = (0x20u << 5) | ((pak_crc5(0x20) ^ 1) & 31);
        memset(pif, 0, 64); tx[0] = 2; tx[1] = (unsigned char)(a16 >> 8); tx[2] = (unsigned char)a16; pif[pos++] = 0xFF; pos = hs(pif, pos, 3, 33, tx); pif[pos] = 0xFE; pif[63] = 1;
        pak_si_dma(1, pif); pak_si_dma(0, pif); CHECK(pif[1 + 2 + 3 + 32] == 0xFF && pif[6] == 0); }
    ident(0, &st); CHECK(st == (1 | 4)); ident(0, &st); CHECK(st == 1);
    /* write with a bad address CRC must not store */
    {   unsigned char pif[64], tx[35]; int pos = 0; unsigned a16 = (0x21u << 5) | ((pak_crc5(0x21) ^ 2) & 31); unsigned char *img;
        memset(pif, 0, 64); fill_pat(d, 9); tx[0] = 3; tx[1] = (unsigned char)(a16 >> 8); tx[2] = (unsigned char)a16; memcpy(tx + 3, d, 32); pif[pos++] = 0xFF; pos = hs(pif, pos, 35, 1, tx); pif[pos] = 0xFE; pif[63] = 1;
        pak_si_dma(1, pif); pak_si_dma(0, pif); CHECK(pif[1 + 2 + 35] == (unsigned char)~pak_crc8(d));
        img = port_img(&g_port[0]); CHECK(memcmp(img + 0x21 * 32, d, 32) != 0); }
    ident(0, &st);
    /* hot swap: removing and inserting sets the latch, a fresh accessory ignores access until the next identify */
    port_set_type(0, PAK_NONE, "test"); ident(0, &st); CHECK(st == 2);
    blk_rw(0, 0, 0x20, r, &crc, &err); CHECK(crc == 0xFF);
    port_set_type(0, PAK_MEMORY, "test"); blk_rw(0, 0, 0x20, r, &crc, &err); CHECK(crc == 0xFF);              /* ignored: not yet identified */
    ident(0, &st); CHECK(st == 3); fill_pat(d, 1); blk_rw(0, 0, 0x20, r, &crc, &err); CHECK(crc == pak_crc8(r) && !memcmp(r, d, 32));      /* the data survived the hot swap */
    /* rumble pak registers */
    port_set_type(1, PAK_RUMBLE, "test"); ident(1, &st);
    memset(d, 0xFE, 32); blk_rw(1, 1, 0x400, d, &crc, &err); CHECK(crc == pak_crc8(d)); blk_rw(1, 0, 0x400, r, &crc, &err); CHECK(r[31] == 0);
    memset(d, 0x80, 32); blk_rw(1, 1, 0x400, d, &crc, &err); blk_rw(1, 0, 0x400, r, &crc, &err); CHECK(r[31] == 0x80 && r[0] == 0x80);
    memset(d, 1, 32); blk_rw(1, 1, 0x600, d, &crc, &err); CHECK(crc == 0xEB && g_port[1].motor == 1 && pak_rumble_get(1) == 1);
    memset(d, 0, 32); blk_rw(1, 1, 0x600, d, &crc, &err); CHECK(g_port[1].motor == 0 && pak_rumble_get(1) == 0);
    blk_rw(1, 0, 0x20, r, &crc, &err); for (i = 0; i < 32; i++) CHECK(r[i] == 0);                   /* no SRAM in a rumble pak */
}
static void test_os(void) {
    unsigned char buf[32], r[32]; s32 ret; int i;
    reset(g_tmp); pak_ensure_init();
    ret = __osContRamRead(Q, 0, 0x20, buf); CHECK(ret == 2);                                          /* first access after power-on, no identify yet: PFS_ERR_NEW_PACK (via the status check) */
    ret = __osContRamRead(Q, 0, 0x20, buf); CHECK(ret == 0);
    fill_pat(buf, 4); ret = __osContRamWrite(Q, 0, 0x30, buf, 0); CHECK(ret == 0);
    ret = __osContRamRead(Q, 0, 0x30, r); CHECK(ret == 0 && !memcmp(buf, r, 32));
    /* the id area (blocks 1..6) is protected unless forced */
    fill_pat(buf, 5); ret = __osContRamWrite(Q, 0, 3, buf, 0); CHECK(ret == 0); __osContRamRead(Q, 0, 3, r); CHECK(memcmp(buf, r, 32) != 0);
    ret = __osContRamWrite(Q, 0, 3, buf, 1); CHECK(ret == 0); __osContRamRead(Q, 0, 3, r); CHECK(!memcmp(buf, r, 32));
    fill_pat(buf, 6); __osContRamWrite(Q, 0, 0, buf, 0); __osContRamRead(Q, 0, 0, r); CHECK(!memcmp(buf, r, 32));      /* block 0 is writable */
    /* port 2 has no controller, port 3 no pak */
    g_test_conn = 1 | 4 | 8; g_port[2].type = PAK_NONE;
    ret = __osContRamRead(Q, 1, 0x20, r); CHECK(ret == 1);                                            /* controller does not answer: PFS_ERR_NOPACK */
    ret = __osContRamRead(Q, 2, 0x20, r); CHECK(ret == 1);                                            /* no pak: CRC FF -> status check -> NOPACK */
    ret = __osContRamWrite(Q, 2, 0x20, buf, 0); CHECK(ret == 1);
    /* rumble probe: memory pak -> PFS_ERR_DEVICE(11), none -> 1, rumble pak -> 0 */
    { unsigned char pfs[0x70]; memset(pfs, 0, sizeof pfs);
      memset((void *)0x800D8380u, 0, 16);
      ret = pak_motor_init(Q, pfs, 0); CHECK(ret == 11);
      ret = pak_motor_init(Q, pfs, 2); CHECK(ret == 1);
      g_port[3].type = PAK_RUMBLE; g_port[3].changed = g_port[3].fresh = 1; { unsigned char st; ident(3, &st); }
      ret = pak_motor_init(Q, pfs, 3); CHECK(ret == 0);
      CHECK(be32(G_MOTOR_INIT(3)) == 1 && G_MSTART_DATA(3)[3] == 0xFF && G_MSTART_DATA(3)[3 + 1] == 0x23 && G_MSTART_DATA(3)[3 + 3] == 3);
      CHECK(be32(pfs + 8) == 3 && pfs[0x65] == 0x80);
      ret = pak_motor_start(pfs); CHECK(ret == 0 && pak_rumble_get(3) == 1);
      ret = pak_motor_stop(pfs); CHECK(ret == 0 && pak_rumble_get(3) == 0);
      ret = pak_motor_start(pfs); CHECK(ret == 0 && pak_rumble_get(3) == 1);
      port_set_type(3, PAK_NONE, "test"); ret = pak_motor_stop(pfs); CHECK(ret != 0);                  /* the pak was pulled */
      memset((void *)0x800D8380u, 0, 16);
      ret = pak_motor_start(pfs); CHECK(ret == 5);                                                    /* not initialised */
    }
    /* __osContGetInitData over a status request block */
    { volatile unsigned char *c = G_CONT_PIF; unsigned char pat; unsigned char d[16]; G_CONT_NUM = 4; memset((void *)0x8014D470u, 0, 64);
      for (i = 0; i < 4; i++) { c[i * 8] = 0xFF; c[i * 8 + 1] = 1; c[i * 8 + 2] = (i == 1) ? 0x83 : 3; c[i * 8 + 3] = 0; c[i * 8 + 4] = 0x05; c[i * 8 + 5] = 0; c[i * 8 + 6] = (unsigned char)(1 + i); c[i * 8 + 7] = 0xFF; }
      memset(d, 0xEE, 16); __osContGetInitData(&pat, (OSContStatus *)d);
      CHECK(pat == (1 | 4 | 8) && d[3] == 0 && d[7] == 8 && d[2] == 1 && d[6] == 0xEE && d[0] == 0 && d[1] == 5 && d[11] == 0 && d[10] == 3 && d[14] == 4); }
    /* osPfsIsPlug */
    { unsigned char pat = 0; g_test_conn = 15; g_port[0].type = PAK_MEMORY; g_port[1].type = PAK_NONE; g_port[2].type = PAK_RUMBLE; g_port[3].type = PAK_MEMORY;
      for (i = 0; i < 4; i++) { unsigned char st; ident(i, &st); }
      ret = osPfsIsPlug(Q, &pat); CHECK(ret == 0 && pat == (1 | 4 | 8)); }
}

/* ---- file backend ------------------------------------------------------------------------------------------------------------------- */
static void mkdir_w(const wchar_t *p) { CreateDirectoryW(p, NULL); }
static void path_in(wchar_t *out, const wchar_t *dir, const wchar_t *leaf) { wjoin(out, MAX_PATH, dir, leaf); }
static void del_tree(const wchar_t *dir) {
    wchar_t pat[MAX_PATH]; WIN32_FIND_DATAW fd; HANDLE h; wjoin(pat, MAX_PATH, dir, L"*"); h = FindFirstFileW(pat, &fd);
    if (h != INVALID_HANDLE_VALUE) { do { wchar_t f[MAX_PATH]; if (!wcscmp(fd.cFileName, L".") || !wcscmp(fd.cFileName, L"..")) continue; wjoin(f, MAX_PATH, dir, fd.cFileName); SetFileAttributesW(f, FILE_ATTRIBUTE_NORMAL); if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) del_tree(f); else DeleteFileW(f); } while (FindNextFileW(h, &fd)); FindClose(h); }
    RemoveDirectoryW(dir);
}
static void write_block_port(int port, unsigned blk, int seed) { unsigned char d[32], crc; unsigned err; fill_pat(d, seed); blk_rw(port, 1, blk, d, &crc, &err); }

static void test_files(void) {
    wchar_t dir[MAX_PATH], f[MAX_PATH]; size_t n; unsigned char *b, img[PAK_SIZE], ser[24] = { 0 }; unsigned char st;
    reset(g_tmp); GetTempPathW(MAX_PATH, dir); wcscat(dir, L"pak_selftest_files"); del_tree(dir); mkdir_w(dir); wset(g_tmp, MAX_PATH, dir);
    /* 1. first run, no saves folder: created; the new image is a valid formatted pak and is written */
    { wchar_t sub[MAX_PATH]; path_in(sub, dir, L"fresh\\saves"); reset(sub); pak_ensure_init(); ident(0, &st); write_block_port(0, 0x40, 1);
      pak_flush_all(1); path_in(f, sub, L"Turok; Rage Wars_Cont_1.mpk"); b = rd_all(f, &n); CHECK(b && n == PAK_SIZE); if (b) { char why[80]; unsigned char t[32]; fill_pat(t, 1); CHECK(image_check(b, why, sizeof why)); CHECK(!memcmp(b + 0x40 * 32, t, 32)); free(b); }
      CHECK(g_port[0].file && g_port[0].file->persist); CHECK(g_nfiles == 1); }
    /* 2. an existing raw image is loaded and left untouched when only read */
    reset(dir); path_in(f, dir, L"Turok; Rage Wars_Cont_1.mpk"); new_serial(ser); pak_format_image(img, ser); img[0x500] = 0x42; wr_all(f, img, PAK_SIZE);
    pak_ensure_init(); { unsigned char r[32]; ident(0, &st); blk_rw(0, 0, 0x500 / 32, r, NULL, NULL); CHECK(r[0] == 0x42); }
    pak_flush_all(1); { FILETIME a; WIN32_FILE_ATTRIBUTE_DATA d; GetFileAttributesExW(f, GetFileExInfoStandard, &d); a = d.ftLastWriteTime; (void)a; } CHECK(!g_port[0].file->dirty);
    /* 3. DexDrive container: header preserved, pak at 0x1040 */
    reset(dir); path_in(f, dir, L"dex.n64"); { unsigned char *dx = (unsigned char *)calloc(1, 0x9040); memcpy(dx, "123-456-STD\0", 12); memcpy(dx + 0x40, "comment", 8); memcpy(dx + 0x1040, img, PAK_SIZE); wr_all(f, dx, 0x9040); free(dx); }
    SetEnvironmentVariableW(L"TUROK_PAK1", f); pak_ensure_init(); ident(0, &st); write_block_port(0, 0x41, 2); pak_flush_all(1);
    b = rd_all(f, &n); CHECK(b && n == 0x9040 && !memcmp(b, "123-456-STD\0", 12) && !memcmp(b + 0x40, "comment", 8)); { unsigned char t[32]; fill_pat(t, 2); CHECK(b && !memcmp(b + 0x1040 + 0x41 * 32, t, 32)); } free(b);
    /* 4. 4-in-1: port 3 uses slice 3 (index 2), the other slices are not touched; "#k" picks a slice */
    reset(dir); path_in(f, dir, L"four.mpk"); { unsigned char *q = (unsigned char *)malloc(4 * PAK_SIZE); int k; for (k = 0; k < 4; k++) { new_serial(ser); pak_format_image(q + k * PAK_SIZE, ser); } wr_all(f, q, 4 * PAK_SIZE); free(q); }
    b = rd_all(f, &n); { unsigned char *orig = b; wchar_t e2[MAX_PATH]; SetEnvironmentVariableW(L"TUROK_PAK3", f); swprintf(e2, MAX_PATH, L"%ls#4", f); SetEnvironmentVariableW(L"TUROK_PAK2", e2);
      pak_ensure_init(); ident(2, &st); ident(1, &st); write_block_port(2, 0x42, 3); write_block_port(1, 0x43, 4); CHECK(g_port[2].file == g_port[1].file); pak_flush_all(1);
      b = rd_all(f, &n); CHECK(b && n == 4 * PAK_SIZE); if (b) { unsigned char t[32]; fill_pat(t, 3); CHECK(!memcmp(b + 2 * PAK_SIZE + 0x42 * 32, t, 32)); fill_pat(t, 4); CHECK(!memcmp(b + 3 * PAK_SIZE + 0x43 * 32, t, 32));
        CHECK(!memcmp(b, orig, 2 * PAK_SIZE)); CHECK(!memcmp(b + 2 * PAK_SIZE + 0x1000, orig + 2 * PAK_SIZE + 0x1000, 0x1000)); free(b); } free(orig); }
    /* 5. short, oversized, blank, read-only, locked */
    reset(dir); path_in(f, dir, L"short.mpk"); { unsigned char s100[100]; memset(s100, 0x11, 100); wr_all(f, s100, 100); }
    SetEnvironmentVariableW(L"TUROK_PAK1", f); pak_ensure_init(); ident(0, &st); write_block_port(0, 0x44, 5); pak_flush_all(1);
    b = rd_all(f, &n); CHECK(b && n == PAK_SIZE && b[0] == 0x11); free(b); { wchar_t o[MAX_PATH]; swprintf(o, MAX_PATH, L"%ls.orig", f); b = rd_all(o, &n); CHECK(b && n == 100); free(b); }
    reset(dir); path_in(f, dir, L"big.mpk"); { unsigned char *big = (unsigned char *)calloc(1, PAK_SIZE + 1234); memcpy(big, img, PAK_SIZE); memcpy(big + PAK_SIZE, "MPKMeta trailer", 15); wr_all(f, big, PAK_SIZE + 1234); free(big); }
    SetEnvironmentVariableW(L"TUROK_PAK1", f); pak_ensure_init(); ident(0, &st); write_block_port(0, 0x45, 6); pak_flush_all(1);
    b = rd_all(f, &n); CHECK(b && n == PAK_SIZE + 1234 && !memcmp(b + PAK_SIZE, "MPKMeta trailer", 15)); free(b);
    reset(dir); path_in(f, dir, L"blank.mpk"); memset(img, 0, PAK_SIZE); wr_all(f, img, PAK_SIZE); SetEnvironmentVariableW(L"TUROK_PAK1", f); pak_ensure_init(); ident(0, &st);
    { unsigned char r[32]; blk_rw(0, 0, 1, r, NULL, NULL); } pak_flush_all(1); b = rd_all(f, &n); { char why[80]; CHECK(b && image_check(b, why, sizeof why)); } free(b);
    reset(dir); path_in(f, dir, L"ro.mpk"); new_serial(ser); pak_format_image(img, ser); wr_all(f, img, PAK_SIZE); SetFileAttributesW(f, FILE_ATTRIBUTE_READONLY);
    SetEnvironmentVariableW(L"TUROK_PAK1", f); pak_ensure_init(); ident(0, &st); write_block_port(0, 0x46, 7); pak_flush_all(1);
    CHECK(g_port[0].file && !g_port[0].file->persist); b = rd_all(f, &n); CHECK(b && !memcmp(b, img, PAK_SIZE)); free(b); { unsigned char r[32], t[32]; fill_pat(t, 7); blk_rw(0, 0, 0x46, r, NULL, NULL); CHECK(!memcmp(r, t, 32)); }   /* session copy works */
    SetFileAttributesW(f, FILE_ATTRIBUTE_NORMAL);
    reset(dir); path_in(f, dir, L"locked.mpk"); wr_all(f, img, PAK_SIZE);
    { HANDLE lk = CreateFileW(f, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL); SetEnvironmentVariableW(L"TUROK_PAK1", f); pak_ensure_init(); ident(0, &st); write_block_port(0, 0x47, 8); pak_flush_all(1);
      CHECK(g_port[0].file && !g_port[0].file->persist); CloseHandle(lk); }
    /* a write that cannot be done now stays pending and is retried: lock the file after loading it */
    reset(dir); path_in(f, dir, L"late.mpk"); wr_all(f, img, PAK_SIZE); SetEnvironmentVariableW(L"TUROK_PAK1", f); pak_ensure_init(); ident(0, &st); write_block_port(0, 0x48, 9);
    { HANDLE lk = CreateFileW(f, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL); CHECK(!file_flush(g_port[0].file, 1)); CHECK(g_port[0].file->dirty && g_port[0].file->fails >= 1); CloseHandle(lk); }
    CHECK(file_flush(g_port[0].file, 1)); b = rd_all(f, &n); { unsigned char t[32]; fill_pat(t, 9); CHECK(b && !memcmp(b + 0x48 * 32, t, 32)); } free(b);
    /* 6. image replaced on disk while the pak is out: reloaded on insert */
    path_in(f, dir, L"late.mpk"); port_set_type(0, PAK_NONE, "test"); { unsigned char *x = (unsigned char *)malloc(PAK_SIZE); new_serial(ser); pak_format_image(x, ser); x[0x900] = 0x77; Sleep(30); wr_all(f, x, PAK_SIZE); free(x); }
    port_set_type(0, PAK_MEMORY, "test"); ident(0, &st); { unsigned char r[32]; blk_rw(0, 0, 0x900 / 32, r, NULL, NULL); CHECK(r[0] == 0x77); }
    /* 7. env precedence over the ini file, ini parsing, port types */
    reset(dir); path_in(f, dir, L"t.ini"); { const char *ini = "; comment\nsavedir=ini_saves\nname=My; Game\nport2 = rumble\nport3=none\npak4=\"C:\\x\\y.mpk\"\nwriteback_ms=50\n"; HANDLE h = CreateFileW(f, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL); DWORD w; WriteFile(h, ini, (DWORD)strlen(ini), &w, NULL); CloseHandle(h); }
    SetEnvironmentVariableW(L"TUROK_PAK_INI", f); SetEnvironmentVariableW(L"TUROK_SAVEDIR", NULL); SetEnvironmentVariableW(L"TUROK_PAK3_TYPE", L"memory"); config_load();
    CHECK(wcsstr(g_cfg.savedir, L"ini_saves") != NULL); CHECK(!wcscmp(g_cfg.name, L"My; Game")); CHECK(g_cfg.type[0] == PAK_MEMORY && g_cfg.type[1] == PAK_RUMBLE && g_cfg.type[2] == PAK_MEMORY && g_cfg.type[3] == PAK_MEMORY);
    CHECK(!wcscmp(g_cfg.pakpath[3], L"C:\\x\\y.mpk") && g_cfg.delay_ms == 50);
    SetEnvironmentVariableW(L"TUROK_PAK3_TYPE", NULL); SetEnvironmentVariableW(L"TUROK_PAK", L"0"); config_load(); CHECK(g_cfg.type[0] == PAK_NONE && g_cfg.type[1] == PAK_NONE);
    /* 8. Project64 save folder discovery: <name>_Cont_<n>.mpk, per-game sub folder, older <name>.mpk */
    SetEnvironmentVariableW(L"TUROK_PAK", NULL); SetEnvironmentVariableW(L"TUROK_PAK_INI", L"D:\\nonexistent\\turok_pak.ini");
    { wchar_t pj[MAX_PATH], sub[MAX_PATH], fp[MAX_PATH], res[MAX_PATH]; int sl; path_in(pj, dir, L"Save"); mkdir_w(pj);
      path_in(f, pj, L"Turok; Rage Wars_Cont_2.mpk"); wr_all(f, img, PAK_SIZE); path_in(f, pj, L"Other Game_Cont_1.mpk"); wr_all(f, img, PAK_SIZE);
      path_in(sub, pj, L"Turok; Rage Wars-0123456789abcdef0123456789abcdef"); mkdir_w(sub); path_in(fp, sub, L"Turok; Rage Wars_Cont_1.mpk"); wr_all(fp, img, PAK_SIZE);
      path_in(f, pj, L"turok- rage wars.mpk"); wr_all(f, img, PAK_SIZE);
      reset(dir); SetEnvironmentVariableW(L"TUROK_PJ64_SAVE", pj); config_load();
      resolve_path(0, res, &sl); CHECK(wcsstr(res, L"0123456789abcdef") != NULL);                           /* _Cont_1 in the unique folder beats the legacy name */
      resolve_path(1, res, &sl); CHECK(wcsstr(res, L"Turok; Rage Wars_Cont_2.mpk") != NULL && !wcsstr(res, L"Other"));
      resolve_path(2, res, &sl); CHECK(wcsstr(res, L"saves") != NULL || wcsstr(res, dir) != NULL);          /* nothing there for port 3: default folder */
      SetEnvironmentVariableW(L"TUROK_PAK1", L"explicit.mpk#3"); config_load(); resolve_path(0, res, &sl); CHECK(wcsstr(res, L"explicit.mpk") != NULL && sl == 2 && !wcschr(res, L'#')); }
    /* mupen64plus style: one "<game>-<md5>.mpk" holding the four paks serves every port (slice = port); a single 32 KiB prefix match serves port 1 only */
    { wchar_t pj[MAX_PATH], res[MAX_PATH]; int sl; unsigned char *q = (unsigned char *)calloc(1, 4 * PAK_SIZE);
      path_in(pj, dir, L"Save2"); mkdir_w(pj); path_in(f, pj, L"Turok - Rage Wars (U) [!]-1A2B3C4D.mpk"); wr_all(f, q, 4 * PAK_SIZE); free(q);
      reset(dir); SetEnvironmentVariableW(L"TUROK_PJ64_SAVE", pj); config_load();
      resolve_path(2, res, &sl); CHECK(wcsstr(res, L"1A2B3C4D") != NULL && sl == 2);
      resolve_path(3, res, &sl); CHECK(wcsstr(res, L"1A2B3C4D") != NULL && sl == 3);
      path_in(f, pj, L"Turok - Rage Wars (U) [!]-1A2B3C4D.mpk"); DeleteFileW(f); path_in(f, pj, L"turokragewars-single.mpk"); wr_all(f, (const unsigned char *)"x", 1); { unsigned char *one = (unsigned char *)calloc(1, PAK_SIZE); wr_all(f, one, PAK_SIZE); free(one); }
      resolve_path(0, res, &sl); CHECK(wcsstr(res, L"turokragewars-single") != NULL);
      resolve_path(1, res, &sl); CHECK(wcsstr(res, L"turokragewars-single") == NULL); }
    /* 9. quotes around a path in an environment variable (cmd: set X="a b") are stripped; an explicit pak file in a folder that does not exist yet gets its folder */
    { wchar_t v[MAX_PATH], sub[MAX_PATH];
      SetEnvironmentVariableW(L"TUROK_SELFTEST_Q", L"\"C:\\a b\\c\""); CHECK(envw(L"TUROK_SELFTEST_Q", v, MAX_PATH) && !wcscmp(v, L"C:\\a b\\c"));
      SetEnvironmentVariableW(L"TUROK_SELFTEST_Q", L"\"\""); CHECK(!envw(L"TUROK_SELFTEST_Q", v, MAX_PATH));
      SetEnvironmentVariableW(L"TUROK_SELFTEST_Q", L"\"x"); CHECK(envw(L"TUROK_SELFTEST_Q", v, MAX_PATH) && !wcscmp(v, L"\"x"));
      SetEnvironmentVariableW(L"TUROK_SELFTEST_Q", NULL);
      reset(dir); path_in(sub, dir, L"newdir\\deeper\\x.mpk"); SetEnvironmentVariableW(L"TUROK_PAK1", sub); pak_ensure_init(); ident(0, &st); write_block_port(0, 0x49, 10); pak_flush_all(1);
      b = rd_all(sub, &n); CHECK(b && n == PAK_SIZE); free(b); CHECK(g_port[0].file && g_port[0].file->persist); }
    del_tree(dir);
}

int main(void) {
    SYSTEM_INFO si; GetSystemInfo(&si);
    if (!VirtualAlloc((void *)0x80000000u, 0x800000, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE)) { printf("cannot reserve the guest RAM at 0x80000000 (link with /LARGEADDRESSAWARE)\n"); return 2; }
    GetTempPathW(MAX_PATH, g_tmp); wcscat(g_tmp, L"pak_selftest");
    test_crc(); test_format(); test_pif(); test_devices(); test_os(); test_files();
    printf("pak_selftest: %d checks passed, %d failed\n", g_pass, g_fail);
    return g_fail ? 1 : 0;
}
