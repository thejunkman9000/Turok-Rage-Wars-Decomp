#include "span_1000/code_802BA13C.h"
#include "common/types_8fd754e1e915.h"

s32 func_802BA140_de(void *arg0)
{
    s32 selected_bit;
    u32 status;
    func_80203E78_S1 *state = arg0;

    status = func_802BA190_de();
    selected_bit = status >> 8;
    selected_bit = selected_bit & 1;
    if (status & 0x80) {
        state->unk4 = (state->unk4 | selected_bit) & ~2;
    }
    return selected_bit;
}
