#include "q01_types.h"
typedef struct Q01V3 { s32 x, y, z; } Q01V3;
typedef struct Q01Mtx { s32 w[4]; } Q01Mtx;
typedef struct Q01M80 { s32 w[20]; } Q01M80;
typedef struct Q01M64 { s32 w[16]; } Q01M64;
typedef struct Q01Obj { u8 pad0[8]; Q01V3 pos; u8 pad14[0x6C-0x14]; f32 f6C; } Q01Obj;
typedef struct Q01Anim {
    s32 *unk0;
    s32 unk4;
    u8 pad8[0x10];
    Q01Obj *unk18;
    f32 f1C, f20, f24, f28, f2C, f30, f34;
    s32 unk38;
    u8 pad3C[0x38];
    s32 unk74;
    u8 pad78[0xF0-0x78];
    Q01V3 vF0;
    f32 fFC;
    u8 pad100[0x1E0-0x100];
    s32 unk1E0;
} Q01Anim;
typedef struct Q01Out { u8 pad0[0x28]; f32 f28, f2C; u8 pad30[8]; Q01V3 v38; } Q01Out;
extern Q01Anim *D_800E2830;
extern Q01Obj *D_80145060;
extern f32 D_800E0B70;
extern f32 D_800E0B74;
extern u8 D_8011FE88[];
extern u8 D_80104030[];
extern Q01V3 D_801041F8;
s32 func_00245788();
void func_002453C4();
f32 func_00271B18(void *m);
f32 func_0027266C(void *m);
void func_00271FA4(Q01V3 *a, Q01V3 *b, Q01V3 *c);
void func_00271FD8(void *m, Q01V3 *a, Q01V3 *b);
void func_0027200C(Q01V3 *a, Q01V3 *b, f32 f);
void func_00272848(void *m);
void func_00272908(void *m, Q01V3 *a, Q01V3 *b);
void func_00272EAC(void *m, f32 a, f32 b, f32 c);
void func_00288440(void *a);
void func_0028D864(void *a);
s32 func_00243A80(void *a, Q01V3 b, void *c);
void func_00401214(Q01V3 *v, f32 f);
void func_004013BC(Q01V3 *v, f32 f);

void func_00401980(Q01Out *arg0) {
    Q01V3 v18;
    Q01V3 v28;
    Q01Mtx m38;
    Q01M80 m48;
    Q01M64 m98;
    Q01V3 vD8;
    Q01Obj *s3;
    s32 r;
    f32 fs0, fs1;
    if (D_800E2830->unk38 == 0) return;
    if (func_00245788() == 0) return;
    if (D_800E2830->f1C < D_800E2830->f30) return;
    if (D_800E2830->f34 < D_800E2830->f1C) return;
    if (D_800E2830->unk1E0 > 0) func_002453C4();
    func_00401214(&v18, D_800E2830->f1C);
    func_004013BC(&v28, D_800E2830->f1C);
    fs0 = D_800E0B70;
    func_0027200C(&v18, &v18, fs0);
    func_0027200C(&v28, &v28, fs0);
    arg0->f28 = 0.0f;
    func_00271FD8(&m38, &v28, &v18);
    if (((D_800E2830->unk74 & 1) && D_800E2830->unk18 != 0) || (D_800E2830->unk74 & 2)) {
        s3 = D_80145060;
        if (D_800E2830->unk74 & 1) {
            if (D_800E2830->unk18 != 0) {
                D_800E2830->vF0 = D_800E2830->unk18->pos;
                D_800E2830->fFC = D_800E2830->unk18->f6C + D_800E0B74;
            }
        }
        if (D_800E2830->unk74 & 2) {
            if (s3 != 0) {
                D_800E2830->vF0 = s3->pos;
                D_800E2830->fFC = s3->f6C;
            } else {
                D_800E2830->vF0.x = 0;
                D_800E2830->vF0.y = 0;
                D_800E2830->vF0.z = 0;
                D_800E2830->fFC = 0.0f;
            }
        }
        func_00272848(&m98);
        func_00272EAC(&m98, 0.0f, D_800E2830->fFC, 0.0f);
        func_00272908(&m98, &v28, &vD8);
        v28 = vD8;
        func_00272908(&m98, &v18, &vD8);
        v18 = vD8;
        func_00271FA4(&v28, &v28, &D_800E2830->vF0);
        func_00271FA4(&v18, &v18, &D_800E2830->vF0);
        func_00271FD8(&m38, &v28, &v18);
        if (s3 != 0) {
            m48 = *(Q01M80 *)s3;
            s3->pos = v28;
            func_00288440(D_8011FE88);
            r = func_00243A80(s3, v18, D_80104030);
            func_0028D864(D_8011FE88);
            *(Q01M80 *)s3 = m48;
            if (r != 0) v18 = D_801041F8;
        }
    }
    fs1 = func_00271B18(&m38);
    {
    f32 t = func_0027266C(&m38);
    arg0->f28 = arg0->f28 + fs1;
    arg0->f2C = -t;
    }
    arg0->v38 = v18;
}
