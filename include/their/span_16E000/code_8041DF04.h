#ifndef UNBAKE_SPAN_16E000_CODE_8041DF04_H
#define UNBAKE_SPAN_16E000_CODE_8041DF04_H
#include "../types.h"
/* unbake published declaration: published_05d9a0171aff75229b03d695 */
extern s32 func_8041EAC4_de();

struct Player_func_8041EAC4_de;
/* unbake published declaration: published_0844c5657826bd63cd30e15a */
typedef struct Player_func_8041EAC4_de Player_func_8041EAC4_de;

struct Screen_func_8041ECB4_de;
/* unbake published declaration: published_093381c8d3c685664dbe0cc5 */
struct Screen_func_8041ECB4_de {
    char pad0[8];
    void *roots[3];
    s32 request;
    s32 timer;
};

/* unbake published declaration: published_264a897e5a76cd79e2d492f3 */
extern s32 func_8041F140_de(s32 key);

/* unbake published declaration: published_7f87caef281d8447fb98425a */
extern void func_8041E5F8_de();

struct Menu_func_8041EE08_de;
/* unbake published declaration: published_9fc7e422b423836fb87395cf */
typedef struct Menu_func_8041EE08_de Menu_func_8041EE08_de;

/* unbake published declaration: published_ae71b601455be2ad72f67e19 */
extern s32 func_8041EBBC_de(void);

struct Request_func_8041E100_de;
/* unbake published declaration: published_bb9cf3bc36ff5a020b49b3d6 */
struct Request_func_8041E100_de {
    s32 id;
    s32 variant;
    s32 word8;
    s32 variantC;
    char name[28 - 0x10];
};

/* unbake published declaration: published_d5b680a7143f4de8cf795bc5 */
extern s32 func_8041DEB4_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Menu_func_8041EE08_de;
/* unbake published declaration: published_df6b471d24eb741ed0366d28 */
struct Menu_func_8041EE08_de {
    char pad[8];
    int items[3];
    int unk14;
    int unk18;
    int unk1C;
};

/* unbake published declaration: published_f42be910a42c1586cb9bed0e */
extern s32 func_8041EB50_de();

#endif
