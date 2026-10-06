#include "b04_types.h"
extern s32 D_8013B290;
typedef struct { u8 pad0[4]; s32 unk4; u8 pad8[0x60]; B04Act *unk68; u8 pad6C[0x28]; s8 unk94; } B04Cfg;
s32 func_002169AC(B04Act *self, B04Cfg *c, B04Act *t) {
    if (c->unk4 == 0)
        return 6;
    if (t == NULL) {
        if (c->unk94)
            return 4;
        return 3;
    }
    if (t == c->unk68)
        return 2;
    if (t->def->type == 5)
        return 5;
    if (t->unkE4 == 0x64F)
        return 7;
    if (D_8013B290 == 0) {
        if (t->flags & 0x300000) {
            B04Act *o = t->owner;
            if (o->unk794 == self && o->unk788 == 2)
                return 1;
        }
        if (self->unk2E0 & 2) {
            if (self->unkE4 != 0xCA)
                return 1;
        }
    }
    return 0;
}
