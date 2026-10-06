#include "p2_types.h"

extern SlotCnt D_80103B5C[24];
extern BlkNode D_80103F88;
extern BlkStats D_80103240;
extern Obj0C *D_80103E20;

void func_0023C6AC(void) {
    u32 max = 0;
    u32 min = 0x80000000;
    u32 total;
    s32 i;
    BlkNode *n;

    for (i = 0; i < 24; i++) {
        u32 v = D_80103B5C[i].cnt;
        if (v > max) {
            max = v;
        }
        if (v < min) {
            min = v;
        }
        D_80103B5C[i].cnt = v + 1;
    }
    total = 0;
    for (n = &D_80103F88; n != NULL; n = n->next) {
        total += n->pages << 12;
    }
    D_80103240.total = total;
    D_80103240.max = max;
    D_80103240.min = min;
    D_80103240.f8 = D_80103E20->fC;
}