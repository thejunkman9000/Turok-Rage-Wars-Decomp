#include "span_16E000/code_8040F1E0.h"
#include "types.h"
/* Returns a texture's resource id, first loading its pixel and 16-bit palette data, detecting a transparent palette entry and creating the texture resource when it is not yet loaded, and in both cases updates the texture's usage record for the requested mode (1 stamps the next expiry time, 2 pins it, 3 counts a reference); the opened file handle is stored through the header symbol as in the paletted texture loader, and the resource id is held in two locals (the second passed to func_80419640_de), which reproduces the cartridge's three stack slots. */









extern FileState D_801539B0;
extern FileHeader D_8014D724;
extern Entry_func_80410674_de *D_80153C10;
extern s32 *D_80153C14;
extern Usage *D_8014D988;
extern char D_800DD0B0;
extern void *func_8025305C_de(s32 size);
extern s32 func_802A0E8C_de(void *header, void *name);
extern void func_802A0EB0_de(s32 file);
extern void func_802A0ED4_de(void *buffer, s32 size, s32 count, s32 file);
extern void func_802A0F60_de(s32 file, s32 offset, s32 whence);
extern void func_802A18CC_de();
extern s32 func_802A1934_de(void);
extern void func_804133E4_de(s32 id);
extern void func_80413720_de(s32 id, s32 format, s16 width, s16 height, s32 stride, s32 rows, s32 a6, s32 size,
                          void *pixels, s32 a9, s32 paletteBytes, u16 *palette, s32 colors);
extern void func_80419640_de(s32 texture, s32 id);

static inline void touch(s32 index, s32 mode) {
    switch (mode) {
        case 1:
            if (D_8014D988[index].expiry != -1) {
                D_8014D988[index].expiry = func_802A1934_de() + 10;
            }
            break;
        case 2:
            D_8014D988[index].expiry = -1;
            break;
        case 3:
            D_8014D988[index].count++;
            break;
    }
}

s32 func_80410674_de(s32 index, s32 mode) {
    s32 id;
    s32 texture;
    u16 *palette;
    void *pixels;
    s32 paletteBytes;
    s32 stride;
    s32 transparent;
    s32 size;
    s32 i;
    s32 format;
    Entry_func_80410674_de *entry;

    if (D_80153C10[index].unk4 & 1) {
        touch(index, mode);
        return D_80153C10[index].unk0;
    }
    palette = 0;
    paletteBytes = 0;
    id = D_80153C10[index].unk0;
    stride = 0;
    func_802A18CC_de();
    ((FileState *)((char *)&D_8014D724 - 4))->unk0 = func_802A0E8C_de(&D_8014D724, &D_800DD0B0);
    entry = &D_8014D724.unk25C[index];
    transparent = 0;
    if (entry->unk8 == 8) {
        stride = (entry->unkA + 7) & -8;
    } else if (entry->unk8 == 4) {
        stride = (entry->unkA + 15) & -16;
    } else if (entry->unk8 == 16) {
        stride = (entry->unkA + 3) & -4;
    }
    func_804133E4_de(id);
    texture = id;
    size = stride * entry->unkC * entry->unk8 / 8;
    pixels = func_8025305C_de(size);
    func_802A0F60_de(D_801539B0.unk0, D_801539B0.unk248 + entry->unk14, 0);
    func_802A0ED4_de(pixels, size, 1, D_801539B0.unk0);
    if (entry->unkE > 0) {
        paletteBytes = entry->unkE * 2;
        palette = func_8025305C_de(paletteBytes);
        func_802A0F60_de(D_801539B0.unk0, D_801539B0.unk248 + entry->unk18, 0);
        func_802A0ED4_de(palette, paletteBytes, 1, D_801539B0.unk0);
        for (i = 0; i < entry->unkE; i++) {
            if (!(palette[i] & 1)) {
                transparent = 1;
                D_80153C14[index] = palette[i];
                break;
            }
        }
        if (i == entry->unkE) {
            transparent = 0;
            D_80153C14[index] = 0xFF000000;
        }
    }
    format = -1;
    if (entry->unkE > 0) {
        if (entry->unk8 == 8) {
            format = 32;
            if (transparent) {
                format = 30;
            }
        } else {
            format = 22;
            if (transparent) {
                format = 20;
            }
        }
    } else if (entry->unk8 == 16) {
        format = 5;
    } else if (entry->unk8 == 24) {
        format = 8;
    } else if (entry->unk8 == 32) {
        format = 12;
    }
    func_80413720_de(id, format, entry->unkA, entry->unkC, stride, entry->unkC, 1, size, pixels, 1, paletteBytes,
                  palette, entry->unkE);
    func_80419640_de(texture, id);
    D_80153C10[index].unk4 |= 1;
    func_802A0EB0_de(D_801539B0.unk0);
    D_801539B0.unk0 = 0;
    func_802A18CC_de();
    touch(index, mode);
    return D_80153C10[index].unk0;
}
