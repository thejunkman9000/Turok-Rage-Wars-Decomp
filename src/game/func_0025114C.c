#include "b12_types.h"

extern s32 D_80105134[];
extern s32 D_80104598[];
extern s32 D_801045A0[];
extern s32 D_801045A8;
extern OSMesgQueue D_80105140;
extern OSMesgQueue D_80105160;
extern s32 D_8010515C;
void func_00254CE4(s32 a, s32 type);

void func_0025114C(void) {
    s32 cnt = 0;
    s32 i;
    s32 j;
    u32 mask;
    u32 m2;
    for (i = 0; i < 2; i++) {
        if (D_80105134[i]) {
            if (D_801045A8 == i) {
                D_80104598[i] = 0;
                func_00254CE4(0, i);
            } else {
                cnt++;
                D_801045A0[i] = 1;
            }
        }
    }
    if (cnt) {
        m2 = __osDisableInt();
        if (--D_8010515C != 0) {
            __osRestoreInt(m2);
            osSendMesg(&D_80105140, 0, 1);
        } else {
            __osRestoreInt(m2);
        }
        for (j = 0; j < cnt; j++) {
            osRecvMesg(&D_80105160, 0, 1);
        }
        mask = __osDisableInt();
        if (++D_8010515C != 1) {
            __osRestoreInt(mask);
            osRecvMesg(&D_80105140, 0, 1);
        } else {
            __osRestoreInt(mask);
        }
    }
}
