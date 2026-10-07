#include "b03_types.h"

extern EntList D_8013B364[];
extern s32 D_8013B368;
EntRec *func_0020C994(EntList *list, s32 key);
void func_00208410(BrainB *b);
void func_00208AAC(BrainB *b);
void func_00211020(BrainB *b);
void func_00213340(BrainB *b);
s32 func_00274544(void);

void func_00213500(ActorB *actor) {
    BrainB *b = actor->owner->brain;
    ActorStats *st;
    ActorB *a;
    EntList *L;
    s32 i;
    s32 id;
    s32 busy;
    s32 busy2;
    s32 t;

    if (b->unk4 == b->unk22C || b->unk22C >= D_8013B368) {
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
    }
    b->unk320 = b->unk320 - 1;
    if (b->unk320 == 0) {
        busy2 = b->unk314 != 0;
        a = b->actor;
        t = a->unk650;
        t ^= 0xF;
        busy = (a->flags38 & 0x3000) != 0;
        if (t && !busy && !busy2) {
            a->unk6B0 |= 0x10;
        }
    }
    if (b->unk320 < 0) {
        b->unk320 = (func_00274544() % 7 + 3) * 15;
    }
    func_00211020(b);
    func_00208410(b);
    func_00208AAC(b);
}
