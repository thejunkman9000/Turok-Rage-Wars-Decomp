#ifndef UNBAKE_SPAN_1000_CODE_802BB15C_H
#define UNBAKE_SPAN_1000_CODE_802BB15C_H
#include "../types.h"
/* unbake published declaration: published_180e04857c059e42e1641a71 */
extern int D_8000030C;

/* unbake published declaration: published_41e95d4889098eace1d54847 */
extern void func_802BAE40_de();

/* unbake published declaration: published_6ad1ce4574a38e893c515c12 */
extern int func_802BB060_de(unsigned int devAddr, unsigned int * data);

struct Thread;
/* unbake published declaration: published_7a58736c21af88662e4a201e */
struct Thread {
    char pad0[0x10];
    u16 state;
};

struct Queue_func_802BB2A0_de;
/* unbake published declaration: published_8197e4cca83a7b4174e9157b */
typedef struct Queue_func_802BB2A0_de Queue_func_802BB2A0_de;

/* unbake published declaration: published_81c934ce1b71e07363601c80 */
extern int func_802BB0F0_de(unsigned int devAddr, unsigned int data);

struct OSThread_s_func_802BB5F0_de;
/* unbake published declaration: published_a81bc8abb7611bed490b47b1 */
typedef struct OSThread_s_func_802BB5F0_de OSThread_s_func_802BB5F0_de;

struct OSThread_s_func_802BB5F0_de;
/* unbake published declaration: published_bcd8d4d43e7b91239827e64e */
struct OSThread_s_func_802BB5F0_de {
    struct OSThread_s_func_802BB5F0_de *next;
    s32 priority;
    struct OSThread_s_func_802BB5F0_de **queue;
    struct OSThread_s_func_802BB5F0_de *tlnext;
    u16 state;
};

/* unbake published declaration: published_c0796d18766c3e456d7b5afa */
extern void func_802BB850_eu(s32 arg0);

struct Thread;
/* unbake published declaration: published_ebd4e16c3f135ff4013c6c32 */
typedef struct Thread Thread;

/* unbake published declaration: published_f06d8134f22c424460b894eb */
extern void func_802BB3D0_de(s32 arg0);

struct Queue_func_802BB2A0_de;
/* unbake published declaration: published_fb96e42317b04d9ecd949773 */
struct Queue_func_802BB2A0_de {
    void *mtqueue;
    void *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    void **msg;
};

#endif
