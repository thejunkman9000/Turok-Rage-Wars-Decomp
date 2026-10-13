.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDEF0-0xBDF18 (VRAM 0x002BD2F0) */
.globl osWritebackDCacheAll
osWritebackDCacheAll:
    /* BDEF0 002BD2F0 3C088000 */  lui        $t0, 0x8000
    /* BDEF4 002BD2F4 240A2000 */  addiu      $t2, $zero, 0x2000
    /* BDEF8 002BD2F8 010A4821 */  addu       $t1, $t0, $t2
    /* BDEFC 002BD2FC 2529FFF0 */  addiu      $t1, $t1, -0x10
.Lauto_002BD300:
    /* BDF00 002BD300 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* BDF04 002BD304 0109082B */  sltu       $at, $t0, $t1
    /* BDF08 002BD308 1420FFFD */  .word 0x1420FFFD
    /* BDF0C 002BD30C 25080010 */  addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* BDF10 002BD310 03E00008 */  jr         $ra
    /* BDF14 002BD314 00000000 */  nop
