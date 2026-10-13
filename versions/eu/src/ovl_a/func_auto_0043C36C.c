#include "o06_types.h"
typedef struct O06N { u8 pad[4]; struct O06N *unk4; u8 padC[6]; u16 unkE; u8 pad2[0x1C]; s32 unk2C; } O06N;
typedef struct { s32 w0; s32 w4; s32 w8; s32 *wC; } O06T;
typedef struct { u8 pad[0x38]; s32 unk38; } O06Z;
typedef struct { u16 v; u16 pad; } O06Ent;
typedef struct { O06Ent ent[19]; } O06Row;
typedef struct { u8 pad[8]; O06N *unk8; } O06H;
typedef struct { u8 pad0[0x4C8]; O06Z *obj; s32 mode; } O06E;
typedef struct { void *window; s32 pad4; O06E entries[4]; } O06S;
extern void func_0040E958(void *a, s32 b);
extern O06H *func_0040ECB0();
extern void func_00439E60(void *a, s32 b);
extern u8 D_auto_80152789;
extern O06S *D_800E59E0;
extern O06T D_800E5BC4[];
extern O06T D_800E5B14[];
extern O06T D_800E5B44[];
extern O06Row D_800E5A1A[];

void func_auto_0043C36C(s32 a, s32 b, s32 c)
{
  O06T *tab;
  O06N *n;
  s32 found;
  if (D_800E59E0->entries[a].mode == 0) return;
  func_0040E958(D_800E59E0->entries[a].obj, 1);
  if (D_800E59E0->entries[a].mode == 1) {
    switch (b) {
    case 0: tab = D_800E5BC4; break;
    case 1: tab = D_800E5B44; break;
    case 2: tab = D_800E5B14; break;
    default: { func_00439E60(((u8 *) D_800E59E0) + ((a * 0xC0) + 0x1370), 0); func_0040E958(D_800E59E0->entries[a].obj, 0); return; }
    }
  } else {
    switch (b) {
    case 0: case 1: tab = D_800E5BC4; break;
    case 2: case 3: tab = D_800E5B44; break;
    case 4: tab = D_800E5B14; break;
    case 5: default: { func_00439E60(((u8 *) D_800E59E0) + ((a * 0xC0) + 0x1370), 0); func_0040E958(D_800E59E0->entries[a].obj, 0); return; }
    }
  }
  if (tab == 0) return;
  n = func_0040ECB0(*((s32 *) D_800E59E0), D_800E5A1A[a].ent[b].v)->unk8;
  found = 0;
  do {
    if (n->unkE == 3) { n->unk2C = tab[c].w0; found = 1; }
    else n = n->unk4;
  } while (found == 0);
  func_00439E60(((u8 *) D_800E59E0) + ((a * 0xC0) + 0x1370), tab[c].w4);
  D_800E59E0->entries[a].obj->unk38 = tab[c].wC[D_auto_80152789];
}
