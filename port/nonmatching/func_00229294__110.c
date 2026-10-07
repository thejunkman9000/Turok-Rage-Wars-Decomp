#include "m02_types.h"
extern const f32 D_800C7D34;
extern f32 D_800C7D38;
extern f32 D_800C7D3C;
extern f32 D_800D2988;
void func_00216488(void *out, void *obj, s32 a, f32 b, s32 c, s32 d);
void func_00219A40(Plr *a, void *b, void *c);
void func_0022B5FC(Plr *a, f32 f, void *o);
void func_00229294(Plr *a) {
    s32 i;
    PlrEnt *e;
    f32 v;
    f32 d;
    f32 t;
    M2Obj *o;
    u8 sp18[0x18];
    for (i = 0; i < 5; i++) {
        e = &a->ent[i];
        if (e->unk4 > 0.0f) {
            d = D_800D2988;
            v = e->unk0 * d;
            v *= D_800C7D34;
            e->unk4 = e->unk4 - d;
            e->unk10 = e->unk10 + (f32)(s32)v;
            if (e->unk4 <= 0.0f) {
                t = e->unkC * D_800C7D34;
                if (e->unk10 < t) {
                    v += t - e->unk10;
                }
            }
            o = (M2Obj *)e->unk8;
            if (o != 0 && o->type == 1 && (o->flags100 & 0x300000) && (o->flags122C & 0x200)) {
                v *= D_800C7D38;
            }
            if (e->unk14 != 0) {
                func_0022B5FC(a, 0.093333334f, (void *)e->unk8);
                if ((f32)a->unk5E4 <= v) {
                    v = D_800C7D3C;
                }
            }
            func_00216488(sp18, (void *)e->unk8, (s32)v, 25.599998f, 0x100080, 0);
            func_00219A40(a, (u8 *)a + 0x170, sp18);
        }
    }
}
