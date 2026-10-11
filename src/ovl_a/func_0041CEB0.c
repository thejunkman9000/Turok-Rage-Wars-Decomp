/* Record/slot screen constructor (state machine: func_0041D1A4).  Allocates the 0x210-byte menu object
   D_800E3590, looks up its widgets in the screen `arg0` (func_0040ECB0 = find node by id), moves the two
   side panels (ids 0x1EC / 0x1EB) off screen by their width and stores width/4 as the per-tick slide step
   (the remainder is folded into the start position, so four ticks bring them exactly home).
   Hidden inside pad_18AEA8 (426 words = 2 pad words + this function + func_0041D1A4); not matched upstream.
   `t` is ONE function-level variable shared by both panel blocks (a block-local t per panel changes the
   local/global register split of the whole block). */
#include "s1008_types.h"

extern S1008Menu *D_800E3590;

extern void *func_00252FFC(s32 size);
extern void *func_0041B690(void *screen, s32 id);
extern void func_0041B768(void *screen, s32 index, s32 flags);
extern void func_0041B9E8(void *handle, s32 enabled);
extern S1008Node *func_0040ECB0(void *screen, s32 id);
extern void func_0040E958(S1008Node *node, s32 enabled);
extern s32 func_00419ED4(s32 id, s32 arg1);
extern void func_0041DBA0(s32 *p);
extern void func_0041D718(void);
extern void func_0041DACC(s32 style);

s32 func_0041CEB0(void *arg0) {
    s32 t;
    D_800E3590 = func_00252FFC(0x210);
    D_800E3590->owner = arg0;
    D_800E3590->handle = func_0041B690(arg0, 4);
    func_0041B768(arg0, 0, 0x201);
    func_0041B768(arg0, 1, 0x201);
    func_0041B768(arg0, 2, 0x201);
    func_0041B768(arg0, 3, 0x201);
    func_0041B9E8(D_800E3590->handle, 1);
    D_800E3590->state = 1;
    D_800E3590->timer = 4;
    D_800E3590->left = func_0040ECB0(arg0, 0x1EC);
    D_800E3590->left->x -= D_800E3590->left->w;
    D_800E3590->leftStep = D_800E3590->left->w / 4;
    t = D_800E3590->left->w - D_800E3590->leftStep * 4;
    D_800E3590->left->x += t;
    D_800E3590->right = func_0040ECB0(arg0, 0x1EB);
    D_800E3590->right->x += D_800E3590->right->w;
    D_800E3590->rightStep = D_800E3590->right->w / 4;
    t = D_800E3590->right->w - D_800E3590->rightStep * 4;
    D_800E3590->right->x -= t;
    func_0040ECB0(arg0, 0x1E8)->style = 0x6E;
    D_800E3590->fade = func_00419ED4(0x1E6, 0xFF);
    D_800E3590->groupA = func_0040ECB0(arg0, 0x1E6);
    func_0040E958(D_800E3590->groupA, 0);
    D_800E3590->cursor = func_0040ECB0(arg0, 0x233);
    func_0040E958(D_800E3590->cursor, 0);
    func_0040ECB0(arg0, 0x1F0)->style = 0x6E;
    func_0040ECB0(arg0, 0x1F1)->style = 0x78;
    D_800E3590->groupB = func_0040ECB0(arg0, 0x200);
    func_0040E958(D_800E3590->groupB, 0);
    D_800E3590->styleValue = 0;
    D_800E3590->styleStep = 0x1B;
    D_800E3590->groupC = func_0040ECB0(arg0, 0x1FF);
    func_0040E958(D_800E3590->groupC, 0);
    D_800E3590->groupC->style = 0;
    D_800E3590->alphaStep = 0x19;
    D_800E3590->nodeF0 = func_0040ECB0(arg0, 0x1FE);
    D_800E3590->clock = 0;
    D_800E3590->f10C = -1;
    func_0041DBA0(&D_800E3590->f10C);
    func_0041D718();
    func_0041DACC(D_800E3590->styleValue);
    func_0040ECB0(arg0, 0x1ED)->style = 0x6E;
    D_800E3590->focus = 0;
    return 0;
}
