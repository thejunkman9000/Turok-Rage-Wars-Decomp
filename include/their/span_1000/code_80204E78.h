#ifndef UNBAKE_SPAN_1000_CODE_80204E78_H
#define UNBAKE_SPAN_1000_CODE_80204E78_H
#include "../types.h"
struct func_8020612C_S3;
/* unbake published declaration: published_04eb475a6a22b3d188fcac15 */
struct func_8020612C_S3 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0xA - 0x4 - sizeof(s32)];
    s16 unkA;
    char padA[0x14 - 0xA - sizeof(s16)];
    s16 unk14;
    char pad14[0x16 - 0x14 - sizeof(s16)];
    s16 unk16;
};

/* unbake published declaration: published_0acdd403e228013932c7439e */
extern unsigned int func_80205700_de(void *object);

/* unbake published declaration: published_0c570371f6ceec7885464926 */
extern void func_80206080_de(void *arg0, void *arg1);

struct func_80206080_S2;
/* unbake published declaration: published_1337c8148100682ea52d1b4c */
struct func_80206080_S2 {
    char pad0[0xC];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    char unk14;
};

struct ActionInfo;
/* unbake published declaration: published_14bb7fa236d33c61962dc47b */
struct ActionInfo {
    s32 flags;
    char pad4[4];
    s16 duration;
};

struct Actor_func_80204FC4_de;
/* unbake published declaration: published_16509b23738f5b60e2569fab */
typedef struct Actor_func_80204FC4_de Actor_func_80204FC4_de;

struct Damage;
/* unbake published declaration: published_16c10fc9eb1d0d409d752730 */
typedef struct Damage Damage;

struct Cell;
/* unbake published declaration: published_17e33abce11c436edd4221e9 */
typedef struct Cell Cell;

struct func_8020520C_S1;
/* unbake published declaration: published_1cbbb8c545d7fd3aa6af4e24 */
typedef struct func_8020520C_S1 func_8020520C_S1;

struct func_80206080_S2;
/* unbake published declaration: published_21c90bfa5be2a407ff5b6351 */
typedef struct func_80206080_S2 func_80206080_S2;

struct Damage;
/* unbake published declaration: published_243368d30632f1256ebbc771 */
struct Damage {
    s32 flags;
    u8 pad4[0x44];
    u8 model[4];
    u8 time[4];
    u8 threshold[4];
};

struct Health;
/* unbake published declaration: published_30441019872b83bd33ceb0db */
struct Health {
    u8 pad0[4];
    s32 health;
    s32 maxHealth;
    u8 padC[0x118];
    s32 model;
    s32 time;
};

/* unbake published declaration: published_3a28a3bee304bdfa635a5dcf */
extern void func_802056D0_de(void *arg0);

/* unbake published declaration: published_3a526745a51fc15b65af6960 */
extern void func_80204F78_de(void *unused, char *object, float value);

struct CallbackHolder;
/* unbake published declaration: published_40e0226c5c368faa23951b00 */
typedef struct CallbackHolder CallbackHolder;

/* unbake published declaration: published_448746a674c253d6e9934e9e */
extern int func_802052F8_de(void *arg0);

struct Access_s32_40;
/* unbake published declaration: published_48338345ece60110ea88259a */
typedef struct Access_s32_40 Access_s32_40;

struct Hit;
/* unbake published declaration: published_49e7e8686a8ea28fe18ba75d */
struct Hit {
    u8 pad0[4];
    s32 damage;
    u8 pad8[4];
    u32 flags;
};

struct Actor_func_80204FC4_de;
/* unbake published declaration: published_60f9eac68ac992e319573a09 */
struct Actor_func_80204FC4_de {
    char pad0[0xE6];
    signed char always;
    char padE7[0x100 - 0xE7];
    int flags;
    float range;
    short x;
    short y;
    short level;
    char pad10E[0x12C - 0x10E];
    short altLevel;
    char pad12E[0x134 - 0x12E];
    float altRange;
};

struct func_8020520C_S2;
/* unbake published declaration: published_6aa263bcba1e01a2eb4ab474 */
typedef struct func_8020520C_S2 func_8020520C_S2;

struct Damageable;
/* unbake published declaration: published_6ac8b51dfca15fae34259737 */
typedef struct Damageable Damageable;

struct Event_func_80206018_de;
/* unbake published declaration: published_6c6cf56185ecfac9a5f91f1a */
typedef struct Event_func_80206018_de Event_func_80206018_de;

/* unbake published declaration: published_6d4e995f737617459f8731c6 */
extern void func_80205494_de(void *arg0, void *arg1);

struct func_80205494_S1;
/* unbake published declaration: published_6e0890aefef9d16964a5aca6 */
struct func_80205494_S1 {
    char pad0[0x18];
    char * unk18;
    char pad18[0x100 - 0x18 - sizeof(char*)];
    unsigned int unk100;
};

struct func_80205628_S2;
/* unbake published declaration: published_6f5372a1c40cc89add07995e */
typedef struct func_80205628_S2 func_80205628_S2;

struct func_8020612C_S3;
/* unbake published declaration: published_71b8c35ec3807bfcdb632e24 */
typedef struct func_8020612C_S3 func_8020612C_S3;

struct func_80204F78_S1;
/* unbake published declaration: published_7333d464d385197176027b44 */
struct func_80204F78_S1 {
    char pad0[0x40];
    float unk40;
    char pad40[0x64 - 0x40 - sizeof(float)];
    float unk64;
};

/* unbake published declaration: published_7b80ebf9a89d38e1578c3a61 */
extern float D_800C1ACC_de;

/* unbake published declaration: published_82f5438b3b625cab3420a85b */
extern void func_80205628_de(void *arg0, void *arg1, void *arg2);

/* unbake published declaration: published_8e16fc4be56809c09b9dbb2d */
extern void func_80205EC4_de(void *arg0, void *arg1);

/* unbake published declaration: published_8ec197889e8ab2c74239ae0b */
extern float D_800C1AD0_de;

struct Health;
/* unbake published declaration: published_972ff6e1119d780069dc8775 */
typedef struct Health Health;

struct func_8020612C_S4;
/* unbake published declaration: published_9766b3968c7ee1691640e761 */
struct func_8020612C_S4 {
    char pad0[0x40];
    f32 unk40;
    char pad40[0x64 - 0x40 - sizeof(f32)];
    f32 unk64;
    char pad64[0x124 - 0x64 - sizeof(f32)];
    s32 unk124;
    char pad124[0x128 - 0x124 - sizeof(s32)];
    s32 unk128;
};

struct func_80205628_S2;
/* unbake published declaration: published_a0415d3860c380836adeef37 */
struct func_80205628_S2 {
    char pad0[0x124];
    s32 unk124;
    char pad124[0x128 - 0x124 - sizeof(s32)];
    s32 unk128;
};

struct func_8020520C_S2;
/* unbake published declaration: published_a459b9d3fb15e6be03f3a132 */
struct func_8020520C_S2 {
    char pad0[0x3];
    signed char unk3;
};

struct Action;
/* unbake published declaration: published_a559141bf69be4469c290828 */
typedef struct Action Action;

struct func_80205628_S1;
/* unbake published declaration: published_a5dfb0fa15f83e43c2bad622 */
typedef struct func_80205628_S1 func_80205628_S1;

struct func_80204F78_S1;
/* unbake published declaration: published_a830858fe56ced1813750789 */
typedef struct func_80204F78_S1 func_80204F78_S1;

struct Action;
/* unbake published declaration: published_b1438cca34afe2ceb3b23b23 */
struct Action {
    char pad0[0x64];
    f32 delay;
    char pad68[0x124 - 0x68];
    s32 timer;
    s32 duration;
};

struct ActionInfo;
/* unbake published declaration: published_b1b1a4678cc5e01c87aded89 */
typedef struct ActionInfo ActionInfo;

struct CallbackHolder;
struct Event_func_80206018_de;
/* unbake published declaration: published_b5c1102116c379645319af00 */
struct CallbackHolder {
    char pad0[8];
    void (*callback)(void *arg0, Event_func_80206018_de *arg1);
};

/* unbake published declaration: published_ec680c90936497af3f531b7f */
struct Event_func_80206018_de {
    char pad0[0x30];
    struct CallbackHolder *holder;
};

struct func_8020612C_S4;
/* unbake published declaration: published_b8030cf0db2728a11eb3b2db */
typedef struct func_8020612C_S4 func_8020612C_S4;

struct Descriptor;
struct Descriptor {
    u8 pad0[0x14];
    Damage damage;
};
struct Damageable;
struct Descriptor;
/* unbake published declaration: published_ce4e63c8f1d5cec926da0352 */
struct Damageable {
    u8 pad0;
    u8 stage;
    u8 pad2[0x16];
    struct Descriptor *desc;
};

/* unbake published declaration: published_d54ab52ba3f1a2cef2c8efba */
extern void func_802055EC_de(void *arg0, void *arg1);

struct Cell;
/* unbake published declaration: published_d895a4e23f64fe2fb5485bf4 */
struct Cell {
    char pad0[0xCA];
    unsigned char pos;
    signed char open;
};

struct Access_s32_40;
/* unbake published declaration: published_da4fb7eaf39963676eb71b3c */
struct Access_s32_40 {
    unsigned char padding_0[64];
    int field;
};

/* unbake published declaration: published_dd1e3a30889e64fbe69b1d23 */
extern int func_8020570C_de(void *arg0);

struct Hit;
/* unbake published declaration: published_e1a27d03ba0efd2c1ddf833d */
typedef struct Hit Hit;

/* unbake published declaration: published_e82b07aa3da7c315934e3343 */
extern int func_802054D0_de(void *object);

struct func_80205494_S1;
/* unbake published declaration: published_e9bda11c8c31d0128b7ff1cc */
typedef struct func_80205494_S1 func_80205494_S1;

struct func_8020520C_S1;
/* unbake published declaration: published_eab51dd00c9529cb6d2af799 */
struct func_8020520C_S1 {
    char pad0[0x2C];
    void * unk2C;
    char pad2C[0x108 - 0x2C - sizeof(void*)];
    void * unk108;
    char pad108[0x10C - 0x108 - sizeof(void*)];
    void * unk10C;
    char pad10C[0x110 - 0x10C - sizeof(void*)];
    void * unk110;
    char pad110[0x124 - 0x110 - sizeof(void*)];
    int unk124;
    char pad124[0x128 - 0x124 - sizeof(int)];
    int unk128;
};

struct Actor_func_80205F18_de;
/* unbake published declaration: published_f048b7022f3159ebd357ce56 */
typedef struct Actor_func_80205F18_de Actor_func_80205F18_de;

/* unbake published declaration: published_f2dcee36062ed49cfb97d152 */
extern void func_8020520C_de(void *source, void *dest);

/* unbake published declaration: published_f74d0c6dfde543808bbdfc2f */
extern int func_80205314_de(void *arg0);

struct Descriptor_func_80205F18_de;
struct Descriptor_func_80205F18_de {
    char pad0[0x14];
    ActionInfo info;
};
struct Actor_func_80205F18_de;
struct Descriptor_func_80205F18_de;
/* unbake published declaration: published_fa9954ad690bcf4be02c7df5 */
struct Actor_func_80205F18_de {
    char pad0[0x18];
    struct Descriptor_func_80205F18_de *desc;
    char pad1C[0xE4 - 0x1C];
    u16 model;
    char padE6[0x100 - 0xE6];
    s32 flags;
};

struct func_80205628_S1;
/* unbake published declaration: published_fae2ea97274712a6273f2375 */
struct func_80205628_S1 {
    char pad0[0xB4];
    s32 unkB4;
    char padB4[0x17C - 0xB4 - sizeof(s32)];
    s32 unk17C;
};

#endif
