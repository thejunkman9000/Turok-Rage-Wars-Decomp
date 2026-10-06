#include "libaudio.h"

void alFilterNew(ALFilter *f, void *handler, void *setParam, s32 type) {
    f->source = 0;
    f->handler = handler;
    f->setParam = setParam;
    f->inp = 0;
    f->outp = 0;
    f->type = type;
}
