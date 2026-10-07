#include "b20_types.h"

s32 func_0028F524(Vid *o, Job **a, Job **b, s32 mode);
extern void *D_80146CF8;
extern void *D_80146CF0;

static inline Job *frameOk(Job *s) {
    if (s != 0) {
        if (s->unkC == D_80146CF8) {
            return 0;
        }
        if (s->unkC == osViGetCurrentFramebuffer()) {
            return 0;
        }
        if (s->unkC != D_80146CF0) {
            return s;
        }
    }
    return 0;
}

s32 func_0028F524(Vid *o, Job **a, Job **b, s32 mode) {
    Job *j;
    Job *h;
    Job *nx;
    s32 orig;
    j = o->head2E8;
    h = o->head2E4;
    orig = mode;
    if (o->unk300 != 0 && (mode & 2)) {
        if (j == 0) {
            *a = h;
        } else {
            if (j->flags8 & 0x10) {
                *a = j;
                goto clr2;
            }
            *a = h;
        }
        o->unk300 = 0;
        mode &= ~2;
        nx = o->head2E4->next;
        o->head2E4 = nx;
        if (nx == 0) {
            o->tail2EC = 0;
        }
        goto end;
    }
    if (frameOk(j) != 0) {
        switch (j->flags8 & 7) {
        case 1:
        case 4:
        case 5:
            break;
        case 3:
            if (j->flags4 & 0x20) {
                if (mode & 2) {
                    *a = j;
                    mode &= ~2;
                    if (j->flags4 & 1) {
                        *b = j;
                        mode &= ~1;
                    }
                    nx = o->head2E8->next;
                    o->head2E8 = nx;
                    goto chk;
                }
            } else if (mode == 3) {
                *b = j;
                *a = j;
                nx = o->head2E8->next;
                mode = 0;
                goto st;
            }
            break;
        case 2:
        case 6:
        case 7:
            if (j->flags4 & 2) {
                if (mode & 2) {
                    *a = j;
clr2:
                    mode &= ~2;
                }
            } else if (j->flags4 & 1) {
                if (mode & 1) {
                    *b = j;
                    nx = o->head2E8->next;
                    mode &= ~1;
st:
                    o->head2E8 = nx;
chk:
                    if (nx == 0) {
                        o->tail2F0 = 0;
                    }
                }
            }
            break;
        }
    }
end:
    if (mode != orig) {
        mode = func_0028F524(o, a, b, mode);
    }
    return mode;
}
