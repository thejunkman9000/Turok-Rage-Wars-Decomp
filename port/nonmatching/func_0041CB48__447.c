#include "o03_types.h"
/* the span of func_0041CB48 also holds three tiny methods (func_0041CE20/4C/78, separate files) after the 182-insn function body */
extern s32 D_800D297C;
extern s32 D_800D2B40;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern u8 D_8011FE88[];
extern u8 D_801450C8[];
void *memset(void *p, s32 v, u32 n);
void *func_0028CF7C();
void func_00246690(void *o, s32 a, s32 b, s32 c, void *d, s32 e, s32 f, f32 g, O3Vec3 v1, s32 h, O3Vec3 v2, O3Vec3 v3, s32 i);
void func_0024B2C0(void *o);
void func_00272908(void *a, O3Vec3 *b, O3Vec3 *c);
void func_0041CE88(void *a, s32 b, s32 c, s32 d);
void *func_0041CB48(O3Act *a, s32 id, s32 p, s32 q, s32 r, O3Vec3 va, O3Vec3 vb, f32 f, s32 e) {
    O3Vec3 sp50;
    O3Vec3 sp60;
    O3Vec3 sp70;
    O3Vec3 sp80;
    O3Body *b;
    O3Blk98 *src;
    f32 sc;
    u8 *base;
    memset(&sp60, 0, 0xC);
    O3_PUSH(0xDA380007, (u32)((D_800D297C << 6) + 0x380 + (s32)(base = D_801450C8)));
    a->f4A0 = e;
    b = (O3Body *)((u8 *)a + 0x190);
    a->f49C = 1;
    src = func_0028CF7C(D_8011FE88, id, p);
    if (src == 0) {
        a->f478 = 0;
        return 0;
    }
    *(s32 *)a = id;
    a->f478 = 1;
    a->f498 = f;
    *(O3Blk98 *)((u8 *)a + 4) = *src;
    a->v480 = va;
    a->v48C = vb;
    *(s32 *)((u8 *)a + 4) = 0;
    *(s32 *)((u8 *)a + 8) = 0;
    *(s32 *)((u8 *)a + 0x18) = 0;
    *(s32 *)((u8 *)a + 0x1C) = 0;
    *(s32 *)((u8 *)a + 0x20) = 0;
    *(f32 *)((u8 *)a + 0xC) = 10240.0f;
    sc = *(f32 *)(base + 0x29C) / (f32)D_800E28D0;
    sp50.x = a->v480.x * sc;
    sp50.z = a->v480.z * sc;
    sp50.y = a->v480.y * (*(f32 *)(base + 0x2A0) / (f32)D_800E28D4);
    *(O3Vec3 *)((u8 *)b + 0x50) = sp50;
    sp70 = a->v48C;
    func_00272908(base + 0x160, &sp70, &sp80);
    func_00246690(b, -1, q, D_800D2B40, (u8 *)a + 4, -1, 0, a->f498 * 0.017453294f, sp80, 0, a->v480, sp60, 0);
    func_0024B2C0(b);
    if (*(s32 *)a == 9) {
        func_0041CE88(a, q, r, p);
    }
    return (u8 *)a + 4;
}
