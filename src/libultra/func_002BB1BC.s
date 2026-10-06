.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBBDBC-0xBBF2C (VRAM 0x002BB1BC) */
glabel func_002BB1BC
    /* BBDBC 002BB1BC 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* BBDC0 002BB1C0 AFB7002C */  sw         $s7, 0x2C($sp)
    /* BBDC4 002BB1C4 0080B821 */  addu       $s7, $a0, $zero
    /* BBDC8 002BB1C8 AFB50024 */  sw         $s5, 0x24($sp)
    /* BBDCC 002BB1CC 8FB50048 */  lw         $s5, 0x48($sp)
    /* BBDD0 002BB1D0 00A02021 */  addu       $a0, $a1, $zero
    /* BBDD4 002BB1D4 AFB60028 */  sw         $s6, 0x28($sp)
    /* BBDD8 002BB1D8 00C0B021 */  addu       $s6, $a2, $zero
    /* BBDDC 002BB1DC AFBE0030 */  sw         $fp, 0x30($sp)
    /* BBDE0 002BB1E0 00E0F021 */  addu       $fp, $a3, $zero
    /* BBDE4 002BB1E4 AFBF0034 */  sw         $ra, 0x34($sp)
    /* BBDE8 002BB1E8 AFB40020 */  sw         $s4, 0x20($sp)
    /* BBDEC 002BB1EC AFB3001C */  sw         $s3, 0x1C($sp)
    /* BBDF0 002BB1F0 AFB20018 */  sw         $s2, 0x18($sp)
    /* BBDF4 002BB1F4 AFB10014 */  sw         $s1, 0x14($sp)
    /* BBDF8 002BB1F8 AFB00010 */  sw         $s0, 0x10($sp)
    /* BBDFC 002BB1FC 8EE3001C */  lw         $v1, 0x1C($s7)
    /* BBE00 002BB200 8EE20014 */  lw         $v0, 0x14($s7)
    /* BBE04 002BB204 00031840 */  sll        $v1, $v1, 1
    /* BBE08 002BB208 00432821 */  addu       $a1, $v0, $v1
    /* BBE0C 002BB20C 0082102B */  sltu       $v0, $a0, $v0
    /* BBE10 002BB210 10400002 */  beqz       $v0, .L002BB21C
    /* BBE14 002BB214 02A03021 */   addu      $a2, $s5, $zero
    /* BBE18 002BB218 00832021 */  addu       $a0, $a0, $v1
  .L002BB21C:
    /* BBE1C 002BB21C 001E3840 */  sll        $a3, $fp, 1
    /* BBE20 002BB220 00878821 */  addu       $s1, $a0, $a3
    /* BBE24 002BB224 00B1102B */  sltu       $v0, $a1, $s1
    /* BBE28 002BB228 10400020 */  beqz       $v0, .L002BB2AC
    /* BBE2C 002BB22C 32C2FFFF */   andi      $v0, $s6, 0xFFFF
    /* BBE30 002BB230 26B50008 */  addiu      $s5, $s5, 0x8
    /* BBE34 002BB234 02A0A021 */  addu       $s4, $s5, $zero
    /* BBE38 002BB238 26B50008 */  addiu      $s5, $s5, 0x8
    /* BBE3C 002BB23C 3C130800 */  lui        $s3, (0x8000000 >> 16)
    /* BBE40 002BB240 00531025 */  or         $v0, $v0, $s3
    /* BBE44 002BB244 00A48023 */  subu       $s0, $a1, $a0
    /* BBE48 002BB248 00108043 */  sra        $s0, $s0, 1
    /* BBE4C 002BB24C 00108040 */  sll        $s0, $s0, 1
    /* BBE50 002BB250 ACC20000 */  sw         $v0, 0x0($a2)
    /* BBE54 002BB254 3202FFFF */  andi       $v0, $s0, 0xFFFF
    /* BBE58 002BB258 3C120400 */  lui        $s2, (0x4000000 >> 16)
    /* BBE5C 002BB25C 02258823 */  subu       $s1, $s1, $a1
    /* BBE60 002BB260 00118843 */  sra        $s1, $s1, 1
    /* BBE64 002BB264 ACC20004 */  sw         $v0, 0x4($a2)
    /* BBE68 002BB268 0C0B032C */  jal        osVirtualToPhysical
    /* BBE6C 002BB26C AE920000 */   sw        $s2, 0x0($s4)
    /* BBE70 002BB270 02A01821 */  addu       $v1, $s5, $zero
    /* BBE74 002BB274 26B50008 */  addiu      $s5, $s5, 0x8
    /* BBE78 002BB278 02D08021 */  addu       $s0, $s6, $s0
    /* BBE7C 002BB27C 3210FFFF */  andi       $s0, $s0, 0xFFFF
    /* BBE80 002BB280 02138025 */  or         $s0, $s0, $s3
    /* BBE84 002BB284 00118840 */  sll        $s1, $s1, 1
    /* BBE88 002BB288 3231FFFF */  andi       $s1, $s1, 0xFFFF
    /* BBE8C 002BB28C AE820004 */  sw         $v0, 0x4($s4)
    /* BBE90 002BB290 AC700000 */  sw         $s0, 0x0($v1)
    /* BBE94 002BB294 02A08021 */  addu       $s0, $s5, $zero
    /* BBE98 002BB298 AC710004 */  sw         $s1, 0x4($v1)
    /* BBE9C 002BB29C AE120000 */  sw         $s2, 0x0($s0)
    /* BBEA0 002BB2A0 8EE40014 */  lw         $a0, 0x14($s7)
    /* BBEA4 002BB2A4 080AECB5 */  j          .L002BB2D4
    /* BBEA8 002BB2A8 26B50008 */   addiu     $s5, $s5, 0x8
  .L002BB2AC:
    /* BBEAC 002BB2AC 26B50008 */  addiu      $s5, $s5, 0x8
    /* BBEB0 002BB2B0 02A08021 */  addu       $s0, $s5, $zero
    /* BBEB4 002BB2B4 26B50008 */  addiu      $s5, $s5, 0x8
    /* BBEB8 002BB2B8 3C030800 */  lui        $v1, (0x8000000 >> 16)
    /* BBEBC 002BB2BC 00431025 */  or         $v0, $v0, $v1
    /* BBEC0 002BB2C0 ACC20000 */  sw         $v0, 0x0($a2)
    /* BBEC4 002BB2C4 30E2FFFF */  andi       $v0, $a3, 0xFFFF
    /* BBEC8 002BB2C8 ACC20004 */  sw         $v0, 0x4($a2)
    /* BBECC 002BB2CC 3C020400 */  lui        $v0, (0x4000000 >> 16)
    /* BBED0 002BB2D0 AE020000 */  sw         $v0, 0x0($s0)
  .L002BB2D4:
    /* BBED4 002BB2D4 0C0B032C */  jal        osVirtualToPhysical
    /* BBED8 002BB2D8 00000000 */   nop
    /* BBEDC 002BB2DC AE020004 */  sw         $v0, 0x4($s0)
    /* BBEE0 002BB2E0 26A20008 */  addiu      $v0, $s5, 0x8
    /* BBEE4 002BB2E4 02A02021 */  addu       $a0, $s5, $zero
    /* BBEE8 002BB2E8 3C030800 */  lui        $v1, (0x8000000 >> 16)
    /* BBEEC 002BB2EC AC830000 */  sw         $v1, 0x0($a0)
    /* BBEF0 002BB2F0 001E1840 */  sll        $v1, $fp, 1
    /* BBEF4 002BB2F4 3063FFFF */  andi       $v1, $v1, 0xFFFF
    /* BBEF8 002BB2F8 AC830004 */  sw         $v1, 0x4($a0)
    /* BBEFC 002BB2FC 8FBF0034 */  lw         $ra, 0x34($sp)
    /* BBF00 002BB300 8FBE0030 */  lw         $fp, 0x30($sp)
    /* BBF04 002BB304 8FB7002C */  lw         $s7, 0x2C($sp)
    /* BBF08 002BB308 8FB60028 */  lw         $s6, 0x28($sp)
    /* BBF0C 002BB30C 8FB50024 */  lw         $s5, 0x24($sp)
    /* BBF10 002BB310 8FB40020 */  lw         $s4, 0x20($sp)
    /* BBF14 002BB314 8FB3001C */  lw         $s3, 0x1C($sp)
    /* BBF18 002BB318 8FB20018 */  lw         $s2, 0x18($sp)
    /* BBF1C 002BB31C 8FB10014 */  lw         $s1, 0x14($sp)
    /* BBF20 002BB320 8FB00010 */  lw         $s0, 0x10($sp)
    /* BBF24 002BB324 03E00008 */  jr         $ra
    /* BBF28 002BB328 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel func_002BB1BC
