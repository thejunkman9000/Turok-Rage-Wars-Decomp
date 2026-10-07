#include "o04_types.h"
extern u8 D_801462C8[];
void func_0042872C(s32 a, s32 b, s32 c);
void func_004283F4(void) {
    s32 i;
    s32 n;
    s32 k;
    s32 cnt;
    s32 row;
    u8 *c = D_801462C8;
    n = 0;
    for (i = 0; i < 4; i++) {
        if (c[i * 0x96 + 0x148] == 1) {
            cnt = 0;
            for (k = 0; k < 0x16; k++) {
                row = i * 0x96;
                if (c[0x11C + row + k] == 1 && k != 0) {
                    func_0042872C(cnt, k, n);
                    cnt++;
                }
            }
            n++;
            if (n >= 2) {
                break;
            }
        }
    }
}
