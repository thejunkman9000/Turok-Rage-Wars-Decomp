#include "b09_types.h"

void osMapTLB(s32 index, s32 pm, void *vaddr, u32 evenpaddr, u32 oddpaddr, s32 asid);

void osMapMainTLB(void) {
    osMapTLB(0x1F, 0x1FE000, (void *)0x200000, 0, 0x100000, 7);
}
