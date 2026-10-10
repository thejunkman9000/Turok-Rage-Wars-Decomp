#ifndef UNBAKE_SPAN_1000_CODE_80291054_H
#define UNBAKE_SPAN_1000_CODE_80291054_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
struct Display;
/* unbake published declaration: published_0fd98bf960b45acfd833434e */
typedef struct Display Display;

struct func_8029397C_S1;
/* unbake published declaration: published_3645ac10d621d5d4c01f94b1 */
typedef struct func_8029397C_S1 func_8029397C_S1;

struct func_80293808_S1;
/* unbake published declaration: published_3c1cacc6f192a8c9b6326042 */
typedef struct func_80293808_S1 func_80293808_S1;

/* unbake published declaration: published_3cdbff6879bce9c9a2ab8852 */
extern int func_802934F8_de();

struct func_80292FA4_S1;
/* unbake published declaration: published_4077c793b43c9752f3dc2e34 */
struct func_80292FA4_S1 {
    char pad0[0x26DC8];
    s32 unk26DC8;
};

struct func_8029382C_S1;
/* unbake published declaration: published_4a819c0526e74e88d318681c */
struct func_8029382C_S1 {
    char pad0[0x26DB8];
    s32 unk26DB8;
};

struct func_8029382C_S1;
/* unbake published declaration: published_4d7de0f9d6453472f1191d24 */
typedef struct func_8029382C_S1 func_8029382C_S1;

struct func_8029397C_S1;
/* unbake published declaration: published_5d6a53ce6aca0fe0d6602582 */
struct func_8029397C_S1 {
    char pad0[0x25580];
    char unk25580;
    char pad25580[0x255C8 - 0x25580 - sizeof(char)];
    char unk255C8;
};

struct func_80293318_S1;
/* unbake published declaration: published_61b0a77aee19a2a7c58048f1 */
typedef struct func_80293318_S1 func_80293318_S1;

/* unbake published declaration: published_6bf82944fbfe4b286fdb3ae0 */
extern int D_800CD8A4_de;

struct func_80293574_S1;
/* unbake published declaration: published_804feeae8b7b85c197d0734d */
typedef struct func_80293574_S1 func_80293574_S1;

/* unbake published declaration: published_8a6ac023de9f334a61bc8c6e */
extern int D_800CD8A0_de;

struct func_80293808_S1;
/* unbake published declaration: published_91c6264069f0a0f79636a6e0 */
struct func_80293808_S1 {
    char pad0[0x26DBC];
    int unk26DBC;
    char pad26DBC[0x26DC1 - 0x26DBC - sizeof(int)];
    char unk26DC1;
};

struct func_80293574_S1;
/* unbake published declaration: published_a969d25acea0e2bb2094f780 */
struct func_80293574_S1 {
    char pad0[0x26DC0];
    unsigned char unk26DC0;
    char pad26DC0[0x26DC1 - 0x26DC0 - sizeof(unsigned char)];
    unsigned char unk26DC1;
    char pad26DC1[0x26DC4 - 0x26DC1 - sizeof(unsigned char)];
    int unk26DC4;
};

struct Frame_func_80293054_de;
/* unbake published declaration: published_e5f286caa67cf392cdd8de4b */
typedef struct Frame_func_80293054_de Frame_func_80293054_de;

struct Frame_func_80293054_de;
/* unbake published declaration: published_eccebbbb0d65e122e5872dcb */
struct Frame_func_80293054_de {
    char pad[0x114];
    int color;
    int depth;
    char tail[0x24];
};

struct Display;
/* unbake published declaration: published_afcf2dcf7c351aa917924e07 */
struct Display {
    Frame_func_80293054_de frames[3];
    void *current;
};

struct func_80293318_S1;
/* unbake published declaration: published_b3fbcd7de143532b89a79b09 */
struct func_80293318_S1 {
    char pad0[0x25580];
    char unk25580;
};

/* unbake published declaration: published_c4abeef3d1583fdb7f07fb18 */
extern void func_80292F24_de();

struct func_80293774_S1;
/* unbake published declaration: published_c8e779b7c5f22d8127615cbb */
struct func_80293774_S1 {
    char pad0[0x26DB4];
    s32 unk26DB4;
    char pad26DB4[0x26DB8 - 0x26DB4 - sizeof(s32)];
    s32 unk26DB8;
    char pad26DB8[0x26DBC - 0x26DB8 - sizeof(s32)];
    s32 unk26DBC;
    char pad26DBC[0x26DC1 - 0x26DBC - sizeof(s32)];
    s8 unk26DC1;
    char pad26DC1[0x26DC4 - 0x26DC1 - sizeof(s8)];
    func_8022E280_S1_U744 unk26DC4;
};

struct func_80292FA4_S1;
/* unbake published declaration: published_cd6c7a396b019aca3825eb7b */
typedef struct func_80292FA4_S1 func_80292FA4_S1;

/* unbake published declaration: published_cf06f9b66119d7029a55f461 */
extern int D_800CD8B4;

/* unbake published declaration: published_fddc33ee549b0bb776d2824d */
extern int D_800CD734;

struct func_80293774_S1;
/* unbake published declaration: published_fe6cae11158326e3f0f58391 */
typedef struct func_80293774_S1 func_80293774_S1;

extern float func_802917D8_de();
extern void func_80293534_de(void);

typedef struct func_80293904_S1 {
    char pad0[0x26DB0];
    f32 unk26DB0;
    char pad26DB4[0x26DBC - 0x26DB4];
    s32 unk26DBC;
    char pad26DC0[1];
    s8 unk26DC1;
} func_80293904_S1;

#endif
