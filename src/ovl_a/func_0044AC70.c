/* their2 */
/* ported from melalawi/ragewars-decomp src/func_8044A020_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "span_16E000/code_80447BB0.h"
#include "types.h"

/* Sets the byte at offset 0x78 of the object at 0x5D8 of an actor, calls func_00449B44 with the
   actor, its second argument and one, then func_00214178 on offsets 0x2E8 and 0x458 with two and
   func_0021B1E4 with D_80146898, zero and one. */




extern s32 D_80146898;
extern void func_00449B44(struct Actor_func_8044A020_de *, void *, s32);
extern void func_00214178(void *, void *, s32);
extern void func_0021B1E4(struct Actor_func_8044A020_de *, s32, s32, s32);




void func_0044AC70(struct Actor_func_8044A020_de *actor, void *second) {
    actor->part->active = 1;
    func_00449B44(actor, second, 1);
    func_00214178(&((func_8044AC70_S1 *)(actor))->unk2E8, &((func_8044AC70_S1 *)(actor))->unk458, 2);
    func_0021B1E4(actor, D_80146898, 0, 1);
}
