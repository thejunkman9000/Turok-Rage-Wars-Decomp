#ifndef UNBAKE_SPAN_1000_CODE_802022E0_H
#define UNBAKE_SPAN_1000_CODE_802022E0_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
struct Obj;
/* unbake published declaration: published_15037d70ad2782d719d578db */
typedef struct Obj Obj;

struct func_80203908_S3;
/* unbake published declaration: published_1ae2e09722afc6493ce87e5e */
struct func_80203908_S3 {
    char pad0[0x37];
    s8 unk37;
    char pad37[0x64 - 0x37 - sizeof(s8)];
    f32 unk64;
    char pad64[0x124 - 0x64 - sizeof(f32)];
    func_80203908_S3_U124 unk124;
    char pad124[0x128 - 0x124 - sizeof(func_80203908_S3_U124)];
    s32 unk128;
};

struct Record_func_8020388C_de;
/* unbake published declaration: published_1f9511da24b0852c42305666 */
struct Record_func_8020388C_de {
    char pad0[0x2C];
    void *table;
    char pad30[0x108 - 0x30];
    void *first;
    s32 pad10C;
    void *second;
    char pad114[0x11C - 0x114];
    void *third;
    void *fourth;
    f32 speed;
    s32 pad128;
    s32 rate;
    s32 a;
    f32 range;
    s32 b;
    s32 c;
};

/* unbake published declaration: published_227e159573df718ae9499db8 */
extern float D_800C6B2C;

/* unbake published declaration: published_3f5ecda998ed84d90842684e */
extern float D_800C1A04_de;

struct Segment_func_80203278_de;
/* unbake published declaration: published_42fc55ab5fe76890b91c2d4d */
typedef struct Segment_func_80203278_de Segment_func_80203278_de;

struct func_80203848_S1;
/* unbake published declaration: published_4b691bb7c494a22f27936b89 */
struct func_80203848_S1 {
    char pad0[0x130];
    f32 unk130;
    char pad130[0x134 - 0x130 - sizeof(f32)];
    f32 unk134;
    char pad134[0x138 - 0x134 - sizeof(f32)];
    f32 unk138;
};

/* unbake published declaration: published_4e5c7e8b2c64205cce8a5abe */
extern float D_800C1A00_de;

struct func_80203DF0_S4;
/* unbake published declaration: published_6fc600e6c8261487bc3eb927 */
typedef struct func_80203DF0_S4 func_80203DF0_S4;

struct Result;
/* unbake published declaration: published_815702544fac5391362bd57e */
typedef struct Result Result;

struct func_80203DF0_S4;
/* unbake published declaration: published_894e62a8ea466f67a3c71d9a */
struct func_80203DF0_S4 {
    char pad0[0x6C];
    f32 unk6C;
    char pad6C[0x20C - 0x6C - sizeof(f32)];
    f32 unk20C;
};

struct func_80203908_S3;
/* unbake published declaration: published_8b482d26770e5503c07fd0d2 */
typedef struct func_80203908_S3 func_80203908_S3;

struct func_80203848_S1;
/* unbake published declaration: published_90bdc0ed791f8ebfc2d976d9 */
typedef struct func_80203848_S1 func_80203848_S1;

/* unbake published declaration: published_924097222ac5e9d37550ab5e */
extern float D_800C19FC_de;

struct Actor;
/* unbake published declaration: published_9575fa7bcf06095b914d7b29 */
typedef struct Actor Actor;

struct Hook;
struct Obj;
/* unbake published declaration: published_95ccc8b20406746e0469a184 */
struct Obj {
    char pad0[0x30];
    struct Hook *hook;
    char pad34[0x12C - 0x34];
    int count;
    char pad130[0x13C - 0x130];
    float timer;
};

struct Rider_func_80203278_de;
/* unbake published declaration: published_a107cc48f5cbdfc3d518e3d8 */
typedef struct Rider_func_80203278_de Rider_func_80203278_de;

struct Actor;
/* unbake published declaration: published_a91a9415f9d8a10dffdb8b47 */
struct Actor {
    char pad[0x1D8];
    struct Actor *linked;
    char pad1DC[0x5D8 - 0x1DC];
    Record *info;
    char pad5DC[0x5E4 - 0x5DC];
    int active;
};

/* unbake published declaration: published_b95c859ed5121f9a5916de9e */
extern void func_80203DF0_de(void *arg0, void *arg1);

struct Segment;
/* unbake published declaration: published_b96106191ae4ff3c30c9b5de */
struct Segment {
    char pad0[0x5C];
    f32 rise;
    f32 radius;
    f32 angle;
    f32 length;
};

struct Result;
/* unbake published declaration: published_b99ccf4138abe99aa43eff87 */
struct Result {
    char pad0[4];
    SharedPlayer *target;
    char pad8[0x38];
    f32 distance;
};

struct Segment_func_80203278_de;
/* unbake published declaration: published_bb1d1d9de614eb47426f207d */
struct Segment_func_80203278_de {
    char pad0[0x54];
    f32 range;
};

/* unbake published declaration: published_c52a897874324f3fd5ffe7ee */
extern int func_80203A94_de(void *arg0);

/* unbake published declaration: published_c978a3fdc8ad0298817ae270 */
extern float D_800C1A48_de;

/* unbake published declaration: published_d1b2aaebfc575b929b88defd */
extern f32 D_80115DEC;

struct func_80203DF0_S2;
/* unbake published declaration: published_da88eec1a4f9abb96eb308f8 */
struct func_80203DF0_S2 {
    char pad0[0x18];
    char * unk18;
    char pad18[0x294 - 0x18 - sizeof(char*)];
    f32 unk294;
};

/* unbake published declaration: published_e8bb017203aceab73b917922 */
extern float D_800C1A0C;

struct Segment;
/* unbake published declaration: published_f2342f0482aca7df953456dc */
typedef struct Segment Segment;

struct Owner_func_8020388C_de;
struct Record_func_8020388C_de;
/* unbake published declaration: published_f720e3462af368e90ba3e14e */
extern void func_8020388C_de(struct Owner_func_8020388C_de *owner, struct Record_func_8020388C_de *record);

struct func_80203DF0_S2;
/* unbake published declaration: published_fd2f6edc11cd1fc8919f2d10 */
typedef struct func_80203DF0_S2 func_80203DF0_S2;

struct Rider;
/* unbake published declaration: published_ff1bafaa97a2b53f1bf6b0bb */
typedef struct Rider Rider;

extern void func_802022E0_de();
extern void func_8020238C_de(void);
extern void func_802023A8_de(void);
extern int func_802023C4_de();
extern void func_802023D0_de(int arg0);
#endif
