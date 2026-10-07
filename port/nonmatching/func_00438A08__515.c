#include "o05_types.h"

typedef struct { s32 v9C; s32 a0; s32 a4; s32 a8; void *ac; } O05E30;
typedef struct {
    u8 pad0[0x9C];
    O05E30 ent[2];
    u8 padC4[4];
    u8 obj[0x188 - 0xC8];
    s32 f188;
    u8 pad18C[0x1C0 - 0x18C];
    s32 f1C0;
} O05M30;
typedef struct { f32 f0; s32 unk4; s32 unk8; f32 fC; s32 unk10; } O06Cam;
extern O05M30 *D_800E5830;
extern s32 D_800D15E0;
extern O06Cam D_800D15E4[];
typedef struct { f32 f; s32 pad[3]; } O05F;
extern O05F D_800D15F0[];
extern f32 D_800D15FA[];
void func_004399D0(void *o);
void func_004387F4(void);

void func_00438A08(void) {
    s32 sel = D_800E5830->f188;
    f32 *pf;
    s32 one;
    s32 t;
    if (D_800E5830->ent[sel].v9C < 0) {
        return;
    }
    if (D_800E5830->f1C0 == 0) {
        return;
    }
    one = 1;

    D_800D15E0 = one;
    D_800D15F0->f = (f32)D_800E5830->ent[sel].a4;
    func_004399D0(D_800E5830->obj);
    D_800D15F0->f = 255.0f;
    t = D_800E5830->ent[sel].a0;
    D_800D15E0 = 0;
    switch (t) {
    case 0:
        D_800E5830->ent[sel].a4 += 2;
        if (D_800E5830->ent[sel].a4 >= 0x97) {
            D_800E5830->ent[sel].a4 = 0x96;
            D_800E5830->ent[sel].a0 = 2;
            if (sel <= 0 && D_800E5830->ent[sel + 1].v9C > 0) {
                D_800E5830->ent[sel].a8 = 0x96;
            } else {
                D_800E5830->ent[sel].a8 = 0x38F;
            }
        }
        break;
    case 2:
        if (D_800E5830->ent[sel].a8 != 0x38F) {
            D_800E5830->ent[sel].a8--;
            if (D_800E5830->ent[sel].a8 <= 0) {
                D_800E5830->ent[sel].a0 = one;
            }
        }
        break;
    case 1:
        D_800E5830->ent[sel].a4 -= 2;
        if (D_800E5830->ent[sel].a4 < 10) {
            D_800E5830->ent[sel].a4 = 10;
            D_800E5830->f188++;
            func_004387F4();
        }
        break;
    }
}

