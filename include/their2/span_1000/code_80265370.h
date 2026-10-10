#ifndef UNBAKE_SPAN_1000_CODE_80265370_H
#define UNBAKE_SPAN_1000_CODE_80265370_H
#include "../types.h"
/* unbake published declaration: published_00d8fd7d904b847a92975352 */
extern void func_80265DD0_de();

/* unbake published declaration: published_0923fd527c583742674cba7e */
extern float D_800C439C_de;

struct LightData;
/* unbake published declaration: published_2f9bc54ad92df4779255f5d6 */
struct LightData {
    u16 falloff;
    u16 near;
    u8 color[4];
};

struct LightData;
/* unbake published declaration: published_58ed6ac8a0a196ea7b808d66 */
typedef struct LightData LightData;

struct LightNode;
/* unbake published declaration: published_1278ae622c8d8531cafe9294 */
struct LightNode {
    char pad0[8];
    LightData *data;
    f32 intensity;
    s16 position[3];
    s16 active;
};

/* unbake published declaration: published_2a92f6d2708159c308e2f267 */
extern int func_8026581C_de(u32 address);

struct UnitLight;
/* unbake published declaration: published_3c0469ece9f36db0b83d6973 */
typedef struct UnitLight UnitLight;

/* unbake published declaration: published_3c0af0a3393650d1a782c6ef */
extern int func_8026563C_de(int arg0);

/* unbake published declaration: published_4a61d6131a0ca58d486a6007 */
extern void func_80265900_de(void);

struct UnitLight;
/* unbake published declaration: published_4aab673a8db0b4cc5ec43a54 */
struct UnitLight {
    s16 dir[3];
    u8 color[4];
    s16 falloff;
    u16 near;
    u16 range;
};

/* unbake published declaration: published_80ddf61d7c821e08007d9117 */
extern void func_802656DC_de(s32 arg0, s32 arg1);

/* unbake published declaration: published_b2c4975635bb3586851d1689 */
extern float D_800C4398_de;

struct LightNode;
/* unbake published declaration: published_bbb33890dcfd3e620b506454 */
typedef struct LightNode LightNode;

/* unbake published declaration: published_cca53252c6594296927740c8 */
extern float D_800C43A0_de;

/* unbake published declaration: published_f39a21e8f8745ba9b70d75b7 */
extern f32 func_80265714_de(f32 arg0);

extern void func_802658DC_de(void);
#endif
