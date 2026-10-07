#include "o06_types.h"
typedef struct { u8 pad[0x5D8]; u8 *unk5D8; } O06Q;
typedef struct O06P { u8 pad[0x12EC]; struct O06P *unk12EC; s32 unk12F0; } O06P;
typedef struct { u8 pad[0x10]; char **unk10; } O06X;
typedef struct { u8 pad[0x18]; O06X *unk18; } O06A;
typedef struct { u8 pad[0x1C]; O06P *unk1C; } O06B;
extern s32 sprintf(char *buf, const char *fmt, ...);
extern char *D_800D71A4;
extern char *D_800D71A8;
extern char *D_800D71AC;
extern char *D_800D71B0;
extern char *D_800D71B4;
extern char *D_800D71B8;
extern char *D_800D71BC;
extern char *D_800D71C0;
extern char *D_800D71C4;
extern char *D_800D71C8;
extern char *D_800D71CC;
extern char *D_800D71D0;
extern char *D_800D71D4;
extern char *D_800D71D8;
extern char *D_800D71DC;
s32 func_00443650(O06A *a, O06B *b) {
    O06X *x = a->unk18;
    O06P *p = b->unk1C;
    char *dst = *x->unk10;
    O06P *s = p->unk12EC;
    if (s == p) {
        sprintf(dst, D_800D71A4);
    } else if (s != 0) {
        switch (p->unk12F0) {
        case 0: sprintf(dst, D_800D71A8, ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 1: sprintf(dst, D_800D71AC, ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 2: sprintf(dst, D_800D71B0, ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 3: sprintf(dst, D_800D71B4, ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 4: sprintf(dst, D_800D71B8, ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 5: sprintf(dst, D_800D71BC, ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 6: sprintf(dst, D_800D71C0, ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        }
    } else {
        switch (p->unk12F0) {
        case 0: sprintf(dst, D_800D71C4); break;
        case 1: sprintf(dst, D_800D71C8); break;
        case 2: sprintf(dst, D_800D71CC); break;
        case 3: sprintf(dst, D_800D71D0); break;
        case 4: sprintf(dst, D_800D71D4); break;
        case 5: sprintf(dst, D_800D71D8); break;
        case 6: sprintf(dst, D_800D71DC); break;
        }
    }
    return 0;
}
