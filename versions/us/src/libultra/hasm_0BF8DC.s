.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBF8DC-0xC0D5C (VRAM 0x002BECDC) */
.globl D_auto_002BECDC
D_auto_002BECDC:
    /* BF8DC 002BECDC 72696453 */  .word 0x72696453
.globl adecReadBits
adecReadBits:
    /* BF8E0 002BECE0 27BDFFF8 */  addiu      $sp, $sp, -0x8
    /* BF8E4 002BECE4 AFB10004 */  sw         $s1, 0x4($sp)
    /* BF8E8 002BECE8 00808821 */  addu       $s1, $a0, $zero
    /* BF8EC 002BECEC 3C04800D */  lui        $a0, %hi(D_auto_800D4168)
    /* BF8F0 002BECF0 24844168 */  addiu      $a0, $a0, %lo(D_auto_800D4168)
    /* BF8F4 002BECF4 AFB00000 */  sw         $s0, 0x0($sp)
    /* BF8F8 002BECF8 94820000 */  lhu        $v0, 0x0($a0)
    /* BF8FC 002BECFC 8FB90018 */  lw         $t9, 0x18($sp)
    /* BF900 002BED00 1440000B */  .word 0x1440000B
    /* BF904 002BED04 30C2FFFF */  andi      $v0, $a2, 0xFFFF
    /* BF908 002BED08 8F220014 */  lw         $v0, 0x14($t9)
    /* BF90C 002BED0C 94430000 */  lhu        $v1, 0x0($v0)
    /* BF910 002BED10 24420002 */  addiu      $v0, $v0, 0x2
    /* BF914 002BED14 AF220014 */  sw         $v0, 0x14($t9)
    /* BF918 002BED18 24020010 */  addiu      $v0, $zero, 0x10
    /* BF91C 002BED1C A4820000 */  sh         $v0, 0x0($a0)
    /* BF920 002BED20 3C028015 */  lui        $v0, %hi(D_auto_80148E00)
    /* BF924 002BED24 24428E00 */  addiu      $v0, $v0, %lo(D_auto_80148E00)
    /* BF928 002BED28 A4430000 */  sh         $v1, 0x0($v0)
    /* BF92C 002BED2C 30C2FFFF */  andi       $v0, $a2, 0xFFFF
.Lauto_002BED30:
    /* BF930 002BED30 1040005B */  .word 0x1040005B
    /* BF934 002BED34 00004821 */  addu      $t1, $zero, $zero
    /* BF938 002BED38 00805021 */  addu       $t2, $a0, $zero
    /* BF93C 002BED3C 3C0B8015 */  lui        $t3, %hi(D_auto_80148E00)
    /* BF940 002BED40 256B8E00 */  addiu      $t3, $t3, %lo(D_auto_80148E00)
    /* BF944 002BED44 24100010 */  addiu      $s0, $zero, 0x10
    /* BF948 002BED48 02071004 */  sllv       $v0, $a3, $s0
    /* BF94C 002BED4C 02027807 */  srav       $t7, $v0, $s0
    /* BF950 002BED50 30ADFFFF */  andi       $t5, $a1, 0xFFFF
    /* BF954 002BED54 3C02800D */  lui        $v0, %hi(D_auto_800D4024)
    /* BF958 002BED58 24424024 */  addiu      $v0, $v0, %lo(D_auto_800D4024)
    /* BF95C 002BED5C 000D1840 */  sll        $v1, $t5, 1
    /* BF960 002BED60 00627021 */  addu       $t6, $v1, $v0
    /* BF964 002BED64 3C18800D */  lui        $t8, %hi(D_auto_800D4000)
    /* BF968 002BED68 27184000 */  addiu      $t8, $t8, %lo(D_auto_800D4000)
    /* BF96C 002BED6C 00786021 */  addu       $t4, $v1, $t8
.Lauto_002BED70:
    /* BF970 002BED70 95430000 */  lhu        $v1, 0x0($t2)
    /* BF974 002BED74 006D102B */  sltu       $v0, $v1, $t5
    /* BF978 002BED78 10400029 */  .word 0x10400029
    /* BF97C 002BED7C 3064FFFF */  andi      $a0, $v1, 0xFFFF
    /* BF980 002BED80 00A34023 */  subu       $t0, $a1, $v1
    /* BF984 002BED84 00042040 */  sll        $a0, $a0, 1
    /* BF988 002BED88 00982021 */  addu       $a0, $a0, $t8
    /* BF98C 002BED8C 00091400 */  sll        $v0, $t1, 16
    /* BF990 002BED90 000213C3 */  sra        $v0, $v0, 15
    /* BF994 002BED94 95630000 */  lhu        $v1, 0x0($t3)
    /* BF998 002BED98 94840000 */  lhu        $a0, 0x0($a0)
    /* BF99C 002BED9C 00513821 */  addu       $a3, $v0, $s1
    /* BF9A0 002BEDA0 00641824 */  and        $v1, $v1, $a0
    /* BF9A4 002BEDA4 3104FFFF */  andi       $a0, $t0, 0xFFFF
    /* BF9A8 002BEDA8 00831804 */  sllv       $v1, $v1, $a0
    /* BF9AC 002BEDAC A4E30000 */  sh         $v1, 0x0($a3)
    /* BF9B0 002BEDB0 8F220014 */  lw         $v0, 0x14($t9)
    /* BF9B4 002BEDB4 94430000 */  lhu        $v1, 0x0($v0)
    /* BF9B8 002BEDB8 24420002 */  addiu      $v0, $v0, 0x2
    /* BF9BC 002BEDBC AF220014 */  sw         $v0, 0x14($t9)
    /* BF9C0 002BEDC0 02041023 */  subu       $v0, $s0, $a0
    /* BF9C4 002BEDC4 00042040 */  sll        $a0, $a0, 1
    /* BF9C8 002BEDC8 00982021 */  addu       $a0, $a0, $t8
    /* BF9CC 002BEDCC A5630000 */  sh         $v1, 0x0($t3)
    /* BF9D0 002BEDD0 3063FFFF */  andi       $v1, $v1, 0xFFFF
    /* BF9D4 002BEDD4 00431807 */  srav       $v1, $v1, $v0
    /* BF9D8 002BEDD8 94820000 */  lhu        $v0, 0x0($a0)
    /* BF9DC 002BEDDC 94E40000 */  lhu        $a0, 0x0($a3)
    /* BF9E0 002BEDE0 00621824 */  and        $v1, $v1, $v0
    /* BF9E4 002BEDE4 00832025 */  or         $a0, $a0, $v1
    /* BF9E8 002BEDE8 11E0000B */  .word 0x11E0000B
    /* BF9EC 002BEDEC A4E40000 */  sh        $a0, 0x0($a3)
    /* BF9F0 002BEDF0 00041400 */  sll        $v0, $a0, 16
    /* BF9F4 002BEDF4 95C30000 */  lhu        $v1, 0x0($t6)
    /* BF9F8 002BEDF8 00021403 */  sra        $v0, $v0, 16
    /* BF9FC 002BEDFC 00431024 */  and        $v0, $v0, $v1
    /* BFA00 002BEE00 5040001E */  .word 0x5040001E
    /* BFA04 002BEE04 02081023 */  subu      $v0, $s0, $t0
    /* BFA08 002BEE08 95820000 */  lhu        $v0, 0x0($t4)
    /* BFA0C 002BEE0C 00021027 */  nor        $v0, $zero, $v0
    /* BFA10 002BEE10 00821025 */  or         $v0, $a0, $v0
    /* BFA14 002BEE14 A4E20000 */  sh         $v0, 0x0($a3)
.Lauto_002BEE18:
    /* BFA18 002BEE18 080AFB9F */  .word 0x080AFB9F
    /* BFA1C 002BEE1C 02081023 */  subu      $v0, $s0, $t0
.Lauto_002BEE20:
    /* BFA20 002BEE20 95430000 */  lhu        $v1, 0x0($t2)
    /* BFA24 002BEE24 95620000 */  lhu        $v0, 0x0($t3)
    /* BFA28 002BEE28 95840000 */  lhu        $a0, 0x0($t4)
    /* BFA2C 002BEE2C 006D1823 */  subu       $v1, $v1, $t5
    /* BFA30 002BEE30 00621007 */  srav       $v0, $v0, $v1
    /* BFA34 002BEE34 00442024 */  and        $a0, $v0, $a0
    /* BFA38 002BEE38 00091400 */  sll        $v0, $t1, 16
    /* BFA3C 002BEE3C 000213C3 */  sra        $v0, $v0, 15
    /* BFA40 002BEE40 00513821 */  addu       $a3, $v0, $s1
    /* BFA44 002BEE44 11E0000B */  .word 0x11E0000B
    /* BFA48 002BEE48 A4E40000 */  sh        $a0, 0x0($a3)
    /* BFA4C 002BEE4C 00041400 */  sll        $v0, $a0, 16
    /* BFA50 002BEE50 95C30000 */  lhu        $v1, 0x0($t6)
    /* BFA54 002BEE54 00021403 */  sra        $v0, $v0, 16
    /* BFA58 002BEE58 00431024 */  and        $v0, $v0, $v1
    /* BFA5C 002BEE5C 10400005 */  .word 0x10400005
    /* BFA60 002BEE60 00000000 */  nop
    /* BFA64 002BEE64 95820000 */  lhu        $v0, 0x0($t4)
    /* BFA68 002BEE68 00021027 */  nor        $v0, $zero, $v0
    /* BFA6C 002BEE6C 00821025 */  or         $v0, $a0, $v0
    /* BFA70 002BEE70 A4E20000 */  sh         $v0, 0x0($a3)
.Lauto_002BEE74:
    /* BFA74 002BEE74 95420000 */  lhu        $v0, 0x0($t2)
    /* BFA78 002BEE78 00451023 */  subu       $v0, $v0, $a1
.Lauto_002BEE7C:
    /* BFA7C 002BEE7C A5420000 */  sh         $v0, 0x0($t2)
    /* BFA80 002BEE80 25220001 */  addiu      $v0, $t1, 0x1
    /* BFA84 002BEE84 00404821 */  addu       $t1, $v0, $zero
    /* BFA88 002BEE88 00021400 */  sll        $v0, $v0, 16
    /* BFA8C 002BEE8C 00021403 */  sra        $v0, $v0, 16
    /* BFA90 002BEE90 30C3FFFF */  andi       $v1, $a2, 0xFFFF
    /* BFA94 002BEE94 0043102A */  slt        $v0, $v0, $v1
    /* BFA98 002BEE98 1440FFB5 */  .word 0x1440FFB5
    /* BFA9C 002BEE9C 00000000 */  nop
.Lauto_002BEEA0:
    /* BFAA0 002BEEA0 8FB10004 */  lw         $s1, 0x4($sp)
    /* BFAA4 002BEEA4 8FB00000 */  lw         $s0, 0x0($sp)
    /* BFAA8 002BEEA8 24020001 */  addiu      $v0, $zero, 0x1
    /* BFAAC 002BEEAC 03E00008 */  jr         $ra
    /* BFAB0 002BEEB0 27BD0008 */  addiu     $sp, $sp, 0x8
.globl adecHuffDecode
adecHuffDecode:
    /* BFAB4 002BEEB4 27BDFFA8 */  addiu      $sp, $sp, -0x58
    /* BFAB8 002BEEB8 00805021 */  addu       $t2, $a0, $zero
    /* BFABC 002BEEBC 00A04821 */  addu       $t1, $a1, $zero
    /* BFAC0 002BEEC0 AFB50044 */  sw         $s5, 0x44($sp)
    /* BFAC4 002BEEC4 0000A821 */  addu       $s5, $zero, $zero
    /* BFAC8 002BEEC8 AFB20038 */  sw         $s2, 0x38($sp)
    /* BFACC 002BEECC 02A09021 */  addu       $s2, $s5, $zero
    /* BFAD0 002BEED0 00E04021 */  addu       $t0, $a3, $zero
    /* BFAD4 002BEED4 AFB10034 */  sw         $s1, 0x34($sp)
    /* BFAD8 002BEED8 00061400 */  sll        $v0, $a2, 16
    /* BFADC 002BEEDC AFBF0054 */  sw         $ra, 0x54($sp)
    /* BFAE0 002BEEE0 AFBE0050 */  sw         $fp, 0x50($sp)
    /* BFAE4 002BEEE4 AFB7004C */  sw         $s7, 0x4C($sp)
    /* BFAE8 002BEEE8 AFB60048 */  sw         $s6, 0x48($sp)
    /* BFAEC 002BEEEC AFB40040 */  sw         $s4, 0x40($sp)
    /* BFAF0 002BEEF0 AFB3003C */  sw         $s3, 0x3C($sp)
    /* BFAF4 002BEEF4 AFB00030 */  sw         $s0, 0x30($sp)
    /* BFAF8 002BEEF8 A5000000 */  sh         $zero, 0x0($t0)
    /* BFAFC 002BEEFC 8D530010 */  lw         $s3, 0x10($t2)
    /* BFB00 002BEF00 00021C03 */  sra        $v1, $v0, 16
    /* BFB04 002BEF04 8E740020 */  lw         $s4, 0x20($s3)
    /* BFB08 002BEF08 186000DD */  .word 0x186000DD
    /* BFB0C 002BEF0C 02A08821 */  addu      $s1, $s5, $zero
    /* BFB10 002BEF10 3C1E800D */  lui        $fp, %hi(D_auto_800D416C)
    /* BFB14 002BEF14 27DE416C */  addiu      $fp, $fp, %lo(D_auto_800D416C)
    /* BFB18 002BEF18 3C17800D */  lui        $s7, %hi(D_auto_800D416A)
    /* BFB1C 002BEF1C 26F7416A */  addiu      $s7, $s7, %lo(D_auto_800D416A)
    /* BFB20 002BEF20 AFA20018 */  sw         $v0, 0x18($sp)
    /* BFB24 002BEF24 0060B021 */  addu       $s6, $v1, $zero
.Lauto_002BEF28:
    /* BFB28 002BEF28 97C30000 */  lhu        $v1, 0x0($fp)
    /* BFB2C 002BEF2C 106000B9 */  .word 0x106000B9
    /* BFB30 002BEF30 2463FFFF */  addiu     $v1, $v1, -0x1
    /* BFB34 002BEF34 96E20000 */  lhu        $v0, 0x0($s7)
    /* BFB38 002BEF38 A7C30000 */  sh         $v1, 0x0($fp)
    /* BFB3C 002BEF3C 30438000 */  andi       $v1, $v0, 0x8000
    /* BFB40 002BEF40 00021040 */  sll        $v0, $v0, 1
    /* BFB44 002BEF44 10600007 */  .word 0x10600007
    /* BFB48 002BEF48 A6E20000 */  sh        $v0, 0x0($s7)
    /* BFB4C 002BEF4C 00151400 */  sll        $v0, $s5, 16
    /* BFB50 002BEF50 00021383 */  sra        $v0, $v0, 14
    /* BFB54 002BEF54 00541021 */  addu       $v0, $v0, $s4
    /* BFB58 002BEF58 94440002 */  lhu        $a0, 0x2($v0)
    /* BFB5C 002BEF5C 080AFBDE */  .word 0x080AFBDE
    /* BFB60 002BEF60 00041400 */  sll       $v0, $a0, 16
.Lauto_002BEF64:
    /* BFB64 002BEF64 00151400 */  sll        $v0, $s5, 16
    /* BFB68 002BEF68 00021383 */  sra        $v0, $v0, 14
    /* BFB6C 002BEF6C 00541021 */  addu       $v0, $v0, $s4
    /* BFB70 002BEF70 94440000 */  lhu        $a0, 0x0($v0)
    /* BFB74 002BEF74 00041400 */  sll        $v0, $a0, 16
.Lauto_002BEF78:
    /* BFB78 002BEF78 00021383 */  sra        $v0, $v0, 14
    /* BFB7C 002BEF7C 00542821 */  addu       $a1, $v0, $s4
    /* BFB80 002BEF80 94A30000 */  lhu        $v1, 0x0($a1)
    /* BFB84 002BEF84 24020800 */  addiu      $v0, $zero, 0x800
    /* BFB88 002BEF88 146200B8 */  .word 0x146200B8
    /* BFB8C 002BEF8C 0080A821 */  addu      $s5, $a0, $zero
    /* BFB90 002BEF90 94B00002 */  lhu        $s0, 0x2($a1)
    /* BFB94 002BEF94 32040F00 */  andi       $a0, $s0, 0xF00
    /* BFB98 002BEF98 10800004 */  .word 0x10800004
    /* BFB9C 002BEF9C 0000A821 */  addu      $s5, $zero, $zero
    /* BFBA0 002BEFA0 24020F00 */  addiu      $v0, $zero, 0xF00
    /* BFBA4 002BEFA4 14820007 */  .word 0x14820007
    /* BFBA8 002BEFA8 00101400 */  sll       $v0, $s0, 16
.Lauto_002BEFAC:
    /* BFBAC 002BEFAC 00111400 */  sll        $v0, $s1, 16
    /* BFBB0 002BEFB0 000213C3 */  sra        $v0, $v0, 15
    /* BFBB4 002BEFB4 00491021 */  addu       $v0, $v0, $t1
    /* BFBB8 002BEFB8 A4500000 */  sh         $s0, 0x0($v0)
    /* BFBBC 002BEFBC 080AFC69 */  .word 0x080AFC69
    /* BFBC0 002BEFC0 26310001 */  addiu     $s1, $s1, 0x1
.Lauto_002BEFC4:
    /* BFBC4 002BEFC4 00021403 */  sra        $v0, $v0, 16
    /* BFBC8 002BEFC8 24030900 */  addiu      $v1, $zero, 0x900
    /* BFBCC 002BEFCC 14430020 */  .word 0x14430020
    /* BFBD0 002BEFD0 24020A00 */  addiu     $v0, $zero, 0xA00
    /* BFBD4 002BEFD4 02E02021 */  addu       $a0, $s7, $zero
    /* BFBD8 002BEFD8 24060001 */  addiu      $a2, $zero, 0x1
    /* BFBDC 002BEFDC 96F00000 */  lhu        $s0, 0x0($s7)
    /* BFBE0 002BEFE0 9665000E */  lhu        $a1, 0xE($s3)
    /* BFBE4 002BEFE4 8FAB0068 */  lw         $t3, 0x68($sp)
    /* BFBE8 002BEFE8 00003821 */  addu       $a3, $zero, $zero
    /* BFBEC 002BEFEC AFA80020 */  sw         $t0, 0x20($sp)
    /* BFBF0 002BEFF0 AFA90024 */  sw         $t1, 0x24($sp)
    /* BFBF4 002BEFF4 AFAA0028 */  sw         $t2, 0x28($sp)
    /* BFBF8 002BEFF8 0C0AFB38 */  jal        adecReadBits
    /* BFBFC 002BEFFC AFAB0010 */  sw        $t3, 0x10($sp)
    /* BFC00 002BF000 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BFC04 002BF004 8FA80020 */  lw         $t0, 0x20($sp)
    /* BFC08 002BF008 8FA90024 */  lw         $t1, 0x24($sp)
    /* BFC0C 002BF00C 8FAA0028 */  lw         $t2, 0x28($sp)
    /* BFC10 002BF010 10400091 */  .word 0x10400091
    /* BFC14 002BF014 00112400 */  sll       $a0, $s1, 16
    /* BFC18 002BF018 26310001 */  addiu      $s1, $s1, 0x1
    /* BFC1C 002BF01C 24020010 */  addiu      $v0, $zero, 0x10
    /* BFC20 002BF020 000423C3 */  sra        $a0, $a0, 15
    /* BFC24 002BF024 00892021 */  addu       $a0, $a0, $t1
    /* BFC28 002BF028 3C05800D */  lui        $a1, %hi(D_auto_800D416C)
    /* BFC2C 002BF02C 94A5416C */  lhu        $a1, %lo(D_auto_800D416C)($a1)
    /* BFC30 002BF030 96E30000 */  lhu        $v1, 0x0($s7)
    /* BFC34 002BF034 00451023 */  subu       $v0, $v0, $a1
    /* BFC38 002BF038 00431004 */  sllv       $v0, $v1, $v0
    /* BFC3C 002BF03C 00A31807 */  srav       $v1, $v1, $a1
    /* BFC40 002BF040 02031825 */  or         $v1, $s0, $v1
    /* BFC44 002BF044 A6E20000 */  sh         $v0, 0x0($s7)
    /* BFC48 002BF048 080AFC69 */  .word 0x080AFC69
    /* BFC4C 002BF04C A4830000 */  sh        $v1, 0x0($a0)
.Lauto_002BF050:
    /* BFC50 002BF050 14820023 */  .word 0x14820023
    /* BFC54 002BF054 24020B00 */  addiu     $v0, $zero, 0xB00
    /* BFC58 002BF058 00003021 */  addu       $a2, $zero, $zero
    /* BFC5C 002BF05C 320300FF */  andi       $v1, $s0, 0xFF
    /* BFC60 002BF060 000310C0 */  sll        $v0, $v1, 3
    /* BFC64 002BF064 00431023 */  subu       $v0, $v0, $v1
    /* BFC68 002BF068 000210C0 */  sll        $v0, $v0, 3
    /* BFC6C 002BF06C 00431023 */  subu       $v0, $v0, $v1
    /* BFC70 002BF070 000210C0 */  sll        $v0, $v0, 3
    /* BFC74 002BF074 00111C00 */  sll        $v1, $s1, 16
    /* BFC78 002BF078 8E64001C */  lw         $a0, 0x1C($s3)
    /* BFC7C 002BF07C 00031BC3 */  sra        $v1, $v1, 15
    /* BFC80 002BF080 00442821 */  addu       $a1, $v0, $a0
    /* BFC84 002BF084 8CA201A0 */  lw         $v0, 0x1A0($a1)
    /* BFC88 002BF088 18400011 */  .word 0x18400011
    /* BFC8C 002BF08C 00693821 */  addu      $a3, $v1, $t1
    /* BFC90 002BF090 00061400 */  sll        $v0, $a2, 16
.Lauto_002BF094:
    /* BFC94 002BF094 24C30001 */  addiu      $v1, $a2, 0x1
    /* BFC98 002BF098 00603021 */  addu       $a2, $v1, $zero
    /* BFC9C 002BF09C 00021403 */  sra        $v0, $v0, 16
    /* BFCA0 002BF0A0 00022040 */  sll        $a0, $v0, 1
    /* BFCA4 002BF0A4 00021080 */  sll        $v0, $v0, 2
    /* BFCA8 002BF0A8 00A21021 */  addu       $v0, $a1, $v0
    /* BFCAC 002BF0AC 00872021 */  addu       $a0, $a0, $a3
    /* BFCB0 002BF0B0 944200A2 */  lhu        $v0, 0xA2($v0)
    /* BFCB4 002BF0B4 00031C00 */  sll        $v1, $v1, 16
    /* BFCB8 002BF0B8 A4820000 */  sh         $v0, 0x0($a0)
    /* BFCBC 002BF0BC 8CA201A0 */  lw         $v0, 0x1A0($a1)
    /* BFCC0 002BF0C0 00031C03 */  sra        $v1, $v1, 16
    /* BFCC4 002BF0C4 0062182A */  slt        $v1, $v1, $v0
    /* BFCC8 002BF0C8 1460FFF2 */  .word 0x1460FFF2
    /* BFCCC 002BF0CC 00061400 */  sll       $v0, $a2, 16
.Lauto_002BF0D0:
    /* BFCD0 002BF0D0 00061400 */  sll        $v0, $a2, 16
    /* BFCD4 002BF0D4 00021403 */  sra        $v0, $v0, 16
    /* BFCD8 002BF0D8 080AFC69 */  .word 0x080AFC69
    /* BFCDC 002BF0DC 02228821 */  addu      $s1, $s1, $v0
.Lauto_002BF0E0:
    /* BFCE0 002BF0E0 14820031 */  .word 0x14820031
    /* BFCE4 002BF0E4 00112400 */  sll       $a0, $s1, 16
    /* BFCE8 002BF0E8 00111400 */  sll        $v0, $s1, 16
    /* BFCEC 002BF0EC 00021403 */  sra        $v0, $v0, 16
    /* BFCF0 002BF0F0 0056102A */  slt        $v0, $v0, $s6
    /* BFCF4 002BF0F4 1040000F */  .word 0x1040000F
    /* BFCF8 002BF0F8 00121C00 */  sll       $v1, $s2, 16
    /* BFCFC 002BF0FC 8FAB0018 */  lw         $t3, 0x18($sp)
    /* BFD00 002BF100 000B2403 */  sra        $a0, $t3, 16
.Lauto_002BF104:
    /* BFD04 002BF104 02201021 */  addu       $v0, $s1, $zero
    /* BFD08 002BF108 24430001 */  addiu      $v1, $v0, 0x1
    /* BFD0C 002BF10C 00608821 */  addu       $s1, $v1, $zero
    /* BFD10 002BF110 00021400 */  sll        $v0, $v0, 16
    /* BFD14 002BF114 000213C3 */  sra        $v0, $v0, 15
    /* BFD18 002BF118 00491021 */  addu       $v0, $v0, $t1
    /* BFD1C 002BF11C 00031C00 */  sll        $v1, $v1, 16
    /* BFD20 002BF120 00031C03 */  sra        $v1, $v1, 16
    /* BFD24 002BF124 0064182A */  slt        $v1, $v1, $a0
    /* BFD28 002BF128 1460FFF6 */  .word 0x1460FFF6
    /* BFD2C 002BF12C A4400000 */  sh        $zero, 0x0($v0)
    /* BFD30 002BF130 00121C00 */  sll        $v1, $s2, 16
.Lauto_002BF134:
    /* BFD34 002BF134 00031C03 */  sra        $v1, $v1, 16
    /* BFD38 002BF138 00031080 */  sll        $v0, $v1, 2
    /* BFD3C 002BF13C 00431021 */  addu       $v0, $v0, $v1
    /* BFD40 002BF140 00021080 */  sll        $v0, $v0, 2
    /* BFD44 002BF144 004A1021 */  addu       $v0, $v0, $t2
    /* BFD48 002BF148 8C430004 */  lw         $v1, 0x4($v0)
    /* BFD4C 002BF14C 8C420008 */  lw         $v0, 0x8($v0)
    /* BFD50 002BF150 080AFC63 */  .word 0x080AFC63
    /* BFD54 002BF154 00621821 */  addu      $v1, $v1, $v0
.Lauto_002BF158:
    /* BFD58 002BF158 00041C00 */  sll        $v1, $a0, 16
    /* BFD5C 002BF15C 95020000 */  lhu        $v0, 0x0($t0)
    /* BFD60 002BF160 00031C03 */  sra        $v1, $v1, 16
    /* BFD64 002BF164 24420001 */  addiu      $v0, $v0, 0x1
    /* BFD68 002BF168 A5020000 */  sh         $v0, 0x0($t0)
    /* BFD6C 002BF16C 00031080 */  sll        $v0, $v1, 2
    /* BFD70 002BF170 00431021 */  addu       $v0, $v0, $v1
    /* BFD74 002BF174 00021080 */  sll        $v0, $v0, 2
    /* BFD78 002BF178 004A1021 */  addu       $v0, $v0, $t2
    /* BFD7C 002BF17C 8C430004 */  lw         $v1, 0x4($v0)
    /* BFD80 002BF180 8C420008 */  lw         $v0, 0x8($v0)
    /* BFD84 002BF184 00809021 */  addu       $s2, $a0, $zero
    /* BFD88 002BF188 00621821 */  addu       $v1, $v1, $v0
.Lauto_002BF18C:
    /* BFD8C 002BF18C 02C3182A */  slt        $v1, $s6, $v1
    /* BFD90 002BF190 1060FFF1 */  .word 0x1060FFF1
    /* BFD94 002BF194 26440001 */  addiu     $a0, $s2, 0x1
    /* BFD98 002BF198 8FAB0018 */  lw         $t3, 0x18($sp)
    /* BFD9C 002BF19C 080AFCA2 */  .word 0x080AFCA2
    /* BFDA0 002BF1A0 000B1403 */  sra       $v0, $t3, 16
.Lauto_002BF1A4:
    /* BFDA4 002BF1A4 00112400 */  sll        $a0, $s1, 16
.Lauto_002BF1A8:
    /* BFDA8 002BF1A8 00121C00 */  sll        $v1, $s2, 16
    /* BFDAC 002BF1AC 00031C03 */  sra        $v1, $v1, 16
    /* BFDB0 002BF1B0 00031080 */  sll        $v0, $v1, 2
    /* BFDB4 002BF1B4 00431021 */  addu       $v0, $v0, $v1
    /* BFDB8 002BF1B8 00021080 */  sll        $v0, $v0, 2
    /* BFDBC 002BF1BC 004A1021 */  addu       $v0, $v0, $t2
    /* BFDC0 002BF1C0 8C430004 */  lw         $v1, 0x4($v0)
    /* BFDC4 002BF1C4 8C420008 */  lw         $v0, 0x8($v0)
    /* BFDC8 002BF1C8 00042403 */  sra        $a0, $a0, 16
    /* BFDCC 002BF1CC 00621821 */  addu       $v1, $v1, $v0
    /* BFDD0 002BF1D0 0083202A */  slt        $a0, $a0, $v1
    /* BFDD4 002BF1D4 14800026 */  .word 0x14800026
    /* BFDD8 002BF1D8 00111400 */  sll       $v0, $s1, 16
    /* BFDDC 002BF1DC 26440001 */  addiu      $a0, $s2, 0x1
    /* BFDE0 002BF1E0 00041C00 */  sll        $v1, $a0, 16
    /* BFDE4 002BF1E4 95020000 */  lhu        $v0, 0x0($t0)
    /* BFDE8 002BF1E8 00031C03 */  sra        $v1, $v1, 16
    /* BFDEC 002BF1EC 24420001 */  addiu      $v0, $v0, 0x1
    /* BFDF0 002BF1F0 A5020000 */  sh         $v0, 0x0($t0)
    /* BFDF4 002BF1F4 00031080 */  sll        $v0, $v1, 2
    /* BFDF8 002BF1F8 00431021 */  addu       $v0, $v0, $v1
    /* BFDFC 002BF1FC 00021080 */  sll        $v0, $v0, 2
    /* BFE00 002BF200 004A1021 */  addu       $v0, $v0, $t2
    /* BFE04 002BF204 8C530010 */  lw         $s3, 0x10($v0)
    /* BFE08 002BF208 8E740020 */  lw         $s4, 0x20($s3)
    /* BFE0C 002BF20C 080AFC9B */  .word 0x080AFC9B
    /* BFE10 002BF210 00809021 */  addu      $s2, $a0, $zero
.Lauto_002BF214:
    /* BFE14 002BF214 3C04800D */  lui        $a0, %hi(D_auto_800D416A)
    /* BFE18 002BF218 2484416A */  addiu      $a0, $a0, %lo(D_auto_800D416A)
    /* BFE1C 002BF21C 24050010 */  addiu      $a1, $zero, 0x10
    /* BFE20 002BF220 24060001 */  addiu      $a2, $zero, 0x1
    /* BFE24 002BF224 8FAB0068 */  lw         $t3, 0x68($sp)
    /* BFE28 002BF228 00003821 */  addu       $a3, $zero, $zero
    /* BFE2C 002BF22C AFA80020 */  sw         $t0, 0x20($sp)
    /* BFE30 002BF230 AFA90024 */  sw         $t1, 0x24($sp)
    /* BFE34 002BF234 AFAA0028 */  sw         $t2, 0x28($sp)
    /* BFE38 002BF238 0C0AFB38 */  jal        adecReadBits
    /* BFE3C 002BF23C AFAB0010 */  sw        $t3, 0x10($sp)
    /* BFE40 002BF240 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BFE44 002BF244 8FA80020 */  lw         $t0, 0x20($sp)
    /* BFE48 002BF248 8FA90024 */  lw         $t1, 0x24($sp)
    /* BFE4C 002BF24C 8FAA0028 */  lw         $t2, 0x28($sp)
    /* BFE50 002BF250 14400003 */  .word 0x14400003
    /* BFE54 002BF254 00000000 */  nop
.Lauto_002BF258:
    /* BFE58 002BF258 080AFCA2 */  .word 0x080AFCA2
    /* BFE5C 002BF25C 2402FFFF */  addiu     $v0, $zero, -0x1
.Lauto_002BF260:
    /* BFE60 002BF260 97C20000 */  lhu        $v0, 0x0($fp)
    /* BFE64 002BF264 24420010 */  addiu      $v0, $v0, 0x10
    /* BFE68 002BF268 A7C20000 */  sh         $v0, 0x0($fp)
.Lauto_002BF26C:
    /* BFE6C 002BF26C 00111400 */  sll        $v0, $s1, 16
.Lauto_002BF270:
    /* BFE70 002BF270 00021403 */  sra        $v0, $v0, 16
    /* BFE74 002BF274 0056102A */  slt        $v0, $v0, $s6
    /* BFE78 002BF278 1440FF2B */  .word 0x1440FF2B
    /* BFE7C 002BF27C 00000000 */  nop
.Lauto_002BF280:
    /* BFE80 002BF280 00111400 */  sll        $v0, $s1, 16
    /* BFE84 002BF284 00021403 */  sra        $v0, $v0, 16
.Lauto_002BF288:
    /* BFE88 002BF288 8FBF0054 */  lw         $ra, 0x54($sp)
    /* BFE8C 002BF28C 8FBE0050 */  lw         $fp, 0x50($sp)
    /* BFE90 002BF290 8FB7004C */  lw         $s7, 0x4C($sp)
    /* BFE94 002BF294 8FB60048 */  lw         $s6, 0x48($sp)
    /* BFE98 002BF298 8FB50044 */  lw         $s5, 0x44($sp)
    /* BFE9C 002BF29C 8FB40040 */  lw         $s4, 0x40($sp)
    /* BFEA0 002BF2A0 8FB3003C */  lw         $s3, 0x3C($sp)
    /* BFEA4 002BF2A4 8FB20038 */  lw         $s2, 0x38($sp)
    /* BFEA8 002BF2A8 8FB10034 */  lw         $s1, 0x34($sp)
    /* BFEAC 002BF2AC 8FB00030 */  lw         $s0, 0x30($sp)
    /* BFEB0 002BF2B0 03E00008 */  jr         $ra
    /* BFEB4 002BF2B4 27BD0058 */  addiu     $sp, $sp, 0x58
.globl adecDecodeFrame
adecDecodeFrame:
    /* BFEB8 002BF2B8 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* BFEBC 002BF2BC AFB10024 */  sw         $s1, 0x24($sp)
    /* BFEC0 002BF2C0 3C03800D */  lui        $v1, %hi(D_auto_800D416E)
    /* BFEC4 002BF2C4 2463416E */  addiu      $v1, $v1, %lo(D_auto_800D416E)
    /* BFEC8 002BF2C8 AFBF0028 */  sw         $ra, 0x28($sp)
    /* BFECC 002BF2CC AFB00020 */  sw         $s0, 0x20($sp)
    /* BFED0 002BF2D0 84620000 */  lh         $v0, 0x0($v1)
    /* BFED4 002BF2D4 3C10800D */  lui        $s0, %hi(D_auto_800D4214)
    /* BFED8 002BF2D8 26104214 */  addiu      $s0, $s0, %lo(D_auto_800D4214)
    /* BFEDC 002BF2DC 14400026 */  .word 0x14400026
    /* BFEE0 002BF2E0 00808821 */  addu      $s1, $a0, $zero
    /* BFEE4 002BF2E4 26240018 */  addiu      $a0, $s1, 0x18
    /* BFEE8 002BF2E8 24050006 */  addiu      $a1, $zero, 0x6
    /* BFEEC 002BF2EC 24060010 */  addiu      $a2, $zero, 0x10
    /* BFEF0 002BF2F0 00003821 */  addu       $a3, $zero, $zero
    /* BFEF4 002BF2F4 24020001 */  addiu      $v0, $zero, 0x1
    /* BFEF8 002BF2F8 A4620000 */  sh         $v0, 0x0($v1)
    /* BFEFC 002BF2FC 0C0AFB38 */  jal        adecReadBits
    /* BFF00 002BF300 AFB10010 */  sw        $s1, 0x10($sp)
    /* BFF04 002BF304 00021400 */  sll        $v0, $v0, 16
    /* BFF08 002BF308 18400048 */  .word 0x18400048
    /* BFF0C 002BF30C 00003821 */  addu      $a3, $zero, $zero
    /* BFF10 002BF310 8E02000C */  lw         $v0, 0xC($s0)
    /* BFF14 002BF314 3C058015 */  lui        $a1, %hi(D_auto_80148E10)
    /* BFF18 002BF318 24A58E10 */  addiu      $a1, $a1, %lo(D_auto_80148E10)
    /* BFF1C 002BF31C 24420060 */  addiu      $v0, $v0, 0x60
    /* BFF20 002BF320 AE02000C */  sw         $v0, 0xC($s0)
.Lauto_002BF324:
    /* BFF24 002BF324 00072400 */  sll        $a0, $a3, 16
    /* BFF28 002BF328 24E30001 */  addiu      $v1, $a3, 0x1
    /* BFF2C 002BF32C 00603821 */  addu       $a3, $v1, $zero
    /* BFF30 002BF330 000423C3 */  sra        $a0, $a0, 15
    /* BFF34 002BF334 02241021 */  addu       $v0, $s1, $a0
    /* BFF38 002BF338 00852021 */  addu       $a0, $a0, $a1
    /* BFF3C 002BF33C 00031C00 */  sll        $v1, $v1, 16
    /* BFF40 002BF340 00031C03 */  sra        $v1, $v1, 16
    /* BFF44 002BF344 94420018 */  lhu        $v0, 0x18($v0)
    /* BFF48 002BF348 28630010 */  slti       $v1, $v1, 0x10
    /* BFF4C 002BF34C 1460FFF5 */  .word 0x1460FFF5
    /* BFF50 002BF350 A4820000 */  sh        $v0, 0x0($a0)
    /* BFF54 002BF354 8E020000 */  lw         $v0, 0x0($s0)
    /* BFF58 002BF358 5040002A */  .word 0x5040002A
    /* BFF5C 002BF35C AFB10010 */  sw        $s1, 0x10($sp)
    /* BFF60 002BF360 26100014 */  addiu      $s0, $s0, 0x14
.Lauto_002BF364:
    /* BFF64 002BF364 8E020000 */  lw         $v0, 0x0($s0)
    /* BFF68 002BF368 5440FFFE */  .word 0x5440FFFE
    /* BFF6C 002BF36C 26100014 */  addiu     $s0, $s0, 0x14
    /* BFF70 002BF370 080AFD01 */  .word 0x080AFD01
    /* BFF74 002BF374 AFB10010 */  sw        $s1, 0x10($sp)
.Lauto_002BF378:
    /* BFF78 002BF378 AFB10010 */  sw         $s1, 0x10($sp)
    /* BFF7C 002BF37C 02002021 */  addu       $a0, $s0, $zero
    /* BFF80 002BF380 26250018 */  addiu      $a1, $s1, 0x18
    /* BFF84 002BF384 24060010 */  addiu      $a2, $zero, 0x10
    /* BFF88 002BF388 0C0AFBAD */  jal        adecHuffDecode
    /* BFF8C 002BF38C 27A70018 */  addiu     $a3, $sp, 0x18
    /* BFF90 002BF390 00021400 */  sll        $v0, $v0, 16
    /* BFF94 002BF394 00021C03 */  sra        $v1, $v0, 16
    /* BFF98 002BF398 24020010 */  addiu      $v0, $zero, 0x10
    /* BFF9C 002BF39C 14620024 */  .word 0x14620024
    /* BFFA0 002BF3A0 2402FFFF */  addiu     $v0, $zero, -0x1
    /* BFFA4 002BF3A4 00003821 */  addu       $a3, $zero, $zero
    /* BFFA8 002BF3A8 87A30018 */  lh         $v1, 0x18($sp)
    /* BFFAC 002BF3AC 3C088015 */  lui        $t0, %hi(D_auto_80148E10)
    /* BFFB0 002BF3B0 25088E10 */  addiu      $t0, $t0, %lo(D_auto_80148E10)
    /* BFFB4 002BF3B4 00031080 */  sll        $v0, $v1, 2
    /* BFFB8 002BF3B8 00431021 */  addu       $v0, $v0, $v1
    /* BFFBC 002BF3BC 00021080 */  sll        $v0, $v0, 2
    /* BFFC0 002BF3C0 00508021 */  addu       $s0, $v0, $s0
.Lauto_002BF3C4:
    /* BFFC4 002BF3C4 00072400 */  sll        $a0, $a3, 16
    /* BFFC8 002BF3C8 000423C3 */  sra        $a0, $a0, 15
    /* BFFCC 002BF3CC 00882821 */  addu       $a1, $a0, $t0
    /* BFFD0 002BF3D0 02242021 */  addu       $a0, $s1, $a0
    /* BFFD4 002BF3D4 24E30001 */  addiu      $v1, $a3, 0x1
    /* BFFD8 002BF3D8 00603821 */  addu       $a3, $v1, $zero
    /* BFFDC 002BF3DC 00031C00 */  sll        $v1, $v1, 16
    /* BFFE0 002BF3E0 00031C03 */  sra        $v1, $v1, 16
    /* BFFE4 002BF3E4 94A60000 */  lhu        $a2, 0x0($a1)
    /* BFFE8 002BF3E8 94820018 */  lhu        $v0, 0x18($a0)
    /* BFFEC 002BF3EC 28630010 */  slti       $v1, $v1, 0x10
    /* BFFF0 002BF3F0 00461021 */  addu       $v0, $v0, $a2
    /* BFFF4 002BF3F4 A4820018 */  sh         $v0, 0x18($a0)
    /* BFFF8 002BF3F8 1460FFF2 */  .word 0x1460FFF2
    /* BFFFC 002BF3FC A4A20000 */  sh        $v0, 0x0($a1)
    /* C0000 002BF400 AFB10010 */  sw         $s1, 0x10($sp)
.Lauto_002BF404:
    /* C0004 002BF404 02002021 */  addu       $a0, $s0, $zero
    /* C0008 002BF408 262500B8 */  addiu      $a1, $s1, 0xB8
    /* C000C 002BF40C 24060100 */  addiu      $a2, $zero, 0x100
    /* C0010 002BF410 0C0AFBAD */  jal        adecHuffDecode
    /* C0014 002BF414 27A70018 */  addiu     $a3, $sp, 0x18
    /* C0018 002BF418 00021400 */  sll        $v0, $v0, 16
    /* C001C 002BF41C 00021C03 */  sra        $v1, $v0, 16
    /* C0020 002BF420 24020100 */  addiu      $v0, $zero, 0x100
    /* C0024 002BF424 10620002 */  .word 0x10620002
    /* C0028 002BF428 24020001 */  addiu     $v0, $zero, 0x1
.Lauto_002BF42C:
    /* C002C 002BF42C 2402FFFF */  addiu      $v0, $zero, -0x1
.Lauto_002BF430:
    /* C0030 002BF430 8FBF0028 */  lw         $ra, 0x28($sp)
    /* C0034 002BF434 8FB10024 */  lw         $s1, 0x24($sp)
    /* C0038 002BF438 8FB00020 */  lw         $s0, 0x20($sp)
    /* C003C 002BF43C 03E00008 */  jr         $ra
    /* C0040 002BF440 27BD0030 */  addiu     $sp, $sp, 0x30
.globl mdctInitTwiddles
mdctInitTwiddles:
    /* C0044 002BF444 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* C0048 002BF448 F7B70040 */  sdc1       $fs1f, 0x40($sp)
    /* C004C 002BF44C 3C01800C */  lui        $at, %hi(D_auto_800C7BE0)
    /* C0050 002BF450 C4377BE0 */  lwc1       $fs1f, %lo(D_auto_800C7BE0)($at)
    /* C0054 002BF454 F7B60038 */  sdc1       $fs1, 0x38($sp)
    /* C0058 002BF458 3C01800C */  lui        $at, %hi(D_auto_800C7BE0 + 0x4)
    /* C005C 002BF45C C4367BE4 */  lwc1       $fs1, %lo(D_auto_800C7BE0 + 0x4)($at)
    /* C0060 002BF460 F7B50030 */  sdc1       $fs0f, 0x30($sp)
    /* C0064 002BF464 3C01800C */  lui        $at, %hi(D_auto_800C7BE8)
    /* C0068 002BF468 C4357BE8 */  lwc1       $fs0f, %lo(D_auto_800C7BE8)($at)
    /* C006C 002BF46C AFB10014 */  sw         $s1, 0x14($sp)
    /* C0070 002BF470 00008821 */  addu       $s1, $zero, $zero
    /* C0074 002BF474 AFB40020 */  sw         $s4, 0x20($sp)
    /* C0078 002BF478 3C148015 */  lui        $s4, %hi(D_auto_80148E30)
    /* C007C 002BF47C 26948E30 */  addiu      $s4, $s4, %lo(D_auto_80148E30)
    /* C0080 002BF480 AFB3001C */  sw         $s3, 0x1C($sp)
    /* C0084 002BF484 3C138015 */  lui        $s3, %hi(D_auto_80149030)
    /* C0088 002BF488 26739030 */  addiu      $s3, $s3, %lo(D_auto_80149030)
    /* C008C 002BF48C AFB20018 */  sw         $s2, 0x18($sp)
    /* C0090 002BF490 3C128015 */  lui        $s2, %hi(D_auto_80149630)
    /* C0094 002BF494 26529630 */  addiu      $s2, $s2, %lo(D_auto_80149630)
    /* C0098 002BF498 AFBF0024 */  sw         $ra, 0x24($sp)
    /* C009C 002BF49C AFB00010 */  sw         $s0, 0x10($sp)
    /* C00A0 002BF4A0 F7B40028 */  sdc1       $fs0, 0x28($sp)
.Lauto_002BF4A4:
    /* C00A4 002BF4A4 00118400 */  sll        $s0, $s1, 16
    /* C00A8 002BF4A8 00108403 */  sra        $s0, $s0, 16
    /* C00AC 002BF4AC 44900000 */  mtc1       $s0, $fv0
    /* C00B0 002BF4B0 46800020 */  cvt.s.w    $fv0, $fv0
    /* C00B4 002BF4B4 46170002 */  mul.s      $fv0, $fv0, $fs1f
    /* C00B8 002BF4B8 46160000 */  add.s      $fv0, $fv0, $fs1
    /* C00BC 002BF4BC 46150502 */  mul.s      $fs0, $fv0, $fs0f
    /* C00C0 002BF4C0 0C0AD924 */  jal        cosf
    /* C00C4 002BF4C4 4600A306 */  mov.s     $fa0, $fs0
    /* C00C8 002BF4C8 4600A306 */  mov.s      $fa0, $fs0
    /* C00CC 002BF4CC 00108080 */  sll        $s0, $s0, 2
    /* C00D0 002BF4D0 02141021 */  addu       $v0, $s0, $s4
    /* C00D4 002BF4D4 0C0ADC18 */  jal        sinf
    /* C00D8 002BF4D8 E4400000 */  swc1      $fv0, 0x0($v0)
    /* C00DC 002BF4DC 26220001 */  addiu      $v0, $s1, 0x1
    /* C00E0 002BF4E0 00408821 */  addu       $s1, $v0, $zero
    /* C00E4 002BF4E4 02131821 */  addu       $v1, $s0, $s3
    /* C00E8 002BF4E8 02128021 */  addu       $s0, $s0, $s2
    /* C00EC 002BF4EC 00021400 */  sll        $v0, $v0, 16
    /* C00F0 002BF4F0 00021403 */  sra        $v0, $v0, 16
    /* C00F4 002BF4F4 28420080 */  slti       $v0, $v0, 0x80
    /* C00F8 002BF4F8 E4600000 */  swc1       $fv0, 0x0($v1)
    /* C00FC 002BF4FC 1440FFE9 */  .word 0x1440FFE9
    /* C0100 002BF500 AE000000 */  sw        $zero, 0x0($s0)
    /* C0104 002BF504 00008821 */  addu       $s1, $zero, $zero
    /* C0108 002BF508 3C01800C */  lui        $at, %hi(D_auto_800C7BE8 + 0x4)
    /* C010C 002BF50C C4357BEC */  lwc1       $fs0f, %lo(D_auto_800C7BE8 + 0x4)($at)
    /* C0110 002BF510 3C138015 */  lui        $s3, %hi(D_auto_80149230)
    /* C0114 002BF514 26739230 */  addiu      $s3, $s3, %lo(D_auto_80149230)
    /* C0118 002BF518 3C128015 */  lui        $s2, %hi(D_auto_80149430)
    /* C011C 002BF51C 26529430 */  addiu      $s2, $s2, %lo(D_auto_80149430)
.Lauto_002BF520:
    /* C0120 002BF520 00118400 */  sll        $s0, $s1, 16
    /* C0124 002BF524 00108403 */  sra        $s0, $s0, 16
    /* C0128 002BF528 44900000 */  mtc1       $s0, $fv0
    /* C012C 002BF52C 46800020 */  cvt.s.w    $fv0, $fv0
    /* C0130 002BF530 46150502 */  mul.s      $fs0, $fv0, $fs0f
    /* C0134 002BF534 0C0AD924 */  jal        cosf
    /* C0138 002BF538 4600A306 */  mov.s     $fa0, $fs0
    /* C013C 002BF53C 4600A306 */  mov.s      $fa0, $fs0
    /* C0140 002BF540 0C0ADC18 */  jal        sinf
    /* C0144 002BF544 46000506 */  mov.s     $fs0, $fv0
    /* C0148 002BF548 26220001 */  addiu      $v0, $s1, 0x1
    /* C014C 002BF54C 00408821 */  addu       $s1, $v0, $zero
    /* C0150 002BF550 00108080 */  sll        $s0, $s0, 2
    /* C0154 002BF554 02131821 */  addu       $v1, $s0, $s3
    /* C0158 002BF558 02128021 */  addu       $s0, $s0, $s2
    /* C015C 002BF55C 4600A040 */  add.s      $fv0f, $fs0, $fv0
    /* C0160 002BF560 00021400 */  sll        $v0, $v0, 16
    /* C0164 002BF564 00021403 */  sra        $v0, $v0, 16
    /* C0168 002BF568 46140001 */  sub.s      $fv0, $fv0, $fs0
    /* C016C 002BF56C 28420080 */  slti       $v0, $v0, 0x80
    /* C0170 002BF570 E4610000 */  swc1       $fv0f, 0x0($v1)
    /* C0174 002BF574 1440FFEA */  .word 0x1440FFEA
    /* C0178 002BF578 E6000000 */  swc1      $fv0, 0x0($s0)
    /* C017C 002BF57C 8FBF0024 */  lw         $ra, 0x24($sp)
    /* C0180 002BF580 8FB40020 */  lw         $s4, 0x20($sp)
    /* C0184 002BF584 8FB3001C */  lw         $s3, 0x1C($sp)
    /* C0188 002BF588 8FB20018 */  lw         $s2, 0x18($sp)
    /* C018C 002BF58C 8FB10014 */  lw         $s1, 0x14($sp)
    /* C0190 002BF590 8FB00010 */  lw         $s0, 0x10($sp)
    /* C0194 002BF594 D7B70040 */  ldc1       $fs1f, 0x40($sp)
    /* C0198 002BF598 D7B60038 */  ldc1       $fs1, 0x38($sp)
    /* C019C 002BF59C D7B50030 */  ldc1       $fs0f, 0x30($sp)
    /* C01A0 002BF5A0 D7B40028 */  ldc1       $fs0, 0x28($sp)
    /* C01A4 002BF5A4 03E00008 */  jr         $ra
    /* C01A8 002BF5A8 27BD0048 */  addiu     $sp, $sp, 0x48
.globl mdctFftInit
mdctFftInit:
    /* C01AC 002BF5AC 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* C01B0 002BF5B0 AFB3001C */  sw         $s3, 0x1C($sp)
    /* C01B4 002BF5B4 00809821 */  addu       $s3, $a0, $zero
    /* C01B8 002BF5B8 AFB10014 */  sw         $s1, 0x14($sp)
    /* C01BC 002BF5BC AFB20018 */  sw         $s2, 0x18($sp)
    /* C01C0 002BF5C0 00139043 */  sra        $s2, $s3, 1
    /* C01C4 002BF5C4 AFB40020 */  sw         $s4, 0x20($sp)
    /* C01C8 002BF5C8 3C14800D */  lui        $s4, %hi(D_auto_800D3FF0)
    /* C01CC 002BF5CC 26943FF0 */  addiu      $s4, $s4, %lo(D_auto_800D3FF0)
    /* C01D0 002BF5D0 AFBF0024 */  sw         $ra, 0x24($sp)
    /* C01D4 002BF5D4 AFB00010 */  sw         $s0, 0x10($sp)
    /* C01D8 002BF5D8 F7B60038 */  sdc1       $fs1, 0x38($sp)
    /* C01DC 002BF5DC F7B50030 */  sdc1       $fs0f, 0x30($sp)
    /* C01E0 002BF5E0 F7B40028 */  sdc1       $fs0, 0x28($sp)
    /* C01E4 002BF5E4 1A400018 */  .word 0x1A400018
    /* C01E8 002BF5E8 00008821 */  addu      $s1, $zero, $zero
    /* C01EC 002BF5EC 3C01800C */  lui        $at, %hi(D_auto_800C7BF0)
    /* C01F0 002BF5F0 C4367BF0 */  lwc1       $fs1, %lo(D_auto_800C7BF0)($at)
    /* C01F4 002BF5F4 4493A800 */  mtc1       $s3, $fs0f
    /* C01F8 002BF5F8 4680AD60 */  cvt.s.w    $fs0f, $fs0f
.Lauto_002BF5FC:
    /* C01FC 002BF5FC 4491A000 */  mtc1       $s1, $fs0
    /* C0200 002BF600 4680A520 */  cvt.s.w    $fs0, $fs0
    /* C0204 002BF604 4616A502 */  mul.s      $fs0, $fs0, $fs1
    /* C0208 002BF608 4615A503 */  div.s      $fs0, $fs0, $fs0f
    /* C020C 002BF60C 0C0AD924 */  jal        cosf
    /* C0210 002BF610 4600A306 */  mov.s     $fa0, $fs0
    /* C0214 002BF614 4600A306 */  mov.s      $fa0, $fs0
    /* C0218 002BF618 8E820000 */  lw         $v0, 0x0($s4)
    /* C021C 002BF61C 00118080 */  sll        $s0, $s1, 2
    /* C0220 002BF620 02021021 */  addu       $v0, $s0, $v0
    /* C0224 002BF624 0C0ADC18 */  jal        sinf
    /* C0228 002BF628 E4400000 */  swc1      $fv0, 0x0($v0)
    /* C022C 002BF62C 26310001 */  addiu      $s1, $s1, 0x1
    /* C0230 002BF630 8E820004 */  lw         $v0, 0x4($s4)
    /* C0234 002BF634 46000007 */  neg.s      $fv0, $fv0
    /* C0238 002BF638 02028021 */  addu       $s0, $s0, $v0
    /* C023C 002BF63C 0232102A */  slt        $v0, $s1, $s2
    /* C0240 002BF640 1440FFEE */  .word 0x1440FFEE
    /* C0244 002BF644 E6000000 */  swc1      $fv0, 0x0($s0)
.Lauto_002BF648:
    /* C0248 002BF648 00003821 */  addu       $a3, $zero, $zero
    /* C024C 002BF64C 8E880008 */  lw         $t0, 0x8($s4)
    /* C0250 002BF650 1A600007 */  .word 0x1A600007
    /* C0254 002BF654 00134840 */  sll       $t1, $s3, 1
    /* C0258 002BF658 01001821 */  addu       $v1, $t0, $zero
.Lauto_002BF65C:
    /* C025C 002BF65C AC670000 */  sw         $a3, 0x0($v1)
    /* C0260 002BF660 24E70001 */  addiu      $a3, $a3, 0x1
    /* C0264 002BF664 00F3102A */  slt        $v0, $a3, $s3
    /* C0268 002BF668 1440FFFC */  .word 0x1440FFFC
    /* C026C 002BF66C 24630004 */  addiu     $v1, $v1, 0x4
.Lauto_002BF670:
    /* C0270 002BF670 24060001 */  addiu      $a2, $zero, 0x1
    /* C0274 002BF674 19200022 */  .word 0x19200022
    /* C0278 002BF678 00C03821 */  addu      $a3, $a2, $zero
    /* C027C 002BF67C 2A6A0002 */  slti       $t2, $s3, 0x2
.Lauto_002BF680:
    /* C0280 002BF680 00E6102A */  slt        $v0, $a3, $a2
    /* C0284 002BF684 10400010 */  .word 0x10400010
    /* C0288 002BF688 24C4FFFF */  addiu     $a0, $a2, -0x1
    /* C028C 002BF68C 000417C2 */  srl        $v0, $a0, 31
    /* C0290 002BF690 00822021 */  addu       $a0, $a0, $v0
    /* C0294 002BF694 00042043 */  sra        $a0, $a0, 1
    /* C0298 002BF698 00042080 */  sll        $a0, $a0, 2
    /* C029C 002BF69C 00882021 */  addu       $a0, $a0, $t0
    /* C02A0 002BF6A0 24E2FFFF */  addiu      $v0, $a3, -0x1
    /* C02A4 002BF6A4 00021FC2 */  srl        $v1, $v0, 31
    /* C02A8 002BF6A8 00431021 */  addu       $v0, $v0, $v1
    /* C02AC 002BF6AC 00021043 */  sra        $v0, $v0, 1
    /* C02B0 002BF6B0 00021080 */  sll        $v0, $v0, 2
    /* C02B4 002BF6B4 00481021 */  addu       $v0, $v0, $t0
    /* C02B8 002BF6B8 8C430000 */  lw         $v1, 0x0($v0)
    /* C02BC 002BF6BC 8C850000 */  lw         $a1, 0x0($a0)
    /* C02C0 002BF6C0 AC830000 */  sw         $v1, 0x0($a0)
    /* C02C4 002BF6C4 AC450000 */  sw         $a1, 0x0($v0)
.Lauto_002BF6C8:
    /* C02C8 002BF6C8 15400009 */  .word 0x15400009
    /* C02CC 002BF6CC 02601821 */  addu      $v1, $s3, $zero
    /* C02D0 002BF6D0 0066102A */  slt        $v0, $v1, $a2
.Lauto_002BF6D4:
    /* C02D4 002BF6D4 50400007 */  .word 0x50400007
    /* C02D8 002BF6D8 24E70002 */  addiu     $a3, $a3, 0x2
    /* C02DC 002BF6DC 00C33023 */  subu       $a2, $a2, $v1
    /* C02E0 002BF6E0 00031843 */  sra        $v1, $v1, 1
    /* C02E4 002BF6E4 28620002 */  slti       $v0, $v1, 0x2
    /* C02E8 002BF6E8 1040FFFA */  .word 0x1040FFFA
    /* C02EC 002BF6EC 0066102A */  slt       $v0, $v1, $a2
.Lauto_002BF6F0:
    /* C02F0 002BF6F0 24E70002 */  addiu      $a3, $a3, 0x2
.Lauto_002BF6F4:
    /* C02F4 002BF6F4 0127102A */  slt        $v0, $t1, $a3
    /* C02F8 002BF6F8 1040FFE1 */  .word 0x1040FFE1
    /* C02FC 002BF6FC 00C33021 */  addu      $a2, $a2, $v1
.Lauto_002BF700:
    /* C0300 002BF700 02801021 */  addu       $v0, $s4, $zero
    /* C0304 002BF704 AE93000C */  sw         $s3, 0xC($s4)
    /* C0308 002BF708 8FBF0024 */  lw         $ra, 0x24($sp)
    /* C030C 002BF70C 8FB40020 */  lw         $s4, 0x20($sp)
    /* C0310 002BF710 8FB3001C */  lw         $s3, 0x1C($sp)
    /* C0314 002BF714 8FB20018 */  lw         $s2, 0x18($sp)
    /* C0318 002BF718 8FB10014 */  lw         $s1, 0x14($sp)
    /* C031C 002BF71C 8FB00010 */  lw         $s0, 0x10($sp)
    /* C0320 002BF720 D7B60038 */  ldc1       $fs1, 0x38($sp)
    /* C0324 002BF724 D7B50030 */  ldc1       $fs0f, 0x30($sp)
    /* C0328 002BF728 D7B40028 */  ldc1       $fs0, 0x28($sp)
    /* C032C 002BF72C 03E00008 */  jr         $ra
    /* C0330 002BF730 27BD0040 */  addiu     $sp, $sp, 0x40
.globl adecDequantize
adecDequantize:
    /* C0334 002BF734 00806021 */  addu       $t4, $a0, $zero
    /* C0338 002BF738 00A05821 */  addu       $t3, $a1, $zero
    /* C033C 002BF73C 00001821 */  addu       $v1, $zero, $zero
    /* C0340 002BF740 256A00A0 */  addiu      $t2, $t3, 0xA0
    /* C0344 002BF744 00603821 */  addu       $a3, $v1, $zero
    /* C0348 002BF748 3C09800D */  lui        $t1, %hi(D_auto_800D4048)
    /* C034C 002BF74C 25294048 */  addiu      $t1, $t1, %lo(D_auto_800D4048)
    /* C0350 002BF750 3C0D800D */  lui        $t5, %hi(D_auto_800D4068)
    /* C0354 002BF754 25AD4068 */  addiu      $t5, $t5, %lo(D_auto_800D4068)
    /* C0358 002BF758 3C01800C */  lui        $at, %hi(D_auto_800C7BF4)
    /* C035C 002BF75C C4227BF4 */  lwc1       $fv1, %lo(D_auto_800C7BF4)($at)
    /* C0360 002BF760 00603021 */  addu       $a2, $v1, $zero
.Lauto_002BF764:
    /* C0364 002BF764 00074400 */  sll        $t0, $a3, 16
    /* C0368 002BF768 00081BC3 */  sra        $v1, $t0, 15
    /* C036C 002BF76C 00691821 */  addu       $v1, $v1, $t1
    /* C0370 002BF770 94630000 */  lhu        $v1, 0x0($v1)
    /* C0374 002BF774 080AFDF5 */  .word 0x080AFDF5
    /* C0378 002BF778 00061400 */  sll       $v0, $a2, 16
.Lauto_002BF77C:
    /* C037C 002BF77C 00031C03 */  sra        $v1, $v1, 16
    /* C0380 002BF780 00032040 */  sll        $a0, $v1, 1
    /* C0384 002BF784 00082BC3 */  sra        $a1, $t0, 15
    /* C0388 002BF788 01651021 */  addu       $v0, $t3, $a1
    /* C038C 002BF78C 008A2021 */  addu       $a0, $a0, $t2
    /* C0390 002BF790 00031880 */  sll        $v1, $v1, 2
    /* C0394 002BF794 006C1821 */  addu       $v1, $v1, $t4
    /* C0398 002BF798 84420000 */  lh         $v0, 0x0($v0)
    /* C039C 002BF79C 84840000 */  lh         $a0, 0x0($a0)
    /* C03A0 002BF7A0 00021080 */  sll        $v0, $v0, 2
    /* C03A4 002BF7A4 004D1021 */  addu       $v0, $v0, $t5
    /* C03A8 002BF7A8 C4410000 */  lwc1       $fv0f, 0x0($v0)
    /* C03AC 002BF7AC 44840000 */  mtc1       $a0, $fv0
    /* C03B0 002BF7B0 46800020 */  cvt.s.w    $fv0, $fv0
    /* C03B4 002BF7B4 46010003 */  div.s      $fv0, $fv0, $fv0f
    /* C03B8 002BF7B8 46020002 */  mul.s      $fv0, $fv0, $fv1
    /* C03BC 002BF7BC 00A92821 */  addu       $a1, $a1, $t1
    /* C03C0 002BF7C0 24C20001 */  addiu      $v0, $a2, 0x1
    /* C03C4 002BF7C4 00403021 */  addu       $a2, $v0, $zero
    /* C03C8 002BF7C8 00021400 */  sll        $v0, $v0, 16
    /* C03CC 002BF7CC E4600000 */  swc1       $fv0, 0x0($v1)
    /* C03D0 002BF7D0 94A30000 */  lhu        $v1, 0x0($a1)
.Lauto_002BF7D4:
    /* C03D4 002BF7D4 00021403 */  sra        $v0, $v0, 16
    /* C03D8 002BF7D8 0043102A */  slt        $v0, $v0, $v1
    /* C03DC 002BF7DC 1440FFE7 */  .word 0x1440FFE7
    /* C03E0 002BF7E0 00061C00 */  sll       $v1, $a2, 16
    /* C03E4 002BF7E4 00071400 */  sll        $v0, $a3, 16
    /* C03E8 002BF7E8 000213C3 */  sra        $v0, $v0, 15
    /* C03EC 002BF7EC 00491021 */  addu       $v0, $v0, $t1
    /* C03F0 002BF7F0 94430000 */  lhu        $v1, 0x0($v0)
    /* C03F4 002BF7F4 24E20001 */  addiu      $v0, $a3, 0x1
    /* C03F8 002BF7F8 00403821 */  addu       $a3, $v0, $zero
    /* C03FC 002BF7FC 00021400 */  sll        $v0, $v0, 16
    /* C0400 002BF800 00021403 */  sra        $v0, $v0, 16
    /* C0404 002BF804 28420010 */  slti       $v0, $v0, 0x10
    /* C0408 002BF808 5440FFD6 */  .word 0x5440FFD6
    /* C040C 002BF80C 00603021 */  addu      $a2, $v1, $zero
    /* C0410 002BF810 3C02800D */  lui        $v0, %hi(D_auto_800D4066)
    /* C0414 002BF814 84424066 */  lh         $v0, %lo(D_auto_800D4066)($v0)
    /* C0418 002BF818 00403821 */  addu       $a3, $v0, $zero
    /* C041C 002BF81C 28420100 */  slti       $v0, $v0, 0x100
    /* C0420 002BF820 1040000B */  .word 0x1040000B
    /* C0424 002BF824 00071400 */  sll       $v0, $a3, 16
.Lauto_002BF828:
    /* C0428 002BF828 00021383 */  sra        $v0, $v0, 14
    /* C042C 002BF82C 004C1021 */  addu       $v0, $v0, $t4
    /* C0430 002BF830 AC400000 */  sw         $zero, 0x0($v0)
    /* C0434 002BF834 24E20001 */  addiu      $v0, $a3, 0x1
    /* C0438 002BF838 00403821 */  addu       $a3, $v0, $zero
    /* C043C 002BF83C 00021400 */  sll        $v0, $v0, 16
    /* C0440 002BF840 00021403 */  sra        $v0, $v0, 16
    /* C0444 002BF844 28420100 */  slti       $v0, $v0, 0x100
    /* C0448 002BF848 1440FFF7 */  .word 0x1440FFF7
    /* C044C 002BF84C 00071400 */  sll       $v0, $a3, 16
.Lauto_002BF850:
    /* C0450 002BF850 03E00008 */  jr         $ra
    /* C0454 002BF854 24020001 */  addiu     $v0, $zero, 0x1
.globl mdctFft
mdctFft:
    /* C0458 002BF858 8FB80010 */  lw         $t8, 0x10($sp)
    /* C045C 002BF85C 18A0001F */  .word 0x18A0001F
    /* C0460 002BF860 00005021 */  addu      $t2, $zero, $zero
    /* C0464 002BF864 8FA90014 */  lw         $t1, 0x14($sp)
    /* C0468 002BF868 00804021 */  addu       $t0, $a0, $zero
.Lauto_002BF86C:
    /* C046C 002BF86C 8D230000 */  lw         $v1, 0x0($t1)
    /* C0470 002BF870 0143102A */  slt        $v0, $t2, $v1
    /* C0474 002BF874 50400015 */  .word 0x50400015
    /* C0478 002BF878 25290004 */  addiu     $t1, $t1, 0x4
    /* C047C 002BF87C 000310C0 */  sll        $v0, $v1, 3
    /* C0480 002BF880 00441021 */  addu       $v0, $v0, $a0
    /* C0484 002BF884 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0488 002BF888 C5030000 */  lwc1       $fv1f, 0x0($t0)
    /* C048C 002BF88C E5000000 */  swc1       $fv0, 0x0($t0)
    /* C0490 002BF890 8D220000 */  lw         $v0, 0x0($t1)
    /* C0494 002BF894 000210C0 */  sll        $v0, $v0, 3
    /* C0498 002BF898 00441021 */  addu       $v0, $v0, $a0
    /* C049C 002BF89C E4430000 */  swc1       $fv1f, 0x0($v0)
    /* C04A0 002BF8A0 8D220000 */  lw         $v0, 0x0($t1)
    /* C04A4 002BF8A4 C5030004 */  lwc1       $fv1f, 0x4($t0)
    /* C04A8 002BF8A8 000210C0 */  sll        $v0, $v0, 3
    /* C04AC 002BF8AC 00441021 */  addu       $v0, $v0, $a0
    /* C04B0 002BF8B0 C4400004 */  lwc1       $fv0, 0x4($v0)
    /* C04B4 002BF8B4 E5000004 */  swc1       $fv0, 0x4($t0)
    /* C04B8 002BF8B8 8D220000 */  lw         $v0, 0x0($t1)
    /* C04BC 002BF8BC 000210C0 */  sll        $v0, $v0, 3
    /* C04C0 002BF8C0 00441021 */  addu       $v0, $v0, $a0
    /* C04C4 002BF8C4 E4430004 */  swc1       $fv1f, 0x4($v0)
    /* C04C8 002BF8C8 25290004 */  addiu      $t1, $t1, 0x4
.Lauto_002BF8CC:
    /* C04CC 002BF8CC 254A0001 */  addiu      $t2, $t2, 0x1
    /* C04D0 002BF8D0 0145102A */  slt        $v0, $t2, $a1
    /* C04D4 002BF8D4 1440FFE5 */  .word 0x1440FFE5
    /* C04D8 002BF8D8 25080008 */  addiu     $t0, $t0, 0x8
.Lauto_002BF8DC:
    /* C04DC 002BF8DC 240E0002 */  addiu      $t6, $zero, 0x2
    /* C04E0 002BF8E0 240F0001 */  addiu      $t7, $zero, 0x1
    /* C04E4 002BF8E4 01E56807 */  srav       $t5, $a1, $t7
    /* C04E8 002BF8E8 19A0003A */  .word 0x19A0003A
    /* C04EC 002BF8EC 01E52804 */  sllv      $a1, $a1, $t7
.Lauto_002BF8F0:
    /* C04F0 002BF8F0 19E00034 */  .word 0x19E00034
    /* C04F4 002BF8F4 00004821 */  addu      $t1, $zero, $zero
    /* C04F8 002BF8F8 44863000 */  mtc1       $a2, $ft1
    /* C04FC 002BF8FC 468031A0 */  cvt.s.w    $ft1, $ft1
    /* C0500 002BF900 000E6040 */  sll        $t4, $t6, 1
    /* C0504 002BF904 03005821 */  addu       $t3, $t8, $zero
    /* C0508 002BF908 00E05021 */  addu       $t2, $a3, $zero
    /* C050C 002BF90C 00094040 */  sll        $t0, $t1, 1
.Lauto_002BF910:
    /* C0510 002BF910 0105102A */  slt        $v0, $t0, $a1
    /* C0514 002BF914 C5600000 */  lwc1       $fv0, 0x0($t3)
    /* C0518 002BF918 C5440000 */  lwc1       $ft0, 0x0($t2)
    /* C051C 002BF91C 46003142 */  mul.s      $ft0f, $ft1, $fv0
    /* C0520 002BF920 10400021 */  .word 0x10400021
    /* C0524 002BF924 000910C0 */  sll       $v0, $t1, 3
    /* C0528 002BF928 00441821 */  addu       $v1, $v0, $a0
    /* C052C 002BF92C 010E1021 */  addu       $v0, $t0, $t6
.Lauto_002BF930:
    /* C0530 002BF930 00021080 */  sll        $v0, $v0, 2
    /* C0534 002BF934 00441021 */  addu       $v0, $v0, $a0
    /* C0538 002BF938 C4410000 */  lwc1       $fv0f, 0x0($v0)
    /* C053C 002BF93C 460120C2 */  mul.s      $fv1f, $ft0, $fv0f
    /* C0540 002BF940 C4420004 */  lwc1       $fv1, 0x4($v0)
    /* C0544 002BF944 46022802 */  mul.s      $fv0, $ft0f, $fv1
    /* C0548 002BF948 00000000 */  nop
    /* C054C 002BF94C 46022082 */  mul.s      $fv1, $ft0, $fv1
    /* C0550 002BF950 00000000 */  nop
    /* C0554 002BF954 46012842 */  mul.s      $fv0f, $ft0f, $fv0f
    /* C0558 002BF958 460018C1 */  sub.s      $fv1f, $fv1f, $fv0
    /* C055C 002BF95C C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C0560 002BF960 46030001 */  sub.s      $fv0, $fv0, $fv1f
    /* C0564 002BF964 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C0568 002BF968 E4400000 */  swc1       $fv0, 0x0($v0)
    /* C056C 002BF96C C4600004 */  lwc1       $fv0, 0x4($v1)
    /* C0570 002BF970 46020001 */  sub.s      $fv0, $fv0, $fv1
    /* C0574 002BF974 E4400004 */  swc1       $fv0, 0x4($v0)
    /* C0578 002BF978 C4610000 */  lwc1       $fv0f, 0x0($v1)
    /* C057C 002BF97C 46030840 */  add.s      $fv0f, $fv0f, $fv1f
    /* C0580 002BF980 C4600004 */  lwc1       $fv0, 0x4($v1)
    /* C0584 002BF984 010C4021 */  addu       $t0, $t0, $t4
    /* C0588 002BF988 46020000 */  add.s      $fv0, $fv0, $fv1
    /* C058C 002BF98C 000C1080 */  sll        $v0, $t4, 2
    /* C0590 002BF990 E4610000 */  swc1       $fv0f, 0x0($v1)
    /* C0594 002BF994 E4600004 */  swc1       $fv0, 0x4($v1)
    /* C0598 002BF998 00621821 */  addu       $v1, $v1, $v0
    /* C059C 002BF99C 0105102A */  slt        $v0, $t0, $a1
    /* C05A0 002BF9A0 1440FFE3 */  .word 0x1440FFE3
    /* C05A4 002BF9A4 010E1021 */  addu      $v0, $t0, $t6
.Lauto_002BF9A8:
    /* C05A8 002BF9A8 000D1080 */  sll        $v0, $t5, 2
    /* C05AC 002BF9AC 01625821 */  addu       $t3, $t3, $v0
    /* C05B0 002BF9B0 01425021 */  addu       $t2, $t2, $v0
    /* C05B4 002BF9B4 25290001 */  addiu      $t1, $t1, 0x1
    /* C05B8 002BF9B8 012F102A */  slt        $v0, $t1, $t7
    /* C05BC 002BF9BC 5440FFD4 */  .word 0x5440FFD4
    /* C05C0 002BF9C0 00094040 */  sll       $t0, $t1, 1
.Lauto_002BF9C4:
    /* C05C4 002BF9C4 000D6843 */  sra        $t5, $t5, 1
    /* C05C8 002BF9C8 000F7840 */  sll        $t7, $t7, 1
    /* C05CC 002BF9CC 1DA0FFC8 */  .word 0x1DA0FFC8
    /* C05D0 002BF9D0 000E7040 */  sll       $t6, $t6, 1
.Lauto_002BF9D4:
    /* C05D4 002BF9D4 03E00008 */  jr         $ra
    /* C05D8 002BF9D8 00000000 */  nop
.globl adecImdctFrame
adecImdctFrame:
    /* C05DC 002BF9DC 27BDF7D0 */  addiu      $sp, $sp, -0x830
    /* C05E0 002BF9E0 AFB20820 */  sw         $s2, 0x820($sp)
    /* C05E4 002BF9E4 00809021 */  addu       $s2, $a0, $zero
    /* C05E8 002BF9E8 AFB00818 */  sw         $s0, 0x818($sp)
    /* C05EC 002BF9EC 3C10800D */  lui        $s0, %hi(D_auto_800D4170)
    /* C05F0 002BF9F0 26104170 */  addiu      $s0, $s0, %lo(D_auto_800D4170)
    /* C05F4 002BF9F4 AFBF0824 */  sw         $ra, 0x824($sp)
    /* C05F8 002BF9F8 AFB1081C */  sw         $s1, 0x81C($sp)
    /* C05FC 002BF9FC F7B40828 */  sdc1       $fs0, 0x828($sp)
    /* C0600 002BFA00 86020000 */  lh         $v0, 0x0($s0)
    /* C0604 002BFA04 14400009 */  .word 0x14400009
    /* C0608 002BFA08 00A08821 */  addu      $s1, $a1, $zero
    /* C060C 002BFA0C 0C0AFD11 */  jal        mdctInitTwiddles
    /* C0610 002BFA10 00000000 */  nop
    /* C0614 002BFA14 0C0AFD6B */  jal        mdctFftInit
    /* C0618 002BFA18 24040080 */  addiu     $a0, $zero, 0x80
    /* C061C 002BFA1C 3C018015 */  lui        $at, %hi(D_auto_80149830)
    /* C0620 002BFA20 AC229830 */  sw         $v0, %lo(D_auto_80149830)($at)
    /* C0624 002BFA24 24020001 */  addiu      $v0, $zero, 0x1
    /* C0628 002BFA28 A6020000 */  sh         $v0, 0x0($s0)
.Lauto_002BFA2C:
    /* C062C 002BFA2C 3C01800C */  lui        $at, %hi(D_auto_800C7BF8)
    /* C0630 002BFA30 C4347BF8 */  lwc1       $fs0, %lo(D_auto_800C7BF8)($at)
    /* C0634 002BFA34 27B00418 */  addiu      $s0, $sp, 0x418
    /* C0638 002BFA38 02002021 */  addu       $a0, $s0, $zero
    /* C063C 002BFA3C 0C0AFDCD */  jal        adecDequantize
    /* C0640 002BFA40 26250018 */  addiu     $a1, $s1, 0x18
    /* C0644 002BFA44 27A60018 */  addiu      $a2, $sp, 0x18
    /* C0648 002BFA48 00002821 */  addu       $a1, $zero, $zero
    /* C064C 002BFA4C 240700FF */  addiu      $a3, $zero, 0xFF
.Lauto_002BFA50:
    /* C0650 002BFA50 00051C00 */  sll        $v1, $a1, 16
    /* C0654 002BFA54 00031C03 */  sra        $v1, $v1, 16
    /* C0658 002BFA58 000320C0 */  sll        $a0, $v1, 3
    /* C065C 002BFA5C 00901021 */  addu       $v0, $a0, $s0
    /* C0660 002BFA60 00862021 */  addu       $a0, $a0, $a2
    /* C0664 002BFA64 00031840 */  sll        $v1, $v1, 1
    /* C0668 002BFA68 00E31823 */  subu       $v1, $a3, $v1
    /* C066C 002BFA6C 00031880 */  sll        $v1, $v1, 2
    /* C0670 002BFA70 00701821 */  addu       $v1, $v1, $s0
    /* C0674 002BFA74 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0678 002BFA78 24A20001 */  addiu      $v0, $a1, 0x1
    /* C067C 002BFA7C 00402821 */  addu       $a1, $v0, $zero
    /* C0680 002BFA80 00021400 */  sll        $v0, $v0, 16
    /* C0684 002BFA84 00021403 */  sra        $v0, $v0, 16
    /* C0688 002BFA88 E4800000 */  swc1       $fv0, 0x0($a0)
    /* C068C 002BFA8C C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C0690 002BFA90 28420080 */  slti       $v0, $v0, 0x80
    /* C0694 002BFA94 1440FFEE */  .word 0x1440FFEE
    /* C0698 002BFA98 E4800004 */  swc1      $fv0, 0x4($a0)
    /* C069C 002BFA9C 27A60018 */  addiu      $a2, $sp, 0x18
    /* C06A0 002BFAA0 3C088015 */  lui        $t0, %hi(D_auto_80148E30)
    /* C06A4 002BFAA4 25088E30 */  addiu      $t0, $t0, %lo(D_auto_80148E30)
    /* C06A8 002BFAA8 3C078015 */  lui        $a3, %hi(D_auto_80149030)
    /* C06AC 002BFAAC 24E79030 */  addiu      $a3, $a3, %lo(D_auto_80149030)
    /* C06B0 002BFAB0 00002821 */  addu       $a1, $zero, $zero
.Lauto_002BFAB4:
    /* C06B4 002BFAB4 00051400 */  sll        $v0, $a1, 16
    /* C06B8 002BFAB8 00021403 */  sra        $v0, $v0, 16
    /* C06BC 002BFABC 000220C0 */  sll        $a0, $v0, 3
    /* C06C0 002BFAC0 00862021 */  addu       $a0, $a0, $a2
    /* C06C4 002BFAC4 00021080 */  sll        $v0, $v0, 2
    /* C06C8 002BFAC8 00481821 */  addu       $v1, $v0, $t0
    /* C06CC 002BFACC C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C06D0 002BFAD0 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C06D4 002BFAD4 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C06D8 002BFAD8 00471021 */  addu       $v0, $v0, $a3
    /* C06DC 002BFADC C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C06E0 002BFAE0 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C06E4 002BFAE4 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C06E8 002BFAE8 00000000 */  nop
    /* C06EC 002BFAEC 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C06F0 002BFAF0 00000000 */  nop
    /* C06F4 002BFAF4 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C06F8 002BFAF8 24A20001 */  addiu      $v0, $a1, 0x1
    /* C06FC 002BFAFC 00402821 */  addu       $a1, $v0, $zero
    /* C0700 002BFB00 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C0704 002BFB04 00021400 */  sll        $v0, $v0, 16
    /* C0708 002BFB08 00021403 */  sra        $v0, $v0, 16
    /* C070C 002BFB0C 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C0710 002BFB10 28420080 */  slti       $v0, $v0, 0x80
    /* C0714 002BFB14 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C0718 002BFB18 1440FFE6 */  .word 0x1440FFE6
    /* C071C 002BFB1C E4820004 */  swc1      $fv1, 0x4($a0)
    /* C0720 002BFB20 3C038015 */  lui        $v1, %hi(D_auto_80149830)
    /* C0724 002BFB24 8C639830 */  lw         $v1, %lo(D_auto_80149830)($v1)
    /* C0728 002BFB28 8C620004 */  lw         $v0, 0x4($v1)
    /* C072C 002BFB2C 27B00018 */  addiu      $s0, $sp, 0x18
    /* C0730 002BFB30 AFA20010 */  sw         $v0, 0x10($sp)
    /* C0734 002BFB34 8C620008 */  lw         $v0, 0x8($v1)
    /* C0738 002BFB38 02002021 */  addu       $a0, $s0, $zero
    /* C073C 002BFB3C AFA20014 */  sw         $v0, 0x14($sp)
    /* C0740 002BFB40 8C65000C */  lw         $a1, 0xC($v1)
    /* C0744 002BFB44 8C670000 */  lw         $a3, 0x0($v1)
    /* C0748 002BFB48 0C0AFE16 */  jal        mdctFft
    /* C074C 002BFB4C 2406FFFF */  addiu     $a2, $zero, -0x1
    /* C0750 002BFB50 3C078015 */  lui        $a3, %hi(D_auto_80149230)
    /* C0754 002BFB54 24E79230 */  addiu      $a3, $a3, %lo(D_auto_80149230)
    /* C0758 002BFB58 3C068015 */  lui        $a2, %hi(D_auto_80149430)
    /* C075C 002BFB5C 24C69430 */  addiu      $a2, $a2, %lo(D_auto_80149430)
    /* C0760 002BFB60 00002821 */  addu       $a1, $zero, $zero
.Lauto_002BFB64:
    /* C0764 002BFB64 00051400 */  sll        $v0, $a1, 16
    /* C0768 002BFB68 00021403 */  sra        $v0, $v0, 16
    /* C076C 002BFB6C 000220C0 */  sll        $a0, $v0, 3
    /* C0770 002BFB70 00902021 */  addu       $a0, $a0, $s0
    /* C0774 002BFB74 00021080 */  sll        $v0, $v0, 2
    /* C0778 002BFB78 00471821 */  addu       $v1, $v0, $a3
    /* C077C 002BFB7C C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C0780 002BFB80 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C0784 002BFB84 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C0788 002BFB88 00461021 */  addu       $v0, $v0, $a2
    /* C078C 002BFB8C C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C0790 002BFB90 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0794 002BFB94 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C0798 002BFB98 00000000 */  nop
    /* C079C 002BFB9C 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C07A0 002BFBA0 00000000 */  nop
    /* C07A4 002BFBA4 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C07A8 002BFBA8 24A20001 */  addiu      $v0, $a1, 0x1
    /* C07AC 002BFBAC 00402821 */  addu       $a1, $v0, $zero
    /* C07B0 002BFBB0 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C07B4 002BFBB4 00021400 */  sll        $v0, $v0, 16
    /* C07B8 002BFBB8 00021403 */  sra        $v0, $v0, 16
    /* C07BC 002BFBBC 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C07C0 002BFBC0 28420080 */  slti       $v0, $v0, 0x80
    /* C07C4 002BFBC4 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C07C8 002BFBC8 1440FFE6 */  .word 0x1440FFE6
    /* C07CC 002BFBCC E4820004 */  swc1      $fv1, 0x4($a0)
    /* C07D0 002BFBD0 00003821 */  addu       $a3, $zero, $zero
    /* C07D4 002BFBD4 3C0C8015 */  lui        $t4, %hi(D_auto_80149630)
    /* C07D8 002BFBD8 258C9630 */  addiu      $t4, $t4, %lo(D_auto_80149630)
    /* C07DC 002BFBDC 3C0B8015 */  lui        $t3, %hi(D_auto_80148E30)
    /* C07E0 002BFBE0 256B8E30 */  addiu      $t3, $t3, %lo(D_auto_80148E30)
    /* C07E4 002BFBE4 27A80018 */  addiu      $t0, $sp, 0x18
    /* C07E8 002BFBE8 3C0A8015 */  lui        $t2, %hi(D_auto_80149030)
    /* C07EC 002BFBEC 254A9030 */  addiu      $t2, $t2, %lo(D_auto_80149030)
    /* C07F0 002BFBF0 240900FF */  addiu      $t1, $zero, 0xFF
    /* C07F4 002BFBF4 44804800 */  mtc1       $zero, $ft2f
    /* C07F8 002BFBF8 3C01800C */  lui        $at, %hi(D_auto_800C7BFC)
    /* C07FC 002BFBFC C4287BFC */  lwc1       $ft2, %lo(D_auto_800C7BFC)($at)
    /* C0800 002BFC00 3C01800C */  lui        $at, %hi(D_auto_800C7C00)
    /* C0804 002BFC04 C4277C00 */  lwc1       $ft1f, %lo(D_auto_800C7C00)($at)
    /* C0808 002BFC08 3C01800C */  lui        $at, %hi(D_auto_800C7C00 + 0x4)
    /* C080C 002BFC0C C4267C04 */  lwc1       $ft1, %lo(D_auto_800C7C00 + 0x4)($at)
    /* C0810 002BFC10 00071C00 */  sll        $v1, $a3, 16
.Lauto_002BFC14:
    /* C0814 002BFC14 00031C03 */  sra        $v1, $v1, 16
    /* C0818 002BFC18 00032080 */  sll        $a0, $v1, 2
    /* C081C 002BFC1C 008C3021 */  addu       $a2, $a0, $t4
    /* C0820 002BFC20 008B2821 */  addu       $a1, $a0, $t3
    /* C0824 002BFC24 000310C0 */  sll        $v0, $v1, 3
    /* C0828 002BFC28 34420004 */  ori        $v0, $v0, 0x4
    /* C082C 002BFC2C C4C40000 */  lwc1       $ft0, 0x0($a2)
    /* C0830 002BFC30 C4A50000 */  lwc1       $ft0f, 0x0($a1)
    /* C0834 002BFC34 01021021 */  addu       $v0, $t0, $v0
    /* C0838 002BFC38 46052042 */  mul.s      $fv0f, $ft0, $ft0f
    /* C083C 002BFC3C 008A2021 */  addu       $a0, $a0, $t2
    /* C0840 002BFC40 C4430000 */  lwc1       $fv1f, 0x0($v0)
    /* C0844 002BFC44 C4800000 */  lwc1       $fv0, 0x0($a0)
    /* C0848 002BFC48 46001882 */  mul.s      $fv1, $fv1f, $fv0
    /* C084C 002BFC4C 00000000 */  nop
    /* C0850 002BFC50 46002102 */  mul.s      $ft0, $ft0, $fv0
    /* C0854 002BFC54 00000000 */  nop
    /* C0858 002BFC58 460518C2 */  mul.s      $fv1f, $fv1f, $ft0f
    /* C085C 002BFC5C 46020840 */  add.s      $fv0f, $fv0f, $fv1
    /* C0860 002BFC60 4601A042 */  mul.s      $fv0f, $fs0, $fv0f
    /* C0864 002BFC64 000318C0 */  sll        $v1, $v1, 3
    /* C0868 002BFC68 01031821 */  addu       $v1, $t0, $v1
    /* C086C 002BFC6C C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C0870 002BFC70 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C0874 002BFC74 E4C00000 */  swc1       $fv0, 0x0($a2)
    /* C0878 002BFC78 4601483E */  c.le.s     $ft2f, $fv0f
    /* C087C 002BFC7C 00000000 */  nop
    /* C0880 002BFC80 45000008 */  .word 0x45000008
    /* C0884 002BFC84 46000806 */  mov.s     $fv0, $fv0f
    /* C0888 002BFC88 46080800 */  add.s      $fv0, $fv0f, $ft2
    /* C088C 002BFC8C 4600383C */  c.lt.s     $ft1f, $fv0
    /* C0890 002BFC90 00000000 */  nop
    /* C0894 002BFC94 45030008 */  .word 0x45030008
    /* C0898 002BFC98 46003806 */  mov.s     $fv0, $ft1f
    /* C089C 002BFC9C 080AFF2E */  .word 0x080AFF2E
    /* C08A0 002BFCA0 00000000 */  nop
.Lauto_002BFCA4:
    /* C08A4 002BFCA4 46080001 */  sub.s      $fv0, $fv0, $ft2
    /* C08A8 002BFCA8 4606003C */  c.lt.s     $fv0, $ft1
    /* C08AC 002BFCAC 00000000 */  nop
    /* C08B0 002BFCB0 45030001 */  .word 0x45030001
    /* C08B4 002BFCB4 46003006 */  mov.s     $fv0, $ft1
.Lauto_002BFCB8:
    /* C08B8 002BFCB8 4600028D */  trunc.w.s  $ft3, $fv0
    /* C08BC 002BFCBC 44035000 */  mfc1       $v1, $ft3
    /* C08C0 002BFCC0 4604A102 */  mul.s      $ft0, $fs0, $ft0
    /* C08C4 002BFCC4 00071400 */  sll        $v0, $a3, 16
    /* C08C8 002BFCC8 00021383 */  sra        $v0, $v0, 14
    /* C08CC 002BFCCC 00521021 */  addu       $v0, $v0, $s2
    /* C08D0 002BFCD0 A4430000 */  sh         $v1, 0x0($v0)
    /* C08D4 002BFCD4 4604483E */  c.le.s     $ft2f, $ft0
    /* C08D8 002BFCD8 00000000 */  nop
    /* C08DC 002BFCDC 45000008 */  .word 0x45000008
    /* C08E0 002BFCE0 46002006 */  mov.s     $fv0, $ft0
    /* C08E4 002BFCE4 46082100 */  add.s      $ft0, $ft0, $ft2
    /* C08E8 002BFCE8 4604383C */  c.lt.s     $ft1f, $ft0
    /* C08EC 002BFCEC 00000000 */  nop
    /* C08F0 002BFCF0 45030008 */  .word 0x45030008
    /* C08F4 002BFCF4 46003906 */  mov.s     $ft0, $ft1f
    /* C08F8 002BFCF8 080AFF45 */  .word 0x080AFF45
    /* C08FC 002BFCFC 00000000 */  nop
.Lauto_002BFD00:
    /* C0900 002BFD00 46080101 */  sub.s      $ft0, $fv0, $ft2
    /* C0904 002BFD04 4606203C */  c.lt.s     $ft0, $ft1
    /* C0908 002BFD08 00000000 */  nop
    /* C090C 002BFD0C 45030001 */  .word 0x45030001
    /* C0910 002BFD10 46003106 */  mov.s     $ft0, $ft1
.Lauto_002BFD14:
    /* C0914 002BFD14 4600228D */  trunc.w.s  $ft3, $ft0
    /* C0918 002BFD18 44035000 */  mfc1       $v1, $ft3
    /* C091C 002BFD1C 00071400 */  sll        $v0, $a3, 16
    /* C0920 002BFD20 000213C3 */  sra        $v0, $v0, 15
    /* C0924 002BFD24 01221023 */  subu       $v0, $t1, $v0
    /* C0928 002BFD28 00021040 */  sll        $v0, $v0, 1
    /* C092C 002BFD2C 00521021 */  addu       $v0, $v0, $s2
    /* C0930 002BFD30 A4430000 */  sh         $v1, 0x0($v0)
    /* C0934 002BFD34 24E20001 */  addiu      $v0, $a3, 0x1
    /* C0938 002BFD38 00403821 */  addu       $a3, $v0, $zero
    /* C093C 002BFD3C 00021400 */  sll        $v0, $v0, 16
    /* C0940 002BFD40 00021403 */  sra        $v0, $v0, 16
    /* C0944 002BFD44 28420080 */  slti       $v0, $v0, 0x80
    /* C0948 002BFD48 5440FFB2 */  .word 0x5440FFB2
    /* C094C 002BFD4C 00071C00 */  sll       $v1, $a3, 16
    /* C0950 002BFD50 8FBF0824 */  lw         $ra, 0x824($sp)
    /* C0954 002BFD54 8FB20820 */  lw         $s2, 0x820($sp)
    /* C0958 002BFD58 8FB1081C */  lw         $s1, 0x81C($sp)
    /* C095C 002BFD5C 8FB00818 */  lw         $s0, 0x818($sp)
    /* C0960 002BFD60 D7B40828 */  ldc1       $fs0, 0x828($sp)
    /* C0964 002BFD64 03E00008 */  jr         $ra
    /* C0968 002BFD68 27BD0830 */  addiu     $sp, $sp, 0x830
.globl adecDecodeFrameOk
adecDecodeFrameOk:
    /* C096C 002BFD6C 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C0970 002BFD70 AFBF0010 */  sw         $ra, 0x10($sp)
    /* C0974 002BFD74 0C0AFCAE */  jal        adecDecodeFrame
    /* C0978 002BFD78 00000000 */  nop
    /* C097C 002BFD7C 00021400 */  sll        $v0, $v0, 16
    /* C0980 002BFD80 00021403 */  sra        $v0, $v0, 16
    /* C0984 002BFD84 00021027 */  nor        $v0, $zero, $v0
    /* C0988 002BFD88 8FBF0010 */  lw         $ra, 0x10($sp)
    /* C098C 002BFD8C 000217C2 */  srl        $v0, $v0, 31
    /* C0990 002BFD90 03E00008 */  jr         $ra
    /* C0994 002BFD94 27BD0018 */  addiu     $sp, $sp, 0x18
.globl mdctBuildBitrevTable
mdctBuildBitrevTable:
    /* C0998 002BFD98 00805021 */  addu       $t2, $a0, $zero
    /* C099C 002BFD9C 00A04821 */  addu       $t1, $a1, $zero
    /* C09A0 002BFDA0 00003821 */  addu       $a3, $zero, $zero
    /* C09A4 002BFDA4 19200007 */  .word 0x19200007
    /* C09A8 002BFDA8 00094040 */  sll       $t0, $t1, 1
    /* C09AC 002BFDAC 01401821 */  addu       $v1, $t2, $zero
.Lauto_002BFDB0:
    /* C09B0 002BFDB0 AC670000 */  sw         $a3, 0x0($v1)
    /* C09B4 002BFDB4 24E70001 */  addiu      $a3, $a3, 0x1
    /* C09B8 002BFDB8 00E9102A */  slt        $v0, $a3, $t1
    /* C09BC 002BFDBC 1440FFFC */  .word 0x1440FFFC
    /* C09C0 002BFDC0 24630004 */  addiu     $v1, $v1, 0x4
.Lauto_002BFDC4:
    /* C09C4 002BFDC4 24060001 */  addiu      $a2, $zero, 0x1
    /* C09C8 002BFDC8 19000023 */  .word 0x19000023
    /* C09CC 002BFDCC 00C03821 */  addu      $a3, $a2, $zero
.Lauto_002BFDD0:
    /* C09D0 002BFDD0 00E6102A */  slt        $v0, $a3, $a2
    /* C09D4 002BFDD4 10400010 */  .word 0x10400010
    /* C09D8 002BFDD8 24C4FFFF */  addiu     $a0, $a2, -0x1
    /* C09DC 002BFDDC 000417C2 */  srl        $v0, $a0, 31
    /* C09E0 002BFDE0 00822021 */  addu       $a0, $a0, $v0
    /* C09E4 002BFDE4 00042043 */  sra        $a0, $a0, 1
    /* C09E8 002BFDE8 00042080 */  sll        $a0, $a0, 2
    /* C09EC 002BFDEC 008A2021 */  addu       $a0, $a0, $t2
    /* C09F0 002BFDF0 24E2FFFF */  addiu      $v0, $a3, -0x1
    /* C09F4 002BFDF4 00021FC2 */  srl        $v1, $v0, 31
    /* C09F8 002BFDF8 00431021 */  addu       $v0, $v0, $v1
    /* C09FC 002BFDFC 00021043 */  sra        $v0, $v0, 1
    /* C0A00 002BFE00 00021080 */  sll        $v0, $v0, 2
    /* C0A04 002BFE04 004A1021 */  addu       $v0, $v0, $t2
    /* C0A08 002BFE08 8C430000 */  lw         $v1, 0x0($v0)
    /* C0A0C 002BFE0C 8C850000 */  lw         $a1, 0x0($a0)
    /* C0A10 002BFE10 AC830000 */  sw         $v1, 0x0($a0)
    /* C0A14 002BFE14 AC450000 */  sw         $a1, 0x0($v0)
.Lauto_002BFE18:
    /* C0A18 002BFE18 01201821 */  addu       $v1, $t1, $zero
    /* C0A1C 002BFE1C 28620002 */  slti       $v0, $v1, 0x2
    /* C0A20 002BFE20 5440000A */  .word 0x5440000A
    /* C0A24 002BFE24 24E70002 */  addiu     $a3, $a3, 0x2
    /* C0A28 002BFE28 0066102A */  slt        $v0, $v1, $a2
.Lauto_002BFE2C:
    /* C0A2C 002BFE2C 50400007 */  .word 0x50400007
    /* C0A30 002BFE30 24E70002 */  addiu     $a3, $a3, 0x2
    /* C0A34 002BFE34 00C33023 */  subu       $a2, $a2, $v1
    /* C0A38 002BFE38 00031843 */  sra        $v1, $v1, 1
    /* C0A3C 002BFE3C 28620002 */  slti       $v0, $v1, 0x2
    /* C0A40 002BFE40 1040FFFA */  .word 0x1040FFFA
    /* C0A44 002BFE44 0066102A */  slt       $v0, $v1, $a2
    /* C0A48 002BFE48 24E70002 */  addiu      $a3, $a3, 0x2
.Lauto_002BFE4C:
    /* C0A4C 002BFE4C 0107102A */  slt        $v0, $t0, $a3
    /* C0A50 002BFE50 1040FFDF */  .word 0x1040FFDF
    /* C0A54 002BFE54 00C33021 */  addu      $a2, $a2, $v1
.Lauto_002BFE58:
    /* C0A58 002BFE58 03E00008 */  jr         $ra
    /* C0A5C 002BFE5C 00000000 */  nop
.globl mdctPackSpectrum
mdctPackSpectrum:
    /* C0A60 002BFE60 00804021 */  addu       $t0, $a0, $zero
    /* C0A64 002BFE64 00003021 */  addu       $a2, $zero, $zero
    /* C0A68 002BFE68 240700FF */  addiu      $a3, $zero, 0xFF
.Lauto_002BFE6C:
    /* C0A6C 002BFE6C 00061C00 */  sll        $v1, $a2, 16
    /* C0A70 002BFE70 00031C03 */  sra        $v1, $v1, 16
    /* C0A74 002BFE74 000320C0 */  sll        $a0, $v1, 3
    /* C0A78 002BFE78 00851021 */  addu       $v0, $a0, $a1
    /* C0A7C 002BFE7C 00882021 */  addu       $a0, $a0, $t0
    /* C0A80 002BFE80 00031840 */  sll        $v1, $v1, 1
    /* C0A84 002BFE84 00E31823 */  subu       $v1, $a3, $v1
    /* C0A88 002BFE88 00031880 */  sll        $v1, $v1, 2
    /* C0A8C 002BFE8C 00651821 */  addu       $v1, $v1, $a1
    /* C0A90 002BFE90 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0A94 002BFE94 24C20001 */  addiu      $v0, $a2, 0x1
    /* C0A98 002BFE98 00403021 */  addu       $a2, $v0, $zero
    /* C0A9C 002BFE9C 00021400 */  sll        $v0, $v0, 16
    /* C0AA0 002BFEA0 00021403 */  sra        $v0, $v0, 16
    /* C0AA4 002BFEA4 E4800000 */  swc1       $fv0, 0x0($a0)
    /* C0AA8 002BFEA8 C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C0AAC 002BFEAC 28420080 */  slti       $v0, $v0, 0x80
    /* C0AB0 002BFEB0 1440FFEE */  .word 0x1440FFEE
    /* C0AB4 002BFEB4 E4800004 */  swc1      $fv0, 0x4($a0)
    /* C0AB8 002BFEB8 03E00008 */  jr         $ra
    /* C0ABC 002BFEBC 00000000 */  nop
.globl mdctTwiddleMul
mdctTwiddleMul:
    /* C0AC0 002BFEC0 00804021 */  addu       $t0, $a0, $zero
    /* C0AC4 002BFEC4 00003821 */  addu       $a3, $zero, $zero
.Lauto_002BFEC8:
    /* C0AC8 002BFEC8 00071400 */  sll        $v0, $a3, 16
    /* C0ACC 002BFECC 00021403 */  sra        $v0, $v0, 16
    /* C0AD0 002BFED0 000220C0 */  sll        $a0, $v0, 3
    /* C0AD4 002BFED4 00882021 */  addu       $a0, $a0, $t0
    /* C0AD8 002BFED8 00021080 */  sll        $v0, $v0, 2
    /* C0ADC 002BFEDC 00451821 */  addu       $v1, $v0, $a1
    /* C0AE0 002BFEE0 C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C0AE4 002BFEE4 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C0AE8 002BFEE8 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C0AEC 002BFEEC 00461021 */  addu       $v0, $v0, $a2
    /* C0AF0 002BFEF0 C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C0AF4 002BFEF4 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0AF8 002BFEF8 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C0AFC 002BFEFC 00000000 */  nop
    /* C0B00 002BFF00 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C0B04 002BFF04 00000000 */  nop
    /* C0B08 002BFF08 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C0B0C 002BFF0C 24E20001 */  addiu      $v0, $a3, 0x1
    /* C0B10 002BFF10 00403821 */  addu       $a3, $v0, $zero
    /* C0B14 002BFF14 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C0B18 002BFF18 00021400 */  sll        $v0, $v0, 16
    /* C0B1C 002BFF1C 00021403 */  sra        $v0, $v0, 16
    /* C0B20 002BFF20 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C0B24 002BFF24 28420080 */  slti       $v0, $v0, 0x80
    /* C0B28 002BFF28 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C0B2C 002BFF2C 1440FFE6 */  .word 0x1440FFE6
    /* C0B30 002BFF30 E4820004 */  swc1      $fv1, 0x4($a0)
    /* C0B34 002BFF34 03E00008 */  jr         $ra
    /* C0B38 002BFF38 00000000 */  nop
.globl mdctFftCtx
mdctFftCtx:
    /* C0B3C 002BFF3C 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* C0B40 002BFF40 00A01021 */  addu       $v0, $a1, $zero
    /* C0B44 002BFF44 AFBF0018 */  sw         $ra, 0x18($sp)
    /* C0B48 002BFF48 8C430004 */  lw         $v1, 0x4($v0)
    /* C0B4C 002BFF4C AFA30010 */  sw         $v1, 0x10($sp)
    /* C0B50 002BFF50 8C430008 */  lw         $v1, 0x8($v0)
    /* C0B54 002BFF54 AFA30014 */  sw         $v1, 0x14($sp)
    /* C0B58 002BFF58 8C45000C */  lw         $a1, 0xC($v0)
    /* C0B5C 002BFF5C 8C470000 */  lw         $a3, 0x0($v0)
    /* C0B60 002BFF60 0C0AFE16 */  jal        mdctFft
    /* C0B64 002BFF64 00000000 */  nop
    /* C0B68 002BFF68 8FBF0018 */  lw         $ra, 0x18($sp)
    /* C0B6C 002BFF6C 03E00008 */  jr         $ra
    /* C0B70 002BFF70 27BD0020 */  addiu     $sp, $sp, 0x20
.globl adecRoundClampS16
adecRoundClampS16:
    /* C0B74 002BFF74 44800000 */  mtc1       $zero, $fv0
    /* C0B78 002BFF78 460C003E */  c.le.s     $fv0, $fa0
    /* C0B7C 002BFF7C 00000000 */  nop
    /* C0B80 002BFF80 45000009 */  .word 0x45000009
    /* C0B84 002BFF84 00000000 */  nop
    /* C0B88 002BFF88 3C01800C */  lui        $at, %hi(D_auto_800C7C08)
    /* C0B8C 002BFF8C C4207C08 */  lwc1       $fv0, %lo(D_auto_800C7C08)($at)
    /* C0B90 002BFF90 46006300 */  add.s      $fa0, $fa0, $fv0
    /* C0B94 002BFF94 3C01800C */  lui        $at, %hi(D_auto_800C7C0C)
    /* C0B98 002BFF98 C4207C0C */  lwc1       $fv0, %lo(D_auto_800C7C0C)($at)
    /* C0B9C 002BFF9C 460C003C */  c.lt.s     $fv0, $fa0
    /* C0BA0 002BFFA0 080AFFF0 */  .word 0x080AFFF0
    /* C0BA4 002BFFA4 00000000 */  nop
.Lauto_002BFFA8:
    /* C0BA8 002BFFA8 3C01800C */  lui        $at, %hi(D_auto_800C7C10)
    /* C0BAC 002BFFAC C4207C10 */  lwc1       $fv0, %lo(D_auto_800C7C10)($at)
    /* C0BB0 002BFFB0 46006301 */  sub.s      $fa0, $fa0, $fv0
    /* C0BB4 002BFFB4 3C01800C */  lui        $at, %hi(D_auto_800C7C14)
    /* C0BB8 002BFFB8 C4207C14 */  lwc1       $fv0, %lo(D_auto_800C7C14)($at)
    /* C0BBC 002BFFBC 4600603C */  c.lt.s     $fa0, $fv0
.Lauto_002BFFC0:
    /* C0BC0 002BFFC0 00000000 */  nop
    /* C0BC4 002BFFC4 45030001 */  .word 0x45030001
    /* C0BC8 002BFFC8 46000306 */  mov.s     $fa0, $fv0
.Lauto_002BFFCC:
    /* C0BCC 002BFFCC 4600604D */  trunc.w.s  $fv0f, $fa0
    /* C0BD0 002BFFD0 44020800 */  mfc1       $v0, $fv0f
    /* C0BD4 002BFFD4 00021400 */  sll        $v0, $v0, 16
    /* C0BD8 002BFFD8 03E00008 */  jr         $ra
    /* C0BDC 002BFFDC 00021403 */  sra       $v0, $v0, 16
.globl adecStreamOpen
adecStreamOpen:
    /* C0BE0 002BFFE0 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C0BE4 002BFFE4 00A04021 */  addu       $t0, $a1, $zero
    /* C0BE8 002BFFE8 3C038015 */  lui        $v1, %hi(D_auto_80149A38)
    /* C0BEC 002BFFEC 24639A38 */  addiu      $v1, $v1, %lo(D_auto_80149A38)
    /* C0BF0 002BFFF0 AFBF0010 */  sw         $ra, 0x10($sp)
    /* C0BF4 002BFFF4 AC640008 */  sw         $a0, 0x8($v1)
    /* C0BF8 002BFFF8 AC640014 */  sw         $a0, 0x14($v1)
    /* C0BFC 002BFFFC 8C870000 */  lw         $a3, 0x0($a0)
    /* C0C00 002C0000 24820004 */  addiu      $v0, $a0, 0x4
    /* C0C04 002C0004 AC620014 */  sw         $v0, 0x14($v1)
    /* C0C08 002C0008 AC670000 */  sw         $a3, 0x0($v1)
    /* C0C0C 002C000C 8C820004 */  lw         $v0, 0x4($a0)
    /* C0C10 002C0010 3C0A0F42 */  lui        $t2, (0xF424000 >> 16)
    /* C0C14 002C0014 AC620010 */  sw         $v0, 0x10($v1)
    /* C0C18 002C0018 8C850004 */  lw         $a1, 0x4($a0)
    /* C0C1C 002C001C 24820008 */  addiu      $v0, $a0, 0x8
    /* C0C20 002C0020 AC620014 */  sw         $v0, 0x14($v1)
    /* C0C24 002C0024 AC65000C */  sw         $a1, 0xC($v1)
    /* C0C28 002C0028 8C820008 */  lw         $v0, 0x8($a0)
    /* C0C2C 002C002C 2484000C */  addiu      $a0, $a0, 0xC
    /* C0C30 002C0030 AC640014 */  sw         $a0, 0x14($v1)
    /* C0C34 002C0034 3C01800D */  lui        $at, %hi(D_auto_800D416E)
    /* C0C38 002C0038 A420416E */  sh         $zero, %lo(D_auto_800D416E)($at)
    /* C0C3C 002C003C 3C01800D */  lui        $at, %hi(D_auto_800D4170)
    /* C0C40 002C0040 A4204170 */  sh         $zero, %lo(D_auto_800D4170)($at)
    /* C0C44 002C0044 3C01800D */  lui        $at, %hi(D_auto_800D4168)
    /* C0C48 002C0048 A4204168 */  sh         $zero, %lo(D_auto_800D4168)($at)
    /* C0C4C 002C004C 3C01800D */  lui        $at, %hi(D_auto_800D416A)
    /* C0C50 002C0050 A420416A */  sh         $zero, %lo(D_auto_800D416A)($at)
    /* C0C54 002C0054 3C01800D */  lui        $at, %hi(D_auto_800D416C)
    /* C0C58 002C0058 A420416C */  sh         $zero, %lo(D_auto_800D416C)($at)
    /* C0C5C 002C005C AC620004 */  sw         $v0, 0x4($v1)
    /* C0C60 002C0060 ACC70000 */  sw         $a3, 0x0($a2)
    /* C0C64 002C0064 8C620010 */  lw         $v0, 0x10($v1)
    /* C0C68 002C0068 354A4000 */  ori        $t2, $t2, (0xF424000 & 0xFFFF)
    /* C0C6C 002C006C 004A0018 */  mult       $v0, $t2
    /* C0C70 002C0070 01004821 */  addu       $t1, $t0, $zero
    /* C0C74 002C0074 00004021 */  addu       $t0, $zero, $zero
    /* C0C78 002C0078 01003021 */  addu       $a2, $t0, $zero
    /* C0C7C 002C007C 00002010 */  mfhi       $a0
    /* C0C80 002C0080 00002812 */  mflo       $a1
    /* C0C84 002C0084 0C0B0334 */  jal        __udivdi3
    /* C0C88 002C0088 01203821 */  addu      $a3, $t1, $zero
    /* C0C8C 002C008C 8FBF0010 */  lw         $ra, 0x10($sp)
    /* C0C90 002C0090 00601021 */  addu       $v0, $v1, $zero
    /* C0C94 002C0094 03E00008 */  jr         $ra
    /* C0C98 002C0098 27BD0018 */  addiu     $sp, $sp, 0x18
.globl adecNextFrame
adecNextFrame:
    /* C0C9C 002C009C 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* C0CA0 002C00A0 AFB20018 */  sw         $s2, 0x18($sp)
    /* C0CA4 002C00A4 3C128015 */  lui        $s2, %hi(D_auto_80149A38)
    /* C0CA8 002C00A8 26529A38 */  addiu      $s2, $s2, %lo(D_auto_80149A38)
    /* C0CAC 002C00AC AFBF001C */  sw         $ra, 0x1C($sp)
    /* C0CB0 002C00B0 AFB10014 */  sw         $s1, 0x14($sp)
    /* C0CB4 002C00B4 AFB00010 */  sw         $s0, 0x10($sp)
    /* C0CB8 002C00B8 8E420010 */  lw         $v0, 0x10($s2)
    /* C0CBC 002C00BC 10400019 */  .word 0x10400019
    /* C0CC0 002C00C0 00001021 */  addu      $v0, $zero, $zero
    /* C0CC4 002C00C4 0C0AFCAE */  jal        adecDecodeFrame
    /* C0CC8 002C00C8 02402021 */  addu      $a0, $s2, $zero
    /* C0CCC 002C00CC 3C11800D */  lui        $s1, %hi(D_auto_800D4172)
    /* C0CD0 002C00D0 26314172 */  addiu      $s1, $s1, %lo(D_auto_800D4172)
    /* C0CD4 002C00D4 96220000 */  lhu        $v0, 0x0($s1)
    /* C0CD8 002C00D8 24420001 */  addiu      $v0, $v0, 0x1
    /* C0CDC 002C00DC A6220000 */  sh         $v0, 0x0($s1)
    /* C0CE0 002C00E0 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C0CE4 002C00E4 2C420006 */  sltiu      $v0, $v0, 0x6
    /* C0CE8 002C00E8 50400001 */  .word 0x50400001
    /* C0CEC 002C00EC A6200000 */  sh        $zero, 0x0($s1)
.Lauto_002C00F0:
    /* C0CF0 002C00F0 3C108015 */  lui        $s0, %hi(D_auto_80149CF0)
    /* C0CF4 002C00F4 26109CF0 */  addiu      $s0, $s0, %lo(D_auto_80149CF0)
    /* C0CF8 002C00F8 96240000 */  lhu        $a0, 0x0($s1)
    /* C0CFC 002C00FC 02402821 */  addu       $a1, $s2, $zero
    /* C0D00 002C0100 00042240 */  sll        $a0, $a0, 9
    /* C0D04 002C0104 0C0AFE77 */  jal        adecImdctFrame
    /* C0D08 002C0108 00902021 */  addu      $a0, $a0, $s0
    /* C0D0C 002C010C 96220000 */  lhu        $v0, 0x0($s1)
    /* C0D10 002C0110 8E430010 */  lw         $v1, 0x10($s2)
    /* C0D14 002C0114 00021240 */  sll        $v0, $v0, 9
    /* C0D18 002C0118 00501021 */  addu       $v0, $v0, $s0
    /* C0D1C 002C011C 2463FFFF */  addiu      $v1, $v1, -0x1
    /* C0D20 002C0120 AE430010 */  sw         $v1, 0x10($s2)
.Lauto_002C0124:
    /* C0D24 002C0124 8FBF001C */  lw         $ra, 0x1C($sp)
    /* C0D28 002C0128 8FB20018 */  lw         $s2, 0x18($sp)
    /* C0D2C 002C012C 8FB10014 */  lw         $s1, 0x14($sp)
    /* C0D30 002C0130 8FB00010 */  lw         $s0, 0x10($sp)
    /* C0D34 002C0134 03E00008 */  jr         $ra
    /* C0D38 002C0138 27BD0020 */  addiu     $sp, $sp, 0x20
.globl adecGetStopFlag
adecGetStopFlag:
    /* C0D3C 002C013C 3C028015 */  lui        $v0, %hi(D_auto_80149A48)
    /* C0D40 002C0140 8C429A48 */  lw         $v0, %lo(D_auto_80149A48)($v0)
    /* C0D44 002C0144 03E00008 */  jr         $ra
    /* C0D48 002C0148 00000000 */  nop
.globl adecClearStopFlag
adecClearStopFlag:
    /* C0D4C 002C014C 3C018015 */  lui        $at, %hi(D_auto_80149A48)
    /* C0D50 002C0150 AC209A48 */  sw         $zero, %lo(D_auto_80149A48)($at)
    /* C0D54 002C0154 03E00008 */  jr         $ra
    /* C0D58 002C0158 00000000 */  nop
