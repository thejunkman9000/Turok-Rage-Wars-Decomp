#include "b14_types.h"
typedef struct { u8 pad[0x224]; } B14Slot;
extern u8 D_800D0E50;
extern B14Slot D_8010F328[];
extern u8 D_8010F0E0[];
void func_002644C8(void *p);
void func_0029B650(void *p);
s32 func_002A339C();
s32 func_002A33AC();


void func_00264424(void) {
s32 i;
    s32 r;
    if (D_800D0E50 != 0) {
        for (i = 0; i < 4; i++) {
            func_002644C8(&D_8010F328[i]);
            r = func_002A33AC();
            if (r == 1 && func_002A339C() == r) {
                func_0029B650(&D_8010F328[i]);
            }
        }
        func_002644C8(D_8010F0E0);
    }
}
