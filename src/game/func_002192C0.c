#include "b04_types.h"
extern u8 D_8011FE88[];
typedef struct { s16 mode; s16 count; } B04Tab;
B04Tab *func_0028D1F4(u8 *, s32);
typedef struct { s8 state; u8 idx; s16 cur; s16 prev; } B04Cur;
void func_002192C0(B04Cur *o) {
    B04Tab *t = func_0028D1F4(D_8011FE88, o->idx);
    s32 n = t->count;
    o->prev = o->cur;
    switch (o->state) {
    case 1: case 2:
        o->state = 1;
        o->cur = o->cur + 1;
        if (o->cur == n) {
            switch (t->mode) {
            case 1: o->cur = 0; return;
            case 0: o->cur = n - 2; o->state = 3; return;
            }
        }
        break;
    case 3: case 4:
        o->state = 3;
        o->cur = o->cur - 1;
        if (o->cur < 0) {
            switch (t->mode) {
            case 0: o->cur = 1; o->state = 1; return;
            case 1: o->cur = n - 1; break;
            }
        }
        break;
    }
}
