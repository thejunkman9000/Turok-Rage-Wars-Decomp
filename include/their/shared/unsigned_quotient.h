#ifndef RW_UNSIGNED_QUOTIENT_H
#define RW_UNSIGNED_QUOTIENT_H
#include "types.h"
/* ROM normalized unsigned division: O32 a0:a1 and a2:a3 operands,
 * v0:v1 quotient. The divisor must be nonzero. */
u64 func_802C0DA0_de(u64 numerator, u64 divisor);
#endif
