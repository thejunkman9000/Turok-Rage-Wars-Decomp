#ifndef UNBAKE_SPAN_1000_CODE_802B9ED8_H
#define UNBAKE_SPAN_1000_CODE_802B9ED8_H
#include "../types.h"
/* unbake published declaration: published_1c748a4b9ba22de5905145a1 */
extern int func_802B9FB0_de();

struct OSTask_t;
/* unbake published declaration: published_23bbe4adbbb375abf4ee69ae */
struct OSTask_t {
    u32 type;
    u32 flags;
    u64 *ucode_boot;
    u32 ucode_boot_size;
    u64 *ucode;
    u32 ucode_size;
    u64 *ucode_data;
    u32 ucode_data_size;
    u64 *dram_stack;
    u32 dram_stack_size;
    u64 *output_buff;
    u64 *output_buff_size;
    u64 *data_ptr;
    u32 data_size;
    u64 *yield_data_ptr;
    u32 yield_data_size;
};

/* unbake published declaration: published_619afe5ad2b129d1f33d1dd0 */
extern void func_802BA120_de();

struct OSTask_t;
/* unbake published declaration: published_7bb7b677401fd25aaf4a41db */
typedef struct OSTask_t OSTask_t;

union OSTask;
/* unbake published declaration: published_79294c2978afea05f2a740ae */
union OSTask {
    OSTask_t t;
    long long force_structure_alignment;
};

union OSTask;
/* unbake published declaration: published_eb4623119943ad8b670fcc6b */
typedef union OSTask OSTask;

/* unbake published declaration: published_a017e7b494c65b5761b1c1ac */
extern void func_802BA100_de(unsigned int arg0);

extern void func_802BA0FC_de(void);
extern s32 func_802B9FD0_de(s32 direction, s32 spAddress, s32 dramAddress, s32 size);
#endif
