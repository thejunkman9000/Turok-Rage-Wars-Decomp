#include "b17_types.h"

extern s32 D_8011FE88;
void func_0028D8E8(void);
void func_402FB4(s32 a, ActorX *b);

void func_00279074(ActorX *a) {
    if (D_8011FE88 == 4) {
        func_0028D8E8();
        func_402FB4(0, a);
    }
}
