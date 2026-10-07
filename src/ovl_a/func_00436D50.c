#include "o05_types.h"

typedef struct { void *f0; u8 pad[0x1C]; s32 f20; } O05M90;
extern O05M90 *D_800E5690;
s32 func_0041A4F0(void *w);
void func_0029A73C(void);
void func_00299368(s32 a);
void func_0029A8A8(void);

s32 func_00436D50(void) {
    s32 t = func_0041A4F0(D_800E5690->f0);
    if (t != 3) {
        if (t == 4) {
            func_0029A73C();
            if (D_800E5690->f20 != -1) {
                func_00299368(D_800E5690->f20);
            } else {
                func_0029A8A8();
            }
        }
    }
    return 0;
}
