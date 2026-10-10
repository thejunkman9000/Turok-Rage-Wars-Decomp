#include "b24_types.h"

typedef struct Stats24b {
    u8 pad0[0x8F];
    u8 unk8F;
    u8 unk90;
    u8 pad91;
    u8 unk92;
} Stats24b;

typedef struct Fx24b {
    s32 *unk0;
    u8 pad4[2];
    s16 unk6;
    s16 unk8;
    u8 padA[2];
    s16 unkC;
} Fx24b;

typedef struct Glob24b {
    u8 pad0[0x24];
    s32 unk24;
    u8 pad28[0x2C];
    s32 unk54;
    u8 pad58[0x1C];
    s32 unk74;
    u8 pad78[8];
    s32 unk80;
    s32 unk84;
} Glob24b;

typedef struct Plr24d Plr24d;
struct Plr24d {
    u8 pad0[0x18];
    /* 0x18 */ struct Fx24b * unk18;
    u8 pad1C[0x5B8];
    /* 0x5D4 */ s32 unk5D4;
    /* 0x5D8 */ Stats24b * unk5D8;
    /* 0x5DC */ s32 unk5DC;
    u8 pad5E0[0x4];
    /* 0x5E4 */ s32 unk5E4;
    u8 pad5E8[0xC];
    /* 0x5F4 */ u16 unk5F4;
    /* 0x5F6 */ u16 unk5F6;
    /* 0x5F8 */ u16 unk5F8;
    u8 pad5FA[0xBE2];
    /* 0x11DC */ f32 unk11DC;
    u8 pad11E0[0x4];
    /* 0x11E4 */ f32 unk11E4;
    u8 pad11E8[0x44];
    /* 0x122C */ s32 unk122C;
    /* 0x1230 */ f32 unk1230;
    u8 pad1234[0x4];
    /* 0x1238 */ s32 unk1238;
    /* 0x123C */ u8 unk123C;
    /* 0x123D */ u8 unk123D;
    /* 0x123E */ u8 unk123E;
    u8 pad123F[0x1];
    /* 0x1240 */ f32 unk1240;
    /* 0x1244 */ f32 unk1244;
    u8 pad1248[0x198];
    /* 0x13E0 */ s32 unk13E0;
    u8 pad13E4[0x2FC];
    /* 0x16E0 */ Plr24d * unk16E0;
    u8 pad16E4[0x4];
};


extern u8 D_80102B00[];
extern u8 D_80102B14[];
extern u8 D_80102B15[];
extern u8 D_80102B16[];
extern u8 D_80102B17[];
extern s32 D_80102B10[];
extern u8 D_80145088[];
extern Plr24d *D_80145044;
extern s32 D_80145048;
extern Glob24b D_801468A0[];
extern s32 D_800CE408;
extern s32 D_800D70D8;
extern s32 D_800D71E4;
extern s32 D_800D7154;
extern s32 D_800D7158;
extern s32 D_800D715C;
extern s32 D_800D7160;
extern s32 D_800D7164;
extern s32 D_800D7168;
extern s32 D_800D716C;
extern s32 D_800D7170;
extern s32 D_800D7174;
extern s32 D_800D717C;
extern s32 D_800D7180;
extern s32 D_800D7184;
extern s32 D_800D7188;
extern s32 D_800D718C;
void func_4030E0(s32);
void func_0022F3E8(u8 *, s32);
void func_00237E70(u8 *, s32, s32);
void func_0023919C(s32, s32, s32, s32, s32, s32, s32, s32);
void func_0025DE74(s32, s32, s32, s32, s32, s32);
void func_0025E13C(s32);
s32 func_0025E2E4();
void func_0025E2F4(s32);
s32 func_002A11E8(void);

#define SND(x) if (o->unk5DC != 0) { func_00237E70(D_80145088, o->unk5DC, x); }

s32 func_002ACBCC(Plr24d *o, Fx24b *f) {
    s32 ok = 0;
    s32 i;
    s32 keep;
    s32 *p;
    s32 b, c;
    Plr24d *q;
    f32 k;
    f32 u;
    u8 t;
    s32 *g;
    Plr24d **pl;
    Glob24b *gf;
    if (o->unk5E4 > 0) {
        switch ((s16)(*(u16 *)((u8 *)f + 4))) {
        case 0xBD6:
            t = o->unk5D8->unk8F;
            if (t == 1 && D_801468A0->unk54 != 0) {
                o->unk5D8->unk8F = 0;
                o->unk5D8->unk90 = t;
                D_801468A0->unk74 = 2;
                D_800CE408 = func_0025E2E4();
                if (func_0025E2E4() != 0) {
                    func_0025E2F4(0x3D);
                }
                ok = 1;
            }
            break;
        case 0xBD7:
            D_801468A0->unk84 = 0;
            D_801468A0->unk80 = 1;
            o->unk5D8->unk8F = 1;
            q = *(Plr24d **)((u8 *)D_801468A0 - 0x1840);
            ok = 1;
            if (q != NULL) {
                do {
                    if (q != o && q->unk5DC != 0) {
                        func_00237E70(D_80145088, q->unk5DC, D_800D70D8);
                    }
                    q = q->unk16E0;
                } while (q != NULL);
            }
            break;
        case 0xBD8:
            do { u = o->unk11E4; } while (0);
            o->unk1240 = 0.0f;
            k = o->unk1240;
            ok = 1;
            o->unk123C = 0;
            o->unk123D = 0;
            o->unk123E = 0;
            if (u != k) {
                o->unk11E4 = k;
                o->unk13E0 = 0;
                SND(D_800D71E4)
            } else {
                keep = o->unk122C & 0x6000;
                o->unk122C = 1 << (func_002A11E8() % 13);
                if (o->unk122C & 0x20) {
                    o->unk1238 = -1;
                    o->unk1230 = k;
                } else {
                    o->unk1230 = 105.0f;
                }
                switch (o->unk122C) {
                case 1:
                    func_0025E13C(0x15E);
                    g = &D_80145048;
                    if (*g > 0) {
                        i = 0;
                        pl = (Plr24d **)(g - 1);
                        gf = (Glob24b *)((u8 *)g + 0x1858);
                        k = 195.0f;
                        do {
                            q = (Plr24d *)((u8 *)*pl + i * 0x16E8);
                            if (q != NULL && q != o && (gf->unk24 == 0 || q->unk5D8->unk92 != o->unk5D8->unk92)) {
                                q->unk122C |= 0x2000;
                                q->unk11DC += k;
                            }
                            if (q->unk5DC != 0) {
                                func_00237E70(D_80145088, q->unk5DC, D_800D7154);
                            }
                            i++;
                        } while (i < D_80145048);
                    }
                    break;
                case 2:
                    o->unk1230 = 300.0f;
                    func_0025E13C(0x164);
                    SND(D_800D7158)
                    o->unk123C = 0xFF;
                    o->unk1240 = 255.0f;
                    o->unk1244 = o->unk1240 / o->unk1230;
                    break;
                case 4:
                    o->unk1230 = 225.0f;
                    func_0025E13C(0x15F);
                    SND(D_800D715C)
                    break;
                case 8:
                    o->unk1230 = 150.0f;
                    func_0025E13C(0x165);
                    SND(D_800D7160)
                    o->unk123C = 0xFF;
                    o->unk123D = 0xFF;
                    o->unk1240 = 255.0f;
                    o->unk1244 = o->unk1240 / o->unk1230;
                    break;
                case 0x10:
                    o->unk1230 = 150.0f;
                    func_0025E13C(0x160);
                    SND(D_800D7164)
                    o->unk123C = 0xFF;
                    o->unk123E = 0xFF;
                    o->unk1240 = 255.0f;
                    o->unk1244 = o->unk1240 / o->unk1230;
                    break;
                case 0x20:
                    o->unk1230 = 180.0f;
                    func_0025E13C(0x166);
                    SND(D_800D7168)
                    break;
                case 0x40:
                    o->unk1230 = 225.0f;
                    func_0025E13C(0x161);
                    SND(D_800D716C)
                    break;
                case 0x80:
                    o->unk1230 = 225.0f;
                    func_0025E13C(0x169);
                    SND(D_800D7170)
                    break;
                case 0x100:
                    o->unk1230 = 450.0f;
                    func_0025E13C(0x162);
                    SND(D_800D7174)
                    break;
                case 0x200:
                    i = 270.0f;
                    o->unk1230 = i;
                    func_0025E13C(0x16A);
                    SND(D_800D717C)
                    o->unk1240 = 255.0f;
                    o->unk1244 = o->unk1240 / o->unk1230;
                    break;
                case 0x400:
                    o->unk1230 = 180.0f;
                    func_0025E13C(0x163);
                    SND(D_800D7180)
                    o->unk123C = 0xFF;
                    o->unk123D = 0xFF;
                    o->unk123E = 0xFF;
                    o->unk1240 = 255.0f;
                    o->unk1244 = o->unk1240 / o->unk1230;
                    break;
                case 0x800:
                    o->unk1230 = 300.0f;
                    func_0025E13C(0x168);
                    SND(D_800D7184)
                    o->unk123E = 0xFF;
                    o->unk1240 = 255.0f;
                    o->unk1244 = o->unk1240 / o->unk1230;
                    break;
                case 0x1000:
                    o->unk1230 = 300.0f;
                    func_0025E13C(0x15F);
                    SND(D_800D7188)
                    o->unk123D = 0xFF;
                    o->unk1240 = 255.0f;
                    o->unk1244 = o->unk1240 / o->unk1230;
                    break;
                default:
                    SND(D_800D718C)
                    break;
                }
                o->unk122C |= keep;
            }
            break;
        case 0x1398:
            ok = 1;
            D_80102B14[o->unk5D4 * 0x190] += 0xA;
            o->unk5F8 += 0xA;
            func_4030E0(0x1F5);
            break;
        case 0x13A0:
            ok = 1;
            D_80102B15[o->unk5D4 * 0x190] += 0x32;
            o->unk5F4 += 0x32;
            func_4030E0(0x1F7);
            break;
        case 0x139F:
            ok = 1;
            D_80102B16[o->unk5D4 * 0x190] += 0x32;
            o->unk5F6 += 0x32;
            func_4030E0(0x1F6);
            break;
        case 0x13C1:
            ok = 1;
            D_80102B10[o->unk5D4 * 100] += 0x500;
            o->unk5E4 += 0x500;
            func_4030E0(0x1F8);
            break;
        case 0x1389:
            func_0022F3E8(D_80102B00 + o->unk5D4 * 0x190, o->unk18->unkC);
        case 0x138A:
            ok = 1;
            func_0022F3E8(D_80102B00 + o->unk5D4 * 0x190, o->unk18->unkC);
            func_4030E0(0x1F4);
            break;
        case 0x13BD:
            ok = 1;
            D_80102B17[o->unk5D4 * 0x190] += 1;
            break;
        case 0x1388:
        case 0x138B: case 0x138C: case 0x138D: case 0x138E: case 0x138F: case 0x1390:
        case 0x1391: case 0x1392: case 0x1393: case 0x1394: case 0x1395: case 0x1396:
        case 0x1397:
        case 0x1399: case 0x139A: case 0x139B: case 0x139C: case 0x139D: case 0x139E:
        case 0x13A1: case 0x13A2: case 0x13A3: case 0x13A4: case 0x13A5: case 0x13A6: case 0x13A7:
        case 0x13A9: case 0x13AA: case 0x13AD: case 0x13BC:
            ok = 1;
            break;
        default:
            break;
        }
    }
    if (ok != 0) {
        p = f->unk0;
        b = f->unk6;
        c = f->unk8;
        if (o->unk5DC != 0) {
            func_0023919C(o->unk5DC, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
            if (p != NULL) {
                func_00237E70(D_80145088, o->unk5DC, *p);
            }
        }
        if (b != 0) {
            func_0025DE74(b, *(s32 *)((u8 *)o + 8), *(s32 *)((u8 *)o + 0xC), *(s32 *)((u8 *)o + 0x10), 0, -1);
        }
        if (c != 0) {
            func_0025E13C(c);
        }
    }
    return ok;
}
