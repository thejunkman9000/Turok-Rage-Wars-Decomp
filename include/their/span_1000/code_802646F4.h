#ifndef UNBAKE_SPAN_1000_CODE_802646F4_H
#define UNBAKE_SPAN_1000_CODE_802646F4_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct Actor_func_80264B8C_de;
/* unbake published declaration: published_5147e735b87f5d698e4037fe */
struct Actor_func_80264B8C_de {
    char pad0[8];
    Triple position;
    s32 id;
    char pad18[0x6C - 0x18];
    f32 field6C;
    char pad70[0x5E0 - 0x70];
    Block70 block;
    char pad650[0x16E8 - 0x650];
};

struct ActorList;
struct Actor_func_80264B8C_de;
/* unbake published declaration: published_06c8cd33ce4abffae58ba3a1 */
struct ActorList {
    s32 pad0;
    struct Actor_func_80264B8C_de *actors;
    s32 count;
};

struct Snapshot;
/* unbake published declaration: published_09089ce3e543f2cac2a3d282 */
struct Snapshot {
    s32 pad0;
    s32 mode;
    char pad8[0x8];
    Block70 blocks[8];
    Triple positions[8];
    f32 values[8];
    s32 handles[8];
};

struct Curve_func_80264EE0_de;
/* unbake published declaration: published_6fcc0c931864cfed4eabc849 */
struct Curve_func_80264EE0_de {
    int type;
    unsigned char samples[0x10];
    float length;
};

struct Curve_func_80264EE0_de;
struct Player_func_80264EE0_de;
/* unbake published declaration: published_0f4a5c57f1232dfe2610654e */
struct Player_func_80264EE0_de {
    struct Curve_func_80264EE0_de *curve;
    float time;
    float value;
};

/* unbake published declaration: published_1b7c3df99c9617d62bd7afca */
extern void func_80264B7C_de();

struct func_80264A40_S1;
/* unbake published declaration: published_21218ef7cdf0cb2315cffc1b */
typedef struct func_80264A40_S1 func_80264A40_S1;

struct Player_func_80264EE0_de;
/* unbake published declaration: published_24aba7705498fe79887d55e1 */
typedef struct Player_func_80264EE0_de Player_func_80264EE0_de;

struct Snapshot;
/* unbake published declaration: published_24e433e356e60b3e5b33b90f */
typedef struct Snapshot Snapshot;

struct Snapshot_func_80264CE0_de;
/* unbake published declaration: published_38196f63704a1fb6ae719d4f */
struct Snapshot_func_80264CE0_de {
    char pad0[0x10];
    Block70 blocks[8];
    Triple positions[8];
    f32 values[8];
    s32 handles[8];
};

/* unbake published declaration: published_383ed0341b2caad6e5152e57 */
extern void func_80264CE0_de();

struct Snapshot_func_80264CE0_de;
/* unbake published declaration: published_3f761cf82f3eeae524c12132 */
typedef struct Snapshot_func_80264CE0_de Snapshot_func_80264CE0_de;

/* unbake published declaration: published_61694a834f10e909b42ae88c */
extern s32 func_802646D4_de(s32 arg0);

struct func_80264E10_S1;
/* unbake published declaration: published_61fec109ac5885dc45abf8f9 */
typedef struct func_80264E10_S1 func_80264E10_S1;

/* unbake published declaration: published_6283ab83280276f3cab10842 */
extern void func_80264B8C_de();

struct func_80264E10_S2;
/* unbake published declaration: published_6a8df5f7845bd0e1db67672a */
struct func_80264E10_S2 {
    char pad0[0x4];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    u8 unk8;
    char pad8[0x9 - 0x8 - sizeof(u8)];
    u8 unk9;
    char pad9[0x14 - 0x9 - sizeof(u8)];
    f32 unk14;
};

/* unbake published declaration: published_70449fad54a50902cdcae295 */
extern void func_80264CB8_de();

struct Actor_func_80264B8C_de;
/* unbake published declaration: published_7e8d996852c16a5f0b4851ee */
typedef struct Actor_func_80264B8C_de Actor_func_80264B8C_de;

/* unbake published declaration: published_885bb769c3d378ce5c698500 */
extern void func_802649FC_de();

/* unbake published declaration: published_93cf0bb319dd4459889c498b */
extern void func_8026479C_de();

struct func_80264E10_S2;
/* unbake published declaration: published_956aa6d99ff581022cffd31a */
typedef struct func_80264E10_S2 func_80264E10_S2;

/* unbake published declaration: published_98fba4e114e13422eb7f02e5 */
extern void func_80264A20_de(void);

struct ActorList;
/* unbake published declaration: published_ad45a7a571200cf882961826 */
typedef struct ActorList ActorList;

/* unbake published declaration: published_afdf9a599b95d30a27f2c2bd */
extern void func_8026480C_de();

/* unbake published declaration: published_c36470da2cdf801c090f730f */
extern void func_80264B44_de();

struct func_80264A40_S1;
/* unbake published declaration: published_c758a25592d5d5e93d3c9f8c */
struct func_80264A40_S1 {
    char pad0[0x5EC];
    s32 unk5EC;
    char pad5EC[0x650 - 0x5EC - sizeof(s32)];
    u16 unk650;
};

/* unbake published declaration: published_d82ab190bc19e2dc19b0adf7 */
extern void func_8026495C_de();

struct func_80264E10_S1;
/* unbake published declaration: published_d98991dbb5a83613faa61ac0 */
struct func_80264E10_S1 {
    char pad0[0x4];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
};

/* unbake published declaration: published_daa202123aa126f3064eb384 */
extern s32 func_80264DF0_de(void *arg0);

struct Curve_func_80264EE0_de;
/* unbake published declaration: published_ea52d4b1c2a7bfcd0f766fce */
typedef struct Curve_func_80264EE0_de Curve_func_80264EE0_de;

/* unbake published declaration: published_f0c37ab62c279c4429eadd42 */
extern void func_80264A0C_de();

#endif
