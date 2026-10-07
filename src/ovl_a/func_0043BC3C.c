#include "o06_types.h"
typedef struct { u8 pad[0x4B0]; s32 unk4B0; s32 unk4B4; s32 unk4B8[6]; } O06P;
typedef struct { u16 v; u16 pad; } O06Ent;
typedef struct { O06Ent ent[19]; } O06Row;
typedef struct { s32 unk0; } O06M;
typedef struct { u8 pad[0x10]; u8 unk10; } O06X;
extern O06X *func_0040ECB0();
extern void func_0040E958(void *a, s32 b);
extern void func_0040E9A8(void *a, s32 b);
extern void func_0043B67C(s32 a, s32 b, s32 c);
extern O06Row D_800E5A06[];
extern O06Row D_800E5A1A[];
extern O06P *D_800E59E0;
void func_0043BC3C(s32 a, s32 b) {
    O06X *x;
    if (b != 5) {
        x = func_0040ECB0(*(s32 *)D_800E59E0, D_800E5A06[a].ent[b].v);
        func_0040E958(x, 1);
    }
    x = func_0040ECB0(*(s32 *)D_800E59E0, D_800E5A1A[a].ent[b].v);
    func_0040E9A8(x, 1);
    {
    s32 off = a * 0x4D0;
    x->unk10 = 0x96;
    ((O06P *)((u8 *)D_800E59E0 + off))->unk4B4 = b;
    func_0043B67C(a, b, *(s32 *)((u8 *)D_800E59E0 + (b * 4 + off) + 0x4B8));
    }
}
