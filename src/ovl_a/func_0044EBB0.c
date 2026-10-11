/* UNIT of 4 functions in ONE file (ROM 0x1BCBB0..0x1BCD93, 121 insns, + 3 linker pad words 0x1BCD94..0x1BCD9F), no upstream source
   (upstream has only the symbols func_8044EBB0 = EBB0 + ECB0 + ED1C and func_8044ED24):
     func_0044EBB0 (64 insns)  sets up the resource pools of a level block: two node pools (func_00279620), the 96 items of 0xB8 bytes on a list,
                               ten empty intrusive lists, 100 nodes of 0x50 bytes queued on the list at +0x95A8; clears two words and calls func_002A6670
     func_0044ECB0 (27 insns)  clears four words at +0x90, calls the empty hook func_0044ED1C and func_002ABD04, builds two 256-byte lookup tables
                               (func_002AC34C from the 117 byte pairs D_800D3080 / D_800D2F94)
     func_0044ED1C (2 insns)   empty function
     func_0044ED24 (28 insns)  starts two scripts on two sprite contexts
   ECB0, ED1C and ED24 follow each other at non 16-aligned addresses (0x1BCD1C, 0x1BCD24), so they are certainly ONE object; EBB0 (256 bytes) is probably the
   same object.  Compile as one unit: symbol offsets EBB0 +0x000, ECB0 +0x100, ED1C +0x16C, ED24 +0x174, text size 484 bytes (the ROM span is 496). */
#include "s1007_types.h"

void func_00279620(S7NodePool *p, void *mem, s32 stride, u32 n);
void func_00279520(S7DL *l);
void func_00279578(S7DL *l, void *n);
void func_00255C40(S7Queue *l, s32 prevOff, s32 nextOff);
s32 func_00255CB4(S7Queue *l, void *n);
void func_002A6670(void *o);
void func_002ABD04(void);
void func_002AC34C(void *o, u8 *pairs, s32 n, u8 *tab);
void func_0044ED1C(void);
void func_002AB6C0(void *s, s16 a, s16 b);
void func_002AB6FC(void *c, s32 *pc);
extern s32 D_auto_800D316C[];
extern s32 D_auto_800D316C_b[] __asm__("D_auto_800D316C");   /* same symbol again: the ROM keeps two lui/addiu pairs, cse must not derive one from the other */
extern u8 D_800D3080[];
extern u8 D_800D2F94[];

void func_0044EBB0(S7Pools *o) {
    s32 i;

    func_00279620(&o->poolA, o->nodesA, 84, 32);
    func_00279620(&o->poolB, o->nodesB, 28, 3);
    func_00279520(&o->list);
    for (i = 0; i < 96; i++) {
        func_00279578(&o->list, &o->items[i]);
    }
    func_00255C40(&o->queue, 0, 4);
    for (i = 0; i < 10; i++) {
        func_00255C40(&o->lists[i], 0, 4);
    }
    for (i = 0; i < 100; i++) {
        func_00255CB4(&o->queue, &o->nodesC[i]);
    }
    o->unk0 = 0;
    o->unk2588 = 0;
    func_002A6670(o);
}

void func_0044ECB0(S7Tabs *o) {
    o->unk90 = 0;
    o->unk94 = 0;
    o->unk98 = 0;
    o->unk9C = 0;
    func_0044ED1C();
    func_002ABD04();
    func_002AC34C(o, D_800D3080, 117, o->tab0);
    func_002AC34C(o, D_800D2F94, 117, o->tab1);
}

void func_0044ED1C(void) {
}

void func_0044ED24(S7AnimPair *o) {
    o->a.unk40 = 0;
    func_002AB6C0(o, 0, -40);
    func_002AB6FC(o, D_auto_800D316C);
    o->b.unk40 = 0;
    func_002AB6C0(&o->b, 0, -20);
    func_002AB6FC(&o->b, D_auto_800D316C_b + 4);
}
