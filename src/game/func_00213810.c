#include "b03_types.h"

extern EntList D_8013B364[];
EntRec *func_0020C994(EntList *list, s32 key);
s32 func_00274544(void);

void func_00213810(BrainB *b) {
    EntList *L = D_8013B364;
    s32 i = 0;
    s32 id;

    if (L->count >= 2) {
        id = b->unk22C;
        while (1) {
            if (i >= 10) {
                break;
            }
            id = func_00274544() % L->count;
            if (func_0020C994(L, id)->flags & 0x400) {
                id = b->unk22C;
            }
            i++;
            if (id != b->unk22C) {
                break;
            }
            continue;
        }
    } else {
        id = 1;
    }
    b->unk22C = id;
    b->unkC = id;
}
