#include "o05_types.h"

typedef struct { u8 pad[0x14]; s32 f14; void *f18; char buf[1]; } O05M94;
typedef struct { u8 pad[0x38]; void *f38; } O05Wd;
extern O05M94 *D_800E5694;
extern s32 D_800D74EC;
void func_0029A73C(void);
void func_00436BC8(s32 i);
void func_00436AD8(s32 i);
void func_002A1C08(void *buf, s32 fmt, s32 n);

s32 func_004373A4(s32 a, s32 b, s32 c, s32 ev) {
    func_0029A73C();
    if (ev != 1) {
        return 0;
    }
    func_00436BC8(D_800E5694->f14);
    D_800E5694->f14--;
    if (D_800E5694->f14 < 0) {
        D_800E5694->f14 = 3;
    }
    func_00436AD8(D_800E5694->f14);
    func_002A1C08(D_800E5694->buf, D_800D74EC, D_800E5694->f14 + 1);
    ((O05Wd *)D_800E5694->f18)->f38 = D_800E5694->buf;

    return 0;
}
