/* RNC ProPack decompression, method 1 (ported from the game's hand-written MIPS: rncUnpackMethod1Body, rncMakeHuffTable,
   rncReadHuffCode, rncInputBits, rncRefillBitBuf in src/libultra/rnc*.s).  Same register roles: t6 = bit buffer, t7 = bit counter.
   Compiled through the same big-endian clang pipeline as the game code, so the source/destination are guest pointers. */


typedef struct { u32 t6; s32 t7; const u8 *s3; } RncBits;

static void rnc_consume(RncBits *b, s32 n) {
    b->t7 -= n;
    if (b->t7 < 0) {                                   /* rncRefillBitBuf */
        const u8 *o;
        b->t7 += n;
        b->t6 >>= (b->t7 & 31);
        o = b->s3;
        b->t6 |= ((u32)o[3] << 24) | ((u32)o[2] << 16);
        b->s3 = o + 2;
        n -= b->t7;
        b->t7 = 16 - n;
    }
    b->t6 >>= (n & 31);
}

static u32 rnc_input_bits(RncBits *b, u32 mask, s32 n) {
    u32 r = b->t6 & mask;
    rnc_consume(b, n);
    return r;
}

/* Huffman table: 16 entries of {u16 mask; u16 code} at +0, then per entry {u8 len; u8 sym; u16 extra mask} at +0x40 (+4 per entry) */
static u32 rnc_read_huff(RncBits *b, const u8 *tab) {
    const u8 *s0 = tab;
    u32 t0, len, bits, nb;
    for (;;) {
        u16 m = *(const u16 *)s0; s0 += 2;
        u16 c = *(const u16 *)s0; s0 += 2;
        t0 = m & b->t6;
        if ((t0 - c) == 0) break;
    }
    len = s0[0x3C];
    rnc_consume(b, (s32)len);
    bits = s0[0x3D];
    if ((s32)(bits - 2) < 0) return bits;
    nb = bits - 1;
    t0 = *(const u16 *)(s0 + 0x3E) & b->t6;
    rnc_consume(b, (s32)nb);
    return t0 | (1u << nb);
}

static void rnc_make_huff(RncBits *b, u8 *s0) {
    u8 lens[32];
    s32 n, t1, t3, t4, k;
    u32 t0, t2;
    n = (s32)rnc_input_bits(b, 0x1F, 5);
    if (n - 1 < 0) return;
    t3 = n - 1;
    for (k = 0; k < n; k++) lens[k] = (u8)rnc_input_bits(b, 0xF, 4);
    t0 = 0x80000000u; t1 = 1; t2 = 0;
    do {
        const u8 *s1 = lens;
        t4 = t3;
        for (;;) {
            u8 at = *s1++;
            if (at == t1) {
                u32 t5, t6 = 0;
                s32 t7, i = t3 - t4;
                *(u16 *)s0 = (u16)((1u << t1) - 1); s0 += 2;
                t5 = (t2 << 16) | (t2 >> 16);
                t7 = t1 - 1;
                do {
                    u32 hi;
                    t6 &= 0xFFFF;
                    hi = t5 & 0x8000;
                    t5 <<= 1;
                    t6 >>= 1;
                    if (hi) t6 |= 0x8000;
                } while (t7-- != 0);
                t6 >>= (16 - t1);
                *(u16 *)s0 = (u16)t6; s0 += 2;
                s0[0x3C] = (u8)t1;
                s0[0x3D] = (u8)i;
                *(u16 *)(s0 + 0x3E) = (u16)(((u32)1 << ((i - 1) & 31)) - 1);
                t2 += t0;
            }
            if (t4 == 0) break;
            t4--;
        }
        t0 >>= 1;
        t1++;
    } while (t1 != 0x11);
}

void rncUnpackMethod1(const u8 *src, u8 *dst, s32 packed, s32 unpacked) {
    RncBits b;
    u8 tabs[0x180];
    const u8 *end_in = src + packed;
    u8 *out = dst;
    (void)unpacked;
    b.s3 = src;
    b.t6 = (u32)src[1] << 8 | src[0];
    b.t7 = 0;
    rnc_input_bits(&b, 2, 2);
    do {
        u32 t4;
        rnc_make_huff(&b, tabs);
        rnc_make_huff(&b, tabs + 0x80);
        rnc_make_huff(&b, tabs + 0x100);
        t4 = ((rnc_input_bits(&b, 0xFFFFFFFFu, 16)) - 1) & 0xFFFF;
        for (;;) {
            s32 cnt = (s32)rnc_read_huff(&b, tabs) - 1;           /* literal run */
            if (cnt >= 0) {
                do { *out++ = *b.s3++; } while (cnt-- != 0);
                {
                    u32 w = (u32)b.s3[1] << 8 | b.s3[0];
                    b.t6 = (b.t6 & (((u32)1 << (b.t7 & 31)) - 1)) | (w << (b.t7 & 31));
                }
            }
            if (t4 == 0) break;
            t4--;
            {                                                   /* match: distance, then length */
                u32 dist = rnc_read_huff(&b, tabs + 0x80);
                u32 len = rnc_read_huff(&b, tabs + 0x100);
                const u8 *from = out - dist - 1;
                *out++ = *from++;
                do { *out++ = *from++; } while (len-- != 0);
            }
        }
    } while (b.s3 < end_in);
}
