#include "o04_types.h"
typedef struct { u16 unk0; u16 unk2; } O04U16s;
extern u8 D_801462D5;
extern s32 D_8015402C;
extern u8 D_8011FE88[];
O04U16s *func_0028D450(void *a, s32 b);
s32 func_0042F014(void) {
    s32 v;
    if (D_801462D5 == 1) {
        v = func_0028D450(D_8011FE88, D_8015402C)->unk2;
    } else {
        v = D_8015402C;
    }
    if (D_8015402C) {
        return v * 10 + 0xBC2;
    } else {
        return v * 10 + 0xBC2;
    }
}
