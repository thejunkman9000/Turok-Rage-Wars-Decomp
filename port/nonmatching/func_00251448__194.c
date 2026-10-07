#include "b12_types.h"

extern s32 D_8010513C;
extern B12Node **D_80104564;
extern u32 D_80105180;
extern u8 D_80104570[];
s32 func_002512C8(s32 a, s32 b, s32 c);
void func_00255C58(void *list, B12Node *n);

B12Node *func_00251448(s32 unused, u32 flags) {
    B12Node *n;
    u32 f;
    if (D_8010513C == 0) {
        n = 0;
    } else {
        n = D_80104564[--D_8010513C];
        n->flags = 0x800;
        n->refs = 0;
        n->key = 0;
        n->next = 0;
        n->prev = 0;
        n->link = 0;
        n->unk10 = D_80105180;
        func_00255C58(D_80104570, n);
        n->flags |= flags & 0xC;
    }
    if (!n) {
        f = flags & 0x10;
        if (func_002512C8(0, 2, f == 0)) {
            if (D_8010513C != 0) {
                n = D_80104564[--D_8010513C];
                n->flags = 0x800;
                n->refs = 0;
                n->key = 0;
                n->next = 0;
                n->prev = 0;
                n->link = 0;
                n->unk10 = D_80105180;
                func_00255C58(D_80104570, n);
                n->flags |= flags & 0xC;
            }
        }
    }
    return n;
}
