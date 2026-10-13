/* func_0044E7C0 (ROM 0x1BC7C0, 59 insns + 1 linker pad word 0x1BC8AC; upstream func_8044DB70_de, no upstream source):
   initialises a pool of 32 effect slots of 0x1E0 bytes: links them into a doubly linked list through prev (+0x1D8) / next (+0x1DC),
   header at +0x3C00 = {head = slot 0, tail 0, count 0}; sets up the two global records D_8011F448 / D_8011F2C0 (func_00219460 + overrides, the second one
   with the 122.88f pool constant at ROM 0xCB080) and calls func_002903E8 on every slot.  (their names: D_8011B388 = our D_8011F448, D_8011B200 = D_8011F2C0) */
#include "s1007_types.h"

void func_00219460(S7Rec *r);
void func_002903E8(S7Slot *s);
extern S7Rec D_8011F448;
extern S7Rec D_8011F2C0;

void func_auto_0044DB70(S7Fx *p) {
    s32 i;

    p->head = &p->slot[0];
    p->count = 0;
    p->tail = 0;
    for (i = 0; i < 31; i++) {
        p->slot[i].next = &p->slot[i + 1];
        p->slot[i].prev = &p->slot[i - 1];
    }
    p->slot[0].prev = 0;
    p->slot[31].next = 0;
    func_00219460(&D_8011F448);
    D_8011F448.unk0 = 8;
    D_8011F448.unk14 = 1;
    D_8011F448.unk12 = 0;
    func_00219460(&D_8011F2C0);
    D_8011F2C0.unk0 = 8;
    D_8011F2C0.unk14 = 0;
    D_8011F2C0.unk12 = 0;
    D_8011F2C0.unk18 = 122.88f;
    D_8011F2C0.unk1C = 122.88f;
    for (i = 0; i < 32; i++) {
        func_002903E8(&p->slot[i]);
    }
}
