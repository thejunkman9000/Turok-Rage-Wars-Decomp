#include "m02_gen.h"
extern f32 D_800D2988;
extern u8 D_801462E5[];
s32 func_0022ABF0(M2H *p);
s32 func_00220D20(M2H *p) {
    f32 fs;
    f32 c;
    f32 v;
    s32 t;
    s32 u;
    u8 *g;
    if ((p->unk122C & 4) && p->unk5E4 > 0) {
        v = (f32)func_0022ABF0(p);
        fs = (f32)p->unk5E4 + D_800D2988 * 68.26667f;
        if (!(v <= fs)) {
            v = fs;
        }
        t = (s32)v;
        p->unk5E4 = t;
        p->unk174 = p->unk5E4;
        p->unk45C = p->unk5E4;
        return t;
    }
    fs = p->unk18->unk24;
    g = D_801462E5;
    if (g[0] != 0 && !(fs < 0.1f) && (c = (f32)p->unk5E4, c != 0.0f) && (p->stats->unk8F == 0 || *(s32 *)(g + 0x60F) == 0)) {
        fs = c + (f32)(s32)(fs * 256.0f) * (D_800D2988 * 0.06666667f);
        if (fs < (f32)func_0022ABF0(p)) {
            t = (s32)fs;
            p->unk5E4 = t;
            return t;
        }
        t = (s32)(f32)func_0022ABF0(p);
        p->unk5E4 = t;
        return t;
    }
}
