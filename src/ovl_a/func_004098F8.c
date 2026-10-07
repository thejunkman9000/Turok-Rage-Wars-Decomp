#include "o01_types.h"

extern u8 *D_8011FECC;
extern u8 D_800E0D90[];
void func_002538A8(s32 a);
void func_002537D8(s32 a, s32 b);
s32 *func_002533DC(s32 a, s32 b, s32 c, void *d);
void *memset(void *p, s32 c, u32 n);

void func_004098F8(s32 *slot, u8 **out, s32 a) {
    s32 size;
    s32 *r;
    u8 *p;
    if (*slot != 0) {
        func_002538A8(0);
        func_002537D8(0, *slot);
    }
    if (a != 0) {
        size = a << 8;
    } else {
        size = (s32)D_8011FECC + 0x610;
    }
    r = func_002533DC(0, size, 0x33, D_800E0D90);
    *slot = (s32)r;
    p = (u8 *)*r;
    *out = p;
    memset(p, 0, size);
}
