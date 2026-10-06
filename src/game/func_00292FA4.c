#include "p4_types.h"
extern u8 D_800EBC80[];
extern OSThread D_8011F880;
extern u8 D_800F3C80[];
extern s32 D_800D2B24;
extern s32 D_800D2B10;
void *memset(void *p, s32 c, u32 n);
void func_00293518(void *arg);
typedef struct { u8 pad[0x26DC8]; s32 f26DC8; } P4ThrOwner;
void func_00292FA4(P4ThrOwner *a, void *arg) {
    memset(D_800EBC80, 1, 0x8000);
    osCreateThread(&D_8011F880, 1, func_00293518, arg, D_800F3C80, D_800D2B24);
    osStartThread(&D_8011F880);
    a->f26DC8 = 0;
    osSetThreadPri(NULL, D_800D2B10);
    for (;;) {}
}
