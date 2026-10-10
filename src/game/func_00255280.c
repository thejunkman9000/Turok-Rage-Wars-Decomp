#include "span_1000/code_80254CE4.h"
#include "types.h"

/* Creates the address hash table: rounds the requested capacity up to a power of two, allocates twice that many 16-byte slots from pool D_801051A0 (keeping the half size, slot count and both index masks in globals), and clears every slot, numbering each with its index. */



extern s32 D_800CB6F0;
extern u32 D_800CB6F4;
extern s32 D_80101190;
extern Slot_func_802552E0_de *D_80101194;
extern s32 D_80101198;
extern char D_801051A0;
extern Slot_func_802552E0_de *func_80255920_de(void *, s32);

void func_802552E0_de(s32 capacity)
{
    s32 bits = 0;
    s32 top = 0;
    s32 i;
    s32 half;
    u32 n;

    for (i = 0; i < 32; i++) {
        s32 bit = 1 << i;
        if (capacity & bit) {
            bits++;
            top = i;
        }
    }
    if (bits != 1) {
        top++;
    }
    half = 1 << top;
    D_800CB6F4 = half * 2;
    D_800CB6F0 = half;
    D_80101190 = D_800CB6F4 - 2;
    D_80101198 = D_800CB6F4 - 1;
    D_80101194 = func_80255920_de(&D_801051A0, half << 5);
    for (n = 0; n < D_800CB6F4; n++) {
        D_80101194[n].value = 0;
        D_80101194[n].key = 0;
        D_80101194[n].next = 0;
        D_80101194[n].index = n;
    }
}
