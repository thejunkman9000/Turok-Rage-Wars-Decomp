#include "s1013_types.h"

Acmd *alAdpcmPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p);
Acmd *alRaw16Pull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p);
Acmd *alAdecPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p);
void alCopy(void *src, void *dst, s32 len);

/* alLoadParam (libaudio load.c): set a load filter's wave table, choosing the pull handler and loop points by the
   table's type (this cartridge has no table length rounding and a third wave type, 2, handled by alAdecPull), or
   reset its decode state. */
s32 alLoadParam(void *filter, s32 paramID, void *param)
{
    S13Loader *a = (S13Loader *)filter;
    ALFilter *f = (ALFilter *)filter;

    switch (paramID) {
        case AL_FILTER_SET_WAVETABLE:
            a->table = (S13WaveTable *)param;
            a->memin = (s32)a->table->base;
            a->sample = 0;
            switch (a->table->type) {
                case AL_ADPCM_WAVE:
                    f->handler = (void *)alAdpcmPull;
                    a->bookSize = 2 * a->table->waveInfo.adpcmWave.book->order *
                                  a->table->waveInfo.adpcmWave.book->npredictors * 8;
                    if (a->table->waveInfo.adpcmWave.loop) {
                        a->loop.start = a->table->waveInfo.adpcmWave.loop->start;
                        a->loop.end = a->table->waveInfo.adpcmWave.loop->end;
                        a->loop.count = a->table->waveInfo.adpcmWave.loop->count;
                        alCopy(a->table->waveInfo.adpcmWave.loop->state, a->lstate, 32);
                    } else {
                        a->loop.start = a->loop.end = a->loop.count = 0;
                    }
                    break;

                case AL_RAW16_WAVE:
                    f->handler = (void *)alRaw16Pull;
                    if (a->table->waveInfo.rawWave.loop) {
                        a->loop.start = a->table->waveInfo.rawWave.loop->start;
                        a->loop.end = a->table->waveInfo.rawWave.loop->end;
                        a->loop.count = a->table->waveInfo.rawWave.loop->count;
                    } else {
                        a->loop.start = a->loop.end = a->loop.count = 0;
                    }
                    break;

                case AL_ADEC_WAVE:
                    f->handler = (void *)alAdecPull;
                    a->loop.start = a->loop.end = a->loop.count = 0;
                    break;

                default:
                    break;
            }
            break;

        case AL_FILTER_RESET:
            a->lastsam = 0;
            a->first = 1;
            a->sample = 0;

            if (a->table) {
                a->memin = (s32)a->table->base;
                if (a->table->type == AL_ADPCM_WAVE) {
                    if (a->table->waveInfo.adpcmWave.loop)
                        a->loop.count = a->table->waveInfo.adpcmWave.loop->count;
                } else if (a->table->type == AL_RAW16_WAVE) {
                    if (a->table->waveInfo.rawWave.loop)
                        a->loop.count = a->table->waveInfo.rawWave.loop->count;
                }
            }
            break;

        default:
            break;
    }
}

/* _decodeChunk (libaudio load.c): DMA the next ADPCM bytes into DMEM aligned down to 8 bytes, set the loop state
   when looping, and queue the ADPCM decode of tsam samples */
Acmd *_decodeChunk(Acmd *ptr, S13Loader *f, s32 tsam, s32 nbytes, s16 outp, s16 inp, u32 flags)
{
    s32 dramAlign, dramLoc;

    if (nbytes > 0) {
        dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
        dramAlign = dramLoc & 0x7;
        nbytes += dramAlign;
        aSetBuffer(ptr++, 0, inp, 0, nbytes + 8 - (nbytes & 0x7));
        aLoadBuffer(ptr++, dramLoc - dramAlign);
    } else
        dramAlign = 0;

    if (flags & 0x02) {
        aSetLoop(ptr++, K0_TO_PHYS(f->lstate));
    }

    aSetBuffer(ptr++, 0, inp + dramAlign, outp, tsam << 1);
    aADPCMdec(ptr++, flags, K0_TO_PHYS(f->state));
    f->first = 0;

    return ptr;
}
