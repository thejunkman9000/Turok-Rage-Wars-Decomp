#include "b20_types.h"

typedef struct { Vec3f a; Vec3f b; } Pair;

s32 *func_0028FD94(s32 *tbl, s32 idx);
void func_00289790(Level *lv, Vec3f *a, u8 *buf, s32 *out);
void func_0028994C(u8 *buf, s32 n, Vec3f *a, Pair *out);
extern Pair D_800D0EE0;
extern s32 D_800D2850;

static inline s32 hasTbl(Level *lv) {
    s32 i;
    for (i = 0; i < lv->cnt1504; i++) {
        s32 *t = func_0028FD94(*lv->ents[i].tblp, 2);
        if (t[1] != 0) {
            return 1;
        }
    }
    return 0;
}

void func_0028C6B0(Level *lv, Vec3f *a1, Pair *out) {
    u8 buf[0x28];
    s32 n;
    if (hasTbl(lv) == 0 || D_800D2850 == 0) {
        *out = D_800D0EE0;
        return;
    }
    func_00289790(lv, a1, buf, &n);
    func_0028994C(buf, n, a1, out);
}
