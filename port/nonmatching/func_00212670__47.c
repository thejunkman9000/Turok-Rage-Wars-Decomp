#include "b03_types.h"

extern EntList D_8013B364[];
extern f32 D_800C71B0;
EntRec *func_0020C994(EntList *list, s32 key);
void *func_0020C9B0(EntList *list, s32 key);
s32 func_0020CCE8(EntList *list, s32 key, s32 *a, s32 *b);
s32 func_0020D1CC(EntList *list, s32 a, s32 b);
f32 func_0027272C(Vec3f *a, EntRec *b);

void func_00212670(BrainB *b) {
    s32 ids[64];
    s32 keys[64];
    Vec3f pos;
    EntList *L = D_8013B364;
    ActorB *t;
    EntRec *r;
    f32 best;
    f32 d;
    s32 me;
    s32 sel;
    s32 n;
    s32 i;
    u32 type;

    t = b->unk64->owner;
    me = t->brain->unk4;
    pos = t->pos;
    for (i = 0; i < 64; i++) {
        ids[i] = -1;
        keys[i] = -1;
    }
    sel = -1;
    best = D_800C71B0;
    n = func_0020CCE8(L, b->unk4, ids, keys);
    for (i = 0; i < n; i++) {
        type = FLD(u8, func_0020C9B0(L, keys[i]), 4);
        if (type == 1 || type == 2 || type == 7) {
            r = func_0020C994(L, ids[i]);
            if (func_0020D1CC(L, me, ids[i]) != 0) {
                d = func_0027272C(&pos, r);
                if (best < d) {
                    best = d;
                    sel = i;
                }
            }
        }
    }
    b->unkC = sel;
}
