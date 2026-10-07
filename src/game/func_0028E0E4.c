#include "b20_types.h"

s32 func_0028B238(u8 *p, s32 a);
extern u8 D_8011FE88[];
extern Entity *D_800F7CF8[4];
extern Entity *D_800F7D08;

void func_0028E0E4(Level *lv) {
    s32 i;
    Entity *e = lv->entities;
    D_800F7D08 = 0;
    for (i = 0; i < 4; i++) {
        D_800F7CF8[i] = 0;
    }
    for (i = 0; i < lv->numEntities; i++) {
        if (e->def->type == 3) {
            if (func_0028B238(D_8011FE88, *(s16 *)((u8 *)e->def + 0x28)) == 0xBD7) {
                D_800F7D08 = e;
                break;
            }
        } else if (e->def->type == 10) {
            switch (e->unkE4) {
            case 0x653:
                D_800F7CF8[0] = e;
                break;
            case 0x654:
                D_800F7CF8[1] = e;
                break;
            case 0x655:
                D_800F7CF8[2] = e;
                break;
            case 0x656:
                D_800F7CF8[3] = e;
                break;
            }
        }
        e++;
    }
}
