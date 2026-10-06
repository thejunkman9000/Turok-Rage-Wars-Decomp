#include "common.h"
OSTask *_VirtualToPhysicalTask(OSTask *intp);

#define HEAD \
    OSTask *tp; \
    tp = _VirtualToPhysicalTask(intp); \
    if (tp->t.flags & OS_TASK_YIELDED) { \
        tp->t.ucode_data = tp->t.yield_data_ptr; \
        tp->t.ucode_data_size = tp->t.yield_data_size; \
        intp->t.flags &= ~OS_TASK_YIELDED; \
        if (tp->t.flags & OS_TASK_LOADABLE) { \
            tp->t.ucode = (u64 *)IO_READ((u32)intp->t.yield_data_ptr + OS_YIELD_DATA_SIZE - 4); \
        } \
    } \
    osWritebackDCache(tp, sizeof(OSTask)); \
    __osSpSetStatus(SPSTATUS_CLEAR_SIGNAL0 | SPSTATUS_CLEAR_SIGNAL1 | SPSTATUS_CLEAR_SIGNAL2 | SPSTATUS_SET_INTR_ON_BREAK); \
    while (__osSpSetPc(SP_IMEM_START) == -1) \
        ; \
    while (__osSpRawStartDma(1, (SP_IMEM_START - sizeof(*tp)), tp, sizeof(OSTask)) == -1) \
        ; \
    while (__osSpDeviceBusy()) \
        ;

void v1(OSTask *intp) {
    HEAD
    while (__osSpRawStartDma(1, SP_IMEM_START, tp->t.ucode_boot, tp->t.ucode_boot_size) == -1)
        ;
}

/* args pulled into locals first */
void v2(OSTask *intp) {
    HEAD
    {
        void *boot = tp->t.ucode_boot;
        u32 bootsz = tp->t.ucode_boot_size;
        while (__osSpRawStartDma(1, SP_IMEM_START, boot, bootsz) == -1)
            ;
    }
}

/* store the address in a variable */
void v3(OSTask *intp) {
    void *imem = SP_IMEM_START;
    HEAD
    while (__osSpRawStartDma(1, imem, tp->t.ucode_boot, tp->t.ucode_boot_size) == -1)
        ;
}

/* do-while form */
void v4(OSTask *intp) {
    HEAD
    do {
    } while (__osSpRawStartDma(1, SP_IMEM_START, tp->t.ucode_boot, tp->t.ucode_boot_size) == -1);
}
