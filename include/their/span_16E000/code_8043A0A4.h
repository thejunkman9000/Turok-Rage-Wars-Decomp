#ifndef UNBAKE_SPAN_16E000_CODE_8043A0A4_H
#define UNBAKE_SPAN_16E000_CODE_8043A0A4_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
#include "gfx.h"
/* unbake published declaration: published_27ad29a7c66d739b3c554ebd */
extern void func_8043B96C_de();

struct Entry_func_8043ACF0_de;
/* unbake published declaration: published_c4dafa7109a851237f92bbe0 */
struct Entry_func_8043ACF0_de {
    char pad0[0x4AC];
    s32 column;
    char pad4B0[0x4CC - 0x4B0];
    s32 mode;
};

struct Entry_func_8043ACF0_de;
struct Screen_func_8043ACF0_de;
/* unbake published declaration: published_2a96ee153672b4bd4c6f70a5 */
struct Screen_func_8043ACF0_de {
    void *window;
    s32 pad4;
    struct Entry_func_8043ACF0_de entries[4];
};

struct Entry_func_8043BA5C_de;
/* unbake published declaration: published_2f20b39c46452f23891e5601 */
struct Entry_func_8043BA5C_de {
    void *window;
    char pad4[0x4B4 - 0x4];
    s32 selection;
    s32 values[6];
    char pad4D0[0x4D0 - 0x4D0];
};

/* unbake published declaration: published_3592017a3bc4be89527e9d29 */
extern s32 func_8043C2D4_de(s32 *record);

struct Entry_func_8043B6E8_de;
/* unbake published declaration: published_a263ce98870e3e6ca3892437 */
struct Entry_func_8043B6E8_de {
    char pad0[0x4B0];
    s32 values[6];
    char pad4C8[0x4CC - 0x4C8];
    s32 mode;
};

struct Entry_func_8043B6E8_de;
struct Screen_func_8043B6E8_de;
/* unbake published declaration: published_4ac5fb5f0aef7b69d9238108 */
struct Screen_func_8043B6E8_de {
    void *window;
    s32 pad4;
    struct Entry_func_8043B6E8_de entries[4];
};

struct Entry_func_8043BCC0_de;
/* unbake published declaration: published_558ba6a37497237118560e87 */
struct Entry_func_8043BCC0_de {
    char pad[0x4B0];
    s32 state;
    char pad4B4[0x4D4 - 0x4B4];
    s32 nextActive;
};

struct ResultsPlayerPanel;
/* unbake published declaration: published_fe0e0d444d82e2c311b9feeb */
struct ResultsPlayerPanel {
    char pad0[0x4A8];
    s32 state;
    char pad4AC[0x4D0 - 0x4AC];
};

struct FourPlayerResultsScreen;
struct ResultsPlayerPanel;
/* unbake published declaration: published_5a90097030f177d8a0ed4b76 */
struct FourPlayerResultsScreen {
    char pad0[8];
    struct ResultsPlayerPanel panels[4];
    char pad1348[0x1358 - 0x1348];
    s32 state;
    char pad135C[0x1370 - 0x135C];
    char badges[4][0xC0];
};

struct Entry_func_8043BBB0_de;
/* unbake published declaration: published_5df084ac90490682f30cbe16 */
struct Entry_func_8043BBB0_de {
    char pad[0x4B0];
    s32 state;
    s32 selection;
    s32 values[6];
};

/* unbake published declaration: published_60504e89059d2773a9123683 */
extern s32 func_8043C2E0_de(s32 *record);

struct Entry_func_8043BA5C_de;
struct Screen_func_8043BA5C_de;
/* unbake published declaration: published_678fc437a4ad3bf3242b06cb */
struct Screen_func_8043BA5C_de {
    struct Entry_func_8043BA5C_de entries[4];
};

struct Entry_func_8043B0CC_de;
struct Resource_func_80419E54_de;
/* unbake published declaration: published_8d22fc19d02e14935d666c6b */
struct Entry_func_8043B0CC_de {
    char pad0[0x4A8];
    s32 open;
    s32 column;
    s32 values[6];
    struct Resource_func_80419E54_de *item;
    s32 mode;
};

struct ResultsPlayerPanel;
struct State_func_8043BF28_de;
/* unbake published declaration: published_a34cedca5053052dd6909a0e */
struct State_func_8043BF28_de {
    void *screen;
    void *menu;
    struct ResultsPlayerPanel players[4];
    char pad1348[0x10];
    int phase;
    int timer;
    char pad1360[8];
    int next;
};

/* unbake published declaration: published_b82d46ccf40b5ebb2430e644 */
extern s32 func_8043BA24_de();

struct State_func_8043BF28_de;
/* unbake published declaration: published_c47a047311cdd9a050e6c28f */
typedef struct State_func_8043BF28_de State_func_8043BF28_de;

struct Entry_func_8043B0CC_de;
struct Screen_func_8043B0CC_de;
/* unbake published declaration: published_c659142865552801922b15c0 */
struct Screen_func_8043B0CC_de {
    s32 window;
    s32 unk4;
    struct Entry_func_8043B0CC_de entries[4];
};

/* unbake published declaration: published_cda0e83c78fadb0f3aec384e */
extern s32 func_8043BFF0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Entry_func_8043BA24_de;
/* unbake published declaration: published_ef0b2320d90a7d0289392078 */
struct Entry_func_8043BA24_de {
    char pad[0x4B0];
    s32 state;
    char pad4B4[0x4D0 - 0x4B4];
};

struct Entry_func_8043BBB0_de;
struct Screen_func_8043BBB0_de;
/* unbake published declaration: published_fb2f21316f66487e8fb335c4 */
struct Screen_func_8043BBB0_de {
    struct Entry_func_8043BBB0_de entries[4];
};

extern int func_8043B854_de();
#endif
