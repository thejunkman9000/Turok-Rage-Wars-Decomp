#include "b12_types.h"

extern OSMesgQueue D_801047E0;

void func_00253C8C(s32 unused, OSMesg msg) {
    osSendMesg(&D_801047E0, msg, 1);
}
