#include "types.h"
#include "n64sdk.h"
#include "gbi.h"

/* Preserve the original SDK shift expression used by the texture commands. */
#include "sdk/mbi.h"

extern void func_80253BBC_de(s32 heap, void **resource);
extern void *func_8028FDB4_de(void *table, s32 index);
extern void func_802955EC_us_rev1(s32 resource, s32 **data);
extern void func_802956AC_us_rev1(s32 resource, s32 **data);
extern s32 D_800CD890;
extern Gfx D_800D0FA0[], D_800D1020[], D_800D10A0[], D_800D1138[], D_800D11D0[];
extern Gfx *D_80110634;
extern s32 D_8014D070, D_8014D074, D_8014D078, D_8014D07C;


void func_80295FB4_us_rev1(s32 *output, void **resource, s32 frame, s32 secondary, s32 scaleS, s32 scaleT, s32 wrapS, s32 wrapT, s32 mode) {
    s32 *texture;
    s32 *palette;
    void *header;
    void *entries;
    u8 *info;
    s32 changed;
    s32 paletteChanged;
    u8 maskS;
    u8 maskT;
    s32 level;
    s32 tile;
    Gfx *list;

    func_80253BBC_de(0, resource);
    header = *resource;
    info = func_8028FDB4_de(header, 0);
    texture = func_8028FDB4_de(func_8028FDB4_de(header, 1), frame);
    entries = func_8028FDB4_de(header, 2);
    if (*(s32 *)entries != 0) {
        palette = func_8028FDB4_de(entries, secondary);
        paletteChanged = 0;
        if (D_800CD890 != (s32)resource || D_8014D074 != secondary) paletteChanged = 1;
    } else {
        paletteChanged = 0;
        palette = 0;
    }
    changed = 0;
    if (D_800CD890 != (s32)resource || D_8014D070 != frame || D_8014D078 != wrapS || D_8014D07C != wrapT) {
        changed = 1;
    }
    if (changed || paletteChanged) {
        D_800CD890 = (s32)resource;
        D_8014D070 = frame;
        D_8014D074 = secondary;
        D_8014D078 = wrapS;
        D_8014D07C = wrapT;
        maskS = 0;
        if (!(wrapS & G_TX_CLAMP)) {
            maskS = info[2];
        }
        maskT = 0;
        if (!(wrapT & G_TX_CLAMP)) {
            maskT = info[3];
        }
        func_802955EC_us_rev1((s32)resource, &texture);
        func_802956AC_us_rev1((s32)resource, &palette);
        switch (info[0]) {
        case 0:
            if (changed) {
                {      gDPSetTextureImage(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, texture);      gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, wrapT, maskT, mode, wrapS, maskS, mode);      gDPLoadSync(D_80110634++);      gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (((((1 << info[2]) * (1 << info[3]) + (1)) >> (1)) - 1) < 2047 ? ((((1 << info[2]) * (1 << info[3]) + (1)) >> (1)) - 1) : 2047), (((1 << G_TX_DXT_FRAC) + (1 > ((1) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (1)) / 8)) ? 1 : ((1) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (1)) / 8))) - 1) / (1 > ((1) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (1)) / 8)) ? 1 : ((1) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (1)) / 8)))));      gDPPipeSync(D_80110634++);      gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_8b, ((1 << info[2]) + 7) >> 3, 0, G_TX_RENDERTILE, 0, wrapT, maskT, mode, wrapS, maskS, mode);      gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, ((1 << info[2]) - 1) << 2, ((1 << info[3]) - 1) << 2); };
                gDPSetTextureLUT(D_80110634++, G_TT_RGBA16);
            }
            if (paletteChanged) {
                     gDPSetTextureImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, palette);      gDPTileSync(D_80110634++);      gDPSetTile(D_80110634++, 0, 0, 0, 256, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);      gDPLoadSync(D_80110634++);      gDPLoadTLUTCmd(D_80110634++, G_TX_LOADTILE, 255);      gDPPipeSync(D_80110634++);
            }
            break;
        case 1:
            if (changed) {
                {      gDPSetTextureImage(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, texture);      gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, wrapT, maskT, mode, wrapS, maskS, mode);      gDPLoadSync(D_80110634++);      gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (((((1 << info[2]) * (1 << info[3]) + (3)) >> (2)) - 1) < 2047 ? ((((1 << info[2]) * (1 << info[3]) + (3)) >> (2)) - 1) : 2047), (((1 << G_TX_DXT_FRAC) + (1 > ((0) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (0)) / 8)) ? 1 : ((0) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (0)) / 8))) - 1) / (1 > ((0) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (0)) / 8)) ? 1 : ((0) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (0)) / 8)))));      gDPPipeSync(D_80110634++);      gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_4b, (((1 << info[2]) >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, wrapT, maskT, mode, wrapS, maskS, mode);      gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, ((1 << info[2]) - 1) << 2, ((1 << info[3]) - 1) << 2); };
                gDPSetTextureLUT(D_80110634++, G_TT_RGBA16);
            }
            if (paletteChanged) {
                     gDPSetTextureImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, palette);      gDPTileSync(D_80110634++);      gDPSetTile(D_80110634++, 0, 0, 0, 256, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);      gDPLoadSync(D_80110634++);      gDPLoadTLUTCmd(D_80110634++, G_TX_LOADTILE, 15);      gDPPipeSync(D_80110634++);
            }
            break;
        case 3:
            if (changed) {
                {      gDPSetTextureImage(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, texture);      gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, wrapT, maskT, mode, wrapS, maskS, mode);      gDPLoadSync(D_80110634++);      gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (((((1 << info[2]) * (1 << info[3]) + (3)) >> (2)) - 1) < 2047 ? ((((1 << info[2]) * (1 << info[3]) + (3)) >> (2)) - 1) : 2047), (((1 << G_TX_DXT_FRAC) + (1 > ((0) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (0)) / 8)) ? 1 : ((0) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (0)) / 8))) - 1) / (1 > ((0) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (0)) / 8)) ? 1 : ((0) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (0)) / 8)))));      gDPPipeSync(D_80110634++);      gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_4b, (((1 << info[2]) >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, wrapT, maskT, mode, wrapS, maskS, mode);      gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, ((1 << info[2]) - 1) << 2, ((1 << info[3]) - 1) << 2); };
                gDPSetTextureLUT(D_80110634++, G_TT_IA16);
            }
            if (paletteChanged) {
                     gDPSetTextureImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, palette);      gDPTileSync(D_80110634++);      gDPSetTile(D_80110634++, 0, 0, 0, 256, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);      gDPLoadSync(D_80110634++);      gDPLoadTLUTCmd(D_80110634++, G_TX_LOADTILE, 15);      gDPPipeSync(D_80110634++);
            }
            break;
        case 2:
            if (changed) {
                {      gDPSetTextureImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 1, texture);      gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 0, 0, G_TX_LOADTILE, 0, wrapT, maskT, mode, wrapS, maskS, mode);      gDPLoadSync(D_80110634++);      gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (((((1 << info[2]) * (1 << info[3]) + (0)) >> (0)) - 1) < 2047 ? ((((1 << info[2]) * (1 << info[3]) + (0)) >> (0)) - 1) : 2047), (((1 << G_TX_DXT_FRAC) + (1 > ((4) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (4)) / 8)) ? 1 : ((4) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (4)) / 8))) - 1) / (1 > ((4) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (4)) / 8)) ? 1 : ((4) == 0 ? ((1 << info[2]) / 16) : (((1 << info[2]) * (4)) / 8)))));      gDPPipeSync(D_80110634++);      gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_32b, ((2 << info[2]) + 7) >> 3, 0, G_TX_RENDERTILE, 0, wrapT, maskT, mode, wrapS, maskS, mode);      gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, ((1 << info[2]) - 1) << 2, ((1 << info[3]) - 1) << 2); };
                gDPSetTextureLUT(D_80110634++, G_TT_NONE);
            }
            break;
        case 4:
            if (changed) {
                gDPPipeSync(D_80110634++);
                gDPSetTextureImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture);
                switch (info[5]) {
                case 2:
                default:
                    list = D_800D10A0;
                    break;
                case 3:
                    list = D_800D1138;
                    break;
                case 1:
                    gDPSetTextureDetail(D_80110634++, G_TD_SHARPEN);
                    list = D_800D0FA0;
                    if (wrapS & 1) list = D_800D1020;
                    break;
                case 0:
                    gDPSetTextureDetail(D_80110634++, G_TD_CLAMP);
                    list = D_800D0FA0;
                    if (wrapS & 1) list = D_800D1020;
                    break;
                }
                gSPDisplayList(D_80110634++, list);
            }
            break;
        case 5:
            if (changed) {
                gDPPipeSync(D_80110634++);
                gDPSetTextureImage(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 1, texture);
                gSPDisplayList(D_80110634++, D_800D11D0);
            }
            break;
        }
    } else {
        gDPPipeSync(D_80110634++);
    }
    switch (info[0]) {
    case 4: level = 5; tile = 0; break;
    case 5: level = 6; tile = 0; break;
    default: level = 0; tile = 0; break;
    }
    gSPTexture(D_80110634++, scaleS, scaleT, level, tile, G_ON);
}
