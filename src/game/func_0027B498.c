#include "common.h"

typedef struct { u8 pad0[4]; u16 type; u8 pad6[0x18 - 6]; s32 *def; u8 pad1C[0x12C - 0x1C]; u8 *tgt; } M5Obj;

extern u8 *D_801041F0;
void func_00278DE8(u8 *, s32, M5Obj *);

static inline s32 clsA(u16 t) {
    switch (t) {
    case 2:
    case 0x56:
    case 0x111:
    case 0x126:
        return 1;
    }
    return 0;
}
static inline s32 clsB(u16 t) {
    switch (t) {
    case 5:
    case 6:
    case 7:
    case 9:
    case 0x11:
    case 0x13:
    case 0x1A:
    case 0x101:
    case 0x110:
        return 1;
    }
    return 0;
}
static inline s32 clsC(u16 t) {
    switch (t) {
    case 8:
    case 0xD:
    case 0x12:
        return 1;
    }
    return 0;
}

void func_0027B498(M5Obj *o) {
    u8 *p;
    s32 k;
    if (D_801041F0 != 0) {
        if (*D_801041F0 == 1) {
            p = o->tgt;
            if (p != 0 && p[0] == D_801041F0[0] && (*(u32 *)(p + 0x100) & 0x300000)) {
                if (clsA(o->type)) func_00278DE8(D_801041F0, 8, o);
                if (clsB(o->type)) func_00278DE8(D_801041F0, 4, o);
                if (clsC(o->type)) func_00278DE8(D_801041F0, 0x10, o);
            } else {
                k = *o->def;
                if (k == 1 || k == 4) {
                    if (clsA(o->type)) func_00278DE8(D_801041F0, 0x80, o);
                    if (clsB(o->type)) func_00278DE8(D_801041F0, 0x40, o);
                    if (clsC(o->type)) func_00278DE8(D_801041F0, 0x100, o);
                }
            }
        }
    }
}
