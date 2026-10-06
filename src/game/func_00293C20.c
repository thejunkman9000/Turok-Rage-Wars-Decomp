#include "b21_types.h"
#include "b21_world.h"

extern f32 D_800D2988;
extern f32 D_800CA598;
extern f32 D_800CA59C;
extern f32 D_800CA5A0;

void func_00293C20(B21Game *g) {
    B21GameBlk *b;
    if (g->unk26DD4 == 0) {
        b = &D_80145040.blk;
        b->unk0 += D_800D2988;
        if (b->unk0 >= D_800CA598) {
            b->unk0 -= D_800CA598;
            b->unk4 += D_800CA59C;
            if (b->unk4 >= D_800CA5A0) {
                b->unk4 -= D_800CA5A0;
                b->unk8 += D_800CA59C;
                if (b->unk8 >= D_800CA5A0) {
                    b->unk8 -= D_800CA5A0;
                    b->unkC += D_800CA59C;
                }
            }
        }
    }
}
