#include "b06_types.h"

void func_0025DF54(s32 a);
void func_00237E70(u8 *a, Pawn *p, char *s);
extern f32 D_800C7E0C;
extern char *D_auto_800E0FF4[][4];
extern u8 D_80145088[];

void func_auto_0022B8C0(Plr *a, Plr *b) {
    u8 *name;
    u8 *g;
    u8 *w;
    if (a->unk11E4 == 0.0f) {
        func_0025DF54(0xB45);
        a->unk13E0 = (s32)b;
        a->unk11E4 = D_800C7E0C;
        if (a->unk5DC != NULL) {
            w = D_80145088;
            g = w + 0x1240;
            func_00237E70(w, a->unk5DC, D_auto_800E0FF4[19][g[0x581]]);
            if (b != NULL && b->unk0 == 1) {
                if (b->flags100 & 0x300000) {
                    name = a->unk13EC;
                    sprintf(name, D_auto_800E0FF4[21][g[0x581]], (u8 *)b->stats + 0x84);
                    func_00237E70(w, a->unk5DC, name);
                    func_00237E70(w, a->unk5DC, D_auto_800E0FF4[22][g[0x581]]);
                }
            }
        }
    }
}
