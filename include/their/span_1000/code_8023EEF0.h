#ifndef UNBAKE_SPAN_1000_CODE_8023EEF0_H
#define UNBAKE_SPAN_1000_CODE_8023EEF0_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_0c1156dcdba08c13c63530cf */
extern int func_80240638_de(void *left, void *right);

struct func_80240C7C_S1;
/* unbake published declaration: published_1176935dcc439e1287db801f */
struct func_80240C7C_S1 {
    s32 unk0;
    char pad0[0x54 - 0x0 - sizeof(s32)];
    s32 unk54;
    char pad54[0x58 - 0x54 - sizeof(s32)];
    s32 unk58;
    char pad58[0xCC - 0x58 - sizeof(s32)];
    f32 unkCC;
};

/* unbake published declaration: published_13f7aee92c26b86e020b61d0 */
extern s32 func_80240698_de(void *arg0, s32 arg1, Triple t, s32 arg5, s32 arg6, void *arg7);

struct Plane;
/* unbake published declaration: published_233f7ddff91d9914d0acd545 */
typedef struct Plane Plane;

struct func_80240C9C_S1;
/* unbake published declaration: published_251d080130524641b8039547 */
struct func_80240C9C_S1 {
    char pad0[0x18];
    Vec3 unk18;
    char pad18[0x24 - 0x18 - sizeof(Vec3)];
    Vec3 unk24;
    char pad24[0x30 - 0x24 - sizeof(Vec3)];
    Vec3 unk30;
    char pad30[0x48 - 0x30 - sizeof(Vec3)];
    Vec3 unk48;
};

struct EntityTable;
/* unbake published declaration: published_4b8d51c9cd61ab772ede8613 */
struct EntityTable {
    char pad0[0x144];
    u8 *entities[0x200];
    s32 count;
};

struct func_8023F634_S1;
/* unbake published declaration: published_4c014920dc823768b55f8daf */
typedef struct func_8023F634_S1 func_8023F634_S1;

/* unbake published declaration: published_4d7ca6d43df74c779b844005 */
extern void func_80240538_de(float *s, float *d);

struct Shape;
struct func_8023F42C_S1;
/* unbake published declaration: published_5f919a15e79e9a982865602d */
struct func_8023F42C_S1 {
    char pad0[0xC];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    f32 unk14;
    char pad14[0x40 - 0x14 - sizeof(f32)];
    struct Shape * unk40;
    char pad40[0x44 - 0x40 - sizeof(Shape*)];
    f32 unk44;
    char pad44[0x48 - 0x44 - sizeof(f32)];
    f32 unk48;
    char pad48[0x4C - 0x48 - sizeof(f32)];
    f32 unk4C;
    char pad4C[0x50 - 0x4C - sizeof(f32)];
    f32 unk50;
    char pad50[0x54 - 0x50 - sizeof(f32)];
    f32 unk54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk58;
};

struct func_8023F42C_S2;
/* unbake published declaration: published_5fc47554aa15059284db5862 */
struct func_8023F42C_S2 {
    char pad0[0x174];
    s32 unk174;
};

struct func_8023F42C_S2;
/* unbake published declaration: published_6d3d7beeb41ef6d8bcaeed79 */
typedef struct func_8023F42C_S2 func_8023F42C_S2;

/* unbake published declaration: published_6ed88249c25c42e63f55530c */
extern float D_800C373C_de;

struct func_8023F634_S1;
/* unbake published declaration: published_78bcdbc0892803681e5c8484 */
struct func_8023F634_S1 {
    char pad0[0xC];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    char unk10;
    char pad10[0x14 - 0x10 - sizeof(char)];
    f32 unk14;
    char pad14[0x40 - 0x14 - sizeof(f32)];
    s32 * unk40;
    char pad40[0x44 - 0x40 - sizeof(s32*)];
    f32 unk44;
    char pad44[0x48 - 0x44 - sizeof(f32)];
    f32 unk48;
    char pad48[0x4C - 0x48 - sizeof(f32)];
    f32 unk4C;
    char pad4C[0x50 - 0x4C - sizeof(f32)];
    f32 unk50;
    char pad50[0x54 - 0x50 - sizeof(f32)];
    f32 unk54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk58;
};

struct func_80240C7C_S1;
/* unbake published declaration: published_7a812346c7d5d08e9538fcb6 */
typedef struct func_80240C7C_S1 func_80240C7C_S1;

struct EntityTable;
/* unbake published declaration: published_8b9e86ecb6ea23997e86fc90 */
typedef struct EntityTable EntityTable;

struct func_80241250_S1;
/* unbake published declaration: published_8c423267bd8305f4ac7661d4 */
typedef struct func_80241250_S1 func_80241250_S1;

struct Quad;
/* unbake published declaration: published_95c4ab4504621477de73ba91 */
struct Quad {
    char pad0[0x14];
    s32 kind;
    Vec3 corner[4];
    Vec3 normal;
};

struct func_80240C9C_S1;
/* unbake published declaration: published_b1c6165e9e5e574aea93ef52 */
typedef struct func_80240C9C_S1 func_80240C9C_S1;

struct func_80241250_S1;
/* unbake published declaration: published_b2c4042855276276aa55efbb */
struct func_80241250_S1 {
    char pad0[0x18];
    Vec3 unk18;
    char pad18[0x48 - 0x18 - sizeof(Vec3)];
    f32 unk48;
    char pad48[0x4C - 0x48 - sizeof(f32)];
    f32 unk4C;
    char pad4C[0x50 - 0x4C - sizeof(f32)];
    f32 unk50;
};

struct Shape_func_802764D4_de_2;
/* unbake published declaration: published_ce5f284f6ea9e7b26fea99cd */
extern void func_802405FC_de(struct Shape_func_802764D4_de_2 *left, struct Shape_func_802764D4_de_2 *right);

struct Plane;
/* unbake published declaration: published_e3668a30bc26bd13649605eb */
struct Plane {
    char pad[0x18];
    Vec3 pos;
    char pad24[0x24];
    Vec3 normal;
};

struct func_8023F42C_S1;
/* unbake published declaration: published_f77566a4a6d3e0553fbbee6d */
typedef struct func_8023F42C_S1 func_8023F42C_S1;

/* unbake published declaration: published_fcbf4162d71373d352fb6116 */
extern void func_80240C8C_de(void *arg0);

#endif
