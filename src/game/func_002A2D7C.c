#include "b23_types.h"

void func_002A2B24(AnimObj *o, s32 n);

void func_002A2D7C(AnimObj *o) {
    if (o->unk54 == 0) {
        if (o->unk58 < o->unk4C) {
            func_002A2B24(o, o->unk58 + 1);
        }
    } else {
        if (o->unk58 == o->unk4C) {
            o->unk58 = o->unk50;
        } else {
            o->unk58 = o->unk58 + 1;
        }
        func_002A2B24(o, o->unk58);
    }
}
