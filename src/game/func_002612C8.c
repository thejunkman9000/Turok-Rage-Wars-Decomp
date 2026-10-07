#include "b14_types.h"
typedef struct { s32 f0; s32 f4; s32 f8; f32 fC; s32 f10; s32 f14; } B14Hdr;
B14Hdr *func_0028FD94(void *tree, s32 id);
s32 func_0025F0F4(void *a, void *b, s32 c, s32 d, s32 e, s32 f);
extern f32 D_800C9288;
extern f32 D_800C928C;
extern f32 D_800C9290;
extern f32 D_800C9294;
extern f32 D_8010EC70;
extern s32 D_8010EC74;
extern s32 D_8010EC78;
extern f32 D_8010EC7C;
extern f32 D_8010EC80;
s32 func_002612C8(void *a, void *b) {
    s32 r;
    B14Hdr *h = func_0028FD94(a, 0);
    void *a1 = func_0028FD94(a, 1);
    void *a2 = func_0028FD94(a, 2);
    void *b1 = func_0028FD94(b, 1);
    void *b2 = func_0028FD94(b, 2);
    D_8010EC78 = 1;
    D_8010EC74 = 0;
    D_8010EC7C = D_800C9288;
    D_8010EC80 = D_800C928C;
    D_8010EC70 = h->fC;
    if (func_0025F0F4(a1, b1, h->f14, 3, h->f0, h->f8) != 0) {
        D_8010EC78 = 0;
        D_8010EC74 = 1;
        D_8010EC7C = D_800C9290;
        D_8010EC80 = D_800C9294;
        D_8010EC70 = h->fC;
        r = func_0025F0F4(a2, b2, h->f10, 4, h->f0, h->f8) != 0;
    } else {
        r = 0;
    }
    return r;
}
