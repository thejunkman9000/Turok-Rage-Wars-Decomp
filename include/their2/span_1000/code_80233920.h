#ifndef UNBAKE_SPAN_1000_CODE_80233920_H
#define UNBAKE_SPAN_1000_CODE_80233920_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
struct Triple;
struct func_802390C0_S1;
/* unbake published declaration: published_0d1f68bfb9e687a29b5f4815 */
struct func_802390C0_S1 {
    char pad0[0x260];
    struct Triple unk260;
};

struct Entity_func_80233C88_de;
/* unbake published declaration: published_0eb5652f523dbefb30d5ca29 */
typedef struct Entity_func_80233C88_de Entity_func_80233C88_de;

struct Racer;
/* unbake published declaration: published_155a78e586cc4ec08c11b00c */
typedef struct Racer Racer;

struct Overlay;
/* unbake published declaration: published_158bac9f1433e83a4aec1b34 */
typedef struct Overlay Overlay;

struct AxisWave;
/* unbake published declaration: published_1833c068e913cc1226f91bb1 */
typedef struct AxisWave AxisWave;

struct Entity_func_80233C88_de;
/* unbake published declaration: published_19267424c2c0e45e980251e7 */
struct Entity_func_80233C88_de {
    char pad0[0x29C];
    f32 width;
    f32 height;
    f32 x;
    f32 y;
    char pad2AC[0x520 - 0x2AC];
    u8 color[4];
};

struct func_8023919C_S1;
/* unbake published declaration: published_1c6a2fb25abc8ee79769029d */
typedef struct func_8023919C_S1 func_8023919C_S1;

/* unbake published declaration: published_1d90da3f512df1029cde0399 */
extern float D_800C3090_de;

struct func_802393C8_S1;
/* unbake published declaration: published_2a0d3c6c38211f158eb75125 */
typedef struct func_802393C8_S1 func_802393C8_S1;

struct func_80234DD0_S1;
/* unbake published declaration: published_2edd9b83bac29a35f2fdc1a6 */
typedef struct func_80234DD0_S1 func_80234DD0_S1;

struct func_80239314_S1;
/* unbake published declaration: published_32e1427bbc9076e3473d0db0 */
typedef struct func_80239314_S1 func_80239314_S1;

struct func_802390E4_S1;
/* unbake published declaration: published_3316d315c7ba36a6e2377774 */
struct func_802390E4_S1 {
    char pad0[0x14];
    s16 unk14;
    char pad14[0x18 - 0x14 - sizeof(s16)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s16 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s16)];
    s32 unk20;
};

/* unbake published declaration: published_340cb388fbb0e65cc7620eb5 */
extern void func_80239184_de(void);

struct func_802390C0_S1;
/* unbake published declaration: published_34886db184385b631602eb0b */
typedef struct func_802390C0_S1 func_802390C0_S1;

/* unbake published declaration: published_3c8595152e1fddffce3d664b */
extern float D_800C3530_de;

struct func_8023912C_S2;
/* unbake published declaration: published_3e2af159f5b0b9df1367460e */
typedef struct func_8023912C_S2 func_8023912C_S2;

struct Overlay;
/* unbake published declaration: published_7b6e0bef6d65a3af442a0849 */
struct Overlay {
    char pad0[0x538];
    f32 timer;
    char pad53C[8];
    u32 state;
    char pad548[2];
    u8 alphaMax;
    u8 fadeIn;
    u8 hold;
    u8 fadeOut;
    char pad54E[3];
    u8 alpha;
};

/* unbake published declaration: published_4879d9aeee3de2db64b11775 */
extern void func_80233B14_de(Overlay *overlay);

struct func_80239314_S1;
/* unbake published declaration: published_4d8af50fb6a149802005fe44 */
struct func_80239314_S1 {
    char pad0[0xA8];
    Vec3 unkA8;
    char padA8[0xB4 - 0xA8 - sizeof(Vec3)];
    f32 unkB4;
    char padB4[0xB8 - 0xB4 - sizeof(f32)];
    s32 unkB8;
    char padB8[0xBC - 0xB8 - sizeof(s32)];
    f32 unkBC;
    char padBC[0xCC - 0xBC - sizeof(f32)];
    s32 unkCC;
    char padCC[0xD0 - 0xCC - sizeof(s32)];
    f32 unkD0;
    char padD0[0xE0 - 0xD0 - sizeof(f32)];
    s32 unkE0;
    char padE0[0xE4 - 0xE0 - sizeof(s32)];
    f32 unkE4;
};

struct Effect33920;
/* unbake published declaration: published_73240ec90645f1bbc1437010 */
typedef struct Effect33920 Effect33920;

struct AxisWave;
/* unbake published declaration: published_e41f2510e7a2a5e4c9dc5e8a */
struct AxisWave {
    s32 kind;
    s32 unk04;
    s32 unk08;
    f32 scale;
    f32 rate;
};

struct Effect33920;
/* unbake published declaration: published_b4deea11405b5220382cd6b8 */
struct Effect33920 {
    s32 unk00;
    s32 unk04;
    Vec3 origin;
    f32 radius;
    AxisWave x;
    AxisWave y;
    AxisWave z;
};

/* unbake published declaration: published_50d1fb38d00a3e50301966dd */
extern void func_80233930_de(Effect33920 *arg0, u32 x, u32 y, u32 z, Vec3 *out);

struct ThreeChannels;
/* unbake published declaration: published_55e0c62a75e42c435a71eb95 */
typedef struct ThreeChannels ThreeChannels;

/* unbake published declaration: published_58db9c4e11bf7a377f56672e */
extern float D_800C352C_de;

struct State44;
/* unbake published declaration: published_5a870e98e060d745541e394e */
typedef struct State44 State44;

struct Race;
/* unbake published declaration: published_60e731ddc9efff8343aa8773 */
typedef struct Race Race;

struct func_80238F14_S1;
/* unbake published declaration: published_6291cad67595bc6d383e0c6c */
struct func_80238F14_S1 {
    char pad0[0x24];
    s32 unk24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
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
    char pad3C[0x40 - 0x3C - sizeof(f32)];
    f32 unk40;
    char pad40[0x44 - 0x40 - sizeof(f32)];
    f32 unk44;
    char pad44[0x48 - 0x44 - sizeof(f32)];
    Shared_Quad unk48;
    char pad48[0x58 - 0x48 - sizeof(Shared_Quad)];
    s32 unk58;
    char pad58[0x5C - 0x58 - sizeof(s32)];
    f32 unk5C;
    char pad5C[0x60 - 0x5C - sizeof(f32)];
    f32 unk60;
    char pad60[0x64 - 0x60 - sizeof(f32)];
    s32 unk64;
};

struct UnitVp;
/* unbake published declaration: published_6511a5ab03c64038afc9aaf6 */
struct UnitVp {
    s16 vscale[4];
    s16 vtrans[4];
};

struct func_802392DC_S1;
/* unbake published declaration: published_66124693d684cb1a7ec5f525 */
typedef struct func_802392DC_S1 func_802392DC_S1;

struct func_802390E4_S1;
/* unbake published declaration: published_66bd5f3f15ac100d86c5fcfc */
typedef struct func_802390E4_S1 func_802390E4_S1;

struct World_func_80236F1C_de;
/* unbake published declaration: published_694230af3b98da209bb3d438 */
typedef struct World_func_80236F1C_de World_func_80236F1C_de;

struct func_80234DD0_S2;
/* unbake published declaration: published_6c431b17f9e0953162ac2ed8 */
struct func_80234DD0_S2 {
    char pad0[0x264];
    f32 unk264;
    char pad264[0x268 - 0x264 - sizeof(f32)];
    f32 unk268;
};

struct func_80239184_S1;
/* unbake published declaration: published_6edc769ffa0b454787567f0c */
typedef struct func_80239184_S1 func_80239184_S1;

struct UnitVp;
/* unbake published declaration: published_852504211ce33ec8522578f3 */
typedef struct UnitVp UnitVp;

struct Racer;
/* unbake published declaration: published_701589cbf2eee5acea255c7b */
struct Racer {
    char pad0[4];
    struct Racer *next;
    char pad8[0x118];
    s32 effect;
    u16 pad124;
    u16 effectArg;
    char pad128[0x188];
    UnitVp viewports[2];
    char pad2D0[0x250];
    u8 hit;
    u8 boost;
    u8 spin;
    char pad523[0x31];
    char sound[0x40];
};

struct World_func_80236F1C_de;
/* unbake published declaration: published_7a4a77041fe7741ba52e7a1f */
struct World_func_80236F1C_de {
    char pad0[0x12A5];
    u8 replay;
};

struct Race;
struct Racer;
/* unbake published declaration: published_87e633f7a0289d762a8d86f0 */
struct Race {
    s32 music;
    char pad4[0x1C];
    struct Racer *racers;
    char pad24[0xC];
    s32 mode;
    char pad34[0xC];
    Racer self;
};

/* unbake published declaration: published_89f5cee85fbb6b21de9a8306 */
extern float D_800C3098_de;

/* unbake published declaration: published_952831d3803075d407c78a37 */
extern float D_800C8610;

struct func_8023912C_S2;
/* unbake published declaration: published_9683d9cee3c5dc9a53874f92 */
struct func_8023912C_S2 {
    char pad0[0x88];
    f32 unk88;
    char pad88[0x8C - 0x88 - sizeof(f32)];
    f32 unk8C;
    char pad8C[0x90 - 0x8C - sizeof(f32)];
    s32 unk90;
    char pad90[0x94 - 0x90 - sizeof(s32)];
    s32 unk94;
    char pad94[0x98 - 0x94 - sizeof(s32)];
    f32 unk98;
    char pad98[0x9C - 0x98 - sizeof(f32)];
    f32 unk9C;
};

/* unbake published declaration: published_97c62163e0590ffd31023673 */
extern void func_8023918C_de(void);

struct func_80238F14_S1;
/* unbake published declaration: published_9f246fa3e83af5c1bc7b1f24 */
typedef struct func_80238F14_S1 func_80238F14_S1;

struct State44;
/* unbake published declaration: published_a47b4e9f88a94ab40cb3de44 */
struct State44 {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    union {s32 i; f32 f;} unk_20;
    Vec3 v;
    f32 unk_30;
    s32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    s32 unk_40;
};

struct func_80239184_S1;
/* unbake published declaration: published_a73c434f0bc215a3075ec33e */
struct func_80239184_S1 {
    char pad0[0x548];
    signed char unk548;
    char pad548[0x549 - 0x548 - sizeof(signed char)];
    signed char unk549;
};

struct func_80234DD0_S2;
/* unbake published declaration: published_ab4fa17e9599dc0495e60ba4 */
typedef struct func_80234DD0_S2 func_80234DD0_S2;

/* unbake published declaration: published_af087754ee82491905e5f45d */
extern void func_802391F8_de(void *arg0, s8 *arg1, s8 *arg2, s8 *arg3);

/* unbake published declaration: published_b2c5dc6201d715ec41f7890c */
extern float D_800C3094_de;

/* unbake published declaration: published_b763990fea80ea7f5671daa2 */
extern float D_800C309C_de;

struct func_80234DD0_S1;
/* unbake published declaration: published_bf634e67cf9c98b444c37794 */
struct func_80234DD0_S1 {
    char pad0[0x70];
    f32 unk70;
    char pad70[0x74 - 0x70 - sizeof(f32)];
    f32 unk74;
    char pad74[0x78 - 0x74 - sizeof(f32)];
    f32 unk78;
    char pad78[0x7C - 0x78 - sizeof(f32)];
    s32 unk7C;
    char pad7C[0x260 - 0x7C - sizeof(s32)];
    func_80234DD0_S1_U260 unk260;
    char pad260[0x368 - 0x260 - sizeof(func_80234DD0_S1_U260)];
    f32 unk368;
    char pad368[0x36C - 0x368 - sizeof(f32)];
    f32 unk36C;
    char pad36C[0x370 - 0x36C - sizeof(f32)];
    f32 unk370;
    char pad370[0x374 - 0x370 - sizeof(f32)];
    f32 unk374;
    char pad374[0x378 - 0x374 - sizeof(f32)];
    f32 unk378;
    char pad378[0x37C - 0x378 - sizeof(f32)];
    f32 unk37C;
    char pad37C[0x528 - 0x37C - sizeof(f32)];
    f32 unk528;
    char pad528[0x530 - 0x528 - sizeof(f32)];
    f32 unk530;
};

struct ThreeChannels;
/* unbake published declaration: published_c03d1495f74d9e01f1a06b21 */
struct ThreeChannels {
    char pad0[0x520];
    u8 first;
    u8 second;
    u8 third;
};

/* unbake published declaration: published_c5b952c979189d9e6e28dd2d */
extern void func_8023913C_de(void *arg0);

/* unbake published declaration: published_c6239bc49dc9fd7644942646 */
extern void func_8023660C_de(char *camera, f32 a, f32 b, f32 c, f32 d);

struct func_8023919C_S1;
/* unbake published declaration: published_d5131d0d7b01d5fe4ee19c25 */
struct func_8023919C_S1 {
    char pad0[0x538];
    s32 unk538;
    char pad538[0x544 - 0x538 - sizeof(s32)];
    s32 unk544;
    char pad544[0x54A - 0x544 - sizeof(s32)];
    s8 unk54A;
    char pad54A[0x54B - 0x54A - sizeof(s8)];
    s8 unk54B;
    char pad54B[0x54C - 0x54B - sizeof(s8)];
    s8 unk54C;
    char pad54C[0x54D - 0x54C - sizeof(s8)];
    s8 unk54D;
    char pad54D[0x54E - 0x54D - sizeof(s8)];
    s8 unk54E;
    char pad54E[0x54F - 0x54E - sizeof(s8)];
    s8 unk54F;
    char pad54F[0x550 - 0x54F - sizeof(s8)];
    s8 unk550;
    char pad550[0x551 - 0x550 - sizeof(s8)];
    s8 unk551;
};

struct func_802392DC_S1;
/* unbake published declaration: published_e057731f420e8d31bd52066a */
struct func_802392DC_S1 {
    char pad0[0x5DC];
    int unk5DC;
    char pad5DC[0x16E0 - 0x5DC - sizeof(int)];
    void * unk16E0;
};

/* unbake published declaration: published_e742300887abac419d5144dc */
extern float D_800C3528_de;

struct func_802393C8_S1;
/* unbake published declaration: published_f43265a662a28054422c2b1c */
struct func_802393C8_S1 {
    char pad0[0xFC];
    int unkFC;
    char padFC[0x100 - 0xFC - sizeof(int)];
    int unk100;
    char pad100[0x104 - 0x100 - sizeof(int)];
    int unk104;
    char pad104[0x108 - 0x104 - sizeof(int)];
    int unk108;
    char pad108[0x10C - 0x108 - sizeof(int)];
    int unk10C;
    char pad10C[0x110 - 0x10C - sizeof(int)];
    float unk110;
    char pad110[0x114 - 0x110 - sizeof(float)];
    float unk114;
    char pad114[0x118 - 0x114 - sizeof(float)];
    int unk118;
};

/* unbake published declaration: published_f6c2e3322959b0434214179c */
extern float D_800C3524_de;

extern void func_802391AC_de(void *view, s32 red, s32 green, s32 blue, s32 mode, s32 alpha, s32 duration, s32 delay);

#endif
