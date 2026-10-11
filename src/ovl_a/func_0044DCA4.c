/* their2 */
/* Port of func_8044D054_de.c of the other decompilation (CC0): func_0044DCA4, symbols renamed to US v1.1 names. */
#include "span_16E000/code_8044ACCC.h"
#include "common/unused.h"
#include "types.h"

/* Loads a selected resource into the shared buffer and releases the temporary allocation. */

struct State_func_8044D054_de;

s32 *func_002518DC(s32, s32, s32, s32, s32, s32, void *, void *, s32); /* extern */
extern void func_002537D8(void *, void *); /* extern */
extern s32 func_00264B8C(void); /* extern */
extern void *func_002C2490(void *, const void *, int); /* memcpy: keep the neutral name, a builtin-typed memcpy declaration is expanded inline */
extern s32 func_00285130(s32 a, s32 b);      /* resource callback (callee defined in src/game/func_00285130.c) */
extern char D_800CA1A0;
extern char D_800FD1F0;

void func_0044DCA4(State_func_8044D054_de *arg0) {
    s32 *temp_v0;
    s32 temp_a1;

    if (func_00264B8C() == 0) {
        temp_v0 = func_002518DC(0, arg0->unk38, arg0->unk38, arg0->unk44, 0, 0, (void *) func_00285130, &D_800CA1A0, 1);
        func_002C2490(&D_800FD1F0, (const void *)*temp_v0, 0x5800);
        func_002537D8(0, temp_v0);
        arg0->unk4 = 1;
    }
}
