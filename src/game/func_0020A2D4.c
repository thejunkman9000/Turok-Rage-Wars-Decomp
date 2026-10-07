#include "b02_types.h"

void func_0020A95C(B2Ctl *ctl, B2Cfg *cfg);
f32 func_0027272C(Vec3f *a, Vec3f *b);
f32 func_002745D4(f32 x);
s32 func_002831FC(void *g, B2Actor *a);
void func_00284FC8(void *g, B2Actor *a, Vec3f *out);
extern u8 D_80121990[];
extern f32 D_800C6E00;
extern f32 D_800C6E04;
extern f32 D_800C6E08;

void func_0020A2D4(B2Ctl *ctl, B2Cfg *cfg) {
    s32 n;
    Vec3f pos;
    B2Actor *t;
    f32 k;

    if (ctl->unk2E4 > 0) {
        ctl->unk2E8 = cfg->unk8;
        ctl->unk2E8 += func_002745D4(D_800C6E00) * cfg->unkC;
        ctl->unk2E4--;
        return;
    }
    if (ctl->unk2E4 == 0) {
        n = func_002831FC(D_80121990, ctl->owner);
        if (n == 3) {
            ctl->unk2E8 = n;
        }
        if (n < ctl->unk2E8) {
            ctl->unk23C = 1;
            return;
        }
        ctl->unk2E4 = -1;
        ctl->unk2E8 = cfg[1].unk8;
        ctl->unk2E8 += func_002745D4(D_800C6E04) * cfg[1].unkC;
        return;
    }
    ctl->unk2E8--;
    t = ctl->target->owner;
    func_00284FC8(D_80121990, ctl->owner, &pos);
    k = D_800C6E08;
    pos.y = t->pos.y;
    if (func_0027272C(&pos, &t->pos) < k) {
        ctl->unk2E8 = 0;
    }
    if (ctl->unk2E8 == 0) {
        ctl->unk240 = 1;
        func_0020A95C(ctl, cfg);
    }
}
