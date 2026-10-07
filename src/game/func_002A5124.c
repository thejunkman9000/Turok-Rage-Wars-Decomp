#include "b23_types.h"
typedef struct Obj5124 {
    u8 pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    u8 pad34[4];
    s32 unk38;
} Obj5124;
typedef struct Def5124 {
    u8 pad0[0x1E];
    u8 mode;
} Def5124;
s32 func_00274544(void);
s32 func_002A5124(Obj5124 *o, Def5124 *d, s32 *lenp) {
    s32 pos;
    s32 *p = &pos;
    s32 n;
    s32 two;
    *p = (s32)o->unk30;
    switch (d->mode) {
    case 0:
        if (*p >= *lenp - 1) {
            *p = *lenp - 1;
            o->unk2C = (f32)*lenp;
        }
        break;
    case 1:
        if (*p >= *lenp) {
            *p = *lenp - 1;
        }
        break;
    case 2:
        *p = *p % *lenp;
        break;
    case 3:
        {
            n = *lenp * 2 - 2;
            if (n > 0) {
                n = *p % n;
            } else {
                n = 0;
            }
            *p = n;
            two = 2;
            if (n >= *lenp) {
                *p = *lenp * two - (n + two);
            }
        }
        break;
    case 4:
        *p = func_00274544() % *lenp;
        break;
    case 5:
        if (o->unk38 == -1) {
            o->unk38 = func_00274544() % *lenp;
        }
        *p = o->unk38;
        break;
    }
    return pos;
}
