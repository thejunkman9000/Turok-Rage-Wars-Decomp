.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8A50-0xB8AB0 (VRAM 0x002B7E50) */
glabel alSndpPlay
    /* B8A50 002B7E50 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B8A54 002B7E54 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B8A58 002B7E58 8C82003C */  lw         $v0, 0x3C($a0)
    /* B8A5C 002B7E5C 8C850040 */  lw         $a1, 0x40($a0)
    /* B8A60 002B7E60 00021840 */  sll        $v1, $v0, 1
    /* B8A64 002B7E64 00621821 */  addu       $v1, $v1, $v0
    /* B8A68 002B7E68 00031900 */  sll        $v1, $v1, 4
    /* B8A6C 002B7E6C 00651821 */  addu       $v1, $v1, $a1
    /* B8A70 002B7E70 8C620028 */  lw         $v0, 0x28($v1)
    /* B8A74 002B7E74 1440000B */  bnez       $v0, .L002B7EA4
    /* B8A78 002B7E78 00003021 */   addu      $a2, $zero, $zero
    /* B8A7C 002B7E7C A7A00010 */  sh         $zero, 0x10($sp)
    /* B8A80 002B7E80 8C83003C */  lw         $v1, 0x3C($a0)
    /* B8A84 002B7E84 24840014 */  addiu      $a0, $a0, 0x14
    /* B8A88 002B7E88 00031040 */  sll        $v0, $v1, 1
    /* B8A8C 002B7E8C 00431021 */  addu       $v0, $v0, $v1
    /* B8A90 002B7E90 00021100 */  sll        $v0, $v0, 4
    /* B8A94 002B7E94 00A21021 */  addu       $v0, $a1, $v0
    /* B8A98 002B7E98 27A50010 */  addiu      $a1, $sp, 0x10
    /* B8A9C 002B7E9C 0C0AD469 */  jal        alEvtqPostEvent
    /* B8AA0 002B7EA0 AFA20014 */   sw        $v0, 0x14($sp)
  .L002B7EA4:
    /* B8AA4 002B7EA4 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B8AA8 002B7EA8 03E00008 */  jr         $ra
    /* B8AAC 002B7EAC 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel alSndpPlay
