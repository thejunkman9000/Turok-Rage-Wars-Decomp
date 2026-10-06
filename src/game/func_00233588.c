#include "p2_types.h"

s32 func_002301E4(PlayerCtl *c);
void func_0022AFFC(Player *p);

void func_00233588(PlayerCtl *c, PlayerEvt *e) {
    Player *p = c->player;

    if (e->fCB != 0) {
        e->f13C = 2;
        if (func_002301E4(c)) {
            e->f13C = 1;
            func_0022AFFC(p);
        }
    }
}