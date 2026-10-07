#include "o04_types.h"
typedef struct { u8 pad0[6]; u16 ids[8]; } O04Rec;
extern s32 D_8015402C;
extern u8 D_8011FE88[];
O04Rec *func_0028D450(void *a, s32 b);
void func_004263BC(O04Plr *p) {
    s32 i;
    O04Rec *r;
    if (p->unk5D8->unk91 == 1 || p->unk5D8->unk78 == 0) {
        return;
    }
    r = func_0028D450(D_8011FE88, D_8015402C);
    for (i = 0; i < 8; i++) {
        s32 id = r->ids[i];
        if (id >= 0x4C3) {
            id -= 0x4C3;
            p->unk602[id].a = 1;
            p->unk602[id].b = i;
        }
    }
}
