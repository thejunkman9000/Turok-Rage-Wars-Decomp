#include "o04_types.h"
typedef struct { u8 pad0[6]; u16 ids[8]; } O04Rec;
extern u8 D_8011FE88[];
void func_004288E0(void);
O04Rec *func_0028D450(void *a, s32 b);
void func_0042872C(s32 a, s32 b, s32 c);
void func_004286A0(s32 a) {
    s32 i;
    s32 n;
    O04Rec *r;
    func_004288E0();
    r = func_0028D450(D_8011FE88, a);
    i = n = 0;
    for (; i < 8; i++) {
        s32 id = r->ids[i];
        if (id < 0x4C3) {
            continue;
        }
        id -= 0x4C3;
        if (id == 0) {
            continue;
        }
        func_0042872C(n, id, 0);
        n++;
    }
}
