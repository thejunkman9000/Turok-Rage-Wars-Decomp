#include "o01_types.h"

extern O01Rumble D_80153330[];
extern O01Pad4 D_8010FBE0[];
extern OSMesgQueue D_8010FC00;

s32 func_004055D4(s32 ch) {
    O01Rumble *r = &D_80153330[ch];
    if (D_8010FBE0[ch].unk3 != 0) {
        r->ok = 0;
        return 0;
    }
    r->ok = osMotorInit(&D_8010FC00, &r->pfs, ch) == 0;
    return r->ok;
}
