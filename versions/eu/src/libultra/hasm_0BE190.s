.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBE190-0xBE1B8 (VRAM 0x002BD590) */
.globl osWritebackDCacheAll
osWritebackDCacheAll:
    /* BE190 002BD590 3C088000 */  lui        $t0, 0x8000
    /* BE194 002BD594 240A2000 */  addiu      $t2, $zero, 0x2000
    /* BE198 002BD598 010A4821 */  addu       $t1, $t0, $t2
    /* BE19C 002BD59C 2529FFF0 */  addiu      $t1, $t1, -0x10
.Lauto_002BD5A0:
    /* BE1A0 002BD5A0 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* BE1A4 002BD5A4 0109082B */  sltu       $at, $t0, $t1
    /* BE1A8 002BD5A8 1420FFFD */  .word 0x1420FFFD
    /* BE1AC 002BD5AC 25080010 */  addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* BE1B0 002BD5B0 03E00008 */  jr         $ra
    /* BE1B4 002BD5B4 00000000 */  nop
