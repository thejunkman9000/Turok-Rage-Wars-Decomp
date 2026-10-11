#include "b21_types.h"
#include "b21_world.h"

extern f32 D_800CA5A4;
extern f32 D_800CA5A8;
extern s32 D_8010F190;
void func_002A3224();
void func_00299368(s32 a);
void func_40C4A8(s32 a);
void func_00293774(B21Game *g, s32 a);
void func_00286050(void *a);
void func_002394A4(void *a);
void func_002AB794(void *a);
void func_00293378(B21Game *g);

void func_auto_00293CE4(B21Game *g) {
    B21GameBlk *b = &D_80145040.blk;
    f32 t;
    if (b->unkAC == 1) {
        t = g->unk26DB0;
        if (D_800CA5A4 < t) {
            if (D_800CA5A8 < t) {
                b->unkAC = 0;
                func_002A3224();
                func_00299368(2);
                func_40C4A8(0);
                func_00293774(g, 1);
                g->unk26DB0 = 0.0f;
            } else if (D_8010F190 != 0) {
                b->unkAC = 0;
                func_002A3224();
                func_00299368(2);
                func_00293774(g, 8);
                g->unk26DB0 = 0.0f;
            }
        }
    }
    func_00286050(g->sub3C8);
    func_002394A4(g->sub255C8);
    func_002AB794(g->sub1BCF8);
    func_00293378(g);
}
