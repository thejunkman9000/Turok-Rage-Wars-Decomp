#include "o06_types.h"
typedef struct { u8 pad[8]; u32 unk8; } O06A;
typedef struct { u8 b[28]; } O06E;
extern O06E D_800E5E74[];
O06E *func_00442F4C(O06A *a) {
    s32 i;
     i = 0; 
    switch (a->unk8 & 0x3FE0) {
     case 0x20: i = 0; break; 
    case 0x40: i = 1; break;
    case 0x80: i = 2; break;
    case 0x100: i = 3; break;
    case 0x200: i = 4; break;
    case 0x400: i = 5; break;
    case 0x800: i = 6; break;
    case 0x1000: i = 7; break;
    case 0x2000: i = 8; break;
     default: i = 0; break; 
    }
    return  &D_800E5E74[i] ;
}
