#include "b19_types.h"
extern u8 *D_800E4680;
void func_00286920(B19Owner *owner) {
    s32 n = 0;
    s32 i;
    B19Obj *p;
    B19Info18 *inf;
    p = (B19Obj *)owner->base;
    owner->listcnt = 0;
    for (i = 15; i >= 0; i--) owner->list[i] = 0;
    for (i = 0; i < owner->cnt; i++) {
        inf = (B19Info18 *)p->info;
        if (inf->type == 0xD) {
            if (D_800E4680 != 0 && (u32)(inf->f20 - 0xD34) < 4) {
                switch (inf->sC) {
                case 0xD2B:
                    if (D_800E4680[1] == 0) inf->f4 |= 4;
                    else inf->f4 &= ~4;
                    break;
                case 0xD2C:
                case 0xD2D:
                case 0xD2E:
                    if (D_800E4680[((B19Info18 *)p->info)->sC - 0xD2A] == 0) ((B19Info18 *)p->info)->f4 |= 4;
                    else ((B19Info18 *)p->info)->f4 &= ~4;
                    break;
                default:
                    ((B19Info18 *)p->info)->f4 &= ~4;
                    break;
                }
            }
            owner->list[n] = p;
            n++;
        }
        if (n >= 16) break;
        p = (B19Obj *)((u8 *)p + 0x2E8);
    }
    owner->listcnt = n;
}
