#include "b24_types.h"

extern u32 D_8014D3D0;
extern f32 D_800CB3A4;
extern f32 D_800CB3A8;
extern f32 D_800CB3AC;
extern f32 D_800CB3B0;
extern f32 D_800CB3B4;
extern f32 D_800CB3B8;

f32 func_002AB854(void) {
    switch (D_8014D3D0) {
    case 0:
        return D_800CB3A4;
    case 1:
        return D_800CB3A8;
    case 2:
        return D_800CB3AC;
    case 3:
        return D_800CB3B0;
    case 4:
        return D_800CB3B4;
    case 5:
    case 6:
    default:
        return D_800CB3B8;
    }
}
