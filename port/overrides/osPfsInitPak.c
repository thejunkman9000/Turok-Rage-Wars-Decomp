#include "common.h"
/* port: no controller pak is ever inserted (the SI layer is not emulated): report PFS_ERR_NOPACK so the game continues without saving */
s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, int channel) {
    return 1;
}
