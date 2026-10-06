#include "p3_types.h"

extern s32 D_8010F310[4];
extern s32 D_8010FC28[4];
extern s32 D_8010FBF0[4];
s32 func_0026477C(s32 i);
s32 func_00264654(s32 i);

void func_00263C44(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (func_0026477C(i) != 0) {
            if (func_00264654(i) != 0) {
                D_8010F310[i] = 1;
                if (D_8010FC28[i] != 0) {
                    D_8010FBF0[i] = 1;
                    D_8010FC28[i] = 0;
                }
            } else if (D_8010F310[i] != 0) {
                D_8010FC28[i] = 1;
            }
        } else {
            D_8010FBF0[i] = 0;
            D_8010FC28[i] = 0;
            D_8010F310[i] = 0;
        }
    }
}
