#include "common.h"

typedef struct {
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
} PfsRespFormat;

void __osPfsGetOneChannelData(int channel, OSContStatus *data) {
    u8 *ptr;
    PfsRespFormat resp;
    int i;
    ptr = (u8 *)&__osPfsPifRam;
    for (i = 0; i < channel; i++) {
        ptr++;
    }
    resp = *(PfsRespFormat *)ptr;
    data->errno = CHNL_ERR(resp);
    if (data->errno == 0) {
        data->type = (resp.typel << 8) | resp.typeh;
        data->status = resp.status;
    }
}
