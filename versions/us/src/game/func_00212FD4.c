#include "b03_types.h"

extern EntList D_8013B364[];
extern f32 D_800C71D0;
extern f32 D_800C71D4;
void func_00208410(BrainB *b);
void func_00208EB0(BrainB *b);
void func_00209804(BrainB *b);
void func_00209874(BrainB *b, s32 mode);
f32 func_00209948(BrainB *b, s32 id);
s32 func_0020B95C(EntList *list, s32 a, s32 b, s32 *out, s32 flag);
void func_00211020(BrainB *b);
f32 func_00272768(Vec3f *a, Vec3f *b);

void func_00212FD4(ActorB *actor) {
    BrainB *b = actor->owner->brain;
    EntList *L = D_8013B364;
    s32 arr[64];
    f32 d;
    s32 i;
    s32 n;
    s32 id;
    s32 first;

    if (b->unkBC == -1) {
        func_00209874(b, 2);
        return;
    }
    if (b->unk68 == NULL) {
        func_00211020(b);
        return;
    }
    d = func_00209948(b, b->unkC);
    if (b->unk4 != b->unkC && D_800C71D0 < d) {
        func_00208410(b);
    } else if (b->unk238 != 0) {
        func_00209874(b, 8);
    } else {
        b->unk2C = b->unk68->pos;
    }
    func_00211020(b);
    if (b->unk68 != NULL) {
        func_00208EB0(b);
        if (func_00272768(&b->actor->pos, &b->unk68->pos) < D_800C71D4 && b->unk238 == 0) {
            b->unk238 = 1;
            for (i = 0; i < 64; i++) {
                arr[i] = -1;
            }
            func_0020B95C(L, b->unkC, b->unkC, arr, 0);
            first = arr[0];
            for (i = 0; i < 64; i++) {
                arr[i] = -1;
            }
            n = func_0020B95C(L, first, b->unkC, arr, 0);
            func_00209804(b);
            b->unkC = arr[n - 1];
        }
    }
}
