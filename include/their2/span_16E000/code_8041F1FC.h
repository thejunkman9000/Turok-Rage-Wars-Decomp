#ifndef UNBAKE_SPAN_16E000_CODE_8041F1FC_H
#define UNBAKE_SPAN_16E000_CODE_8041F1FC_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct Row_func_80420850_de;
/* unbake published declaration: published_036993707647b67829999063 */
typedef struct Row_func_80420850_de Row_func_80420850_de;

struct Row_func_80420850_de;
/* unbake published declaration: published_5848f3618d6a7481dc290d4c */
struct Row_func_80420850_de {
    s32 choice;
    s32 phase;
    s32 costume;
    char padC[4];
    char preview[0x4A8];
    char tail[0x10];
};

struct Selection_func_80420850_de;
/* unbake published declaration: published_009aa3b05f9f6139ed2bfc07 */
struct Selection_func_80420850_de {
    void *screen;
    char pad4[0xC];
    Row_func_80420850_de rows[8];
};

struct Selection_func_80420850_de;
/* unbake published declaration: published_0a0303efc06e5bf518ecdffe */
typedef struct Selection_func_80420850_de Selection_func_80420850_de;

struct CharacterSelectionRoot;
/* unbake published declaration: published_0a2cc8cccbf2f6d95cadd03c */
struct CharacterSelectionRoot {
    void *screen;
    s32 panel;
    char pad8[8];
    s32 choice;
    s32 phase;
};

/* unbake published declaration: published_188abccad1e26575ba9a7514 */
extern void func_8041FF2C_de();

struct PanelRecord;
/* unbake published declaration: published_1a835bc7f8782c4950c6ad38 */
struct PanelRecord {
    char pad[0x14];
    s32 mode;
    char pad18[8];
    char target;
    char pad21[0x4A7];
};

struct Entry_func_80420AD4_de;
/* unbake published declaration: published_1cdf033cda85bee2fa0b8710 */
struct Entry_func_80420AD4_de {
    char pad[0x14];
    s32 state;
    char pad18[0x4C8 - 0x18];
};

struct RosterSlot;
/* unbake published declaration: published_1e5791b18eea570a664fa7b9 */
typedef struct RosterSlot RosterSlot;

struct Entry_func_80420B78_de;
/* unbake published declaration: published_282c639ef06b8c31fd03b737 */
struct Entry_func_80420B78_de {
    char pad[0x10];
    int target;
    int active;
    char pad18[0x4C8 - 0x18];
};

struct SelectEntry;
/* unbake published declaration: published_398b824d8158b03749dbc3af */
struct SelectEntry {
    int choice;
    int state;
    unsigned char variant[4];
    char pad0C[4];
    char preview[0x4A8];
    int confirmed;
    char pad4BC[0xC];
};

struct SelectEntry;
/* unbake published declaration: published_b37a91616f52f24a31062aac */
typedef struct SelectEntry SelectEntry;

struct SelectMenu;
/* unbake published declaration: published_31bd6462e94b8010a13c8988 */
struct SelectMenu {
    void *screen;
    void *menu;
    char pad08[8];
    SelectEntry entries[8];
};

struct Item_func_80420308_de;
/* unbake published declaration: published_7dcb8339ff53c0dcb2aad5bb */
struct Item_func_80420308_de {
    char pad[0x14];
    u16 x;
    u16 y;
};

struct Entry_func_80420308_de;
struct Item_func_80420308_de;
/* unbake published declaration: published_36945dd8a28346e4b7838e52 */
struct Entry_func_80420308_de {
    void *window;
    char pad4[0x8 - 0x4];
    struct Item_func_80420308_de *cursor;
    char padC[0x14 - 0xC];
    s32 state;
    char pad18[0x4C8 - 0x18];
};

struct Entry_func_80420308_de;
struct Screen_func_80420308_de;
/* unbake published declaration: published_37169904a059184206bba1fc */
struct Screen_func_80420308_de {
    struct Entry_func_80420308_de entries[4];
};

struct Match_func_80420618_de;
/* unbake published declaration: published_3a680c6ae494bc484b887554 */
typedef struct Match_func_80420618_de Match_func_80420618_de;

struct Row;
struct StateFlags;
/* unbake published declaration: published_483f97f991fd3bf9e65a9485 */
struct Row {
    char pad0[0xC];
    struct StateFlags cells[6];
};

/* unbake published declaration: published_62c84a0fa2ba140b8e37c224 */
extern void func_80420850_de(s32 player);

struct Row_func_80420438_de;
struct StateFlags;
/* unbake published declaration: published_62cc733f243be705de46759d */
struct Row_func_80420438_de {
    char pad0[0xC];
    struct StateFlags cells[3];
    struct StateFlags options[3];
};

struct Choice;
/* unbake published declaration: published_63a99ef6a20fd96bf8eea4ff */
typedef struct Choice Choice;

struct Panel_func_8041FC50_de;
/* unbake published declaration: published_fab453cc4103315756782186 */
struct Panel_func_8041FC50_de {
    char pad0[8];
    s32 player;
    s32 state;
    char pad10[8];
    char body[0x4A8];
    s32 flash;
    char pad4C4[4];
};

struct Panel_func_8041FC50_de;
struct Screen_func_8041FC50_de;
/* unbake published declaration: published_6a4a3eafa2aedd9aefcca2db */
struct Screen_func_8041FC50_de {
    char pad0[8];
    struct Panel_func_8041FC50_de panels[4];
    char pad1328[0x10];
    s32 state;
};

struct Choice;
/* unbake published declaration: published_79e2ff0eef71d37e1bff7789 */
struct Choice {
    s32 id;
    char pad4[8];
    f32 scale[4];
    f32 angle[4];
    Vec3 position[4];
    s32 flags[4];
    char pad6C[4];
};

struct Entry_func_80420B78_de;
/* unbake published declaration: published_8101fb8766bde7b66c10f3da */
typedef struct Entry_func_80420B78_de Entry_func_80420B78_de;

struct CharacterScreenCell;
/* unbake published declaration: published_8a066cd55436611949dc83bf */
struct CharacterScreenCell {
    u16 id;
    u16 pad;
};

struct CharacterSelectionRoot;
/* unbake published declaration: published_9629605cc274a1afb542286c */
typedef struct CharacterSelectionRoot CharacterSelectionRoot;

struct SelectMenu;
/* unbake published declaration: published_967fe1b6ba9500ed2608d78a */
typedef struct SelectMenu SelectMenu;

struct State_func_80420C10_de;
/* unbake published declaration: published_9a55810d7e5a6385f4588f25 */
typedef struct State_func_80420C10_de State_func_80420C10_de;

struct PanelRecord;
/* unbake published declaration: published_9abe21e05f0ca67676b345af */
typedef struct PanelRecord PanelRecord;

struct Entry_func_804201A4_de;
/* unbake published declaration: published_d59c2ae02199a9d3f90d5935 */
struct Entry_func_804201A4_de {
    void *window;
    char pad4[0x10 - 0x4];
    s32 kind;
    char pad14[0x18 - 0x14];
    s32 choice;
    char pad1C[0x4C8 - 0x1C];
};

struct Entry_func_804201A4_de;
struct Screen_func_804201A4_de;
/* unbake published declaration: published_a88ba62904e6b8990c3e1cf2 */
struct Screen_func_804201A4_de {
    struct Entry_func_804201A4_de entries[4];
};

/* unbake published declaration: published_aac1607b54a64d9724942e2c */
extern s32 func_8041F1D8_de(s32 key);

struct CharacterScreenCell;
/* unbake published declaration: published_e7e5c3d189ff3e6814c25769 */
typedef struct CharacterScreenCell CharacterScreenCell;

struct RosterSlot;
/* unbake published declaration: published_bbf7fecc9804567a9deb0ba3 */
struct RosterSlot {
    char pad00[0x78];
    unsigned char active;
    char pad79[6];
    unsigned char player;
    unsigned char kind;
    unsigned char variant;
    char pad82[0xF];
    unsigned char locked;
    char pad92[4];
};

/* unbake published declaration: published_c2b27b23b87dcae3d94d741c */
extern s32 func_80420D90_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Slot_func_8041F1D8_de;
/* unbake published declaration: published_c64304819166efb4f665e660 */
struct Slot_func_8041F1D8_de {
    s32 key;
    s32 value;
    char pad[0x70 - 8];
};

struct Match_func_80420618_de;
/* unbake published declaration: published_d19de4187229b9f61d62a5ee */
struct Match_func_80420618_de {
    char pad00[0xD];
    unsigned char mode;
    char pad0E[0xC2];
    RosterSlot slots[8];
};

struct State_func_80420C10_de;
/* unbake published declaration: published_d4629280bba1082196b9f5df */
struct State_func_80420C10_de {
    s32 a;
    s32 unk4;
    char p0[8];
    s32 unk10;
    s32 unk14;
    char p1[0x1320];
    s32 unk1338;
    s32 unk133C;
    char p2[0x14];
    s32 unk1354;
};

struct Row_func_80420308_de;
/* unbake published declaration: published_de32f660266e1e28de8e91a6 */
struct Row_func_80420308_de {
    s16 pad0;
    s16 frame;
    s16 pad4;
    u16 cursor;
    s16 pad8;
    u16 prompt;
    char padC[36 - 0xC];
};

/* unbake published declaration: published_e48e12f57cba2675cf62e0f5 */
extern s32 func_80420AD4_de(void);

#endif
