#include "o04_types.h"
typedef struct { s32 unk0; u8 pad[0xC]; s32 unk10; } O04S5430;
extern O04S5430 *D_800E5430;
void func_0029A73C(void);
void func_0041A4B0(s32 a, s32 b);
s32 func_0042DEA4(void) {
    func_0029A73C();
    D_800E5430->unk10 = -1;
    func_0041A4B0(D_800E5430->unk0, 2);
    return 0;
}
