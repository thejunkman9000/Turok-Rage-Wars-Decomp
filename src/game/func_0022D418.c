#include "p2_types.h"

extern f32 D_800C7EA8;
void func_002748E0(f32 *cur, f32 target, f32 rate);
void func_44A4C0(Player *p);

void func_0022D418(Player *p) {
    if (p->f850 == 0) {
        if (!(p->f664 & 0x8000)) {
            func_002748E0(&p->f72C, 1.308997f, 0.25f);
        }
        if (p->f658 > D_800C7EA8) {
            func_44A4C0(p);
        }
    }
}