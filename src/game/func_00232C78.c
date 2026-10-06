#include "p2_types.h"

extern WeaponInfo *D_800D052C[];
extern f32 D_800C8110;
void func_0022AF64(Player *p, s32 a);

void func_00232C78(PlayerCtl *c, PlayerEvt *e) {
    Player *p = c->player;

    e->f130 = D_800D052C[p->weapon]->f18 * D_800C8110;
    if (p->weapon == 8 && p->f11C0 == 0) {
        func_0022AF64(p, 0xA3C);
    }
}