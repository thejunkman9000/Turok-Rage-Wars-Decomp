#include "b15_types.h"

typedef struct B15Ent {
    u8 pad0[0x16];
    s16 unk16;
} B15Ent;

void func_00255E78(void *pool, B15Ent *e);
void func_00255C58(void *list, B15Ent *e);

void func_00268C7C(u8 *pool, B15Ent *e) {
    e->unk16 = 0;
    func_00255E78(pool, e);
    func_00255C58(pool + 0x14, e);
}
