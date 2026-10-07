#include "b14_types.h"
typedef struct { u8 pad[0xCC]; s32 fCC; u8 pad2[0x224 - 0xD0]; } B14Slot;
extern B14Slot D_8010F328[];
extern s32 D_8010FC18[];
extern u8 D_8010EC90[];
extern s32 D_800D0E58;
void func_00264268(B14Slot *s);
void func_00285D00(void *p);
void func_002648E8(void) {
    s32 i;
    s32 j;
    B14Slot *s;
    for (i = 0; i < 4; i++) {
        D_8010FC18[i] = D_8010F328[i].fCC;
    }
    func_00285D00(D_8010EC90);
    for (j = 0, s = D_8010F328; j < 4; j++, s++) {
        func_00264268(s);
    }
    D_800D0E58 = 1;
}
