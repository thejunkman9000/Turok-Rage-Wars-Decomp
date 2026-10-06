#include "common.h"

typedef struct { u8 pad[0x534]; s32 a; s32 b; } S534;
typedef struct { u8 pad[0x3C]; s32 v; } S3C;
typedef struct LinkNode_s { struct LinkNode_s *next; struct LinkNode_s *prev; } LinkNode;

extern S534 *D_8014D084;
extern S3C *D_800E2830;

void f_0029AA48(s32 a, s32 b) {
    D_8014D084->a = a;
    D_8014D084->b = b;
}

s32 f_00245840(void) {
    return D_800E2830->v;
}

void f_00259B10(LinkNode *ln, LinkNode *to) {
    ln->next = to->next;
    ln->prev = to;
    if (to->next != 0) {
        to->next->prev = ln;
    }
    to->next = ln;
}

void f_0029FBC8(f32 *dst, f32 *src) {
    dst[0] = src[0];
    dst[5] = src[1];
    dst[10] = src[2];
}

s32 f_00243840(f32 *a, f32 *b) {
    if (a[1] < b[1]) {
        return 1;
    }
    return -1;
}
