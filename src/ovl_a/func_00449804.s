.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B7804-0x1B784C (VRAM 0x00449804) */
glabel func_00449804
    /* 1B7804 00449804 00003821 */  addu       $a3, $zero, $zero
    /* 1B7808 00449808 A4C00000 */  sh         $zero, 0x0($a2)
    /* 1B780C 0044980C A4A00000 */  sh         $zero, 0x0($a1)
    /* 1B7810 00449810 00871021 */  addu       $v0, $a0, $a3
  .L00449814:
    /* 1B7814 00449814 94430000 */  lhu        $v1, 0x0($v0)
    /* 1B7818 00449818 94A20000 */  lhu        $v0, 0x0($a1)
    /* 1B781C 0044981C 24E70002 */  addiu      $a3, $a3, 0x2
    /* 1B7820 00449820 00431021 */  addu       $v0, $v0, $v1
    /* 1B7824 00449824 A4A20000 */  sh         $v0, 0x0($a1)
    /* 1B7828 00449828 94C20000 */  lhu        $v0, 0x0($a2)
    /* 1B782C 0044982C 00031827 */  nor        $v1, $zero, $v1
    /* 1B7830 00449830 00431021 */  addu       $v0, $v0, $v1
    /* 1B7834 00449834 A4C20000 */  sh         $v0, 0x0($a2)
    /* 1B7838 00449838 2CE2001C */  sltiu      $v0, $a3, 0x1C
    /* 1B783C 0044983C 1440FFF5 */  bnez       $v0, .L00449814
    /* 1B7840 00449840 00871021 */   addu      $v0, $a0, $a3
    /* 1B7844 00449844 03E00008 */  jr         $ra
    /* 1B7848 00449848 00001021 */   addu      $v0, $zero, $zero
endlabel func_00449804
