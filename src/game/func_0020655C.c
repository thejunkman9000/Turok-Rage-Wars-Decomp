#include "p1_types.h"
extern Actor *D_8013B124;
extern u8 D_80145040[];
s32 func_0022A8E0(void *p);
s32 func_0020655C(s32 id) {
    Actor *a;
    if (id == 0x84F) {
        for (a = D_8013B124; a != NULL; a = a->next2EC) {
            if (a->def->type == 4) {
                return 0;
            }
        }
        return func_0022A8E0(D_80145040) == 0;
    }
    return 1;
}
