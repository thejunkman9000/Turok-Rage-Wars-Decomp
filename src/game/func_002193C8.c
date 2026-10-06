#include "b04_types.h"
extern u8 D_8011FE88[];
s32 func_0028D268(u8 *);
typedef struct { u8 unk0; u8 unk1; s16 unk2; s16 unk4; } B04Ev;
void func_002193C8(B04Ev *e, s32 a) {
    e->unk0 = 1;
    e->unk1 = a;
    e->unk2 = func_0028D268(D_8011FE88);
    e->unk4 = 0;
}
