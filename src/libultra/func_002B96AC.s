.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBA2AC-0xBA35C (VRAM 0x002B96AC) */
glabel func_002B96AC
    /* BA2AC 002B96AC 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* BA2B0 002B96B0 AFB00018 */  sw         $s0, 0x18($sp)
    /* BA2B4 002B96B4 00808021 */  addu       $s0, $a0, $zero
    /* BA2B8 002B96B8 AFB1001C */  sw         $s1, 0x1C($sp)
    /* BA2BC 002B96BC 00A08821 */  addu       $s1, $a1, $zero
    /* BA2C0 002B96C0 3C05002C */  lui        $a1, %hi(func_002B9800)
    /* BA2C4 002B96C4 24A59800 */  addiu      $a1, $a1, %lo(func_002B9800)
    /* BA2C8 002B96C8 3C06002C */  lui        $a2, %hi(func_002BA288)
    /* BA2CC 002B96CC 24C6A288 */  addiu      $a2, $a2, %lo(func_002BA288)
    /* BA2D0 002B96D0 AFBF0020 */  sw         $ra, 0x20($sp)
    /* BA2D4 002B96D4 0C0AE92C */  jal        func_002BA4B0
    /* BA2D8 002B96D8 24070004 */   addiu     $a3, $zero, 0x4
    /* BA2DC 002B96DC 00002021 */  addu       $a0, $zero, $zero
    /* BA2E0 002B96E0 00802821 */  addu       $a1, $a0, $zero
    /* BA2E4 002B96E4 02203021 */  addu       $a2, $s1, $zero
    /* BA2E8 002B96E8 24070001 */  addiu      $a3, $zero, 0x1
    /* BA2EC 002B96EC 24020050 */  addiu      $v0, $zero, 0x50
    /* BA2F0 002B96F0 0C0AD504 */  jal        func_002B5410
    /* BA2F4 002B96F4 AFA20010 */   sw        $v0, 0x10($sp)
    /* BA2F8 002B96F8 AE020014 */  sw         $v0, 0x14($s0)
    /* BA2FC 002B96FC 24020001 */  addiu      $v0, $zero, 0x1
    /* BA300 002B9700 AE020038 */  sw         $v0, 0x38($s0)
    /* BA304 002B9704 AE000048 */  sw         $zero, 0x48($s0)
    /* BA308 002B9708 A602001A */  sh         $v0, 0x1A($s0)
    /* BA30C 002B970C A6020028 */  sh         $v0, 0x28($s0)
    /* BA310 002B9710 A602002E */  sh         $v0, 0x2E($s0)
    /* BA314 002B9714 A602001C */  sh         $v0, 0x1C($s0)
    /* BA318 002B9718 A602001E */  sh         $v0, 0x1E($s0)
    /* BA31C 002B971C A6000020 */  sh         $zero, 0x20($s0)
    /* BA320 002B9720 A6000022 */  sh         $zero, 0x22($s0)
    /* BA324 002B9724 A6020026 */  sh         $v0, 0x26($s0)
    /* BA328 002B9728 A6000024 */  sh         $zero, 0x24($s0)
    /* BA32C 002B972C A6000024 */  sh         $zero, 0x24($s0)
    /* BA330 002B9730 AE000030 */  sw         $zero, 0x30($s0)
    /* BA334 002B9734 AE000034 */  sw         $zero, 0x34($s0)
    /* BA338 002B9738 A6000018 */  sh         $zero, 0x18($s0)
    /* BA33C 002B973C AE00003C */  sw         $zero, 0x3C($s0)
    /* BA340 002B9740 AE000040 */  sw         $zero, 0x40($s0)
    /* BA344 002B9744 AE000044 */  sw         $zero, 0x44($s0)
    /* BA348 002B9748 8FBF0020 */  lw         $ra, 0x20($sp)
    /* BA34C 002B974C 8FB1001C */  lw         $s1, 0x1C($sp)
    /* BA350 002B9750 8FB00018 */  lw         $s0, 0x18($sp)
    /* BA354 002B9754 03E00008 */  jr         $ra
    /* BA358 002B9758 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B96AC
