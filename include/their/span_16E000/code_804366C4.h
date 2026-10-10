#ifndef UNBAKE_SPAN_16E000_CODE_804366C4_H
#define UNBAKE_SPAN_16E000_CODE_804366C4_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct Frame_func_804217D4_de;
struct Menu_func_804241BC_de;
struct State_func_80437444_de;
/* unbake published declaration: published_04c9e579a382217a5a49b2eb */
struct State_func_80437444_de {
    struct Menu_func_804241BC_de *menu;
    char pad4[0x8 - 0x4];
    struct Frame_func_804217D4_de *list;
    s32 delay;
    s32 target;
    s32 seen;
};

struct Menu_func_80437718_de;
struct Resource_func_80419E54_de;
/* unbake published declaration: published_0cbd278e3af94cc365db698c */
struct Menu_func_80437718_de {
    void *title;
    void *button;
    struct Resource_func_80419E54_de *item;
    s32 count;
    s32 selection;
};

/* unbake published declaration: published_155befbf380050b32cf65748 */
extern s32 func_80436E04_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct MenuListScreen;
/* unbake published declaration: published_1a082dcb5b9665912745b7f1 */
typedef struct MenuListScreen MenuListScreen;

/* unbake published declaration: published_2fd4381f7a6105fdeabd2770 */
extern s32 func_80437274_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct State_func_80436BF4_de;
/* unbake published declaration: published_522f83daaf4bfe2a001d5ec3 */
struct State_func_80436BF4_de {
    void *first;
    char pad4[0x20 - 4];
    s32 value;
    char pad24[0x28 - 0x24];
    s32 item;
};

struct MenuListScreen;
/* unbake published declaration: published_cba34d1af31b6bf00850302b */
struct MenuListScreen {
    void *panels[2];
    void *listB;
    void *listA;
    void *listC;
    s32 selection;
    void *window;
};

struct State_func_804368F8_de;
/* unbake published declaration: published_df8235a0fd1bf75c6b5eb5b6 */
struct State_func_804368F8_de {
    void *c;
    void *d;
    void *b;
    void *a;
    void *e;
};

struct State_func_804366B8_de;
/* unbake published declaration: published_e8caf44339850c40633c9ddc */
struct State_func_804366B8_de {
    char pad0[8];
    void *c;
    void *d;
    void *b;
    void *a;
    void *e;
};


/* Exact localized menu callbacks, bound to current native/consumer receipts. */
extern s32 func_80437114_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_80436C94_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_80436D4C_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_804371C4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_80438F0C_de(void);
#endif
