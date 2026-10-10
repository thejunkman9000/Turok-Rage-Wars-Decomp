#ifndef UNBAKE_SPAN_1000_CODE_802106E0_H
#define UNBAKE_SPAN_1000_CODE_802106E0_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
/* unbake published declaration: published_09ccbe7e7b0455e623071e2c */
extern float D_800C1FD8_de;

struct func_80211020_S1;
/* unbake published declaration: published_0ae72388ece026107c139691 */
struct func_80211020_S1 {
    char pad0[0x21C];
    s32 unk21C;
    char pad21C[0x220 - 0x21C - sizeof(s32)];
    s32 unk220;
};

/* unbake published declaration: published_0aeb927bcce242b0011a6d5e */
extern void func_80212948_de(void *arg0);

struct Actor_func_802120A8_eu;
struct Brain_func_802120A8_eu;
/* unbake published declaration: published_0f682c8b603403f42bf3669b */
struct Actor_func_802120A8_eu {
    char pad0[8];
    Vec3 pos;
    char pad14[0x24];
    s32 flags;
    char pad3C[0x30];
    f32 yaw;
    char pad70[0x168];
    struct Actor_func_802120A8_eu *self;
    char pad1DC[0x3F8];
    s32 slot;
    char pad5D8[0xCC];
    f32 strafe;
    char pad6A8[0xDAC];
    struct Brain_func_802120A8_eu *brain;
};

/* unbake published declaration: published_bc9ad5eede98091e5d43534c */
struct Brain_func_802120A8_eu {
    struct Actor_func_802120A8_eu *player;
    s32 route;
    char pad8[8];
    s32 node;
    s32 w14;
    char pad18[0x4C];
    struct Actor_func_802120A8_eu *target;
    char pad68[0x188];
    f32 walk[8];
    char pad210[0x20];
    s32 combat;
    char pad234[0xA4];
    s32 timer;
    s32 pattern;
    char pad2E0[0x38];
    s32 frames;
    s32 visible;
};

struct func_8021290C_S3;
/* unbake published declaration: published_1025b208217bc78fadfd0a2a */
struct func_8021290C_S3 {
    char pad0[0xC];
    int unkC;
    char padC[0x220 - 0xC - sizeof(int)];
    int unk220;
    char pad220[0x2FC - 0x220 - sizeof(int)];
    int unk2FC;
};

/* unbake published declaration: published_159e3802e1d6f72a99aa46ec */
extern void func_80212470_eu(void *arg0);

struct ObjectState3C;
/* unbake published declaration: published_195346e209b7d48f00db840c */
struct ObjectState3C {
    char pad0[0x8];
    f32 unk_8;
    char pad8[0x38 - 0x8 - sizeof(f32)];
    u32 unk_38;
};

struct CloseAttackBrain;
/* unbake published declaration: published_1fa1724d1ea16b348fbfeccb */
typedef struct CloseAttackBrain CloseAttackBrain;

struct func_802123DC_S3;
/* unbake published declaration: published_2180df91b414ab8208908430 */
typedef struct func_802123DC_S3 func_802123DC_S3;

/* unbake published declaration: published_23ff6e897dba678f5b3d87e9 */
extern float D_800C1FE8_de;

struct CloseAttackActor;
/* unbake published declaration: published_8f6e770cb7f5d5db138f644a */
typedef struct CloseAttackActor CloseAttackActor;

struct CloseAttackActor;
struct CloseAttackBrain;
/* unbake published declaration: published_2f25158b01f5238eb4865bdf */
struct CloseAttackActor {
    char pad0[8];
    Vec3 pos;
    char pad14[0x24];
    s32 flags;
    char pad3C[0x30];
    f32 yaw;
    char pad70[0x168];
    struct CloseAttackActor *self;
    char pad1DC[0x3F8];
    s32 slot;
    char pad5D8[0xCC];
    f32 strafe;
    f32 forward;
    s32 w6AC;
    s32 buttons;
    char pad6B4[0xDA0];
    struct CloseAttackBrain *brain;
};

/* unbake published declaration: published_81b30dd874c306676f1c1f3a */
struct CloseAttackBrain {
    CloseAttackActor *player;
    s32 route;
    s32 w8;
    s32 destination;
    s32 node;
    s32 w14;
    char pad18[0x4C];
    CloseAttackActor *target;
    char pad68[0x188];
    f32 walk[8];
    char pad210[0x20];
    s32 combat;
    char pad234[0xA4];
    s32 timer;
    s32 pattern;
    s32 distance;
    char pad2E4[0x34];
    s32 frames;
    s32 visible;
    s32 fireTimer;
};

/* unbake published declaration: published_250e469dbc254612c9f396f2 */
extern void func_80211490_eu(CloseAttackActor *actor);

struct Brain_func_802120A8_eu;
/* unbake published declaration: published_30e7ad5ba2df9b1aae9ac7e2 */
typedef struct Brain_func_802120A8_eu Brain_func_802120A8_eu;

struct IntegerState1C;
/* unbake published declaration: published_385dce91567ef3954cd3d1fb */
struct IntegerState1C {
    char pad0[0x4];
    s32 unk_4;
    char pad4[0x18 - 0x4 - sizeof(s32)];
    s32 unk_18;
};

/* unbake published declaration: published_3d45cc2791d6d77a621f8a84 */
extern void func_802127F4_de(void *arg0);

struct IntegerState1C;
/* unbake published declaration: published_42801da8d13f4fb6161cc54f */
typedef struct IntegerState1C IntegerState1C;

struct Player_func_802110C4_de;
/* unbake published declaration: published_472ef43ed77eb3951417d719 */
struct Player_func_802110C4_de {
    s32 active;
    char pad4[0x1CC - 4];
    s32 timer;
    f32 first[8];
    f32 second[8];
    f32 level;
    char pad214[0x288 - 0x214];
    s32 ready;
};

struct Hit_func_802106E0_de;
/* unbake published declaration: published_49e8db62c6a0bf9de997a940 */
struct Hit_func_802106E0_de {
    char pad0[0xE4];
    Vec3 pos;
};

/* unbake published declaration: published_4ad9d8561ff3e339a4ff928e */
extern int func_80211000_de(int arg0);

struct Player_func_80210E88_de;
/* unbake published declaration: published_6b36887914e324f3c2d79a35 */
struct Player_func_80210E88_de {
    void *clip;
    char pad4[0x1C8];
    int frame;
};

struct Player_func_80210E88_de;
/* unbake published declaration: published_744a4085bafe22b617dccbdc */
typedef struct Player_func_80210E88_de Player_func_80210E88_de;

/* unbake published declaration: published_4c8a139a4066bc29abdc9fbb */
extern int func_80210E88_de(Player_func_80210E88_de *p);

/* unbake published declaration: published_4dfbfeeeaff69d924343aeb0 */
extern void func_80212C04_de(void *arg0);

/* unbake published declaration: published_646a013d44cfd314e96cc339 */
extern float D_800C1FF0_de;

struct func_80212828_S3;
/* unbake published declaration: published_649b46c342c6a64eeb5d49f8 */
typedef struct func_80212828_S3 func_80212828_S3;

/* unbake published declaration: published_65f95af4be8c80dd1b413f94 */
extern float D_800C1FDC_de;

/* unbake published declaration: published_6e73b59a5041b39535517bc6 */
extern float D_800C1FE4_de;

struct func_80212450_S3;
/* unbake published declaration: published_78ef0d798641ab8297dd905d */
struct func_80212450_S3 {
    char pad0[0x220];
    s32 unk220;
    char pad220[0x2D8 - 0x220 - sizeof(s32)];
    s32 unk2D8;
    char pad2D8[0x2DC - 0x2D8 - sizeof(s32)];
    s32 unk2DC;
    char pad2DC[0x2E0 - 0x2DC - sizeof(s32)];
    s32 unk2E0;
    char pad2E0[0x318 - 0x2E0 - sizeof(s32)];
    s32 unk318;
    char pad318[0x31C - 0x318 - sizeof(s32)];
    s32 unk31C;
    char pad31C[0x320 - 0x31C - sizeof(s32)];
    s32 unk320;
};

/* unbake published declaration: published_7eeb99de68b99b9804838cf0 */
extern void func_80212A7C_de(void *arg0);

/* unbake published declaration: published_80b0b6f3ae06840471f399b5 */
extern int func_80210FE8_de(int arg0);

struct func_80211020_S1;
/* unbake published declaration: published_844da0008e7afac3f94e3aff */
typedef struct func_80211020_S1 func_80211020_S1;

struct func_80212948_S3;
/* unbake published declaration: published_86847bc40290825e7852b97c */
typedef struct func_80212948_S3 func_80212948_S3;

struct func_80212828_S3;
/* unbake published declaration: published_9a540272d1021ddac5ba3cbe */
struct func_80212828_S3 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x64 - 0x10 - sizeof(s32)];
    void * unk64;
    char pad64[0x230 - 0x64 - sizeof(void*)];
    s32 unk230;
};

struct ObjectState2C;
/* unbake published declaration: published_9afc91de00fbe29518c81cf9 */
typedef struct ObjectState2C ObjectState2C;

struct func_80212948_S3;
/* unbake published declaration: published_9bbdab76e3791404096c226e */
struct func_80212948_S3 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x64 - 0xC - sizeof(s32)];
    void * unk64;
    char pad64[0x230 - 0x64 - sizeof(void*)];
    s32 unk230;
};

struct Hit_func_802106E0_de;
/* unbake published declaration: published_9cb6af2ef7eb344bc54b7004 */
typedef struct Hit_func_802106E0_de Hit_func_802106E0_de;

struct ObjectState3C;
/* unbake published declaration: published_9dc8437e0c6e43cc6809e55d */
typedef struct ObjectState3C ObjectState3C;

/* unbake published declaration: published_9f248dd56fbb64e4d2d099ec */
extern void func_80211A9C_eu(CloseAttackActor *actor);

struct Vehicle;
/* unbake published declaration: published_ad1a8d07002e1d493500edd6 */
typedef struct Vehicle Vehicle;

/* unbake published declaration: published_ad5ee721edb6f144fc56ced9 */
extern float D_800C1FEC_de;

/* unbake published declaration: published_b17a31c970125e1e3da18e80 */
extern void func_80212828_de(void *arg0);

struct Actor_func_802120A8_eu;
/* unbake published declaration: published_b36b3c73b50881fc86c0cbf6 */
typedef struct Actor_func_802120A8_eu Actor_func_802120A8_eu;

struct Wheels;
struct Wheels {
    char pad0[0x1D0];
    f32 reach[8];
    char pad1F0[0x20];
    f32 length;
};
struct Vehicle;
struct Wheels;
/* unbake published declaration: published_b7dad620d88dc60173bd791a */
struct Vehicle {
    char pad0[8];
    Vec3 pos;
    char pad14[0x1440];
    struct Wheels *wheels;
};

/* unbake published declaration: published_c32abb04f3cf54c80ad6f91b */
extern float D_800C1FE0_de;

/* unbake published declaration: published_c5b6c869b7d2487a4bcb9f35 */
extern void func_8021290C_de(void *arg0);

struct func_80212828_S5;
/* unbake published declaration: published_c750e1fe56f18da31410f8d8 */
struct func_80212828_S5 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x1454 - 0x8 - sizeof(f32)];
    void * unk1454;
};

/* unbake published declaration: published_c7cc28f614505989e742a130 */
extern void func_802123FC_eu(void *arg0);

struct func_8021290C_S3;
/* unbake published declaration: published_c843a58c21741d9082818327 */
typedef struct func_8021290C_S3 func_8021290C_S3;

/* unbake published declaration: published_cb2fbdb78ae815b775783c5e */
extern void func_80212A40_de(void *arg0);

struct ObjectState2C;
/* unbake published declaration: published_d07887f56b84c1b248d9b9a5 */
struct ObjectState2C {
    char pad0[0x4];
    s32 unk_4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unk_C;
    char padC[0x14 - 0xC - sizeof(s32)];
    char unk_14;
    char pad14[0x28 - 0x14 - sizeof(char)];
    s32 unk_28;
};

struct func_80212450_S3;
/* unbake published declaration: published_d699902d7490fbe9275edd98 */
typedef struct func_80212450_S3 func_80212450_S3;

/* unbake published declaration: published_e25fcc5f08d0c88c7e3de28a */
extern float D_800C70F4;

/* unbake published declaration: published_e53564183ff9c7bd7e5b4b10 */
extern float D_800C70F0;

struct func_80212828_S5;
/* unbake published declaration: published_f2894711801a466a86ad8cc3 */
typedef struct func_80212828_S5 func_80212828_S5;

/* unbake published declaration: published_f7452bafb12112d3e2b8b338 */
extern void func_80212BD0_de(void *arg0);

struct func_802123DC_S3;
/* unbake published declaration: published_f9fd587ddad5a37b1c3ef8ac */
struct func_802123DC_S3 {
    char pad0[0x220];
    s32 unk220;
    char pad220[0x2D8 - 0x220 - sizeof(s32)];
    s32 unk2D8;
    char pad2D8[0x2DC - 0x2D8 - sizeof(s32)];
    s32 unk2DC;
};

/* unbake published declaration: published_ff6b43f85bcf8ca8eae75a22 */
extern void func_802120A8_eu(Actor_func_802120A8_eu *actor);

extern int func_80212610_eu(void * arg0);

extern s32 func_802744D4_de(void);
typedef struct func_802125F0_S1 func_802125F0_S1;
typedef struct func_802125F0_S2 func_802125F0_S2;
typedef struct func_802125F0_S3 func_802125F0_S3;
struct func_802125F0_S1 {
    char pad0[0x1D8];
    void* unk1D8;
};
struct func_802125F0_S2 {
    char pad0[0x1454];
    void* unk1454;
};
struct func_802125F0_S3 {
    char pad0[0x220];
    s32 unk220;
    char pad220[0x2D8 - 0x220 - sizeof(s32)];
    s32 unk2D8;
    char pad2D8[0x2DC - 0x2D8 - sizeof(s32)];
    s32 unk2DC;
};

#endif
