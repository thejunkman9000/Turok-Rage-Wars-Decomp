#include "o01_types.h"
extern u8 D_auto_80152789;

extern char *D_auto_800E25A4[];
extern char *D_auto_800E25B4[];
extern s32 D_800E28C8;
extern s32 D_8011FECC;
s32 func_00405338(s32 pad, s32 idx, u8 **out);
void func_00405648(u8 *src, u8 *dst, s32 n);
s32 func_002A137C(char *a, char *b);
s32 func_00405160(s32 pad, s32 *out);
s32 func_004050CC(s32 pad, s32 *out);
u32 func_004057EC(u32 n);

static inline s32 O01Find(s32 pad, char *name) {
    u8 buf[16];
    u8 *ent;
    s32 i;
    for (i = 0; i < 16; i++) {
        func_00405338(pad, i, &ent);
        func_00405648(ent, buf, 16);
        if (func_002A137C((char *)buf, name) == 0) {
            return 1;
        }
    }
    return 0;
}

s32 func_auto_004068CC(s32 unused, s32 pad, s32 *outPad, s32 *outBlocks) {
    s32 f1;
    s32 f2;
    s32 r;
    s32 a;
    s32 b;
    s32 need;
    f1 = O01Find(pad, D_auto_800E25A4[D_auto_80152789]);
    f2 = O01Find(pad, D_auto_800E25B4[D_auto_80152789]);
    if (f1 != 0 || f2 != 0) {
        *outPad = pad;
        *outBlocks = 0x7B;
        return 1;
    }
    r = func_00405160(D_800E28C8, &a);
    if (r == 0) {
        r = func_004050CC(D_800E28C8, &b);
        if (r == 0) {
            need = func_004057EC(D_8011FECC + 0x610);
            if (b == 0 || a < need) {
                if (*outBlocks < need) {
                    *outBlocks = need;
                    *outPad = pad;
                }
                return 0;
            }
        }
    }
    return r == 0;
}
