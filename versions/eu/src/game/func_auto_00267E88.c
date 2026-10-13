#include "b15_types.h"

typedef struct B15Idx { s32 idx; s32 y; } B15Idx;
typedef struct B15Snd {
    s32 *a;
    s32 b;
} B15Snd;

void func_00237E70(void *a, void *b, s32 c);
void func_0025E13C(s32 a);
extern u8 D_80145088[];
extern B15Snd D_800E45D4[];

void func_auto_00267E88(s32 a, Actor *src, s32 c, Vec3f pos, B15Idx k) {
    void *p;

    if (*(u8 *)src == 1 && (src->flags & 0x300000)) {
        p = *(void **)((u8 *)src->owner + 0x5DC);
        if (p == NULL) goto tail;
        func_00237E70(D_80145088, p, D_800E45D4[k.idx].a[D_80145088[0x17C1]]);
    } else {
        func_00237E70(D_80145088, D_80145088 + 0x40, D_800E45D4[k.idx].a[D_80145088[0x17C1]]);
    }
tail:
    if (D_800E45D4[k.idx].b != 0) {
        func_0025E13C(D_800E45D4[k.idx].b);
    }
}
