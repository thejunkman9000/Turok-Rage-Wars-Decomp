#include "libaudio.h"
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

/* port debug: log sound-effect starts */
void alSndpPlay(ALSndPlayer *sndp) {
    ALEvent evt;
    static int n;
    { extern unsigned long long port_audio_pushed(void); if (n++ < 60) fprintf(__acrt_iob_func(2), "alSndpPlay(sndp=%p target=%d) wav_byte=%llu\n", (void *)sndp, (int)sndp->target, port_audio_pushed()); }
    evt.type = AL_SNDP_PLAY_EVT;
    evt.msg.sndp.state = sndp->sndState + sndp->target;
    alEvtqPostEvent(&sndp->evtq, &evt, 0);
}
