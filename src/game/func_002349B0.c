#include "b08_types.h"

typedef struct Quat {
    f32 x, y, z, w;
} Quat;

typedef struct Mtx4 {
    f32 m[16];
} Mtx4;

typedef struct EmitNode EmitNode;
struct EmitNode {
    s32 unk0;
    EmitNode *next4;
};

typedef struct CamObj {
    u8 pad0[0x28];
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    Vec3f pos38;
    f32 unk44;
    Quat quat48;
    u8 pad58[0x24];
    s32 unk7C;
    u8 pad80[0x20];
    ChanObj chans;
    u8 padF4[0x3C];
    Quat unk130;
    Quat unk140;
    Quat unk150;
    Mtx4 unk160;
} CamObj;

extern f32 D_80115DEC;
extern u8 D_801450C8[];

s32 func_00245788();
void func_00239E94(CamObj *o, Vec3f *out);
void func_00274108(Quat *out, Quat *a, Quat *b);
void func_002742B4(Quat *q, Mtx4 *m);
void func_00272CD0(Mtx4 *m, f32 x, f32 y, f32 z);
void func_00233920(ChanObj *o, Vec3f p, Vec3f *out);
s32 func_002337C0(Chan *c);
void func_0026F690(Mtx4 *out, Mtx4 *a, Mtx4 *b);
void func_00272908(Mtx4 *m, Vec3f *in, Vec3f *out);

void func_002349B0(CamObj *o) {
    Quat q1, q2, q3, q4, q5;
    Mtx4 m1, m2, m3, m4, m5, m6;
    Vec3f jit;
    Vec3f force;
    Vec3f tv;
    f32 ang;
    f32 k;
    f32 sn;
    f32 fs1, fs1f;
    EmitNode *n;

    if (o->unk7C != 0) {
        fs1 = o->unk2C;
        fs1f = o->unk34;
        if (func_00245788() == 0) {
            func_00239E94(o, &jit);
            fs1f += jit.z;
            k = 0.5f;
            fs1 += jit.x;
            D_80115DEC = sinf(fs1f * k);
            q3.x = 0;
            q3.y = 0;
            q3.z = D_80115DEC;
            q3.w = cosf(fs1f * k);
            D_80115DEC = sinf(fs1 * k);
            q1.x = D_80115DEC;
            q1.y = 0;
            q1.z = 0;
            q1.w = cosf(fs1 * k);
            D_80115DEC = sinf((o->unk28 + o->unk30) * k);
            q2.x = 0;
            q2.y = D_80115DEC;
            q2.z = 0;
            q2.w = cosf((o->unk28 + o->unk30) * k);
            func_00274108(&q4, &q1, &q2);
            func_00274108(&o->unk150, &q4, &o->quat48);
            func_00274108(&o->unk140, &q3, &o->unk150);
            func_00274108(&q5, &q3, &q4);
            func_002742B4(&q5, &m1);
            func_00272CD0(&m2, 0.0f, o->unk44, 0.0f);
            func_002742B4(&o->quat48, &m3);
            force.x = 0.0f;
            force.y = 0.0f;
            force.z = 0.0f;
            func_00233920(&o->chans, o->chans.ch[0].v, &force);
            func_002337C0(&o->chans.ch[1]);
            func_002337C0(&o->chans.ch[2]);
            func_002337C0(&o->chans.ch[3]);
            if ((u8 *)o != D_801450C8) {
                for (n = *(EmitNode **)(D_801450C8 + 0x11AC); n != NULL; n = n->next4) {
                    func_00233920((ChanObj *)n, o->pos38, &force);
                }
            }
            func_0026F690(&m5, &m1, &m3);
            func_00272908(&m5, &force, &tv);
            func_0026F690(&m5, &m1, &m2);
            func_0026F690(&m6, &m5, &m3);
            func_00272CD0(&m4, o->pos38.x + tv.x, o->pos38.y + jit.y + tv.y, o->pos38.z + tv.z);
            func_0026F690(&o->unk160, &m6, &m4);
        } else {
            D_80115DEC = sinf(o->unk34 * 0.5f);
            q3.x = 0;
            q3.y = 0;
            q3.z = D_80115DEC;
            q3.w = cosf(o->unk34 * 0.5f);
            D_80115DEC = sinf(o->unk2C * 0.5f);
            q1.x = D_80115DEC;
            q1.y = 0;
            q1.z = 0;
            q1.w = cosf(o->unk2C * 0.5f);
            sn = sinf((o->unk28 + o->unk30) * 0.5f);
            q2.x = 0;
            q2.y = sn;
            q2.z = 0;
            D_80115DEC = sn;
            q2.w = cosf((o->unk28 + o->unk30) * 0.5f);
            func_00274108(&q4, &q1, &q2);
            o->unk150 = q4;
            func_00274108(&o->unk140, &q3, &o->unk150);
            func_002742B4(&q4, &m1);
            func_00272CD0(&m4, o->pos38.x, o->pos38.y, o->pos38.z);
            func_0026F690(&o->unk160, &m1, &m4);
        }
        o->unk130.y = fs1;
        o->unk130.w = fs1f;
        o->unk130.z = o->unk28;
    }
}
