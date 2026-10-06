#include "b04_types.h"
void func_00271FD8(void *, Vec3f *, Vec3f *);
void func_002720EC(Vec3f *);
typedef struct { u8 pad0[8]; Vec3f pos; u8 pad14[0x58]; f32 unk6C; } B04A;
typedef struct { u8 pad0[0x48]; Vec3f pos; u8 pad54[0xC]; f32 unk60; } B04B;
typedef struct { Vec3f d; Vec3f n; f32 len; Vec3f e; Vec3f e2; f32 elen; f32 dy; } B04Dir;
void func_002165F8(B04A *a, B04B *b, B04Dir *o) {
    func_00271FD8(o, &a->pos, &b->pos);
    o->n = o->d;
    func_002720EC(&o->n);
    o->len = sqrtf(o->d.x * o->d.x + o->d.y * o->d.y + o->d.z * o->d.z);
    o->e.y = 0;
    o->e.x = o->d.x;
    o->e.z = o->d.z;
    o->e2 = o->e;
    func_002720EC(&o->e2);
    o->elen = sqrtf(o->e.x * o->e.x + o->e.y * o->e.y + o->e.z * o->e.z);
    o->dy = a->unk6C - b->unk60;
}
