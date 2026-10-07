#include "o01_types.h"

void *func_0028FD94(void *tree, s32 idx);
s32 func_00285150(void *p, s32 n);
s32 func_0028FE98(void *p);
s32 *func_00254420(s32 a, s32 **src, s32 size);
void func_00253CB0(s32 a, s32 **src, s32 *r);
void func_002610C8(void *blk, s32 n);
void *func_00261110(void *blk, void *src, s32 size);
void func_004002D8(s32 n, void *pts, void *tv, void *out);

void func_0040067C(s32 unused, s32 **src) {
    void *root;
    O01Node *A;
    void *B;
    void *C;
    void *D;
    s32 count;
    s32 size1;
    s32 size2;
    s32 size3;
    s32 size4;
    s32 i;
    s32 *r;
    void *buf;
    void *blk;
    void *seg;
    void *y1;
    void *y2;
    O01Node *n1;
    O01Node *n2;
    O01Node *n3;
    O01Node *s0;
    O01Node *s3;
    void *t1;
    void *t2;
    void *z;
    s32 c0;
    s32 c2;
    s32 ka;
    s32 kb;
    if (func_00285150(src, 1) == 0) {
        return;
    }
    root = (void *)**src;
    A = func_0028FD94(root, 0);
    B = func_0028FD94(root, 1);
    C = func_0028FD94(root, 2);
    D = func_0028FD94(root, 3);
    i = 0;
    count = A->unk0;
    size1 = (count * 4 + 0xF) & ~7;
    for (i = 0; i < A->unk0; i++) {
        n1 = func_0028FD94(A, i);
        n2 = func_0028FD94(n1, 0);
        n3 = func_0028FD94(n1, 2);
        ka = n2->unk4 * 9;
        kb = n3->unk4 * 9;
        size1 += (kb + ka) * 4 + 0x30;
    }
    size4 = func_0028FE98(D);
    size2 = func_0028FE98(B);
    size3 = func_0028FE98(C);
    r = func_00254420(0, src, size1 + size2 + size3 + size4 + 0x18);
    if (r == 0) {
        return;
    }
    buf = (void *)*r;
    func_002610C8(buf, 4);
    blk = func_00261110(buf, 0, size1);
    func_00261110(buf, B, size2);
    func_00261110(buf, C, size3);
    func_00261110(buf, D, size4);
    func_002610C8(blk, count);
    for (i = 0; i < count; i++) {
        n1 = func_0028FD94(A, i);
        n2 = func_0028FD94(n1, 0);
        n3 = func_0028FD94(n1, 2);
        ka = n3->unk4 * 9;
        kb = n2->unk4 * 9;
        seg = func_00261110(blk, 0, (kb + ka) * 4 + 0x30);
        func_002610C8(seg, 3);
        s0 = func_0028FD94(n1, 0);
        t1 = func_0028FD94(n1, 1);
        s3 = func_0028FD94(n1, 2);
        t2 = func_0028FD94(n1, 3);
        z = func_0028FD94(n1, 4);
        c0 = s0->unk4;
        c2 = s3->unk4;
        y1 = func_00261110(seg, 0, c0 * 36 + 8);
        y2 = func_00261110(seg, 0, c2 * 36 + 8);
        func_00261110(seg, z, 8);
        func_004002D8(c0, (u8 *)s0 + 8, (u8 *)t1 + 8, y1);
        func_004002D8(c2, (u8 *)s3 + 8, (u8 *)t2 + 8, y2);
    }
    func_00253CB0(0, src, r);
}
