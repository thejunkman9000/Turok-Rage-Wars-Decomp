#include "span_1000/code_802A8A94.h"
#include "span_1000/code_802A8A94.h"
#include "types.h"
#include "gfx.h"
#include "gbi.h"
#include "abi.h"
#include "n64sdk.h"

/* Draws a text string in the current font style D_801376F8: when centring, measures it through func_804422F0_de at the style size scaled by the language-dependent factors for D_80147150, shrinks the scale so it fits 44 pixels inside the screen width D_800E28D0 and shifts x left by half the width; then sets the environment colour from the style with the given alpha and the primitive colour from the style, and draws the string through func_802A88F0_de, first as a shadow when requested. */

extern s32 D_800E28D0;
extern Gfx *D_80110634;
extern f32 func_804422F0_de(s32 text, f32 size, f32 spacing);


void func_802A8F28_de(s32 text, s32 x, s32 y, s32 alpha, s32 centred, s32 shadow, f32 scaleX, f32 scaleY) {
    FontStyle *style;
    f32 sizeFactor;
    f32 spacing;
    f32 size;
    f32 width;
    f32 limit;
    f32 ratio;
    f32 fx;
    f32 fy;
    f32 w;
    f32 h;
    s32 language;

    style = &D_801376F8;
    if (centred) {
        switch (D_80147150) {
        case 0:
            sizeFactor = 24.0f;
            break;
        case 1:
            sizeFactor = 12.0f;
            break;
        case 3:
            sizeFactor = 6.0f;
            break;
        case 4:
        case 5:
            sizeFactor = 16.0f;
            break;
        case 2:
        case 6:
            sizeFactor = 8.0f;
            break;
        default:
            sizeFactor = 1.0f;
            break;
        }
        size = style->width * scaleX * sizeFactor;
        switch (D_80147150) {
        case 0:
            spacing = 24.0f;
            break;
        case 1:
            spacing = 12.0f;
            break;
        case 3:
            spacing = 6.0f;
            break;
        case 4:
        case 5:
            spacing = 16.0f;
            break;
        case 2:
        case 6:
            spacing = 8.0f;
            break;
        default:
            spacing = 1.0f;
            break;
        }
        width = func_804422F0_de(text, size, spacing);
        limit = D_800E28D0 - 0x2C;
        if (limit < width) {
            ratio = limit / width;
            scaleX *= ratio;
            width *= ratio;
        }
        x -= (s32)(width * 0.5f);
    }
    gDPPipeSync(D_80110634++);
    gDPSetEnvColor(D_80110634++, (u32)((style->envR)), (u32)((style->envG)), (u32)((style->envB)), (u32)((alpha)));
    gDPSetPrimColor(D_80110634++, 0, 0, (u32)((style->primR)), (u32)((style->primG)), (u32)((style->primB)), 255);
    fx = x;
    w = style->width * scaleX;
    h = style->height * scaleY;
    language = D_80147150;
    fy = y;
    if (shadow) {
        func_802A88F0_de(text, fx, fy, w, h, 1, alpha, language);
    }
    func_802A88F0_de(text, fx, fy, w, h, 0, alpha, language);
}

/* Emits the render-state display-list prologue for a flat colour pass: pipeline sync, one-cycle
   mode, the two combiner/mode presets through func_80268CE0_de and func_8026925C_de, the environment
   colour from the argument with full alpha bits, texture enable and the texture-filter, colour-dither
   and alpha-dither mode words, the alpha dither chosen by D_800E28D8. */

extern Gfx *D_80110634;
extern s32 D_800E28D8;

extern void func_80268CE0_de(s32 arg0);
extern void func_8026925C_de(s32 arg0);

void func_802A9234_de(s32 color) {
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
    func_80268CE0_de(0x1B);
    func_8026925C_de(0x19);
    {
        Gfx *cmd = D_80110634++;
        gDPSetEnvColor(cmd, 255, 255, 255, color);
    }
    gSPTexture(D_80110634++, 32768, 32768, 0, 0, G_ON);
    gDPSetTextureLUT(D_80110634++, G_TT_NONE);
    gDPSetTexturePersp(D_80110634++, G_TP_NONE);
    if (D_800E28D8 == 0) { gDPSetTextureFilter(D_80110634++, G_TF_POINT); } else { gDPSetTextureFilter(D_80110634++, G_TF_BILERP); }
}

extern Gfx *D_80110634;

void func_802A9364_de(void *pTexture, void *pOpacity, int XPos, int YPos, int TextureWidth, int TextureHeight) {
    { gDPSetTextureImage(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pOpacity); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { gDPSetTextureImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((TextureWidth*TextureHeight-1)<2047?(TextureWidth*TextureHeight-1):2047))), (u32)((((1<<11)+(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))-1)/(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (u32)((((TextureWidth*2)+7)>>3)), 0, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)((TextureWidth/16)), 256, 1, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0);
    gDPSetTileSize(D_80110634++, 1, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2)));
    { Gfx *g=D_80110634++; gDPTexRect(g, XPos<<2, YPos<<2, (XPos+TextureWidth)<<2, (YPos+TextureHeight)<<2, 0); gDPHalf1(D_80110634++, 0); gDPHalf2(D_80110634++, (((u32)((1<<10)) & 0xFFFF) << ((16)))|(((u32)((1<<10)) & 0xFFFF) << ((0)))); }
}

extern Gfx *D_80110634;

void func_802A9734_de(void *pTexture, void *pOpacity, float XPos, float YPos, int TextureWidth, int TextureHeight, float ScaleX, float ScaleY) {
 int dsdx=1024,dtdy; int xl,yl,xh,yh;
 if(ScaleX!=0.0f) dsdx=dsdx/ScaleX;
 dtdy=1024;
 if(ScaleY!=0.0f) dtdy=dtdy/ScaleY;
 xl=XPos*D_800C61B8_de; xh=(XPos+TextureWidth*ScaleX)*D_800C61B8_de;
 yl=YPos*D_800C61B8_de; yh=(YPos+TextureHeight*ScaleY)*D_800C61B8_de;

    { gDPSetTextureImage(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pOpacity); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { gDPSetTextureImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((TextureWidth*TextureHeight-1)<2047?(TextureWidth*TextureHeight-1):2047))), (u32)((((1<<11)+(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))-1)/(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (u32)((((TextureWidth*2)+7)>>3)), 0, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)((TextureWidth/16)), 256, 1, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0);
    gDPSetTileSize(D_80110634++, 1, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2)));
    gDPTexRect(D_80110634++,
        (s16)xl > 0 ? (s16)xl : 0, (s16)yl > 0 ? (s16)yl : 0,
        (s16)xh > 0 ? (s16)xh : 0, (s16)yh > 0 ? (s16)yh : 0,
        G_TX_RENDERTILE);
    gDPHalf1(D_80110634++, (((u32)((((short)xl<0 ? ((short)dsdx<0 ? -(((((short)xl*(short)dsdx)>>7))>((0))?((((short)xl*(short)dsdx)>>7)):((0))) : -(((((short)xl*(short)dsdx)>>7))<((0))?((((short)xl*(short)dsdx)>>7)):((0)))) : 0))) & 0xFFFF) << ((16)))
      | (((u32)(((yl<0 ? ((short)dtdy<0 ? -(((((short)yl*(short)dtdy)>>7))>((0))?((((short)yl*(short)dtdy)>>7)):((0))) : -(((((short)yl*(short)dtdy)>>7))<((0))?((((short)yl*(short)dtdy)>>7)):((0)))) : 0))) & 0xFFFF) << ((0))));
    gDPHalf2(D_80110634++, (((u32)((dsdx)) & 0xFFFF) << ((16)))|(((u32)((dtdy)) & 0xFFFF) << ((0))));
}

/* Appends display-list commands to D_80110634 that load a 4-bit texture block of the given size and draw it as a texture rectangle at the given position. Adapted from func_802A9364_de with the palette block and the second texture block removed and its first block's image pointer taken from the texture argument. */

extern Gfx *D_80110634;

void func_802A9CD0_de(void *pTexture, int XPos, int YPos, int TextureWidth, int TextureHeight) {
    { gDPSetTextureImage(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { Gfx *g=D_80110634++; gDPTexRect(g, XPos<<2, YPos<<2, (XPos+TextureWidth)<<2, (YPos+TextureHeight)<<2, 0); gDPHalf1(D_80110634++, 0); gDPHalf2(D_80110634++, (((u32)((1<<10)) & 0xFFFF) << ((16)))|(((u32)((1<<10)) & 0xFFFF) << ((0)))); }
}

/* Appends display-list commands to D_80110634 that load a 4-bit texture block of the given size and draw it as a texture rectangle at a floating-point position, stretched by the given horizontal and vertical scales with the texture steps divided by them. Adapted from func_802A9CD0_de with the position made floating point, the rectangle corners scaled by D_800C61BC_de and the scale factors applied to the extent and the texture step. */

extern Gfx *D_80110634;
extern f32 D_800C61BC_de;
void func_802A9EE8_de(void *pTexture, f32 XPos, f32 YPos, int TextureWidth, int TextureHeight, f32 ScaleX, f32 ScaleY) {
    int dsdx;
    int dtdy;
    int xl, yl, xh, yh;

    dsdx = 1 << 10;
    if (ScaleX != 0.0f) {
        dsdx = dsdx / ScaleX;
    }
    dtdy = 1 << 10;
    if (ScaleY != 0.0f) {
        dtdy = dtdy / ScaleY;
    }
    xl = XPos * D_800C61BC_de;
    xh = (XPos + TextureWidth * ScaleX) * D_800C61BC_de;
    yl = YPos * D_800C61BC_de;
    yh = (YPos + TextureHeight * ScaleY) * D_800C61BC_de;
    { gDPSetTextureImage(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { Gfx *g=D_80110634++; gDPTexRect(g, xl, yl, xh, yh, 0); gDPHalf1(D_80110634++, 0); gDPHalf2(D_80110634++, (((u32)((dsdx)) & 0xFFFF) << ((16)))|(((u32)((dtdy)) & 0xFFFF) << ((0)))); }
}
