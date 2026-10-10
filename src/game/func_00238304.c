#include "b08_types.h"

typedef struct TextNode TextNode;
struct TextNode {
    TextNode *next0;
    TextNode *next4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[4];
    s32 unk20;
    u8 *unk24;
};

typedef struct TextSrc {
    u8 pad0[0x29C];
    f32 unk29C;
    f32 unk2A0;
    f32 unk2A4;
    f32 unk2A8;
    u8 pad2AC[0xB94];
    TextNode *listE40;
    TextNode *listE44;
    u8 padE48[0xDC];
    TextNode *freeF24;
} TextSrc;

s32 func_00245788();
void func_00238040(TextSrc *o, TextSrc *b);
void func_002A94E8(void *list);
void func_002A9F18(u8 *str, s32 x, s32 y, s32 a, s32 b, s32 c, f32 sx, f32 sy);
void func_00255E78(void *list, void *n);
void func_00255C58(void *list, void *n);

extern f32 D_800D2988;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern s32 D_800E28D8;

void func_00238304(TextSrc *o, TextSrc *b) {
    TextNode *p;
    TextNode *next;
    f32 rx, ry, rz, rw;
    f32 sc;
    f32 sx;
    f32 sy;
    f32 fy;
    f32 fx;
    f32 nv;
    s32 flag;
    register TextNode **la __asm__("$4");
    s32 ix;
    register s32 one __asm__("$2");

    if (func_00245788() != 0) {
        func_00238040(o, b);
        return;
    }
    rx = b->unk29C;
    ry = b->unk2A0;
    rz = b->unk2A4;
    rw = b->unk2A8;
    sc = 1.0f;
    sy = ry / (f32)D_800E28D4;
    sx = rx / (f32)D_800E28D0;
    flag = 1;
    if (!(sx < sc) && !(sy < sc)) {
        flag = 0;
    }
    fx = rx * 0.5f + rz;
    fy = (ry * 0.8f + rw) - sy * 18.0f;
    p = b->listE44;
    if (p != NULL) {
        ix = (s32)fx;
        do {
            next = p->next0;
            la = &b->listE40;
            if (p->unk14 == 0) {
                goto remove;
            }
            func_002A94E8(la);
            if (flag != 0 || p->unk20 != 0) {
                sc = 0.6f;
                if (D_800E28D8 == 0) {
                    sc = 0.5f;
                }
                sy = 0.8f;
            } else {
                sc = 0.4f;
            }
            one = 1;
            func_002A9F18(p->unk24, ix, (s32)fy, p->unk18, one, one, p->unk10 * sx * sc, p->unk10 * sy * sc);
            switch (p->unk14) {
            case 2:
                p->unk18 += 0x1F;
                if (p->unk18 >= 0xFF) {
                    p->unk18 = 0xFF;
                    p->unk14 = 3;
                    p->unk8 = p->unkC;
                }
                p->unk10 = sinf((f32)p->unk18 * 0.006159986f);
                break;
            case 3:
                nv = p->unk8 - D_800D2988;
                p->unk8 = nv;
                p->unk18 = 0xFF;
                p->unk10 = 1.0f;
                if (nv < 0.0f) {
                    p->unk14 = 4;
                    p->unk18 = 0x80;
                }
                break;
            case 4:
                p->unk10 = p->unk10 - sinf(255.0f - (f32)p->unk18 * 0.012319972f) * 0.33333334f;
                if (p->unk10 < 0.0f) {
                    p->unk10 = 0.0f;
                }
                p->unk18 -= 0xC;
                if (p->unk18 < 0) {
                    p->unk18 = 0;
                    p->unk14 = 0;
                }
                break;
            }
            if (p->unk14 != 0) {
                goto skip;
            }
            la = &b->listE40;
        remove:
            func_00255E78(la, p);
            func_00255C58(&o->freeF24, p);
        skip:
            fy -= sy * 9.0f / sc;
            p = next;
        } while (p != NULL);
    }
}
