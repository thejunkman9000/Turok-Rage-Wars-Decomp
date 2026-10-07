#include "o03_types.h"
typedef struct Q2PjRec {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 state;
    s32 f10;
    s32 f14;
    u8 sub[0x4A8];
    s32 cnt;
    s32 fpad;
} Q2PjRec;
typedef struct Q2Pj {
    s32 h0;
    s32 h4;
    Q2PjRec rec[4];
    s32 pad1328[4];
    s32 f1338;
} Q2Pj;
extern Q2Pj *D_800E42D0;
extern s32 D_800E41C0[][4];
extern s32 D_800D15E0;
extern f32 D_800D15E4[];
extern s32 D_800E28D0;
extern s32 D_800E28D4;
void func_0041C864(void *p);
s32 func_0041FCC0(s32 a0, s32 a1, s32 a2) {
    s32 i;
    O3Dl *g;
    if (a2 == 1 && D_800E42D0->f1338 == 3) {
        D_800D15E0 = 0;
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
        for (i = 0; i < 4; i++) {
            if (D_800E42D0->rec[i].state == 1 || D_800E42D0->rec[i].state == 3) {
                if (D_800E42D0->rec[i].f8 != -1) {
                    g = D_80110634++;
                    g->w0 = (((s32)((f32)D_800E41C0[i][0] * 4.0f) & 0xFFF) << 12) | ((s32)((f32)D_800E41C0[i][1] * 4.0f) & 0xFFF) | 0xED000000;
                    g->w1 = (((s32)((f32)D_800E41C0[i][2] * 4.0f) & 0xFFF) << 12) | ((s32)((f32)D_800E41C0[i][3] * 4.0f) & 0xFFF);
                    if (D_800E42D0->rec[i].cnt > 0) {
                        D_800D15E4[0] = 150.0f;
                        D_800D15E4[1] = 0;
                        D_800D15E4[2] = 0;
                        D_800D15E4[3] = 100.0f;
                        D_800D15E4[4] = 100.0f;
                        D_800D15E0 = 3;
                        D_800E42D0->rec[i].cnt = D_800E42D0->rec[i].cnt - 1;
                    } else {
                        D_800D15E0 = 0;
                        D_800D15E4[0] = 255.0f;
                        D_800D15E4[1] = 255.0f;
                        D_800D15E4[2] = 255.0f;
                        D_800D15E4[3] = 255.0f;
                    }
                    func_0041C864(D_800E42D0->rec[i].sub);
                }
            }
        }
        g = D_80110634++;
        D_800D15E0 = 0;
        g->w0 = 0xED000000;
        g->w1 = (((s32)((f32)(D_800E28D0 - 1) * 4.0f) & 0xFFF) << 12) | ((s32)((f32)(D_800E28D4 - 1) * 4.0f) & 0xFFF);
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
    }
    return 0;
}
