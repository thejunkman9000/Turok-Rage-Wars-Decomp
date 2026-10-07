#include "m02_gen.h"
extern f32 D_800C7F80;
extern M2Row18 D_800CE8DC[];
extern M2Cls *D_800D052C[];
extern f32 D_800D2988;
void func_00214178(M2Act *a, M2St *s, s32 id);
void func_0022BC04(M2Own *o);
void func_0022FC10(M2Act *a, M2St *s) {
    M2Own *o;
    f32 dt;
    M2Fn f;
    f32 sc;
    s32 kind;
    o = a->owner;
    kind = D_800CE8DC[o->unk650].unk0;
    if (!(o->unk11D8 > 0.0f)) {
        dt = D_800D2988;
        sc = dt * D_800C7F80;
        if (o != 0 && (o->unk122C & 0x2000)) {
            D_800D2988 = sc;
        } else {
            D_800D2988 = dt;
        }
        if (s->unk148 > 0.0f) {
            s->unk148 = s->unk148 - D_800D2988;
        }
        a->unk1 = 0;
        if (s->unk130 > 0.0f) {
            s->unk130 = s->unk130 - D_800D2988;
        }
        if (kind == 1) {
            func_00214178(a, s, 1);
        }
        if (o->unk770 != o->unk62E) {
            o->unk7E8 = 0;
            func_00214178(a, s, 1);
        }
        if (s->link != 0) {
            f = s->link->cb8;
            if (f != 0) {
                f(a, s);
            }
        }
        f = D_800D052C[o->unk62E]->fn5C;
        if (f != 0) {
            f(a, s);
        }
        func_0022BC04(o);
        D_800D2988 = dt;
    }
}
