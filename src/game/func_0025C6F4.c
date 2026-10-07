
#include "b13_types.h"

SndEnv *func_00258C14(SndMgr *m, s16 id);
s32 func_00258D4C(SndMgr *m, s16 id);
s16 func_00259B30(Vec3f *pos, SndMgr *m);
f32 Trunc16ToF32(u16 v);

void func_0025C6F4(SndVoice *v, SndInfo *info) {
    f32 d;
    s16 id;
    v->pan = 0x40;
    id = info->wC;
    if (id != -1) {
        v->env = *func_00258C14(v->mgr, id);
        d = Trunc16ToF32(v->env.a);
        do { v->unk9C = (d - Trunc16ToF32(v->env.b)) / (f32)v->env.c;
        v->unk98 = Trunc16ToF32(v->env.a);
        v->pan = Trunc16ToF32(v->env.a);
        v->unk88 = 1; return; } while (0);
    } else {
        v->unk88 = 0;
        if (v->tag < 0x100) {
            if (v->unkC0 == 0 && func_00258D4C(v->mgr, id) != 0) {
                v->pan = (s8)v->mgr->unk2B94;
            }
        } else if (v->unkC0 == 0 && func_00258D4C(v->mgr, id) != 0) {
            v->pan = func_00259B30(&v->pos, (SndMgr *)v->mgr->unk2B98);
        }
    }
}


