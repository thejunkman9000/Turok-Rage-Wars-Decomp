#include "o02_types.h"
typedef struct { u8 pad[8]; s16 v; } S_func_00413D14;
extern S_func_00413D14 *D_80153D58;
extern void (*D_80153CDC)(void);
extern s32 D_80153C84;
extern s32 D_80153C8C;
void func_00413D14(s32 base, s32 n, s32 v) {
    D_80153C8C = v;
    D_80153C84 = base + n * D_80153D58->v;
    D_80153CDC();
}
