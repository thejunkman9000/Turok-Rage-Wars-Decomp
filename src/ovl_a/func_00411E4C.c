#include "o02_types.h"
typedef struct { u8 pad[8]; void *p; } S_func_00411E4C;
extern S_func_00411E4C *D_80153C44;
void *func_00411E4C(s32 i) {
    return D_80153C44[i].p;
}
