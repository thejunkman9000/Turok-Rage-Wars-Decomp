#include "b12_types.h"
#include "libaudio.h"

extern u32 D_800D0944;
extern u32 D_800D0940;
extern OSMesgQueue D_8010BDD8;
typedef struct B12Timer {
    ALLink link;
    s32 pad8;
    u32 count;
} B12Timer;
typedef struct B12TimerList {
    B12Timer *first;
    B12Timer *last;
} B12TimerList;
extern B12TimerList D_8010BDF4;

void func_00256FE0(void) {
    u32 i = 0;
    OSMesg msg = 0;
    B12Timer *p;
    B12Timer *next;
    if (D_800D0944) {
        do {
            osRecvMesg(&D_8010BDD8, &msg, 1);
            i++;
        } while (i < D_800D0944);
    }
    p = D_8010BDF4.first;
    if (p) {
        do {
            next = (B12Timer *)p->link.next;
            if (p->count + 1 < D_800D0940) {
                if (D_8010BDF4.first == p) {
                    D_8010BDF4.first = next;
                }
                alUnlink(&p->link);
                if (D_8010BDF4.last != 0) {
                    alLink(&p->link, &D_8010BDF4.last->link);
                } else {
                    D_8010BDF4.last = p;
                    p->link.next = 0;
                    p->link.prev = 0;
                }
            }
            p = next;
        } while (p);
    }
    D_800D0944 = 0;
    D_800D0940++;
}
