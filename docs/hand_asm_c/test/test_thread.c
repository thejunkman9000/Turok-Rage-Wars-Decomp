/*
 * test_thread.c - C side of the differential test of ../thread.c.
 *
 *   test_thread <scenarios.txt>
 *
 * Reads scenarios written by run_thread_tests.py, runs the C reconstruction on host structures and
 * prints one result line per scenario in a canonical text form, which the script compares with the
 * state left by the original machine code.  thread.c is #included so that the hw_* stubs and the
 * MI register read can be provided here.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned g_mi;                                   /* MI_INTR_MASK_REG value */
#define MI_INTR_MASK_REG_READ() (g_mi)
#include "../thread.c"

/* ---- host side of the hw_* stubs ---- */
static u32 g_status;
static HwCpuRegs g_cpu;
static HwFpuRegs g_fpu;
static u32 g_watchlo, g_watchhi = 0xFFFFFFFFu;
static int g_dispatched;
static OSThread *g_destroyed = (OSThread *)1;

u32 hw_cp0_get_status(void) { return g_status; }
void hw_cpu_regs(HwCpuRegs *r) { *r = g_cpu; }
void hw_fpu_regs(HwFpuRegs *r) { *r = g_fpu; }
void hw_cp0_set_watchlo(u32 v) { g_watchlo = v; }
u32 hw_cp0_get_watchhi(void) { return g_watchhi; }
void __osDispatchThread(void) { g_dispatched = 1; }
void osDestroyThread(OSThread *t) { g_destroyed = t; }

OSThread *__osRunningThread;
OSThread *__osRunQueue;
u32 __OSGlobalIntMask;

#define MAXT 16
static OSThread th[MAXT + 2];       /* 0..n-1 queued, n = running, n+1 = sentinel */
static OSThread *qhead;

static int idx_of(OSThread *p, int n)
{
    int i;
    if (p == NULL) return -1;
    for (i = 0; i < n + 2; i++)
        if (&th[i] == p) return i;
    return -2;
}

static void print_order(int n)
{
    OSThread *p = qhead;
    printf("order=");
    while (p) {
        printf("%d,", idx_of(p, n));
        p = p->next;
    }
    printf(" queuefield=");
    {
        int i;
        for (i = 0; i < n + 1; i++)
            printf("%d", th[i].queue == NULL ? 0 : (th[i].queue == &qhead ? 1 : 9));
    }
}

static void build(int n, int *prio, int qlen, int *q)
{
    int i;
    memset(th, 0x5A, sizeof th);
    for (i = 0; i < n + 2; i++) {
        th[i].next = NULL;
        th[i].queue = NULL;
        th[i].tlnext = NULL;
        th[i].priority = (i == n + 1) ? -1 : (i == n ? 10 : prio[i]);
    }
    qhead = &th[n + 1];
    for (i = qlen - 1; i >= 0; i--) {       /* build list q[0] -> q[1] -> ... -> sentinel */
        th[q[i]].next = qhead;
        th[q[i]].queue = &qhead;
        qhead = &th[q[i]];
    }
}

static unsigned long long rd64(FILE *f) { unsigned long long v = 0; fscanf(f, "%llx", &v); return v; }
static unsigned rd32(FILE *f) { unsigned v = 0; fscanf(f, "%x", &v); return v; }
static int rdi(FILE *f) { int v = 0; fscanf(f, "%d", &v); return v; }

int main(int argc, char **argv)
{
    FILE *f;
    char kind[16];
    if (argc != 2) return 2;
    f = fopen(argv[1], "r");
    if (!f) return 2;
    while (fscanf(f, "%15s", kind) == 1) {
        int n, qlen, prio[MAXT], q[MAXT], i;
        if (!strcmp(kind, "ENQ") || !strcmp(kind, "POP")) {
            int which;
            n = rdi(f);
            for (i = 0; i < n; i++) prio[i] = rdi(f);
            qlen = rdi(f);
            for (i = 0; i < qlen; i++) q[i] = rdi(f);
            which = rdi(f);                     /* ENQ: thread to insert */
            build(n, prio, qlen, q);
            if (kind[0] == 'E') {
                __osEnqueueThread(&qhead, &th[which]);
                printf("ENQ ");
                print_order(n);
                printf(" selfnext=%d\n", idx_of(th[which].next, n));
            } else {
                OSThread *t = __osPopThread(&qhead);
                printf("POP ret=%d retnext=%d ", idx_of(t, n), idx_of(t->next, n));
                print_order(n);
                printf("\n");
            }
        } else if (!strcmp(kind, "YIELD")) {
            OSThreadContext *c;
            int hasq, k;
            OSThread *queue_arg;
            g_dispatched = 0;
            n = rdi(f);
            for (i = 0; i < n; i++) prio[i] = rdi(f);
            qlen = rdi(f);
            for (i = 0; i < qlen; i++) q[i] = rdi(f);
            build(n, prio, qlen, q);
            hasq = rdi(f);
            th[n].fp = rdi(f);
            g_status = rd32(f);
            g_fpu.fcsr = rd32(f);
            g_cpu.s0 = rd32(f); g_cpu.s1 = rd32(f); g_cpu.s2 = rd32(f); g_cpu.s3 = rd32(f);
            g_cpu.s4 = rd32(f); g_cpu.s5 = rd32(f); g_cpu.s6 = rd32(f); g_cpu.s7 = rd32(f);
            g_cpu.gp = rd32(f); g_cpu.sp = rd32(f); g_cpu.fp = rd32(f); g_cpu.ra = rd32(f);
            for (k = 0; k < 16; k++) g_fpu.even[k] = rd64(f);
            for (k = 0; k < 16; k++) g_fpu.odd[k] = rd64(f);
            __OSGlobalIntMask = rd32(f);
            g_mi = rd32(f);
            th[n].context.rcp = rd32(f);
            __osRunningThread = &th[n];
            (void)queue_arg;
            __osEnqueueAndYield(hasq ? &qhead : NULL);
            c = &th[n].context;
            printf("YIELD dispatched=%d ", g_dispatched);
            print_order(n);
            printf(" sr=%08X pc=%08X rcp=%08X fpcsr=%08X", c->sr, c->pc, c->rcp, c->fpcsr);
            printf(" gpr=%llX,%llX,%llX,%llX,%llX,%llX,%llX,%llX,%llX,%llX,%llX,%llX",
                   (unsigned long long)c->s0, (unsigned long long)c->s1, (unsigned long long)c->s2,
                   (unsigned long long)c->s3, (unsigned long long)c->s4, (unsigned long long)c->s5,
                   (unsigned long long)c->s6, (unsigned long long)c->s7, (unsigned long long)c->gp,
                   (unsigned long long)c->sp, (unsigned long long)c->s8, (unsigned long long)c->ra);
            printf(" other=%llX,%llX,%llX,%08X,%08X", (unsigned long long)c->at, (unsigned long long)c->t0,
                   (unsigned long long)c->hi, c->cause, c->badvaddr);
            printf(" fe=");
            for (k = 0; k < 16; k++) printf("%llX,", (unsigned long long)c->fp_even[k]);
            printf(" fo=");
            for (k = 0; k < 16; k++) printf("%llX,", (unsigned long long)c->fp_odd[k]);
            printf("\n");
        } else if (!strcmp(kind, "WATCH")) {
            unsigned a0 = rd32(f), a1 = rd32(f);
            dbgSetWatchpoint(a0, a1);
            printf("WATCH %08X\n", g_watchlo);
        } else if (!strcmp(kind, "CLEANUP")) {
            g_destroyed = (OSThread *)1;
            __osCleanupThread();
            printf("CLEANUP destroy_arg=%s\n", g_destroyed == NULL ? "NULL" : "other");
        } else {
            fprintf(stderr, "bad scenario kind %s\n", kind);
            return 2;
        }
    }
    return 0;
}
