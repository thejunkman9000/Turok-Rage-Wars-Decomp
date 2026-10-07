#include "b11_types.h"

extern f32 D_800C8E5C;
extern f32 D_800C8E60;
extern f32 D_800C8E64;

f32 func_0024E2EC(Obj *a) {
    switch (a->def->type) {
    case 11:
        return a->def->unkEC;
    case 1:
        return a->def->unk2C;
    case 2:
        if (a->def->u18.h == 0) {
            return D_800C8E5C;
        }
        return a->def->unk1C;
    case 5:
        return a->def->u18.f;
    case 8:
        if (a->def->flags14 & 1) {
            return D_800C8E60;
        }
        return a->def->u18.f;
    default:
        return D_800C8E64;
    }
}
