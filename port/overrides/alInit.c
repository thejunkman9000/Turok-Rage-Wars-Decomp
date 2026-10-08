#include "libaudio.h"
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
void alSynNew(ALSynth *drvr, void *config);

/* port debug: log the audio library initialisation */
void alInit(ALGlobals *glob, void *config) {
    fprintf(__acrt_iob_func(2), "alInit(glob=%p cfg=%p) alGlobalsp=%p\n", (void *)glob, config, (void *)alGlobalsp);
    if (alGlobalsp == 0) {
        alGlobalsp = glob;
        alSynNew(&glob->drvr, config);
    }
    fprintf(__acrt_iob_func(2), "alInit done: alGlobalsp=%p\n", (void *)alGlobalsp);
}
