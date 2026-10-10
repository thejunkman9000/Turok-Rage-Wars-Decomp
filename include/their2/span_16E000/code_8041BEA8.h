#ifndef UNBAKE_SPAN_16E000_CODE_8041BEA8_H
#define UNBAKE_SPAN_16E000_CODE_8041BEA8_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
struct Label;
/* unbake published declaration: published_071e2f1d45bdec4a8ab958eb */
typedef struct Label Label;

struct State_func_8041C40C_de;
/* unbake published declaration: published_08273769c2fd90ce34054da8 */
struct State_func_8041C40C_de {
    char pad[0x14];
    int ticks;
    int paused;
};

struct State_func_8041DE5C_de;
/* unbake published declaration: published_0d9f3fe8e9c92e657e2f8529 */
struct State_func_8041DE5C_de {
    char pad[0xD8];
    s32 first;
    s32 second;
};

/* unbake published declaration: published_127bbe14566499ab730b1755 */
extern s32 func_8041C574_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Game_func_8041D960_de;
/* unbake published declaration: published_1abe4f103ac74272f1de8d3f */
struct Game_func_8041D960_de {
    char pad0[0x17C1];
    u8 language;
};

struct Menu_func_8041D960_de;
/* unbake published declaration: published_27699676947040539e4792a0 */
typedef struct Menu_func_8041D960_de Menu_func_8041D960_de;

struct Obj_func_8041CDB0_de;
/* unbake published declaration: published_2e841e8bd63a1fe476f13279 */
struct Obj_func_8041CDB0_de {
    char pad[0x480];
    Vec3 unk480;
};

struct ProfileStatisticsScreen;
/* unbake published declaration: published_317eed37e97172535e206606 */
typedef struct ProfileStatisticsScreen ProfileStatisticsScreen;

/* unbake published declaration: published_38a059cd0693171835a9e7f2 */
extern void func_8041D960_de();

/* unbake published declaration: published_3b623652acff665a1fcb4161 */
extern void func_8041D6A8_de();

struct Object49C;
/* unbake published declaration: published_3ce97c189eaa8a35c93b2743 */
struct Object49C {
    char pad[0x49C];
    s32 value;
};

struct Obj_func_8041CDDC_de;
/* unbake published declaration: published_c03ba07b361362cc033e49fc */
struct Obj_func_8041CDDC_de {
    char pad[0x48C];
    Vec3 unk48C;
};

struct Obj_func_8041CDDC_de;
/* unbake published declaration: published_faaa3561751720687cd8bf8e */
typedef struct Obj_func_8041CDDC_de Obj_func_8041CDDC_de;

/* unbake published declaration: published_453a28f8fab805b037759d74 */
extern void func_8041CDDC_de(Obj_func_8041CDDC_de *arg0, Vec3 v);

struct Menu_func_8041DA5C_de;
/* unbake published declaration: published_4aea74a399b126083e1269ea */
typedef struct Menu_func_8041DA5C_de Menu_func_8041DA5C_de;

struct Menu_func_8041D134_de;
/* unbake published declaration: published_553a59590ee337c0876044af */
typedef struct Menu_func_8041D134_de Menu_func_8041D134_de;

struct Obj_func_8041CDB0_de;
/* unbake published declaration: published_59c3ea2741e8bd9e5b53f71e */
typedef struct Obj_func_8041CDB0_de Obj_func_8041CDB0_de;

struct Node_func_8041DA5C_de;
/* unbake published declaration: published_5f01b9834d0f09cd81cb2512 */
struct Node_func_8041DA5C_de {
    char pad0[0x10];
    s8 style;
};

struct Unk8041CE88;
/* unbake published declaration: published_8113e883cb62106f01388ee9 */
typedef struct Unk8041CE88 Unk8041CE88;

struct Unk8041CE88;
/* unbake published declaration: published_ec2927588dc4a69b52deebd2 */
struct Unk8041CE88 {
    char pad0[0x274];
    u16 unk274;
};

/* unbake published declaration: published_62c6359553cd46d9a2b9650c */
extern void func_8041CE18_de(Unk8041CE88 *arg0);

struct Obj_func_8041CE08_de;
/* unbake published declaration: published_70698890fb9475b91dbc443a */
struct Obj_func_8041CE08_de {
    char pad[0x498];
    s32 unk498;
};

/* unbake published declaration: published_73815b73f51585dd35385fad */
extern s32 func_8041C164_de();

struct Menu_func_8041DA5C_de;
/* unbake published declaration: published_7683e5fb2f8f5c3f5e4daf26 */
struct Menu_func_8041DA5C_de {
    void *root;
    char pad4[0x108];
    s32 player;
};

struct Unk8041CE88;
/* unbake published declaration: published_7e2255239e4ebbc96ee7f100 */
extern void func_8041C610_de(struct Unk8041CE88 * arg0);

struct Obj_func_8041CE08_de;
/* unbake published declaration: published_dc21ac5814513660ea45a56a */
typedef struct Obj_func_8041CE08_de Obj_func_8041CE08_de;

/* unbake published declaration: published_80082b8a31d12a360dbc3674 */
extern void func_8041CE08_de(Obj_func_8041CE08_de *arg0, s32 arg1);

struct Game_func_8041D960_de;
/* unbake published declaration: published_8601cf4c300bd3bd57b1d9d3 */
typedef struct Game_func_8041D960_de Game_func_8041D960_de;

struct Node_func_8041D134_de;
/* unbake published declaration: published_868ac28517fd36d97ebb1bc8 */
typedef struct Node_func_8041D134_de Node_func_8041D134_de;

struct Menu_func_8041DBCC_de;
/* unbake published declaration: published_86ad0ccb9776044ba232d9bf */
struct Menu_func_8041DBCC_de {
    char pad0[8];
    char model[1];
};

struct ProfileStatisticsScreen;
/* unbake published declaration: published_92e0119e748ba31157756d0c */
struct ProfileStatisticsScreen {
    void *handle;
    char pad4[0x10C - 4];
    s32 index;
    char kills[0x32];
    char wins[0x32];
    char deaths[0x32];
    char score[0x32];
    char count[0x32];
};

/* unbake published declaration: published_a3de72094ac45d81601db810 */
extern void func_8041C19C_de();

struct State_func_8041C40C_de;
/* unbake published declaration: published_ac779ee07ad8933245dbcaa7 */
typedef struct State_func_8041C40C_de State_func_8041C40C_de;

struct Node_func_8041D134_de;
/* unbake published declaration: published_add903776511fb6736aa4249 */
struct Node_func_8041D134_de {
    char pad0[0x10];
    u8 style;
    char pad11[0x14 - 0x11];
    u16 x;
    u16 y;
};

struct Label;
struct Menu_func_8041D960_de;
/* unbake published declaration: published_adfc70e0f87b2d8ab0e4d1ad */
struct Menu_func_8041D960_de {
    char pad0[0xEC];
    func_8021C9B4_S3 *focus;
    struct Label *label;
    char padF4[0x18];
    s32 player;
};

struct List_func_8041BE28_de;
/* unbake published declaration: published_b086c1429dfd24b3abaafb3d */
typedef struct List_func_8041BE28_de List_func_8041BE28_de;

struct Menu_func_8041DBCC_de;
/* unbake published declaration: published_bf4fe46f1486a4bec126e50a */
typedef struct Menu_func_8041DBCC_de Menu_func_8041DBCC_de;

struct Screen_func_8041C2AC_de;
/* unbake published declaration: published_cf4890031d65c2f082cb5e7c */
struct Screen_func_8041C2AC_de {
    void *parent;
    void *windows[4];
    s32 selection;
    s32 scroll;
    s32 state;
};

struct List_func_8041BE28_de;
/* unbake published declaration: published_d8df106f71a3c295e4de8982 */
struct List_func_8041BE28_de {
    char pad[0x48];
    int count;
    void *items[1];
};

struct Node_func_8041DA5C_de;
/* unbake published declaration: published_f355bf5a73f691aff5221634 */
typedef struct Node_func_8041DA5C_de Node_func_8041DA5C_de;

struct State_func_8041DDF4_de;
/* unbake published declaration: published_f617c079db92b4971239d0a2 */
struct State_func_8041DDF4_de {
    char pad0[0xEC];
    s32 value;
};

/* unbake published declaration: published_f84563b8c4f5bb3134de663a */
extern void func_8041CDB0_de(Obj_func_8041CDB0_de *arg0, Vec3 v);

struct Menu_func_8041D134_de;
struct Node_func_8041D134_de;
/* unbake published declaration: published_fd732b3e3a790b74ed174ef5 */
struct Menu_func_8041D134_de {
    char pad0[4];
    void *handle;
    char pad8[0xC8 - 8];
    struct Node_func_8041D134_de *left;
    char padCC[2];
    u16 leftStep;
    struct Node_func_8041D134_de *right;
    char padD4[2];
    u16 rightStep;
    s32 state;
    s32 timer;
    s32 fade;
    struct Node_func_8041D134_de *groupA;
    struct Node_func_8041D134_de *cursor;
    struct Node_func_8041D134_de *focus;
    char padF0[4];
    struct Node_func_8041D134_de *groupB;
    s32 styleStep;
    s32 styleValue;
    struct Node_func_8041D134_de *groupC;
    char pad104[3];
    u8 alphaStep;
    s32 clock;
};

/* unbake published declaration: published_fe96fcbd09660d9f4acd172f */
extern void func_8041D4E0_de();

#endif
