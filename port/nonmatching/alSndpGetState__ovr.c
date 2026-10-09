#include "libaudio.h"
extern char *getenv(const char *);
static int st0 = -1;      /* TUROK_SNDSTATE0: report every player as stopped (what the stubbed library did) */

s32 alSndpGetState(ALSndPlayer *sndp) {
    if (st0 < 0) st0 = getenv("TUROK_SNDSTATE0") ? 1 : 0;
    if (st0) return 0;
    return sndp->sndState[sndp->target].state;
}
