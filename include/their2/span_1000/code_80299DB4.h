#ifndef UNBAKE_SPAN_1000_CODE_80299DB4_H
#define UNBAKE_SPAN_1000_CODE_80299DB4_H
#include "../types.h"
struct Callback;
/* unbake published declaration: published_001fb9bfecd9864e1777a4cf */
typedef struct Callback Callback;

struct Event_func_8029A558_de;
/* unbake published declaration: published_0329ff057dcbddf7a1c2fad6 */
struct Event_func_8029A558_de {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fA;
    s16 fC;
};

/* unbake published declaration: published_0490ed726d9fbfd78bb44533 */
extern void func_8029AA78_de();

/* unbake published declaration: published_0ad5bc6b0562016edead8ba4 */
extern void func_80299B60_de(float *arg0, float *arg1);

struct Msg;
/* unbake published declaration: published_0ea52e8eff2237e428d14944 */
struct Msg {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    s32 f8;
    s16 fC;
    s16 fE;
    s16 f10;
    s16 f12;
};

struct Callback;
/* unbake published declaration: published_1094cc25439c3cf39b1e222c */
struct Callback {
    s32 (*callback)(void);
};

struct func_8029B650_S1;
/* unbake published declaration: published_2783f5f79a09adac30c4e1b6 */
struct func_8029B650_S1 {
    char pad0[0x4];
    s8 unk4;
    char pad4[0xAC - 0x4 - sizeof(s8)];
    s32 unkAC;
    char padAC[0xB0 - 0xAC - sizeof(s32)];
    s32 unkB0;
    char padB0[0xC4 - 0xB0 - sizeof(s32)];
    s8 unkC4;
    char padC4[0xC5 - 0xC4 - sizeof(s8)];
    s8 unkC5;
};

struct Node_func_80299CF0_de;
/* unbake published declaration: published_2e7e1fb10d7ef2b55d947599 */
typedef struct Node_func_80299CF0_de Node_func_80299CF0_de;

/* unbake published declaration: published_3282b96faeb75f55e85bd151 */
extern float D_800C5688_de;

struct Msg;
/* unbake published declaration: published_40d1f396e6bfb8bb29704edd */
typedef struct Msg Msg;

struct func_8029BA34_S1;
/* unbake published declaration: published_4dabc75ad540f8cddf295471 */
typedef struct func_8029BA34_S1 func_8029BA34_S1;

struct Event_func_8029A558_de;
/* unbake published declaration: published_5d50da5827969bcc1fb01a21 */
typedef struct Event_func_8029A558_de Event_func_8029A558_de;

/* unbake published declaration: published_64c011b276506d4d2771cb1f */
extern void func_80299C80_de(void *arg0);

/* unbake published declaration: published_8dd57096c7c1345d1d040550 */
extern void func_8029AAAC_de();

/* unbake published declaration: published_954020bebbde753f5d4c6c27 */
extern void func_80299A5C_de(s32 *arg0, s32 *arg1);

struct Node_func_80299CF0_de;
/* unbake published declaration: published_9f967a0301bba53478d04e30 */
struct Node_func_80299CF0_de {
    s32 unk0;
    struct Node_func_80299CF0_de *left;
    struct Node_func_80299CF0_de *right;
    s16 value;
    u16 type;
    u16 unk10;
    u16 flags;
};

struct func_8029B650_S1;
/* unbake published declaration: published_a4377b84f7c0a1ea4ff954c2 */
typedef struct func_8029B650_S1 func_8029B650_S1;

struct func_8029AA48_S1;
/* unbake published declaration: published_a62e20b13bff3b27e6380f1c */
struct func_8029AA48_S1 {
    char pad0[0x534];
    int unk534;
    char pad534[0x538 - 0x534 - sizeof(int)];
    int unk538;
};

struct func_8029BA34_S1;
/* unbake published declaration: published_dad22c052668db0c7926783f */
struct func_8029BA34_S1 {
    char pad0[0xC04];
    char unkC04;
};

struct func_8029AB74_S1;
/* unbake published declaration: published_efa88cfb46f09bef628d493f */
typedef struct func_8029AB74_S1 func_8029AB74_S1;

struct func_8029AB74_S1;
/* unbake published declaration: published_f0f6ba56be34b37feb45646d */
struct func_8029AB74_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
};

/* unbake published declaration: published_fb13880cc280f0d492647175 */
extern void func_8029AA24_de(int arg0);

struct func_8029AA48_S1;
/* unbake published declaration: published_fe671614dced83eb2325c961 */
typedef struct func_8029AA48_S1 func_8029AA48_S1;

#endif
