.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2C20-0xC2C40 (VRAM 0x002C2020) */
glabel __osDisableInt
    /* C2C20 002C2020 40086000 */  mfc0       $t0, $12 /* handwritten instruction */
    /* C2C24 002C2024 2401FFFE */  addiu      $at, $zero, -0x2
    /* C2C28 002C2028 01014824 */  and        $t1, $t0, $at
    /* C2C2C 002C202C 40896000 */  mtc0       $t1, $12 /* handwritten instruction */
    /* C2C30 002C2030 31020001 */  andi       $v0, $t0, 0x1
    /* C2C34 002C2034 00000000 */  nop
    /* C2C38 002C2038 03E00008 */  jr         $ra
    /* C2C3C 002C203C 00000000 */   nop
endlabel __osDisableInt
