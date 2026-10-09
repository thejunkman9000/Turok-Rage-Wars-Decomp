/* libultra aspMain (ABI1) audio microcode HLE. Layout notes in AUDIO_HLE.md.
 * DMEM is kept as a big-endian byte array so DMA load/save are plain copies. */
#include <stdio.h>
#include <stdlib.h>
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

/* the 64-phase 4-tap interpolation table of the audio microcode (taps apply to the 4 samples before the input position) */
static const int16_t RESAMPLE_LUT[64][4] = {
    {0x0c39, 0x66ad, 0x0d46, -0x0021}, {0x0b39, 0x6696, 0x0e5f, -0x0028}, {0x0a44, 0x6669, 0x0f83, -0x0030}, {0x095a, 0x6626, 0x10b4, -0x0038},
    {0x087d, 0x65cd, 0x11f0, -0x0041}, {0x07ab, 0x655e, 0x1338, -0x004a}, {0x06e4, 0x64d9, 0x148c, -0x0054}, {0x0628, 0x643f, 0x15eb, -0x005f},
    {0x0577, 0x638f, 0x1756, -0x006a}, {0x04d1, 0x62cb, 0x18cb, -0x0076}, {0x0435, 0x61f3, 0x1a4c, -0x0082}, {0x03a4, 0x6106, 0x1bd7, -0x008f},
    {0x031c, 0x6007, 0x1d6c, -0x009c}, {0x029f, 0x5ef5, 0x1f0b, -0x00aa}, {0x022a, 0x5dd0, 0x20b3, -0x00b8}, {0x01be, 0x5c9a, 0x2262, -0x00c6},
    {0x015b, 0x5b53, 0x2419, -0x00d4}, {0x0101, 0x59fc, 0x25d7, -0x00e2}, {0x00ae, 0x5896, 0x279a, -0x00f0}, {0x0063, 0x5720, 0x2961, -0x00fe},
    {0x001f, 0x559d, 0x2b2c, -0x010c}, {-0x001e, 0x540d, 0x2cf9, -0x0118}, {-0x0054, 0x5270, 0x2ec8, -0x0125}, {-0x0084, 0x50c7, 0x3097, -0x0130},
    {-0x00ad, 0x4f14, 0x3266, -0x013a}, {-0x00d2, 0x4d57, 0x3432, -0x0143}, {-0x00f1, 0x4b91, 0x35fb, -0x014a}, {-0x010b, 0x49c2, 0x37bf, -0x0150},
    {-0x0121, 0x47ed, 0x397e, -0x0154}, {-0x0132, 0x4611, 0x3b37, -0x0155}, {-0x0140, 0x4430, 0x3ce8, -0x0154}, {-0x014a, 0x424a, 0x3e91, -0x0151},
    {-0x0151, 0x4060, 0x4030, -0x014a}, {-0x0151, 0x3e91, 0x424a, -0x014a}, {-0x0154, 0x3ce8, 0x4430, -0x0140}, {-0x0155, 0x3b37, 0x4611, -0x0132},
    {-0x0154, 0x397e, 0x47ed, -0x0121}, {-0x0150, 0x37bf, 0x49c2, -0x010b}, {-0x014a, 0x35fb, 0x4b91, -0x00f1}, {-0x0143, 0x3432, 0x4d57, -0x00d2},
    {-0x013a, 0x3266, 0x4f14, -0x00ad}, {-0x0130, 0x3097, 0x50c7, -0x0084}, {-0x0125, 0x2ec8, 0x5270, -0x0054}, {-0x0118, 0x2cf9, 0x540d, -0x001e},
    {-0x010c, 0x2b2c, 0x559d, 0x001f}, {-0x00fe, 0x2961, 0x5720, 0x0063}, {-0x00f0, 0x279a, 0x5896, 0x00ae}, {-0x00e2, 0x25d7, 0x59fc, 0x0101},
    {-0x00d4, 0x2419, 0x5b53, 0x015b}, {-0x00c6, 0x2262, 0x5c9a, 0x01be}, {-0x00b8, 0x20b3, 0x5dd0, 0x022a}, {-0x00aa, 0x1f0b, 0x5ef5, 0x029f},
    {-0x009c, 0x1d6c, 0x6007, 0x031c}, {-0x008f, 0x1bd7, 0x6106, 0x03a4}, {-0x0082, 0x1a4c, 0x61f3, 0x0435}, {-0x0076, 0x18cb, 0x62cb, 0x04d1},
    {-0x006a, 0x1756, 0x638f, 0x0577}, {-0x005f, 0x15eb, 0x643f, 0x0628}, {-0x0054, 0x148c, 0x64d9, 0x06e4}, {-0x004a, 0x1338, 0x655e, 0x07ab},
    {-0x0041, 0x11f0, 0x65cd, 0x087d}, {-0x0038, 0x10b4, 0x6626, 0x095a}, {-0x0030, 0x0f83, 0x6669, 0x0a44}, {-0x0028, 0x0e5f, 0x6696, 0x0b39},
};
static void build_table(void)
{
    int i, k;
    if (tab_ready) return;
    for (i = 0; i < 64; i++) for (k = 0; k < 4; k++) resamp_tab[i][k] = RESAMPLE_LUT[i][k];
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

    for (k = 0; k < 16; k++) dm_wr(out + 2 * k, last[k]);      /* history prefix: the resampler reads its 4-sample window from the end of it */
    out += 32;
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
    static int rs_causal = -1; if (rs_causal < 0) rs_causal = getenv("TUROK_RS") ? atoi(getenv("TUROK_RS")) : 1;      /* 1: the RSP window is the 4 samples before the input position */

    if (!(f & A_INIT) && st) {
        for (k = 0; k < 4; k++) hist[k] = be16(st + 2 * k);
        pos = (uint16_t)be16(st + 8);
    }
#define X(i) (((int32_t)(i)) < 0 ? hist[4 + (i)] : dm_rd(S.in + 2 * (uint32_t)(i)))
    for (k = 0; k < n; k++) {
        int32_t i = (int32_t)(pos >> 16), fr = (int32_t)((pos >> 10) & 63);
        const int16_t *c = resamp_tab[fr];
        int32_t acc = rs_causal ? c[0] * (int32_t)X(i - 4) + c[1] * (int32_t)X(i - 3) + c[2] * (int32_t)X(i - 2) + c[3] * (int32_t)X(i - 1)
                                : c[0] * (int32_t)X(i - 1) + c[1] * (int32_t)X(i) + c[2] * (int32_t)X(i + 1) + c[3] * (int32_t)X(i + 2);
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


/* ENVMIXER (exponential envelope): the state block is 80 bytes (alEnvmixerNew); words 0..9 hold
   wet (low half of word 0), dry (low half of word 1), target L/R, rate L/R, the exponential sequence L/R and the current value L/R.
   Every 8 samples the sequence is multiplied by the 16.16 rate and the per-sample step becomes (seq - value) / 8. */
static void op_envmixer(uint32_t w0, uint32_t w1)
{
    uint32_t f = (w0 >> 16) & 0xFF, k = 0, n = S.count / 2, y, x;
    uint8_t *st = resolve(w1);
    int32_t val[2], tgt[2], rate[2], seq[2], step[2];
    int16_t dry = S.dry, wet = S.wet;
    int aux = (f & A_AUX) != 0, lr;
    static int nowet = -1; if (nowet < 0) nowet = getenv("TUROK_NOWET") ? 1 : 0;

    if ((f & A_INIT) || !st) {
        for (lr = 0; lr < 2; lr++) {
            val[lr] = (int32_t)S.vol[lr] << 16;
            tgt[lr] = (int32_t)S.target[lr] << 16;
            rate[lr] = S.rate[lr];
            seq[lr] = (int32_t)((int64_t)S.vol[lr] * (int64_t)S.rate[lr]);
        }
    } else {
        wet = be16(st + 2); dry = be16(st + 6);
        for (lr = 0; lr < 2; lr++) {
            tgt[lr] = (int32_t)be32(st + 8 + 4 * lr);
            rate[lr] = (int32_t)be32(st + 16 + 4 * lr);
            seq[lr] = (int32_t)be32(st + 24 + 4 * lr);
            val[lr] = (int32_t)be32(st + 32 + 4 * lr);
        }
    }
    step[0] = tgt[0] - val[0]; step[1] = tgt[1] - val[1];
    for (y = 0; y < n; y += 8) {
        for (lr = 0; lr < 2; lr++) if (step[lr] != 0) {
            seq[lr] = (int32_t)(((int64_t)seq[lr] * (int64_t)rate[lr]) >> 16);
            step[lr] = (seq[lr] - val[lr]) >> 3;
        }
        for (x = 0; x < 8 && k < n; x++, k++) {
            int32_t s = dm_rd(S.in + 2 * k), v[2], g, o;
            for (lr = 0; lr < 2; lr++) {
                int reached;
                val[lr] += step[lr];
                reached = (step[lr] <= 0) ? (val[lr] <= tgt[lr]) : (val[lr] >= tgt[lr]);
                if (reached) { val[lr] = tgt[lr]; step[lr] = 0; }
                v[lr] = val[lr] >> 16;
            }
            g = clamp16((v[0] * dry + 0x4000) >> 15); o = S.out + 2 * k;       dm_wr(o, clamp16(dm_rd(o) + ((s * g) >> 15)));
            g = clamp16((v[1] * dry + 0x4000) >> 15); o = S.dry_right + 2 * k; dm_wr(o, clamp16(dm_rd(o) + ((s * g) >> 15)));
            if (aux && !nowet) {
                g = clamp16((v[0] * wet + 0x4000) >> 15); o = S.wet_left + 2 * k;  dm_wr(o, clamp16(dm_rd(o) + ((s * g) >> 15)));
                g = clamp16((v[1] * wet + 0x4000) >> 15); o = S.wet_right + 2 * k; dm_wr(o, clamp16(dm_rd(o) + ((s * g) >> 15)));
            }
        }
    }
    if (st) {
        put16(st + 0, 0); put16(st + 2, wet); put16(st + 4, 0); put16(st + 6, dry);
        for (lr = 0; lr < 2; lr++) {
            put32(st + 8 + 4 * lr, (uint32_t)tgt[lr]);
            put32(st + 16 + 4 * lr, (uint32_t)rate[lr]);
            put32(st + 24 + 4 * lr, (uint32_t)seq[lr]);
            put32(st + 32 + 4 * lr, (uint32_t)val[lr]);
        }
    }
}

static void op_mixer(uint32_t w0, uint32_t w1)
{
    int32_t gain = (int16_t)w0;
    uint32_t in = w1 >> 16, out = w1 & 0xFFFF, k, n = S.count / 2;
    for (k = 0; k < n; k++)
        dm_wr(out + 2 * k, clamp16(dm_rd(out + 2 * k) + ((dm_rd(in + 2 * k) * gain) >> 15)));
}

/* count is the byte length of ONE channel: the output is twice as long (the following SAVEBUFF saves 2 * count bytes) */
static void op_interleave(uint32_t w1)
{
    uint32_t l = w1 >> 16, r = w1 & 0xFFFF, k, n = S.count / 2;
    for (k = 0; k < n; k++) {
        int16_t a = dm_rd(l + 2 * k), b = dm_rd(r + 2 * k);
        dm_wr(S.out + 4 * k, a);
        dm_wr(S.out + 4 * k + 2, b);
    }
}

static void op_polef(uint32_t w0, uint32_t w1)
{
    uint32_t f = (w0 >> 16) & 0xFF, gain = w0 & 0xFFFF;
    uint8_t *st = resolve(w1);
    uint32_t in = S.in, out = S.out, count = ((uint32_t)S.count + 15) & ~15u, k, i, j;
    int16_t h1[8], h2[8], h2b[8], frame[8], o[8];
    int32_t l1 = 0, l2 = 0;
    for (i = 0; i < 8; i++) { h1[i] = S.book[i]; h2b[i] = S.book[8 + i]; h2[i] = (int16_t)(((int32_t)h2b[i] * (int32_t)gain) >> 14); S.book[8 + i] = h2[i]; }
    if (!(f & A_INIT) && st) { l1 = be16(st + 4); l2 = be16(st + 6); }
    for (i = 0; i < 8; i++) o[i] = 0;
    for (k = 0; k < count; k += 16) {
        for (i = 0; i < 8; i++) frame[i] = dm_rd(in + k + 2 * i);
        for (i = 0; i < 8; i++) {
            int32_t acc = (int32_t)frame[i] * (int32_t)gain + h1[i] * l1 + h2b[i] * l2;
            for (j = 0; j < i; j++) acc += h2[j] * frame[i - 1 - j];
            o[i] = clamp16(acc >> 14);
        }
        for (i = 0; i < 8; i++) dm_wr(out + k + 2 * i, o[i]);
        l1 = o[6]; l2 = o[7];
    }
    if (st) for (i = 0; i < 4; i++) put16(st + 2 * i, o[4 + i]);
}

static int hle_lists;
static void run_one(uint32_t w0, uint32_t w1)
{
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
    case A_POLEF: { static int np = -1; if (np < 0) np = getenv("TUROK_NOPOLEF") ? 1 : 0; if (!np) op_polef(w0, w1); } break;
    case A_SETLOOP: S.loop = w1; break;    /* resolved lazily at A_ADPCM time */
    default: S.unknown++; break;
    }
}

int audio_hle_run_ptr(const uint8_t *cmds, uint32_t byte_len)
{
    uint32_t off;
    int n = 0;
    for (off = 0; off + 8 <= byte_len; off += 8, n++) {
        uint32_t w0 = be32(cmds + off), w1 = be32(cmds + off + 4);
        { static int lg = -1, lg0; if (lg < 0) { const char *e = getenv("TUROK_HLELOG"); lg = 0; if (e) { lg0 = atoi(e); lg = strchr(e, 59) ? atoi(strchr(e, 59) + 1) : lg0; if (!strchr(e, 59)) lg0 = 0; lg += lg0; } } if (lg && hle_lists >= lg0 && hle_lists < lg) { fprintf(stderr, "hle[%d] %02X %08X %08X%s", hle_lists, w0 >> 24, w0, w1, off + 8 >= byte_len ? " end\n" : "\n"); } }
        { static int dl = -2; if (dl == -2) dl = getenv("TUROK_HLEDUMP") ? atoi(getenv("TUROK_HLEDUMP")) : -1;
          if (dl >= 0 && hle_lists >= dl && hle_lists < dl + 2) { int op_ = w0 >> 24; uint32_t a_ = 0, q_; int show = 1;
            if (op_ == A_ADPCM) a_ = S.out; else if (op_ == A_RESAMPLE) a_ = S.out; else if (op_ == A_ENVMIXER) a_ = S.out; else if (op_ == A_INTERLEAVE) a_ = S.out; else if (op_ == A_MIXER) a_ = w1 & 0xFFFF; else if (op_ == A_SAVEBUFF) a_ = S.out; else if (op_ == A_LOADBUFF) a_ = S.in; else show = 0;
            if (show) { run_one(w0, w1); fprintf(stderr, "dump[%d] op %02X w0 %08X w1 %08X in=%04X out=%04X cnt=%04X ->%04X:", hle_lists, op_, w0, w1, S.in, S.out, S.count, a_); for (q_ = 0; q_ < 24; q_++) fprintf(stderr, " %d", dm_rd(a_ + 2 * q_)); fputc(10, stderr); if (op_ == A_INTERLEAVE) { fprintf(stderr, "   L bus %04X:", w1 >> 16); for (q_ = 0; q_ < 12; q_++) fprintf(stderr, " %d", dm_rd((w1 >> 16) + 2 * q_)); fputc(10, stderr); } if (off + 8 >= byte_len) hle_lists++; continue; } }
        }
        if (off + 8 >= byte_len) hle_lists++;
        run_one(w0, w1);
    }
    return n;
}

int audio_hle_run(uint32_t cmd_list_addr, uint32_t byte_len)
{
    const uint8_t *p = S.xlat ? S.xlat(cmd_list_addr & 0x1FFFFFFF) : NULL;
    return p ? audio_hle_run_ptr(p, byte_len) : -1;
}
