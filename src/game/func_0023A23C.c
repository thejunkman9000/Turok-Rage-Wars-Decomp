#include "b08_types.h"

void func_002538A8(s32 a);
void func_002537D8(s32 a, s32 b);

void func_0023A23C(u8 *o) {
    func_002538A8(0);
    if (*(s32 *)(o + 0xF18) != 0) {
        func_002537D8(0, *(s32 *)(o + 0xF18));
        *(s32 *)(o + 0xF18) = 0;
        *(s32 *)(o + 0xF1C) = 0;
        *(s32 *)(o + 0xF20) = 0;
    }
}
