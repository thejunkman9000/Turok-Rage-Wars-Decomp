#include "p4_types.h"
extern f32 D_800CB3E8;
void func_002A94E8(void);
void func_002A9700(void);
void func_002ABB58(f32 a, f32 b);
void func_002ABB2C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_002AC398(void) {
    u8 buf[0x100];
    func_002A94E8();
    func_002A9700();
    func_002ABB58(D_800CB3E8, D_800CB3E8);
    func_002ABB2C(255, 255, 255, 200, 200, 200);
}
