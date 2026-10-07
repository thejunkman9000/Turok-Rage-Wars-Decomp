#include "b12_types.h"
#include "libaudio.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
extern u8 D_801051A0[];
B12Node *func_00251448(s32 a, s32 b);
s32 func_002555D0(void *heap, s32 ptr, s32 size);
void func_00254C10(s32 a, B12Node *n);
void func_00254A70(s32 a, B12Node *n);

B12Node *func_002534D0(s32 unused, s32 ptr, s32 size) {
    u32 mask;
    u32 m2;
    B12Node *n;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    n = func_00251448(0, 0);
    if (n) {
        n->key = func_002555D0(D_801051A0, ptr, size);
        if (n->key) {
            n->unk4 = size;
            n->flags |= 3;
            func_00254C10(0, n);
        } else {
            func_00254A70(0, n);
            n = 0;
        }
    }
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
    return n;
}
