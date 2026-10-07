#include "b20_types.h"
s32 func_002A11E8(void);
extern Entity *D_800F7CD0[10];
extern Entity *D_800F7D0C;
extern s32 D_80146910;
void func_0028E260(Level *lv) {
    s32 n = 0;
    s32 i;
    Entity *e = lv->entities;
    D_800F7D0C = 0;
    for (i = 0; i < 10; i++) {
        D_800F7CD0[i] = 0;
    }
    for (i = 0; i < lv->numEntities; i++) {
        if (e->def->type == 3) {
            if (*(s16 *)((u8 *)e->def + 0x28) == 0xBD6) {
                D_800F7D0C = e;
            }
        } else if (e->def->type == 10) {
            if (e->unkE4 == 0x64E) {
                D_800F7CD0[n] = e;
                n++;
            }
        }
        if (n >= 10) {
            return;
        }
        e++;
    }
    D_80146910 = func_002A11E8() % 3;
}
