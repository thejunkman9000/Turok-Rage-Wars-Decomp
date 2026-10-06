#include "b04_types.h"
extern u8 D_8011FE88[];
void func_0028D220(u8 *, s32, s32);
typedef struct { u8 unk0; u8 unk1; s16 unk2; } B04Ev;
void func_00219408(B04Ev *e) {
    func_0028D220(D_8011FE88, e->unk1, e->unk2);
}
