#ifndef MENU_SCREEN_SETUP_H
#define MENU_SCREEN_SETUP_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043962C.h"
/* Native model calls copy three 32-bit words by value. The float view
 * preserves the actual coordinate bits through that owning word contract. */
typedef union SetupModelVector { Vec3 value; Triple words; } SetupModelVector;
/* Five retained model records start at +8, with native stride 0xC0. */
typedef union SetupScreenModel {
    State_func_80439B5C_de initial;
    struct func_802062E0_S2 rotation;
    struct Object_func_80439C30_de offset;
    u8 record[0xC0];
} SetupScreenModel;
typedef struct SetupScreen {
    void *window;
    s32 field4;
    SetupScreenModel models[5];
    void *list;
    MenuWidget *left;
    s32 leftCount;
    MenuWidget *right;
    s32 rightCount;
    s32 unk3DC;
    s32 unk3E0;
    void *text3E4;
    MenuWidget *unk3E8;
    MenuWidget *label;
    MenuWidget *unk3F0;
    char text[0x40];
    s32 category;
    s32 selection;
    MenuWidget *item;
    MenuWidget *unk440;
    MenuWidget *unk444;
    MenuWidget *unk448;
    MenuWidget *unk44C;
    MenuWidget *unk450;
    MenuWidget *unk454;
    MenuWidget *unk458;
    s32 unk45C;
    s32 unk460;
    s32 unk464;
    s32 unk468;
    s32 unk46C;
} SetupScreen;
extern SetupScreen *D_800E4F60;
extern ListScreenRecord D_80146398[];
/* The prior selection and pending-state words are one real two-word array. */
extern s32 D_80154020[2];
/* Actual loads in the US-rev1 constructor; not guessed constants. */
extern f32 D_800E1AA0, D_800E1AA4, D_800E1AA8, D_800E1AAC;
extern f32 D_800E1AB0, D_800E1AB4, D_800E1AB8;
extern s32 func_80439B5C_de(State_func_80439B5C_de *, s32, Triple, Triple);
extern void func_80439BE0_de(struct func_802062E0_S2 *, Triple);
extern void func_80439C30_de(struct Object_func_80439C30_de *, Triple);
#endif
