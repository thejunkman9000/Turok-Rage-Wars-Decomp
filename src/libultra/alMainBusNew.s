.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBA180-0xBA1DC (VRAM 0x002B9580) */
glabel alMainBusNew
    /* BA180 002B9580 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* BA184 002B9584 AFB00010 */  sw         $s0, 0x10($sp)
    /* BA188 002B9588 00808021 */  addu       $s0, $a0, $zero
    /* BA18C 002B958C AFB20018 */  sw         $s2, 0x18($sp)
    /* BA190 002B9590 00A09021 */  addu       $s2, $a1, $zero
    /* BA194 002B9594 AFB10014 */  sw         $s1, 0x14($sp)
    /* BA198 002B9598 00C08821 */  addu       $s1, $a2, $zero
    /* BA19C 002B959C 3C05002C */  lui        $a1, %hi(alMainBusPull + 0xC)
    /* BA1A0 002B95A0 24A58ED0 */  addiu      $a1, $a1, %lo(alMainBusPull + 0xC)
    /* BA1A4 002B95A4 3C06002C */  lui        $a2, %hi(alMainBusParam)
    /* BA1A8 002B95A8 24C68FAC */  addiu      $a2, $a2, %lo(alMainBusParam)
    /* BA1AC 002B95AC AFBF001C */  sw         $ra, 0x1C($sp)
    /* BA1B0 002B95B0 0C0AE92C */  jal        alFilterNew
    /* BA1B4 002B95B4 24070006 */   addiu     $a3, $zero, 0x6
    /* BA1B8 002B95B8 AE000014 */  sw         $zero, 0x14($s0)
    /* BA1BC 002B95BC AE110018 */  sw         $s1, 0x18($s0)
    /* BA1C0 002B95C0 AE12001C */  sw         $s2, 0x1C($s0)
    /* BA1C4 002B95C4 8FBF001C */  lw         $ra, 0x1C($sp)
    /* BA1C8 002B95C8 8FB20018 */  lw         $s2, 0x18($sp)
    /* BA1CC 002B95CC 8FB10014 */  lw         $s1, 0x14($sp)
    /* BA1D0 002B95D0 8FB00010 */  lw         $s0, 0x10($sp)
    /* BA1D4 002B95D4 03E00008 */  jr         $ra
    /* BA1D8 002B95D8 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel alMainBusNew
