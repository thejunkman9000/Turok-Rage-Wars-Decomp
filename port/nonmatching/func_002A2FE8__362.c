
#include "b23_types.h"
void func_002A2D14(StateObj *o);
void func_002A2D7C(StateObj *o);
s32 func_002A2FE8(StateObj *o) {
    StateObj *q = o;
    switch (o->unk5C) {
    case 0:
        o->unk48 = o->unk48 + 1;
        if (o->unk48 >= 11) {
            func_002A2D14(o);
        }
        break;
    case 1:
        q->unk48 = q->unk48 + 1;
        if (q->unk48 >= 11) {
            func_002A2D7C(q);
        }
        break;
    case 2:
        break;

    }
    return 0;
}

