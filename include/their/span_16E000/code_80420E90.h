#ifndef UNBAKE_SPAN_16E000_CODE_80420E90_H
#define UNBAKE_SPAN_16E000_CODE_80420E90_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_082ae33459cdbbb965fb5112 */
extern void func_804210E8_de();

struct Frame_func_804217D4_de;
/* unbake published declaration: published_0a920c89df11abff59707634 */
typedef struct Frame_func_804217D4_de Frame_func_804217D4_de;

/* unbake published declaration: published_11e5d51874caff88bc070ed4 */
extern float D_800DD600;

/* unbake published declaration: published_1d789b7fe26bf1dbfaab6468 */
extern void func_80422020_de();

/* unbake published declaration: published_37d09d050b7622a64b902934 */
extern s32 func_80421A58_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_470066988f71e326febecb50 */
extern void func_8042177C_de();

struct State_func_804217D4_de;
/* unbake published declaration: published_4783857c04a3e8e4cde57d8c */
typedef struct State_func_804217D4_de State_func_804217D4_de;

/* unbake published declaration: published_4e9a177ee26de90b4e5e2377 */
extern void func_80421234_de();

/* unbake published declaration: published_8a0b77a12b0ddbc83b98081e */
extern void func_804217D4_de();

struct MenuWidget;
struct NumberPadScreen;
/* unbake published declaration: published_8c4a11f21a93cf3c2df78131 */
struct NumberPadScreen {
    char pad0[8];
    void *window;
    char padC[0x20 - 0xC];
    struct MenuWidget *pad;
    char pad24[4];
    s32 length;
    s32 mode;
    s32 value;
    s32 cursor;
    s32 full;
};

struct NumberPadScreen;
/* unbake published declaration: published_96e626e27cf85714ee03fdb6 */
typedef struct NumberPadScreen NumberPadScreen;

/* unbake published declaration: published_a3603f65c2efd03dc3bb49eb */
extern s32 func_80421E60_de(s32 *record);

/* unbake published declaration: published_c357c1325eca09ef40edcd4a */
extern void func_804213DC_de();

struct Meter;
struct Resource_func_80419E54_de;
/* unbake published declaration: published_c4bf64c2e8c13cba999ea0d3 */
struct Meter {
    s32 amount;
    s32 done;
    s32 falling;
    struct Resource_func_80419E54_de *bar;
};

struct Meter;
/* unbake published declaration: published_d240b89c911404e9230afa45 */
extern s32 func_80421E9C_de(struct Meter *meter, s32 step);

/* unbake published declaration: published_d5bcff0946d11ed9de958394 */
extern s32 func_80421DD0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_e071ed26209bd10823c13627 */
extern float D_800DD608;

struct State_func_8042177C_de;
/* unbake published declaration: published_e3b5565479094a0b8f658bd8 */
struct State_func_8042177C_de {
    char pad0[8];
    void *list;
    char padC[0x20 - 0xC];
    void *object;
    char pad24[0x34 - 0x24];
    s32 ready;
};

struct Screen_func_80421884_de;
/* unbake published declaration: published_e719e63785e56280fa10466e */
struct Screen_func_80421884_de {
    s32 dialog;
    char pad4[0x34 - 4];
    s32 open;
    s32 confirmed;
};

struct Frame_func_804217D4_de;
struct State_func_804217D4_de;
/* unbake published declaration: published_ea3a487a1951edcb7baaeab5 */
struct State_func_804217D4_de {
    char a[8];
    s32 unk8;
    char b[0x14];
    struct Frame_func_804217D4_de *unk20;
    char c[8];
    s32 unk2C;
};

struct Screen_func_804210E8_de;
/* unbake published declaration: published_ed17473aead6bb2f81ae84c4 */
struct Screen_func_804210E8_de {
    char pad0[0xC];
    void *boxes[4];
};

struct Triple;
/* unbake published declaration: published_eeac431c508b92f5fbc3e468 */
extern void func_80421E6C_de(struct Triple *timer, s32 mode);

struct Rec_func_8024C92C_de;
/* unbake published declaration: published_f87963d92f5b2ea3ed9f4326 */
extern void func_80421FEC_de(struct Rec_func_8024C92C_de *record, s32 value);

#endif
