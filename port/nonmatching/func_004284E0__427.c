#include "o04_types.h"
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x80 - 0x79]; s8 unk80; u8 pad81[0x96 - 0x81]; } O04Ent96c;
typedef struct { u8 pad0[0x190]; } O04Row190c;
typedef struct { u8 pad0[0x4C]; s32 ids[8]; } O04Rec4C;
extern O04ModeS4690 *D_800E4690;
extern O04Ent96c D_80146398[];
extern O04Row190c D_80102B00[];
extern u8 D_8011FE88[];
void func_004288E0(void);
O04Rec4C *func_0028CF7C(void *a, s32 b, s32 c);
s32 func_0022F4CC(void *a, s32 b);
void func_0042872C(s32 a, s32 b, s32 c);
void func_004284E0(void) {
    s32 i;
    s32 n;
    s32 row;
    O04Rec4C *r;
    func_004288E0();
    n = 0;
    i = 0;
    row = D_800E4690->unkA5C;
    r = func_0028CF7C(D_8011FE88, 0xB, D_80146398[row].unk80);
    for (i = 0; i < 8; i++) {
        s32 id = r->ids[i];
        if (id >= 0x4C3) {
            id -= 0x4C3;
            if (func_0022F4CC(&D_80102B00[row], id) == 1) {
                if (id != 0) {
                    func_0042872C(n, id, 0);
                    n++;
                }
            }
        }
    }
}
