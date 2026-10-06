#include "b23_types.h"

typedef struct Node6BD4 {
    u8 pad0[8];
    u8 sub[0x40];
    s32 unk48;
} Node6BD4;

typedef struct Pool6BD4 {
    u8 pad0[0x94E0];
    u8 lists[0xC8];
    Node6BD4 *unk95A8;
} Pool6BD4;

extern f32 D_800CB038;
extern s32 D_800D2E58;

void func_00271888(void *a, Vec3f *b);
void func_00255E78(void *list, Node6BD4 *n);
void func_00255CB4(void *list, Node6BD4 *n);
void func_002742B4(void *a, void *b);
void func_00273860(void *a, f32 f);
void func_002720EC(Vec3f *v);
void func_0027200C(Vec3f *a, Vec3f *b, f32 s);
void func_00271FA4(Vec3f *a, Vec3f *b, Vec3f *c);
void func_002734B8(void *m, f32 x, f32 y, f32 z);
void func_002734EC(void *m, f32 a, f32 b, f32 c);
void func_002702EC(void *a, void *b);

Node6BD4 *func_002A6BD4(Pool6BD4 *o, Vec3f pos, Vec3f dir, s32 idx, s32 val) {
    u8 m10[0x40];
    u8 m50[0x10];
    Node6BD4 *n;
    u8 *list;
    u8 *l;
    func_00271888(m50, &dir);
    if (D_800D2E58 != 0) {
        return 0;
    }
    {
        D_800D2E58 = 1;
        n = o->unk95A8;
        list = o->lists + idx * 0x14;
        if (n != 0) {
            func_00255E78((u8 *)o + 0x95A8, n);
            goto have;
        }
        n = *(Node6BD4 **)list;
        if (n != 0) {
            func_00255E78(list, n);
have:
            func_00255CB4(list, n);
            if (n != 0) {
                n->unk48 = val;
                func_002742B4(m50, m10);
                func_00273860(m10, 1.5707965f);
                func_002720EC(&dir);
                func_0027200C(&dir, &dir, 2.048f);
                func_00271FA4(&pos, &pos, &dir);
                func_002734B8(m10, pos.x, pos.y, pos.z);
                func_002734EC(m10, D_800CB038, 1.0f, D_800CB038);
                func_002702EC(m10, n->sub);
            }
        }
    }
    return n;
}
