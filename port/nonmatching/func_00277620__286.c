#include "r06_types.h"

typedef struct R06Mat { f32 m[4][4]; } R06Mat;

void func_00270980();
void func_00271FA4();
void func_00272908();
void func_00272BA8();
s32 func_00277444(R06Vol *o, R06V3 p, R06V3 nrm, void *m, s32 *a, f32 *b);


void func_00277620(R06Vol **objs, s32 nobj, u8 *blk, u8 *mtxs, R06V3 *out, s32 useMtx) {
    R06Mat m;
    R06V3 acc, pos, nrm, tp, tn;
    s32 hit[3];
    f32 dist;
    s32 *hp;
    f32 *dp;
    s32 cnt;
    s32 i, j, k;
    R06SVtx *vp, *vb;
    f32 d2;
    R06Vol *o;
    u8 type, idx;
    s32 s;
    u32 a, b, c;

    cnt = ((s32 *)blk)[1];
    func_00270980(&m, mtxs, cnt);
    vb = (R06SVtx *)(blk + 8);
    hp = hit;
    dp = &d2;
    for (i = 0; i < cnt; i++) {
        vp = vb + i;
        type = 0;
        dist = 0.0f;
        idx = 0;
        if (!(vp->flag & 0x80)) {
            if (useMtx != 0) {
                func_00270980(&m, mtxs + (vp->flag >> 8) * 64);
            }
            pos.x = (f32)vp->x;
            pos.y = (f32)vp->y;
            pos.z = (f32)vp->z;
            func_00272908(&m, &pos, &tp);
            nrm.x = (f32)vp->nx;
            nrm.y = (f32)vp->ny;
            nrm.z = (f32)vp->nz;
            func_00272BA8(&m, &nrm, &tn);
            acc.x = dist;
            acc.y = dist;
            acc.z = dist;
            for (j = 0; j < nobj; j++) {
                o = objs[j];
                hit[0] = 0;
                hit[1] = 0;
                hit[2] = 0;
                if (tp.x < o->mxx && tp.y < o->mxy && tp.z < o->mxz && o->mnx <= tp.x && o->mny <= tp.y &&
                    o->mnz <= tp.z && func_00277444(o, tp, tn, o->mtx, hp, dp) != 0) {
                    if (o->kind != 0) {
                        type = o->kind;
                        idx = o->idx;
                        dist = d2;
                    }
                    func_00271FA4(&acc, &acc, hp);
                }
            }
            if (type != 0) {
                k = 0;
                if (dist < 0.6000000238418579f) k = 1;
                if (dist < 0.30000001192092896f) k = 2;
                if (type == 1) {
                    vp->flag = (vp->flag & 0xFF8F) | ((((idx % 7) + 1) * 16) & 0x70);
                }
                if (type == 2) {
                    a = (u32)tp.x / 10;
                    b = (u32)tp.y / 10;
                    c = (u32)tp.z / 10;
                    s = (a + b + c) % 7;
                    vp->flag = (vp->flag & 0xFF8F) | (((s + 1) * 16) & 0x70);
                }
                vp->flag = (vp->flag & 0xFFF3) | (k << 2);
                if (dist < 0.10000000149011612f) {
                    vp->flag = vp->flag & 0xFF83;
                }
            }
            out->x = out->x + acc.x;
            out->y = out->y + acc.y;
            out->z = out->z + acc.z;
            out++;
        }
    }
}
