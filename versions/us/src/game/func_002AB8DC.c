#include "b24_types.h"

typedef struct TabEnt {
    s32 off;
    u8 unk4;
    u8 pad5[3];
} TabEnt;

void func_002AB8DC(s16 **a0, s32 idx, void **out, u8 *out2) {
    s16 *t;
    TabEnt *e;
    u8 *p;
    s32 i;
    u8 b;
    s32 off;

    *out = NULL;
    if (a0 != NULL) {
        t = *a0;
        i = idx % *t;
        p = (u8 *)t + 8;
        e = (TabEnt *)(i * 8 + (u32)p);
        b = e->unk4;
        off = e->off;
        *out2 = b;
        *out = (u8 *)t + off;
    }
}
