#ifndef UNBAKE_SPAN_1000_CODE_80213ED4_H
#define UNBAKE_SPAN_1000_CODE_80213ED4_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
struct Field_Vec_B0;
/* unbake published declaration: published_00a70eb2f18933755a890481 */
typedef struct Field_Vec_B0 Field_Vec_B0;

struct Field_void_68;
/* unbake published declaration: published_038d6a63e6fffc5a84098d61 */
struct Field_void_68 {
    char pad[0x68];
    void * value;
};

struct func_802169AC_S4;
/* unbake published declaration: published_044bf6c44cd5697c37dd7dbd */
typedef struct func_802169AC_S4 func_802169AC_S4;

struct func_80216F44_S1;
/* unbake published declaration: published_04b34993c597bb636315980d */
typedef struct func_80216F44_S1 func_80216F44_S1;

struct Field_s32_788;
/* unbake published declaration: published_077d7ed49320342913f89854 */
typedef struct Field_s32_788 Field_s32_788;

struct func_802169AC_S3;
/* unbake published declaration: published_089ff31589e4990651cdba34 */
typedef struct func_802169AC_S3 func_802169AC_S3;

struct TrackResult;
/* unbake published declaration: published_0f1ff02eb82b49d7556186c0 */
typedef struct TrackResult TrackResult;

struct func_80216F44_S1;
/* unbake published declaration: published_0f8f23fe12b8936c1ab577ce */
struct func_80216F44_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x6C - 0x10 - sizeof(f32)];
    f32 unk6C;
};

struct func_802172D0_S3;
/* unbake published declaration: published_1012d6e3f88578ef91e242c3 */
struct func_802172D0_S3 {
    char pad0[0x8];
    char unk8;
    char pad8[0xD0 - 0x8 - sizeof(char)];
    void * unkD0;
};

struct func_802169AC_S4;
/* unbake published declaration: published_18d4b15adda532f36b71838b */
struct func_802169AC_S4 {
    char pad0[0xE4];
    u16 unkE4;
    char padE4[0x2E0 - 0xE4 - sizeof(u16)];
    s32 unk2E0;
};

/* unbake published declaration: published_1c2f5ac19591f2cbf5f77554 */
extern float D_800C21DC_de;

struct Actor_func_80214DD4_de;
/* unbake published declaration: published_220b909b7ac5e4ce93f24b66 */
typedef struct Actor_func_80214DD4_de Actor_func_80214DD4_de;

/* unbake published declaration: published_245699faeb32fa0456df511c */
extern float D_800C2170_de;

struct AudioStateA4;
/* unbake published declaration: published_24f77e2051f82d5dce570b6e */
struct AudioStateA4 {
    char pad0[0x98];
    s32 field98;
    char pad9C[4];
    s32 fieldA0;
};

struct Source_func_802164A8_de;
/* unbake published declaration: published_27aaed62669b0432c49081ba */
struct Source_func_802164A8_de {
    char pad0[8];
    Triple position;
    char pad14[4];
    s32 *kind;
    char pad1c[0x50];
    f32 height;
    char pad70[0x90];
    s32 flags;
    char pad104[0x98];
    s32 active;
};

struct CActor_t;
/* unbake published declaration: published_28147ac65171ef8c99f4c0d0 */
typedef struct CActor_t CActor_t;

struct Actor_func_80214DD4_de;
struct TrackResult;
/* unbake published declaration: published_2b49f34172cbedcc9b15432a */
struct TrackResult {
    s32 kind;
    struct Actor_func_80214DD4_de *target;
    f32 range;
    Vec3 pos;
    Vec3 delta;
    f32 dist;
    Vec3 flatPos;
    Vec3 flatDelta;
    f32 flatDist;
};

struct Field_Vec_34;
/* unbake published declaration: published_3236d2aa112a840a121a8e0f */
struct Field_Vec_34 {
    char pad[0x34];
    Vec3 value;
};

struct Field_f32_9C;
/* unbake published declaration: published_32706ae99f58664919fe09a2 */
struct Field_f32_9C {
    char pad[0x9C];
    f32 value;
};

struct Field_void_68;
/* unbake published declaration: published_3a5c8e57bfb06c5663005a61 */
typedef struct Field_void_68 Field_void_68;

struct Field_Vec_C;
/* unbake published declaration: published_3bff6ac9a3d8d7284f81f387 */
typedef struct Field_Vec_C Field_Vec_C;

struct Field_f32_24;
/* unbake published declaration: published_3dd2819092614e1563af472c */
typedef struct Field_f32_24 Field_f32_24;

struct AudioStateA4;
/* unbake published declaration: published_3ef4f32a583d06d2b996f143 */
typedef struct AudioStateA4 AudioStateA4;

struct Result_func_802165F8_de;
/* unbake published declaration: published_403e7a64a1abcee347e37039 */
struct Result_func_802165F8_de {
    Vec3 first;
    Vec3 first_normalized;
    f32 first_length;
    Vec3 flat;
    Vec3 flat_normalized;
    f32 flat_length;
    f32 height;
};

struct Func802172C4Value;
/* unbake published declaration: published_433130731a92760ee1a8c308 */
typedef struct Func802172C4Value Func802172C4Value;

struct Picker;
/* unbake published declaration: published_4377128f3f1d78341915db95 */
typedef struct Picker Picker;

struct ObjectLinks1230;
/* unbake published declaration: published_45f12c5c076813e84477797a */
struct ObjectLinks1230 {
    char pad0[0x100];
    u32 unk_100;
    char pad100[0x5D8 - 0x100 - sizeof(u32)];
    char * unk_5D8;
    char pad5D8[0x122C - 0x5D8 - sizeof(char*)];
    u32 unk_122C;
};

struct Vec3_func_802168B8_de;
/* unbake published declaration: published_49ee22cbf5d9213173910cd2 */
struct Vec3_func_802168B8_de {
    s32 unk0;
    s32 unk4;
    f32 x;
    f32 y;
    f32 z;
};

struct Field_Vec_34;
/* unbake published declaration: published_4ced375fcf8f9b1dd4796104 */
typedef struct Field_Vec_34 Field_Vec_34;

struct func_802169AC_S1;
/* unbake published declaration: published_58222eda972369c204282c2f */
struct func_802169AC_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x68 - 0x4 - sizeof(s32)];
    void * unk68;
    char pad68[0x94 - 0x68 - sizeof(void*)];
    s8 unk94;
};

/* unbake published declaration: published_596cfedde9104eb933d1b5b2 */
extern float D_800C21C8_de;

struct func_80216A6C_S1;
/* unbake published declaration: published_6387ddfcc90f460c4f4528ca */
typedef struct func_80216A6C_S1 func_80216A6C_S1;

struct Field_Vec_0;
/* unbake published declaration: published_64bfb5927189375b0974bde4 */
struct Field_Vec_0 {
    Vec3 value;
};

/* unbake published declaration: published_6b53c8d39f53e43e4cfc7703 */
extern float D_800C2174_de;

struct Dest_func_802164A8_de;
/* unbake published declaration: published_6c1055b0ac525b78771998b0 */
typedef struct Dest_func_802164A8_de Dest_func_802164A8_de;

struct CActor_t;
/* unbake published declaration: published_6ef2d7bd03c3974dffc47099 */
struct CActor_t {
    u8 type;
    u8 pad001[0x1B];
    Vec3 position;
    u8 pad028[0xBC];
    u16 objectId;
    u8 pad0E6[0x10A];
    s32 eventValue;
    u8 pad1F4[0xA8];
    s32 eventCount;
};

/* unbake published declaration: published_735df06e63c06ebef873e38b */
extern void func_802171BC_de(int *value, int word);

struct Field_f32_24;
/* unbake published declaration: published_7713ff46cd6df17aede98727 */
struct Field_f32_24 {
    char pad[0x24];
    f32 value;
};

struct Func802172C4Value;
/* unbake published declaration: published_782af9c5726b7dd99d0ba4fe */
struct Func802172C4Value {
    int words[2];
};

struct Source_func_802164A8_de;
/* unbake published declaration: published_7894b7a8b2aa4c86d833f1c0 */
typedef struct Source_func_802164A8_de Source_func_802164A8_de;

struct func_80216D3C_S2;
/* unbake published declaration: published_820864e0937ca07bc2c2e611 */
struct func_80216D3C_S2 {
    char pad0[0x44];
    Output80216D3C unk44;
};

struct Field_f32_9C;
/* unbake published declaration: published_8243cc250db291df12883874 */
typedef struct Field_f32_9C Field_f32_9C;

struct func_802165F8_S2;
/* unbake published declaration: published_841194aaf38806d255ba3f6c */
typedef struct func_802165F8_S2 func_802165F8_S2;

struct Location;
/* unbake published declaration: published_84d8fc3a3cf90514844bcc79 */
struct Location {
    Vec3 pos;
    s32 room;
};

struct func_80216D3C_S2;
/* unbake published declaration: published_86cb6f876a5b8a7007b4f111 */
typedef struct func_80216D3C_S2 func_80216D3C_S2;

struct func_80216D30_S1;
/* unbake published declaration: published_89657f4d1998492b17bc5d3e */
struct func_80216D30_S1 {
    char pad0[0x78];
    int unk78;
    char pad78[0x7C - 0x78 - sizeof(int)];
    int unk7C;
};

struct func_802169AC_S3;
/* unbake published declaration: published_89c94296312eec4dab79b016 */
struct func_802169AC_S3 {
    char pad0[0x788];
    s32 unk788;
    char pad788[0x794 - 0x788 - sizeof(s32)];
    void * unk794;
};

struct Field_Vec_28;
/* unbake published declaration: published_8abf75bd0c6c9c1ac2c4d7f6 */
typedef struct Field_Vec_28 Field_Vec_28;

/* unbake published declaration: published_8cd7680e729458610f1638f9 */
extern void func_802172C4_de(void *arg0, void *arg1, Func802172C4Value arg2);

struct Field_s32_788;
/* unbake published declaration: published_91c05dbcc6636de850c5869b */
struct Field_s32_788 {
    char pad[0x788];
    s32 value;
};

struct Tracker;
/* unbake published declaration: published_94409c3fdbfab3f5ba96c9f0 */
typedef struct Tracker Tracker;

struct func_80216D30_S1;
/* unbake published declaration: published_971373f21b82f989ecb10df9 */
typedef struct func_80216D30_S1 func_80216D30_S1;

struct Field_Vec_28;
/* unbake published declaration: published_9832257fb2ec8657e15488e0 */
struct Field_Vec_28 {
    char pad[0x28];
    Vec3 value;
};

struct Field_void_794;
/* unbake published declaration: published_9a324383675be8b82149dd2a */
typedef struct Field_void_794 Field_void_794;

/* unbake published declaration: published_9c0ca14669e28d53162e1aec */
extern float D_800C21CC_de;

struct Field_void_88;
/* unbake published declaration: published_9d66c8769a2c675bc204793b */
struct Field_void_88 {
    char pad[0x88];
    void * value;
};

struct func_802172D0_S1;
/* unbake published declaration: published_a1036c58f3b68592fb829cc6 */
struct func_802172D0_S1 {
    char pad0[0xFC];
    void * unkFC;
};

struct Cursor802171C8;
/* unbake published declaration: published_dc0eba4d1402d449cc4141b5 */
typedef struct Cursor802171C8 Cursor802171C8;

struct Cursor802171C8;
/* unbake published declaration: published_ea048968fde104626a2b476c */
struct Cursor802171C8 {
    void *base;
    u16 *cur;
};

/* unbake published declaration: published_a125f8b68423a1acf3b35466 */
extern s16 func_802171C8_de(Cursor802171C8 *arg0);

/* unbake published declaration: published_a15ba52b67b58abc273ee04b */
extern void func_80216D30_de(void *arg0, void *arg1, int arg2, int arg3);

struct func_802169AC_S1;
/* unbake published declaration: published_a3713d6ff2075279ac94bfb8 */
typedef struct func_802169AC_S1 func_802169AC_S1;

/* unbake published declaration: published_a47eee0ead2b4a974ebd691a */
extern float D_800C21E4_de;

struct Location;
/* unbake published declaration: published_a5af071c8103941ae77131f8 */
typedef struct Location Location;

/* unbake published declaration: published_a62405aa0ae453733c8ceba6 */
extern s32 func_802169AC_de(void *arg0, void *arg1, void *arg2);

struct func_802172D0_S1;
/* unbake published declaration: published_a8902cd868406acade640873 */
typedef struct func_802172D0_S1 func_802172D0_S1;

struct Field_Vec_B0;
/* unbake published declaration: published_a8ee024ee6e9c622a1061d9a */
struct Field_Vec_B0 {
    char pad[0xB0];
    Vec3 value;
};

struct func_802169AC_S2;
/* unbake published declaration: published_a98b8c69d3fa378806aa68a6 */
typedef struct func_802169AC_S2 func_802169AC_S2;

struct Vec3_func_802168B8_de;
/* unbake published declaration: published_ab52d44fe2d7fe855b79800f */
typedef struct Vec3_func_802168B8_de Vec3_func_802168B8_de;

struct func_80216A6C_S1;
/* unbake published declaration: published_acb4508c90a8a2228bd0da09 */
struct func_80216A6C_S1 {
    char pad0[0xC];
    f32 unkC;
    char padC[0x70 - 0xC - sizeof(f32)];
    f32 unk70;
};

struct Actor_func_80214DD4_de;
struct Tracker;
/* unbake published declaration: published_afbb8e79c1cfe9c7a2df8608 */
struct Tracker {
    s32 flags;
    s32 active;
    u8 pad8[0x60];
    struct Actor_func_80214DD4_de *self;
    Vec3 offset;
    s32 unk78;
    u8 pad7C[4];
    struct Actor_func_80214DD4_de *anchor;
    u8 pad84[4];
    struct Actor_func_80214DD4_de *target;
    f32 angle;
    f32 height;
    s8 slot;
    u8 pad95[0x1B];
    Vec3 homePos;
    s32 homeRoom;
    u8 padC0[0xE];
    s8 team;
};

/* unbake published declaration: published_b0058167eb1e859902d7c309 */
extern float D_800C2178_de;

/* unbake published declaration: published_b2e67e8d89f7ea24c22a694e */
extern const float D_800C216C_de;

struct Field_void_88;
/* unbake published declaration: published_b87d4af4d38e94a8c7069512 */
typedef struct Field_void_88 Field_void_88;

struct Picker;
/* unbake published declaration: published_b92e4d4c8714695233c15d0e */
struct Picker {
    s16 count;
    char pad[0x66];
};

struct Field_void_794;
/* unbake published declaration: published_c16e9d15d56ce31020f85fb4 */
struct Field_void_794 {
    char pad[0x794];
    void * value;
};

struct func_802165F8_S2;
/* unbake published declaration: published_c2a70fefb11d3b4d85cd591c */
struct func_802165F8_S2 {
    char pad0[0x48];
    Vec3 unk48;
    char pad48[0x60 - 0x48 - sizeof(Vec3)];
    f32 unk60;
};

struct Field_s8_94;
/* unbake published declaration: published_caabd95f3156b683abafddfc */
struct Field_s8_94 {
    char pad[0x94];
    s8 value;
};

struct Field_s8_94;
/* unbake published declaration: published_cbefbafe6ab5978dd64944d1 */
typedef struct Field_s8_94 Field_s8_94;

struct func_80216D3C_S1;
/* unbake published declaration: published_cdac0c5fe263d21e8daebbe9 */
typedef struct func_80216D3C_S1 func_80216D3C_S1;

struct func_802172D0_S3;
/* unbake published declaration: published_d1102181d743d3563d01c2d8 */
typedef struct func_802172D0_S3 func_802172D0_S3;

struct Dest_func_802164A8_de;
/* unbake published declaration: published_d77910ed03a78ef1d0e4c95f */
struct Dest_func_802164A8_de {
    char pad0[0x40];
    f32 value;
    char pad44[4];
    Triple old_position;
    Triple position;
    f32 height;
    char pad64[0x69];
    u8 timer;
    char padce[0x2E];
    func_80205628_S3 *aux;
    char pad100[8];
    void (*callback)(Source_func_802164A8_de *, struct Dest_func_802164A8_de *);
};

struct Field_s8_CE;
/* unbake published declaration: published_dbb1c58e63ced8f84b48d49a */
struct Field_s8_CE {
    char pad[0xCE];
    s8 value;
};

struct func_802169AC_S2;
/* unbake published declaration: published_e2351aa58c217ee834667336 */
struct func_802169AC_S2 {
    char pad0[0x18];
    s32 * unk18;
    char pad18[0xE4 - 0x18 - sizeof(s32*)];
    u16 unkE4;
    char padE4[0x100 - 0xE4 - sizeof(u16)];
    s32 unk100;
    char pad100[0x1D8 - 0x100 - sizeof(s32)];
    void * unk1D8;
};

struct Field_Vec_C;
/* unbake published declaration: published_eb20126c129585f89eb1454c */
struct Field_Vec_C {
    char pad[0xC];
    Vec3 value;
};

struct ObjectLinks1230;
/* unbake published declaration: published_ed78684135e71fa200a4951a */
typedef struct ObjectLinks1230 ObjectLinks1230;

struct Result_func_802165F8_de;
/* unbake published declaration: published_efa17d5cdc26ff7d1ec5b9db */
typedef struct Result_func_802165F8_de Result_func_802165F8_de;

struct Field_Vec_0;
/* unbake published declaration: published_f2c0fd31a75c74ba27b63a76 */
typedef struct Field_Vec_0 Field_Vec_0;

struct Field_s8_CE;
/* unbake published declaration: published_f3cd6b68ed6392d16fdd0aa3 */
typedef struct Field_s8_CE Field_s8_CE;

struct func_80216D3C_S1;
/* unbake published declaration: published_f6b6d829b249d35053fa5484 */
struct func_80216D3C_S1 {
    char pad0[0x78];
    s32 unk78;
    char pad78[0x7C - 0x78 - sizeof(s32)];
    f32 unk7C;
    char pad7C[0x80 - 0x7C - sizeof(f32)];
    s32 unk80;
    char pad80[0x88 - 0x80 - sizeof(s32)];
    s32 unk88;
};

#endif
