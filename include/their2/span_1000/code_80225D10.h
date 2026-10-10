#ifndef UNBAKE_SPAN_1000_CODE_80225D10_H
#define UNBAKE_SPAN_1000_CODE_80225D10_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
struct func_802285C4_S2;
/* unbake published declaration: published_037df425b11710e33a8249ff */
typedef struct func_802285C4_S2 func_802285C4_S2;

/* unbake published declaration: published_0828b590eabe66f051645287 */
extern float D_800C2B5C_de;

/* unbake published declaration: published_0aa4b297bf4a25067618163d */
extern float D_800C2B64_de;

struct Rules_func_802283B8_de;
/* unbake published declaration: published_0dd86c1634143700da477d61 */
typedef struct Rules_func_802283B8_de Rules_func_802283B8_de;

struct Game_func_802283B8_de;
/* unbake published declaration: published_0f59b2c8aa0cd62ba8f1f8a7 */
typedef struct Game_func_802283B8_de Game_func_802283B8_de;

struct Rules;
/* unbake published declaration: published_120d294eb88d9abc03185b9a */
struct Rules {
    char pad0[0x24];
    s32 teams;
    char pad28[0x78 - 0x28];
    s32 teamRule;
};

struct Scores;
struct Scores {
    char pad[0x1c];
    short score[8];
};
struct Obj_func_802281F0_de;
struct Scores;
/* unbake published declaration: published_cc2bd6790b2f308941cf2024 */
struct Obj_func_802281F0_de {
    char pad[0x5d4];
    int unk5D4;
    struct Scores *unk5D8;
    char pad5dc[0x1104];
    struct Obj_func_802281F0_de *unk16E0;
};

struct Obj_func_802281F0_de;
struct Root;
/* unbake published declaration: published_137c1db27bf993072f982916 */
struct Root {
    char pad[0x20];
    struct Obj_func_802281F0_de *unk20;
};

struct Stats;
/* unbake published declaration: published_147c4c01ddc6ff78cddf7830 */
typedef struct Stats Stats;

struct Shape_typemap_165;
struct func_802285C4_S4;
/* unbake published declaration: published_182329cbb622fc0d769c5a44 */
struct func_802285C4_S4 {
    char pad0[0x2F0];
    Triple unk2F0;
    char pad2F0[0x2FC - 0x2F0 - sizeof(Triple)];
    s32 unk2FC;
    char pad2FC[0x344 - 0x2FC - sizeof(s32)];
    struct Shape_typemap_165 unk344;
    char pad344[0x354 - 0x344 - sizeof(struct Shape_typemap_165)];
    f32 unk354;
    char pad354[0x3E8 - 0x354 - sizeof(f32)];
    s32 unk3E8;
};

/* unbake published declaration: published_1826fc0481a16ed808a83aa2 */
extern float D_800C2BE8_de;

/* unbake published declaration: published_19a00b07b6d748b2ef9814c7 */
extern float D_800C2B50_de;

struct HudGlobals;
/* unbake published declaration: published_1a4f2a7cc60dd31e39ec5757 */
struct HudGlobals {
    u8 fade;
    u8 reserved;
    u8 state;
};

struct func_802285C4_S4;
/* unbake published declaration: published_1b0134716e2b463a79368994 */
typedef struct func_802285C4_S4 func_802285C4_S4;

struct SubActor;
/* unbake published declaration: published_1eb299c3785edb9faa42d70d */
struct SubActor {
    char pad0[4];
    u16 unk4;
    char pad6[0x8F - 6];
    u8 unk8F;
    u8 unk90;
};

struct func_80228774_S2;
/* unbake published declaration: published_22895d0c10429da0b68865c9 */
typedef struct func_80228774_S2 func_80228774_S2;

struct Player_func_80229FA0_de;
struct Player_func_80229FA0_de {
    char pad0[146];
    u8 unk92;
    u8 unk93;
};
struct Obj_func_80229FA0_de;
struct Player_func_80229FA0_de;
/* unbake published declaration: published_22f8bc9cd3bcff3700132763 */
struct Obj_func_80229FA0_de {
    u8 unk0;
    char pad1[227];
    unsigned short unkE4;
    char pade6[26];
    int unk100;
    char pad104[40];
    struct Obj_func_80229FA0_de * unk12C;
    char pad130[168];
    struct Obj_func_80229FA0_de * unk1D8;
    char pad1dc[1020];
    struct Player_func_80229FA0_de * unk5D8;
    char pad5dc[3700];
    int unk1450;
};

struct Held;
/* unbake published declaration: published_24b1ef2fdb5f6ca165a5adc7 */
typedef struct Held Held;

struct Rules;
/* unbake published declaration: published_24ceb02e2014d9fd58bae40f */
typedef struct Rules Rules;

struct Round;
/* unbake published declaration: published_28e3d8ab6bbed8991dd38e46 */
typedef struct Round Round;

/* unbake published declaration: published_2ca20bd1df323110a6392d54 */
extern float D_800C2B60_de;

struct ObjectLinks16E4_2;
/* unbake published declaration: published_2ced0f4f42a3724fe746b860 */
struct ObjectLinks16E4_2 {
    char pad0[0x70];
    s32 unk_70;
    char pad70[0x358 - 0x70 - sizeof(s32)];
    s32 unk_358;
    char pad358[0x16E0 - 0x358 - sizeof(s32)];
    void * unk_16E0;
};

struct ObjectState5E8;
/* unbake published declaration: published_2e247eafe8002d6503471297 */
struct ObjectState5E8 {
    char pad0[0x170];
    char unk_170;
    char pad170[0x5E4 - 0x170 - sizeof(char)];
    s32 unk_5E4;
};

struct func_80229A54_S1;
/* unbake published declaration: published_2f4a86839a73ffaf48faa08e */
struct func_80229A54_S1 {
    char pad0[0x4];
    char * unk4;
    char pad4[0x20 - 0x4 - sizeof(char*)];
    char * unk20;
};

/* unbake published declaration: published_31a917a672742418728cb58a */
extern float D_800C2B58_de;

struct SharedPlayer_func_80226A34_de;
/* unbake published declaration: published_7887955cf823ac19eea79f58 */
typedef struct SharedPlayer_func_80226A34_de SharedPlayer_func_80226A34_de;

struct World_func_80226A34_de;
/* unbake published declaration: published_3342d92857f1c8d5867fa996 */
struct World_func_80226A34_de {
    char pad0[0x20];
    SharedPlayer_func_80226A34_de *players;
    char pad24[0x40 - 0x24];
    s32 spin;
};

struct ActorNode;
/* unbake published declaration: published_33ffc4682b1b728772942735 */
typedef struct ActorNode ActorNode;

struct Receiver;
/* unbake published declaration: published_36047d197405697aeac71851 */
struct Receiver {
    char pad[0x5A4];
    s32 index;
    s32 amount;
};

struct func_80226524_S1;
/* unbake published declaration: published_379100aac4e51ea6c1e8e53d */
struct func_80226524_S1 {
    char pad0[0x8];
    func_8020E674_S1_U8 unk8;
    char pad8[0x1210 - 0x8 - sizeof(func_8020E674_S1_U8)];
    s32 unk1210;
};

/* unbake published declaration: published_3b700e6ffa4c6425949e2cdc */
extern float D_800C2C08_de;

struct ObjectLinks18_3;
/* unbake published declaration: published_3e85de45d3c7ab46e025bb90 */
struct ObjectLinks18_3 {
    char pad0[0x4];
    f32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    void * unk_8;
    char pad8[0xC - 0x8 - sizeof(void*)];
    f32 unk_C;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk_10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    s32 unk_14;
};

struct SubActor;
/* unbake published declaration: published_4206ce78d244f2fa01efacbf */
typedef struct SubActor SubActor;

struct Actor_func_80228FB8_de;
/* unbake published declaration: published_462692d3d906f94429e141f3 */
typedef struct Actor_func_80228FB8_de Actor_func_80228FB8_de;

struct SharedPlayer_func_802283B8_de;
/* unbake published declaration: published_a0118ec9e73196e95bc1e653 */
typedef struct SharedPlayer_func_802283B8_de SharedPlayer_func_802283B8_de;

struct Body;
struct Character;
struct Controller;
struct Ctrl;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct Profile;
struct Record;
struct Record_func_80208158_de;
struct Rider;
struct Settings;
struct SharedPlayer_func_802283B8_de;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;
/* unbake published declaration: published_a549f1c46bfa30029ae5452d */
struct SharedPlayer_func_802283B8_de {
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
            struct SharedPlayer_func_802283B8_de * unk1D8;
        } view1D8_22;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_802283B8_de * self;
        } view1D8_23;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_802283B8_de * f1D8;
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
            struct Record_func_80208158_de * controls;
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
            struct SharedPlayer_func_802283B8_de * unk16E0;
        } view16E0_0;
        struct {
            struct SharedPlayer_func_802283B8_de * next;
        } view16E0_1;
        struct {
            struct SharedPlayer_func_802283B8_de * next;
        } view16E0_2;
    } views16E0;
};

struct World_func_802283B8_de;
/* unbake published declaration: published_4db590050fe29f5fe6d475a0 */
struct World_func_802283B8_de {
    char pad0[0x20];
    SharedPlayer_func_802283B8_de *players;
};

struct IntegerStateB4C;
/* unbake published declaration: published_4fb1bd39d868ada3e14c9ddc */
typedef struct IntegerStateB4C IntegerStateB4C;

/* unbake published declaration: published_52bde7afe31f10a3bc1d37a9 */
extern void func_80225F44_de();

struct ViewState;
/* unbake published declaration: published_569db5e1b9c1cc6b211c1ce5 */
struct ViewState {
    u8 bytes[0x29C];
    f32 width;
    f32 height;
};

struct Player_func_80228FB8_de;
/* unbake published declaration: published_581a6918ac5e3b198c65afd5 */
typedef struct Player_func_80228FB8_de Player_func_80228FB8_de;

struct Rules_func_802283B8_de;
/* unbake published declaration: published_ab8137664e6640111414ece5 */
struct Rules_func_802283B8_de {
    char pad0[0x14];
    f32 timeLimit;
    s32 scoreLimit;
    s32 locked;
    char pad20[0x54 - 0x20];
    s32 sudden;
    char pad58[0x9C - 0x58];
    s32 rounds;
    char padA0[0xA8 - 0xA0];
    s32 humanWon;
};

struct Game_func_802283B8_de;
/* unbake published declaration: published_5d5e4121a15abe6c032ff965 */
struct Game_func_802283B8_de {
    char pad0[0xCB9];
    u8 trialKind;
    char padCBA[0xCC9 - 0xCBA];
    u8 allowed;
    char padCCA[0x1278 - 0xCCA];
    s32 paused;
    char pad127C[0x1284 - 0x127C];
    Rules_func_802283B8_de rules;
};

struct func_80226524_S1;
/* unbake published declaration: published_5f224dada72948b01abb8e98 */
typedef struct func_80226524_S1 func_80226524_S1;

struct IntegerStateB4C;
/* unbake published declaration: published_6815850c856c54a1dfc6b6b9 */
struct IntegerStateB4C {
    char pad0[0xB48];
    s32 unk_B48;
};

struct ObjectLinks18_3;
/* unbake published declaration: published_6b840e65397b58a99d97d21b */
typedef struct ObjectLinks18_3 ObjectLinks18_3;

struct Game;
/* unbake published declaration: published_6e40faffedfe84c925e01fc4 */
struct Game {
    s32 state;
    char pad4[0x24 - 0x4];
    Rules rules;
};

struct func_80229A54_S1;
/* unbake published declaration: published_6ec810a92d317b9b80120287 */
typedef struct func_80229A54_S1 func_80229A54_S1;

struct View_func_80226340_de;
/* unbake published declaration: published_70774f098f0388c84be5a782 */
typedef struct View_func_80226340_de View_func_80226340_de;

struct ActorNode;
struct SubActor;
/* unbake published declaration: published_724d90cdd5d43bb457e01edc */
struct ActorNode {
    char pad0[0x5D8];
    struct SubActor *unk5D8;
    char pad1[0x16E0 - 0x5D8 - 4];
    struct ActorNode *unk16E0;
};

struct Receiver;
/* unbake published declaration: published_7467c7ac93d12534f1f7bd2d */
typedef struct Receiver Receiver;

struct Actor_func_802285E8_de;
/* unbake published declaration: published_79f34ff841a53eb83e263382 */
typedef struct Actor_func_802285E8_de Actor_func_802285E8_de;

struct func_80228774_S2;
/* unbake published declaration: published_7a2fb257716d9053617ea093 */
struct func_80228774_S2 {
    char pad0[0xC4];
    s32 unkC4;
    char padC4[0xD0 - 0xC4 - sizeof(s32)];
    s32 unkD0;
    char padD0[0x100 - 0xD0 - sizeof(s32)];
    s32 unk100;
    char pad100[0x2E8 - 0x100 - sizeof(s32)];
    char unk2E8;
    char pad2E8[0x5DC - 0x2E8 - sizeof(char)];
    void * unk5DC;
    char pad5DC[0x16E0 - 0x5DC - sizeof(void*)];
    void * unk16E0;
};

/* unbake published declaration: published_7e376c1886a52c147c9ddd63 */
extern float D_800C2B54_de;

struct IntegerState1230;
/* unbake published declaration: published_81acd3f882354783efcb77b7 */
typedef struct IntegerState1230 IntegerState1230;

struct IntegerState948;
/* unbake published declaration: published_845b84506b046ecd72fd7e74 */
struct IntegerState948 {
    char pad0[0x944];
    s32 unk_944;
};

struct ObjectLinks94C;
/* unbake published declaration: published_84c33c1a7d6bb40a7d94efcc */
typedef struct ObjectLinks94C ObjectLinks94C;

struct IntegerState948;
/* unbake published declaration: published_87d2cae53cf6f8328f40dd79 */
typedef struct IntegerState948 IntegerState948;

/* unbake published declaration: published_8847c14b9e1397eebf2f5f95 */
extern float D_800C2BF0_de;

struct ObjectLinks16E4;
/* unbake published declaration: published_8a24b35ae7834642bfafc5ed */
typedef struct ObjectLinks16E4 ObjectLinks16E4;

struct ObjectLinks148;
/* unbake published declaration: published_8ad905833ed18fd9edceb832 */
typedef struct ObjectLinks148 ObjectLinks148;

struct func_80229BE0_S1;
/* unbake published declaration: published_8daeda882fd4acef940235b3 */
struct func_80229BE0_S1 {
    char pad0[0xE4];
    u16 unkE4;
    char padE4[0x5D8 - 0xE4 - sizeof(u16)];
    char * unk5D8;
};

struct State;
/* unbake published declaration: published_931faa407e8eeb52c854a143 */
typedef struct State State;

struct ObjectLinks16E4;
/* unbake published declaration: published_98ec1c1a913198bd75a85e64 */
struct ObjectLinks16E4 {
    char pad0[0x5D8];
    char * unk_5D8;
    char pad5D8[0x5DC - 0x5D8 - sizeof(char*)];
    s32 unk_5DC;
    char pad5DC[0x11FC - 0x5DC - sizeof(s32)];
    f32 unk_11FC;
    char pad11FC[0x120C - 0x11FC - sizeof(f32)];
    s32 unk_120C;
    char pad120C[0x1210 - 0x120C - sizeof(s32)];
    s32 unk_1210;
    char pad1210[0x16E0 - 0x1210 - sizeof(s32)];
    char * unk_16E0;
};

struct HudGlobals;
/* unbake published declaration: published_9c22796c17773ca0015031cd */
typedef struct HudGlobals HudGlobals;

struct View_func_80226340_de;
/* unbake published declaration: published_9ed4259ddaac2289c7202858 */
struct View_func_80226340_de {
    char pad0[0x128];
    Triple position;
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
struct SharedPlayer_func_80226340_de;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View_func_80226340_de;
/* unbake published declaration: published_9e343d69a6144ed10b7a3af1 */
struct SharedPlayer_func_80226340_de {
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
            struct SharedPlayer_func_80226340_de * unk1D8;
        } view1D8_22;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80226340_de * self;
        } view1D8_23;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80226340_de * f1D8;
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
            struct View_func_80226340_de * view;
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
            struct SharedPlayer_func_80226340_de * unk16E0;
        } view16E0_0;
        struct {
            struct SharedPlayer_func_80226340_de * next;
        } view16E0_1;
        struct {
            struct SharedPlayer_func_80226340_de * next;
        } view16E0_2;
    } views16E0;
};

struct Game;
/* unbake published declaration: published_a08888e757fa2bf9817e227b */
typedef struct Game Game;

struct Menu_func_80226A34_de;
/* unbake published declaration: published_a2379109e7829aa9338ca048 */
struct Menu_func_80226A34_de {
    char pad0[0xCC9];
    u8 allowed;
    char padCCA[0x1278 - 0xCCA];
    s32 open;
    char pad127C[0x1284 - 0x127C];
    MenuRules rules;
};

struct Damage_func_80229FA0_de;
struct Obj_func_80229FA0_de;
/* unbake published declaration: published_a35d4eb60b3ff83e7eda3ae9 */
struct Damage_func_80229FA0_de {
    struct Obj_func_80229FA0_de *unk0;
    int unk4;
};

struct World_func_80226A34_de;
/* unbake published declaration: published_a892350965cfd92b5a7e064e */
typedef struct World_func_80226A34_de World_func_80226A34_de;

struct State;
/* unbake published declaration: published_aac796a4afae0be77d69697a */
struct State {
    char pad[0x58];
    int unk58;
    char pad5c[0x4c];
    int humanWon;
};

struct Stats;
/* unbake published declaration: published_ab3cc2ea8b80955f42b81243 */
struct Stats {
    char pad0[0x3C];
    s16 kills[8];
};

struct HudState;
/* unbake published declaration: published_aeddb792a4f3e2b7eb3ae3e3 */
typedef struct HudState HudState;

struct HudState;
/* unbake published declaration: published_aee4a502516b23d7704408f8 */
struct HudState {
    u8 reserved[0x5D4];
    f32 timer;
};

struct Player16C0;
/* unbake published declaration: published_af404818f647c7c7379e8cfd */
typedef struct Player16C0 Player16C0;

/* unbake published declaration: published_b67da224ec60a56f50e6a95f */
extern float D_800C2BF4_de;

struct Player16C0;
/* unbake published declaration: published_b69dc22e3196ffbce0f5e9da */
struct Player16C0 {
    char pad0[0x5E4];
    s32 alive;
    char pad5E8[0x1640 - 0x5E8];
    UnitMtx markers[2];
};

struct ObjectLinks16E4_2;
/* unbake published declaration: published_b740eacd3c6014bfbac3939d */
typedef struct ObjectLinks16E4_2 ObjectLinks16E4_2;

struct Body;
struct Controller;
struct Controls;
struct Ctrl;
struct Desc;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct Profile_func_80229554_de;
struct Record;
struct Rider;
struct Settings;
struct SharedPlayer_func_80229554_de;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;
/* unbake published declaration: published_b8ab50fda48c7f521156087d */
struct SharedPlayer_func_80229554_de {
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
            struct Desc * character;
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
            struct SharedPlayer_func_80229554_de * unk1D8;
        } view1D8_22;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80229554_de * self;
        } view1D8_23;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80229554_de * f1D8;
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
            struct Profile_func_80229554_de * profile;
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
            struct SharedPlayer_func_80229554_de * unk16E0;
        } view16E0_0;
        struct {
            struct SharedPlayer_func_80229554_de * next;
        } view16E0_1;
        struct {
            struct SharedPlayer_func_80229554_de * next;
        } view16E0_2;
    } views16E0;
};

struct ObjectLinks148;
/* unbake published declaration: published_b9d44f134cd755b8ed83ce9a */
struct ObjectLinks148 {
    char pad0[0x144];
    void * unk_144;
};

struct Inventory;
/* unbake published declaration: published_bd502b0a330fab7d18dc42a2 */
struct Inventory {
    char pad[0x5F4];
    s16 items[3];
};

struct Inventory;
/* unbake published declaration: published_dc6f12ff97d371e51f06f80b */
typedef struct Inventory Inventory;

/* unbake published declaration: published_bccd69830d83e513ee78739b */
extern void func_80229468_de(Inventory *arg0, Receiver *arg1);

struct ObjectLinks94C;
/* unbake published declaration: published_bce56b24a50ec832d1e9da01 */
struct ObjectLinks94C {
    unsigned char padding_0[2376];
    void *unk_948;
};

struct SharedPlayer_func_80229554_de;
/* unbake published declaration: published_c17b142d78b76ff10f04594b */
typedef struct SharedPlayer_func_80229554_de SharedPlayer_func_80229554_de;

struct Damage_func_80229FA0_de;
/* unbake published declaration: published_c2dd2e73c121e88abdf0a00d */
typedef struct Damage_func_80229FA0_de Damage_func_80229FA0_de;

struct ViewState;
/* unbake published declaration: published_c9a48c50d826fc803248b18c */
typedef struct ViewState ViewState;

struct Root;
/* unbake published declaration: published_ca0bd3cd07981931783e44e8 */
typedef struct Root Root;

struct Menu_func_80226A34_de;
/* unbake published declaration: published_cd5659611d6b92b664f0a95f */
typedef struct Menu_func_80226A34_de Menu_func_80226A34_de;

struct Rules_func_80228FB8_de;
/* unbake published declaration: published_cdd8a5f6008d3b77d4198c4a */
typedef struct Rules_func_80228FB8_de Rules_func_80228FB8_de;

struct Obj_func_80229FA0_de;
/* unbake published declaration: published_ce5a03701b44c30f4a150c26 */
typedef struct Obj_func_80229FA0_de Obj_func_80229FA0_de;

/* unbake published declaration: published_d09b30ba807ed4d5bb14dcf1 */
extern s32 func_80229A80_de(void *game);

/* unbake published declaration: published_d2750d0b39aa45fc0f69213a */
extern float D_800C2BE0_de;

/* unbake published declaration: published_d431e1c48169632883cf57be */
extern float D_800C2BDC_de;

union func_802285C4_S2_U11BC;
/* unbake published declaration: published_eaa836bf712682c94c804856 */
typedef union func_802285C4_S2_U11BC func_802285C4_S2_U11BC;

union func_802285C4_S2_U11BC;
/* unbake published declaration: published_ef761cc6613f7fc234de88de */
union func_802285C4_S2_U11BC {
    void * v0;
    s32 v1;
};

struct Shape_typemap_165;
struct func_802285C4_S2;
/* unbake published declaration: published_d768730097658f17ab492945 */
struct func_802285C4_S2 {
    char pad0[0x8];
    Triple unk8;
    char pad8[0x14 - 0x8 - sizeof(Triple)];
    s32 unk14;
    char pad14[0x5C - 0x14 - sizeof(s32)];
    struct Shape_typemap_165 unk5C;
    char pad5C[0x6C - 0x5C - sizeof(struct Shape_typemap_165)];
    f32 unk6C;
    char pad6C[0x10E - 0x6C - sizeof(f32)];
    u8 unk10E;
    char pad10E[0x2E8 - 0x10E - sizeof(u8)];
    Block unk2E8;
    char pad2E8[0x5DC - 0x2E8 - sizeof(Block)];
    void * unk5DC;
    char pad5DC[0x5EA - 0x5DC - sizeof(void*)];
    s16 unk5EA;
    char pad5EA[0x86C - 0x5EA - sizeof(s16)];
    s32 unk86C;
    char pad86C[0x11BC - 0x86C - sizeof(s32)];
    func_802285C4_S2_U11BC unk11BC;
    char pad11BC[0x11C0 - 0x11BC - sizeof(func_802285C4_S2_U11BC)];
    func_802285C4_S2_U11BC unk11C0;
    char pad11C0[0x11D8 - 0x11C0 - sizeof(func_802285C4_S2_U11BC)];
    f32 unk11D8;
    char pad11D8[0x16E0 - 0x11D8 - sizeof(f32)];
    char * unk16E0;
};

struct World_func_802283B8_de;
/* unbake published declaration: published_d85cfb8b1bb692fb6f6116bc */
typedef struct World_func_802283B8_de World_func_802283B8_de;

struct Player_func_80228FB8_de;
/* unbake published declaration: published_d8b31884d29a07beaa0a4368 */
struct Player_func_80228FB8_de {
    char pad0[0x5D8];
    func_8020EA10_S3 *controls;
    char pad5DC[0x1230 - 0x5DC];
    f32 tintTime;
    char pad1234[0x1238 - 0x1234];
    s32 tintMode;
};

struct Obj_func_802281F0_de;
/* unbake published declaration: published_d95649a524a1c838aadaa503 */
typedef struct Obj_func_802281F0_de Obj_func_802281F0_de;

struct IntegerState1230;
/* unbake published declaration: published_df96b88e73eb8fedd53a640a */
struct IntegerState1230 {
    char pad0[0x100];
    s32 unk_100;
    char pad100[0x122C - 0x100 - sizeof(s32)];
    s32 unk_122C;
};

struct Rules_func_80228FB8_de;
/* unbake published declaration: published_e6b4e1e4b5d5635b99c12ae3 */
struct Rules_func_80228FB8_de {
    char pad0[0x54];
    s32 teams;
    char pad58[0x73 - 0x58];
    u8 colour;
};

/* unbake published declaration: published_e6ccdfb937cae538fe19731b */
extern float D_800C2BEC_de;

/* unbake published declaration: published_e81e78dc6f71e35c8d6f0ca8 */
extern float D_800C9FEC;

struct ObjectState5E8;
/* unbake published declaration: published_ed35f289bc1d4c98d57667e1 */
typedef struct ObjectState5E8 ObjectState5E8;

struct SharedPlayer_func_80226340_de;
/* unbake published declaration: published_eddbe3857aa2eec7df0f04e3 */
typedef struct SharedPlayer_func_80226340_de SharedPlayer_func_80226340_de;

struct Actor_func_802285E8_de;
/* unbake published declaration: published_efdc054c2a4d1e34ed596896 */
struct Actor_func_802285E8_de {
    u8 pad000[0x3E8];
    s32 flags;
    u8 pad3EC[0x480];
    s32 value86C;
};

struct ActorNode;
struct Round;
/* unbake published declaration: published_f38e6aa8378e39886d03150b */
struct Round {
    char pad0[0x20];
    struct ActorNode *players;
};

struct Actor_func_80228FB8_de;
struct ModelDef;
struct Player_func_80228FB8_de;
/* unbake published declaration: published_f76c818911f67afcd8e1ae0f */
struct Actor_func_80228FB8_de {
    char pad0;
    u8 colour;
    char pad2[0x18 - 0x2];
    struct ModelDef *def;
    char pad1C[0xB4 - 0x1C];
    s32 animation;
    char padB8[0x140 - 0xB8];
    char views[0x18];
    char pad158[0x1D8 - 0x158];
    struct Player_func_80228FB8_de *player;
};

struct func_80229BE0_S1;
/* unbake published declaration: published_face534eec2e0698231c8c1f */
typedef struct func_80229BE0_S1 func_80229BE0_S1;

struct SharedPlayer;
extern void func_80229814_de(struct SharedPlayer *player, f32 amount);
#endif
