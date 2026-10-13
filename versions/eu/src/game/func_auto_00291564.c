/* best attempt: ~80 words differ. Semantics right.  Known diffs: ROM keeps blk pointer in s0 (sw zero,0xAC(s0) in the func_00293774 call slot, then a dead addiu s0,s0,-0x5D8 before the loop); ROM keeps constant 1 in s1 across the loop */
#include "b21_types.h"
#include "b21_world.h"

typedef struct B21Msg {
    s16 type;
} B21Msg;

extern s32 D_80000300;
extern u8 D_801536C8[];
extern void *D_801536F8[];
extern f32 D_800CA510;
extern f32 D_800CA514;
extern f32 D_80146CFC;
extern s32 D_8014AD7C;
extern s32 D_80146D68;
extern s32 D_801469E0;
extern s32 D_80146D64;
extern s32 D_8011FAB8;
extern s32 D_8014696C;
extern s32 D_80146CF4;
extern s32 D_8014AD88;
extern s32 D_8014AD8C;
extern s32 D_8014AD90;
extern s32 D_8011FAB4;
extern s32 D_80146CF8;
extern s32 D_80146CF0;
extern OSMesgQueue D_801053E8;
extern OSMesgQueue D_80146980;
extern B21Msg *D_8014AD70;
extern u32 D_800E28A0;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern u8 D_8011FE88[];
extern u8 D_800D0E51;
extern s32 D_80146998;
extern s32 D_8014AD94;
extern s32 D_8014ADA0;
extern s32 D_80146D60;
extern s32 D_8014AD9C;
extern s32 D_80146D6C;
extern void *D_8014AD98;
extern u8 D_800D2F80;

void osViBlack(u8 active);
void osViSwapBuffer(void *buf);
void dbgLinkSetCallHook(s32 (*fn)(u32));
s32 func_002953FC(u32 id);
void func_002567F0();
void func_405CA8(void *a);
void func_4058B0(void *a);
void func_002911E8(B21Game *g);
void func_0023EDF0();
void func_44B27C(void *a);
void func_44AA00(void *a);
s32 func_00265984(s32 a);
void func_44AFC0(void *a, s32 b);
void func_44A600(void *a, s32 b, s32 c);
void func_44C410(void *a, s32 b);
void func_44BAC0();
void func_44ECB0(void *a);
void func_404D84();
void func_002A31F4();
void func_00299368(s32 a);
void func_002647BC();
void func_00293774(B21Game *g, s32 a);
void func_0029382C(B21Game *g);
void func_00292910(B21Game *g);
void func_0026482C();
void func_00264874(s32 a);
void func_00293808(B21Game *g, s32 a);

void func_auto_00291564(B21Game *g) {
    u32 i;
    u8 *a;
    u8 *b;
    B21GameBlk *blk;
    B21Sub1288 *sub;
    func_002567F0();
    osCreateViManager(0xFE);
    osViBlack(1);
    if (D_80000300 != 0) {
        for (;;) {
        }
    }
    func_405CA8(D_801536C8);
    func_4058B0(D_801536C8);
    osViSwapBuffer(D_801536F8[0]);
    osViBlack(0);
    if (D_80000300 == 0) {
        D_80146CFC = D_800CA510;
    } else {
        D_80146CFC = D_800CA514;
    }
    D_8014AD7C = 0;
    D_80146D68 = 2;
    D_801469E0 = 0;
    D_80146D64 = 0;
    D_8011FAB8 = 0;
    D_8014696C = 0;
    D_80146CF4 = 0;
    D_8014AD88 = 0;
    D_8014AD8C = 0;
    D_8014AD90 = 0;
    D_8011FAB4 = 0;
    D_80146CF8 = 0;
    D_80146CF0 = 0;
    func_002911E8(g);
    for (i = 0; i < D_800E28A0; i++) {
        memset(D_801536F8[i], 0, D_800E28D0 * D_800E28D4 * 2);
    }
    a = g->sub255C8;
    func_44B27C(a);
    b = g->sub25580;
    func_44AA00(b);
    func_0023EDF0();
    g->unk3C4 = func_00265984(0x18) & 0x3FFFFFFF;
    func_44AFC0(a, 0);
    func_44A600(b, 0, 0);
    func_44C410(D_8011FE88, g->unk3C4);
    if (D_800D0E51 == 0) {
        func_44BAC0();
    }
    func_44ECB0(g->sub1BCF8);
    func_404D84();
    func_002A31F4();
    func_00299368(2);
    D_80146998 = 3;
    D_8014AD94 = 0;
    D_8014ADA0 = 0;
    D_80146D60 = 0;
    D_8014AD9C = 1;
    D_80146D6C = 0;
    func_002647BC();
    blk = &D_80145040.blk;
    blk->unkAC = 0;
    func_00293774(g, 0);
    sub = &D_80145040.sub1288;
    for (;;) {
        __asm__ volatile("" : : "r"(sub));
        osRecvMesg(&D_80146980, (OSMesg *)&D_8014AD7C, 1);
        __asm__ volatile("");
        __asm__ volatile("");
        __asm__ volatile("");
        __asm__ volatile("");
        switch (((B21Msg *)D_8014AD7C)->type) {
        case 1:
            func_0029382C(g);
            break;
        case 2:
            if ((u8 *)D_8014AD7C == (u8 *)g + 0xF0) {
                D_8014AD98 = g;
            } else if ((u8 *)D_8014AD7C == (u8 *)g + 0x230) {
                D_8014AD98 = (u8 *)g + 0x140;
            } else if ((u8 *)D_8014AD7C == (u8 *)g + 0x370) {
                D_8014AD98 = (u8 *)g + 0x280;
            }
            if (g->unk26DB8 == 20) {
                D_80146D68++;
            } else {
                func_00292910(g);
            }
            break;
        case 4:
            D_800D2F80 = 0;
            func_0026482C();
            func_00264874(0);
            g->unk26DC0 = 1;
            g->unk26DD0 = 1;
            func_00293808(g, 20);
            break;
        }
    }
}
