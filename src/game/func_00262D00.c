#include "b14_types.h"
typedef struct B14Ent3 B14Ent3;
struct B14Ent3 {
    /* 0x000 */ u8 pad0[0x2F0];
    /* 0x2F0 */ s32 *counter;
};
typedef struct {
    /* 0x0000 */ u8 pad0[0x5F00];
    /* 0x5F00 */ B14Ent3 *freeHead;
    /* 0x5F04 */ u8 pad5F04[0x10];
    /* 0x5F14 */ u8 usedList[0x10];
    /* 0x5F24 */ u32 freeCount;
} B14World2;
extern s32 D_800D29B4;
extern s32 D_800D2B40;
extern s32 D_8013B290;
extern u8 D_8011FE88[];
s32 func_0028B1F8(void *p, s32 id);
s32 func_0028B238(void *p, s32 id);
void func_00255E78(void *list, void *e);
void func_00255C58(void *list, void *e);
void func_00246690(B14Ent3 *e, s32 id, s32 x, s32 d, s32 a, s32 m1, s32 b, f32 f, B14W3 w1, s32 flags, B14W3 w2, B14W3 w3, s32 z);
void func_0024B2C0(B14Ent3 *e);
B14Ent3 *func_00262D00(B14World2 *w, s32 id, s32 x, s32 a3, s32 a4, B14W3 w5, f32 f8, B14W3 w9, B14W3 w12, s32 *counter) {
    B14Ent3 *e;
    if (D_800D29B4 != 0 && a3 != 0) {
        if (id == -1) {
            id = func_0028B1F8(D_8011FE88, x);
            if (id == -1) {
                return NULL;
            }
        }
        if ((u32)(x + 1) < 2) {
            x = func_0028B238(D_8011FE88, id);
        }
        if (D_8013B290 != 0 || (e = NULL, w->freeCount < 3)) {
            e = w->freeHead;
            if (e != NULL) {
                func_00255E78(&w->freeHead, e);
                func_00255C58(w->usedList, e);
                e->counter = counter;
                if (counter != NULL) {
                    *counter += 1;
                }
            }
        }
        if (e != NULL) {
            func_00246690(e, id, x, D_800D2B40, a3, -1, a4, f8, w5, 0x80000, w12, w9, 0);
            func_0024B2C0(e);
            return e;
        }
    }
    return NULL;
}
