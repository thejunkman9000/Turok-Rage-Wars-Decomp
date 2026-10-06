.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7660-0xB7710 (VRAM 0x002B6A60) */
glabel func_002B6A60
    /* B7660 002B6A60 90820034 */  lbu        $v0, 0x34($a0)
    /* B7664 002B6A64 10400028 */  beqz       $v0, .L002B6B08
    /* B7668 002B6A68 00002821 */   addu      $a1, $zero, $zero
    /* B766C 002B6A6C 24090040 */  addiu      $t1, $zero, 0x40
    /* B7670 002B6A70 2408007F */  addiu      $t0, $zero, 0x7F
    /* B7674 002B6A74 24070005 */  addiu      $a3, $zero, 0x5
    /* B7678 002B6A78 240600C8 */  addiu      $a2, $zero, 0xC8
    /* B767C 002B6A7C 3C01800D */  lui        $at, %hi(D_800CC71C)
    /* B7680 002B6A80 C420C71C */  lwc1       $fv0, %lo(D_800CC71C)($at)
  .L002B6A84:
    /* B7684 002B6A84 8C820060 */  lw         $v0, 0x60($a0)
    /* B7688 002B6A88 00051900 */  sll        $v1, $a1, 4
    /* B768C 002B6A8C 00621021 */  addu       $v0, $v1, $v0
    /* B7690 002B6A90 AC400000 */  sw         $zero, 0x0($v0)
    /* B7694 002B6A94 8C820060 */  lw         $v0, 0x60($a0)
    /* B7698 002B6A98 00621021 */  addu       $v0, $v1, $v0
    /* B769C 002B6A9C A0400006 */  sb         $zero, 0x6($v0)
    /* B76A0 002B6AA0 8C820060 */  lw         $v0, 0x60($a0)
    /* B76A4 002B6AA4 00621021 */  addu       $v0, $v1, $v0
    /* B76A8 002B6AA8 A040000A */  sb         $zero, 0xA($v0)
    /* B76AC 002B6AAC 8C820060 */  lw         $v0, 0x60($a0)
    /* B76B0 002B6AB0 00621021 */  addu       $v0, $v1, $v0
    /* B76B4 002B6AB4 A0490007 */  sb         $t1, 0x7($v0)
    /* B76B8 002B6AB8 8C820060 */  lw         $v0, 0x60($a0)
    /* B76BC 002B6ABC 00621021 */  addu       $v0, $v1, $v0
    /* B76C0 002B6AC0 A0480009 */  sb         $t0, 0x9($v0)
    /* B76C4 002B6AC4 8C820060 */  lw         $v0, 0x60($a0)
    /* B76C8 002B6AC8 00621021 */  addu       $v0, $v1, $v0
    /* B76CC 002B6ACC A0470008 */  sb         $a3, 0x8($v0)
    /* B76D0 002B6AD0 8C820060 */  lw         $v0, 0x60($a0)
    /* B76D4 002B6AD4 00621021 */  addu       $v0, $v1, $v0
    /* B76D8 002B6AD8 A040000B */  sb         $zero, 0xB($v0)
    /* B76DC 002B6ADC 8C820060 */  lw         $v0, 0x60($a0)
    /* B76E0 002B6AE0 00621021 */  addu       $v0, $v1, $v0
    /* B76E4 002B6AE4 A4460004 */  sh         $a2, 0x4($v0)
    /* B76E8 002B6AE8 8C820060 */  lw         $v0, 0x60($a0)
    /* B76EC 002B6AEC 00621821 */  addu       $v1, $v1, $v0
    /* B76F0 002B6AF0 E460000C */  swc1       $fv0, 0xC($v1)
    /* B76F4 002B6AF4 90820034 */  lbu        $v0, 0x34($a0)
    /* B76F8 002B6AF8 24A50001 */  addiu      $a1, $a1, 0x1
    /* B76FC 002B6AFC 00A2102A */  slt        $v0, $a1, $v0
    /* B7700 002B6B00 1440FFE0 */  bnez       $v0, .L002B6A84
    /* B7704 002B6B04 00000000 */   nop
  .L002B6B08:
    /* B7708 002B6B08 03E00008 */  jr         $ra
    /* B770C 002B6B0C 00000000 */   nop
endlabel func_002B6A60
