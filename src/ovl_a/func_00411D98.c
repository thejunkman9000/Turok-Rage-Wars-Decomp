#include "o02_types.h"
typedef struct { s16 n; u8 pad[0x32]; s32 mode; } S_func_00411D98;
extern S_func_00411D98 D_80153C20;
void func_00411598(s32 i);
void func_00411D98(void) {
    s32 i;
    if (D_80153C20.mode != 1) {
        for (i = 0; i < D_80153C20.n; i++) {
            func_00411598(i);
        }
    }
}
