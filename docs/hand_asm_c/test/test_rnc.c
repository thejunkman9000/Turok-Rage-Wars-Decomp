/*
 * test_rnc.c - C side of the differential test of ../rnc.c.
 *
 *   test_rnc cases <cases.bin>   run the cases that run_tests.py recorded from the original machine
 *                                code (via mips_interp.py) and compare byte for byte
 *   test_rnc crc <baserom.z64>   unpack every RNC method 1 blob found in the ROM and verify the
 *                                unpacked size and the CRC16 stored in the RNC header
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef int32_t s32;

extern u32 rnc_last_unpacked_size;
extern u16 rnc_tail_count;
u32 rnc_unpack_method1(const u8 *in, u8 *out, s32 in_len, s32 out_len, int *status);
s32 rncUnpackMethod2(const u8 *rnc, u8 *dst, s32 packed, s32 unpacked);

#define MARGIN 0x400
#define SLACK  0x100
#define PAD    0x1000

typedef struct {
    u32 kind;        /* 1 = method 1, 2 = method 2 */
    u32 in_total;
    u32 in_len;      /* packed parameter (method 1) */
    u32 out_len;     /* unpacked parameter / header value */
    u32 region_len;
    u32 exp_v0;
    u32 exp_global;
} CaseHdr;

static u16 crc16(const u8 *p, u32 n)
{
    u32 crc = 0, i, j;
    for (i = 0; i < n; i++) {
        crc ^= p[i];
        for (j = 0; j < 8; j++)
            crc = (crc & 1) ? (crc >> 1) ^ 0xA001 : crc >> 1;
    }
    return (u16)crc;
}

static int run_cases(const char *path)
{
    FILE *f = fopen(path, "rb");
    CaseHdr h;
    int n = 0, pass = 0, fail = 0, refused = 0;
    if (!f) { perror(path); return 2; }
    while (fread(&h, sizeof h, 1, f) == 1) {
        u8 *in = calloc(h.in_total + PAD, 1);
        u8 *region = malloc(h.region_len);
        u8 *work = malloc(h.region_len);
        u8 *out;
        int st = 0;
        u32 v0 = 0;
        fread(in, 1, h.in_total, f);
        fread(region, 1, h.region_len, f);
        memset(work, 0xA5, h.region_len);
        out = work + MARGIN;
        rnc_last_unpacked_size = 0xDEADBEEF;
        rnc_tail_count = 0x1234;
        if (h.kind == 1) {
            v0 = rnc_unpack_method1(in + 0x12, out, (s32)h.in_len, (s32)h.out_len, &st);
        } else {
            st = rncUnpackMethod2(in, out, 0, 0);
        }
        n++;
        if (st != 0) {
            refused++;      /* hardening check fired where the original ran on */
            printf("case %d kind %u: REFUSED by hardening check (original produced output)\n", n, h.kind);
        } else if (memcmp(work, region, h.region_len) != 0) {
            u32 i;
            for (i = 0; i < h.region_len && work[i] == region[i]; i++) ;
            printf("case %d kind %u: FAIL output differs at region offset 0x%X (out+%d): C %02X, original %02X\n",
                   n, h.kind, i, (int)i - MARGIN, work[i], region[i]);
            fail++;
        } else if (h.kind == 1 && v0 != h.exp_v0) {
            printf("case %d: FAIL return value C %08X original %08X\n", n, v0, h.exp_v0);
            fail++;
        } else if (h.kind == 2 && (rnc_last_unpacked_size != h.exp_global || rnc_tail_count != 0)) {
            printf("case %d: FAIL global D_8014D420 C %08X original %08X\n", n, rnc_last_unpacked_size, h.exp_global);
            fail++;
        } else {
            pass++;
        }
        free(in); free(region); free(work);
    }
    fclose(f);
    printf("cases: %d  pass: %d  fail: %d  refused-by-hardening: %d\n", n, pass, fail, refused);
    return fail ? 1 : 0;
}

static int run_crc(const char *path)
{
    FILE *f = fopen(path, "rb");
    u8 *rom;
    long sz, o;
    int blobs = 0, ok = 0, bad = 0;
    if (!f) { perror(path); return 2; }
    fseek(f, 0, SEEK_END); sz = ftell(f); fseek(f, 0, SEEK_SET);
    rom = malloc(sz + PAD);
    memset(rom, 0, sz + PAD);
    fread(rom, 1, sz, f);
    fclose(f);
    for (o = 0; o + 18 < sz; o++) {
        u32 un, pk, want;
        u8 *dst;
        int st;
        if (memcmp(rom + o, "RNC\x01", 4) != 0) continue;
        un = ((u32)rom[o+4] << 24) | (rom[o+5] << 16) | (rom[o+6] << 8) | rom[o+7];
        pk = ((u32)rom[o+8] << 24) | (rom[o+9] << 16) | (rom[o+10] << 8) | rom[o+11];
        if (un == 0 || un > 0x1000000 || pk == 0 || pk > 0x400000 || o + 18 + pk > (u32)sz) continue;
        want = ((u32)rom[o+12] << 8) | rom[o+13];
        blobs++;
        dst = calloc(un + 0x100, 1);
        (void)rnc_unpack_method1(rom + o + 0x12, dst, (s32)pk, (s32)un, &st);
        if (st == 0 && crc16(dst, un) == want) ok++;
        else { bad++; printf("blob at ROM 0x%lX: unpack failed or CRC mismatch (status %d)\n", o, st); }
        free(dst);
    }
    printf("RNC1 blobs: %d  CRC ok: %d  bad: %d\n", blobs, ok, bad);
    free(rom);
    return bad ? 1 : 0;
}

int main(int argc, char **argv)
{
    if (argc == 3 && !strcmp(argv[1], "cases")) return run_cases(argv[2]);
    if (argc == 3 && !strcmp(argv[1], "crc")) return run_crc(argv[2]);
    fprintf(stderr, "usage: test_rnc cases <cases.bin> | crc <baserom.z64>\n");
    return 2;
}
