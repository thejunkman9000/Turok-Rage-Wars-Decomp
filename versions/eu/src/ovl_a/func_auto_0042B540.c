#include "o04_types.h"
typedef struct { u16 a; u16 b; } O04HW;
extern O04ModeF60 *D_800E4F60;
extern O04HW D_800E51E4[];
extern O04HW D_800E51F8[];
extern O04HW D_800E5214[];
extern O04HW D_800E5240[];
extern char *D_auto_800E1DA4[];
extern u8 D_auto_80152789;
extern u8 D_8011FE88[];
void *func_0040ECB0(void *a, s32 b);
s32 func_0042B474(s32 a);
s32 func_0042B398(s32 a, s32 b);
void func_0028D35C(void *a, s32 b, char *buf, s32 c);
char *func_002A1494(char *s);
void func_002A125C(char *dst, char *src);
void func_00245B18(void);
void func_auto_0042B540(void) {
    char buf[0x40];
    char *s;
    O04HW *tbl;
    switch (D_800E4F60->unk434) {
    case 3:
        tbl = D_800E51E4;
        break;
    case 2:
        tbl = D_800E51F8;
        break;
    case 1:
        tbl = D_800E5214;
        break;
    case 0:
        tbl = D_800E5240;
        break;
    default:
        return;
    }
    D_800E4F60->unk43C = func_0040ECB0(D_800E4F60->unk0, tbl[D_800E4F60->unk438].b);
    if (D_800E4F60->unk438 == 0) {
        func_002A125C(D_800E4F60->unk3F4, D_auto_800E1DA4[D_auto_80152789]);
    } else {
        func_0028D35C(D_8011FE88, func_0042B398(func_0042B474(D_800E4F60->unk434), D_800E4F60->unk438), buf, 0x3F);
        func_002A125C(D_800E4F60->unk3F4, func_002A1494(buf));
    }
    D_800E4F60->unk3EC->unk38 = D_800E4F60->unk3F4;
    func_00245B18();
}
