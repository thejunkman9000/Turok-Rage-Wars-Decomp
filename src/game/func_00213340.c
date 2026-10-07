#include "b03_types.h"

extern EntList D_8013B364[];
extern s32 D_8013B368;
EntRec *func_0020C994(EntList *list, s32 key);
s32 func_00274544(void);

void func_00213340(BrainB *b) {
    s32 list[32];
    s32 n;
    s32 sel;
    s32 i;
    s32 id;
    s32 k;
    EntList *L;
    EntList *L1;

    sel = 0;
    n = 0;
    for (i = 0; i < 32; i++) {
        list[i] = -1;
    }
    L1 = D_8013B364;
    for (i = 0; i < L1->count; i++) {
        if (func_0020C994(L1, i)->flags & 0x800) {
            list[n] = i;
            n++;
        }
    }
    if (n == 0) {
        L = D_8013B364;
        k = 0;
        if (D_8013B368 >= 2) {
            id = b->unk22C;
            while (1) {
                if (k >= 10) {
                    break;
                }
                id = func_00274544() % L->count;
                if (func_0020C994(L, id)->flags & 0x400) {
                    id = b->unk22C;
                }
                k++;
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
    } else {
        sel = list[func_00274544() % n];
    }
    b->unk22C = sel;
    b->unkC = sel;
}
