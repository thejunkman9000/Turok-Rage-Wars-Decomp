#ifndef UNBAKE_SPAN_1000_CODE_80255BEC_H
#define UNBAKE_SPAN_1000_CODE_80255BEC_H
#include "../types.h"
/* unbake published declaration: published_058b8d18d1fddeccf7610040 */
/* Initializes an empty list whose nodes keep their links at the given offsets. */
extern void func_80255CA0_de(IntrusiveList *list, s32 prevOffset, s32 nextOffset);

/* Appends node at the tail and returns the new count. */
extern s32 func_80255D14_de(IntrusiveList *list, void *node);

extern void func_80255C4C_de(void *arg0, s32 *arg1, u32 *arg2);

/* unbake published declaration: published_174cc56f20dc62afad99ad94 */
extern void func_80255E24_de(void *arg0, s32 arg1, s32 arg2);

struct func_80256130_S1;
/* unbake published declaration: published_4a6616e05ecbbbd22a85ff69 */
typedef struct func_80256130_S1 func_80256130_S1;

union func_80255F34_S1_U4;
/* unbake published declaration: published_7d44a7794210c10e7d2c1778 */
union func_80255F34_S1_U4 {
    char * v0;
    int v1;
};

union func_80255F34_S1_U4;
/* unbake published declaration: published_a16b72f70d60e13f57e1dd3d */
typedef union func_80255F34_S1_U4 func_80255F34_S1_U4;

struct func_80255F34_S1;
/* unbake published declaration: published_65ec92bbb2b357bd381a3bd0 */
struct func_80255F34_S1 {
    char pad0[0x4];
    func_80255F34_S1_U4 unk4;
    char pad4[0x8 - 0x4 - sizeof(func_80255F34_S1_U4)];
    int unk8;
    char pad8[0x10 - 0x8 - sizeof(int)];
    int unk10;
};

struct func_80255BEC_S2;
/* unbake published declaration: published_7967c5469a73462b8cae8ae2 */
typedef struct func_80255BEC_S2 func_80255BEC_S2;

/* unbake published declaration: published_7e8031b54b653d8e39f33f86 */
extern void func_80255F94_de(void *arg0);

/* unbake published declaration: published_7faa7483c171e4920b76690f */


struct func_80256130_S1;
/* unbake published declaration: published_8375207b3ef61fefdc567a64 */
struct func_80256130_S1 {
    char pad0[0xC];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    u32 unk10;
};

struct func_80255F34_S1;
/* unbake published declaration: published_b71232c13d60e725abe0764a */
typedef struct func_80255F34_S1 func_80255F34_S1;

struct func_80255BEC_S2;
/* unbake published declaration: published_b7b294ea88f118c5df2ff2cb */
struct func_80255BEC_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x14 - 0x4 - sizeof(void*)];
    u32 unk14;
};

/* unbake published declaration: published_bf9ea302073ae247d1d487e6 */
extern void func_80256214_de(void *arg0);

/* unbake published declaration: published_d8f98b308dad9f6319839557 */
extern void func_802560A4_de(void *arg0, s32 arg1);

#endif
