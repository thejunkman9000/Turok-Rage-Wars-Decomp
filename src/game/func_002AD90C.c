#include "b24_types.h"

typedef struct Row18 {
    s32 pad0;
    s16 id;
    u8 pad6[18];
} Row18;

extern Row18 D_800D31D0[];

Row18 *func_002AD90C(s32 id) {
    s32 i;
    Row18 *p = D_800D31D0;
    for (i = 3; i != -1; i--) {
        if (p->id == id) {
            return p;
        }
        p++;
    }
    return NULL;
}
