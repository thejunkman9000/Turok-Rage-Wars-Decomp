#include "b11_types.h"

B11Rec *func_002625B8(s32 a);
s32 func_002625E4(s32 a);
void func_00272908(void *m, void *v, Vec3f *out);
void func_00265E30(Obj *a, Obj *b, u16 c, s32 d, Vec3f e, B11Pair f);

void func_0024C1B4(Obj *a, s32 b) {
    B11Rec *list = func_002625B8(b);
    s32 n = func_002625E4(b);
    s32 i;
    s32 t;
    Vec3f v;
    for (i = 0; i < n; i++) {
        t = list[i].type;
        if (t < 8) {
            if (t >= 6) {
                func_00272908(a->unk74, &list[i].pos, &v);
                func_00265E30(a, a, list[i].type, -1, v, list[i].unk14);
            }
        }
    }
}
