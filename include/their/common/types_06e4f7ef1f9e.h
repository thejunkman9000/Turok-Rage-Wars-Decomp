#ifndef UNBAKE_COMMON_TYPES_06E4F7EF1F9E_H
#define UNBAKE_COMMON_TYPES_06E4F7EF1F9E_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
/* unbake declaration evidence: evidence_15634c5f0d54764e20fb0b72 */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
#define RW_LOCALIZED_TEXT(fixed, eu_table, eu_x_table, language) ((eu_x_table)[language])
#else
#define RW_LOCALIZED_TEXT(fixed, eu_table, eu_x_table, language) ((eu_table)[language])
#endif
#else
#define RW_LOCALIZED_TEXT(fixed, eu_table, eu_x_table, language) (fixed)
#endif

/* unbake evidence input: LyogdW5iYWtlIGRlY2xhcmF0aW9uIGV2aWRlbmNlOiBldmlkZW5jZV8xNTYzNGM1ZjBkNTQ3NjRlMjBmYjBiNzIgKi8KI2lmIGRlZmluZWQoVkVSU0lPTl9FVSkgfHwgZGVmaW5lZChWRVJTSU9OX0VVX1gpCiNpZiBkZWZpbmVkKFZFUlNJT05fRVVfWCkKI2RlZmluZSBSV19MT0NBTElaRURfVEVYVChmaXhlZCwgZXVfdGFibGUsIGV1X3hfdGFibGUsIGxhbmd1YWdlKSAoKGV1X3hfdGFibGUpW2xhbmd1YWdlXSkKI2Vsc2UKI2RlZmluZSBSV19MT0NBTElaRURfVEVYVChmaXhlZCwgZXVfdGFibGUsIGV1X3hfdGFibGUsIGxhbmd1YWdlKSAoKGV1X3RhYmxlKVtsYW5ndWFnZV0pCiNlbmRpZgojZWxzZQojZGVmaW5lIFJXX0xPQ0FMSVpFRF9URVhUKGZpeGVkLCBldV90YWJsZSwgZXVfeF90YWJsZSwgbGFuZ3VhZ2UpIChmaXhlZCkKI2VuZGlmCg== */

struct func_80203C40_S1;
/* unbake published declaration: published_0003f32f202f251a68cf1ca1 */
struct func_80203C40_S1 {
    char pad0[0x100];
    s32 unk100;
};

struct Vector4f;
/* unbake published declaration: published_1e4532db7539a6306f2b3fdc */
typedef struct Vector4f Vector4f;

struct Vector4f;
/* unbake published declaration: published_1f88bceeb427d07926fd0b66 */
struct Vector4f {
    float x;
    float y;
    float z;
    float w;
};

struct func_8022C6D4_S1;
/* unbake published declaration: published_06261458ac5eea89c9a820f0 */
struct func_8022C6D4_S1 {
    char pad0[0x650];
    s16 unk650;
};

struct func_80205628_S3;
/* unbake published declaration: published_0628c008e458e172b993b9e6 */
struct func_80205628_S3 {
    char pad0[0xC];
    s32 unkC;
};

struct Hook;
/* unbake published declaration: published_7c0fcddf63c33d49f62a90db */
struct Hook {
    char pad[8];
    void (*fn)(void *, void *);
};

struct Hook;
/* unbake published declaration: published_ecec2bdefe90c3c8c304d131 */
typedef struct Hook Hook;

struct func_8022FD9C_S1;
/* unbake published declaration: published_07f8700b064d55fcc2823e8e */
typedef struct func_8022FD9C_S1 func_8022FD9C_S1;

struct AudioState;
/* unbake published declaration: published_08cd2d7cb27bd7f9d6bbf9c6 */
typedef struct AudioState AudioState;

struct func_80203B60_S1;
/* unbake published declaration: published_099df7869ce039a063a968fb */
typedef struct func_80203B60_S1 func_80203B60_S1;

struct Actor_func_8028CC34_de;
/* unbake published declaration: published_8a7465b3d7454e1e3634eb6d */
struct Actor_func_8028CC34_de {
    char pad[0x1D8];
    int link;
};

struct Actor_func_8028CC34_de;
/* unbake published declaration: published_98f5706f18d687fed7e6424c */
typedef struct Actor_func_8028CC34_de Actor_func_8028CC34_de;

struct Shape_func_8020AF9C_de_2;
/* unbake published declaration: published_1354340abafc8f04a04abea9 */
struct Shape_func_8020AF9C_de_2 {
    int field_0;
};

union func_80230BB8_S2_U1D8;
/* unbake published declaration: published_816ead12706cdc10433e98e6 */
union func_80230BB8_S2_U1D8 {
    char * v0;
    void * v1;
};

union func_80230BB8_S2_U1D8;
/* unbake published declaration: published_bdcc23761b79a60b48ef71d1 */
typedef union func_80230BB8_S2_U1D8 func_80230BB8_S2_U1D8;

struct func_80232C78_S4;
/* unbake published declaration: published_1603d44a49db15f24cbe85b6 */
typedef struct func_80232C78_S4 func_80232C78_S4;

struct SharedPlayer;
/* unbake published declaration: published_9f9a677e1355e1ffb5863504 */
typedef struct SharedPlayer SharedPlayer;

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
struct Rider_func_80203278_de;
struct Settings;
struct SharedPlayer;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;
/* unbake published declaration: published_167da96ca26d112670b49534 */
struct SharedPlayer {
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
            struct SharedPlayer * unk1D8;
        } view1D8_22;
        struct {
            char pad[0x1BC];
            struct SharedPlayer * self;
        } view1D8_23;
        struct {
            char pad[0x1BC];
            struct SharedPlayer * f1D8;
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
            struct View * view;
        } view5DC_2;
        struct {
            u8 pad4[8];
        } view5DC_3;
        struct {
            void * entity;
        } view5DC_4;
        struct {
            struct Rider_func_80203278_de * rider;
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
            struct SharedPlayer * unk16E0;
        } view16E0_0;
        struct {
            struct SharedPlayer * next;
        } view16E0_1;
        struct {
            struct SharedPlayer * next;
        } view16E0_2;
    } views16E0;
};

/* unbake published declaration: published_5a94cb9040e6eb0eb981dc94 */
struct Rider_func_80203278_de {
    char pad0[0x80];
    SharedPlayer *target;
    char pad84[0xAC];
    Vec3 aim;
};

struct WeaponFireState;
/* unbake published declaration: published_1ac661e0b4305bf3b2f44e85 */
struct WeaponFireState {
    char pad0[0x34];
    s8 variant;
    char pad35[0x124 - 0x35];
    union { f32 spinStep; s32 reset; };
    f32 spin;
    char pad12C[0x13C - 0x12C];
    s32 mode;
    char pad140[4];
    s32 rounds;
    char pad148[4];
    s32 triggered;
    s32 alternate;
};

union func_80203908_S3_U124;
/* unbake published declaration: published_1b0655e0e29ff68d91793fea */
typedef union func_80203908_S3_U124 func_80203908_S3_U124;

union func_80203908_S3_U124;
/* unbake published declaration: published_eac5088e5709bdb6118d57e4 */
union func_80203908_S3_U124 {
    f32 v0;
    s32 v1;
};

struct func_80232FE8_S1;
/* unbake published declaration: published_1bb5e40acd3396440c2ceae0 */
struct func_80232FE8_S1 {
    char pad0[0x100];
    s32 unk100;
    char pad100[0x1D8 - 0x100 - sizeof(s32)];
    void * unk1D8;
};

struct Shared_Actor;
/* unbake published declaration: published_217a8efd9f2fe489d98cb330 */
typedef struct Shared_Actor Shared_Actor;

struct func_80230BB8_S3;
/* unbake published declaration: published_22e14b164146481b6555f245 */
typedef struct func_80230BB8_S3 func_80230BB8_S3;

union func_8022FD9C_S2_U770;
/* unbake published declaration: published_2722fefbea959ec59da10307 */
union func_8022FD9C_S2_U770 {
    s16 v0;
    u16 v1;
};

struct func_8022E3B4_S1;
/* unbake published declaration: published_280d8b514f2128cbc616e3a3 */
struct func_8022E3B4_S1 {
    char pad0[0x1450];
    s32 unk1450;
};

struct func_802063EC_S2;
/* unbake published declaration: published_28f6d040d476ed8980570892 */
struct func_802063EC_S2 {
    char pad0[0x128];
    s32 unk128;
};

struct func_80230BB8_S3;
/* unbake published declaration: published_2a957bf9cd36fcd92d7bf53c */
struct func_80230BB8_S3 {
    char pad0[0x23C];
    s32 unk23C;
};

struct func_8020A028_S3;
/* unbake published declaration: published_2f40ea0e0b30df93e37e8708 */
typedef struct func_8020A028_S3 func_8020A028_S3;

struct func_8022FD9C_S4;
/* unbake published declaration: published_30ad9d87e1e03c3a3ae219ed */
typedef struct func_8022FD9C_S4 func_8022FD9C_S4;

struct SettingsE;
/* unbake published declaration: published_32fd468ca0caebfb5fc52fcb */
struct SettingsE {
    char pad0[0xD];
    u8 players;
};

struct func_8022FD9C_S3;
/* unbake published declaration: published_332b884b6d23c6f3a9d3dec7 */
typedef struct func_8022FD9C_S3 func_8022FD9C_S3;

union func_8022FD9C_S2_U770;
/* unbake published declaration: published_dde02fb5f9c5cb1c6105a457 */
typedef union func_8022FD9C_S2_U770 func_8022FD9C_S2_U770;

struct func_8022FD9C_S2;
/* unbake published declaration: published_35673c27dc6787862c6a9f72 */
struct func_8022FD9C_S2 {
    char pad0[0x5DC];
    void * unk5DC;
    char pad5DC[0x62E - 0x5DC - sizeof(void*)];
    s16 unk62E;
    char pad62E[0x770 - 0x62E - sizeof(s16)];
    func_8022FD9C_S2_U770 unk770;
    char pad770[0x13B8 - 0x770 - sizeof(func_8022FD9C_S2_U770)];
    s32 unk13B8;
    char pad13B8[0x13BC - 0x13B8 - sizeof(s32)];
    s32 unk13BC;
    char pad13BC[0x13C0 - 0x13BC - sizeof(s32)];
    s32 unk13C0;
};

struct IntegerState11C4;
/* unbake published declaration: published_3bac764a2b7d0a4bd906f376 */
typedef struct IntegerState11C4 IntegerState11C4;

struct func_80203DF0_S3;
/* unbake published declaration: published_3c9a89ed52b78e6797a5f6f1 */
typedef struct func_80203DF0_S3 func_80203DF0_S3;

struct func_80203908_S1;
/* unbake published declaration: published_4241f3967809264f793d6eff */
struct func_80203908_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0xE4 - 0x18 - sizeof(void*)];
    u16 unkE4;
    char padE4[0x100 - 0xE4 - sizeof(u16)];
    s32 unk100;
};

struct func_80205494_S2;
/* unbake published declaration: published_44f1e94d9e4feda248e44987 */
typedef struct func_80205494_S2 func_80205494_S2;

struct func_80232C78_S4;
/* unbake published declaration: published_4a926ef3ef03d90762d94237 */
struct func_80232C78_S4 {
    char pad0[0x18];
    f32 unk18;
};

struct func_8022FD9C_Record;
/* unbake published declaration: published_4b39cbd5fcacfb27dcaee8b6 */
struct func_8022FD9C_Record {
    char pad0[0x54];
    s32 unk54;
};

struct WeaponActionRecord;
/* unbake published declaration: published_4d5aebce60f6f9cbda5f46cb */
typedef struct WeaponActionRecord WeaponActionRecord;

struct Info;
/* unbake published declaration: published_6c08a5e2e0388cd2921018e3 */
typedef struct Info Info;

struct Info;
/* unbake published declaration: published_b0589d37e25377a2dbc09d06 */
struct Info {
    unsigned char raw[0x18];
};

struct Shared_Actor;
struct Shared_Entity;
struct Shared_Variant;
/* unbake published declaration: published_4e1ae7670a0086d70418cbe0 */
struct Shared_Actor {
    u8 pad0;
    u8 color;
    u8 pad1;
    s8 subtype;
    u8 pad2[20];
    struct Shared_Variant * variant;
    u8 pad3[152];
    s32 action;
    u8 pad4[0x100 - 0xB8];
    s32 weaponFlags;
    u8 pad104[0x140 - 0x104];
    Info effects[6];
    u8 pad5[8];
    struct Shared_Entity * entity;
};

struct WeaponFireState;
/* unbake published declaration: published_58369032d929fd6f56a91158 */
typedef struct WeaponFireState WeaponFireState;

struct func_802077F4_S2;
/* unbake published declaration: published_bfbb3446182e9f6dcbc1a63f */
typedef struct func_802077F4_S2 func_802077F4_S2;

struct func_802077F4_S2;
/* unbake published declaration: published_c618d2a659a28c30df5bb933 */
struct func_802077F4_S2 {
    char pad0[0x4];
    f32 unk4;
};

struct func_8024BE70_S1;
/* unbake published declaration: published_5ce5c72a42c921a210285495 */
struct func_8024BE70_S1 {
    char pad0[0x1];
    s8 unk1;
};

struct func_80203908_S2;
/* unbake published declaration: published_5fa03bd4524e5cfb76bac251 */
typedef struct func_80203908_S2 func_80203908_S2;

struct func_80203B60_S2;
/* unbake published declaration: published_62ad5ec4bc602e154eea9aa7 */
typedef struct func_80203B60_S2 func_80203B60_S2;

struct func_8022FD9C_Record;
/* unbake published declaration: published_62d43e74befc589884542fb8 */
typedef struct func_8022FD9C_Record func_8022FD9C_Record;

struct WeaponActionRecord;
/* unbake published declaration: published_6884c06c14329493c4d4cf0b */
struct WeaponActionRecord {
    s16 action;
    char pad2[0x16];
};

struct func_802063EC_S2;
/* unbake published declaration: published_69c3cd7d3cf7ddc934ea2bfa */
typedef struct func_802063EC_S2 func_802063EC_S2;

struct Owner_func_8020388C_de;
/* unbake published declaration: published_6ce041ca83e6bfd3dc56040d */
struct Owner_func_8020388C_de {
    char pad[0xE4];
    u16 id;
};

struct func_80232FE8_S1;
/* unbake published declaration: published_76299e1815b7e4eac1091557 */
typedef struct func_80232FE8_S1 func_80232FE8_S1;

struct func_80203908_S1;
/* unbake published declaration: published_7656d2864fc76160fad1c537 */
typedef struct func_80203908_S1 func_80203908_S1;

struct AudioState;
/* unbake published declaration: published_775c3548a50ff2f9cce1ce83 */
struct AudioState {
    char pad0[0x54];
    s32 active;
    char pad58[0x18];
    s32 mode;
};

struct func_8022E3B4_S1;
/* unbake published declaration: published_78af0e7254b94d145dfb0f82 */
typedef struct func_8022E3B4_S1 func_8022E3B4_S1;

struct func_80203908_S2;
/* unbake published declaration: published_79259aa61f1767d062b75f69 */
struct func_80203908_S2 {
    char pad0[0x14];
    char unk14;
};

struct func_8022FD9C_S1;
/* unbake published declaration: published_7a197b83fcd5ce97f156c9f9 */
struct func_8022FD9C_S1 {
    char pad0[0x1];
    s8 unk1;
    char pad1[0x1D8 - 0x1 - sizeof(s8)];
    void * unk1D8;
};

struct func_80203C40_S1;
/* unbake published declaration: published_80412e8a3883cfdb1701c8fe */
typedef struct func_80203C40_S1 func_80203C40_S1;

struct func_80203C84_S1;
/* unbake published declaration: published_84d4b303c1ce4c9a24fb40c2 */
typedef struct func_80203C84_S1 func_80203C84_S1;

struct func_80203B60_S1;
/* unbake published declaration: published_8707cde93cd1113e5d516147 */
struct func_80203B60_S1 {
    char pad0[0x18];
    char * unk18;
    char pad18[0x100 - 0x18 - sizeof(char*)];
    s32 unk100;
};

struct func_80203DF0_S3;
/* unbake published declaration: published_9337442bb0c5112cfcfa3519 */
struct func_80203DF0_S3 {
    char pad0[0x3C];
    s32 unk3C;
    char pad3C[0x40 - 0x3C - sizeof(s32)];
    s32 unk40;
};

struct func_80203C84_S1;
/* unbake published declaration: published_9754e5a293beffa17f8b0631 */
struct func_80203C84_S1 {
    char pad0[0x34];
    s8 unk34;
};

struct func_80203DF0_S1;
/* unbake published declaration: published_9b8ea508bf9ec07714a67474 */
struct func_80203DF0_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    void * unk8;
};

/* unbake published declaration: published_9cfea25b2f10dfacdbfc8d9f */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
#define RW_LOCALIZED_TEXT(fixed, eu_table, eu_x_table, language) ((eu_x_table)[language])
#else
#define RW_LOCALIZED_TEXT(fixed, eu_table, eu_x_table, language) ((eu_table)[language])
#endif
#else
#define RW_LOCALIZED_TEXT(fixed, eu_table, eu_x_table, language) (fixed)
#endif

struct func_8022FD9C_S3;
/* unbake published declaration: published_a06c92c2e3b2a63d3cba1d99 */
struct func_8022FD9C_S3 {
    char pad0[0x2C];
    s32 unk2C;
    char pad2C[0x120 - 0x2C - sizeof(s32)];
    s32 unk120;
    char pad120[0x124 - 0x120 - sizeof(s32)];
    s32 unk124;
    char pad124[0x128 - 0x124 - sizeof(s32)];
    s32 unk128;
    char pad128[0x130 - 0x128 - sizeof(s32)];
    s32 unk130;
};

struct IntegerState11C4;
/* unbake published declaration: published_a169505495ef350409a35ec4 */
struct IntegerState11C4 {
    unsigned char padding_0[4544];
    s32 unk_11C0;
};

struct func_80205494_S2;
/* unbake published declaration: published_a9eceb126be005afed0c8c7b */
struct func_80205494_S2 {
    char pad0[0xCB];
    signed char unkCB;
};

struct func_80232FE8_S3;
/* unbake published declaration: published_ac8c06e6a0b1c60c080b0716 */
typedef struct func_80232FE8_S3 func_80232FE8_S3;

struct func_8022BECC_S1;
/* unbake published declaration: published_b4d84fc60610fd3072bb4be1 */
typedef struct func_8022BECC_S1 func_8022BECC_S1;

struct func_80232FE8_S3;
/* unbake published declaration: published_b4f09c3043dddde2201bad8e */
struct func_80232FE8_S3 {
    char pad0[0x13C];
    s32 unk13C;
};

struct func_80203AB0_S1;
/* unbake published declaration: published_b50d1078391ecf9953f4e750 */
struct func_80203AB0_S1 {
    char pad0[0xCB];
    char unkCB;
};

struct func_80203DF0_S1;
/* unbake published declaration: published_bfa59073273aa440dee9d6e7 */
typedef struct func_80203DF0_S1 func_80203DF0_S1;

struct func_8020A028_S3;
/* unbake published declaration: published_bff43bccc7dacc8221ef4184 */
struct func_8020A028_S3 {
    char pad0[0x1D8];
    void * unk1D8;
};

struct func_8022FD9C_S4;
/* unbake published declaration: published_c10e83d39cebef3353fd5616 */
struct func_8022FD9C_S4 {
    char pad0[0x58];
    s32 unk58;
};

struct func_8022C6D4_S1;
/* unbake published declaration: published_c1ecec37c03d616d0925a6c4 */
typedef struct func_8022C6D4_S1 func_8022C6D4_S1;

struct SettingsE;
/* unbake published declaration: published_cba23257d420dfdc2100a4df */
typedef struct SettingsE SettingsE;

struct func_8022BECC_S1;
/* unbake published declaration: published_ccadde14a836d5f8f43d2626 */
struct func_8022BECC_S1 {
    char pad0[0x62E];
    short unk62E;
};

struct func_80203AB0_S1;
/* unbake published declaration: published_d10bb3cccd45d9097a134fdf */
typedef struct func_80203AB0_S1 func_80203AB0_S1;

struct func_80203B60_S3;
/* unbake published declaration: published_d491af75e10cb5bb73c186a7 */
typedef struct func_80203B60_S3 func_80203B60_S3;

struct Owner;
/* unbake published declaration: published_d50d51ef2524703bd6c21e18 */
struct Owner {
    char pad0[0x18];
    char *track;
};

struct func_80205628_S3;
/* unbake published declaration: published_e006d98ff1ff1735a788a539 */
typedef struct func_80205628_S3 func_80205628_S3;

struct func_8024BE70_S1;
/* unbake published declaration: published_d981b530a89db9f1232dbf73 */
typedef struct func_8024BE70_S1 func_8024BE70_S1;

struct func_80203B60_S3;
/* unbake published declaration: published_e890c26b407b34ef7403e4bf */
struct func_80203B60_S3 {
    char pad0[0x110];
    s32 unk110;
};

struct func_80203B60_S2;
/* unbake published declaration: published_e9f8a41119649362904c3b24 */
struct func_80203B60_S2 {
    char pad0[0xC];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
};

struct func_8022FD9C_S2;
/* unbake published declaration: published_ed058b6d8bd6d4e7ab12ebc4 */
typedef struct func_8022FD9C_S2 func_8022FD9C_S2;

#endif
