#include "p3_types.h"

typedef struct {
    u8 pad0[0xE];
    s16 count;             /* 0x0E */
    u32 v[1];              /* 0x10 */
} P3SortArr;

void func_00258F8C(P3SortArr *a) {
    s32 i, j;
    for (i = 0; i < a->count; i++) {
        for (j = i + 1; j < a->count; j++) {
            u32 x = a->v[j];
            u32 y = a->v[i];
            if (x < y) {
                a->v[i] = x;
                a->v[j] = y;
            }
        }
    }
}
