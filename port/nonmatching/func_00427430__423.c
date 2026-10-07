#include "o04_types.h"
extern O04Ent1C D_800E4694[];
s32 func_00265670(void *m, s32 i);
void func_002656A8(void *m, s32 i, s32 v);
s32 func_00428338(s32 a, s32 b);
s32 func_00427430(void *m, s32 *list) {
    s32 found;
    s32 i;
    s32 n;
    s32 *p;
    s32 *q;
    s32 r;
    found = 0;
    i = 0;
    do {
        if (func_00265670(m, i) == 1) {
            found = 1;
        }
        i++;
    } while (i < 0x24 && found == 0);
    if (found) {
        n = 0;
        if (list[0] != -1) {
            q = list;
            do {
                q++;
                n++;
            } while (*q != -1);
        }
        n--;
        i = 0;
        p = &list[n];
        for (; i < 0x24; i++) {
            if (func_00265670(m, i) != 0) {
                r = func_00428338(D_800E4694[p[0]].id, D_800E4694[i].id);
                if (r == 1) {
                    p++;
                    p[0] = i;
                    p[1] = -1;
                    func_002656A8(m, i, 0);
                    if (func_00427430(m, list) == r) {
                        return 1;
                    }
                    func_002656A8(m, i, 1);
                    p[0] = -1;
                    p--;
                }
            }
        }
    }
    return 1;
}
