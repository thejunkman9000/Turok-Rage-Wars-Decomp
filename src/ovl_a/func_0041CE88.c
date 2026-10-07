#include "o03_types.h"
/* span of func_0041CE88 = this 8-insn function, then 2 padding words (`jal func_0041D9D0 ; nop` junk) and the real big function at rom 0x18AEB0 (see func_0041CEB0) */
typedef struct { u8 pad[0x274]; u16 f274; } O3Q274;
void func_0041C680();
void func_0041CE88(O3Q274 *o) {
    o->f274 = 0xFFFF;
    func_0041C680(o);
}
