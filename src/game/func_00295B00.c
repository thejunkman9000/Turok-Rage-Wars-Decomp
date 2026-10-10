#include "span_1000/code_80294C64.h"



extern func_80295B00_S1 *D_8014AED0;

/** Compute a bit mask from the byte at offset 2 of the global record. */
int func_80295B00_us_rev1(void) {
    return 1 << D_8014AED0->unk2;
}
