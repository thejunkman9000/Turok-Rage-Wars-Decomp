/* func_00449E38 (ROM 0x1B7E38, 209 insns = splat func_00449E38 (178) + the tail func_0044A100 (31 words, asm/1B8100.s); @SN): player (re)start: runs func_0022BAC0/func_0022BB70(/func_00426270) when the game state byte is set, resets the sub-record at +0x878 (float pool 437.5 -675.0 0.25 0.1875 pi/2), initialises the widget records at +0xE2C.. (func_002AB6C0/func_002AB6FC), copies the 16-byte record of the HUD, then sets p->0x5EC from D_8013B2BC under the flag computed from func_00245774/D_8013B290.  Pool ro=0xC7FF0:24 (6 literals). Not a pfs function. */
#include "s1011_types.h"

extern S11Game D_801462C8[];
extern u16 D_800E28D6[];
extern s32 D_8013B2BC;
extern s32 D_8013B290;
extern u8 D_800CE4BC[];
extern u8 D_800CE52C[];
extern u8 D_800CE59C[];
extern u8 D_800CE480[];
extern u8 D_800CE60C[];
extern u8 D_800CE630[];
extern u8 D_800CE670[];
extern u8 D_800CE69C[];
extern u8 D_800CE6D8[];

extern void func_0022BAC0();
extern void func_0022BB70(void *);
extern void func_00426270(void *);
extern void func_00264808(void *, s32);
extern void func_002AB6C0(void *, s16, s16);
extern void func_002AB6FC(void *, void *);
extern void func_0021A78C(void *);
extern s32 func_00245774();
extern void func_002458C8();
extern void func_00278E74(void *, s32, void *);
extern void func_002458B4();

void func_00449E38(S11Obj *p) {
    S11E878 *e;
    s32 flag;

    if (D_801462C8->unk1D != 0) {
        func_0022BAC0();
        func_0022BB70(p);
        if (p->rec->b91 == 0 && D_801462C8->unkD == 1) {
            func_00426270(p);
        }
    }
    e = &p->e878;
    e->unkB4 = 0;
    e->unk8 = 0;
    e->unkB8 = 0;
    e->unk4 = -1;
    p->e878.unk0 = -1;
    e->unkA8 = 0;
    e->unk9C = 0;
    e->unkA4 = 0;
    e->unkAC = 437.5f;
    e->unkB0 = -675.0f;
    e->unk90 = 0.25f;
    e->unk94 = 0.1875f;
    e->unk98 = 0.25f;
    e->unkA0 = 1.5707965f;
    p->unk11B0 = 0;
    func_00264808(p->unk698, 1);
    p->unk678 = 0;
    p->unk67C = 0;
    p->unk680 = 0;
    p->unk684 = 0;
    func_002AB6C0(&p->spr[0], 0x78, 0x60);
    func_002AB6FC(&p->spr[0], D_800CE4BC);
    func_002AB6C0(&p->spr[1], 0xBE, 0x60);
    func_002AB6FC(&p->spr[1], D_800CE52C);
    func_002AB6C0(&p->spr[2], 0x104, 0x60);
    func_002AB6FC(&p->spr[2], D_800CE59C);
    func_002AB6C0(&p->spr[3], 0x1C, 0x60);
    func_002AB6FC(&p->spr[3], D_800CE480);
    func_002AB6C0(&p->spr[4], -0x40, 0x10);
    func_002AB6FC(&p->spr[4], D_800CE60C);
    func_002AB6C0(&p->spr[5], 0x28, 0x10);
    func_002AB6FC(&p->spr[5], D_800CE630);
    func_002AB6C0(&p->spr[9], -0x52, 0x10);
    func_002AB6FC(&p->spr[9], D_800CE670);
    p->spr[9].f34 = 255.0f;
    func_002AB6C0(&p->spr[10], -0x52, 0x44);
    func_002AB6FC(&p->spr[10], D_800CE69C);
    func_002AB6C0(&p->spr[11], -0x52, 0x44);
    func_002AB6FC(&p->spr[11], D_800CE6D8);
    func_002AB6C0(&p->spr[7], 0x18, D_800E28D6[0] + 0x60);
    func_002AB6C0(&p->spr[8], 0x18, D_800E28D6[0] + 0x60);
    func_002AB6C0(&p->spr12, 0x64, 0x64);
    p->unk11C4 = 0;
    p->unk7BC = 0;
    p->unk1134 = p->unk5E4;
    if (p->hud != 0) {
        p->quad760 = p->hud->quad140;
    }
    func_0021A78C(p);
    flag = 0;
    if (func_00245774() == 0) {
        flag = D_8013B2BC != 0x3E7;
    }
    if (D_8013B290 != 0) {
        flag = 1;
    }
    if (flag) {
        p->unk5EC = D_8013B2BC;
    }
    p->unk1228 = 0;
    p->unk1224 = 0;
    func_002458C8();
    if (p->unk14 != 0) {
        func_00278E74(p->unk14, 1, p);
    }
    func_002458B4();
}
