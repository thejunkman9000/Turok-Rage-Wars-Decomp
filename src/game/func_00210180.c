#include "common/unused.h"
#include "types.h"

/* Route-following check for a computer driver's brain: when it has a target at 0x64, it calls func_8020DC10_de if func_802099B4_de reports the target reached, and again when its route node at 0xC (unless -1) lies closer than 100 to the position func_8020993C_de gives; always returns one. */

extern char D_8013B364[];

extern s32 func_802099B4_de(RouteArrivalBrain *, void *);
extern void func_8020DC10_de(RouteArrivalBrain *);
extern void *func_8020993C_de(RouteArrivalBrain *);
extern void *func_8020C994_de(char *, s32);
extern f32 func_802726F8_de(void *, void *);

s32 func_80210198_eu(RouteArrivalBrain *brain) {
    void *pos;

    if (brain->target == 0) {
        return 1;
    }
    if (func_802099B4_de(brain, brain->target) != 0) {
        func_8020DC10_de(brain);
    }
    if (brain->node == -1) {
        return 1;
    }
    pos = func_8020993C_de(brain);
    if (func_802726F8_de(pos, func_8020C994_de(D_8013B364, brain->node)) < 100.0f) {
        func_8020DC10_de(brain);
    }
    return 1;
}
