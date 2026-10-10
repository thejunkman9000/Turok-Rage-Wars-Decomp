#ifndef UNBAKE_SPAN_16E000_CODE_804290E8_H
#define UNBAKE_SPAN_16E000_CODE_804290E8_H
#include "../types.h"
struct Options;
/* unbake published declaration: published_249245fb980923e94bfa5fd8 */
struct Options {
    char pad[0x24];
    u8 values[5];
};

struct Screen_func_80429654_de;
/* unbake published declaration: published_285b328c5fb4aaa1c249c5cb */
struct Screen_func_80429654_de {
    char pad0[0x20];
    s32 cursor;
    char pad24[0x34 - 0x24];
    s32 list;
};

struct Options_func_80429560_de;
/* unbake published declaration: published_48f7b4ef01aeb22f99188ec4 */
struct Options_func_80429560_de {
    char pad[0x24];
    s8 val0;
    s8 val1;
    s8 val2;
    s8 val3;
    u8 val4;
};

/* unbake published declaration: published_7aa71184b70ff5f9d61f8ec6 */
extern void func_80429560_de();

struct func_804296A4_S1;
/* unbake published declaration: published_7bda6b07e68fe0f0df05ed8b */
typedef struct func_804296A4_S1 func_804296A4_S1;

/* unbake published declaration: published_94f1d8e3487730f2cc19a552 */
extern void func_804294C4_de();

/* unbake published declaration: published_bc2efbc08df30e2ec5535f4c */
extern s32 func_80429994_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_d579690f22bcf4722d31e722 */
extern s32 func_80428F08_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct func_804296A4_S1;
/* unbake published declaration: published_d63f14bc4e2ce2c55585296a */
struct func_804296A4_S1 {
    char pad0[0x1C];
    void * unk1C;
    char pad1C[0x24 - 0x1C - sizeof(void*)];
    void * unk24;
    char pad24[0x28 - 0x24 - sizeof(void*)];
    void * unk28;
    char pad28[0x2C - 0x28 - sizeof(void*)];
    void * unk2C;
    char pad2C[0x30 - 0x2C - sizeof(void*)];
    void * unk30;
};

struct Screen_func_80429560_de;
/* unbake published declaration: published_e86a0894f7ce4d87288dfa9b */
struct Screen_func_80429560_de {
    char pad0[0x1C];
    void *selectWidget;
    void *cursorWidget;
    void *widget24;
    void *widget28;
    void *widget2C;
    void *widget30;
    void *widget34;
    s32 countCap;
    s32 countDefault;
};

#endif
