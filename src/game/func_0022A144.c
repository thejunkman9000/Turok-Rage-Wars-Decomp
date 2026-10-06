#include "b06_types.h"

void func_00253B5C(s32 a, s32 b);
void func_0024B8B4(void *a);
void func_0022BC84(Plr *a, s32 b);
void func_0024B7D4(Plr *a, s32 b);
extern GStateB6 D_801462C8[];

void func_0022A144(PlrGroup *g) {
    Plr *a;
    if (g->unk0 != 0) {
        func_00253B5C(0, g->unk0);
    }
    for (a = g->head; a != NULL; a = a->next) {
        func_0024B8B4(a);
        func_0024B8B4((u8 *)a + 0x2E8);
        func_0022BC84(a, 0);
        if (D_801462C8->unk1D != 0) {
            func_0024B7D4(a, 1);
        }
    }
}
