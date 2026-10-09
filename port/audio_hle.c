/* libultra aspMain (ABI1) audio microcode HLE. Layout notes in AUDIO_HLE.md.
 * DMEM is kept as a big-endian byte array so DMA load/save are plain copies. */
#include <stdio.h>
#include "audio_hle.h"
#include <string.h>
#include <math.h>

#ifndef AUDIO_HLE_VOL_SHIFT
#define AUDIO_HLE_VOL_SHIFT 15   /* envmixer: sample * vol >> shift (0x7FFF ~ unity) */
#endif

static struct {
    audio_hle_translate_fn xlat;
    uint8_t  dmem[AUDIO_HLE_DMEM_SIZE];
    uint32_t seg[16];
    int16_t  book[256];            /* ADPCM codebook (8 predictors x 2 x 8 coefs, up to 16) */
    int      book_n;               /* number of int16 entries loaded */
    uint32_t loop;                 /* A_SETLOOP address (resolved) */
    uint16_t in, out, count;
    uint16_t dry_right, wet_left, wet_right;
    int16_t  vol[2], target[2];
    int32_t  rate[2];
    int16_t  dry, wet;
    uint32_t last_addr, last_bytes;
    int      have_save;
    uint32_t unknown;
} S;

static int16_t resamp_tab[64][4];
static int tab_ready;

static int16_t clamp16(int32_t v) { return v > 32767 ? 32767 : v < -32768 ? -32768 : (int16_t)v; }
static uint32_t be32(const uint8_t *p) { return ((uint32_t)p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]; }
static int16_t be16(const uint8_t *p) { return (int16_t)((p[0] << 8) | p[1]); }
static void put16(uint8_t *p, int16_t v) { p[0] = (uint8_t)((uint16_t)v >> 8); p[1] = (uint8_t)v; }
static void put32(uint8_t *p, uint32_t v) { p[0] = (uint8_t)(v >> 24); p[1] = (uint8_t)(v >> 16); p[2] = (uint8_t)(v >> 8); p[3] = (uint8_t)v; }

#define DM(a) (S.dmem[(a) & 0xFFF])
static int16_t dm_rd(uint32_t a) { return (int16_t)((DM(a) << 8) | DM(a + 1)); }
static void dm_wr(uint32_t a, int16_t v) { DM(a) = (uint8_t)((uint16_t)v >> 8); DM(a + 1) = (uint8_t)v; }

static uint8_t *resolve(uint32_t a)
{
    uint32_t r = S.seg[(a >> 24) & 0xF] + (a & 0xFFFFFF);
    return S.xlat ? S.xlat(r) : NULL;
}
static uint32_t resolve_addr(uint32_t a) { return S.seg[(a >> 24) & 0xF] + (a & 0xFFFFFF); }

static void build_table(void)
{
    int i;
    if (tab_ready) return;
    for (i = 0; i < 64; i++) { /* Catmull-Rom cubic; NOT the original ucode table */
        double t = i / 64.0, t2 = t * t, t3 = t2 * t;
        double c[4];
        int k;
        c[0] = -0.5 * t3 + t2 - 0.5 * t;
        c[1] = 1.5 * t3 - 2.5 * t2 + 1.0;
        c[2] = -1.5 * t3 + 2.0 * t2 + 0.5 * t;
        c[3] = 0.5 * t3 - 0.5 * t2;
        for (k = 0; k < 4; k++) resamp_tab[i][k] = (int16_t)floor(c[k] * 32768.0 + 0.5);
    }
    tab_ready = 1;
}

void audio_hle_reset(void)
{
    audio_hle_translate_fn x = S.xlat;
    memset(&S, 0, sizeof S);
    S.xlat = x;
    build_table();
}

void audio_hle_init(audio_hle_translate_fn translate)
{
    memset(&S, 0, sizeof S);
    S.xlat = translate;
    build_table();
}

uint8_t *audio_hle_dmem(void) { return S.dmem; }
uint32_t audio_hle_unknown_count(void) { return S.unknown; }
int audio_hle_last_save(uint32_t *addr, uint32_t *bytes)
{
    if (!S.have_save) return 0;
    if (addr) *addr = S.last_addr;
    if (bytes) *bytes = S.last_bytes;
    return 1;
}

/* ---- commands -------------------------------------------------------- */

static void op_clearbuff(uint32_t w0, uint32_t w1)
{
    uint32_t a = w0 & 0xFFFF, n = w1 & 0xFFFF, i;
    for (i = 0; i < n; i++) DM(a + i) = 0;
}

static void dma_in(uint16_t dst, uint32_t addr, uint32_t n)
{
    const uint8_t *p = resolve(addr);
    uint32_t i;
    for (i = 0; i < n; i++) DM(dst + i) = p ? p[i] : 0;
}

static void op_loadbuff(uint32_t w1) { dma_in(S.in, w1, S.count); }

static void op_savebuff(uint32_t w1)
{
    uint8_t *p = resolve(w1);
    uint32_t i;
    if (p) for (i = 0; i < S.count; i++) p[i] = DM(S.out + i);
    S.last_addr = resolve_addr(w1);
    S.last_bytes = S.count;
    S.have_save = 1;
}

static void op_setbuff(uint32_t w0, uint32_t w1)
{
    if ((w0 >> 16) & A_AUX) {
        S.dry_right = (uint16_t)w0;
        S.wet_left = (uint16_t)(w1 >> 16);
        S.wet_right = (uint16_t)w1;
    } else {
        S.in = (uint16_t)w0;
        S.out = (uint16_t)(w1 >> 16);
        S.count = (uint16_t)w1;
    }
}

static void op_setvol(uint32_t w0, uint32_t w1)
{
    uint32_t f = (w0 >> 16) & 0xFF;
    int lr = (f & A_LEFT) ? 0 : 1;
    if (f & A_AUX) {
        S.dry = (int16_t)w0;
        S.wet = (int16_t)w1;
    } else if (f & A_VOL) {
        S.vol[lr] = (int16_t)w0;
    } else {
        S.target[lr] = (int16_t)w0;
        S.rate[lr] = (int32_t)w1;
    }
}

static void op_dmemmove(uint32_t w0, uint32_t w1)
{
    uint32_t src = w0 & 0xFFFF, dst = w1 >> 16, n = w1 & 0xFFFF, i;
    uint8_t tmp[AUDIO_HLE_DMEM_SIZE];
    for (i = 0; i < n; i++) tmp[i & 0xFFF] = DM(src + i);
    for (i = 0; i < n; i++) DM(dst + i) = tmp[i & 0xFFF];
}

static void op_loadadpcm(uint32_t w0, uint32_t w1)
{
    uint32_t n = (w0 & 0xFFFFFF) / 2, i;
    const uint8_t *p = resolve(w1);
    if (n > 256) n = 256;
    S.book_n = (int)n;
    for (i = 0; i < n; i++) S.book[i] = p ? be16(p + 2 * i) : 0;
}

static void op_adpcm(uint32_t w0, uint32_t w1)
{
    uint32_t f = (w0 >> 16) & 0xFF, frames, fr;
    uint8_t *st = resolve(w1);
    const uint8_t *src = st;
    int16_t last[16];
    uint32_t in = S.in, out = S.out;
    int k;

    if (f & A_INIT) src = NULL;
    else if (f & A_LOOP) src = resolve(S.loop);
    for (k = 0; k < 16; k++) last[k] = src ? be16(src + 2 * k) : 0;

    frames = ((uint32_t)S.count + 31) / 32;
    for (fr = 0; fr < frames; fr++) {
        uint8_t hdr = DM(in);
        int scale = hdr >> 4, pred = hdr & 0xF, h, i, j;
        const int16_t *b1, *b2;
        int16_t o[16];
        int32_t res[16];

        if ((pred + 1) * 16 > S.book_n) pred = 0;
        b1 = S.book + pred * 16;
        b2 = b1 + 8;
        for (j = 0; j < 16; j++) {
            int n = DM(in + 1 + j / 2);
            n = (j & 1) ? (n & 0xF) : (n >> 4);
            if (n >= 8) n -= 16;
            res[j] = n * (1 << scale);
        }
        for (h = 0; h < 2; h++) {
            int32_t l1 = h ? o[6] : last[14];
            int32_t l2 = h ? o[7] : last[15];
            const int32_t *fm = res + h * 8;
            for (i = 0; i < 8; i++) {
                int32_t acc = fm[i] * 2048 + b1[i] * l1 + b2[i] * l2;
                for (j = 0; j < i; j++) acc += fm[i - j - 1] * b2[j];
                o[h * 8 + i] = clamp16(acc >> 11);
            }
        }
        for (j = 0; j < 16; j++) dm_wr(out + 2 * j, o[j]);
        memcpy(last, o, sizeof last);
        in += 9;
        out += 32;
    }
    if (st) for (k = 0; k < 16; k++) put16(st + 2 * k, last[k]);
}

static void op_resample(uint32_t w0, uint32_t w1)
{
    uint32_t f = (w0 >> 16) & 0xFF;
    uint32_t step = (uint32_t)(w0 & 0xFFFF) << 1;   /* 16.16; field 0x8000 = ratio 1.0 */
    uint8_t *st = resolve(w1);
    int16_t hist[4] = {0, 0, 0, 0};
    uint32_t pos = 0, n = S.count / 2, k, consumed;

    if (!(f & A_INIT) && st) {
        for (k = 0; k < 4; k++) hist[k] = be16(st + 2 * k);
        pos = (uint16_t)be16(st + 8);
    }
#define X(i) (((int32_t)(i)) < 0 ? hist[4 + (i)] : dm_rd(S.in + 2 * (uint32_t)(i)))
    for (k = 0; k < n; k++) {
        int32_t i = (int32_t)(pos >> 16), fr = (int32_t)((pos >> 10) & 63);
        const int16_t *c = resamp_tab[fr];
        int32_t acc = c[0] * (int32_t)X(i - 1) + c[1] * (int32_t)X(i) +
                      c[2] * (int32_t)X(i + 1) + c[3] * (int32_t)X(i + 2);
        dm_wr(S.out + 2 * k, clamp16((acc + 16384) >> 15));
        pos += step;
    }
    consumed = pos >> 16;
    if (st) {
        for (k = 0; k < 4; k++) put16(st + 2 * k, X((int32_t)consumed - 4 + (int32_t)k));
        put16(st + 8, (int16_t)(pos & 0xFFFF));
        put16(st + 10, 0); put16(st + 12, 0); put16(st + 14, 0);
    }
#undef X
}

static void ramp(int32_t *v, int32_t step, int32_t target)
{
    *v += step;
    if ((step < 0 && *v < target) || (step > 0 && *v > target)) *v = target;
}

/* state: 6 x int32 (value L/R, target L/R, rate L/R) + dry,wet int16 + pad = 32 bytes */
static void op_envmixer(uint32_t w0, uint32_t w1)
{
    uint32_t f = (w0 >> 16) & 0xFF, k, n = S.count / 2;
    uint8_t *st = resolve(w1);
    int32_t val[2], tgt[2], rate[2];
    int16_t dry = S.dry, wet = S.wet;
    int lr;

    if ((f & A_INIT) || !st) {
        for (lr = 0; lr < 2; lr++) {
            val[lr] = (int32_t)S.vol[lr] << 16;
            tgt[lr] = (int32_t)S.target[lr] << 16;
            rate[lr] = S.rate[lr];
        }
    } else {
        for (lr = 0; lr < 2; lr++) {
            val[lr] = (int32_t)be32(st + 4 * lr);
            tgt[lr] = (int32_t)be32(st + 8 + 4 * lr);
            rate[lr] = (int32_t)be32(st + 16 + 4 * lr);
        }
        dry = be16(st + 24);
        wet = be16(st + 26);
    }
    for (k = 0; k < n; k++) {
        int32_t s = dm_rd(S.in + 2 * k), l, r, o;
        ramp(&val[0], rate[0] / 8, tgt[0]);
        ramp(&val[1], rate[1] / 8, tgt[1]);
        l = (s * (val[0] >> 16)) >> AUDIO_HLE_VOL_SHIFT;
        r = (s * (val[1] >> 16)) >> AUDIO_HLE_VOL_SHIFT;
        o = S.out + 2 * k;
        dm_wr(o, clamp16(dm_rd(o) + ((l * dry) >> 15)));
        o = S.dry_right + 2 * k;
        dm_wr(o, clamp16(dm_rd(o) + ((r * dry) >> 15)));
        o = S.wet_left + 2 * k;
        dm_wr(o, clamp16(dm_rd(o) + ((l * wet) >> 15)));
        o = S.wet_right + 2 * k;
        dm_wr(o, clamp16(dm_rd(o) + ((r * wet) >> 15)));
    }
    if (st) {
        for (lr = 0; lr < 2; lr++) {
            put32(st + 4 * lr, (uint32_t)val[lr]);
            put32(st + 8 + 4 * lr, (uint32_t)tgt[lr]);
            put32(st + 16 + 4 * lr, (uint32_t)rate[lr]);
        }
        put16(st + 24, dry); put16(st + 26, wet);
        put32(st + 28, 0);
    }
}

static void op_mixer(uint32_t w0, uint32_t w1)
{
    int32_t gain = (int16_t)w0;
    uint32_t in = w1 >> 16, out = w1 & 0xFFFF, k, n = S.count / 2;
    for (k = 0; k < n; k++)
        dm_wr(out + 2 * k, clamp16(dm_rd(out + 2 * k) + ((dm_rd(in + 2 * k) * gain) >> 15)));
}

static void op_interleave(uint32_t w1)
{
    uint32_t l = w1 >> 16, r = w1 & 0xFFFF, k, n = S.count / 4;
    for (k = 0; k < n; k++) {
        int16_t a = dm_rd(l + 2 * k), b = dm_rd(r + 2 * k);
        dm_wr(S.out + 4 * k, a);
        dm_wr(S.out + 4 * k + 2, b);
    }
}

int audio_hle_run_ptr(const uint8_t *cmds, uint32_t byte_len)
{
    uint32_t off;
    int n = 0;
    for (off = 0; off + 8 <= byte_len; off += 8, n++) {
        uint32_t w0 = be32(cmds + off), w1 = be32(cmds + off + 4);
        switch (w0 >> 24) {
        case A_SPNOOP: break;
        case A_ADPCM: op_adpcm(w0, w1); break;
        case A_CLEARBUFF: op_clearbuff(w0, w1); break;
        case A_ENVMIXER: op_envmixer(w0, w1); break;
        case A_LOADBUFF: op_loadbuff(w1); break;
        case A_RESAMPLE: op_resample(w0, w1); break;
        case A_SAVEBUFF: op_savebuff(w1); break;
        case A_SEGMENT: S.seg[(w1 >> 24) & 0xF] = w1 & 0xFFFFFF; break;
        case A_SETBUFF: op_setbuff(w0, w1); break;
        case A_SETVOL: op_setvol(w0, w1); break;
        case A_DMEMMOVE: op_dmemmove(w0, w1); break;
        case A_LOADADPCM: op_loadadpcm(w0, w1); break;
        case A_MIXER: op_mixer(w0, w1); break;
        case A_INTERLEAVE: op_interleave(w1); break;
        case A_POLEF: S.unknown++; break;          /* not implemented */
        case A_SETLOOP: S.loop = w1; break;        /* resolved lazily at A_ADPCM time */
        default: S.unknown++; break;
        }
    }
    return n;
}

int audio_hle_run(uint32_t cmd_list_addr, uint32_t byte_len)
{
    const uint8_t *p = S.xlat ? S.xlat(cmd_list_addr & 0x1FFFFFFF) : NULL;
    return p ? audio_hle_run_ptr(p, byte_len) : -1;
}
