#include "o03_types.h"
/* PARTIAL: ROM has two stray words before the prologue: `addiu sp,sp,0x18 ; addiu sp,sp,-0x18` (rom 0x190258); the body below matches from 0x422260 (rom 0x190260). */
typedef struct { u8 pad[0x1C]; s32 f1C; s32 f20; } O3Q24;
extern O3Q24 *D_800E44A0;
void *func_00252FFC(s32 size);
void func_0043C3F0();
s32 func_00422258(void) {
    O3Q24 *p = func_00252FFC(0x24);
    D_800E44A0 = p;
    p->f1C = 0;
    p->f20 = 0;
    func_0043C3F0(p, 0x67, 0, 0, 0);
    return 0;
}
