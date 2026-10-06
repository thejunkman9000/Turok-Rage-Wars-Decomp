#include "b15_types.h"

f32 func_0024BECC(SndSrc *src);
extern f32 D_800C9510;

f32 func_002672E8(SndSrc *src) {
    if (src->type == 1) {
        return func_0024BECC(src);
    }
    return D_800C9510;
}
