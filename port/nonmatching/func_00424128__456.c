#include "o04_types.h"
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x7F - 0x79]; u8 unk7F; u8 pad80[0x96 - 0x80]; } Q2Ent96;
typedef struct { u8 pad0[0xD]; s8 unkD; u8 padE[0x190 - 0xE]; } Q2Row190;
typedef struct { u8 pad0[0xD]; u8 f0D; u8 padE[0xD0 - 0xE]; Q2Ent96 pl[8]; } Q2Cfg;
extern O04ModeS4600 *D_800E4600;
extern Q2Cfg D_801462C8[];
extern Q2Ent96 D_80146398[];
extern Q2Row190 D_80102B00[];
extern s32 D_800E4680;
extern u8 D_801462D5;
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_0022F1F4(s32 a);
void func_0022EF20(void *p);
void func_00435190(s32 a);
void func_0022F594(void *p, s32 a);
void func_0041A4B0(s32 a, s32 b);
s32 func_00424128(void) {
    s32 i;
    Q2Ent96 *p;
    func_0029A73C();
    switch (func_0029AA08()) {
    case 0x45:
        D_800E4600->unk18 = 0x1A;
        ((u8 *)D_80146398)[-0xC3] = 0;
        break;
    case 0x49:
        D_800E4600->unk18 = 7;
        D_801462C8->f0D = 2;
        for (i = 0; i < 2; i++) {
            p = &D_801462C8->pl[i];
            p->unk78 = 1;
            p->unk7F = i;
            if (D_80102B00[i].unkD < 0) {
                func_0022F1F4(i);
            }
        }
        break;
    case 0x46:
        p = D_80146398;
        p->unk78 = 1;
        p->unk7F = 0;
        func_0022EF20(D_80102B00);
        func_00435190(7);
        D_800E4600->unk18 = 0x13;
        ((u8 *)p)[-0xC3] = 1;
        break;
    case 0x4B:
        D_800E4600->unk18 = 0x1B;
        break;
    case 0x47:
        D_800E4600->unk18 = 4;
        break;
    case 0x4C:
        D_800E4600->unk18 = 0x10;
        break;
    case 0x48:
        p = D_80146398;
        D_800E4600->unk18 = 7;
        p->unk78 = 1;
        p->unk7F = 0;
        if (D_80102B00[0].unkD < 0) {
            func_0022F1F4(0);
            for (i = 0; i < 0x14; i++) {
                func_0022F594(D_80102B00, i);
            }
        }
        D_801462D5 = 3;
        break;
    case 0x4A:
        p = D_80146398;
        D_800E4600->unk18 = 0xA;
        p->unk78 = 1;
        p->unk7F = 0;
        if (D_80102B00[0].unkD < 0) {
            func_0022F1F4(0);
        }
        ((u8 *)p)[-0xC3] = 4;
        D_800E4680 = 0;
        break;
    default:
        return 0;
    }
    func_0041A4B0(D_800E4600->unk0, 2);
    return 0;
}
