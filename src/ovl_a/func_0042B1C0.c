#include "o04_types.h"
extern O04ModeF60 *D_800E4F60;
extern char *D_800D7500;
extern u8 D_8011FE88[];
s32 func_0042B474(s32 a);
s32 func_0042B398(s32 a, s32 b);
void func_0028D35C(void *a, s32 b, char *buf, s32 c);
char *func_002A1494(char *s);
void func_002A125C(char *dst, char *src);
void func_0042B1C0(void) {
    char buf[0x40];
    if (D_800E4F60->unk438 == 0) {
        func_002A125C(D_800E4F60->unk3F4, D_800D7500);
    } else {
        func_0028D35C(D_8011FE88, func_0042B398(func_0042B474(D_800E4F60->unk434), D_800E4F60->unk438), buf, 0x3F);
        func_002A125C(D_800E4F60->unk3F4, func_002A1494(buf));
    }
    D_800E4F60->unk3EC->unk38 = D_800E4F60->unk3F4;
}
