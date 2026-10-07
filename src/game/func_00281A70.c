#include "b18_types.h"

typedef struct B18Ent B18Ent;
struct B18Ent {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ u16 type;
    /* 0x006 */ u8 pad6[2];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[0x118];
    /* 0x12C */ B18Ent *unk12C;
    /* 0x130 */ u8 pad130[0x1C];
    /* 0x14C */ s16 unk14C;
    /* 0x14E */ u8 pad14E[0x26];
    /* 0x174 */ s32 unk174;
    /* 0x178 */ u8 pad178[0x46C];
    /* 0x5E4 */ s32 unk5E4;
    /* 0x5E8 */ u8 pad5E8[0x10F8];
    /* 0x16E0 */ B18Ent *next;
};

typedef struct B18Mgr {
    /* 0x000 */ u8 pad0[0xE54];
    /* 0xE54 */ B18Ent *ents[0x40];
    /* 0xF54 */ s32 count;
} B18Mgr;

extern B18Mgr D_8011FE88[];
extern B18Ent *D_80145060;

void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);

void func_00281A70(s32 unused, B18Ent *o, B18Ent **arr, s32 n) {
    Vec3f d;
    s32 i;
    s32 cnt;

    cnt = D_8011FE88->count;
    for (i = 0; i < cnt; i++) {
        B18Ent *e = D_8011FE88->ents[i];
        if (e->unk174 > 0) {
            func_00271FD8(&d, &e->pos, &o->pos);
            if (d.x * d.x + d.y * d.y + d.z * d.z <= 65536.0f) {
                o->unk14C = 1;
                return;
            }
        }
    }
    {
        B18Ent *p;
        for (p = D_80145060; p != NULL; p = p->next) {
            if (o->unk12C != p && p->unk5E4 > 0) {
                func_00271FD8(&d, &p->pos, &o->pos);
                if (d.x * d.x + d.y * d.y + d.z * d.z <= 65536.0f) {
                    o->unk14C = 1;
                    return;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        B18Ent *e = arr[i];
        if (e != o && (e->type == 0xC || e->type == 0x22)) {
            func_00271FD8(&d, &e->pos, &o->pos);
            if (d.x * d.x + d.y * d.y + d.z * d.z <= 262144.0f) {
                o->unk14C = 1;
                return;
            }
        }
    }
}
