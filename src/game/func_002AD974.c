#include "b24_types.h"

typedef struct Row18 {
    s32 pad0;
    s16 id;
    u8 pad6[18];
} Row18;

extern Row18 D_800D32A8[];

Row18 *func_002AD974(s32 id) {
    s32 i;
    Row18 *p = D_800D32A8;
    for (i = 7; i != -1; i--) {
        if (p->id == id) {
            return p;
        }
        p++;
    }
    return NULL;
}
