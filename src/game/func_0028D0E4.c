#include "b20_types.h"

typedef struct { f32 div; u8 r; u8 g; u8 b; u8 pad7; } Pal;

void func_00293100(u8 *a, u8 *col, s32 c, s32 d, s32 e, s32 f);
extern Pal D_800D2934[];
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern u8 D_8011FAC0[];

void func_0028D0E4(Level *lv) {
    u8 col[4];
    f32 t;
    Pal *p;
    s32 a = lv->unk1B414;
    if (a != 0) {
      if (a >= 0) {
       if (a < 3) {
        p = &D_800D2934[lv->unk1B410];
        if (p->div != 0.0f) {
            col[0] = p->r;
            col[1] = p->g;
            col[2] = p->b;
            t = lv->unk1B418 * 255.0f / p->div;
            col[3] = (u32)t;
            func_00293100(D_8011FAC0, col, 0, 0, D_800E28D0, D_800E28D4);
        }
       }
      }
    }
}
