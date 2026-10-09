/* port (passthru_fix.py): func_002301E4 needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "p2_types.h"

s32 func_002301E4(PlayerCtl *c, u32);
void func_0022AFFC(Player *p);

void func_00233588(PlayerCtl *c, PlayerEvt *e) {
    Player *p = c->player;

    if (e->fCB != 0) {
        e->f13C = 2;
        if (func_002301E4(c, e)) {
            e->f13C = 1;
            func_0022AFFC(p);
        }
    }
}