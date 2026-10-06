#include "p2_types.h"

extern s32 D_8013B190;
extern s32 D_800D297C;
void func_00273744(P2Mtx *m, s32 a);
void func_002734EC(P2Mtx *m, f32 x, f32 y, f32 z);
void func_002725BC(P2Vec3 *v, f32 s);
void func_002734B8(P2Mtx *m, f32 x, f32 y, f32 z);
void func_00273DDC(P2Mtx *m);
void func_002702EC(P2Mtx *src, P2Mtx *dst);

void func_0024F624(Actor *a) {
    P2Mtx m;

    if (a->info->kind == 8) {
        func_00273744(&m, D_8013B190);
    } else {
        func_00273744(&m, a->f174);
    }
    func_002734EC(&m, a->f194, a->f194, a->f194);
    func_002725BC(&a->pos, 20000.0f);
    func_002734B8(&m, a->pos.x, a->pos.y + a->f198, a->pos.z);
    func_00273DDC(&m);
    func_002702EC(&m, &a->mtx[D_800D297C]);
}