.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x2F8C-0x2FA8 (VRAM 0x0020238C) */
glabel func_0020238C
    /* 2F8C 0020238C 3C088000 */  lui        $t0, %hi(D_80001FF0)
    /* 2F90 00202390 25091FF0 */  addiu      $t1, $t0, %lo(D_80001FF0)
  .L00202394:
    /* 2F94 00202394 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* 2F98 00202398 1509FFFE */  bne        $t0, $t1, .L00202394
    /* 2F9C 0020239C 25080010 */   addiu     $t0, $t0, 0x10
    /* 2FA0 002023A0 03E00008 */  jr         $ra
    /* 2FA4 002023A4 00000000 */   nop
endlabel func_0020238C
