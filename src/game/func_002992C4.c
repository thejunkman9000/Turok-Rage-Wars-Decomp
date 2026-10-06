#include "p4_types.h"
extern P4SlotTbl *D_8014D080;


void func_002992C4(s32 id, s32 a, s32 b, s32 c) {
    s32 idx = -1;
s32 i;
for (i = 0; i < 64; i++) {
    if (D_8014D080->ent[i].id == id) { idx = i; break; }
    if (D_8014D080->ent[i].id == -1 && idx == -1) idx = i;
}
if (a != 0) {
    D_8014D080->ent[idx].id = id;
    D_8014D080->ent[idx].f4 = a;
    D_8014D080->ent[idx].fC = b;
    D_8014D080->ent[idx].f8 = 0;
    D_8014D080->ent[idx].f10 = c;
} else {
    D_8014D080->ent[idx].id = -1;
    D_8014D080->ent[idx].f4 = 0;
    D_8014D080->ent[idx].fC = 0;
    D_8014D080->ent[idx].f8 = 0;
}
}
