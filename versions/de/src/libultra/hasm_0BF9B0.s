.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBF9B0-0xC0E2C (VRAM 0x002BEDB0) */
.globl adecReadBits
adecReadBits:
    /* BF9B0 002BEDB0 27BDFFF8 */  addiu      $sp, $sp, -0x8
    /* BF9B4 002BEDB4 AFB10004 */  sw         $s1, 0x4($sp)
    /* BF9B8 002BEDB8 00808821 */  addu       $s1, $a0, $zero
    /* BF9BC 002BEDBC 3C04800D */  lui        $a0, %hi(D_auto_800D54B8)
    /* BF9C0 002BEDC0 248454B8 */  addiu      $a0, $a0, %lo(D_auto_800D54B8)
    /* BF9C4 002BEDC4 AFB00000 */  sw         $s0, 0x0($sp)
    /* BF9C8 002BEDC8 94820000 */  lhu        $v0, 0x0($a0)
    /* BF9CC 002BEDCC 8FB90018 */  lw         $t9, 0x18($sp)
    /* BF9D0 002BEDD0 1440000B */  .word 0x1440000B
    /* BF9D4 002BEDD4 30C2FFFF */  andi      $v0, $a2, 0xFFFF
    /* BF9D8 002BEDD8 8F220014 */  lw         $v0, 0x14($t9)
    /* BF9DC 002BEDDC 94430000 */  lhu        $v1, 0x0($v0)
    /* BF9E0 002BEDE0 24420002 */  addiu      $v0, $v0, 0x2
    /* BF9E4 002BEDE4 AF220014 */  sw         $v0, 0x14($t9)
    /* BF9E8 002BEDE8 24020010 */  addiu      $v0, $zero, 0x10
    /* BF9EC 002BEDEC A4820000 */  sh         $v0, 0x0($a0)
    /* BF9F0 002BEDF0 3C028015 */  lui        $v0, %hi(D_auto_8014AE00)
    /* BF9F4 002BEDF4 2442AE00 */  addiu      $v0, $v0, %lo(D_auto_8014AE00)
    /* BF9F8 002BEDF8 A4430000 */  sh         $v1, 0x0($v0)
    /* BF9FC 002BEDFC 30C2FFFF */  andi       $v0, $a2, 0xFFFF
.Lauto_002BEE00:
    /* BFA00 002BEE00 1040005B */  .word 0x1040005B
    /* BFA04 002BEE04 00004821 */  addu      $t1, $zero, $zero
    /* BFA08 002BEE08 00805021 */  addu       $t2, $a0, $zero
    /* BFA0C 002BEE0C 3C0B8015 */  lui        $t3, %hi(D_auto_8014AE00)
    /* BFA10 002BEE10 256BAE00 */  addiu      $t3, $t3, %lo(D_auto_8014AE00)
    /* BFA14 002BEE14 24100010 */  addiu      $s0, $zero, 0x10
    /* BFA18 002BEE18 02071004 */  sllv       $v0, $a3, $s0
    /* BFA1C 002BEE1C 02027807 */  srav       $t7, $v0, $s0
    /* BFA20 002BEE20 30ADFFFF */  andi       $t5, $a1, 0xFFFF
    /* BFA24 002BEE24 3C02800D */  lui        $v0, %hi(D_auto_800D5374)
    /* BFA28 002BEE28 24425374 */  addiu      $v0, $v0, %lo(D_auto_800D5374)
    /* BFA2C 002BEE2C 000D1840 */  sll        $v1, $t5, 1
    /* BFA30 002BEE30 00627021 */  addu       $t6, $v1, $v0
    /* BFA34 002BEE34 3C18800D */  lui        $t8, %hi(D_auto_800D5350)
    /* BFA38 002BEE38 27185350 */  addiu      $t8, $t8, %lo(D_auto_800D5350)
    /* BFA3C 002BEE3C 00786021 */  addu       $t4, $v1, $t8
.Lauto_002BEE40:
    /* BFA40 002BEE40 95430000 */  lhu        $v1, 0x0($t2)
    /* BFA44 002BEE44 006D102B */  sltu       $v0, $v1, $t5
    /* BFA48 002BEE48 10400029 */  .word 0x10400029
    /* BFA4C 002BEE4C 3064FFFF */  andi      $a0, $v1, 0xFFFF
    /* BFA50 002BEE50 00A34023 */  subu       $t0, $a1, $v1
    /* BFA54 002BEE54 00042040 */  sll        $a0, $a0, 1
    /* BFA58 002BEE58 00982021 */  addu       $a0, $a0, $t8
    /* BFA5C 002BEE5C 00091400 */  sll        $v0, $t1, 16
    /* BFA60 002BEE60 000213C3 */  sra        $v0, $v0, 15
    /* BFA64 002BEE64 95630000 */  lhu        $v1, 0x0($t3)
    /* BFA68 002BEE68 94840000 */  lhu        $a0, 0x0($a0)
    /* BFA6C 002BEE6C 00513821 */  addu       $a3, $v0, $s1
    /* BFA70 002BEE70 00641824 */  and        $v1, $v1, $a0
    /* BFA74 002BEE74 3104FFFF */  andi       $a0, $t0, 0xFFFF
    /* BFA78 002BEE78 00831804 */  sllv       $v1, $v1, $a0
    /* BFA7C 002BEE7C A4E30000 */  sh         $v1, 0x0($a3)
    /* BFA80 002BEE80 8F220014 */  lw         $v0, 0x14($t9)
    /* BFA84 002BEE84 94430000 */  lhu        $v1, 0x0($v0)
    /* BFA88 002BEE88 24420002 */  addiu      $v0, $v0, 0x2
    /* BFA8C 002BEE8C AF220014 */  sw         $v0, 0x14($t9)
    /* BFA90 002BEE90 02041023 */  subu       $v0, $s0, $a0
    /* BFA94 002BEE94 00042040 */  sll        $a0, $a0, 1
    /* BFA98 002BEE98 00982021 */  addu       $a0, $a0, $t8
    /* BFA9C 002BEE9C A5630000 */  sh         $v1, 0x0($t3)
    /* BFAA0 002BEEA0 3063FFFF */  andi       $v1, $v1, 0xFFFF
    /* BFAA4 002BEEA4 00431807 */  srav       $v1, $v1, $v0
    /* BFAA8 002BEEA8 94820000 */  lhu        $v0, 0x0($a0)
    /* BFAAC 002BEEAC 94E40000 */  lhu        $a0, 0x0($a3)
    /* BFAB0 002BEEB0 00621824 */  and        $v1, $v1, $v0
    /* BFAB4 002BEEB4 00832025 */  or         $a0, $a0, $v1
    /* BFAB8 002BEEB8 11E0000B */  .word 0x11E0000B
    /* BFABC 002BEEBC A4E40000 */  sh        $a0, 0x0($a3)
    /* BFAC0 002BEEC0 00041400 */  sll        $v0, $a0, 16
    /* BFAC4 002BEEC4 95C30000 */  lhu        $v1, 0x0($t6)
    /* BFAC8 002BEEC8 00021403 */  sra        $v0, $v0, 16
    /* BFACC 002BEECC 00431024 */  and        $v0, $v0, $v1
    /* BFAD0 002BEED0 5040001E */  .word 0x5040001E
    /* BFAD4 002BEED4 02081023 */  subu      $v0, $s0, $t0
    /* BFAD8 002BEED8 95820000 */  lhu        $v0, 0x0($t4)
    /* BFADC 002BEEDC 00021027 */  nor        $v0, $zero, $v0
    /* BFAE0 002BEEE0 00821025 */  or         $v0, $a0, $v0
    /* BFAE4 002BEEE4 A4E20000 */  sh         $v0, 0x0($a3)
.Lauto_002BEEE8:
    /* BFAE8 002BEEE8 080AFBD3 */  .word 0x080AFBD3
    /* BFAEC 002BEEEC 02081023 */  subu      $v0, $s0, $t0
.Lauto_002BEEF0:
    /* BFAF0 002BEEF0 95430000 */  lhu        $v1, 0x0($t2)
    /* BFAF4 002BEEF4 95620000 */  lhu        $v0, 0x0($t3)
    /* BFAF8 002BEEF8 95840000 */  lhu        $a0, 0x0($t4)
    /* BFAFC 002BEEFC 006D1823 */  subu       $v1, $v1, $t5
    /* BFB00 002BEF00 00621007 */  srav       $v0, $v0, $v1
    /* BFB04 002BEF04 00442024 */  and        $a0, $v0, $a0
    /* BFB08 002BEF08 00091400 */  sll        $v0, $t1, 16
    /* BFB0C 002BEF0C 000213C3 */  sra        $v0, $v0, 15
    /* BFB10 002BEF10 00513821 */  addu       $a3, $v0, $s1
    /* BFB14 002BEF14 11E0000B */  .word 0x11E0000B
    /* BFB18 002BEF18 A4E40000 */  sh        $a0, 0x0($a3)
    /* BFB1C 002BEF1C 00041400 */  sll        $v0, $a0, 16
    /* BFB20 002BEF20 95C30000 */  lhu        $v1, 0x0($t6)
    /* BFB24 002BEF24 00021403 */  sra        $v0, $v0, 16
    /* BFB28 002BEF28 00431024 */  and        $v0, $v0, $v1
    /* BFB2C 002BEF2C 10400005 */  .word 0x10400005
    /* BFB30 002BEF30 00000000 */  nop
    /* BFB34 002BEF34 95820000 */  lhu        $v0, 0x0($t4)
    /* BFB38 002BEF38 00021027 */  nor        $v0, $zero, $v0
    /* BFB3C 002BEF3C 00821025 */  or         $v0, $a0, $v0
    /* BFB40 002BEF40 A4E20000 */  sh         $v0, 0x0($a3)
.Lauto_002BEF44:
    /* BFB44 002BEF44 95420000 */  lhu        $v0, 0x0($t2)
    /* BFB48 002BEF48 00451023 */  subu       $v0, $v0, $a1
.Lauto_002BEF4C:
    /* BFB4C 002BEF4C A5420000 */  sh         $v0, 0x0($t2)
    /* BFB50 002BEF50 25220001 */  addiu      $v0, $t1, 0x1
    /* BFB54 002BEF54 00404821 */  addu       $t1, $v0, $zero
    /* BFB58 002BEF58 00021400 */  sll        $v0, $v0, 16
    /* BFB5C 002BEF5C 00021403 */  sra        $v0, $v0, 16
    /* BFB60 002BEF60 30C3FFFF */  andi       $v1, $a2, 0xFFFF
    /* BFB64 002BEF64 0043102A */  slt        $v0, $v0, $v1
    /* BFB68 002BEF68 1440FFB5 */  .word 0x1440FFB5
    /* BFB6C 002BEF6C 00000000 */  nop
.Lauto_002BEF70:
    /* BFB70 002BEF70 8FB10004 */  lw         $s1, 0x4($sp)
    /* BFB74 002BEF74 8FB00000 */  lw         $s0, 0x0($sp)
    /* BFB78 002BEF78 24020001 */  addiu      $v0, $zero, 0x1
    /* BFB7C 002BEF7C 03E00008 */  jr         $ra
    /* BFB80 002BEF80 27BD0008 */  addiu     $sp, $sp, 0x8
.globl adecHuffDecode
adecHuffDecode:
    /* BFB84 002BEF84 27BDFFA8 */  addiu      $sp, $sp, -0x58
    /* BFB88 002BEF88 00805021 */  addu       $t2, $a0, $zero
    /* BFB8C 002BEF8C 00A04821 */  addu       $t1, $a1, $zero
    /* BFB90 002BEF90 AFB50044 */  sw         $s5, 0x44($sp)
    /* BFB94 002BEF94 0000A821 */  addu       $s5, $zero, $zero
    /* BFB98 002BEF98 AFB20038 */  sw         $s2, 0x38($sp)
    /* BFB9C 002BEF9C 02A09021 */  addu       $s2, $s5, $zero
    /* BFBA0 002BEFA0 00E04021 */  addu       $t0, $a3, $zero
    /* BFBA4 002BEFA4 AFB10034 */  sw         $s1, 0x34($sp)
    /* BFBA8 002BEFA8 00061400 */  sll        $v0, $a2, 16
    /* BFBAC 002BEFAC AFBF0054 */  sw         $ra, 0x54($sp)
    /* BFBB0 002BEFB0 AFBE0050 */  sw         $fp, 0x50($sp)
    /* BFBB4 002BEFB4 AFB7004C */  sw         $s7, 0x4C($sp)
    /* BFBB8 002BEFB8 AFB60048 */  sw         $s6, 0x48($sp)
    /* BFBBC 002BEFBC AFB40040 */  sw         $s4, 0x40($sp)
    /* BFBC0 002BEFC0 AFB3003C */  sw         $s3, 0x3C($sp)
    /* BFBC4 002BEFC4 AFB00030 */  sw         $s0, 0x30($sp)
    /* BFBC8 002BEFC8 A5000000 */  sh         $zero, 0x0($t0)
    /* BFBCC 002BEFCC 8D530010 */  lw         $s3, 0x10($t2)
    /* BFBD0 002BEFD0 00021C03 */  sra        $v1, $v0, 16
    /* BFBD4 002BEFD4 8E740020 */  lw         $s4, 0x20($s3)
    /* BFBD8 002BEFD8 186000DD */  .word 0x186000DD
    /* BFBDC 002BEFDC 02A08821 */  addu      $s1, $s5, $zero
    /* BFBE0 002BEFE0 3C1E800D */  lui        $fp, %hi(D_auto_800D54BC)
    /* BFBE4 002BEFE4 27DE54BC */  addiu      $fp, $fp, %lo(D_auto_800D54BC)
    /* BFBE8 002BEFE8 3C17800D */  lui        $s7, %hi(D_auto_800D54BA)
    /* BFBEC 002BEFEC 26F754BA */  addiu      $s7, $s7, %lo(D_auto_800D54BA)
    /* BFBF0 002BEFF0 AFA20018 */  sw         $v0, 0x18($sp)
    /* BFBF4 002BEFF4 0060B021 */  addu       $s6, $v1, $zero
.Lauto_002BEFF8:
    /* BFBF8 002BEFF8 97C30000 */  lhu        $v1, 0x0($fp)
    /* BFBFC 002BEFFC 106000B9 */  .word 0x106000B9
    /* BFC00 002BF000 2463FFFF */  addiu     $v1, $v1, -0x1
    /* BFC04 002BF004 96E20000 */  lhu        $v0, 0x0($s7)
    /* BFC08 002BF008 A7C30000 */  sh         $v1, 0x0($fp)
    /* BFC0C 002BF00C 30438000 */  andi       $v1, $v0, 0x8000
    /* BFC10 002BF010 00021040 */  sll        $v0, $v0, 1
    /* BFC14 002BF014 10600007 */  .word 0x10600007
    /* BFC18 002BF018 A6E20000 */  sh        $v0, 0x0($s7)
    /* BFC1C 002BF01C 00151400 */  sll        $v0, $s5, 16
    /* BFC20 002BF020 00021383 */  sra        $v0, $v0, 14
    /* BFC24 002BF024 00541021 */  addu       $v0, $v0, $s4
    /* BFC28 002BF028 94440002 */  lhu        $a0, 0x2($v0)
    /* BFC2C 002BF02C 080AFC12 */  .word 0x080AFC12
    /* BFC30 002BF030 00041400 */  sll       $v0, $a0, 16
.Lauto_002BF034:
    /* BFC34 002BF034 00151400 */  sll        $v0, $s5, 16
    /* BFC38 002BF038 00021383 */  sra        $v0, $v0, 14
    /* BFC3C 002BF03C 00541021 */  addu       $v0, $v0, $s4
    /* BFC40 002BF040 94440000 */  lhu        $a0, 0x0($v0)
    /* BFC44 002BF044 00041400 */  sll        $v0, $a0, 16
.Lauto_002BF048:
    /* BFC48 002BF048 00021383 */  sra        $v0, $v0, 14
    /* BFC4C 002BF04C 00542821 */  addu       $a1, $v0, $s4
    /* BFC50 002BF050 94A30000 */  lhu        $v1, 0x0($a1)
    /* BFC54 002BF054 24020800 */  addiu      $v0, $zero, 0x800
    /* BFC58 002BF058 146200B8 */  .word 0x146200B8
    /* BFC5C 002BF05C 0080A821 */  addu      $s5, $a0, $zero
    /* BFC60 002BF060 94B00002 */  lhu        $s0, 0x2($a1)
    /* BFC64 002BF064 32040F00 */  andi       $a0, $s0, 0xF00
    /* BFC68 002BF068 10800004 */  .word 0x10800004
    /* BFC6C 002BF06C 0000A821 */  addu      $s5, $zero, $zero
    /* BFC70 002BF070 24020F00 */  addiu      $v0, $zero, 0xF00
    /* BFC74 002BF074 14820007 */  .word 0x14820007
    /* BFC78 002BF078 00101400 */  sll       $v0, $s0, 16
.Lauto_002BF07C:
    /* BFC7C 002BF07C 00111400 */  sll        $v0, $s1, 16
    /* BFC80 002BF080 000213C3 */  sra        $v0, $v0, 15
    /* BFC84 002BF084 00491021 */  addu       $v0, $v0, $t1
    /* BFC88 002BF088 A4500000 */  sh         $s0, 0x0($v0)
    /* BFC8C 002BF08C 080AFC9D */  .word 0x080AFC9D
    /* BFC90 002BF090 26310001 */  addiu     $s1, $s1, 0x1
.Lauto_002BF094:
    /* BFC94 002BF094 00021403 */  sra        $v0, $v0, 16
    /* BFC98 002BF098 24030900 */  addiu      $v1, $zero, 0x900
    /* BFC9C 002BF09C 14430020 */  .word 0x14430020
    /* BFCA0 002BF0A0 24020A00 */  addiu     $v0, $zero, 0xA00
    /* BFCA4 002BF0A4 02E02021 */  addu       $a0, $s7, $zero
    /* BFCA8 002BF0A8 24060001 */  addiu      $a2, $zero, 0x1
    /* BFCAC 002BF0AC 96F00000 */  lhu        $s0, 0x0($s7)
    /* BFCB0 002BF0B0 9665000E */  lhu        $a1, 0xE($s3)
    /* BFCB4 002BF0B4 8FAB0068 */  lw         $t3, 0x68($sp)
    /* BFCB8 002BF0B8 00003821 */  addu       $a3, $zero, $zero
    /* BFCBC 002BF0BC AFA80020 */  sw         $t0, 0x20($sp)
    /* BFCC0 002BF0C0 AFA90024 */  sw         $t1, 0x24($sp)
    /* BFCC4 002BF0C4 AFAA0028 */  sw         $t2, 0x28($sp)
    /* BFCC8 002BF0C8 0C0AFB6C */  jal        adecReadBits
    /* BFCCC 002BF0CC AFAB0010 */  sw        $t3, 0x10($sp)
    /* BFCD0 002BF0D0 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BFCD4 002BF0D4 8FA80020 */  lw         $t0, 0x20($sp)
    /* BFCD8 002BF0D8 8FA90024 */  lw         $t1, 0x24($sp)
    /* BFCDC 002BF0DC 8FAA0028 */  lw         $t2, 0x28($sp)
    /* BFCE0 002BF0E0 10400091 */  .word 0x10400091
    /* BFCE4 002BF0E4 00112400 */  sll       $a0, $s1, 16
    /* BFCE8 002BF0E8 26310001 */  addiu      $s1, $s1, 0x1
    /* BFCEC 002BF0EC 24020010 */  addiu      $v0, $zero, 0x10
    /* BFCF0 002BF0F0 000423C3 */  sra        $a0, $a0, 15
    /* BFCF4 002BF0F4 00892021 */  addu       $a0, $a0, $t1
    /* BFCF8 002BF0F8 3C05800D */  lui        $a1, %hi(D_auto_800D54BC)
    /* BFCFC 002BF0FC 94A554BC */  lhu        $a1, %lo(D_auto_800D54BC)($a1)
    /* BFD00 002BF100 96E30000 */  lhu        $v1, 0x0($s7)
    /* BFD04 002BF104 00451023 */  subu       $v0, $v0, $a1
    /* BFD08 002BF108 00431004 */  sllv       $v0, $v1, $v0
    /* BFD0C 002BF10C 00A31807 */  srav       $v1, $v1, $a1
    /* BFD10 002BF110 02031825 */  or         $v1, $s0, $v1
    /* BFD14 002BF114 A6E20000 */  sh         $v0, 0x0($s7)
    /* BFD18 002BF118 080AFC9D */  .word 0x080AFC9D
    /* BFD1C 002BF11C A4830000 */  sh        $v1, 0x0($a0)
.Lauto_002BF120:
    /* BFD20 002BF120 14820023 */  .word 0x14820023
    /* BFD24 002BF124 24020B00 */  addiu     $v0, $zero, 0xB00
    /* BFD28 002BF128 00003021 */  addu       $a2, $zero, $zero
    /* BFD2C 002BF12C 320300FF */  andi       $v1, $s0, 0xFF
    /* BFD30 002BF130 000310C0 */  sll        $v0, $v1, 3
    /* BFD34 002BF134 00431023 */  subu       $v0, $v0, $v1
    /* BFD38 002BF138 000210C0 */  sll        $v0, $v0, 3
    /* BFD3C 002BF13C 00431023 */  subu       $v0, $v0, $v1
    /* BFD40 002BF140 000210C0 */  sll        $v0, $v0, 3
    /* BFD44 002BF144 00111C00 */  sll        $v1, $s1, 16
    /* BFD48 002BF148 8E64001C */  lw         $a0, 0x1C($s3)
    /* BFD4C 002BF14C 00031BC3 */  sra        $v1, $v1, 15
    /* BFD50 002BF150 00442821 */  addu       $a1, $v0, $a0
    /* BFD54 002BF154 8CA201A0 */  lw         $v0, 0x1A0($a1)
    /* BFD58 002BF158 18400011 */  .word 0x18400011
    /* BFD5C 002BF15C 00693821 */  addu      $a3, $v1, $t1
    /* BFD60 002BF160 00061400 */  sll        $v0, $a2, 16
.Lauto_002BF164:
    /* BFD64 002BF164 24C30001 */  addiu      $v1, $a2, 0x1
    /* BFD68 002BF168 00603021 */  addu       $a2, $v1, $zero
    /* BFD6C 002BF16C 00021403 */  sra        $v0, $v0, 16
    /* BFD70 002BF170 00022040 */  sll        $a0, $v0, 1
    /* BFD74 002BF174 00021080 */  sll        $v0, $v0, 2
    /* BFD78 002BF178 00A21021 */  addu       $v0, $a1, $v0
    /* BFD7C 002BF17C 00872021 */  addu       $a0, $a0, $a3
    /* BFD80 002BF180 944200A2 */  lhu        $v0, 0xA2($v0)
    /* BFD84 002BF184 00031C00 */  sll        $v1, $v1, 16
    /* BFD88 002BF188 A4820000 */  sh         $v0, 0x0($a0)
    /* BFD8C 002BF18C 8CA201A0 */  lw         $v0, 0x1A0($a1)
    /* BFD90 002BF190 00031C03 */  sra        $v1, $v1, 16
    /* BFD94 002BF194 0062182A */  slt        $v1, $v1, $v0
    /* BFD98 002BF198 1460FFF2 */  .word 0x1460FFF2
    /* BFD9C 002BF19C 00061400 */  sll       $v0, $a2, 16
.Lauto_002BF1A0:
    /* BFDA0 002BF1A0 00061400 */  sll        $v0, $a2, 16
    /* BFDA4 002BF1A4 00021403 */  sra        $v0, $v0, 16
    /* BFDA8 002BF1A8 080AFC9D */  .word 0x080AFC9D
    /* BFDAC 002BF1AC 02228821 */  addu      $s1, $s1, $v0
.Lauto_002BF1B0:
    /* BFDB0 002BF1B0 14820031 */  .word 0x14820031
    /* BFDB4 002BF1B4 00112400 */  sll       $a0, $s1, 16
    /* BFDB8 002BF1B8 00111400 */  sll        $v0, $s1, 16
    /* BFDBC 002BF1BC 00021403 */  sra        $v0, $v0, 16
    /* BFDC0 002BF1C0 0056102A */  slt        $v0, $v0, $s6
    /* BFDC4 002BF1C4 1040000F */  .word 0x1040000F
    /* BFDC8 002BF1C8 00121C00 */  sll       $v1, $s2, 16
    /* BFDCC 002BF1CC 8FAB0018 */  lw         $t3, 0x18($sp)
    /* BFDD0 002BF1D0 000B2403 */  sra        $a0, $t3, 16
.Lauto_002BF1D4:
    /* BFDD4 002BF1D4 02201021 */  addu       $v0, $s1, $zero
    /* BFDD8 002BF1D8 24430001 */  addiu      $v1, $v0, 0x1
    /* BFDDC 002BF1DC 00608821 */  addu       $s1, $v1, $zero
    /* BFDE0 002BF1E0 00021400 */  sll        $v0, $v0, 16
    /* BFDE4 002BF1E4 000213C3 */  sra        $v0, $v0, 15
    /* BFDE8 002BF1E8 00491021 */  addu       $v0, $v0, $t1
    /* BFDEC 002BF1EC 00031C00 */  sll        $v1, $v1, 16
    /* BFDF0 002BF1F0 00031C03 */  sra        $v1, $v1, 16
    /* BFDF4 002BF1F4 0064182A */  slt        $v1, $v1, $a0
    /* BFDF8 002BF1F8 1460FFF6 */  .word 0x1460FFF6
    /* BFDFC 002BF1FC A4400000 */  sh        $zero, 0x0($v0)
    /* BFE00 002BF200 00121C00 */  sll        $v1, $s2, 16
.Lauto_002BF204:
    /* BFE04 002BF204 00031C03 */  sra        $v1, $v1, 16
    /* BFE08 002BF208 00031080 */  sll        $v0, $v1, 2
    /* BFE0C 002BF20C 00431021 */  addu       $v0, $v0, $v1
    /* BFE10 002BF210 00021080 */  sll        $v0, $v0, 2
    /* BFE14 002BF214 004A1021 */  addu       $v0, $v0, $t2
    /* BFE18 002BF218 8C430004 */  lw         $v1, 0x4($v0)
    /* BFE1C 002BF21C 8C420008 */  lw         $v0, 0x8($v0)
    /* BFE20 002BF220 080AFC97 */  .word 0x080AFC97
    /* BFE24 002BF224 00621821 */  addu      $v1, $v1, $v0
.Lauto_002BF228:
    /* BFE28 002BF228 00041C00 */  sll        $v1, $a0, 16
    /* BFE2C 002BF22C 95020000 */  lhu        $v0, 0x0($t0)
    /* BFE30 002BF230 00031C03 */  sra        $v1, $v1, 16
    /* BFE34 002BF234 24420001 */  addiu      $v0, $v0, 0x1
    /* BFE38 002BF238 A5020000 */  sh         $v0, 0x0($t0)
    /* BFE3C 002BF23C 00031080 */  sll        $v0, $v1, 2
    /* BFE40 002BF240 00431021 */  addu       $v0, $v0, $v1
    /* BFE44 002BF244 00021080 */  sll        $v0, $v0, 2
    /* BFE48 002BF248 004A1021 */  addu       $v0, $v0, $t2
    /* BFE4C 002BF24C 8C430004 */  lw         $v1, 0x4($v0)
    /* BFE50 002BF250 8C420008 */  lw         $v0, 0x8($v0)
    /* BFE54 002BF254 00809021 */  addu       $s2, $a0, $zero
    /* BFE58 002BF258 00621821 */  addu       $v1, $v1, $v0
.Lauto_002BF25C:
    /* BFE5C 002BF25C 02C3182A */  slt        $v1, $s6, $v1
    /* BFE60 002BF260 1060FFF1 */  .word 0x1060FFF1
    /* BFE64 002BF264 26440001 */  addiu     $a0, $s2, 0x1
    /* BFE68 002BF268 8FAB0018 */  lw         $t3, 0x18($sp)
    /* BFE6C 002BF26C 080AFCD6 */  .word 0x080AFCD6
    /* BFE70 002BF270 000B1403 */  sra       $v0, $t3, 16
.Lauto_002BF274:
    /* BFE74 002BF274 00112400 */  sll        $a0, $s1, 16
.Lauto_002BF278:
    /* BFE78 002BF278 00121C00 */  sll        $v1, $s2, 16
    /* BFE7C 002BF27C 00031C03 */  sra        $v1, $v1, 16
    /* BFE80 002BF280 00031080 */  sll        $v0, $v1, 2
    /* BFE84 002BF284 00431021 */  addu       $v0, $v0, $v1
    /* BFE88 002BF288 00021080 */  sll        $v0, $v0, 2
    /* BFE8C 002BF28C 004A1021 */  addu       $v0, $v0, $t2
    /* BFE90 002BF290 8C430004 */  lw         $v1, 0x4($v0)
    /* BFE94 002BF294 8C420008 */  lw         $v0, 0x8($v0)
    /* BFE98 002BF298 00042403 */  sra        $a0, $a0, 16
    /* BFE9C 002BF29C 00621821 */  addu       $v1, $v1, $v0
    /* BFEA0 002BF2A0 0083202A */  slt        $a0, $a0, $v1
    /* BFEA4 002BF2A4 14800026 */  .word 0x14800026
    /* BFEA8 002BF2A8 00111400 */  sll       $v0, $s1, 16
    /* BFEAC 002BF2AC 26440001 */  addiu      $a0, $s2, 0x1
    /* BFEB0 002BF2B0 00041C00 */  sll        $v1, $a0, 16
    /* BFEB4 002BF2B4 95020000 */  lhu        $v0, 0x0($t0)
    /* BFEB8 002BF2B8 00031C03 */  sra        $v1, $v1, 16
    /* BFEBC 002BF2BC 24420001 */  addiu      $v0, $v0, 0x1
    /* BFEC0 002BF2C0 A5020000 */  sh         $v0, 0x0($t0)
    /* BFEC4 002BF2C4 00031080 */  sll        $v0, $v1, 2
    /* BFEC8 002BF2C8 00431021 */  addu       $v0, $v0, $v1
    /* BFECC 002BF2CC 00021080 */  sll        $v0, $v0, 2
    /* BFED0 002BF2D0 004A1021 */  addu       $v0, $v0, $t2
    /* BFED4 002BF2D4 8C530010 */  lw         $s3, 0x10($v0)
    /* BFED8 002BF2D8 8E740020 */  lw         $s4, 0x20($s3)
    /* BFEDC 002BF2DC 080AFCCF */  .word 0x080AFCCF
    /* BFEE0 002BF2E0 00809021 */  addu      $s2, $a0, $zero
.Lauto_002BF2E4:
    /* BFEE4 002BF2E4 3C04800D */  lui        $a0, %hi(D_auto_800D54BA)
    /* BFEE8 002BF2E8 248454BA */  addiu      $a0, $a0, %lo(D_auto_800D54BA)
    /* BFEEC 002BF2EC 24050010 */  addiu      $a1, $zero, 0x10
    /* BFEF0 002BF2F0 24060001 */  addiu      $a2, $zero, 0x1
    /* BFEF4 002BF2F4 8FAB0068 */  lw         $t3, 0x68($sp)
    /* BFEF8 002BF2F8 00003821 */  addu       $a3, $zero, $zero
    /* BFEFC 002BF2FC AFA80020 */  sw         $t0, 0x20($sp)
    /* BFF00 002BF300 AFA90024 */  sw         $t1, 0x24($sp)
    /* BFF04 002BF304 AFAA0028 */  sw         $t2, 0x28($sp)
    /* BFF08 002BF308 0C0AFB6C */  jal        adecReadBits
    /* BFF0C 002BF30C AFAB0010 */  sw        $t3, 0x10($sp)
    /* BFF10 002BF310 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BFF14 002BF314 8FA80020 */  lw         $t0, 0x20($sp)
    /* BFF18 002BF318 8FA90024 */  lw         $t1, 0x24($sp)
    /* BFF1C 002BF31C 8FAA0028 */  lw         $t2, 0x28($sp)
    /* BFF20 002BF320 14400003 */  .word 0x14400003
    /* BFF24 002BF324 00000000 */  nop
.Lauto_002BF328:
    /* BFF28 002BF328 080AFCD6 */  .word 0x080AFCD6
    /* BFF2C 002BF32C 2402FFFF */  addiu     $v0, $zero, -0x1
.Lauto_002BF330:
    /* BFF30 002BF330 97C20000 */  lhu        $v0, 0x0($fp)
    /* BFF34 002BF334 24420010 */  addiu      $v0, $v0, 0x10
    /* BFF38 002BF338 A7C20000 */  sh         $v0, 0x0($fp)
.Lauto_002BF33C:
    /* BFF3C 002BF33C 00111400 */  sll        $v0, $s1, 16
.Lauto_002BF340:
    /* BFF40 002BF340 00021403 */  sra        $v0, $v0, 16
    /* BFF44 002BF344 0056102A */  slt        $v0, $v0, $s6
    /* BFF48 002BF348 1440FF2B */  .word 0x1440FF2B
    /* BFF4C 002BF34C 00000000 */  nop
.Lauto_002BF350:
    /* BFF50 002BF350 00111400 */  sll        $v0, $s1, 16
    /* BFF54 002BF354 00021403 */  sra        $v0, $v0, 16
.Lauto_002BF358:
    /* BFF58 002BF358 8FBF0054 */  lw         $ra, 0x54($sp)
    /* BFF5C 002BF35C 8FBE0050 */  lw         $fp, 0x50($sp)
    /* BFF60 002BF360 8FB7004C */  lw         $s7, 0x4C($sp)
    /* BFF64 002BF364 8FB60048 */  lw         $s6, 0x48($sp)
    /* BFF68 002BF368 8FB50044 */  lw         $s5, 0x44($sp)
    /* BFF6C 002BF36C 8FB40040 */  lw         $s4, 0x40($sp)
    /* BFF70 002BF370 8FB3003C */  lw         $s3, 0x3C($sp)
    /* BFF74 002BF374 8FB20038 */  lw         $s2, 0x38($sp)
    /* BFF78 002BF378 8FB10034 */  lw         $s1, 0x34($sp)
    /* BFF7C 002BF37C 8FB00030 */  lw         $s0, 0x30($sp)
    /* BFF80 002BF380 03E00008 */  jr         $ra
    /* BFF84 002BF384 27BD0058 */  addiu     $sp, $sp, 0x58
.globl adecDecodeFrame
adecDecodeFrame:
    /* BFF88 002BF388 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* BFF8C 002BF38C AFB10024 */  sw         $s1, 0x24($sp)
    /* BFF90 002BF390 3C03800D */  lui        $v1, %hi(D_auto_800D54BE)
    /* BFF94 002BF394 246354BE */  addiu      $v1, $v1, %lo(D_auto_800D54BE)
    /* BFF98 002BF398 AFBF0028 */  sw         $ra, 0x28($sp)
    /* BFF9C 002BF39C AFB00020 */  sw         $s0, 0x20($sp)
    /* BFFA0 002BF3A0 84620000 */  lh         $v0, 0x0($v1)
    /* BFFA4 002BF3A4 3C10800D */  lui        $s0, %hi(D_auto_800D5564)
    /* BFFA8 002BF3A8 26105564 */  addiu      $s0, $s0, %lo(D_auto_800D5564)
    /* BFFAC 002BF3AC 14400026 */  .word 0x14400026
    /* BFFB0 002BF3B0 00808821 */  addu      $s1, $a0, $zero
    /* BFFB4 002BF3B4 26240018 */  addiu      $a0, $s1, 0x18
    /* BFFB8 002BF3B8 24050006 */  addiu      $a1, $zero, 0x6
    /* BFFBC 002BF3BC 24060010 */  addiu      $a2, $zero, 0x10
    /* BFFC0 002BF3C0 00003821 */  addu       $a3, $zero, $zero
    /* BFFC4 002BF3C4 24020001 */  addiu      $v0, $zero, 0x1
    /* BFFC8 002BF3C8 A4620000 */  sh         $v0, 0x0($v1)
    /* BFFCC 002BF3CC 0C0AFB6C */  jal        adecReadBits
    /* BFFD0 002BF3D0 AFB10010 */  sw        $s1, 0x10($sp)
    /* BFFD4 002BF3D4 00021400 */  sll        $v0, $v0, 16
    /* BFFD8 002BF3D8 18400048 */  .word 0x18400048
    /* BFFDC 002BF3DC 00003821 */  addu      $a3, $zero, $zero
    /* BFFE0 002BF3E0 8E02000C */  lw         $v0, 0xC($s0)
    /* BFFE4 002BF3E4 3C058015 */  lui        $a1, %hi(D_auto_8014AE10)
    /* BFFE8 002BF3E8 24A5AE10 */  addiu      $a1, $a1, %lo(D_auto_8014AE10)
    /* BFFEC 002BF3EC 24420060 */  addiu      $v0, $v0, 0x60
    /* BFFF0 002BF3F0 AE02000C */  sw         $v0, 0xC($s0)
.Lauto_002BF3F4:
    /* BFFF4 002BF3F4 00072400 */  sll        $a0, $a3, 16
    /* BFFF8 002BF3F8 24E30001 */  addiu      $v1, $a3, 0x1
    /* BFFFC 002BF3FC 00603821 */  addu       $a3, $v1, $zero
    /* C0000 002BF400 000423C3 */  sra        $a0, $a0, 15
    /* C0004 002BF404 02241021 */  addu       $v0, $s1, $a0
    /* C0008 002BF408 00852021 */  addu       $a0, $a0, $a1
    /* C000C 002BF40C 00031C00 */  sll        $v1, $v1, 16
    /* C0010 002BF410 00031C03 */  sra        $v1, $v1, 16
    /* C0014 002BF414 94420018 */  lhu        $v0, 0x18($v0)
    /* C0018 002BF418 28630010 */  slti       $v1, $v1, 0x10
    /* C001C 002BF41C 1460FFF5 */  .word 0x1460FFF5
    /* C0020 002BF420 A4820000 */  sh        $v0, 0x0($a0)
    /* C0024 002BF424 8E020000 */  lw         $v0, 0x0($s0)
    /* C0028 002BF428 5040002A */  .word 0x5040002A
    /* C002C 002BF42C AFB10010 */  sw        $s1, 0x10($sp)
    /* C0030 002BF430 26100014 */  addiu      $s0, $s0, 0x14
.Lauto_002BF434:
    /* C0034 002BF434 8E020000 */  lw         $v0, 0x0($s0)
    /* C0038 002BF438 5440FFFE */  .word 0x5440FFFE
    /* C003C 002BF43C 26100014 */  addiu     $s0, $s0, 0x14
    /* C0040 002BF440 080AFD35 */  .word 0x080AFD35
    /* C0044 002BF444 AFB10010 */  sw        $s1, 0x10($sp)
.Lauto_002BF448:
    /* C0048 002BF448 AFB10010 */  sw         $s1, 0x10($sp)
    /* C004C 002BF44C 02002021 */  addu       $a0, $s0, $zero
    /* C0050 002BF450 26250018 */  addiu      $a1, $s1, 0x18
    /* C0054 002BF454 24060010 */  addiu      $a2, $zero, 0x10
    /* C0058 002BF458 0C0AFBE1 */  jal        adecHuffDecode
    /* C005C 002BF45C 27A70018 */  addiu     $a3, $sp, 0x18
    /* C0060 002BF460 00021400 */  sll        $v0, $v0, 16
    /* C0064 002BF464 00021C03 */  sra        $v1, $v0, 16
    /* C0068 002BF468 24020010 */  addiu      $v0, $zero, 0x10
    /* C006C 002BF46C 14620024 */  .word 0x14620024
    /* C0070 002BF470 2402FFFF */  addiu     $v0, $zero, -0x1
    /* C0074 002BF474 00003821 */  addu       $a3, $zero, $zero
    /* C0078 002BF478 87A30018 */  lh         $v1, 0x18($sp)
    /* C007C 002BF47C 3C088015 */  lui        $t0, %hi(D_auto_8014AE10)
    /* C0080 002BF480 2508AE10 */  addiu      $t0, $t0, %lo(D_auto_8014AE10)
    /* C0084 002BF484 00031080 */  sll        $v0, $v1, 2
    /* C0088 002BF488 00431021 */  addu       $v0, $v0, $v1
    /* C008C 002BF48C 00021080 */  sll        $v0, $v0, 2
    /* C0090 002BF490 00508021 */  addu       $s0, $v0, $s0
.Lauto_002BF494:
    /* C0094 002BF494 00072400 */  sll        $a0, $a3, 16
    /* C0098 002BF498 000423C3 */  sra        $a0, $a0, 15
    /* C009C 002BF49C 00882821 */  addu       $a1, $a0, $t0
    /* C00A0 002BF4A0 02242021 */  addu       $a0, $s1, $a0
    /* C00A4 002BF4A4 24E30001 */  addiu      $v1, $a3, 0x1
    /* C00A8 002BF4A8 00603821 */  addu       $a3, $v1, $zero
    /* C00AC 002BF4AC 00031C00 */  sll        $v1, $v1, 16
    /* C00B0 002BF4B0 00031C03 */  sra        $v1, $v1, 16
    /* C00B4 002BF4B4 94A60000 */  lhu        $a2, 0x0($a1)
    /* C00B8 002BF4B8 94820018 */  lhu        $v0, 0x18($a0)
    /* C00BC 002BF4BC 28630010 */  slti       $v1, $v1, 0x10
    /* C00C0 002BF4C0 00461021 */  addu       $v0, $v0, $a2
    /* C00C4 002BF4C4 A4820018 */  sh         $v0, 0x18($a0)
    /* C00C8 002BF4C8 1460FFF2 */  .word 0x1460FFF2
    /* C00CC 002BF4CC A4A20000 */  sh        $v0, 0x0($a1)
    /* C00D0 002BF4D0 AFB10010 */  sw         $s1, 0x10($sp)
.Lauto_002BF4D4:
    /* C00D4 002BF4D4 02002021 */  addu       $a0, $s0, $zero
    /* C00D8 002BF4D8 262500B8 */  addiu      $a1, $s1, 0xB8
    /* C00DC 002BF4DC 24060100 */  addiu      $a2, $zero, 0x100
    /* C00E0 002BF4E0 0C0AFBE1 */  jal        adecHuffDecode
    /* C00E4 002BF4E4 27A70018 */  addiu     $a3, $sp, 0x18
    /* C00E8 002BF4E8 00021400 */  sll        $v0, $v0, 16
    /* C00EC 002BF4EC 00021C03 */  sra        $v1, $v0, 16
    /* C00F0 002BF4F0 24020100 */  addiu      $v0, $zero, 0x100
    /* C00F4 002BF4F4 10620002 */  .word 0x10620002
    /* C00F8 002BF4F8 24020001 */  addiu     $v0, $zero, 0x1
.Lauto_002BF4FC:
    /* C00FC 002BF4FC 2402FFFF */  addiu      $v0, $zero, -0x1
.Lauto_002BF500:
    /* C0100 002BF500 8FBF0028 */  lw         $ra, 0x28($sp)
    /* C0104 002BF504 8FB10024 */  lw         $s1, 0x24($sp)
    /* C0108 002BF508 8FB00020 */  lw         $s0, 0x20($sp)
    /* C010C 002BF50C 03E00008 */  jr         $ra
    /* C0110 002BF510 27BD0030 */  addiu     $sp, $sp, 0x30
.globl mdctInitTwiddles
mdctInitTwiddles:
    /* C0114 002BF514 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* C0118 002BF518 F7B70040 */  sdc1       $fs1f, 0x40($sp)
    /* C011C 002BF51C 3C01800C */  lui        $at, %hi(D_auto_800C7CC0)
    /* C0120 002BF520 C4377CC0 */  lwc1       $fs1f, %lo(D_auto_800C7CC0)($at)
    /* C0124 002BF524 F7B60038 */  sdc1       $fs1, 0x38($sp)
    /* C0128 002BF528 3C01800C */  lui        $at, %hi(D_auto_800C7CC0 + 0x4)
    /* C012C 002BF52C C4367CC4 */  lwc1       $fs1, %lo(D_auto_800C7CC0 + 0x4)($at)
    /* C0130 002BF530 F7B50030 */  sdc1       $fs0f, 0x30($sp)
    /* C0134 002BF534 3C01800C */  lui        $at, %hi(D_auto_800C7CC8)
    /* C0138 002BF538 C4357CC8 */  lwc1       $fs0f, %lo(D_auto_800C7CC8)($at)
    /* C013C 002BF53C AFB10014 */  sw         $s1, 0x14($sp)
    /* C0140 002BF540 00008821 */  addu       $s1, $zero, $zero
    /* C0144 002BF544 AFB40020 */  sw         $s4, 0x20($sp)
    /* C0148 002BF548 3C148015 */  lui        $s4, %hi(D_auto_8014AE30)
    /* C014C 002BF54C 2694AE30 */  addiu      $s4, $s4, %lo(D_auto_8014AE30)
    /* C0150 002BF550 AFB3001C */  sw         $s3, 0x1C($sp)
    /* C0154 002BF554 3C138015 */  lui        $s3, %hi(D_auto_8014B030)
    /* C0158 002BF558 2673B030 */  addiu      $s3, $s3, %lo(D_auto_8014B030)
    /* C015C 002BF55C AFB20018 */  sw         $s2, 0x18($sp)
    /* C0160 002BF560 3C128015 */  lui        $s2, %hi(D_auto_8014B630)
    /* C0164 002BF564 2652B630 */  addiu      $s2, $s2, %lo(D_auto_8014B630)
    /* C0168 002BF568 AFBF0024 */  sw         $ra, 0x24($sp)
    /* C016C 002BF56C AFB00010 */  sw         $s0, 0x10($sp)
    /* C0170 002BF570 F7B40028 */  sdc1       $fs0, 0x28($sp)
.Lauto_002BF574:
    /* C0174 002BF574 00118400 */  sll        $s0, $s1, 16
    /* C0178 002BF578 00108403 */  sra        $s0, $s0, 16
    /* C017C 002BF57C 44900000 */  mtc1       $s0, $fv0
    /* C0180 002BF580 46800020 */  cvt.s.w    $fv0, $fv0
    /* C0184 002BF584 46170002 */  mul.s      $fv0, $fv0, $fs1f
    /* C0188 002BF588 46160000 */  add.s      $fv0, $fv0, $fs1
    /* C018C 002BF58C 46150502 */  mul.s      $fs0, $fv0, $fs0f
    /* C0190 002BF590 0C0AD958 */  jal        cosf
    /* C0194 002BF594 4600A306 */  mov.s     $fa0, $fs0
    /* C0198 002BF598 4600A306 */  mov.s      $fa0, $fs0
    /* C019C 002BF59C 00108080 */  sll        $s0, $s0, 2
    /* C01A0 002BF5A0 02141021 */  addu       $v0, $s0, $s4
    /* C01A4 002BF5A4 0C0ADC4C */  jal        sinf
    /* C01A8 002BF5A8 E4400000 */  swc1      $fv0, 0x0($v0)
    /* C01AC 002BF5AC 26220001 */  addiu      $v0, $s1, 0x1
    /* C01B0 002BF5B0 00408821 */  addu       $s1, $v0, $zero
    /* C01B4 002BF5B4 02131821 */  addu       $v1, $s0, $s3
    /* C01B8 002BF5B8 02128021 */  addu       $s0, $s0, $s2
    /* C01BC 002BF5BC 00021400 */  sll        $v0, $v0, 16
    /* C01C0 002BF5C0 00021403 */  sra        $v0, $v0, 16
    /* C01C4 002BF5C4 28420080 */  slti       $v0, $v0, 0x80
    /* C01C8 002BF5C8 E4600000 */  swc1       $fv0, 0x0($v1)
    /* C01CC 002BF5CC 1440FFE9 */  .word 0x1440FFE9
    /* C01D0 002BF5D0 AE000000 */  sw        $zero, 0x0($s0)
    /* C01D4 002BF5D4 00008821 */  addu       $s1, $zero, $zero
    /* C01D8 002BF5D8 3C01800C */  lui        $at, %hi(D_auto_800C7CC8 + 0x4)
    /* C01DC 002BF5DC C4357CCC */  lwc1       $fs0f, %lo(D_auto_800C7CC8 + 0x4)($at)
    /* C01E0 002BF5E0 3C138015 */  lui        $s3, %hi(D_auto_8014B230)
    /* C01E4 002BF5E4 2673B230 */  addiu      $s3, $s3, %lo(D_auto_8014B230)
    /* C01E8 002BF5E8 3C128015 */  lui        $s2, %hi(D_auto_8014B430)
    /* C01EC 002BF5EC 2652B430 */  addiu      $s2, $s2, %lo(D_auto_8014B430)
.Lauto_002BF5F0:
    /* C01F0 002BF5F0 00118400 */  sll        $s0, $s1, 16
    /* C01F4 002BF5F4 00108403 */  sra        $s0, $s0, 16
    /* C01F8 002BF5F8 44900000 */  mtc1       $s0, $fv0
    /* C01FC 002BF5FC 46800020 */  cvt.s.w    $fv0, $fv0
    /* C0200 002BF600 46150502 */  mul.s      $fs0, $fv0, $fs0f
    /* C0204 002BF604 0C0AD958 */  jal        cosf
    /* C0208 002BF608 4600A306 */  mov.s     $fa0, $fs0
    /* C020C 002BF60C 4600A306 */  mov.s      $fa0, $fs0
    /* C0210 002BF610 0C0ADC4C */  jal        sinf
    /* C0214 002BF614 46000506 */  mov.s     $fs0, $fv0
    /* C0218 002BF618 26220001 */  addiu      $v0, $s1, 0x1
    /* C021C 002BF61C 00408821 */  addu       $s1, $v0, $zero
    /* C0220 002BF620 00108080 */  sll        $s0, $s0, 2
    /* C0224 002BF624 02131821 */  addu       $v1, $s0, $s3
    /* C0228 002BF628 02128021 */  addu       $s0, $s0, $s2
    /* C022C 002BF62C 4600A040 */  add.s      $fv0f, $fs0, $fv0
    /* C0230 002BF630 00021400 */  sll        $v0, $v0, 16
    /* C0234 002BF634 00021403 */  sra        $v0, $v0, 16
    /* C0238 002BF638 46140001 */  sub.s      $fv0, $fv0, $fs0
    /* C023C 002BF63C 28420080 */  slti       $v0, $v0, 0x80
    /* C0240 002BF640 E4610000 */  swc1       $fv0f, 0x0($v1)
    /* C0244 002BF644 1440FFEA */  .word 0x1440FFEA
    /* C0248 002BF648 E6000000 */  swc1      $fv0, 0x0($s0)
    /* C024C 002BF64C 8FBF0024 */  lw         $ra, 0x24($sp)
    /* C0250 002BF650 8FB40020 */  lw         $s4, 0x20($sp)
    /* C0254 002BF654 8FB3001C */  lw         $s3, 0x1C($sp)
    /* C0258 002BF658 8FB20018 */  lw         $s2, 0x18($sp)
    /* C025C 002BF65C 8FB10014 */  lw         $s1, 0x14($sp)
    /* C0260 002BF660 8FB00010 */  lw         $s0, 0x10($sp)
    /* C0264 002BF664 D7B70040 */  ldc1       $fs1f, 0x40($sp)
    /* C0268 002BF668 D7B60038 */  ldc1       $fs1, 0x38($sp)
    /* C026C 002BF66C D7B50030 */  ldc1       $fs0f, 0x30($sp)
    /* C0270 002BF670 D7B40028 */  ldc1       $fs0, 0x28($sp)
    /* C0274 002BF674 03E00008 */  jr         $ra
    /* C0278 002BF678 27BD0048 */  addiu     $sp, $sp, 0x48
.globl mdctFftInit
mdctFftInit:
    /* C027C 002BF67C 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* C0280 002BF680 AFB3001C */  sw         $s3, 0x1C($sp)
    /* C0284 002BF684 00809821 */  addu       $s3, $a0, $zero
    /* C0288 002BF688 AFB10014 */  sw         $s1, 0x14($sp)
    /* C028C 002BF68C AFB20018 */  sw         $s2, 0x18($sp)
    /* C0290 002BF690 00139043 */  sra        $s2, $s3, 1
    /* C0294 002BF694 AFB40020 */  sw         $s4, 0x20($sp)
    /* C0298 002BF698 3C14800D */  lui        $s4, %hi(D_auto_800D5340)
    /* C029C 002BF69C 26945340 */  addiu      $s4, $s4, %lo(D_auto_800D5340)
    /* C02A0 002BF6A0 AFBF0024 */  sw         $ra, 0x24($sp)
    /* C02A4 002BF6A4 AFB00010 */  sw         $s0, 0x10($sp)
    /* C02A8 002BF6A8 F7B60038 */  sdc1       $fs1, 0x38($sp)
    /* C02AC 002BF6AC F7B50030 */  sdc1       $fs0f, 0x30($sp)
    /* C02B0 002BF6B0 F7B40028 */  sdc1       $fs0, 0x28($sp)
    /* C02B4 002BF6B4 1A400018 */  .word 0x1A400018
    /* C02B8 002BF6B8 00008821 */  addu      $s1, $zero, $zero
    /* C02BC 002BF6BC 3C01800C */  lui        $at, %hi(D_auto_800C7CD0)
    /* C02C0 002BF6C0 C4367CD0 */  lwc1       $fs1, %lo(D_auto_800C7CD0)($at)
    /* C02C4 002BF6C4 4493A800 */  mtc1       $s3, $fs0f
    /* C02C8 002BF6C8 4680AD60 */  cvt.s.w    $fs0f, $fs0f
.Lauto_002BF6CC:
    /* C02CC 002BF6CC 4491A000 */  mtc1       $s1, $fs0
    /* C02D0 002BF6D0 4680A520 */  cvt.s.w    $fs0, $fs0
    /* C02D4 002BF6D4 4616A502 */  mul.s      $fs0, $fs0, $fs1
    /* C02D8 002BF6D8 4615A503 */  div.s      $fs0, $fs0, $fs0f
    /* C02DC 002BF6DC 0C0AD958 */  jal        cosf
    /* C02E0 002BF6E0 4600A306 */  mov.s     $fa0, $fs0
    /* C02E4 002BF6E4 4600A306 */  mov.s      $fa0, $fs0
    /* C02E8 002BF6E8 8E820000 */  lw         $v0, 0x0($s4)
    /* C02EC 002BF6EC 00118080 */  sll        $s0, $s1, 2
    /* C02F0 002BF6F0 02021021 */  addu       $v0, $s0, $v0
    /* C02F4 002BF6F4 0C0ADC4C */  jal        sinf
    /* C02F8 002BF6F8 E4400000 */  swc1      $fv0, 0x0($v0)
    /* C02FC 002BF6FC 26310001 */  addiu      $s1, $s1, 0x1
    /* C0300 002BF700 8E820004 */  lw         $v0, 0x4($s4)
    /* C0304 002BF704 46000007 */  neg.s      $fv0, $fv0
    /* C0308 002BF708 02028021 */  addu       $s0, $s0, $v0
    /* C030C 002BF70C 0232102A */  slt        $v0, $s1, $s2
    /* C0310 002BF710 1440FFEE */  .word 0x1440FFEE
    /* C0314 002BF714 E6000000 */  swc1      $fv0, 0x0($s0)
.Lauto_002BF718:
    /* C0318 002BF718 00003821 */  addu       $a3, $zero, $zero
    /* C031C 002BF71C 8E880008 */  lw         $t0, 0x8($s4)
    /* C0320 002BF720 1A600007 */  .word 0x1A600007
    /* C0324 002BF724 00134840 */  sll       $t1, $s3, 1
    /* C0328 002BF728 01001821 */  addu       $v1, $t0, $zero
.Lauto_002BF72C:
    /* C032C 002BF72C AC670000 */  sw         $a3, 0x0($v1)
    /* C0330 002BF730 24E70001 */  addiu      $a3, $a3, 0x1
    /* C0334 002BF734 00F3102A */  slt        $v0, $a3, $s3
    /* C0338 002BF738 1440FFFC */  .word 0x1440FFFC
    /* C033C 002BF73C 24630004 */  addiu     $v1, $v1, 0x4
.Lauto_002BF740:
    /* C0340 002BF740 24060001 */  addiu      $a2, $zero, 0x1
    /* C0344 002BF744 19200022 */  .word 0x19200022
    /* C0348 002BF748 00C03821 */  addu      $a3, $a2, $zero
    /* C034C 002BF74C 2A6A0002 */  slti       $t2, $s3, 0x2
.Lauto_002BF750:
    /* C0350 002BF750 00E6102A */  slt        $v0, $a3, $a2
    /* C0354 002BF754 10400010 */  .word 0x10400010
    /* C0358 002BF758 24C4FFFF */  addiu     $a0, $a2, -0x1
    /* C035C 002BF75C 000417C2 */  srl        $v0, $a0, 31
    /* C0360 002BF760 00822021 */  addu       $a0, $a0, $v0
    /* C0364 002BF764 00042043 */  sra        $a0, $a0, 1
    /* C0368 002BF768 00042080 */  sll        $a0, $a0, 2
    /* C036C 002BF76C 00882021 */  addu       $a0, $a0, $t0
    /* C0370 002BF770 24E2FFFF */  addiu      $v0, $a3, -0x1
    /* C0374 002BF774 00021FC2 */  srl        $v1, $v0, 31
    /* C0378 002BF778 00431021 */  addu       $v0, $v0, $v1
    /* C037C 002BF77C 00021043 */  sra        $v0, $v0, 1
    /* C0380 002BF780 00021080 */  sll        $v0, $v0, 2
    /* C0384 002BF784 00481021 */  addu       $v0, $v0, $t0
    /* C0388 002BF788 8C430000 */  lw         $v1, 0x0($v0)
    /* C038C 002BF78C 8C850000 */  lw         $a1, 0x0($a0)
    /* C0390 002BF790 AC830000 */  sw         $v1, 0x0($a0)
    /* C0394 002BF794 AC450000 */  sw         $a1, 0x0($v0)
.Lauto_002BF798:
    /* C0398 002BF798 15400009 */  .word 0x15400009
    /* C039C 002BF79C 02601821 */  addu      $v1, $s3, $zero
    /* C03A0 002BF7A0 0066102A */  slt        $v0, $v1, $a2
.Lauto_002BF7A4:
    /* C03A4 002BF7A4 50400007 */  .word 0x50400007
    /* C03A8 002BF7A8 24E70002 */  addiu     $a3, $a3, 0x2
    /* C03AC 002BF7AC 00C33023 */  subu       $a2, $a2, $v1
    /* C03B0 002BF7B0 00031843 */  sra        $v1, $v1, 1
    /* C03B4 002BF7B4 28620002 */  slti       $v0, $v1, 0x2
    /* C03B8 002BF7B8 1040FFFA */  .word 0x1040FFFA
    /* C03BC 002BF7BC 0066102A */  slt       $v0, $v1, $a2
.Lauto_002BF7C0:
    /* C03C0 002BF7C0 24E70002 */  addiu      $a3, $a3, 0x2
.Lauto_002BF7C4:
    /* C03C4 002BF7C4 0127102A */  slt        $v0, $t1, $a3
    /* C03C8 002BF7C8 1040FFE1 */  .word 0x1040FFE1
    /* C03CC 002BF7CC 00C33021 */  addu      $a2, $a2, $v1
.Lauto_002BF7D0:
    /* C03D0 002BF7D0 02801021 */  addu       $v0, $s4, $zero
    /* C03D4 002BF7D4 AE93000C */  sw         $s3, 0xC($s4)
    /* C03D8 002BF7D8 8FBF0024 */  lw         $ra, 0x24($sp)
    /* C03DC 002BF7DC 8FB40020 */  lw         $s4, 0x20($sp)
    /* C03E0 002BF7E0 8FB3001C */  lw         $s3, 0x1C($sp)
    /* C03E4 002BF7E4 8FB20018 */  lw         $s2, 0x18($sp)
    /* C03E8 002BF7E8 8FB10014 */  lw         $s1, 0x14($sp)
    /* C03EC 002BF7EC 8FB00010 */  lw         $s0, 0x10($sp)
    /* C03F0 002BF7F0 D7B60038 */  ldc1       $fs1, 0x38($sp)
    /* C03F4 002BF7F4 D7B50030 */  ldc1       $fs0f, 0x30($sp)
    /* C03F8 002BF7F8 D7B40028 */  ldc1       $fs0, 0x28($sp)
    /* C03FC 002BF7FC 03E00008 */  jr         $ra
    /* C0400 002BF800 27BD0040 */  addiu     $sp, $sp, 0x40
.globl adecDequantize
adecDequantize:
    /* C0404 002BF804 00806021 */  addu       $t4, $a0, $zero
    /* C0408 002BF808 00A05821 */  addu       $t3, $a1, $zero
    /* C040C 002BF80C 00001821 */  addu       $v1, $zero, $zero
    /* C0410 002BF810 256A00A0 */  addiu      $t2, $t3, 0xA0
    /* C0414 002BF814 00603821 */  addu       $a3, $v1, $zero
    /* C0418 002BF818 3C09800D */  lui        $t1, %hi(D_auto_800D5398)
    /* C041C 002BF81C 25295398 */  addiu      $t1, $t1, %lo(D_auto_800D5398)
    /* C0420 002BF820 3C0D800D */  lui        $t5, %hi(D_auto_800D53B8)
    /* C0424 002BF824 25AD53B8 */  addiu      $t5, $t5, %lo(D_auto_800D53B8)
    /* C0428 002BF828 3C01800C */  lui        $at, %hi(D_auto_800C7CD4)
    /* C042C 002BF82C C4227CD4 */  lwc1       $fv1, %lo(D_auto_800C7CD4)($at)
    /* C0430 002BF830 00603021 */  addu       $a2, $v1, $zero
.Lauto_002BF834:
    /* C0434 002BF834 00074400 */  sll        $t0, $a3, 16
    /* C0438 002BF838 00081BC3 */  sra        $v1, $t0, 15
    /* C043C 002BF83C 00691821 */  addu       $v1, $v1, $t1
    /* C0440 002BF840 94630000 */  lhu        $v1, 0x0($v1)
    /* C0444 002BF844 080AFE29 */  .word 0x080AFE29
    /* C0448 002BF848 00061400 */  sll       $v0, $a2, 16
.Lauto_002BF84C:
    /* C044C 002BF84C 00031C03 */  sra        $v1, $v1, 16
    /* C0450 002BF850 00032040 */  sll        $a0, $v1, 1
    /* C0454 002BF854 00082BC3 */  sra        $a1, $t0, 15
    /* C0458 002BF858 01651021 */  addu       $v0, $t3, $a1
    /* C045C 002BF85C 008A2021 */  addu       $a0, $a0, $t2
    /* C0460 002BF860 00031880 */  sll        $v1, $v1, 2
    /* C0464 002BF864 006C1821 */  addu       $v1, $v1, $t4
    /* C0468 002BF868 84420000 */  lh         $v0, 0x0($v0)
    /* C046C 002BF86C 84840000 */  lh         $a0, 0x0($a0)
    /* C0470 002BF870 00021080 */  sll        $v0, $v0, 2
    /* C0474 002BF874 004D1021 */  addu       $v0, $v0, $t5
    /* C0478 002BF878 C4410000 */  lwc1       $fv0f, 0x0($v0)
    /* C047C 002BF87C 44840000 */  mtc1       $a0, $fv0
    /* C0480 002BF880 46800020 */  cvt.s.w    $fv0, $fv0
    /* C0484 002BF884 46010003 */  div.s      $fv0, $fv0, $fv0f
    /* C0488 002BF888 46020002 */  mul.s      $fv0, $fv0, $fv1
    /* C048C 002BF88C 00A92821 */  addu       $a1, $a1, $t1
    /* C0490 002BF890 24C20001 */  addiu      $v0, $a2, 0x1
    /* C0494 002BF894 00403021 */  addu       $a2, $v0, $zero
    /* C0498 002BF898 00021400 */  sll        $v0, $v0, 16
    /* C049C 002BF89C E4600000 */  swc1       $fv0, 0x0($v1)
    /* C04A0 002BF8A0 94A30000 */  lhu        $v1, 0x0($a1)
.Lauto_002BF8A4:
    /* C04A4 002BF8A4 00021403 */  sra        $v0, $v0, 16
    /* C04A8 002BF8A8 0043102A */  slt        $v0, $v0, $v1
    /* C04AC 002BF8AC 1440FFE7 */  .word 0x1440FFE7
    /* C04B0 002BF8B0 00061C00 */  sll       $v1, $a2, 16
    /* C04B4 002BF8B4 00071400 */  sll        $v0, $a3, 16
    /* C04B8 002BF8B8 000213C3 */  sra        $v0, $v0, 15
    /* C04BC 002BF8BC 00491021 */  addu       $v0, $v0, $t1
    /* C04C0 002BF8C0 94430000 */  lhu        $v1, 0x0($v0)
    /* C04C4 002BF8C4 24E20001 */  addiu      $v0, $a3, 0x1
    /* C04C8 002BF8C8 00403821 */  addu       $a3, $v0, $zero
    /* C04CC 002BF8CC 00021400 */  sll        $v0, $v0, 16
    /* C04D0 002BF8D0 00021403 */  sra        $v0, $v0, 16
    /* C04D4 002BF8D4 28420010 */  slti       $v0, $v0, 0x10
    /* C04D8 002BF8D8 5440FFD6 */  .word 0x5440FFD6
    /* C04DC 002BF8DC 00603021 */  addu      $a2, $v1, $zero
    /* C04E0 002BF8E0 3C02800D */  lui        $v0, %hi(D_auto_800D53B6)
    /* C04E4 002BF8E4 844253B6 */  lh         $v0, %lo(D_auto_800D53B6)($v0)
    /* C04E8 002BF8E8 00403821 */  addu       $a3, $v0, $zero
    /* C04EC 002BF8EC 28420100 */  slti       $v0, $v0, 0x100
    /* C04F0 002BF8F0 1040000B */  .word 0x1040000B
    /* C04F4 002BF8F4 00071400 */  sll       $v0, $a3, 16
.Lauto_002BF8F8:
    /* C04F8 002BF8F8 00021383 */  sra        $v0, $v0, 14
    /* C04FC 002BF8FC 004C1021 */  addu       $v0, $v0, $t4
    /* C0500 002BF900 AC400000 */  sw         $zero, 0x0($v0)
    /* C0504 002BF904 24E20001 */  addiu      $v0, $a3, 0x1
    /* C0508 002BF908 00403821 */  addu       $a3, $v0, $zero
    /* C050C 002BF90C 00021400 */  sll        $v0, $v0, 16
    /* C0510 002BF910 00021403 */  sra        $v0, $v0, 16
    /* C0514 002BF914 28420100 */  slti       $v0, $v0, 0x100
    /* C0518 002BF918 1440FFF7 */  .word 0x1440FFF7
    /* C051C 002BF91C 00071400 */  sll       $v0, $a3, 16
.Lauto_002BF920:
    /* C0520 002BF920 03E00008 */  jr         $ra
    /* C0524 002BF924 24020001 */  addiu     $v0, $zero, 0x1
.globl mdctFft
mdctFft:
    /* C0528 002BF928 8FB80010 */  lw         $t8, 0x10($sp)
    /* C052C 002BF92C 18A0001F */  .word 0x18A0001F
    /* C0530 002BF930 00005021 */  addu      $t2, $zero, $zero
    /* C0534 002BF934 8FA90014 */  lw         $t1, 0x14($sp)
    /* C0538 002BF938 00804021 */  addu       $t0, $a0, $zero
.Lauto_002BF93C:
    /* C053C 002BF93C 8D230000 */  lw         $v1, 0x0($t1)
    /* C0540 002BF940 0143102A */  slt        $v0, $t2, $v1
    /* C0544 002BF944 50400015 */  .word 0x50400015
    /* C0548 002BF948 25290004 */  addiu     $t1, $t1, 0x4
    /* C054C 002BF94C 000310C0 */  sll        $v0, $v1, 3
    /* C0550 002BF950 00441021 */  addu       $v0, $v0, $a0
    /* C0554 002BF954 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0558 002BF958 C5030000 */  lwc1       $fv1f, 0x0($t0)
    /* C055C 002BF95C E5000000 */  swc1       $fv0, 0x0($t0)
    /* C0560 002BF960 8D220000 */  lw         $v0, 0x0($t1)
    /* C0564 002BF964 000210C0 */  sll        $v0, $v0, 3
    /* C0568 002BF968 00441021 */  addu       $v0, $v0, $a0
    /* C056C 002BF96C E4430000 */  swc1       $fv1f, 0x0($v0)
    /* C0570 002BF970 8D220000 */  lw         $v0, 0x0($t1)
    /* C0574 002BF974 C5030004 */  lwc1       $fv1f, 0x4($t0)
    /* C0578 002BF978 000210C0 */  sll        $v0, $v0, 3
    /* C057C 002BF97C 00441021 */  addu       $v0, $v0, $a0
    /* C0580 002BF980 C4400004 */  lwc1       $fv0, 0x4($v0)
    /* C0584 002BF984 E5000004 */  swc1       $fv0, 0x4($t0)
    /* C0588 002BF988 8D220000 */  lw         $v0, 0x0($t1)
    /* C058C 002BF98C 000210C0 */  sll        $v0, $v0, 3
    /* C0590 002BF990 00441021 */  addu       $v0, $v0, $a0
    /* C0594 002BF994 E4430004 */  swc1       $fv1f, 0x4($v0)
    /* C0598 002BF998 25290004 */  addiu      $t1, $t1, 0x4
.Lauto_002BF99C:
    /* C059C 002BF99C 254A0001 */  addiu      $t2, $t2, 0x1
    /* C05A0 002BF9A0 0145102A */  slt        $v0, $t2, $a1
    /* C05A4 002BF9A4 1440FFE5 */  .word 0x1440FFE5
    /* C05A8 002BF9A8 25080008 */  addiu     $t0, $t0, 0x8
.Lauto_002BF9AC:
    /* C05AC 002BF9AC 240E0002 */  addiu      $t6, $zero, 0x2
    /* C05B0 002BF9B0 240F0001 */  addiu      $t7, $zero, 0x1
    /* C05B4 002BF9B4 01E56807 */  srav       $t5, $a1, $t7
    /* C05B8 002BF9B8 19A0003A */  .word 0x19A0003A
    /* C05BC 002BF9BC 01E52804 */  sllv      $a1, $a1, $t7
.Lauto_002BF9C0:
    /* C05C0 002BF9C0 19E00034 */  .word 0x19E00034
    /* C05C4 002BF9C4 00004821 */  addu      $t1, $zero, $zero
    /* C05C8 002BF9C8 44863000 */  mtc1       $a2, $ft1
    /* C05CC 002BF9CC 468031A0 */  cvt.s.w    $ft1, $ft1
    /* C05D0 002BF9D0 000E6040 */  sll        $t4, $t6, 1
    /* C05D4 002BF9D4 03005821 */  addu       $t3, $t8, $zero
    /* C05D8 002BF9D8 00E05021 */  addu       $t2, $a3, $zero
    /* C05DC 002BF9DC 00094040 */  sll        $t0, $t1, 1
.Lauto_002BF9E0:
    /* C05E0 002BF9E0 0105102A */  slt        $v0, $t0, $a1
    /* C05E4 002BF9E4 C5600000 */  lwc1       $fv0, 0x0($t3)
    /* C05E8 002BF9E8 C5440000 */  lwc1       $ft0, 0x0($t2)
    /* C05EC 002BF9EC 46003142 */  mul.s      $ft0f, $ft1, $fv0
    /* C05F0 002BF9F0 10400021 */  .word 0x10400021
    /* C05F4 002BF9F4 000910C0 */  sll       $v0, $t1, 3
    /* C05F8 002BF9F8 00441821 */  addu       $v1, $v0, $a0
    /* C05FC 002BF9FC 010E1021 */  addu       $v0, $t0, $t6
.Lauto_002BFA00:
    /* C0600 002BFA00 00021080 */  sll        $v0, $v0, 2
    /* C0604 002BFA04 00441021 */  addu       $v0, $v0, $a0
    /* C0608 002BFA08 C4410000 */  lwc1       $fv0f, 0x0($v0)
    /* C060C 002BFA0C 460120C2 */  mul.s      $fv1f, $ft0, $fv0f
    /* C0610 002BFA10 C4420004 */  lwc1       $fv1, 0x4($v0)
    /* C0614 002BFA14 46022802 */  mul.s      $fv0, $ft0f, $fv1
    /* C0618 002BFA18 00000000 */  nop
    /* C061C 002BFA1C 46022082 */  mul.s      $fv1, $ft0, $fv1
    /* C0620 002BFA20 00000000 */  nop
    /* C0624 002BFA24 46012842 */  mul.s      $fv0f, $ft0f, $fv0f
    /* C0628 002BFA28 460018C1 */  sub.s      $fv1f, $fv1f, $fv0
    /* C062C 002BFA2C C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C0630 002BFA30 46030001 */  sub.s      $fv0, $fv0, $fv1f
    /* C0634 002BFA34 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C0638 002BFA38 E4400000 */  swc1       $fv0, 0x0($v0)
    /* C063C 002BFA3C C4600004 */  lwc1       $fv0, 0x4($v1)
    /* C0640 002BFA40 46020001 */  sub.s      $fv0, $fv0, $fv1
    /* C0644 002BFA44 E4400004 */  swc1       $fv0, 0x4($v0)
    /* C0648 002BFA48 C4610000 */  lwc1       $fv0f, 0x0($v1)
    /* C064C 002BFA4C 46030840 */  add.s      $fv0f, $fv0f, $fv1f
    /* C0650 002BFA50 C4600004 */  lwc1       $fv0, 0x4($v1)
    /* C0654 002BFA54 010C4021 */  addu       $t0, $t0, $t4
    /* C0658 002BFA58 46020000 */  add.s      $fv0, $fv0, $fv1
    /* C065C 002BFA5C 000C1080 */  sll        $v0, $t4, 2
    /* C0660 002BFA60 E4610000 */  swc1       $fv0f, 0x0($v1)
    /* C0664 002BFA64 E4600004 */  swc1       $fv0, 0x4($v1)
    /* C0668 002BFA68 00621821 */  addu       $v1, $v1, $v0
    /* C066C 002BFA6C 0105102A */  slt        $v0, $t0, $a1
    /* C0670 002BFA70 1440FFE3 */  .word 0x1440FFE3
    /* C0674 002BFA74 010E1021 */  addu      $v0, $t0, $t6
.Lauto_002BFA78:
    /* C0678 002BFA78 000D1080 */  sll        $v0, $t5, 2
    /* C067C 002BFA7C 01625821 */  addu       $t3, $t3, $v0
    /* C0680 002BFA80 01425021 */  addu       $t2, $t2, $v0
    /* C0684 002BFA84 25290001 */  addiu      $t1, $t1, 0x1
    /* C0688 002BFA88 012F102A */  slt        $v0, $t1, $t7
    /* C068C 002BFA8C 5440FFD4 */  .word 0x5440FFD4
    /* C0690 002BFA90 00094040 */  sll       $t0, $t1, 1
.Lauto_002BFA94:
    /* C0694 002BFA94 000D6843 */  sra        $t5, $t5, 1
    /* C0698 002BFA98 000F7840 */  sll        $t7, $t7, 1
    /* C069C 002BFA9C 1DA0FFC8 */  .word 0x1DA0FFC8
    /* C06A0 002BFAA0 000E7040 */  sll       $t6, $t6, 1
.Lauto_002BFAA4:
    /* C06A4 002BFAA4 03E00008 */  jr         $ra
    /* C06A8 002BFAA8 00000000 */  nop
.globl adecImdctFrame
adecImdctFrame:
    /* C06AC 002BFAAC 27BDF7D0 */  addiu      $sp, $sp, -0x830
    /* C06B0 002BFAB0 AFB20820 */  sw         $s2, 0x820($sp)
    /* C06B4 002BFAB4 00809021 */  addu       $s2, $a0, $zero
    /* C06B8 002BFAB8 AFB00818 */  sw         $s0, 0x818($sp)
    /* C06BC 002BFABC 3C10800D */  lui        $s0, %hi(D_auto_800D54C0)
    /* C06C0 002BFAC0 261054C0 */  addiu      $s0, $s0, %lo(D_auto_800D54C0)
    /* C06C4 002BFAC4 AFBF0824 */  sw         $ra, 0x824($sp)
    /* C06C8 002BFAC8 AFB1081C */  sw         $s1, 0x81C($sp)
    /* C06CC 002BFACC F7B40828 */  sdc1       $fs0, 0x828($sp)
    /* C06D0 002BFAD0 86020000 */  lh         $v0, 0x0($s0)
    /* C06D4 002BFAD4 14400009 */  .word 0x14400009
    /* C06D8 002BFAD8 00A08821 */  addu      $s1, $a1, $zero
    /* C06DC 002BFADC 0C0AFD45 */  jal        mdctInitTwiddles
    /* C06E0 002BFAE0 00000000 */  nop
    /* C06E4 002BFAE4 0C0AFD9F */  jal        mdctFftInit
    /* C06E8 002BFAE8 24040080 */  addiu     $a0, $zero, 0x80
    /* C06EC 002BFAEC 3C018015 */  lui        $at, %hi(D_auto_8014B830)
    /* C06F0 002BFAF0 AC22B830 */  sw         $v0, %lo(D_auto_8014B830)($at)
    /* C06F4 002BFAF4 24020001 */  addiu      $v0, $zero, 0x1
    /* C06F8 002BFAF8 A6020000 */  sh         $v0, 0x0($s0)
.Lauto_002BFAFC:
    /* C06FC 002BFAFC 3C01800C */  lui        $at, %hi(D_auto_800C7CD8)
    /* C0700 002BFB00 C4347CD8 */  lwc1       $fs0, %lo(D_auto_800C7CD8)($at)
    /* C0704 002BFB04 27B00418 */  addiu      $s0, $sp, 0x418
    /* C0708 002BFB08 02002021 */  addu       $a0, $s0, $zero
    /* C070C 002BFB0C 0C0AFE01 */  jal        adecDequantize
    /* C0710 002BFB10 26250018 */  addiu     $a1, $s1, 0x18
    /* C0714 002BFB14 27A60018 */  addiu      $a2, $sp, 0x18
    /* C0718 002BFB18 00002821 */  addu       $a1, $zero, $zero
    /* C071C 002BFB1C 240700FF */  addiu      $a3, $zero, 0xFF
.Lauto_002BFB20:
    /* C0720 002BFB20 00051C00 */  sll        $v1, $a1, 16
    /* C0724 002BFB24 00031C03 */  sra        $v1, $v1, 16
    /* C0728 002BFB28 000320C0 */  sll        $a0, $v1, 3
    /* C072C 002BFB2C 00901021 */  addu       $v0, $a0, $s0
    /* C0730 002BFB30 00862021 */  addu       $a0, $a0, $a2
    /* C0734 002BFB34 00031840 */  sll        $v1, $v1, 1
    /* C0738 002BFB38 00E31823 */  subu       $v1, $a3, $v1
    /* C073C 002BFB3C 00031880 */  sll        $v1, $v1, 2
    /* C0740 002BFB40 00701821 */  addu       $v1, $v1, $s0
    /* C0744 002BFB44 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0748 002BFB48 24A20001 */  addiu      $v0, $a1, 0x1
    /* C074C 002BFB4C 00402821 */  addu       $a1, $v0, $zero
    /* C0750 002BFB50 00021400 */  sll        $v0, $v0, 16
    /* C0754 002BFB54 00021403 */  sra        $v0, $v0, 16
    /* C0758 002BFB58 E4800000 */  swc1       $fv0, 0x0($a0)
    /* C075C 002BFB5C C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C0760 002BFB60 28420080 */  slti       $v0, $v0, 0x80
    /* C0764 002BFB64 1440FFEE */  .word 0x1440FFEE
    /* C0768 002BFB68 E4800004 */  swc1      $fv0, 0x4($a0)
    /* C076C 002BFB6C 27A60018 */  addiu      $a2, $sp, 0x18
    /* C0770 002BFB70 3C088015 */  lui        $t0, %hi(D_auto_8014AE30)
    /* C0774 002BFB74 2508AE30 */  addiu      $t0, $t0, %lo(D_auto_8014AE30)
    /* C0778 002BFB78 3C078015 */  lui        $a3, %hi(D_auto_8014B030)
    /* C077C 002BFB7C 24E7B030 */  addiu      $a3, $a3, %lo(D_auto_8014B030)
    /* C0780 002BFB80 00002821 */  addu       $a1, $zero, $zero
.Lauto_002BFB84:
    /* C0784 002BFB84 00051400 */  sll        $v0, $a1, 16
    /* C0788 002BFB88 00021403 */  sra        $v0, $v0, 16
    /* C078C 002BFB8C 000220C0 */  sll        $a0, $v0, 3
    /* C0790 002BFB90 00862021 */  addu       $a0, $a0, $a2
    /* C0794 002BFB94 00021080 */  sll        $v0, $v0, 2
    /* C0798 002BFB98 00481821 */  addu       $v1, $v0, $t0
    /* C079C 002BFB9C C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C07A0 002BFBA0 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C07A4 002BFBA4 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C07A8 002BFBA8 00471021 */  addu       $v0, $v0, $a3
    /* C07AC 002BFBAC C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C07B0 002BFBB0 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C07B4 002BFBB4 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C07B8 002BFBB8 00000000 */  nop
    /* C07BC 002BFBBC 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C07C0 002BFBC0 00000000 */  nop
    /* C07C4 002BFBC4 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C07C8 002BFBC8 24A20001 */  addiu      $v0, $a1, 0x1
    /* C07CC 002BFBCC 00402821 */  addu       $a1, $v0, $zero
    /* C07D0 002BFBD0 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C07D4 002BFBD4 00021400 */  sll        $v0, $v0, 16
    /* C07D8 002BFBD8 00021403 */  sra        $v0, $v0, 16
    /* C07DC 002BFBDC 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C07E0 002BFBE0 28420080 */  slti       $v0, $v0, 0x80
    /* C07E4 002BFBE4 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C07E8 002BFBE8 1440FFE6 */  .word 0x1440FFE6
    /* C07EC 002BFBEC E4820004 */  swc1      $fv1, 0x4($a0)
    /* C07F0 002BFBF0 3C038015 */  lui        $v1, %hi(D_auto_8014B830)
    /* C07F4 002BFBF4 8C63B830 */  lw         $v1, %lo(D_auto_8014B830)($v1)
    /* C07F8 002BFBF8 8C620004 */  lw         $v0, 0x4($v1)
    /* C07FC 002BFBFC 27B00018 */  addiu      $s0, $sp, 0x18
    /* C0800 002BFC00 AFA20010 */  sw         $v0, 0x10($sp)
    /* C0804 002BFC04 8C620008 */  lw         $v0, 0x8($v1)
    /* C0808 002BFC08 02002021 */  addu       $a0, $s0, $zero
    /* C080C 002BFC0C AFA20014 */  sw         $v0, 0x14($sp)
    /* C0810 002BFC10 8C65000C */  lw         $a1, 0xC($v1)
    /* C0814 002BFC14 8C670000 */  lw         $a3, 0x0($v1)
    /* C0818 002BFC18 0C0AFE4A */  jal        mdctFft
    /* C081C 002BFC1C 2406FFFF */  addiu     $a2, $zero, -0x1
    /* C0820 002BFC20 3C078015 */  lui        $a3, %hi(D_auto_8014B230)
    /* C0824 002BFC24 24E7B230 */  addiu      $a3, $a3, %lo(D_auto_8014B230)
    /* C0828 002BFC28 3C068015 */  lui        $a2, %hi(D_auto_8014B430)
    /* C082C 002BFC2C 24C6B430 */  addiu      $a2, $a2, %lo(D_auto_8014B430)
    /* C0830 002BFC30 00002821 */  addu       $a1, $zero, $zero
.Lauto_002BFC34:
    /* C0834 002BFC34 00051400 */  sll        $v0, $a1, 16
    /* C0838 002BFC38 00021403 */  sra        $v0, $v0, 16
    /* C083C 002BFC3C 000220C0 */  sll        $a0, $v0, 3
    /* C0840 002BFC40 00902021 */  addu       $a0, $a0, $s0
    /* C0844 002BFC44 00021080 */  sll        $v0, $v0, 2
    /* C0848 002BFC48 00471821 */  addu       $v1, $v0, $a3
    /* C084C 002BFC4C C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C0850 002BFC50 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C0854 002BFC54 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C0858 002BFC58 00461021 */  addu       $v0, $v0, $a2
    /* C085C 002BFC5C C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C0860 002BFC60 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0864 002BFC64 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C0868 002BFC68 00000000 */  nop
    /* C086C 002BFC6C 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C0870 002BFC70 00000000 */  nop
    /* C0874 002BFC74 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C0878 002BFC78 24A20001 */  addiu      $v0, $a1, 0x1
    /* C087C 002BFC7C 00402821 */  addu       $a1, $v0, $zero
    /* C0880 002BFC80 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C0884 002BFC84 00021400 */  sll        $v0, $v0, 16
    /* C0888 002BFC88 00021403 */  sra        $v0, $v0, 16
    /* C088C 002BFC8C 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C0890 002BFC90 28420080 */  slti       $v0, $v0, 0x80
    /* C0894 002BFC94 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C0898 002BFC98 1440FFE6 */  .word 0x1440FFE6
    /* C089C 002BFC9C E4820004 */  swc1      $fv1, 0x4($a0)
    /* C08A0 002BFCA0 00003821 */  addu       $a3, $zero, $zero
    /* C08A4 002BFCA4 3C0C8015 */  lui        $t4, %hi(D_auto_8014B630)
    /* C08A8 002BFCA8 258CB630 */  addiu      $t4, $t4, %lo(D_auto_8014B630)
    /* C08AC 002BFCAC 3C0B8015 */  lui        $t3, %hi(D_auto_8014AE30)
    /* C08B0 002BFCB0 256BAE30 */  addiu      $t3, $t3, %lo(D_auto_8014AE30)
    /* C08B4 002BFCB4 27A80018 */  addiu      $t0, $sp, 0x18
    /* C08B8 002BFCB8 3C0A8015 */  lui        $t2, %hi(D_auto_8014B030)
    /* C08BC 002BFCBC 254AB030 */  addiu      $t2, $t2, %lo(D_auto_8014B030)
    /* C08C0 002BFCC0 240900FF */  addiu      $t1, $zero, 0xFF
    /* C08C4 002BFCC4 44804800 */  mtc1       $zero, $ft2f
    /* C08C8 002BFCC8 3C01800C */  lui        $at, %hi(D_auto_800C7CDC)
    /* C08CC 002BFCCC C4287CDC */  lwc1       $ft2, %lo(D_auto_800C7CDC)($at)
    /* C08D0 002BFCD0 3C01800C */  lui        $at, %hi(D_auto_800C7CE0)
    /* C08D4 002BFCD4 C4277CE0 */  lwc1       $ft1f, %lo(D_auto_800C7CE0)($at)
    /* C08D8 002BFCD8 3C01800C */  lui        $at, %hi(D_auto_800C7CE0 + 0x4)
    /* C08DC 002BFCDC C4267CE4 */  lwc1       $ft1, %lo(D_auto_800C7CE0 + 0x4)($at)
    /* C08E0 002BFCE0 00071C00 */  sll        $v1, $a3, 16
.Lauto_002BFCE4:
    /* C08E4 002BFCE4 00031C03 */  sra        $v1, $v1, 16
    /* C08E8 002BFCE8 00032080 */  sll        $a0, $v1, 2
    /* C08EC 002BFCEC 008C3021 */  addu       $a2, $a0, $t4
    /* C08F0 002BFCF0 008B2821 */  addu       $a1, $a0, $t3
    /* C08F4 002BFCF4 000310C0 */  sll        $v0, $v1, 3
    /* C08F8 002BFCF8 34420004 */  ori        $v0, $v0, 0x4
    /* C08FC 002BFCFC C4C40000 */  lwc1       $ft0, 0x0($a2)
    /* C0900 002BFD00 C4A50000 */  lwc1       $ft0f, 0x0($a1)
    /* C0904 002BFD04 01021021 */  addu       $v0, $t0, $v0
    /* C0908 002BFD08 46052042 */  mul.s      $fv0f, $ft0, $ft0f
    /* C090C 002BFD0C 008A2021 */  addu       $a0, $a0, $t2
    /* C0910 002BFD10 C4430000 */  lwc1       $fv1f, 0x0($v0)
    /* C0914 002BFD14 C4800000 */  lwc1       $fv0, 0x0($a0)
    /* C0918 002BFD18 46001882 */  mul.s      $fv1, $fv1f, $fv0
    /* C091C 002BFD1C 00000000 */  nop
    /* C0920 002BFD20 46002102 */  mul.s      $ft0, $ft0, $fv0
    /* C0924 002BFD24 00000000 */  nop
    /* C0928 002BFD28 460518C2 */  mul.s      $fv1f, $fv1f, $ft0f
    /* C092C 002BFD2C 46020840 */  add.s      $fv0f, $fv0f, $fv1
    /* C0930 002BFD30 4601A042 */  mul.s      $fv0f, $fs0, $fv0f
    /* C0934 002BFD34 000318C0 */  sll        $v1, $v1, 3
    /* C0938 002BFD38 01031821 */  addu       $v1, $t0, $v1
    /* C093C 002BFD3C C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C0940 002BFD40 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C0944 002BFD44 E4C00000 */  swc1       $fv0, 0x0($a2)
    /* C0948 002BFD48 4601483E */  c.le.s     $ft2f, $fv0f
    /* C094C 002BFD4C 00000000 */  nop
    /* C0950 002BFD50 45000008 */  .word 0x45000008
    /* C0954 002BFD54 46000806 */  mov.s     $fv0, $fv0f
    /* C0958 002BFD58 46080800 */  add.s      $fv0, $fv0f, $ft2
    /* C095C 002BFD5C 4600383C */  c.lt.s     $ft1f, $fv0
    /* C0960 002BFD60 00000000 */  nop
    /* C0964 002BFD64 45030008 */  .word 0x45030008
    /* C0968 002BFD68 46003806 */  mov.s     $fv0, $ft1f
    /* C096C 002BFD6C 080AFF62 */  .word 0x080AFF62
    /* C0970 002BFD70 00000000 */  nop
.Lauto_002BFD74:
    /* C0974 002BFD74 46080001 */  sub.s      $fv0, $fv0, $ft2
    /* C0978 002BFD78 4606003C */  c.lt.s     $fv0, $ft1
    /* C097C 002BFD7C 00000000 */  nop
    /* C0980 002BFD80 45030001 */  .word 0x45030001
    /* C0984 002BFD84 46003006 */  mov.s     $fv0, $ft1
.Lauto_002BFD88:
    /* C0988 002BFD88 4600028D */  trunc.w.s  $ft3, $fv0
    /* C098C 002BFD8C 44035000 */  mfc1       $v1, $ft3
    /* C0990 002BFD90 4604A102 */  mul.s      $ft0, $fs0, $ft0
    /* C0994 002BFD94 00071400 */  sll        $v0, $a3, 16
    /* C0998 002BFD98 00021383 */  sra        $v0, $v0, 14
    /* C099C 002BFD9C 00521021 */  addu       $v0, $v0, $s2
    /* C09A0 002BFDA0 A4430000 */  sh         $v1, 0x0($v0)
    /* C09A4 002BFDA4 4604483E */  c.le.s     $ft2f, $ft0
    /* C09A8 002BFDA8 00000000 */  nop
    /* C09AC 002BFDAC 45000008 */  .word 0x45000008
    /* C09B0 002BFDB0 46002006 */  mov.s     $fv0, $ft0
    /* C09B4 002BFDB4 46082100 */  add.s      $ft0, $ft0, $ft2
    /* C09B8 002BFDB8 4604383C */  c.lt.s     $ft1f, $ft0
    /* C09BC 002BFDBC 00000000 */  nop
    /* C09C0 002BFDC0 45030008 */  .word 0x45030008
    /* C09C4 002BFDC4 46003906 */  mov.s     $ft0, $ft1f
    /* C09C8 002BFDC8 080AFF79 */  .word 0x080AFF79
    /* C09CC 002BFDCC 00000000 */  nop
.Lauto_002BFDD0:
    /* C09D0 002BFDD0 46080101 */  sub.s      $ft0, $fv0, $ft2
    /* C09D4 002BFDD4 4606203C */  c.lt.s     $ft0, $ft1
    /* C09D8 002BFDD8 00000000 */  nop
    /* C09DC 002BFDDC 45030001 */  .word 0x45030001
    /* C09E0 002BFDE0 46003106 */  mov.s     $ft0, $ft1
.Lauto_002BFDE4:
    /* C09E4 002BFDE4 4600228D */  trunc.w.s  $ft3, $ft0
    /* C09E8 002BFDE8 44035000 */  mfc1       $v1, $ft3
    /* C09EC 002BFDEC 00071400 */  sll        $v0, $a3, 16
    /* C09F0 002BFDF0 000213C3 */  sra        $v0, $v0, 15
    /* C09F4 002BFDF4 01221023 */  subu       $v0, $t1, $v0
    /* C09F8 002BFDF8 00021040 */  sll        $v0, $v0, 1
    /* C09FC 002BFDFC 00521021 */  addu       $v0, $v0, $s2
    /* C0A00 002BFE00 A4430000 */  sh         $v1, 0x0($v0)
    /* C0A04 002BFE04 24E20001 */  addiu      $v0, $a3, 0x1
    /* C0A08 002BFE08 00403821 */  addu       $a3, $v0, $zero
    /* C0A0C 002BFE0C 00021400 */  sll        $v0, $v0, 16
    /* C0A10 002BFE10 00021403 */  sra        $v0, $v0, 16
    /* C0A14 002BFE14 28420080 */  slti       $v0, $v0, 0x80
    /* C0A18 002BFE18 5440FFB2 */  .word 0x5440FFB2
    /* C0A1C 002BFE1C 00071C00 */  sll       $v1, $a3, 16
    /* C0A20 002BFE20 8FBF0824 */  lw         $ra, 0x824($sp)
    /* C0A24 002BFE24 8FB20820 */  lw         $s2, 0x820($sp)
    /* C0A28 002BFE28 8FB1081C */  lw         $s1, 0x81C($sp)
    /* C0A2C 002BFE2C 8FB00818 */  lw         $s0, 0x818($sp)
    /* C0A30 002BFE30 D7B40828 */  ldc1       $fs0, 0x828($sp)
    /* C0A34 002BFE34 03E00008 */  jr         $ra
    /* C0A38 002BFE38 27BD0830 */  addiu     $sp, $sp, 0x830
.globl adecDecodeFrameOk
adecDecodeFrameOk:
    /* C0A3C 002BFE3C 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C0A40 002BFE40 AFBF0010 */  sw         $ra, 0x10($sp)
    /* C0A44 002BFE44 0C0AFCE2 */  jal        adecDecodeFrame
    /* C0A48 002BFE48 00000000 */  nop
    /* C0A4C 002BFE4C 00021400 */  sll        $v0, $v0, 16
    /* C0A50 002BFE50 00021403 */  sra        $v0, $v0, 16
    /* C0A54 002BFE54 00021027 */  nor        $v0, $zero, $v0
    /* C0A58 002BFE58 8FBF0010 */  lw         $ra, 0x10($sp)
    /* C0A5C 002BFE5C 000217C2 */  srl        $v0, $v0, 31
    /* C0A60 002BFE60 03E00008 */  jr         $ra
    /* C0A64 002BFE64 27BD0018 */  addiu     $sp, $sp, 0x18
.globl mdctBuildBitrevTable
mdctBuildBitrevTable:
    /* C0A68 002BFE68 00805021 */  addu       $t2, $a0, $zero
    /* C0A6C 002BFE6C 00A04821 */  addu       $t1, $a1, $zero
    /* C0A70 002BFE70 00003821 */  addu       $a3, $zero, $zero
    /* C0A74 002BFE74 19200007 */  .word 0x19200007
    /* C0A78 002BFE78 00094040 */  sll       $t0, $t1, 1
    /* C0A7C 002BFE7C 01401821 */  addu       $v1, $t2, $zero
.Lauto_002BFE80:
    /* C0A80 002BFE80 AC670000 */  sw         $a3, 0x0($v1)
    /* C0A84 002BFE84 24E70001 */  addiu      $a3, $a3, 0x1
    /* C0A88 002BFE88 00E9102A */  slt        $v0, $a3, $t1
    /* C0A8C 002BFE8C 1440FFFC */  .word 0x1440FFFC
    /* C0A90 002BFE90 24630004 */  addiu     $v1, $v1, 0x4
.Lauto_002BFE94:
    /* C0A94 002BFE94 24060001 */  addiu      $a2, $zero, 0x1
    /* C0A98 002BFE98 19000023 */  .word 0x19000023
    /* C0A9C 002BFE9C 00C03821 */  addu      $a3, $a2, $zero
.Lauto_002BFEA0:
    /* C0AA0 002BFEA0 00E6102A */  slt        $v0, $a3, $a2
    /* C0AA4 002BFEA4 10400010 */  .word 0x10400010
    /* C0AA8 002BFEA8 24C4FFFF */  addiu     $a0, $a2, -0x1
    /* C0AAC 002BFEAC 000417C2 */  srl        $v0, $a0, 31
    /* C0AB0 002BFEB0 00822021 */  addu       $a0, $a0, $v0
    /* C0AB4 002BFEB4 00042043 */  sra        $a0, $a0, 1
    /* C0AB8 002BFEB8 00042080 */  sll        $a0, $a0, 2
    /* C0ABC 002BFEBC 008A2021 */  addu       $a0, $a0, $t2
    /* C0AC0 002BFEC0 24E2FFFF */  addiu      $v0, $a3, -0x1
    /* C0AC4 002BFEC4 00021FC2 */  srl        $v1, $v0, 31
    /* C0AC8 002BFEC8 00431021 */  addu       $v0, $v0, $v1
    /* C0ACC 002BFECC 00021043 */  sra        $v0, $v0, 1
    /* C0AD0 002BFED0 00021080 */  sll        $v0, $v0, 2
    /* C0AD4 002BFED4 004A1021 */  addu       $v0, $v0, $t2
    /* C0AD8 002BFED8 8C430000 */  lw         $v1, 0x0($v0)
    /* C0ADC 002BFEDC 8C850000 */  lw         $a1, 0x0($a0)
    /* C0AE0 002BFEE0 AC830000 */  sw         $v1, 0x0($a0)
    /* C0AE4 002BFEE4 AC450000 */  sw         $a1, 0x0($v0)
.Lauto_002BFEE8:
    /* C0AE8 002BFEE8 01201821 */  addu       $v1, $t1, $zero
    /* C0AEC 002BFEEC 28620002 */  slti       $v0, $v1, 0x2
    /* C0AF0 002BFEF0 5440000A */  .word 0x5440000A
    /* C0AF4 002BFEF4 24E70002 */  addiu     $a3, $a3, 0x2
    /* C0AF8 002BFEF8 0066102A */  slt        $v0, $v1, $a2
.Lauto_002BFEFC:
    /* C0AFC 002BFEFC 50400007 */  .word 0x50400007
    /* C0B00 002BFF00 24E70002 */  addiu     $a3, $a3, 0x2
    /* C0B04 002BFF04 00C33023 */  subu       $a2, $a2, $v1
    /* C0B08 002BFF08 00031843 */  sra        $v1, $v1, 1
    /* C0B0C 002BFF0C 28620002 */  slti       $v0, $v1, 0x2
    /* C0B10 002BFF10 1040FFFA */  .word 0x1040FFFA
    /* C0B14 002BFF14 0066102A */  slt       $v0, $v1, $a2
    /* C0B18 002BFF18 24E70002 */  addiu      $a3, $a3, 0x2
.Lauto_002BFF1C:
    /* C0B1C 002BFF1C 0107102A */  slt        $v0, $t0, $a3
    /* C0B20 002BFF20 1040FFDF */  .word 0x1040FFDF
    /* C0B24 002BFF24 00C33021 */  addu      $a2, $a2, $v1
.Lauto_002BFF28:
    /* C0B28 002BFF28 03E00008 */  jr         $ra
    /* C0B2C 002BFF2C 00000000 */  nop
.globl mdctPackSpectrum
mdctPackSpectrum:
    /* C0B30 002BFF30 00804021 */  addu       $t0, $a0, $zero
    /* C0B34 002BFF34 00003021 */  addu       $a2, $zero, $zero
    /* C0B38 002BFF38 240700FF */  addiu      $a3, $zero, 0xFF
.Lauto_002BFF3C:
    /* C0B3C 002BFF3C 00061C00 */  sll        $v1, $a2, 16
    /* C0B40 002BFF40 00031C03 */  sra        $v1, $v1, 16
    /* C0B44 002BFF44 000320C0 */  sll        $a0, $v1, 3
    /* C0B48 002BFF48 00851021 */  addu       $v0, $a0, $a1
    /* C0B4C 002BFF4C 00882021 */  addu       $a0, $a0, $t0
    /* C0B50 002BFF50 00031840 */  sll        $v1, $v1, 1
    /* C0B54 002BFF54 00E31823 */  subu       $v1, $a3, $v1
    /* C0B58 002BFF58 00031880 */  sll        $v1, $v1, 2
    /* C0B5C 002BFF5C 00651821 */  addu       $v1, $v1, $a1
    /* C0B60 002BFF60 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0B64 002BFF64 24C20001 */  addiu      $v0, $a2, 0x1
    /* C0B68 002BFF68 00403021 */  addu       $a2, $v0, $zero
    /* C0B6C 002BFF6C 00021400 */  sll        $v0, $v0, 16
    /* C0B70 002BFF70 00021403 */  sra        $v0, $v0, 16
    /* C0B74 002BFF74 E4800000 */  swc1       $fv0, 0x0($a0)
    /* C0B78 002BFF78 C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C0B7C 002BFF7C 28420080 */  slti       $v0, $v0, 0x80
    /* C0B80 002BFF80 1440FFEE */  .word 0x1440FFEE
    /* C0B84 002BFF84 E4800004 */  swc1      $fv0, 0x4($a0)
    /* C0B88 002BFF88 03E00008 */  jr         $ra
    /* C0B8C 002BFF8C 00000000 */  nop
.globl mdctTwiddleMul
mdctTwiddleMul:
    /* C0B90 002BFF90 00804021 */  addu       $t0, $a0, $zero
    /* C0B94 002BFF94 00003821 */  addu       $a3, $zero, $zero
.Lauto_002BFF98:
    /* C0B98 002BFF98 00071400 */  sll        $v0, $a3, 16
    /* C0B9C 002BFF9C 00021403 */  sra        $v0, $v0, 16
    /* C0BA0 002BFFA0 000220C0 */  sll        $a0, $v0, 3
    /* C0BA4 002BFFA4 00882021 */  addu       $a0, $a0, $t0
    /* C0BA8 002BFFA8 00021080 */  sll        $v0, $v0, 2
    /* C0BAC 002BFFAC 00451821 */  addu       $v1, $v0, $a1
    /* C0BB0 002BFFB0 C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C0BB4 002BFFB4 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C0BB8 002BFFB8 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C0BBC 002BFFBC 00461021 */  addu       $v0, $v0, $a2
    /* C0BC0 002BFFC0 C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C0BC4 002BFFC4 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0BC8 002BFFC8 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C0BCC 002BFFCC 00000000 */  nop
    /* C0BD0 002BFFD0 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C0BD4 002BFFD4 00000000 */  nop
    /* C0BD8 002BFFD8 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C0BDC 002BFFDC 24E20001 */  addiu      $v0, $a3, 0x1
    /* C0BE0 002BFFE0 00403821 */  addu       $a3, $v0, $zero
    /* C0BE4 002BFFE4 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C0BE8 002BFFE8 00021400 */  sll        $v0, $v0, 16
    /* C0BEC 002BFFEC 00021403 */  sra        $v0, $v0, 16
    /* C0BF0 002BFFF0 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C0BF4 002BFFF4 28420080 */  slti       $v0, $v0, 0x80
    /* C0BF8 002BFFF8 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C0BFC 002BFFFC 1440FFE6 */  .word 0x1440FFE6
    /* C0C00 002C0000 E4820004 */  swc1      $fv1, 0x4($a0)
    /* C0C04 002C0004 03E00008 */  jr         $ra
    /* C0C08 002C0008 00000000 */  nop
.globl mdctFftCtx
mdctFftCtx:
    /* C0C0C 002C000C 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* C0C10 002C0010 00A01021 */  addu       $v0, $a1, $zero
    /* C0C14 002C0014 AFBF0018 */  sw         $ra, 0x18($sp)
    /* C0C18 002C0018 8C430004 */  lw         $v1, 0x4($v0)
    /* C0C1C 002C001C AFA30010 */  sw         $v1, 0x10($sp)
    /* C0C20 002C0020 8C430008 */  lw         $v1, 0x8($v0)
    /* C0C24 002C0024 AFA30014 */  sw         $v1, 0x14($sp)
    /* C0C28 002C0028 8C45000C */  lw         $a1, 0xC($v0)
    /* C0C2C 002C002C 8C470000 */  lw         $a3, 0x0($v0)
    /* C0C30 002C0030 0C0AFE4A */  jal        mdctFft
    /* C0C34 002C0034 00000000 */  nop
    /* C0C38 002C0038 8FBF0018 */  lw         $ra, 0x18($sp)
    /* C0C3C 002C003C 03E00008 */  jr         $ra
    /* C0C40 002C0040 27BD0020 */  addiu     $sp, $sp, 0x20
.globl adecRoundClampS16
adecRoundClampS16:
    /* C0C44 002C0044 44800000 */  mtc1       $zero, $fv0
    /* C0C48 002C0048 460C003E */  c.le.s     $fv0, $fa0
    /* C0C4C 002C004C 00000000 */  nop
    /* C0C50 002C0050 45000009 */  .word 0x45000009
    /* C0C54 002C0054 00000000 */  nop
    /* C0C58 002C0058 3C01800C */  lui        $at, %hi(D_auto_800C7CE8)
    /* C0C5C 002C005C C4207CE8 */  lwc1       $fv0, %lo(D_auto_800C7CE8)($at)
    /* C0C60 002C0060 46006300 */  add.s      $fa0, $fa0, $fv0
    /* C0C64 002C0064 3C01800C */  lui        $at, %hi(D_auto_800C7CEC)
    /* C0C68 002C0068 C4207CEC */  lwc1       $fv0, %lo(D_auto_800C7CEC)($at)
    /* C0C6C 002C006C 460C003C */  c.lt.s     $fv0, $fa0
    /* C0C70 002C0070 080B0024 */  .word 0x080B0024
    /* C0C74 002C0074 00000000 */  nop
.Lauto_002C0078:
    /* C0C78 002C0078 3C01800C */  lui        $at, %hi(D_auto_800C7CF0)
    /* C0C7C 002C007C C4207CF0 */  lwc1       $fv0, %lo(D_auto_800C7CF0)($at)
    /* C0C80 002C0080 46006301 */  sub.s      $fa0, $fa0, $fv0
    /* C0C84 002C0084 3C01800C */  lui        $at, %hi(D_auto_800C7CF4)
    /* C0C88 002C0088 C4207CF4 */  lwc1       $fv0, %lo(D_auto_800C7CF4)($at)
    /* C0C8C 002C008C 4600603C */  c.lt.s     $fa0, $fv0
.Lauto_002C0090:
    /* C0C90 002C0090 00000000 */  nop
    /* C0C94 002C0094 45030001 */  .word 0x45030001
    /* C0C98 002C0098 46000306 */  mov.s     $fa0, $fv0
.Lauto_002C009C:
    /* C0C9C 002C009C 4600604D */  trunc.w.s  $fv0f, $fa0
    /* C0CA0 002C00A0 44020800 */  mfc1       $v0, $fv0f
    /* C0CA4 002C00A4 00021400 */  sll        $v0, $v0, 16
    /* C0CA8 002C00A8 03E00008 */  jr         $ra
    /* C0CAC 002C00AC 00021403 */  sra       $v0, $v0, 16
.globl adecStreamOpen
adecStreamOpen:
    /* C0CB0 002C00B0 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C0CB4 002C00B4 00A04021 */  addu       $t0, $a1, $zero
    /* C0CB8 002C00B8 3C038015 */  lui        $v1, %hi(D_auto_8014BA38)
    /* C0CBC 002C00BC 2463BA38 */  addiu      $v1, $v1, %lo(D_auto_8014BA38)
    /* C0CC0 002C00C0 AFBF0010 */  sw         $ra, 0x10($sp)
    /* C0CC4 002C00C4 AC640008 */  sw         $a0, 0x8($v1)
    /* C0CC8 002C00C8 AC640014 */  sw         $a0, 0x14($v1)
    /* C0CCC 002C00CC 8C870000 */  lw         $a3, 0x0($a0)
    /* C0CD0 002C00D0 24820004 */  addiu      $v0, $a0, 0x4
    /* C0CD4 002C00D4 AC620014 */  sw         $v0, 0x14($v1)
    /* C0CD8 002C00D8 AC670000 */  sw         $a3, 0x0($v1)
    /* C0CDC 002C00DC 8C820004 */  lw         $v0, 0x4($a0)
    /* C0CE0 002C00E0 3C0A0F42 */  lui        $t2, (0xF424000 >> 16)
    /* C0CE4 002C00E4 AC620010 */  sw         $v0, 0x10($v1)
    /* C0CE8 002C00E8 8C850004 */  lw         $a1, 0x4($a0)
    /* C0CEC 002C00EC 24820008 */  addiu      $v0, $a0, 0x8
    /* C0CF0 002C00F0 AC620014 */  sw         $v0, 0x14($v1)
    /* C0CF4 002C00F4 AC65000C */  sw         $a1, 0xC($v1)
    /* C0CF8 002C00F8 8C820008 */  lw         $v0, 0x8($a0)
    /* C0CFC 002C00FC 2484000C */  addiu      $a0, $a0, 0xC
    /* C0D00 002C0100 AC640014 */  sw         $a0, 0x14($v1)
    /* C0D04 002C0104 3C01800D */  lui        $at, %hi(D_auto_800D54BE)
    /* C0D08 002C0108 A42054BE */  sh         $zero, %lo(D_auto_800D54BE)($at)
    /* C0D0C 002C010C 3C01800D */  lui        $at, %hi(D_auto_800D54C0)
    /* C0D10 002C0110 A42054C0 */  sh         $zero, %lo(D_auto_800D54C0)($at)
    /* C0D14 002C0114 3C01800D */  lui        $at, %hi(D_auto_800D54B8)
    /* C0D18 002C0118 A42054B8 */  sh         $zero, %lo(D_auto_800D54B8)($at)
    /* C0D1C 002C011C 3C01800D */  lui        $at, %hi(D_auto_800D54BA)
    /* C0D20 002C0120 A42054BA */  sh         $zero, %lo(D_auto_800D54BA)($at)
    /* C0D24 002C0124 3C01800D */  lui        $at, %hi(D_auto_800D54BC)
    /* C0D28 002C0128 A42054BC */  sh         $zero, %lo(D_auto_800D54BC)($at)
    /* C0D2C 002C012C AC620004 */  sw         $v0, 0x4($v1)
    /* C0D30 002C0130 ACC70000 */  sw         $a3, 0x0($a2)
    /* C0D34 002C0134 8C620010 */  lw         $v0, 0x10($v1)
    /* C0D38 002C0138 354A4000 */  ori        $t2, $t2, (0xF424000 & 0xFFFF)
    /* C0D3C 002C013C 004A0018 */  mult       $v0, $t2
    /* C0D40 002C0140 01004821 */  addu       $t1, $t0, $zero
    /* C0D44 002C0144 00004021 */  addu       $t0, $zero, $zero
    /* C0D48 002C0148 01003021 */  addu       $a2, $t0, $zero
    /* C0D4C 002C014C 00002010 */  mfhi       $a0
    /* C0D50 002C0150 00002812 */  mflo       $a1
    /* C0D54 002C0154 0C0B0368 */  jal        __udivdi3
    /* C0D58 002C0158 01203821 */  addu      $a3, $t1, $zero
    /* C0D5C 002C015C 8FBF0010 */  lw         $ra, 0x10($sp)
    /* C0D60 002C0160 00601021 */  addu       $v0, $v1, $zero
    /* C0D64 002C0164 03E00008 */  jr         $ra
    /* C0D68 002C0168 27BD0018 */  addiu     $sp, $sp, 0x18
.globl adecNextFrame
adecNextFrame:
    /* C0D6C 002C016C 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* C0D70 002C0170 AFB20018 */  sw         $s2, 0x18($sp)
    /* C0D74 002C0174 3C128015 */  lui        $s2, %hi(D_auto_8014BA38)
    /* C0D78 002C0178 2652BA38 */  addiu      $s2, $s2, %lo(D_auto_8014BA38)
    /* C0D7C 002C017C AFBF001C */  sw         $ra, 0x1C($sp)
    /* C0D80 002C0180 AFB10014 */  sw         $s1, 0x14($sp)
    /* C0D84 002C0184 AFB00010 */  sw         $s0, 0x10($sp)
    /* C0D88 002C0188 8E420010 */  lw         $v0, 0x10($s2)
    /* C0D8C 002C018C 10400019 */  .word 0x10400019
    /* C0D90 002C0190 00001021 */  addu      $v0, $zero, $zero
    /* C0D94 002C0194 0C0AFCE2 */  jal        adecDecodeFrame
    /* C0D98 002C0198 02402021 */  addu      $a0, $s2, $zero
    /* C0D9C 002C019C 3C11800D */  lui        $s1, %hi(D_auto_800D54C2)
    /* C0DA0 002C01A0 263154C2 */  addiu      $s1, $s1, %lo(D_auto_800D54C2)
    /* C0DA4 002C01A4 96220000 */  lhu        $v0, 0x0($s1)
    /* C0DA8 002C01A8 24420001 */  addiu      $v0, $v0, 0x1
    /* C0DAC 002C01AC A6220000 */  sh         $v0, 0x0($s1)
    /* C0DB0 002C01B0 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C0DB4 002C01B4 2C420006 */  sltiu      $v0, $v0, 0x6
    /* C0DB8 002C01B8 50400001 */  .word 0x50400001
    /* C0DBC 002C01BC A6200000 */  sh        $zero, 0x0($s1)
.Lauto_002C01C0:
    /* C0DC0 002C01C0 3C108015 */  lui        $s0, %hi(D_auto_8014BCF0)
    /* C0DC4 002C01C4 2610BCF0 */  addiu      $s0, $s0, %lo(D_auto_8014BCF0)
    /* C0DC8 002C01C8 96240000 */  lhu        $a0, 0x0($s1)
    /* C0DCC 002C01CC 02402821 */  addu       $a1, $s2, $zero
    /* C0DD0 002C01D0 00042240 */  sll        $a0, $a0, 9
    /* C0DD4 002C01D4 0C0AFEAB */  jal        adecImdctFrame
    /* C0DD8 002C01D8 00902021 */  addu      $a0, $a0, $s0
    /* C0DDC 002C01DC 96220000 */  lhu        $v0, 0x0($s1)
    /* C0DE0 002C01E0 8E430010 */  lw         $v1, 0x10($s2)
    /* C0DE4 002C01E4 00021240 */  sll        $v0, $v0, 9
    /* C0DE8 002C01E8 00501021 */  addu       $v0, $v0, $s0
    /* C0DEC 002C01EC 2463FFFF */  addiu      $v1, $v1, -0x1
    /* C0DF0 002C01F0 AE430010 */  sw         $v1, 0x10($s2)
.Lauto_002C01F4:
    /* C0DF4 002C01F4 8FBF001C */  lw         $ra, 0x1C($sp)
    /* C0DF8 002C01F8 8FB20018 */  lw         $s2, 0x18($sp)
    /* C0DFC 002C01FC 8FB10014 */  lw         $s1, 0x14($sp)
    /* C0E00 002C0200 8FB00010 */  lw         $s0, 0x10($sp)
    /* C0E04 002C0204 03E00008 */  jr         $ra
    /* C0E08 002C0208 27BD0020 */  addiu     $sp, $sp, 0x20
.globl adecGetStopFlag
adecGetStopFlag:
    /* C0E0C 002C020C 3C028015 */  lui        $v0, %hi(D_auto_8014BA48)
    /* C0E10 002C0210 8C42BA48 */  lw         $v0, %lo(D_auto_8014BA48)($v0)
    /* C0E14 002C0214 03E00008 */  jr         $ra
    /* C0E18 002C0218 00000000 */  nop
.globl adecClearStopFlag
adecClearStopFlag:
    /* C0E1C 002C021C 3C018015 */  lui        $at, %hi(D_auto_8014BA48)
    /* C0E20 002C0220 AC20BA48 */  sw         $zero, %lo(D_auto_8014BA48)($at)
    /* C0E24 002C0224 03E00008 */  jr         $ra
    /* C0E28 002C0228 00000000 */  nop
