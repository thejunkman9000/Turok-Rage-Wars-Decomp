


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
    s32 *r;
    O01Node *A;
    void *blk;
    s32 count;
    void *B;
    void *root;
    void *C;
    void *D;
    s32 size1;
    s32 size2;
    s32 size3;
    s32 size4;
    s32 i;
    void *buf;
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
        O01Node *m1 = func_0028FD94(A, i);
        O01Node *m2 = func_0028FD94(m1, 0);
        O01Node *m3 = func_0028FD94(m1, 2);
        s32 ja = m2->unk4 * 9;
        s32 jb = m3->unk4 * 9;
        s32 add = (jb + ja) * 4 + 0x30;
        size1 += add;
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
        register O01Node *m1 __asm__("s1");
        O01Node *m2;
        O01Node *m3;
        s32 ja, jb;
        s32 n0, n2;
        u8 *p0, *p3, *p2;
        register s32 a0v __asm__("a0");
        register u8 *a1v __asm__("a1");
        register void *sg __asm__("s5");
        register O01Node *q0 __asm__("s4");
        register O01Node *q3 __asm__("s3");
        void *u1;
        register void *u2 __asm__("s7");
        register void *zz __asm__("s6");
        register s32 e0 __asm__("s1");
        register s32 e2 __asm__("s2");
        register void *w1 __asm__("s0");
        void *w2;
        m1 = func_0028FD94(A, i);
        m2 = func_0028FD94(m1, 0);
        m3 = func_0028FD94(m1, 2);
        ja = m2->unk4 * 9;
        jb = m3->unk4 * 9;
        sg = func_00261110(blk, 0, (jb + ja) * 4 + 0x30);
        func_002610C8(sg, 3);
        q0 = func_0028FD94(m1, 0);
        u1 = func_0028FD94(m1, 1);
        q3 = func_0028FD94(m1, 2);
        u2 = func_0028FD94(m1, 3);
        zz = func_0028FD94(m1, 4);
        e0 = q0->unk4;
        e2 = q3->unk4;
        n0 = e0 * 36 + 8;
        n2 = e2 * 36 + 8;
        w1 = func_00261110(sg, 0, n0);
        w2 = func_00261110(sg, 0, n2);
        func_00261110(sg, zz, 8);
        a0v = e0;
        p0 = (u8 *)q0 + 8;
        __asm__("" : "+r"(p0));
        func_004002D8(a0v, p0, (u8 *)u1 + 8, w1);
        a0v = e2;
        p3 = (u8 *)q3 + 8;
        __asm__("" : "+r"(p3));
        a1v = p3;
        p2 = (u8 *)u2 + 8;
        __asm__("" : "+r"(p2));
        func_004002D8(a0v, a1v, p2, w2);
    }
    func_00253CB0(0, src, r);
}





