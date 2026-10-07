#include "o03_types.h"
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } O3Z;
void func_002A338C(void);
void func_0042201C(O3Z *o, s32 v) {
    o->f4 = 0;
    o->f0 = 0;
    o->f8 = 0;
    o->fC = v;
    o->f10 = 1;
    func_002A338C();
}
