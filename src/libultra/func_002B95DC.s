.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBA1DC-0xBA268 (VRAM 0x002B95DC) */
glabel func_002B95DC
    /* BA1DC 002B95DC 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* BA1E0 002B95E0 AFB00018 */  sw         $s0, 0x18($sp)
    /* BA1E4 002B95E4 00808021 */  addu       $s0, $a0, $zero
    /* BA1E8 002B95E8 AFB1001C */  sw         $s1, 0x1C($sp)
    /* BA1EC 002B95EC 00A08821 */  addu       $s1, $a1, $zero
    /* BA1F0 002B95F0 3C05002C */  lui        $a1, %hi(func_002BA640)
    /* BA1F4 002B95F4 24A5A640 */  addiu      $a1, $a1, %lo(func_002BA640)
    /* BA1F8 002B95F8 3C06002C */  lui        $a2, %hi(func_002BA800)
    /* BA1FC 002B95FC 24C6A800 */  addiu      $a2, $a2, %lo(func_002BA800)
    /* BA200 002B9600 AFBF0020 */  sw         $ra, 0x20($sp)
    /* BA204 002B9604 0C0AE92C */  jal        func_002BA4B0
    /* BA208 002B9608 24070001 */   addiu     $a3, $zero, 0x1
    /* BA20C 002B960C 00002021 */  addu       $a0, $zero, $zero
    /* BA210 002B9610 00802821 */  addu       $a1, $a0, $zero
    /* BA214 002B9614 02203021 */  addu       $a2, $s1, $zero
    /* BA218 002B9618 24070001 */  addiu      $a3, $zero, 0x1
    /* BA21C 002B961C 24020020 */  addiu      $v0, $zero, 0x20
    /* BA220 002B9620 0C0AD504 */  jal        func_002B5410
    /* BA224 002B9624 AFA20010 */   sw        $v0, 0x10($sp)
    /* BA228 002B9628 3C01800D */  lui        $at, %hi(D_800CC830)
    /* BA22C 002B962C C420C830 */  lwc1       $fv0, %lo(D_800CC830)($at)
    /* BA230 002B9630 AE020014 */  sw         $v0, 0x14($s0)
    /* BA234 002B9634 24020001 */  addiu      $v0, $zero, 0x1
    /* BA238 002B9638 AE000020 */  sw         $zero, 0x20($s0)
    /* BA23C 002B963C AE020024 */  sw         $v0, 0x24($s0)
    /* BA240 002B9640 AE000030 */  sw         $zero, 0x30($s0)
    /* BA244 002B9644 AE00001C */  sw         $zero, 0x1C($s0)
    /* BA248 002B9648 AE000028 */  sw         $zero, 0x28($s0)
    /* BA24C 002B964C AE00002C */  sw         $zero, 0x2C($s0)
    /* BA250 002B9650 E6000018 */  swc1       $fv0, 0x18($s0)
    /* BA254 002B9654 8FBF0020 */  lw         $ra, 0x20($sp)
    /* BA258 002B9658 8FB1001C */  lw         $s1, 0x1C($sp)
    /* BA25C 002B965C 8FB00018 */  lw         $s0, 0x18($sp)
    /* BA260 002B9660 03E00008 */  jr         $ra
    /* BA264 002B9664 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B95DC
