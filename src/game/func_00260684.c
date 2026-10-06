#include "b14_types.h"
u32 func_00260684(u32 x) {
    return (x & 0xF0000000) | ((x & 0x0FFFFFFF) << 3);
}
