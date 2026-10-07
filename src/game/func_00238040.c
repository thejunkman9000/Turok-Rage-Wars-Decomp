#include "b08_types.h"

typedef struct TextNode TextNode;
struct TextNode {
    TextNode *next0;
    TextNode *next4;
    u8 pad8[0xC];
    s32 unk14;
    s32 unk18;
    u8 pad1C[8];
    u8 *unk24;
    f32 unk28;
    u8 pad2C[4];
    f32 unk30;
    f32 unk34;
};

typedef struct TextSrc {
    u8 pad0[0xE40];
    TextNode *listE40;
    TextNode *listE44;
    u8 padE48[0xDC];
    TextNode *freeF24;
} TextSrc;

void func_002A94E8();
void func_002A97F0();
void func_002A9F18(u8 *str, s32 x, s32 y, s32 a, s32 b, s32 c, f32 sx, f32 sy);
void func_00255E78(void *list, void *n);
void func_00255C58(void *list, void *n);

extern f32 D_800D2988;
extern s32 D_800E28D4;

void func_00238040(TextSrc *o, TextSrc *b) {
    TextNode *n;
    TextNode *p;
    TextNode *q;
    TextNode *next;
    f32 step;
    f32 v;
    f32 dy = 9.0f;

    if (b != NULL) {
        func_002A94E8();
        func_002A97F0();
        n = b->listE40;
        if (n != NULL) {
            p = n->next4;
            n->unk34 = (f32)D_800E28D4 * 0.81f;
            while (p != NULL) {
                p->unk34 = n->unk34 + dy;
                n = p;
                p = p->next4;
            }
        }
        for (p = b->listE44; p != NULL; p = p->next0) {
            func_002A9F18(p->unk24, (s32)p->unk30, (s32)p->unk34, p->unk18, 1, 1, 1.0f, 1.0f);
        }
        for (p = b->listE44; p != NULL; p = p->next0) {
            {
                n = p;
                step = D_800D2988 * 0.06666667f;
                switch (p->unk14) {
                case 2:
                    p->unk18 = (s32)(sinf(p->unk28 * 1.5707964f) * 255.0f);
                    p->unk28 = p->unk28 + step;
                    if (1.0f < p->unk28) {
                        p->unk14 = 3;
                        p->unk28 = 0.0f;
                    }
                    break;
                case 1:
                    p->unk18 = 0;
                    break;
                case 3:
                    p->unk18 = 255;
                    break;
                case 4:
                    p->unk18 = (s32)(cosf(p->unk28 * 1.5707964f) * 255.0f);
                    p->unk28 = p->unk28 + step;
                    if (1.0f < p->unk28) {
                        for (q = b->listE40; q != NULL; q = q->next4) {
                            if (q->unk14 == 1) {
                                q->unk14 = 2;
                                q->unk28 = 0.0f;
                            }
                        }
                        n->unk14 = 0;
                        n->unk28 = 0.0f;
                    }
                    break;
                default:
                    n->unk18 = 0;
                    n->unk14 = 0;
                    break;
                }
            }
        }
        p = b->listE44;
        if (p != NULL) {
            do {
                next = p->next0;
                if (p->unk14 == 0) {
                    func_00255E78(&b->listE40, p);
                    func_00255C58(&o->freeF24, p);
                }
                p = next;
            } while (p != NULL);
        }
    }
}
