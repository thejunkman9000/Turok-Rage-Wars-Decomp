#include "b12_types.h"

extern u32 D_80105190;
extern B12Bucket *D_80105194;

void func_00255428(u32 key) {
    B12Bucket *p;
    B12Bucket *prev;
    B12Bucket *nx;
    p = &D_80105194[((key << 5) ^ (key >> 1) ^ (key >> 9) ^ (key >> 17)) & D_80105190];
    prev = 0;
    if (p->unk0 != key) {
        for (;;) {
            prev = p;
            p = p->next;
            if (!p) {
                return;
            }
            if (p->unk0 == key) {
                break;
            }
        }
    }
    if (p) {
        nx = p->next;
        if (nx) {
            p->unk4 = nx->unk4;
            p->unk0 = nx->unk0;
            p->next = nx->next;
            {
                B12Bucket *t = p;
                p = nx;
                nx = t;
            }
        }
        if (prev) {
            prev->next = nx;
        }
        p->unk4 = 0;
        p->unk0 = 0;
        p->next = 0;
    }
}
