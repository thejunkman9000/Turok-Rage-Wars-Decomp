#include "b08_types.h"

typedef struct TextNode {
    u8 pad0[0xC];
    f32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 *unk24;
    s32 unk28;
    s32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
} TextNode;

typedef struct TextSrc {
    u8 pad0[0xE40];
    s32 listE40;
    u8 padE44[0xE0];
    TextNode *freeF24;
} TextSrc;

void func_00239CD0(TextNode *n);
void func_00255E78(void *list, void *n);
void func_00255CB4(void *list, void *n);

extern u8 *D_800D7028;
extern u8 *D_800D7034;
extern s32 D_800E28D0;
extern s32 D_800E28D4;

static inline TextNode *takeNode(TextSrc *o, TextSrc *b) {
    TextNode *n;

    n = o->freeF24;
    if (n != NULL) {
        func_00239CD0(n);
        func_00255E78(&o->freeF24, n);
        func_00255CB4(&b->listE40, n);
    }
    return n;
}

static inline TextNode *spawnLines(TextSrc *o, TextSrc *b, u8 *str, s32 type, f32 sc, s32 id) {
    TextNode *n;
    u8 *p;
    u8 *start;
    u8 c;

    n = NULL;
    if (b == NULL) {
        return n;
    }
    {
        if (str == D_800D7034) {
            str = D_800D7028;
        }
        p = str;
        start = p;
        if (*p != 0) {
            do {
                p++;
                if (*p != '\n' && *p != 0) {
                    continue;
                }
                if (start != p) {
                    n = takeNode(o, b);
                    if (n != NULL) {
                    n->unk14 = type;
                    n->unk24 = start;
                    n->unk18 = 0;
                    n->unk10 = 1.0f;
                    n->unk1C = id;
                    n->unk20 = 0;
                    n->unk28 = 0;
                    n->unk2C = 0;
                    n->unk38 = 1.0f;
                    n->unk3C = 1.0f;
                    n->unk30 = D_800E28D0 / 2;
                    n->unk34 = D_800E28D4 - 0x50;
                    n->unkC = sc * 15.0f;
                    }
                    start = p + 1;
                }
            } while (*p != 0);
        }
    }
    return n;
}

TextNode *func_00239760(TextSrc *o, TextSrc *b, u8 *str, f32 sc) {
    return spawnLines(o, b, str, 2, sc, -1);
}


