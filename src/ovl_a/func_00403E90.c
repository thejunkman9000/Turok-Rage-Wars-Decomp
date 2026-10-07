#include "o01_types.h"

extern O01PadTab *D_800E2854;
extern OSPfs D_80153510[];
s32 osPfsFileState(OSPfs *pfs, s32 file_no, void *state);
s32 osPfsFreeBlocks(OSPfs *pfs, s32 *leo_bytes);

typedef struct O01E2 {
    /* 0x00 */ s32 pad0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u8 unkE[4];
    /* 0x12 */ u8 unk12[0x10];
} O01E2;
s32 func_00403E90(s32 pad) {
    s32 r;
    s32 i;
    s32 bytes;
    OSPfs *pfs;
    O01E2 *q;
    O01E2 *n;
    if (D_800E2854 != 0) {
        i = 0;
        pfs = &D_80153510[pad];
        for (; i < 16; i++) {
            r = osPfsFileState(pfs, i, &D_800E2854[pad].ent[i]);
            if (r != 0 && r != 5) {
                r = osPfsFileState(pfs, i, &D_800E2854[pad].ent[i]);
            }
            if (r == 5) {
                q = (O01E2 *)(pad * 0x204 + (u32)D_800E2854 + i * 0x20);
                q->unkE[0] = 0;
                q->unk4 = 0;
                q->unk8 = 0;
                q->unkC = 0;
                n = (O01E2 *)(pad * 0x204 + (u32)D_800E2854 + i * 0x20);
                n->unk12[0] = 0;
            }
        }
    }
    r = osPfsFreeBlocks(&D_80153510[pad], &bytes);
    if (r == 0) {
        D_800E2854[pad].unk0 = bytes;
    }
    return r;
}
