#ifndef UNBAKE_SPAN_1000_CODE_80296014_H
#define UNBAKE_SPAN_1000_CODE_80296014_H
#include "../types.h"
/* unbake published declaration: published_0f4d6a6ed77c86884b702d2e */
extern void func_80295FF4_de();

/* unbake published declaration: published_2ba003e8ada102b4ecb29be8 */
extern f32 func_802969B0_de(f32 *a, f32 *b);

struct Frustum;
/* unbake published declaration: published_2dbec37407da8c42fc756154 */
struct Frustum {
    f32 planes[6][4];
};

/* unbake published declaration: published_328a278807d3a82926118774 */
extern f32 func_80296930_de(f32 *arg0, f32 *arg1, f32 *arg2);

struct Obj5;
/* unbake published declaration: published_5b72608fc3f6351216ba9775 */
typedef struct Obj5 Obj5;

struct Obj5;
/* unbake published declaration: published_63779a0db11fa94e2fe2904d */
struct Obj5 {
    char pad0[4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s16 table[400];
};

struct Frustum;
/* unbake published declaration: published_709beb9403166a30cb5abef8 */
typedef struct Frustum Frustum;

struct Board;
/* unbake published declaration: published_8a2d36425876c10516bf2045 */
typedef struct Board Board;

/* unbake published declaration: published_9d0b0a95881ff7ded1951f56 */
extern float D_800C5510_de;

struct Board;
/* unbake published declaration: published_c8c8b1ca50f9db3014b3a308 */
struct Board {
    s32 unk0;
    s32 unk4;
    s32 originX;
    s32 originY;
    s32 unk10;
    s32 unk14;
    s16 cells[17 * 17];
};

/* unbake published declaration: published_d762d7617c57d79c9b23f941 */
extern s32 func_80296C30_de(f32 *arg0, f32 *arg1);

#endif
