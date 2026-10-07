#include "b12_types.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
extern u8 D_801051A0[];
void func_00254D70(s32 a, B12Node *n);
void func_00255ACC(void *list, s32 key);
void func_00254A70(s32 a, B12Node *n);

inline void func_00254930(s32 unused, B12Node *n) {
    n->flags &= ~2;
    while (n->refs != 0) {
        n->refs--;
        if (n->refs == 0) {
            n->flags &= ~0x100;
        }
    }
    if (!(n->flags & 0x702)) {
        func_00254D70(0, n);
        func_00255ACC(D_801051A0, n->key);
        func_00254A70(0, n);
    }
}

void func_00253CB0(s32 unused, B12Node **p, B12Node *n2) {
    u32 mask;
    u32 m2;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    func_00254930(0, p[0]);
    p[0] = n2;
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
}
