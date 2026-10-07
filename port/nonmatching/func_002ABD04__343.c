#include "b24_types.h"

typedef struct TabEnt {
    s32 off;
    u8 unk4;
    u8 pad5[3];
} TabEnt;

extern void *D_800D2F90;
extern u8 D_8011FE88[];
extern u8 D_8014D340[];
void *memcpy(void *, const void *, u32);
s16 **func_0028BE88(u8 *, s32, s32, s32);
void func_002536F4(s32, s16 **);

static inline void lookup(s16 **a0, s32 idx, void **out, u8 *out2) {
    s16 *t;
    TabEnt *e;
    *out = NULL;
    if (a0 != NULL) {
        t = *a0;
        e = (TabEnt *)((u8 *)t + 8);
        e += idx % *t;
        *out2 = e->unk4;
        *out = (u8 *)t + e->off;
    }
}

void func_002ABD04(void) {
    struct { void *p; u8 b; s32 x; } r;
    s16 **h;
    D_800D2F90 = NULL;
    h = func_0028BE88(D_8011FE88, 2, 0, 1);
    if (h != NULL) {
        lookup(h, 0, &r.p, &r.b);
        if (r.p != NULL) {
            r.p = (u8 *)r.p + 0x10;
        }
        memcpy(D_8014D340, r.p, 0x90);
        func_002536F4(0, h);
        D_800D2F90 = D_8014D340;
    }
}
