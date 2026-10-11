#include "common.h"

#define VIRT_TO_PHYS(field) \
    if (tp->t.field != NULL) { \
        tp->t.field = (void *)osVirtualToPhysical(tp->t.field); \
    }

OSTask *_VirtualToPhysicalTask(OSTask *intp) {
    OSTask *tp;

    tp = &__osTmpTask;
    memcpy(tp, intp, sizeof(OSTask));

    VIRT_TO_PHYS(ucode);
    VIRT_TO_PHYS(ucode_data);
    VIRT_TO_PHYS(dram_stack);
    VIRT_TO_PHYS(output_buff);
    VIRT_TO_PHYS(output_buff_size);
    VIRT_TO_PHYS(data_ptr);
    VIRT_TO_PHYS(yield_data_ptr);

    return tp;
}
