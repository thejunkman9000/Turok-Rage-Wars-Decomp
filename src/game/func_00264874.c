#include "b14_types.h"
typedef struct { u8 pad[0xCC]; s32 fCC; u8 pad2[0x224 - 0xD0]; } B14Slot;
extern B14Slot D_8010F328[];
extern u8 D_8010EC90[];
void func_00264268(B14Slot *s);
void func_00285D00(void *p);


void func_00264874(s32 v) {
B14Slot *s;
    s32 i;
    for (i = 0, s = D_8010F328; i < 4; i++, s++) {
        s->fCC = v;
        if (v == 0) {
            func_00264268(s);
        }
    }
    if (v == 0) {
        func_00285D00(D_8010EC90);
    }
}
