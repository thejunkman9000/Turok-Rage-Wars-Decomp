#include "b14_types.h"
extern s32 D_800D0E5C;
extern OSMesgQueue D_8010FBC0;
void func_0026456C(void) {
    D_800D0E5C = -1;
    osSendMesg(&D_8010FBC0, 0, 1);
}
