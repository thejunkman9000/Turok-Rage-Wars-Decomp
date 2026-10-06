#include "p4_types.h"
typedef struct { s32 pad0; s32 pad4; u16 tbl[1]; } P4Tbl94;
typedef struct { u8 pad[0x94]; P4Tbl94 *t; } P4Obj94;
u16 func_0028B238(P4Obj94 *o, s32 i) {
    return o->t->tbl[i];
}
