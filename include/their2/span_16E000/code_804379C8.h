#ifndef UNBAKE_SPAN_16E000_CODE_804379C8_H
#define UNBAKE_SPAN_16E000_CODE_804379C8_H
#include "../types.h"
/* unbake published declaration: published_3bddf339a1debac892b63926 */
extern void func_80438A88_de();

struct State_func_80438C84_de;
/* unbake published declaration: published_5a6a5174221f949a86c2fa40 */
struct State_func_80438C84_de {
    char pad[0x24];
    void *item;
    char pad28[0x90 - 0x28];
    s32 started;
    char pad94[0x1C0 - 0x94];
    s32 busy;
};

struct State_func_80438A88_de;
/* unbake published declaration: published_9f79018f007db4b2dd23ca28 */
struct State_func_80438A88_de {
    char pad0[0x9C];
    s32 first;
    char padA0[0xB0 - 0xA0];
    s32 second;
    char padB4[0x188 - 0xB4];
    s32 third;
};

struct MenuSelectionMessage;
/* unbake published declaration: published_a155879ea99d20f486fdc5bb */
struct MenuSelectionMessage {
    void *first;
    s32 pad4[3];
    s32 value;
};

struct State_func_80439018_de;
/* unbake published declaration: published_a7ef845622ab039cd2f70964 */
struct State_func_80439018_de {
    void *menu;
    char pad4[0x8 - 0x4];
    void *music;
    void *effects;
    char pad10[0x14 - 0x10];
    s32 target;
};

struct MenuSelectionMessage;
/* unbake published declaration: published_afb448bf4ad50d1be421a5f8 */
typedef struct MenuSelectionMessage MenuSelectionMessage;

/* unbake published declaration: published_d86467481bccdb757d1e00c2 */
extern s32 func_804391B0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_e586bef6cab034da840f52f6 */
extern s32 func_80438E7C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_eac0a13627ab994dbf330832 */
extern void func_804389C4_de(void);

struct State_func_80439128_de;
/* unbake published declaration: published_f80c209c9ab67e1462b3cdf5 */
struct State_func_80439128_de {
    void *first;
    char pad4[0x14 - 4];
    s32 value;
};

#endif
