#ifndef RW_GAMEPLAY_ROUND_RULES_H
#define RW_GAMEPLAY_ROUND_RULES_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "shared/func_80425674_de_layout.h"
/* Complete shared records retained from origin/legacy func_80227014.c and its shared headers. */
typedef struct Shared_func_80227014_S1 Shared_func_80227014_S1;
struct Shared_func_80227014_S1 {
    char pad0[0x1C];
    s32 unk1C; /* +0x1C: src/func_80227014.c */
    char pad20[0x34];
    s32 unk54; /* +0x54: src/func_80227014.c */
    char pad58[0x4];
    s32 unk5C; /* +0x5C: src/func_80227014.c */
    s32 unk60; /* +0x60: src/func_80227014.c */
    s32 unk64; /* +0x64: src/func_80227014.c */
    s32 unk68; /* +0x68: src/func_80227014.c */
    s32 unk6C; /* +0x6C: src/func_80227014.c */
    char pad70[0x4];
    s32 unk74; /* +0x74: src/func_80227014.c */
    char pad78[0x98 - 0x78];
    s32 unk98; /* +0x98: origin/legacy func_80286A78.c, Shared_func_80286A78_S4. */
};
typedef char Shared_func_80227014_S1_size_check[(sizeof(Shared_func_80227014_S1) == 0x9C) ? 1 : -1];


typedef struct Shared_func_80227014_S2 Shared_func_80227014_S2;
struct Shared_func_80227014_S2 {
    char pad0[0x8];
    Vec3 position; /* +0x8: actor position, shared player provider and sound Vec3 argument. */
    char pad14[0x4];
    struct Shared_func_80227014_S7 * unk18; /* +0x18: src/func_80227014.c */
    char pad1C[0x158];
    s32 unk174; /* +0x174: src/func_80227014.c */
    char pad178[0x170];
    s8 unk2E8; /* +0x2E8: src/func_80227014.c */
    char pad2E9[0x16F];
    s8 unk458; /* +0x458: src/func_80227014.c */
    char pad459[0x17B];
    s32 unk5D4; /* +0x5D4: src/func_80227014.c */
    struct Shared_func_80227014_S6 * unk5D8; /* +0x5D8: src/func_80227014.c */
    void * unk5DC; /* +0x5DC: src/func_80227014.c */
    char pad5E0[0x4];
    s32 unk5E4; /* +0x5E4: src/func_80227014.c */
    char pad5E8[0x4];
    s32 unk5EC; /* +0x5EC: src/func_80227014.c */
    char pad5F0[0x348];
    char unk938[2172]; /* +0x938: src/func_80227014.c */
    s32 unk11B4; /* +0x11B4: src/func_80227014.c */
    char pad11B8[0x298];
    s32 unk1450; /* +0x1450: src/func_80227014.c */
};
typedef char Shared_func_80227014_S2_size_check[(sizeof(Shared_func_80227014_S2) == 0x1454) ? 1 : -1];


typedef struct Shared_func_80227014_S3 Shared_func_80227014_S3;
struct Shared_func_80227014_S3 {
    char pad0[0x80];
    s8 unk80; /* +0x80: src/func_80227014.c */
    char pad81[0xF];
    u8 unk90; /* +0x90: src/func_80227014.c */
    char pad91[0x3];
    u8 unk94; /* +0x94: src/func_80227014.c */
};
typedef char Shared_func_80227014_S3_size_check[(sizeof(Shared_func_80227014_S3) == 0x95) ? 1 : -1];


typedef struct Shared_func_80227014_S4 Shared_func_80227014_S4;
struct Shared_func_80227014_S4 {
    char pad0[0x29C];
    f32 unk29C; /* +0x29C: src/func_80227014.c */
    f32 unk2A0; /* +0x2A0: src/func_80227014.c */
    f32 unk2A4; /* +0x2A4: src/func_80227014.c */
    f32 unk2A8; /* +0x2A8: src/func_80227014.c */
    char pad2AC[0x2B8];
    s32 unk564; /* +0x564: src/func_80227014.c */
};
typedef char Shared_func_80227014_S4_size_check[(sizeof(Shared_func_80227014_S4) == 0x568) ? 1 : -1];


typedef struct Shared_func_80227014_S5 Shared_func_80227014_S5;
struct Shared_func_80227014_S5 {
    s32 unk0; /* +0x0: src/func_80227014.c */
    s32 unk4; /* +0x4: src/func_80227014.c */
};
typedef char Shared_func_80227014_S5_size_check[(sizeof(Shared_func_80227014_S5) == 0x8) ? 1 : -1];


typedef struct Shared_func_80227014_S6 Shared_func_80227014_S6;
struct Shared_func_80227014_S6 {
    char pad0[0x8F];
    s8 unk8F; /* +0x8F: src/func_80227014.c */
};
typedef char Shared_func_80227014_S6_size_check[(sizeof(Shared_func_80227014_S6) == 0x90) ? 1 : -1];


typedef struct Shared_func_80227014_S7 Shared_func_80227014_S7;
struct Shared_func_80227014_S7 {
    char pad0[0x18];
    s32 unk18; /* +0x18: src/func_80227014.c */
};
typedef char Shared_func_80227014_S7_size_check[(sizeof(Shared_func_80227014_S7) == 0x1C) ? 1 : -1];


typedef struct Shared_func_80227014_S8 Shared_func_80227014_S8;
struct Shared_func_80227014_S8 {
    char pad0[0x8];
    Vec3 position; /* +0x8: actor position, shared player provider and sound Vec3 argument. */
    char pad14[0x4];
    struct Shared_func_80227014_S12 * unk18; /* +0x18: src/func_80227014.c */
    char pad1C[0x158];
    s32 unk174; /* +0x174: src/func_80227014.c */
    char pad178[0x170];
    s8 unk2E8; /* +0x2E8: src/func_80227014.c */
    char pad2E9[0x16F];
    s8 unk458; /* +0x458: src/func_80227014.c */
    char pad459[0x17B];
    s32 unk5D4; /* +0x5D4: src/func_80227014.c */
    struct Shared_func_80227014_S10 * unk5D8; /* +0x5D8: src/func_80227014.c */
    void * unk5DC; /* +0x5DC: src/func_80227014.c */
    char pad5E0[0x4];
    s32 unk5E4; /* +0x5E4: src/func_80227014.c */
    char pad5E8[0x4];
    s32 unk5EC; /* +0x5EC: src/func_80227014.c */
    char pad5F0[0x348];
    char unk938[2172]; /* +0x938: src/func_80227014.c */
    s32 unk11B4; /* +0x11B4: src/func_80227014.c */
    char pad11B8[0x298];
    s32 unk1450; /* +0x1450: src/func_80227014.c */
};
typedef char Shared_func_80227014_S8_size_check[(sizeof(Shared_func_80227014_S8) == 0x1454) ? 1 : -1];


typedef struct Shared_func_80227014_S9 Shared_func_80227014_S9;
struct Shared_func_80227014_S9 {
    char pad0[0x29C];
    f32 unk29C; /* +0x29C: src/func_80227014.c */
    f32 unk2A0; /* +0x2A0: src/func_80227014.c */
    f32 unk2A4; /* +0x2A4: src/func_80227014.c */
    f32 unk2A8; /* +0x2A8: src/func_80227014.c */
    char pad2AC[0x2B8];
    s32 unk564; /* +0x564: src/func_80227014.c */
};
typedef char Shared_func_80227014_S9_size_check[(sizeof(Shared_func_80227014_S9) == 0x568) ? 1 : -1];


typedef struct Shared_func_80227014_S10 Shared_func_80227014_S10;
struct Shared_func_80227014_S10 {
    char pad0[0x8F];
    u8 unk8F; /* +0x8F: src/func_80227014.c */
};
typedef char Shared_func_80227014_S10_size_check[(sizeof(Shared_func_80227014_S10) == 0x90) ? 1 : -1];


typedef struct Shared_func_80227014_S11 Shared_func_80227014_S11;
struct Shared_func_80227014_S11 {
    char pad0[0x80];
    s8 unk80; /* +0x80: src/func_80227014.c */
    char pad81[0xE];
    u8 unk8F; /* +0x8F: src/func_80227014.c */
    char pad90[0x4];
    u8 unk94; /* +0x94: src/func_80227014.c */
};
typedef char Shared_func_80227014_S11_size_check[(sizeof(Shared_func_80227014_S11) == 0x95) ? 1 : -1];


typedef struct Shared_func_80227014_S12 Shared_func_80227014_S12;
struct Shared_func_80227014_S12 {
    char pad0[0x18];
    s32 unk18; /* +0x18: src/func_80227014.c */
};
typedef char Shared_func_80227014_S12_size_check[(sizeof(Shared_func_80227014_S12) == 0x1C) ? 1 : -1];


typedef struct Shared_func_80227014_S13 Shared_func_80227014_S13;
struct Shared_func_80227014_S13 {
    char pad0[0x8];
    Vec3 position; /* +0x8: actor position, shared player provider and sound Vec3 argument. */
    char pad14[0x4];
    struct Shared_func_80227014_S17 * unk18; /* +0x18: src/func_80227014.c */
    char pad1C[0x158];
    s32 unk174; /* +0x174: src/func_80227014.c */
    char pad178[0x170];
    s8 unk2E8; /* +0x2E8: src/func_80227014.c */
    char pad2E9[0x16F];
    s8 unk458; /* +0x458: src/func_80227014.c */
    char pad459[0x17B];
    s32 unk5D4; /* +0x5D4: src/func_80227014.c */
    struct Shared_func_80227014_S15 * unk5D8; /* +0x5D8: src/func_80227014.c */
    void * unk5DC; /* +0x5DC: src/func_80227014.c */
    char pad5E0[0x4];
    s32 unk5E4; /* +0x5E4: src/func_80227014.c */
    char pad5E8[0x4];
    s32 unk5EC; /* +0x5EC: src/func_80227014.c */
    char pad5F0[0x348];
    char unk938[2172]; /* +0x938: src/func_80227014.c */
    s32 unk11B4; /* +0x11B4: src/func_80227014.c */
    char pad11B8[0x298];
    s32 unk1450; /* +0x1450: src/func_80227014.c */
};
typedef char Shared_func_80227014_S13_size_check[(sizeof(Shared_func_80227014_S13) == 0x1454) ? 1 : -1];


typedef struct Shared_func_80227014_S14 Shared_func_80227014_S14;
struct Shared_func_80227014_S14 {
    char pad0[0x29C];
    f32 unk29C; /* +0x29C: src/func_80227014.c */
    f32 unk2A0; /* +0x2A0: src/func_80227014.c */
    f32 unk2A4; /* +0x2A4: src/func_80227014.c */
    f32 unk2A8; /* +0x2A8: src/func_80227014.c */
    char pad2AC[0x2B8];
    s32 unk564; /* +0x564: src/func_80227014.c */
};
typedef char Shared_func_80227014_S14_size_check[(sizeof(Shared_func_80227014_S14) == 0x568) ? 1 : -1];


typedef struct Shared_func_80227014_S15 Shared_func_80227014_S15;
struct Shared_func_80227014_S15 {
    char pad0[0x8F];
    u8 unk8F; /* +0x8F: src/func_80227014.c */
};
typedef char Shared_func_80227014_S15_size_check[(sizeof(Shared_func_80227014_S15) == 0x90) ? 1 : -1];


typedef struct Shared_func_80227014_S16 Shared_func_80227014_S16;
struct Shared_func_80227014_S16 {
    char pad0[0x80];
    s8 unk80; /* +0x80: src/func_80227014.c */
    char pad81[0xE];
    u8 unk8F; /* +0x8F: src/func_80227014.c */
    char pad90[0x4];
    u8 unk94; /* +0x94: src/func_80227014.c */
};
typedef char Shared_func_80227014_S16_size_check[(sizeof(Shared_func_80227014_S16) == 0x95) ? 1 : -1];


typedef struct Shared_func_80227014_S17 Shared_func_80227014_S17;
struct Shared_func_80227014_S17 {
    char pad0[0x18];
    s32 unk18; /* +0x18: src/func_80227014.c */
};
typedef char Shared_func_80227014_S17_size_check[(sizeof(Shared_func_80227014_S17) == 0x1C) ? 1 : -1];


typedef struct Shared_func_80227014_S18 Shared_func_80227014_S18;
struct Shared_func_80227014_S18 {
    char pad0[0x8];
    Vec3 position; /* +0x8: actor position, shared player provider and sound Vec3 argument. */
    char pad14[0x4];
    struct Shared_func_80227014_S23 * unk18; /* +0x18: src/func_80227014.c */
    char pad1C[0x158];
    s32 unk174; /* +0x174: src/func_80227014.c */
    char pad178[0x170];
    s8 unk2E8; /* +0x2E8: src/func_80227014.c */
    char pad2E9[0x16F];
    s8 unk458; /* +0x458: src/func_80227014.c */
    char pad459[0x17B];
    s32 unk5D4; /* +0x5D4: src/func_80227014.c */
    struct Shared_func_80227014_S21 * unk5D8; /* +0x5D8: src/func_80227014.c */
    void * unk5DC; /* +0x5DC: src/func_80227014.c */
    char pad5E0[0x4];
    s32 unk5E4; /* +0x5E4: src/func_80227014.c */
    char pad5E8[0x4];
    s32 unk5EC; /* +0x5EC: src/func_80227014.c */
    char pad5F0[0x348];
    char unk938[2172]; /* +0x938: src/func_80227014.c */
    s32 unk11B4; /* +0x11B4: src/func_80227014.c */
    char pad11B8[0x298];
    s32 unk1450; /* +0x1450: src/func_80227014.c */
};
typedef char Shared_func_80227014_S18_size_check[(sizeof(Shared_func_80227014_S18) == 0x1454) ? 1 : -1];


typedef struct Shared_func_80227014_S19 Shared_func_80227014_S19;
struct Shared_func_80227014_S19 {
    char pad0[0x8F];
    u8 unk8F; /* +0x8F: src/func_80227014.c */
    s8 unk90; /* +0x90: src/func_80227014.c */
};
typedef char Shared_func_80227014_S19_size_check[(sizeof(Shared_func_80227014_S19) == 0x91) ? 1 : -1];


typedef struct Shared_func_80227014_S20 Shared_func_80227014_S20;
struct Shared_func_80227014_S20 {
    char pad0[0x29C];
    f32 unk29C; /* +0x29C: src/func_80227014.c */
    f32 unk2A0; /* +0x2A0: src/func_80227014.c */
    f32 unk2A4; /* +0x2A4: src/func_80227014.c */
    f32 unk2A8; /* +0x2A8: src/func_80227014.c */
    char pad2AC[0x2B8];
    s32 unk564; /* +0x564: src/func_80227014.c */
};
typedef char Shared_func_80227014_S20_size_check[(sizeof(Shared_func_80227014_S20) == 0x568) ? 1 : -1];


typedef struct Shared_func_80227014_S21 Shared_func_80227014_S21;
struct Shared_func_80227014_S21 {
    char pad0[0x8F];
    u8 unk8F; /* +0x8F: src/func_80227014.c */
};
typedef char Shared_func_80227014_S21_size_check[(sizeof(Shared_func_80227014_S21) == 0x90) ? 1 : -1];


typedef struct Shared_func_80227014_S22 Shared_func_80227014_S22;
struct Shared_func_80227014_S22 {
    char pad0[0x80];
    s8 unk80; /* +0x80: src/func_80227014.c */
    char pad81[0xE];
    u8 unk8F; /* +0x8F: src/func_80227014.c */
    char pad90[0x4];
    u8 unk94; /* +0x94: src/func_80227014.c */
};
typedef char Shared_func_80227014_S22_size_check[(sizeof(Shared_func_80227014_S22) == 0x95) ? 1 : -1];


typedef struct Shared_func_80227014_S23 Shared_func_80227014_S23;
struct Shared_func_80227014_S23 {
    char pad0[0x18];
    s32 unk18; /* +0x18: src/func_80227014.c */
};
typedef char Shared_func_80227014_S23_size_check[(sizeof(Shared_func_80227014_S23) == 0x1C) ? 1 : -1];


typedef struct Shared_Entry190 Shared_Entry190;
struct Shared_Entry190 {
    s32 value; /* +0x0: src/func_80227014.c */
    u8 pad[396]; /* +0x4: src/func_80227014.c */
};
typedef char Shared_Entry190_size_check[(sizeof(Shared_Entry190) == 0x190) ? 1 : -1];


#endif
