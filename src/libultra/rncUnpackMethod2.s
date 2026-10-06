.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB3610-0xB36BC (VRAM 0x002B2A10) */
glabel rncUnpackMethod2
    /* B3610 002B2A10 23BDFFB8 */  addi       $sp, $sp, -0x48 /* handwritten instruction */
    /* B3614 002B2A14 AFA40000 */  sw         $a0, 0x0($sp)
    /* B3618 002B2A18 AFA50004 */  sw         $a1, 0x4($sp)
    /* B361C 002B2A1C AFA60008 */  sw         $a2, 0x8($sp)
    /* B3620 002B2A20 AFA7000C */  sw         $a3, 0xC($sp)
    /* B3624 002B2A24 AFA80010 */  sw         $t0, 0x10($sp)
    /* B3628 002B2A28 AFA90014 */  sw         $t1, 0x14($sp)
    /* B362C 002B2A2C AFAA0018 */  sw         $t2, 0x18($sp)
    /* B3630 002B2A30 AFAB001C */  sw         $t3, 0x1C($sp)
    /* B3634 002B2A34 AFAC0020 */  sw         $t4, 0x20($sp)
    /* B3638 002B2A38 AFAD0024 */  sw         $t5, 0x24($sp)
    /* B363C 002B2A3C AFAE0028 */  sw         $t6, 0x28($sp)
    /* B3640 002B2A40 AFAF002C */  sw         $t7, 0x2C($sp)
    /* B3644 002B2A44 AFB00030 */  sw         $s0, 0x30($sp)
    /* B3648 002B2A48 AFB10034 */  sw         $s1, 0x34($sp)
    /* B364C 002B2A4C AFB20038 */  sw         $s2, 0x38($sp)
    /* B3650 002B2A50 AFB3003C */  sw         $s3, 0x3C($sp)
    /* B3654 002B2A54 AFBF0040 */  sw         $ra, 0x40($sp)
    /* B3658 002B2A58 3C0C002B */  lui        $t4, %hi(D_002B2AB8)
    /* B365C 002B2A5C 258C2AB8 */  addiu      $t4, $t4, %lo(D_002B2AB8)
    /* B3660 002B2A60 00000000 */  nop
    /* B3664 002B2A64 0180F809 */  jalr       $t4
    /* B3668 002B2A68 00000000 */   nop
    /* B366C 002B2A6C 8FA40000 */  lw         $a0, 0x0($sp)
    /* B3670 002B2A70 8FA50004 */  lw         $a1, 0x4($sp)
    /* B3674 002B2A74 8FA60008 */  lw         $a2, 0x8($sp)
    /* B3678 002B2A78 8FA7000C */  lw         $a3, 0xC($sp)
    /* B367C 002B2A7C 8FA80010 */  lw         $t0, 0x10($sp)
    /* B3680 002B2A80 8FA90014 */  lw         $t1, 0x14($sp)
    /* B3684 002B2A84 8FAA0018 */  lw         $t2, 0x18($sp)
    /* B3688 002B2A88 8FAB001C */  lw         $t3, 0x1C($sp)
    /* B368C 002B2A8C 8FAC0020 */  lw         $t4, 0x20($sp)
    /* B3690 002B2A90 8FAD0024 */  lw         $t5, 0x24($sp)
    /* B3694 002B2A94 8FAE0028 */  lw         $t6, 0x28($sp)
    /* B3698 002B2A98 8FAF002C */  lw         $t7, 0x2C($sp)
    /* B369C 002B2A9C 8FB00030 */  lw         $s0, 0x30($sp)
    /* B36A0 002B2AA0 8FB10034 */  lw         $s1, 0x34($sp)
    /* B36A4 002B2AA4 8FB20038 */  lw         $s2, 0x38($sp)
    /* B36A8 002B2AA8 8FB3003C */  lw         $s3, 0x3C($sp)
    /* B36AC 002B2AAC 8FBF0040 */  lw         $ra, 0x40($sp)
    /* B36B0 002B2AB0 23BD0048 */  addi       $sp, $sp, 0x48 /* handwritten instruction */
    /* B36B4 002B2AB4 03E00008 */  jr         $ra
  alabel D_002B2AB8
    /* B36B8 002B2AB8 00807021 */   addu      $t6, $a0, $zero
endlabel rncUnpackMethod2
