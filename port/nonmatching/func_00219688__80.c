#include "b04_types.h"
extern u8 *D_800D7A6C[], *D_800D7A70[], *D_800D7A74[], *D_800D7A80[], *D_800D7A84[];
typedef struct { u8 pad0[0x54]; s32 unk54; u8 pad58[0x20]; s32 unk78; } B04Gs;
typedef struct { u8 pad0[0x1D]; u8 unk1D; u8 pad1E[0x5BA]; B04Gs sub; } B04G2;
extern B04G2 D_801462C8[];
typedef struct { u8 pad0[0x84]; u8 name[1]; } B04Nm;
typedef struct { u8 pad0[0x8F]; u8 unk8F; } B04St;
typedef struct { u8 pad0[0x5D8]; B04Nm *stats; void *cam; u8 pad5E0[0xE08]; s32 idx; } B04Pm;
void func_002934A4(void *, void *);
void func_00239760(void *, void *, void *, f32);
#define SA(o) ((u8 *)(o) + ((o)->idx * 0x19 + 0x13EC))
#define SB(o, k) ((u8 *)((o)->idx * 0x19 + (u32)(o) + (k)))
#define ADV(o) { (o)->idx = (o)->idx + 1; (o)->idx = (o)->idx % 4; }
void func_00219688(B04Pm *a, B04Pm *b) {
    B04G2 *G = D_801462C8;
    B04Gs *T;
    if (G->unk1D != 0) {
        if (a != b) {
            T = &G->sub;
            if (((B04St *)a->stats)->unk8F != 0) {
                if (T->unk54 != 0) {
                    func_002934A4(SA(a), D_800D7A6C[0]);
                    func_002934A4(SB(a, 0x13F6), (u8 *)b->stats + 0x84);
                    if (a->cam != NULL)
                        func_00239760((u8 *)G - 0x1240, a->cam, SA(a), 1.5f);
                    ADV(a);
                    func_002934A4(SA(b), D_800D7A70[0]);
                    func_002934A4(SB(b, 0x13F7), (u8 *)a->stats + 0x84);
                    if (b->cam != NULL)
                        func_00239760((u8 *)G - 0x1240, b->cam, SA(b), 1.5f);
                    goto blk25;
                }
                if (T->unk78 != 0) {
                    func_002934A4(SA(a), D_800D7A74[0]);
                    func_002934A4(SB(a, 0x13F6), (u8 *)b->stats + 0x84);
                    if (a->cam != NULL)
                        func_00239760((u8 *)G - 0x1240, a->cam, SA(a), 1.5f);
                    ADV(a);
                    func_002934A4(SA(a), D_800D7A80[0]);
                    if (a->cam != NULL)
                        func_00239760((u8 *)G - 0x1240, a->cam, SA(a), 1.5f);
                    ADV(a);
                    func_002934A4(SA(b), D_800D7A70[0]);
                    func_002934A4(SB(b, 0x13F7), (u8 *)a->stats + 0x84);
                    if (b->cam != NULL)
                        func_00239760((u8 *)G - 0x1240, b->cam, SA(b), 1.5f);
                    ADV(b);
                    func_002934A4(SA(b), D_800D7A84[0]);
                    if (b->cam != NULL)
                        func_00239760((u8 *)G - 0x1240, b->cam, SA(b), 1.5f);
                    goto blk25;
                }
            }
        } else {
blk25:
            ADV(b);
        }
    }
}
