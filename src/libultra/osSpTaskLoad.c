#include "common.h"

OSTask *_VirtualToPhysicalTask(OSTask *intp);

#ifdef NON_MATCHING
/* Functionally identical; the only difference is where the `lui $a1` of the final DMA call is scheduled
 * (the original hoists it above the two argument loads). */
void osSpTaskLoad(OSTask *intp) {
    OSTask *tp;

    tp = _VirtualToPhysicalTask(intp);

    if (tp->t.flags & OS_TASK_YIELDED) {
        tp->t.ucode_data = tp->t.yield_data_ptr;
        tp->t.ucode_data_size = tp->t.yield_data_size;
        intp->t.flags &= ~OS_TASK_YIELDED;

        if (tp->t.flags & OS_TASK_LOADABLE) {
            tp->t.ucode = (u64 *)IO_READ((u32)intp->t.yield_data_ptr + OS_YIELD_DATA_SIZE - 4);
        }
    }

    osWritebackDCache(tp, sizeof(OSTask));

    __osSpSetStatus(SPSTATUS_CLEAR_SIGNAL0 | SPSTATUS_CLEAR_SIGNAL1 | SPSTATUS_CLEAR_SIGNAL2 |
                    SPSTATUS_SET_INTR_ON_BREAK);

    while (__osSpSetPc(SP_IMEM_START) == -1)
        ;

    while (__osSpRawStartDma(1, SP_IMEM_START - sizeof(*tp), tp, sizeof(OSTask)) == -1)
        ;

    while (__osSpDeviceBusy())
        ;

    while (__osSpRawStartDma(1, SP_IMEM_START, tp->t.ucode_boot, tp->t.ucode_boot_size) == -1)
        ;
}
#else
INCLUDE_ASM("asm/nonmatchings/libultra/osSpTaskLoad", osSpTaskLoad);
#endif
