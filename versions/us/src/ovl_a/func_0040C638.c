#include "o02_types.h"
typedef struct { s32 w[10]; } O02Blob40;
typedef struct O02Node { struct O02Node *next0; struct O02Node *next; struct O02Node *child; u8 pad[0x12-12]; u16 flags; } O02Node;
s32 func_0040E154(O02Rect *a, O02Rect *b, O02Node *n, s32 *c);
void func_002A2898(s32 *a, s32 *b, s32 *c, s32 *d);
void func_002A2870(s32 a, s32 b, s32 c, s32 d);
void func_0040F508(O02Rect *a, O02Rect *b);
void func_0040E87C(O02Node *n, O02Blob40 b);
void func_0040C638(O02Node *n, O02Blob40 b) {
    O02Rect r30, r40, r50, r60;
    s32 pushed = 0;
    if (func_0040E154(&r30, &r40, n, &b.w[0])) {
        if (n->flags & 0x200) {
            func_002A2898(&r50.w[0], &r50.w[2], &r50.w[1], &r50.w[3]);
            r60 = r50;
            func_0040F508(&r60, &r40);
            func_002A2870(r60.w[0], r60.w[2], r60.w[1], r60.w[3]);
            pushed = 1;
        }
        func_0040E87C(n->child, b);
        if (pushed) {
            func_002A2870(r50.w[0], r50.w[2], r50.w[1], r50.w[3]);
        }
    }
}
