#include "b24_types.h"

typedef struct Row14 {
    s32 pad0;
    s16 id;
    u8 pad6[14];
} Row14;

extern Row14 D_800D3230[];

Row14 *func_002AD940(s32 id) {
    s32 i;
    Row14 *p = D_800D3230;
    for (i = 5; i != -1; i--) {
        if (p->id == id) {
            return p;
        }
        p++;
    }
    return NULL;
}
