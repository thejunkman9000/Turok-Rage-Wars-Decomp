.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBB400-0xBB4C0 (VRAM 0x002BA800) */
glabel func_002BA800
    /* BB400 002BA800 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* BB404 002BA804 AFBF0010 */  sw         $ra, 0x10($sp)
    /* BB408 002BA808 24A7FFFF */  addiu      $a3, $a1, -0x1
    /* BB40C 002BA80C 2CE20009 */  sltiu      $v0, $a3, 0x9
    /* BB410 002BA810 10400021 */  beqz       $v0, .L002BA898
    /* BB414 002BA814 00801821 */   addu      $v1, $a0, $zero
    /* BB418 002BA818 00071080 */  sll        $v0, $a3, 2
    /* BB41C 002BA81C 3C01800D */  lui        $at, %hi(jtbl_800CC9A0)
    /* BB420 002BA820 00220821 */  addu       $at, $at, $v0
    /* BB424 002BA824 8C22C9A0 */  lw         $v0, %lo(jtbl_800CC9A0)($at)
    /* BB428 002BA828 00400008 */  jr         $v0
    /* BB42C 002BA82C 00000000 */   nop
    /* BB430 002BA830 080AEA2C */  j          .L002BA8B0
    /* BB434 002BA834 AC860000 */   sw        $a2, 0x0($a0)
    /* BB438 002BA838 24020001 */  addiu      $v0, $zero, 0x1
    /* BB43C 002BA83C AC600020 */  sw         $zero, 0x20($v1)
    /* BB440 002BA840 AC620024 */  sw         $v0, 0x24($v1)
    /* BB444 002BA844 AC600030 */  sw         $zero, 0x30($v1)
    /* BB448 002BA848 AC60001C */  sw         $zero, 0x1C($v1)
    /* BB44C 002BA84C 8C840000 */  lw         $a0, 0x0($a0)
    /* BB450 002BA850 10800017 */  beqz       $a0, .L002BA8B0
    /* BB454 002BA854 24050004 */   addiu     $a1, $zero, 0x4
    /* BB458 002BA858 8C820008 */  lw         $v0, 0x8($a0)
    /* BB45C 002BA85C 080AEA2A */  j          .L002BA8A8
    /* BB460 002BA860 00003021 */   addu      $a2, $zero, $zero
    /* BB464 002BA864 24020001 */  addiu      $v0, $zero, 0x1
    /* BB468 002BA868 AC620030 */  sw         $v0, 0x30($v1)
    /* BB46C 002BA86C 8C840000 */  lw         $a0, 0x0($a0)
    /* BB470 002BA870 1080000F */  beqz       $a0, .L002BA8B0
    /* BB474 002BA874 24050009 */   addiu     $a1, $zero, 0x9
    /* BB478 002BA878 8C820008 */  lw         $v0, 0x8($a0)
    /* BB47C 002BA87C 080AEA2A */  j          .L002BA8A8
    /* BB480 002BA880 00003021 */   addu      $a2, $zero, $zero
    /* BB484 002BA884 080AEA2C */  j          .L002BA8B0
    /* BB488 002BA888 AC660018 */   sw        $a2, 0x18($v1)
    /* BB48C 002BA88C 24020001 */  addiu      $v0, $zero, 0x1
    /* BB490 002BA890 080AEA2C */  j          .L002BA8B0
    /* BB494 002BA894 AC62001C */   sw        $v0, 0x1C($v1)
  .L002BA898:
    /* BB498 002BA898 8C840000 */  lw         $a0, 0x0($a0)
    /* BB49C 002BA89C 10800004 */  beqz       $a0, .L002BA8B0
    /* BB4A0 002BA8A0 00000000 */   nop
    /* BB4A4 002BA8A4 8C820008 */  lw         $v0, 0x8($a0)
  .L002BA8A8:
    /* BB4A8 002BA8A8 0040F809 */  jalr       $v0
    /* BB4AC 002BA8AC 00000000 */   nop
  .L002BA8B0:
    /* BB4B0 002BA8B0 8FBF0010 */  lw         $ra, 0x10($sp)
    /* BB4B4 002BA8B4 00001021 */  addu       $v0, $zero, $zero
    /* BB4B8 002BA8B8 03E00008 */  jr         $ra
    /* BB4BC 002BA8BC 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_002BA800
