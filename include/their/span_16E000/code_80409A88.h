#ifndef UNBAKE_SPAN_16E000_CODE_80409A88_H
#define UNBAKE_SPAN_16E000_CODE_80409A88_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_07a44697ba06cc8c499f9970 */
extern s32 func_8040A1B0_de(s32 arg0);

/* unbake published declaration: published_2b70cf46ad43d55c4a33c66d */
extern void func_8040A47C_de(void);

/* unbake published declaration: published_44abf24d3dd9d883afb93f30 */
extern void func_8040A748_de(void);

/* unbake published declaration: published_453dd610e0ca095dcea9d1ed */
extern void func_8040A764_de(void);

struct Target_func_8040A77C_de;
struct Target_func_8040A77C_de {
    char pad0[0xA8];
    s32 first;
    char padAC[0xD0 - 0xAC];
    s32 second;
};
struct Record_func_8040A77C_de;
struct Target_func_8040A77C_de;
/* unbake published declaration: published_cd9c08f89effdac569e27e56 */
struct Record_func_8040A77C_de {
    char pad[0xC];
    struct Target_func_8040A77C_de *target;
};

struct Record_func_8040A77C_de;
/* unbake published declaration: published_4636b1b3271bb165fbc6275c */
extern void func_8040A77C_de(struct Record_func_8040A77C_de *record);

struct Display_func_8040A4D4_de;
/* unbake published declaration: published_5daf7f021acdf92fd1fc6ea4 */
typedef struct Display_func_8040A4D4_de Display_func_8040A4D4_de;

/* unbake published declaration: published_6d3b2b6c4dcb82e4d3fe50fb */
extern void func_8040A490_de(void);

struct Record_func_80409EF4_de;
struct func_80242278_S1;
/* unbake published declaration: published_84515e9328c58a1da4549019 */
struct Record_func_80409EF4_de {
    char pad[0x1C];
    s32 result;
    struct func_80242278_S1 *inner;
};

struct Display_func_8040A4D4_de;
/* unbake published declaration: published_9ac5e2e4fb3242b6bc2c68de */
struct Display_func_8040A4D4_de {
    char pad[0x90];
    unsigned int depth;
};

/* unbake published declaration: published_af238bc082da7be000e434d9 */
extern char *func_8040A038_de(int unused, int kind);

struct Record_func_8040A6DC_de;
/* unbake published declaration: published_f7e591ba92a32bed0de811ca */
struct Record_func_8040A6DC_de {
    char pad[0x1C];
    s32 first;
    s32 second;
    void *resource;
};

struct Record_func_8040A6DC_de;
/* unbake published declaration: published_b1a85249db219f352b8931f4 */
extern s32 func_8040A6DC_de(void *unused, struct Record_func_8040A6DC_de *record);

struct Owner_func_804099EC_de;
/* unbake published declaration: published_c7331feb077b665139782554 */
extern void func_80409A5C_de(struct Owner_func_804099EC_de *owner);

struct Record_func_80409BDC_de;
/* unbake published declaration: published_d65b819d0e22085119fabad2 */
extern void func_80409F2C_de(struct Record_func_80409BDC_de *record);

struct Record_func_80409EF4_de;
/* unbake published declaration: published_f2e85cd90b5b006120bf0e01 */
extern s32 func_80409EF4_de(struct Record_func_80409EF4_de *record, s32 *out);

struct Record_func_80409BDC_de;
/* unbake published declaration: published_ffd2293097a24092b681d7a4 */
extern char *func_8040A09C_de(struct Record_func_80409BDC_de *menu);


struct Item_func_80441FE8_de;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8040A300_de(struct Item_func_80441FE8_de *field, struct Record_func_80409BDC_de *holder);
#endif

#endif
