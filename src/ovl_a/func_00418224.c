/* func_00418224 (ROM 0x186224, 767 insns) - draws the current texture (D_800E32A4) scaled into the rectangle (x0,y0)-(x1,y1) in strips that fit TMEM.
 * Per strip: a gDPLoadTextureBlock_4b/8b/16b-style load (the SDK macro expansion written out through Q_PUSH, see include/q02_tex.h) and a gSPTextureRectangle.
 *
 * Needs @SN.  No pins, no asm.  What matters for the ROM allocation / schedule (details in wip/out/FINDINGS.txt):
 *  - the loop-invariant SDK macro arguments (stripRows - 1, tw * stripRows, ((tw*stripRows+3)>>2), the F540 line word, the tile-size word) are written INLINE in the
 *    loop body (macros below): loop.c hoists them and the allocator spills them, which gives the ROM's sp20/sp24/sp28/sp2C slots.  A pinned or hard-register tw would
 *    make them non-invariant (loop.c never moves anything that uses a hard register);
 *  - y0 / y1 / x0 / x1 are used as the parameters themselves (a copy into a pinned local drops the a3 preference of the long-lived y1 pseudo, and the hoisted
 *    &D_80110634 then takes a3 instead of t0);
 *  - hCopy = h BEFORE the first use of h, wCopy = w: the later float conversions use the copies (the ROM's addu a3,v0 / addu a2,a0);
 *  - srcHi = (s32)srcH is computed before dtdy (orders the two trunc.w.s);
 *  - switch cases 8/0x10/0x18: stripRows = (K / w) & ~1 BEFORE rowBytes;
 *  - the gSPTextureRectangle word is ((0xE4000000 | lrx_part) | lry_part) (SDK _SHIFTL order).
 */
#include "q02_tex.h"
extern Q2Tex *D_800E32A4;
extern s32 D_800E32B0;
extern s32 D_800E32B4;
extern s32 D_800E32B8;
extern f32 D_800E1434;
extern f32 D_800E1438[];
#define ROWS_M1 (stripRows - 1)
#define LINE_WORD_4B ((((((tw >> 1) + 7) >> 3) & 0x1FF) << 9) | 0xF5400000)
#define TILESIZE_W1 ((((((tw - 1) * 4) & 0xFFF) << 12)) | (((stripRows - 1) * 4) & 0xFFF))
#define TEXELS (tw * stripRows)
#define LRS_4B ((TEXELS + 3) >> 2)
#define LRS_8B ((TEXELS + 1) >> 1)
void func_00418224(s32 x0, s32 y0, s32 x1, s32 y1, f32 s0, f32 t0, f32 s1, f32 t1) {
    s32 invDtdy, dsdx, dtdy, rowBytes, texRows, sStart, tStart, headerDone, rowPos, stripRows;
    s32 w;
    s32 h;
    s32 tw;
    s32 dy;
    s32 top;
    s32 bottom;
    s32 tOff;
    s32 imgPtr;
    s32 mode;
    s32 wCopy;
    s32 hCopy;
    s32 srcHi;
    f32 srcH;
    headerDone = 0;
    w = D_800E32A4->unk4;
    if (w != 0) {
        h = D_800E32A4->unk6;
        if (h != 0 && x0 != x1 && y0 != y1) {
            hCopy = h;
            srcH = (t1 - t0) * (f32)h;
            srcHi = (s32)srcH;
            wCopy = w;
            dy = (y1 - y0) + 1;
            dsdx = (s32)((s1 - s0) * (f32)w * D_800E1434) / ((x1 - x0) + 1);
            mode = D_800E32B8;
            tw = D_800E32A4->w;
            D_800E32B4 = 0;
            dtdy = (s32)(srcH * D_800E1434) / dy;
            if (srcHi == 0) {
                invDtdy = 0x3E8;
            } else {
                invDtdy = (s32)(((f32)dy * D_800E1434) / srcH);
            }
            y0 <<= 10;
            x0 <<= 10;
            x1 <<= 10;
            tStart = (s32)(t0 * (f32)hCopy * D_800E1438[0]);
            y1 <<= 10;
            switch (mode) {
            case 4: {
                s16 u = (u16)D_800E32A4->w;
                stripRows = (0x1000 / u) & ~1;
                rowBytes = u / 2;
                break;
            }
            case 8:
                stripRows = (0x800 / D_800E32A4->w) & ~1;
                rowBytes = D_800E32A4->w;
                break;
            case 0x10:
                rowBytes = D_800E32A4->w * 2;
                stripRows = (0x800 / D_800E32A4->w) & ~1;
                break;
            case 0x18:
                stripRows = (0x400 / D_800E32A4->w) & ~1;
                rowBytes = D_800E32A4->w * 4;
                break;
            default:
                rowBytes = 0;
                stripRows = 0;
                break;
            }
            if (D_800E32A4->unk6 < stripRows) {
                stripRows = D_800E32A4->unk6;
            }
            rowPos = 0;
            texRows = D_800E32A4->unk6;
            sStart = (s32)(s0 * (f32)wCopy * D_800E1438[1]);
            if (texRows >= 0) {
                do {
                    tOff = 0;
                    top = y0 + ((invDtdy * ((rowPos << 10) - tStart)) >> 10);
                    bottom = (y0 + ((invDtdy * (((rowPos + stripRows) << 10) - tStart)) >> 10)) - 0x400;
                    imgPtr = D_800E32A4->img + rowPos * rowBytes;
                    rowPos = rowPos + stripRows;
                    if (bottom < top) {
                        tOff = top;
                        top = bottom;
                        bottom = tOff;
                        tOff = ROWS_M1 << 10;
                    }
                    if (y1 >= top && bottom >= y0) {
                        if (top < y0) {
                            tOff += ((y0 - top) * dtdy) >> 10;
                            top = y0;
                        }
                        if (y1 < bottom) {
                            bottom = y1;
                        }
                        if (D_800E32B0 == 0) {
                            switch (mode) {
                            case 4:
                                Q_PUSH(0xFD500000, imgPtr);
                                Q_PUSH(0xF5500000, 0x07080200);
                                Q_PUSH(0xE6000000, 0);
                                Q_PUSH(0xF3000000, Q_LOADBLK(tw, 16, LRS_4B - 1));
                                Q_PUSH(0xE7000000, 0);
                                Q_PUSH(LINE_WORD_4B, 0x80200);
                                Q_PUSH(0xF2000000, TILESIZE_W1);
                                break;
                            case 8:
                                Q_PUSH(0xFD500000, imgPtr);
                                Q_PUSH(0xF5500000, 0x07080200);
                                Q_PUSH(0xE6000000, 0);
                                Q_PUSH(0xF3000000, Q_LOADBLK(tw, 8, LRS_8B - 1));
                                Q_PUSH(0xE7000000, 0);
                                Q_PUSH(0xF5480000 | ((((tw + 7) >> 3) & 0x1FF) << 9), 0x80200);
                                Q_PUSH(0xF2000000, TILESIZE_W1);
                                break;
                            case 0x10:
                                Q_PUSH(0xFD100000, imgPtr);
                                Q_PUSH(0xF5100000, 0x07080200);
                                Q_PUSH(0xE6000000, 0);
                                Q_PUSH(0xF3000000, Q_LOADBLK(tw, 4, TEXELS - 1));
                                Q_PUSH(0xE7000000, 0);
                                Q_PUSH(0xF5100000 | (((((tw * 2) + 7) >> 3) & 0x1FF) << 9), 0x80200);
                                Q_PUSH(0xF2000000, TILESIZE_W1);
                                break;
                            }
                        } else {
                            switch (mode) {
                            case 4:
                                Q_PUSH(0xFD500000, imgPtr);
                                Q_PUSH(0xF5500000, 0x07080200);
                                Q_PUSH(0xE6000000, 0);
                                Q_PUSH(0xF3000000, ((Q_MIN(LRS_4B - 1, 2047) & 0xFFF) << 12) | 0x07000000);
                                Q_PUSH(0xE7000000, 0);
                                Q_PUSH(LINE_WORD_4B, 0x80200);
                                Q_PUSH(0xF2000000, TILESIZE_W1);
                                break;
                            case 8:
                                if (headerDone == 0) {
                                    headerDone = 1;
                                    Q_PUSH(0xF5500000, 0x07080200);
                                    Q_PUSH(0xF5480000 | ((((tw + 7) >> 3) & 0x1FF) << 9), 0x80200);
                                    Q_PUSH(0xF2000000, TILESIZE_W1);
                                    Q_PUSH(0xE7000000, 0);
                                }
                                Q_PUSH(0xE6000000, 0);
                                Q_PUSH(0xFD500000, imgPtr);
                                Q_PUSH(0xF3000000, ((Q_MIN(LRS_8B - 1, 2047) & 0xFFF) << 12) | 0x07000000);
                                break;
                            case 0x10:
                                Q_PUSH(0xFD100000, imgPtr);
                                Q_PUSH(0xF5100000, 0x07080200);
                                Q_PUSH(0xE6000000, 0);
                                Q_PUSH(0xF3000000, ((Q_MIN(TEXELS - 1, 2047) & 0xFFF) << 12) | 0x07000000);
                                Q_PUSH(0xE7000000, 0);
                                Q_PUSH(0xF5100000 | (((((tw * 2) + 7) >> 3) & 0x1FF) << 9), 0x80200);
                                Q_PUSH(0xF2000000, TILESIZE_W1);
                                break;
                            }
                        }
                        Q_PUSH((0xE4000000 | ((((x1 >> 8) + 4) & 0xFFF) << 12)) | (((bottom >> 8) + 4) & 0xFFF), (((x0 >> 8) & 0xFFF) << 12) | ((top >> 8) & 0xFFF));
                        Q_PUSH(0xE1000000, ((sStart >> 5) << 16) | ((tOff >> 5) & 0xFFFF));
                        Q_PUSH(0xF1000000, (dsdx << 16) | (dtdy & 0xFFFF));
                    }
                } while (texRows >= rowPos);
            }
        }
    }
}
