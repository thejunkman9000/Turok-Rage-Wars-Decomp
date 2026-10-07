#include "b06_types.h"

void func_0025DF54(s32 a);
void func_00237E70(u8 *a, Pawn *p, char *s);
extern f32 D_800C7E0C;
extern char *D_800D71E0;
extern char *D_800D71E8;
extern char *D_800D71EC;
extern u8 D_80145088[];

void func_0022B7E8(Plr *a, Plr *b) {
    u8 *name;
    if (a->unk11E4 == 0.0f) {
        func_0025DF54(0xB45);
        a->unk13E0 = (s32)b;
        a->unk11E4 = D_800C7E0C;
        if (a->unk5DC != NULL) {
            func_00237E70(D_80145088, a->unk5DC, D_800D71E0);
            if (b != NULL && b->unk0 == 1) {
                if (b->flags100 & 0x300000) {
                    name = a->unk13EC;
                    sprintf(name, D_800D71E8, (u8 *)b->stats + 0x84);
                    func_00237E70(D_80145088, a->unk5DC, name);
                    func_00237E70(D_80145088, a->unk5DC, D_800D71EC);
                }
            }
        }
    }
}
