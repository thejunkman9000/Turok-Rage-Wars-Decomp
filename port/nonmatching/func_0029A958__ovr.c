/* debug: log every change of the current screen id, and the pak-screen state now and then */
#include "b22_types.h"
extern SndMgr *D_8014D080;
extern s32 D_8014D098;
extern s32 D_800E28E0;
extern u8 *D_800E3518;
extern u32 port_unresolve(u32); extern int fprintf(void *, const char *, ...); extern char *getenv(const char *); extern void *__acrt_iob_func(unsigned);
static int dump_cnt;
static void dump_tree(SndCtx *n, int depth) {
    for (; n && dump_cnt < 160 && depth < 12; n = n->child1) {
        dump_cnt++;
        fprintf(__acrt_iob_func(2), "    %*snode %p id=%d unkE=%d fl=%x h3C=%p h40=%p h44=%p\n", depth * 2, "", (void *)n, n->id, n->unkE, n->flags12, (void *)port_unresolve((u32)n->unk3C), (void *)port_unresolve((u32)n->unk40), (void *)port_unresolve((u32)n->unk44));
        if (n->child2) dump_tree(n->child2, depth + 1);
    }
}
s32 func_0029A958(void)
{
    static s32 last = -2;
    static int n;
    s32 v = D_8014D098;
    if (v < 0) {
        if (D_8014D080->top < 0) { v = -1; goto out; }
        v = D_8014D080->stk[D_8014D080->top].id;
    }
out:
    if (v != last) { fprintf(__acrt_iob_func(2), "mgr callback ptr = %p handlerlist? words: %08x %08x %08x\n", (void *)*(u32 *)D_8014D080, ((u32 *)D_8014D080)[1], ((u32 *)D_8014D080)[2], ((u32 *)D_8014D080)[3]); last = v; { extern void port_ff_screen(int); port_ff_screen((int)v); } fprintf(__acrt_iob_func(2), "screen id -> %d (top=%d)\n", v, D_8014D080->top); if (D_8014D080->top >= 0) { if (getenv("TUROK_TREE")) { { int q; for (q = 0; q < 64; q++) if (D_8014D080->slot[q].id || D_8014D080->slot[q].unkC) fprintf(__acrt_iob_func(2), "  SLOT[%d] id=%d fn=%08x u4=%08x u8=%08x u10=%08x\n", q, D_8014D080->slot[q].id, port_unresolve((u32)D_8014D080->slot[q].unkC), D_8014D080->slot[q].unk4, D_8014D080->slot[q].unk8, D_8014D080->slot[q].unk10); } dump_cnt = 0; fprintf(__acrt_iob_func(2), "  TREE of screen %d:\n", v); dump_tree(D_8014D080->stk[D_8014D080->top].ctx, 0); } SndCtx *c = D_8014D080->stk[D_8014D080->top].ctx; SndCtx *u = D_8014D080->stk[D_8014D080->top].unk8; if (c && c->child2) { SndCtx *k = c->child2; fprintf(__acrt_iob_func(2), "  child2 id=%d unkE=%d flags12=%x c1=%p c2=%p h40=%p\n", k->id, k->unkE, k->flags12, (void *)k->child1, (void *)k->child2, (void *)port_unresolve((u32)k->unk40)); if (k->child1) { SndCtx *j = k->child1; fprintf(__acrt_iob_func(2), "    child2.child1 id=%d unkE=%d flags12=%x\n", j->id, j->unkE, j->flags12); } } fprintf(__acrt_iob_func(2), "  ctx unkE=%d flags12=%x child1=%p child2=%p\n", c ? c->unkE : -1, c ? c->flags12 : 0, c ? (void *)c->child1 : 0, c ? (void *)c->child2 : 0); fprintf(__acrt_iob_func(2), "  ctx=%p id=%d h3C=%p h40=%p h44=%p | unk8=%p id=%d h40=%p\n", c, c ? c->id : -1, c ? (void *)c->unk3C : 0, c ? (void *)port_unresolve((u32)c->unk40) : 0, c ? (void *)c->unk44 : 0, u, u ? u->id : -1, u ? (void *)u->unk40 : 0); } }
    if (++n % 2000 == 1) {
        fprintf(__acrt_iob_func(2), "ui: D_800E28E0=%d pg=%p f14=%d f18=%d f1C=%d\n", D_800E28E0, D_800E3518,
                D_800E3518 ? *(s32 *)(D_800E3518 + 0x14) : -1, D_800E3518 ? *(s32 *)(D_800E3518 + 0x18) : -1, D_800E3518 ? *(s32 *)(D_800E3518 + 0x1C) : -1);
    }
    return v;
}
