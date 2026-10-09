/* port (passthru_fix.py): func_00442158 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o01_types.h"

extern u16 D_8015371C;
extern char *D_800D779C;
extern char *D_800D77A0;
extern char *D_800D77A4;
extern char *D_800D77A8;
extern char *D_800D77AC;
extern char *D_800D77B0;
extern char *D_800D77B4;
extern char *D_800D77B8;
extern char *D_800D77BC;
extern char *D_800D77C0;
extern char *D_800D77C4;
extern char *D_800D77C8;
s32 func_00442158();

s32 func_00408AC4(O01Item *item) {
    u32 v = D_8015371C;
    char *s = 0;
    u8 *dst;
    s32 i;
    if (v < 50) {
        s = D_800D779C;
    } else if (v >= 50 && v < 150) {
        s = D_800D77A0;
    } else if (v >= 150 && v < 300) {
        s = D_800D77A4;
    } else if (v >= 300 && v < 500) {
        s = D_800D77A8;
    } else if (v >= 500 && v < 800) {
        s = D_800D77AC;
    } else if (v >= 800 && v < 1300) {
        s = D_800D77B0;
    } else if (v >= 1300 && v < 2000) {
        s = D_800D77B4;
    } else if (v >= 2000 && v < 3000) {
        s = D_800D77B8;
    } else if (v >= 3000 && v < 4500) {
        s = D_800D77BC;
    } else if (v >= 4500 && v < 6500) {
        s = D_800D77C0;
    } else if (v >= 6500 && v < 9999) {
        s = D_800D77C4;
    } else if ((s32)v >= 9999) {
        s = D_800D77C8;
    }
    dst = (u8 *)item->unk14->buf;
    dst += func_00442158(item) - 11;
    if (s != 0) {
        for (i = 0; i < 11; i++) {
            *dst++ = *s++;
        }
    }
    return 0;
}
