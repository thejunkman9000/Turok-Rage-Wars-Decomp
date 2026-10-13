#include "m02_gen.h"
extern M2Row18 D_800CE8DC[];
extern M2G D_801468A0[];
s32 func_00222A80(M2Own *o, s32 w);
void func_0022B9B4(M2Own *o);
s32 func_0022F95C(M2Own *o);
void func_002325EC(M2Act *a, M2St *s);
void func_00214178(M2Act *a, M2St *s, s32 id);
void func_0025DE74(s32 id, Vec3f pos, Vec3f *pp, s32 x);
void func_auto_00230604(M2Act *a, M2St *s) {
    M2Own *o;
    s32 kind;
    o = a->owner;
    kind = D_800CE8DC[o->unk650].unk0;
    if (s->unkCB != 0 && func_00222A80(o, o->unk62E) == 0 && s->unk13C == 2) {
        s->unk13C = 1;
        if (func_00222A80(o, o->unk62E) == 0) {
            o->unk770 = func_0022F95C(o);
        }
    }
    func_0022B9B4(o);
    o->unk11FC = 0;
    o->unk698->unk168 = 0;
    s->unk138 = 0;
    if (D_801468A0->unk54 != 0 && o->stats->unk8F != 0) {
        if (o->unk6B0 & 0x2000) {
            switch (D_801468A0->unk70) {
            case 0:
                func_0025DE74(0x18A1, o->pos, &o->pos, -1);
                break;
            case 1:
                func_0025DE74(0x1969, o->pos, &o->pos, -1);
                break;
            case 2:
                func_0025DE74(0x1905, o->pos, &o->pos, -1);
                break;
            }
        }
    } else if (kind != 1 && kind != 7 && s->unkCB != 0) {
        func_002325EC(a, s);
        func_00214178(a, s, 0);
    }
}
