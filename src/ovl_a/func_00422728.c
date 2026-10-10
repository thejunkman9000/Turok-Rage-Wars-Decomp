#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "span_16E000/code_8041A4B0.h"
#include "types.h"
#include "types.h"
#include "common/types_1dc8418c21db.h"
typedef struct Shared_OptionsScreen Shared_OptionsScreen;
struct Shared_OptionsScreen {
    u32 unknown00[7];
    s32 cursor;
    MenuWidget *leftTab;
    s32 leftStep;
    MenuWidget *rightTab;
    s32 rightStep;
    s32 page;
    s32 pages;
    s32 title;
    MenuWidget *marker;
    MenuWidget *header;
    MenuWidget *footer;
    MenuWidget *pakIcon;
    MenuWidget *rumbleIcon;
    s32 slider;
    Record_func_8041ABC0_de *firstList;
    Record_func_8041ABC0_de *secondList;
    s32 state;
    s32 selection;
    s32 sound;
    MenuWidget *prompt;
};
typedef struct Shared_MenuReply Shared_MenuReply;
struct Shared_MenuReply {
    s32 value;
    s32 ready;
};
typedef struct Shared_MenuObject Shared_MenuObject;
struct Shared_MenuObject {
    u8 unknown00[0x17C1];
    u8 language;
    u8 unknown17C2[0x2E];
};
typedef struct Shared_MenuData Shared_MenuData;
struct Shared_MenuData {
    u32 unknown00[18];
    Shared_MenuObject object;
    s32 stage;
    u32 unknown183C[6];
    s32 pause;
};

#include "types.h"
#include "shared/func_80425674_de_layout.h"

/* Builds options screen state D_800E4518 for menu node arg0: allocates its 0x6C bytes, sets up the two
   sliding tabs 0x381/0x388 (centring each by a quarter of its width), the header sprites, the two text
   lists 0x375 and 0x378 and the 0x80-step slider 0x37A like func_804234CC_de, shows the pak and rumble
   markers according to the settings' controller mode, registers the remaining resources, resets the
   cursor state and returns zero. */

extern Shared_OptionsScreen *D_800E4518;
extern Shared_Game D_801462C8;

extern char *D_800D2124;
extern char *D_800D2128;
/* Three consecutive localized labels at US-rev1 800D74B4..800D74BC. */
extern char *D_800D2134[3];
extern char *D_800D2138;
extern char *D_800D213C;
extern s32 D_80146894;
extern s32 D_80154020[2];

extern Shared_OptionsScreen *func_8025305C_de(s32);
extern s32 func_8025E2C4_de(void);

extern void func_8025E384_de(void);

extern MenuWidget *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(void *, s32);
extern void func_8040E950_de(MenuWidget *, s32);
extern s32 func_80419E54_de(s32, s32);
extern void func_8041B110_de(s32);
extern Record_func_8041ABC0_de *func_8041ABC0_de(s32, s32);
extern void func_8041AD34_de(Record_func_8041ABC0_de *, char *);
extern void func_8041AD10_de(Record_func_8041ABC0_de *, s32);
extern s32 func_80265350_de(void);
extern s32 func_8041A580_de(s32, s32, s32);
extern void func_8041A6EC_de(s32, s32);
extern s32 func_8042AF28_de(void);
extern void func_804221E8_de(void);
extern void func_802A2394_de(void);
extern void func_8043C210_de(Shared_OptionsScreen *, s32, s32, s32, s32);
extern void func_8043C278_de(Shared_OptionsScreen *);

s32 func_80422728_us_rev1(void *node) {
    Shared_Game *settings;
    MenuWidget *handle;
    MenuWidget *marker;
    MenuWidget *header;
    MenuWidget *rumble;
    MenuWidget *pak;
    MenuWidget *prompt;
    Record_func_8041ABC0_de *firstListHandle;
    Record_func_8041ABC0_de *secondListHandle;
    s32 slider;
    s32 i;
    s32 rem;

    D_800E4518 = func_8025305C_de(0x6C);
    D_800E4518->sound = func_8025E2C4_de();
    func_8025E2D4_de(0x34);
    func_8025E384_de();
    func_8025E214_de(-1);
    D_800E4518->page = 1;
    D_800E4518->pages = 4;
    D_800E4518->leftTab = func_8040EC30_de(node, 0x381);
    D_800E4518->leftTab->x -= D_800E4518->leftTab->width;
    D_800E4518->leftStep = D_800E4518->leftTab->width / 4;
    rem = D_800E4518->leftTab->width - D_800E4518->leftStep * 4;
    D_800E4518->leftTab->x += rem;
    D_800E4518->rightTab = func_8040EC30_de(node, 0x388);
    D_800E4518->rightTab->x += D_800E4518->rightTab->width;
    D_800E4518->rightStep = D_800E4518->rightTab->width / 4;
    rem = D_800E4518->rightTab->width - D_800E4518->rightStep * 4;
    D_800E4518->rightTab->x -= rem;
    D_800E4518->title = func_80419E54_de(0x373, 0x6E);
    marker = func_8040EC30_de(node, 0x372);
    D_800E4518->marker = marker;
    func_8040E8D8_de(marker, 0);
    func_8040EC30_de(node, 0x386)->alpha = 0x6E;
    header = func_8040EC30_de(node, 0x387);
    D_800E4518->header = header;
    header->alpha = 0x8C;
    D_800E4518->footer = func_8040EC30_de(node, 0x370);
    rumble = func_8040EC30_de(node, 0x384);
    D_800E4518->rumbleIcon = rumble;
    func_8040E8D8_de(rumble, 1);
    func_8040EC30_de(node, 0x385)->alpha = 0x6E;
    pak = func_8040EC30_de(node, 0x374);
    D_800E4518->pakIcon = pak;
    func_8040E8D8_de(pak, 0);
    func_8041B110_de(0x377);
    func_8041B110_de(0x37C);
    firstListHandle = func_8041ABC0_de(0x375, 0x376);
    D_800E4518->firstList = firstListHandle;
    func_8041AD34_de(firstListHandle, D_800D3470_de[0]);
    func_8041AD34_de(D_800E4518->firstList, D_800D2124);
    func_8041AD34_de(D_800E4518->firstList, D_800D2128);
    settings = &D_801462C8;
    func_8041AD10_de(D_800E4518->firstList, settings->firstListMode);
    secondListHandle = func_8041ABC0_de(0x378, 0x379);
    D_800E4518->secondList = secondListHandle;
    func_8041AD34_de(secondListHandle, D_800D2134[0]);
    if (func_80265350_de() != 0x400000) {
        func_8041AD34_de(D_800E4518->secondList, D_800D2138);
        func_8041AD34_de(D_800E4518->secondList, D_800D213C);
    }
    func_8041AD10_de(D_800E4518->secondList, settings->slots[7].secondListMode);
    slider = func_8041A580_de(0x37A, 0x37B, 0x80);
    D_800E4518->slider = slider;

    func_8041A6EC_de(slider, settings->buttons);
    switch (settings->controllerMode) {
    case 0:
        if (func_8042AF28_de() == 0) {
            func_8040E950_de(func_8040EC30_de(node, 0x37E), 1);
        }
        handle = func_8040EC30_de(node, 0x380);
        func_8040E950_de(handle, 1);
        for (i = 0; i < 8; i++) {
            if (settings->slots[i].enabled == 1 && settings->slots[i].controller == 1) {
                func_8040E950_de(handle, 0);
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        func_8040E950_de(func_8040EC30_de(node, 0x380), 1);
        func_8040E950_de(func_8040EC30_de(node, 0x37E), 1);
        break;
    }
    func_8041B110_de(0x380);
    func_8041B110_de(0x37D);
    func_8041B110_de(0x37E);
    func_8041B110_de(0x37F);
    D_800E4518->state = 0;
    func_802A2394_de();
    func_8043C210_de(D_800E4518, 0x67, 0, 0, 0);
    func_8043C278_de(D_800E4518);
    D_800E4518->cursor = 0;
    D_800E4518->selection = -1;
    func_8040E8D8_de(node, 0);
    D_80146894 = 1;
    D_80154020[1] = 0;
    D_80154020[0] = -1;
    func_804221E8_de();
    prompt = func_8040EC30_de(node, 0x371);
    D_800E4518->prompt = prompt;
    func_8040E8D8_de(prompt, 1);
    return 0;
}
