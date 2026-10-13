#include "common.h"

void func_002A94E8(void);
void func_002A97F0(void);
void func_002ABB58(f32 a, f32 b);
void func_002ABB2C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_002ABB6C(u8 *p, f32 a, f32 b, f32 c, f32 d, s32 e, s32 f, s32 g);
extern s32 D_8011FAB0;
extern f32 D_8014AD78;
extern u8 D_auto_80152789;
extern s32 *D_auto_800E42A4[];
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern s32 D_8014D3D0;

void func_auto_00290F8C(void) {
    s32 idx = D_8011FAB0;
    f32 t = D_8014AD78;
    u8 *p;
    f32 v;
    s32 c;
    func_002A94E8();
    func_002A97F0();
    func_002ABB58(1.0f, 1.0f);
    do {
        p = (u8 *)D_auto_800E42A4[D_auto_80152789][idx];
        if (p != 0) {
            if (t < 0.0f) {
                v = 0.0f;
            } else if (!(16.0f < t)) {
                if (!(t < 0.0f)) {
                    v = t * 16.0f;
                } else {
                    v = 0.0f;
                }
            } else {
                v = 256.0f;
            }
            if (255.0f < v) {
                v = 255.0f;
            }
            c = (s32)v;
            func_002ABB2C(255, 255, 255, c, c, c);
            if (0.0f <= t) {
                func_002ABB6C(p, (f32)(D_800E28D0 * 14 / 284), (f32)(s32)t,
                              (f32)D_800E28D0 * 0.0028169013f, (f32)D_800E28D4 * 0.0045045046f, 1, c, D_8014D3D0);
            }
            idx++;
        }
        t = t + (f32)D_800E28D4 * 0.045045048f;
    } while (t <= (f32)D_800E28D4);
}
