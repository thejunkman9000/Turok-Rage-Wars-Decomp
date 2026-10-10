#ifndef UNBAKE_SPAN_1000_CODE_80231F5C_H
#define UNBAKE_SPAN_1000_CODE_80231F5C_H
#include "../types.h"
#include "common/draft_fields_func_80232E64_de.h"
#include "common/types_8a8189af7b05.h"
struct Player_func_802327F4_de;
/* unbake published declaration: published_06ea17d3b76620f434127d12 */
typedef struct Player_func_802327F4_de Player_func_802327F4_de;

struct func_80232A38_S1;
/* unbake published declaration: published_0946de6968dd07964f07de8e */
struct func_80232A38_S1 {
    char pad0[0x2C];
    char * unk2C;
    char pad2C[0x108 - 0x2C - sizeof(char*)];
    char * unk108;
    char pad108[0x10C - 0x108 - sizeof(char*)];
    char * unk10C;
    char pad10C[0x124 - 0x10C - sizeof(char*)];
    s32 unk124;
    char pad124[0x128 - 0x124 - sizeof(s32)];
    s32 unk128;
    char pad128[0x12C - 0x128 - sizeof(s32)];
    f32 unk12C;
    char pad12C[0x130 - 0x12C - sizeof(f32)];
    s32 unk130;
    char pad130[0x138 - 0x130 - sizeof(s32)];
    s32 unk138;
    char pad138[0x13C - 0x138 - sizeof(s32)];
    s32 unk13C;
    char pad13C[0x144 - 0x13C - sizeof(s32)];
    s32 unk144;
    char pad144[0x148 - 0x144 - sizeof(s32)];
    s32 unk148;
    char pad148[0x14C - 0x148 - sizeof(s32)];
    s32 unk14C;
    char pad14C[0x150 - 0x14C - sizeof(s32)];
    s32 unk150;
};

/* unbake published declaration: published_0bea5370953606996db4ca6d */
extern float D_800C303C_de;

struct ObjectState140;
/* unbake published declaration: published_0c7a6a087886d867c4ffe26a */
typedef struct ObjectState140 ObjectState140;

struct func_80232B54_S3;
/* unbake published declaration: published_0e5ed4d6aa3fff6ada90c916 */
struct func_80232B54_S3 {
    char pad0[0xCB];
    s8 unkCB;
    char padCB[0x124 - 0xCB - sizeof(s8)];
    s32 unk124;
    char pad124[0x128 - 0x124 - sizeof(s32)];
    s32 unk128;
};

/* unbake published declaration: published_260d0131793faf13e8de230a */
extern float D_800C3018_de;

struct Source_func_80232F8C_de;
struct Source_func_80232F8C_de {
    char pad[0x294];
    float speed;
};
struct Event;
struct Source_func_80232F8C_de;
/* unbake published declaration: published_2ba768141efc2a146dde55d3 */
struct Event {
    int unk0;
    int side;
    struct Source_func_80232F8C_de *source;
};

struct func_80232FE8_S2;
/* unbake published declaration: published_337f0b7ce7539a82159c4ff9 */
typedef struct func_80232FE8_S2 func_80232FE8_S2;

/* unbake published declaration: published_37ed4f90a3db7482e33c2ab8 */
extern float D_800C3028_de;

/* unbake published declaration: published_38a4116ff567398586433c05 */
extern float D_800C3038_de;

struct func_80232C78_S2;
/* unbake published declaration: published_3d178411fbfbaa209000a415 */
typedef struct func_80232C78_S2 func_80232C78_S2;

struct func_80232CDC_S3;
/* unbake published declaration: published_3f92d23c29b99e16db811a1f */
struct func_80232CDC_S3 {
    char pad0[0x8];
    Vec3 unk8;
    char pad8[0x62E - 0x8 - sizeof(Vec3)];
    s16 unk62E;
    char pad62E[0x6AC - 0x62E - sizeof(s16)];
    s32 unk6AC;
    char pad6AC[0x788 - 0x6AC - sizeof(s32)];
    s32 unk788;
    char pad788[0x78C - 0x788 - sizeof(s32)];
    s32 unk78C;
};

struct func_80232B54_S2;
/* unbake published declaration: published_42ce87f6a8dea4b1af6adf51 */
typedef struct func_80232B54_S2 func_80232B54_S2;

struct func_80232CDC_S3;
/* unbake published declaration: published_44b3cb793d147ec6cfcbd3c1 */
typedef struct func_80232CDC_S3 func_80232CDC_S3;

struct func_80232C78_S2;
/* unbake published declaration: published_47ff2f402da375be5d5fbeb6 */
struct func_80232C78_S2 {
    char pad0[0x62E];
    s16 unk62E;
    char pad62E[0x11C0 - 0x62E - sizeof(s16)];
    s32 unk11C0;
};

struct func_8023292C_S1;
/* unbake published declaration: published_4d7b93405705b87c20e506aa */
struct func_8023292C_S1 {
    char pad0[0xB4];
    s32 unkB4;
    char padB4[0x1D8 - 0xB4 - sizeof(s32)];
    void * unk1D8;
};

/* unbake published declaration: published_4df449b12ec16ccfa17b133c */
extern float D_800C302C_de;

/* unbake published declaration: published_51d0e31c2b6f04c4cccabf2b */
extern void func_80233314_de(void);

/* unbake published declaration: published_584aebb21ac40a2c00e74d0d */
extern void func_80232C68_de(void *arg0);

struct ObjectState134;
/* unbake published declaration: published_5fb851a1760daa8e3546f309 */
typedef struct ObjectState134 ObjectState134;

struct Player_func_802327F4_de;
/* unbake published declaration: published_61a14f7b73456c4a1f034e0a */
struct Player_func_802327F4_de {
    char pad0[0x5D4];
    int character;
    char pad5D8[4];
    void *hud;
    char pad5E0[0x62E - 0x5E0];
    short weapon;
    char pad630[0x11D8 - 0x630];
    float shield;
    char pad11DC[0x1450 - 0x11DC];
    int isBot;
};

struct func_8023292C_S3;
/* unbake published declaration: published_644c7ce7196e96aac1d74066 */
struct func_8023292C_S3 {
    char pad0[0x144];
    s32 unk144;
};

/* unbake published declaration: published_6f2f0a5e6863facf4ec6ac96 */
extern float D_800C2FC4_de;

struct ObjectState134;
/* unbake published declaration: published_6f9cf52ccb38b3c45fb573b6 */
struct ObjectState134 {
    char pad0[0x64];
    s32 unk_64;
    char pad64[0x130 - 0x64 - sizeof(s32)];
    f32 unk_130;
};

struct func_8023292C_S2;
/* unbake published declaration: published_73608969a3a01baef01f3ab0 */
struct func_8023292C_S2 {
    char pad0[0x5DC];
    void * unk5DC;
    char pad5DC[0x62E - 0x5DC - sizeof(void*)];
    s16 unk62E;
    char pad62E[0x11F8 - 0x62E - sizeof(s16)];
    s32 unk11F8;
};

/* unbake published declaration: published_750759a061055e9f3ce72c05 */
extern float D_800C301C_de;

/* unbake published declaration: published_77626fb20677fc7eb2279663 */
extern void func_802325FC_de(void *arg0, void *arg1);

/* unbake published declaration: published_783acd5acac7f417bbfe4ed7 */
extern void func_80232DF4_de(void *arg0);

/* unbake published declaration: published_8d2ea3e99aed556b5040b897 */
extern void func_802325E0_de(void);

struct func_80232CDC_S2;
/* unbake published declaration: published_8debdcf5fc7b220b94f706ac */
typedef struct func_80232CDC_S2 func_80232CDC_S2;

struct Event;
/* unbake published declaration: published_eadba07d46aa6d05eff20474 */
typedef struct Event Event;

/* unbake published declaration: published_8ea3f22ea411b0fe67318d01 */
extern void func_80233188_de(void *object, Event *event);

struct func_80232A38_S1;
/* unbake published declaration: published_9160fda2f040b48ce37ba7e5 */
typedef struct func_80232A38_S1 func_80232A38_S1;

struct func_80232B54_S2;
/* unbake published declaration: published_93ea8c96f2274f7e3d0436d7 */
struct func_80232B54_S2 {
    char pad0[0x788];
    s32 unk788;
    char pad788[0x78C - 0x788 - sizeof(s32)];
    s32 unk78C;
    char pad78C[0x794 - 0x78C - sizeof(s32)];
    s32 unk794;
};

struct func_80232BC0_S1;
/* unbake published declaration: published_95c21a86011d5b7856e654bd */
typedef struct func_80232BC0_S1 func_80232BC0_S1;

struct func_8023292C_S3;
/* unbake published declaration: published_965681d5c1480be39fc798cd */
typedef struct func_8023292C_S3 func_8023292C_S3;

struct func_80232BC0_S1;
/* unbake published declaration: published_969659f0d5e1655d122f31eb */
struct func_80232BC0_S1 {
    char pad0[0x62E];
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
    void * unk1454;
};

/* unbake published declaration: published_97e6877a74a35f2ded58e997 */
extern s32 func_802327D4_de(s32 arg0);

/* unbake published declaration: published_9f2e248e019fcff8a0f5f5eb */
extern void func_80232C88_de(void *arg0, void *arg1);

/* unbake published declaration: published_b67b1f2e963fcf99c57d42c9 */
extern void func_80232F8C_de(void *obj, Event *event);

/* unbake published declaration: published_bae3bf471ed029f927c37f2d */
extern float D_800C3020_de;

struct func_8023292C_S2;
/* unbake published declaration: published_bbcb7b5d2344313fa297d7d0 */
typedef struct func_8023292C_S2 func_8023292C_S2;

struct func_80232B54_S3;
/* unbake published declaration: published_bc8b11826971c5ce2ae39b6a */
typedef struct func_80232B54_S3 func_80232B54_S3;

/* unbake published declaration: published_c13b78f45f0f4c1e1f2cf2fb */
extern void func_80232E38_de(void *arg0);

/* unbake published declaration: published_c64e23832cf3302d79b74a15 */
extern void func_802330AC_de(void *arg0, void *arg1);

/* unbake published declaration: published_cc83f24c759b82850f4aca4e */
extern float D_800C8100;

struct func_8023292C_S1;
/* unbake published declaration: published_daea86442eeb93eaa6573bc1 */
typedef struct func_8023292C_S1 func_8023292C_S1;

/* unbake published declaration: published_dd7ef6e462b0a4484ca4f089 */
extern float D_800C8130;

struct ObjectState140;
/* unbake published declaration: published_ded5e0792b7e89b84a147ce4 */
struct ObjectState140 {
    char pad0[0x64];
    f32 unk_64;
    char pad64[0x130 - 0x64 - sizeof(f32)];
    f32 unk_130;
    char pad130[0x13C - 0x130 - sizeof(f32)];
    s32 unk_13C;
};

/* unbake published declaration: published_e8e714ff0e84850dfe6bbd70 */
extern s32 func_80232780_de(s32 arg0);

struct func_80232FE8_S2;
/* unbake published declaration: published_e9568d547a9375c682709297 */
struct func_80232FE8_S2 {
    char pad0[0x62E];
    s16 unk62E;
    char pad62E[0x650 - 0x62E - sizeof(s16)];
    s16 unk650;
    char pad650[0x770 - 0x650 - sizeof(s16)];
    s16 unk770;
};

struct func_80232CDC_S2;
/* unbake published declaration: published_f663bfc25651ac798e5cfcba */
struct func_80232CDC_S2 {
    char pad0[0x35];
    s8 unk35;
    char pad35[0xCB - 0x35 - sizeof(s8)];
    s8 unkCB;
};

/* unbake published declaration: published_fb1fb41bbb968506add593fc */
extern void func_8023293C_de(void *arg0, void *arg1, void *arg2);

/* unbake published declaration: published_fdedd08fa12de135d3c069fc */
extern float D_800C2FC8_de;

#endif
