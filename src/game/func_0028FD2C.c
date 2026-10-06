#include "common.h"

void func_0028FD2C(u8 *o, OSMesg msg) {
    osSendMesg((OSMesgQueue *)(o + 0x78), msg, OS_MESG_BLOCK);
    osSendMesg((OSMesgQueue *)(o + 0x40), (OSMesg)6, OS_MESG_BLOCK);
}
