#include "o03_types.h"
void func_00419D04(O3A *o, s32 n);
s32 func_00274544(void);
void func_0025DF54(s32 snd);
s32 func_00419B8C(O3A *o) {
    s32 t;
    if (o->state == 1) {
        if (o->flag == 0) {
            t = o->timer - 1;
            o->timer = t < 0 ? 0 : (t < 51 ? t : 50);
            if (o->timer <= 0) {
                if (func_00274544() % 100 < 2) {
                    o->flag = 1;
                    o->gobj->alpha = (u8)o->vals[o->idx];
                    func_0025DF54(0xE75);
                }
            }
        } else {
            o->gobj->alpha = (u8)o->base;
            o->cnts[o->idx]--;
            if (o->cnts[o->idx] <= 0 || o->idx + 1 >= o->count) {
                o->idx++;
                if (o->idx < o->count) {
                    o->gobj->alpha = (u8)o->vals[o->idx];
                    func_0025DF54(0xE75);
                } else {
                    func_00419D04(o, -1);
                    o->gobj->alpha = (u8)o->base;
                    o->timer = 50;
                }
            }
        }
    }
    return 0;
}
