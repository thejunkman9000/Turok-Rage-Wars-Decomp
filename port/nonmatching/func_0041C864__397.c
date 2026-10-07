#include "o03_types.h"
extern s32 D_800D15D0;
extern s32 D_800D297C;
extern O3Dl *D_80110634;
extern u8 D_801450C8[];
extern O3Blk6 D_800E3570;
void func_00246E34(void *p);
void func_00249E18(void *p, void *q);
void func_0024B8B4(void *p);
void func_0025470C(s32 a);
s32 func_0025471C();
void func_0026D844();
void func_0026D980();
void func_0026D9D0();
void func_00272908(void *a, O3Vec3 *b, O3Vec3 *c, s32 d);
void func_00273860(void *a, f32 b);
void func_004171B8(s32 a);
void func_0041C864(O3Act *a) {
    O3Vec3 sp10;
    O3Vec3 sp20;
    s32 save;
    O3Body *b = (O3Body *)((u8 *)a + 0x190);
    u8 *base = D_801450C8;
    if (a->f478 != 0) {
        save = D_800D15D0;
        D_800D15D0 = 0;
        O3_PUSH(0xDA380007, (u32)(base + (D_800D297C << 6) + 0x380));
        sp10 = a->v48C;
        func_00272908(base + 0x160, &sp10, &sp20, 0xDA380007);
        if (func_0025471C() == 0) {
            func_0025470C(1);
        }
        func_004171B8(0x33335);
        O3_PUSH(0xE7000000, 0);
        O3_PUSH(0xE3000A01, 0x100000);
        O3_PUSH(0xE3000C00, 0x80000);
        O3_PUSH(0xE3001201, 0x2000);
        func_0026D844();
        a->pos198 = sp20;
        a->pos354 = sp20;
        func_0024B8B4(b);
        a->pos198 = sp20;
        a->pos354 = sp20;
        if (a->f49C != 0 || b->f10E == 0) {
            func_00246E34(b);
            if (a->f4A0 != 0) {
                func_00273860(a->mtx204, (f32)a->f4A0 * 0.017453294f);
            }
        }
        b->f6C = a->f498 * 0.017453294f;
        b->pos = sp20;
        b->p1C4 = sp20;
        func_0026D980();
        func_00249E18(b, base);
        b->c140 = D_800E3570;
        b->c158 = D_800E3570;
        func_0026D9D0();
        D_800D15D0 = save;
    }
}
