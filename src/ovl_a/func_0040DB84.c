#include "o02_types.h"
typedef struct O02Node { struct O02Node *next0; struct O02Node *next; struct O02Node *child; u8 pad[0xE - 12]; u16 type; u8 pad10[2]; u16 flags; u8 pad14[0x2C-0x14]; struct { u8 pad[0x14]; s16 x; s16 y; } *f2C, *f30, *f34; } O02Node;
typedef struct { s32 w0, w1, w2; f32 f3, f4; s32 w5, w6, w7, w8, w9; } S_ctx2;
extern s32 D_800E2AB8;
s32 func_0040E154(O02Rect *a, O02Rect *b, O02Node *n, s32 *c);
void func_002A2898(s32 *a, s32 *b, s32 *c, s32 *d);
void func_002A2870(s32 a, s32 b, s32 c, s32 d);
s32 func_0040F508(O02Rect *a, O02Rect *b);
void func_0040E87C(O02Node *n, O02Ctx c);
void func_0040CDD0(O02Node *n, O02Ctx c);
void func_0040D350(O02Node *n, O02Ctx c);
void func_0040D00C(O02Node *n, O02Ctx c);
s32 func_0029A838(s32 t);
void func_002A28FC(void);
void func_002A28F4(void);
s32 func_0029AA80(O02Node *n, O02Ctx c);
void func_0040DB84(O02Node *n, O02Ctx c);

static inline void body_c638(O02Node *n, O02Ctx c) {
    O02Rect r40, r30, r50, r60;
    s32 pushed = 0;
    if (func_0040E154(&r30, &r40, n, &c.w[0])) {
        if (n->flags & 0x200) {
            func_002A2898(&r50.w[0], &r50.w[2], &r50.w[1], &r50.w[3]);
            r60 = r50;
            if (!func_0040F508(&r60, &r40)) return;
            func_002A2870(r60.w[0], r60.w[2], r60.w[1], r60.w[3]);
            pushed = 1;
        }
        func_0040E87C(n->child, c);
        if (pushed) {
            func_002A2870(r50.w[0], r50.w[2], r50.w[1], r50.w[3]);
        }
    }
}
static inline void body_f3d0(O02Node *n, O02Ctx c) {
    O02Rect r30, r40, r50, r60;
    s32 pushed = 0;
    D_800E2AB8 = 0;
    if (func_0040E154(&r60, &r30, n, &c.w[0])) {
        if (n->flags & 0x200) {
            func_002A2898(&r40.w[0], &r40.w[2], &r40.w[1], &r40.w[3]);
            r50 = r40;
            if (!func_0040F508(&r50, &r30)) return;
            func_002A2870(r50.w[0], r50.w[2], r50.w[1], r50.w[3]);
            pushed = 1;
        }
        func_0040E87C(n->child, c);
        if (pushed) {
            func_002A2870(r40.w[0], r40.w[2], r40.w[1], r40.w[3]);
        }
    }
}
static inline void body_f2b0(O02Node *n, S_ctx2 c) {
    O02Rect r30, r40;
    void *s;
    if (func_0040E154(&r30, &r40, n, &c.w0)) {
        if (c.w2 & 0x100) {
            s = n->f34;
        } else if (c.w2 & 0x40) {
            s = n->f30;
        } else {
            s = n->f2C;
        }
        if (s) {
            c.w0 -= (s32)(((struct { u8 pad[0x14]; s16 x; s16 y; } *)s)->x * c.f3);
            c.w1 -= (s32)(((struct { u8 pad[0x14]; s16 x; s16 y; } *)s)->y * c.f4);
            func_0040DB84(s, *(O02Ctx *)&c);
        }
    }
}
void func_0040DB84(O02Node *n, O02Ctx c) {
    s32 f;
    switch (n->type) {
    case 3:
        func_0040CDD0(n, c);
        break;
    case 4:
        func_0040D350(n, c);
        break;
    case 6:
        func_0040D00C(n, c);
        break;
    case 8:
        body_f2b0(n, *(S_ctx2 *)&c);
        break;
    case 2:
        body_f3d0(n, c);
        break;
    case 1:
        body_c638(n, c);
        break;
    default:
        f = func_0029A838(n->type) & 1;
        if (!f) {
            func_002A28FC();
            D_800E2AB8 = 0;
        }
        if (func_0029AA80(n, c)) {
            if (!f) {
                func_002A28F4();
                D_800E2AB8 = 0;
            }
        }
        break;
    }
}
