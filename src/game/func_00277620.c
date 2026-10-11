#include "s802_types.h"

void func_00270980();
void func_00271FA4();
void func_00272908();
void func_00272BA8();
s32 func_00277444(S8Vol *o, S8Vec3 p, S8Vec3 n, void *m, S8Vec3 *hit, f32 *dist);

void func_00277620(S8Vol **objs, s32 nobj, u8 *blk, u8 *mtxs, S8Vec3 *out, s32 useMtx) {
    S8Mat m;
    S8Vec3 acc, pos, nrm, tp, tn;
    s32 hit[3];
    f32 dist;
    f32 d2;
    s32 cnt;
    s32 i, j, k, n;
    S8Vtx *vp;
    S8Vtx *vb;
    S8Vol *o;
    s32 type, idx;
    u32 a;

    vb = (S8Vtx *)(blk + 8);
    cnt = ((s32 *)blk)[1];
    func_00270980(&m, mtxs);
    n = 0;
    for (i = 0; i < cnt; i++) {
        vp = vb + i;
        type = 0;
        idx = 0;
        dist = 0.0f;
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
                if (o->mx.x > tp.x && o->mx.y > tp.y && o->mx.z > tp.z && o->mn.x <= tp.x && o->mn.y <= tp.y &&
                    o->mn.z <= tp.z && func_00277444(o, tp, tn, o->mtx, hit, &d2) != 0) {
                    if (o->kind != 0) {
                        type = o->kind;
                        idx = o->idx;
                        dist = d2;
                    }
                    func_00271FA4(&acc, &acc, hit);
                }
            }
            if (type != 0) {
                k = 0;
                if (dist < 0.6f) k = 1;
                if (dist < 0.3f) k = 2;
                if (type == 1) {
                    vp->flag = (vp->flag & 0xFF8F) | ((((idx % 7) + 1) * 16) & 0x70);
                }
                if (type == 2) {
                    a = 0;
                    a += (u32)tp.x / 10;
                    a += (u32)tp.y / 10;
                    a += (u32)tp.z / 10;
                    a = a % 7 + 1;
                    vp->flag = (vp->flag & 0xFF8F) | ((a * 16) & 0x70);
                }
                vp->flag = (vp->flag & 0xFFF3) | (k << 2);
                if (dist < 0.1f) {
                    vp->flag = vp->flag & 0xFF83;
                }
            }
            out[n].x = out[n].x + acc.x;
            out[n].y = out[n].y + acc.y;
            out[n].z = out[n].z + acc.z;
            n++;
        }
    }
}
