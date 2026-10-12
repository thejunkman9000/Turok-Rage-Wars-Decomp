#include "b02_types.h"

void *func_0020C994(B2Mgr *ref, s32 idx);
f32 func_00272768(Vec3f *pos, void *p);
extern B2Mgr D_8013B364;

void func_00209948(B2Ctl *ctl, s32 idx) {
    func_00272768(&ctl->owner->pos, func_0020C994(&D_8013B364, idx));
}
