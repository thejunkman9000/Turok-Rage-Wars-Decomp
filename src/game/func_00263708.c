/* Swaps the bit pairs 0x10000 <-> 0x8 and 0x80000 <-> 0x4 of a flag word (all other bits except those four are kept).
   First 19 words of the manifest unit pad_064308 (follows func_002636D0, same object); the last 3 words of that
   unit are ROM+0x1000 copies = padding.  Upstream: func_802636E8_de. */
#include "s1008_types.h"

s32 func_00263708(s32 arg0) {
    s32 new_var;
    s32 var_v1;
    new_var = 0x80000;
    var_v1 = arg0 & 0xFFF6FFF3;
    if (arg0 & 0x10000) {
        var_v1 |= 8;
    }
    if (arg0 & 8) {
        var_v1 = var_v1 | 0x10000;
    }
    if (arg0 & new_var) {
        var_v1 |= 4;
    }
    if (arg0 & 4) {
        var_v1 |= 0x80000;
    }
    return var_v1;
}
