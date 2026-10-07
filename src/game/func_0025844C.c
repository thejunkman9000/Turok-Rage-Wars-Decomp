#include "b13_types.h"

typedef struct PosObj { u8 pad0[0x128]; Vec3f pos; } PosObj;

extern f32 D_800C8FD0;
extern u8 D_801462E1[];
extern s32 D_800D0960;
extern u8 D_80145088[];

void func_0025BD20(SndVoices *p);
void func_00259460(SndQueue *q);
void func_0025CCB0(SndFx *fx);
void func_0025D948(SndSeq *s);
void func_0025D470(SndSeq *s);
PosObj *func_00239594(void *, Vec3f *);
s32 func_002934DC(void);
void func_00257DF4(SndMgr *, s32, Vec3f, s32, s32);

void func_0025844C(SndMgr *m) {
    Vec3f v;
    PosObj *o;
    Vec3f *p;
    u8 *t = D_801462E1;
    m->unk2BA0 = t[0] * D_800C8FD0;
    m->unk2BA4 = t[-1] * D_800C8FD0;
    m->unk2BA8 = t[1] * D_800C8FD0;
    m->unk2BB0 = t[-2];
    SndMgr_Lock(m);
    func_0025BD20(&m->pool);
    SndMgr_Unlock(m);
    func_00259460(&m->q);
    func_0025CCB0(&m->obj2BC0);
    func_0025D948(&m->seq);
    func_0025D470(&m->seq);
    if (D_800D0960 != 0 && m->unk2BB4 != 0 && func_002934DC() != 0 && m->unk134 > 0) {
        v.z = 0.0f;
        v.y = 0.0f;
        v.x = 0.0f;
        o = func_00239594(D_80145088, &v);
        p = &o->pos;
        if ((m->unk104 & 3) == 0) {
            func_00257DF4(m, m->unk134, *p, 0, -1);
        }
    }
    m->unk104++;
}
