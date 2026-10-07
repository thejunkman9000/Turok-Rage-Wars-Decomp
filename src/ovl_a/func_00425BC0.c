#include "o04_types.h"
typedef struct { u8 pad0[0x57]; u8 b[0x190 - 0x57]; } O04Row190s;
extern O04Row190s D_80102B00[];
s32 func_00265670(void *p, s32 a);
void func_00425BC0(s32 a) {
    s32 c;
    s32 n;
    s32 i;
    O04Row190s *r = &D_80102B00[a];
    c = 0;
    for (i = 0; i < 0x32; i++) {
        if (func_00265670((u8 *)D_80102B00 + 0x4A + a * 0x190, i) == 1) {
            c++;
        }
    }
    n = c;
    if (n >= 2) {
        r->b[0x57 - 0x57] = 2;
    }
    if (n >= 4) {
        r->b[0x5C - 0x57] = 2;
    }
    if (n >= 6) {
        r->b[0x58 - 0x57] = 2;
    }
    if (n >= 8) {
        r->b[0x60 - 0x57] = 2;
    }
    if (n >= 10) {
        r->b[0x59 - 0x57] = 2;
    }
    if (n >= 12) {
        r->b[0x5A - 0x57] = 2;
    }
    if (n >= 14) {
        r->b[0x61 - 0x57] = 2;
    }
    if (n >= 16) {
        r->b[0x5D - 0x57] = 2;
    }
    if (n >= 18) {
        r->b[0x68 - 0x57] = 2;
    }
    if (n >= 20) {
        r->b[0x5E - 0x57] = 2;
    }
    if (n >= 22) {
        r->b[0x5B - 0x57] = 2;
    }
    if (n >= 24) {
        r->b[0x5F - 0x57] = 2;
    }
    if (n >= 26) {
        r->b[0x69 - 0x57] = 2;
    }
    if (n >= 28) {
        r->b[0x57 - 0x57] = 3;
    }
    if (n >= 30) {
        r->b[0x5C - 0x57] = 3;
    }
    if (n >= 32) {
        r->b[0x58 - 0x57] = 3;
    }
    if (n >= 34) {
        r->b[0x60 - 0x57] = 3;
    }
    if (n >= 36) {
        r->b[0x59 - 0x57] = 3;
    }
    if (n >= 38) {
        r->b[0x5A - 0x57] = 3;
    }
    if (n >= 40) {
        r->b[0x61 - 0x57] = 3;
    }
    if (n >= 42) {
        r->b[0x68 - 0x57] = 3;
    }
    if (n >= 44) {
        r->b[0x5E - 0x57] = 3;
    }
    if (n >= 46) {
        r->b[0x5B - 0x57] = 3;
    }
    if (n >= 48) {
        r->b[0x5F - 0x57] = 3;
    }
    if (n >= 50) {
        r->b[0x69 - 0x57] = 3;
    }
}
