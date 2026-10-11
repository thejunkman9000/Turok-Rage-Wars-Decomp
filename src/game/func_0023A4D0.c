#include "types.h"
#include "n64sdk.h"
#include "gbi.h"

#include "s903_types.h"

extern s32 D_800D297C;
extern Gfx *D_80110634;

s32 func_00296EC4(void *sub, s32 a);
void func_00296F7C(s32 node, SdRes *res);
void func_00295FB4(void *sub, s32 node, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_00268CE0(s32 a);
void func_00271FD8(void *o, SdV3 *a, SdV3 *b);
void func_00272088(void *o, void *a, void *b);
f32 func_00297930(void *m, SdV3 *a, SdV3 *b);
void func_002536F4(s32 a, s32 b);

void func_0023A4D0(SdEmit *e, SdView *v)
{
    SdRes res;
    SdV3 pts[5];
    f32 col0[5];
    f32 col1[5];
    f32 col2[5];
    f32 alp[5];
    SdV3 d[3];
    SdV3 tri[3];
    f32 cc0[4];
    f32 cc1[4];
    f32 cc2[4];
    f32 cc3[4];
    SdV4 ed0;
    SdV4 ed1;
    SdV4 cr;
    u8 cA[8];
    u8 cB[8];
    s32 flag;
    s32 node;
    SdCls *cls;
    s32 sdiv, sshs, ssht, ty;
    f32 tt0, tt1, a0v, lim, ey, den, zero;
    f32 f;
    SdInfo *inf;
    f32 f2;
    f32 f3;
    f32 t;
    f32 range;
    f32 al;
    f32 fs0;
    f32 fs1;
    f32 dd;
    f32 mnx, mxx, mnz, mxz, offx, offz, k;
    SdV3 *p;
    SdV3 *p0;
    SdV3 *q;
    s32 i;
    s32 q4;
    s32 a0, a1, a2;
    SdVtx *vt;
    Gfx *g;

    node = func_00296EC4(e->sub, -1);
    if (node != 0) {
        func_00296F7C(node, &res);
        if (res.cnt != 0) {
            inf = res.info;
            sdiv = inf->div;
            cls = e->cls;
            tt0 = e->unk20C;
            tt1 = e->unk218;
            f = cls->unkC * (tt1 * 768.0f);
            sshs = inf->shs;
            ssht = inf->sht;
            gDPPipeSync(D_80110634++);
            func_00295FB4(e->sub, node, (s32)(tt0 / (f32)sdiv) % res.cnt, 0,
                          (s32)((f32)(1 << sshs) * f), (s32)((f32)(1 << ssht) * f), 0, 0, 0xF);
            fs1 = 5120.0f;
            ty = res.info->type;
            fs0 = 10240.0f;
            if (ty < 0) goto big;
            if (ty >= 2) {
big:
                func_00268CE0(0x20);
                gDPSetEnvColor(D_80110634++, cls->c2[0], cls->c2[1], cls->c2[2], 0xFF);
                cA[0] = cls->c1[0];
                cA[1] = cls->c1[1];
                cA[2] = cls->c1[2];
                cB[0] = cls->c1[0];
                cB[1] = cls->c1[1];
                cB[2] = cls->c1[2];
            } else {
                func_00268CE0(0x21);
                cA[0] = 0xFF;
                cA[1] = 0xFF;
                cA[2] = 0xFF;
                cB[0] = 0xFF;
                cB[1] = 0xFF;
                cB[2] = 0xFF;
            }
            ey = e->unk210;
            f2 = (v->pos[1].y + v->pos[2].y + v->pos[3].y + v->pos[4].y) * 0.25f;
            flag = 1;
            t = v->pos[0].y;
            if (!(t < f2)) {
                flag = 0;
            }
            t = t - ey;
            al = (f32)cls->unk28;
            if (t < 0.0f) {
                t = -t;
            }
            range = cls->unk18;
            i = 0;
            if (t < range) {
                f3 = t - range * 0.25f;
                den = range * 0.75f;
                if (f3 < 0.0f) {
                    al = 0.0f;
                } else {
                    al = (f3 * al) / den;
                }
            }
            al *= e->unk208 * e->unk220;
            i = 0;
            do {
                pts[i].x = v->pos[i].x;
                pts[i].y = ey;
                pts[i].z = v->pos[i].z;
                col0[i] = (f32)(i == 0 ? cA[0] : cB[0]);
                col1[i] = (f32)(i == 0 ? cA[1] : cB[1]);
                col2[i] = (f32)(i == 0 ? cA[2] : cB[2]);
                alp[i] = (i == 0) ? al : 0.0f;
                i++;
            } while (i < 5);
            i = 1;
            p0 = &pts[0];
            zero = 0.0f;
            lim = 1.0f;
            for (; i < 5; i++) {
                p = &pts[i];
                dd = func_00297930(v->mtx, p0, p);
                if (dd >= zero && dd < lim) {
                    p->x = pts[0].x + dd * (p->x - pts[0].x);
                    p->z = pts[0].z + dd * (p->z - pts[0].z);
                }
            }
            q4 = 0;
            do {
                switch (q4) {
                case 0:
                default:
                    a0 = 0;
                    a1 = 1;
                    a2 = 3;
                    break;
                case 1:
                    a0 = 0;
                    a1 = 3;
                    a2 = 4;
                    break;
                case 2:
                    a0 = 0;
                    a1 = 4;
                    a2 = 2;
                    break;
                case 3:
                    a0 = 0;
                    a1 = 2;
                    a2 = 1;
                    break;
                }
                __asm__("" : "+r"(a0));
                d[0] = *(SdV3 *)((u8 *)pts + (a0 & ~0xB));
                d[1] = pts[a1];
                d[2] = pts[a2];
                func_00271FD8(&ed0, &d[1], &d[0]);
                func_00271FD8(&ed1, &d[2], &d[1]);
                func_00272088(&cr, &ed0, &ed1);
                if (cr.y <= 0.0f) {
                    if (flag == 1) {
                        ;
                    } else {
                        goto draw;
                    }
                } else {
                    if (flag != 0) {
draw:
                        i = 0;
                        cc0[0] = col0[a0];
                        cc0[1] = col0[a1];
                        cc0[2] = col0[a2];
                        cc1[0] = col1[a0];
                        cc1[1] = col1[a1];
                        cc1[2] = col1[a2];
                        cc2[0] = col2[a0];
                        cc2[1] = col2[a1];
                        cc2[2] = col2[a2];
                        cc3[0] = alp[a0];
                        cc3[1] = alp[a1];
                        cc3[2] = alp[a2];
                        tri[0] = *(SdV3 *)((u8 *)pts + (a0 & ~0xB));
                        tri[1] = pts[a1];
                        tri[2] = pts[a2];
                        do {
                            tri[i].x -= d[0].x * 0.5f;
                            tri[i].z = tri[i].z - d[0].z * 0.5f;
                            tri[i].x += e->unk1C;
                            tri[i].z = tri[i].z + e->unk20;
                            i++;
                        } while (i < 3);
                        mnx = tri[2].x;
                        if (!(tri[1].x <= mnx)) mnx = tri[1].x;
                        if (!(tri[0].x <= mnx)) mnx = tri[0].x;
                        mxx = tri[2].x;
                        if (!(mxx <= tri[1].x)) mxx = tri[1].x;
                        if (!(mxx <= tri[0].x)) mxx = tri[0].x;
                        mnz = tri[2].z;
                        if (!(tri[1].z <= mnz)) mnz = tri[1].z;
                        if (!(tri[0].z <= mnz)) mnz = tri[0].z;
                        mxz = tri[2].z;
                        if (!(mxz <= tri[1].z)) mxz = tri[1].z;
                        if (!(mxz <= tri[0].z)) mxz = tri[0].z;
                        if (fs0 <= mnx) {
                            offx = (f32)(s32)(mnx / fs0) * -fs0;
                        } else if (mxx <= -fs0) {
                            offx = (f32)(s32)(mxx / fs0) * fs0;
                        } else {
                            offx = 0.0f;
                        }
                        if (fs0 <= mnz) {
                            offz = (f32)(s32)(mnz / fs0) * -fs0;
                        } else if (mxz <= -fs0) {
                            offz = (f32)(s32)(mxz / fs0) * fs0;
                        } else {
                            offz = 0.0f;
                        }
                        i = 0;
                        do {
                            vt = (SdVtx *)((u8 *)e + (D_800D297C * 0xF0 + 0x28) + q4 * 0x30) + i;
                            vt->flag = 0;
                            vt->x = (s16)(s32)d[i].x;
                            vt->y = (s16)(s32)d[i].y;
                            vt->z = (s16)(s32)d[i].z;
                            k = 16384.0f / fs1;
                            vt->u = (s16)(s32)((tri[i].x + offx) * k);
                            vt->v = (s16)(s32)((tri[i].z + offz) * k);
                            vt->col[0] = (u32)cc0[i];
                            vt->col[1] = (u32)cc1[i];
                            vt->col[2] = (u32)cc2[i];
                            vt->col[3] = (u32)cc3[i];
                            i++;
                        } while (i < 3);
                        gSPVertex(D_80110634++, (u32)((u8 *)e + (D_800D297C * 0xF0 + 0x28) + q4 * 0x30), 3, 0);
                        gSP1Triangle(D_80110634++, 0, 1, 2, 0);
                    }
                }
                q4++;
            } while (q4 < 4);
        }
        func_002536F4(0, node);
    }
}
