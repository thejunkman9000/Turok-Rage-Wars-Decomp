#include "b23_types.h"
u8 *func_002A66B4(EntPool *p, s32 n) {
    u8 *r;
    if (p->cnt < n) {
        return 0;
    }
    r = p->cur;
    p->cnt -= n;
    p->cur += n * 16;
    return r;

}
