#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804264F0.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"
/* Draw callback of the results screen D_800E4690: on draw event 1 in states 3, 8 or 9 it resets
   the fill colour D_800D15E0 to opaque white, and for each of the one or two viewports clips the
   display list to its rectangle in D_800E41C0 (0, then 2 for the lower view), draws the player's panel through func_8041C7F4_de and restores the
   full-screen clip. Outside two-player mode (and unless func_80299958_de reports 0x19) it plays sound
   0x259 past the base at 0xA44 on the twentieth frame, raises the banner blink after six more
   frames, and fades the two banner sprites out by 30 per frame before hiding them. Returns zero. */








extern struct ResultsDrawScreen *D_800E4690;
extern s32 D_800D15E0;
extern f32 D_800D15E4[4];
extern struct Shape_typemap_6 D_800E41C0[];
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern Gfx *D_80110634;

extern struct SettingsE D_801462C8;

extern void func_8041C7F4_de(char *);
extern s32 func_80299958_de(void);
extern void func_804220A8_de(s32);
extern void func_8040E8D8_de(struct Shape_typemap_21 *, s32);

s32 func_80426CE4_de(void *arg0, void *arg1, s32 event) {
    s32 views;
    s32 i;
    s32 alpha;
    s32 k;

    if (event == 1 && (D_800E4690->state == 3 || D_800E4690->state == 8 || D_800E4690->state == 9)) {
        D_800D15E0 = 0;
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
        views = 1;
        if (D_801462C8.players == 2) {
            views = 2;
        }
        for (i = 0, k = 0; i < views; i++, k = 2) {
            gDPSetScissorFrac(D_80110634++, G_SC_NON_INTERLACE, (s32)((f32)((D_800E41C0[k].field_0)) * 4.0f), (s32)((f32)((D_800E41C0[k].field_4)) * 4.0f), (s32)((f32)((D_800E41C0[k].field_8)) * 4.0f), (s32)((f32)((D_800E41C0[k].field_C)) * 4.0f));
            func_8041C7F4_de(D_800E4690->panels[i]);
            gDPSetScissorFrac(D_80110634++, G_SC_NON_INTERLACE, (s32)((f32)((0)) * 4.0f), (s32)((f32)((0)) * 4.0f), (s32)((f32)((D_800E28D0 - 1)) * 4.0f), (s32)((f32)((D_800E28D4 - 1)) * 4.0f));
        }
        if (D_801462C8.players != 2 && func_80299958_de() != 0x19) {
            if (D_800E4690->frames < 20) {
                if (++D_800E4690->frames == 20) {
                    k = D_800E4690->soundBase;
                    func_804220A8_de(k + 0x259);
                    D_800E4690->blinkDelay = 0;
                }
            }
            if (D_800E4690->blinkDelay != -1) {
                if (++D_800E4690->blinkDelay >= 6) {
                    D_800E4690->blinking = 1;
                    D_800E4690->blinkDelay = -1;
                }
            }
            if (D_800E4690->blinking == 1) {
                alpha = D_800E4690->banner->field_10;
                alpha -= 30;
                if (alpha <= 0) {
                    D_800E4690->blinking = 0;
                    func_8040E8D8_de(D_800E4690->bannerShadow, 0);
                    func_8040E8D8_de(D_800E4690->banner, 0);
                    alpha = 0xFF;
                }
                D_800E4690->banner->field_10 = alpha;
                D_800E4690->bannerShadow->field_10 = alpha;
            }
        }
    }
    return 0;
}
