#include "b01_types.h"

extern s32 D_800CD4C0;
extern u8 D_8011FE88[];
s32 func_00285F28(void *mgr, B01Actor *actor);
void func_00214178(B01Actor *actor, B01State *state, s32 event);

void func_002044C8(B01Actor *actor, B01State *state) {
    if (func_00285F28(D_8011FE88, actor) == 1) {
        func_00214178(actor, state, 1);
        switch (actor->unkE4) {
        case 0x64C:
            actor->flags &= ~0x2000;
            actor->flags &= ~0x100;
            break;
        case 0x64B:
        case 0x64E:
            actor->flags &= 0xF7FFFFFF;
            break;
        }
    } else {
        D_800CD4C0 = 1;
        func_00214178(actor, state, 0);
        D_800CD4C0 = 0;
    }
}
