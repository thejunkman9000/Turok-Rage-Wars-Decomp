/* func_00449970 (ROM 0x1B7970, 117 insns, @SN): player/actor object constructor: two base entities (the object itself and the one at +0x2E8) through func_0024B398, callbacks at 0x27C..0x290 / 0x568..0x574, flag words 0x100 / 0x3E8, then copies three floats of the record at +0x18.  Pool: one 0.5f literal (ro=0xC7FE4:4). Not a pfs function. */
#include "s1011_types.h"

extern u8 D_801462E5[];
extern void func_00219A40();
extern void func_0021A2D4();
extern void func_0022E0A0();
extern void func_0022E250();
extern void func_0022F5D0();
extern void func_0024B52C();
extern void func_0024B398(void *, void *, s32, s32);
extern void func_00214178(void *, void *, s32);
extern void func_002325EC(void *, void *);
extern void func_00220A5C(void *, void *);
extern void func_00245854(void *);

void func_auto_00449F80(S11Obj *p, void *a1, s32 a2) {
    p->self = p;
    func_0024B398(p, a1, a2, 0);
    p->self = p;
    p->flags |= 0x100000;
    p->flags |= 0x10000;
    p->flags |= 0x1000000;
    p->flags |= 0x2000000;
    if (D_801462E5[0] == 0) {
        p->flags |= 0x10000000;
    }
    p->unk28C = func_0024B52C;
    p->unk290 = func_0022E0A0;
    p->unk280 = func_00219A40;
    p->unk288 = func_0022E250;
    if (D_801462E5[0] != 0) {
        p->unk27C = func_0021A2D4;
    }
    p->self4C0 = p;
    func_0024B398(&p->ent2E8, a1, a2, 0);
    p->unk574 = func_0022F5D0;
    p->unk48C = -1;
    p->self4C0 = p;
    p->unk568 = func_00219A40;
    p->unk570 = func_0022E250;
    p->flags3E8 |= 0x200000;
    p->unk62E = -1;
    p->unk338 = 0.5f;
    p->unk33C = 0.5f;
    p->unk340 = 0.5f;
    p->flags3E8 &= 0xFFFEFFFF;
    func_00214178(&p->ent2E8, &p->ent458, 0);
    func_002325EC(&p->ent2E8, &p->ent458);
    func_00220A5C(p, p);
    if (p->hud != 0) {
        func_00245854(p->hud);
    }
    p->unk50 = p->cfg->unkFC;
    p->unk54 = p->cfg->unk100;
    p->unk58 = p->cfg->unk104;
    p->cfg->flags &= ~4;
}
