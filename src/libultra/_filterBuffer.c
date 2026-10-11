#include "s1013_types.h"

/* _filterBuffer (libaudio reverb.c): run the low-pass (pole) filter of a delay section over buff.
   Written out where the SDK's aSetBuffer / aLoadADPCM / aPoleFilter macros land with plain -O2 (no -fforce-addr):
   three command words stored through one base pointer, the new command pointer computed before the second
   osVirtualToPhysical call. */
Acmd *_filterBuffer(S13LowPass *lp, s32 buff, s32 count, Acmd *p)
{
    Acmd *ptr = p;
    Acmd *ret;
    s32 a1 = buff & 0xFFFF;

    ptr[0].w0 = a1 | 0x08000000;
    ptr[0].w1 = (a1 << 16) | ((count * 2) & 0xFFFF);
    ptr[1].w0 = 0x0B000020;
    ptr[1].w1 = osVirtualToPhysical(lp->fcoef);
    {
        s32 c2 = 0x0E000000;
        s32 b2f = ((u8 *)lp)[0x2F];
        s32 h2 = (u16)lp->fgain;
        ptr[2].w0 = (b2f << 16) | (h2 | c2);
    }
    ret = ptr + 3;
    ptr[2].w1 = osVirtualToPhysical(lp->fstate);
    lp->first = 0;
    return ret;
}
