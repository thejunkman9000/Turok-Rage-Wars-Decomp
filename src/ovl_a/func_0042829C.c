#include "o04_types.h"
extern O04ModeS4690 *D_800E4690;
extern u8 D_8011FE88[];
void func_0028D35C(void *a, s32 b, char *buf, s32 c);
s32 func_002A1494(char *s);
void func_002A125C(char *dst, s32 n);
void func_0042829C(void) {
    char buf[0x40];
    func_0028D35C(D_8011FE88, D_800E4690->unkA44, buf, 0x3F);
    func_002A125C(D_800E4690->unkA04, func_002A1494(buf));
    D_800E4690->unk998->unk38 = D_800E4690->unkA04;
}
