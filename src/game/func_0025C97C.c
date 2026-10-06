#include "p3_types.h"

typedef struct {
    u8 pad0[8];
    s32 handle;            /* 0x08 */
    s32 id;                /* 0x0C */
    P3Vec3 pos;            /* 0x10 */
    s32 arg;               /* 0x1C */
} P3SNode;

typedef struct {
    P3SNode *first;        /* 0x00 */
    u8 pad04[0x14 - 4];
    u8 list2[0x14];        /* 0x14 */
} P3SList;

extern s32 D_800D0D50;
void func_00255E78(P3SList *l, P3SNode *n);
void func_00255CB4(void *list, P3SNode *n);
s32 func_0025DE74(s16 id, P3Vec3 pos, s32 a, s32 b);

P3SNode *func_0025C97C(P3SList *l, s32 id, P3Vec3 *pos, s32 a, s32 b) {
    P3SNode *n = l->first;
    if (n != NULL) {
        func_00255E78(l, n);
        func_00255CB4(l->list2, n);
        n->id = -1;
        n->handle = -1;
        n->handle = func_0025DE74(id, *pos, a, b);
        D_800D0D50 = n->handle;
        n->id = id;
        n->pos = *pos;
        n->arg = a;
    }
    return n;
}
