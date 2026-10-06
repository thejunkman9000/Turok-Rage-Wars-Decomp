#include "b14_types.h"
typedef struct {
    /* 0x000 */ u8 pad0[0x174];
    /* 0x174 */ s32 f174;
    /* 0x178 */ u8 pad178[0x178];
    /* 0x2F0 */ s32 *f2F0;
} B14Obj;
extern u8 D_8013B124[];
extern u8 D_8013B110[];
void func_00255E78(void *list, B14Obj *o);
void func_00255CB4(void *list, B14Obj *o);
void func_00262CA8(B14Obj *o) {
    s32 *p = o->f2F0;
    o->f174 = 0;
    if (p != NULL) {
        *p -= 1;
    }
    func_00255E78(D_8013B124, o);
    func_00255CB4(D_8013B110, o);
}
