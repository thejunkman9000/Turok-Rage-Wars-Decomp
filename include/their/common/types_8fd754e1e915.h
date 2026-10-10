#ifndef UNBAKE_COMMON_TYPES_8FD754E1E915_H
#define UNBAKE_COMMON_TYPES_8FD754E1E915_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
struct Player;
/* unbake published declaration: published_038392ee5aca3bbae9c77df5 */
struct Player {
    char pad0[8];
    Vec3 pos;
};

struct func_8020A028_S4;
/* unbake published declaration: published_065e9124cd99670a6d0994d5 */
typedef struct func_8020A028_S4 func_8020A028_S4;

struct func_8028FFB0_S3;
/* unbake published declaration: published_0c4c309fc9346bf78512568b */
typedef struct func_8028FFB0_S3 func_8028FFB0_S3;

struct func_8022A404_S1;
/* unbake published declaration: published_0ef470c36c33aac1678541f0 */
struct func_8022A404_S1 {
    char pad0[0x20];
    int unk20;
};

struct func_8022ADA0_S1;
/* unbake published declaration: published_15319c200fc4826ec4cd9060 */
struct func_8022ADA0_S1 {
    char pad0[0x5E4];
    int unk5E4;
};

struct func_80237E70_G1;
/* unbake published declaration: published_15bbcc9cf86837275a04fe48 */
struct func_80237E70_G1 {
    u8 * unk0;
};

struct func_8022C070_S1;
/* unbake published declaration: published_1622ac15db337834fc5f53a6 */
typedef struct func_8022C070_S1 func_8022C070_S1;

struct Player;
/* unbake published declaration: published_d8dcb86fbb8137ac4bad3624 */
typedef struct Player Player;

union func_80237E70_S1_UF24;
/* unbake published declaration: published_1cce067f7aad9c705606aa41 */
typedef union func_80237E70_S1_UF24 func_80237E70_S1_UF24;

struct Course;
/* unbake published declaration: published_216630242578523cec543667 */
struct Course {
    char pad0[0x28];
    u8 laps;
};

struct CollisionInfo8020CD74;
/* unbake published declaration: published_247806b135682bb989f76d39 */
typedef struct CollisionInfo8020CD74 CollisionInfo8020CD74;

struct func_8021C9B4_S2;
/* unbake published declaration: published_2992b6641f8252b38c3b8592 */
typedef struct func_8021C9B4_S2 func_8021C9B4_S2;

struct func_8021C9B4_S3;
/* unbake published declaration: published_38f41ea56ea46e3acfde77e6 */
typedef struct func_8021C9B4_S3 func_8021C9B4_S3;

struct func_8021C9B4_S3;
/* unbake published declaration: published_77f3131db20f5bb3cbf8ff28 */
struct func_8021C9B4_S3 {
    char pad0[0xC];
    s16 unkC;
};

union func_80234DD0_S1_U260;
/* unbake published declaration: published_2d71dad7fa5594ed0ff7ccff */
typedef union func_80234DD0_S1_U260 func_80234DD0_S1_U260;

struct Message;
/* unbake published declaration: published_4b2e377bb23513bebdbc1ce3 */
struct Message {
    char pad0[0xC];
    f32 size;
    f32 alpha;
    s32 kind;
    s32 timer;
    s32 target;
    s32 pad20;
    u8 *text;
    s32 pad28;
    s32 pad2C;
    f32 x;
    f32 y;
    f32 scaleX;
    f32 scaleY;
};

struct Message;
union func_80237E70_S1_UF24;
/* unbake published declaration: published_2e4db81399e9d66d8e3ada2c */
union func_80237E70_S1_UF24 {
    struct Message * v0;
    char v1;
};

struct func_8022C884_S1;
/* unbake published declaration: published_312c403436a35d2ca1d2f977 */
typedef struct func_8022C884_S1 func_8022C884_S1;

struct func_80237E70_S2;
/* unbake published declaration: published_314d45c0b4bdfcb0f8bcbce7 */
typedef struct func_80237E70_S2 func_80237E70_S2;

struct func_80209B64_S2;
/* unbake published declaration: published_38bff7fb5bfdb161bc875f6e */
struct func_80209B64_S2 {
    char pad0[0x93];
    u8 unk93;
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
struct SharedPlayer_func_80209CD8_de;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;
/* unbake published declaration: published_39f1aff0e9c5c2b6601a8142 */
struct SharedPlayer_func_80209CD8_de {
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
            struct SharedPlayer_func_80209CD8_de * unk1D8;
        } view1D8_22;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80209CD8_de * self;
        } view1D8_23;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80209CD8_de * f1D8;
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
            struct SharedPlayer_func_80209CD8_de * unk16E0;
        } view16E0_0;
        struct {
            struct SharedPlayer_func_80209CD8_de * next;
        } view16E0_1;
        struct {
            struct SharedPlayer_func_80209CD8_de * next;
        } view16E0_2;
    } views16E0;
};

struct func_80205314_S1;
/* unbake published declaration: published_3e2ccefdc488aa189f5b0dac */
struct func_80205314_S1 {
    char pad0[0x18];
    void * unk18;
};

/* unbake published declaration: published_458d8cd18563e836751fbb0d */
extern int D_800CE47C;

struct func_80229A54_S2;
/* unbake published declaration: published_4b5b21f928fc805642982cde */
struct func_80229A54_S2 {
    char pad0[0x5D8];
    char * unk5D8;
    char pad5D8[0x16E0 - 0x5D8 - sizeof(char*)];
    char * unk16E0;
};

struct Message;
/* unbake published declaration: published_5c8c7bc278828738eae8469a */
typedef struct Message Message;

union func_80234DD0_S1_U260;
/* unbake published declaration: published_fb7831f6f2d5bed7b1a3e492 */
union func_80234DD0_S1_U260 {
    Vec3 v0;
    f32 v1;
};

struct Message;
union func_80237E70_S2_UE40;
/* unbake published declaration: published_c783b163f708458b1694f686 */
union func_80237E70_S2_UE40 {
    char v0;
    struct Message * v1;
};

union func_80237E70_S2_UE40;
/* unbake published declaration: published_f70fbf877980fd25852eb909 */
typedef union func_80237E70_S2_UE40 func_80237E70_S2_UE40;

struct func_80237E70_S2;
/* unbake published declaration: published_53ecc0d6133b1b8a81791bf6 */
struct func_80237E70_S2 {
    char pad0[0xE40];
    func_80237E70_S2_UE40 unkE40;
};

struct ObjectLinks3C;
/* unbake published declaration: published_5bab6b1b518c4a13cf256fc1 */
typedef struct ObjectLinks3C ObjectLinks3C;

struct func_80237E70_S4;
/* unbake published declaration: published_5f2b8df85b968505a6e63f57 */
typedef struct func_80237E70_S4 func_80237E70_S4;

struct func_80209B64_S4;
/* unbake published declaration: published_819336a813f25bbdd5f7fbba */
typedef struct func_80209B64_S4 func_80209B64_S4;

struct func_80209B64_S4;
/* unbake published declaration: published_f41be357b4d486a06cf791d9 */
struct func_80209B64_S4 {
    char pad0[0x5D8];
    void * unk5D8;
};

struct func_80237E70_G1;
/* unbake published declaration: published_6173b1be7689f3d15438d0a3 */
typedef struct func_80237E70_G1 func_80237E70_G1;

struct Model_func_80223E34_de;
/* unbake published declaration: published_643a575b68115baf18e12e93 */
struct Model_func_80223E34_de {
    char pad0[0xF4];
    f32 height;
};

struct func_802285C4_S1;
/* unbake published declaration: published_e336c22feb33e5da5040e5e4 */
struct func_802285C4_S1 {
    char pad0[0x20];
    char * unk20;
};

struct Frame;
/* unbake published declaration: published_6766de618a8df73c02c9aa7b */
typedef struct Frame Frame;

union func_80209DAC_S2_U93;
/* unbake published declaration: published_6b0d69e26d6f7e781f737cec */
typedef union func_80209DAC_S2_U93 func_80209DAC_S2_U93;

struct func_80216BF4_S1;
/* unbake published declaration: published_7342324c038a4978f4405098 */
struct func_80216BF4_S1 {
    char pad0[0xC];
    f32 unkC;
};

union func_80209DAC_S2_U93;
/* unbake published declaration: published_9734fbdb4149c0946d24b60a */
union func_80209DAC_S2_U93 {
    u8 v0;
    s8 v1;
};

struct func_8021C9B4_S2;
/* unbake published declaration: published_83ff6a2d071859b2b55124fb */
struct func_8021C9B4_S2 {
    char pad0[0x81];
    u8 unk81;
    char pad81[0x8F - 0x81 - sizeof(u8)];
    u8 unk8F;
};

struct Message;
struct func_80237E70_S4;
/* unbake published declaration: published_86e11553ead31f9ee60a7439 */
struct func_80237E70_S4 {
    char pad0[0x4];
    struct Message * unk4;
};

struct func_8020D1FC_S1;
/* unbake published declaration: published_87984c97a621164625c54a6d */
struct func_8020D1FC_S1 {
    char pad0[0x38];
    s32 unk38;
};

struct func_8020D1FC_S1;
/* unbake published declaration: published_8ae23b59734ed7c5bd5a7b12 */
typedef struct func_8020D1FC_S1 func_8020D1FC_S1;

struct func_80219490_S2;
/* unbake published declaration: published_8b15a4ef2de8e3f7b26e965f */
typedef struct func_80219490_S2 func_80219490_S2;

struct func_80207ABC_S1;
/* unbake published declaration: published_95943328149f90ede93cc3ba */
typedef struct func_80207ABC_S1 func_80207ABC_S1;

struct func_80237E70_S1;
/* unbake published declaration: published_976a687fb0f4ca917c9183e4 */
struct func_80237E70_S1 {
    char pad0[0xF24];
    func_80237E70_S1_UF24 unkF24;
};

struct Model_func_80223E34_de;
/* unbake published declaration: published_97885ae3357bd7b19a31d475 */
typedef struct Model_func_80223E34_de Model_func_80223E34_de;

struct Course;
/* unbake published declaration: published_978ec52e02267703dd9401a4 */
typedef struct Course Course;

struct ObjectLinks3C;
/* unbake published declaration: published_98236de9655387e75400eb42 */
struct ObjectLinks3C {
    char pad0[0x18];
    char * unk_18;
    char pad18[0x38 - 0x18 - sizeof(char*)];
    s32 unk_38;
};

struct func_80219490_S2;
/* unbake published declaration: published_9c0c6f95fc3748021e7c02d4 */
struct func_80219490_S2 {
    char pad0[0x29C];
    f32 unk29C;
    char pad29C[0x2A0 - 0x29C - sizeof(f32)];
    f32 unk2A0;
    char pad2A0[0x2A4 - 0x2A0 - sizeof(f32)];
    f32 unk2A4;
    char pad2A4[0x2A8 - 0x2A4 - sizeof(f32)];
    f32 unk2A8;
};

struct func_80204620_S2;
/* unbake published declaration: published_a673890484372da256a4dfba */
struct func_80204620_S2 {
    char pad0[0x28];
    s16 unk28;
};

struct func_80207ABC_S1;
/* unbake published declaration: published_a5dfc2008d0a6ca4ec8e5840 */
struct func_80207ABC_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x38 - 0x18 - sizeof(void*)];
    s32 unk38;
};

struct func_8028FFB0_S3;
/* unbake published declaration: published_aaeca452f5b69bef91b4d8f0 */
struct func_8028FFB0_S3 {
    char pad0[0x1D8];
    char * unk1D8;
};

struct func_80203E78_S1;
/* unbake published declaration: published_aaef9e04cd149e7e9b9bff6e */
struct func_80203E78_S1 {
    char pad0[0x4];
    s32 unk4;
};

struct func_8022C070_S1;
/* unbake published declaration: published_abe235c706505cdfc9c84e24 */
struct func_8022C070_S1 {
    char pad0[0x2C];
    f32 unk2C;
};

struct func_80216BF4_S1;
/* unbake published declaration: published_afbc21781e0ef858054d572d */
typedef struct func_80216BF4_S1 func_80216BF4_S1;

struct func_8020A028_S4;
/* unbake published declaration: published_afe45d3df0eefb571c5630bc */
struct func_8020A028_S4 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
};

struct func_80228774_S1;
/* unbake published declaration: published_b236c4fb22a855c312ea6735 */
struct func_80228774_S1 {
    char pad0[0x20];
    void * unk20;
};

struct func_802285C4_S1;
/* unbake published declaration: published_b412c8b51980ce44aede35dd */
typedef struct func_802285C4_S1 func_802285C4_S1;

struct func_8022C884_S1;
/* unbake published declaration: published_bd2e412d9501070c02ec22ef */
struct func_8022C884_S1 {
    char pad0[0x1C];
    int unk1C;
    char pad1C[0x20 - 0x1C - sizeof(int)];
    int unk20;
    char pad20[0x24 - 0x20 - sizeof(int)];
    int unk24;
};

/* unbake published declaration: published_c6db770db09f6280f91dc11b */
extern int D_801371DC;

/* unbake published declaration: published_cb91fd939f7e0ef99c7fc438 */
extern int D_800CE430[];

struct func_8022A404_S1;
/* unbake published declaration: published_cf8cc049dea9915d8b543590 */
typedef struct func_8022A404_S1 func_8022A404_S1;

struct Record_func_80208158_de;
/* unbake published declaration: published_cfc4c1b204a2b8c2f13b03fa */
typedef struct Record_func_80208158_de Record_func_80208158_de;

struct func_80237E70_S1;
/* unbake published declaration: published_db39e476ff883658175a37b1 */
typedef struct func_80237E70_S1 func_80237E70_S1;

struct func_80209B64_S2;
/* unbake published declaration: published_dfe0864b2134717307392264 */
typedef struct func_80209B64_S2 func_80209B64_S2;

struct func_8022ADA0_S1;
/* unbake published declaration: published_e19ea50d9e037c6ecfac74d9 */
typedef struct func_8022ADA0_S1 func_8022ADA0_S1;

struct SharedPlayer_func_80209CD8_de;
/* unbake published declaration: published_e72f1deab26f50ba74b6f994 */
typedef struct SharedPlayer_func_80209CD8_de SharedPlayer_func_80209CD8_de;

struct func_80205314_S1;
/* unbake published declaration: published_e7acd01bb5bfca1882b4f478 */
typedef struct func_80205314_S1 func_80205314_S1;

struct CollisionInfo8020CD74;
/* unbake published declaration: published_f35af8eca6d43e4be2a06191 */
struct CollisionInfo8020CD74 {
    s32 w[7];
};

struct func_80229A54_S2;
/* unbake published declaration: published_faa25f1c1af7c6308a84c591 */
typedef struct func_80229A54_S2 func_80229A54_S2;

struct func_80203E78_S1;
/* unbake published declaration: published_faa789fba760926bcea48080 */
typedef struct func_80203E78_S1 func_80203E78_S1;

struct func_8021CD70_S4;
/* unbake published declaration: published_fc9408ddd3f226576d810ebb */
typedef struct func_8021CD70_S4 func_8021CD70_S4;

struct func_80228774_S1;
/* unbake published declaration: published_fd0ab19a5d575fc1818754e9 */
typedef struct func_80228774_S1 func_80228774_S1;

struct Frame;
/* unbake published declaration: published_fd78cec88c4c0b83f8a27fcd */
struct Frame {
    char pad0[0x110];
    void *colorImage;
};

#endif
