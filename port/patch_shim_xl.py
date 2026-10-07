#!/usr/bin/env python3
"""One-off patch: make port/os_shim.c translate guest pointers in the low guest space ([0x200000,0x2000000) lives at +0x30000000)."""
import re
p = 'port/os_shim.c'
s = open(p, newline='').read()
if 'XL(' not in s:
    s = s.replace('#define LDP(x)', '''/* guest pointers into the low guest space (overlay data, assets) are accessed at +0x30000000 on the host */
#define XL(p) ((void *)(size_t)((((u32)(size_t)(p)) - 0x200000u) < 0x1E00000u ? (u32)(size_t)(p) + 0x30000000u : (u32)(size_t)(p)))
#define LDP(x)''', 1)

def sub(old, new, count=1):
    global s
    if old not in s:
        print('MISSING:', old[:70]); return
    s = s.replace(old, new, count)

sub('void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 count) {\n    os_init();', 'void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 count) {\n    os_init(); mq = (OSMesgQueue *)XL(mq);')
sub('static int send_common(OSMesgQueue *mq, OSMesg m, s32 flags, int jam) {\n', 'static int send_common(OSMesgQueue *mq, OSMesg m, s32 flags, int jam) {\n    mq = (OSMesgQueue *)XL(mq);\n')
sub('s32 osRecvMesg(OSMesgQueue *mq, OSMesg *m, s32 flags) {\n', 's32 osRecvMesg(OSMesgQueue *mq, OSMesg *m, s32 flags) {\n    mq = (OSMesgQueue *)XL(mq); m = (OSMesg *)XL(m);\n')
sub('static void post_from_host(OSMesgQueue *mq, OSMesg m) {\n', 'static void post_from_host(OSMesgQueue *mq, OSMesg m) {\n    mq = (OSMesgQueue *)XL(mq);\n')
s = s.replace('OSMesg *buf = (OSMesg *)LDP(mq->msg);', 'OSMesg *buf = (OSMesg *)XL(LDP(mq->msg));')
open(p, 'w', newline='').write(s)
print('patched')
