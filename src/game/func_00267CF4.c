#include "b15_types.h"

typedef struct B15Node B15Node;
struct B15Node {
    s32 unk0;
    B15Node *next;
};

s32 func_0023939C(B15Node *n, Vec3f pos);
void func_0023919C(B15Node *n, u8 a, u8 b, u8 c, u8 d, u8 e, u8 f, u8 g);
extern B15Node *D_801450A8;

void func_00267CF4(s32 a, s32 b, s32 c, Vec3f pos, B15Bytes7 col) {
    B15Node *n;

    for (n = D_801450A8; n != NULL; n = n->next) {
        if (func_0023939C(n, pos)) {
            func_0023919C(n, col.c[0], col.c[1], col.c[2], col.c[3], col.c[4], col.c[5], col.c[6]);
        }
    }
}
