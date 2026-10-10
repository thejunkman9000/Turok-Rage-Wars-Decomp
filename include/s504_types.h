#include "types.h"
#ifndef S504_TYPES_H
#define S504_TYPES_H
/* types for group s504 (sn-mode ports of ragewars-decomp structs) */
typedef struct S504Anim {
    float unk0;
    char pad4[0x4];
    short unk8;
    char padA[0x2];
    int unkC;
    int **unk10;
} S504Anim;
typedef struct S504AnimOut {
    signed char *unk0;
    signed char *unk4;
    signed char *unk8;
    signed char *unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float unk20;
} S504AnimOut;
#endif
