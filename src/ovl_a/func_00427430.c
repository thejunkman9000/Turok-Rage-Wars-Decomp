#include "o04_types.h"
extern O04Ent1C D_800E4694[];
s32 func_00265670(void *m, s32 i);
void func_002656A8(void *m, s32 i, s32 v);
s32 func_00428338(s32 a, s32 b);
s32 func_00427430(void *available, s32 *sequence) {
    s32 found;
    s32 i;
    s32 count;
    s32 compatible;
    s32 *last;
    s32 neg;
    s32 one;

    i = found = 0;
    do {
        if (func_00265670(available, i) == 1) {
            if (available || i) {
                found = 1;
            } else {
                found = 1;
            }
        }
        i++;
    } while (i < 36 && found == 0);
    if (found != 0) {
        count = 0;
        while (sequence[count] != -1) {
            count++;
        }
        count--;
        i = 0;
        one = 1;
        neg = -1;
        last = (s32 *)(count * 4 + (u32)sequence);
        for (; i < 36; i++) {
            if (func_00265670(available, i) != 0) {
                compatible = func_00428338(D_800E4694[*last].id,
                                              D_800E4694[i].id);
                if (compatible == one) {
                    last++;
                    last[0] = i;
                    last[1] = neg;
                    func_002656A8(available, i, 0);
                    if (func_00427430(available, sequence) == compatible) {
                        return 1;
                    }
                    func_002656A8(available, i, 1);
                    last[0] = neg;
                    last--;
                }
            }
        }
    }
    return 1;
}




