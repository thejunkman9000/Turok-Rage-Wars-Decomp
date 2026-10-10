#include "span_16E000/menu_screen_setup.h"
#include "common/unused.h"
/* Opens the screen D_800E4F60: allocates its 0x470-byte state for the window, sets up the list,
   the left and right arrows (shifted by their width and snapped to 4 pixels), the labels and
   items of the window with their alpha and visibility, resets the selection and the counters at
   D_80154024, clears the pending flag at 0x91 of the eight D_80146398 records, places the four
   character models (ids 0xEA6 to 0xEA9, x 0, -6, -13, -19) and a fifth model 0xEA6, then issues
   request 0xE78 through func_8025DF34_de and calls func_80422170_de; returns zero. */
#include "types.h"
#include "common/types_8a8189af7b05.h"
















extern f32 D_800E1AA0;
extern f32 D_800E1AA8;
extern f32 D_800E1AB0;
extern f32 D_800E1AB8;
static inline f32 read_float(f32 *value) {
    return *value;
}

extern void *func_8025305C_de(s32 size);
extern void *func_8041B610_de(void *, s32);
extern void func_8041B6E8_de(void *, s32, s32);
extern void *func_8040EC30_de(void *, u16);
extern void func_8040E8D8_de(MenuWidget *, s32);
extern void *func_80419E54_de(s32, s32);
extern void func_802A2394_de(void);




extern void func_8025DF34_de(s32);

s32 func_80429A24_de(void *window) {
    SetupModelVector scale;
    SetupModelVector position;
    SetupModelVector rotation;
    SetupModelVector offset;
    MenuWidget *item1, *item2, *item3, *item4, *item5, *item6, *item7, *item8;
    MenuWidget *opacityItem;
    f32 z;
    ListScreenRecord *record;
    s32 *counter;
    s32 i;
    s32 x;
    s32 id;

    D_800E4F60 = func_8025305C_de(sizeof(SetupScreen));
    D_800E4F60->window = window;
    D_800E4F60->list = func_8041B610_de(window, 4);
    func_8041B6E8_de(window, 0, 0x2FF);
    func_8041B6E8_de(window, 1, 0x2FF);
    func_8041B6E8_de(window, 2, 0x2FF);
    func_8041B6E8_de(window, 3, 0x2FF);
    D_800E4F60->unk3DC = 1;
    D_800E4F60->unk45C = 0;
    D_800E4F60->unk3E0 = 4;

    item1 = func_8040EC30_de(window, 0x306);
    D_800E4F60->left = item1;
    item1->x -= item1->width;
    D_800E4F60->leftCount = D_800E4F60->left->width / 4;
    x = D_800E4F60->left->width - D_800E4F60->leftCount * 4;
    D_800E4F60->left->x += x;

    item2 = func_8040EC30_de(window, 0x30F);
    D_800E4F60->right = item2;
    item2->x += item2->width;
    D_800E4F60->rightCount = D_800E4F60->right->width / 4;
    x = D_800E4F60->right->width - D_800E4F60->rightCount * 4;
    D_800E4F60->right->x -= x;

    opacityItem = func_8040EC30_de(window, 0x30A);
    opacityItem->alpha = 0x6E;
    item3 = func_8040EC30_de(window, 0x35D);
    D_800E4F60->unk448 = item3;
    item3->alpha = 0x41;
    func_8040E8D8_de(D_800E4F60->unk448, 0);
    D_800E4F60->text3E4 = func_80419E54_de(0x303, 0x6E);
    item4 = func_8040EC30_de(window, 0x301);
    D_800E4F60->unk3E8 = item4;
    func_8040E8D8_de(item4, 0);
    D_800E4F60->label = func_8040EC30_de(window, 0x30E);
    D_800E4F60->unk3F0 = func_8040EC30_de(window, 0x310);
    func_8042B080_de();
    D_800E4F60->selection = 0;
    D_800E4F60->category = 0;
    func_8042A990_de();
    func_8042AFE0_de();
    counter = &D_80154020[1];
    *counter = 0;
    counter[-1] = -1;
    D_800E4F60->unk454 = func_8040EC30_de(window, 0x308);
    opacityItem = func_8040EC30_de(window, 0x309);
    opacityItem->alpha = 0x6E;
    D_800E4F60->unk46C = 0;
    item5 = func_8040EC30_de(window, 0x30B);
    D_800E4F60->unk440 = item5;
    item5->alpha = 0x8C;
    func_8040E8D8_de(D_800E4F60->unk440, 1);
    item6 = func_8040EC30_de(window, 0x30D);
    D_800E4F60->unk444 = item6;
    item6->alpha = 0x8C;
    func_8040E8D8_de(D_800E4F60->unk444, 0);
    item7 = func_8040EC30_de(window, 0x30C);
    D_800E4F60->unk44C = item7;
    item7->alpha = 0xFF;
    D_800E4F60->unk450 = func_8040EC30_de(window, 0x2FE);
    item8 = func_8040EC30_de(window, 0x300);
    D_800E4F60->unk458 = item8;
    func_8040E8D8_de(item8, 1);
    func_802A2394_de();
    D_800E4F60->unk460 = 0;
    D_800E4F60->unk464 = 0;
    D_800E4F60->unk468 = -1;

    for (i = 0; i < 8; i++) {
        record = &D_80146398[i];
        if (record->out == 1) {
            record->active = 0;
            record->out = 0;
        }
    }
    func_802A23C4_de(1);

    x = 0;
    id = 0;
    scale.value.x = D_800E1AA0;
    scale.value.y = D_800E1AA0;
    scale.value.z = D_800E1AA0;
    rotation.value.x = 0.0f;
    rotation.value.y = 0.0f;
    rotation.value.z = 0.0f;
    offset.value.x = 0.0f;
    offset.value.y = D_800E1AA4;
    offset.value.z = 0.0f;
    for (i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            x = 0;
            id = 0xEA6;
            break;
        case 1:
            x = -6;
            id = 0xEA7;
            break;
        case 2:
            x = -13;
            id = 0xEA8;
            break;
        case 3:
            x = -19;
            id = 0xEA9;
            break;
        }
        position.value.x = x;
        position.value.y = read_float(&D_800E1AA8);
        z = D_800E1AAC;
        position.value.z = z;
        func_80439B5C_de(&D_800E4F60->models[i].initial, id, scale.words, position.words);
        func_80439BE0_de(&D_800E4F60->models[i].rotation, rotation.words);
        func_80439C30_de(&D_800E4F60->models[i].offset, offset.words);
    }
    scale.value.x = D_800E1AB0;
    scale.value.y = D_800E1AB0;
    scale.value.z = D_800E1AB0;
    position.value.z = z;
    position.value.x = D_800E1AB4;
    position.value.y = D_800E1AB8;
    func_80439B5C_de(&D_800E4F60->models[4].initial, 0xEA6, scale.words, position.words);
    func_80439BE0_de(&D_800E4F60->models[4].rotation, rotation.words);
    func_80439C30_de(&D_800E4F60->models[4].offset, offset.words);
    func_8025DF34_de(0xE78);
    func_80422170_de();
    return 0;
}

