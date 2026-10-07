#include "b17_types.h"

extern SessMgr D_8011FE88;
s32 func_0028BBE8(SessMgr *s, Rec14 *r);
s32 func_0028C400(SessMgr *s, s32 id);
void func_0028C490(SessMgr *s, s32 id);
void func_00278F70(Rec14 *r);
s32 func_00279490(Rec14 *r, s32 flag);
void func_0028BAF8(SessMgr *s, Rec14 *r, s32 n);
void func_0028BD28(SessMgr *s, s32 id);
s32 func_0028BD88(SessMgr *s, s32 id);
void func_0028C34C(SessMgr *s, s32 id);
void func_00278EEC(Rec14 *r);

void func_00279274(Rec14 *base, s32 n, u32 m2, u32 m3, u32 m4, u32 m5, s32 g) {
    s32 i, ok, hit;
    Rec14 *r;
    u8 fe;
    u32 v;

    r = base;
    for (i = 0; i < n; r++, i++) {
        ok = 1;
        if (D_8011FE88.mode != 4) {
            ok = func_0028BBE8(&D_8011FE88, r) == 0;
        }
        if (ok) {
            hit = 1;
            fe = r->flagsE;
            if (!(fe & 0x20) && m3 != 0 && (r->w0 & m3)) {
                r->flagsE = fe | 0x40;
                if (r->b0F != 0) {
                    if (func_0028C400(&D_8011FE88, r->b0F)) {
                        func_0028C490(&D_8011FE88, r->b0F);
                    }
                } else {
                    func_00278F70(r);
                }
                hit = 1;
            }
            if (m2 != 0) {
                v = r->w0 & m2;
                hit = v != 0;
            }
            if (m3 != 0) {
                if ((r->w0 & m3) == 0) {
                    hit = 0;
                }
            }
            v = r->w0 & m5;
            if (v != 0) {
                if ((v & m4) == 0) {
                    hit = 0;
                }
            }
            if ((*(u32 *)&r->wC & 0x1100) == 0x1000) {
                hit = 0;
            }
            if (func_00279490(r, g) == 0) {
                hit = 0;
            }
            if (hit != 0) {
                if (r->b0F != 0) {
                    if (!(r->flagsE & 0x80)) {
                        func_0028BAF8(&D_8011FE88, r, 1);
                        r->flagsE |= 0x80;
                        func_0028BD28(&D_8011FE88, r->b0F);
                        if (func_0028BD88(&D_8011FE88, r->b0F)) {
                            func_0028C34C(&D_8011FE88, r->b0F);
                        }
                    }
                } else {
                    func_00278EEC(r);
                }
            }
        }
    }
}
