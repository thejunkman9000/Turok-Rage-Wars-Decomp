.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC245C-0xC2470 (VRAM 0x002C185C) */
glabel __osCleanupThread
    /* C245C 002C185C 0C0B07C4 */  jal        osDestroyThread
    /* C2460 002C1860 00002021 */   addu      $a0, $zero, $zero
    /* C2464 002C1864 10400002 */  .word      0x10400002 /* linker padding */
    /* C2468 002C1868 24100020 */  .word      0x24100020 /* linker padding */
    /* C246C 002C186C 02208021 */  .word      0x02208021 /* linker padding */
endlabel __osCleanupThread
