#include "b01_types.h"
typedef struct { u8 p[0x1D]; u8 f; } GFx;
extern GFx D_801462C8;
extern u8 D_800CD840[];
void func_00206724(B01Actor *actor, B01State *state);
void func_0020694C(B01Actor *actor, B01State *state);
s32 func_00245AFC(void);

void func_00206604(B01Actor *actor, B01State *state) {
    state->table = D_800CD840;
    state->fn108 = func_00206724;
    actor->flags |= 0x1000000;
    actor->flags |= 0x2000000;
    actor->flags |= 0x20000;
    if (D_801462C8.f == 0) {
        actor->flags |= 0x10000000;
    }
    if (actor->unkE4 == 0x453 && func_00245AFC() == 0x6F) {
        state->fn10C = func_0020694C;
    }
}
