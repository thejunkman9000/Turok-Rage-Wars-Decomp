#include "o05_types.h"

typedef struct { u8 pad[0x14]; s32 f14; void *f18; char buf[1]; } O05M94;
typedef struct { u8 pad[0x38]; void *f38; } O05Wd;
extern O05M94 *D_auto_800F1CB4;
extern u8 D_auto_80152789;
extern s32 D_auto_800E1D54[];
void func_0029A73C(void);
void func_auto_00437968(s32 i);
void func_auto_00437878(s32 i);
void func_002A1C08(void *buf, s32 fmt, s32 n);

s32 func_auto_00437F2C(s32 a, s32 b, s32 c, s32 ev) {
    func_0029A73C();
    if (ev != 1) {
        return 0;
    }
    func_auto_00437968(D_auto_800F1CB4->f14);
    D_auto_800F1CB4->f14++;
    if (D_auto_800F1CB4->f14 >= 4) {
        D_auto_800F1CB4->f14 = 0;
    }
    func_auto_00437878(D_auto_800F1CB4->f14);
    func_002A1C08(D_auto_800F1CB4->buf, D_auto_800E1D54[D_auto_80152789], D_auto_800F1CB4->f14 + 1);
    ((O05Wd *)D_auto_800F1CB4->f18)->f38 = D_auto_800F1CB4->buf;

    return 0;
}
