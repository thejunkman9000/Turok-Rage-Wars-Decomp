.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B4B44-0x1B4B7C (VRAM 0x00446B44) */
glabel func_00446B44
    /* 1B4B44 00446B44 3C038014 */  lui        $v1, %hi(D_801468A0)
    /* 1B4B48 00446B48 246368A0 */  addiu      $v1, $v1, %lo(D_801468A0)
    /* 1B4B4C 00446B4C 8C620028 */  lw         $v0, 0x28($v1)
    /* 1B4B50 00446B50 14400007 */  bnez       $v0, .L00446B70
    /* 1B4B54 00446B54 00002021 */   addu      $a0, $zero, $zero
    /* 1B4B58 00446B58 8C62001C */  lw         $v0, 0x1C($v1)
    /* 1B4B5C 00446B5C 54400005 */  bnel       $v0, $zero, .L00446B74
    /* 1B4B60 00446B60 24040001 */   addiu     $a0, $zero, 0x1
    /* 1B4B64 00446B64 8C620020 */  lw         $v0, 0x20($v1)
    /* 1B4B68 00446B68 10400002 */  beqz       $v0, .L00446B74
    /* 1B4B6C 00446B6C 00000000 */   nop
  .L00446B70:
    /* 1B4B70 00446B70 24040001 */  addiu      $a0, $zero, 0x1
  .L00446B74:
    /* 1B4B74 00446B74 03E00008 */  jr         $ra
    /* 1B4B78 00446B78 00801021 */   addu      $v0, $a0, $zero
endlabel func_00446B44
