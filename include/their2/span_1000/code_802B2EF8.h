#ifndef UNBAKE_SPAN_1000_CODE_802B2EF8_H
#define UNBAKE_SPAN_1000_CODE_802B2EF8_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_1b35c161a6dda3b4fab25539 */
typedef void ( *Shared_func_802B32A0_de_FuncPtr)(void *, signed int, void *);

struct Node_func_802B3130_de;
/* unbake published declaration: published_1eb6fcd504e69aa603a10375 */
typedef struct Node_func_802B3130_de Node_func_802B3130_de;

struct ObjectLinks10_2;
/* unbake published declaration: published_24bebf72275479f1b58650c2 */
typedef struct ObjectLinks10_2 ObjectLinks10_2;

struct ALParam_s_func_802B3000_de;
/* unbake published declaration: published_4462338651d321652e0085d1 */
typedef struct ALParam_s_func_802B3000_de ALParam_s_func_802B3000_de;

struct ObjectState10_3;
/* unbake published declaration: published_4d8fc2c6bb3558c158b30391 */
typedef struct ObjectState10_3 ObjectState10_3;

struct ObjectLinks10_2;
/* unbake published declaration: published_554ed21602220045b0d53b34 */
struct ObjectLinks10_2 {
    char pad0[0x4];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    void * unk_C;
};

struct func_802B8200_S1;
/* unbake published declaration: published_566db0ab27c5d7b87c766d0a */
typedef struct func_802B8200_S1 func_802B8200_S1;

struct ObjectState10_4;
/* unbake published declaration: published_6fb02cdcd49d698e0ed3f38a */
typedef struct ObjectState10_4 ObjectState10_4;

/* unbake published declaration: published_7ee0f456fc19c8ab1c1e70fb */
typedef void ( *Shared_func_802B33E0_de_FuncPtr)(void *, signed int, void *);

struct PVoice_s_func_802B3000_de;
/* unbake published declaration: published_93d375f4c25f08be40c4df7a */
typedef struct PVoice_s_func_802B3000_de PVoice_s_func_802B3000_de;

struct ALParam_s_func_802B3000_de;
/* unbake published declaration: published_944a4685134e543027d24007 */
struct ALParam_s_func_802B3000_de {
    struct ALParam_s_func_802B3000_de *next;
    s32 delta;
    s16 type;
    union {
        f32 f;
        s32 i;
    } data;
    union {
        f32 f;
        s32 i;
    } moredata;
};

/* unbake published declaration: published_962bde26585babda28db01a5 */
typedef void ( *Shared_func_802B3350_de_FuncPtr)(void *, signed int, void *);

struct Obj_func_802B2F60_de;
/* unbake published declaration: published_afb2437966459a5449d8f897 */
struct Obj_func_802B2F60_de {
    char pad3C[0x3C];
    s32 field3C;
    s32 field40;
};

struct func_802B8200_S1;
/* unbake published declaration: published_c0c5e9fec64fa3d1dc16de69 */
struct func_802B8200_S1 {
    char pad0[4];
    void *unk4;
    char pad4[4];
    void *unkC;
    char padC[4];
    void *unk14;
};

struct ObjectState10_3;
/* unbake published declaration: published_c5542e5845c4ba1690d6e302 */
struct ObjectState10_3 {
    s32 unk_0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    s32 unk_C;
};

struct Limit;
struct Node_func_802B3130_de;
/* unbake published declaration: published_cb8bb6a97ff478625ba6da89 */
struct Node_func_802B3130_de {
    struct Node_func_802B3130_de *next;
    char pad4[4];
    struct Limit *limit;
    char padC[0xCC];
    s32 flags;
};

/* unbake published declaration: published_d338b25b44ef71ad6ed78da8 */
typedef void ( *Shared_func_802B3200_de_FuncPtr)(void *, signed int, void *);

struct ObjectState10_4;
/* unbake published declaration: published_e999602ae921277ca5ba3889 */
struct ObjectState10_4 {
    s32 unk_0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    f32 unk_C;
};

struct Obj_func_802B2F60_de;
/* unbake published declaration: published_eba0a4d7bfba4ca2f8140423 */
typedef struct Obj_func_802B2F60_de Obj_func_802B2F60_de;

extern void func_802B31E8_de(void);
#endif
