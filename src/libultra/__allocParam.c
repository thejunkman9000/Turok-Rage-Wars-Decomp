#include "libaudio.h"

ALParam *__allocParam(void) {
    ALParam *update = 0;
    if (alGlobalsp->drvr.paramList != 0) {
        update = alGlobalsp->drvr.paramList;
        alGlobalsp->drvr.paramList = update->next;
        update->next = 0;
    }
    return update;
}
