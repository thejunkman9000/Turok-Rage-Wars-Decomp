#include "b13_types.h"

extern u8 D_80145088[];
s32 func_00239594(void *p, s32 id);
s32 func_0025BA6C(void *pool, s16 a);
f32 func_0025C12C(s32 id, s32 p);
s32 func_0025BDCC(void *pool, s16 a, s32 b);
s32 func_00259280(void *q, SndInfo *info, s32 id, s32 a3, s32 a5);
void func_0025B940(void *pool, s16 a, s16 b);
SndVoice *func_0025B1E8(void *pool, SndInfo *info, s32 a3, s32 a4);
void func_0025BB7C(SndVoice *v, s32 id, s32 a6);
void func_0025BB9C(SndVoice *v, s16 a);
void func_0025BBA4(SndVoice *v, SndInfo *info, s32 a5);
s32 func_00257814(SndMgr *m, s32 id, s32 a2, s32 a3);

s32 func_00257BD4(SndMgr *m, SndInfo *info, s32 id, s32 a3, s32 a4, s32 a5, s32 a6) {
    SndVoice *v;
    m->unk2B98 = func_00239594(D_80145088, id);
    if (info->bits6 & 1) {
        if (func_0025BA6C(&m->pool, m->unk2B8C) != 0) {
            return -1;
        }
        if (func_0025C12C(id, m->unk2B98 + 0x128) == 0.0f) {
            return -1;
        }
    }
    if (info->bits6 & 0x1000) {
        if (m->unk2B90 != -1) {
            if (func_0025BDCC(&m->pool, m->unk2B8C, m->unk2B90) != -1) {
                return -1;
            }
        }
    }
    if (info->w2 != 0) {
        return func_00259280(&m->q, info, id, a3, a5);
    }
    if (info->bits6 & 0x40) {
        func_0025B940(&m->pool, m->unk2B8C, info->w0);
    }
    v = func_0025B1E8(&m->pool, info, a3, a4);
    if (v == 0) {
        return -1;
    }
    func_0025BB7C(v, id, a6);
    func_0025BB9C(v, m->unk2B8C);
    func_0025BBA4(v, info, a5);
    SndMgr_Lock(m);
    func_00257814(m, v->unkC, 0, id);
    SndMgr_Unlock(m);
    return 0;
}
