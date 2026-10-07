#include "o02_types.h"
typedef struct { u8 pad[0x48]; u8 rows, cols; } S_func_004126B4;
typedef struct { u8 b[0x3C]; } S_cell;
void func_0041234C(S_func_004126B4 *o, S_cell *c, s32 r, s32 col);
void func_0040D350(S_cell *c, O02Ctx ctx);
void func_004126B4(S_func_004126B4 *o, O02Ctx ctx) {
    S_cell c;
    u32 r, col;
    S_func_004126B4 *p = o;
    for (r = 0; r < p->rows; r++) {
        for (col = 0; col < p->cols; col++) {
            func_0041234C(p, &c, r, col);
            func_0040D350(&c, ctx);
        }
    }
}
