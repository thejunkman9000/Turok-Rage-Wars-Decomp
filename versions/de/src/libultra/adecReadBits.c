#include "adec_types.h"

/* Acclaim compressed-audio codec (ROM 0xC4AA0-0xC5F20): ONE translation unit with a shared literal pool
   (ro=0xCDB10:56).  A frame is 256 samples: 16 scale indices (first frame raw 6 bit fields, later Huffman coded
   deltas against the previous frame) followed by 256 Huffman coded quantised MDCT coefficients; decoding = bit reader -> Huffman ->
   dequantise -> inverse MDCT via a 128 point complex FFT -> overlap-add -> round/clamp to s16.  The stream is driven by alAdecPull
   (adecStreamOpen / adecNextFrame).

   Build flags: the libultra default (-O3 -fforce-addr -fno-builtin -mcpu=r4300), equivalently the @SN toolchain with
   `-fforce-addr -finline-functions -fno-builtin`.  -finline-functions is what inlines mdctPackSpectrum, mdctTwiddleMul,
   mdctFftCtx and adecRoundClampS16 into adecImdctFrame (they are defined before it); gcc 2.8 emits the functions in the
   order of their first declaration, hence the prototypes below in ROM order.

   Globals (names kept as in the symbol table):
     D_800D9380 u16[17] mask (1 << n) - 1        D_800D93A4 u16[17] sign bit 1 << (n - 1)
     D_800D93C8 u16[16] band end index           D_800D93E6 s16 first coefficient that is forced to 0
     D_800D93E8 f32[]  dequantisation step per scale index
     D_800D94E8 bits left in D_80151090 (current stream word)   D_800D94EA / D_800D94EC Huffman bit buffer / bits left
     D_800D94EE first-frame (header) done   D_800D94F0 IMDCT tables built   D_800D94F2 output ring index (0..5)
     D_801510A0 u16[16] previous scale indices   D_801510C0/D_801512C0 pre-twiddle cos/sin (128)
     D_801514C0/D_801516C0 post-twiddle (cos + sin / sin - cos)   D_801518C0 overlap state (128)
     D_800D9370 MdctCtx (FFT tables of 128 points)   D_80151AC0 pointer to it
     D_80151CC8 AdecStream (the one decoder instance)   D_80151CD8 stop flag   D_80151F80 ring of 6 x 256 s16 output frames */
s32 adecReadBits(u16 *dst, u16 nbits, u16 count, s16 sign, AdecStream *st);
s16 adecHuffDecode(AdecHuffSeg *segs, s16 *out, s16 n, s16 *cnt, AdecStream *st);
s32 adecDecodeFrame(AdecStream *st);
void mdctInitTwiddles(void);
MdctCtx *mdctFftInit(s32 n);
s32 adecDequantize(f32 *out, s16 *band);
void mdctFft(f32 *d, s32 n, s32 sign, f32 *cos, f32 *sin, s32 *bitrev);
void adecImdctFrame(s16 *out, AdecStream *st);
s32 adecDecodeFrameOk(AdecStream *st);
void mdctBuildBitrevTable(s32 *tab, s32 n);
void mdctPackSpectrum(AdecCpx *out, f32 *in);
void mdctTwiddleMul(AdecCpx *d, f32 *c, f32 *s);
void mdctFftCtx(f32 *data, MdctCtx *ctx, s32 sign);
s16 adecRoundClampS16(f32 x);
u32 adecStreamOpen(u32 *hdr, u32 rate, u32 *outWord0);
void *adecNextFrame(void);
u32 adecGetStopFlag(void);
void adecClearStopFlag(void);

f32 cosf(f32 x);
f32 sinf(f32 x);
u64 __udivdi3(u64 a, u64 b);

extern MdctCtx D_800D9370;
extern MdctCtx *D_80151AC0;
extern f32 D_801510C0[128];
extern f32 D_801512C0[128];
extern f32 D_801514C0[128];
extern f32 D_801516C0[128];
extern f32 D_801518C0[128];
extern u16 D_801510A0[16];
extern AdecHuffSeg D_800D9594[];
extern u16 D_800D93C8[16];
extern f32 D_800D93E8[];
extern s16 D_800D93E6;
extern u16 D_800D9380[];
extern u16 D_800D93A4[];
extern u16 D_80151090;
extern u16 D_800D94E8;
extern u16 D_800D94EA;
extern u16 D_800D94EC;
extern s16 D_800D94EE;
extern s16 D_800D94F0;
extern u16 D_800D94F2;
extern u32 D_80151CD8;
extern AdecStream D_80151CC8;
extern u8 D_80151F80[];

/* Bit reader: fetches `count` fields of `nbits` bits (MSB first) from the stream of 16-bit words at st->rd into dst[],
   sign-extending each field to 16 bits when `sign` is set.  D_800D94E8 = bits still unread in the current word D_80151090.
   Always returns 1.  (The `+= 0` (an extra reference of the word's address: global-alloc priority), the split reads curWord/maskLeft, the
   `int` temporaries fldA/fldB (HImode vs SImode `and`) and the volatile first store only steer the register allocation and scheduling of the
   original gcc output: they do not change what the code does.) */
s32 adecReadBits(u16 *dst, u16 nbits, u16 count, s16 sign, AdecStream *st)
{
    s16 i;
    u16 extra;     /* bits needed from the next word */
    u16 maskLeft;
    u16 curWord;
    int fldA;
    int fldB;
    if (D_800D94E8 == 0) {
        *(volatile u16 *)&D_80151090 = *(st->rd++);
        D_800D94E8 = 16;
    }
    for (i = 0; i < count; i++) {
        if (D_800D94E8 < nbits) {
            /* the field straddles two words: the low D_800D94E8 bits of this one, then the top `extra` bits of the next */
            extra = nbits - D_800D94E8;
            curWord = D_80151090;
            maskLeft = D_800D9380[D_800D94E8];
            dst[i] = (curWord & maskLeft) << extra;
            D_80151090 = *(st->rd++);
            D_80151090 += 0;
            fldA = (D_80151090 >> (16 - extra)) & D_800D9380[extra];
            dst[i] |= fldA;
            if (sign) {
                if (((s16)dst[i]) & D_800D93A4[nbits]) {
                    dst[i] |= ~D_800D9380[nbits];
                }
            }
            D_800D94E8 = 16 - extra;
        } else {
            fldB = (D_80151090 >> (D_800D94E8 - nbits)) & D_800D9380[nbits];
            dst[i] = fldB;
            if (sign) {
                if (((s16)dst[i]) & D_800D93A4[nbits]) {
                    dst[i] |= ~D_800D9380[nbits];
                }
            }
            D_800D94E8 -= nbits;
        }
    }
    return 1;
}

/* Huffman decoder for the spectral data.  segs: segment table (terminated by kind == 0), each segment has its own binary tree
   (tree->nodes[node][bit]; a node whose first half-word is 0x800 is a leaf whose value is in the second half-word).
   Leaf value classes (v & 0xF00): 0x000/0xF00 literal coefficient, 0x900 escape (raw value of tree->escBits bits follows),
   0xA00 run of literal values from escape codebook number (v & 0xFF), 0xB00 end of block (rest of out[] is zeroed).
   Bits come from the 16-bit buffer D_800D94EA (D_800D94EC = bits left), refilled through adecReadBits.
   *cnt receives the number of segments that were completed; returns the number of coefficients produced, or -1 on error. */
s16 adecHuffDecode(AdecHuffSeg *segs, s16 *out, s16 n, s16 *cnt, AdecStream *st)
{
    AdecHuffTree *tree;
    u16 (*nodes)[2];
    AdecCodebook *cbSave;
    s16 node = 0;
    s16 si = 0;
    s16 k = 0;
    u16 v;
    u16 cls;
    u16 bit;
    s16 next;
    s16 i;
    *cnt = 0;
    tree = segs->tree;
    nodes = tree->nodes;
    while (k < n) {
        if (D_800D94EC != 0) {
            D_800D94EC--;
            bit = D_800D94EA & 0x8000;
            D_800D94EA <<= 1;
            if (bit) {
                next = nodes[node][1];
            } else {
                next = nodes[node][0];
            }
            if (nodes[next][0] == 0x800) {
                v = nodes[next][1];
                node = 0;
                cls = v & 0xF00;
                if ((cls == 0) || (cls == 0xF00)) {
                    out[k] = v;
                    k++;
                } else if (((s16)v) == 0x900) {
                    v = D_800D94EA;
                    if (((u16)adecReadBits(&D_800D94EA, tree->escBits, 1, 0, st)) == 0) {
                        return -1;
                    }
                    {
                        u16 bits;
                        u16 w;
                        s16 *o = (s16 *)(k * 2 + (int)out);
                        k++;
                        bits = D_800D94EC;
                        w = D_800D94EA;
                        D_800D94EA = w << (16 - bits);
                        *o = v | (w >> bits);
                    }
                } else if (cls == 0xA00) {
                    AdecCodebook *cb = (AdecCodebook *)((v & 0xFF) * 0x1B8 + (int)tree->codebooks);
                    s16 *p = (s16 *)(k * 2 + (int)out);
                    cbSave = cb;
                    i = 0;
                    while (i < cbSave->count) {
                        p[i] = cbSave->ent[i].val;
                        i++;
                    }
                    k += (i << 16) >> 16;
                } else if (cls == 0xB00) {
                    while (k < n) {
                        out[k++] = 0;
                    }
                    while (n >= (segs[si].start + segs[si].len)) {
                        si++;
                        (*cnt)++;
                    }
                    return n;
                }
                if (k >= (segs[si].start + segs[si].len)) {
                    si++;
                    (*cnt)++;
                    tree = segs[si].tree;
                    nodes = tree->nodes;
                }
            } else {
                node = next;
            }
        } else {
            if (((u16)adecReadBits(&D_800D94EA, 16, 1, 0, st)) == 0) {
                return -1;
            }
            D_800D94EC += 16;
        }
    }
    return k;
}

/* Decodes one frame into st: the 16 scale indices st->band[] (the very first frame raw 6 bit fields, afterwards Huffman coded
   differences against the previous frame D_801510A0) and the 256 coefficients st->coef[].  Returns 1, or -1 on a stream error.
   (A single result variable `rv` for both Huffman calls is what the original register allocation needs.) */
s32 adecDecodeFrame(AdecStream *st) {
    s16 cnt;
    s16 nv;
    s16 i;
    s32 rv;
    AdecHuffSeg *seg = D_800D9594;
    if (D_800D94EE == 0) {
        D_800D94EE = 1;
        if ((s16)adecReadBits((u16 *)st->band, 6, 16, 0, st) <= 0) {
            return -1;
        }
        seg->pos += 0x60;
        for (i = 0; i < 16; i++) {
            D_801510A0[i] = st->band[i];
        }
        while (seg->kind != 0) {
            seg++;
        }
    } else {
        rv = adecHuffDecode(seg, st->band, 16, &cnt, st);
        if (rv != 16) {
            goto fail;
        }
        seg = &seg[nv = cnt];
        for (i = 0; i < 16; i++) {
            nv = D_801510A0[i];
            st->band[i] += nv;
            D_801510A0[i] = st->band[i];
        }
    }
    rv = adecHuffDecode(seg, st->coef, 256, &cnt, st);
    if (rv != 256) {
    fail:
        return -1;
    }
    return 1;
}

/* Builds the twiddle tables of the 256 point (128 complex) inverse MDCT: pre-twiddle exp(i (4k+1) pi / 1024) as cos/sin tables
   D_801510C0 / D_801512C0, clears the overlap state D_801518C0, post-twiddle tables D_801514C0 = cos + sin and
   D_801516C0 = sin - cos of k pi / 256. */
void mdctInitTwiddles(void) {
    s16 k;
    f32 x;
    for (k = 0; k < 128; k++) {
        x = ((f32)k * 4.0f + 1.0f) * 0.0030679616f;
        D_801510C0[k] = cosf(x);
        D_801512C0[k] = sinf(x);
        D_801518C0[k] = 0.0f;
    }
    for (k = 0; k < 128; k++) {
        f32 c;
        f32 s;
        x = (f32)k * 0.012271847f;
        c = cosf(x);
        s = sinf(x);
        D_801514C0[k] = c + s;
        D_801516C0[k] = s - c;
    }
}

/* Prepares the FFT context D_800D9370 for n complex points: cos(2 pi i / n) and -sin(2 pi i / n) for i < n / 2 and the
   bit-reversal permutation table; returns the context. */
MdctCtx *mdctFftInit(s32 n) {
    s32 i;
    s32 k;
    s32 j;
    s32 m;
    s32 nn;
    s32 half = n >> 1;
    s32 *tab;
    MdctCtx *ctx = &D_800D9370;
    f32 x;
    for (i = 0; i < half; i++) {
        f32 c, s;
        x = (f32)i * 6.2831855f / (f32)n;
        c = cosf(x);
        ctx->cos[i] = c;
        s = sinf(x);
        ctx->sin[i] = -s;
    }
    tab = ctx->bitrev;
    nn = n << 1;
    for (k = 0; k < n; k++) {
        tab[k] = k;
    }
    j = 1;
    for (k = 1; k <= nn; k += 2) {
        if (j > k) {
            s32 t = tab[(j - 1) / 2];
            tab[(j - 1) / 2] = tab[(k - 1) / 2];
            tab[(k - 1) / 2] = t;
        }
        m = n;
        while (m >= 2 && j > m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
    ctx->n = n;
    return ctx;
}

/* Dequantises the 256 coefficients that follow the 16 scale indices in `band` (a stream's band[] + coef[]): the coefficients of
   band b (end index D_800D93C8[b]) are divided by the step D_800D93E8[scale index b] and scaled by 2^-15; everything from the
   cutoff D_800D93E6 on is cleared.  Returns 1. */
s32 adecDequantize(f32 *out, s16 *band) {
    s16 b;
    s16 i;
    s16 start = 0;
    s16 *coef = band + 80;
    for (b = 0; b < 16; b++) {
        for (i = start; i < D_800D93C8[b]; i++) {
            out[i] = (f32)coef[i] / D_800D93E8[*(s16 *)((u8 *)band + (b << 1))] * 3.0517578e-05f;
        }
        start = D_800D93C8[b];
    }
    for (b = D_800D93E6; b < 256; b++) {
        out[b] = 0.0f;
    }
    return 1;
}

/* In-place radix-2 complex FFT of n points (interleaved re/im floats in d): bit-reversal permutation by `bitrev`, then
   log2(n) butterfly passes with the twiddles cos[w] + i * sign * sin[w]. */
void mdctFft(f32 *d, s32 n, s32 sign, f32 *cos, f32 *sin, s32 *bitrev) {
    s32 i, k, half, dist, stride, idx, w, nn;
    f32 wc, ws, xr, xi, tr, ti;
    for (i = 0; i < n; i++) {
        if (i < bitrev[i]) {
            tr = d[i * 2];
            d[i * 2] = d[bitrev[i] * 2];
            d[bitrev[i] * 2] = tr;
            tr = d[i * 2 + 1];
            d[i * 2 + 1] = d[bitrev[i] * 2 + 1];
            d[bitrev[i] * 2 + 1] = tr;
        }
    }
    dist = 2;
    half = 1;
    stride = n >> half;
    nn = n << half;
    while (stride > 0) {
        w = 0;
        for (k = 0; k < half; k++) {
            wc = cos[w];
            ws = (f32)sign * sin[w];
            for (idx = k * 2; idx < nn; idx += dist * 2) {
                xr = d[idx + dist];
                xi = d[idx + dist + 1];
                tr = wc * xr - ws * xi;
                ti = wc * xi + ws * xr;
                d[idx + dist] = d[idx] - tr;
                d[idx + dist + 1] = d[idx + 1] - ti;
                d[idx] = d[idx] + tr;
                d[idx + 1] = d[idx + 1] + ti;
            }
            w += stride;
        }
        stride >>= 1;
        half <<= 1;
        dist <<= 1;
    }
}

/* out[k] = (in[2k], in[255 - 2k]) for k < 128: folds the 256 spectrum values into 128 complex points. */
void mdctPackSpectrum(AdecCpx *out, f32 *in) {
    s16 k;
    for (k = 0; k < 128; k++) {
        out[k].re = in[k * 2];
        out[k].im = in[255 - k * 2];
    }
}

/* d[k] *= (c[k] + i s[k]) for the 128 complex points. */
void mdctTwiddleMul(AdecCpx *d, f32 *c, f32 *s) {
    s16 k;
    for (k = 0; k < 128; k++) {
        f32 re = d[k].re;
        f32 cc = c[k];
        f32 im = d[k].im;
        f32 ss = s[k];
        d[k].re = re * cc - im * ss;
        d[k].im = re * ss + im * cc;
    }
}

/* FFT with the tables of an MdctCtx. */
void mdctFftCtx(f32 *data, MdctCtx *ctx, s32 sign) {
    mdctFft(data, ctx->n, sign, ctx->cos, ctx->sin, ctx->bitrev);
}

/* Rounds to nearest (half away from zero) and clamps to the s16 range. */
s16 adecRoundClampS16(f32 x) {
    f32 y;
    if (x >= 0.0f) {
        y = x + 0.5f;
        if (y > 32767.0f) {
            y = 32767.0f;
        }
    } else {
        y = x - 0.5f;
        if (y < -32768.0f) {
            y = -32768.0f;
        }
    }
    return (s16)y;
}

/* Inverse MDCT of the frame in st (band[] scale indices, coef[] quantised values) -> 256 s16 samples in out[].  The twiddle tables
   and the FFT context are built on first use.  The helpers above are inlined here by -finline-functions. */
void adecImdctFrame(s16 *out, AdecStream *st) {
    f32 buf[256];
    f32 deq[256];
    s16 k;
    f32 scale;
    if (D_800D94F0 == 0) {
        mdctInitTwiddles();
        D_80151AC0 = mdctFftInit(0x80);
        D_800D94F0 = 1;
    }
    scale = 23170.475f;
    adecDequantize(deq, st->band);
    mdctPackSpectrum((AdecCpx *)buf, deq);
    mdctTwiddleMul((AdecCpx *)buf, D_801510C0, D_801512C0);
    mdctFftCtx(buf, D_80151AC0, -1);
    mdctTwiddleMul((AdecCpx *)buf, D_801514C0, D_801516C0);
    for (k = 0; k < 128; k++) {
        f32 ov = D_801518C0[k];
        f32 cc = D_801510C0[k];
        f32 im = buf[k * 2 + 1];
        f32 ss = D_801512C0[k];
        f32 t1 = ov * cc + im * ss;
        f32 t2 = ov * ss - im * cc;
        D_801518C0[k] = buf[k * 2];
        out[k * 2] = adecRoundClampS16(scale * t1);
        out[255 - k * 2] = adecRoundClampS16(scale * t2);
    }
}

/* 1 if the frame decoded without a stream error. */
s32 adecDecodeFrameOk(AdecStream *st) {
    s16 r = adecDecodeFrame(st);
    return r >= 0;
}

/* Fills tab[0..n-1] with 0..n-1 and applies the bit-reversal permutation of an n point FFT (swap walk). */
void mdctBuildBitrevTable(s32 *tab, s32 n) {
    s32 i, j, m;
    s32 nn = n << 1;
    for (i = 0; i < n; i++) {
        tab[i] = i;
    }
    j = 1;
    for (i = 1; i <= nn; i += 2) {
        if (j > i) {
            s32 t = tab[(j - 1) / 2];
            tab[(j - 1) / 2] = tab[(i - 1) / 2];
            tab[(i - 1) / 2] = t;
        }
        m = n;
        while (m >= 2 && j > m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
}

/* Starts a stream: hdr = {word0, frame count, word2, frame data...}; resets the decoder state and returns the stream length in
   microseconds (frames * 256 samples * 1e6 / rate); *outWord0 receives the first header word. */
u32 adecStreamOpen(u32 *hdr, u32 rate, u32 *outWord0) {
    AdecStream *st = &D_80151CC8;
    st->hdr = hdr;
    st->rd = (u16 *)hdr;
    st->hdr0 = *(u32 *)st->rd;
    st->rd += 2;
    st->remaining = *(u32 *)st->rd;
    st->nframes = *(u32 *)st->rd;
    st->rd += 2;
    st->hdr2 = *(u32 *)st->rd;
    st->rd += 2;
    D_800D94EE = 0; D_800D94F0 = 0; D_800D94E8 = 0; D_800D94EA = 0; D_800D94EC = 0;
    *outWord0 = st->hdr0;
    return (u32)(((s64)(s32)st->remaining * 256000000) / (u64)rate);
}

/* Decodes the next frame into the next of 6 ring buffers (256 s16 each) and returns it, or 0 when the stream is finished. */
void *adecNextFrame(void) {
    if (D_80151CC8.remaining != 0) {
        adecDecodeFrame(&D_80151CC8);
        D_800D94F2++;
        if (D_800D94F2 >= 6) {
            D_800D94F2 = 0;
        }
        adecImdctFrame((s16 *)(D_80151F80 + D_800D94F2 * 0x200), &D_80151CC8);
        D_80151CC8.remaining--;
        return D_80151F80 + D_800D94F2 * 0x200;
    }
    return 0;
}

u32 adecGetStopFlag(void) {
    return D_80151CD8;
}

void adecClearStopFlag(void) {
    D_80151CD8 = 0;
}
