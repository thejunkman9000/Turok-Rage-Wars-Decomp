#include "b06_types.h"

void func_002227D0(u8 *a, u8 *b, s32 c);
void func_00264874(s32 a);
extern GameB6 D_801468A0[];

void func_0022A738(ActorGroup *g) {
    Actor *a;
    if (D_801468A0->unk1C == 0 && D_801468A0->unk20 == 0) {
        func_00264874(0);
        if (D_801468A0->unk24 != 0) {
            if (D_801468A0->unk28 == 0) {
                D_801468A0->unk28 = 1;
                for (a = g->head; a != NULL; a = a->next) {
                    func_002227D0((u8 *)a, (u8 *)a, 0x15);
                }
            }
        } else {
            D_801468A0->unk1C = 1;
            for (a = g->head; a != NULL; a = a->next) {
                func_002227D0((u8 *)a, (u8 *)a, 0x15);
            }
        }
        D_801468A0->unk1C = 1;
        for (a = g->head; a != NULL; a = a->next) {
            B6F(a, s32, 0x85C) = 0;
            a->stats->unk8E = 1;
        }
    }
}
