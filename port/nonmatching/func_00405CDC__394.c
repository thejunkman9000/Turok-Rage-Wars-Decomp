#include "q01_types.h"
typedef struct Q01Pool { s32 unk0; s32 *unk4; s32 *unk8; s32 *unkC[3]; s32 *unk18; s32 *unk1C; } Q01Pool;
void func_002537D8(s32 a, s32 *b);
void func_00405CDC(Q01Pool *arg0) {
    s32 n;
    s32 j;
    if (arg0->unk4 != 0) func_002537D8(0, arg0->unk4);
    if (arg0->unk8 != 0) func_002537D8(0, arg0->unk8);
    if (arg0->unk18 != 0) func_002537D8(0, arg0->unk18);
    if (arg0->unk1C != 0) func_002537D8(0, arg0->unk1C);
    for (n = 0; n < 3; n++) {
        if (arg0->unkC[n] != 0) func_002537D8(0, arg0->unkC[n]);
    }
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    for (j = 2; j >= 0; j--) arg0->unkC[j] = 0;
}
