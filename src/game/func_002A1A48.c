#include "b23_types.h"

void func_002A1A48(MsgBox *b) {
    osCreateMesgQueue(&b->q, &b->msg, 1);
    osSendMesg(&b->q, (OSMesg)1, 1);
}
