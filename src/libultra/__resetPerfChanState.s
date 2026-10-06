.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7710-0xB7790 (VRAM 0x002B6B10) */
glabel __resetPerfChanState
    /* B7710 002B6B10 8C820060 */  lw         $v0, 0x60($a0)
    /* B7714 002B6B14 00052900 */  sll        $a1, $a1, 4
    /* B7718 002B6B18 00A21021 */  addu       $v0, $a1, $v0
    /* B771C 002B6B1C A0400006 */  sb         $zero, 0x6($v0)
    /* B7720 002B6B20 8C820060 */  lw         $v0, 0x60($a0)
    /* B7724 002B6B24 00A21021 */  addu       $v0, $a1, $v0
    /* B7728 002B6B28 A040000A */  sb         $zero, 0xA($v0)
    /* B772C 002B6B2C 8C820060 */  lw         $v0, 0x60($a0)
    /* B7730 002B6B30 24030040 */  addiu      $v1, $zero, 0x40
    /* B7734 002B6B34 00A21021 */  addu       $v0, $a1, $v0
    /* B7738 002B6B38 A0430007 */  sb         $v1, 0x7($v0)
    /* B773C 002B6B3C 8C820060 */  lw         $v0, 0x60($a0)
    /* B7740 002B6B40 2403007F */  addiu      $v1, $zero, 0x7F
    /* B7744 002B6B44 00A21021 */  addu       $v0, $a1, $v0
    /* B7748 002B6B48 A0430009 */  sb         $v1, 0x9($v0)
    /* B774C 002B6B4C 8C820060 */  lw         $v0, 0x60($a0)
    /* B7750 002B6B50 24030005 */  addiu      $v1, $zero, 0x5
    /* B7754 002B6B54 00A21021 */  addu       $v0, $a1, $v0
    /* B7758 002B6B58 A0430008 */  sb         $v1, 0x8($v0)
    /* B775C 002B6B5C 8C820060 */  lw         $v0, 0x60($a0)
    /* B7760 002B6B60 00A21021 */  addu       $v0, $a1, $v0
    /* B7764 002B6B64 A040000B */  sb         $zero, 0xB($v0)
    /* B7768 002B6B68 8C820060 */  lw         $v0, 0x60($a0)
    /* B776C 002B6B6C 240300C8 */  addiu      $v1, $zero, 0xC8
    /* B7770 002B6B70 00A21021 */  addu       $v0, $a1, $v0
    /* B7774 002B6B74 A4430004 */  sh         $v1, 0x4($v0)
    /* B7778 002B6B78 8C820060 */  lw         $v0, 0x60($a0)
    /* B777C 002B6B7C 3C01800D */  lui        $at, %hi(D_800CC720)
    /* B7780 002B6B80 C420C720 */  lwc1       $fv0, %lo(D_800CC720)($at)
    /* B7784 002B6B84 00A22821 */  addu       $a1, $a1, $v0
    /* B7788 002B6B88 03E00008 */  jr         $ra
    /* B778C 002B6B8C E4A0000C */   swc1      $fv0, 0xC($a1)
endlabel __resetPerfChanState
