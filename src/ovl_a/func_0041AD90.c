#include "o03_types.h"
typedef struct { u8 pad[0x110]; s32 sel; } O3Sel;
void func_0041AD90(O3List *o, s32 i) {
    O3ListG *g = o->g;
    *(s32 *)((u8 *)o + 0x110) = i;
    g->sel = &o->ent[i];
}
