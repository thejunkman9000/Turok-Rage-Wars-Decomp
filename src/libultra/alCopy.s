.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5FE0-0xB6010 (VRAM 0x002B53E0) */
glabel alCopy
    /* B5FE0 002B53E0 18C00008 */  blez       $a2, .L002B5404
    /* B5FE4 002B53E4 00001821 */   addu      $v1, $zero, $zero
  .L002B53E8:
    /* B5FE8 002B53E8 90820000 */  lbu        $v0, 0x0($a0)
    /* B5FEC 002B53EC 24840001 */  addiu      $a0, $a0, 0x1
    /* B5FF0 002B53F0 24630001 */  addiu      $v1, $v1, 0x1
    /* B5FF4 002B53F4 A0A20000 */  sb         $v0, 0x0($a1)
    /* B5FF8 002B53F8 0066102A */  slt        $v0, $v1, $a2
    /* B5FFC 002B53FC 1440FFFA */  bnez       $v0, .L002B53E8
    /* B6000 002B5400 24A50001 */   addiu     $a1, $a1, 0x1
  .L002B5404:
    /* B6004 002B5404 03E00008 */  jr         $ra
    /* B6008 002B5408 00000000 */   nop
    /* B600C 002B540C 24160002 */  .word      0x24160002 /* linker padding */
endlabel alCopy
