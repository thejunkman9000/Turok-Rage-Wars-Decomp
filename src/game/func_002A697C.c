#include "b23_types.h"

typedef struct Slot697C Slot697C;
typedef struct Owner697C Owner697C;

typedef struct Cfg697C {
    u8 pad0[4];
    f32 unk4;
} Cfg697C;

typedef struct Tgt697C {
    u8 pad0[0x13B];
    u8 unk13B;
    u8 pad13C[0x9D];
    u8 unk1D9;
} Tgt697C;

struct Slot697C {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ Slot697C *next;
    /* 0x08 */ Cfg697C *cfg;
    /* 0x0C */ u8 padC[0x10];
    /* 0x1C */ Tgt697C *target;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u8 pad28[0x14];
    /* 0x3C */ u32 flags;
};

struct Owner697C {
    u8 pad0[0x7528];
    Slot697C *slots;
};

void func_002A697C(Owner697C *o, Tgt697C *t) {
    Slot697C *s;
    Tgt697C *tt;

    for (s = o->slots; s != 0; s = s->next) {
        tt = s->target;
        if (tt == t) {
            if (tt != 0) {
                if (s->flags & 1) {
                    if (tt->unk13B != 0) {
                        tt->unk13B = tt->unk13B - 1;
                    }
                }
                if (s->flags & 2) {
                    if (s->target->unk1D9 != 0) {
                        s->target->unk1D9 = s->target->unk1D9 - 1;
                    }
                }
            }
            s->target = 0;
            if (s->unk24 < s->cfg->unk4) {
                s->unk24 = s->cfg->unk4;
            }
        }
    }
}
