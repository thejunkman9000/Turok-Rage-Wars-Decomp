#include "common/unused.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80447BB0.h"

extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);
extern s32 func_80448CC4_de(OSPfs_func_80445F80_de *pfs);

s32 func_80448BFC_de(OSPfs_func_80445F80_de *pfs)
{
    int k;
    u8 temp[32];
    s32 ret;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = func_80448CC4_de(pfs);
        if (ret != 0)
            return ret;
    }

    ret = func_802B84C0_de(pfs->queue, pfs->channel, 1, temp);

    if (ret != 0) {
        if (ret != 2) {
            return ret;
        }
        ret = func_802B84C0_de(pfs->queue, pfs->channel, 1, temp);
        if (ret != 0)
            return ret;
    }

    for (k = 0; k < 32; k++) {
        if (pfs->id[k] != temp[k])
            return 2;
    }

    return 0;
}
