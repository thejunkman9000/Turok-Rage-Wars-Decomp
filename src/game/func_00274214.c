/* their2: ported from the newer headers of the other decompilation (include/their2) */
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8027302C.h"
#include "types.h"

extern f32 func_802B72B0_de(f32);
extern char D_800C4928_de;




void func_802741A4_de(f32 *arg0) {
    f32 mag;
    f32 scale;

    mag = func_802B72B0_de((arg0[0] * arg0[0]) + (arg0[1] * arg0[1]) + (arg0[2] * arg0[2]) + (arg0[3] * arg0[3]));
    if (mag != 0.0f) {
        scale = ((func_802077F4_S2 *)(&D_800C4928_de))->unk4 / mag;
        arg0[0] = arg0[0] * scale;
        arg0[1] = arg0[1] * scale;
        arg0[2] = arg0[2] * scale;
        arg0[3] = arg0[3] * scale;
    }
}
