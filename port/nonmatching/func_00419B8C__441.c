#include "o03_types.h"
void func_00419D04(O3A *o, s32 n);
s32 func_00274544(void);
void func_0025DF54(s32 snd);
s32 func_00419B8C(O3A *o) {
    s32 t, v;
    O3A *p = o;
    if (o->state == 1) {
        if (o->flag == 0) {
            v = p->timer - 1;
            if (v >= 0) {
                if (v < 51) {
                    t = v;
                } else {
                    t = 50;
                }
            } else {
                t = 0;
            }
            p->timer = t;
            if (t <= 0) {
                if (func_00274544() % 100 < 2) {
                    p->flag = 1;
                    p->gobj->alpha = (u8)p->vals[p->idx];
                    func_0025DF54(0xE75);
                }
            }
        } else {
            o->gobj->alpha = (u8)o->base;
            o->cnts[o->idx]--;
            if (o->cnts[o->idx] <= 0 || o->idx + 1 >= o->count) {
                o->idx++;
                if (o->idx >= o->count) {
                    func_00419D04(o, -1);
                    o->gobj->alpha = (u8)o->base;
                    o->timer = 50;
                } else {
                    p->gobj->alpha = (u8)p->vals[p->idx];
                    func_0025DF54(0xE75);
                }
            }
        }
    }
    return 0;
}
