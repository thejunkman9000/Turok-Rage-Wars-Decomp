.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBBDA8-0xBBDBC (VRAM 0x002BB1A8) */
glabel func_002BB1A8
    /* BBDA8 002BB1A8 24020001 */  addiu      $v0, $zero, 0x1
    /* BBDAC 002BB1AC 50A20001 */  beql       $a1, $v0, .L002BB1B4
    /* BBDB0 002BB1B0 AC860000 */   sw        $a2, 0x0($a0)
  .L002BB1B4:
    /* BBDB4 002BB1B4 03E00008 */  jr         $ra
    /* BBDB8 002BB1B8 00001021 */   addu      $v0, $zero, $zero
endlabel func_002BB1A8
