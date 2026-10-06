.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB9BAC-0xB9BE0 (VRAM 0x002B8FAC) */
glabel alMainBusParam
    /* B9BAC 002B8FAC 8C87001C */  lw         $a3, 0x1C($a0)
    /* B9BB0 002B8FB0 24020002 */  addiu      $v0, $zero, 0x2
    /* B9BB4 002B8FB4 14A20007 */  bne        $a1, $v0, .L002B8FD4
    /* B9BB8 002B8FB8 00000000 */   nop
    /* B9BBC 002B8FBC 8C830014 */  lw         $v1, 0x14($a0)
    /* B9BC0 002B8FC0 00431004 */  sllv       $v0, $v1, $v0
    /* B9BC4 002B8FC4 24630001 */  addiu      $v1, $v1, 0x1
    /* B9BC8 002B8FC8 00471021 */  addu       $v0, $v0, $a3
    /* B9BCC 002B8FCC AC460000 */  sw         $a2, 0x0($v0)
    /* B9BD0 002B8FD0 AC830014 */  sw         $v1, 0x14($a0)
  .L002B8FD4:
    /* B9BD4 002B8FD4 03E00008 */  jr         $ra
    /* B9BD8 002B8FD8 00001021 */   addu      $v0, $zero, $zero


    /* B9BDC 002B8FDC 3C020308 */  .word      0x3C020308 /* linker padding */
endlabel alMainBusParam
