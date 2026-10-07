#include "b12_types.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
B12Node *func_00251448(s32 a, u32 flags);
s32 func_00254B2C(s32 a, s32 b, s32 c, u32 d);
void func_00254C10(s32 a, B12Node *n);
void func_00254A70(s32 a, B12Node *n);

B12Node *func_002545A0(s32 unused, s32 a1, s32 a2) {
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
    n = func_00251448(0, 0x22);
    if (n) {
        n->refs++;
        n->flags |= 0x100;
        n->key = func_00254B2C(0, a2, (0x22 >> 5) & 1, 0x22);
        if (n->key) {
            n->unk4 = a2;
            n->flags |= 0x22;
            func_00254C10(0, n);
        } else {
            n->refs--;
            if (n->refs == 0) {
                n->flags &= ~0x100;
            }
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
