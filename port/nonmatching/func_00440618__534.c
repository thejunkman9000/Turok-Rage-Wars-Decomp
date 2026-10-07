#include "q04_types.h"
typedef struct { u8 pad[0x14]; s32 x; u8 pad18[4]; s32 y; } Q04B;
typedef struct { u8 pad[0x14]; s32 l; s32 r; } Q04C;
extern void func_0043F69C(Q04Item *it, Q04Info *info);
extern void func_0043FFAC(Q04Item *it, Q04B *b, Q04C *c, s32 d, s32 e, s32 f);
extern void func_0044044C(Q04Item *it, Q04B *b, Q04C *c, s32 d);
static inline void fin(Q04Item *q, Q04B *b, Q04C *c, s32 d) { func_0043FFAC(q, b, c, d, *(s32 *)q->f14, 0); }
void func_00440618(Q04Item *it, Q04B *b, Q04C *c, s32 d) {
    Q04Item cp;
    Q04Info o1, o2, o3;
    s32 mid, t;
    mid = (c->l + c->r) / 2;
    cp = *it;
    cp.w4 = 0;
    func_0043F69C(&cp, &o1);
    cp = *it;
    cp.w4 = 1;
    cp.f14 = 0;
    func_0043F69C(&cp, &o2);
    cp = *it;
    cp.w4 = 1;
    cp.f14 = 0;
    func_0043F69C(&cp, &o3);
    cp = *it;
    cp.f14 = 0;
    b->y = b->y + o1.f8;
    if (it->flags & 1) {
        b->x = mid - ((o2.f4 + o3.f4) / 2);
    }
    b->x = b->x + o3.f4 / 2;
    func_0044044C(&cp, b, c, d);
    cp = *it;
    cp.f14 = 0;
    t = it->f1C * o2.f4;
    b->x = b->x + (t / 256 - o3.f4 / 2);
    b->y = b->y + (o2.f8 / 2 - o3.f8 / 2);
    func_0044044C(&cp, b, c, d);
    cp = *it;
    if (it->flags & 1) {
        b->x = mid - o1.f4 / 2;
    }
    fin(&cp, b, c, d);
}
