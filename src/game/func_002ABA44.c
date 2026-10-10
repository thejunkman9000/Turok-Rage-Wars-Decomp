#include "span_1000/code_802A8A94.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"
#include "math_helpers.h"
/* Emits pipe sync, primitive color and a rectangle with nonnegative coordinates. */
extern Gfx *D_80110634;
void func_802AAA54_de(s32 x0,s32 y0,s32 x1,s32 y1,u8 r,u8 g,u8 b,u8 a) {
 gDPPipeSync(D_80110634++);
 gDPSetPrimColor(D_80110634++, 255, 255, r, g, b, a);
 gDPFillRectangle(D_80110634++, ((x0))>((0))?((x0)):((0)), ((y0))>((0))?((y0)):((0)), ((x1))>((0))?((x1)):((0)), ((y1))>((0))?((y1)):((0)));
}
