#include "m02_gen.h"
extern DlCmd *D_80110634;
extern s32 D_800D15E0;
extern f32 D_800D15F0;
extern s32 D_800D297C;
extern M2G2 D_801468A0[];
void func_0024A3A0(M2Act2 *a, M2Own2 *o, void *b, M2Args *c);
void func_00268CE0(s32 id);
void func_0026CBA4(s32 a, M2Own2 *o, s32 b, s32 c, void *d, s32 e, s32 f);
void func_00228F94(M2Act2 *a, void *b, M2Args *c) {
    M2Own2 *o;
    DlCmd *g;
    if (a != 0) {
        o = (M2Own2 *)a->owner;
        if (o != 0) {
            g = D_80110634++;
            g->w0 = 0xE200001C;
            g->w1 = 0xC4404B50;
            func_00268CE0(2);
            if (D_801468A0->unk54 != 0 && o->stats->unk8F != 0) {
                a->unk1 = D_801468A0->unk73;
            } else {
                a->unk1 = a->unk18->unkE;
            }
            if (o->unk1238 == 0) {
                f32 *q = (f32 *)&D_800D15E0 + 1;
                f32 v1, v2, v3, v4;
                v1 = 255.0f - o->unk1230 * 17.0f;
                D_800D15E0 = 1;
                v1 = (v1 < 0.0f) ? 0.0f : v1;
                q[0] = v1;
                v2 = 255.0f - o->unk1230 * 17.0f;
                v2 = (v2 < 0.0f) ? 0.0f : v2;
                q[1] = v2;
                q[2] = 0.0f;
                v3 = 255.0f - o->unk1230 * 8.533334f;
                v3 = (v3 < 0.0f) ? 0.0f : v3;
                q[3] = v3;
                func_0024A3A0(a, o, b, c);
                v4 = 255.0f - 2.0f * q[3];
                v4 = (v4 < 0.0f) ? 0.0f : v4;
                q[3] = v4;
                func_0026CBA4(c->unkC, o, a->unkB4, 1, (u8 *)a + D_800D297C * 0x18 + 0x140, 0, -1);
            } else if (o->unk1238 == 1) {
                f32 *q = (f32 *)&D_800D15E0 + 1;
                f32 v1, v2, v3;
                v1 = 255.0f - o->unk1230 * 17.0f;
                D_800D15E0 = 1;
                v1 = (v1 < 0.0f) ? 0.0f : v1;
                q[0] = v1;
                v2 = 255.0f - o->unk1230 * 17.0f;
                v2 = (v2 < 0.0f) ? 0.0f : v2;
                q[1] = v2;
                q[2] = 0.0f;
                v3 = 255.0f - o->unk1230 * 8.533334f;
                v3 = (v3 < 0.0f) ? 0.0f : v3;
                q[3] = v3;
                func_0026CBA4(c->unkC, o, a->unkB4, 1, (u8 *)a + D_800D297C * 0x18 + 0x140, 0, -1);
            } else if (o->unk1238 == 3) {
                f32 v;
                v = o->unk1230 * 0.425f;
                D_800D15E0 = 1;
                if (v < 0.0f) {
                    v = 0.0f;
                }
                D_800D15F0 = v;
                func_0024A3A0(a, o, b, c);
            }
            D_800D15E0 = 0;
        }
    }
}
