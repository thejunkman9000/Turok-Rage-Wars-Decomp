#include "b03_types.h"

extern EntList D_8013B364[];
extern s32 D_8013B368;
EntRec *func_0020C994(EntList *list, s32 key);
void func_00209988(BrainB *b);
void func_00213340(BrainB *b);
s32 func_00274544(void);

void func_002136EC(ActorB *actor) {
    BrainB *b = actor->owner->brain;
    ActorStats *st;
    EntList *L;
    s32 i;
    s32 id;

    b->unk220 = 0;
    st = b->actor->stats;
    if (st->unk94 != 0 && st->unk80 == 0xC) {
        func_00213340(b);
    } else {
        i = 0;
        L = D_8013B364;
        if (D_8013B368 >= 2) {
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
    func_00209988(b);
    b->unk320 = -1;
}
