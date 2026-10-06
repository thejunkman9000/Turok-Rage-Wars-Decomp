#include "b24_types.h"

typedef struct Row10 {
    s32 pad0;
    s16 id;
    u8 pad6[10];
} Row10;

extern Row10 D_800D3390[];

Row10 *func_002ADA10(s32 id) {
    s32 i;
    Row10 *p = D_800D3390;
    for (i = 2; i != -1; i--) {
        if (p->id == id) {
            return p;
        }
        p++;
    }
    return NULL;
}
