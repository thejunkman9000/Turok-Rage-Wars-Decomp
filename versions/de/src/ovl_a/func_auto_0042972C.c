#include "o04_types.h"
typedef struct {
    u8 pad0[0x24]; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; u8 pad38[4]; s32 unk3C;
} O04S4EF0c;
extern O04S4EF0c *D_800E4EF0;
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_002A2B24(s32 a, s32 b);
s32 func_auto_0042972C(s32 a, s32 b, u32 c, s32 d) {
    if ((c >> 16) == 3 && d == 2) {
        func_0029A73C();
        switch (func_0029AA08()) {
        case 0x35F:
            func_002A2B24(D_800E4EF0->unk24, 0);
            break;
        case 0x35D:
            func_002A2B24(D_800E4EF0->unk28, 0);
            break;
        case 0x35B:
            func_002A2B24(D_800E4EF0->unk2C, 0);
            break;
        case 0x361:
            func_002A2B24(D_800E4EF0->unk30, 0);
            break;
        case 0x368:
            func_002A2B24(D_800E4EF0->unk34, D_800E4EF0->unk3C);
            break;
        }
    }
    return 0;
}
