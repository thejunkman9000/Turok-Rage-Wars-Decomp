#include "o02_types.h"
typedef struct O02Node { struct O02Node *next0; struct O02Node *next; struct O02Node *child; u8 pad[0x12-12]; u16 flags; u8 pad2[0x2C-0x14]; s32 f2C; } O02Node;
extern s32 D_80153800;
extern s32 D_800E2ABC;
extern s32 D_800E2AB8;
extern O02Ent D_80153820[];
s32 func_0040E154(O02Rect *a, O02Rect *b, O02Node *n, s32 *c);
void func_002A2898(s32 *a, s32 *b, s32 *c, s32 *d);
void func_002A2870(s32 a, s32 b, s32 c, s32 d);
s32 func_0040F508(O02Rect *a, O02Rect *b);
void func_0040CB30(void);
s32 func_004106F4(s32 a, s32 b);
void func_004171B8(s32 a);
void func_00417574(s32 a);
void func_00418E20(f32 a, f32 b, f32 c, f32 d, f32 e, s32 f);
void func_0040CDD0(O02Node *n, O02Ctx c) {
    O02Rect r18, r28, r38, r48;
    s32 pushed = 0;
    s32 i, found, h, col;
    O02Ent *e;
    if (func_0040E154(&r28, &r18, n, &c.w[0])) {
        if (n->flags & 0x200) {
            func_002A2898(&r38.w[0], &r38.w[2], &r38.w[1], &r38.w[3]);
            r48 = r38;
            if (!func_0040F508(&r48, &r18)) return;
            func_002A2870(r48.w[0], r48.w[2], r48.w[1], r48.w[3]);
            pushed = 1;
        }
        i = 0;
        if (D_80153800 > 0) {
            found = 1;
            do {
                e = &D_80153820[i];
                if (r28.w[1] < e->b[0]) goto nx;
                if (e->b[1] < r28.w[0]) goto nx;
                if (r28.w[3] < e->b[2]) goto nx;
                if (e->b[3] < r28.w[2]) goto nx;
                goto done;
nx:             i++;
            } while (i < D_80153800);
        }
        found = 0;
done:
        if (found) func_0040CB30();
        h = func_004106F4(n->f2C, 1);
        col = (c.col << 24) | 0xFFFFFF;
        if (D_800E2ABC != 0x53333 || D_800E2AB8 == 0) {
            D_800E2ABC = 0x53333;
            func_004171B8(0x53333);
            D_800E2AB8 = 1;
        }
        func_00417574(h);
        func_00418E20((f32)r28.w[0], (f32)r28.w[2], 0, (f32)(r28.w[1] - r28.w[0] + 1), (f32)(r28.w[3] - r28.w[2] + 1), col);
        if (pushed) {
            func_002A2870(r38.w[0], r38.w[2], r38.w[1], r38.w[3]);
        }
    }
}
