#include "common.h"

typedef struct {
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
} PfsReqFormat;

void __osPfsRequestOneChannel(int channel) {
    u8 *ptr;
    PfsReqFormat req;
    int i;
    __osPfsPifRam.pifstatus = 1;
    req.txsize = 1;
    req.rxsize = 3;
    __osContLastCmd = 0;
    req.cmd = 0;
    req.typeh = 0xFF;
    req.typel = 0xFF;
    req.status = 0xFF;
    ptr = (u8 *)&__osPfsPifRam;
    for (i = 0; i < channel; i++) {
        *ptr++ = 0;
    }
    *(PfsReqFormat *)ptr = req;
    ptr += sizeof(PfsReqFormat);
    *ptr = 0xFE;
}
