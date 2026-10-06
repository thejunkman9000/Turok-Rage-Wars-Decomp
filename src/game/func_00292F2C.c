#include "b21_types.h"

extern u8 D_800EBC00[];
extern OSThread D_8011F650;
extern OSPri D_800D2B14;
void func_002934F0(void *arg);

void func_00292F2C(B21Game *g) {
    memset(D_800EBC00, 0, 0x80);
    osCreateThread(&D_8011F650, 0, func_002934F0, 0, D_800EBC00 + 0x80, D_800D2B14);
    osStartThread(&D_8011F650);
}
