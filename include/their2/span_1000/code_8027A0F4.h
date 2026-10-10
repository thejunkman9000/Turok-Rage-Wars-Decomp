#ifndef UNBAKE_SPAN_1000_CODE_8027A0F4_H
#define UNBAKE_SPAN_1000_CODE_8027A0F4_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
struct Actor_func_80281A9C_de;
/* unbake published declaration: published_01c1540c780b0945aeeb4574 */
typedef struct Actor_func_80281A9C_de Actor_func_80281A9C_de;

struct Shared_ParticleInstance;
/* unbake published declaration: published_0a321779c558d1f593c9a8d6 */
struct Shared_ParticleInstance {
    char pad0[0x4];
    u16 type;
    char pad6[0x2];
    Vec3 pos;
    s32 unk14;
    char pad18[0x4];
    Vec3 velocity;
    char pad28[0x10];
    s32 unk38;
    char pad3C[0x14];
};

struct func_8027EB00_S2;
/* unbake published declaration: published_0dd702acca521d72f06fcccb */
struct func_8027EB00_S2 {
    char pad0[0x8];
    char unk8;
    char pad8[0x110 - 0x8 - sizeof(char)];
    s32 unk110;
    s32 unk114;
    void *unk118;
};

struct Actor_func_8027B428_de;
/* unbake published declaration: published_1091e35184f55f436e14d38a */
typedef struct Actor_func_8027B428_de Actor_func_8027B428_de;

struct Actor_func_8027B428_de;
struct Shape_func_8021A2D4_de_2;
/* unbake published declaration: published_134ae700c5b2f3996d996d53 */
struct Actor_func_8027B428_de {
    char pad0[4];
    u16 type;
    char pad6[0x12];
    struct Shape_func_8021A2D4_de_2 *descriptor;
    char pad1C[0x110];
    func_8024E8F0_S1 *owner;
};

struct Parent;
/* unbake published declaration: published_13e0b60f9a9768bf3a0d4dcc */
typedef struct Parent Parent;

/* unbake published declaration: published_186e7519a54a7930f9dc4953 */
extern void func_8027FF58_de(void *arg0);

struct Entry_func_80282C8C_de;
/* unbake published declaration: published_18f63e363b9a76ff3e4124bd */
struct Entry_func_80282C8C_de {
    s16 kind;
    char pad[2];
    s16 id;
};

struct Shared_CollisionResult;
/* unbake published declaration: published_221a8aac7e4d210ed7a8637f */
typedef struct Shared_CollisionResult Shared_CollisionResult;

union func_80282E6C_S1_U8;
/* unbake published declaration: published_275c8a308c08632232c40ee7 */
union func_80282E6C_S1_U8 {
    Triple v0;
    Vec3 v1;
};

union func_8027C5A0_S1_U118;
/* unbake published declaration: published_a351037139724da45d883827 */
union func_8027C5A0_S1_U118 {
    void * v0;
    s32 * v1;
};

union func_8027C5A0_S1_U118;
/* unbake published declaration: published_e16239ec6db2070c3c1236af */
typedef union func_8027C5A0_S1_U118 func_8027C5A0_S1_U118;

struct func_8027C5A0_S1;
/* unbake published declaration: published_3b00f045f705a1f6bed5b99e */
struct func_8027C5A0_S1 {
    char pad0[0x1C];
    Triple unk1C;
    char pad1C[0x5C - 0x1C - sizeof(Triple)];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    func_8027C5A0_S1_U118 unk118;
    char pad118[0x12C - 0x118 - sizeof(func_8027C5A0_S1_U118)];
    void * unk12C;
    char pad12C[0x130 - 0x12C - sizeof(void*)];
    s32 unk130;
    char pad130[0x134 - 0x130 - sizeof(s32)];
    s32 unk134;
};

struct func_8027D950_S1;
/* unbake published declaration: published_3e0f8d347cb46eb089a4fb9a */
typedef struct func_8027D950_S1 func_8027D950_S1;

struct Shared_ParticleInstance;
/* unbake published declaration: published_4034a51c57fc44bfe277891d */
typedef struct Shared_ParticleInstance Shared_ParticleInstance;

struct Shared_ParticleOwner;
/* unbake published declaration: published_45094f0b9c49c1a5c3888a9d */
typedef struct Shared_ParticleOwner Shared_ParticleOwner;

struct Entry_func_80282C8C_de;
/* unbake published declaration: published_a63190c895f17a28552ccd1e */
typedef struct Entry_func_80282C8C_de Entry_func_80282C8C_de;

struct Record_func_80282C8C_de;
/* unbake published declaration: published_46117cb54291d21eef30301d */
struct Record_func_80282C8C_de {
    char pad[0x20];
    Entry_func_80282C8C_de *first[3];
    Entry_func_80282C8C_de *second[3];
};

struct Node_func_8027FF58_de;
/* unbake published declaration: published_4648080ea1c3543abc3607d2 */
typedef struct Node_func_8027FF58_de Node_func_8027FF58_de;

struct func_8027EB00_S2;
/* unbake published declaration: published_4a401ecdc7295e4fcf760872 */
typedef struct func_8027EB00_S2 func_8027EB00_S2;

/* unbake published declaration: published_4abce60b94e9b4d6e2aa6250 */
extern int D_801042C4;

struct Actor_func_8027DAD0_de;
/* unbake published declaration: published_4b67bf2ed900be63d854b5b0 */
typedef struct Actor_func_8027DAD0_de Actor_func_8027DAD0_de;

struct Actor_func_8027E784_de;
/* unbake published declaration: published_6b8d8952d90b016d92375e11 */
typedef struct Actor_func_8027E784_de Actor_func_8027E784_de;

struct Instance_func_8027E784_de;
/* unbake published declaration: published_d585b6c4bca2c358888626b7 */
typedef struct Instance_func_8027E784_de Instance_func_8027E784_de;

struct Instance_func_8027E784_de;
/* unbake published declaration: published_fb3c9eb4c5a3430788186f0d */
struct Instance_func_8027E784_de {
    char pad0[8];
    Vec3 position;
    char pad14[8];
    Vec3 velocity;
    char pad28[0x28];
};

struct ActorDef;
struct ActorDef {
    s32 flags;
    char pad4[0x10];
    s32 large;
    char pad18[0xC];
    func_80232C78_S4 *size;
};
struct ActorDef;
struct Actor_func_8027E784_de;
/* unbake published declaration: published_81b0c0e7598273f3982a2fe0 */
struct Actor_func_8027E784_de {
    Instance_func_8027E784_de instance;
    char pad50[0xC8];
    struct ActorDef *def;
    char pad11C[0x24];
    f32 damage;
    char pad144[8];
    s16 health;
    char pad14E[0xA];
    f32 radius;
};

/* unbake published declaration: published_55891ab1bb3f3be17d17e761 */
extern void func_8027E784_de(Actor_func_8027E784_de *actor);

struct Shared_ParticleTarget;
/* unbake published declaration: published_5879124f3c29ad5ae941e338 */
struct Shared_ParticleTarget {
    char pad0[0xB4];
    struct UnitMtx *drawMatrices;
    char padB8[0x48];
    s32 flags;
    char pad104[0x6C];
    s32 unk170;
    s32 unk174;
    char pad178[0x2C];
    s8 unk1A4;
};

struct func_80282E6C_Table;
/* unbake published declaration: published_5d8950fedf82531b2a3c73b3 */
struct func_80282E6C_Table {
    char pad[0xA8];
    u16 unkA8;
};

/* unbake published declaration: published_5fd74448f8ea787720271fb3 */
extern float D_800C4E60_de;

struct Object_func_80281A9C_de;
/* unbake published declaration: published_606b3c51606d87ffd3801f46 */
typedef struct Object_func_80281A9C_de Object_func_80281A9C_de;

struct Object_func_80281A9C_de;
/* unbake published declaration: published_a563ce7431a407c7bba5df6c */
struct Object_func_80281A9C_de {
    char pad0[8];
    Vec3 position;
    char pad14[0x160];
    s32 count;
};

struct World_func_80281A9C_de;
/* unbake published declaration: published_6c72fd032f42254870fc5abf */
struct World_func_80281A9C_de {
    char pad0[0xE54];
    Object_func_80281A9C_de *objects[64];
    s32 objectCount;
};

struct Shared_Particle;
/* unbake published declaration: published_6f3167a99cb20372c900b17d */
typedef struct Shared_Particle Shared_Particle;

struct func_8027C324_S1;
/* unbake published declaration: published_706d3d7d188259c98012eb08 */
typedef struct func_8027C324_S1 func_8027C324_S1;

union func_8027C324_S1_U118;
/* unbake published declaration: published_77d1296f089eb70e933ea816 */
union func_8027C324_S1_U118 {
    s32 * v0;
    void * v1;
};

struct func_80282E6C_S1;
/* unbake published declaration: published_7867b34dca3536c0426f5878 */
typedef struct func_80282E6C_S1 func_80282E6C_S1;

struct Ground;
/* unbake published declaration: published_7a1f647be581e88752622e6a */
struct Ground {
    s32 found;
    char pad4[8];
    f32 height;
    char pad10[0xE0];
    Vec3 normal;
};

/* unbake published declaration: published_8522f496d9d17f5e4ed2e83b */
extern int D_8010029C;

struct func_80282E6C_Table;
/* unbake published declaration: published_86adc43cb4d0bfc408e9a74c */
typedef struct func_80282E6C_Table func_80282E6C_Table;

struct func_8027D950_S1;
/* unbake published declaration: published_8b51c8a6cf265b815349a429 */
struct func_8027D950_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    s32 unk10;
    char pad10[0x1D0 - 0x10 - sizeof(s32)];
    func_80209DAC_S2_U93 unk1D0;
};

struct Parent;
/* unbake published declaration: published_a16c4b79f656bd49bf4368ec */
struct Parent {
    char pad0[8];
    Vec3 position;
    char pad14[0x60];
    f32 transform[16];
    void *skeleton;
    char padB8[0x48];
    s32 flags;
    char pad104[0xD4];
    func_80228774_S5 *model;
};

struct Actor_func_8027DAD0_de;
struct Parent;
/* unbake published declaration: published_907982b0e2cc2097b42d7845 */
struct Actor_func_8027DAD0_de {
    char pad0[4];
    u16 type;
    char pad6[2];
    Vec3 position;
    s32 unk14;
    char pad18[4];
    Vec3 heading;
    char pad28[0x28];
    Vec3 offset;
    s32 flags;
    char pad60[0xCC];
    struct Parent *owner;
    char pad130[4];
    struct Parent *parent;
    char pad138[0x3C];
    Vec3 facing;
    char pad180[0x51];
    s8 bone;
};

struct func_8027DAA4_S1;
/* unbake published declaration: published_93decf7ee52d89879776fcf9 */
struct func_8027DAA4_S1 {
    char pad0[0x160];
    char unk160;
};

struct Shared_CollisionResult;
/* unbake published declaration: published_93e8ed7aafa6b5b2b92e5ade */
struct Shared_CollisionResult {
    u8 *unk0;
    char pad4[0x4];
    char unk8[0x80];
    s32 unk88;
    char pad8C[0x4];
    char unk90[0xC];
    s32 unk9C;
    char unkA0[0x10];
    s32 unkB0;
    s32 unkB4;
    char unkB8[0xC];
    s32 unkC4;
    char unkC8[0x10];
    Vec3 unkD8;
};

struct func_80282E6C_S3;
/* unbake published declaration: published_94ebebb8f957d45605b04ee7 */
struct func_80282E6C_S3 {
    char pad0[0x140];
    char unk140;
};

union func_80282E6C_S1_U8;
/* unbake published declaration: published_b359a77fa2fdbfe3a99e87eb */
typedef union func_80282E6C_S1_U8 func_80282E6C_S1_U8;

struct func_80282E6C_S1;
/* unbake published declaration: published_9bcec8c7e31a6b30a39e8627 */
struct func_80282E6C_S1 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0x8 - 0x4 - sizeof(u16)];
    func_80282E6C_S1_U8 unk8;
    char pad8[0x118 - 0x8 - sizeof(func_80282E6C_S1_U8)];
    void * unk118;
    char pad118[0x12C - 0x118 - sizeof(void*)];
    void * unk12C;
    char pad12C[0x1D0 - 0x12C - sizeof(void*)];
    s8 unk1D0;
};

struct func_80282E6C_S5;
/* unbake published declaration: published_aa83a44636df3accb331fd9d */
struct func_80282E6C_S5 {
    char pad0[0x70];
    u16 unk70;
    char pad70[0x8C - 0x70 - sizeof(u16)];
    u16 unk8C;
};

union func_8027C324_S1_U118;
/* unbake published declaration: published_ab4a49bc6e2a432298b17645 */
typedef union func_8027C324_S1_U118 func_8027C324_S1_U118;

struct Shared_ParticleOwner;
/* unbake published declaration: published_cdfcc9d10f6451519f4498c8 */
struct Shared_ParticleOwner {
    u8 kind;
    char pad1[0xFF];
    s32 flags;
    char pad104[0xD4];
    Player_func_802676EC_de *state;
};

struct Shared_ParticleColors;
struct Shared_ParticleColors {
    char pad0[0x6];
    u8 prim[3];
    u8 env[3];
};
struct Shared_ParticleFade;
struct Shared_ParticleFade {
    char pad0[0x5];
    s8 rangeMode;
    char pad6[0x3];
    s8 fadeIn;
    s8 fadeOut;
    char padB[0x3];
    s8 unkE;
};
struct Shared_ParticleColors;
struct Shared_ParticleDesc;
struct Shared_ParticleFade;
/* The oscillator controller is reached through descriptor byte0x2C.
 * The ROM reads its signed ramp byte at0x18. */
struct Shared_ParticleOscillation {
    char reserved[0x18];
    s8 ramp;
};
struct Shared_ParticleDesc {
    s32 flags;
    char pad4[0x4];
    s8 animMode;
    char pad9[0x7];
    s16 unk10;
    char pad12[0x1A];
    struct Shared_ParticleOscillation *oscillation;
    char pad30[0x4];
    struct Shared_ParticleColors *colors;
    struct Shared_ParticleFade *fade;
};
struct Shared_Particle;
struct Shared_ParticleDesc;
struct Shared_ParticleOwner;
struct Shared_ParticleTarget;
/* unbake published declaration: published_b1656c38df628e0dea184522 */
struct Shared_Particle {
    Shared_ParticleInstance inst;
    Vec3 attachmentPosition;
    s32 flags;
    Matrix mtx[2];
    char padE0[0x38];
    struct Shared_ParticleDesc *desc;
    s32 model;
    char pad120[0xC];
    struct Shared_ParticleOwner *owner;
    char pad130[0x4];
    struct Shared_ParticleTarget *target;
    char pad138[0x8];
    f32 time;
    f32 frame;
    f32 unk148;
    s16 life;
    s8 unk14E;
    s8 unk14F;
    Vec3 size;
    Vec3 growth;
    Vec3 prevPos;
    Vec3 unk174;
    Vec3 rot;
    Vec3 rotSpeed;
    f32 alpha;
    /* Two phase/speed/amplitude triples occupy the existing oscillator words. */
    f32 phaseA;
    f32 phaseB;
    f32 phaseSpeedA;
    f32 phaseSpeedB;
    f32 amplitudeA;
    f32 amplitudeB;
    s32 unk1B4;
    char pad1B8[0x1];
    s8 unk1B9;
    char pad1BA[0x2];
    f32 unk1BC;
    char pad1C0[0x10];
    s8 unk1D0;
    s8 unk1D1;
    u8 prim[3];
    u8 env[3];
    u8 opacity;
};

struct func_8027C808_S1;
/* unbake published declaration: published_b3b5837af2b0d5f86579fc40 */
typedef struct func_8027C808_S1 func_8027C808_S1;

struct func_80282E6C_S3;
/* unbake published declaration: published_b8528fa6c1f1640fb99065d0 */
typedef struct func_80282E6C_S3 func_80282E6C_S3;

struct func_8027C808_S1;
/* unbake published declaration: published_b8b30b7bbb8dcdb72f44e6e6 */
struct func_8027C808_S1 {
    char pad0[0x1C];
    Triple unk1C;
    char pad1C[0x5C - 0x1C - sizeof(Triple)];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    func_8027C5A0_S1_U118 unk118;
    char pad118[0x12C - 0x118 - sizeof(func_8027C5A0_S1_U118)];
    void * unk12C;
    char pad12C[0x130 - 0x12C - sizeof(void*)];
    s32 unk130;
    char pad130[0x134 - 0x130 - sizeof(s32)];
    s32 unk134;
    char pad134[0x18C - 0x134 - sizeof(s32)];
    char unk18C;
    char pad18C[0x1BA - 0x18C - sizeof(char)];
    s8 unk1BA;
    char pad1BA[0x1C4 - 0x1BA - sizeof(s8)];
    s32 unk1C4;
};

struct func_8027D950_S2;
/* unbake published declaration: published_ba2c9a79f4a4544465758e25 */
typedef struct func_8027D950_S2 func_8027D950_S2;

struct func_80282E6C_S5;
/* unbake published declaration: published_bb277c20a60bc6743f4760f1 */
typedef struct func_80282E6C_S5 func_80282E6C_S5;

struct func_80282E6C_S2;
/* unbake published declaration: published_c30715a86114e8da126b9271 */
typedef struct func_80282E6C_S2 func_80282E6C_S2;

struct Node_func_8027FF58_de;
/* unbake published declaration: published_cae4f6b2514024c876c19dfa */
struct Node_func_8027FF58_de {
    char pad0[0x5C];
    s32 flags;
    char pad60[0xD0];
    s32 *counter;
    char pad134[4];
    s32 resource;
    char pad13C[0x9D];
    u8 marker;
    char pad1DA[0xA];
    void *handle;
    char pad1E8[4];
    struct Node_func_8027FF58_de *next;
};

struct Shared_ParticleTarget;
/* unbake published declaration: published_d2edcc91d44782b1059490e1 */
typedef struct Shared_ParticleTarget Shared_ParticleTarget;

struct func_8027D950_S2;
/* unbake published declaration: published_d67b909fbfd684ba51a53c42 */
struct func_8027D950_S2 {
    char pad0[0xE54];
    char unkE54;
    char padE54[0xE94 - 0xE54 - sizeof(char)];
    char unkE94;
};

struct Record_func_80282C8C_de;
/* unbake published declaration: published_d97ec572ff51aa925ed6c196 */
typedef struct Record_func_80282C8C_de Record_func_80282C8C_de;

struct func_8027C5A0_S1;
/* unbake published declaration: published_dea4dc1217a6045c4d0e93a3 */
typedef struct func_8027C5A0_S1 func_8027C5A0_S1;

struct func_8027C324_S1;
/* unbake published declaration: published_ea6cd149ddc099f01c1f4cf5 */
struct func_8027C324_S1 {
    char pad0[0x1C];
    Triple unk1C;
    char pad1C[0x5C - 0x1C - sizeof(Triple)];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    func_8027C324_S1_U118 unk118;
    char pad118[0x12C - 0x118 - sizeof(func_8027C324_S1_U118)];
    void * unk12C;
    char pad12C[0x130 - 0x12C - sizeof(void*)];
    s32 unk130;
    char pad130[0x134 - 0x130 - sizeof(s32)];
    s32 unk134;
    char pad134[0x18C - 0x134 - sizeof(s32)];
    char unk18C;
    char pad18C[0x1B9 - 0x18C - sizeof(char)];
    s8 unk1B9;
    char pad1B9[0x1C4 - 0x1B9 - sizeof(s8)];
    s32 unk1C4;
};

struct func_80282E6C_S2;
/* unbake published declaration: published_eb264894a27c3af38e5a8121 */
struct func_80282E6C_S2 {
    char pad0[0x8];
    Vec3 unk8;
    char pad8[0x698 - 0x8 - sizeof(Vec3)];
    void * unk698;
    char pad698[0x11EC - 0x698 - sizeof(void*)];
    f32 unk11EC;
};

struct func_8027DAA4_S1;
/* unbake published declaration: published_ef15202bbc8cae1008b232a9 */
typedef struct func_8027DAA4_S1 func_8027DAA4_S1;

struct Ground;
/* unbake published declaration: published_f73b5726b46a6c342eced252 */
typedef struct Ground Ground;

struct Actor_func_80281A9C_de;
/* unbake published declaration: published_fa84a8131bf205ca4edd30ea */
struct Actor_func_80281A9C_de {
    char pad0[4];
    u16 type;
    char pad6[2];
    Vec3 position;
    char pad14[0x118];
    SharedPlayer_func_8022A398_de *owner;
    char pad130[0x1C];
    s16 crowded;
};

struct World_func_80281A9C_de;
/* unbake published declaration: published_fcaeb83c38037bde687b826b */
typedef struct World_func_80281A9C_de World_func_80281A9C_de;

#endif
