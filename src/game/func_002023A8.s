.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x2FA8-0x2FC4 (VRAM 0x002023A8) */
glabel func_002023A8
    /* 2FA8 002023A8 3C088000 */  lui        $t0, %hi(D_80003FE0)
    /* 2FAC 002023AC 25093FE0 */  addiu      $t1, $t0, %lo(D_80003FE0)
  .L002023B0:
    /* 2FB0 002023B0 BD000000 */  cache      0x00, 0x0($t0) /* handwritten instruction */
    /* 2FB4 002023B4 1509FFFE */  bne        $t0, $t1, .L002023B0
    /* 2FB8 002023B8 25080020 */   addiu     $t0, $t0, 0x20
    /* 2FBC 002023BC 03E00008 */  jr         $ra
    /* 2FC0 002023C0 00000000 */   nop
endlabel func_002023A8
