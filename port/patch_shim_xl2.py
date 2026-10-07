#!/usr/bin/env python3
"""second pass of the guest-pointer translation patch for port/os_shim.c (threads, timers, DMA, controllers)"""
p = 'port/os_shim.c'
s = open(p, newline='').read()
def sub(old, new):
    global s
    if old not in s:
        print('MISSING:', old[:80]); return
    s = s.replace(old, new, 1)

sub('void osCreateThread(OSThread *t, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri pri) {\n    os_init(); (void)sp;',
    'extern void *port_resolve(unsigned guest);\nvoid osCreateThread(OSThread *t, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri pri) {\n    OSThread *tx = (OSThread *)XL(t);\n    os_init(); (void)sp; entry = (void (*)(void *))port_resolve((unsigned)(size_t)entry);')
sub('ST32(t->priority, pri); ST32(t->id, id); ST16(t->state, OS_STATE_STOPPED); STP(t->next, 0); STP(t->queue, 0);',
    'ST32(tx->priority, pri); ST32(tx->id, id); ST16(tx->state, OS_STATE_STOPPED); STP(tx->next, 0); STP(tx->queue, 0);')
sub('ST16(t->state, OS_STATE_RUNNABLE);', 'ST16(((OSThread *)XL(t))->state, OS_STATE_RUNNABLE);')
sub('if (h->t) ST32(h->t->priority, pri);', 'if (h->t) ST32(((OSThread *)XL(h->t))->priority, pri);')
sub('return h && h->t ? (OSId)LD32(h->t->id) : 0;', 'return h && h->t ? (OSId)LD32(((OSThread *)XL(h->t))->id) : 0;')
sub('os_init(); STP(t->mq, mq); ST32(t->msg, (u32)(size_t)msg); ST64(t->interval, interval);',
    'os_init(); { OSTimer *tx = (OSTimer *)XL(t); STP(tx->mq, mq); ST32(tx->msg, (u32)(size_t)msg); ST64(tx->interval, interval); }')
sub('if (t) post_from_host((OSMesgQueue *)LDP(t->mq), (OSMesg)(size_t)LD32(t->msg));',
    'if (t) { OSTimer *tx = (OSTimer *)XL(t); post_from_host((OSMesgQueue *)LDP(tx->mq), (OSMesg)(size_t)LD32(tx->msg)); }')
sub('if (dir == 0) rom_copy(vaddr, dev, n);                    /* OS_READ */\n    STP(mb->hdr.retQueue, mq);',
    'if (dir == 0) rom_copy(XL(vaddr), dev, n);                    /* OS_READ */\n    STP(((OSIoMesg *)XL(mb))->hdr.retQueue, mq);')
sub('if (dir == 0) rom_copy(vaddr, dev, n);\n    post_from_host(g_ev_mq[8]', 'if (dir == 0) rom_copy(XL(vaddr), dev, n);\n    post_from_host(g_ev_mq[8]')
sub('(void)mq; *bitpattern = 1;\n    for (int i = 0; i < 4; i++) { ST16(status[i].type',
    '(void)mq; bitpattern = (u8 *)XL(bitpattern); status = (OSContStatus *)XL(status); *bitpattern = 1;\n    for (int i = 0; i < 4; i++) { ST16(status[i].type')
sub('s32 osSpTaskLoad(OSTask *t) { g_task = *t; return 0; }', 's32 osSpTaskLoad(OSTask *t) { g_task = *(OSTask *)XL(t); return 0; }')
open(p, 'w', newline='').write(s)
print('patched')
