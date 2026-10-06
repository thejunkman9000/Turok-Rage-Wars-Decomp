#include "b23_types.h"

typedef struct Slot697C Slot697C;
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

typedef struct Owner6DF8 {
    u8 pad0[0x751C];
    u8 freeList[0xC];
    u8 pad7528[0];
} Owner6DF8;

s32 func_002A3F94(void *o, Slot697C *s);
void func_00279764(void *list, Slot697C *s);

void func_002A6DF8(u8 *o) {
    Slot697C *s, *next;
    Tgt697C *t;

    s = *(Slot697C **)(o + 0x7528);
    if (s != 0) {
        do {
            next = s->next;
            if (func_002A3F94(o, s) == 0) {
                t = s->target;
                if (t != 0) {
                    if (s->flags & 1) {
                        if (t->unk13B != 0) {
                            t->unk13B = t->unk13B - 1;
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
                func_00279764(o + 0x751C, s);
            }
            s = next;
        } while (s != 0);
    }
}
