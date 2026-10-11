/* their2: ported from the newer headers of the other decompilation (include/their2) */
#include "span_1000/code_8027302C.h"
#include "types.h"

extern f32 D_800C4918_de;

extern f32 D_800C4928_de;

void func_80274020_de(f32 *value)
{
    {
        f32 val;
        f32 limit;
        f32 step;

        val = *value;
        limit = *(&D_800C4918_de + 1);
        if (val < limit) {
            step = D_800C4920_de;
            do {
                val += step;
                *value = val;
            } while (val < limit);
        }
    }
    {
        f32 val;
        f32 limit;
        f32 step;

        val = *value;
        limit = *(&D_800C4920_de + 1);
        if (limit <= val) {
            step = D_800C4928_de;
            do {
                val -= step;
                *value = val;
            } while (limit <= val);
        }
    }
}
