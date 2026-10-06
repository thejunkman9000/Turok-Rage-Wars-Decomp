
#include "b22_types.h"
extern SndMgr *D_8014D080;
extern s32 D_8014D084;
extern s32 D_8014D088;
extern s32 D_8014D08C;
extern s32 D_8014D0A0;
extern s32 D_800D2B50;
extern f64 D_800CA810;
void func_0029864C(s32, s32, s32, void *, s32);
f64 func_002A28CC(void);
void func_002A28F4(void);
void func_002A28FC(void);
void func_0040E6FC(SndCtx *, B22Viewport);
void func_0040E914(void);
void func_0040E154(void *, void *, SndCtx *, B22Viewport *);
void func_00299FE8(void)
{
    B22Viewport vp;
    u8 buf1[16];
    u8 buf2[16];
    s32 now;
    s32 dt;
    s32 i;
    SndMgr *m = D_8014D080;
    vp.x = m->unk534;
    vp.y = m->unk538;
    vp.alpha = 0xFF;
    vp.unk8 = 0;
    vp.sx = 1.0f;
    vp.sy = 1.0f;
    D_8014D084 = 0;
    vp.x2 = m->unk534;
    vp.y2 = m->unk538;
    vp.w = D_8014D088 - 1;
    vp.h = D_8014D08C - 1;
    now = func_002A28CC() * D_800CA810;
    if (D_800D2B50 == 0) {
        D_800D2B50 = now;
    }
    dt = now - D_800D2B50;
    D_800D2B50 = now;
    func_0029864C(0, 0xE0A, 0, &vp, dt);
    for (i = D_8014D080->unk8; i <= D_8014D080->top; i++) {
        func_002A28F4();
        func_0040E6FC(D_8014D080->stk[i].ctx, vp);
        func_0040E914();
        func_002A28FC();
        func_0040E154(buf1, buf2, D_8014D080->stk[i].ctx, &vp);
    }
    func_0029864C(0, 0xE0A, 1, 0, dt);
    D_8014D0A0 = 0;
}

