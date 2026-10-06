#include "libaudio.h"

u8 __alCSeqGetTrackEvent(ALCSeq *seq, u32 track, ALEvent *event);
u32 __readVarLen(ALCSeq *seq, u32 track);
s32 alCSeqNextEvent(ALCSeq *seq, ALEvent *event);

s32 alCSeqNextEvent(ALCSeq *seq, ALEvent *event) {
    u32 i;
    u32 firstTime = 0xFFFFFFFF;
    u32 firstTrack;
    u32 lastDelta = seq->lastDeltaTicks;

    for (i = 0; i < 16; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag) {
                seq->evtDeltaTicks[i] -= lastDelta;
            }
            if (seq->evtDeltaTicks[i] < firstTime) {
                firstTime = seq->evtDeltaTicks[i];
                firstTrack = i;
            }
        }
    }

    __alCSeqGetTrackEvent(seq, firstTrack, event);

    event->msg.midi.ticks = firstTime;
    seq->lastDeltaTicks = firstTime;
    seq->lastTicks += firstTime;

    if (event->type != AL_SEQ_END_EVT) {
        seq->evtDeltaTicks[firstTrack] += __readVarLen(seq, firstTrack);
    }

    seq->deltaFlag = 1;
    return 1;
}
