#include "o05_types.h"

typedef struct { u8 pad[0x28]; s32 f28; void *f2C; char buf[1]; } O05M90;
typedef struct { u8 pad[0x38]; void *f38; } O05Wd;
extern O05M90 *D_auto_800F1CB0;
extern u8 D_auto_80152789;
extern s32 D_auto_800E1D54[];
void func_0029A73C(void);
void func_auto_0043753C(s32 i);
void func_auto_0043744C(s32 i);
void func_002A1C08(void *buf, s32 fmt, s32 n);
void func_0025DF54(s32 a);

s32 func_auto_00437CDC(s32 a, s32 b, s32 c, s32 ev) {
    func_0029A73C();
    if (ev != 1) {
        return 0;
    }
    func_auto_0043753C(D_auto_800F1CB0->f28);
    D_auto_800F1CB0->f28--;
    if (D_auto_800F1CB0->f28 < 0) {
        D_auto_800F1CB0->f28 = 3;
    }
    func_auto_0043744C(D_auto_800F1CB0->f28);
    func_002A1C08(D_auto_800F1CB0->buf, D_auto_800E1D54[D_auto_80152789], D_auto_800F1CB0->f28 + 1);
    ((O05Wd *)D_auto_800F1CB0->f2C)->f38 = D_auto_800F1CB0->buf;
    func_0025DF54(0xE81);

    return 0;
}
