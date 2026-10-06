.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2F70-0xC2FE0 (VRAM 0x002C2370) */
glabel osWritebackDCache
    /* C2F70 002C2370 18A0000E */  blez       $a1, .L002C23AC
    /* C2F74 002C2374 240B2000 */   addiu     $t3, $zero, 0x2000
    /* C2F78 002C2378 00AB082B */  sltu       $at, $a1, $t3
  .L002C237C:
    /* C2F7C 002C237C 1020000D */  beqz       $at, .L002C23B4
    /* C2F80 002C2380 00804021 */   addu      $t0, $a0, $zero
    /* C2F84 002C2384 00854821 */  addu       $t1, $a0, $a1
    /* C2F88 002C2388 0109082B */  sltu       $at, $t0, $t1
    /* C2F8C 002C238C 10200007 */  beqz       $at, .L002C23AC
    /* C2F90 002C2390 2529FFF0 */   addiu     $t1, $t1, -0x10
    /* C2F94 002C2394 310A000F */  andi       $t2, $t0, 0xF
    /* C2F98 002C2398 010A4023 */  subu       $t0, $t0, $t2
  .L002C239C:
    /* C2F9C 002C239C BD190000 */  cache      0x19, 0x0($t0) /* handwritten instruction */
    /* C2FA0 002C23A0 0109082B */  sltu       $at, $t0, $t1
    /* C2FA4 002C23A4 1420FFFD */  bnez       $at, .L002C239C
    /* C2FA8 002C23A8 25080010 */   addiu     $t0, $t0, 0x10
  .L002C23AC:
    /* C2FAC 002C23AC 03E00008 */  jr         $ra
    /* C2FB0 002C23B0 00000000 */   nop
  .L002C23B4:
    /* C2FB4 002C23B4 3C088000 */  lui        $t0, 0x8000
    /* C2FB8 002C23B8 010B4821 */  addu       $t1, $t0, $t3
    /* C2FBC 002C23BC 2529FFF0 */  addiu      $t1, $t1, -0x10
  .L002C23C0:
    /* C2FC0 002C23C0 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* C2FC4 002C23C4 0109082B */  sltu       $at, $t0, $t1
    /* C2FC8 002C23C8 1420FFFD */  bnez       $at, .L002C23C0
    /* C2FCC 002C23CC 25080010 */   addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* C2FD0 002C23D0 03E00008 */  jr         $ra
    /* C2FD4 002C23D4 00000000 */   nop


    /* C2FD8 002C23D8 34420002 */  .word      0x34420002 /* linker padding */
    /* C2FDC 002C23DC 0C0B0F49 */  .word      0x0C0B0F49 /* linker padding */
endlabel osWritebackDCache
