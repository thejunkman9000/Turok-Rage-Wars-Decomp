#include "b13_types.h"

typedef struct PosObj { u8 pad0[0x128]; Vec3f pos; } PosObj;

extern s32 D_800D0960;
extern u8 D_80145088[];

PosObj *func_00239594(void *, Vec3f *);
s32 func_002934DC(void);
void func_00257DF4(SndMgr *, s32, Vec3f, s32, s32);

void func_00258B00(SndMgr *m) {
    Vec3f v;
    PosObj *o;
    Vec3f *p;
    if (D_800D0960 != 0 && m->unk2BB4 != 0 && func_002934DC() != 0 && m->unk134 > 0) {
        v.x = v.y = v.z = 0.0f;
        o = func_00239594(D_80145088, &v);
        p = &o->pos;
        if ((m->unk104 & 3) == 0) {
            func_00257DF4(m, m->unk134, *p, 0, -1);
        }
    }
}
