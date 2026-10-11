#include "s1013_types.h"

Acmd *_decodeChunk(Acmd *ptr, S13Loader *f, s32 tsam, s32 nbytes, s16 outp, s16 inp, u32 flags);
u32 func_002570E0(void *addr, s32 len);

/* alAdpcmPull (libaudio load.c): pull handler of the loader filter for ADPCM wave tables: load the codebook, decode
   whole 16 sample frames (9 bytes each) through _decodeChunk, restarting from the loop start (and merging the
   sections in DMEM) when the request crosses the loop end, and clear what runs past the end of the table. */
Acmd *alAdpcmPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    S13Loader *f = (S13Loader *)filter;
    s32 nbytes;
    s32 nframes;
    s32 nSam;
    s32 tsam;
    s32 overFlow;
    s32 dmemOut;
    s32 overBytes;
    s32 off;
    s32 dmemAlign;
    s32 looped;
    s32 decoded = 0;
    s32 tmp;
    s16 inp;

    if (outCount == 0)
        return ptr;

    /* the codebook of the wave table goes through the game's DMA cache */
    aLoadADPCM(ptr++, f->bookSize, func_002570E0((void *)((u32)f->table->waveInfo.adpcmWave.book + 8), f->bookSize));

    looped = 0;
    inp = 0;
    if (f->loop.end < outCount + f->sample)
        looped = 0 < f->loop.count;
    if (looped)
        nSam = f->loop.end - f->sample;
    else
        nSam = outCount;
    if (f->lastsam)
        dmemAlign = 16 - f->lastsam;
    else
        dmemAlign = 0;
    tsam = nSam - dmemAlign;
    if (tsam < 0)
        tsam = 0;
    nframes = (tsam + 15) >> 4;
    nbytes = nframes * 9;

    if (looped) {
        ptr = _decodeChunk(ptr, f, tsam, nbytes, *outp, inp, f->first);
        if (f->lastsam)
            *outp += f->lastsam << 1;
        else
            *outp += 32;
        f->lastsam = f->loop.start & 0xF;
        f->memin = (s32)f->table->base + ((f->loop.start >> 4) + 1) * 9;
        f->sample = f->loop.start;
        dmemOut = *outp;
        while (nSam < outCount) {
            tmp = dmemOut + (nframes + 1) * 32;
            dmemOut += nSam << 1;
            dmemAlign = tmp & ~31;
            outCount -= nSam;
            if (f->loop.count != -1 && f->loop.count != 0)
                f->loop.count--;
            nSam = (outCount < f->loop.end - f->loop.start) ? outCount : f->loop.end - f->loop.start;
            tsam = nSam - 16 + f->lastsam;
            if (tsam < 0)
                tsam = 0;
            nframes = (tsam + 15) >> 4;
            ptr = _decodeChunk(ptr, f, tsam, nframes * 9, dmemAlign, inp, f->first | 2);
            aDMEMMove(ptr++, dmemAlign + (f->lastsam << 1), dmemOut, nSam << 1);
        }
        f->lastsam = (outCount + f->lastsam) & 0xF;
        f->sample += outCount;
        f->memin += nframes * 9;
        return ptr;
    } else {
        nSam = nframes << 4;
        overBytes = f->memin + nbytes - ((s32)f->table->base + f->table->len);
        if (overBytes < 0)
            overBytes = 0;
        overFlow = (overBytes / 9) << 4;
        if (overFlow > nSam + dmemAlign)
            overFlow = nSam + dmemAlign;
        nbytes -= overBytes;
        if (overFlow - (overFlow & 0xF) < outCount) {
            decoded = 1;
            ptr = _decodeChunk(ptr, f, nSam - overFlow, nbytes, *outp, inp, f->first);
            if (f->lastsam)
                *outp += f->lastsam << 1;
            else
                *outp += 32;
            f->lastsam = (outCount + f->lastsam) & 0xF;
            f->sample += outCount;
            f->memin += nframes * 9;
        } else {
            f->lastsam = 0;
            f->memin += nframes * 9;
        }
        if (overFlow) {
            f->lastsam = 0;
            if (decoded)
                off = (dmemAlign + nSam - overFlow) << 1;
            else
                off = 0;
            aClearBuffer(ptr++, off + *outp, overFlow << 1);
        }
    }
    return ptr;
}
