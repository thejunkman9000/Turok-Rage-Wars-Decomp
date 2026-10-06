#include "common.h"

OSMesgQueue *osPiGetCmdQueue(void) {
    if (!__osPiDevMgr.initialized) {
        return NULL;
    }
    return __osPiDevMgr.cmdQueue;
}
