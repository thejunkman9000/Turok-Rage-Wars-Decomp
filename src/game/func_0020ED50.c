#include "b02_types.h"

s32 func_0020D1CC(B2Mgr *m, s32 i, s32 j);
s32 func_0020BC50(B2Mgr *m, s32 a, s32 b, B2Edge2 *obj);
extern B2Mgr D_8013B364;

s32 func_0020ED50(B2Edge2 *obj) {
    B2Mgr *m = &D_8013B364;

    if (m != NULL) {
        if (obj->dst == -1) {
            return 1;
        }
        if (obj->src == obj->dst) {
            return 1;
        }
        if (func_0020D1CC(m, obj->src, obj->dst) != 0) {
            return 1;
        }
        obj->unkC = func_0020BC50(m, obj->src, obj->dst, obj);
    }
    return 1;
}
