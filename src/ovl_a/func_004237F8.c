#include "o04_types.h"

typedef struct { u8 pad0[0xC]; s32 unkC; } O04_S4514;
extern O04_S4514 *D_800E4514;
void func_002A3358(void);

s32 func_004237F8(void) {
    if (D_800E4514->unkC == 0) {
        D_800E4514->unkC = 1;
        func_002A3358();
    }
    return 0;
}
