#include "b06_types.h"

void func_00226DAC(u8 *a, f32 *out);
void func_00273340(f32 *a, s32 b);

void func_0022B134(u8 *a, s32 b) {
    f32 buf[16];
    func_00226DAC(a, buf);
    func_00273340(buf, b);
}
