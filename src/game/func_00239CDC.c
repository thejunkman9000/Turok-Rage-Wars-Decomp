#include "b08_types.h"

typedef struct Node4 {
    s32 pad0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Node4;

void func_00239CDC(Node4 *n) {
    n->unk4 = 0;
    n->unk8 = 0;
    n->unkC = 0;
    n->unk10 = 0;
}
