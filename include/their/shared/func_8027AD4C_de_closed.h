#ifndef FUNC_8027AD4C_DE_CLOSED_H
#define FUNC_8027AD4C_DE_CLOSED_H
#include "span_C76B0/data.h"
#include "span_1000/code_8027A0F4.h"

/* Complete records from origin/legacy shared headers and source; historical gaps retained. */
typedef struct Shared_func_8027ADBC_S2 Shared_func_8027ADBC_S2;
struct Shared_func_8027ADBC_S2 {
    char pad0[0x8];
    Vec3 pos; /* +0x8: src/func_8027ADBC.c */
    char pad14[0x5C];
    f32 unk70; /* +0x70: src/func_8027ADBC.c */
    char pad74[0x166C];
    void * unk16E0; /* +0x16E0: src/func_8027ADBC.c */
};

typedef struct Shared_func_8027ADBC_S3 Shared_func_8027ADBC_S3;
struct Shared_func_8027ADBC_S3 {
    char pad0[0x8];
    Vec3 pos; /* +0x8: src/func_8027ADBC.c */
};

typedef struct Shared_func_8027ADBC_S6 Shared_func_8027ADBC_S6;
struct Shared_func_8027ADBC_S6 {
    char pad0[0x8];
    Vec3 pos; /* +0x8: src/func_8027ADBC.c */
};

typedef struct Shared_func_8027ADBC_S5 Shared_func_8027ADBC_S5;
struct Shared_func_8027ADBC_S5 { char pad0[0x10]; u16 unk10; u16 unk12; };

typedef struct Shared_func_8027ADBC_S4 Shared_func_8027ADBC_S4;
struct Shared_func_8027ADBC_S4 { u32 flags; char pad4[0xA]; s16 unkE; char pad10[0x20]; Shared_func_8027ADBC_S5 *unk30; };

/* Phase-1 candidate; target/descriptor layouts and helper ABI remain unresolved. */
typedef struct Shared_func_8027ADBC_S2 func_8027ADBC_S2;
typedef struct Shared_func_8027ADBC_S3 func_8027ADBC_S3;
typedef struct Shared_func_8027ADBC_S6 func_8027ADBC_S6;
extern f32 D_800C4BCC_de;








extern f32 D_800C4BE0_de;











void func_80228DC4_de(void *, void *);
f32 func_8024D284_de(void *);
f32 func_8024E420_de(void *);
void func_80270CD0_de(void *, f32, void *, void *);
void func_80271F34_de(void *, void *, void *);
void func_80271F68_de(void *, void *, void *);
void func_80271F9C_de(Vec3 *, Vec3 *, f32);
void func_8027207C_de(f32 *);
void func_80272748_de(void *, f32);
void func_80272898_de(void *, void *, void *);
void func_80274244_de(f32 *, f32 *);


void func_80279DD0_de(void *, f32);
#if defined(VERSION_EU)
float func_802AD520_eu(int);
#else
float func_802B2350(int);
#endif
f32 func_802B72B0_de(f32);
void func_80271818_de(void *, f32 *);            /* extern */
void func_8027A084_de(void *);                      /* extern */
void func_8027A4D0_de(void *);                      /* extern */
extern s32 D_80145040;
extern void *D_80145060;


#endif
