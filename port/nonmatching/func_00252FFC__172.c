#include "b12_types.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
extern u8 D_800C8F98[];
B12Node *func_00254858(s32 a, void *b, u32 c, void *d);
void func_0025114C(s32 a);
s32 func_00254AF8(s32 a, s32 b, s32 c);
void func_00251590(s32 a, s32 b);

u8 *func_00252FFC(u8 *p) {
    u32 m1;
    u32 m2;
    u32 m3;
    u32 m4;
    u32 m5;
    u32 m6;
    B12Node *n;
    u8 *data = p + 0x10;
    u8 *blk;
    m1 = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(m1);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m1);
    }
    n = func_00254858(0, data, 0x33, D_800C8F98);
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
    if (!n) {
        m3 = __osDisableInt();
        if (++D_8010515C != 1) {
            __osRestoreInt(m3);
            osRecvMesg(&D_80105140, 0, 1);
        } else {
            __osRestoreInt(m3);
        }
        func_0025114C(0);
        while (func_00254AF8(0, 0, 0)) {
        }
        func_00251590(0, 1);
        m4 = __osDisableInt();
        if (--D_8010515C != 0) {
            __osRestoreInt(m4);
            osSendMesg(&D_80105140, 0, 1);
        } else {
            __osRestoreInt(m4);
        }
        m5 = __osDisableInt();
        if (++D_8010515C != 1) {
            __osRestoreInt(m5);
            osRecvMesg(&D_80105140, 0, 1);
        } else {
            __osRestoreInt(m5);
        }
        n = func_00254858(0, data, 0x33, D_800C8F98);
        m6 = __osDisableInt();
        if (--D_8010515C != 0) {
            __osRestoreInt(m6);
            osSendMesg(&D_80105140, 0, 1);
        } else {
            __osRestoreInt(m6);
        }
        if (!n) {
            return 0;
        }
    }
    blk = (u8 *)n->key;
    *(B12Node **)blk = n;
    return blk + 0x10;
}
