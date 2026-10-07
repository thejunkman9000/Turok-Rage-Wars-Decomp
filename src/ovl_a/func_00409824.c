#include "o01_types.h"

extern char *D_800D770C;
extern char *D_800D7708;
s32 func_002A1238(char *s);
s32 func_002A137C(char *a, char *b);

s32 func_00409824(char *a, char *b) {
    if (func_002A1238(b) == 4 && func_002A1238(a) == 2 && func_002A137C(b, D_800D770C) == 0 && func_002A137C(a, D_800D7708) == 0) {
        return 1;
    }
    return 0;
}
