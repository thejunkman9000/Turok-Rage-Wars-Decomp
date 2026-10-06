.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* OSThread *__osGetCurrFaultedThread(void) { return __osFaultedThread; } */
glabel __osGetCurrFaultedThread
    lui   $v0, %hi(__osFaultedThread)
    lw    $v0, %lo(__osFaultedThread)($v0)
    jr    $ra
     nop
endlabel __osGetCurrFaultedThread
