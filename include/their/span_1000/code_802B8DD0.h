#ifndef UNBAKE_SPAN_1000_CODE_802B8DD0_H
#define UNBAKE_SPAN_1000_CODE_802B8DD0_H
#include "../types.h"
struct DeviceState;
/* unbake published declaration: published_016ba57dc086a16530780e51 */
struct DeviceState {
    struct DeviceState *previous;
    u8 type;
    u8 latency;
    u8 page_size;
    u8 release;
    u8 pulse;
    u8 domain;
    u8 pad_A[2];
    u32 address;
    u32 queue;
};

struct DeviceState;
/* unbake published declaration: published_cf9d731e8a5f92f421d3846b */
typedef struct DeviceState DeviceState;

/* unbake published declaration: published_448d2ab1c31f36cb69e5e531 */
extern void func_802B9A10_de(void);

struct PiTransfer802BE820;
/* unbake published declaration: published_5e4ee83d8c31c58ef7d927e3 */
typedef struct PiTransfer802BE820 PiTransfer802BE820;

/* unbake published declaration: published_691b48181189ba6737d49229 */
extern void func_802B9950_de();

struct PiTransfer802BE820;
/* unbake published declaration: published_a290c5fa1c41a2c63e2a3141 */
struct PiTransfer802BE820 {
    u8 pad0[5];
    u8 field5;
    u8 field6;
    u8 field7;
    u8 field8;
    u8 index;
    u8 padA[2];
    u32 address;
};

struct OSPiHandle_s_func_802B93B0_de;
/* unbake published declaration: published_aeaf8bf4e9874569d697e42c */
typedef struct OSPiHandle_s_func_802B93B0_de OSPiHandle_s_func_802B93B0_de;

struct OSPiHandle_s_func_802B93B0_de;
/* unbake published declaration: published_cc90623f38b4387fe9d1dc17 */
struct OSPiHandle_s_func_802B93B0_de {
    struct OSPiHandle_s_func_802B93B0_de *next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u32 baseAddress;
    u32 speed;
};

/* unbake published declaration: published_d5eb8459abc124429449418e */
extern void func_802B99A4_de(void);

struct OSPiHandle_s;
extern s32 func_802B9590_de(struct OSPiHandle_s *handle, u32 address, u32 *value);
#endif
