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
    B17Vtx *vp, *vb;
    Vec3f *op;
    f32 k;
    f32 x, y, z;
    s32 j;

    cnt = b->count;
    vb = b->v;
    func_00270980(&m);
    L.x = D_8013B138->x;
    L.y = D_8013B138->y;
    L.z = D_8013B138->z;
    func_002720EC(&L);
    i = 0;
    j = 0;
    if (cnt > 0) {
        do {
            vp = vb + i;
            if (!(vp->flag & 0x80)) {
                if (useMtx != 0) {
                    do { func_00270980(&m, mtxs + (vp->flag >> 8)); } while (0);
                }
                n.x = (s8)vp->col[0];
                n.y = (s8)vp->col[1];
                n.z = (s8)vp->col[2];
                func_00272BA8(&m, &n, &t);
                k = t.x * L.x + t.y * L.y + t.z * L.z;
                k = (k < 0.0f) ? 56.00000381f : (k + 0.2196078598f) * 255.0f;
                x = out[j].x;
                y = out[j].y;
                z = out[j].z;
                out[j].x = x + k;
                out[j].y = y + k;
                out[j].z = z + k;
                j++;
            }
            i++;
        } while (i < cnt);
    }
}