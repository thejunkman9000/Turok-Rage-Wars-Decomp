#include "b24_types.h"

typedef struct AtlasCell {
    u32 w;
    u32 h;
} AtlasCell;

void func_002AAED8(u8 *, f32, f32, u32, u32, f32, f32);

void func_002AC1A0(u16 *hdr, f32 x0, f32 y, f32 sx, f32 sy) {
    f32 rows, cols, x;
    u32 w, h;
    u8 *p;
    p = (u8 *)hdr + 8;
    h = 0;
    rows = hdr[1];
    while (rows-- != 0.0f) {
        cols = hdr[0];
        x = x0;
        while (cols-- != 0.0f) {
            h = ((AtlasCell *)p)->h;
            w = ((AtlasCell *)p)->w;
            func_002AAED8(p + 8, x, y, w, h, sx, sy);
            x += (f32)w * sx;
            p += (w * h) >> 1;
            p += 8;
        }
        y += (f32)h * sy;
    }
}
