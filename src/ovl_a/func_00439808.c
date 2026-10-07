#include "o05_types.h"

typedef struct { u8 pad[0x10]; u8 b10; } O05Obj10;
typedef struct { O05Obj10 *f0; s32 f4; } O05M50;
extern s32 D_800E28E0;
extern O05M50 *D_800E5950;
void func_002A3358(void);
f32 cosf(f32 x);

s32 func_00439808(s32 a, s32 b, s32 c) {
    f32 x;
    if (D_800E28E0 >= 2) {
        return 0;
    }
    func_002A3358();
    D_800E5950->f4 += c;
    x = cosf((f32)D_800E5950->f4 * 0.005f) * 100.0f + 150.0f;
    D_800E5950->f0->b10 = (u32)x;
    return 0;
}
