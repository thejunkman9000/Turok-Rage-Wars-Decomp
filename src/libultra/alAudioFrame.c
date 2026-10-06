#include "libaudio.h"

s32 __nextSampleTime(ALSynth *drvr, ALPlayer **client);
s32 _timeToSamplesNoRound_2(ALSynth *synth, s32 micros);
void _collectPVoices(ALSynth *drvr);

Acmd *alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen) {
    ALPlayer *client;
    ALSynth *drvr = &alGlobalsp->drvr;
    s16 outp = 0;
    s32 samplesLeft = outLen;
    Acmd *cmdp = cmdList;
    s16 *lOutBuf = outBuf;
    s32 samples;
    ALFilter *sink;
    s32 delta;
    if (drvr->head == 0) {
        *cmdLen = 0;
        return cmdList;
    }
    drvr->paramSamples = __nextSampleTime(drvr, &client);
    while (drvr->paramSamples - drvr->curSamples < samplesLeft) {
        drvr->paramSamples &= ~0xF;
        delta = ((s32 (*)(ALPlayer *))client->handler)(client);
        client->samplesLeft += _timeToSamplesNoRound_2(drvr, delta);
        drvr->paramSamples = __nextSampleTime(drvr, &client);
    }
    drvr->paramSamples &= ~0xF;
    while (samplesLeft > 0) {
        if (samplesLeft > drvr->maxOutSamples) {
            samples = drvr->maxOutSamples;
        } else {
            samples = samplesLeft;
        }
        cmdp->w0 = 0x07000000;
        cmdp->w1 = 0;
        sink = drvr->saveBus;
        sink->setParam(sink, 6, lOutBuf);
        cmdp = sink->handler(sink, &outp, samples, drvr->curSamples, cmdp + 1);
        do {
            samplesLeft -= samples;
            lOutBuf += samples << 1;
            drvr->curSamples += samples;
        } while (0);
    }
    *cmdLen = cmdp - cmdList;
    _collectPVoices(drvr);
    return cmdp;
}
