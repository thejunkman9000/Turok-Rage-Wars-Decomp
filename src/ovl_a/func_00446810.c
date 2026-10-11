/* their2 */
/* ported from melalawi/ragewars-decomp src/func_80445BC0_de.c (CC0); names changed to our US v1.1 names (func_00XXXXXX / D_XXXXXXXX); the pool floats 6.0f (D_800E2810+4) and 0.0035211267f (D_800E2818) that upstream reads as externs are LITERALS here: they are this function's own pool (ro=0xE3414:16 = 6.0f 0.0035211267f 64.0f 2^31); built with @SN */
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802A8A94.h"
#include "span_16E000/code_804453C4.h"
#include "types.h"

/* Draws a menu spinner: during the first half of its blink period (the timer of its D_800E63C0 entry up to the float after D_800E2810) it fills a two-pixel white bar under the digit its value selects, placed from the item's x at 0x14 by the character width func_00442F4C reports scaled to the screen, with the style's alpha at 0x30 and 0x34, through func_002AB9E4 and func_002A8DD4; then draws the item through func_004421FC. */








extern char D_80145040[];
extern Spinner D_800E63C0[];


extern s32 D_800E28D0;
extern s32 D_800E1E20;

extern s32 func_0022A590(char *, s32);
extern func_802077F4_S2 *func_00442F4C(void *, s32);

extern void func_002A8DD4(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_004421FC(void *, Item_func_8043C9AC_de *, void *, Style_func_80445BC0_de *);

void func_00446810(void *menu, Item_func_8043C9AC_de *item, void *arg2, Style_func_80445BC0_de *style) {
    s32 i;
    f32 width;
    f32 alpha;
    s32 x;
    unsigned int bits;

    i = func_0022A590(D_80145040, style->id);
    if (D_800E63C0[i].timer <= 6.0f) {
        width = func_00442F4C(menu, 0)->unk4 * (f32)D_800E28D0 * 0.0035211267f;
        x = (f32)item->x + (f32)D_800E63C0[i].value * width;
        D_800E1E20 = -1;
        alpha = style->alpha * (style->fade * (64.0f));
        func_002AB9E4();
        func_002A8DD4(x, item->y - 2, (f32)x + width, item->y, 0, 0, 0xFF, 0xFF, 0xFF,
                      (u8)(bits = !((2147483648.0f) <= alpha) ? (s32)alpha : (bits = (s32)(alpha - (2147483648.0f))) | 0x80000000));
    }
    func_004421FC(menu, item, arg2, style);
}
