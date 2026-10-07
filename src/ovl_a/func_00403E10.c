#include "o01_types.h"

typedef struct O01Kind {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 kind;
    /* 0x12 */ u8 val;
} O01Kind;

s32 func_00403E10(O01Kind *a) {
    s32 r = 0;
    switch (a->kind) {
    case 1:
        if (a->val == 5) r = 1;
        break;
    case 9:
        if (a->val == 4) r = 1;
        break;
    case 10:
        if (a->val == 3) r = 1;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}
