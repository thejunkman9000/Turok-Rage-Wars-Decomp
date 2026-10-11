#include "s1013_types.h"

/* alRaw16Pull (libaudio load.c): DMA raw 16-bit samples into DMEM at 8-byte alignment for the requested output
   count, restarting from the loop start and merging the sections in DMEM when the count crosses the loop end,
   and clearing what runs past the table. */
Acmd *alRaw16Pull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    s32 nbytes;
    s32 dramLoc;
    s32 dramAlign;
    s32 dmemAlign;
    s32 overFlow;
    s32 startZero;
    s32 nSam;
    s32 op;
    S13Loader *f = (S13Loader *)filter;

    if (outCount == 0)
        return ptr;

    if ((outCount + f->sample > f->loop.end) && (f->loop.count != 0)) {
        nSam = f->loop.end - f->sample;
        nbytes = nSam << 1;
        if (nSam > 0) {
            dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
            dramAlign = dramLoc & 0x7;
            nbytes += dramAlign;
            aSetBuffer(ptr++, 0, *outp, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, dramLoc - dramAlign);
        } else
            dramAlign = 0;
        *outp += dramAlign;
        f->memin = (s32)f->table->base + (f->loop.start << 1);
        f->sample = f->loop.start;
        op = *outp;
        while (outCount > nSam) {
            op += (nSam << 1);
            outCount -= nSam;
            if ((f->loop.count != -1) && (f->loop.count != 0))
                f->loop.count--;
            nSam = (outCount < f->loop.end - f->loop.start) ? outCount : f->loop.end - f->loop.start;
            nbytes = nSam << 1;
            dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
            dramAlign = dramLoc & 0x7;
            nbytes += dramAlign;
            if (op & 0x7)
                dmemAlign = 8 - (op & 0x7);
            else
                dmemAlign = 0;
            aSetBuffer(ptr++, 0, op + dmemAlign, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, dramLoc - dramAlign);
            if (dramAlign || dmemAlign)
                aDMEMMove(ptr++, op + dramAlign + dmemAlign, op, nSam << 1);
        }
        f->sample += outCount;
        f->memin += (outCount << 1);
        return ptr;
    }

    nbytes = outCount << 1;
    overFlow = f->memin + nbytes - ((s32)f->table->base + f->table->len);
    if (overFlow < 0)
        overFlow = 0;
    if (overFlow > nbytes)
        overFlow = nbytes;
    if (overFlow < nbytes) {
        if (outCount > 0) {
            nbytes -= overFlow;
            dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
            dramAlign = dramLoc & 0x7;
            nbytes += dramAlign;
            aSetBuffer(ptr++, 0, *outp, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, dramLoc - dramAlign);
        } else
            dramAlign = 0;
        *outp += dramAlign;
        f->sample += outCount;
        f->memin += outCount << 1;
    } else {
        f->memin += outCount << 1;
    }
    if (overFlow) {
        startZero = (outCount << 1) - overFlow;
        if (startZero < 0)
            startZero = 0;
        aClearBuffer(ptr++, startZero + *outp, overFlow);
    }
    return ptr;
}

extern s32 D_800D9360;
extern s32 adecNextFrame();

/* alAdecPull: the loader pull handler of the Acclaim compressed-audio wave type (2): streams decoded 16-bit
   samples (one 0x100 sample block at a time, adecNextFrame) through DMEM like alRaw16Pull; clears the output and
   stops when no block arrives */
Acmd *alAdecPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    s32 nbytes;
    s32 dramAlign;
    s32 dmemAlign;
    s32 nSam;
    s32 op;
    S13Loader *f = (S13Loader *)filter;
    s32 *stream;

    op = *outp;
    if (f->table->base == 0) {
        aClearBuffer(ptr++, op, outCount << 1);
        return ptr;
    }
    if (outCount != 0) {
        stream = &D_800D9360;
        do {
            nSam = outCount;
            if (f->sample == 0) {
                D_800D9360 = adecNextFrame();
                if (D_800D9360 == 0) {
                    aClearBuffer(ptr++, op, outCount << 1);
                    return ptr;
                }
                osWritebackDCache((void *)D_800D9360, 0x200);
                f->sample = 0x100;
            }
            if (f->sample < outCount) {
                nSam = f->sample;
            }
            nbytes = nSam << 1;
            dramAlign = D_800D9360 & 0x7;
            nbytes += dramAlign;
            if (op & 0x7) {
                dmemAlign = 8 - (op & 0x7);
            } else {
                dmemAlign = 0;
            }
            aSetBuffer(ptr++, 0, op + dmemAlign, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, (D_800D9360 & 0x1FFFFFFF) - dramAlign);
            if (dramAlign || dmemAlign) {
                aDMEMMove(ptr++, op + dramAlign + dmemAlign, op, nSam << 1);
            }
            outCount -= nSam;
            op += nSam << 1;
            *stream += nSam << 1;
            f->sample -= nSam;
        } while (outCount != 0);
    }
    return ptr;
}
