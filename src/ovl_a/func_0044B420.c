/* their2 */
/* Port of func_8044A7D0_de.c of the other decompilation (CC0): func_0044B420, symbols renamed to US v1.1 names. */
#include "span_16E000/code_8044ACCC.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

extern void func_00255C40(IntrusiveList *list, s32 prevOffset, s32 nextOffset);
extern s32 func_00255CB4(IntrusiveList *list, void *node);

/* Initialises the two lists at offsets 0x8B4 and 0x8A0 of a pool with node offsets 0 and 4
   through func_00255C40, adds the pool's four entries of 0x228 bytes to the second list through
   func_00255CB4 and clears the halfword at 0x8C8. */
void func_0044B420(func_8044B420_S1 *pool) {
    s32 i;
    struct Entry_func_8044A7D0_de *entry;

    func_00255C40(&pool->active, 0, 4);
    func_00255C40(&pool->free, 0, 4);
    for (i = 0, entry = pool->entries; i < 4; i++, entry++) {
        func_00255CB4(&pool->free, entry);
    }
    pool->unk8C8 = 0;
}
