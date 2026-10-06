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
    u8 pad24[0x11DC];
    s32 unk1200;
} PList;

void func_002725BC(void *p, f32 f);
void func_00271FD8(Vec3f *out, void *a, void *b);

extern f32 D_800C8638;

void *func_00239594(PList *l, void *pt) {
    Vec3f v;
    PNode *n;
    PNode *best;
    f32 min;
    f32 d;

    func_002725BC(pt, 20000.0f);
    if (l->unk1200 == 0) {
        min = D_800C8638;
        best = NULL;
        for (n = l->head; n != NULL; n = n->next) {
            func_00271FD8(&v, pt, &n->pos);
            d = v.x * v.x + v.y * v.y + v.z * v.z;
            if (d < min) {
                best = n;
                min = d;
            }
        }
        if (best == NULL) {
            return (u8 *)l + 0x40;
        }
        return best;
    }
    return (u8 *)l + 0x40;
}
