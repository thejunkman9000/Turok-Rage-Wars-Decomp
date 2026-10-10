#ifndef UNBAKE_SPAN_16E000_CODE_804143D8_H
#define UNBAKE_SPAN_16E000_CODE_804143D8_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
struct Texture;
/* unbake published declaration: published_0046a35fa4ae4fa146339145 */
typedef struct Texture Texture;

struct Image_func_80419490_de;
/* unbake published declaration: published_06efb6807f21d00f2a85a8b6 */
typedef struct Image_func_80419490_de Image_func_80419490_de;

/* unbake published declaration: published_0b866873c5e7558793a09e8e */
extern void func_80419430_de(void *source);

/* unbake published declaration: published_124d9db3074bf68afa41e156 */
extern void func_80419278_de(s32 left, s32 top, s32 right, s32 bottom, f32 u0, f32 v0, f32 u1, f32 v1);

/* unbake published declaration: published_134fbd6009f4b0375edf57ed */
extern void func_80417138_de(s32 flags);

/* unbake published declaration: published_1bb6113cace35bff83381cbc */
extern void func_8029D7E8_auto(void);

struct Image_func_80419490_de;
/* unbake published declaration: published_2e19d1998d96afe138883d2c */
struct Image_func_80419490_de {
    char pad0[8];
    s16 width;
    s16 height;
    char padC[0xC];
    s32 *pixels;
};

struct Command;
/* unbake published declaration: published_349315272fc79afbc2de218d */
struct Command {
    unsigned words[2];
};

/* unbake published declaration: published_4ac3157fca77b40766ca8669 */
extern int D_8014DCE0;

struct Texture;
/* unbake published declaration: published_c0ceb6937cee5a470df7fdd5 */
struct Texture {
    char pad0[4];
    s16 width;
    s16 height;
};

/* unbake published declaration: published_5cb3d983580ae75047b9c39e */
extern void func_80419608_de();

/* unbake published declaration: published_6308e39fc7f32eced2bd68e1 */
extern int D_80153F68;

/* unbake published declaration: published_658fcbb01a1ea5da261d23a4 */
extern float D_800DD410_de;

/* unbake published declaration: published_a3beffc83ccedc9801aaa4a4 */
extern double func_804147F0_eu_x();

/* unbake published declaration: published_b92e5af7168c47e74895a712 */
extern void func_80418F8C_de();

/* unbake published declaration: published_bebf5e7737aabeb743217773 */
extern void func_804191A4_de(void);

/* unbake published declaration: published_d91a0797969128b4dc0db8cc */
extern void func_804190C4_de(s32 mode);

/* unbake published declaration: published_efa7c6ac7828cf2370b893df */
extern void func_80414360_de();

/* unbake published declaration: published_f08ba1fc0237e9ec9a5aa515 */
extern void func_804191E8_de(void);

/* unbake published declaration: published_fdbc4568ecebd837bd5a62af */
extern void func_80414384_de();

extern void func_80419868_eu_x(void);

extern void func_802BA1B0_de(s32 arg0);

#endif
