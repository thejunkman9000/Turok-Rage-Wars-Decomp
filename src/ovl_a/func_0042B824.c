#include "o04_types.h"
extern O04ModeF60 *D_800E4F60;
void func_0029A73C(void);
s32 func_0042B474(s32 a);
s32 func_0042B334(s32 a);
void func_0025DF54(s32 a);
void func_0042B4C4(void);
void func_0042AB70(void);
void func_0040E958(void *p, s32 a);
s32 func_0042B824(s32 a, s32 b, s32 c, s32 d) {
    s32 s0;
    s32 a1;
    s32 v1;
    s32 lim;
    O04ModeF60 *new_var;
    O04ModeF60 *p;
    func_0029A73C();
    if (d != 1) {
        return 0;
    }
    s0 = 0;
    a1 = func_0042B334(func_0042B474(D_800E4F60->unk434));
    p = D_800E4F60;
    if (p->unk434 != 0) {
        v1 = p->unk438 + 1;
        if (v1 < a1) {
            s0 = 1;
            p->unk438 = v1;
        }
    } else {
        v1 = p->unk438;
        if (v1 >= 0xB) {
            v1 = v1 - 1;
            lim = 0xA;
        } else {
            lim = func_0042B334(func_0042B474(0));
            a1 = lim;
            p = D_800E4F60;
            v1 = p->unk438 + 1;
            if (v1 == a1) {
                goto done;
            }
            lim = 0xB;
        }
        if (v1 != lim) {
            s0 = 1;
            p->unk438 = v1;
        }
    }
done:
    if (s0 == 1) {
        func_0025DF54(0xE7D);
        func_0042B4C4();
        D_800E4F60->unk45C = 0;
        D_800E4F60->unk464 = 0;
        D_800E4F60->unk43C->unk10 = 0x41;
        func_0042AB70();
        func_0040E958((new_var = D_800E4F60)->unk440, 0);
        func_0040E958(D_800E4F60->unk444, 1);
        func_0040E958(D_800E4F60->unk448, 0);
    }
    return 0;
}
