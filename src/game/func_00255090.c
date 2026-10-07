#include "b12_types.h"

extern s32 D_800D2B1C;
void func_00255220(B12Port *p);

void func_00255090(B12Port *p, s32 id) {
    osCreateMesgQueue(&p->q, (OSMesg *)((u8 *)p + 0x248), 0x80);
    memset((u8 *)p + 0x448, id, 0x1000);
    osCreateThread(&p->thread, id, (void (*)(void *))func_00255220, p, (u8 *)p + 0x1448, D_800D2B1C);
    osStartThread(&p->thread);
}
