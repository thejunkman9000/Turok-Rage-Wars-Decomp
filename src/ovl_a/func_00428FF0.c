#include "o04_types.h"
extern O04ModeS4690 *D_800E4690;
extern O04Ent1C D_800E4694[];
void func_0029A73C(void);
void func_004275B4(void);
void func_0042EB80(s32 a, s32 b);
void func_0042EB68(s32 a);
s32 func_00428FF0(void) {
    func_0029A73C();
    func_004275B4();
    func_0042EB80(D_800E4694[D_800E4690->unkA44].a, D_800E4694[D_800E4690->unkA44].b);
    func_0042EB68(0x19);
    return 0;
}
