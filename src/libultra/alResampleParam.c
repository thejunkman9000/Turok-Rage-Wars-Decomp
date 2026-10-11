#include "s1013_types.h"

/* alResampleParam (libaudio resample.c): control messages of the resampler filter */
s32 alResampleParam(void *filter, s32 paramID, void *param)
{
    S13Resampler *f = (S13Resampler *)filter;

    switch (paramID) {
        case AL_FILTER_SET_SOURCE:
            ((ALFilter *)filter)->source = (ALFilter *)param;
            break;

        case AL_FILTER_RESET:
            f->delta = 0;
            f->first = 1;
            f->motion = 0;
            f->upitch = 0;
            if (((ALFilter *)filter)->source)
                (*((ALFilter *)filter)->source->setParam)(((ALFilter *)filter)->source, AL_FILTER_RESET, 0);
            break;

        case AL_FILTER_START:
            f->motion = 1;
            if (((ALFilter *)filter)->source)
                (*((ALFilter *)filter)->source->setParam)(((ALFilter *)filter)->source, AL_FILTER_START, 0);
            break;

        case AL_FILTER_SET_PITCH:
            *(void **)&f->ratio = param;
            break;

        case AL_FILTER_SET_UNITY_PITCH:
            f->upitch = 1;
            break;

        default:
            if (((ALFilter *)filter)->source)
                (*((ALFilter *)filter)->source->setParam)(((ALFilter *)filter)->source, paramID, param);
            break;
    }
    return 0;
}
