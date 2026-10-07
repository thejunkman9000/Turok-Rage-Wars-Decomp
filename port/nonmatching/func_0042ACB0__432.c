#include "o04_types.h"
typedef struct { u8 pad0[2]; u16 unk2; union { s32 w; struct { u16 h0; u16 h1; } h; } u4; u8 pad8[8]; } O04Ent16;
extern O04ModeF60 *D_800E4F60;
extern O04Ent16 D_800E4F64[];
s32 func_0042B398(s32 a, s32 b);
void *func_0040ECB0(void *a, s32 b);
void func_0040E958(void *p, s32 a);
void func_0042EB80(s32 a, s32 b);
void func_0042EB68(s32 a);
void func_0042B530(void);
void func_0042B1A0(s32 a);
void func_0042B1B0(s32 a);
s32 func_0042AEB8(void);
static inline s32 o04_map(s32 k) {
    switch (k) {
    case 3:
        return 0;
    case 2:
        return 1;
    case 1:
        return 3;
    case 0:
        return 2;
    }
    return 0;
}
void func_0042ACB0(void) {
    s32 s2;
    s32 t;
    s32 s3;
    s32 s1;
    s2 = 0;
    switch (D_800E4F60->unk434) {
    case 0:
        s2 = 2;
        break;
    case 1:
        s2 = 3;
        break;
    case 2:
        s2 = 1;
        break;
    case 3:
        s2 = 0;
        break;
    }
    s3 = func_0042B398(s2, D_800E4F60->unk438);
    for (s1 = 0; s1 < 0x28; s1++) {
        func_0040E958(func_0040ECB0(D_800E4F60->unk0, D_800E4F64[s1].unk2), 0);
        if (D_800E4F64[s1].u4.w != -1) {
            func_0040E958(func_0040ECB0(D_800E4F60->unk0, D_800E4F64[s1].u4.h.h1), 0);
        }
    }
    func_0042EB80(s2, s3);
    func_0042EB68(0x15);
    func_0040E958(D_800E4F60->unk440, 0);
    func_0040E958(D_800E4F60->unk448, 0);
    func_0040E958(D_800E4F60->unk444, 0);
    func_0040E958(D_800E4F60->unk3EC, 0);
    func_0040E958(D_800E4F60->unk3F0, 0);
    func_0042B530();
    if (D_800E4F60->unk438 == 0) {
        func_0042B1A0(s2);
        func_0042B1B0(0);
        func_0042AEB8();
    } else {
        func_0042B1A0(-1);
        func_0042B1B0(D_800E4F60->unk438);
    }
}
