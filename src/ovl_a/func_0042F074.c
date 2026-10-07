#include "o04_types.h"
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x80 - 0x79]; s8 unk80; u8 pad81[0x96 - 0x81]; } O04Ent96c;
extern O04Ent96c D_80146398[];
s32 func_00274544(void);
s32 func_0042F074(void) {
    s32 r;
    s32 ok;
    s32 i;
    O04Ent96c *e;
    do {
        r = func_00274544() % 11;
        if (r == 0 || r == 5) {
            ok = 1;
            for (i = 0; i < 8; i++) {
                e = &D_80146398[i];
                if (e->unk78 != 0 && e->unk80 == r) {
                    ok = 0;
                }
            }
        } else {
            ok = 1;
        }
    } while (ok == 0);
    return r;
}
