#include "o02_types.h"
typedef struct O02Quad { u8 pad0[0x12]; u16 flags; u8 pad14[0x2C-0x14]; union { u32 c; u8 a; } col[4]; } O02Quad;
extern s32 D_80153800;
extern s32 D_800E2ABC;
extern s32 D_800E2AB8;
extern O02Ent D_80153820[];
s32 func_0040E154(O02Rect *a, O02Rect *b, O02Quad *n, s32 *c);
void func_002A2898(s32 *a, s32 *b, s32 *c, s32 *d);
void func_002A2870(s32 a, s32 b, s32 c, s32 d);
s32 func_0040F508(O02Rect *a, O02Rect *b);
void func_0040CB30(void);
void func_004171B8(s32 a);
void func_00417574(s32 a);
void func_00418E60(f32 a, f32 b, f32 c, f32 d, f32 e, u32 c0, u32 c1, u32 c2, u32 c3);
#define SCALE(c, a) (((c) & 0xFFFFFF) | (((a) * (s32)((c) >> 24) / 255) << 24))
void func_0040D00C(O02Quad *n, O02Ctx c) {
    O02Rect r28, r38, r48, r58;
    s32 pushed = 0;
    s32 i, found;
    O02Ent *e;
    if (func_0040E154(&r38, &r28, n, &c.w[0])) {
        { s32 t = n->col[0].a | n->col[1].a; t |= n->col[2].a; t |= n->col[3].a; if (t == 0) return; }
        if (n->flags & 0x200) {
            func_002A2898(&r48.w[0], &r48.w[2], &r48.w[1], &r48.w[3]);
            r58 = r48;
            if (!func_0040F508(&r58, &r28)) return;
            func_002A2870(r58.w[0], r58.w[2], r58.w[1], r58.w[3]);
            pushed = 1;
        }
        i = 0;
        if (D_80153800 > 0) {
            found = 1;
            do {
                e = &D_80153820[i];
                if (r38.w[1] < e->b[0]) goto nx;
                if (e->b[1] < r38.w[0]) goto nx;
                if (r38.w[3] < e->b[2]) goto nx;
                if (e->b[3] < r38.w[2]) goto nx;
                goto done;
nx:             i++;
            } while (i < D_80153800);
        }
        found = 0;
done:
        if (found) func_0040CB30();
        if (D_800E2ABC != 0x53533 || D_800E2AB8 == 0) {
            D_800E2ABC = 0x53533;
            func_004171B8(0x53533);
            D_800E2AB8 = 1;
        }
        func_00417574(0);
        func_00418E60((f32)r38.w[0], (f32)r38.w[2], 0, (f32)(r38.w[1] - r38.w[0] + 1), (f32)(r38.w[3] - r38.w[2] + 1),
            SCALE(n->col[0].c, c.col), SCALE(n->col[1].c, c.col), SCALE(n->col[2].c, c.col), SCALE(n->col[3].c, c.col));
        if (pushed) {
            func_002A2870(r48.w[0], r48.w[2], r48.w[1], r48.w[3]);
        }
    }
}
