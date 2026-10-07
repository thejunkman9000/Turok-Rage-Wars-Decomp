#include "o02_types.h"
typedef struct { s8 pad[8]; struct { s8 a, b, c, d, e, f, g, h; } e[1]; } T;
T *func_0041208C(s32 i);
s16 func_00411CE0(s32 i);
/* permuter result: the sum++/sum-- pair only perturbs pseudo numbering (register allocation) */
s32 func_0040F1E0(s32 font, u8 *str, s32 len) {
    T *t = func_0041208C(font);
    s32 i;
    s32 sum;
    i = (sum = 0);
    while (i < len) {
        sum += t->e[*str++ - 0x20].a;
        i++;
    }
    sum++;
    sum--;
    return sum + func_00411CE0(font) * (len - 1);
}
