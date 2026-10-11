#include "s1005_types.h"

extern s32 D_80145048;
extern S5Glob D_801462C8[];

extern void func_0022A738(void *);
extern void func_0021B1E4(S5Player *p, s32 model, s32 scale, s32 flag);
extern void func_0044A17C(S5Player *p);
extern void func_002227D0(S5Player *p, S5Player *q, s32 id);

void func_0044A4C0(S5Player *p) {
    s32 scale;

    scale = (D_80145048 >= 2) * 2;
    if (!(D_801462C8->flags & 2) || D_801462C8->f1D != 0) {
        if ((D_801462C8->mode == 1 || D_801462C8->mode == 4) && p->computer == 0) {
            if (p->respawn > 0) {
                p->respawn--;
            }
            if (p->respawn == 0) {
                D_801462C8->f680 = 0;
                func_0022A738((u8 *)D_801462C8 - 0x1288);
            }
        }
    }
    switch (D_801462C8->mode) {
    case 1:
    case 4:
        if (p->computer == 0) {
            if (p->respawn <= 0) {
                if (D_801462C8->f1D != 0 && p->s10E == 0 && p->stats->u8F == 0) {
                    return;
                }
                func_002227D0(p, p, 0x12);
            } else {
                func_0021B1E4(p, p->model, scale, 1);
                func_0044A17C(p);
            }
            p->f1340 = 0;
            return;
        }
        break;
    }
    func_002227D0(p, p, 0x12);
    p->f1340 = 0;
}
