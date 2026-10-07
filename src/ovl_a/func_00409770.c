#include "o01_types.h"

extern s32 D_800E28C8;
void func_00404E28(s32 ch);
s32 func_00404F04(s32 ch);

void func_00409770(void) {
    s32 sel;
    s32 tries;
    if (D_800E28C8 == -1) {
        sel = 0;
        tries = 0;
        do {
            func_00404E28(sel);
            if (func_00404F04(sel) != -2) {
                break;
            }
            sel++;
            if (sel >= 4) {
                sel = 0;
            }
            tries++;
        } while (tries < 4);
        if (tries == 4) {
            sel = -1;
        }
        D_800E28C8 = sel;
    }
}
