#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80443868.h"
#include "types.h"
#include "stddef.h"
/* Pulses the caption intensity on a 512-step triangle wave and redraws the caption sprite centred on the entry, dropped one full line or a short line when the wide-layout flag is clear. */
extern void func_802A9234_de(s32);
extern void func_802AAC28_de(s32, s32, s16, s16, f32, f32, s32);
extern s32 D_800E28D8;
extern f32 D_800DE740;
void func_80443734_de(func_80239CD0_S1 *arg0, Entry_func_80443734_de *arg1, s32 arg2, Style_func_8043C9AC_de *arg3) {
    s32 phase;
    s32 amount;
    s32 half;
    s32 drop;
    f32 scale;
    f32 sx;
    phase = arg0->unk1C = (arg0->unk1C + 0x14) % 512;
    if (phase >= 0x100) {
        amount = (s32) ((f32) (0x200 - phase) * arg3->alpha * arg3->fade);
    } else {
        amount = (s32) ((f32) phase * arg3->alpha * arg3->fade);
    }
    func_802A9234_de(amount);
    drop = 0x50;
    half = arg1->width >> 1;
    if (D_800E28D8 == 0) {
        drop = 0x2D;
    }
    sx = arg1->scaleX;
    scale = *(&D_800DE740 + 1);
    func_802AAC28_de(arg0->unk14, 0, arg1->x - (half * 8), arg1->y + drop,
                  sx * scale, arg1->scaleY * scale, 1);
}
