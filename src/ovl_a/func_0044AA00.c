/* their2 */
/* ported from melalawi/ragewars-decomp src/func_80449DB0_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "span_16E000/code_80447BB0.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"
/* declarations of symbols that the headers declare under their own (German version) names */
extern void func_00255C40(IntrusiveList *list, s32 prevOffset, s32 nextOffset);

/* Resets a 0x44-byte record: clears it through memset, initialises the two lists at offsets
   0xC and 0x20 through func_00255C40 with 0x16DC and 0x16E0, and clears the words at 0 to 8 and
   0x34 to 0x40. */
extern void *memset(void *, int, u32);

void func_0044AA00(struct Record_func_80449DB0_de *record) {
    memset(record, 0, 0x44);
    func_00255C40(&record->listC, 0x16DC, 0x16E0);
    func_00255C40(&record->list20, 0x16DC, 0x16E0);
    record->word0 = 0;
    record->word4 = 0;
    record->word8 = 0;
    record->word34 = 0;
    record->word38 = 0;
    record->word3C = 0;
    record->word40 = 0;
}
