#ifndef UNBAKE_SPAN_1000_CODE_80297CD0_H
#define UNBAKE_SPAN_1000_CODE_80297CD0_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
/* unbake published declaration: published_0179e056373ea9952b35ab7c */
typedef signed int ( *func_802995D4_de_Callback)(signed int, signed int, signed int, signed int);

struct func_8029A9F4_S1;
/* unbake published declaration: published_02f1564aea202c90c72f58c1 */
struct func_8029A9F4_S1 {
    char pad0[0x528];
    unsigned int unk528;
};

struct IntegerState530;
/* unbake published declaration: published_065dc1b4c3544ccf58387528 */
typedef struct IntegerState530 IntegerState530;

/* unbake published declaration: published_0706788d41048bbeb1b33016 */
extern void func_802998A8_de();

struct State_func_80297EA4_de;
/* unbake published declaration: published_09c4de972d2a3db28a77d613 */
typedef struct State_func_80297EA4_de State_func_80297EA4_de;

typedef s32 (*MenuElementHandler)(void *element, s32 event, s32 arg2, s32 arg3, s32 arg4);

struct Element;
/* unbake published declaration: published_0a639495095b5bad30ce37a2 */
struct Element {
    char pad0[0xC];
    s16 id;
    u16 kind;
    u16 field10;
    u16 flags;
    u8 unobserved14[0x3C - 0x14];
    s32 linked_id;
    MenuElementHandler handler;
};

struct Ui_func_80297FA0_de;
/* unbake published declaration: published_1b11a7d08dfd61fa3bf4edfa */
typedef struct Ui_func_80297FA0_de Ui_func_80297FA0_de;

struct Entry_func_80298ECC_de;
/* unbake published declaration: published_7f99c5a411529a9831a28afe */
struct Entry_func_80298ECC_de {
    void *object;
    s32 field4;
    s32 field8;
    s32 fieldC;
    s32 field10;
    s32 field14;
    s32 field18;
};

struct Entry_func_80298ECC_de;
/* unbake published declaration: published_e90e1642e71b424dd596b499 */
typedef struct Entry_func_80298ECC_de Entry_func_80298ECC_de;

struct Manager_func_80298FE8_de;
/* unbake published declaration: published_1b1e83e99d76959be740b731 */
struct Manager_func_80298FE8_de {
    s32 field0;
    s32 index;
    s32 lowIndex;
    Entry_func_80298ECC_de *entries;
    s8 pad10[0x524];
    s32 field534;
    s32 field538;
};

struct Element;
/* unbake published declaration: published_1c3f6dcc3397454c5988203a */
typedef struct Element Element;

struct func_8029A9F4_S1;
/* unbake published declaration: published_1d596a5e8b64b7bf1f24c8c5 */
typedef struct func_8029A9F4_S1 func_8029A9F4_S1;

/* unbake published declaration: published_20c3ab6f4ffe5f472dbd431d */
extern void func_80297DBC_de();

struct Entry_func_80297EA4_de;
struct Entry_func_80297EA4_de {
    char pad[8];
    func_8021C9B4_S3 *unk8;
    char rest[16];
};
struct Entry_func_80297EA4_de;
struct State_func_80297EA4_de;
/* unbake published declaration: published_2a6639ad0aa23c3084ec7e0c */
struct State_func_80297EA4_de {
    int (*unk0)(int,int,int,int);
    int unk4;
    int unk8;
    struct Entry_func_80297EA4_de *unkC;
    char pad[0x510];
    int unk520;
    char pad2[12];
    int unk530;
};

/* unbake published declaration: published_30a3874416a1bce4b6844b09 */
extern void func_80298ECC_de();

/* Draw providers use several existing aggregate declarations. Registration
 * stores these functions; this type does not prescribe a call signature. */
typedef void (*MenuDrawHandler)();

struct MenuHandlerEntry {
    s32 id;
    MenuElementHandler default_handler;
    MenuElementHandler override_handler;
    MenuDrawHandler draw_handler;
    s32 flags;
};

struct WidgetTable_func_802982C4_de;
/* unbake published declaration: published_393c16ac7ddf82564194d1c5 */
struct WidgetTable_func_802982C4_de {
    u8 pad0[0x1C];
    struct MenuHandlerEntry handlers[64];
};

/* unbake published declaration: published_398f496c9387fdef10485897 */
extern void func_80299778_de(s32 id, s32 mode, MenuElementHandler handler);

/* unbake published declaration: published_435ee34e56734fa03bad10c6 */
extern void func_80297FA0_de(s32 screenCount, s32 value);

/* unbake published declaration: published_44053f661eab87e016e69b12 */
extern int D_80146E18;

struct Entry_func_80298170_de;
struct Entry_func_80298170_de {
    s32 id;
    struct Element *object;
    s32 context;
};
struct Cache_func_80298170_de;
struct Entry_func_80298170_de;
/* unbake published declaration: published_450de80ffdc44b37bc87bedb */
struct Cache_func_80298170_de {
    char pad0[0x53C];
    struct Entry_func_80298170_de *entries;
    s32 count;
};

/* unbake published declaration: published_493ddd4abaf4db92a21104d7 */
extern void func_80299468_de();

struct Widget;
/* unbake published declaration: published_fdea94dbb8aa66e0b1ac96e3 */
struct Widget {
    char pad0[0xC];
    s16 id;
    char padE[4];
    u16 flags;
    char pad14[0x2C - 0x14];
    struct Widget *links[4];
};

struct Screen;
struct Widget;
struct Screen {
    char pad0[8];
    struct Widget *focus;
    char padC[0x1C - 0xC];
};
struct Screen;
struct Ui;
/* unbake published declaration: published_518b6434dc944b56bcf84549 */
struct Ui {
    s32 pad0;
    s32 current;
    s32 pad8;
    struct Screen *screens;
};

/* unbake published declaration: published_537cbd152bd3a14cf4b30ded */
extern int D_80146E08;

struct Ui;
/* unbake published declaration: published_547b3cde9e098967313e53d3 */
typedef struct Ui Ui;

struct Manager_func_802995D4_de;
/* unbake published declaration: published_560fb4e081c63de251493ea3 */
struct Manager_func_802995D4_de {
    func_802995D4_de_Callback callback;
    s32 index;
    s32 lowIndex;
    Entry_func_80298ECC_de *entries;
    char pad10[0x510];
    s32 dispatching;
    s32 pad524;
    s32 blockedValue;
};

/* unbake published declaration: published_5917bf7d575ed4dbdc026eb8 */
extern double D_800C5680_de;

/* unbake published declaration: published_5e2e92529ab65f01519ef1c1 */
typedef void ( *func_80299468_de_Callback)(signed int, signed int, signed int, signed int);

struct Manager_func_80299468_de;
/* unbake published declaration: published_5ce29765776e6ec68047afd7 */
struct Manager_func_80299468_de {
    func_80299468_de_Callback callback;
    s32 index;
    s32 lowIndex;
    void *entries;
    char pad10[0x520];
    s32 field530;
    char pad534[8];
    void *field53C;
};

struct IntegerState530;
/* unbake published declaration: published_5f2b8e51e9ed23aa0d373e95 */
struct IntegerState530 {
    unsigned char padding_0[1324];
    s32 unk_52C;
};

struct Cache_func_80298170_de;
/* unbake published declaration: published_5fbf4aa0693a2e98d28e67f1 */
typedef struct Cache_func_80298170_de Cache_func_80298170_de;

struct Menu_func_802991D4_de;
/* unbake published declaration: published_6264b08b432c721fe6bf8088 */
typedef struct Menu_func_802991D4_de Menu_func_802991D4_de;

/* unbake published declaration: published_66054314bec3a9e63ed90a86 */
extern s32 func_802998E0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_6e178e78801d8ecf511e092d */
extern unsigned int func_802999E0_de(void);

/* unbake published declaration: published_7c030161db43d27ab0d89cfa */
extern int D_80146E0C;

struct Manager_func_80298FE8_de;
/* unbake published declaration: published_806b3093b7ddf49c71fe0ef4 */
typedef struct Manager_func_80298FE8_de Manager_func_80298FE8_de;

struct func_8029A8E0_S1;
/* unbake published declaration: published_8bc42287cae0279ae26b4baa */
struct func_8029A8E0_S1 {
    char pad0[0xE];
    u16 unkE;
};

/* unbake published declaration: published_951e70ecdaa56392a84dbf3f */
extern void func_8029958C_de(s32 arg0);

struct Manager_func_80299468_de;
/* unbake published declaration: published_9984a51b0106099f1dd5fbbe */
typedef struct Manager_func_80299468_de Manager_func_80299468_de;

/* unbake published declaration: published_9dc1a54b8fa94bb72fc0d2d9 */
extern double D_800C5668_de;

/* unbake published declaration: published_ae4b99f5abd58f28b26d8234 */
extern float D_800C5678_de;

/* unbake published declaration: published_b1913274801d51ade5779773 */
extern void func_80296CD0_de(s32 direction);

struct Entry_func_80297DBC_de;
struct Obj_func_80297DBC_de;
struct Entry_func_80297DBC_de {
    struct Obj_func_80297DBC_de *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
struct Entry_func_80297DBC_de;
struct State_func_80297DBC_de;
/* unbake published declaration: published_b967d99c80bd917dd2375859 */
struct State_func_80297DBC_de {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    struct Entry_func_80297DBC_de *unkC;
    s32 (*unk10)(s32);
};

struct WidgetTable_func_802982C4_de;
/* unbake published declaration: published_bb9a7c51ab3c1922326384f8 */
typedef struct WidgetTable_func_802982C4_de WidgetTable_func_802982C4_de;

extern void func_802982C4_de(s32 id, MenuElementHandler event_handler, MenuDrawHandler draw_handler, s32 flags);
extern MenuElementHandler func_802997E4_de(s32 kind);

struct Args_func_80298FE8_de;
/* unbake published declaration: published_bbf98d14358e4a913e02d040 */
struct Args_func_80298FE8_de {
    s32 word0;
    s32 word4;
    s32 word8;
    f32 wordC;
    f32 word10;
    u8 byte14;
    u8 pad15[3];
    s32 word18;
    s32 word1C;
    s32 word20;
    s32 word24;
};

/* unbake published declaration: published_be039b981260b18ee0a0ec88 */
extern int D_800CD8E0;

struct Entry_func_80298ECC_de;
struct Manager_func_80298ECC_de;
/* unbake published declaration: published_bf0cb74b7ac3b76fce133421 */
struct Manager_func_80298ECC_de {
    s32 field0;
    s32 index;
    s32 lowIndex;
    struct Entry_func_80298ECC_de *entries;
};

struct Element;
struct Entry_func_802991D4_de;
struct Entry_func_802991D4_de {
    struct Element *primary;
    s32 owner;
    struct Element *focus;
    char padC[0x10];
};
struct Entry_func_802991D4_de;
struct Menu_func_802991D4_de;
/* unbake published declaration: published_c04258f089061c3ddf9a6588 */
struct Menu_func_802991D4_de {
    s32 (*callback)(s32 event, s32, s32, s32);
    s32 current;
    char pad8[4];
    struct Entry_func_802991D4_de *entries;
    char pad10[0x510];
    s32 handled;
    char pad524[4];
    s32 locked;
};

struct Manager_func_80298ECC_de;
/* unbake published declaration: published_c0f60ad13b09c1f7b3cec974 */
typedef struct Manager_func_80298ECC_de Manager_func_80298ECC_de;

struct State_func_80297DBC_de;
/* unbake published declaration: published_c40ef82cabcdba7a14a26413 */
typedef struct State_func_80297DBC_de State_func_80297DBC_de;

/* unbake published declaration: published_c5bbd2230248a43cba767665 */
extern int D_8014D09C;

/* unbake published declaration: published_cb3ed8b7ac36ecc746080895 */
extern void func_80299874_de(s32 arg0, s32 arg1);

struct func_8029A7E4_S1;
/* unbake published declaration: published_d13d4a92cff4a6197ea71d2a */
struct func_8029A7E4_S1 {
    char pad0[0x1C];
    int unk1C;
    char pad1C[0x20 - 0x1C - sizeof(int)];
    Rec_func_8024C92C_de unk20;
};

/* unbake published declaration: published_dbc2c6824d0379e5c7d85b0b */
extern void func_80298FE8_de();

struct Ui_func_80297FA0_de;
/* unbake published declaration: published_e492084e6c41e962a4cefe13 */
struct Ui_func_80297FA0_de {
    s32 pad0;
    s32 current;
    s32 pad8;
    void *screens;
    s32 value;
    s32 limit;
    s32 screenCount;
    Rec_func_8024C92C_de slots[64];
    s32 pad51C[2];
    s32 frames;
    s32 focus;
    s32 paging;
    s32 pad530;
    s32 field534;
    s32 field538;
    void *cache;
    s32 cacheCount;
};

struct Args_func_80298FE8_de;
/* unbake published declaration: published_f2393c375f966bc6962fa533 */
typedef struct Args_func_80298FE8_de Args_func_80298FE8_de;

struct Manager_func_802995D4_de;
/* unbake published declaration: published_f559cbd87f439915c1d741e7 */
typedef struct Manager_func_802995D4_de Manager_func_802995D4_de;

struct Widget;
/* unbake published declaration: published_f9c8917e3b13d64fe5ac2877 */
typedef struct Widget Widget;

struct func_8029A8E0_S1;
/* unbake published declaration: published_fa549790fff71e3cce449c0f */
typedef struct func_8029A8E0_S1 func_8029A8E0_S1;

struct func_8029A7E4_S1;
/* unbake published declaration: published_faf4aa5965bc6bba692ab017 */
typedef struct func_8029A7E4_S1 func_8029A7E4_S1;

/* Callable low-address aliases of the native code providers. The cartridge
 * registers these entry addresses, not overlay file ranges or data objects. */
/* D_002A1B50: func_802A1B50_de */
extern s32 D_002A1B50(void *, s32, s32, s32, s32);
/* D_002A1BE0: func_802A1BE0_de */
extern void D_002A1BE0();
/* D_0040C5C0: second return stub in func_8040C5B8_de (+8) */
extern s32 D_0040C5C0(void *, s32, s32, s32, s32);
/* D_0040C5C8: func_8040C5C8_de */
extern void D_0040C5C8();
/* D_004125A4: func_804125A4_de */
extern s32 D_004125A4(void *, s32, s32, s32, s32);
/* D_00412634: func_80412634_de */
extern void D_00412634();
/* D_00419A4C: func_80419A4C_de */
extern s32 D_00419A4C(void *, s32, s32, s32, s32);
/* D_00419ADC: func_80419ADC_de */
extern void D_00419ADC();
/* D_00419F9C: func_80419F9C_de */
extern s32 D_00419F9C(void *, s32, s32, s32, s32);
/* D_0041A02C: func_8041A02C_de */
extern void D_0041A02C();
/* D_0041A490: func_8041A490_de */
extern s32 D_0041A490(void *, s32, s32, s32, s32);
/* D_0041A520: func_8041A520_de */
extern void D_0041A520();
/* D_0041A724: func_8041A724_de */
extern s32 D_0041A724(void *, s32, s32, s32, s32);
/* D_0041A7B4: func_8041A7B4_de */
extern void D_0041A7B4();
/* D_0041AD7C: func_8041AD7C_de */
extern s32 D_0041AD7C(void *, s32, s32, s32, s32);
/* D_0041AE0C: func_8041AE0C_de */
extern void D_0041AE0C();
/* D_0041B340: func_8041B340_de */
extern s32 D_0041B340(void *, s32, s32, s32, s32);
/* D_0041B3D0: func_8041B3D0_de */
extern void D_0041B3D0();
/* D_0041B970: func_8041B970_de */
extern s32 D_0041B970(void *, s32, s32, s32, s32);
/* D_0041BA00: func_8041BA00_de */
extern void D_0041BA00();

#endif
