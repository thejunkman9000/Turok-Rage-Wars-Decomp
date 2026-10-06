#include "p2_types.h"

extern f32 D_800C7EE8[];
extern f32 D_800C7EF0;
void func_002748E0(f32 *cur, f32 target, f32 rate);

void func_0022DD84(Player *p) {
    f32 target = 0.0f;
    f32 cur;
    f32 d;

    if ((u16)(p->state - 9) < 4) {
        target = D_800C7EE8[0];
    }
    cur = p->f720;
    func_002748E0(&cur, target, 0.25f);
    d = cur - p->f720;
    if (d < 0) {
        if (-d < D_800C7EE8[1]) {
            goto zero;
        }
    } else if (d < D_800C7EF0) {
zero:
        d = 0;
    }
    p->f720 += d;
}