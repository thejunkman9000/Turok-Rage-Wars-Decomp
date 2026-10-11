#include "common.h"
/* port: osPfsIsPlug asks the virtual Controller Pak which ports have a pak (port/pak_os.c: pak_pfs_isplug = the standard libultra routine, a status request
 * for the four channels through the PIF model).  The game does not call it.  port/pak_os.c also defines osPfsIsPlug (it wins over this object at link time);
 * this file only keeps a rebuild of the overrides from bringing the old "no pak plugged anywhere" stub (*pattern = 0) back. */
s32 pak_pfs_isplug(OSMesgQueue *queue, u8 *pattern);
s32 osPfsIsPlug(OSMesgQueue *queue, u8 *pattern) {
    return pak_pfs_isplug(queue, pattern);
}
