#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80206258.h"
#include "types.h"

extern char D_800C86A0_de;
extern char D_002079B0;
extern char D_00207910;
extern char D_800C1B98_de;












void func_802077F4_de(void *arg0, void *arg1)
{
    f32 k;
    f32 value;
    f32 scaled;
    char *temp_v1;
    char *temp_v0;

    temp_v1 = ((func_80203B60_S1 *)(arg0))->unk18;
    k = ((func_802077F4_S2 *)(&D_800C1B98_de))->unk4;
    ((func_802077F4_S3 *)(arg1))->unk2C = &D_800C86A0_de;
    ((func_802077F4_S3 *)(arg1))->unk108 = &D_002079B0;
    ((func_802077F4_S3 *)(arg1))->unk11C = &D_00207910;
    ((func_802077F4_S3 *)(arg1))->unk134 = 0;
    ((func_802077F4_S3 *)(arg1))->unk138 = 0;
    temp_v0 = temp_v1 + 0x14;
    value = ((func_802077F4_S4 *)(temp_v0))->unk40;
    ((func_802077F4_S3 *)(arg1))->unk124 = 0;
    ((func_802077F4_S3 *)(arg1))->unk128 = 0;
    ((func_802077F4_S3 *)(arg1))->unk12C = 0;
    ((func_802077F4_S3 *)(arg1))->unk130 = 0;
    ((func_802077F4_S3 *)(arg1))->unk64 = value;
    scaled = ((func_802077F4_S4 *)(temp_v0))->unk40;
    ((func_802077F4_S3 *)(arg1))->unk140 = 0;
    ((func_802077F4_S3 *)(arg1))->unk144 = 0;
    scaled = scaled * k;
    ((func_802077F4_S3 *)(arg1))->unk148 = 0;
    ((func_802077F4_S3 *)(arg1))->unk14C = 0;
    ((func_802077F4_S3 *)(arg1))->unk168 = 0;
    ((func_802077F4_S3 *)(arg1))->unk16C = 0;
    ((func_802077F4_S3 *)(arg1))->unk13C = scaled;
    if (((func_80204468_S3 *)(temp_v1))->unk14 & 4) {
        ((func_80203B60_S1 *)(arg0))->unk100 = ((func_80203B60_S1 *)(arg0))->unk100 & ~0x2000;
    }
}
