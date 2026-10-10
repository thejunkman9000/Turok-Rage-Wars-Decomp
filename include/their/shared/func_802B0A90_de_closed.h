#ifndef FUNC_802B0A90_DE_CLOSED_H
#define FUNC_802B0A90_DE_CLOSED_H
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802B243C.h"
#include "span_1000/code_802B0388.h"
#include "common/unused.h"
struct ALSequencePlayer {
    ALSeqPlayer_func_802B0C94_de base;
    ALSeqMarker *loopStart;
    ALSeqMarker *loopEnd;
    s32 loopCount;
};
struct ALSequenceLoopEvent {
    ALSeqMarker *start;
    ALSeqMarker *end;
    s32 count;
};

extern char D_800C7440[];   /* "EX" */
extern char D_800C7444[];   /* "audio/seqplayer.c" */

extern void func_802B1E80_de(struct ALSeq_s *, Message_func_802AF150_de *);                 /* alSeqNextEvent */
extern void func_802B0C94_de(ALSeqPlayer_func_802B0C94_de *, Message_func_802AF150_de *);           /* __handleMIDIMsg */
extern void func_802B1DEC_de(ALSeqPlayer_func_802B0C94_de *, Message_func_802AF150_de *);           /* __handleMetaMsg */
extern u8 func_802B22F4_de(struct ALSeq_s *, s32 *);                       /* __alSeqNextDelta (char; unsigned in this build) */
extern s32 func_802B20C8_de(struct ALSeq_s *);                             /* alSeqGetTicks */
extern void func_802B22BC_de(struct ALSeq_s *, ALSeqMarker *);             /* alSeqSetLoc */
extern void func_802B00D4_de(ALEventQueue *, Message_func_802AF150_de *, ALMicroTime);  /* alEvtqPostEvent */
extern void func_802BAC50_de(char *, char *, s32);                /* __assert */

static inline void postNextSeqEvent(struct ALSequencePlayer *seqp)
{
    Message_func_802AF150_de evt;
    s32 deltaTicks;
    struct ALSeq_s *seq = seqp->base.target;

    if ((seqp->base.state != 1) || (seq == 0))
        return;

    if (!func_802B22F4_de(seq, &deltaTicks))
        return;

    if (seqp->loopCount) {
        if (func_802B20C8_de(seq) + deltaTicks >= seqp->loopEnd->curTicks) {
            func_802B22BC_de(seq, seqp->loopStart);
            if (seqp->loopCount != -1)
                seqp->loopCount--;
        }
    }

    evt.type = 0;   /* AL_SEQ_REF_EVT */
    func_802B00D4_de(&seqp->base.evtq, &evt, deltaTicks * seqp->base.uspt);
}


#endif
