#include "b20_types.h"

typedef struct {
    u8 pad0[4];
    s16 unk4;
    u8 pad6[2];
    Vec3f pos;
    s32 unk14;
    ActorDef *def;
    Vec3f vel;
    u8 pad28[0x50 - 0x28];
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 pad60[0x168 - 0x60];
    s32 unk168;
    f32 unk16C;
    s32 unk170;
    s32 unk174;
    s32 unk178;
    f32 box[6];
    s32 unk194;
    u8 pad198[4];
    s16 unk19C;
    u8 pad19E[0x1A8 - 0x19E];
    u8 unk1A8[0x1C4 - 0x1A8];
    s32 unk1C4;
    f32 unk1C8;
    s32 unk1CC;
    u32 flags1D0;
    s32 *counter1D4;
    Node *prev1D8;
    Node *next1DC;
} Spawn;

s32 func_0028B1F8(u8 *lv, s32 id);
void func_00290930(NodeOwner *o, Node *n);
void func_00246174(Spawn *s);
s32 func_0028C174(u8 *lv, s32 idx);
f32 func_0024D274(Spawn *s);
void func_0028C6B0(u8 *lv, Vec3f *a, u8 *out);
extern s32 D_800D29B4;
extern u8 D_8011FE88[];
extern u8 D_801462E5;
extern u8 D_8011F2C0[];
extern u8 D_8011F448[];

Spawn *func_0028FFB0(NodeOwner *o, s32 *counter, s32 id, Vec3f vel, Vec3f pos, s32 val, f32 f) {
    s32 idx;
    s32 r;
    Spawn *n;
    Vec3f tmp;
    if (D_800D29B4 == 0) {
        return 0;
    }
    idx = func_0028B1F8(D_8011FE88, id);
    if (idx == -1) {
        return 0;
    }
    if (o->freeList == 0) {
        func_00290930(o, o->tail);
    }
    n = (Spawn *)o->freeList;
    o->freeList = n->next1DC;
    if (o->head != 0) {
        o->head->prev = (Node *)n;
    }
    n->next1DC = o->head;
    n->prev1D8 = 0;
    o->head = (Node *)n;
    if (o->tail == 0) {
        o->tail = (Node *)n;
    }
    n->flags1D0 |= 1;
    func_00246174(n);
    n->unk1C8 = 0;
    r = func_0028C174(D_8011FE88, idx);
    n->counter1D4 = counter;
    if (counter != 0) {
        *counter = *counter + 1;
    }
    if (D_801462E5 != 0) {
        n->def = (ActorDef *)D_8011F2C0;
    } else {
        n->def = (ActorDef *)D_8011F448;
    }
    n->unk1C8 = f;
    n->unk1CC = 0;
    n->unk4 = idx;
    pos.y = pos.y + 10.24f;
    n->pos = pos;
    n->unk174 = 0;
    n->unk178 = 0;
    n->unk168 = 0;
    n->unk16C = 1.0f;
    n->unk170 = 0;
    n->box[0] = pos.x - 81.92f;
    n->box[1] = pos.y - 81.92f;
    n->box[2] = pos.z - 81.92f;
    n->box[3] = pos.x + 81.92f;
    n->box[4] = pos.y + 81.92f;
    n->box[5] = pos.z + 81.92f;
    n->unk50 = r;
    n->unk54 = -1;
    n->unk58 = 0;
    n->unk5C = 0;
    n->unk14 = val;
    n->unk194 = 0;
    n->unk19C = 0x1A;
    n->vel = vel;
    n->unk1C4 = 0;
    tmp.x = n->pos.x;
    tmp.y = n->pos.y + func_0024D274(n) * 0.5f;
    tmp.z = n->pos.z;
    func_0028C6B0(D_8011FE88, &tmp, n->unk1A8);
    return n;
}
