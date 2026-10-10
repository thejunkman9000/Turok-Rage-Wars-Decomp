#ifndef UNBAKE_SPAN_1000_CODE_8022F3E8_H
#define UNBAKE_SPAN_1000_CODE_8022F3E8_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
struct ObjectLinks14C;
/* unbake published declaration: published_0030a10c76665024b9356466 */
struct ObjectLinks14C {
    char pad0[0x30];
    void * callback_owner;
    char pad30[0x130 - 0x30 - sizeof(void*)];
    f32 unk_130;
    char pad130[0x148 - 0x130 - sizeof(f32)];
    f32 unk_148;
};

struct func_80230BB8_S1;
/* unbake published declaration: published_0cc23fdae24dd36955e5f1cc */
struct func_80230BB8_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0x5DC - 0x8 - sizeof(s32)];
    char * unk5DC;
    char pad5DC[0x62E - 0x5DC - sizeof(char*)];
    s16 unk62E;
    char pad62E[0x6AC - 0x62E - sizeof(s16)];
    s32 unk6AC;
    char pad6AC[0x11B4 - 0x6AC - sizeof(s32)];
    s32 unk11B4;
    char pad11B4[0x11D8 - 0x11B4 - sizeof(s32)];
    f32 unk11D8;
    char pad11D8[0x1450 - 0x11D8 - sizeof(f32)];
    s32 unk1450;
    char pad1450[0x1454 - 0x1450 - sizeof(s32)];
    char * unk1454;
};

struct func_80230BB8_S5;
/* unbake published declaration: published_0fc24be9d525ed0334f61c11 */
typedef struct func_80230BB8_S5 func_80230BB8_S5;

struct ObjectState44;
/* unbake published declaration: published_13a653fa610353385661faf8 */
typedef struct ObjectState44 ObjectState44;

struct Obj_func_8022F3F8_de;
/* unbake published declaration: published_1845ae5dfa19a57ac81344d0 */
typedef struct Obj_func_8022F3F8_de Obj_func_8022F3F8_de;

union ObjectLinks4;
/* unbake published declaration: published_716e53ec3f95fec19571f8e5 */
union ObjectLinks4 {
    s32 v0;
    char * v1;
};

union ObjectLinks4;
/* unbake published declaration: published_9fab55e6986213b3e4c54696 */
typedef union ObjectLinks4 ObjectLinks4;

struct ObjectState630;
/* unbake published declaration: published_1904c6c5af5d3385fafb066b */
struct ObjectState630 {
    char pad0[0x5DC];
    ObjectLinks4 unk_5DC;
    char pad5DC[0x62E - 0x5DC - sizeof(ObjectLinks4)];
    s16 unk_62E;
};

struct func_80230BB8_S2;
/* unbake published declaration: published_243e8e86396c9e5b36c6eec5 */
typedef struct func_80230BB8_S2 func_80230BB8_S2;

/* unbake published declaration: published_24618cf503bb4417c508a267 */
extern float D_800C2F5C_de;

/* unbake published declaration: published_2a2829b037eaa91a2d236782 */
extern float D_800C2FBC_de;

struct Object_func_8022FAF8_de;
/* unbake published declaration: published_35c73d87637de8710edbc72e */
typedef struct Object_func_8022FAF8_de Object_func_8022FAF8_de;

struct ObjectLinks1DC_2;
/* unbake published declaration: published_3c055b819f082d43f6e4cbee */
struct ObjectLinks1DC_2 {
    char pad0[0x1];
    u8 unk_1;
    char pad1[0x1D8 - 0x1 - sizeof(u8)];
    void * unk_1D8;
};

/* unbake published declaration: published_3d69e0ad11c48f85f6c647e2 */
extern int D_800CA040_de;

struct func_8022F95C_S2;
/* unbake published declaration: published_435029c5c1f5b9fa4906b8e1 */
struct func_8022F95C_S2 {
    char pad0[0x603];
    s8 unk603;
};

/* unbake published declaration: published_44ef6fc6c9538dcf38322ea3 */
extern float D_800C2E90_de;

struct CallbackState60;
/* unbake published declaration: published_4787c504c8a29073d532ffc4 */
struct CallbackState60 {
    unsigned char padding_0[92];
    void (*callback)(void *, void *);
};

/* unbake published declaration: published_59b57a779a5a0c7128c62eb6 */
extern void func_8022FF04_de(void *arg0, void *arg1);

/* unbake published declaration: published_5a6e6bc89ceeab00549f1ecd */
extern void func_8022F5E0_de(char *arg0);

struct Object_func_8022FAF8_de;
/* unbake published declaration: published_5aee2728b5d11f4a349ca5a8 */
struct Object_func_8022FAF8_de {
    s8 pad603[0x603];
    s8 values[0x2B];
    s16 selected;
};

struct func_80230BB8_S5;
/* unbake published declaration: published_5c16409486ddb5458f2aa1ac */
struct func_80230BB8_S5 {
    char pad0[0x64];
    f32 unk64;
    char pad64[0x128 - 0x64 - sizeof(f32)];
    f32 unk128;
};

struct ObjectState44;
/* unbake published declaration: published_5c7a4341e75960c6123925d6 */
struct ObjectState44 {
    unsigned char padding_0[56];
    Vec3 unk_38;
};

struct ObjectState630;
/* unbake published declaration: published_5f9a0667a615f09418881d85 */
typedef struct ObjectState630 ObjectState630;

struct func_8022FEF4_S3;
/* unbake published declaration: published_64e3a57d5ef7f1371727a484 */
typedef struct func_8022FEF4_S3 func_8022FEF4_S3;

struct ObjectState1230;
/* unbake published declaration: published_69c90230e6e389bd8554395a */
typedef struct ObjectState1230 ObjectState1230;

struct ObjectLinks14C;
/* unbake published declaration: published_6ade76dd23c34f18c086312c */
typedef struct ObjectLinks14C ObjectLinks14C;

struct func_80230620_S2;
/* unbake published declaration: published_6b01460da85191375f4690b5 */
struct func_80230620_S2 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x5D8 - 0x10 - sizeof(s32)];
    void * unk5D8;
    char pad5D8[0x62E - 0x5D8 - sizeof(void*)];
    s16 unk62E;
    char pad62E[0x650 - 0x62E - sizeof(s16)];
    s16 unk650;
    char pad650[0x698 - 0x650 - sizeof(s16)];
    void * unk698;
    char pad698[0x6B0 - 0x698 - sizeof(void*)];
    s32 unk6B0;
    char pad6B0[0x770 - 0x6B0 - sizeof(s32)];
    s16 unk770;
    char pad770[0x11FC - 0x770 - sizeof(s16)];
    s32 unk11FC;
};

struct ObjectState1230;
/* unbake published declaration: published_73528a40fa4c19a71dad0179 */
struct ObjectState1230 {
    char pad0[0x62E];
    s16 unk_62E;
    char pad62E[0x650 - 0x62E - sizeof(s16)];
    s16 unk_650;
    char pad650[0x770 - 0x650 - sizeof(s16)];
    s16 unk_770;
    char pad770[0x7E8 - 0x770 - sizeof(s16)];
    s32 unk_7E8;
    char pad7E8[0x11D8 - 0x7E8 - sizeof(s32)];
    f32 unk_11D8;
    char pad11D8[0x122C - 0x11D8 - sizeof(f32)];
    s32 unk_122C;
};

/* unbake published declaration: published_7a61126e726ed7a7f286581b */
extern float D_800C2FB4_de;

struct func_80230BB8_S1;
/* unbake published declaration: published_7b270fadb1a8ce0ed28cdd21 */
typedef struct func_80230BB8_S1 func_80230BB8_S1;

struct ObjectLinks1DC_2;
/* unbake published declaration: published_7d06155fbec76663e462db22 */
typedef struct ObjectLinks1DC_2 ObjectLinks1DC_2;

/* unbake published declaration: published_7fdf6ca242a5295aad890924 */
extern void func_8022F770_de(void *, void *);

struct func_80230620_S4;
/* unbake published declaration: published_804478e98930f4c7cdab36ba */
typedef struct func_80230620_S4 func_80230620_S4;

struct WeaponAnimationState;
/* unbake published declaration: published_890f46e2f8ee946b9f40b3bb */
struct WeaponAnimationState {
    char pad0[0x168];
    f32 speed;
};

/* unbake published declaration: published_92539d70256cade897db6a6c */
extern float D_800C2FC0_de;

/* unbake published declaration: published_973f3285d21d39dfaa57ed65 */
extern float D_800C2F20_de;

struct func_8022FEF4_S3;
/* unbake published declaration: published_9958eb0d3241bd3cab823ad3 */
struct func_8022FEF4_S3 {
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
    char pad130[0x13C - 0x130 - sizeof(s32)];
    s32 unk13C;
    char pad13C[0x144 - 0x13C - sizeof(s32)];
    s32 unk144;
};

struct func_80230620_S3;
/* unbake published declaration: published_9ca96462da9642364d40d41d */
struct func_80230620_S3 {
    char pad0[0xCB];
    s8 unkCB;
    char padCB[0x138 - 0xCB - sizeof(s8)];
    s32 unk138;
    char pad138[0x13C - 0x138 - sizeof(s32)];
    s32 unk13C;
};

/* unbake published declaration: published_a1272342d458a80a33c91142 */
extern float D_800C2F14_de;

/* unbake published declaration: published_a2055080676415f8cbd205d6 */
extern float D_800C8008;

struct func_80230620_S4;
/* unbake published declaration: published_a7022ad07e30e9c784a439bc */
struct func_80230620_S4 {
    char pad0[0x168];
    s32 unk168;
};

struct func_8022F95C_S2;
/* unbake published declaration: published_a94aeda88997c085a58a4f61 */
typedef struct func_8022F95C_S2 func_8022F95C_S2;

struct func_8022FEF4_S1;
/* unbake published declaration: published_ac557a8d929ead4a444e29ab */
typedef struct func_8022FEF4_S1 func_8022FEF4_S1;

/* unbake published declaration: published_aff68439c71d0beea546b569 */
extern float D_800C2F60_de;

struct ObjectLinks1DC;
/* unbake published declaration: published_b5917b7c798b2d4c77affd62 */
typedef struct ObjectLinks1DC ObjectLinks1DC;

struct func_80230620_S2;
/* unbake published declaration: published_c6e92cd685d702f458662f7e */
typedef struct func_80230620_S2 func_80230620_S2;

/* unbake published declaration: published_c722b42fc213936d40a66203 */
extern int D_800CA048;

struct CallbackState60;
/* unbake published declaration: published_c794881bf5130c26498569b9 */
typedef struct CallbackState60 CallbackState60;

struct WeaponAnimationState;
/* unbake published declaration: published_c8f9b51336320865597a989c */
typedef struct WeaponAnimationState WeaponAnimationState;

struct func_80230620_S3;
/* unbake published declaration: published_cace5b93ac1ce48237de4305 */
typedef struct func_80230620_S3 func_80230620_S3;

struct func_8022F95C_S1;
/* unbake published declaration: published_cc01ed8444b9faa8c0bdeded */
typedef struct func_8022F95C_S1 func_8022F95C_S1;

struct Obj_func_8022F3F8_de;
/* unbake published declaration: published_d4c7c68a6cb39e55ad78cf21 */
struct Obj_func_8022F3F8_de {
    char pad[0x18];
    unsigned char slots[13];
};

/* unbake published declaration: published_de36188ca636f21a793c8ff0 */
extern int D_800CA044;

struct ObjectLinks1DC;
/* unbake published declaration: published_e2f673f1792857317797e360 */
struct ObjectLinks1DC {
    char pad0[0x50];
    Vec3 unk_50;
    char pad50[0x1D8 - 0x50 - sizeof(Vec3)];
    char * unk_1D8;
};

struct func_80230BB8_S2;
/* unbake published declaration: published_ec88405fc572c95813c853bb */
struct func_80230BB8_S2 {
    char pad0[0x100];
    s32 unk100;
    char pad100[0x1D8 - 0x100 - sizeof(s32)];
    func_80230BB8_S2_U1D8 unk1D8;
};

/* unbake published declaration: published_ee551dc86fb89d65ef6e567f */
extern void func_80230DA4_de(void *actor, void *weapon);

/* unbake published declaration: published_f4e58562b584c04404a8059b */
extern float D_800C2FB0_de;

struct func_8022FEF4_S1;
/* unbake published declaration: published_fba23e2b53581f7f46621513 */
struct func_8022FEF4_S1 {
    char pad0[0x1];
    char unk1;
    char pad1[0x1D8 - 0x1 - sizeof(char)];
    char * unk1D8;
};

struct func_8022F95C_S1;
/* unbake published declaration: published_ff142b3f953422494970b11c */
struct func_8022F95C_S1 {
    char pad0[0x5F4];
    s16 unk5F4;
    char pad5F4[0x62E - 0x5F4 - sizeof(s16)];
    s16 unk62E;
    char pad62E[0x1450 - 0x62E - sizeof(s16)];
    s32 unk1450;
};

#endif
