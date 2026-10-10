#include "types.h"
#include "gfx.h"
#include "gbi.h"
#include "span_C76B0/data.h"

/* Draw the inset viewport border with black bands and a one-pixel outline. */
void func_8026D8F8_de(void);
extern Gfx *D_80110634;
extern s32 D_800E28D0;
extern s32 D_800E28D4;

void func_80401D74_de(s32 inset) {
    f32 left;
    f32 top;
    f32 width;
    f32 height;
    func_8026D8F8_de();
    left = 0.0f;
    top = (f32)inset;
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(D_80110634++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    width = (f32)D_800E28D0;
    gDPSetPrimColor(D_80110634++, 0, 0, 0, 0, 0, 0);
    height = (f32)(D_800E28D4 - inset * 2);
    gDPFillRectangle(D_80110634++, left, top, (width - 1.0f), (top + (2.0f)));
    gDPFillRectangle(D_80110634++, left, ((top + height) - (2.0f)), ((left + width) - (1.0f)), ((top + height) - (1.0f)));
    gDPFillRectangle(D_80110634++, left, top, (left + (2.0f)), ((top + height) - 1.0f));
    gDPFillRectangle(D_80110634++, ((left + width) - (2.0f)), top, ((left + width) - (1.0f)), ((top + height) - (1.0f)));
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_FILL);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
    gDPSetRenderMode(D_80110634++, 0, 0);
    gDPSetFillColor(D_80110634++, 0x10001);
    gDPFillRectangle(D_80110634++, left, top, ((left + width) - 1.0f), top);
    gDPFillRectangle(D_80110634++, left, ((top + height) - (1.0f)), ((left + width) - (1.0f)), ((top + height) - (1.0f)));
    gDPFillRectangle(D_80110634++, left, top, left, ((top + height) - (1.0f)));
    gDPFillRectangle(D_80110634++, ((left + width) - (1.0f)), top, (left + width), ((top + height) - (1.0f)));
}
