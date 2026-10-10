#include "types.h"
/* Opens image archives and allocates image, palette, and cached-resource tables. */
void * func_8025305C_de(s32);
void func_802547E4_de(void *);
u8 * func_802A025C_de(u8 *, u8 *);
void * func_802A0748_de(void *, int, u32);
s32 func_802A0E8C_de(void *, void *);
extern char D_8014D724[];
extern char D_800DD0B0[];
void func_802A0EB0_de(s32);
s32 func_802A0ED4_de(s32, s32, s32, s32);
void func_802A0F60_de(s32, s32, s32);
void func_80419608_de(void *);
s32 func_8040F9E0_de();                     /* extern */






extern s32 D_80153C2C;

extern s32 D_800E2AC4[3];

typedef union { s16 count; s32 clear; } ArchiveCountWord; /* FAKEMATCH: shared views keep count reloads ordered with record clears. */
typedef struct func_8040FC14_S1 func_8040FC14_S1;
typedef struct func_8040FC14_S2 func_8040FC14_S2;
typedef struct func_8040FC14_S3 func_8040FC14_S3;
typedef struct func_8040FC14_S4 func_8040FC14_S4;
typedef struct func_8040FC14_S5 func_8040FC14_S5;
typedef struct func_8040FC14_S6 func_8040FC14_S6;
typedef struct func_8040FC14_S7 func_8040FC14_S7;
typedef struct func_8040FC14_S8 func_8040FC14_S8;
typedef struct func_8040FC14_S9 func_8040FC14_S9;
typedef struct func_8040FC14_S10 func_8040FC14_S10;
typedef struct func_8040FC14_S11 func_8040FC14_S11;
typedef struct func_8040FC14_S12 func_8040FC14_S12;
typedef struct func_8040FC14_S13 func_8040FC14_S13;
typedef struct func_8040FC14_S14 func_8040FC14_S14;
typedef struct func_8040FC14_S15 func_8040FC14_S15;
typedef struct func_8040FC14_S16 func_8040FC14_S16;
typedef struct func_8040FC14_S17 func_8040FC14_S17;
typedef struct func_8040FC14_S18 func_8040FC14_S18;
typedef struct func_8040FC14_S19 func_8040FC14_S19;
struct func_8040FC14_S1 {
    s32 unk0;
    char unk4[0x204];
    s32 unk208;
    u32 unk20C;
    char pad20C[0x4C];
    s16 unk25C;
    char pad25C[0x2];
    void* unk260;
    void* unk264;
    void* unk268;
    void* unk26C; /* FAKEMATCH: reload the resource base after linking a descriptor. */
};

typedef struct { char pad0[0xC]; u32 unkC; char padC[0xC]; s32 unk1C; } ImageHeader;
extern ImageHeader D_8014D940;
struct func_8040FC14_S2 {
    char pad0[0x12];
    u8 unk12;
};
struct func_8040FC14_S3 {
    void *unk0;
    s32 unk4;
    char pad8[0xA];
    s16 unk12;
    char pad14[8];
};
struct func_8040FC14_S4 {
    s32 unk0;
    s16 unk4;
}; /* FAKEMATCH: order table clears between the two table-base reloads. */
struct func_8040FC14_S5 {
    void* unk0;
};
struct func_8040FC14_S6 {
    char unk0[1];
};
struct func_8040FC14_S7 {
    s16 unk0;
    char pad0[0x2];
    void* unk4;
    char pad4[0xC];
    ArchiveCountWord unk14;
    void* unk18;
    void* unk1C;
};
struct func_8040FC14_S8 {
    char pad0[0x8];
    ArchiveCountWord unk8;
};
struct func_8040FC14_S9 {
    s16 unk0;
    char pad0[0xA];
    void* unkC;
    void* unk10;
};
struct func_8040FC14_S13 {
    s16 unk0;
    char pad2[2];
    void *raw;
    func_8040FC14_S15 *unk8;
};
struct func_8040FC14_S10 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    u32 unk28;
    char pad28[0x30];
    func_8040FC14_S13 objects;
    func_8040FC14_S7 palettes;
};
extern func_8040FC14_S10 D_8014D934;
struct func_8040FC14_S11 {
    char pad0[0x48C];
    void* unk48C;
};
struct func_8040FC14_S12 {
    char unk0[1];
};
struct func_8040FC14_S14 {
    char pad0[0x48C];
    void* unk48C;
};
struct func_8040FC14_S15 {
    char pad0[0x4];
    s8 unk4;
    char pad4[0x47F];
    void** unk484;
    void** unk488;
    func_8040FC14_S16 *metadata;
    char pad490[0xC];
};
struct func_8040FC14_S16 {
    char pad0[0x8];
    s16 unk8;
    char pad8[0x4];
    s16 unkE;
    char padE[4];
    s32 unk14;
    s32 unk18;
};
struct func_8040FC14_S17 {
    char unk0[1];
};
struct func_8040FC14_S18 {
    char unk0[1];
};
struct func_8040FC14_S19 {
    s32 unk0;
    char pad4[8];
    s32 unkC;
    func_8040FC14_S10 header;
    char pad98[0x8];
    s32 unkA0;
};
extern func_8040FC14_S19 D_8014D924;
typedef union {
    func_8040FC14_S1 images;
    struct { char prefix[0x204]; func_8040FC14_S19 status; } archive;
} ArchiveContext;
extern ArchiveContext D_801539B0;



/* FAKEMATCH: preserve the ordered table-base reloads around the two clears. */
/* FAKEMATCH: reload the map table base on each record clear. */
typedef struct { s16 count; func_8040FC14_S3 *res; s32 unk8; func_8040FC14_S4 *tim; } F4Pool0;
extern F4Pool0 D_80153C0C;
typedef struct { s16 count; s16 pad2[3]; func_8040FC14_S15 *entries; } F4Pool2;
extern F4Pool2 D_80153C20;
typedef struct { s16 count; func_8040FC14_S8 *primary; void *secondary; void *flags; void *refs; } F4Buf;
extern F4Buf D_80153C40;
/* Opens image archives and allocates image, palette, and cached-resource tables. */
void func_0040FC14(u8 *arg0) {
    void *state; /* FAKEMATCH: recycle the file base for the final status view, ending its old live range. */
    void * regpart_state;
    func_8040FC14_S10 *header;
    func_8040FC14_S7 *palettes;
    register s32 recordData __asm__("$19"); /* FAKEMATCH: share the field-derived member address and later object counter in one N64 integer local; their lifetimes are disjoint. */
    func_8040FC14_S13 *objects;
    func_8040FC14_S15 **objectTable;
    ArchiveCountWord *mapCount;
    s16 temp_a0_3;
    s16 temp_hi;
    s16 temp_v0_3;
    s32 ofs3;
    s32 temp_a0; /* FAKEMATCH: reuse the record-link offset as the object index to raise its allocator priority. */
    void **temp_a0_2;
    void **temp_a0_4;
    s32 temp_a1;
    s32 temp_a3;
    s32 var_s2; /* FAKEMATCH: reuse the descriptor index as the later palette stride to preserve allocation lifetime. */
    s32 temp_v1;
    s32 var_a1; /* FAKEMATCH: share the two independent pointer-array indices. */
    s32 var_a2; /* FAKEMATCH: share the independent linking and block-offset counters. */
    register s32 var_s0 __asm__("$16"); /* FAKEMATCH: reuse the image, map, and record-link indices to preserve their shared saved register. */
    extern s32 D_8014D970;
    s32 var_s4;
    s32 var_v1;
    u32 temp_v0_2;
    u32 temp_v1_2;
    void **temp_v1_3;
    void **temp_v1_4;
    func_8040FC14_S16 *temp_s0;
    func_8040FC14_S15 *temp_s1;
    void *temp_s7;
    func_8040FC14_S2 *temp_v0;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    func_8040FC14_S3 *var_s1;

    temp_a3 = func_802A0E8C_de(arg0, D_800DD0B0);
    state = &D_801539B0.images;
    ((func_8040FC14_S1 *)state)->unk0 = temp_a3;
    func_802A0ED4_de((s32) &((func_8040FC14_S1 *)state)->unk208, 0x54, 1, temp_a3);
    temp_hi = ((func_8040FC14_S1 *)state)->unk20C / 28;
    ((func_8040FC14_S1 *)state)->unk25C = temp_hi;
    if (temp_hi > 0) {
        ((func_8040FC14_S1 *)state)->unk26C = func_8025305C_de(temp_hi << 5);
        ((func_8040FC14_S1 *)state)->unk268 = func_8025305C_de(((func_8040FC14_S1 *)state)->unk25C * 8);
        ((func_8040FC14_S1 *)state)->unk264 = func_8025305C_de(((func_8040FC14_S1 *)state)->unk25C * 4);
        temp_v0 = func_8025305C_de((s32) ((func_8040FC14_S1 *)state)->unk20C);
        ((func_8040FC14_S1 *)state)->unk260 = temp_v0;
        var_s1 = (void *)temp_v0;
        func_802A0F60_de(((func_8040FC14_S1 *)state)->unk0, ((func_8040FC14_S1 *)state)->unk208, 0);
        func_802A0ED4_de((s32) var_s1, 0x1C, (s32) ((func_8040FC14_S1 *)state)->unk25C, ((func_8040FC14_S1 *)state)->unk0);
        var_s0 = 0;
        if (((func_8040FC14_S1 *)state)->unk25C > 0) {
            recordData = (s32) &((func_8040FC14_S1 *)state)->unk26C;
            var_s2 = 0;
            do {
                temp_v1 = var_s0;
                var_s1->unk4 = 0;
                var_s1->unk12 = 0;
                temp_a1 = var_s0 << 5;
                D_80153C0C.tim[var_s0].unk4 = 0;
                D_80153C0C.tim[var_s0].unk0 = 0;
                var_s0 += 1;
                D_80153C0C.res[var_s2].unk0 = ((void *)&((func_8040FC14_S6 *)((*((void **)recordData))))->unk0[temp_a1]);
                func_80419608_de((u8 *)*((void **)recordData) + temp_a1);
                var_s2 += 1;
                var_s1++;
            } while (var_s0 < *(s16 *)((u8 *)recordData - 0x10));
        }
    }
    palettes = &D_8014D924.header.palettes;
    temp_v0_2 = (u32) D_8014D924.header.unk18 >> 3;
    palettes->unk0 = (s16) temp_v0_2;
    if ((s32)(temp_v0_2 << 0x10) > 0) {
        palettes->unk4 = func_8025305C_de((s32) D_8014D924.header.unk18);
        func_802A0F60_de(((func_8040FC14_S1 *)state)->unk0, D_8014D924.header.unk14, 0);
        func_802A0ED4_de((s32) palettes->unk4, (s32) D_8014D924.header.unk18, 1, ((func_8040FC14_S1 *)state)->unk0);
        func_8040F9E0_de(0);
    }
    temp_v0_3 = D_8014D924.header.unk28 / 12;
    palettes->unk14.count = temp_v0_3;
    if ((s32)((u32)temp_v0_3 << 0x10) > 0) {
        palettes->unk18 = func_8025305C_de(D_8014D924.header.unk28);
        if (*D_800E2AC4 != 0) {
            temp_v0_4 = func_8025305C_de(D_8014D924.header.unk28);
            palettes->unk1C = temp_v0_4;
            func_802A0748_de(temp_v0_4, 0, (u32) D_8014D924.header.unk28);
        }
        func_802A0F60_de(((func_8040FC14_S1 *)state)->unk0, D_8014D924.header.unk24, 0);
        func_802A0ED4_de((s32) palettes->unk18, D_8014D924.header.unk28, 1, ((func_8040FC14_S1 *)state)->unk0);
        if (palettes->unk14.count > 0) {
        var_s0 = 0;
        mapCount = &palettes->unk14;
            var_v1 = 0;
            do {
                var_s0 += 1;
                D_80153C40.primary[var_v1].unk8.clear = 0;
                var_v1 += 1;
            } while (var_s0 < mapCount->count);
        }
        temp_v0_5 = func_8025305C_de(D_80153C40.count * 2);
        D_80153C40.refs = temp_v0_5;
        func_802A0748_de(temp_v0_5, 0, D_80153C40.count * 2);
        temp_v0_6 = func_8025305C_de(D_80153C40.count * 2);
        D_80153C40.flags = temp_v0_6;
        func_802A0748_de(temp_v0_6, 0, D_80153C40.count * 2);
    }
    header = &D_8014D924.header;
    if (header->unk0 > 0) {
        var_s0 = 0;
        temp_s7 = func_8025305C_de(header->unk8);
        func_802A0F60_de(((func_8040FC14_S1 *)state)->unk0, header->unk4, 0);
        func_802A0ED4_de((s32) temp_s7, header->unk8, 1, ((func_8040FC14_S1 *)state)->unk0);
        header->objects.raw = func_8025305C_de(header->unk0);
        func_802A0F60_de(((func_8040FC14_S1 *)state)->unk0, ((func_8040FC14_S19 *)&D_8014D924)->unkC, 0);
        func_802A0ED4_de((s32) header->objects.raw, header->unk0, 1, ((func_8040FC14_S1 *)state)->unk0);
        temp_v1_2 = (u32) header->unk0 >> 5;
        header->objects.unk0 = (s16) temp_v1_2;
        temp_v0_7 = func_8025305C_de((s16) temp_v1_2 * 0x49C);
        header->objects.unk8 = temp_v0_7;
        func_802A0748_de(temp_v0_7, 0, header->objects.unk0 * 0x49C);
        if (header->objects.unk0 > 0) {
            var_a1 = (s32) &header->objects.raw;
            var_a2 = 0;
            __asm__ volatile("");
            do {
                ofs3 = var_s0 << 5;
                var_s0 += 1;
                do { D_80153C20.entries[var_a2].metadata = ((void *)&((func_8040FC14_S12 *)(*((void **)var_a1)))->unk0[ofs3]); } while (0);
                var_a2 += 1;
            } while (var_s0 < *(s16 *)((u8 *)var_a1 - 4));
        }
        objects = &D_8014D924.header.objects;
        temp_a0 = 0;
        recordData = 0;
        if (objects->unk0 > 0) {
            objectTable = &objects->unk8;
            var_s4 = 0;
            do {
                temp_s0 = D_80153C20.entries[var_s4].metadata;
                temp_s1 = (*objectTable) + var_s4;
                func_802A0F60_de(((func_8040FC14_S1 *)state)->unk0, *(s32 *)((u8 *)objectTable - 0x58) + ((func_8040FC14_S16 *)temp_s0)->unk14, 0);
                func_802A0ED4_de(&temp_s1->unk4, 8, 0x60, ((func_8040FC14_S1 *)state)->unk0);
                temp_s1->unk484 = func_8025305C_de(temp_s0->unkE * 4);
                *temp_s1->unk484 = func_8025305C_de(temp_s0->unkE * 0x1080);
                func_802A0748_de(*temp_s1->unk484, 0, temp_s0->unkE * 0x1080);
                var_a1 = 0;
                if (temp_s0->unkE > 0) {
                    var_a2 = 0;
                    do {
                        temp_a0_2 = (void **)((var_a1 << 2) + (s32)temp_s1->unk484);
                        temp_v1_3 = temp_s1->unk484;
                        var_a1 += 1;
                        *temp_a0_2 = ((void *)&((func_8040FC14_S17 *)((*temp_v1_3)))->unk0[var_a2]);
                        var_a2 += 0x1080;
                    } while (var_a1 < temp_s0->unkE);
                }
                temp_a0_3 = temp_s0->unkE;
                if (temp_a0_3 > 0) {
                    var_s2 = ((temp_s0->unk8 * 2) + 7) & ~7;
                    temp_s1->unk488 = func_8025305C_de(temp_a0_3 * 4);
                    *temp_s1->unk488 = func_8025305C_de(temp_s0->unkE * var_s2);
                    func_802A0F60_de(((func_8040FC14_S1 *)state)->unk0, D_8014D970 + ((s32 *)temp_s7)[temp_a0], 0);
                    func_802A0ED4_de((s32) *temp_s1->unk488, temp_s0->unkE * var_s2, 1, ((func_8040FC14_S1 *)state)->unk0);
                    var_a1 = 0;
                    if (temp_s0->unkE > 0) {
                        var_a2 = 0;
                        do {
                            temp_a0_4 = (void **)((var_a1 << 2) + (s32)temp_s1->unk488);
                            temp_v1_4 = temp_s1->unk488;
                            var_a1 += 1;
                            *temp_a0_4 = ((void *)&((func_8040FC14_S18 *)((*temp_v1_4)))->unk0[var_a2]);
                            var_a2 += var_s2;
                        } while (var_a1 < temp_s0->unkE);
                    }
                    temp_a0 += temp_s0->unkE;
                }

                var_s4 += 1;
            } while (++recordData < D_80153C20.count);
        }
        func_802547E4_de(temp_s7);
    } else {
        header->objects.unk0 = 0;
    }
    regpart_state = &D_801539B0.archive.status;
    ((func_8040FC14_S19 *)regpart_state)->unk0 = 1;
    func_802A025C_de(D_801539B0.images.unk4, arg0);
    ((func_8040FC14_S19 *)regpart_state)->unkA0 = 0;
    func_802A0EB0_de(D_801539B0.images.unk0);
    D_801539B0.images.unk0 = 0;
}

