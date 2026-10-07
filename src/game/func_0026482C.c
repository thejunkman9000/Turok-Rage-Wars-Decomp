#include "b14_types.h"
typedef struct { u8 pad[0x224]; } B14Slot;
extern B14Slot D_8010F328[];
void func_00264268(B14Slot *s);
void func_0026482C(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        func_00264268(&D_8010F328[i]);
    }
}
