#include "o03_types.h"
/* span of func_0041CE88 = this 8-insn function (sets the pose field, then tail-calls func_0041C680 with the caller's a1..a3) */
typedef struct { u8 pad[0x274]; u16 f274; } O3Q274;
void func_0041C680(void *o, s32 a1, s32 a2, s32 a3);
void func_0041CE88(O3Q274 *o, s32 a1, s32 a2, s32 a3) {
    o->f274 = 0xFFFF;
    func_0041C680(o, a1, a2, a3);
}
