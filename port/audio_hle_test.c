/* Standalone test for audio_hle.c.
 * zig: python -m ziglang cc -target x86-windows-msvc -O1 audio_hle_test.c audio_hle.c -o audio_hle_test.exe */
#include "audio_hle.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static uint8_t ram[1 << 20];
static int fails, checks;
#define CHECK(c, ...) do { checks++; if (!(c)) { fails++; printf("FAIL line %d: ", __LINE__); printf(__VA_ARGS__); printf("\n"); } } while (0)

static uint8_t *xlat(uint32_t a) { return a < sizeof ram ? ram + a : NULL; }

static void w32(uint8_t *p, uint32_t v) { p[0] = v >> 24; p[1] = v >> 16; p[2] = v >> 8; p[3] = v; }
static void w16(uint8_t *p, int v) { p[0] = (uint8_t)(v >> 8); p[1] = (uint8_t)v; }
static int r16(const uint8_t *p) { return (int16_t)((p[0] << 8) | p[1]); }

static uint8_t cl[4096];
static int ncl;
static void cmd(uint32_t w0, uint32_t w1) { w32(cl + ncl * 8, w0); w32(cl + ncl * 8 + 4, w1); ncl++; }
static void run(void) { audio_hle_run_ptr(cl, ncl * 8); ncl = 0; }
#define OP(o, f, lo) (((uint32_t)(o) << 24) | ((uint32_t)(f) << 16) | ((lo) & 0xFFFF))

static uint32_t rng = 12345;
static int rnd(void) { rng = rng * 1103515245u + 12345u; return (rng >> 16) & 0x7FFF; }

/* ---- independent textbook VADPCM reference (matrix form) ---- */
static int16_t book[8][2][8];
static int sat(long v) { return v > 32767 ? 32767 : v < -32768 ? -32768 : (int)v; }
static void ref_decode(const uint8_t *src, int frames, int16_t *out, int16_t st[16])
{
    int f;
    for (f = 0; f < frames; f++, src += 9) {
        int scale = src[0] >> 4, pred = src[0] & 15, h, i, j;
        int q[16];
        for (j = 0; j < 16; j++) {
            int n = (j & 1) ? (src[1 + j / 2] & 15) : (src[1 + j / 2] >> 4);
            q[j] = (n > 7 ? n - 16 : n) << scale;
        }
        for (h = 0; h < 2; h++) {
            int16_t *o = out + f * 16 + h * 8;
            long p1 = h ? o[-2] : (f ? out[f * 16 - 2] : st[14]);
            long p2 = h ? o[-1] : (f ? out[f * 16 - 1] : st[15]);
            for (i = 0; i < 8; i++) {
                long a = (long)q[h * 8 + i] * 2048 + book[pred][0][i] * p1 + book[pred][1][i] * p2;
                for (j = 0; j < i; j++) a += (long)q[h * 8 + j] * book[pred][1][i - 1 - j];
                o[i] = (int16_t)sat(a >> 11);
            }
        }
    }
}

enum { BOOK = 0x1000, SRC = 0x2000, STATE = 0x3000, OUT = 0x4000, ENV = 0x5000, RS = 0x6000, STATE2 = 0x7000 };

static void make_codebook(void)
{
    int p, v, i;
    for (p = 0; p < 8; p++) for (v = 0; v < 2; v++) for (i = 0; i < 8; i++) {
        book[p][v][i] = (int16_t)((rnd() % 4000) - 2000);
        w16(ram + BOOK + ((p * 2 + v) * 8 + i) * 2, book[p][v][i]);
    }
}

static void test_adpcm(void)
{
    enum { F = 8 };
    int16_t ref[F * 16], zero[16] = {0};
    int f, i, bad = 0;
    for (f = 0; f < F; f++) {
        ram[SRC + f * 9] = (uint8_t)(((rnd() % 6) << 4) | (rnd() % 8));
        for (i = 1; i < 9; i++) ram[SRC + f * 9 + i] = (uint8_t)rnd();
    }
    ref_decode(ram + SRC, F, ref, zero);

    audio_hle_reset();
    cmd(OP(A_LOADADPCM, 0, 0) | 256, BOOK);
    cmd(OP(A_SETBUFF, 0, 0x200), (0x400u << 16) | (F * 9));
    cmd(OP(A_LOADBUFF, 0, 0), SRC);
    cmd(OP(A_SETBUFF, 0, 0x200), (0x400u << 16) | (F * 32));
    cmd(OP(A_ADPCM, A_INIT, 0), STATE);
    cmd(OP(A_SAVEBUFF, 0, 0), OUT);
    run();
    for (i = 0; i < F * 16; i++) if (r16(ram + OUT + 2 * i) != ref[i]) bad++;
    CHECK(bad == 0, "adpcm single call: %d mismatches", bad);
    CHECK(r16(ram + STATE + 30) == ref[F * 16 - 1], "adpcm state not saved");

    /* two calls of 4 frames, second continues from saved state (no INIT) */
    audio_hle_reset();
    memset(ram + OUT, 0, 512);
    cmd(OP(A_LOADADPCM, 0, 0) | 256, BOOK);
    cmd(OP(A_SETBUFF, 0, 0x200), (0x400u << 16) | (4 * 9));
    cmd(OP(A_LOADBUFF, 0, 0), SRC);
    cmd(OP(A_SETBUFF, 0, 0x200), (0x400u << 16) | (4 * 32));
    cmd(OP(A_ADPCM, A_INIT, 0), STATE2);
    cmd(OP(A_SAVEBUFF, 0, 0), OUT);
    cmd(OP(A_SETBUFF, 0, 0x200), (0x400u << 16) | (4 * 9));
    cmd(OP(A_LOADBUFF, 0, 0), SRC + 36);
    cmd(OP(A_SETBUFF, 0, 0x200), (0x400u << 16) | (4 * 32));
    cmd(OP(A_ADPCM, 0, 0), STATE2);
    cmd(OP(A_SAVEBUFF, 0, 0), OUT + 128);
    run();
    bad = 0;
    for (i = 0; i < F * 16; i++) if (r16(ram + OUT + 2 * i) != ref[i]) bad++;
    CHECK(bad == 0, "adpcm split call: %d mismatches", bad);
}

static void load_samples(const int16_t *s, int n, int dmem_dst_unused)
{
    int i;
    (void)dmem_dst_unused;
    for (i = 0; i < n; i++) w16(ram + SRC + 2 * i, s[i]);
}

static void test_resample(void)
{
    int16_t in[256], out1[64], i;
    int bad = 0, k;
    for (i = 0; i < 256; i++) in[i] = (int16_t)(i * 100 - 5000);   /* linear ramp */
    load_samples(in, 256, 0);

    /* ratio 1.0 */
    audio_hle_reset();
    cmd(OP(A_SETBUFF, 0, 0x100), (0x400u << 16) | 512);
    cmd(OP(A_LOADBUFF, 0, 0), SRC);
    cmd(OP(A_SETBUFF, 0, 0x100), (0x800u << 16) | 128);   /* 64 out samples */
    cmd(OP(A_RESAMPLE, A_INIT, 0x8000), RS);
    cmd(OP(A_SAVEBUFF, 0, 0), OUT);
    /* SAVEBUFF uses S.out=0x800, count 128 */
    run();
    for (k = 0; k < 64; k++) if (r16(ram + OUT + 2 * k) != in[k]) bad++;
    CHECK(bad == 0, "resample 1.0: %d mismatches", bad);

    /* ratio 0.5 : out[2k]==in[k], out[2k+1] ~ midpoint (cubic exact on a ramp) */
    audio_hle_reset();
    cmd(OP(A_SETBUFF, 0, 0x100), (0x400u << 16) | 512);
    cmd(OP(A_LOADBUFF, 0, 0), SRC);
    cmd(OP(A_SETBUFF, 0, 0x100), (0x800u << 16) | 128);
    cmd(OP(A_RESAMPLE, A_INIT, 0x4000), RS);
    cmd(OP(A_SAVEBUFF, 0, 0), OUT);
    run();
    for (k = 0; k < 64; k++) out1[k] = (int16_t)r16(ram + OUT + 2 * k);
    bad = 0;
    for (k = 0; k < 32; k++) {
        if (out1[2 * k] != in[k]) bad++;
        if (k > 0 && abs(out1[2 * k + 1] - (in[k] + 50)) > 2) bad++;   /* k=0 sees zero history */
    }
    CHECK(bad == 0, "resample 0.5: %d mismatches (out[0]=%d out[1]=%d)", bad, out1[0], out1[1]);

    /* split: two 32-sample calls == one 64-sample call (state carry) */
    audio_hle_reset();
    cmd(OP(A_SETBUFF, 0, 0x100), (0x400u << 16) | 512);
    cmd(OP(A_LOADBUFF, 0, 0), SRC);
    cmd(OP(A_SETBUFF, 0, 0x100), (0x800u << 16) | 64);
    cmd(OP(A_RESAMPLE, A_INIT, 0x4000), RS);
    cmd(OP(A_SAVEBUFF, 0, 0), OUT + 256);
    cmd(OP(A_SETBUFF, 0, 0x100 + 32), (0x800u << 16) | 64);   /* consumed 16 samples = 32 bytes */
    cmd(OP(A_RESAMPLE, 0, 0x4000), RS);
    cmd(OP(A_SAVEBUFF, 0, 0), OUT + 256 + 64);
    run();
    bad = 0;
    for (k = 0; k < 64; k++) if (r16(ram + OUT + 256 + 2 * k) != out1[k]) bad++;
    CHECK(bad == 0, "resample split: %d mismatches", bad);
}

static void test_envmix(void)
{
    int16_t in[256];
    int k, bad = 0;
    int vol = 0, v32 = 0;
    for (k = 0; k < 256; k++) in[k] = 10000;
    load_samples(in, 256, 0);
    audio_hle_reset();
    memset(ram + OUT, 0, 2048);
    cmd(OP(A_SETBUFF, 0, 0x100), (0x600u << 16) | 512);
    cmd(OP(A_LOADBUFF, 0, 0), SRC);
    cmd(OP(A_SETBUFF, A_AUX, 0x800), ((uint32_t)0xA00 << 16) | 0xC00);  /* dry_right, wet_l, wet_r */
    cmd(OP(A_SETVOL, A_VOL | A_LEFT, 0), 0);
    cmd(OP(A_SETVOL, A_VOL, 0), 0);
    cmd(OP(A_SETVOL, A_LEFT, 0x4000), 0x02000000);   /* step = rate/8 = 64 vol units per sample (16.16) */
    cmd(OP(A_SETVOL, 0, 0x4000), 0);                 /* right: rate 0 -> stays at vol 0 */
    cmd(OP(A_SETVOL, A_AUX, 0), (0x7FFFu << 16) | 0x4000);
    cmd(OP(A_ENVMIXER, A_INIT, 0), ENV);
    cmd(OP(A_SAVEBUFF, 0, 0), OUT);
    run();
    for (k = 0; k < 256; k++) {
        int32_t l;
        v32 += 64 << 16; if (v32 > (0x4000 << 16)) v32 = 0x4000 << 16;
        vol = v32 >> 16;
        l = (10000 * vol) >> 15;
        if (r16(ram + OUT + 2 * k) != ((l * 0x7FFF) >> 15)) bad++;
    }
    CHECK(bad == 0, "envmixer left ramp: %d mismatches", bad);
    CHECK(r16(ram + OUT + 2) > r16(ram + OUT), "ramp not rising");
    CHECK(r16(ram + OUT + 510) == ((((10000 * 0x4000) >> 15) * 0x7FFF) >> 15), "ramp end %d", r16(ram + OUT + 510));
    CHECK(((uint8_t *)audio_hle_dmem())[0x800] == 0 && r16(audio_hle_dmem() + 0x800 + 100) == 0, "right should be silent");

    /* continue: second call without INIT must hold the plateau and keep wet */
    cmd(OP(A_ENVMIXER, 0, 0), ENV);
    run();
    {
        int16_t wl = (int16_t)r16(audio_hle_dmem() + 0xA00 + 2);
        CHECK(wl > 0, "wet not mixed");
    }
}

static void test_end_to_end(void)
{
    enum { F = 4, CL = 0x9000, SEGBASE = 0x10000 };
    int16_t ref[F * 16], zero[16] = {0};
    int f, i, bad = 0, nz = 0;
    uint32_t a, b;
    /* data at segment 5 offset: segment base 0x10000, so seg-5 address 0x05000000+off */
    uint8_t *seg = ram + SEGBASE;
    for (f = 0; f < F; f++) {
        seg[f * 9] = (uint8_t)((3 << 4) | (f & 3));
        for (i = 1; i < 9; i++) seg[f * 9 + i] = (uint8_t)rnd();
    }
    memcpy(seg + 0x100, ram + BOOK, 256);
    ref_decode(seg, F, ref, zero);

    audio_hle_reset();
    ncl = 0;
    cmd(OP(A_SEGMENT, 0, 0), (5u << 24) | SEGBASE);
    cmd(OP(A_LOADADPCM, 0, 0) | 256, 0x05000100u);
    cmd(OP(A_SETBUFF, 0, 0x200), (0x400u << 16) | (F * 9));
    cmd(OP(A_LOADBUFF, 0, 0), 0x05000000u);
    cmd(OP(A_SETBUFF, 0, 0x200), (0x400u << 16) | (F * 32));
    cmd(OP(A_SETLOOP, 0, 0), 0x80000000u | STATE);
    cmd(OP(A_ADPCM, A_INIT, 0), 0x80000000u | STATE);
    /* resample 1:1 from 0x400 to 0x600 */
    cmd(OP(A_SETBUFF, 0, 0x400), (0x600u << 16) | (F * 32));
    cmd(OP(A_RESAMPLE, A_INIT, 0x8000), 0x80000000u | RS);
    /* env mix: left vol 0x4000 fixed, right 0x2000 fixed; dry = 0x7FFF */
    cmd(OP(A_SETBUFF, 0, 0x600), (0x800u << 16) | (F * 32));
    cmd(OP(A_SETBUFF, A_AUX, 0xA00), ((uint32_t)0xC00 << 16) | 0xE00);
    cmd(OP(A_CLEARBUFF, 0, 0x800), F * 32);
    cmd(OP(A_CLEARBUFF, 0, 0xA00), F * 32);
    cmd(OP(A_SETVOL, A_VOL | A_LEFT, 0x4000), 0);
    cmd(OP(A_SETVOL, A_VOL, 0x2000), 0);
    cmd(OP(A_SETVOL, A_LEFT, 0x4000), 0);
    cmd(OP(A_SETVOL, 0, 0x2000), 0);
    cmd(OP(A_SETVOL, A_AUX, 0), (0x7FFFu << 16));
    cmd(OP(A_ENVMIXER, A_INIT, 0), 0x80000000u | ENV);
    /* interleave L=0x800, R=0xA00 into 0x1000 : count = out bytes = 2*F*32 */
    cmd(OP(A_SETBUFF, 0, 0), (0xF00u << 16) | (F * 64));
    cmd(OP(A_INTERLEAVE, 0, 0), (0x800u << 16) | 0xA00);
    cmd(OP(A_SAVEBUFF, 0, 0), 0x80000000u | OUT);
    memcpy(ram + CL, cl, ncl * 8);
    i = ncl;
    ncl = 0;
    CHECK(audio_hle_run(0x80000000u | CL, i * 8) == i, "command count");
    CHECK(audio_hle_last_save(&a, &b) && a == OUT && b == F * 64, "last_save a=%x b=%u", a, b);
    CHECK(audio_hle_unknown_count() == 0, "unknown ops");
    for (i = 0; i < F * 16; i++) {
        int s = ref[i];
        int l = (s * 0x4000) >> 15, r = (s * 0x2000) >> 15;
        l = (l * 0x7FFF) >> 15; r = (r * 0x7FFF) >> 15;
        if (r16(ram + OUT + 4 * i) != l || r16(ram + OUT + 4 * i + 2) != r) bad++;
        if (l) nz++;
    }
    CHECK(bad == 0, "end-to-end: %d mismatches", bad);
    CHECK(nz > 10, "end-to-end output looks silent");
}

int main(void)
{
    audio_hle_init(xlat);
    make_codebook();
    test_adpcm();
    test_resample();
    test_envmix();
    test_end_to_end();
    printf("%d checks, %d failures\n", checks, fails);
    return fails != 0;
}
