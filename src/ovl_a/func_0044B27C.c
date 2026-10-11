/* their2 */
/* ported from melalawi/ragewars-decomp src/func_8044A62C_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "span_16E000/code_8044ACCC.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"
/* declarations of symbols that the headers declare under their own (German version) names */
extern void func_00255C40(IntrusiveList *list, s32 prevOffset, s32 nextOffset);

/* Resets a 0x1208-byte actor: clears it through memset, initialises its three lists at 0xC,
   0x20 and 0xF24 through func_00255C40, sets its words at 0x1200 and 0x38 to 1 and 2, clears those at
   0 to 8 and 0xF18 to 0xF20, and resets the parts at offset 0x40 through func_0044ADC0 and
   func_00234FDC. */
extern void *memset(void *, int, u32);
extern void func_0044ADC0(void *);
extern void func_00234FDC(void *);




void func_0044B27C(func_8044B27C_S1 *actor) {
    char *parts;

    memset(actor, 0, 0x1208);
    func_00255C40(&actor->unkC, 0, 4);
    func_00255C40(&actor->unk20, 0, 4);
    func_00255C40(&actor->unkF24, 0, 4);
    parts = &actor->unk40;
    actor->unk1200 = 1;
    actor->unk0 = 0;
    actor->unk4 = 0;
    actor->unk8 = 0;
    actor->unkF18 = 0;
    actor->unkF1C = 0;
    actor->unkF20 = 0;
    actor->unk38 = 2;
    func_0044ADC0(parts);
    func_00234FDC(parts);
}
