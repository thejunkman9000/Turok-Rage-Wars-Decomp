.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB75B4-0xB7660 (VRAM 0x002B69B4) */
glabel __initFromBank
    /* B75B4 002B69B4 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B75B8 002B69B8 AFB20018 */  sw         $s2, 0x18($sp)
    /* B75BC 002B69BC 00809021 */  addu       $s2, $a0, $zero
    /* B75C0 002B69C0 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B75C4 002B69C4 00A09821 */  addu       $s3, $a1, $zero
    /* B75C8 002B69C8 02601021 */  addu       $v0, $s3, $zero
    /* B75CC 002B69CC AFBF0020 */  sw         $ra, 0x20($sp)
    /* B75D0 002B69D0 AFB10014 */  sw         $s1, 0x14($sp)
    /* B75D4 002B69D4 AFB00010 */  sw         $s0, 0x10($sp)
  .L002B69D8:
    /* B75D8 002B69D8 8C51000C */  lw         $s1, 0xC($v0)
    /* B75DC 002B69DC 1220FFFE */  beqz       $s1, .L002B69D8
    /* B75E0 002B69E0 24420004 */   addiu     $v0, $v0, 0x4
    /* B75E4 002B69E4 92420034 */  lbu        $v0, 0x34($s2)
    /* B75E8 002B69E8 1040000D */  beqz       $v0, .L002B6A20
    /* B75EC 002B69EC 00008021 */   addu      $s0, $zero, $zero
    /* B75F0 002B69F0 02402021 */  addu       $a0, $s2, $zero
  .L002B69F4:
    /* B75F4 002B69F4 0C0ADAC4 */  jal        __resetPerfChanState
    /* B75F8 002B69F8 02002821 */   addu      $a1, $s0, $zero
    /* B75FC 002B69FC 02402021 */  addu       $a0, $s2, $zero
    /* B7600 002B6A00 02202821 */  addu       $a1, $s1, $zero
    /* B7604 002B6A04 0C0ADAE4 */  jal        __setInstChanState
    /* B7608 002B6A08 02003021 */   addu      $a2, $s0, $zero
    /* B760C 002B6A0C 92420034 */  lbu        $v0, 0x34($s2)
    /* B7610 002B6A10 26100001 */  addiu      $s0, $s0, 0x1
    /* B7614 002B6A14 0202102A */  slt        $v0, $s0, $v0
    /* B7618 002B6A18 1440FFF6 */  bnez       $v0, .L002B69F4
    /* B761C 002B6A1C 02402021 */   addu      $a0, $s2, $zero
  .L002B6A20:
    /* B7620 002B6A20 8E620008 */  lw         $v0, 0x8($s3)
    /* B7624 002B6A24 10400007 */  beqz       $v0, .L002B6A44
    /* B7628 002B6A28 02402021 */   addu      $a0, $s2, $zero
    /* B762C 002B6A2C 0C0ADAC4 */  jal        __resetPerfChanState
    /* B7630 002B6A30 02002821 */   addu      $a1, $s0, $zero
    /* B7634 002B6A34 02402021 */  addu       $a0, $s2, $zero
    /* B7638 002B6A38 8E650008 */  lw         $a1, 0x8($s3)
    /* B763C 002B6A3C 0C0ADAE4 */  jal        __setInstChanState
    /* B7640 002B6A40 24060009 */   addiu     $a2, $zero, 0x9
  .L002B6A44:
    /* B7644 002B6A44 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B7648 002B6A48 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B764C 002B6A4C 8FB20018 */  lw         $s2, 0x18($sp)
    /* B7650 002B6A50 8FB10014 */  lw         $s1, 0x14($sp)
    /* B7654 002B6A54 8FB00010 */  lw         $s0, 0x10($sp)
    /* B7658 002B6A58 03E00008 */  jr         $ra
    /* B765C 002B6A5C 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel __initFromBank
