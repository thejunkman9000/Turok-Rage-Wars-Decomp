#include "p1_types.h"

typedef struct { u32 pad0; u32 flags; } Def;
typedef struct {
    u8 pad0[8];
    Vec3f pos;
    u32 pad14;
    Def *def;
    f32 vx;
    f32 vy;
    f32 vz;
    u8 pad28[0x17C - 0x28];
    f32 box[6];
    u8 pad194[0x1CC - 0x194];
    f32 unk1CC;
} Obj;

void func_0024F490(Obj *o);
void func_00243A80(Obj *o, f32 x, f32 y, f32 z, u8 *t);
extern u8 D_80104438[];
extern u8 D_801043F8[];
extern u8 D_8011F448[];
extern f32 D_800D2988;

void func_00290404(Obj *o) {
    u8 *t;
    Vec3f saved;
    t = D_80104438;
    if (!(o->def->flags & 4)) {
        t = D_801043F8;
    }
    if (0.0f < o->unk1CC) {
        o->unk1CC = o->unk1CC - D_800D2988;
        saved = o->pos;
    }
    func_0024F490(o);
    if ((u8 *)o->def != D_8011F448) {
        o->vx = 0.0f;
        o->vy = 0.0f;
        o->vz = 0.0f;
    }
    func_00243A80(o, o->pos.x, o->pos.y, o->pos.z, t);
    o->box[0] = o->pos.x - 81.92f;
    o->box[1] = o->pos.y - 81.92f;
    o->box[2] = o->pos.z - 81.92f;
    o->box[3] = o->pos.x + 81.92f;
    o->box[4] = o->pos.y + 81.92f;
    o->box[5] = o->pos.z + 81.92f;
}
