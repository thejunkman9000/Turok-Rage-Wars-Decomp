#include "b14_types.h"
typedef struct { u8 pad[0xCC]; s32 fCC; u8 pad2[0x224 - 0xD0]; } B14Slot;
extern s32 D_800D0E58;
extern B14Slot D_8010F328[];
extern s32 D_8010FC18[];
extern u8 D_8010EC90[];
void func_00264268(B14Slot *s);
void func_00285D00(void *p);
void func_0026497C(void) {
    s32 i;
    s32 j;
    B14Slot *s;
    if (D_800D0E58 != 0) {
        for (i = 0, s = D_8010F328; i < 4; i++, s++) {
            func_00264268(s);
        }
        for (j = 0; j < 4; j++) {
            D_8010F328[j].fCC = D_8010FC18[j];
        }
        func_00285D00(D_8010EC90);
        D_800D0E58 = 0;
    }
}
