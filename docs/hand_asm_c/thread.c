/*
 * thread.c - readable C reconstruction of the hand-written libultra thread / scheduler assembly
 *            of Turok: Rage Wars (src/libultra/__osEnqueueThread.s, __osPopThread.s,
 *            __osCleanupThread.s, __osEnqueueAndYield.s) and of the debugger watchpoint stub
 *            dbgSetWatchpoint.s.
 *
 * These are `exceptasm.s` routines of the N64 SDK: LEAF() assembly, written to run inside the
 * exception handler with the CPU state in $k0/$k1.  They are not byte-matchable from C, but their
 * logic is small and is reproduced here with the OS structures spelled out.  Coprocessor-0 and
 * register-file access, which C cannot express, goes through the documented hw_* stubs below.
 * The differential test (test/run_thread_tests.py) runs the original machine code against this
 * file.
 */
#include <stdint.h>
#include <stddef.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t  s32;
typedef uint64_t u64;
typedef int64_t  s64;

/* ---------------------------------------------------------------------------------------------
 * OS structures (layout of the N64 build: 32 bit pointers, sizeof(OSThread) == 0x230)
 * --------------------------------------------------------------------------------------------- */

#define OS_STATE_STOPPED  1
#define OS_STATE_RUNNABLE 2
#define OS_STATE_RUNNING  4
#define OS_STATE_WAITING  8

#define SR_EXL      0x00000002u     /* exception level: set in the saved SR so that eret resumes */
#define SR_IMASK    0x0000FF00u     /* CP0 Status interrupt mask (IM0-IM7) */
#define SR_FR       0x04000000u     /* 32 x 64 bit FPU registers: also save the odd ones */

typedef s32 OSPri;

/* One saved thread context (offsets from the start of OSThread: 0x20 ...) */
typedef struct {
    /* 0x020 */ u64 at, v0, v1, a0, a1, a2, a3;
    /* 0x058 */ u64 t0, t1, t2, t3, t4, t5, t6, t7;
    /* 0x098 */ u64 s0, s1, s2, s3, s4, s5, s6, s7;
    /* 0x0D8 */ u64 t8, t9, gp, sp, s8, ra;
    /* 0x108 */ u64 lo, hi;
    /* 0x118 */ u32 sr;         /* CP0 Status */
    /* 0x11C */ u32 pc;         /* EPC: where eret resumes */
    /* 0x120 */ u32 cause;
    /* 0x124 */ u32 badvaddr;
    /* 0x128 */ u32 rcp;        /* MI_INTR_MASK image: which RCP interrupts the thread has enabled */
    /* 0x12C */ u32 fpcsr;
    /* 0x130 */ u64 fp_even[16];   /* $f0, $f2, ... $f30 (the SDK names these fp0..fp30) */
    /* 0x1B0 */ u64 fp_odd[16];    /* $f1, $f3, ... $f31, only meaningful when SR_FR is set */
} OSThreadContext;

typedef struct OSThread_s {
    /* 0x00 */ struct OSThread_s *next;     /* next thread in the queue this thread is on */
    /* 0x04 */ OSPri priority;
    /* 0x08 */ struct OSThread_s **queue;   /* the queue head it sits in (NULL when not queued) */
    /* 0x0C */ struct OSThread_s *tlnext;   /* link of the all-threads list */
    /* 0x10 */ u16 state;
    /* 0x12 */ u16 flags;
    /* 0x14 */ s32 id;
    /* 0x18 */ s32 fp;                      /* non-zero: thread uses the FPU, save/restore it */
    /* 0x1C */ void *thprof;
    /* 0x20 */ OSThreadContext context;
} OSThread;                                 /* 0x230 bytes */

/* ---------------------------------------------------------------------------------------------
 * Globals
 * --------------------------------------------------------------------------------------------- */
extern OSThread *__osRunningThread;     /* 0x800D92A0: thread that owns the CPU */
extern OSThread *__osRunQueue;          /* 0x800D9298: priority ordered run queue head */
extern u32 __OSGlobalIntMask;           /* 0x800D9288: bits 8-15 CP0 IM, bits 16-21 RCP (MI) mask */

extern void __osDispatchThread(void);   /* hand-written asm, not part of this reconstruction */
extern void osDestroyThread(OSThread *t);

/* MI_INTR_MASK_REG (0xA430000C) is read below.  A host build can redirect it. */
#ifndef MI_INTR_MASK_REG_READ
#define MI_INTR_MASK_REG_READ() (*(volatile u32 *)0xA430000Cu)
#endif

/* ---------------------------------------------------------------------------------------------
 * Hardware access stubs (coprocessor 0 / FPU / live registers).  On the console these are single
 * instructions in the middle of an assembler routine; for the host test they are plain functions.
 * --------------------------------------------------------------------------------------------- */

/* The callee-saved integer registers (and $gp) of the *caller* of __osEnqueueAndYield. */
typedef struct {
    u32 s0, s1, s2, s3, s4, s5, s6, s7, gp, sp, fp, ra;
} HwCpuRegs;

/* FPU state: FCSR plus the registers __osEnqueueAndYield saves. */
typedef struct {
    u32 fcsr;
    u64 even[16];       /* $f0 ... $f30 */
    u64 odd[16];        /* $f1 ... $f31 */
} HwFpuRegs;

extern u32  hw_cp0_get_status(void);            /* mfc0 $12 */
extern void hw_cpu_regs(HwCpuRegs *r);          /* the registers as they are at the call */
extern void hw_fpu_regs(HwFpuRegs *r);          /* cfc1 $31 / sdc1 $fN */
extern void hw_cp0_set_watchlo(u32 v);          /* mtc0 $18 */
extern u32  hw_cp0_get_watchhi(void);           /* mfc0 $19 */

/* ---------------------------------------------------------------------------------------------
 * __osEnqueueThread(queue, thread)
 *   Insert `thread` into the priority queue `*queue`: after all entries whose priority is >= its
 *   own (FIFO among equals).  The queue is terminated by a sentinel thread of priority -1
 *   (__osThreadTail), so no end test is needed.  Registers: $t9 = predecessor, $t8 = successor.
 * --------------------------------------------------------------------------------------------- */
void __osEnqueueThread(OSThread **queue, OSThread *t)
{
    OSThread *pred = (OSThread *)queue;     /* $t9: the queue head pretends to be an OSThread whose ->next is *queue */
    OSThread *succ = *queue;                /* $t8 */
    OSPri pri = t->priority;                /* $t7 */

    while (succ->priority >= pri) {
        pred = succ;
        succ = succ->next;
    }
    /* in the original: t8 = pred->next; pred->next = t; t->next = t8; t->queue = queue */
    t->next = pred->next;
    pred->next = t;
    t->queue = queue;
}

/* ---------------------------------------------------------------------------------------------
 * __osPopThread(queue): unlink and return the head of `*queue` (the highest priority thread).
 *   The returned thread's ->next is cleared; its ->queue field is left alone.  The queue must
 *   not be empty (it always holds at least the sentinel when called by the dispatcher).
 * --------------------------------------------------------------------------------------------- */
OSThread *__osPopThread(OSThread **queue)
{
    OSThread *t = *queue;       /* $v0 */
    OSThread *next = t->next;   /* $t9 */

    t->next = NULL;
    *queue = next;
    return t;
}

/* ---------------------------------------------------------------------------------------------
 * __osCleanupThread
 *   Return address planted in the stack frame of every thread created by osCreateThread: a thread
 *   function that returns lands here and destroys itself (osDestroyThread(NULL) = "the running
 *   thread").  osDestroyThread dispatches the next thread and never returns to this code.
 *   (In the ROM the routine has no `jr $ra`: it just falls into the code that follows it.)
 * --------------------------------------------------------------------------------------------- */
void __osCleanupThread(void)
{
    osDestroyThread(NULL);
}

/* ---------------------------------------------------------------------------------------------
 * __osEnqueueAndYield(threadQueue)
 *   Put the running thread to sleep: save its state in its OSThread context, optionally append it
 *   to `threadQueue` (osYieldThread / the scheduler's time slice pass the run queue; blocking
 *   calls pass NULL after they have queued the thread themselves), then dispatch the next thread.
 *   Never returns: it ends with a jump to __osDispatchThread.  The thread later resumes at
 *   the saved `pc` = the $ra of the call, with the callee-saved registers restored.
 *
 *   Original register use: $a1 = running thread, $a0 = threadQueue (kept across the call),
 *   $t0/$t1/$k0/$k1 scratch.  Only callee-saved GPRs and the FPU registers that are callee-saved
 *   by the n32/o32 ABI are stored (the temporaries cannot be live across this call).
 * --------------------------------------------------------------------------------------------- */
void __osEnqueueAndYield(OSThread **threadQueue)
{
    OSThread *t = __osRunningThread;
    OSThreadContext *c = &t->context;
    HwCpuRegs r;
    u32 sr, ipmask, mi;

    /* saved SR: current Status with EXL set, so the dispatcher's eret returns to `pc` */
    sr = hw_cp0_get_status() | SR_EXL;
    c->sr = sr;

    hw_cpu_regs(&r);
    c->s0 = (u64)(s64)(s32)r.s0;
    c->s1 = (u64)(s64)(s32)r.s1;
    c->s2 = (u64)(s64)(s32)r.s2;
    c->s3 = (u64)(s64)(s32)r.s3;
    c->s4 = (u64)(s64)(s32)r.s4;
    c->s5 = (u64)(s64)(s32)r.s5;
    c->s6 = (u64)(s64)(s32)r.s6;
    c->s7 = (u64)(s64)(s32)r.s7;
    c->gp = (u64)(s64)(s32)r.gp;
    c->sp = (u64)(s64)(s32)r.sp;
    c->s8 = (u64)(s64)(s32)r.fp;
    c->ra = (u64)(s64)(s32)r.ra;
    c->pc = r.ra;                       /* resume where the caller continues */

    if (t->fp != 0) {                   /* thread uses the FPU */
        HwFpuRegs f;
        hw_fpu_regs(&f);
        c->fpcsr = f.fcsr;
        /* $f0,$f2,$f4 and $f8..$f30.  $f6 is a caller-saved temporary: not saved (the dispatcher
         * restores the slot anyway, so it carries whatever is in the context). */
        c->fp_even[0] = f.even[0];
        c->fp_even[1] = f.even[1];
        c->fp_even[2] = f.even[2];
        {
            int i;
            for (i = 4; i < 16; i++)
                c->fp_even[i] = f.even[i];
        }
        if (c->sr & SR_FR) {            /* 32 register mode: odd registers exist too */
            int i;
            for (i = 0; i < 16; i++)
                c->fp_odd[i] = f.odd[i];
        }
    }

    /* Interrupt mask bookkeeping.  The saved CP0 IM bits are widened with every bit that is
     * currently masked off globally, so a thread keeps the enable state it asked for and the
     * dispatcher can re-apply __OSGlobalIntMask when it resumes the thread. */
    sr = c->sr;
    ipmask = sr & SR_IMASK;
    if (ipmask != 0) {
        ipmask |= ~__OSGlobalIntMask & SR_IMASK;
        c->sr = (sr & 0xFFFF00FFu) | ipmask;
    }

    /* RCP (MI) interrupt mask image: if any RCP interrupt is enabled in the hardware mask, merge in
     * the thread's own bits for the interrupts the global mask leaves available. */
    mi = MI_INTR_MASK_REG_READ();
    if (mi != 0)
        mi |= (~(__OSGlobalIntMask >> 16) & 0x3Fu) & c->rcp;
    c->rcp = mi;

    if (threadQueue != NULL)
        __osEnqueueThread(threadQueue, t);
    __osDispatchThread();
}

/* ---------------------------------------------------------------------------------------------
 * dbgSetWatchpoint(addr, mode)  -  debugger support (libdbg-like): program the R4300 data
 * watchpoint.  CP0 WatchLo ($18) layout: bits 31..3 physical address (8 byte aligned),
 * bit 1 = watch loads (R), bit 0 = watch stores (W).
 *   addr: a KSEG0/KSEG1 virtual address; the segment bits are stripped (low 28 bits kept),
 *         the low 3 bits are dropped.
 *   mode: bit0 = trap on write, bit1 = trap on read (anything else is masked off).
 * The original follows the mtc0 with four nops (CP0 hazard) and reads WatchHi ($19) into $zero,
 * i.e. a read whose result is discarded.
 * --------------------------------------------------------------------------------------------- */
void dbgSetWatchpoint(u32 addr, u32 mode)
{
    u32 lo = ((addr << 4) >> 4) & ~7u;

    hw_cp0_set_watchlo(lo | (mode & 3u));
    (void)hw_cp0_get_watchhi();
}
