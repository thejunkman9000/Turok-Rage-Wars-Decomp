#include "o05_types.h"

typedef struct { u8 pad[0x10]; u8 b10; } O05Wb;
extern O05L2 *D_800E59E0;
extern O05R150 D_80146398[];
typedef struct { u16 w[38]; } O05Row;
extern O05Row D_800E5A2E[];
void func_002A33BC(s32 a);
s32 func_00274544(void);
void func_00439D3C(void *o, s32 n, O05Vec3 a, O05Vec3 b);
void func_00439DC0(void *o, O05Vec3 v);
void func_00439E10(void *o, O05Vec3 v);
O05Wb *func_0040ECB0(void *p, s32 id);
void func_0040E9A8(void *w, s32 a);
void func_0043BC3C(s32 k, s32 c);
void func_0025DF54(s32 a);

s32 func_0043A510(void) {
    s32 i;
    s32 base;
    O05Vec3 a;
    O05Vec3 b;
    O05Vec3 c;
    O05Vec3 d;
    func_002A33BC(1);
    base = 0;
    a.z = a.y = a.x = 0.0035000001f;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    d.x = 0;
    d.y = 5.0f;
    d.z = 0;
    b.x = 0;
    b.y = 0;
    b.z = -100.0f;
    for (i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            b.y = 28.0f;
            break;
        case 1:
            b.y = 12.0f;
            break;
        case 2:
            b.y = -3.0f;
            break;
        case 3:
            b.y = -18.0f;
            break;
        }
        c.y = (f32)(base + func_00274544() % 10);
        base += 0x2D;
        func_00439D3C((u8 *)D_800E59E0 + 0x1370 + i * 0xC0, 0, a, b);
        func_00439DC0((u8 *)D_800E59E0 + 0x1370 + i * 0xC0, c);
        func_00439E10((u8 *)D_800E59E0 + 0x1370 + i * 0xC0, d);
    }
    for (i = 0; i < 4; i++) {
        s32 f = D_80146398[i].b0;
        if (f == 1) {
            O05Wb *w = func_0040ECB0(D_800E59E0->f0, D_800E5A2E[i].w[0]);
            func_0040E9A8(w, 0);
            w->b10 = 0x23;
            switch (D_800E59E0->row[i].f4CC) {
            case 0:
                D_800E59E0->row[i].f4AC = 5;
                func_0043BC3C(i, 5);
                break;
            case 1:
                D_800E59E0->row[i].f4AC = 0;
                func_0043BC3C(i, 0);
                break;
            case 2:
                D_800E59E0->row[i].f4AC = 0;
                func_0043BC3C(i, 0);
                break;
            }
        }
    }
    func_0025DF54(0xE78);
    return 0;
}
