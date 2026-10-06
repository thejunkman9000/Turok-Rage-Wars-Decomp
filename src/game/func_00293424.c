#include "common.h"

s32 func_00293424(u8 *a, u8 *b) {
    if (a == NULL || b == NULL) {
        return -1;
    }
    while (*a != 0 && *b != 0) {
        if (*a < *b) {
            return -1;
        }
        if (*b < *a) {
            return 1;
        }
        a++;
        b++;
    }
    if (*a != 0) {
        return 1;
    }
    if (*b != 0) {
        return -1;
    }
    return 0;
}
