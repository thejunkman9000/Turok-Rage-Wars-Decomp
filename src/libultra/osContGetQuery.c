#include "common.h"

void osContGetQuery(OSContStatus *data) {
    u8 pattern;

    __osContGetInitData(&pattern, data);
}
