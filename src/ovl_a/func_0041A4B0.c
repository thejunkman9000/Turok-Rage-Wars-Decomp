#include "o03_types.h"
void func_0025DF54(s32 snd);
void func_0041A4B0(O3B60 *o, s32 v) {
    o->state = v;
    switch (v) {
    case 1:
        func_0025DF54(0xE77);
        break;
    case 2:
        func_0025DF54(0xE76);
        break;
    }
}