#include "b07_types.h"

extern B07Row D_80102B00[];
extern B07Rec96 D_80146398[];
extern s32 D_800D750C[];

void func_0022EF20(B07Row *row);
void func_002A1C08(B07Row *row, s32 a1, s32 a2);

void func_0022F1F4(s32 i)
{
    B07Rec96 *r;
    func_0022EF20(&D_80102B00[i]);
    D_80102B00[i].unk8 = 0;
    D_80102B00[i].unkD = i;
    D_80102B00[i].unkC = 0;
    D_80102B00[i].unkE = 1;
    func_002A1C08(&D_80102B00[i], D_800D750C[0], i + 1);
    r = &D_80146398[i];
    D_80102B00[i].unk189 = r->unk7B;
    D_80102B00[i].unk18A = r->unk7D;
    D_80102B00[i].unk18B = r->unk79;
    D_80102B00[i].unk18C = r->unk7A;
    D_80102B00[i].unk18D = r->unk82;
}
