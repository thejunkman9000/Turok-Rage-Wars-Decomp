#include "types.h"

/* Resource blocks store a count and relative offsets; unused entries carry
 * the resource builder's DEADBEEF sentinel. */
typedef struct ResourceBlock { s32 count; s32 offset[1]; } ResourceBlock;
typedef struct ResourceHandle { ResourceBlock *block; s32 bytes; } ResourceHandle;
typedef struct MotionHeader {
    s32 channels;
    s32 frames;
    s32 flags;
    f32 duration;
    s32 rotations;
    s32 translations;
    f32 frameCount;
    f32 frameStep;
} MotionHeader;

extern s32 func_80285180_de(void **, s32);
extern s32 func_8028FDC8_de(s32, s32, s32 *);
extern char *func_8028FDB4_de(s32 *, s32);
extern void *func_80254480_de(s32, void *, s32);
extern void *func_802BD3A0_de(void *, const void *, s32);
extern void func_80253838_de(s32, void *);
extern void func_80253D10_de(s32, void **, void *);
extern s32 func_8025F0F4_us_rev1(void *, void *, s32, s32, s32, s32);
extern const f32 D_800C411C_de, D_800C4120_de, D_800C4124_de;
extern const f32 D_800C4128_de, D_800C412C_de;
extern f32 D_8010AC70, D_8010AC7C, D_8010AC80;
extern s32 D_8010AC74, D_8010AC78, D_8010AC84, D_8010AC88;

static inline void resource_begin(ResourceBlock *block, s32 count, s32 bytes) {
    s32 i = 1;
    s32 *entry = &block->offset[0];
    block->count = count;
    block->offset[0] = bytes;
    do {
        entry[1] = 0xDEADBEEF;
        i++;
        entry++;
    } while (i <= count);
}

static inline char *resource_reserve(ResourceBlock *block, s32 bytes) {
    s32 count = block->count;
    s32 i = 0;
    s32 *entry;
    s32 sentinel;
    if (count >= 0) {
        sentinel = 0xDEADBEEF;
        entry = &block->count;
loop:
        if (entry[1] != sentinel) {
            i++;
            entry++;
            if (count >= i) goto loop;
        }
    }
    i--;
    block->offset[i+1] = block->offset[i] + bytes;
    return (char *)block + block->offset[i];
}

static inline void resource_copy(ResourceBlock *block, void *from, s32 bytes) {
    char *destination = resource_reserve(block, bytes);
    if (from != 0) func_802BD3A0_de(destination, from, bytes);
}

static inline s32 motion_storage(s32 channels, s32 frames) {
    s32 data = channels * 16;
    s32 offsets = (channels * 4 + 15) & ~7;
    return data * frames + offsets;
}

/* Rebuild the resource motion blocks, then replace the original handle. */
void func_8025F56C_de(s32 unused, ResourceHandle **handle) {
    s32 bytes0, bytes1, bytes2, bytes3, bytes4, bytes5, bytes6;
    s32 fetchedRotationBytes, fetchedTranslationBytes;
    ResourceBlock *source;
    void *section0, *section1, *section2, *section3, *section4;
    s32 rotationBytes, translationBytes;
    void *section6;
    ResourceBlock *motion;
    MotionHeader *header;
    ResourceHandle *output;
    ResourceBlock *result;
    ResourceBlock *newMotion;
    MotionHeader *newHeader;
    void *rotations, *translations, *newRotations, *newTranslations;
    s32 sourceBytes;
    s32 sourceFrames;
    s32 motionBytes;
    s32 success;
    f32 count;

    if (func_80285180_de((void **)handle, 1)) {
        source = (*handle)->block;
        sourceBytes = (*handle)->bytes;
        section0 = (void *)func_8028FDC8_de((s32)source, 0, &bytes0);
        section1 = (void *)func_8028FDC8_de((s32)source, 1, &bytes1);
        section2 = (void *)func_8028FDC8_de((s32)source, 2, &bytes2);
        section3 = (void *)func_8028FDC8_de((s32)source, 3, &bytes3);
        section4 = (void *)func_8028FDC8_de((s32)source, 4, &bytes4);
        motion = (ResourceBlock *)func_8028FDC8_de((s32)source, 5, &bytes5);
        header = (MotionHeader *)func_8028FDB4_de((s32 *)motion, 0);
        func_8028FDC8_de((s32)motion, 1, &fetchedRotationBytes);
        func_8028FDC8_de((s32)motion, 2, &fetchedTranslationBytes);
        section6 = (void *)func_8028FDC8_de((s32)source, 6, &bytes6);
        func_8028FDB4_de(section3, 0);
        sourceFrames = header->frames;
        D_8010AC84 = sourceFrames;
        D_8010AC88 = sourceFrames;
        header->frameCount = (f32)sourceFrames;
        header->frameStep = D_800C411C_de;
        if (sourceFrames >= 2) {
            count = (f32)(sourceFrames - 1);
            header->frameStep = count / count;
        }
        rotationBytes = motion_storage(header->translations, D_8010AC88);
        translationBytes = motion_storage(header->rotations, D_8010AC88);
        motionBytes = translationBytes + rotationBytes + 0x38;
        output = func_80254480_de(0, handle, sourceBytes - bytes5 + motionBytes + bytes6);
        if (output != 0) {
            result = output->block;
            resource_begin(result, 7, 0x28);
            resource_copy(result, section0, bytes0);
            resource_copy(result, section1, bytes1);
            resource_copy(result, section2, bytes2);
            resource_copy(result, section3, bytes3);
            resource_copy(result, section4, bytes4);
            newMotion = (ResourceBlock *)resource_reserve(result, motionBytes);
            resource_begin(newMotion, 3, 0x18);
            resource_copy(newMotion, header, 0x20);
            resource_reserve(newMotion, rotationBytes);
            resource_reserve(newMotion, translationBytes);
            resource_copy(result, section6, bytes6);
            newHeader = (MotionHeader *)func_8028FDB4_de((s32 *)motion, 0);
            rotations = func_8028FDB4_de((s32 *)motion, 1);
            translations = func_8028FDB4_de((s32 *)motion, 2);
            newRotations = func_8028FDB4_de((s32 *)newMotion, 1);
            newTranslations = func_8028FDB4_de((s32 *)newMotion, 2);
            D_8010AC78 = 1;
            D_8010AC74 = 0;
            D_8010AC7C = D_800C4120_de;
            D_8010AC80 = D_800C4124_de;
            D_8010AC70 = newHeader->duration;
            if (func_8025F0F4_us_rev1(rotations, newRotations, newHeader->translations, 3, newHeader->channels, newHeader->flags) == 0) {
                success = 0;
            } else {
                D_8010AC78 = 0;
                D_8010AC74 = 1;
                D_8010AC7C = D_800C4128_de;
                D_8010AC80 = D_800C412C_de;
                D_8010AC70 = newHeader->duration;
                success = func_8025F0F4_us_rev1(translations, newTranslations, newHeader->rotations, 4, newHeader->channels, newHeader->flags) != 0;
            }
            if (success == 0) {
                func_80253838_de(0, output);
                func_80253D10_de(0, (void **)handle, 0);
            } else {
                goto replace_output;
            }
        } else {
replace_output:
            func_80253D10_de(0, (void **)handle, output);
        }
    }
}
