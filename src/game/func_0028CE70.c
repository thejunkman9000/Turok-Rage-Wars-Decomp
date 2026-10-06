#include "b20_types.h"
s32 func_00265570(s32 *ents, s32 n, s32 id, s32 *lo, s32 *hi);
void func_00285B34(s32 a, u8 *p, Vec3f v, f32 f, f32 g, s32 h);
void func_0028CE70(Level *lv, s32 a1, s32 id, Vec3f v, f32 f6, f32 f7) {
    s32 lo;
    s32 hi;
    s32 i;
    s32 *t = lv->unkA8;
    s32 n = t[1];
    if (func_00265570(t + 2, n, id, &lo, &hi) != 0) {
        i = lo;
        if (hi >= i) {
            do {
                s32 *tbl = lv->unkAC;
                func_00285B34(a1, (u8 *)tbl + (i * tbl[0] + 8), v, f6, f7, 0);
                i++;
            } while (hi >= i);
        }
    }
}
