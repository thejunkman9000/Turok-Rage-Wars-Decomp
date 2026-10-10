#ifndef UNBAKE_SPAN_1000_CODE_802BAC58_H
#define UNBAKE_SPAN_1000_CODE_802BAC58_H
#include "../types.h"
struct OSThread_s;
/* unbake published declaration: published_28089a3c7de105e8ea5e3d0d */
typedef struct OSThread_s OSThread_s;

struct ObjectLinks18_2;
/* unbake published declaration: published_4f53f53d76f2afdb74f936ea */
typedef struct ObjectLinks18_2 ObjectLinks18_2;

struct OSThreadContext;
/* unbake published declaration: published_55c9a8f14dcdadc01db7c115 */
typedef struct OSThreadContext OSThreadContext;

struct ObjectLinks18_2;
/* unbake published declaration: published_a756ed0fcf80dc7443452765 */
struct ObjectLinks18_2 {
    s32 *unk_0;
    s32 *unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
};

struct OSThreadContext;
/* unbake published declaration: published_e0e6c3cb3272195ee653d56e */
struct OSThreadContext {
    u64 at;
    u64 v0;
    u64 v1;
    u64 a0;
    u64 a1;
    u64 a2;
    u64 a3;
    u64 t0;
    u64 t1;
    u64 t2;
    u64 t3;
    u64 t4;
    u64 t5;
    u64 t6;
    u64 t7;
    u64 s0;
    u64 s1;
    u64 s2;
    u64 s3;
    u64 s4;
    u64 s5;
    u64 s6;
    u64 s7;
    u64 t8;
    u64 t9;
    u64 gp;
    u64 sp;
    u64 s8;
    u64 ra;
    u64 lo;
    u64 hi;
    u32 sr;
    u32 pc;
    u32 cause;
    u32 badvaddr;
    u32 rcp;
    u32 fpcsr;
};

struct OSThread_s;
/* unbake published declaration: published_de67a6594626ba0044c05b68 */
struct OSThread_s {
    struct OSThread_s *next;
    s32 priority;
    struct OSThread_s **queue;
    struct OSThread_s *tlnext;
    u16 state;
    u16 flags;
    s32 id;
    int fp;
    OSThreadContext context;
};

extern void func_802BAD68_de(void);
extern void func_802BB008_eu(void);
#endif
