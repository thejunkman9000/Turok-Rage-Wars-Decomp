#include "b15_types.h"

typedef struct B15Ent {
    u8 pad0[8];
    s32 unk8;
    u8 padC[0xA];
    s16 unk16;
} B15Ent;

typedef struct B15Pool {
    u8 pad0[0x14];
    B15Ent *head;
} B15Pool;

void func_00255E78(void *list, B15Ent *e);
void func_00255C58(B15Pool *pool, B15Ent *e);

B15Ent *func_00268C1C(B15Pool *pool, s32 val) {
    B15Ent *e;

    e = pool->head;
    if (e != NULL) {
        func_00255E78(&pool->head, e);
        func_00255C58(pool, e);
        e->unk8 = val;
        e->unk16 = 0;
    }
    return e;
}
