#include "types.h"
#include "math_helpers.h"
/* 4-way version of the menu stick decoder (sibling of func_00217B3C, 8-way): -1 inside the dead zone
   (radius 60) or in the diagonal band (||x|-|y|| < 46 with both axes non-zero), else 1/3 for right/left when
   the horizontal axis dominates and 0/2 for up/down.  Stick bytes at 0xC6/0xC7 of the controller at 0x698. */
typedef struct { char pad0[0xC6]; u8 x; u8 y; } B988Ctl;
typedef struct { char pad0[0x698]; B988Ctl *controller; } B988Plr;
s32 func_00218988(B988Plr *player) {
    B988Ctl *controller;
    s8 x;
    s8 y;
    controller = player->controller;
    x = controller->x;
    y = controller->y;
    if (x * x + y * y < 3600) {
        return -1;
    }
    if (RW_ABS(RW_ABS(x) - RW_ABS(y)) < 46 && x != 0 && y != 0) {
        goto out;
    }
    if (RW_ABS(x) > RW_ABS(y)) {
        return x <= 0 ? 3 : 1;
    }
    return y > 0 ? 0 : 2;
out:
    return -1;
}
