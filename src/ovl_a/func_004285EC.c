#include "o04_types.h"
extern O04ModeS4690 *D_800E4690;
extern u8 D_801462C8[];
void func_004288E0(void);
void func_0042872C(s32 a, s32 b, s32 c);
void func_004285EC(void) {
    s32 i;
    s32 n;
    s32 row;
    u8 *c;
    func_004288E0();
    i = n = 0;
    row = D_800E4690->unkA5C * 0x96;
    c = D_801462C8;
    for (; i < 0x16; i++) {
        if (c[0x11C + row + i] == 1 && i != 0) {
            func_0042872C(n, i, 0);
            n++;
        }
    }
}
