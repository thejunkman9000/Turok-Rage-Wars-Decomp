







#include "b22_types.h"
extern SndAux *D_8014D0B0;
s32 func_0029AB4C(void);
s32 func_0029A958(void);
s32 func_0029A5D4(s32, s32, s32, s32, s32);
void func_0029B324(SndMsg *m)
{
    s16 ch = m->a;
    u16 mode = m->b;
    s32 key = ((u16)m->type << 16) | (ch & 0xFFFF);
    s32 s0, s2, s3, s4;
    register s32 s5 asm("$21");
    register s32 s6 asm("$22");
    s32 cur, t;
    u16 ix;
    register s32 is4b asm("$4");
    register s32 row asm("$3");
    register u32 m3 asm("$2");
    register s32 is4 asm("$16");
    SndCtl *c;
    s32 a0, v1;
    cur = func_0029AB4C();
    s6 = 0;
    row = ch * 0xC0;
    __asm__("" : "+r"(row));
    row += 4;
    s5 = s6;
    m3 = (u16)(mode - 3);
    is4 = (s16)mode == 4;
    __asm__ __volatile__("");
    ix = m->c;
    ix -= 0x160;
    c = (SndCtl *)((u8 *)D_8014D0B0 + row) + (s16)ix;
    is4b = is4;
    c->cur0 = c->nxt0;
    if (m3 < 2) {
        c->cur1 = c->nxt1;
    }
    if (is4) {
        c->cur2 = c->nxt2;
    }
    c->nxt0 = m->f;
    if (m3 < 2) {
        c->nxt1 = m->g;
    }
    if (is4b) {
        c->nxt2 = m->h;
    }
    s0 = 0;
    s2 = 0;
    s3 = 0;
    s4 = 0;
    a0 = c->nxt1;
    v1 = c->cur1;
    if (v1 < a0) {
        if (v1 < cur) {
            s3 = cur < a0;
        }
        s0 = 5;
        s6 = a0;
    } else {
        t = -cur;
        if (a0 < v1) {
            if (t < v1 && a0 < t) {
                s3 = 1;
            }
            s0 = 6;
            s6 = c->nxt1;
        }
    }
    a0 = c->nxt0;
    v1 = c->cur0;
    if (v1 < a0) {
        if (v1 < cur && cur < a0) {
            s4 = 1;
        }
        s2 = 8;
        goto l5;
    }
    t = -cur;
    if (a0 < v1) {
        if (t < v1 && a0 < t) {
            s4 = 1;
        }
        s2 = 7;
l5:
        s5 = c->nxt0;
    }
    if (s0 != 0) {
        func_0029A5D4(func_0029A958(), s0, key, s3, s6);
    }
    if (s2 != 0) {
        func_0029A5D4(func_0029A958(), s2, key, s4, s5);
    }
    c->cur0 = c->nxt0;
    c->cur1 = c->nxt1;
}







