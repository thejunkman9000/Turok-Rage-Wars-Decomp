#include "o06_types.h"
typedef struct { u8 pad[8]; u32 unk8; u8 pad2[8]; s32 unk14; } O06A;
typedef struct { u8 pad[4]; s32 unk4; s32 unk8; f32 unkC; f32 unk10; s32 unk14; u8 pad2[4]; s32 unk1C; } O06B;
typedef struct { u8 pad[0x30]; f32 unk30; f32 unk34; u8 pad2[4]; s32 unk3C; } O06D;
extern s32 func_002934DC(O06A *a);
extern s32 func_00265370();
extern void func_002AB9E4(void);
extern void func_002A8DD4(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void func_002AA224(s32 a);
extern void func_002ABC18(s32 a, s32 b, s16 c, s16 d, f32 e, f32 f, s32 g);
extern s32 D_800E5E70;
extern s32 D_80146894[];
extern u8 D_801462E5;
extern f32 D_800E24AC;
void func_0044044C(O06A *a, O06B *b, s32 c, O06D *d) {
    s32 alpha;
    f32 fx, fy, t1, t2;
    if ((func_002934DC(a) != 0 && (a->unk8 & 0x40000000) != 0) ||
        (D_801462E5 != 0 && (s32)a->unk8 < 0 && func_00265370() == 0x400000)) {
        d->unk3C = 1;
        if (D_800E5E70 != 3) D_800E5E70 = 3;
        func_002AB9E4();
        t1 = (f32)b->unk4 * b->unkC;
        t2 = (f32)b->unk8 * b->unk10;
        fy = (f32)b->unk1C;
        fx = (f32)b->unk14;
        fx = fx + t1;
        fy = fy + t2;
        if (D_80146894[0] != 0) {
            if (((u8 *)D_80146894)[-0x5AF] != 0) {
                if ((s32)a->unk8 < 0) alpha = 0xFF; else alpha = 0xC0;
            } else alpha = 0x80;
        } else alpha = 0x80;
        func_002A8DD4(b->unk14, b->unk1C, (s32)fx, (s32)fy, 1, 0, 0, 0, 0, alpha);
    } else {
        if (D_800E5E70 != 3) {
            D_800E5E70 = 3;
            func_002AA224((s32)(d->unk30 * (d->unk34 * D_800E24AC)));
        }
        func_002ABC18(a->unk14, 0, (s16)b->unk14, (s16)b->unk1C, b->unkC, b->unk10, 1);
    }
}
