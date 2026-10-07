#include "o04_types.h"
typedef struct { s32 k; u8 pad4[8]; s32 v; } O04E16b;
extern s32 D_800E51E4[];
extern s32 D_800E51F8[];
extern s32 D_800E5214[];
extern s32 D_800E5240[];
extern O04E16b D_800E4F64[];
s32 func_0042B398(s32 a, s32 b) {
    s32 *tbl;
    s32 key;
    s32 i;
    s32 found;
    s32 r;
    r = 0;
    if (b == 0) {
        b = 1;
    }
    switch (a) {
    case 0:
        tbl = D_800E51E4;
        break;
    case 1:
        tbl = D_800E51F8;
        break;
    case 3:
        tbl = D_800E5214;
        break;
    case 2:
        tbl = D_800E5240;
        break;
    default:
        return 0;
    }
    key = tbl[b];
    found = 0;
    i = 0;
    do {
        if (key == D_800E4F64[i].k) {
            found = 1;
            r = D_800E4F64[i].v;
        }
        i++;
    } while (i < 0x28 && found == 0);
    return r;
}
