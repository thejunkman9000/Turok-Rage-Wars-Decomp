#ifndef UNBAKE_SPAN_1000_CODE_8020D370_H
#define UNBAKE_SPAN_1000_CODE_8020D370_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
struct Actor_func_8020E674_de;
/* unbake published declaration: published_0176138604e4992c8d1da53c */
typedef struct Actor_func_8020E674_de Actor_func_8020E674_de;

/* unbake published declaration: published_3230f00876e09b2a57948656 */
extern float D_800C1DB8_de;

struct Obj_func_8020D9C0_de;
/* unbake published declaration: published_339c3efbae7a56108bf691a1 */
struct Obj_func_8020D9C0_de {
    char pad0[0x38];
    s32 count;
    char pad3C[0x138-0x3C];
    Vec3 points[10];
    Vec3 result;
    char pad1BC[0x1C4-0x1BC];
    s32 infoIndex;
};

/* unbake published declaration: published_348e6079c8c9c9fde2eb97ed */
extern float D_800C1E40_de;

struct Stage;
/* unbake published declaration: published_6a6c8e165b57234ab3402cee */
struct Stage {
    s32 to;
    s32 from;
    f32 distance;
};

struct Stage;
/* unbake published declaration: published_9b0edbb211cb7c0373d8b70c */
typedef struct Stage Stage;

struct Selection_func_8020D4AC_de;
/* unbake published declaration: published_350765eb6e76bee2bb6f76ae */
struct Selection_func_8020D4AC_de {
    char pad0[0xC];
    s32 node;
    char pad10[0x28];
    s32 objectCount;
    Player *objects[33];
    Stage stages[10];
    Vec3 dirs[10];
    char pad1B0[0xC];
    s32 stageCount;
    s32 id;
};

struct func_8020DC10_S1;
/* unbake published declaration: published_50997f56aa1a93f36668f0ee */
typedef struct func_8020DC10_S1 func_8020DC10_S1;

struct Actor_func_8020E674_de;
struct InstanceHdr;
/* unbake published declaration: published_525af3877f2130c638c3ad61 */
struct Actor_func_8020E674_de {
    struct InstanceHdr *instance;
    u8 pad004[0x254];
    f32 field258;
    u8 pad25C[4];
    f32 field260;
    f32 field264;
    u8 pad268[0x10];
    f32 field278;
};

struct func_8020DC10_S1;
/* unbake published declaration: published_5417fc22fb71771b87b16f99 */
struct func_8020DC10_S1 {
    char pad0[0x64];
    s32 unk64;
    char pad64[0x21C - 0x64 - sizeof(s32)];
    s32 unk21C;
};

struct Selection_func_8020D4AC_de;
/* unbake published declaration: published_54afb90db27db9a7df97eced */
typedef struct Selection_func_8020D4AC_de Selection_func_8020D4AC_de;

/* unbake published declaration: published_565f6e0d1b282ecc765ee0ed */
extern float D_800C1E48_de;

struct WeightSource;
/* unbake published declaration: published_56b172783c84a5b169154283 */
struct WeightSource {
    char pad[0x2C];
    f32 first;
    f32 second;
    f32 third;
};

struct func_8020DCA0_S1;
/* unbake published declaration: published_5743bc90c34505fc2b4a85e4 */
typedef struct func_8020DCA0_S1 func_8020DCA0_S1;

/* unbake published declaration: published_5fc6d0338a53d3ce70ff7398 */
extern float D_800C1E58_de;

/* unbake published declaration: published_8fe243505677d26ba3c78fa2 */
extern float D_800C1E44_de;

struct Obj_func_8020DB14_de;
/* unbake published declaration: published_90780bb2624ff1971b0cf82c */
struct Obj_func_8020DB14_de {
    char pad0[0x14];
    int nodes[4];
    char pad24[0x1BC - 0x24];
    int hits;
    int node;
    char pad1C4[4];
    int pending;
};

struct func_8020DCA0_S1;
/* unbake published declaration: published_a1499a27304d192f789fbdef */
struct func_8020DCA0_S1 {
    void * unk0;
    char pad0[0x230 - 0x0 - sizeof(void*)];
    s32 unk230;
};

struct Obj_func_8020DB14_de;
/* unbake published declaration: published_b3f4d175bbdeb2315d14913f */
typedef struct Obj_func_8020DB14_de Obj_func_8020DB14_de;

struct Obj_func_8020D9C0_de;
/* unbake published declaration: published_c3c809df77ca5cfdb72cb640 */
typedef struct Obj_func_8020D9C0_de Obj_func_8020D9C0_de;

/* unbake published declaration: published_c77ad99a48accf163ef11824 */
extern float D_800C1E50_de;

struct WeightSource;
/* unbake published declaration: published_da5ca4180ae9da0953a5339a */
typedef struct WeightSource WeightSource;

/* unbake published declaration: published_e4f7695ce36ca193d6d164db */
extern s32 func_8020EAB4_de(void);

#endif
