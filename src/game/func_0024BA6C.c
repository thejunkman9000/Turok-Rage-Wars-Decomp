
#include "p2_types.h"
#include "m03_types.h"

typedef struct M03BaVec { u8 pad0[8]; u8 *p8; u8 pad0C[4]; s32 f10; } M03BaVec;

extern M03Dl *D_80110634;
extern s32 D_800D297C;
extern u8 D_8011FFB0[];
s32 func_00279A30(void *, s32);
void func_0026F908(void *, s32, s32);
void func_00272898(void *);
void func_0026FD0C(void *, s32);
void func_0026C6D8(s32, s32, s32, s32, void *, s32, s32);

void func_0024BA6C(Actor *a, M03BaVec *b, s32 m, u16 flag) {
    u8 mtx[0x40];
    s32 node;
    u8 *base;
    M03Dl *dl;
    M03Dl *dl2;
    if (a->fB4 != 0) {
        node = func_00279A30(D_8011FFB0, 1);
        if (node != 0) {
            base = b->p8;
            func_0026F908(mtx, m, (s32)base + 0x1E0);
            func_00272898(mtx);
            func_0026FD0C(mtx, node);
            dl = D_80110634++;
            dl->w0 = 0xDA380007;
            dl->w1 = node;
            func_0026C6D8(flag & 0xFF, b->f10, a->fB4, 1, &a->seg[D_800D297C], 0, a->f3);
            dl2 = D_80110634++;
            dl2->w0 = 0xDA380007;
            dl2->w1 = (u32)(base + ((D_800D297C << 6) + 0x380));
        }
    }
}
