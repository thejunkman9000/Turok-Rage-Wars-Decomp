#include "o03_types.h"
void func_002A3358();
s32 func_00421ECC(O3Fd *o, s32 dt) {
    if (o->done == 0) {
        if (o->dir == 0) {
            if (o->timer < 1000) {
                o->item->alpha = (u32)((f32)o->timer * 0.25500003f);
            } else {
                o->item->alpha = 0xFF;
                o->done = 1;
                func_002A3358();
            }
            o->timer = o->timer + dt;
        } else {
            if (o->timer > 0) {
                o->item->alpha = (u32)((f32)o->timer * 0.25500003f);
            } else {
                o->item->alpha = 0;
                o->done = 1;
                func_002A3358();
            }
            o->timer = o->timer - dt;
        }
    }
    return o->done;
}
