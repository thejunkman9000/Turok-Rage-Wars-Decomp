#include "b17_types.h"

extern LightB *D_8013B138;
void func_00270980();
void func_002720EC(Vec3f *v);
void func_00272BA8(Mat4F *m, Vec3f *in, Vec3f *out);

void func_00277B08(VtxBlk *b, Mat4F *mtxs, Vec3f *out, s32 useMtx) {
    Vec3f L;
    Mat4F m;
    Vec3f n, t;
    s32 i, cnt;
    B17Vtx *vp;
    Vec3f *op;
    f32 k;

    cnt = b->count;
    func_00270980(&m);
    vp = b->v;
    L.x = D_8013B138->x;
    L.y = D_8013B138->y;
    i = 0;
    L.z = D_8013B138->z;
    func_002720EC(&L);
    if (cnt > 0) {
        op = out;
        do {
            if (!(vp->flag & 0x80)) {
                if (useMtx != 0) {
                    func_00270980(&m, mtxs + (vp->flag >> 8));
                }
                n.x = (s8)vp->col[0];
                n.y = (s8)vp->col[1];
                n.z = (s8)vp->col[2];
                func_00272BA8(&m, &n, &t);
                k = t.x * L.x + t.y * L.y + t.z * L.z;
                if (!(k < 0.0f)) {
                    k = (k + 0.2196078598f) * 255.0f;
                } else {
                    k = 56.00000381f;
                }
                op->x = op->x + k;
                op->y = op->y + k;
                op->z = op->z + k;
                op++;
            }
            i++;
            vp++;
        } while (i < cnt);
    }
}
