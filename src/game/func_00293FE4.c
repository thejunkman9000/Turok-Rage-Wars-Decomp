#include "b21_types.h"

typedef struct B21Hdr {
    u8 pad0[0x110];
    s32 unk110;
} B21Hdr;

extern DlCmd *D_80110634;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern B21Hdr *D_8011FE80;
void func_002AB940(s32 id, s32 a, s32 *w, s32 *h);
void func_002AA224(s32 a);
void func_002ABC18(s32 id, s32 a, s32 b, s32 c, f32 sx, f32 sy, s32 d);

void func_00293FE4(void) {
    s32 w;
    s32 h;
    DlCmd *dl;
    w = 0;
    h = 0;
    dl = D_80110634++;
    dl->w0 = 0xFF100000 | ((D_800E28D0 - 1) & 0xFFF);
    dl->w1 = D_8011FE80->unk110;
    func_002AB940(0x388, 0, &w, &h);
    if (w != 0 && h != 0) {
        func_002AA224(250);
        func_002ABC18(0x388, 0, 0, 0, (f32)D_800E28D0 / (f32)w, (f32)D_800E28D4 / (f32)h, 1);
    }
}
