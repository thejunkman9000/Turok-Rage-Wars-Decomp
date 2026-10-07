#include "b06_types.h"

void func_0024BE2C();
void func_00246E34(PlrObj *e);
extern f32 D_800D2988;

void func_0022A94C(Plr *a) {
    PlrObj *e = (PlrObj *)((u8 *)a + 0x2E8);
    s32 saved = a->unk86C;
    f32 f = D_800D2988;
    e->unk2E0 = 0x10;
    e->flags100 &= 0xFFFDFFFF;
    func_0024BE2C(e);
    if (a->unk11D8 <= 0.0f) {
        func_00246E34(e);
    }
    D_800D2988 = f;
    if (saved != a->unk86C) {
        a->unk10E = 0;
    }
    a->unk2F0 = a->pos;
    a->unk354 = a->unk6C;
    a->unk2FC = a->unk14;
    a->unk344 = a->unk5C;
}
