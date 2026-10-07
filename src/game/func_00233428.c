#include "b08_types.h"

typedef struct Row24 {
    s16 unk0;
    u8 pad2[0x16];
} Row24;

extern Row24 D_800CE8DC[];
extern u8 D_80121990[];
extern s32 D_801468F4;

void func_00214178(Actor *actor, ActorState *state, s32 id);
s32 func_00222A80(Player *p, s32 a);
void func_0022B180(Player *p);
s32 func_0022F95C(Player *p);
s32 func_002301E4(Actor *actor, ActorState *state);
s32 func_002831FC(void *a, Player *p);

void func_00233428(Actor *actor, ActorState *state) {
    Player *p;
    s32 id;

    p = (Player *)actor->owner;
    id = D_800CE8DC[p->unk650].unk0;
    if (p->unk11D8 <= 0.0f && (p->stats->unk8F == 0 || D_801468F4 == 0) && (p->flags6AC & 0x4000)) {
        func_0022B180(p);
    }
    if (func_00222A80(p, p->unk62E) == 0) {
        if (func_002831FC(D_80121990, p) == 0) {
            p->unk770 = func_0022F95C(p);
        }
    } else if (func_002301E4(actor, state) == 0 && !(actor->flags & 0x400)) {
        func_00214178(actor, state, id);
    }
}
