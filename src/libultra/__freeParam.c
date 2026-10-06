#include "libaudio.h"

void __freeParam(ALParam *param) {
    param->next = alGlobalsp->drvr.paramList;
    alGlobalsp->drvr.paramList = param;
}
