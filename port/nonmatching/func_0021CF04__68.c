#include "m02_gen.h"
typedef struct M2Cls1C { u8 pad[0x1C]; f32 unk1C; } M2Cls1C;
extern M2Cls1C *D_800D052C[];
extern f32 D_80115DEC;
extern u8 D_801462E5[];
extern s32 D_80120CD8;
extern M2Tgt *D_80120AD8[];
f32 sinf(f32);
f32 cosf(f32);
f32 func_002BC380(f32);
s32 func_0021CD70(M2Tgt *p, M2Tgt *t);
f32 func_0022ADAC(M2Tgt *p);
void func_0024795C(M2Quat *q, M2Tgt *p);
void func_0024BC84(Vec3f *out, M2Tgt *p, Vec3f v);
f32 func_0024D274(M2Tgt *t);
void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
void func_00272088(Vec3f *out, Vec3f *a, Vec3f *b);
void func_002720EC(Vec3f *v);
void func_00274108(M2Quat *dst, M2Quat *a, M2Quat *b);
f32 func_00274640(f32 x);
M2Quat func_0021CF04(M2Tgt *p, M2Tgt **out, Vec3f *aim) {
    Vec3f sp18;
    Vec3f sp28;
    Vec3f sp38;
    Vec3f sp48;
    Vec3f sp58;
    Vec3f sp68;
    Vec3f sp78;
    Vec3f sp88;
    M2Quat sp98;
    M2Quat spA8;
    M2Quat spB8;
    f32 fs0;
    f32 fs1;
    f32 d;
    f32 e;
    M2Tgt *best;
    M2Tgt *t;
    s32 i;
    s32 n;
    u8 *g;
    sp48.x = 0.0f;
    sp48.y = 0.0f;
    sp48.z = 0;
    sp78.x = 0;
    sp78.y = 0;
    sp78.z = 0;
    spB8.x = spB8.y = spB8.z = sp48.x;
    spB8.w = 1.0f;
    best = 0;
    if (p->unk62E != -1) {
        fs1 = D_800D052C[p->unk62E]->unk1C;
    } else {
        fs1 = sp48.x;
    }
    fs0 = cosf(fs1 * 0.5f);
    if (fs1 != 0.0f) {
        sp68.x = 0.0f;
        sp68.y = 0.0f;
        sp68.z = 1.0f;
        func_0024BC84(&sp58, p, sp68);
        sp38 = p->pos;
        sp38.y += func_0022ADAC(p);
        g = D_801462E5;
        if (g[0] != 0) {
            t = *(M2Tgt **)(g - 0x1285);
            if (t != 0) {
                do {
                    if (func_0021CD70(p, t) != 0 && t != p) {
                        if (p->unk62E == 0x12) {
                            sp18 = t->v248;
                        } else {
                            sp18 = t->pos;
                            sp18.y += t->unk70;
                            sp18.y += func_0024D274(t) * 0.75f;
                        }
                        func_00271FD8(&sp28, &sp18, &sp38);
                        func_002720EC(&sp28);
                        d = sp58.x * sp28.x + sp58.y * sp28.y + sp58.z * sp28.z;
                        if (fs0 < d) {
                            fs0 = d;
                            sp48 = sp18;
                            best = t;
                        }
                    }
                    t = t->next;
                } while (t != 0);
            }
        }
        n = D_80120CD8;
        i = 0;
        if (n > 0) {
            do {
                t = D_80120AD8[i];
                if (func_0021CD70(p, t) != 0) {
                    if (p->unk62E == 0x12) {
                        sp18 = t->v248;
                    } else {
                        sp18 = t->pos;
                        sp18.y += t->unk70;
                        sp18.y += func_0024D274(t) * 0.75f;
                    }
                    func_00271FD8(&sp28, &sp18, &sp38);
                    func_002720EC(&sp28);
                    d = sp58.x * sp28.x + sp58.y * sp28.y + sp58.z * sp28.z;
                    i++;
                    if (fs0 < d) {
                        fs0 = d;
                        best = t;
                        sp48 = sp18;
                        sp78 = sp28;
                    }
                } else {
                    i++;
                }
            } while (i < n);
        }
    }
    *out = best;
    *aim = sp48;
    if (best != 0) {
        func_00272088(&sp88, &sp58, &sp78);
        func_002720EC(&sp88);
        e = func_00274640(fs0);
        fs0 = e * func_002BC380(func_002BC380(1.0f - e / (fs1 * 0.75f))) * 0.75f;
        D_80115DEC = sinf(fs0);
        sp98.x = sp88.x * D_80115DEC;
        sp98.y = sp88.y * D_80115DEC;
        sp98.z = sp88.z * D_80115DEC;
        sp98.w = cosf(fs0);
        func_0024795C(&spA8, p);
        func_00274108(&spB8, &spA8, &sp98);
    }
    return spB8;
}
