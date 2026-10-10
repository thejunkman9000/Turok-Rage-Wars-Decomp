#ifndef UNBAKE_COMMON_TYPES_1DC8418C21DB_H
#define UNBAKE_COMMON_TYPES_1DC8418C21DB_H
#include "audio_callbacks.h"
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
struct Item_func_8043C9AC_de;
/* unbake published declaration: published_0000b9574e3dbb500173c4e4 */
struct Item_func_8043C9AC_de {
    char pad0[0x14];
    s32 x;
    char pad18[8];
    s32 y;
};

struct func_802B67B0_S2;
/* unbake published declaration: published_21beb2161f372600785adb96 */
struct func_802B67B0_S2 {
    char pad0[0xE];
    s16 unkE;
};

struct func_802B67B0_S2;
/* unbake published declaration: published_2e5a1782dc053826a6184d30 */
typedef struct func_802B67B0_S2 func_802B67B0_S2;

struct func_80212828_S2;
/* unbake published declaration: published_006021299ba26f820483d6ab */
struct func_80212828_S2 {
    char pad0[0x1454];
    void * unk1454;
};

struct Pool;
/* unbake published declaration: published_011b7f96503b6bf7ce3b86f2 */
struct Pool {
    s32 count;
    char pad[0x40];
    s32 field44;
};

struct Actor_func_8024A1D0_de;
/* unbake published declaration: published_020166c5c253c76df8324109 */
typedef struct Actor_func_8024A1D0_de Actor_func_8024A1D0_de;

struct Table_func_8028CE94_de;
/* unbake published declaration: published_023ca9c9b9aae1ee9104a1c4 */
struct Table_func_8028CE94_de {
    s32 stride;
    s32 count;
    char data[1];
};

struct FftTables;
/* unbake published declaration: published_c8ad400ccfebdece5f6c05e9 */
typedef struct FftTables FftTables;

struct FftTables;
/* unbake published declaration: published_f644b5279df8e318ef052f82 */
struct FftTables {
    f32 *sines;
    f32 *cosines;
    s32 *order;
    s32 size;
};

struct func_80205314_S2;
/* unbake published declaration: published_02cb88377431768c435e20d4 */
struct func_80205314_S2 {
    char pad0[0x2C];
    int unk2C;
};

/* unbake published declaration: published_02f4baaa498ff52d659e794c */
extern int D_80142CA8;

struct func_8025C598_S1;
/* unbake published declaration: published_0374eeb78b200e378a1d478d */
typedef struct func_8025C598_S1 func_8025C598_S1;

struct func_8020C9CC_S1;
/* unbake published declaration: published_03962c0596ee60c577a57df7 */
struct func_8020C9CC_S1 {
    char pad0[0x4];
    u8 unk4;
};

struct ObjectState1E;
/* unbake published declaration: published_046de2526869f573e78b83d4 */
struct ObjectState1E {
    unsigned char padding_0[29];
    s8 unk_1D;
};

struct func_8021CD70_S3;
/* unbake published declaration: published_04beb446d36a8cbd13a06aef */
struct func_8021CD70_S3 {
    s32 unk0;
    char pad0[0x10];
    s32 unk14;
};

struct Frame_func_804217D4_de;
/* unbake published declaration: published_a8e26bd535350d095c54f5a9 */
struct Frame_func_804217D4_de {
    char a[0x16];
    s16 unk16;
    char b[2];
    s16 unk1A;
};

struct Frame_func_804217D4_de;
struct Menu_func_804241BC_de;
/* unbake published declaration: published_18d156d7cdaaa9235f18bdb4 */
struct Menu_func_804241BC_de {
    char pad[0x44];
    struct Frame_func_804217D4_de *list;
};

struct FieldRow;
/* unbake published declaration: published_a20e1d37eda81eb179481d83 */
struct FieldRow {
    s32 value;
    char pad[8];
};

struct FieldRow;
/* unbake published declaration: published_f5b4477524b28d4fa78545d9 */
typedef struct FieldRow FieldRow;

struct Menu_func_8043E494_de;
/* unbake published declaration: published_05da667abf37b8e3c93d1207 */
typedef struct Menu_func_8043E494_de Menu_func_8043E494_de;

struct Clip;
/* unbake published declaration: published_779ea483178ce6725dbf429f */
struct Clip {
    s16 mode;
    s16 frames;
};

struct Clip;
/* unbake published declaration: published_8ba80fdb24f35e974dc52d5b */
typedef struct Clip Clip;

struct Node_func_80285B64_de;
/* unbake published declaration: published_06745a4e2b0255244a16a083 */
struct Node_func_80285B64_de {
    char pad0[8];
    Clip *key;
    Vec3 position;
    f32 value0;
    f32 value1;
    char pad20[0x18];
    struct Node_func_80285B64_de **owner;
};

struct Element_func_8041200C_de;
/* unbake published declaration: published_068d2190ce9044ec428e5b78 */
struct Element_func_8041200C_de {
    char unk_0[1180];
};

struct func_8029A73C_S1;
/* unbake published declaration: published_06c5727ba14806e5b1199ba7 */
typedef struct func_8029A73C_S1 func_8029A73C_S1;

struct Block70;
/* unbake published declaration: published_a07837165e308ae98b630565 */
struct Block70 {
    s32 w[28];
};

struct Block70;
/* unbake published declaration: published_aab93d2faae606c445a2b482 */
typedef struct Block70 Block70;

struct func_8025E5B0_S1;
/* unbake published declaration: published_0708e54cc434b6e7dd1de6da */
struct func_8025E5B0_S1 {
    char pad0[0x14];
    short unk14;
};

struct Entry_func_80441EB0_de;
struct Entry_func_80441EB0_de {
    s16 type;
    char pad[0x22];
};
union func_8020E674_S1_U8;
/* unbake published declaration: published_16f28ec40bd2228fd7458baf */
typedef union func_8020E674_S1_U8 func_8020E674_S1_U8;

union func_8020E674_S1_U8;
/* unbake published declaration: published_27eaf25ed7d0dd5ad6c1b88e */
union func_8020E674_S1_U8 {
    f32 v0;
    Vec3 v1;
};

struct ALPlayer_s14;
/* unbake published declaration: published_ae83369a25d427fac33356da */
struct ALPlayer_s14 {
    struct ALPlayer_s14 *next;
    void *clientData;
    ALVoiceHandler handler;
    s32 callTime;
    s32 samplesLeft;
};

struct ALPlayer_s14;
/* unbake published declaration: published_ba2619d5141c158cd632ec6f */
typedef struct ALPlayer_s14 ALPlayer_s14;

struct ALEventQueue;
/* unbake published declaration: published_4a83efa611c3cacbedd33c17 */
typedef struct ALEventQueue ALEventQueue;

struct Message_func_802AF150_de;
/* unbake published declaration: published_7559de8ac5fd16290f355714 */
struct Message_func_802AF150_de {
    s16 type;
    char pad[14];
};

struct Link_func_802596B4_de;
/* unbake published declaration: published_ad5fe741124e29789f5285da */
struct Link_func_802596B4_de {
    struct Link_func_802596B4_de *next;
    struct Link_func_802596B4_de *prev;
};

struct Link_func_802596B4_de;
/* unbake published declaration: published_e31665eb5522814f62ebdd55 */
typedef struct Link_func_802596B4_de Link_func_802596B4_de;

struct ALEventQueue;
/* unbake published declaration: published_c963c324ee4858c8e3c6ef80 */
struct ALEventQueue {
    Link_func_802596B4_de freeList;
    Link_func_802596B4_de allocList;
    s32 eventCount;
};

struct Message_func_802AF150_de;
/* unbake published declaration: published_dd304da65eb4eb0029d8585c */
typedef struct Message_func_802AF150_de Message_func_802AF150_de;

struct Node802A697C;
/* unbake published declaration: published_e7cdeffb2feaa7080de94744 */
struct Node802A697C {
    u32 unk0;
    f32 value;
};

struct func_802062E0_S2;
/* unbake published declaration: published_07494911ae1e6c4b0ccb137c */
struct func_802062E0_S2 {
    char pad0[0x1C];
    Triple unk1C;
};

struct Shape_typemap_6;
/* unbake published declaration: published_075a151dc4dcf660788df095 */
struct Shape_typemap_6 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct func_8024C5C4_S2;
/* unbake published declaration: published_07833ab4f1d7ff6b0ed7d818 */
typedef struct func_8024C5C4_S2 func_8024C5C4_S2;

struct Brain_func_80212D78_eu_x;
/* unbake published declaration: published_07c4d4ef1f93bf463c22f5f0 */
struct Brain_func_80212D78_eu_x {
    char pad0[0x220];
    s32 unk220;
    char pad224[0xD8];
    s32 unk2FC;
};

struct Output80216D3C;
/* unbake published declaration: published_4e6066605d0e9469b7fa2305 */
struct Output80216D3C {
    s32 type;
    s32 unk4;
    s32 unk8;
    Triple first;
    Triple second;
    s32 unk24;
    Triple third;
    Triple fourth;
    s32 unk40;
};

struct Output80216D3C;
/* unbake published declaration: published_bcfe85616368d3dacfd649dd */
typedef struct Output80216D3C Output80216D3C;

struct func_8022ED94_S1;
/* unbake published declaration: published_0883e72d214916dc7b97c469 */
typedef struct func_8022ED94_S1 func_8022ED94_S1;

struct Matrix_func_80213CF8_de;
/* unbake published declaration: published_08e103ad750f7da04ceb4db2 */
struct Matrix_func_80213CF8_de {
    f32 m[4][4];
};

struct Record_func_80433914_de;
/* unbake published declaration: published_2638c31841497532c2172e27 */
typedef struct Record_func_80433914_de Record_func_80433914_de;

struct Record_func_80433914_de;
/* unbake published declaration: published_6bff282b2fe14d8828c90819 */
struct Record_func_80433914_de {
    union {
        struct {
    u8 name[8];
    s32 time;
    s8 owner;
    s8 player;
    char padE[1];
    u8 slot;
    char pad10[7];
    u8 count;
    char pad18[0x25 - 0x18];
    u8 rank;
    char pad26[0x4A - 0x26];
    u8 achievementFlags[0x189 - 0x4A];
    u8 setting[5];
    char pad18E[0x190 - 0x18E];
        };
        struct { char pad0[0x6C]; s32 wins, kills, deaths; } statistics;
    };
};

struct MenuWidget;
/* unbake published declaration: published_ad28380903e0937f63001350 */
struct MenuWidget {
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
    struct MenuWidget *next;
    s32 field34;
    union { void *text; s32 image; s32 word38; };
};

struct MenuWidget;
/* unbake published declaration: published_f2f23a906c282a1b530d14d8 */
typedef struct MenuWidget MenuWidget;

struct func_8020CA10_G1;
/* unbake published declaration: published_5bd3fe2aafd5bcdac812de87 */
typedef struct func_8020CA10_G1 func_8020CA10_G1;

struct func_8020CA10_G1;
/* unbake published declaration: published_eb22dfb1a02f8fd91a7fcb2b */
struct func_8020CA10_G1 {
    f32 unk0;
};

struct func_8020EA10_S1;
/* unbake published declaration: published_0a1ee3cdc11c3c652a5baeac */
typedef struct func_8020EA10_S1 func_8020EA10_S1;

struct ALVoice_s;
/* unbake published declaration: published_d23993bfb182d79b3124ff3b */
typedef struct ALVoice_s ALVoice_s;

struct ALVoice_s;
/* unbake published declaration: published_dcc2406d221f80c12f102a0d */
struct ALVoice_s {
    Link_func_802596B4_de node;
    void *pvoice;
    void *table;
    void *clientPrivate;
    s16 state;
    s16 priority;
    s16 fxBus;
    s16 unityPitch;
};

struct ALSynth_func_802B3000_de;
/* unbake published declaration: published_0ade3de4a37623ca53351699 */
typedef struct ALSynth_func_802B3000_de ALSynth_func_802B3000_de;

struct func_80275120_S1;
/* unbake published declaration: published_0aea5c83f3d82cd262349bde */
struct func_80275120_S1 {
    float unk0;
    char pad0[0x8 - 0x0 - sizeof(float)];
    float unk8;
    char pad8[0xC - 0x8 - sizeof(float)];
    float unkC;
};

struct Queue_func_802517B4_de;
/* unbake published declaration: published_0b033301f1f98dc98f42b2ad */
struct Queue_func_802517B4_de {
    void **head;
    s32 unk04;
    s32 count;
    s32 index;
    s32 capacity;
    void **entries;
};

/* unbake published declaration: published_7e2b8c8c5525c00ea0a14201 */
typedef signed int ( *Handler802A2B50)(void *, signed int, signed int, signed int, signed int);

struct Field_f32_10;
/* unbake published declaration: published_0ba059358608483ed64c2a74 */
typedef struct Field_f32_10 Field_f32_10;

struct Actor_func_8024A1D0_de;
/* unbake published declaration: published_0be896998f62f6fed7adac8c */
struct Actor_func_8024A1D0_de {
    u32 pad0[2];
    Vec3 position0;
    u32 pad14[2];
    Vec3 position1;
    u32 pad28[13];
    Vector4f rotation;
};

struct Resource_func_80419E54_de;
/* unbake published declaration: published_29ec88a34cc80eff5b2428c9 */
struct Resource_func_80419E54_de {
    char pad[0x10];
    unsigned char value;
};

struct Field_s32_2E0;
/* unbake published declaration: published_0c996eec471f3207d96a843f */
struct Field_s32_2E0 {
    char pad[0x2E0];
    s32 value;
};

struct Entry802AB8DC;
/* unbake published declaration: published_647da3a9e82037366a7fed4f */
typedef struct Entry802AB8DC Entry802AB8DC;

struct Entry802AB8DC;
/* unbake published declaration: published_c82146315f89debf42f8095c */
struct Entry802AB8DC {
    s32 offset;
    u8 pad4[4];
};

struct Inner8043E56C;
/* unbake published declaration: published_44f8af99bcdedacdb6ed0814 */
struct Inner8043E56C {
    u8 pad0[4];
    s8 unk4;
};

struct Inner8043E56C;
struct Outer8043E56C;
/* unbake published declaration: published_8efcdeb114c4bf37335711b6 */
struct Outer8043E56C {
    u8 pad0[0x20];
    struct Inner8043E56C *unk20;
};

struct Outer8043E56C;
/* unbake published declaration: published_a3f873d9394496583e4f08b3 */
typedef struct Outer8043E56C Outer8043E56C;

struct func_80254930_S1;
/* unbake published declaration: published_0f93018056966667273f140d */
typedef struct func_80254930_S1 func_80254930_S1;

struct Owner_func_8043E1F8_de;
/* unbake published declaration: published_0fb6bf3c0700960c78d18d62 */
struct Owner_func_8043E1F8_de {
    char pad0[0x85C];
    s32 unk85C;
};

struct ALVoice_s_func_802B3000_de;
/* unbake published declaration: published_10ccbf4d266d8e078e94cbb8 */
typedef struct ALVoice_s_func_802B3000_de ALVoice_s_func_802B3000_de;

struct UnitMtx;
/* unbake published declaration: published_4d2fa0dcb9b5cf418c27dc88 */
typedef struct UnitMtx UnitMtx;

struct UnitMtx;
/* unbake published declaration: published_ff45d0694bcc5c16f01a8349 */
struct UnitMtx {
    s32 m[16];
};

struct func_8024C864_S1;
/* unbake published declaration: published_11bf102de435c5c9c510ed3a */
typedef struct func_8024C864_S1 func_8024C864_S1;

struct __OSInode;
/* unbake published declaration: published_7a6cf21706533f9d005e3e3c */
typedef struct __OSInode __OSInode;

union __OSInodeUnit;
/* unbake published declaration: published_26cfa90f8d429212827e9d7f */
union __OSInodeUnit {
    struct {
        u8 bank;
        u8 page;
    } inode_t;
    u16 ipage;
};

union __OSInodeUnit;
/* unbake published declaration: published_9029c10c32c5a172356d19c7 */
typedef union __OSInodeUnit __OSInodeUnit;

struct __OSInode;
/* unbake published declaration: published_801b3d51716392937c09a685 */
struct __OSInode {
    __OSInodeUnit inode_page[128];
};

struct TextLayerRect;
/* unbake published declaration: published_13adfbb8be44469a738cd545 */
typedef struct TextLayerRect TextLayerRect;

struct func_8025E52C_S1;
/* unbake published declaration: published_148234b9b88cf06050b6f289 */
typedef struct func_8025E52C_S1 func_8025E52C_S1;

struct func_802044C8_S1;
/* unbake published declaration: published_14bdec5005ecbfaa5090b5dc */
struct func_802044C8_S1 {
    char pad0[0xE4];
    u16 unkE4;
    char padE4[0x100 - 0xE4 - sizeof(u16)];
    s32 unk100;
};

struct Node75;
/* unbake published declaration: published_14dd7802c4127be1d968e144 */
typedef struct Node75 Node75;

struct func_8020CC0C_S1;
/* unbake published declaration: published_1563e20f7a6ac71f1c56b55a */
struct func_8020CC0C_S1 {
    char pad0[0x8];
    char unk8;
};

struct ALMIDIEvent;
/* unbake published declaration: published_15bc6c88808f15e674cffa37 */
typedef struct ALMIDIEvent ALMIDIEvent;

struct func_80229BE0_S2;
/* unbake published declaration: published_5feb3ea30e4ec0a6345d71c1 */
struct func_80229BE0_S2 {
    char pad0[0x80];
    s8 unk80;
};

struct ResourceManagerState;
/* unbake published declaration: published_9d8431d8719e860d53360074 */
struct ResourceManagerState {
    s32 active;
    s32 count;
};

struct Arg1Struct;
/* unbake published declaration: published_48b0e61afd4a5ccba3be8b27 */
typedef struct Arg1Struct Arg1Struct;

struct Arg1Struct;
/* unbake published declaration: published_72d108bb4f29d13084f1e2e9 */
struct Arg1Struct {
    char pad0[0x1C];
    s32 unk1C;
    char pad1[0x20 - 0x1C - 4];
    s32 unk20;
};

struct func_80206930_S3;
/* unbake published declaration: published_171525c20616ff16939eb2c2 */
typedef struct func_80206930_S3 func_80206930_S3;

union ObjectLinks4_3;
/* unbake published declaration: published_22fc6041ae452293c56affcd */
typedef union ObjectLinks4_3 ObjectLinks4_3;

union ObjectLinks4_3;
/* unbake published declaration: published_3fe9c50cd121bb2b193e5d6d */
union ObjectLinks4_3 {
    void * v0;
    char * v1;
};

struct ObjectStateC_2;
/* unbake published declaration: published_176bd470e3004875ce3c40d9 */
struct ObjectStateC_2 {
    char pad0[0x8];
    ObjectLinks4_3 unk_8;
};

struct ALHeap;
/* unbake published declaration: published_17c984787b8d1879c1a29157 */
typedef struct ALHeap ALHeap;

struct func_8021846C_S3;
/* unbake published declaration: published_1845aa495ad0258352a0428c */
struct func_8021846C_S3 {
    char pad0[0xB0];
    s32 unkB0;
};

struct NodeEvent;
/* unbake published declaration: published_193b6ef76b192e1eeb438e2d */
struct NodeEvent {
    s32 words[10];
};

struct Resource_func_80419E54_de;
/* unbake published declaration: published_1a0a3d9b20404d831b4e965a */
typedef struct Resource_func_80419E54_de Resource_func_80419E54_de;

struct Shape_func_802764D4_de_2;
/* unbake published declaration: published_1a29f5e3b0253670a8d7fcd6 */
struct Shape_func_802764D4_de_2 {
    int field_0;
    int field_4;
};

struct func_80228774_S7;
/* unbake published declaration: published_1aa3e2e75b9c3d80b23473d5 */
struct func_80228774_S7 {
    char pad0[0x130];
    f32 unk130;
};

union func_802626BC_S1_U10;
/* unbake published declaration: published_2b783af22cb66197dcb51b13 */
union func_802626BC_S1_U10 {
    s32 v0;
    void * v1;
};

union func_802626BC_S1_U10;
/* unbake published declaration: published_c800933b6cb83dbb544e9b2e */
typedef union func_802626BC_S1_U10 func_802626BC_S1_U10;

struct Handler;
/* unbake published declaration: published_1acad16891db463f071dfee4 */
struct Handler {
    char pad0[4];
    s16 id;
    char pad6[6];
    union {
        s32 (*targeted)(void *actor, struct Handler *entry, s32 target);
        s32 (*plain)(void *actor, struct Handler *entry);
    } handleC;
    s32 (*handle10)(void *actor, struct Handler *entry);
    s32 (*handle14)(void *actor, struct Handler *entry);
};

struct Shape_typemap_110;
/* unbake published declaration: published_55e4c4981b47eba05d05085e */
struct Shape_typemap_110 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
};

struct func_80258BB4_S1;
/* unbake published declaration: published_1ba2002454390fce44dd2376 */
struct func_80258BB4_S1 {
    char pad0[0x2BA4];
    float unk2BA4;
};

struct ALFilter_s14;
/* unbake published declaration: published_81443b36fa92e493852c1f47 */
typedef struct ALFilter_s14 ALFilter_s14;

struct ALFilter_s14;
/* unbake published declaration: published_b56631290d354695c1fa2f29 */
struct ALFilter_s14 {
    struct ALFilter_s14 *source;
    ALCmdHandler handler;
    void *setParam;
    s16 inp;
    s16 outp;
    s32 type;
};

struct func_8025BD20_S1;
/* unbake published declaration: published_1c5ee5b02a20c6f1b950de7b */
struct func_8025BD20_S1 {
    char pad0[0x4];
    char unk4;
};

/* unbake published declaration: published_1c9faf1a9bc904eac543007a */
extern int D_801005A8;

struct Key;
/* unbake published declaration: published_ba9cf19b27448ccad06decba */
struct Key {
    char pad0[0x14];
};

struct Key;
struct Owner_func_8041AD10_de;
/* unbake published declaration: published_1cc0ba573da4b949829a8397 */
struct Owner_func_8041AD10_de {
    char pad[0x38];
    struct Key *selected;
};

struct OSPfs_func_80445F80_de;
/* unbake published declaration: published_1d4057f01420b1b65a90ce7c */
typedef struct OSPfs_func_80445F80_de OSPfs_func_80445F80_de;

struct Entry_func_8023B9C0_eu;
/* unbake published declaration: published_27c312b131dd167a993db59c */
struct Entry_func_8023B9C0_eu {
    u16 id;
    u8 team;
    u8 slot;
};

struct Entry_func_8023B9C0_eu;
/* unbake published declaration: published_5777b54f092a8350e6a23785 */
typedef struct Entry_func_8023B9C0_eu Entry_func_8023B9C0_eu;

struct Shape_typemap_21;
/* unbake published declaration: published_1e5efcd752944d94fec91192 */
struct Shape_typemap_21 {
    unsigned char padding_0[16];
    unsigned char field_10;
};

struct Profile_func_80229554_de;
/* unbake published declaration: published_1e817df98aceafb95dd40385 */
struct Profile_func_80229554_de {
    char pad0[0x14];
    u8 bonus2;
    u8 bonus0;
    u8 bonus1;
    char pad17[0x190 - 0x17];
};

struct func_80212828_S2;
/* unbake published declaration: published_1eacabaec1066598de114af7 */
typedef struct func_80212828_S2 func_80212828_S2;

struct func_8029A73C_S1;
/* unbake published declaration: published_1eda1e2df2c8edca25b5fc14 */
struct func_8029A73C_S1 {
    char pad0[0x520];
    int unk520;
};

struct Field_u16_14;
/* unbake published declaration: published_b17a106e46b93c25521f4ec5 */
struct Field_u16_14 {
    char pad[0x14];
    u16 value;
};

struct func_8028469C_S2;
/* unbake published declaration: published_415757108c5581fe4c0543c0 */
struct func_8028469C_S2 {
    char pad0[0x38];
    void * unk38;
};

struct Block24;
/* unbake published declaration: published_1f8a2771ce11c5da3f6d6076 */
typedef struct Block24 Block24;

struct func_8028B3C0_S1;
/* unbake published declaration: published_2029da9dde7370791d569834 */
typedef struct func_8028B3C0_S1 func_8028B3C0_S1;

struct Plane_func_802965B0_de;
/* unbake published declaration: published_5d67de7bfacc64ef3aeb581d */
struct Plane_func_802965B0_de {
    Vec3 normal;
    f32 distance;
};

struct Plane_func_802965B0_de;
/* unbake published declaration: published_9abce325a4fd0dde198687bb */
typedef struct Plane_func_802965B0_de Plane_func_802965B0_de;

struct Extra;
/* unbake published declaration: published_21fd3bcfbe90e3620bc87fb2 */
struct Extra {
    s32 id;
    f32 scale;
};

struct Block;
/* unbake published declaration: published_32a576b418db63da879b5a72 */
struct Block {
    u8 pad000[0x100];
    s32 flags;
    u8 pad104[0x1DC];
    s32 value;
};

struct Block;
/* unbake published declaration: published_efe64ca945ee5873705aecf2 */
typedef struct Block Block;

struct func_80250BD4_S1;
/* unbake published declaration: published_225f708bc57899c3fb4388c1 */
struct func_80250BD4_S1 {
    char pad0[0x20];
    s32 * unk20;
};

struct Vec3Words;
/* unbake published declaration: published_22a17ae57e0bca8aa859eff5 */
struct Vec3Words {
    s32 w[3];
};

struct func_8022D418_S1;
/* unbake published declaration: published_2371cab836997265b3cd0d37 */
struct func_8022D418_S1 {
    char pad0[0x658];
    f32 unk658;
    char pad658[0x664 - 0x658 - sizeof(f32)];
    s32 unk664;
    char pad664[0x72C - 0x664 - sizeof(s32)];
    f32 unk72C;
    char pad72C[0x850 - 0x72C - sizeof(f32)];
    s32 unk850;
};

struct func_80293268_S2;
/* unbake published declaration: published_246dc1310be114e79f22f672 */
typedef struct func_80293268_S2 func_80293268_S2;

struct func_80207B5C_S2;
/* unbake published declaration: published_24cb05d7554101eb9e8e1fee */
typedef struct func_80207B5C_S2 func_80207B5C_S2;

/* unbake published declaration: published_24f68c327f52e802770c4b47 */
extern int D_8010515C;

struct Player_func_804356BC_de;
/* unbake published declaration: published_bc2cc2d266fcdd8cb192b4b0 */
struct Player_func_804356BC_de {
    char pad0[0x18];
    char slots[4][400];
    char pad658[0xB68 - 0x658];
};

struct StateFlags;
/* unbake published declaration: published_be54cdb02dee6359a629e0cf */
typedef struct StateFlags StateFlags;

struct StateFlags;
/* unbake published declaration: published_bfdfc89b329651e469d5c18a */
struct StateFlags {
    u16 value;
    u16 flags;
};

struct func_8024C864_S1;
/* unbake published declaration: published_2650d6e1f4daf47ca4d3a06d */
struct func_8024C864_S1 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
};

struct Queue_func_802517B4_de;
/* unbake published declaration: published_265196d59ac3231ebda495a7 */
typedef struct Queue_func_802517B4_de Queue_func_802517B4_de;

struct Desc;
/* unbake published declaration: published_2664019344de70ddd701313a */
struct Desc {
    char pad[0x108];
    s32 caps[4];
};

struct Owner_func_804441F4_de;
/* unbake published declaration: published_e846829241c7a7320f351480 */
struct Owner_func_804441F4_de {
    char pad[0x5D8];
    char *name;
};

struct func_8025CA44_S1;
/* unbake published declaration: published_27447c5c98fd48b6c5eda084 */
typedef struct func_8025CA44_S1 func_8025CA44_S1;

struct func_802B4ECC_S1;
/* unbake published declaration: published_2781f3e09b2f0ee3cd3c3a1a */
typedef struct func_802B4ECC_S1 func_802B4ECC_S1;

struct func_80207BB8_S4;
/* unbake published declaration: published_280b980b261521714a37fd9a */
typedef struct func_80207BB8_S4 func_80207BB8_S4;

struct func_8022BC04_S3;
/* unbake published declaration: published_28abda6dc46709745d37eeeb */
typedef struct func_8022BC04_S3 func_8022BC04_S3;

struct Rec_func_8024C92C_de;
/* unbake published declaration: published_85239b94a58723911cc0f63b */
typedef struct Rec_func_8024C92C_de Rec_func_8024C92C_de;

struct Rec_func_8024C92C_de;
/* unbake published declaration: published_dd21bc8a5cf928df342d2256 */
struct Rec_func_8024C92C_de {
    s32 x;
    s32 y;
    s32 z;
    s32 pad0;
    s32 pad1;
};

struct func_80204468_S2;
/* unbake published declaration: published_294ae9ec3ba2cbfd9a007446 */
struct func_80204468_S2 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x100 - 0x18 - sizeof(void*)];
    int unk100;
};

struct State_func_804232AC_de;
/* unbake published declaration: published_29589869f8f9245577a329a5 */
struct State_func_804232AC_de {
    void *menu;
    char pad4[0x20 - 4];
    s32 value;
};

struct HudStatusShared_MatchRules;
/* unbake published declaration: published_2a7dc2f253cb0eaffc5b10b4 */
typedef struct HudStatusShared_MatchRules HudStatusShared_MatchRules;

struct func_8022CA04_S3;
/* unbake published declaration: published_2a89e7a18cfb465b660fa2a0 */
struct func_8022CA04_S3 {
    char pad0[0x20];
    f32 unk20;
};

struct Params_func_802B2F10_de;
/* unbake published declaration: published_2a8de81772f595071fe100c3 */
typedef struct Params_func_802B2F10_de Params_func_802B2F10_de;

struct Node75;
/* unbake published declaration: published_5b09d6a5b24be0a6ab715262 */
struct Node75 {
    s32 pad0;
    Vec3 *prev;
    Vec3 *cur;
    Vec3 *next;
};

struct Field_s32_2E0;
/* unbake published declaration: published_2b34053b10cb5464f893964d */
typedef struct Field_s32_2E0 Field_s32_2E0;

/* unbake published declaration: published_2b9f5a9f73a212e4b16be6e4 */
extern int D_8014693C;

struct func_8028DA50_S1;
/* unbake published declaration: published_2bb5518843eebf76cc756ef2 */
struct func_8028DA50_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
};

struct InventorySlot;
/* unbake published declaration: published_35822f19f218196345816741 */
struct InventorySlot {
    u8 available;
    u8 slot;
};

struct InventorySlot;
/* unbake published declaration: published_35b8e01a89e251a7af93f44b */
typedef struct InventorySlot InventorySlot;

struct func_8024DED0_S2;
/* unbake published declaration: published_6cffbd2632e87174d87c3715 */
typedef struct func_8024DED0_S2 func_8024DED0_S2;

struct func_8024DED0_S2;
/* unbake published declaration: published_87952bbcb8b9e92e465e9c15 */
struct func_8024DED0_S2 {
    char pad0[0x4C];
    int unk4C;
};

struct Obj_func_80297DBC_de;
/* unbake published declaration: published_2cc6fec764ed91f0b9214654 */
typedef struct Obj_func_80297DBC_de Obj_func_80297DBC_de;

struct func_80242278_S2;
/* unbake published declaration: published_2d8d9b5fbf92dec8424ed9a3 */
struct func_80242278_S2 {
    char pad0[0x8];
    u8 unk8;
};

struct func_8023945C_S1;
/* unbake published declaration: published_a3f8e678c243d8b18953d311 */
struct func_8023945C_S1 {
    char pad0[0x128];
    Vec3 unk128;
};

struct func_80272848_S1;
/* unbake published declaration: published_2e270a5e3a702d6ecc70b74c */
struct func_80272848_S1 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    f32 unk14;
    char pad14[0x18 - 0x14 - sizeof(f32)];
    f32 unk18;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
    char pad24[0x28 - 0x24 - sizeof(f32)];
    f32 unk28;
    char pad28[0x2C - 0x28 - sizeof(f32)];
    f32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(f32)];
    f32 unk30;
    char pad30[0x34 - 0x30 - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
    char pad38[0x3C - 0x38 - sizeof(f32)];
    f32 unk3C;
};

struct ListScreenRecord;
/* unbake published declaration: published_98622db55a32be3dd6a25fd3 */
typedef struct ListScreenRecord ListScreenRecord;

struct ListScreenRecord;
/* unbake published declaration: published_e8b20ebcf6a3a90240d5e9c0 */
struct ListScreenRecord {
    char pad0[0x78];
    u8 active;
    char pad79[0x18];
    u8 out;
    char pad92[0x4];
};

struct Pool;
/* unbake published declaration: published_2e703458ff6524cf9bab13ad */
typedef struct Pool Pool;

struct func_80254D70_S1;
/* unbake published declaration: published_2e863c6916ad0cd8cddee1a8 */
typedef struct func_80254D70_S1 func_80254D70_S1;

struct func_80204EA8_S1;
/* unbake published declaration: published_2f788a22885baaa8261be6ac */
struct func_80204EA8_S1 {
    char pad0[0x8];
    Triple unk8;
};

/* unbake published declaration: published_2f854eb917d392155604fdcc */
extern IntrusiveList D_80137064;

struct func_802A68A0_S3;
/* unbake published declaration: published_2fd09ceb30ebda22c64e8ba7 */
typedef struct func_802A68A0_S3 func_802A68A0_S3;

/* unbake published declaration: published_31571e0add26581bb9d86538 */
extern float D_8010AC7C;

struct func_80258D60_S1;
/* unbake published declaration: published_31833af71a5cb5d5417f600e */
struct func_80258D60_S1 {
    char pad0[0x84];
    char unk84;
};

struct func_80239CD0_S1;
/* unbake published declaration: published_31a9087bcfa90786177375a2 */
struct func_80239CD0_S1 {
    char pad0[0x14];
    int unk14;
    char pad14[0x1C - 0x14 - sizeof(int)];
    int unk1C;
};

struct ObjectState14;
/* unbake published declaration: published_31ec7c0fcc97f140005b489c */
struct ObjectState14 {
    char pad0[0xC];
    s16 unk_C;
    char padC[0xE - 0xC - sizeof(s16)];
    s16 unk_E;
    char padE[0x10 - 0xE - sizeof(s16)];
    s16 unk_10;
    char pad10[0x12 - 0x10 - sizeof(s16)];
    s16 unk_12;
};

struct func_8020CA10_S2;
/* unbake published declaration: published_31f18d9de056eea90d90ee8b */
struct func_8020CA10_S2 {
    char pad0[0xC];
    u16 unkC;
};

struct ALEvent_func_802B21A8_de;
/* unbake published declaration: published_320df531b28aace7afa65389 */
struct ALEvent_func_802B21A8_de {
    s16 type;
    union {
        struct {
            s32 ticks;
            u8 status;
            u8 byte1;
            u8 byte2;
            u32 duration;
        } midi;
    } msg;
};

struct Object6C;
/* unbake published declaration: published_32ae5c4cb96c666c56775b57 */
struct Object6C {
    char pad[0x6C];
    s32 value;
};

struct func_8021CD70_S4;
/* unbake published declaration: published_e232acdbcbdf81d0e90a04d8 */
struct func_8021CD70_S4 {
    char pad0[0x564];
    s32 unk564;
};

struct Body;
struct Character;
struct Controller;
struct Controls;
struct Ctrl;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct Profile;
struct Record;
struct Rider;
struct Settings;
struct SharedPlayer_func_80226A34_de;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct func_8021CD70_S4;
/* unbake published declaration: published_fcf15580694f5651bcec8ab6 */
struct SharedPlayer_func_80226A34_de {
    union {
        struct {
            u8 unk0[24];
        } view0_0;
        struct {
            u8 pad0[24];
        } view0_1;
        struct {
            char pad[0x3];
            u8 team;
        } view3_2;
        struct {
            char pad[0x8];
            Vec3 unk8;
        } view8_2;
        struct {
            char pad[0x8];
            Vec3 pos;
        } view8_3;
        struct {
            char pad[0x8];
            Vec3 position;
        } view8_4;
        struct {
            char pad[0x14];
            struct Shared_Model * model;
        } view14_6;
        struct { char pad[8]; s32 positionWords[3]; } positionBits;
    } views0;
    union {
        struct {
            char * unk18;
        } view18_0;
        struct {
            char * track;
        } view18_1;
        struct {
            struct Model * model;
        } view18_2;
        struct {
            struct Body * body;
        } view18_3;
        struct {
            struct Character * character;
        } view18_4;
        struct {
            struct Shared_Body * body;
        } view18_5;
    } views18;
    union {
        struct {
            u8 unk1C[344];
        } view1C_0;
        struct {
            u8 pad1[344];
        } view1C_1;
        struct {
            char pad[0x4];
            f32 velY;
        } view20_2;
        struct {
            char pad[0x1C];
            s32 unk38;
        } view38_2;
        struct {
            char pad[0x1C];
            s32 flags;
        } view38_3;
        struct {
            char pad[0x24];
            f32 unk40;
        } view40_5;
        struct {
            char pad[0x40];
            Shared_Quad unk5C;
        } view5C_6;
        struct {
            char pad[0x50];
            f32 unk6C;
        } view6C_4;
        struct {
            char pad[0x50];
            f32 heading;
        } view6C_5;
        struct {
            char pad[0x50];
            f32 yaw;
        } view6C_9;
        struct {
            char pad[0xC8];
            u16 unkE4;
        } viewE4_6;
        struct {
            char pad[0xC8];
            u16 kind;
        } viewE4_7;
        struct {
            char pad[0xE4];
            s32 unk100;
        } view100_8;
        struct {
            char pad[0xE4];
            s32 flags;
        } view100_9;
        struct {
            char pad[0xE8];
            f32 unk104;
        } view104_10;
        struct {
            char pad[0xE8];
            f32 idleTime;
        } view104_11;
        struct {
            char pad[0xEC];
            s16 anim;
        } view108_16;
        struct {
            char pad[0xF2];
            s8 unk10E;
        } view10E_12;
        struct {
            char pad[0xF2];
            s8 idle;
        } view10E_13;
        struct {
            char pad[0xF2];
            s8 replaying;
        } view10E_14;
        struct {
            char pad[0xF2];
            s8 animPending;
        } view10E_20;
        struct {
            char pad[0x154];
            char unk170[100];
        } view170_15;
        struct {
            char pad[0x154];
            char body[100];
        } view170_16;
        struct {
            char pad[0x154];
            s32 unk170;
        } view170_23;
        struct {
            char pad[0x158];
            s32 unk174;
        } view174_17;
        struct {
            char pad[0x15C];
            u8 unk178[740];
        } view178_18;
        struct {
            char pad[0x15C];
            u8 pad2[740];
        } view178_19;
        struct {
            char pad[0x1B8];
            f32 unk1D4;
        } view1D4_20;
        struct {
            char pad[0x1B8];
            f32 holdTime;
        } view1D4_21;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80226A34_de * unk1D8;
        } view1D8_22;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80226A34_de * self;
        } view1D8_23;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80226A34_de * f1D8;
        } view1D8_24;
        struct {
            char pad[0x1BC];
            void * unk1D8;
        } view1D8_32;
        struct {
            char pad[0x244];
            Vec3 unk260;
        } view260_25;
        struct {
            char pad[0x244];
            Vec3 muzzle;
        } view260_26;
        struct {
            char pad[0x2CC];
            char unk2E8[368];
        } view2E8_27;
        struct {
            char pad[0x2CC];
            char weapon[368];
        } view2E8_28;
        struct {
            char pad[0x2CC];
            Shared_Emitter emitter;
        } view2E8_37;
        struct {
            char pad[0x43C];
            char unk458[384];
        } view458_29;
        struct {
            char pad[0x43C];
            char ammo[384];
        } view458_30;
        struct {
            char pad[0x43C];
            s32 unk458;
        } view458_40;
        struct {
            char pad[0x440];
            s32 unk45C;
        } view45C_31;
        struct {
            char pad[0x444];
            u8 unk460[376];
        } view460_32;
        struct {
            char pad[0x444];
            u8 pad3[376];
        } view460_33;
        struct {
            char pad[0x468];
            struct Shared_Voice * voice;
        } view484_44;
        struct {
            char pad[0x470];
            s8 unk48C;
        } view48C_34;
        struct {
            char pad[0x470];
            s8 state;
        } view48C_35;
        struct {
            char pad[0x4A4];
            void * unk4C0;
        } view4C0_47;
        struct {
            char pad[0x507];
            s8 unk523;
        } view523_36;
        struct {
            char pad[0x507];
            s8 busy;
        } view523_37;
        struct {
            char pad[0x578];
            s32 unk594;
        } view594_38;
        struct {
            char pad[0x578];
            s32 gear;
        } view594_39;
        struct {
            char pad[0x578];
            s32 mode;
        } view594_40;
        struct {
            char pad[0x584];
            f32 unk5A0;
        } view5A0_41;
        struct {
            char pad[0x584];
            f32 charge;
        } view5A0_42;
        struct {
            char pad[0x5B4];
            s32 unk5D0;
        } view5D0_43;
        struct {
            char pad[0x5B4];
            s32 f5D0;
        } view5D0_44;
        struct {
            char pad[0x5B8];
            s32 unk5D4;
        } view5D4_45;
        struct {
            char pad[0x5B8];
            s32 slot;
        } view5D4_46;
        struct {
            char pad[0x5B8];
            s32 profile;
        } view5D4_47;
        struct {
            char pad[0x5B8];
            s32 f5D4;
        } view5D4_48;
    } views1C;
    union {
        struct {
            struct Record * unk5D8;
        } view5D8_0;
        struct {
            struct Record * record;
        } view5D8_1;
        struct {
            struct Controls * controls;
        } view5D8_2;
        struct {
            struct TeamInfo * teamInfo;
        } view5D8_3;
        struct {
            struct Ctrl * ctrl;
        } view5D8_4;
        struct {
            unsigned char * info;
        } view5D8_5;
        struct {
            struct Profile * profile;
        } view5D8_6;
        struct {
            struct Settings * settings;
        } view5D8_7;
        struct {
            s32 f5D8;
        } view5D8_8;
        struct {
            struct Shared_Profile * profile;
        } view5D8_9;
    } views5D8;
    union {
        struct {
            void * unk5DC;
        } view5DC_0;
        struct {
            void * view;
        } view5DC_1;
        struct {
            struct func_8021CD70_S4 * view;
        } view5DC_2;
        struct {
            u8 pad4[8];
        } view5DC_3;
        struct {
            void * entity;
        } view5DC_4;
        struct {
            struct Rider * rider;
        } view5DC_5;
        struct {
            char * storage;
        } view5DC_6;
        struct {
            char * messages;
        } view5DC_7;
        struct {
            struct Shared_Hud * hud;
        } view5DC_8;
        struct {
            char pad[0x4];
            s32 unk5E0;
        } view5E0_8;
        struct {
            char pad[0x4];
            s32 state;
        } view5E0_9;
        struct {
            char pad[0x4];
            s32 slot;
        } view5E0_10;
    } views5DC;
    union {
        struct {
            s32 unk5E4;
        } view5E4_0;
        struct {
            s32 active;
        } view5E4_1;
        struct {
            s32 health;
        } view5E4_2;
        struct {
            s32 alive;
        } view5E4_3;
        struct {
            s32 holding;
        } view5E4_4;
    } views5E4;
    union {
        struct {
            u8 unk5E8[3140];
        } view5E8_0;
        struct {
            u8 pad5[3140];
        } view5E8_1;
        struct {
            char pad[0x2];
            s16 unk5EA;
        } view5EA_2;
        struct {
            char pad[0x2];
            s16 respawns;
        } view5EA_3;
        struct {
            char pad[0x2];
            s16 runType;
        } view5EA_4;
        struct {
            char pad[0x4];
            s32 unk5EC;
        } view5EC_5;
        struct {
            char pad[0x4];
            s32 model;
        } view5EC_6;
        struct {
            char pad[0x4];
            s32 spawnPoint;
        } view5EC_7;
        struct {
            char pad[0x4];
            s32 f5EC;
        } view5EC_8;
        struct {
            char pad[0x8];
            s32 unk5F0;
        } view5F0_9;
        struct {
            char pad[0x8];
            s32 f5F0;
        } view5F0_10;
        struct {
            char pad[0xC];
            s16 unk5F4[4];
        } view5F4_11;
        struct {
            char pad[0xC];
            s16 ammo[4];
        } view5F4_12;
        struct {
            char pad[0xC];
            s16 ammo[3];
        } view5F4_13;
        struct {
            char pad[0x1A];
            Shared_Slot slots[22];
        } view602_14;
        struct {
            char pad[0x46];
            s16 unk62E;
        } view62E_13;
        struct {
            char pad[0x46];
            s16 weapon;
        } view62E_14;
        struct {
            char pad[0x46];
            s16 character;
        } view62E_17;
        struct {
            char pad[0x68];
            s16 unk650;
        } view650_15;
        struct {
            char pad[0x68];
            s16 state;
        } view650_16;
        struct {
            char pad[0x68];
            s16 action;
        } view650_17;
        struct {
            char pad[0x68];
            s16 mode;
        } view650_18;
        struct {
            char pad[0x6A];
            s16 unk652;
        } view652_19;
        struct {
            char pad[0x6A];
            s16 previous;
        } view652_20;
        struct {
            char pad[0x6A];
            s16 pad652;
        } view652_24;
        struct {
            char pad[0x6C];
            s16 prevState;
        } view654_25;
        struct {
            char pad[0x6E];
            s16 pad656;
        } view656_26;
        struct {
            char pad[0x70];
            f32 unk658;
        } view658_21;
        struct {
            char pad[0x70];
            f32 counter;
        } view658_22;
        struct {
            char pad[0x70];
            f32 stride;
        } view658_23;
        struct {
            char pad[0x70];
            f32 swimTime;
        } view658_24;
        struct {
            char pad[0x70];
            f32 stateTime;
        } view658_31;
        struct {
            char pad[0x74];
            s32 unk65C;
        } view65C_32;
        struct {
            char pad[0x78];
            s32 unk660;
        } view660_25;
        struct {
            char pad[0x78];
            s32 previousTimer;
        } view660_26;
        struct {
            char pad[0x7C];
            s32 unk664;
        } view664_27;
        struct {
            char pad[0x7C];
            s32 timer;
        } view664_28;
        struct {
            char pad[0x84];
            f32 unk66C;
        } view66C_29;
        struct {
            char pad[0x88];
            f32 unk670;
        } view670_30;
        struct {
            char pad[0x88];
            f32 shield;
        } view670_31;
        struct {
            char pad[0x90];
            f32 unk678;
        } view678_40;
        struct {
            char pad[0xA0];
            char unk688[16];
        } view688_32;
        struct {
            char pad[0xA0];
            char body[16];
        } view688_33;
        struct {
            char pad[0xA0];
            Shared_Input input;
        } view688_43;
        struct {
            char pad[0xB0];
            struct Controller * unk698;
        } view698_34;
        struct {
            char pad[0xB0];
            struct Controller * controller;
        } view698_35;
        struct {
            char pad[0xB0];
            void * controller;
        } view698_36;
        struct {
            char pad[0xB0];
            char * emitter;
        } view698_37;
        struct {
            char pad[0xB0];
            char * title;
        } view698_38;
        struct {
            char pad[0xB4];
            f32 unk69C;
        } view69C_39;
        struct {
            char pad[0xB4];
            f32 stick;
        } view69C_40;
        struct {
            char pad[0xBC];
            f32 unk6A4;
        } view6A4_41;
        struct {
            char pad[0xBC];
            f32 strafe;
        } view6A4_42;
        struct {
            char pad[0xC0];
            f32 unk6A8;
        } view6A8_43;
        struct {
            char pad[0xC0];
            f32 lift;
        } view6A8_44;
        struct {
            char pad[0xC4];
            s32 unk6AC;
        } view6AC_45;
        struct {
            char pad[0xC8];
            s32 unk6B0;
        } view6B0_46;
        struct {
            char pad[0xC8];
            s32 input;
        } view6B0_47;
        struct {
            char pad[0xC8];
            s32 state;
        } view6B0_48;
        struct {
            char pad[0xD0];
            s32 unk6B8;
        } view6B8_49;
        struct {
            char pad[0xD0];
            s32 input;
        } view6B8_50;
        struct {
            char pad[0xD8];
            f32 unk6C0;
        } view6C0_51;
        struct {
            char pad[0xD8];
            f32 climb;
        } view6C0_52;
        struct {
            char pad[0xD8];
            f32 speed;
        } view6C0_53;
        struct {
            char pad[0xD8];
            f32 velX;
        } view6C0_64;
        struct {
            char pad[0xDC];
            f32 unk6C4;
        } view6C4_54;
        struct {
            char pad[0xDC];
            f32 side;
        } view6C4_55;
        struct {
            char pad[0xDC];
            f32 velZ;
        } view6C4_67;
        struct {
            char pad[0xE0];
            f32 unk6C8;
        } view6C8_56;
        struct {
            char pad[0xE0];
            f32 speed;
        } view6C8_57;
        struct {
            char pad[0xE4];
            f32 lastVelY;
        } view6CC_70;
        struct {
            char pad[0xE8];
            s32 onGround;
        } view6D0_71;
        struct {
            char pad[0xEC];
            f32 unk6D4;
        } view6D4_58;
        struct {
            char pad[0xF0];
            f32 unk6D8;
        } view6D8_59;
        struct {
            char pad[0xF4];
            f32 unk6DC;
        } view6DC_60;
        struct {
            char pad[0xFC];
            f32 unk6E4;
        } view6E4_61;
        struct {
            char pad[0xFC];
            f32 depth;
        } view6E4_62;
        struct {
            char pad[0xFC];
            f32 airTime;
        } view6E4_77;
        struct {
            char pad[0x100];
            f32 unk6E8;
        } view6E8_63;
        struct {
            char pad[0x100];
            Vec3 unk6E8;
        } view6E8_79;
        struct {
            char pad[0x104];
            f32 unk6EC;
        } view6EC_64;
        struct {
            char pad[0x104];
            f32 height;
        } view6EC_65;
        struct {
            char pad[0x108];
            f32 unk6F0;
        } view6F0_66;
        struct {
            char pad[0x10C];
            f32 unk6F4;
        } view6F4_83;
        struct {
            char pad[0x110];
            Vec3 unk6F8;
        } view6F8_84;
        struct {
            char pad[0x11C];
            f32 unk704;
        } view704_67;
        struct {
            char pad[0x11C];
            f32 lift;
        } view704_68;
        struct {
            char pad[0x130];
            f32 unk718;
        } view718_69;
        struct {
            char pad[0x130];
            f32 crouch;
        } view718_70;
        struct {
            char pad[0x134];
            s32 unk71C;
        } view71C_89;
        struct {
            char pad[0x138];
            f32 swim;
        } view720_90;
        struct {
            char pad[0x13C];
            f32 unk724;
        } view724_71;
        struct {
            char pad[0x13C];
            f32 pitch;
        } view724_72;
        struct {
            char pad[0x140];
            f32 unk728;
        } view728_73;
        struct {
            char pad[0x140];
            f32 kickPitch;
        } view728_74;
        struct {
            char pad[0x144];
            f32 unk72C;
        } view72C_75;
        struct {
            char pad[0x144];
            f32 kickRoll;
        } view72C_76;
        struct {
            char pad[0x144];
            f32 lean;
        } view72C_77;
        struct {
            char pad[0x148];
            f32 unk730[3];
        } view730_78;
        struct {
            char pad[0x148];
            f32 sway[3];
        } view730_79;
        struct {
            char pad[0x154];
            f32 unk73C;
        } view73C_80;
        struct {
            char pad[0x154];
            f32 side;
        } view73C_81;
        struct {
            char pad[0x154];
            Vec3 weapon;
        } view73C_82;
        struct {
            char pad[0x158];
            f32 unk740;
        } view740_83;
        struct {
            char pad[0x158];
            f32 height;
        } view740_84;
        struct {
            char pad[0x15C];
            f32 unk744;
        } view744_85;
        struct {
            char pad[0x15C];
            f32 forward;
        } view744_86;
        struct {
            char pad[0x170];
            f32 unk758;
        } view758_87;
        struct {
            char pad[0x170];
            f32 bobStrength;
        } view758_88;
        struct {
            char pad[0x174];
            f32 unk75C;
        } view75C_89;
        struct {
            char pad[0x174];
            f32 bobSpeed;
        } view75C_90;
        struct {
            char pad[0x188];
            s16 unk770;
        } view770_91;
        struct {
            char pad[0x188];
            s16 nextWeapon;
        } view770_92;
        struct {
            char pad[0x188];
            s16 weapon;
        } view770_113;
        struct {
            char pad[0x18A];
            s16 pad772;
        } view772_114;
        struct {
            char pad[0x18C];
            Vec3 unk774;
        } view774_115;
        struct {
            char pad[0x198];
            f32 unk780;
        } view780_116;
        struct {
            char pad[0x19C];
            f32 unk784;
        } view784_117;
        struct {
            char pad[0x1A0];
            s32 unk788;
        } view788_93;
        struct {
            char pad[0x1A0];
            s32 icons;
        } view788_94;
        struct {
            char pad[0x1B0];
            s32 unk798;
        } view798_95;
        struct {
            char pad[0x1B0];
            s32 carried;
        } view798_96;
        struct {
            char pad[0x1B4];
            Vec3 unk79C;
        } view79C_97;
        struct {
            char pad[0x1B4];
            Vec3 carriedPosition;
        } view79C_98;
        struct {
            char pad[0x1D0];
            s32 unk7B8;
        } view7B8_99;
        struct {
            char pad[0x1D0];
            s32 target;
        } view7B8_100;
        struct {
            char pad[0x1D4];
            f32 unk7BC;
        } view7BC_101;
        struct {
            char pad[0x1D4];
            f32 timer;
        } view7BC_102;
        struct {
            char pad[0x1D8];
            Vec3 unk7C0;
        } view7C0_103;
        struct {
            char pad[0x1D8];
            Vec3 targetPosition;
        } view7C0_104;
        struct {
            char pad[0x200];
            s32 unk7E8;
        } view7E8_105;
        struct {
            char pad[0x200];
            s32 zoomed;
        } view7E8_106;
        struct {
            char pad[0x204];
            f32 unk7EC;
        } view7EC_132;
        struct {
            char pad[0x208];
            f32 unk7F0;
        } view7F0_133;
        struct {
            char pad[0x224];
            struct Mount * unk80C;
        } view80C_107;
        struct {
            char pad[0x224];
            struct Mount * mount;
        } view80C_108;
        struct {
            char pad[0x228];
            s32 unk810;
        } view810_109;
        struct {
            char pad[0x228];
            s32 kind;
        } view810_110;
        struct {
            char pad[0x22C];
            Triple unk814;
        } view814_111;
        struct {
            char pad[0x22C];
            Triple offset;
        } view814_112;
        struct {
            char pad[0x250];
            f32 unk838;
        } view838_113;
        struct {
            char pad[0x250];
            f32 rideTime;
        } view838_114;
        struct {
            char pad[0x254];
            f32 unk83C;
        } view83C_115;
        struct {
            char pad[0x254];
            f32 bump;
        } view83C_116;
        struct {
            char pad[0x258];
            s32 unk840;
        } view840_117;
        struct {
            char pad[0x258];
            s32 surfaced;
        } view840_118;
        struct {
            char pad[0x264];
            s32 unk84C;
        } view84C_149;
        struct {
            char pad[0x26C];
            f32 unk854;
        } view854_147;
        struct {
            char pad[0x274];
            s32 unk85C;
        } view85C_119;
        struct {
            char pad[0x274];
            s32 w85C;
        } view85C_120;
        struct {
            char pad[0x27C];
            s32 unk864;
        } view864_121;
        struct {
            char pad[0x27C];
            s32 f864;
        } view864_122;
        struct {
            char pad[0x280];
            s32 unk868;
        } view868_123;
        struct {
            char pad[0x280];
            s32 f868;
        } view868_124;
        struct {
            char pad[0x284];
            s32 unk86C;
        } view86C_125;
        struct {
            char pad[0x284];
            s32 parameter;
        } view86C_126;
        struct {
            char pad[0x284];
            s32 animation;
        } view86C_127;
        struct {
            char pad[0x288];
            s32 unk870;
        } view870_157;
        struct {
            char pad[0x290];
            Shared_Effect effect;
        } view878_158;
        struct {
            char pad[0x350];
            char unk938[2188];
        } view938_128;
        struct {
            char pad[0x350];
            char strokes[2188];
        } view938_129;
        struct {
            char pad[0x350];
            char strokes[2188];
        } view938_130;
        struct {
            char pad[0x350];
            s32 unk938;
        } view938_162;
        struct {
            char pad[0x6D0];
            s32 unkCB8;
        } viewCB8_163;
        struct {
            char pad[0x6E4];
            s32 unkCCC;
        } viewCCC_164;
        struct {
            char pad[0x758];
            s32 unkD40;
        } viewD40_165;
        struct {
            char pad[0x96C];
            s32 unkF54;
        } viewF54_131;
        struct {
            char pad[0x96C];
            s32 selection;
        } viewF54_132;
        struct {
            char pad[0x9A8];
            s32 unkF90;
        } viewF90_133;
        struct {
            char pad[0x9A8];
            s32 choice;
        } viewF90_134;
        struct {
            char pad[0xBCC];
            s32 unk11B4;
        } view11B4_135;
        struct {
            char pad[0xBCC];
            s32 locked;
        } view11B4_136;
        struct {
            char pad[0xBD0];
            s32 unk11B8;
        } view11B8_137;
        struct {
            char pad[0xBD0];
            s32 frozen;
        } view11B8_138;
        struct {
            char pad[0xBD4];
            s32 unk11BC;
        } view11BC_139;
        struct {
            char pad[0xBD4];
            s32 f11BC;
        } view11BC_140;
        struct {
            char pad[0xBD8];
            s32 unk11C0;
        } view11C0_141;
        struct {
            char pad[0xBD8];
            s32 f11C0;
        } view11C0_142;
        struct {
            char pad[0xBDC];
            f32 unk11C4;
        } view11C4_143;
        struct {
            char pad[0xBDC];
            f32 soundTime;
        } view11C4_144;
        struct {
            char pad[0xBE4];
            s32 unk11CC;
        } view11CC_145;
        struct {
            char pad[0xBE4];
            s32 f11CC;
        } view11CC_146;
        struct {
            char pad[0xBF0];
            f32 unk11D8;
        } view11D8_147;
        struct {
            char pad[0xBF0];
            f32 recoil;
        } view11D8_148;
        struct {
            char pad[0xBF0];
            f32 stun;
        } view11D8_149;
        struct {
            char pad[0xBF4];
            f32 unk11DC;
        } view11DC_185;
        struct {
            char pad[0xBF8];
            f32 unk11E0;
        } view11E0_186;
        struct {
            char pad[0xC00];
            s32 unk11E8;
        } view11E8_150;
        struct {
            char pad[0xC00];
            s32 f11E8;
        } view11E8_151;
        struct {
            char pad[0xC04];
            f32 unk11EC;
        } view11EC_189;
        struct {
            char pad[0xC28];
            s32 unk1210;
        } view1210_152;
        struct {
            char pad[0xC28];
            s32 marker;
        } view1210_153;
        struct {
            char pad[0xC2C];
            s32 unk1214;
        } view1214_154;
        struct {
            char pad[0xC2C];
            s32 marker;
        } view1214_155;
        struct {
            char pad[0xC2C];
            s32 markerShown;
        } view1214_156;
        struct {
            char pad[0xC30];
            s32 unk1218;
        } view1218_157;
        struct {
            char pad[0xC30];
            s32 f1218;
        } view1218_158;
        struct {
            char pad[0xC34];
            s32 unk121C;
        } view121C_159;
        struct {
            char pad[0xC34];
            s32 f121C;
        } view121C_160;
        struct {
            char pad[0xC38];
            s32 unk1220;
        } view1220_161;
        struct {
            char pad[0xC38];
            s32 f1220;
        } view1220_162;
        struct { char pad[0xE]; s16 charge; } chargeView;
        struct { char pad[0x11F4 - 0x5E8]; f32 spin; s32 frame; } rapidFireView;
    } views5E8;
    union {
        struct {
            u32 unk122C;
        } view122C_0;
        struct {
            u32 flags;
        } view122C_1;
        struct {
            s32 options;
        } view122C_2;
        struct {
            s32 f122C;
        } view122C_3;
        struct {
            s32 fxFlags;
        } view122C_4;
    } views122C;
    f32 fxTime;
    f32 fxSpeed;
    s32 fxStage;
    char pad123C[0x4];
    f32 unk1240;
    f32 unk1244;
    char pad1248[0x7C];
    union {
        struct {
            s32 unk12C4;
        } view12C4_0;
        struct {
            s32 f12C4;
        } view12C4_1;
    } views12C4;
    union {
        struct {
            s32 unk12C8;
        } view12C8_0;
        struct {
            s32 f12C8;
        } view12C8_1;
    } views12C8;
    union {
        struct {
            s32 unk12CC[8];
        } view12CC_0;
        struct {
            s32 splitsA[8];
        } view12CC_1;
    } views12CC;
    s32 unk12EC;
    char pad12F0[0x4];
    union {
        struct {
            s32 unk12F4[8];
        } view12F4_0;
        struct {
            s32 splitsB[8];
        } view12F4_1;
    } views12F4;
    char pad1314[0x20];
    union {
        struct {
            s32 unk1334;
        } view1334_0;
        struct {
            s32 f1334;
        } view1334_1;
    } views1334;
    union {
        struct {
            s32 unk1338;
        } view1338_0;
        struct {
            s32 f1338;
        } view1338_1;
    } views1338;
    union {
        struct {
            s32 unk133C;
        } view133C_0;
        struct {
            s32 laps;
        } view133C_1;
        struct {
            s32 lives;
        } view133C_2;
    } views133C;
    union {
        struct {
            s32 unk1340;
        } view1340_0;
        struct {
            s32 stalls;
        } view1340_1;
        struct {
            s32 timer;
        } view1340_2;
        struct {
            s32 respawnTimer;
        } view1340_3;
    } views1340;
    char pad1344[0x70];
    union {
        struct {
            struct StateInfo * unk13B4;
        } view13B4_0;
        struct {
            struct StateInfo * states;
        } view13B4_1;
        struct {
            struct Mode * unk13B4;
        } view13B4_2;
        struct {
            void * character;
        } view13B4_3;
        struct {
            s32 f13B4;
        } view13B4_4;
        struct {
            struct Shared_StateInfo * states;
        } view13B4_5;
    } views13B4;
    char pad13B8[0x10];
    union {
        struct {
            s32 unk13C8;
        } view13C8_0;
        struct {
            s32 w13C8;
        } view13C8_1;
        struct {
            s32 f13C8;
        } view13C8_2;
    } views13C8;
    char pad13CC[0x8];
    s32 unk13D4;
    union {
        struct {
            struct Held * unk13D8;
        } view13D8_0;
        struct {
            struct Held * held;
        } view13D8_1;
    } views13D8;
    char pad13DC[0xC];
    s32 messageIndex;
    char pad13EC[0x64];
    union {
        struct {
            s32 unk1450;
        } view1450_0;
        struct {
            s32 computer;
        } view1450_1;
        struct {
            s32 infinite;
        } view1450_2;
        struct {
            s32 unlimited;
        } view1450_3;
        struct {
            s32 uncounted;
        } view1450_4;
        struct {
            s32 f1450;
        } view1450_5;
    } views1450;
    union {
        struct {
            s32 unk1454;
        } view1454_0;
        struct {
            s32 f1454;
        } view1454_1;
    } views1454;
    char pad1458[0xC];
    union {
        struct {
            Vec3 unk1464;
        } view1464_0;
        struct {
            Vec3 aim;
        } view1464_1;
    } views1464;
    char pad1470[0x10];
    union {
        struct {
            Matrix unk1480[2];
        } view1480_0;
        struct {
            Matrix beams[2];
        } view1480_1;
    } views1480;
    union {
        struct {
            Matrix unk1500[2];
        } view1500_0;
        struct {
            Matrix lasers[2];
        } view1500_1;
    } views1500;
    union {
        struct {
            Matrix unk1580[2];
        } view1580_0;
        struct {
            Matrix dots[2];
        } view1580_1;
    } views1580;
    char pad1600[0xD4];
    union {
        struct {
            s32 unk16D4;
        } view16D4_0;
        struct {
            s32 f16D4;
        } view16D4_1;
    } views16D4;
    u16 unk16D8;
    char pad16DA[0x6];
    union {
        struct {
            struct SharedPlayer_func_80226A34_de * unk16E0;
        } view16E0_0;
        struct {
            struct SharedPlayer_func_80226A34_de * next;
        } view16E0_1;
        struct {
            struct SharedPlayer_func_80226A34_de * next;
        } view16E0_2;
    } views16E0;
};

union func_80239C2C_S1_UF24;
/* unbake published declaration: published_337e0632dec190355a1f769b */
union func_80239C2C_S1_UF24 {
    void * v0;
    char v1;
};

struct ALHeap;
/* unbake published declaration: published_e651c1758be9c69209ec0c82 */
struct ALHeap {
    u8 *base;
    u8 *cur;
    s32 len;
    s32 count;
};

struct Item_func_8043C9AC_de;
/* unbake published declaration: published_3466f91618c58c36f5d0a546 */
typedef struct Item_func_8043C9AC_de Item_func_8043C9AC_de;

struct StateBlock;
/* unbake published declaration: published_347829ca349ec21ae611e457 */
typedef struct StateBlock StateBlock;

struct Style_func_8043C9AC_de;
/* unbake published declaration: published_34ae20ebe8a7bf2d98fee430 */
struct Style_func_8043C9AC_de {
    char pad0[0x30];
    f32 alpha;
    f32 fade;
};

struct Owner_func_8043DB04_de;
/* unbake published declaration: published_90b8dcdc07b3dd75b22144d4 */
struct Owner_func_8043DB04_de {
    char pad[0x5D0];
    s32 value;
};

struct Holder;
struct Owner_func_8043DB04_de;
/* unbake published declaration: published_34bf03291d15e7949420b25d */
struct Holder {
    char pad[0x1C];
    struct Owner_func_8043DB04_de *owner;
};

struct CallbackStateC_4;
/* unbake published declaration: published_34dc9aaf9df7d94751142442 */
typedef struct CallbackStateC_4 CallbackStateC_4;

struct Field_void_4;
/* unbake published declaration: published_35084dae1dd0bf543bd97a38 */
struct Field_void_4 {
    char pad[0x4];
    void * value;
};

struct Obj_func_802B20D4_de;
/* unbake published declaration: published_52315c1ec7bee79da5dec97d */
struct Obj_func_802B20D4_de {
    char pad18[0x18];
    s16 field18;
};

struct func_8022ED94_S1;
/* unbake published declaration: published_3570a11fa2e554c79bd6643e */
struct func_8022ED94_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
};

union func_80239C2C_S1_UF24;
/* unbake published declaration: published_805fcf110675d765a05e7d4a */
typedef union func_80239C2C_S1_UF24 func_80239C2C_S1_UF24;

struct Item_func_8042B4D4_de;
/* unbake published declaration: published_35e14301611e585353a17c53 */
struct Item_func_8042B4D4_de {
    char pad[0x10];
    u8 alpha;
    char pad11[0x14 - 0x11];
    s16 x;
};

struct func_8022EA2C_S1;
/* unbake published declaration: published_35ea266e8edec7bc22ec0e80 */
typedef struct func_8022EA2C_S1 func_8022EA2C_S1;

struct Draw;
/* unbake published declaration: published_3635d0476a8a3565006d279b */
typedef struct Draw Draw;

struct func_80258614_S1;
/* unbake published declaration: published_374542d99ec5e7759db805b1 */
typedef struct func_80258614_S1 func_80258614_S1;

struct State_func_8042D8C4_de;
/* unbake published declaration: published_384fce218963309e34fe08b0 */
struct State_func_8042D8C4_de {
    char pad[0xE8];
    s32 count;
};

union func_8026E158_S1_U8;
/* unbake published declaration: published_38b624a81da70d6c3e40d657 */
typedef union func_8026E158_S1_U8 func_8026E158_S1_U8;

struct ALMIDIEvent;
/* unbake published declaration: published_95f878d168e488b7378d8a75 */
struct ALMIDIEvent {
    s32 ticks;
    u8 status;
    u8 byte1;
    u8 byte2;
    u32 duration;
};

struct Func802608ECResult;
/* unbake published declaration: published_73b684e56276861bc857d8fe */
typedef struct Func802608ECResult Func802608ECResult;

struct Func802608ECResult;
/* unbake published declaration: published_7deedb7344cd72029b05f48a */
struct Func802608ECResult {
    u32 value;
    f32 start;
    f32 delta;
};

struct MenuRules;
/* unbake published declaration: published_3a4673226d5c1b9b320be164 */
typedef struct MenuRules MenuRules;

struct Extra;
/* unbake published declaration: published_7e1d5db5ab83a881ca75cf54 */
typedef struct Extra Extra;

struct ALSynth_func_802B3000_de;
/* unbake published declaration: published_3b9f8afa7cf59d544c612d16 */
struct ALSynth_func_802B3000_de {
    void *head;
    Link_func_802596B4_de pFreeList;
    Link_func_802596B4_de pAllocList;
    Link_func_802596B4_de pLameList;
    s32 paramSamples;
};

struct func_8025E58C_S1;
/* unbake published declaration: published_3c831a0418582e6814d5e6c3 */
struct func_8025E58C_S1 {
    char pad0[0x10];
    short unk10;
};

struct func_8024C654_S1;
/* unbake published declaration: published_3cc6b4e023f08569de18d9de */
typedef struct func_8024C654_S1 func_8024C654_S1;

struct func_80254D70_S2;
/* unbake published declaration: published_3d227b945e105164a22e5890 */
typedef struct func_80254D70_S2 func_80254D70_S2;

struct Node75_func_802750B0_de;
/* unbake published declaration: published_3db38929be33ba46ce03e750 */
typedef struct Node75_func_802750B0_de Node75_func_802750B0_de;

struct func_80207F90_S1;
/* unbake published declaration: published_3ffc70c1edf5a46f3370bc14 */
struct func_80207F90_S1 {
    char pad0[0x100];
    unsigned int unk100;
};

/* unbake published declaration: published_4044050f960d35044af6d1df */
extern int D_80145048;

struct func_802A2E5C_S2;
/* unbake published declaration: published_4087c6f8ae324af8ffd0f478 */
typedef struct func_802A2E5C_S2 func_802A2E5C_S2;

struct Entry_func_8041EB50_de;
/* unbake published declaration: published_40a58bb2c2640eb233c8d0df */
struct Entry_func_8041EB50_de {
    s32 value;
    char pad[28 - 4];
};

struct func_80229BE0_S2;
/* unbake published declaration: published_e9152f81eecf0d527b51253b */
typedef struct func_80229BE0_S2 func_80229BE0_S2;

struct func_8022D418_S1;
/* unbake published declaration: published_4143f5b231a68b223416c4a3 */
typedef struct func_8022D418_S1 func_8022D418_S1;

struct ObjectLinks24_2;
/* unbake published declaration: published_419243f315c290f9c6613650 */
typedef struct ObjectLinks24_2 ObjectLinks24_2;

struct func_80245690_S1;
/* unbake published declaration: published_42763ffed19f6f43aa981fae */
struct func_80245690_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x38 - 0x4 - sizeof(s32)];
    s32 unk38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    s32 unk3C;
    char pad3C[0x60 - 0x3C - sizeof(s32)];
    s32 unk60;
};

struct Resource_func_804101BC_de;
/* unbake published declaration: published_42a92dc0426047c98e5d73bf */
struct Resource_func_804101BC_de {
    s32 id;
    s16 retained;
    s16 unused;
};

struct Field_Vec_18;
/* unbake published declaration: published_4306296485f0022a5315c57b */
struct Field_Vec_18 {
    char pad[0x18];
    Vec3 value;
};

struct func_8022EA2C_S1;
/* unbake published declaration: published_f2f93c922daf25ab4bd3847e */
struct func_8022EA2C_S1 {
    char pad0[0x2];
    u16 unk2;
};

/* unbake published declaration: published_4335da24c87791fec9c1e6b6 */
extern int D_80111D24;

struct func_80205700_S1;
/* unbake published declaration: published_4385d0277eec985a1ade5f36 */
typedef struct func_80205700_S1 func_80205700_S1;

struct func_8024E58C_S1;
/* unbake published declaration: published_439305f25cfe72ba8dd69e40 */
typedef struct func_8024E58C_S1 func_8024E58C_S1;

struct Player_func_80434750_de;
/* unbake published declaration: published_43a3a290701fee34fcd1ba88 */
typedef struct Player_func_80434750_de Player_func_80434750_de;

struct ObjectState14;
/* unbake published declaration: published_43e9c1eec313214faad3ee75 */
typedef struct ObjectState14 ObjectState14;

union func_8022E280_S1_U744;
/* unbake published declaration: published_8d8d5558117ec17fbc55d18b */
typedef union func_8022E280_S1_U744 func_8022E280_S1_U744;

union func_8022E280_S1_U744;
/* unbake published declaration: published_f44bca49e49e5273fde40929 */
union func_8022E280_S1_U744 {
    s32 v0;
    f32 v1;
};

struct Record_func_8043E494_de;
/* unbake published declaration: published_fbed43d2212e770be1de4696 */
struct Record_func_8043E494_de {
    char pad[0x7B];
    s8 mode;
};

struct Owner_func_8043E494_de;
struct Record_func_8043E494_de;
struct Owner_func_8043E494_de {
    char pad[0x5D8];
    struct Record_func_8043E494_de *record;
};
struct Menu_func_8043E494_de;
struct Owner_func_8043E494_de;
/* unbake published declaration: published_44ad4689a613ae056fe0d867 */
struct Menu_func_8043E494_de {
    char pad[0x1C];
    struct Owner_func_8043E494_de *owner;
};

struct func_8025C8F8_S1;
/* unbake published declaration: published_44d5d495182d5b02214fb13f */
typedef struct func_8025C8F8_S1 func_8025C8F8_S1;

struct Cell_func_80421BEC_de;
/* unbake published declaration: published_aab95ed50bfcc56183722dfc */
struct Cell_func_80421BEC_de {
    char pad[0x16];
    s16 unk16;
    s16 unk18;
    s16 unk1A;
};

struct Cell_func_80421BEC_de;
struct Obj_func_80421BEC_de;
struct Obj_func_80421BEC_de {
    char pad[0x44];
    struct Cell_func_80421BEC_de *unk44;
};
struct Cell_func_80421BEC_de;
struct Obj_func_80421BEC_de;
struct State_func_80421BEC_de;
/* unbake published declaration: published_44f8e179285419fc64cb690b */
struct State_func_80421BEC_de {
    struct Obj_func_80421BEC_de *unk0;
    s32 unk4;
    struct Cell_func_80421BEC_de *unk8;
    s32 unkC;
    s32 unk10;
};

struct func_80228774_S4;
/* unbake published declaration: published_45be82d5f14b46d060576a03 */
typedef struct func_80228774_S4 func_80228774_S4;

struct func_802165F8_S1;
/* unbake published declaration: published_4621e415bab0bc49c4c1bc88 */
typedef struct func_802165F8_S1 func_802165F8_S1;

struct Access_s32_5C;
/* unbake published declaration: published_46ae33f652dd96cec3dd7175 */
struct Access_s32_5C {
    char pad[0x5C];
    s32 field;
};

struct ObjectState1E_2;
/* unbake published declaration: published_48034f6af36ac72f7a5fbaad */
struct ObjectState1E_2 {
    char pad0[0x1D];
    u8 unk_1D;
};

struct func_80258BB4_S1;
/* unbake published declaration: published_4818a797a78536bad09335cf */
typedef struct func_80258BB4_S1 func_80258BB4_S1;

struct func_80255BEC_S1;
/* unbake published declaration: published_488a9cb4630c5e7ff2265e14 */
typedef struct func_80255BEC_S1 func_80255BEC_S1;

struct State_func_8043E254_de;
/* unbake published declaration: published_4aeb528a0291b09c87e50410 */
typedef struct State_func_8043E254_de State_func_8043E254_de;

struct func_80204EA8_S1;
/* unbake published declaration: published_4b9c1093430d3674d4fc2d04 */
typedef struct func_80204EA8_S1 func_80204EA8_S1;

struct __OSDir;
/* unbake published declaration: published_4bdea319ec2c27b0cff61b31 */
typedef struct __OSDir __OSDir;

struct func_80255BEC_S1;
/* unbake published declaration: published_bde8dc471c892c9222b99039 */
struct func_80255BEC_S1 {
    char pad0[0x8];
    void * unk8;
};

struct BufferPool;
/* unbake published declaration: published_4c1c9130b919f5e6e6c7f61c */
struct BufferPool {
    s16 count;
    func_80255BEC_S1 *primary;
    func_80255BEC_S1 *secondary;
    u16 *flags;
    s16 *refs;
};

struct Node_func_80239AF4_de;
/* unbake published declaration: published_98bfc26f8fb365bb72cfd018 */
typedef struct Node_func_80239AF4_de Node_func_80239AF4_de;

struct Node_func_80239AF4_de;
/* unbake published declaration: published_f73cf1994272ba27b6ed1bd9 */
struct Node_func_80239AF4_de {
    struct Node_func_80239AF4_de *next;
};

struct func_8022BECC_S2;
/* unbake published declaration: published_4ceed9857a45d6c818c111ec */
typedef struct func_8022BECC_S2 func_8022BECC_S2;

struct Controller_func_80217B3C_de;
/* unbake published declaration: published_4d53d15b8630596477569b16 */
struct Controller_func_80217B3C_de {
    char pad0[0xC6];
    s8 x;
    s8 y;
};

struct Event_func_8024C1C4_de;
struct Shape_func_802764D4_de_2;
/* unbake published declaration: published_4d71599d48ccee696fd3546c */
struct Event_func_8024C1C4_de {
    u16 frame;
    u16 effect;
    s16 bone;
    s16 pad6;
    Vec3 local;
    struct Shape_func_802764D4_de_2 params;
};

struct Record_func_80208158_de;
/* unbake published declaration: published_d6f4137e387641dff8cda5bf */
struct Record_func_80208158_de {
    char pad0[0x80];
    s8 kind;
    char pad81[0x13];
    u8 display;
};

struct __OSContRequesFormat;
/* unbake published declaration: published_4f4813086e93098646cea1bd */
struct __OSContRequesFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
    u8 dummy1;
};

struct func_80272908_S2;
/* unbake published declaration: published_4fbe5fc8146bcb9f82b0d282 */
struct func_80272908_S2 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    f32 unk14;
    char pad14[0x18 - 0x14 - sizeof(f32)];
    f32 unk18;
    char pad18[0x20 - 0x18 - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
    char pad24[0x28 - 0x24 - sizeof(f32)];
    f32 unk28;
    char pad28[0x30 - 0x28 - sizeof(f32)];
    f32 unk30;
    char pad30[0x34 - 0x30 - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
};

struct WeaponInfo;
/* unbake published declaration: published_500c9290ad76e46bd4826f50 */
struct WeaponInfo {
    char pad0[0x20];
    s16 *weaponClass;
};

struct func_8022E694_S1;
/* unbake published declaration: published_503f43d3e760e7c04c703568 */
typedef struct func_8022E694_S1 func_8022E694_S1;

struct Slot;
/* unbake published declaration: published_50ae37e54793a854efed0939 */
typedef struct Slot Slot;

struct func_8025E52C_S1;
/* unbake published declaration: published_50e81e234e294aec8be023ac */
struct func_8025E52C_S1 {
    char pad0[0x2];
    short unk2;
};

struct Effect_func_8024A1D0_de;
/* unbake published declaration: published_51a7e343f95783055b03021d */
typedef struct Effect_func_8024A1D0_de Effect_func_8024A1D0_de;

struct Field_Vec_18;
/* unbake published declaration: published_51c3db92683b88451bb7fd63 */
typedef struct Field_Vec_18 Field_Vec_18;

struct ALVoiceConfig_s;
/* unbake published declaration: published_522b248798b99523293f1dad */
typedef struct ALVoiceConfig_s ALVoiceConfig_s;

struct InstanceHdr;
/* unbake published declaration: published_7d3590cc1e6ec99bead71137 */
struct InstanceHdr {
    s32 w[5];
};

struct func_8023EBEC_S1;
/* unbake published declaration: published_52fe8c30caac31977b2d8cf5 */
typedef struct func_8023EBEC_S1 func_8023EBEC_S1;

/* unbake published declaration: published_530fb81c51ad21d5670bf13c */
extern int D_800CB720;

struct Input80216D3C;
/* unbake published declaration: published_53205c48a818f9da2d1d7b66 */
typedef struct Input80216D3C Input80216D3C;

struct __OSDir;
/* unbake published declaration: published_53d97a666f0179a92f04ab1e */
struct __OSDir {
    u32 game_code;
    u16 company_code;
    __OSInodeUnit start_page;
    u8 status;
    s8 reserved;
    u16 data_sum;
    u8 ext_name[4];
    u8 game_name[16];
};

struct Element_func_8041200C_de;
/* unbake published declaration: published_54263f45d638e112eee9c973 */
typedef struct Element_func_8041200C_de Element_func_8041200C_de;

struct func_80207F90_S1;
/* unbake published declaration: published_542b7b864104510ae33352c2 */
typedef struct func_80207F90_S1 func_80207F90_S1;

struct Part;
/* unbake published declaration: published_547fbc9d07c0e2e77eaba5fd */
struct Part {
    char pad[0x78];
    u8 active;
};

struct Player_func_8041EAC4_de;
/* unbake published declaration: published_54e8b6964f4fcf9f1e68d7f6 */
struct Player_func_8041EAC4_de {
    char pad0[0x78];
    u8 active;
    char pad79[0x96 - 0x79];
};

struct TextEntry;
/* unbake published declaration: published_54ea28b4b4c78c652dc6aa80 */
struct TextEntry {
    s32 id;
    char **text;
};

struct Node75_func_802750B0_de;
/* unbake published declaration: published_54f35d0a262e7889893e370a */
struct Node75_func_802750B0_de {
    int pad0;
    void *prev;
    void *cur;
    void *next;
};

struct Label;
/* unbake published declaration: published_5553c7e52b076d457900d062 */
struct Label {
    char pad0[0x38];
    char *text;
};

struct func_80228774_S6;
/* unbake published declaration: published_55643695e0f7db13f6d08ba9 */
typedef struct func_80228774_S6 func_80228774_S6;

struct Effect_func_8024A1D0_de;
/* unbake published declaration: published_55a9219cf0bd746720675da4 */
struct Effect_func_8024A1D0_de {
    unsigned char pad0[0x150];
    f32 field150;
    f32 field154;
};

struct Shape;
/* unbake published declaration: published_83b76873a4822e73395a988b */
struct Shape {
    s32 flags;
    s8 enabled;
};

struct Shape;
/* unbake published declaration: published_ad73f029ceee340381d6b8c8 */
typedef struct Shape Shape;

struct UnitVtx;
/* unbake published declaration: published_5653f462969607198f7238dd */
typedef struct UnitVtx UnitVtx;

struct Access_u8_3;
/* unbake published declaration: published_56b142b7b8c93cfe3a917886 */
struct Access_u8_3 {
    char pad[0x3];
    u8 field;
};

struct Actor_func_80214310_de;
/* unbake published declaration: published_56e67aad88f7fd5dee05ae04 */
typedef struct Actor_func_80214310_de Actor_func_80214310_de;

struct Shield;
/* unbake published declaration: published_5710b7578d4c32cc7e6af956 */
struct Shield {
    char pad0[0x68];
    f32 factor;
};

struct Header44;
/* unbake published declaration: published_572e635d4a24cadb7fd002fa */
typedef struct Header44 Header44;

struct Key;
/* unbake published declaration: published_579f1423a5c8fa87a22df298 */
typedef struct Key Key;

union func_8028472C_S2_U118;
/* unbake published declaration: published_78bc61d202aad7f7a645cb4f */
union func_8028472C_S2_U118 {
    s32 v0;
    s32 * v1;
};

union func_8028472C_S2_U118;
/* unbake published declaration: published_e5185d0aca34cd17d304cd9c */
typedef union func_8028472C_S2_U118 func_8028472C_S2_U118;

struct func_8020D0CC_S1;
/* unbake published declaration: published_57dfa981e2484c80e480a067 */
struct func_8020D0CC_S1 {
    char pad0[0x24];
    void * unk24;
};

struct func_8022CA04_S4;
/* unbake published declaration: published_581f1b412a83b9d9dd6109ae */
typedef struct func_8022CA04_S4 func_8022CA04_S4;

struct func_8020EA10_S1;
/* unbake published declaration: published_584dc5539d50a14424e2e081 */
struct func_8020EA10_S1 {
    char pad0[0x78];
    s32 unk78;
};

struct Triple_func_802683E0_de;
/* unbake published declaration: published_585bc1cb2d221a7a102e7b23 */
typedef struct Triple_func_802683E0_de Triple_func_802683E0_de;

struct PlayerRecord;
/* unbake published declaration: published_59355cf5b7510f7b93b75bb8 */
typedef struct PlayerRecord PlayerRecord;

struct Shared_HudView;
/* unbake published declaration: published_8b933778ba660a431e5bab6d */
struct Shared_HudView {
    char pad0[0x24];
    s32 flags;
    char pad28[0x274];
    f32 width;
    f32 height;
    f32 x;
    f32 y;
};

struct ALEventListItem;
/* unbake published declaration: published_5a5b5a93af52253ef8cc096b */
typedef struct ALEventListItem ALEventListItem;

struct func_80207BB8_S4;
/* unbake published declaration: published_5aa7482e5b9e5897b616c213 */
struct func_80207BB8_S4 {
    char pad0[0x64];
    f32 unk64;
};

struct func_8022CA04_S4;
/* unbake published declaration: published_5b4f16af617b03851ac6dabe */
struct func_8022CA04_S4 {
    char pad0[0x1C];
    Vec3 unk1C;
};

struct func_80435010_S4;
/* unbake published declaration: published_5b5acd580df6ab32307b8ada */
struct func_80435010_S4 {
    char pad0[0xB9C];
    s32 unkB9C;
};

struct Object_func_80442064_de;
/* unbake published declaration: published_5b85d3d97e10248190f5b7f5 */
struct Object_func_80442064_de {
    char pad[0x14];
    s32 *source;
};

struct PackedMatrixWords;
/* unbake published declaration: published_5b9993d856d1ed7f8ea61379 */
struct PackedMatrixWords {
    u32 upper[8];
    u32 lower[8];
};

struct func_8024575C_S1;
/* unbake published declaration: published_5ba8738a59ee44a766d949f8 */
typedef struct func_8024575C_S1 func_8024575C_S1;

struct func_80239CDC_S1;
/* unbake published declaration: published_5c93ff6f9a035c6ce0affd5e */
struct func_80239CDC_S1 {
    char pad0[0x4];
    int unk4;
    char pad4[0x8 - 0x4 - sizeof(int)];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    int unkC;
    char padC[0x10 - 0xC - sizeof(int)];
    int unk10;
};

struct func_80228774_S6;
/* unbake published declaration: published_5cd70c13b99dbbaec11dab1f */
struct func_80228774_S6 {
    char pad0[0x128];
    f32 unk128;
};

struct OSPifRam;
/* unbake published declaration: published_5d43eed370ae060b1722861c */
struct OSPifRam {
    u32 ramarray[15];
    u32 pifstatus;
};

struct func_802A6A54_S1;
/* unbake published declaration: published_5e209583196790244f4297c1 */
typedef struct func_802A6A54_S1 func_802A6A54_S1;

struct Entry_func_80441EB0_de;
struct List_func_80442574_de;
/* unbake published declaration: published_5e255186b1e47dd7570c4bf8 */
struct List_func_80442574_de {
    struct Entry_func_80441EB0_de *entries;
    s16 count;
};

struct Record_func_80439C80_de;
/* unbake published declaration: published_5e9553cb98a7440b6f272371 */
struct Record_func_80439C80_de {
    s32 count;
    char pad4[0x34 - 4];
    s32 handle;
};

struct Record_func_80409BDC_de;
struct func_80242278_S1;
/* unbake published declaration: published_5f4d2b451150d5fda5e14351 */
struct Record_func_80409BDC_de {
    char pad[0x20];
    struct func_80242278_S1 *inner;
};

struct func_8022A5E4_S2;
/* unbake published declaration: published_5f684e0b9f3d4626f9ff87bf */
struct func_8022A5E4_S2 {
    char pad0[0x16E0];
    void * unk16E0;
};

struct MenuPanelRoot;
/* unbake published declaration: published_5f7e527356912c1e6b313e7f */
struct MenuPanelRoot {
    char pad0[0xE0];
    s32 window;
};

struct ReadWord;
/* unbake published declaration: published_5f86daba4820dae6ca104bab */
struct ReadWord {
    s32 word;
    u8 byte;
};

struct func_802044C8_S1;
/* unbake published declaration: published_60591f5463b8f111ea71a0b7 */
typedef struct func_802044C8_S1 func_802044C8_S1;

struct MatchMenuObjects;
/* unbake published declaration: published_612216de0185387f3255d2e1 */
struct MatchMenuObjects {
    char pad0[0x17F0];
    s32 transition;
};

struct func_8020E674_S1;
/* unbake published declaration: published_6129b4974a421208730e8f9b */
typedef struct func_8020E674_S1 func_8020E674_S1;

struct Shape_typemap_13;
/* unbake published declaration: published_dc1db12135fe76b092c26593 */
struct Shape_typemap_13 {
    int field_0;
    int field_4;
};

struct func_8028B3C0_S1;
/* unbake published declaration: published_6275a4b953a8795a600de053 */
struct func_8028B3C0_S1 {
    char pad0[0x84];
    void * unk84;
};

struct func_8020C9CC_S1;
/* unbake published declaration: published_62957f6e42a3ee7061a786df */
typedef struct func_8020C9CC_S1 func_8020C9CC_S1;

struct ALPlayer_s;
/* unbake published declaration: published_67525b01f18599b20edbf736 */
typedef struct ALPlayer_s ALPlayer_s;

struct ALPlayer_s;
/* unbake published declaration: published_ea5422417f4ef6a2abfe1e14 */
struct ALPlayer_s {
    struct ALPlayer_s *next;
    void *clientData;
    void *handler;
    s32 callTime;
    s32 samplesLeft;
};

struct func_8028469C_S2;
/* unbake published declaration: published_63e7efbccaf9498929021b02 */
typedef struct func_8028469C_S2 func_8028469C_S2;

struct Queue;
/* unbake published declaration: published_e1aec4fd7d7fc2ed2c347e83 */
struct Queue {
    char pad[0x14];
    s32 items[4];
};

struct HashNode;
/* unbake published declaration: published_657a0b32a34dcb7e1a85b721 */
struct HashNode {
    s32 key;
    void *value;
    s32 unk08;
    struct HashNode *next;
};

struct InstanceHdr;
/* unbake published declaration: published_65c940c9d99648c154d96aa9 */
typedef struct InstanceHdr InstanceHdr;

struct OSPfs_func_80445F80_de;
/* unbake published declaration: published_66132d015d538112cccd25c5 */
struct OSPfs_func_80445F80_de {
    int status;
    void *queue;
    int channel;
    u8 id[32];
    u8 label[32];
    int version;
    int dir_size;
    int inode_table;
    int minode_table;
    int dir_table;
    int inode_start_page;
    u8 banks;
    u8 activebank;
};

struct func_8024C8B4_S1;
/* unbake published declaration: published_66231ef7e000fd7b58b165e4 */
typedef struct func_8024C8B4_S1 func_8024C8B4_S1;

struct func_8020C9B0_S1;
/* unbake published declaration: published_671d835a90fed65e815b140c */
struct func_8020C9B0_S1 {
    char pad0[0x8];
    char * unk8;
};

struct func_80245A10_S1;
/* unbake published declaration: published_685263b46906ee8362a629f5 */
typedef struct func_80245A10_S1 func_80245A10_S1;

struct ALEventListItem;
/* unbake published declaration: published_6861e0b9edb6550e8db9ee63 */
struct ALEventListItem {
    Link_func_802596B4_de node;
    s32 delta;
    Message_func_802AF150_de evt;
};

struct Params;
/* unbake published declaration: published_6a0c13dcf839bb05fcad1c02 */
typedef struct Params Params;

struct func_802077F4_S4;
/* unbake published declaration: published_6ae359391b38ab4576497612 */
typedef struct func_802077F4_S4 func_802077F4_S4;

struct func_80204BB4_S1;
/* unbake published declaration: published_6b065e6fd96c8ebc3faf4187 */
typedef struct func_80204BB4_S1 func_80204BB4_S1;

struct Queue_func_802BB420_de;
/* unbake published declaration: published_6b09a85b8884f5c01b2f5c2b */
typedef struct Queue_func_802BB420_de Queue_func_802BB420_de;

struct func_802B7EB0_S1;
/* unbake published declaration: published_6c80dea4fee26bf149e0eca0 */
typedef struct func_802B7EB0_S1 func_802B7EB0_S1;

struct MenuRules;
/* unbake published declaration: published_cc3853dc56786897bacca3ab */
struct MenuRules {
    char pad0[0x1C];
    s32 locked;
};

struct func_80207B5C_S2;
/* unbake published declaration: published_6cf516e8df52c482412839ad */
struct func_80207B5C_S2 {
    char pad0[0x24];
    s32 unk24;
};

struct TextEntry;
/* unbake published declaration: published_e963675f434d972faa292e38 */
typedef struct TextEntry TextEntry;

struct func_802428C0_S2;
/* unbake published declaration: published_6de3e9a158efe1519b53c00e */
typedef struct func_802428C0_S2 func_802428C0_S2;

struct func_8020D280_S1;
/* unbake published declaration: published_6e4277a7c260c953b1d1833d */
typedef struct func_8020D280_S1 func_8020D280_S1;

struct Queue_func_802BB420_de;
/* unbake published declaration: published_ead70c5f1b04fafc768f3561 */
struct Queue_func_802BB420_de {
    s32 *state;
    s32 unknown4;
    s32 count;
    s32 start;
    s32 capacity;
    s32 *entries;
};

struct func_80272908_S2;
/* unbake published declaration: published_6f9d7025664ca776b4c207cb */
typedef struct func_80272908_S2 func_80272908_S2;

struct Quad_func_802A1BE0_de;
/* unbake published declaration: published_d5dddeb1ae961281f232ca51 */
typedef struct Quad_func_802A1BE0_de Quad_func_802A1BE0_de;

struct Quad_func_802A1BE0_de;
/* unbake published declaration: published_e22cdb88d0e18003af5bb277 */
struct Quad_func_802A1BE0_de {
    u32 x;
    u32 y;
    u32 z;
    u32 w;
};

struct Params;
/* unbake published declaration: published_706aa23265b816f6476e87af */
struct Params {
    Triple v;
    s32 w;
};

struct Node80253610;
/* unbake published declaration: published_70d3334b21c9cb3dc8dce9ad */
typedef struct Node80253610 Node80253610;

struct func_8023ECAC_S2;
/* unbake published declaration: published_71d149f8a2579ee6c2931b03 */
typedef struct func_8023ECAC_S2 func_8023ECAC_S2;

struct func_8021CD70_S3;
/* unbake published declaration: published_71d906f8ae535013e105d9a4 */
typedef struct func_8021CD70_S3 func_8021CD70_S3;

struct func_80251448_S1;
/* unbake published declaration: published_7222052fa3eb6cd0ce318931 */
typedef struct func_80251448_S1 func_80251448_S1;

struct Instance8020CD74;
/* unbake published declaration: published_723b762f0675218cb40af45c */
typedef struct Instance8020CD74 Instance8020CD74;

struct func_80255D10_S1;
/* unbake published declaration: published_724812c0c504deb4ad9ff563 */
struct func_80255D10_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
};

struct UnitVtx;
/* unbake published declaration: published_d9cd2270ebbe1266485bd7c1 */
struct UnitVtx {
    s16 x;
    s16 y;
    s16 z;
    u16 flag;
    s16 s;
    s16 t;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

/* unbake published declaration: published_75d7ba4c4e4a699fa2c757fa */
extern int D_800D0910;

struct func_80250DBC_S2;
/* unbake published declaration: published_75d83d6a7673b3ff8b74b764 */
typedef struct func_80250DBC_S2 func_80250DBC_S2;

struct func_8025C8F8_S1;
/* unbake published declaration: published_771d6b6a35906ebebfa2010a */
struct func_8025C8F8_S1 {
    char pad0[0x14];
    IntrusiveList unk14;
    char pad14[0x28 - 0x14 - sizeof(IntrusiveList)];
    s32 unk28;
};

struct func_8024B8DC_S2;
/* unbake published declaration: published_77a3e5abf2b872185926bbad */
struct func_8024B8DC_S2 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
};

struct func_80264874_S1;
/* unbake published declaration: published_77dba614acb8b424cadb7a49 */
struct func_80264874_S1 {
    char pad0[0xCC];
    s32 unkCC;
};

/* unbake published declaration: published_78818960804290f7946a2b5e */
extern unsigned char D_800D297B;

struct Instance8020CD74;
/* unbake published declaration: published_79de00ac1f7d845d7b716705 */
struct Instance8020CD74 {
    s32 w[20];
};

struct func_80293C20_S1;
/* unbake published declaration: published_c61dcf012b5f037b5a030126 */
typedef struct func_80293C20_S1 func_80293C20_S1;

struct func_80293C20_S1;
/* unbake published declaration: published_f223fda4b6cd3f4a2f789891 */
struct func_80293C20_S1 {
    char pad0[0x26DD4];
    s32 unk26DD4;
};

struct func_80435010_S3;
/* unbake published declaration: published_7a702a30d351e29f5bad4da0 */
struct func_80435010_S3 {
    char pad0[0xB8C];
    u8 unkB8C;
};

struct func_802A2BE0_S1;
/* unbake published declaration: published_7b3efc8d3687f894d7313282 */
typedef struct func_802A2BE0_S1 func_802A2BE0_S1;

/* unbake published declaration: published_7bcbc310ed1b6e966e382a21 */
extern int D_800CD8B8_de;

struct func_80212C04_S2;
/* unbake published declaration: published_7c0812e923fd41b3d70d429a */
struct func_80212C04_S2 {
    char pad0[0x1454];
    s32 * unk1454;
};

struct Limit;
/* unbake published declaration: published_7c0b7963b450dcb484c4a583 */
struct Limit {
    char pad[0x16];
    s16 limit;
};

struct Triple_func_802683E0_de;
/* unbake published declaration: published_7cddc82a987f0affc7b6e0cb */
struct Triple_func_802683E0_de {
    s32 x;
    f32 y;
    s32 z;
};

struct World;
/* unbake published declaration: published_7ce839a2886bd274354660fa */
struct World {
    u8 pad000[0xFC];
    s32 state;
};

struct func_80251448_S1;
/* unbake published declaration: published_7cf09a5fd651dff2b09cf1c0 */
struct func_80251448_S1 {
    s32 unk0;
    char pad0[0x8 - 0x0 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x20 - 0x14 - sizeof(s32)];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
};

struct Field;
/* unbake published declaration: published_7cf3b03af5fb0c406aaf95b2 */
struct Field {
    char pad[0x14];
    char **text;
};

struct func_802165F8_S1;
/* unbake published declaration: published_7d10594aaee2535229d4b887 */
struct func_802165F8_S1 {
    char pad0[0x8];
    Vec3 unk8;
    char pad8[0x6C - 0x8 - sizeof(Vec3)];
    f32 unk6C;
};

struct Field_void_80;
/* unbake published declaration: published_7dd5130b697863b37ba599f5 */
struct Field_void_80 {
    char pad[0x80];
    void * value;
};

struct func_802558C0_S1;
/* unbake published declaration: published_7e5480a544165c66625a830d */
struct func_802558C0_S1 {
    char pad0[0x20];
    char unk20;
};

struct ObjectState1E_2;
/* unbake published declaration: published_7e9a5b21f54e9ec2839c8198 */
typedef struct ObjectState1E_2 ObjectState1E_2;

struct Matrix_func_80213CF8_de;
/* unbake published declaration: published_a2a63cb4ccc6f2cb73ca691f */
typedef struct Matrix_func_80213CF8_de Matrix_func_80213CF8_de;

struct func_8023945C_S1;
/* unbake published declaration: published_7ed68ffbc1d36976c6b1426d */
typedef struct func_8023945C_S1 func_8023945C_S1;

struct Access_s32_50;
/* unbake published declaration: published_7f3dbef09cb10ba5ae1a69f2 */
typedef struct Access_s32_50 Access_s32_50;

struct func_80254930_S1;
/* unbake published declaration: published_7fb486c847332ce4effe358d */
struct func_80254930_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
};

struct Target_func_8040AB54_de;
struct Target_func_8040AB54_de {
    char pad[0x120];
    s32 flags;
};
struct Record_func_8040AB54_de;
struct Target_func_8040AB54_de;
/* unbake published declaration: published_801a443cad120759729bacb2 */
struct Record_func_8040AB54_de {
    char pad[0xC];
    struct Target_func_8040AB54_de *target;
};

struct func_8022BECC_S2;
/* unbake published declaration: published_f1ec4e9119e67791e66e83d3 */
struct func_8022BECC_S2 {
    char pad0[0x8];
    short unk8;
};

struct Header;
/* unbake published declaration: published_80279dd9ae54df27ab86a21b */
struct Header {
    u8 data[0xCC];
};

struct Access_u8_3;
/* unbake published declaration: published_813abd0ac8d8bbc8ddcec44f */
typedef struct Access_u8_3 Access_u8_3;

struct Vec3Words;
/* unbake published declaration: published_9bc9fba2b61514330264b747 */
typedef struct Vec3Words Vec3Words;

struct func_80258D60_S1;
/* unbake published declaration: published_81b9562c5eb39a2f4b6acf2f */
typedef struct func_80258D60_S1 func_80258D60_S1;

struct func_8022A5E4_S2;
/* unbake published declaration: published_83255176b7aad247ce905cb6 */
typedef struct func_8022A5E4_S2 func_8022A5E4_S2;

struct func_80245690_S1;
/* unbake published declaration: published_83c30317a1b7c4f2e73268b7 */
typedef struct func_80245690_S1 func_80245690_S1;

struct func_8025E55C_S1;
/* unbake published declaration: published_86d561d60effa3f56e6b98d1 */
typedef struct func_8025E55C_S1 func_8025E55C_S1;

struct State_func_80421D94_de;
/* unbake published declaration: published_86e18d2597560d0a056bd654 */
struct State_func_80421D94_de {
    void *first;
    char pad4[0x10 - 4];
    s32 value;
};

struct HudStatusShared_MatchRules;
/* unbake published declaration: published_8780860e2c6feb800a0f86f0 */
struct HudStatusShared_MatchRules {
    char pad0[0x20];
    s32 hideHud;
    s32 teams;
    char pad28[0x4];
    s32 teamScores[5];
    s32 squadScores[5];
    s32 countRule;
    char pad58[0x20];
    s32 squads;
    char pad7C[0x1C];
    s32 markers;
};

struct Shield;
/* unbake published declaration: published_912e1f4b2a89f36372b28022 */
typedef struct Shield Shield;

struct Item_func_8041A940_de;
/* unbake published declaration: published_87d6238c617ff9a4a445c545 */
struct Item_func_8041A940_de {
    s32 pad0;
    struct Item_func_8041A940_de *next;
    char pad8[0xE - 8];
    u16 kind;
    u8 alpha;
};

struct Slot;
/* unbake published declaration: published_b5e6212d560aa8567f3d5226 */
struct Slot {
    char data[24];
};

struct MenuPanelRoot;
/* unbake published declaration: published_8923212da2092ba1371685be */
typedef struct MenuPanelRoot MenuPanelRoot;

/* unbake published declaration: published_98719319a42eadcf831dc0c4 */
typedef void ( *VoidCallback)(void);

struct __OSContRequesFormat;
/* unbake published declaration: published_89ecc2f72ea1ef1e632824e1 */
typedef struct __OSContRequesFormat __OSContRequesFormat;

struct func_80205494_S3;
/* unbake published declaration: published_8adc168ada80cfc03192513b */
typedef struct func_80205494_S3 func_80205494_S3;

struct ReadWord;
/* unbake published declaration: published_8b400a2d8d971ba7c086ce27 */
typedef struct ReadWord ReadWord;

/* unbake published declaration: published_8bc2ae33bea6edb388cc6377 */
extern int D_800D3650;

struct Buf16;
/* unbake published declaration: published_8bc7a1b2da806ef74cfac66e */
typedef struct Buf16 Buf16;

struct func_80272BA8_S2;
/* unbake published declaration: published_8cfb5116aab9945c77d28796 */
typedef struct func_80272BA8_S2 func_80272BA8_S2;

struct func_8020D0CC_S2;
/* unbake published declaration: published_8d6528293911bccf31f4e5c6 */
typedef struct func_8020D0CC_S2 func_8020D0CC_S2;

struct Buf16;
/* unbake published declaration: published_8d6544cdebd7861d9c71b66c */
struct Buf16 {
    s16 count;
    s16 _pad2;
    s32 value;
    s32 _pad8;
    s32 _padC;
};

struct func_802A67D0_S1;
/* unbake published declaration: published_8d7371d287d6ccadd64127a0 */
typedef struct func_802A67D0_S1 func_802A67D0_S1;

struct Table;
/* unbake published declaration: published_8d7563f7f410b3f977d4b0d4 */
struct Table {
    s32 unk0;
    s32 unk4;
    s32 deltas[1];
};

struct Request;
/* unbake published declaration: published_8d8b2af8dddcabc9cc2c7842 */
struct Request {
    s16 type;
};

struct func_802428C0_S2;
/* unbake published declaration: published_8d91ca8ce845b81cd6977867 */
struct func_802428C0_S2 {
    char pad0[0x38];
    unsigned int unk38;
};

struct Controller_func_80217B3C_de;
/* unbake published declaration: published_8e432628c33ce01bb2e72cb6 */
typedef struct Controller_func_80217B3C_de Controller_func_80217B3C_de;

struct ALFilter_s_func_802B3000_de;
/* unbake published declaration: published_8e9b3b22e24a2535fb7da8c3 */
struct ALFilter_s_func_802B3000_de {
    struct ALFilter_s_func_802B3000_de *source;
    void *handler;
    ALSetParam setParam;
};

/* unbake published declaration: published_8f86b9502d344725201435be */
extern int D_801427D0;

struct Field_u16_14;
/* unbake published declaration: published_8fef90f78494aacc7faa372f */
typedef struct Field_u16_14 Field_u16_14;

struct func_804360F4_S2;
/* unbake published declaration: published_902dd06c67a721067db58673 */
struct func_804360F4_S2 {
    char pad0[0x1C];
    void * unk1C;
};

struct ALFilter_s_func_802B3000_de;
struct ALVoice_s_func_802B3000_de;
struct PVoice_s_func_802B3000_de;
/* unbake published declaration: published_907934bd7bf43a1da9aea540 */
struct PVoice_s_func_802B3000_de {
    Link_func_802596B4_de node;
    struct ALVoice_s_func_802B3000_de *vvoice;
    struct ALFilter_s_func_802B3000_de *channelKnob;
    char pad10[0xD8 - 0x10];
    s32 offset;
};

/* unbake published declaration: published_b75a0f7396c3bd07bedaebdf */
struct ALVoice_s_func_802B3000_de {
    Link_func_802596B4_de node;
    struct PVoice_s_func_802B3000_de *pvoice;
    void *table;
    void *clientPrivate;
    s16 state;
    s16 priority;
    s16 fxBus;
    s16 unityPitch;
};

struct Field_func_8040A4A0_de;
/* unbake published declaration: published_90cfb6c30b6e70c52946e36f */
struct Field_func_8040A4A0_de {
    char pad[0x14];
    char *text;
};

struct Header44;
/* unbake published declaration: published_912d06094ab948dc213ab6e2 */
struct Header44 {
    s32 words[11];
};

struct ImageHeader;
struct ImageHeader {
    char pad0[2];
    unsigned char widthShift;
    unsigned char heightShift;
    char pad4[0x1D - 4];
    unsigned char scale;
    char pad1E[0x21 - 0x1E];
    unsigned char width;
    unsigned char height;
    unsigned char format;
    char data[1];
};
struct Image;
struct ImageHeader;
/* unbake published declaration: published_9cfb3be44ef1390ffc0a674d */
struct Image {
    char pad0[8];
    struct ImageHeader *header;
    s32 fieldC;
    s32 field10;
    char pad14[0x3C - 0x14];
    s32 flags;
};

/* unbake published declaration: published_91874d26658d310760a2714f */
extern float D_800C4458_de;

struct func_8020676C_S1;
/* unbake published declaration: published_918ccc499438119c9fc2226f */
typedef struct func_8020676C_S1 func_8020676C_S1;

struct func_8028DA50_S1;
/* unbake published declaration: published_91d212d3b35d31c1c0d23f05 */
typedef struct func_8028DA50_S1 func_8028DA50_S1;

/* unbake published declaration: published_91f5192029d081aec8c8bac9 */
extern int D_800D5258;

struct func_802A68A0_S3;
/* unbake published declaration: published_92362712c55071b46a9c4013 */
struct func_802A68A0_S3 {
    char pad0[0x118];
    void * unk118;
};

struct func_8025C458_S3;
/* unbake published declaration: published_92ff0fee9e337403fb73d1d5 */
struct func_8025C458_S3 {
    char pad0[0xDC];
    s16 unkDC;
};

struct ModelDef;
/* unbake published declaration: published_9316998183ff87589f67a703 */
struct ModelDef {
    char pad0[0xE];
    u8 colour;
};

struct func_80284AF4_G2;
/* unbake published declaration: published_93d8b7407e98987cffff37fc */
typedef struct func_80284AF4_G2 func_80284AF4_G2;

struct Obj_func_802B3EDC_de;
/* unbake published declaration: published_9409980e10af3b17df91cea0 */
struct Obj_func_802B3EDC_de {
    char pad14[0x14];
    s32 count;
    char pad18[0x4];
    s32 *base;
};

struct Brain_func_80212D78_eu_x;
/* unbake published declaration: published_942813ec1496d950eb1aeeed */
typedef struct Brain_func_80212D78_eu_x Brain_func_80212D78_eu_x;

struct func_80228774_S4;
/* unbake published declaration: published_947b704a33338b744fbf824f */
struct func_80228774_S4 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0xC4 - 0x10 - sizeof(f32)];
    s32 unkC4;
    char padC4[0xD0 - 0xC4 - sizeof(s32)];
    s32 unkD0;
    char padD0[0x100 - 0xD0 - sizeof(s32)];
    s32 unk100;
    char pad100[0x1D8 - 0x100 - sizeof(s32)];
    void * unk1D8;
};

struct func_8020478C_S1;
/* unbake published declaration: published_94904f19ff0bc195804c3217 */
typedef struct func_8020478C_S1 func_8020478C_S1;

struct Access_s32_50;
/* unbake published declaration: published_94b201b8bdb1a0f845f94a56 */
struct Access_s32_50 {
    char pad[0x50];
    s32 field;
};

union func_8026E158_S1_U8;
/* unbake published declaration: published_f2909180e0bddf72587407ea */
union func_8026E158_S1_U8 {
    s32 v0;
    char v1;
};

struct func_8020C9B0_S1;
/* unbake published declaration: published_96f4a01174b96a9362872d6c */
typedef struct func_8020C9B0_S1 func_8020C9B0_S1;

struct func_80275120_S1;
/* unbake published declaration: published_973941421c1048d871016dd3 */
typedef struct func_80275120_S1 func_80275120_S1;

struct func_80239760_S2;
/* unbake published declaration: published_9761372e9707c70804eff089 */
struct func_80239760_S2 {
    char pad0[0xE40];
    IntrusiveList unkE40;
};

struct func_802A2E5C_S2;
/* unbake published declaration: published_9787ab72f3c7a4f87cd52603 */
struct func_802A2E5C_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0xE - 0x4 - sizeof(void*)];
    u16 unkE;
    char padE[0x10 - 0xE - sizeof(u16)];
    s8 unk10;
};

struct func_80242278_S2;
/* unbake published declaration: published_982c4332d1028d650c74cd5e */
typedef struct func_80242278_S2 func_80242278_S2;

struct func_802062E0_S2;
/* unbake published declaration: published_9a77a0d828b7b4f792bfbba0 */
typedef struct func_802062E0_S2 func_802062E0_S2;

struct Work56EC8;
/* unbake published declaration: published_9bd40fead9736cf258983218 */
struct Work56EC8 {
    void *owner;
    s16 id;
    char pad6[2];
    char payload[0x40];
    void *base;
    s32 offset;
};

struct MenuSettings;
/* unbake published declaration: published_9c3c2e3154a62f80d2128aca */
typedef struct MenuSettings MenuSettings;

struct func_8023ECAC_S2;
/* unbake published declaration: published_9c46ca854b7736d0551fd58a */
struct func_8023ECAC_S2 {
    char pad0[0x44];
    s32 unk44;
    char pad44[0x52 - 0x44 - sizeof(s32)];
    u16 unk52;
};

struct PackedMatrixWords;
/* unbake published declaration: published_9ccd2ce1e71a35de1dd4c3ac */
typedef struct PackedMatrixWords PackedMatrixWords;

struct func_80205314_S2;
/* unbake published declaration: published_9db895beae80f58114ebf009 */
typedef struct func_80205314_S2 func_80205314_S2;

struct func_8020CA10_S2;
/* unbake published declaration: published_9deb1ef05bed21cc577685f4 */
typedef struct func_8020CA10_S2 func_8020CA10_S2;

struct func_80254D70_S2;
/* unbake published declaration: published_9df1674beec6d61fc1cbd898 */
struct func_80254D70_S2 {
    char pad0[0x8];
    s32 unk8;
};

struct func_8025BD20_S1;
/* unbake published declaration: published_9e06cb8ee009e6ccc7cd74e0 */
typedef struct func_8025BD20_S1 func_8025BD20_S1;

struct func_8020D0CC_S2;
/* unbake published declaration: published_9e0f1ee7f3a32a8f95b6b749 */
struct func_8020D0CC_S2 {
    char pad0[0x10];
    void * unk10;
};

struct func_80239CD0_S1;
/* unbake published declaration: published_9e3e1ab71f097651e1d0a48f */
typedef struct func_80239CD0_S1 func_80239CD0_S1;

struct Header;
/* unbake published declaration: published_fe7e455a0a1a0ac68ec8c307 */
typedef struct Header Header;

/* unbake published declaration: published_9eeed217d2e6f34673d6ebd0 */
extern int D_800CC370;

struct State_func_804447F0_de;
/* unbake published declaration: published_a08c290e358e728891bee1e0 */
struct State_func_804447F0_de {
    char a[8];
    s32 unk8;
    char b[8];
    char *unk14;
};

struct StateBlock;
/* unbake published declaration: published_a145759ca41b3809d38525cb */
struct StateBlock {
    char pad0[0x84];
    s32 unk84;
};

struct Shared_GameMode;
/* unbake published declaration: published_a176af2669249fb8ab6fdb91 */
typedef struct Shared_GameMode Shared_GameMode;

/* unbake published declaration: published_a1d2f21619fc5f5e5598d92e */
extern int D_800E63AC;

struct func_80245A10_S1;
/* unbake published declaration: published_a1e0d27f8ec73fe097b1b3cc */
struct func_80245A10_S1 {
    char pad0[0x104];
    int unk104;
};

struct Args;
/* unbake published declaration: published_a25a6e4fe825a578e722a57b */
struct Args {
    u32 words[10];
};

struct func_8025E58C_S1;
/* unbake published declaration: published_a362f87c371f040afd3b51a8 */
typedef struct func_8025E58C_S1 func_8025E58C_S1;

struct Field_f32_10;
/* unbake published declaration: published_a38990a21356bb557fed955a */
struct Field_f32_10 {
    char pad[0x10];
    f32 value;
};

struct func_80435010_S4;
/* unbake published declaration: published_a3bc92c9eee24ed8eb7778b0 */
typedef struct func_80435010_S4 func_80435010_S4;

struct Player_func_80434750_de;
/* unbake published declaration: published_a5112f37ecc212d444650e92 */
struct Player_func_80434750_de {
    char pad[0x58];
    int state;
    char pad5C[0xB68 - 0x5C];
};

struct func_8025CA44_S1;
/* unbake published declaration: published_a5ca2aee24189694990425ed */
struct func_8025CA44_S1 {
    char pad0[0x14];
    IntrusiveList unk14;
};

/* unbake published declaration: published_a5f18dd6ce967cceec610246 */
extern int D_801534F0[];

struct HashNode;
/* unbake published declaration: published_a69a794c2f0c47a1a6257b12 */
typedef struct HashNode HashNode;

struct func_8025E55C_S1;
/* unbake published declaration: published_a70a4f0c7926308eb050803e */
struct func_8025E55C_S1 {
    char pad0[0xA];
    short unkA;
};

struct func_8029A838_S1;
/* unbake published declaration: published_a8f5f16936eb9589d3297e0a */
typedef struct func_8029A838_S1 func_8029A838_S1;

struct Record;
/* unbake published declaration: published_b5093e836cad674d96d2f887 */
typedef struct Record Record;

/* unbake published declaration: published_a992285c81bc28560179c4f1 */
extern float D_80146CB8;

struct func_802558C0_S1;
/* unbake published declaration: published_aa8a6afde0163208a522b2d7 */
typedef struct func_802558C0_S1 func_802558C0_S1;

struct Shape_typemap_71;
/* unbake published declaration: published_aab5af7ea99db6e11a22ed2d */
struct Shape_typemap_71 {
    unsigned char padding_0[28];
    int field_1C;
};

struct func_8024E58C_S1;
/* unbake published declaration: published_aad639dfd78950e908fe9952 */
struct func_8024E58C_S1 {
    f32 unk0;
    char pad0[0x8 - 0x0 - sizeof(f32)];
    f32 unk8;
};

struct BufferPool;
/* unbake published declaration: published_ac12cacf61884782b2b93830 */
typedef struct BufferPool BufferPool;

struct Request;
/* unbake published declaration: published_c3f44ffbad214ec9b7eaa965 */
typedef struct Request Request;

struct func_80284AF4_G2;
/* unbake published declaration: published_fafef379cce5a361924846ec */
struct func_80284AF4_G2 {
    void * unk0;
};

struct func_80255D10_S1;
/* unbake published declaration: published_acde419f592aeb55bc1ab310 */
typedef struct func_80255D10_S1 func_80255D10_S1;

struct func_8024C654_S1;
/* unbake published declaration: published_acea07128c6a731a00b0a117 */
struct func_8024C654_S1 {
    char pad0[0x18];
    s32 * unk18;
};

struct func_8020676C_S1;
/* unbake published declaration: published_ada5963c33d8bdc0153eaccc */
struct func_8020676C_S1 {
    char pad0[0x6];
    unsigned short unk6;
};

struct func_80206930_S3;
/* unbake published declaration: published_ada76dd784a40c0aeb23bcc5 */
struct func_80206930_S3 {
    char pad0[0x7];
    unsigned char unk7;
};

struct func_8029A9E0_S1;
/* unbake published declaration: published_ae0a44168bb905326e5f23a9 */
typedef struct func_8029A9E0_S1 func_8029A9E0_S1;

struct Shared_HudView;
/* unbake published declaration: published_af114715567101bc0a5ee7cf */
typedef struct Shared_HudView Shared_HudView;

struct State_func_8043E254_de;
/* unbake published declaration: published_af14f7e521633bb1b9de2523 */
struct State_func_8043E254_de {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    char pad24[4];
    s32 unk28;
};

struct State_func_804447F0_de;
/* unbake published declaration: published_af1a22608a740bd84f58bf3c */
typedef struct State_func_804447F0_de State_func_804447F0_de;

struct ObjectLinks24_2;
/* unbake published declaration: published_af9e1f0c56e27ead7b73c885 */
struct ObjectLinks24_2 {
    char * unk_0;
    char pad0[0x4 - 0x0 - sizeof(char*)];
    char * unk_4;
    char pad4[0xC - 0x4 - sizeof(char*)];
    void * unk_C;
    char padC[0x10 - 0xC - sizeof(void*)];
    s32 unk_10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk_14;
    char pad14[0x20 - 0x14 - sizeof(s32)];
    s32 unk_20;
};

struct func_8020F2A8_S3;
/* unbake published declaration: published_b0ee4018e1b12921568b78d2 */
typedef struct func_8020F2A8_S3 func_8020F2A8_S3;

struct func_802831FC_S1;
/* unbake published declaration: published_b12f8ebe7f7169e08c038fad */
typedef struct func_802831FC_S1 func_802831FC_S1;

struct Link;
/* unbake published declaration: published_b22f9a982ce55888b943859e */
struct Link {
    unsigned short from;
    unsigned short to;
    unsigned char type;
};

struct CollisionInfo;
/* unbake published declaration: published_dce43c60dc64cd1e53cc6bea */
struct CollisionInfo {
    s32 w[8];
};

struct func_80254D70_S1;
/* unbake published declaration: published_b2ce63b6237716384667818d */
struct func_80254D70_S1 {
    char pad0[0x14];
    void * unk14;
};

struct OSPifRam;
/* unbake published declaration: published_b362c599177b05373da276a7 */
typedef struct OSPifRam OSPifRam;

struct func_8026E158_S1;
/* unbake published declaration: published_b42a3d4e86db025d113f64ef */
struct func_8026E158_S1 {
    char pad0[0x8];
    func_8026E158_S1_U8 unk8;
};

struct func_80212C04_S2;
/* unbake published declaration: published_b561d7be716d401eed8113e0 */
typedef struct func_80212C04_S2 func_80212C04_S2;

struct func_80293268_S2;
/* unbake published declaration: published_b58995a55fcaac135fd389cb */
struct func_80293268_S2 {
    char pad0[0x26DBC];
    s32 unk26DBC;
    char pad26DBC[0x26DC1 - 0x26DBC - sizeof(s32)];
    s8 unk26DC1;
    char pad26DC1[0x26DD8 - 0x26DC1 - sizeof(s8)];
    s32 unk26DD8;
    char pad26DD8[0x26DDC - 0x26DD8 - sizeof(s32)];
    s32 unk26DDC;
};

struct func_80435010_S3;
/* unbake published declaration: published_b59af7c130cb8b3b0b4ca06e */
typedef struct func_80435010_S3 func_80435010_S3;

struct Slots_func_8041B7FC_de;
/* unbake published declaration: published_ebb2f0239d2816dd0df99bf4 */
struct Slots_func_8041B7FC_de {
    char pad[0x4C];
    s32 values[1];
};

struct Cell_func_80421BEC_de;
/* unbake published declaration: published_b808f6f754b73aa2f8063bd5 */
typedef struct Cell_func_80421BEC_de Cell_func_80421BEC_de;

struct D_800C7470_Pair;
/* unbake published declaration: published_d2d430da02041be828af514b */
struct D_800C7470_Pair {
    f32 first;
    f32 second;
};

struct func_8024C8B4_S1;
/* unbake published declaration: published_b8a10c6b88db2513b2dd2d2f */
struct func_8024C8B4_S1 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
};

struct Pair14;
/* unbake published declaration: published_ece4d7d6ddf67da1c94cc858 */
struct Pair14 {
    char pad[0x14];
    s16 first;
    s16 second;
};

struct Obj_func_80297DBC_de;
/* unbake published declaration: published_ca8f2ecaf65a96aa5ec23c35 */
struct Obj_func_80297DBC_de {
    char p[0x40];
    s32 unk40;
};

struct func_8020E674_S1;
/* unbake published declaration: published_bab7524367378b94c35864bd */
struct func_8020E674_S1 {
    char pad0[0x8];
    func_8020E674_S1_U8 unk8;
};

struct func_80272BA8_S2;
/* unbake published declaration: published_baf0a17a5ed132ba805bccbb */
struct func_80272BA8_S2 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    f32 unk14;
    char pad14[0x18 - 0x14 - sizeof(f32)];
    f32 unk18;
    char pad18[0x20 - 0x18 - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
    char pad24[0x28 - 0x24 - sizeof(f32)];
    f32 unk28;
};

struct func_804360F4_S2;
/* unbake published declaration: published_bb2ab5ccf84c415b2062825e */
typedef struct func_804360F4_S2 func_804360F4_S2;

struct func_802B4ECC_S1;
/* unbake published declaration: published_bb8d2b1406d5d8560462c939 */
struct func_802B4ECC_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x24 - 0x18 - sizeof(void*)];
    s32 unk24;
};

struct Slot_func_8041F140_de;
/* unbake published declaration: published_bc0f5412f123abc91e4e82a3 */
struct Slot_func_8041F140_de {
    s32 key;
    char pad[0x70 - 4];
};

struct Shape_typemap_30;
/* unbake published declaration: published_bc21a498ac45fc9428498d51 */
struct Shape_typemap_30 {
    unsigned char padding_0[32];
    int field_20;
};

struct Block24;
/* unbake published declaration: published_c4ecabf1d7c477868271a578 */
struct Block24 {
    s32 words[6];
};

struct ALVoiceConfig_s;
/* unbake published declaration: published_bcaf57a21cb2033f92cfb549 */
struct ALVoiceConfig_s {
    s16 priority;
    s16 fxBus;
    u8 unityPitch;
};

struct IntegerStateDC_2;
/* unbake published declaration: published_bccbf822b2adb0e18aba56bf */
typedef struct IntegerStateDC_2 IntegerStateDC_2;

struct func_802077F4_S4;
/* unbake published declaration: published_bcf592aba10207a57909fbe1 */
struct func_802077F4_S4 {
    char pad0[0x40];
    f32 unk40;
};

struct List;
/* unbake published declaration: published_bd038eef2c72a7af7b30480c */
struct List {
    char pad0[0x48];
    u8 visibleX;
    u8 visibleY;
    u8 maxX;
    u8 maxY;
    u8 cursorX;
    u8 cursorY;
    u8 scrollX;
    u8 scrollY;
    u8 minX;
    u8 minY;
};

struct func_802A67D0_S1;
/* unbake published declaration: published_bd27d6cf9f9100012a85a15c */
struct func_802A67D0_S1 {
    char pad0[0x7528];
    void * unk7528;
};

struct func_8025C598_S1;
/* unbake published declaration: published_bdda7d98ca6325c6f55722a4 */
struct func_8025C598_S1 {
    s32 unk0;
    char pad0[0xB0 - 0x0 - sizeof(s32)];
    s32 unkB0;
};

struct MatchMenuObjects;
/* unbake published declaration: published_be2bb9485c7eebb19cb979ef */
typedef struct MatchMenuObjects MatchMenuObjects;

struct func_80247F08_S1;
/* unbake published declaration: published_beb50804145c25080c1d7f28 */
struct func_80247F08_S1 {
    char pad0[0x30];
    f32 unk30;
    char pad30[0x34 - 0x30 - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
};

struct ControllerProfile;
/* unbake published declaration: published_bf3203d18d65a17e6eae0305 */
struct ControllerProfile {
    char pad0[0x224];
};

struct Args;
/* unbake published declaration: published_bfa458f813920932ae72e052 */
typedef struct Args Args;

struct func_8020CC0C_S1;
/* unbake published declaration: published_bfe01d50c48c50a1f3cdcab9 */
typedef struct func_8020CC0C_S1 func_8020CC0C_S1;

struct func_80272848_S1;
/* unbake published declaration: published_c02b1a76f23d70f3c73e97f0 */
typedef struct func_80272848_S1 func_80272848_S1;

struct Actor_func_80214310_de;
/* unbake published declaration: published_c094cbdac1189bf35a7e1f7b */
struct Actor_func_80214310_de {
    char pad0[8];
    Vec3 position;
    char pad14[0x70 - 0x14];
    f32 eye;
};

struct World_func_8028787C_de;
/* unbake published declaration: published_c0d5fa627b66ae56ac76bffd */
typedef struct World_func_8028787C_de World_func_8028787C_de;

struct ObjectState1E;
/* unbake published declaration: published_c0f513524165b3eb8e7060d1 */
typedef struct ObjectState1E ObjectState1E;

/* unbake published declaration: published_c165567343eef5483eaaf1ea */
extern int D_800CC38C;

struct func_80203908_S4;
/* unbake published declaration: published_c1757081a2e845b286360a6f */
typedef struct func_80203908_S4 func_80203908_S4;

struct Link;
/* unbake published declaration: published_c1a1013284ba5e27cd1e0dbb */
typedef struct Link Link;

struct Draw;
/* unbake published declaration: published_c1c254635e9cf01fe0d5ec16 */
struct Draw {
    char pad0[0xC];
    void *model;
};

struct Field_void_4;
/* unbake published declaration: published_c252de46e371168bf09bd14b */
typedef struct Field_void_4 Field_void_4;

struct func_80293268_S1;
/* unbake published declaration: published_c2bef8ddfc758d50262eb90a */
typedef struct func_80293268_S1 func_80293268_S1;

struct func_80250BD4_S1;
/* unbake published declaration: published_f22fddc58767858684f8ec2b */
typedef struct func_80250BD4_S1 func_80250BD4_S1;

struct ALEvent_func_802B21A8_de;
/* unbake published declaration: published_c56e236774645e350554b216 */
typedef struct ALEvent_func_802B21A8_de ALEvent_func_802B21A8_de;

struct func_8022E694_S1;
/* unbake published declaration: published_c60d3d01d0a7dcb5158ae365 */
struct func_8022E694_S1 {
    char pad0[0x44];
    s32 unk44;
};

struct Obj_func_8043CC10_de;
/* unbake published declaration: published_c7cc0e85cc3c1457fba33a31 */
struct Obj_func_8043CC10_de {
    char pad[0x14];
    u8 **unk14;
};

struct func_8020478C_S1;
/* unbake published declaration: published_c7d2f1035438a049792c77f5 */
struct func_8020478C_S1 {
    char pad0[0x4];
    unsigned short unk4;
    char pad4[0xA - 0x4 - sizeof(unsigned short)];
    unsigned short unkA;
};

struct World_func_8028787C_de;
/* unbake published declaration: published_c8bb46e64d4f901ddd5fc866 */
struct World_func_8028787C_de {
    char pad0[0x80];
    void *levels;
    char pad84[0x1B40C - 0x84];
    s32 level;
};

struct func_80250DBC_S2;
/* unbake published declaration: published_caca92f813aff9624827b5c2 */
struct func_80250DBC_S2 {
    char pad0[0xE];
    s8 unkE;
};

struct Field_void_80;
/* unbake published declaration: published_cb0d44f414ae11a2024c1a15 */
typedef struct Field_void_80 Field_void_80;

struct Node80253610;
/* unbake published declaration: published_f54ebc4bb99b6bb5a7266d38 */
struct Node80253610 {
    s32 field0;
    s32 field4;
    s32 references;
    u32 flags;
};

struct Obj_func_8043CC10_de;
/* unbake published declaration: published_cb89cc400fc07460002da944 */
typedef struct Obj_func_8043CC10_de Obj_func_8043CC10_de;

struct func_80247F08_S1;
/* unbake published declaration: published_cc3bacb69b7bb7259920cf04 */
typedef struct func_80247F08_S1 func_80247F08_S1;

struct HudStatusShared_Settings;
/* unbake published declaration: published_cc3beafe87dc360a62f55d0d */
typedef struct HudStatusShared_Settings HudStatusShared_Settings;

struct func_80204BB4_S1;
/* unbake published declaration: published_cc45b3e79922568641f2b581 */
struct func_80204BB4_S1 {
    char pad0[0x2C];
    void * unk2C;
    char pad2C[0x108 - 0x2C - sizeof(void*)];
    void * unk108;
};

struct func_80239760_S2;
/* unbake published declaration: published_cc5751da4c3c2301c30a4a1e */
typedef struct func_80239760_S2 func_80239760_S2;

struct func_8023EBEC_S1;
/* unbake published declaration: published_cc5e095699149633e0e5ad08 */
struct func_8023EBEC_S1 {
    char pad0[0x3C];
    s32 unk3C;
};

struct func_80264874_S1;
/* unbake published declaration: published_cff9cea93981c7c6ca00fabb */
typedef struct func_80264874_S1 func_80264874_S1;

struct func_8022CA04_S3;
/* unbake published declaration: published_d0c179720d675c8974b3b79f */
typedef struct func_8022CA04_S3 func_8022CA04_S3;

struct NodeEvent;
/* unbake published declaration: published_d103bcd1208303f4fe31d799 */
typedef struct NodeEvent NodeEvent;

struct Style_func_8043C9AC_de;
/* unbake published declaration: published_d811909f0532c0d6b47d62c8 */
typedef struct Style_func_8043C9AC_de Style_func_8043C9AC_de;

struct Access_s32_5C;
/* unbake published declaration: published_d13aa3e24574d6b03ac32707 */
typedef struct Access_s32_5C Access_s32_5C;

struct func_80228774_S7;
/* unbake published declaration: published_d1e7ac7895cba7000db10f52 */
typedef struct func_80228774_S7 func_80228774_S7;

struct func_80293268_S1;
/* unbake published declaration: published_d20ef780af47817785e49f5b */
struct func_80293268_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x88 - 0xC - sizeof(s32)];
    s32 unk88;
};

struct Work56EC8;
/* unbake published declaration: published_eb2fbe3b02c53987d4612dd6 */
typedef struct Work56EC8 Work56EC8;

struct Table;
/* unbake published declaration: published_d5432d3f9c224d0638d1841f */
typedef struct Table Table;

/* unbake published declaration: published_d309d4bdc9e361884e9a47f2 */
extern int D_80153500[];

struct func_8029A838_S1;
/* unbake published declaration: published_d34d772a66aee81e1bbc3dac */
struct func_8029A838_S1 {
    s32 unk0;
    char pad0[0x10 - 0x0 - sizeof(s32)];
    s32 unk10;
};

struct Record_func_80444C68_de;
/* unbake published declaration: published_d379b7e4a5f15b08a6cc9cfb */
struct Record_func_80444C68_de {
    char pad[8];
    s32 flags;
    char padC[0x14 - 0xC];
    s32 value;
};

struct ResourceManagerState;
/* unbake published declaration: published_d621fc2d5410edb1aab7f4f0 */
typedef struct ResourceManagerState ResourceManagerState;

struct Table_func_8028CE94_de;
/* unbake published declaration: published_d7e1ce4bd2fd42bb270d287f */
typedef struct Table_func_8028CE94_de Table_func_8028CE94_de;

struct D_800C7470_Pair;
/* unbake published declaration: published_d8bfffd8786b723a2506227a */
typedef struct D_800C7470_Pair D_800C7470_Pair;

struct Profile_func_80229554_de;
/* unbake published declaration: published_d976f3eff395d51affecab6b */
typedef struct Profile_func_80229554_de Profile_func_80229554_de;

struct func_8021846C_S3;
/* unbake published declaration: published_d9958afe2cb953476ff475e6 */
typedef struct func_8021846C_S3 func_8021846C_S3;

struct ControllerProfile;
/* unbake published declaration: published_f1312078707cb850b87b62b8 */
typedef struct ControllerProfile ControllerProfile;

struct func_8024B8DC_S2;
/* unbake published declaration: published_dcd1571440c6b91a678ef93d */
typedef struct func_8024B8DC_S2 func_8024B8DC_S2;

struct func_80205494_S3;
/* unbake published declaration: published_dcede80dccc770b28a31756d */
struct func_80205494_S3 {
    char pad0[0x14];
    unsigned int unk14;
};

struct TextLayerRect;
/* unbake published declaration: published_dd7ea923e4214c9210956082 */
struct TextLayerRect {
    char pad[0x14];
    int x;
    int right;
    int y;
};

struct Shared_GameMode;
/* unbake published declaration: published_de5c3da5469b3cacf140ab9f */
struct Shared_GameMode {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[0x8];
    s32 unk28;
};

struct Query;
/* unbake published declaration: published_dfa39b37eb876a779f5e99c3 */
struct Query {
    f32 radius;
    f32 bottom;
    f32 top;
    f32 top1;
    f32 bottom1;
    f32 top2;
    f32 bottom2;
    f32 minX;
    f32 minZ;
    f32 maxX;
    f32 maxZ;
    s32 flag;
};

struct Item_func_8041A940_de;
struct Menu_func_8041A940_de;
/* unbake published declaration: published_e19ed6f87353fc596fdc7bba */
struct Menu_func_8041A940_de {
    char pad0[8];
    struct Item_func_8041A940_de *items;
    char padC[0x54 - 0xC];
    s32 state;
};

struct func_8022E3B4_S3;
/* unbake published declaration: published_e1f9f4a8930606e923f1bf84 */
struct func_8022E3B4_S3 {
    char pad0[0x4];
    s16 unk4;
};

/* unbake published declaration: published_e20b724170fcd7667fab8e0c */
extern int D_80100598[];

struct func_802A6A54_S1;
/* unbake published declaration: published_e316f370dfbaf253be0b206e */
struct func_802A6A54_S1 {
    char pad0[0x14];
    f32 unk14;
    char pad14[0x24 - 0x14 - sizeof(f32)];
    f32 unk24;
    char pad24[0x34 - 0x24 - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
    char pad38[0x3C - 0x38 - sizeof(f32)];
    f32 unk3C;
};

struct func_80204468_S2;
/* unbake published declaration: published_e350f3237e7a7d30e4d94663 */
typedef struct func_80204468_S2 func_80204468_S2;

struct func_80203908_S4;
/* unbake published declaration: published_e3e48c2adb2a04bb100b987c */
struct func_80203908_S4 {
    char pad0[0x6C];
    f32 unk6C;
};

struct PixelFormat;
/* unbake published declaration: published_e3e74adbe366e9af56bbd7ab */
struct PixelFormat {
    char pad0[0x14];
    u32 mask[4];
    s32 shift[4];
};

struct func_8025C458_S3;
/* unbake published declaration: published_e42c62cca52effb4a261c210 */
typedef struct func_8025C458_S3 func_8025C458_S3;

struct func_8020D9C0_S1;
/* unbake published declaration: published_e4f7c8121b2df75bf36f81b5 */
typedef struct func_8020D9C0_S1 func_8020D9C0_S1;

struct func_802045CC_S1;
/* unbake published declaration: published_e5e306e770ff7b79d5339797 */
typedef struct func_802045CC_S1 func_802045CC_S1;

struct ALFilter_s_func_802B3000_de;
/* unbake published declaration: published_e6f0a0fa64427e029924b4e0 */
typedef struct ALFilter_s_func_802B3000_de ALFilter_s_func_802B3000_de;

struct ObjectStateC_2;
/* unbake published declaration: published_e7c4f43859960e50d0df5ff0 */
typedef struct ObjectStateC_2 ObjectStateC_2;

struct func_8026E158_S1;
/* unbake published declaration: published_e8ec2e2471b5c7b56ef6b144 */
typedef struct func_8026E158_S1 func_8026E158_S1;

struct PixelFormat;
/* unbake published declaration: published_e957d7eaa14fe08685d9163f */
typedef struct PixelFormat PixelFormat;

struct Input80216D3C;
/* unbake published declaration: published_e9b405420c87a901208ed9bf */
struct Input80216D3C {
    s32 unk0;
    s32 unk4;
    Triple vec;
};

struct CallbackStateC_4;
/* unbake published declaration: published_e9f01050f9cb79bde69d4556 */
struct CallbackStateC_4 {
    char pad0[0x8];
    void (*callback)(void *, s32, void *);
};

struct func_8029A9E0_S1;
/* unbake published declaration: published_eab9f423c7f824a858bf9f3e */
struct func_8029A9E0_S1 {
    char pad0[0x4];
    unsigned int unk4;
};

struct State_func_80421BEC_de;
/* unbake published declaration: published_eb4401fe0a39dc1651cb79a1 */
typedef struct State_func_80421BEC_de State_func_80421BEC_de;

struct Record_func_80409DCC_de;
struct func_8021846C_S3;
/* unbake published declaration: published_ebe1669012b0508cea35f47e */
struct Record_func_80409DCC_de {
    char pad[0x20];
    struct func_8021846C_S3 *inner;
};

struct Status;
/* unbake published declaration: published_ec001ec9617e1b5e9edde8a3 */
struct Status {
    char pad0[0x78];
    u8 active;
    char pad79[0x80 - 0x79];
    s8 kind;
    char pad81[150 - 0x81];
};

struct Model;
/* unbake published declaration: published_edff5738cab5afc0ccf09835 */
typedef struct Model Model;

struct func_802428C0_S1;
/* unbake published declaration: published_eebf7da90f63bb5ad095913a */
typedef struct func_802428C0_S1 func_802428C0_S1;

struct func_802045CC_S1;
/* unbake published declaration: published_ef14878068979f7d2c49afd6 */
struct func_802045CC_S1 {
    char pad0[0x12C];
    s32 unk12C;
};

struct Entry_func_804101BC_de;
/* unbake published declaration: published_ffe2dc1f46a1993ec6b6f57d */
struct Entry_func_804101BC_de {
    s32 unused;
    s32 flags;
    char rest[0x14];
};

struct HudStatusShared_Settings;
/* unbake published declaration: published_f0d300155f9d0b2722ff0704 */
struct HudStatusShared_Settings {
    s32 flags;
    s32 selection;
    char pad8[0x5];
    u8 trialKind;
    char padE[0x8];
    u8 hudFade;
    char pad17[0x6];
    u8 hudShown;
    char pad1E[0xB2];
    ListScreenRecord roster[8];
    char pad580[0x1];
    u8 language;
    char pad582[0x32];
    s32 state;
    char pad5B8[0x20];
    HudStatusShared_MatchRules rules;
    char pad674[0xC];
    s32 humanWon;
};

struct func_80205700_S1;
/* unbake published declaration: published_f1154bb75fe6762514922e89 */
struct func_80205700_S1 {
    char pad0[0xC];
    unsigned int unkC;
};

/* unbake published declaration: published_f2202df0f27df40a9ee02ee4 */
extern int D_8010BBF0[];

struct WeaponInfo;
/* unbake published declaration: published_f2280489c00d8b8a29935b5b */
typedef struct WeaponInfo WeaponInfo;

struct func_8024575C_S1;
/* unbake published declaration: published_f26ef9931caecab73a06d02a */
struct func_8024575C_S1 {
    char pad0[0xDC];
    int unkDC;
};

struct func_8020D9C0_S1;
/* unbake published declaration: published_f2a6847a295bc68a10f41668 */
struct func_8020D9C0_S1 {
    char pad0[0x14];
    f32 unk14;
};

/* unbake published declaration: published_f2cca3cd2558250d5daa552a */
extern int D_800CC388;

struct func_8020D280_S1;
/* unbake published declaration: published_f2e9df12b78b317b603ce5a9 */
struct func_8020D280_S1 {
    char pad0[0x28];
    int unk28;
};

struct Event_func_8024C1C4_de;
/* unbake published declaration: published_f30948a6d8cb4a6f30b151e9 */
typedef struct Event_func_8024C1C4_de Event_func_8024C1C4_de;

struct func_8022BC04_S3;
/* unbake published declaration: published_f32b77603867d81a58ed08bd */
struct func_8022BC04_S3 {
    char pad0[0x10];
    s32 unk10;
};

struct func_802A2BE0_S1;
/* unbake published declaration: published_f36a95f1a5f520bf531e6b1a */
struct func_802A2BE0_S1 {
    char pad0[0x8];
    void * unk8;
    char pad8[0x12 - 0x8 - sizeof(void*)];
    u16 unk12;
};

struct func_8020CB3C_S1;
/* unbake published declaration: published_f38c2601eb3340bdee4577b7 */
typedef struct func_8020CB3C_S1 func_8020CB3C_S1;

struct MenuSettings;
/* unbake published declaration: published_f85dc68eafa2bfb56b80f22e */
struct MenuSettings {
    u8 padding[0x581];
    u8 language;
};

struct func_802B7EB0_S1;
/* unbake published declaration: published_f572163464bc33b4adb3b983 */
struct func_802B7EB0_S1 {
    char pad0[0x14];
    char unk14;
    char pad14[0x3C - 0x14 - sizeof(char)];
    s32 unk3C;
    char pad3C[0x40 - 0x3C - sizeof(s32)];
    s32 unk40;
};

struct func_802831FC_S1;
/* unbake published declaration: published_f83c710b8aa9e390c4c159a6 */
struct func_802831FC_S1 {
    char pad0[0xFC3C];
    s8 * unkFC3C;
};

struct IntegerStateDC_2;
/* unbake published declaration: published_f865a32e1cd57bd910f5dee5 */
struct IntegerStateDC_2 {
    unsigned char padding[216];
    s32 state;
};

struct func_8022E3B4_S3;
/* unbake published declaration: published_f8882077f937e18bc7e9087e */
typedef struct func_8022E3B4_S3 func_8022E3B4_S3;

struct func_80239CDC_S1;
/* unbake published declaration: published_f90759d6eced0d78c4b45498 */
typedef struct func_80239CDC_S1 func_80239CDC_S1;

struct func_8020F2A8_S3;
/* unbake published declaration: published_f93a4ea3fb191cfb8b51d685 */
struct func_8020F2A8_S3 {
    char pad0[0x34];
    s32 unk34;
};

struct Node_func_80285B64_de;
/* unbake published declaration: published_f948bffa7c32050e0d261bb2 */
typedef struct Node_func_80285B64_de Node_func_80285B64_de;

struct func_8024C5C4_S2;
/* unbake published declaration: published_fa120508a38e192aae76f47a */
struct func_8024C5C4_S2 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    char unk8;
};

struct func_80258614_S1;
/* unbake published declaration: published_fa18d2903c258ce4bfcdd645 */
struct func_80258614_S1 {
    char pad0[0x110];
    s32 unk110;
    char pad110[0x138 - 0x110 - sizeof(s32)];
    char unk138;
    char pad138[0x1DB8 - 0x138 - sizeof(char)];
    char unk1DB8;
};

struct Obj_func_802B3EDC_de;
/* unbake published declaration: published_fb9946203df94b9793d178f3 */
typedef struct Obj_func_802B3EDC_de Obj_func_802B3EDC_de;

struct func_8020D0CC_S1;
/* unbake published declaration: published_fc7432c910ca424f652c3211 */
typedef struct func_8020D0CC_S1 func_8020D0CC_S1;

struct Params_func_802B2F10_de;
/* unbake published declaration: published_fcd3e8ea6edc5707d1449a2d */
struct Params_func_802B2F10_de {
    s16 f0;
    s32 f4;
    s16 f8;
};

struct func_802428C0_S1;
/* unbake published declaration: published_fe08c6cf4b200d1880af9a74 */
struct func_802428C0_S1 {
    char pad0[0x3C];
    unsigned int unk3C;
};

/* unbake published declaration: published_fe8c36e10b95641da3a6268c */
extern int D_80145070;

struct PlayerRecord;
/* unbake published declaration: published_ff0a79f54e2818908ae59912 */
struct PlayerRecord {
    char data[0x190];
};

struct func_8020CB3C_S1;
/* unbake published declaration: published_ff35b4b167af40916e84e69d */
struct func_8020CB3C_S1 {
    void * unk0;
    char pad0[0x4 - 0x0 - sizeof(void*)];
    s32 unk4;
};

struct func_8025E5B0_S1;
/* unbake published declaration: published_ff5aa22e7b5e3ba5c9ef9dde */
typedef struct func_8025E5B0_S1 func_8025E5B0_S1;

#endif
