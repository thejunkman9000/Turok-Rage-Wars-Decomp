#include "common.h"
/* port: osPfsInitPak is the game's own libultra function now (the statically recompiled ROM code at 0x447BB0); it runs against the virtual Controller Pak
 * (port/pak.c: SI/PIF model, port/pak_os.c: __osContRamRead/Write).  port/pak_os.c defines the same wrapper (the link order lets it win over this object);
 * this file only keeps a rebuild of the overrides from bringing the old "no pak is ever inserted" stub (return 1) back. */
u32 func_00447BB0(u32 queue, u32 pfs, u32 channel, u32 a3);
s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, int channel) {
    return (s32)func_00447BB0((u32)queue, (u32)pfs, (u32)channel, 0);
}
