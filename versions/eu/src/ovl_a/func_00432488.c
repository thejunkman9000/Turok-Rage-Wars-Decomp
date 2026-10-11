/* Updates the selected player's setup panel and its linked controls. */
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/menu_setup_versions.h"
extern s32 D_800DF4C4;
#include "common/unused.h"
typedef struct SetupSaveRecord {
    union {
        struct {
    u8 name[8];
    s32 time;
    s8 owner;
    s8 player;
    char padE[1];
    u8 slot; /* +0xF: event-result text selection */
    char pad10[7];
    u8 count;
    char pad18[0x25 - 0x18];
    u8 rank; /* +0x25: achievement rank */
    char pad26[0x4A - 0x26];
    u8 achievementFlags[0x189 - 0x4A];
    u8 setting[5];
    char pad18E[0x190 - 0x18E];
        };
        struct { char pad0[0x6C]; s32 wins, kills, deaths; } statistics;
    };
} SetupSaveRecord;

typedef struct SetupPakDisplayName { char text[0x3C]; char code[70 - 0x3C]; } SetupPakDisplayName;

typedef struct SetupPakName {
    u8 flags[2];
    u8 code[0x14];
    u8 text[0x46 - 0x16];
} SetupPakName;

typedef struct SetupPort {
    s32 active;
    s32 pad4;
    s32 pad8;
} SetupPort;

typedef struct SetupPlayerRecord SetupPlayerRecord;
struct SetupPlayerRecord {
    s32 state;
    s32 sub;
    s32 next;
    union { s32 menu; MenuWidget *menuWidget; };
    char pad10[0x14 - 0x10];
    s32 back;
    union {
        char slots[4][400];
        SetupSaveRecord records[4];
    };
    union {
        struct { char pad658[0x67E - 0x658]; SetupPakName names[15]; };
        SetupPakDisplayName displayNames[15];
    };
    char padA98[0xAD8 - 0xA98];
    s32 slot;
    union {
        char padADC[0xAEC - 0xADC];
        struct { s32 scroll; MenuWidget *labels[3]; };
    };
    union {
        s32 chosen;
        s32 choice;
    };
    s32 used[4];
    union { s32 notes[4]; MenuWidget *nodes[4]; };
    char padB10[0xB28 - 0xB10];
    s32 port;
    s32 record;
    s32 host;
    char padB34[0xB64 - 0xB34];
    s32 profile;
};

typedef struct SetupBlock SetupBlock;
struct SetupBlock {
    void *window;
    union {
        void *list;
        s32 menu;
    };
    char pad8[0x54 - 0x8];
    s32 mode;
    SetupPlayerRecord players[4];
    s32 source;
    s32 sourceRecord;
    SetupPort ports[4];
};

typedef struct SetupPanelRoot SetupPanelRoot;
typedef struct SetupTextNode SetupTextNode;
typedef struct SetupRosterChoice SetupRosterChoice;
typedef struct SetupRosterSlot SetupRosterSlot;
typedef struct SetupCharacterState SetupCharacterState;
typedef struct SetupLinkedLabel SetupLinkedLabel;
typedef struct SetupRosterRecord SetupRosterRecord;
typedef struct {
    u32 state;
    char pad4[0x8];
    void *panel;
    void *root;
    char pad14[0x4];
    char rosterNames[0x668];
    char rosterDetails[0xB34 - 0x680];
    union {
        char chars[0x10];
        struct { char glyph; char terminator; } character[8];
    };
    s32 valueB44;
    s32 valueB48;
    s32 valueB4C;
    char textB50[0xB68 - 0xB50];
} SetupPanelRecord;
struct SetupPanelRoot {
    union {
        SetupBlock block;
        struct {
            void* unk0;
            void* unk4;
            s32 unk8;
            u8 unkC;
            char padC[0x47];
            u32 unk54;
            char pad54[0x2DA0];
            s32 unk2DF8;
            s32 unk2DFC;
            s32 unk2E00;
        } f;
        u8 bytes[0x2E04];
        struct {
            char pad0[0x58];
            SetupPanelRecord players[4];
        } panelView;
    } v;
};
struct SetupTextNode {
    char pad0[0x34];
    s32 unk34;
    void* unk38;
};
struct SetupRosterChoice {
    char pad0[0x64];
    void* unk64;
    char pad64[0xADC];
    s32 unkB44;
};
struct SetupRosterSlot {
    char pad0[0x64];
    void* unk64;
    char pad64[0xAC8];
    s32 unkB30;
};
struct SetupCharacterState {
    char pad0[0xBA0];
    s32 unkBA0;
    s32 unkBA4;
};
struct SetupLinkedLabel {
    char pad0[0x8];
    MenuWidget * unk8;
    char pad8[0x4];
    u8 unk10;
    char pad10[0x27];
    void* unk38;
};
struct SetupRosterRecord {
    char pad0[0x64];
    void* unk64;
    char pad64[0xB1C];
    s32 unkB84;
};

typedef struct {
    char pad0[0x58];
    u32 state;
    char pad5C[0x8];
    void *panel;
    void *root;
    char pad6C[0x4];
    char slot70[0x668];
    char slot6D8[0x4B4];
    s8 chars[2];
    char padB8E[0xE];
    s32 valueB9C;
    char padBA0[0x8];
    char textBA8[1];
} SetupPlayerPanel;





int func_80264614_de(int);
u8 * func_802A025C_de(u8 *, u8 *);
void func_802A2394_de(void);
void func_8040E8D8_de(void *, int);
void func_8040E928_de(void *, int);
void * func_8040EC30_de(void *, unsigned short);
char * func_80411D78_de(s32);
void func_8041B6E8_de(void *, s32, s32);
void func_8041B7B4_de(void *, s32, s32);
s32 func_8041B7FC_de(void *, s32);
void func_8041B8DC_de(void *, s32, void *);
void func_8042E9B4_de(char *, char *, char *);
void func_80433914_de(s32);
void func_80433BCC_de(s32);
void func_80433EA0_de(s32);
void func_80434C2C_de(s32);
s32 func_80435528_de(void);
void func_8043577C_de(s32);
void func_8043C278_de(s32 *);
s32 func_80433D38_de();                         /* extern */


/* The slot-error scalar is real external storage in every ROM version. */
extern SetupPanelRoot *D_800E54A4;
























void func_804322AC_de(s32 arg0) {



    s32 text_node; 

    s32 temp_s2; 

    s32 slot_active;

 
 
    s32 var_a0;
    s32 var_a0_5;
    s32 var_s0;

    
    s32 var_s1; 
    s32 var_v0;

    s8 *temp_s1;
    s8 *temp_copy_source;
    u16 var_a1;
    u16 var_a1_2;
    u16 var_a1_3;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_4;
    void *temp_a0;
    void *temp_v0;
    void *temp_v0_10;
    SetupRosterSlot *temp_v0_11;
    void *temp_v0_12;
    void *temp_v0_13;
    void *temp_v0_14;
    void *temp_v0_16;
    void *temp_v0_17;
    void *temp_v0_18;
    void *temp_v0_19;
    SetupRosterRecord *temp_v0_20;
    void *temp_v0_21;
    void *temp_v0_22;
    void *temp_v0_23;
    void *temp_v0_24;
    void *temp_v0_25;
    void *temp_v0_26;
    void *temp_v0_27;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    SetupRosterChoice *temp_v0_9;
    SetupCharacterState *temp_v1_3;
    void *var_a0_2;
    void *var_a0_3;
    void *var_a0_4;
    SetupPanelRoot *var_v1;

    temp_a0 = D_800E54A4->v.panelView.players[arg0].panel;
    if (temp_a0 != 0) {
        func_8040E8D8_de(temp_a0, 0);
    }
    func_8040E928_de(func_8041B7FC_de(D_800E54A4->v.f.unk4, arg0), 0);
    func_8041B6E8_de(D_800E54A4->v.f.unk0, arg0, SETUP_LABEL_ID);
    temp_v1 = D_800E54A4->v.panelView.players[arg0].state;
    switch (temp_v1) {                              /* switch 1 */
    case 0:                                         /* switch 1 */

        temp_v0 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, PANEL_ROOT_ID);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0;
        func_8040E8D8_de(temp_v0, 1);
        text_node = (s32)func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, PANEL_TEXT_ID);
        ((SetupTextNode *)text_node)->unk38 = D_800E54A4->v.panelView.players[arg0].textB50;
        temp_v1_2 = D_800E54A4->v.f.unk54;
        
        switch (temp_v1_2) {                        /* switch 2 */
        case 1:                                     /* switch 2 */
        case 7:                                     /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_17_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        case 2:                                     /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_2_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        case 3:                                     /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_3_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        case 4:                                     /* switch 2 */
        case 6:                                     /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_46_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        case 5:                                     /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_5_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        case 0:                                     /* switch 2 */
        default:                                    /* switch 2 */
            temp_s1 = func_80411D78_de(MODE_DEFAULT_ID);
            temp_copy_source = func_80411D78_de(((SetupTextNode *)text_node)->unk34);
            break;
        }


        func_802A025C_de((&D_800E54A4->v.panelView.players[arg0])->textB50, temp_copy_source);
        func_8042E9B4_de((&D_800E54A4->v.panelView.players[arg0])->textB50, D_800DDDC8, temp_s1);
        var_v0 = arg0 * 8;
        if (D_800E54A4->v.f.unk54 == 6) {
            func_8040E8D8_de(func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, MODE_HIDE_ID), 0);
            var_v0 = arg0 * 8;
        }
        break;
    case 1:                                         /* switch 1 */

        temp_v0_3 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_1_2EC);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_3;
        func_8040E8D8_de(temp_v0_3, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_1_2EE));
        var_v0 = arg0 * 8;
        break;
    case 2:                                         /* switch 1 */

        var_a0_3 = D_800E54A4->v.panelView.players[arg0].root;
        var_a1_2 = UI_CASE_2_2D4;
block_36:
        temp_v0_4 = func_8040EC30_de(var_a0_3, var_a1_2);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_4;
        func_8040E8D8_de(temp_v0_4, 1);
        var_v0 = arg0 * 8;
        break;
    case 3:                                         /* switch 1 */

        temp_v0_5 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_3_2BB);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_5;
        func_8040E8D8_de(temp_v0_5, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_3_2BC));
        break;
    case 4:                                         /* switch 1 */

        temp_v0_6 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_4_2D5);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_6;
        func_8040E8D8_de(temp_v0_6, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_4_2DA));
        func_80433EA0_de(arg0);
        var_v0 = arg0 * 8;
        break;
    case 22:                                        /* switch 1 */
        func_8040E8D8_de(D_800E54A4->v.panelView.players[arg0].panel, 1);
        var_v1 = D_800E54A4;
        var_s1 = 0;
        if (var_v1->v.f.unk2E00 == 0) {
            do {
                var_v1 = (void *)&var_v1->v.f.unkC;
                var_s1 += 1;
            } while (var_v1->v.f.unk2E00 == 0);
        }
        var_s0 = SLOT_DEFAULT_ID;
        if (var_s1 == 1) {
            goto case22_one;
        }
        if (var_s1 >= 2) {
            goto case22_check_two;
        }
        if (var_s1 == 0) {
            goto case22_selected;
        }
        goto case22_default;
case22_check_two:
        if (var_s1 == 2) {
            goto case22_two;
        }
case22_check_three:
        if (var_s1 == 3) {
            goto case22_three;
        }
case22_default:
        var_s0 = SLOT_DEFAULT_ID;
        goto case22_selected;
case22_one:
        var_s0 = SLOT_1_ID;
        goto case22_selected;
case22_two:
        var_s0 = SLOT_2_ID;
        goto case22_selected;
case22_three:
        var_s0 = SLOT_3_ID;
case22_selected:
        func_8041B6E8_de(D_800E54A4->v.f.unk0, arg0, var_s0);
        func_80433BCC_de(arg0);
        var_v0 = arg0 * 8;
        break;
    case 6:                                         /* switch 1 */

        temp_v0_7 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_6_2E4);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_7;
        func_8040E8D8_de(temp_v0_7, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_6_2E8));
        func_80434C2C_de(arg0);
        var_v0 = arg0 * 8;
        break;
    case 7:                                         /* switch 1 */

        temp_v0_8 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_7_2CA);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_8;
        func_8040E8D8_de(temp_v0_8, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_7_2CC));

        var_a0_4 = D_800E54A4->v.block.players[arg0].menuWidget;
        var_s1 = D_800E54A4->v.block.players[arg0].chosen;
        var_a1_3 = UI_CASE_7_2CB;

        (((MenuWidget *)(func_8040EC30_de(var_a0_4, var_a1_3)))->text) = &(&D_800E54A4->v.panelView.players[arg0])->rosterNames[var_s1 * 0x190];
        goto block_84;
    case 8:                                         /* switch 1 */

        temp_v0_10 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_8_2CE);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_10;
        func_8040E8D8_de(temp_v0_10, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_8_2CF));

        var_s1 = D_800E54A4->v.block.players[arg0].slot;
        temp_v0_10 = func_8040EC30_de(D_800E54A4->v.block.players[arg0].menuWidget, UI_CASE_8_2CB);

        ((MenuWidget *)temp_v0_10)->text = D_800E54A4->v.block.players[arg0].names[var_s1].code;
        goto block_84;
    case 9:                                         /* switch 1 */

        temp_v0_12 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_9_2C6);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_12;
        func_8040E8D8_de(temp_v0_12, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_9_2C8));
        ((MenuWidget *)func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_9_2C7))->text = &D_800E54A4->v.panelView.players[D_800E54A4->v.f.unk2DF8].rosterNames[D_800E54A4->v.f.unk2DFC * 0x190];
        goto block_84;
    case 10:                                        /* switch 1 */

        temp_v0_4 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_10_2A4);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_4;
        func_8040E8D8_de(temp_v0_4, 1);
        var_v0 = arg0 * 8;
        break;
    case 11:                                        /* switch 1 */

        temp_v0_13 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_11_2D1);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_13;
        func_8040E8D8_de(temp_v0_13, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_11_2D2));
        break;
    case 12:                                        /* switch 1 */

        temp_v0_14 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_12_2F2);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_14;
        func_8040E8D8_de(temp_v0_14, 1);
        temp_s2 = 0;
        var_s1 = (s32)func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_12_2F3);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, (void *)var_s1);
 

        D_800E54A4->v.panelView.players[arg0].valueB44 = 0;

        do {
            if (temp_s2 == 0) {
                D_800E54A4->v.panelView.players[arg0].character[temp_s2].glyph = 0x41;
            } else {
                D_800E54A4->v.panelView.players[arg0].character[temp_s2].glyph = 0;
            }
            D_800E54A4->v.panelView.players[arg0].character[temp_s2].terminator = 0;
            temp_s2++;
        } while (temp_s2 < 7);

        D_800E54A4->v.panelView.players[arg0].valueB4C = 0;
        D_800E54A4->v.panelView.players[arg0].valueB48 = 2;
        var_a0_5 = 0;
        do {
            ((SetupLinkedLabel *)var_s1)->unk10 = 0xFF;
            text_node = (s32)((SetupLinkedLabel *)var_s1)->unk8; 
            ((MenuWidget *)text_node)->text = &D_800E54A4->v.panelView.players[arg0].character[var_a0_5].glyph;
            var_s1 = (s32)((SetupLinkedLabel *)var_s1)->unk38;
            var_a0_5 += 1;
        } while (var_s1 != 0);
        var_v0 = arg0 * 8;
        break;
    case 13:                                        /* switch 1 */

        temp_v0_16 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_13_2AF);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_16;
        func_8040E8D8_de(temp_v0_16, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_13_2B6));
        func_80433914_de(arg0);
        var_v0 = arg0 * 8;
        break;
    case 14:                                        /* switch 1 */
    case 17:                                        /* switch 1 */
        func_8041B6E8_de(D_800E54A4->v.f.unk0, arg0, SETUP_LABEL_ID);
        func_8041B7B4_de(D_800E54A4->v.f.unk4, arg0, 1);

        temp_v0_17 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_17_2A5);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_17;
        func_8040E8D8_de(temp_v0_17, 1);
        if (func_80435528_de() == 0) {
            temp_v1_4 = D_800E54A4->v.f.unk54;
            if (temp_v1_4 == 4) {
                goto mode_default;
            }
            if ((s32)temp_v1_4 < 5) {
                goto mode_default;
            }
            if (temp_v1_4 == 5) {
                goto mode_five;
            }
            if (temp_v1_4 == 6) {
                goto mode_six;
            }
            goto mode_default;
mode_five:
            func_802A2394_de();
            func_8043C278_de(&D_800E54A4->v.f.unk8);
            goto mode_end;
mode_six:
            {
                func_8043577C_de(0x1D);
                if (D_800DF4C4 == 1) {
                    D_800DF4C0 -= 1;
                }
                if (D_800DF4C4 == 0) {
                    D_800DF4C0 = -1;
                }
                goto mode_end;
            }
mode_default:
            func_8043577C_de(0x1B);
mode_end:;
        }
        var_v0 = arg0 * 8;
        break;
    case 15:                                        /* switch 1 */

        temp_v0_18 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_15_2EF);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_18;
        func_8040E8D8_de(temp_v0_18, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_15_2F1));
        break;
    case 16:                                        /* switch 1 */

        temp_v0_19 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_16_2B7);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_19;
        func_8040E8D8_de(temp_v0_19, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_16_2B9));
        var_a1_3 = UI_CASE_16_2BA;

        var_a0_4 = D_800E54A4->v.block.players[arg0].menuWidget;
        var_s1 = D_800E54A4->v.block.players[arg0].record;
block_61:

        (((MenuWidget *)(func_8040EC30_de(var_a0_4, var_a1_3)))->text) = &(&D_800E54A4->v.panelView.players[arg0])->rosterNames[var_s1 * 0x190];
        goto block_84;
    case 21:                                        /* switch 1 */

        temp_v0_21 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_21_2E1);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_21;
        func_8040E8D8_de(temp_v0_21, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_21_2E2));
        break;
    case 23:                                        /* switch 1 */

        temp_v0_22 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_23_2AC);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_22;
        func_8040E8D8_de(temp_v0_22, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_23_2AE));
        break;
    case 24:                                        /* switch 1 */

        temp_v0_23 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_24_2A9);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_23;
        func_8040E8D8_de(temp_v0_23, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_24_2AA));
        break;
    case 25:                                        /* switch 1 */

        temp_v0_24 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_25_2EA);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_24;
        func_8040E8D8_de(temp_v0_24, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_25_2EB));
        break;
    case 26:                                        /* switch 1 */

        temp_v0_25 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_26_2A6);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_25;
        func_8040E8D8_de(temp_v0_25, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_26_2A7));
        break;
case27_found:
        func_8041B6E8_de(D_800E54A4->v.f.unk0, arg0, var_s0);
        goto case27_done;
    case 27:                                        /* switch 1 */
        func_8040E8D8_de(D_800E54A4->v.panelView.players[arg0].panel, 1);
        temp_s2 = 0;
 
        func_8041B6E8_de(D_800E54A4->v.f.unk0, arg0, CHECK_0_ID);
        do {
loop_69:
        if (temp_s2 == 1) {
            goto case27_one;
        }
        if (temp_s2 >= 2) {
            goto case27_check_two;
        }
        if (temp_s2 == 0) {
            goto case27_zero;
        }
        var_s0 = CHECK_DEFAULT_ID;
        goto case27_selected;
case27_check_two:
        if (temp_s2 == 2) {
            goto case27_two;
        }
        var_s0 = CHECK_DEFAULT_ID;
        goto case27_selected;
case27_zero:
        var_s0 = CHECK_0_ID;
        goto case27_selected;
case27_one:
        var_s0 = CHECK_1_ID;
        goto case27_selected;
case27_two:
        var_s0 = CHECK_2_ID;
case27_selected:
        slot_active = func_80264614_de(temp_s2);
        temp_s2 += 1;
        if (slot_active == 1) {
            goto case27_found;
        }
        } while (temp_s2 < 4);
case27_done:
        func_80433D38_de(arg0);
        var_v0 = arg0 * 8;
        break;
    case 28:                                        /* switch 1 */

        temp_v0_26 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_28_2DE);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_26;
        func_8040E8D8_de(temp_v0_26, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_28_2DF));
        break;
    case 29:                                        /* switch 1 */

        temp_v0_27 = func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].root, UI_CASE_29_2BF);
        D_800E54A4->v.panelView.players[arg0].panel = temp_v0_27;
        func_8040E8D8_de(temp_v0_27, 1);
        func_8041B8DC_de(D_800E54A4->v.f.unk4, arg0, func_8040EC30_de(D_800E54A4->v.panelView.players[arg0].panel, UI_CASE_29_2C0));
        var_v0 = arg0 * 8;
        break;
    default:                                        /* switch 1 */
block_84:
        var_v0 = arg0 * 8;
        break;
    }
    ((SetupLinkedLabel *)D_800E54A4->v.panelView.players[arg0].panel)->unk10 = 0x96;
}
