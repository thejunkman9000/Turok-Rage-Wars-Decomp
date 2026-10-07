#include "o06_types.h"
typedef struct O06N { u8 pad[4]; struct O06N *unk4; u8 padC[6]; u16 unkE; u8 pad2[0x1C]; s32 unk2C; } O06N;
typedef struct { s32 w0; s32 w4; s32 w8; s32 *wC; } O06T;
typedef struct { u8 pad[0x4B0]; s32 unk4B0; u8 pad2[0x1C]; } O06P;
typedef struct { O06P base; void *unk4D0; s32 unk4D4; } O06Q;
typedef struct { u8 pad[0x38]; s32 unk38; } O06Z;
typedef struct { u16 v; u16 pad; } O06Ent;
typedef struct { O06Ent ent[19]; } O06Row;
typedef struct { u8 pad[8]; O06N *unk8; } O06H;
extern void func_0040E958(void *a, s32 b);
extern O06H *func_0040ECB0();
extern void func_00439E60(void *a, s32 b);
extern O06P *D_800E59E0;
extern O06T D_800E5BC4[];
extern O06T D_800E5B14[];
extern O06T D_800E5B44[];
extern O06Row D_800E5A1A[];
void func_0043B67C(s32 a, s32 b, s32 c) {
    O06P *p;
    O06T *tab;
    O06N *n;
    s32 found;
    p = &D_800E59E0[a];
    if (((O06Q *)p)->unk4D4 == 0) return;
    func_0040E958(((O06Q *)p)->unk4D0, 1);
    p = &D_800E59E0[a];
    if (((O06Q *)p)->unk4D4 == 1) {
        switch (b) {
        case 0: goto c0;
        case 1: goto c1;
        case 2: goto c2;
        default: goto dflt;
        }
    } else {
        switch (b) {
        case 0: case 1: goto c0;
        case 2: case 3: goto c1;
        case 4: goto c2;
        default: goto dflt;
        }
    }
c0: tab = D_800E5BC4; goto have;
c1: tab = D_800E5B44; goto have;
c2: tab = D_800E5B14; goto have;
dflt:
    func_00439E60((u8 *)D_800E59E0 + (a * 0xC0 + 0x1370), 0);
    func_0040E958(((O06Q *)&D_800E59E0[a])->unk4D0, 0);
    return;
have:
    if (tab == 0) return;
    n = func_0040ECB0(*(s32 *)D_800E59E0, D_800E5A1A[a].ent[b].v)->unk8;
    found = 0;
    do {
        if (n->unkE == 3) { n->unk2C = tab[c].w0; found = 1; }
        else n = n->unk4;
    } while (found == 0);
    func_00439E60((u8 *)D_800E59E0 + (a * 0xC0 + 0x1370), tab[c].w4);
    ((O06Z *)((O06Q *)&D_800E59E0[a])->unk4D0)->unk38 = *tab[c].wC;
}
