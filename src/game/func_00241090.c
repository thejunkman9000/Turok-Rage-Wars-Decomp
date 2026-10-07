#include "b09_types.h"

void func_00271FD8(u8 *, u8 *, u8 *);
void func_00272088(u8 *, u8 *, u8 *);
void func_002720EC(u8 *);

static inline void m03_plane(u8 *p) {
    u8 a[0x10];
    u8 b[0x10];
    func_00271FD8(a, p + 0x24, p + 0x18);
    func_00271FD8(b, p + 0x30, p + 0x24);
    func_00272088(p + 0x48, b, a);
    func_002720EC(p + 0x48);
}

void func_00241090(B09Quad *q, B09Box *box) {
    q->kind = 4;
    q->v[3] = box->p[0];
    q->v[2] = box->p[3];
    q->v[1] = box->p[7];
    q->v[0] = box->p[4];
    m03_plane((u8 *)q);
}
