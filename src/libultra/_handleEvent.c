#include "synth_types.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);
s32 alSynAllocVoice(ALSynth *drvr, ALVoice *voice, ALVoiceConfig *vc);
void alSynStartVoice(ALSynth *drvr, ALVoice *voice, void *w);
void alSynSetPan(ALSynth *drvr, ALVoice *voice, u8 pan);
void alSynSetVol(ALSynth *drvr, ALVoice *voice, s16 vol, s32 time);
void alSynSetPitch(ALSynth *drvr, ALVoice *voice, f32 pitch);
void alSynSetFXMix(ALSynth *drvr, ALVoice *voice, u8 fxmix);
void alSynStopVoice(ALSynth *drvr, ALVoice *voice);
void alSynFreeVoice(ALSynth *drvr, ALVoice *voice);
void _removeEvents(ALEventQueue *evtq, ALSndState *state);
s32 __sndpTimeAtPitch(s32 time, f32 pitch);

void _handleEvent(ALSndPlayer *sndp, ALEvent *event) {
    ALSndState *state = (ALSndState *)event->msg.sndp.state;
    ALSndSound *sound = state->sound;
    ALVoiceConfig config;
    ALEvent evt;
    u8 pan;
    s32 vol;
    s32 envVol;
    s16 panTmp;
    s32 delta;
    f32 pitch;
    s16 newVol;
    f32 newPitch;
    switch (event->type) {
    case AL_SNDP_PLAY_EVT:
        if (state->state != AL_STOPPED) {
            break;
        }
        if (sound == 0) {
            break;
        }
        config.fxBus = 0;
        config.priority = state->priority;
        config.unityPitch = 0;
        alSynAllocVoice(sndp->drvr, &state->voice, &config);
        vol = (sound->envelope->attackVolume * state->vol) / 127;
        panTmp = sound->samplePan + (state->pan - 64);
        if (panTmp < 0) {
            panTmp = 0;
        }
        pan = (panTmp < 127) ? panTmp : 127;
        delta = sound->envelope->attackTime;
        pitch = state->pitch;
        alSynStartVoice(sndp->drvr, &state->voice, sound->wavetable);
        state->state = AL_PLAYING;
        alSynSetPan(sndp->drvr, &state->voice, pan);
        alSynSetVol(sndp->drvr, &state->voice, vol, delta);
        alSynSetPitch(sndp->drvr, &state->voice, pitch);
        alSynSetFXMix(sndp->drvr, &state->voice, state->fxMix);
        evt.type = AL_SNDP_DECAY_EVT;
        evt.msg.sndp.state = (ALSoundState *)state;
        alEvtqPostEvent(&sndp->evtq, &evt, __sndpTimeAtPitch(sound->envelope->attackTime, state->pitch));
        break;
    case AL_SNDP_STOP_EVT:
        if (state->state != AL_PLAYING) {
            break;
        }
        if (sound == 0) {
            break;
        }
        delta = __sndpTimeAtPitch(sound->envelope->releaseTime, state->pitch);
        alSynSetVol(sndp->drvr, &state->voice, 0, delta);
        if (delta != 0) {
            evt.type = AL_SNDP_END_EVT;
            evt.msg.sndp.state = (ALSoundState *)state;
            alEvtqPostEvent(&sndp->evtq, &evt, delta);
            state->state = AL_STOPPING;
        } else {
            alSynStopVoice(sndp->drvr, &state->voice);
            alSynFreeVoice(sndp->drvr, &state->voice);
            _removeEvents(&sndp->evtq, state);
            state->state = AL_STOPPED;
        }
        break;
    case AL_SNDP_PAN_EVT:
        state->pan = event->msg.sndpan.pan;
        if (state->state != AL_PLAYING) {
            break;
        }
        if (sound == 0) {
            break;
        }
        panTmp = sound->samplePan + (state->pan - 64);
        if (panTmp < 0) {
            panTmp = 0;
        }
        pan = (panTmp < 127) ? panTmp : 127;
        alSynSetPan(sndp->drvr, &state->voice, pan);
        break;
    case AL_SNDP_PITCH_EVT:
        newPitch = event->msg.sndpitch.pitch;
        state->pitch = newPitch;
        if (newPitch < 0.0001f) {
            state->pitch = 0.0001f;
        }
        if (state->state != AL_PLAYING) {
            break;
        }
        alSynSetPitch(sndp->drvr, &state->voice, state->pitch);
        break;
    case AL_SNDP_FX_EVT:
        state->fxMix = event->msg.sndfx.fxmix;
        if (state->state != AL_PLAYING) {
            break;
        }
        alSynSetFXMix(sndp->drvr, &state->voice, state->fxMix);
        break;
    case AL_SNDP_VOL_EVT:
        newVol = event->msg.sndvol.vol;
        state->vol = newVol;
        if (state->state != AL_PLAYING) {
            break;
        }
        if (sound == 0) {
            break;
        }
        envVol = (sound->envelope->decayVolume * newVol) / 127;
        alSynSetVol(sndp->drvr, &state->voice, envVol, 1000);
        break;
    case AL_SNDP_DECAY_EVT:
        if (sound->envelope->decayTime == -1) {
            break;
        }
        envVol = (sound->envelope->decayVolume * state->vol) / 127;
        delta = __sndpTimeAtPitch(sound->envelope->decayTime, state->pitch);
        alSynSetVol(sndp->drvr, &state->voice, envVol, delta);
        evt.type = AL_SNDP_STOP_EVT;
        evt.msg.sndp.state = (ALSoundState *)state;
        alEvtqPostEvent(&sndp->evtq, &evt, delta);
        break;
    case AL_SNDP_END_EVT:
        alSynStopVoice(sndp->drvr, &state->voice);
        alSynFreeVoice(sndp->drvr, &state->voice);
        _removeEvents(&sndp->evtq, state);
        state->state = AL_STOPPED;
        break;
    }
}
