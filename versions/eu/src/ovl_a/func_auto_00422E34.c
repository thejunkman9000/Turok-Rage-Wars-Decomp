#include "common.h"

typedef struct EuWidget {
    char pad0[12];
    s16 resource;
    char padE[2];
    u8 alpha;
    char pad11[3];
    s16 x;
    s16 y;
    s16 width;
    s16 height;
    char pad1C[0x2C - 0x1C];
    s32 value;
    struct EuWidget *next;
    s32 field34;
    s32 word38;
} EuWidget;
typedef struct EuOptionsScreen EuOptionsScreen;
struct EuOptionsScreen {
    u32 unknown00[7];
    s32 cursor;
    EuWidget *leftTab;
    s32 leftStep;
    EuWidget *rightTab;
    s32 rightStep;
    s32 page;
    s32 pages;
    s32 title;
    EuWidget *marker;
    EuWidget *header;
    EuWidget *footer;
    EuWidget *pakIcon;
    EuWidget *rumbleIcon;
    s32 slider;
    s32 firstList;
    s32 secondList;
    s32 state;
    s32 selection;
    s32 sound;
    EuWidget *prompt;
};
typedef struct EuSlot {
    u8 enabled;
    u8 pad1[0x18];
    u8 controller;
    u8 pad1A[4];
    u8 secondListMode;
    u8 pad1F[0x77];
} EuSlot;
typedef struct EuGame {
    u32 flags;
    u8 pad04[9];
    u8 controllerMode;
    u8 pad0E[2];
    s32 buttons;
    u8 pad14[7];
    u8 firstListMode;
    u8 pad1C[0x148 - 0x1C];
    EuSlot slots[8];
    u8 pad5F8[0x3C];
    /* 0x634 */ u8 pad634[0x40];
} EuGame;

extern EuOptionsScreen *D_auto_800F0B38;
extern EuGame D_801462C8;
extern char *D_auto_800E1C14[];
extern char *D_auto_800E1C34[];
extern char *D_auto_800E1C44[];
extern char *D_auto_800E1C74[];
extern char *D_auto_800E1C84[];
extern char *D_auto_800E1C94[];
extern s32 D_auto_801527D4;
extern s32 D_80154020[2];

extern EuOptionsScreen *func_00252FFC(s32);
extern s32 func_0025E2E4(void);
extern void func_0025E2F4(s32);
extern void func_0025E3A4(void);
extern void func_0025E234(s32);
extern EuWidget *func_auto_0040F070(void *, s32);
extern void func_auto_0040ED18(void *, s32);
extern void func_auto_0040ED90(EuWidget *, s32);
extern s32 func_auto_0041A294(s32, s32);
extern void func_auto_0041B550(s32);
extern s32 func_auto_0041B000(s32, s32);
extern void func_auto_0041B174(s32, char *);
extern void func_auto_0041B150(s32, s32);
extern s32 func_00265370(void);
extern s32 func_auto_0041A9C0(s32, s32, s32);
extern void func_auto_0041AB2C(s32, s32);
extern s32 func_auto_0042BAE8(void);
extern void func_auto_004226E8(void);
extern void func_002A338C(void);
extern void func_auto_0043D0F0(EuOptionsScreen *, s32, s32, s32, s32);
extern void func_auto_0043D158(EuOptionsScreen *);

s32 func_auto_00422E34(void *node) {
    EuGame *settings;
    register EuWidget *handle asm("$16");
    EuWidget *marker;
    EuWidget *header;
    EuWidget *rumble;
    EuWidget *pak;
    EuWidget *prompt;
    s32 firstListHandle;
    s32 secondListHandle;
    s32 slider;
    s32 i;
    s32 rem;

    D_auto_800F0B38 = func_00252FFC(0x6C);
    D_auto_800F0B38->sound = func_0025E2E4();
    func_0025E2F4(0x34);
    func_0025E3A4();
    func_0025E234(-1);
    D_auto_800F0B38->page = 1;
    D_auto_800F0B38->pages = 4;
    D_auto_800F0B38->leftTab = func_auto_0040F070(node, 0x381);
    D_auto_800F0B38->leftTab->x -= D_auto_800F0B38->leftTab->width;
    D_auto_800F0B38->leftStep = D_auto_800F0B38->leftTab->width / 4;
    rem = D_auto_800F0B38->leftTab->width - D_auto_800F0B38->leftStep * 4;
    D_auto_800F0B38->leftTab->x += rem;
    D_auto_800F0B38->rightTab = func_auto_0040F070(node, 0x388);
    D_auto_800F0B38->rightTab->x += D_auto_800F0B38->rightTab->width;
    D_auto_800F0B38->rightStep = D_auto_800F0B38->rightTab->width / 4;
    rem = D_auto_800F0B38->rightTab->width - D_auto_800F0B38->rightStep * 4;
    D_auto_800F0B38->rightTab->x -= rem;
    D_auto_800F0B38->title = func_auto_0041A294(0x373, 0x6E);
    marker = func_auto_0040F070(node, 0x372);
    D_auto_800F0B38->marker = marker;
    func_auto_0040ED18(marker, 0);
    func_auto_0040F070(node, 0x386)->alpha = 0x6E;
    header = func_auto_0040F070(node, 0x387);
    D_auto_800F0B38->header = header;
    header->alpha = 0x8C;
    D_auto_800F0B38->footer = func_auto_0040F070(node, 0x370);
    rumble = func_auto_0040F070(node, 0x384);
    D_auto_800F0B38->rumbleIcon = rumble;
    func_auto_0040ED18(rumble, 1);
    func_auto_0040F070(node, 0x385)->alpha = 0x6E;
    pak = func_auto_0040F070(node, 0x374);
    D_auto_800F0B38->pakIcon = pak;
    func_auto_0040ED18(pak, 0);
    func_auto_0041B550(0x377);
    func_auto_0041B550(0x37C);
    firstListHandle = func_auto_0041B000(0x375, 0x376);
    D_auto_800F0B38->firstList = firstListHandle;
    settings = &D_801462C8;
    func_auto_0041B174(firstListHandle, D_auto_800E1C14[((u8 *)settings)[0x581]]);
    func_auto_0041B174(D_auto_800F0B38->firstList, D_auto_800E1C34[((u8 *)settings)[0x581]]);
    func_auto_0041B174(D_auto_800F0B38->firstList, D_auto_800E1C44[((u8 *)settings)[0x581]]);
    func_auto_0041B150(D_auto_800F0B38->firstList, settings->firstListMode);
    secondListHandle = func_auto_0041B000(0x378, 0x379);
    D_auto_800F0B38->secondList = secondListHandle;
    func_auto_0041B174(secondListHandle, D_auto_800E1C74[((u8 *)settings)[0x581]]);
    if (func_00265370() != 0x400000) {
        func_auto_0041B174(D_auto_800F0B38->secondList, D_auto_800E1C84[((u8 *)settings)[0x581]]);
        func_auto_0041B174(D_auto_800F0B38->secondList, D_auto_800E1C94[((u8 *)settings)[0x581]]);
    }
    func_auto_0041B150(D_auto_800F0B38->secondList, ((u8 *)settings)[0x580]);
    slider = func_auto_0041A9C0(0x37A, 0x37B, 0x80);
    D_auto_800F0B38->slider = slider;

    func_auto_0041AB2C(slider, settings->buttons);
    switch (settings->controllerMode) {
    case 0:
        if (func_auto_0042BAE8() == 0) {
            func_auto_0040ED90(func_auto_0040F070(node, 0x37E), 1);
        }
        handle = func_auto_0040F070(node, 0x380);
        func_auto_0040ED90(handle, 1);
        for (i = 0; i < 8; i++) {
            if (settings->slots[i].enabled == 1 && settings->slots[i].controller == 1) {
                func_auto_0040ED90(handle, 0);
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        func_auto_0040ED90(func_auto_0040F070(node, 0x380), 1);
        func_auto_0040ED90(func_auto_0040F070(node, 0x37E), 1);
        break;
    }
    func_auto_0041B550(0x380);
    func_auto_0041B550(0x37D);
    func_auto_0041B550(0x37E);
    func_auto_0041B550(0x37F);
    D_auto_800F0B38->state = 0;
    func_002A338C();
    func_auto_0043D0F0(D_auto_800F0B38, 0x67, 0, 0, 0);
    func_auto_0043D158(D_auto_800F0B38);
    D_auto_800F0B38->cursor = 0;
    D_auto_800F0B38->selection = -1;
    func_auto_0040ED18(node, 0);
    D_auto_801527D4 = 1;
    D_80154020[1] = 0;
    D_80154020[0] = -1;
    func_auto_004226E8();
    prompt = func_auto_0040F070(node, 0x371);
    D_auto_800F0B38->prompt = prompt;
    func_auto_0040ED18(prompt, 1);
    return 0;
}
