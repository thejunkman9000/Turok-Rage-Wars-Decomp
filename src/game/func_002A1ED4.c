#include "b23_types.h"
extern s32 (*D_800D2B9C)(s32 fp, void *buf, s32 n);
s32 func_002A1ED4(void *buf, s32 size, s32 n, s32 fp) {
    s32 total = size * n;
    if (total == 0) {
        return 0;
    }
    return D_800D2B9C(fp, buf, total) / size;

}
