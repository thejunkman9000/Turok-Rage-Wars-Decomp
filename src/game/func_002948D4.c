#include "b21_types.h"

extern s32 D_800D29D0;
extern s32 D_8010F194[];
extern s32 D_80146958;
extern f32 D_800CA5C8;
extern f32 D_80146D74;
void func_00293A04(B21Game *g, s32 a, s32 b);

void func_002948D4(B21Game *g) {
    if (D_800D29D0 != 0) {
        func_00293A04(g, 1, 1);
    } else if (D_8010F194[0] & 0x1000) {
        if (D_80146958 == 0) {
            D_80146958 = 1;
            D_8010F194[0] = 0;
            D_80146D74 = D_800CA5C8;
        }
    }
}
