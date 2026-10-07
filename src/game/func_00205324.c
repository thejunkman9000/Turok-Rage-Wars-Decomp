#include "m01_types.h"

extern s32 D_8011FE88[];
extern u8 D_8013BA80[];
void func_00285D80(s32 *p, M1Actor *a, s32 n);
void func_00278DE8(M1Actor *a, s32 b, M1Actor *c);
void func_0025DE74(s16 id, Vec3f pos, s32 a, s32 b);
void func_00216288(M1Actor *a, s32 id, Vec3f pos, s32 n);
void func_002170A0(M1Actor *a, M1State *s, s32 n, s32 x, s32 y);
void func_002A6D28(u8 *p, M1Actor *a);

void func_00205324(M1Actor *actor, M1State *state) {
    M1Info *info = &actor->def->info;
    s32 mode;
    func_00285D80(D_8011FE88, actor, 1);
    func_00278DE8(actor, 0x40000, actor);
    if (state->unk4 == 0) {
        actor->flags &= ~0x10000;
    }
    if (info->unk18 == 0) {
        actor->flags &= ~0x2000;
        actor->flags &= ~0x100;
    }
    mode = D_8011FE88[0];
    if (mode == 4) {
        if (info->unk20.i != -1) {
            func_0025DE74(info->unk20.h[1], actor->pos, 0, -1);
        }
        if (info->unk1C != -1) {
            func_00216288(actor, info->unk1C, actor->pos, 0);
        }
        func_002170A0(actor, state, 4, info->unk24.i, info->unk28.i);
        func_002A6D28(D_8013BA80, actor);
        if (D_8011FE88[0] != mode) goto L;
    } else {
L:
        actor->flags &= ~0x100;
        actor->flags |= 0x8000000;
    }
}
