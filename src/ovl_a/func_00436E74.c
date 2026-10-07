#include "o05_types.h"

typedef struct { void *f0; u8 pad[0x24]; s32 f28; void *f2C; char buf[1]; } O05M90;
typedef struct { u8 pad[0x38]; void *f38; } O05Wd;
extern O05M90 *D_800E5690;
extern s32 D_800D74EC;
void func_0029A73C(void);
void func_00436988(s32 i);
void func_00436898(s32 i);
void func_002A1C08(void *buf, s32 fmt, s32 n);
void func_0025DF54(s32 a);

s32 func_00436E74(s32 a, s32 b, s32 c, s32 ev) {
    func_0029A73C();
    if (ev != 1) {
        return 0;
    }
    func_00436988(D_800E5690->f28);
    D_800E5690->f28++;
    if (D_800E5690->f28 >= 4) {
        D_800E5690->f28 = 0;
    }
    func_00436898(D_800E5690->f28);
    func_002A1C08(D_800E5690->buf, D_800D74EC, D_800E5690->f28 + 1);
    ((O05Wd *)D_800E5690->f2C)->f38 = D_800E5690->buf;
    func_0025DF54(0xE81);

    return 0;
}
