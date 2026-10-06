.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2FE0-0xC3010 (VRAM 0x002C23E0) */
glabel osWritebackDCacheAll
    /* C2FE0 002C23E0 3C088000 */  lui        $t0, 0x8000
    /* C2FE4 002C23E4 240A2000 */  addiu      $t2, $zero, 0x2000
    /* C2FE8 002C23E8 010A4821 */  addu       $t1, $t0, $t2
    /* C2FEC 002C23EC 2529FFF0 */  addiu      $t1, $t1, -0x10
  .L002C23F0:
    /* C2FF0 002C23F0 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* C2FF4 002C23F4 0109082B */  sltu       $at, $t0, $t1
    /* C2FF8 002C23F8 1420FFFD */  bnez       $at, .L002C23F0
    /* C2FFC 002C23FC 25080010 */   addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* C3000 002C2400 03E00008 */  jr         $ra
    /* C3004 002C2404 00000000 */   nop


    /* C3008 002C2408 3C030A00 */  .word      0x3C030A00 /* linker padding */
    /* C300C 002C240C ACA40004 */  .word      0xACA40004 /* linker padding */
endlabel osWritebackDCacheAll
