#include "libaudio.h"

s32 alSaveParam(void *filter, s32 paramID, void *param) {
    ALSave *f = (ALSave *)filter;
    switch (paramID) {
    case 1:
        f->filter.source = (ALFilter *)param;
        break;
    case 6:
        f->dramout = (s32)param;
        break;
    }
    return 0;
}
