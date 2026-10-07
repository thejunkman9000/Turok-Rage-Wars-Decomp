#include "b13_types.h"

extern f32 D_800C8FE8;

void func_0025CEF0(SndFx *fx, s32 a, f32 x, s32 b);

void func_00258F30(SndMgr *m, s32 a) {
    f32 t = D_800C8FE8;
    if (!(t < m->unk2BA8)) {
        t = m->unk2BA8;
    }
    func_0025CEF0(&m->obj2BC0, a, t, 0x40);
}
