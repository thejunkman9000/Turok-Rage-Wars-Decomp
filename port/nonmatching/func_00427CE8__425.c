#include "o04_types.h"
typedef struct { u8 pad0[0x80]; s8 unk80; u8 pad81[0x96 - 0x81]; } O04Ent96l2;
typedef struct { u8 pad0[0x64]; char **unk64; u8 pad68[0x70 - 0x68]; } O04Tbl70b;
typedef struct { u8 pad0[0x24]; u8 unk24; } O04R24;
extern O04ModeS4690 *D_800E4690;
extern O04Cfg D_801462C8[];
extern O04Tbl70b D_800E3A58[];
extern u8 D_80102B94[];
extern char D_800E19EC[];
extern char D_800E19F8[];
extern char D_800E1A00[];
extern char *D_800D7504;
extern char *D_800D7508;
O04Sub2C *func_0040ECB0(s32 a, s32 b);
void func_002A125C(char *dst, char *src);
char *func_00411DF8(s32 a);
s32 func_0041F1B0(s32 a);
void func_0042EB94(char *s, char *find, char *repl);
void func_0040E958(void *p, s32 a);
O04R24 *func_00425E50(s32 a, s32 b, s32 c);
void func_002A1C08(char *buf, char *fmt, s32 a, s32 b);
void func_00427CE8(void) {
    char buf[0x20];
    O04Sub2C *h;
    s32 v;
    s32 idx;
    s32 a2;
    s32 a3;
    O04R24 *r;
    func_0040ECB0(D_800E4690->unk970, 0x153)->unk38 = (s32)D_800E4690->unk9A0;
    switch (D_801462C8->unkD) {
    case 1:
        func_002A125C(D_800E4690->unk9A0, func_00411DF8(0x69));
        func_0042EB94(D_800E4690->unk9A0, D_800E19EC,
                      *D_800E3A58[func_0041F1B0(((O04Ent96l2 *)((u8 *)D_801462C8 + 0xD0))[D_800E4690->unkA5C].unk80)].unk64);
        break;
    case 3:
        func_002A125C(D_800E4690->unk9D2, func_00411DF8(0x3D));
        h = func_0040ECB0(D_800E4690->unk970, 0x156);
        func_0040E958(h, 1);
        h->unk38 = (s32)D_800E4690->unk9D2;
        idx = D_800E4690->unkA44;
        v = *(s32 *)(D_80102B94 + idx * 4 + D_800E4690->unkA5C * 0x190);
        if (v > 0) {
            a2 = v / 60;
            a3 = v % 60;
        } else {
            r = func_00425E50(idx, 3, 0);
            a2 = (u8)(r->unk24 / 60);
            a3 = (u8)(r->unk24 % 60);
        }
        func_002A1C08(buf, D_800E19F8, a2, a3);
        func_0042EB94(D_800E4690->unk9D2, D_800E1A00, buf);
        func_002A125C(D_800E4690->unk9A0, D_800D7508);
        break;
    case 4:
        func_002A125C(D_800E4690->unk9A0, D_800D7504);
        break;
    }
}
