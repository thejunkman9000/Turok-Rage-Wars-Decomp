#include "b23_types.h"


void func_002A1A84(MsgBox *b) {
    osRecvMesg(&b->q, &b->msg, 1);
}
