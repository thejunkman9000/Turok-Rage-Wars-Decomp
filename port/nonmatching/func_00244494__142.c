#include "b10_types.h"

extern s32 D_800D0658;
extern s32 D_800D065C;
void func_0023EBC4(B10Cx *c);
void func_0023E828(B10Cx *c);
s32 func_0023D148(B10Cx *c);
void func_0023E44C(B10Cx *c);
s32 func_0023D370(B10Cx *c);
void func_0023E6C0(B10Cx *c, s32 a);
void func_0023E680(B10Cx *c, Vec3f v, f32 r);

inline s32 func_00244B58(B10Obj *o, B10Cx *c, Vec3f p0, Vec3f p1, s32 flags) {
    s32 n;
    s32 cnt;
    s32 r;
    B10Cx *cc = c;
    func_0023EBC4(cc);
    if (p0.x != p1.x || p0.y != p1.y || p0.z != p1.z) {
        {
            s32 v = D_800D0658 + 1;
            D_800D0658 = v;
            D_800D065C = v < D_800D065C ? D_800D065C : v;
        }
        cc->o = o;
        if (o) {
            cc->f4 = o->type == 1 && (o->flags100 & 0x300000) > 0;
        } else {
            cc->f4 = 0;
        }
        cc->p44 = p0;
        cc->p50 = p1;
        cc->f24 = 0;
        cc->f20 = 0;
        cc->f28 = 0;
        cc->f2C = 0;
        cc->f1C = 0;
        cc->f40 = flags;
        cc->fAC = 0;
        cc->f30 = 0;
        cc->f34 = 0;
        func_0023E828(cc);
        cnt = 1;
        n = 0;
        do {
            if (func_0023D148(cc)) {
                func_0023E44C(cc);
                n++;
                r = func_0023D370(cc);
                cc->p44 = cc->p180;
                cc->p50 = cc->p198;
                cc->p74 = cc->p1A4;
                cnt--;
            } else {
                r = 0;
                cc->p44 = cc->p50;
                cnt--;
            }
        } while (r && cnt);
        return n;
    }
    return 0;
}

s32 func_00244494(B10Obj *o, Vec3f p0, Vec3f p1, s32 flags) {
    B10Cx ctx;
    func_0023E6C0(&ctx, 0);
    return func_00244B58(o, &ctx, p0, p1, flags);
}

s32 func_002446D0(B10Obj *o, Vec3f p0, Vec3f p1, s32 flags, s32 arg8) {
    B10Cx ctx;
    func_0023E6C0(&ctx, arg8);
    return func_00244B58(o, &ctx, p0, p1, flags);
}

s32 func_0024490C(B10Obj *o, Vec3f p0, Vec3f p1, s32 flags, Vec3f vi, f32 r) {
    B10Cx ctx;
    func_0023E680(&ctx, vi, r);
    return func_00244B58(o, &ctx, p0, p1, flags);
}
