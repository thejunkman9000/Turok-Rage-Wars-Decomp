#include "o05_types.h"
typedef struct { u8 pad0[0x9C]; s32 f9C; u8 pad1[0x10]; s32 fB0; u8 pad2[0xD4]; s32 f188; } S;
extern S *D_800E5830;
void func_00438C68(void) {
    S *p = D_800E5830;
    p->f9C = -1;
    p->fB0 = -1;
    p->f188 = 0;
}
