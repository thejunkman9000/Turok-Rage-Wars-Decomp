#include "libaudio.h"

s32 __nextSampleTime(ALSynth *drvr, ALPlayer **client);
s32 _timeToSamplesNoRound_2(ALSynth *synth, s32 micros);
void _collectPVoices(ALSynth *drvr);

Acmd *alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen) {
    @@decl@@
    if (drvr->head == 0) {
        *cmdLen = 0;
        return cmdList;
    }
    @@init@@
    drvr->paramSamples = __nextSampleTime(drvr, &client);
    while (drvr->paramSamples - drvr->curSamples < samplesLeft) {
        drvr->paramSamples &= ~0xF;
        delta = ((s32 (*)(ALPlayer *))client->handler)(client);
        client->samplesLeft += _timeToSamplesNoRound_2(drvr, delta);
        drvr->paramSamples = __nextSampleTime(drvr, &client);
    }
    drvr->paramSamples &= ~0xF;
    while (samplesLeft > 0) {
        @@smp@@
        cmdp->w0 = 0x07000000;
        cmdp->w1 = 0;
        sink = drvr->saveBus;
        sink->setParam(sink, 6, outBuf);
        cmdp = sink->handler(sink, &outp, samples, drvr->curSamples, cmdp + 1);
        samplesLeft -= samples;
        outBuf += samples << 1;
        drvr->curSamples += samples;
    }
    *cmdLen = cmdp - cmdlistp;
    _collectPVoices(drvr);
    return cmdp;
}
