#include "b08_types.h"

typedef struct PNode PNode;
struct PNode {
    u8 pad0[4];
    PNode *next;
    u8 pad8[0x120];
    Vec3f pos;
};

typedef struct PList {
    u8 pad0[0x20];
    PNode *head;
    u8 pad24[0xC];
    u32 count;
} PList;

void func_00271FD8(Vec3f *out, void *a, void *b);

f32 func_00239668(PList *l, void *pt) {
    Vec3f v;
    PNode *n;
    f32 sum;

    if (l->count == 0) {
        return 0.0f;
    }
    sum = 0.0f;
    for (n = l->head; n != NULL; n = n->next) {
        func_00271FD8(&v, &n->pos, pt);
        sum += b08_sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    }
    return sum / (f32)l->count;
}
