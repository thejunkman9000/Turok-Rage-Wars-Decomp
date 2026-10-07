#include "r05_types.h"

extern f32 D_800C9380;
extern f32 D_800C9384;
extern f32 D_800C9388;
extern f32 D_800C938C;
extern f32 D_800C9390;
extern f32 D_800C9394;
extern f32 D_800C9398;
extern f32 D_800C939C;
extern f32 D_800C93A0;
extern f32 D_800C93A4;
extern f32 D_800C93A8;
extern f32 D_800C93AC;
extern f32 D_800C93B0;
extern f32 D_800C93B4;
extern f32 D_800C93B8;
extern f32 D_800C93BC;
extern f32 D_800C93C0;
extern f32 D_800C93C4;
extern f32 D_800C93C8;
extern f32 D_800C93CC;
extern f32 D_800C93D0;
extern f32 D_800C93D4;
extern f32 D_800C93D8;
extern f32 D_800D2988;
extern R05PadMap D_800D0DB0[];

f32 func_00274810(f32 a, f32 b, R05PadMap *tab, R05PadCtl *c);

void func_002631D0(R05PadOut *s, R05PadOwn *ow)
{
    R05PadCfg *cfg = ow->cfg;
    f32 dt = D_800C9388 - ow->f7EC * D_800C9380;
    R05PadCtl *c = s->ctl;
    f32 k;
    R05PadMap *tab;
    s32 mask;
    s32 val;
    s32 b;
    f32 cur;
    f32 fa;
    f32 lim;
    f32 sq;
    f32 r;

    k = ((((f32)cfg->b7A * D_800C9384 - D_800C9388) * D_800C9390 + D_800C9388)) * (D_800D2988 * (dt * D_800C938C));
    tab = 0;
    if (cfg->mode < 2) {
        if (cfg->mode >= 0) {
            if (cfg->b7C == 1) {
                tab = D_800D0DB0;
            }
        }
    }
    if (tab != 0) {
        s->bits[0] = 0;
        s->bits[1] = 0;
        s->bits[2] = 0;
        s->bits[3] = 0;
        s->bits[4] = 0;
        if (tab->mask != 0) {
loop:
            mask = tab->mask;
            val = tab->val;
            if (c->btn[0] & mask) {
                s->bits[0] |= val;
            }
            if (c->btn[1] & mask) {
                s->bits[1] |= val;
            }
            if (c->btn[2] & mask) {
                s->bits[2] |= val;
            }
            if (c->btn[3] & mask) {
                s->bits[3] |= val;
            }
            tab++;
            if (c->btn[4] & mask) {
                s->bits[4] |= val;
            }
            if (tab->mask != 0) {
                goto loop;
            }
        }
    } else {
        s->bits[0] = c->btn[0];
        s->bits[1] = c->btn[1];
        s->bits[2] = c->btn[2];
        s->bits[3] = c->btn[3];
        s->bits[4] = c->btn[4];
    }
    switch (cfg->mode) {
    case 0:
        b = s->bits[0];
        if (b & 1) {
            s->f8 = D_800C9394;
        } else if (!(b & 2)) {
            s->f8 = 0.0f;
        } else {
            s->f8 = D_800C9398;
        }
        b = s->bits[0];
        s->f0 = (f32)c->stickX * D_800C939C;
        if (b & 8) {
            s->fC = D_800C93A0;
        } else if (!(b & 4)) {
            s->fC = 0.0f;
        } else {
            s->fC = D_800C93A4;
        }
        if (cfg->b7D != 0) {
            s->f4 = (f32)c->stickY * D_800C93A8;
        } else if (ow->unk11B4 == 0) {
            if (c->stickY != 0) {
                s->f4 = s->f4 + (k * D_800C93AC * (f32)c->stickY);
            }
            cur = s->f4;
            if (D_800C93B0 < cur) {
                s->f4 = D_800C93B0;
            } else if (cur < D_800C93B4) {
                s->f4 = D_800C93B4;
            }
        }
        break;
    case 1:
        b = s->bits[0];
        s->f0 = (f32)c->stickX * D_800C93B8;
        if (b & 1) {
            s->f8 = D_800C93BC;
        } else if (!(b & 2)) {
            s->f8 = 0.0f;
        } else {
            s->f8 = D_800C93C0;
        }
        if (ow->unk11B4 != 0) {
            s->fC = 0.0f;
        } else {
            s->fC = (f32)c->stickY * D_800C93C4;
        }
        b = s->bits[0];
        if (!(b & 0x10)) {
            if (b & 8) {
                cur = s->f4 + (k * D_800C93C8);
                lim = D_800C93CC;
                if (lim < cur) {
                    cur = lim;
                }
                s->f4 = cur;
            } else if (b & 4) {
                cur = s->f4 - (k * D_800C93D0);
                lim = D_800C93D4;
                if (cur < lim) {
                    cur = lim;
                }
                s->f4 = cur;
            } else if (cfg->b7D != 0) {
                fa = s->fC;
                if (fa != 0.0f && ow->unk7E8 == 0) {
                    fa = fa * (dt * D_800C93D8);
                    if (fa < 0.0f) {
                        fa = -fa;
                    }
                    s->f4 = func_00274810(s->f4, fa, tab, c);
                }
            }
        }
        break;
    }
    cur = s->f8;
    sq = cur * cur;
    if (sq < 0.0f) {
        r = cur * -sq;
    } else {
        r = cur * sq;
    }
    cur = s->f0;
    sq = cur * cur;
    s->f1C = r;
    if (sq < 0.0f) {
        s->f14 = cur * -sq;
    } else {
        s->f14 = cur * sq;
    }
    s->f20 = s->fC;
    s->f18 = s->f4;
}
