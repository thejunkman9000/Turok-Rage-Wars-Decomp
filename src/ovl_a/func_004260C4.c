#include "o04_types.h"
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x91 - 0x79]; u8 unk91; u8 pad92[0x96 - 0x92]; } O04Ent96g;
extern O04Ent96g D_80146398[];
extern u8 D_80102B4A[];
s32 func_00265670(void *p, s32 a);
void func_002656A8(void *p, s32 a, s32 b);
void func_004260C4(s32 a, s32 *out) {
    s32 flag = 1;
    s32 i;
    s32 row;
    O04Ent96g *e = &D_80146398[a];
    if (e->unk78 == 1 && e->unk91 == 0) {
        row = a * 0x190;
        if (func_00265670(D_80102B4A + row, 0x31) == 0) {
            for (i = 0; i < 4; i++) {
                if (flag != 1) {
                    return;
                }
                if (func_00265670(D_80102B4A + 0xDA + row, i) == 0) {
                    flag = 0;
                }
            }
            if (flag == 1) {
                func_002656A8(D_80102B4A + a * 0x190, 0x31, 1);
                *out = 0x31;
            }
        }
    }
}
