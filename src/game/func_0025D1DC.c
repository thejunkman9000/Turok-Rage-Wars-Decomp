#include "p3_types.h"

typedef struct {
    void *owner;           /* 0x00 */
    u8 pad04[4];
    s32 state;             /* 0x08 */
    u8 pad0C[0x1E - 0xC];
    s16 sndId;             /* 0x1E */
} P3SndObj;

void func_00258760(void *o);
void func_002587C4(void *o);
void *func_00258D60(void *o);
void alSndpSetSound(void *sndp, s16 id);
void alSndpStop(void *sndp);

void func_0025D1DC(P3SndObj *s) {
    void *sndp;
    func_00258760(s->owner);
    if (s->state != 2 && s->state != 0) {
        s->state = 2;
        sndp = func_00258D60(s->owner);
        alSndpSetSound(sndp, s->sndId);
        alSndpStop(sndp);
    }
    func_002587C4(s->owner);
}
