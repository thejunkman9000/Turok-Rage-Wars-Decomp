#include "b06_types.h"

s32 func_00245788();
void func_00246E34(PlrObj *e);
void func_0024BE2C();
void func_0025CA44(s32 a, s32 b);
s32 func_0025CC8C();
extern f32 D_800D2988;
extern s32 D_8014687C;
extern s32 D_80146894;

void func_002285C4(PlrGroup *g) {
    Plr *a;
    PlrObj *e;
    s32 saved;
    f32 f;
    s32 v;
    if (D_8014687C == 0xB || D_8014687C == 8) {
        return;
    }
    for (a = g->head; a != NULL; a = a->next) {
        if (func_00245788() != 0 || a->unk5EA == 0) {
            func_0025CA44(func_0025CC8C(), a->unk11BC);
            a->unk11BC = 0;
            func_0025CA44(func_0025CC8C(), a->unk11C0);
            a->unk11C0 = 0;
        } else if (D_80146894 == 0) {
            if (a->unk5DC == NULL) {
                v = 0;
            } else {
                v = a->unk5DC->unk564 != 0;
            }
            if (v == 0) {
                e = (PlrObj *)((u8 *)a + 0x2E8);
                saved = a->unk86C;
                f = D_800D2988;
                a->flags3E8 |= 0x200;
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
                a->flags3E8 &= ~0x200;
            }
        }
    }
}
