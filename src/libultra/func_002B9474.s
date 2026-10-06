.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBA074-0xBA124 (VRAM 0x002B9474) */
glabel func_002B9474
    /* BA074 002B9474 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* BA078 002B9478 AFB00018 */  sw         $s0, 0x18($sp)
    /* BA07C 002B947C 00808021 */  addu       $s0, $a0, $zero
    /* BA080 002B9480 AFB30024 */  sw         $s3, 0x24($sp)
    /* BA084 002B9484 00A09821 */  addu       $s3, $a1, $zero
    /* BA088 002B9488 AFB20020 */  sw         $s2, 0x20($sp)
    /* BA08C 002B948C 00C09021 */  addu       $s2, $a2, $zero
    /* BA090 002B9490 3C05002C */  lui        $a1, %hi(D_002C31C0)
    /* BA094 002B9494 24A531C0 */  addiu      $a1, $a1, %lo(D_002C31C0)
    /* BA098 002B9498 3C06002C */  lui        $a2, %hi(func_002C3B94)
    /* BA09C 002B949C 24C63B94 */  addiu      $a2, $a2, %lo(func_002C3B94)
    /* BA0A0 002B94A0 00003821 */  addu       $a3, $zero, $zero
    /* BA0A4 002B94A4 AFBF0028 */  sw         $ra, 0x28($sp)
    /* BA0A8 002B94A8 0C0AE92C */  jal        func_002BA4B0
    /* BA0AC 002B94AC AFB1001C */   sw        $s1, 0x1C($sp)
    /* BA0B0 002B94B0 00002021 */  addu       $a0, $zero, $zero
    /* BA0B4 002B94B4 00802821 */  addu       $a1, $a0, $zero
    /* BA0B8 002B94B8 02403021 */  addu       $a2, $s2, $zero
    /* BA0BC 002B94BC 24070001 */  addiu      $a3, $zero, 0x1
    /* BA0C0 002B94C0 24110020 */  addiu      $s1, $zero, 0x20
    /* BA0C4 002B94C4 0C0AD504 */  jal        func_002B5410
    /* BA0C8 002B94C8 AFB10010 */   sw        $s1, 0x10($sp)
    /* BA0CC 002B94CC 00002021 */  addu       $a0, $zero, $zero
    /* BA0D0 002B94D0 00802821 */  addu       $a1, $a0, $zero
    /* BA0D4 002B94D4 02403021 */  addu       $a2, $s2, $zero
    /* BA0D8 002B94D8 24070001 */  addiu      $a3, $zero, 0x1
    /* BA0DC 002B94DC AE020014 */  sw         $v0, 0x14($s0)
    /* BA0E0 002B94E0 0C0AD504 */  jal        func_002B5410
    /* BA0E4 002B94E4 AFB10010 */   sw        $s1, 0x10($sp)
    /* BA0E8 002B94E8 26040034 */  addiu      $a0, $s0, 0x34
    /* BA0EC 002B94EC 0260F809 */  jalr       $s3
    /* BA0F0 002B94F0 AE020018 */   sw        $v0, 0x18($s0)
    /* BA0F4 002B94F4 AE020030 */  sw         $v0, 0x30($s0)
    /* BA0F8 002B94F8 24020001 */  addiu      $v0, $zero, 0x1
    /* BA0FC 002B94FC AE00003C */  sw         $zero, 0x3C($s0)
    /* BA100 002B9500 AE020040 */  sw         $v0, 0x40($s0)
    /* BA104 002B9504 AE000044 */  sw         $zero, 0x44($s0)
    /* BA108 002B9508 8FBF0028 */  lw         $ra, 0x28($sp)
    /* BA10C 002B950C 8FB30024 */  lw         $s3, 0x24($sp)
    /* BA110 002B9510 8FB20020 */  lw         $s2, 0x20($sp)
    /* BA114 002B9514 8FB1001C */  lw         $s1, 0x1C($sp)
    /* BA118 002B9518 8FB00018 */  lw         $s0, 0x18($sp)
    /* BA11C 002B951C 03E00008 */  jr         $ra
    /* BA120 002B9520 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_002B9474
