#include "o01_types.h"

void func_00404E28(s32 ch);
s32 func_00404F04(s32 ch);

s32 func_0040A1DC(s32 cur) {
    s32 sel = 0;
    s32 tries;
    if (cur != -1) {
        sel = cur + 1;
        if (sel >= 4) {
            sel = 0;
        }
    }
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
    return sel;
}
