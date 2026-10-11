/* func_0044E038 (ROM 0x1BC038, 80 insns; upstream func_8044D3E8_de, no upstream source):
   finds the placed object of kind `kind` that is nearest to `pos` in a track (tables from func_0028FD94: table 0 = keys, table 1 = the 20-byte objects;
   both preceded by 8 header bytes, count = word 1 of table 0), copies it to *out and returns its key; returns 0 when none matched (index 0 never wins).
   The only float constant is FLT_MAX (literal pool word 0x7F7FFFFF at ROM 0xCAFEC).
   NOTE on the second `if (best == 0) return 0;` inside the then-part: it is dead (cse knows best != 0 there) and emits no code.  It keeps a CODE_LABEL
   between the first branch and the `return 0` block, which stops jump.c's "if (foo) bar; else break;" block swap (second jump_optimize sweep) that would
   otherwise move the `return 0` block in front of the copy; the ROM has the unswapped layout (copy, j K, return 0, K: return keys[best]). */
#include "s1007_types.h"

s32 *func_0028FD94(void *tbl, s32 idx);
f32 func_00272768(Vec3f *a, Vec3f *b);

s32 func_0044E038(S7Track *track, Vec3f *pos, s32 kind, S7Obj *out) {
    s32 i;
    s32 best = 0;
    s32 count;
    s32 *t;
    s32 *keys;
    S7Obj *objs;
    f32 bestd;
    f32 d;

    t = func_0028FD94(track->resource, 0);
    count = t[1];
    keys = t + 2;
    objs = (S7Obj *)(func_0028FD94(track->resource, 1) + 2);
    bestd = 3.4028235e+38f;
    for (i = 0; i < count; i++) {
        if (objs[i].kind == kind) {
            d = func_00272768(&objs[i].pos, pos);
            if (d < bestd) {
                bestd = d;
                best = i;
            }
        }
    }
    if (best != 0) {
        *out = objs[best];
        if (best == 0) {
            return 0;
        }
    } else {
        return 0;
    }
    return keys[best];
}
