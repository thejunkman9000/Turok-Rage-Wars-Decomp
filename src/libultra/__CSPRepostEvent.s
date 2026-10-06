.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5A3C-0xB5ACC (VRAM 0x002B4E3C) */
glabel __CSPRepostEvent
    /* B5A3C 002B4E3C 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B5A40 002B4E40 AFB00010 */  sw         $s0, 0x10($sp)
    /* B5A44 002B4E44 00808021 */  addu       $s0, $a0, $zero
    /* B5A48 002B4E48 AFB10014 */  sw         $s1, 0x14($sp)
    /* B5A4C 002B4E4C 00A08821 */  addu       $s1, $a1, $zero
    /* B5A50 002B4E50 AFBF0018 */  sw         $ra, 0x18($sp)
    /* B5A54 002B4E54 0C0B0898 */  jal        osSetIntMask
    /* B5A58 002B4E58 24040001 */   addiu     $a0, $zero, 0x1
    /* B5A5C 002B4E5C 26050008 */  addiu      $a1, $s0, 0x8
    /* B5A60 002B4E60 10A00013 */  beqz       $a1, .L002B4EB0
    /* B5A64 002B4E64 00408021 */   addu      $s0, $v0, $zero
  .L002B4E68:
    /* B5A68 002B4E68 8CA60000 */  lw         $a2, 0x0($a1)
    /* B5A6C 002B4E6C 10C00007 */  beqz       $a2, .L002B4E8C
    /* B5A70 002B4E70 00000000 */   nop
    /* B5A74 002B4E74 8E240008 */  lw         $a0, 0x8($s1)
    /* B5A78 002B4E78 8CC30008 */  lw         $v1, 0x8($a2)
    /* B5A7C 002B4E7C 0083102A */  slt        $v0, $a0, $v1
    /* B5A80 002B4E80 10400006 */  beqz       $v0, .L002B4E9C
    /* B5A84 002B4E84 00641023 */   subu      $v0, $v1, $a0
    /* B5A88 002B4E88 ACC20008 */  sw         $v0, 0x8($a2)
  .L002B4E8C:
    /* B5A8C 002B4E8C 0C0ADD54 */  jal        alLink
    /* B5A90 002B4E90 02202021 */   addu      $a0, $s1, $zero
    /* B5A94 002B4E94 080AD3AC */  j          .L002B4EB0
    /* B5A98 002B4E98 00000000 */   nop
  .L002B4E9C:
    /* B5A9C 002B4E9C 00831023 */  subu       $v0, $a0, $v1
    /* B5AA0 002B4EA0 AE220008 */  sw         $v0, 0x8($s1)
    /* B5AA4 002B4EA4 8CA50000 */  lw         $a1, 0x0($a1)
    /* B5AA8 002B4EA8 14A0FFEF */  bnez       $a1, .L002B4E68
    /* B5AAC 002B4EAC 00000000 */   nop
  .L002B4EB0:
    /* B5AB0 002B4EB0 0C0B0898 */  jal        osSetIntMask
    /* B5AB4 002B4EB4 02002021 */   addu      $a0, $s0, $zero
    /* B5AB8 002B4EB8 8FBF0018 */  lw         $ra, 0x18($sp)
    /* B5ABC 002B4EBC 8FB10014 */  lw         $s1, 0x14($sp)
    /* B5AC0 002B4EC0 8FB00010 */  lw         $s0, 0x10($sp)
    /* B5AC4 002B4EC4 03E00008 */  jr         $ra
    /* B5AC8 002B4EC8 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel __CSPRepostEvent
