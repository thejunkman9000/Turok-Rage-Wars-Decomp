#include "o02_types.h"
void func_0040C9D0(O02Slider *s);
s32 func_0029A958(void);
void func_0029A5D4(s32 a, s32 b, s32 c, s32 d, s32 e);
void func_0029A73C(void);
typedef struct { u8 pad[0xC]; s16 id; } O02Widget;
s32 func_0040C77C(O02Widget *w, s32 cmd, s32 a2, s32 a3) {
    O02Slider *s = (O02Slider *)w;
    if (s->val < s->min) s->val = s->min;
    if (s->val > s->max) s->val = s->max;
    switch (cmd) {
    case 5:
    case 8:
        if (a3) {
            s->val += s->step;
            if (s->max < s->val) s->val = s->max;
        }
        break;
    case 6:
    case 7:
        if (a3) {
            s->val -= s->step;
            if (s->val < s->min) s->val = s->min;
        }
        break;
    case 0x1000: return s->val;
    case 0x1002: return s->min;
    case 0x1003: return s->max;
    case 0x1006: return s->step;
    case 0x1008: return s->unk6C;
    case 0x1005:
        if (a2 >= s->min && a2 <= s->max) s->val = a2;
        break;
    case 0x1004:
        if (s->min < a2) s->max = a2;
        if (a3 < s->max) s->min = a3;
        break;
    case 0x1007:
        if (a2 < s->max - s->min) s->step = a2;
        break;
    case 0x1009:
        s->unk6C = a2;
        break;
    default:
        return 0;
    }
    func_0040C9D0(s);
    func_0029A5D4(func_0029A958(), 0x100A, w->id, s->val, 0);
    func_0029A73C();
    return 0;
}
