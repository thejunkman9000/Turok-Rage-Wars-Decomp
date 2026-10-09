
#include "b22_types.h"
extern SndMgr *D_8014D080;
extern int port_verbose(void);
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
s32 func_0029A958(void);
s32 func_0029A5D4(s32, s32, s32, s32, s32);
void func_0029ACF0(SndCtx *n, s32 cmd, s32 a, s32 b, s32 c, s32 depth)
{
    SndMgr *m;
    s32 *p;
    s32 saved;
    s32 ok;
    if (n != 0) {
        if (cmd == 0xE06 && port_verbose()) fprintf(__acrt_iob_func(2), "E06 node id=%d unkE=%d depth=%d flags12=%x" "\n", n->id, n->unkE, depth, n->flags12);
        m = D_8014D080;
        saved = m->unk520;
        m->unk520 = 0;
        p = &m->unk520;
        if (n->child1) {
            func_0029ACF0(n->child1, cmd, a, b, c, depth + 1);
        }
        if (m->unk520 == 0) {
            if (n->child2) {
                func_0029ACF0(n->child2, cmd, a, b, c, depth + 1);
            }
            if (m->unk520 == 0) {
                if (depth > 0 && n->id != -1 && n->unkE > 8) {
                    ok = 1;
                    if (cmd == 0xE08 && (n->flags12 | 2) == 0) {
                        ok = 0;
                    } else if (cmd == 0xE09 && (n->flags12 | 4) == 0) {
                        ok = 0;
                    }
                    if (ok) {
                        func_0029A958();
                        func_0029A5D4(n->id, cmd, a, b, c);
                    }
                }
                *p = saved;
                return;
            }
        }
        *p = saved;
    }
}

