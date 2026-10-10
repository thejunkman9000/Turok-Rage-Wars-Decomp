#ifndef UNBAKE_SPAN_1000_CODE_8023A284_H
#define UNBAKE_SPAN_1000_CODE_8023A284_H
#include "../types.h"
#include "common/types_8fd754e1e915.h"
/* unbake published declaration: published_18eaa73701f79305ca915876 */
extern f32 func_8023A294_de(s32 arg0, f32 value, f32 target, f32 step);

struct Descriptor_func_8023B718_de;
/* unbake published declaration: published_1fb82f2dfd0b3d64e22fd9a7 */
typedef struct Descriptor_func_8023B718_de Descriptor_func_8023B718_de;

/* unbake published declaration: published_28f21988c3440cbb59d385c0 */
extern float D_800C86E8;

struct View_func_8023B3F8_de;
/* unbake published declaration: published_2e2c1cfebf9086da8e0e991d */
typedef struct View_func_8023B3F8_de View_func_8023B3F8_de;

/* unbake published declaration: published_4d7bbec7dbebbc324828a671 */
extern Message *func_8023A344_de(void *owner, void *pool, u8 *text, s32 kind, f32 size, s32 target);

struct IntegerState8A4;
/* unbake published declaration: published_4e9774ff0e93e6e76c7c1c43 */
typedef struct IntegerState8A4 IntegerState8A4;

struct Host;
/* unbake published declaration: published_509d709d1f26c2f1ff0dd390 */
struct Host {
    char pad0[0x24];
    s32 stalled;
    char pad28[0x104];
    f32 speed;
};

/* unbake published declaration: published_59af513bd2f4025ef27f5c6e */
extern int func_8023B978_de(void *first, void *second);

struct Descriptor_func_8023B718_de;
/* unbake published declaration: published_5c692a18355f2513ff6458db */
struct Descriptor_func_8023B718_de {
    char pad0[8];
    f32 spinRate;
    char padC[4];
    f32 phaseRate;
    f32 baseSpeed;
    char pad18[4];
    f32 hostScale;
    f32 throttleRate;
    char pad24[5];
    u8 flags;
};

struct func_8023B968_S1;
/* unbake published declaration: published_5d28c79b1a7c577308efe61c */
typedef struct func_8023B968_S1 func_8023B968_S1;

struct Effect;
/* unbake published declaration: published_651b7ce4baff40b799660fe7 */
struct Effect {
    char pad00[0xC];
    s16 *definition;
    s16 mask;
    char pad12[0xA];
    s32 angle0;
    s32 angle1;
    char pad24[0x1E4];
    s32 timer;
    s32 velocity;
    char pad210[4];
    f32 scale;
    f32 offset0;
    f32 offset1;
    f32 offset2;
};

struct Host;
/* unbake published declaration: published_65765a518039c469f159dbd2 */
typedef struct Host Host;

struct Object_func_8023B3F8_de;
/* unbake published declaration: published_759f3754d4c83f778500f736 */
struct Object_func_8023B3F8_de {
    char gap0[4];
    struct Object_func_8023B3F8_de *next;
    char gap8[0x208];
    f32 depth;
};

/* unbake published declaration: published_7eb250fdea2c615ced1230a6 */
extern void func_8023B938_de(int *arg0, int *arg1);

/* unbake published declaration: published_857b67ebef4d0091aa694088 */
extern float D_800CD744_de;

/* unbake published declaration: published_882773c6da6fcdc3b2fb0446 */
extern s32 func_8023B94C_de(void **arg0, void **arg1);

struct View_func_8023B3F8_de;
/* unbake published declaration: published_8ce62a676361f9f97e42aa6b */
struct View_func_8023B3F8_de {
    char gap0[0x120];
    s32 hidden;
    char gap124[8];
    f32 depth;
};

struct Object_func_8023B3F8_de;
/* unbake published declaration: published_938be822171f2182db96fda5 */
typedef struct Object_func_8023B3F8_de Object_func_8023B3F8_de;

struct Scene;
/* unbake published declaration: published_9621413a074c3925e8ac4de5 */
typedef struct Scene Scene;

/* unbake published declaration: published_abb9d5333cedc5b2a611956e */
extern float D_800C86E0;

struct Effect;
/* unbake published declaration: published_b2879a00679df81abd4c7fff */
typedef struct Effect Effect;

struct Rotor;
/* unbake published declaration: published_b9b33c6146e576468c57e898 */
typedef struct Rotor Rotor;

/* unbake published declaration: published_c20732dba7baf5bdd31d98c6 */
extern float D_800C35F4_de;

struct Descriptor_func_8023B718_de;
struct Rotor;
/* unbake published declaration: published_cf443b42531c06a4812056e8 */
struct Rotor {
    char pad0[0xC];
    struct Descriptor_func_8023B718_de *descriptor;
    u16 mask;
    char pad12[0xA];
    f32 angleA;
    f32 angleB;
    char pad24[0x1E4];
    f32 throttle;
    f32 phase;
    f32 speed;
    f32 phaseScale;
    char pad218[4];
    f32 trim;
};

struct func_8023B968_S1;
/* unbake published declaration: published_d7ed8104472a0b26d74f3df3 */
struct func_8023B968_S1 {
    char pad0[0x210];
    float unk210;
};

struct Object_func_8023B3F8_de;
struct Scene;
/* unbake published declaration: published_ec7e9c749ae38a555ddd0b1f */
struct Scene {
    char gap0[0x8B4];
    struct Object_func_8023B3F8_de *objects;
    char gap8B8[12];
    s32 count;
};

struct IntegerState8A4;
/* unbake published declaration: published_f067575a4d900db80e929878 */
struct IntegerState8A4 {
    unsigned char padding_0[2208];
    IntrusiveList unk_8A0;
    IntrusiveList unk_8B4;
};

#endif
