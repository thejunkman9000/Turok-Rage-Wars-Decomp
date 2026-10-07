#include "m01_types.h"

typedef struct V16 { f32 x, y, z, w; } V16;
extern s32 D_8013B290;
extern f32 D_800C724C;
extern f32 D_800C7250;
extern f32 D_800C7254;

V16 *func_00219408(void *p);
void func_00271FD8(V16 *dst, Vec3f *a, Vec3f *b);
void func_002720EC(V16 *v);
void func_0027200C(V16 *dst, V16 *src, f32 s);
void func_00271FA4(V16 *dst, Vec3f *a, V16 *b);
f32 func_0024D388(M1Actor *a);
void func_0024E78C(M1Actor *a, f32 x, f32 y, f32 z, V16 *p1, s32 *p2, s32 z1, s32 z2);
s32 func_00240688(M1Actor *a, s32 k, Vec3f pos, s32 w, s32 v, V16 *out);
s32 func_00240650(M1Actor *a, Vec3f pos, s32 w, s32 v, V16 *out);
s32 func_00275B80(s32 id, f32 x, f32 z);
f32 func_00271B18(V16 *v);
f32 func_00216F44(M1Actor *a, Vec3f pos);

s32 func_00214624(M1Actor *actor, M1Ctl *ctl, M1Actor *target) {
    s32 kind;
    V16 A;
    V16 B;
    V16 V4;
    V16 V5;
    s32 w;
    f32 fs0;
    V16 *p;
    s32 r;

    if (ctl->unk4 == 0) {
        kind = 6;
    } else if (target == NULL) {
        if (ctl->b94 != 0) {
            kind = 4;
        } else {
            kind = 3;
        }
    } else if (target == ctl->unk68) {
        kind = 2;
    } else if (target->def->kind == 5) {
        kind = 5;
    } else if (target->unkE4 == 0x64F) {
        kind = 7;
    } else if (D_8013B290 != 0) {
        kind = 0;
    } else {
        kind = 1;
        if ((target->flags & 0x300000) && target->owner->unk794 == actor && target->owner->unk788 == 2) {
            goto have_kind;
        }
        if (!(actor->unk2E0 & 2) || actor->unkE4 == 0xCA) {
            kind = 0;
        }
    }
have_kind:
    switch (kind) {
    case 6:
        *(Vec3f *)&A = actor->pos;
        w = actor->unk14;
        break;
    case 4:
        p = func_00219408((u8 *)ctl + 0x94);
        *(Vec3f *)&A = *(Vec3f *)p;
        w = *(s32 *)&p->w;
        break;
    case 3:
        *(Vec3f *)&A = ctl->vB0;
        w = ctl->unkBC;
        break;
    case 7:
        if (ctl->unk80 != NULL) {
            func_00271FD8(&V4, &target->pos, &ctl->unk80->pos);
            V4.y = 0.0f;
            func_002720EC(&V4);
        } else {
            V4.x = 0.0f;
            V4.y = 0.0f;
            V4.z = 0.0f;
        }
        fs0 = func_0024D388(target);
        fs0 = fs0 + func_0024D388(actor);
        fs0 = fs0 + D_800C724C;
        func_0027200C(&V4, &V4, fs0);
        func_00271FA4(&V5, &target->pos, &V4);
        func_0024E78C(target, V5.x, V5.y, V5.z, &A, &w, 0, 0);
        break;
    case 1:
        w = func_00240688(actor, ctl->unk84, target->pos, target->unk14, ctl->unk30->unkC, &A);
        if (w != 0) break;
    default:
        *(Vec3f *)&A = target->pos;
        w = target->unk14;
        break;
    case 2:
    case 5:
        *(Vec3f *)&A = target->pos;
        w = target->unk14;
        break;
    }
    if (func_00240650(actor, *(Vec3f *)&A, w, ctl->unk30->unkC, &B)) {
        if (func_00275B80(actor->unk14, B.x, B.z)) {
            ctl->f90 = B.y;
        } else {
            ctl->f90 = B.y + D_800C7250;
        }
        func_00271FD8(&B, (Vec3f *)&B, &actor->pos);
        ctl->f8C = func_00271B18(&B) + D_800C7254;
        return 1;
    }
    if (kind == 1) {
        ctl->f90 = A.y;
        ctl->f8C = actor->f6C + func_00216F44(actor, *(Vec3f *)&A);
        return 1;
    }
    return 0;
}
