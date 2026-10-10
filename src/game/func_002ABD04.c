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

void func_002ABD04(void) {
    struct { void *p; u8 b; } r;
    s16 **h;
    s16 *t;
    TabEnt *e;
    D_800D2F90 = NULL;
    h = func_0028BE88(D_8011FE88, 2, 0, 1);
    if (h != NULL) {
        t = *h;
        r.p = NULL;
        e = (TabEnt *)((u8 *)t + 8);
        e += 0 % *t;
        { s32 off = e->off; r.b = e->unk4; r.p = (u8 *)t + off; }
        if (r.p != NULL) {
            r.p = (u8 *)r.p + 0x10;
        }
        memcpy(D_8014D340, r.p, 0x90);
        func_002536F4(0, h);
        D_800D2F90 = D_8014D340;
    }
}
