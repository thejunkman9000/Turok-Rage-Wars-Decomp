/* func_0044EACC (ROM 0x1BCACC, 54 insns + 3 linker pad words 0x1BCBA4..0x1BCBAF; upstream func_8044DE7C_de, no upstream source):
   sibling of func_00293268 / func_0044EA24: looks up the object `a` in the track D_8011FE88 (func_0044DE70, any kind, one result; 0 when none),
   clears five words of the game block D_801468A0 and enters match state 13 (when the block flag at +0x26825 and D_801468A0+0xAC are both set) or 12. */
#include "s1007_types.h"

extern u8 D_8011FE88[];
extern S7Blk D_801468A0[];
s32 func_0044DE70(void *track, s32 kind, s32 key, void *out, s32 max);

#define SET_STATE(m, s) do { (m)->unk26DC1 = 2; (m)->state = (s); } while (0)

void func_auto_0044F14C(S7Match *m, s32 a) {
    s32 buf[6];
    S7Blk *b;

    if (func_0044DE70(D_8011FE88, -1, a, buf, 1) == 0) {
        a = 0;
    }
    b = D_801468A0;
    b->unk0 = 0;
    b->unk4 = 0;
    b->unk8 = 0;
    b->unkC = 0;
    b->unk88 = 0;
    m->unk26DDC = 0;
    m->unk26DD8 = a;
    if (m->unk26825 != 0 && b->unkAC != 0) {
        SET_STATE(m, 13);
    } else {
        SET_STATE(m, 12);
    }
}
