#include "o06_types.h"
typedef struct { u8 pad[0x5D8]; u8 *unk5D8; } O06Q;
typedef struct O06P { u8 pad[0x12EC]; struct O06P *unk12EC; s32 unk12F0; } O06P;
typedef struct { u8 pad[0x10]; char **unk10; } O06X;
typedef struct { u8 pad[0x18]; O06X *unk18; } O06A;
typedef struct { u8 pad[0x1C]; O06P *unk1C; } O06B;
extern s32 sprintf(char *buf, const char *fmt, ...);
extern u8 D_auto_80152789;
extern char *D_auto_800E1034[];
extern char *D_auto_800E1044[];
extern char *D_auto_800E1054[];
extern char *D_auto_800E1064[];
extern char *D_auto_800E1074[];
extern char *D_auto_800E1084[];
extern char *D_auto_800E1094[];
extern char *D_auto_800E10A4[];
extern char *D_auto_800E10B4[];
extern char *D_auto_800E10C4[];
extern char *D_auto_800E10D4[];
extern char *D_auto_800E10E4[];
extern char *D_auto_800E10F4[];
extern char *D_auto_800E1104[];
extern char *D_auto_800E1114[];
s32 func_auto_00444430(O06A *a, O06B *b) {
    O06X *x = a->unk18;
    O06P *p = b->unk1C;
    char *dst = x->unk10[D_auto_80152789];
    O06P *s = p->unk12EC;
    if (s == p) {
        sprintf(dst, D_auto_800E1034[D_auto_80152789]);
    } else if (s != 0) {
        switch (p->unk12F0) {
        case 0: sprintf(dst, D_auto_800E1044[D_auto_80152789], ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 1: sprintf(dst, D_auto_800E1054[D_auto_80152789], ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 2: sprintf(dst, D_auto_800E1064[D_auto_80152789], ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 3: sprintf(dst, D_auto_800E1074[D_auto_80152789], ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 4: sprintf(dst, D_auto_800E1084[D_auto_80152789], ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 5: sprintf(dst, D_auto_800E1094[D_auto_80152789], ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        case 6: sprintf(dst, D_auto_800E10A4[D_auto_80152789], ((O06Q *)p->unk12EC)->unk5D8 + 0x84); break;
        }
    } else {
        switch (p->unk12F0) {
        case 0: sprintf(dst, D_auto_800E10B4[D_auto_80152789]); break;
        case 1: sprintf(dst, D_auto_800E10C4[D_auto_80152789]); break;
        case 2: sprintf(dst, D_auto_800E10D4[D_auto_80152789]); break;
        case 3: sprintf(dst, D_auto_800E10E4[D_auto_80152789]); break;
        case 4: sprintf(dst, D_auto_800E10F4[D_auto_80152789]); break;
        case 5: sprintf(dst, D_auto_800E1104[D_auto_80152789]); break;
        case 6: sprintf(dst, D_auto_800E1114[D_auto_80152789]); break;
        }
    }
    return 0;
}
