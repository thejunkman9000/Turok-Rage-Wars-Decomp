#include "o02_types.h"
typedef struct { u8 pad[0x12]; u16 flags; } S_func_0040E6FC;
s32 func_0040E154(O02Rect *a, O02Rect *b, S_func_0040E6FC *n, s32 *c);
void func_002A2898(s32 *a, s32 *b, s32 *c, s32 *d);
void func_002A2870(s32 a, s32 b, s32 c, s32 d);
s32 func_0040F508(O02Rect *a, O02Rect *b);
void func_0040DB84(S_func_0040E6FC *n, O02Ctx c);
void func_0040E6FC(S_func_0040E6FC *n, O02Ctx c) {
    O02Rect r30, r40, r50, r60;
    O02Ctx lc;
    s32 pushed = 0;
    if (n->flags & 8) {
        lc = c;
        if (func_0040E154(&r40, &r30, n, &lc.w[0])) {
            if (lc.w[2] & 0x200) {
                func_002A2898(&r50.w[0], &r50.w[2], &r50.w[1], &r50.w[3]);
                r60 = r50;
                if (!func_0040F508(&r60, &r30)) return;
                func_002A2870(r60.w[0], r60.w[2], r60.w[1], r60.w[3]);
                pushed = 1;
            }
            func_0040DB84(n, c);
            if (pushed) {
                func_002A2870(r50.w[0], r50.w[2], r50.w[1], r50.w[3]);
            }
        }
    }
}
