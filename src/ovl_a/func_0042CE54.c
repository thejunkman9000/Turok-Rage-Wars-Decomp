#include "o04_types.h"
typedef struct { u16 pad0; u16 id; } O04IdPair;
typedef struct { O04IdPair e[10]; } O04Row28;
extern O04ModeS53C0 *D_800E53C0;
extern O04Row28 D_800E5320[];
void *func_0040ECB0(s32 a, s32 b);
void func_0040E958(void *p, s32 a);
void func_0042D5F8(s32 a);
void func_0042CE54(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5320[i].e[0].id), 0);
        func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5320[i].e[1].id), 0);
        func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5320[i].e[2].id), 0);
        func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5320[i].e[3].id), 0);
        func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5320[i].e[4].id), 0);
        func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5320[i].e[5].id), 0);
        func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5320[i].e[6].id), 0);
        func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5320[i].e[7].id), 0);
        func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5320[i].e[8].id), 0);
        func_0040E958(func_0040ECB0(D_800E53C0->unkE0, D_800E5320[i].e[9].id), 0);
    }
    func_0042D5F8(0x269);
    func_0042D5F8(0x26E);
}
