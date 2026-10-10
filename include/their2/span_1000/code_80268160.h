#ifndef UNBAKE_SPAN_1000_CODE_80268160_H
#define UNBAKE_SPAN_1000_CODE_80268160_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
struct RangeNode;
/* unbake published declaration: published_0e61783fc3cf6252fb94c2ca */
typedef struct RangeNode RangeNode;

struct Blast;
/* unbake published declaration: published_1674dc6e7998c501c7a3fb2f */
typedef struct Blast Blast;

/* unbake published declaration: published_18fec7fa00f4accc6bb0f453 */
extern float D_800C4468_de;

struct Owner_func_802688E4_de;
/* unbake published declaration: published_26f04a7a4f57400d65b212ea */
struct Owner_func_802688E4_de {
    char pad0[8];
    Vec3 pos;
    char pad14[0x16D4 - 0x14];
    s32 alive;
};

struct Actor_func_802688E4_de;
struct Owner_func_802688E4_de;
/* unbake published declaration: published_1aa8fe06877cc2d44045ef3d */
struct Actor_func_802688E4_de {
    u8 kind;
    char pad1[0x100 - 1];
    s32 flags;
    char pad104[0x1D8 - 0x104];
    struct Owner_func_802688E4_de *owner;
};

struct Limit;
/* unbake published declaration: published_1b9f077d7d40e40ab73cd50c */
typedef struct Limit Limit;

struct func_802689BC_S1;
/* unbake published declaration: published_1d3404b81e866b72817dfb0e */
struct func_802689BC_S1 {
    char pad0[0xF];
    char unkF;
};

/* unbake published declaration: published_1d95b0e9e3bd81241c99d167 */
extern void func_80268264_de(int arg0, int arg1, int arg2, int arg3, ...);

struct Params_func_8026826C_de;
/* unbake published declaration: published_31841659cf04ee987523c34d */
typedef struct Params_func_8026826C_de Params_func_8026826C_de;

struct Actor_func_802688E4_de;
/* unbake published declaration: published_9b7d5bfa448a64a7f69ccd33 */
typedef struct Actor_func_802688E4_de Actor_func_802688E4_de;

struct Blast;
/* unbake published declaration: published_e3b91e32963472e507185ad5 */
struct Blast {
    char pad0[0xC];
    s32 radius;
    s32 damage;
};

/* unbake published declaration: published_31da22e46a4724642f35d436 */
extern void func_802688E4_de(Actor_func_802688E4_de *arg0, Player *arg1, s32 arg2, Blast blast);

struct Params_func_802681A8_de;
/* unbake published declaration: published_4c5748dfea80283c9c6c466d */
struct Params_func_802681A8_de {
    s32 value;
    s16 angle;
    u8 scale;
    u8 pad;
};

struct Object_func_8026826C_de;
/* unbake published declaration: published_598cd8dd0ff27d8037ef1e4a */
typedef struct Object_func_8026826C_de Object_func_8026826C_de;

struct func_802689BC_S2;
/* unbake published declaration: published_6264d5577fc995d13ec45585 */
typedef struct func_802689BC_S2 func_802689BC_S2;

struct Owner_func_802688E4_de;
/* unbake published declaration: published_748c98a6963923fd94977493 */
typedef struct Owner_func_802688E4_de Owner_func_802688E4_de;

struct func_80268C1C_S2;
/* unbake published declaration: published_8655dac5db4d4a715b2699bb */
typedef struct func_80268C1C_S2 func_80268C1C_S2;

/* unbake published declaration: published_917cc74c71427489d9cbeeb9 */
extern float D_800C9564;

/* unbake published declaration: published_9281aa36e4667c2ed3cf6a7e */
extern float D_800C9560;

/* unbake published declaration: published_942453373d0fc9d0593f585f */
extern float D_800C446C_de;

struct func_802689CC_S1;
/* unbake published declaration: published_99c7afa50f1340a5831e9a5b */
typedef struct func_802689CC_S1 func_802689CC_S1;

struct RangeNode;
/* unbake published declaration: published_9abf316d4082e839a5c381c8 */
struct RangeNode {
    char pad0[4];
    struct RangeNode *next;
    u16 *radius;
    char padC[4];
    s16 x;
    s16 y;
    s16 z;
    s16 active;
};

struct Context_func_802681A8_de;
/* unbake published declaration: published_9c8650ac4e6b26926284117f */
typedef struct Context_func_802681A8_de Context_func_802681A8_de;

struct Params_func_8026826C_de;
/* unbake published declaration: published_9fbf4e6d9dc66fc00b881b5c */
struct Params_func_8026826C_de {
    s16 unk0;
    s16 value;
    s32 team;
};

/* unbake published declaration: published_acf75d2ac2612ffdd8cf1e72 */
extern void func_802684B8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

struct Kind;
struct Kind {
    s32 value;
    u8 pad4[0xA];
    s8 team;
};
struct Kind;
struct Object_func_8026826C_de;
/* unbake published declaration: published_b555c50cedd412cc4408c8b9 */
struct Object_func_8026826C_de {
    u8 type;
    u8 pad1[0x17];
    struct Kind *kind;
    u8 pad1C[0xB4];
    s32 value;
    u8 padD4[0xA8];
    u32 mask;
};

struct func_802689CC_S1;
/* unbake published declaration: published_b599163dba2d28f91d1bf48d */
struct func_802689CC_S1 {
    char pad0[0x100];
    s32 unk100;
    char pad100[0x170 - 0x100 - sizeof(s32)];
    s32 unk170;
};

struct Filter;
/* unbake published declaration: published_b69520c775698600c38e0fed */
struct Filter {
    u8 type;
    u8 pad[0x17B];
    s32 mask;
};

struct func_802689BC_S1;
/* unbake published declaration: published_c4249a54fad8d9bc04b7ff5f */
typedef struct func_802689BC_S1 func_802689BC_S1;

struct func_80268C1C_S2;
/* unbake published declaration: published_cd0c591ee4365220fc148921 */
struct func_80268C1C_S2 {
    char pad0[0x8];
    void * unk8;
    char pad8[0x16 - 0x8 - sizeof(void*)];
    s16 unk16;
};

/* unbake published declaration: published_d8bba8ccd7df2b9b9e30c8c9 */
extern float D_800C4490_de;

struct Params_func_802681A8_de;
/* unbake published declaration: published_df099c757fa0e19f12f8293f */
typedef struct Params_func_802681A8_de Params_func_802681A8_de;

struct Filter;
/* unbake published declaration: published_e1d623f54bef900206d8b433 */
typedef struct Filter Filter;

struct Inner;
struct Inner {
    char pad[0x698];
    char *resource;
};
struct Context_func_802681A8_de;
struct Inner;
/* unbake published declaration: published_e43111799628ef1634daed01 */
struct Context_func_802681A8_de {
    char pad[0x1D8];
    struct Inner *inner;
};

/* unbake published declaration: published_e52a97d0b2d4f89523083173 */
extern float D_800C4494_de;

/* unbake published declaration: published_f266f9d601d20b2dacc28e77 */
extern void func_802684E8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

/* unbake published declaration: published_fc0677306b5e5efd7079b8f7 */
extern void func_802689BC_de(void *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, unsigned char arg6);

struct func_802689BC_S2;
/* unbake published declaration: published_fdfb7de5e51682d2d4404993 */
struct func_802689BC_S2 {
    char pad0[0x270];
    char unk270;
};

#endif
