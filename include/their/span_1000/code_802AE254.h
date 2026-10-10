#ifndef UNBAKE_SPAN_1000_CODE_802AE254_H
#define UNBAKE_SPAN_1000_CODE_802AE254_H
#include "../types.h"
/* unbake published declaration: published_088027b127a569cc56bf02b7 */
extern s32 func_802AF6A0_us_rev1(void);

/* unbake published declaration: published_1d7fc0ad8e76d8c952d0c34c */
extern int func_802B05C8_us_rev1(void * arg0, int arg1, int arg2, int arg3);

struct Response;
/* unbake published declaration: published_270026d72a19023b3d3f506d */
struct Response {
    u8 handshake;
    u8 pad11[3];
    u32 output;
    u8 byte;
};

struct TransferScratch;
/* unbake published declaration: published_2a606c8b2eb55a62c153e256 */
typedef struct TransferScratch TransferScratch;

/* unbake published declaration: published_2b3909bb4f4496682028ab3c */
extern s32 func_802B1790_us_rev1(u32 arg0);

struct WriteWord;
/* unbake published declaration: published_3352ede424eba3c7a1371d54 */
typedef struct WriteWord WriteWord;

/* unbake published declaration: published_3d05fa603e4dae934ed44600 */
extern u32 func_802B0D3C_us_rev1(u32 arg0);

/* unbake published declaration: published_460f6a0785e17cb5d407ea72 */
extern s32 func_802B15EC_us_rev1(s32 *arg0);

struct ReadWord_func_802AEF84_us_rev1;
/* unbake published declaration: published_4c5672fb5749ea79df5f3e78 */
typedef struct ReadWord_func_802AEF84_us_rev1 ReadWord_func_802AEF84_us_rev1;

/* unbake published declaration: published_508c71b291a4ff9d62db3bc8 */
extern int func_802AEF84_us_rev1(void);

struct TransferScratch;
/* unbake published declaration: published_55519e24ae4e28ad30295f9f */
struct TransferScratch {
    u8 response;
    u8 status;
    u16 pad;
    s32 output;
};

struct WriteWord;
/* unbake published declaration: published_5a33ab701e7df6c7b39a94bd */
struct WriteWord {
    u32 word;
    u8 byte;
    u8 value;
};

struct ReadWord_func_802AEF84_us_rev1;
/* unbake published declaration: published_d4b6345017e4db80fe3e8fca */
struct ReadWord_func_802AEF84_us_rev1 {
    u32 word;
    u8 byte;
};

struct CommandState;
/* unbake published declaration: published_55f384fb25d99bb48827a81f */
struct CommandState {
    u8 command;
    u8 pad01[3];
    ReadWord_func_802AEF84_us_rev1 address;
    ReadWord_func_802AEF84_us_rev1 callback;
    WriteWord output;
};

struct CommandState;
/* unbake published declaration: published_5b1743048290605e3baed240 */
typedef struct CommandState CommandState;

struct ReadHalfword;
/* unbake published declaration: published_649bd46e50711d245eae042a */
typedef struct ReadHalfword ReadHalfword;

struct ReadHalfword;
/* unbake published declaration: published_698d0851cc7ca9affdd241b1 */
struct ReadHalfword {
    s32 word;
    u8 byte;
    u16 value;
    u8 next_byte;
};

/* unbake published declaration: published_6b8a36de09da1d3971125134 */
extern int func_802AD264_de(void);

/* unbake published declaration: published_73f26dce0211169a160217c2 */
extern u32 func_802AFCE4_us_rev1(u8 *arg0, u8 *arg1);

/* unbake published declaration: published_754e3d8db837ca56c5253a34 */
extern void func_802AF990_us_rev1();

/* unbake published declaration: published_7cb65110ad250de5c82a0eb9 */
extern unsigned char D_B2000001;

/* unbake published declaration: published_874683f9fccb11ba6531faa6 */
extern void func_802B1554_us_rev1(void);

/* unbake published declaration: published_9bb8a89d531a31b14434dac5 */
extern int D_800D3648;

/* unbake published declaration: published_abe1df725b3aa6e00f2e7979 */
extern u32 func_802B091C_us_rev1(u32 arg0, u32 arg1, u32 arg2);

/* unbake published declaration: published_b0104d92e19df916bfc43bd6 */
extern int D_800D3640;

/* unbake published declaration: published_b7c1ab007355bbd942f642b3 */
extern s32 func_802B1734_us_rev1(u32 arg0);

/* unbake published declaration: published_c3d45ac0ccbe5f9543f361f0 */
extern s32 func_802B16B4_us_rev1(u8 *arg0, s32 arg1);

/* unbake published declaration: published_def9a913f6e64270b8f0be2e */
extern s32 func_802B156C_us_rev1(u16 *arg0);

struct Response;
/* unbake published declaration: published_e4ff627cb23b3e230d837e73 */
typedef struct Response Response;

/* unbake published declaration: published_ed6a22ad2a4983a67da0aa01 */
extern void func_802B155C_us_rev1(int arg0);

/* unbake published declaration: published_f5d8adab7b40d508e99b6ddf */
extern int D_800D3644;

/* unbake published declaration: published_fe7c54d5d2c6f14d2259b44c */
extern s32 func_802AF544_us_rev1(void);

#endif
