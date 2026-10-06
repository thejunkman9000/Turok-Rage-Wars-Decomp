#include "common.h"

void func_0022A404(u8 *p);
void func_002947DC(s32 a, s32 b);
void func_00293808(s32 a, s32 b);
extern s32 D_80146958;
extern f32 D_80146D74;
extern f32 D_800D2988;
extern u8 D_80145040[];
extern s32 D_800D29D4;
extern s32 D_800D29D0;
extern s32 D_8014692C;
extern s32 D_800E28D4;
extern f32 D_8014AD78;
extern s32 D_8011FAB0;
extern s32 *D_800D7E40;

void func_00291054(s32 a) {
    f32 f;
    s32 idx;
    if (D_80146958 != 0) {
        D_80146D74 = D_80146D74 - D_800D2988;
        if (D_80146D74 <= 0.0f) {
            func_0022A404(D_80145040);
            if (D_800D29D4 != 0) {
                if (D_800D29D0 == 0) {
                    func_002947DC(a, 0x7CF);
                    return;
                }
                func_00293808(a, 1);
                D_8014692C = 1;
            } else if (D_800D29D0 != 0) {
                func_00293808(a, 1);
                D_8014692C = 1;
            }
        }
    } else {
        if (D_800E28D4 >= 0xDF) {
            D_8014AD78 = D_8014AD78 - 1.0f;
        } else {
            D_8014AD78 = D_8014AD78 - 0.5f;
        }
        f = (f32)D_800E28D4 * 0.045045048f;
        if (D_8014AD78 <= -f) {
            D_8014AD78 = D_8014AD78 + f;
            idx = D_8011FAB0 + 1;
            D_8011FAB0 = idx;
            if (D_800D7E40[idx] == 0) {
                D_80146958 = 1;
                D_80146D74 = 67.5f;
            }
        }
    }
}
