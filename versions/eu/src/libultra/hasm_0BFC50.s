.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBFC50-0xC10CC (VRAM 0x002BF050) */
.globl adecReadBits
adecReadBits:
    /* BFC50 002BF050 27BDFFF8 */  addiu      $sp, $sp, -0x8
    /* BFC54 002BF054 AFB10004 */  sw         $s1, 0x4($sp)
    /* BFC58 002BF058 00808821 */  addu       $s1, $a0, $zero
    /* BFC5C 002BF05C 3C04800E */  lui        $a0, %hi(D_auto_800E5B38)
    /* BFC60 002BF060 24845B38 */  addiu      $a0, $a0, %lo(D_auto_800E5B38)
    /* BFC64 002BF064 AFB00000 */  sw         $s0, 0x0($sp)
    /* BFC68 002BF068 94820000 */  lhu        $v0, 0x0($a0)
    /* BFC6C 002BF06C 8FB90018 */  lw         $t9, 0x18($sp)
    /* BFC70 002BF070 1440000B */  .word 0x1440000B
    /* BFC74 002BF074 30C2FFFF */  andi      $v0, $a2, 0xFFFF
    /* BFC78 002BF078 8F220014 */  lw         $v0, 0x14($t9)
    /* BFC7C 002BF07C 94430000 */  lhu        $v1, 0x0($v0)
    /* BFC80 002BF080 24420002 */  addiu      $v0, $v0, 0x2
    /* BFC84 002BF084 AF220014 */  sw         $v0, 0x14($t9)
    /* BFC88 002BF088 24020010 */  addiu      $v0, $zero, 0x10
    /* BFC8C 002BF08C A4820000 */  sh         $v0, 0x0($a0)
    /* BFC90 002BF090 3C028016 */  lui        $v0, %hi(D_auto_8015AE00)
    /* BFC94 002BF094 2442AE00 */  addiu      $v0, $v0, %lo(D_auto_8015AE00)
    /* BFC98 002BF098 A4430000 */  sh         $v1, 0x0($v0)
    /* BFC9C 002BF09C 30C2FFFF */  andi       $v0, $a2, 0xFFFF
.Lauto_002BF0A0:
    /* BFCA0 002BF0A0 1040005B */  .word 0x1040005B
    /* BFCA4 002BF0A4 00004821 */  addu      $t1, $zero, $zero
    /* BFCA8 002BF0A8 00805021 */  addu       $t2, $a0, $zero
    /* BFCAC 002BF0AC 3C0B8016 */  lui        $t3, %hi(D_auto_8015AE00)
    /* BFCB0 002BF0B0 256BAE00 */  addiu      $t3, $t3, %lo(D_auto_8015AE00)
    /* BFCB4 002BF0B4 24100010 */  addiu      $s0, $zero, 0x10
    /* BFCB8 002BF0B8 02071004 */  sllv       $v0, $a3, $s0
    /* BFCBC 002BF0BC 02027807 */  srav       $t7, $v0, $s0
    /* BFCC0 002BF0C0 30ADFFFF */  andi       $t5, $a1, 0xFFFF
    /* BFCC4 002BF0C4 3C02800E */  lui        $v0, %hi(D_auto_800E59F4)
    /* BFCC8 002BF0C8 244259F4 */  addiu      $v0, $v0, %lo(D_auto_800E59F4)
    /* BFCCC 002BF0CC 000D1840 */  sll        $v1, $t5, 1
    /* BFCD0 002BF0D0 00627021 */  addu       $t6, $v1, $v0
    /* BFCD4 002BF0D4 3C18800E */  lui        $t8, %hi(D_auto_800E59D0)
    /* BFCD8 002BF0D8 271859D0 */  addiu      $t8, $t8, %lo(D_auto_800E59D0)
    /* BFCDC 002BF0DC 00786021 */  addu       $t4, $v1, $t8
.Lauto_002BF0E0:
    /* BFCE0 002BF0E0 95430000 */  lhu        $v1, 0x0($t2)
    /* BFCE4 002BF0E4 006D102B */  sltu       $v0, $v1, $t5
    /* BFCE8 002BF0E8 10400029 */  .word 0x10400029
    /* BFCEC 002BF0EC 3064FFFF */  andi      $a0, $v1, 0xFFFF
    /* BFCF0 002BF0F0 00A34023 */  subu       $t0, $a1, $v1
    /* BFCF4 002BF0F4 00042040 */  sll        $a0, $a0, 1
    /* BFCF8 002BF0F8 00982021 */  addu       $a0, $a0, $t8
    /* BFCFC 002BF0FC 00091400 */  sll        $v0, $t1, 16
    /* BFD00 002BF100 000213C3 */  sra        $v0, $v0, 15
    /* BFD04 002BF104 95630000 */  lhu        $v1, 0x0($t3)
    /* BFD08 002BF108 94840000 */  lhu        $a0, 0x0($a0)
    /* BFD0C 002BF10C 00513821 */  addu       $a3, $v0, $s1
    /* BFD10 002BF110 00641824 */  and        $v1, $v1, $a0
    /* BFD14 002BF114 3104FFFF */  andi       $a0, $t0, 0xFFFF
    /* BFD18 002BF118 00831804 */  sllv       $v1, $v1, $a0
    /* BFD1C 002BF11C A4E30000 */  sh         $v1, 0x0($a3)
    /* BFD20 002BF120 8F220014 */  lw         $v0, 0x14($t9)
    /* BFD24 002BF124 94430000 */  lhu        $v1, 0x0($v0)
    /* BFD28 002BF128 24420002 */  addiu      $v0, $v0, 0x2
    /* BFD2C 002BF12C AF220014 */  sw         $v0, 0x14($t9)
    /* BFD30 002BF130 02041023 */  subu       $v0, $s0, $a0
    /* BFD34 002BF134 00042040 */  sll        $a0, $a0, 1
    /* BFD38 002BF138 00982021 */  addu       $a0, $a0, $t8
    /* BFD3C 002BF13C A5630000 */  sh         $v1, 0x0($t3)
    /* BFD40 002BF140 3063FFFF */  andi       $v1, $v1, 0xFFFF
    /* BFD44 002BF144 00431807 */  srav       $v1, $v1, $v0
    /* BFD48 002BF148 94820000 */  lhu        $v0, 0x0($a0)
    /* BFD4C 002BF14C 94E40000 */  lhu        $a0, 0x0($a3)
    /* BFD50 002BF150 00621824 */  and        $v1, $v1, $v0
    /* BFD54 002BF154 00832025 */  or         $a0, $a0, $v1
    /* BFD58 002BF158 11E0000B */  .word 0x11E0000B
    /* BFD5C 002BF15C A4E40000 */  sh        $a0, 0x0($a3)
    /* BFD60 002BF160 00041400 */  sll        $v0, $a0, 16
    /* BFD64 002BF164 95C30000 */  lhu        $v1, 0x0($t6)
    /* BFD68 002BF168 00021403 */  sra        $v0, $v0, 16
    /* BFD6C 002BF16C 00431024 */  and        $v0, $v0, $v1
    /* BFD70 002BF170 5040001E */  .word 0x5040001E
    /* BFD74 002BF174 02081023 */  subu      $v0, $s0, $t0
    /* BFD78 002BF178 95820000 */  lhu        $v0, 0x0($t4)
    /* BFD7C 002BF17C 00021027 */  nor        $v0, $zero, $v0
    /* BFD80 002BF180 00821025 */  or         $v0, $a0, $v0
    /* BFD84 002BF184 A4E20000 */  sh         $v0, 0x0($a3)
.Lauto_002BF188:
    /* BFD88 002BF188 080AFC7B */  .word 0x080AFC7B
    /* BFD8C 002BF18C 02081023 */  subu      $v0, $s0, $t0
.Lauto_002BF190:
    /* BFD90 002BF190 95430000 */  lhu        $v1, 0x0($t2)
    /* BFD94 002BF194 95620000 */  lhu        $v0, 0x0($t3)
    /* BFD98 002BF198 95840000 */  lhu        $a0, 0x0($t4)
    /* BFD9C 002BF19C 006D1823 */  subu       $v1, $v1, $t5
    /* BFDA0 002BF1A0 00621007 */  srav       $v0, $v0, $v1
    /* BFDA4 002BF1A4 00442024 */  and        $a0, $v0, $a0
    /* BFDA8 002BF1A8 00091400 */  sll        $v0, $t1, 16
    /* BFDAC 002BF1AC 000213C3 */  sra        $v0, $v0, 15
    /* BFDB0 002BF1B0 00513821 */  addu       $a3, $v0, $s1
    /* BFDB4 002BF1B4 11E0000B */  .word 0x11E0000B
    /* BFDB8 002BF1B8 A4E40000 */  sh        $a0, 0x0($a3)
    /* BFDBC 002BF1BC 00041400 */  sll        $v0, $a0, 16
    /* BFDC0 002BF1C0 95C30000 */  lhu        $v1, 0x0($t6)
    /* BFDC4 002BF1C4 00021403 */  sra        $v0, $v0, 16
    /* BFDC8 002BF1C8 00431024 */  and        $v0, $v0, $v1
    /* BFDCC 002BF1CC 10400005 */  .word 0x10400005
    /* BFDD0 002BF1D0 00000000 */  nop
    /* BFDD4 002BF1D4 95820000 */  lhu        $v0, 0x0($t4)
    /* BFDD8 002BF1D8 00021027 */  nor        $v0, $zero, $v0
    /* BFDDC 002BF1DC 00821025 */  or         $v0, $a0, $v0
    /* BFDE0 002BF1E0 A4E20000 */  sh         $v0, 0x0($a3)
.Lauto_002BF1E4:
    /* BFDE4 002BF1E4 95420000 */  lhu        $v0, 0x0($t2)
    /* BFDE8 002BF1E8 00451023 */  subu       $v0, $v0, $a1
.Lauto_002BF1EC:
    /* BFDEC 002BF1EC A5420000 */  sh         $v0, 0x0($t2)
    /* BFDF0 002BF1F0 25220001 */  addiu      $v0, $t1, 0x1
    /* BFDF4 002BF1F4 00404821 */  addu       $t1, $v0, $zero
    /* BFDF8 002BF1F8 00021400 */  sll        $v0, $v0, 16
    /* BFDFC 002BF1FC 00021403 */  sra        $v0, $v0, 16
    /* BFE00 002BF200 30C3FFFF */  andi       $v1, $a2, 0xFFFF
    /* BFE04 002BF204 0043102A */  slt        $v0, $v0, $v1
    /* BFE08 002BF208 1440FFB5 */  .word 0x1440FFB5
    /* BFE0C 002BF20C 00000000 */  nop
.Lauto_002BF210:
    /* BFE10 002BF210 8FB10004 */  lw         $s1, 0x4($sp)
    /* BFE14 002BF214 8FB00000 */  lw         $s0, 0x0($sp)
    /* BFE18 002BF218 24020001 */  addiu      $v0, $zero, 0x1
    /* BFE1C 002BF21C 03E00008 */  jr         $ra
    /* BFE20 002BF220 27BD0008 */  addiu     $sp, $sp, 0x8
.globl adecHuffDecode
adecHuffDecode:
    /* BFE24 002BF224 27BDFFA8 */  addiu      $sp, $sp, -0x58
    /* BFE28 002BF228 00805021 */  addu       $t2, $a0, $zero
    /* BFE2C 002BF22C 00A04821 */  addu       $t1, $a1, $zero
    /* BFE30 002BF230 AFB50044 */  sw         $s5, 0x44($sp)
    /* BFE34 002BF234 0000A821 */  addu       $s5, $zero, $zero
    /* BFE38 002BF238 AFB20038 */  sw         $s2, 0x38($sp)
    /* BFE3C 002BF23C 02A09021 */  addu       $s2, $s5, $zero
    /* BFE40 002BF240 00E04021 */  addu       $t0, $a3, $zero
    /* BFE44 002BF244 AFB10034 */  sw         $s1, 0x34($sp)
    /* BFE48 002BF248 00061400 */  sll        $v0, $a2, 16
    /* BFE4C 002BF24C AFBF0054 */  sw         $ra, 0x54($sp)
    /* BFE50 002BF250 AFBE0050 */  sw         $fp, 0x50($sp)
    /* BFE54 002BF254 AFB7004C */  sw         $s7, 0x4C($sp)
    /* BFE58 002BF258 AFB60048 */  sw         $s6, 0x48($sp)
    /* BFE5C 002BF25C AFB40040 */  sw         $s4, 0x40($sp)
    /* BFE60 002BF260 AFB3003C */  sw         $s3, 0x3C($sp)
    /* BFE64 002BF264 AFB00030 */  sw         $s0, 0x30($sp)
    /* BFE68 002BF268 A5000000 */  sh         $zero, 0x0($t0)
    /* BFE6C 002BF26C 8D530010 */  lw         $s3, 0x10($t2)
    /* BFE70 002BF270 00021C03 */  sra        $v1, $v0, 16
    /* BFE74 002BF274 8E740020 */  lw         $s4, 0x20($s3)
    /* BFE78 002BF278 186000DD */  .word 0x186000DD
    /* BFE7C 002BF27C 02A08821 */  addu      $s1, $s5, $zero
    /* BFE80 002BF280 3C1E800E */  lui        $fp, %hi(D_auto_800E5B3C)
    /* BFE84 002BF284 27DE5B3C */  addiu      $fp, $fp, %lo(D_auto_800E5B3C)
    /* BFE88 002BF288 3C17800E */  lui        $s7, %hi(D_auto_800E5B3A)
    /* BFE8C 002BF28C 26F75B3A */  addiu      $s7, $s7, %lo(D_auto_800E5B3A)
    /* BFE90 002BF290 AFA20018 */  sw         $v0, 0x18($sp)
    /* BFE94 002BF294 0060B021 */  addu       $s6, $v1, $zero
.Lauto_002BF298:
    /* BFE98 002BF298 97C30000 */  lhu        $v1, 0x0($fp)
    /* BFE9C 002BF29C 106000B9 */  .word 0x106000B9
    /* BFEA0 002BF2A0 2463FFFF */  addiu     $v1, $v1, -0x1
    /* BFEA4 002BF2A4 96E20000 */  lhu        $v0, 0x0($s7)
    /* BFEA8 002BF2A8 A7C30000 */  sh         $v1, 0x0($fp)
    /* BFEAC 002BF2AC 30438000 */  andi       $v1, $v0, 0x8000
    /* BFEB0 002BF2B0 00021040 */  sll        $v0, $v0, 1
    /* BFEB4 002BF2B4 10600007 */  .word 0x10600007
    /* BFEB8 002BF2B8 A6E20000 */  sh        $v0, 0x0($s7)
    /* BFEBC 002BF2BC 00151400 */  sll        $v0, $s5, 16
    /* BFEC0 002BF2C0 00021383 */  sra        $v0, $v0, 14
    /* BFEC4 002BF2C4 00541021 */  addu       $v0, $v0, $s4
    /* BFEC8 002BF2C8 94440002 */  lhu        $a0, 0x2($v0)
    /* BFECC 002BF2CC 080AFCBA */  .word 0x080AFCBA
    /* BFED0 002BF2D0 00041400 */  sll       $v0, $a0, 16
.Lauto_002BF2D4:
    /* BFED4 002BF2D4 00151400 */  sll        $v0, $s5, 16
    /* BFED8 002BF2D8 00021383 */  sra        $v0, $v0, 14
    /* BFEDC 002BF2DC 00541021 */  addu       $v0, $v0, $s4
    /* BFEE0 002BF2E0 94440000 */  lhu        $a0, 0x0($v0)
    /* BFEE4 002BF2E4 00041400 */  sll        $v0, $a0, 16
.Lauto_002BF2E8:
    /* BFEE8 002BF2E8 00021383 */  sra        $v0, $v0, 14
    /* BFEEC 002BF2EC 00542821 */  addu       $a1, $v0, $s4
    /* BFEF0 002BF2F0 94A30000 */  lhu        $v1, 0x0($a1)
    /* BFEF4 002BF2F4 24020800 */  addiu      $v0, $zero, 0x800
    /* BFEF8 002BF2F8 146200B8 */  .word 0x146200B8
    /* BFEFC 002BF2FC 0080A821 */  addu      $s5, $a0, $zero
    /* BFF00 002BF300 94B00002 */  lhu        $s0, 0x2($a1)
    /* BFF04 002BF304 32040F00 */  andi       $a0, $s0, 0xF00
    /* BFF08 002BF308 10800004 */  .word 0x10800004
    /* BFF0C 002BF30C 0000A821 */  addu      $s5, $zero, $zero
    /* BFF10 002BF310 24020F00 */  addiu      $v0, $zero, 0xF00
    /* BFF14 002BF314 14820007 */  .word 0x14820007
    /* BFF18 002BF318 00101400 */  sll       $v0, $s0, 16
.Lauto_002BF31C:
    /* BFF1C 002BF31C 00111400 */  sll        $v0, $s1, 16
    /* BFF20 002BF320 000213C3 */  sra        $v0, $v0, 15
    /* BFF24 002BF324 00491021 */  addu       $v0, $v0, $t1
    /* BFF28 002BF328 A4500000 */  sh         $s0, 0x0($v0)
    /* BFF2C 002BF32C 080AFD45 */  .word 0x080AFD45
    /* BFF30 002BF330 26310001 */  addiu     $s1, $s1, 0x1
.Lauto_002BF334:
    /* BFF34 002BF334 00021403 */  sra        $v0, $v0, 16
    /* BFF38 002BF338 24030900 */  addiu      $v1, $zero, 0x900
    /* BFF3C 002BF33C 14430020 */  .word 0x14430020
    /* BFF40 002BF340 24020A00 */  addiu     $v0, $zero, 0xA00
    /* BFF44 002BF344 02E02021 */  addu       $a0, $s7, $zero
    /* BFF48 002BF348 24060001 */  addiu      $a2, $zero, 0x1
    /* BFF4C 002BF34C 96F00000 */  lhu        $s0, 0x0($s7)
    /* BFF50 002BF350 9665000E */  lhu        $a1, 0xE($s3)
    /* BFF54 002BF354 8FAB0068 */  lw         $t3, 0x68($sp)
    /* BFF58 002BF358 00003821 */  addu       $a3, $zero, $zero
    /* BFF5C 002BF35C AFA80020 */  sw         $t0, 0x20($sp)
    /* BFF60 002BF360 AFA90024 */  sw         $t1, 0x24($sp)
    /* BFF64 002BF364 AFAA0028 */  sw         $t2, 0x28($sp)
    /* BFF68 002BF368 0C0AFC14 */  jal        adecReadBits
    /* BFF6C 002BF36C AFAB0010 */  sw        $t3, 0x10($sp)
    /* BFF70 002BF370 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* BFF74 002BF374 8FA80020 */  lw         $t0, 0x20($sp)
    /* BFF78 002BF378 8FA90024 */  lw         $t1, 0x24($sp)
    /* BFF7C 002BF37C 8FAA0028 */  lw         $t2, 0x28($sp)
    /* BFF80 002BF380 10400091 */  .word 0x10400091
    /* BFF84 002BF384 00112400 */  sll       $a0, $s1, 16
    /* BFF88 002BF388 26310001 */  addiu      $s1, $s1, 0x1
    /* BFF8C 002BF38C 24020010 */  addiu      $v0, $zero, 0x10
    /* BFF90 002BF390 000423C3 */  sra        $a0, $a0, 15
    /* BFF94 002BF394 00892021 */  addu       $a0, $a0, $t1
    /* BFF98 002BF398 3C05800E */  lui        $a1, %hi(D_auto_800E5B3C)
    /* BFF9C 002BF39C 94A55B3C */  lhu        $a1, %lo(D_auto_800E5B3C)($a1)
    /* BFFA0 002BF3A0 96E30000 */  lhu        $v1, 0x0($s7)
    /* BFFA4 002BF3A4 00451023 */  subu       $v0, $v0, $a1
    /* BFFA8 002BF3A8 00431004 */  sllv       $v0, $v1, $v0
    /* BFFAC 002BF3AC 00A31807 */  srav       $v1, $v1, $a1
    /* BFFB0 002BF3B0 02031825 */  or         $v1, $s0, $v1
    /* BFFB4 002BF3B4 A6E20000 */  sh         $v0, 0x0($s7)
    /* BFFB8 002BF3B8 080AFD45 */  .word 0x080AFD45
    /* BFFBC 002BF3BC A4830000 */  sh        $v1, 0x0($a0)
.Lauto_002BF3C0:
    /* BFFC0 002BF3C0 14820023 */  .word 0x14820023
    /* BFFC4 002BF3C4 24020B00 */  addiu     $v0, $zero, 0xB00
    /* BFFC8 002BF3C8 00003021 */  addu       $a2, $zero, $zero
    /* BFFCC 002BF3CC 320300FF */  andi       $v1, $s0, 0xFF
    /* BFFD0 002BF3D0 000310C0 */  sll        $v0, $v1, 3
    /* BFFD4 002BF3D4 00431023 */  subu       $v0, $v0, $v1
    /* BFFD8 002BF3D8 000210C0 */  sll        $v0, $v0, 3
    /* BFFDC 002BF3DC 00431023 */  subu       $v0, $v0, $v1
    /* BFFE0 002BF3E0 000210C0 */  sll        $v0, $v0, 3
    /* BFFE4 002BF3E4 00111C00 */  sll        $v1, $s1, 16
    /* BFFE8 002BF3E8 8E64001C */  lw         $a0, 0x1C($s3)
    /* BFFEC 002BF3EC 00031BC3 */  sra        $v1, $v1, 15
    /* BFFF0 002BF3F0 00442821 */  addu       $a1, $v0, $a0
    /* BFFF4 002BF3F4 8CA201A0 */  lw         $v0, 0x1A0($a1)
    /* BFFF8 002BF3F8 18400011 */  .word 0x18400011
    /* BFFFC 002BF3FC 00693821 */  addu      $a3, $v1, $t1
    /* C0000 002BF400 00061400 */  sll        $v0, $a2, 16
.Lauto_002BF404:
    /* C0004 002BF404 24C30001 */  addiu      $v1, $a2, 0x1
    /* C0008 002BF408 00603021 */  addu       $a2, $v1, $zero
    /* C000C 002BF40C 00021403 */  sra        $v0, $v0, 16
    /* C0010 002BF410 00022040 */  sll        $a0, $v0, 1
    /* C0014 002BF414 00021080 */  sll        $v0, $v0, 2
    /* C0018 002BF418 00A21021 */  addu       $v0, $a1, $v0
    /* C001C 002BF41C 00872021 */  addu       $a0, $a0, $a3
    /* C0020 002BF420 944200A2 */  lhu        $v0, 0xA2($v0)
    /* C0024 002BF424 00031C00 */  sll        $v1, $v1, 16
    /* C0028 002BF428 A4820000 */  sh         $v0, 0x0($a0)
    /* C002C 002BF42C 8CA201A0 */  lw         $v0, 0x1A0($a1)
    /* C0030 002BF430 00031C03 */  sra        $v1, $v1, 16
    /* C0034 002BF434 0062182A */  slt        $v1, $v1, $v0
    /* C0038 002BF438 1460FFF2 */  .word 0x1460FFF2
    /* C003C 002BF43C 00061400 */  sll       $v0, $a2, 16
.Lauto_002BF440:
    /* C0040 002BF440 00061400 */  sll        $v0, $a2, 16
    /* C0044 002BF444 00021403 */  sra        $v0, $v0, 16
    /* C0048 002BF448 080AFD45 */  .word 0x080AFD45
    /* C004C 002BF44C 02228821 */  addu      $s1, $s1, $v0
.Lauto_002BF450:
    /* C0050 002BF450 14820031 */  .word 0x14820031
    /* C0054 002BF454 00112400 */  sll       $a0, $s1, 16
    /* C0058 002BF458 00111400 */  sll        $v0, $s1, 16
    /* C005C 002BF45C 00021403 */  sra        $v0, $v0, 16
    /* C0060 002BF460 0056102A */  slt        $v0, $v0, $s6
    /* C0064 002BF464 1040000F */  .word 0x1040000F
    /* C0068 002BF468 00121C00 */  sll       $v1, $s2, 16
    /* C006C 002BF46C 8FAB0018 */  lw         $t3, 0x18($sp)
    /* C0070 002BF470 000B2403 */  sra        $a0, $t3, 16
.Lauto_002BF474:
    /* C0074 002BF474 02201021 */  addu       $v0, $s1, $zero
    /* C0078 002BF478 24430001 */  addiu      $v1, $v0, 0x1
    /* C007C 002BF47C 00608821 */  addu       $s1, $v1, $zero
    /* C0080 002BF480 00021400 */  sll        $v0, $v0, 16
    /* C0084 002BF484 000213C3 */  sra        $v0, $v0, 15
    /* C0088 002BF488 00491021 */  addu       $v0, $v0, $t1
    /* C008C 002BF48C 00031C00 */  sll        $v1, $v1, 16
    /* C0090 002BF490 00031C03 */  sra        $v1, $v1, 16
    /* C0094 002BF494 0064182A */  slt        $v1, $v1, $a0
    /* C0098 002BF498 1460FFF6 */  .word 0x1460FFF6
    /* C009C 002BF49C A4400000 */  sh        $zero, 0x0($v0)
    /* C00A0 002BF4A0 00121C00 */  sll        $v1, $s2, 16
.Lauto_002BF4A4:
    /* C00A4 002BF4A4 00031C03 */  sra        $v1, $v1, 16
    /* C00A8 002BF4A8 00031080 */  sll        $v0, $v1, 2
    /* C00AC 002BF4AC 00431021 */  addu       $v0, $v0, $v1
    /* C00B0 002BF4B0 00021080 */  sll        $v0, $v0, 2
    /* C00B4 002BF4B4 004A1021 */  addu       $v0, $v0, $t2
    /* C00B8 002BF4B8 8C430004 */  lw         $v1, 0x4($v0)
    /* C00BC 002BF4BC 8C420008 */  lw         $v0, 0x8($v0)
    /* C00C0 002BF4C0 080AFD3F */  .word 0x080AFD3F
    /* C00C4 002BF4C4 00621821 */  addu      $v1, $v1, $v0
.Lauto_002BF4C8:
    /* C00C8 002BF4C8 00041C00 */  sll        $v1, $a0, 16
    /* C00CC 002BF4CC 95020000 */  lhu        $v0, 0x0($t0)
    /* C00D0 002BF4D0 00031C03 */  sra        $v1, $v1, 16
    /* C00D4 002BF4D4 24420001 */  addiu      $v0, $v0, 0x1
    /* C00D8 002BF4D8 A5020000 */  sh         $v0, 0x0($t0)
    /* C00DC 002BF4DC 00031080 */  sll        $v0, $v1, 2
    /* C00E0 002BF4E0 00431021 */  addu       $v0, $v0, $v1
    /* C00E4 002BF4E4 00021080 */  sll        $v0, $v0, 2
    /* C00E8 002BF4E8 004A1021 */  addu       $v0, $v0, $t2
    /* C00EC 002BF4EC 8C430004 */  lw         $v1, 0x4($v0)
    /* C00F0 002BF4F0 8C420008 */  lw         $v0, 0x8($v0)
    /* C00F4 002BF4F4 00809021 */  addu       $s2, $a0, $zero
    /* C00F8 002BF4F8 00621821 */  addu       $v1, $v1, $v0
.Lauto_002BF4FC:
    /* C00FC 002BF4FC 02C3182A */  slt        $v1, $s6, $v1
    /* C0100 002BF500 1060FFF1 */  .word 0x1060FFF1
    /* C0104 002BF504 26440001 */  addiu     $a0, $s2, 0x1
    /* C0108 002BF508 8FAB0018 */  lw         $t3, 0x18($sp)
    /* C010C 002BF50C 080AFD7E */  .word 0x080AFD7E
    /* C0110 002BF510 000B1403 */  sra       $v0, $t3, 16
.Lauto_002BF514:
    /* C0114 002BF514 00112400 */  sll        $a0, $s1, 16
.Lauto_002BF518:
    /* C0118 002BF518 00121C00 */  sll        $v1, $s2, 16
    /* C011C 002BF51C 00031C03 */  sra        $v1, $v1, 16
    /* C0120 002BF520 00031080 */  sll        $v0, $v1, 2
    /* C0124 002BF524 00431021 */  addu       $v0, $v0, $v1
    /* C0128 002BF528 00021080 */  sll        $v0, $v0, 2
    /* C012C 002BF52C 004A1021 */  addu       $v0, $v0, $t2
    /* C0130 002BF530 8C430004 */  lw         $v1, 0x4($v0)
    /* C0134 002BF534 8C420008 */  lw         $v0, 0x8($v0)
    /* C0138 002BF538 00042403 */  sra        $a0, $a0, 16
    /* C013C 002BF53C 00621821 */  addu       $v1, $v1, $v0
    /* C0140 002BF540 0083202A */  slt        $a0, $a0, $v1
    /* C0144 002BF544 14800026 */  .word 0x14800026
    /* C0148 002BF548 00111400 */  sll       $v0, $s1, 16
    /* C014C 002BF54C 26440001 */  addiu      $a0, $s2, 0x1
    /* C0150 002BF550 00041C00 */  sll        $v1, $a0, 16
    /* C0154 002BF554 95020000 */  lhu        $v0, 0x0($t0)
    /* C0158 002BF558 00031C03 */  sra        $v1, $v1, 16
    /* C015C 002BF55C 24420001 */  addiu      $v0, $v0, 0x1
    /* C0160 002BF560 A5020000 */  sh         $v0, 0x0($t0)
    /* C0164 002BF564 00031080 */  sll        $v0, $v1, 2
    /* C0168 002BF568 00431021 */  addu       $v0, $v0, $v1
    /* C016C 002BF56C 00021080 */  sll        $v0, $v0, 2
    /* C0170 002BF570 004A1021 */  addu       $v0, $v0, $t2
    /* C0174 002BF574 8C530010 */  lw         $s3, 0x10($v0)
    /* C0178 002BF578 8E740020 */  lw         $s4, 0x20($s3)
    /* C017C 002BF57C 080AFD77 */  .word 0x080AFD77
    /* C0180 002BF580 00809021 */  addu      $s2, $a0, $zero
.Lauto_002BF584:
    /* C0184 002BF584 3C04800E */  lui        $a0, %hi(D_auto_800E5B3A)
    /* C0188 002BF588 24845B3A */  addiu      $a0, $a0, %lo(D_auto_800E5B3A)
    /* C018C 002BF58C 24050010 */  addiu      $a1, $zero, 0x10
    /* C0190 002BF590 24060001 */  addiu      $a2, $zero, 0x1
    /* C0194 002BF594 8FAB0068 */  lw         $t3, 0x68($sp)
    /* C0198 002BF598 00003821 */  addu       $a3, $zero, $zero
    /* C019C 002BF59C AFA80020 */  sw         $t0, 0x20($sp)
    /* C01A0 002BF5A0 AFA90024 */  sw         $t1, 0x24($sp)
    /* C01A4 002BF5A4 AFAA0028 */  sw         $t2, 0x28($sp)
    /* C01A8 002BF5A8 0C0AFC14 */  jal        adecReadBits
    /* C01AC 002BF5AC AFAB0010 */  sw        $t3, 0x10($sp)
    /* C01B0 002BF5B0 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C01B4 002BF5B4 8FA80020 */  lw         $t0, 0x20($sp)
    /* C01B8 002BF5B8 8FA90024 */  lw         $t1, 0x24($sp)
    /* C01BC 002BF5BC 8FAA0028 */  lw         $t2, 0x28($sp)
    /* C01C0 002BF5C0 14400003 */  .word 0x14400003
    /* C01C4 002BF5C4 00000000 */  nop
.Lauto_002BF5C8:
    /* C01C8 002BF5C8 080AFD7E */  .word 0x080AFD7E
    /* C01CC 002BF5CC 2402FFFF */  addiu     $v0, $zero, -0x1
.Lauto_002BF5D0:
    /* C01D0 002BF5D0 97C20000 */  lhu        $v0, 0x0($fp)
    /* C01D4 002BF5D4 24420010 */  addiu      $v0, $v0, 0x10
    /* C01D8 002BF5D8 A7C20000 */  sh         $v0, 0x0($fp)
.Lauto_002BF5DC:
    /* C01DC 002BF5DC 00111400 */  sll        $v0, $s1, 16
.Lauto_002BF5E0:
    /* C01E0 002BF5E0 00021403 */  sra        $v0, $v0, 16
    /* C01E4 002BF5E4 0056102A */  slt        $v0, $v0, $s6
    /* C01E8 002BF5E8 1440FF2B */  .word 0x1440FF2B
    /* C01EC 002BF5EC 00000000 */  nop
.Lauto_002BF5F0:
    /* C01F0 002BF5F0 00111400 */  sll        $v0, $s1, 16
    /* C01F4 002BF5F4 00021403 */  sra        $v0, $v0, 16
.Lauto_002BF5F8:
    /* C01F8 002BF5F8 8FBF0054 */  lw         $ra, 0x54($sp)
    /* C01FC 002BF5FC 8FBE0050 */  lw         $fp, 0x50($sp)
    /* C0200 002BF600 8FB7004C */  lw         $s7, 0x4C($sp)
    /* C0204 002BF604 8FB60048 */  lw         $s6, 0x48($sp)
    /* C0208 002BF608 8FB50044 */  lw         $s5, 0x44($sp)
    /* C020C 002BF60C 8FB40040 */  lw         $s4, 0x40($sp)
    /* C0210 002BF610 8FB3003C */  lw         $s3, 0x3C($sp)
    /* C0214 002BF614 8FB20038 */  lw         $s2, 0x38($sp)
    /* C0218 002BF618 8FB10034 */  lw         $s1, 0x34($sp)
    /* C021C 002BF61C 8FB00030 */  lw         $s0, 0x30($sp)
    /* C0220 002BF620 03E00008 */  jr         $ra
    /* C0224 002BF624 27BD0058 */  addiu     $sp, $sp, 0x58
.globl adecDecodeFrame
adecDecodeFrame:
    /* C0228 002BF628 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* C022C 002BF62C AFB10024 */  sw         $s1, 0x24($sp)
    /* C0230 002BF630 3C03800E */  lui        $v1, %hi(D_auto_800E5B3E)
    /* C0234 002BF634 24635B3E */  addiu      $v1, $v1, %lo(D_auto_800E5B3E)
    /* C0238 002BF638 AFBF0028 */  sw         $ra, 0x28($sp)
    /* C023C 002BF63C AFB00020 */  sw         $s0, 0x20($sp)
    /* C0240 002BF640 84620000 */  lh         $v0, 0x0($v1)
    /* C0244 002BF644 3C10800E */  lui        $s0, %hi(D_auto_800E5BE4)
    /* C0248 002BF648 26105BE4 */  addiu      $s0, $s0, %lo(D_auto_800E5BE4)
    /* C024C 002BF64C 14400026 */  .word 0x14400026
    /* C0250 002BF650 00808821 */  addu      $s1, $a0, $zero
    /* C0254 002BF654 26240018 */  addiu      $a0, $s1, 0x18
    /* C0258 002BF658 24050006 */  addiu      $a1, $zero, 0x6
    /* C025C 002BF65C 24060010 */  addiu      $a2, $zero, 0x10
    /* C0260 002BF660 00003821 */  addu       $a3, $zero, $zero
    /* C0264 002BF664 24020001 */  addiu      $v0, $zero, 0x1
    /* C0268 002BF668 A4620000 */  sh         $v0, 0x0($v1)
    /* C026C 002BF66C 0C0AFC14 */  jal        adecReadBits
    /* C0270 002BF670 AFB10010 */  sw        $s1, 0x10($sp)
    /* C0274 002BF674 00021400 */  sll        $v0, $v0, 16
    /* C0278 002BF678 18400048 */  .word 0x18400048
    /* C027C 002BF67C 00003821 */  addu      $a3, $zero, $zero
    /* C0280 002BF680 8E02000C */  lw         $v0, 0xC($s0)
    /* C0284 002BF684 3C058016 */  lui        $a1, %hi(D_auto_8015AE10)
    /* C0288 002BF688 24A5AE10 */  addiu      $a1, $a1, %lo(D_auto_8015AE10)
    /* C028C 002BF68C 24420060 */  addiu      $v0, $v0, 0x60
    /* C0290 002BF690 AE02000C */  sw         $v0, 0xC($s0)
.Lauto_002BF694:
    /* C0294 002BF694 00072400 */  sll        $a0, $a3, 16
    /* C0298 002BF698 24E30001 */  addiu      $v1, $a3, 0x1
    /* C029C 002BF69C 00603821 */  addu       $a3, $v1, $zero
    /* C02A0 002BF6A0 000423C3 */  sra        $a0, $a0, 15
    /* C02A4 002BF6A4 02241021 */  addu       $v0, $s1, $a0
    /* C02A8 002BF6A8 00852021 */  addu       $a0, $a0, $a1
    /* C02AC 002BF6AC 00031C00 */  sll        $v1, $v1, 16
    /* C02B0 002BF6B0 00031C03 */  sra        $v1, $v1, 16
    /* C02B4 002BF6B4 94420018 */  lhu        $v0, 0x18($v0)
    /* C02B8 002BF6B8 28630010 */  slti       $v1, $v1, 0x10
    /* C02BC 002BF6BC 1460FFF5 */  .word 0x1460FFF5
    /* C02C0 002BF6C0 A4820000 */  sh        $v0, 0x0($a0)
    /* C02C4 002BF6C4 8E020000 */  lw         $v0, 0x0($s0)
    /* C02C8 002BF6C8 5040002A */  .word 0x5040002A
    /* C02CC 002BF6CC AFB10010 */  sw        $s1, 0x10($sp)
    /* C02D0 002BF6D0 26100014 */  addiu      $s0, $s0, 0x14
.Lauto_002BF6D4:
    /* C02D4 002BF6D4 8E020000 */  lw         $v0, 0x0($s0)
    /* C02D8 002BF6D8 5440FFFE */  .word 0x5440FFFE
    /* C02DC 002BF6DC 26100014 */  addiu     $s0, $s0, 0x14
    /* C02E0 002BF6E0 080AFDDD */  .word 0x080AFDDD
    /* C02E4 002BF6E4 AFB10010 */  sw        $s1, 0x10($sp)
.Lauto_002BF6E8:
    /* C02E8 002BF6E8 AFB10010 */  sw         $s1, 0x10($sp)
    /* C02EC 002BF6EC 02002021 */  addu       $a0, $s0, $zero
    /* C02F0 002BF6F0 26250018 */  addiu      $a1, $s1, 0x18
    /* C02F4 002BF6F4 24060010 */  addiu      $a2, $zero, 0x10
    /* C02F8 002BF6F8 0C0AFC89 */  jal        adecHuffDecode
    /* C02FC 002BF6FC 27A70018 */  addiu     $a3, $sp, 0x18
    /* C0300 002BF700 00021400 */  sll        $v0, $v0, 16
    /* C0304 002BF704 00021C03 */  sra        $v1, $v0, 16
    /* C0308 002BF708 24020010 */  addiu      $v0, $zero, 0x10
    /* C030C 002BF70C 14620024 */  .word 0x14620024
    /* C0310 002BF710 2402FFFF */  addiu     $v0, $zero, -0x1
    /* C0314 002BF714 00003821 */  addu       $a3, $zero, $zero
    /* C0318 002BF718 87A30018 */  lh         $v1, 0x18($sp)
    /* C031C 002BF71C 3C088016 */  lui        $t0, %hi(D_auto_8015AE10)
    /* C0320 002BF720 2508AE10 */  addiu      $t0, $t0, %lo(D_auto_8015AE10)
    /* C0324 002BF724 00031080 */  sll        $v0, $v1, 2
    /* C0328 002BF728 00431021 */  addu       $v0, $v0, $v1
    /* C032C 002BF72C 00021080 */  sll        $v0, $v0, 2
    /* C0330 002BF730 00508021 */  addu       $s0, $v0, $s0
.Lauto_002BF734:
    /* C0334 002BF734 00072400 */  sll        $a0, $a3, 16
    /* C0338 002BF738 000423C3 */  sra        $a0, $a0, 15
    /* C033C 002BF73C 00882821 */  addu       $a1, $a0, $t0
    /* C0340 002BF740 02242021 */  addu       $a0, $s1, $a0
    /* C0344 002BF744 24E30001 */  addiu      $v1, $a3, 0x1
    /* C0348 002BF748 00603821 */  addu       $a3, $v1, $zero
    /* C034C 002BF74C 00031C00 */  sll        $v1, $v1, 16
    /* C0350 002BF750 00031C03 */  sra        $v1, $v1, 16
    /* C0354 002BF754 94A60000 */  lhu        $a2, 0x0($a1)
    /* C0358 002BF758 94820018 */  lhu        $v0, 0x18($a0)
    /* C035C 002BF75C 28630010 */  slti       $v1, $v1, 0x10
    /* C0360 002BF760 00461021 */  addu       $v0, $v0, $a2
    /* C0364 002BF764 A4820018 */  sh         $v0, 0x18($a0)
    /* C0368 002BF768 1460FFF2 */  .word 0x1460FFF2
    /* C036C 002BF76C A4A20000 */  sh        $v0, 0x0($a1)
    /* C0370 002BF770 AFB10010 */  sw         $s1, 0x10($sp)
.Lauto_002BF774:
    /* C0374 002BF774 02002021 */  addu       $a0, $s0, $zero
    /* C0378 002BF778 262500B8 */  addiu      $a1, $s1, 0xB8
    /* C037C 002BF77C 24060100 */  addiu      $a2, $zero, 0x100
    /* C0380 002BF780 0C0AFC89 */  jal        adecHuffDecode
    /* C0384 002BF784 27A70018 */  addiu     $a3, $sp, 0x18
    /* C0388 002BF788 00021400 */  sll        $v0, $v0, 16
    /* C038C 002BF78C 00021C03 */  sra        $v1, $v0, 16
    /* C0390 002BF790 24020100 */  addiu      $v0, $zero, 0x100
    /* C0394 002BF794 10620002 */  .word 0x10620002
    /* C0398 002BF798 24020001 */  addiu     $v0, $zero, 0x1
.Lauto_002BF79C:
    /* C039C 002BF79C 2402FFFF */  addiu      $v0, $zero, -0x1
.Lauto_002BF7A0:
    /* C03A0 002BF7A0 8FBF0028 */  lw         $ra, 0x28($sp)
    /* C03A4 002BF7A4 8FB10024 */  lw         $s1, 0x24($sp)
    /* C03A8 002BF7A8 8FB00020 */  lw         $s0, 0x20($sp)
    /* C03AC 002BF7AC 03E00008 */  jr         $ra
    /* C03B0 002BF7B0 27BD0030 */  addiu     $sp, $sp, 0x30
.globl mdctInitTwiddles
mdctInitTwiddles:
    /* C03B4 002BF7B4 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* C03B8 002BF7B8 F7B70040 */  sdc1       $fs1f, 0x40($sp)
    /* C03BC 002BF7BC 3C01800D */  lui        $at, %hi(D_auto_800C88B0)
    /* C03C0 002BF7C0 C43788B0 */  lwc1       $fs1f, %lo(D_auto_800C88B0)($at)
    /* C03C4 002BF7C4 F7B60038 */  sdc1       $fs1, 0x38($sp)
    /* C03C8 002BF7C8 3C01800D */  lui        $at, %hi(D_auto_800C88B0 + 0x4)
    /* C03CC 002BF7CC C43688B4 */  lwc1       $fs1, %lo(D_auto_800C88B0 + 0x4)($at)
    /* C03D0 002BF7D0 F7B50030 */  sdc1       $fs0f, 0x30($sp)
    /* C03D4 002BF7D4 3C01800D */  lui        $at, %hi(D_auto_800C88B8)
    /* C03D8 002BF7D8 C43588B8 */  lwc1       $fs0f, %lo(D_auto_800C88B8)($at)
    /* C03DC 002BF7DC AFB10014 */  sw         $s1, 0x14($sp)
    /* C03E0 002BF7E0 00008821 */  addu       $s1, $zero, $zero
    /* C03E4 002BF7E4 AFB40020 */  sw         $s4, 0x20($sp)
    /* C03E8 002BF7E8 3C148016 */  lui        $s4, %hi(D_auto_8015AE30)
    /* C03EC 002BF7EC 2694AE30 */  addiu      $s4, $s4, %lo(D_auto_8015AE30)
    /* C03F0 002BF7F0 AFB3001C */  sw         $s3, 0x1C($sp)
    /* C03F4 002BF7F4 3C138016 */  lui        $s3, %hi(D_auto_8015B030)
    /* C03F8 002BF7F8 2673B030 */  addiu      $s3, $s3, %lo(D_auto_8015B030)
    /* C03FC 002BF7FC AFB20018 */  sw         $s2, 0x18($sp)
    /* C0400 002BF800 3C128016 */  lui        $s2, %hi(D_auto_8015B630)
    /* C0404 002BF804 2652B630 */  addiu      $s2, $s2, %lo(D_auto_8015B630)
    /* C0408 002BF808 AFBF0024 */  sw         $ra, 0x24($sp)
    /* C040C 002BF80C AFB00010 */  sw         $s0, 0x10($sp)
    /* C0410 002BF810 F7B40028 */  sdc1       $fs0, 0x28($sp)
.Lauto_002BF814:
    /* C0414 002BF814 00118400 */  sll        $s0, $s1, 16
    /* C0418 002BF818 00108403 */  sra        $s0, $s0, 16
    /* C041C 002BF81C 44900000 */  mtc1       $s0, $fv0
    /* C0420 002BF820 46800020 */  cvt.s.w    $fv0, $fv0
    /* C0424 002BF824 46170002 */  mul.s      $fv0, $fv0, $fs1f
    /* C0428 002BF828 46160000 */  add.s      $fv0, $fv0, $fs1
    /* C042C 002BF82C 46150502 */  mul.s      $fs0, $fv0, $fs0f
    /* C0430 002BF830 0C0ADA00 */  jal        cosf
    /* C0434 002BF834 4600A306 */  mov.s     $fa0, $fs0
    /* C0438 002BF838 4600A306 */  mov.s      $fa0, $fs0
    /* C043C 002BF83C 00108080 */  sll        $s0, $s0, 2
    /* C0440 002BF840 02141021 */  addu       $v0, $s0, $s4
    /* C0444 002BF844 0C0ADCF4 */  jal        sinf
    /* C0448 002BF848 E4400000 */  swc1      $fv0, 0x0($v0)
    /* C044C 002BF84C 26220001 */  addiu      $v0, $s1, 0x1
    /* C0450 002BF850 00408821 */  addu       $s1, $v0, $zero
    /* C0454 002BF854 02131821 */  addu       $v1, $s0, $s3
    /* C0458 002BF858 02128021 */  addu       $s0, $s0, $s2
    /* C045C 002BF85C 00021400 */  sll        $v0, $v0, 16
    /* C0460 002BF860 00021403 */  sra        $v0, $v0, 16
    /* C0464 002BF864 28420080 */  slti       $v0, $v0, 0x80
    /* C0468 002BF868 E4600000 */  swc1       $fv0, 0x0($v1)
    /* C046C 002BF86C 1440FFE9 */  .word 0x1440FFE9
    /* C0470 002BF870 AE000000 */  sw        $zero, 0x0($s0)
    /* C0474 002BF874 00008821 */  addu       $s1, $zero, $zero
    /* C0478 002BF878 3C01800D */  lui        $at, %hi(D_auto_800C88B8 + 0x4)
    /* C047C 002BF87C C43588BC */  lwc1       $fs0f, %lo(D_auto_800C88B8 + 0x4)($at)
    /* C0480 002BF880 3C138016 */  lui        $s3, %hi(D_auto_8015B230)
    /* C0484 002BF884 2673B230 */  addiu      $s3, $s3, %lo(D_auto_8015B230)
    /* C0488 002BF888 3C128016 */  lui        $s2, %hi(D_auto_8015B430)
    /* C048C 002BF88C 2652B430 */  addiu      $s2, $s2, %lo(D_auto_8015B430)
.Lauto_002BF890:
    /* C0490 002BF890 00118400 */  sll        $s0, $s1, 16
    /* C0494 002BF894 00108403 */  sra        $s0, $s0, 16
    /* C0498 002BF898 44900000 */  mtc1       $s0, $fv0
    /* C049C 002BF89C 46800020 */  cvt.s.w    $fv0, $fv0
    /* C04A0 002BF8A0 46150502 */  mul.s      $fs0, $fv0, $fs0f
    /* C04A4 002BF8A4 0C0ADA00 */  jal        cosf
    /* C04A8 002BF8A8 4600A306 */  mov.s     $fa0, $fs0
    /* C04AC 002BF8AC 4600A306 */  mov.s      $fa0, $fs0
    /* C04B0 002BF8B0 0C0ADCF4 */  jal        sinf
    /* C04B4 002BF8B4 46000506 */  mov.s     $fs0, $fv0
    /* C04B8 002BF8B8 26220001 */  addiu      $v0, $s1, 0x1
    /* C04BC 002BF8BC 00408821 */  addu       $s1, $v0, $zero
    /* C04C0 002BF8C0 00108080 */  sll        $s0, $s0, 2
    /* C04C4 002BF8C4 02131821 */  addu       $v1, $s0, $s3
    /* C04C8 002BF8C8 02128021 */  addu       $s0, $s0, $s2
    /* C04CC 002BF8CC 4600A040 */  add.s      $fv0f, $fs0, $fv0
    /* C04D0 002BF8D0 00021400 */  sll        $v0, $v0, 16
    /* C04D4 002BF8D4 00021403 */  sra        $v0, $v0, 16
    /* C04D8 002BF8D8 46140001 */  sub.s      $fv0, $fv0, $fs0
    /* C04DC 002BF8DC 28420080 */  slti       $v0, $v0, 0x80
    /* C04E0 002BF8E0 E4610000 */  swc1       $fv0f, 0x0($v1)
    /* C04E4 002BF8E4 1440FFEA */  .word 0x1440FFEA
    /* C04E8 002BF8E8 E6000000 */  swc1      $fv0, 0x0($s0)
    /* C04EC 002BF8EC 8FBF0024 */  lw         $ra, 0x24($sp)
    /* C04F0 002BF8F0 8FB40020 */  lw         $s4, 0x20($sp)
    /* C04F4 002BF8F4 8FB3001C */  lw         $s3, 0x1C($sp)
    /* C04F8 002BF8F8 8FB20018 */  lw         $s2, 0x18($sp)
    /* C04FC 002BF8FC 8FB10014 */  lw         $s1, 0x14($sp)
    /* C0500 002BF900 8FB00010 */  lw         $s0, 0x10($sp)
    /* C0504 002BF904 D7B70040 */  ldc1       $fs1f, 0x40($sp)
    /* C0508 002BF908 D7B60038 */  ldc1       $fs1, 0x38($sp)
    /* C050C 002BF90C D7B50030 */  ldc1       $fs0f, 0x30($sp)
    /* C0510 002BF910 D7B40028 */  ldc1       $fs0, 0x28($sp)
    /* C0514 002BF914 03E00008 */  jr         $ra
    /* C0518 002BF918 27BD0048 */  addiu     $sp, $sp, 0x48
.globl mdctFftInit
mdctFftInit:
    /* C051C 002BF91C 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* C0520 002BF920 AFB3001C */  sw         $s3, 0x1C($sp)
    /* C0524 002BF924 00809821 */  addu       $s3, $a0, $zero
    /* C0528 002BF928 AFB10014 */  sw         $s1, 0x14($sp)
    /* C052C 002BF92C AFB20018 */  sw         $s2, 0x18($sp)
    /* C0530 002BF930 00139043 */  sra        $s2, $s3, 1
    /* C0534 002BF934 AFB40020 */  sw         $s4, 0x20($sp)
    /* C0538 002BF938 3C14800E */  lui        $s4, %hi(D_auto_800E59C0)
    /* C053C 002BF93C 269459C0 */  addiu      $s4, $s4, %lo(D_auto_800E59C0)
    /* C0540 002BF940 AFBF0024 */  sw         $ra, 0x24($sp)
    /* C0544 002BF944 AFB00010 */  sw         $s0, 0x10($sp)
    /* C0548 002BF948 F7B60038 */  sdc1       $fs1, 0x38($sp)
    /* C054C 002BF94C F7B50030 */  sdc1       $fs0f, 0x30($sp)
    /* C0550 002BF950 F7B40028 */  sdc1       $fs0, 0x28($sp)
    /* C0554 002BF954 1A400018 */  .word 0x1A400018
    /* C0558 002BF958 00008821 */  addu      $s1, $zero, $zero
    /* C055C 002BF95C 3C01800D */  lui        $at, %hi(D_auto_800C88C0)
    /* C0560 002BF960 C43688C0 */  lwc1       $fs1, %lo(D_auto_800C88C0)($at)
    /* C0564 002BF964 4493A800 */  mtc1       $s3, $fs0f
    /* C0568 002BF968 4680AD60 */  cvt.s.w    $fs0f, $fs0f
.Lauto_002BF96C:
    /* C056C 002BF96C 4491A000 */  mtc1       $s1, $fs0
    /* C0570 002BF970 4680A520 */  cvt.s.w    $fs0, $fs0
    /* C0574 002BF974 4616A502 */  mul.s      $fs0, $fs0, $fs1
    /* C0578 002BF978 4615A503 */  div.s      $fs0, $fs0, $fs0f
    /* C057C 002BF97C 0C0ADA00 */  jal        cosf
    /* C0580 002BF980 4600A306 */  mov.s     $fa0, $fs0
    /* C0584 002BF984 4600A306 */  mov.s      $fa0, $fs0
    /* C0588 002BF988 8E820000 */  lw         $v0, 0x0($s4)
    /* C058C 002BF98C 00118080 */  sll        $s0, $s1, 2
    /* C0590 002BF990 02021021 */  addu       $v0, $s0, $v0
    /* C0594 002BF994 0C0ADCF4 */  jal        sinf
    /* C0598 002BF998 E4400000 */  swc1      $fv0, 0x0($v0)
    /* C059C 002BF99C 26310001 */  addiu      $s1, $s1, 0x1
    /* C05A0 002BF9A0 8E820004 */  lw         $v0, 0x4($s4)
    /* C05A4 002BF9A4 46000007 */  neg.s      $fv0, $fv0
    /* C05A8 002BF9A8 02028021 */  addu       $s0, $s0, $v0
    /* C05AC 002BF9AC 0232102A */  slt        $v0, $s1, $s2
    /* C05B0 002BF9B0 1440FFEE */  .word 0x1440FFEE
    /* C05B4 002BF9B4 E6000000 */  swc1      $fv0, 0x0($s0)
.Lauto_002BF9B8:
    /* C05B8 002BF9B8 00003821 */  addu       $a3, $zero, $zero
    /* C05BC 002BF9BC 8E880008 */  lw         $t0, 0x8($s4)
    /* C05C0 002BF9C0 1A600007 */  .word 0x1A600007
    /* C05C4 002BF9C4 00134840 */  sll       $t1, $s3, 1
    /* C05C8 002BF9C8 01001821 */  addu       $v1, $t0, $zero
.Lauto_002BF9CC:
    /* C05CC 002BF9CC AC670000 */  sw         $a3, 0x0($v1)
    /* C05D0 002BF9D0 24E70001 */  addiu      $a3, $a3, 0x1
    /* C05D4 002BF9D4 00F3102A */  slt        $v0, $a3, $s3
    /* C05D8 002BF9D8 1440FFFC */  .word 0x1440FFFC
    /* C05DC 002BF9DC 24630004 */  addiu     $v1, $v1, 0x4
.Lauto_002BF9E0:
    /* C05E0 002BF9E0 24060001 */  addiu      $a2, $zero, 0x1
    /* C05E4 002BF9E4 19200022 */  .word 0x19200022
    /* C05E8 002BF9E8 00C03821 */  addu      $a3, $a2, $zero
    /* C05EC 002BF9EC 2A6A0002 */  slti       $t2, $s3, 0x2
.Lauto_002BF9F0:
    /* C05F0 002BF9F0 00E6102A */  slt        $v0, $a3, $a2
    /* C05F4 002BF9F4 10400010 */  .word 0x10400010
    /* C05F8 002BF9F8 24C4FFFF */  addiu     $a0, $a2, -0x1
    /* C05FC 002BF9FC 000417C2 */  srl        $v0, $a0, 31
    /* C0600 002BFA00 00822021 */  addu       $a0, $a0, $v0
    /* C0604 002BFA04 00042043 */  sra        $a0, $a0, 1
    /* C0608 002BFA08 00042080 */  sll        $a0, $a0, 2
    /* C060C 002BFA0C 00882021 */  addu       $a0, $a0, $t0
    /* C0610 002BFA10 24E2FFFF */  addiu      $v0, $a3, -0x1
    /* C0614 002BFA14 00021FC2 */  srl        $v1, $v0, 31
    /* C0618 002BFA18 00431021 */  addu       $v0, $v0, $v1
    /* C061C 002BFA1C 00021043 */  sra        $v0, $v0, 1
    /* C0620 002BFA20 00021080 */  sll        $v0, $v0, 2
    /* C0624 002BFA24 00481021 */  addu       $v0, $v0, $t0
    /* C0628 002BFA28 8C430000 */  lw         $v1, 0x0($v0)
    /* C062C 002BFA2C 8C850000 */  lw         $a1, 0x0($a0)
    /* C0630 002BFA30 AC830000 */  sw         $v1, 0x0($a0)
    /* C0634 002BFA34 AC450000 */  sw         $a1, 0x0($v0)
.Lauto_002BFA38:
    /* C0638 002BFA38 15400009 */  .word 0x15400009
    /* C063C 002BFA3C 02601821 */  addu      $v1, $s3, $zero
    /* C0640 002BFA40 0066102A */  slt        $v0, $v1, $a2
.Lauto_002BFA44:
    /* C0644 002BFA44 50400007 */  .word 0x50400007
    /* C0648 002BFA48 24E70002 */  addiu     $a3, $a3, 0x2
    /* C064C 002BFA4C 00C33023 */  subu       $a2, $a2, $v1
    /* C0650 002BFA50 00031843 */  sra        $v1, $v1, 1
    /* C0654 002BFA54 28620002 */  slti       $v0, $v1, 0x2
    /* C0658 002BFA58 1040FFFA */  .word 0x1040FFFA
    /* C065C 002BFA5C 0066102A */  slt       $v0, $v1, $a2
.Lauto_002BFA60:
    /* C0660 002BFA60 24E70002 */  addiu      $a3, $a3, 0x2
.Lauto_002BFA64:
    /* C0664 002BFA64 0127102A */  slt        $v0, $t1, $a3
    /* C0668 002BFA68 1040FFE1 */  .word 0x1040FFE1
    /* C066C 002BFA6C 00C33021 */  addu      $a2, $a2, $v1
.Lauto_002BFA70:
    /* C0670 002BFA70 02801021 */  addu       $v0, $s4, $zero
    /* C0674 002BFA74 AE93000C */  sw         $s3, 0xC($s4)
    /* C0678 002BFA78 8FBF0024 */  lw         $ra, 0x24($sp)
    /* C067C 002BFA7C 8FB40020 */  lw         $s4, 0x20($sp)
    /* C0680 002BFA80 8FB3001C */  lw         $s3, 0x1C($sp)
    /* C0684 002BFA84 8FB20018 */  lw         $s2, 0x18($sp)
    /* C0688 002BFA88 8FB10014 */  lw         $s1, 0x14($sp)
    /* C068C 002BFA8C 8FB00010 */  lw         $s0, 0x10($sp)
    /* C0690 002BFA90 D7B60038 */  ldc1       $fs1, 0x38($sp)
    /* C0694 002BFA94 D7B50030 */  ldc1       $fs0f, 0x30($sp)
    /* C0698 002BFA98 D7B40028 */  ldc1       $fs0, 0x28($sp)
    /* C069C 002BFA9C 03E00008 */  jr         $ra
    /* C06A0 002BFAA0 27BD0040 */  addiu     $sp, $sp, 0x40
.globl adecDequantize
adecDequantize:
    /* C06A4 002BFAA4 00806021 */  addu       $t4, $a0, $zero
    /* C06A8 002BFAA8 00A05821 */  addu       $t3, $a1, $zero
    /* C06AC 002BFAAC 00001821 */  addu       $v1, $zero, $zero
    /* C06B0 002BFAB0 256A00A0 */  addiu      $t2, $t3, 0xA0
    /* C06B4 002BFAB4 00603821 */  addu       $a3, $v1, $zero
    /* C06B8 002BFAB8 3C09800E */  lui        $t1, %hi(D_auto_800E5A18)
    /* C06BC 002BFABC 25295A18 */  addiu      $t1, $t1, %lo(D_auto_800E5A18)
    /* C06C0 002BFAC0 3C0D800E */  lui        $t5, %hi(D_auto_800E5A38)
    /* C06C4 002BFAC4 25AD5A38 */  addiu      $t5, $t5, %lo(D_auto_800E5A38)
    /* C06C8 002BFAC8 3C01800D */  lui        $at, %hi(D_auto_800C88C4)
    /* C06CC 002BFACC C42288C4 */  lwc1       $fv1, %lo(D_auto_800C88C4)($at)
    /* C06D0 002BFAD0 00603021 */  addu       $a2, $v1, $zero
.Lauto_002BFAD4:
    /* C06D4 002BFAD4 00074400 */  sll        $t0, $a3, 16
    /* C06D8 002BFAD8 00081BC3 */  sra        $v1, $t0, 15
    /* C06DC 002BFADC 00691821 */  addu       $v1, $v1, $t1
    /* C06E0 002BFAE0 94630000 */  lhu        $v1, 0x0($v1)
    /* C06E4 002BFAE4 080AFED1 */  .word 0x080AFED1
    /* C06E8 002BFAE8 00061400 */  sll       $v0, $a2, 16
.Lauto_002BFAEC:
    /* C06EC 002BFAEC 00031C03 */  sra        $v1, $v1, 16
    /* C06F0 002BFAF0 00032040 */  sll        $a0, $v1, 1
    /* C06F4 002BFAF4 00082BC3 */  sra        $a1, $t0, 15
    /* C06F8 002BFAF8 01651021 */  addu       $v0, $t3, $a1
    /* C06FC 002BFAFC 008A2021 */  addu       $a0, $a0, $t2
    /* C0700 002BFB00 00031880 */  sll        $v1, $v1, 2
    /* C0704 002BFB04 006C1821 */  addu       $v1, $v1, $t4
    /* C0708 002BFB08 84420000 */  lh         $v0, 0x0($v0)
    /* C070C 002BFB0C 84840000 */  lh         $a0, 0x0($a0)
    /* C0710 002BFB10 00021080 */  sll        $v0, $v0, 2
    /* C0714 002BFB14 004D1021 */  addu       $v0, $v0, $t5
    /* C0718 002BFB18 C4410000 */  lwc1       $fv0f, 0x0($v0)
    /* C071C 002BFB1C 44840000 */  mtc1       $a0, $fv0
    /* C0720 002BFB20 46800020 */  cvt.s.w    $fv0, $fv0
    /* C0724 002BFB24 46010003 */  div.s      $fv0, $fv0, $fv0f
    /* C0728 002BFB28 46020002 */  mul.s      $fv0, $fv0, $fv1
    /* C072C 002BFB2C 00A92821 */  addu       $a1, $a1, $t1
    /* C0730 002BFB30 24C20001 */  addiu      $v0, $a2, 0x1
    /* C0734 002BFB34 00403021 */  addu       $a2, $v0, $zero
    /* C0738 002BFB38 00021400 */  sll        $v0, $v0, 16
    /* C073C 002BFB3C E4600000 */  swc1       $fv0, 0x0($v1)
    /* C0740 002BFB40 94A30000 */  lhu        $v1, 0x0($a1)
.Lauto_002BFB44:
    /* C0744 002BFB44 00021403 */  sra        $v0, $v0, 16
    /* C0748 002BFB48 0043102A */  slt        $v0, $v0, $v1
    /* C074C 002BFB4C 1440FFE7 */  .word 0x1440FFE7
    /* C0750 002BFB50 00061C00 */  sll       $v1, $a2, 16
    /* C0754 002BFB54 00071400 */  sll        $v0, $a3, 16
    /* C0758 002BFB58 000213C3 */  sra        $v0, $v0, 15
    /* C075C 002BFB5C 00491021 */  addu       $v0, $v0, $t1
    /* C0760 002BFB60 94430000 */  lhu        $v1, 0x0($v0)
    /* C0764 002BFB64 24E20001 */  addiu      $v0, $a3, 0x1
    /* C0768 002BFB68 00403821 */  addu       $a3, $v0, $zero
    /* C076C 002BFB6C 00021400 */  sll        $v0, $v0, 16
    /* C0770 002BFB70 00021403 */  sra        $v0, $v0, 16
    /* C0774 002BFB74 28420010 */  slti       $v0, $v0, 0x10
    /* C0778 002BFB78 5440FFD6 */  .word 0x5440FFD6
    /* C077C 002BFB7C 00603021 */  addu      $a2, $v1, $zero
    /* C0780 002BFB80 3C02800E */  lui        $v0, %hi(D_auto_800E5A36)
    /* C0784 002BFB84 84425A36 */  lh         $v0, %lo(D_auto_800E5A36)($v0)
    /* C0788 002BFB88 00403821 */  addu       $a3, $v0, $zero
    /* C078C 002BFB8C 28420100 */  slti       $v0, $v0, 0x100
    /* C0790 002BFB90 1040000B */  .word 0x1040000B
    /* C0794 002BFB94 00071400 */  sll       $v0, $a3, 16
.Lauto_002BFB98:
    /* C0798 002BFB98 00021383 */  sra        $v0, $v0, 14
    /* C079C 002BFB9C 004C1021 */  addu       $v0, $v0, $t4
    /* C07A0 002BFBA0 AC400000 */  sw         $zero, 0x0($v0)
    /* C07A4 002BFBA4 24E20001 */  addiu      $v0, $a3, 0x1
    /* C07A8 002BFBA8 00403821 */  addu       $a3, $v0, $zero
    /* C07AC 002BFBAC 00021400 */  sll        $v0, $v0, 16
    /* C07B0 002BFBB0 00021403 */  sra        $v0, $v0, 16
    /* C07B4 002BFBB4 28420100 */  slti       $v0, $v0, 0x100
    /* C07B8 002BFBB8 1440FFF7 */  .word 0x1440FFF7
    /* C07BC 002BFBBC 00071400 */  sll       $v0, $a3, 16
.Lauto_002BFBC0:
    /* C07C0 002BFBC0 03E00008 */  jr         $ra
    /* C07C4 002BFBC4 24020001 */  addiu     $v0, $zero, 0x1
.globl mdctFft
mdctFft:
    /* C07C8 002BFBC8 8FB80010 */  lw         $t8, 0x10($sp)
    /* C07CC 002BFBCC 18A0001F */  .word 0x18A0001F
    /* C07D0 002BFBD0 00005021 */  addu      $t2, $zero, $zero
    /* C07D4 002BFBD4 8FA90014 */  lw         $t1, 0x14($sp)
    /* C07D8 002BFBD8 00804021 */  addu       $t0, $a0, $zero
.Lauto_002BFBDC:
    /* C07DC 002BFBDC 8D230000 */  lw         $v1, 0x0($t1)
    /* C07E0 002BFBE0 0143102A */  slt        $v0, $t2, $v1
    /* C07E4 002BFBE4 50400015 */  .word 0x50400015
    /* C07E8 002BFBE8 25290004 */  addiu     $t1, $t1, 0x4
    /* C07EC 002BFBEC 000310C0 */  sll        $v0, $v1, 3
    /* C07F0 002BFBF0 00441021 */  addu       $v0, $v0, $a0
    /* C07F4 002BFBF4 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C07F8 002BFBF8 C5030000 */  lwc1       $fv1f, 0x0($t0)
    /* C07FC 002BFBFC E5000000 */  swc1       $fv0, 0x0($t0)
    /* C0800 002BFC00 8D220000 */  lw         $v0, 0x0($t1)
    /* C0804 002BFC04 000210C0 */  sll        $v0, $v0, 3
    /* C0808 002BFC08 00441021 */  addu       $v0, $v0, $a0
    /* C080C 002BFC0C E4430000 */  swc1       $fv1f, 0x0($v0)
    /* C0810 002BFC10 8D220000 */  lw         $v0, 0x0($t1)
    /* C0814 002BFC14 C5030004 */  lwc1       $fv1f, 0x4($t0)
    /* C0818 002BFC18 000210C0 */  sll        $v0, $v0, 3
    /* C081C 002BFC1C 00441021 */  addu       $v0, $v0, $a0
    /* C0820 002BFC20 C4400004 */  lwc1       $fv0, 0x4($v0)
    /* C0824 002BFC24 E5000004 */  swc1       $fv0, 0x4($t0)
    /* C0828 002BFC28 8D220000 */  lw         $v0, 0x0($t1)
    /* C082C 002BFC2C 000210C0 */  sll        $v0, $v0, 3
    /* C0830 002BFC30 00441021 */  addu       $v0, $v0, $a0
    /* C0834 002BFC34 E4430004 */  swc1       $fv1f, 0x4($v0)
    /* C0838 002BFC38 25290004 */  addiu      $t1, $t1, 0x4
.Lauto_002BFC3C:
    /* C083C 002BFC3C 254A0001 */  addiu      $t2, $t2, 0x1
    /* C0840 002BFC40 0145102A */  slt        $v0, $t2, $a1
    /* C0844 002BFC44 1440FFE5 */  .word 0x1440FFE5
    /* C0848 002BFC48 25080008 */  addiu     $t0, $t0, 0x8
.Lauto_002BFC4C:
    /* C084C 002BFC4C 240E0002 */  addiu      $t6, $zero, 0x2
    /* C0850 002BFC50 240F0001 */  addiu      $t7, $zero, 0x1
    /* C0854 002BFC54 01E56807 */  srav       $t5, $a1, $t7
    /* C0858 002BFC58 19A0003A */  .word 0x19A0003A
    /* C085C 002BFC5C 01E52804 */  sllv      $a1, $a1, $t7
.Lauto_002BFC60:
    /* C0860 002BFC60 19E00034 */  .word 0x19E00034
    /* C0864 002BFC64 00004821 */  addu      $t1, $zero, $zero
    /* C0868 002BFC68 44863000 */  mtc1       $a2, $ft1
    /* C086C 002BFC6C 468031A0 */  cvt.s.w    $ft1, $ft1
    /* C0870 002BFC70 000E6040 */  sll        $t4, $t6, 1
    /* C0874 002BFC74 03005821 */  addu       $t3, $t8, $zero
    /* C0878 002BFC78 00E05021 */  addu       $t2, $a3, $zero
    /* C087C 002BFC7C 00094040 */  sll        $t0, $t1, 1
.Lauto_002BFC80:
    /* C0880 002BFC80 0105102A */  slt        $v0, $t0, $a1
    /* C0884 002BFC84 C5600000 */  lwc1       $fv0, 0x0($t3)
    /* C0888 002BFC88 C5440000 */  lwc1       $ft0, 0x0($t2)
    /* C088C 002BFC8C 46003142 */  mul.s      $ft0f, $ft1, $fv0
    /* C0890 002BFC90 10400021 */  .word 0x10400021
    /* C0894 002BFC94 000910C0 */  sll       $v0, $t1, 3
    /* C0898 002BFC98 00441821 */  addu       $v1, $v0, $a0
    /* C089C 002BFC9C 010E1021 */  addu       $v0, $t0, $t6
.Lauto_002BFCA0:
    /* C08A0 002BFCA0 00021080 */  sll        $v0, $v0, 2
    /* C08A4 002BFCA4 00441021 */  addu       $v0, $v0, $a0
    /* C08A8 002BFCA8 C4410000 */  lwc1       $fv0f, 0x0($v0)
    /* C08AC 002BFCAC 460120C2 */  mul.s      $fv1f, $ft0, $fv0f
    /* C08B0 002BFCB0 C4420004 */  lwc1       $fv1, 0x4($v0)
    /* C08B4 002BFCB4 46022802 */  mul.s      $fv0, $ft0f, $fv1
    /* C08B8 002BFCB8 00000000 */  nop
    /* C08BC 002BFCBC 46022082 */  mul.s      $fv1, $ft0, $fv1
    /* C08C0 002BFCC0 00000000 */  nop
    /* C08C4 002BFCC4 46012842 */  mul.s      $fv0f, $ft0f, $fv0f
    /* C08C8 002BFCC8 460018C1 */  sub.s      $fv1f, $fv1f, $fv0
    /* C08CC 002BFCCC C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C08D0 002BFCD0 46030001 */  sub.s      $fv0, $fv0, $fv1f
    /* C08D4 002BFCD4 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C08D8 002BFCD8 E4400000 */  swc1       $fv0, 0x0($v0)
    /* C08DC 002BFCDC C4600004 */  lwc1       $fv0, 0x4($v1)
    /* C08E0 002BFCE0 46020001 */  sub.s      $fv0, $fv0, $fv1
    /* C08E4 002BFCE4 E4400004 */  swc1       $fv0, 0x4($v0)
    /* C08E8 002BFCE8 C4610000 */  lwc1       $fv0f, 0x0($v1)
    /* C08EC 002BFCEC 46030840 */  add.s      $fv0f, $fv0f, $fv1f
    /* C08F0 002BFCF0 C4600004 */  lwc1       $fv0, 0x4($v1)
    /* C08F4 002BFCF4 010C4021 */  addu       $t0, $t0, $t4
    /* C08F8 002BFCF8 46020000 */  add.s      $fv0, $fv0, $fv1
    /* C08FC 002BFCFC 000C1080 */  sll        $v0, $t4, 2
    /* C0900 002BFD00 E4610000 */  swc1       $fv0f, 0x0($v1)
    /* C0904 002BFD04 E4600004 */  swc1       $fv0, 0x4($v1)
    /* C0908 002BFD08 00621821 */  addu       $v1, $v1, $v0
    /* C090C 002BFD0C 0105102A */  slt        $v0, $t0, $a1
    /* C0910 002BFD10 1440FFE3 */  .word 0x1440FFE3
    /* C0914 002BFD14 010E1021 */  addu      $v0, $t0, $t6
.Lauto_002BFD18:
    /* C0918 002BFD18 000D1080 */  sll        $v0, $t5, 2
    /* C091C 002BFD1C 01625821 */  addu       $t3, $t3, $v0
    /* C0920 002BFD20 01425021 */  addu       $t2, $t2, $v0
    /* C0924 002BFD24 25290001 */  addiu      $t1, $t1, 0x1
    /* C0928 002BFD28 012F102A */  slt        $v0, $t1, $t7
    /* C092C 002BFD2C 5440FFD4 */  .word 0x5440FFD4
    /* C0930 002BFD30 00094040 */  sll       $t0, $t1, 1
.Lauto_002BFD34:
    /* C0934 002BFD34 000D6843 */  sra        $t5, $t5, 1
    /* C0938 002BFD38 000F7840 */  sll        $t7, $t7, 1
    /* C093C 002BFD3C 1DA0FFC8 */  .word 0x1DA0FFC8
    /* C0940 002BFD40 000E7040 */  sll       $t6, $t6, 1
.Lauto_002BFD44:
    /* C0944 002BFD44 03E00008 */  jr         $ra
    /* C0948 002BFD48 00000000 */  nop
.globl adecImdctFrame
adecImdctFrame:
    /* C094C 002BFD4C 27BDF7D0 */  addiu      $sp, $sp, -0x830
    /* C0950 002BFD50 AFB20820 */  sw         $s2, 0x820($sp)
    /* C0954 002BFD54 00809021 */  addu       $s2, $a0, $zero
    /* C0958 002BFD58 AFB00818 */  sw         $s0, 0x818($sp)
    /* C095C 002BFD5C 3C10800E */  lui        $s0, %hi(D_auto_800E5B40)
    /* C0960 002BFD60 26105B40 */  addiu      $s0, $s0, %lo(D_auto_800E5B40)
    /* C0964 002BFD64 AFBF0824 */  sw         $ra, 0x824($sp)
    /* C0968 002BFD68 AFB1081C */  sw         $s1, 0x81C($sp)
    /* C096C 002BFD6C F7B40828 */  sdc1       $fs0, 0x828($sp)
    /* C0970 002BFD70 86020000 */  lh         $v0, 0x0($s0)
    /* C0974 002BFD74 14400009 */  .word 0x14400009
    /* C0978 002BFD78 00A08821 */  addu      $s1, $a1, $zero
    /* C097C 002BFD7C 0C0AFDED */  jal        mdctInitTwiddles
    /* C0980 002BFD80 00000000 */  nop
    /* C0984 002BFD84 0C0AFE47 */  jal        mdctFftInit
    /* C0988 002BFD88 24040080 */  addiu     $a0, $zero, 0x80
    /* C098C 002BFD8C 3C018016 */  lui        $at, %hi(D_auto_8015B830)
    /* C0990 002BFD90 AC22B830 */  sw         $v0, %lo(D_auto_8015B830)($at)
    /* C0994 002BFD94 24020001 */  addiu      $v0, $zero, 0x1
    /* C0998 002BFD98 A6020000 */  sh         $v0, 0x0($s0)
.Lauto_002BFD9C:
    /* C099C 002BFD9C 3C01800D */  lui        $at, %hi(D_auto_800C88C8)
    /* C09A0 002BFDA0 C43488C8 */  lwc1       $fs0, %lo(D_auto_800C88C8)($at)
    /* C09A4 002BFDA4 27B00418 */  addiu      $s0, $sp, 0x418
    /* C09A8 002BFDA8 02002021 */  addu       $a0, $s0, $zero
    /* C09AC 002BFDAC 0C0AFEA9 */  jal        adecDequantize
    /* C09B0 002BFDB0 26250018 */  addiu     $a1, $s1, 0x18
    /* C09B4 002BFDB4 27A60018 */  addiu      $a2, $sp, 0x18
    /* C09B8 002BFDB8 00002821 */  addu       $a1, $zero, $zero
    /* C09BC 002BFDBC 240700FF */  addiu      $a3, $zero, 0xFF
.Lauto_002BFDC0:
    /* C09C0 002BFDC0 00051C00 */  sll        $v1, $a1, 16
    /* C09C4 002BFDC4 00031C03 */  sra        $v1, $v1, 16
    /* C09C8 002BFDC8 000320C0 */  sll        $a0, $v1, 3
    /* C09CC 002BFDCC 00901021 */  addu       $v0, $a0, $s0
    /* C09D0 002BFDD0 00862021 */  addu       $a0, $a0, $a2
    /* C09D4 002BFDD4 00031840 */  sll        $v1, $v1, 1
    /* C09D8 002BFDD8 00E31823 */  subu       $v1, $a3, $v1
    /* C09DC 002BFDDC 00031880 */  sll        $v1, $v1, 2
    /* C09E0 002BFDE0 00701821 */  addu       $v1, $v1, $s0
    /* C09E4 002BFDE4 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C09E8 002BFDE8 24A20001 */  addiu      $v0, $a1, 0x1
    /* C09EC 002BFDEC 00402821 */  addu       $a1, $v0, $zero
    /* C09F0 002BFDF0 00021400 */  sll        $v0, $v0, 16
    /* C09F4 002BFDF4 00021403 */  sra        $v0, $v0, 16
    /* C09F8 002BFDF8 E4800000 */  swc1       $fv0, 0x0($a0)
    /* C09FC 002BFDFC C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C0A00 002BFE00 28420080 */  slti       $v0, $v0, 0x80
    /* C0A04 002BFE04 1440FFEE */  .word 0x1440FFEE
    /* C0A08 002BFE08 E4800004 */  swc1      $fv0, 0x4($a0)
    /* C0A0C 002BFE0C 27A60018 */  addiu      $a2, $sp, 0x18
    /* C0A10 002BFE10 3C088016 */  lui        $t0, %hi(D_auto_8015AE30)
    /* C0A14 002BFE14 2508AE30 */  addiu      $t0, $t0, %lo(D_auto_8015AE30)
    /* C0A18 002BFE18 3C078016 */  lui        $a3, %hi(D_auto_8015B030)
    /* C0A1C 002BFE1C 24E7B030 */  addiu      $a3, $a3, %lo(D_auto_8015B030)
    /* C0A20 002BFE20 00002821 */  addu       $a1, $zero, $zero
.Lauto_002BFE24:
    /* C0A24 002BFE24 00051400 */  sll        $v0, $a1, 16
    /* C0A28 002BFE28 00021403 */  sra        $v0, $v0, 16
    /* C0A2C 002BFE2C 000220C0 */  sll        $a0, $v0, 3
    /* C0A30 002BFE30 00862021 */  addu       $a0, $a0, $a2
    /* C0A34 002BFE34 00021080 */  sll        $v0, $v0, 2
    /* C0A38 002BFE38 00481821 */  addu       $v1, $v0, $t0
    /* C0A3C 002BFE3C C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C0A40 002BFE40 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C0A44 002BFE44 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C0A48 002BFE48 00471021 */  addu       $v0, $v0, $a3
    /* C0A4C 002BFE4C C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C0A50 002BFE50 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0A54 002BFE54 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C0A58 002BFE58 00000000 */  nop
    /* C0A5C 002BFE5C 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C0A60 002BFE60 00000000 */  nop
    /* C0A64 002BFE64 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C0A68 002BFE68 24A20001 */  addiu      $v0, $a1, 0x1
    /* C0A6C 002BFE6C 00402821 */  addu       $a1, $v0, $zero
    /* C0A70 002BFE70 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C0A74 002BFE74 00021400 */  sll        $v0, $v0, 16
    /* C0A78 002BFE78 00021403 */  sra        $v0, $v0, 16
    /* C0A7C 002BFE7C 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C0A80 002BFE80 28420080 */  slti       $v0, $v0, 0x80
    /* C0A84 002BFE84 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C0A88 002BFE88 1440FFE6 */  .word 0x1440FFE6
    /* C0A8C 002BFE8C E4820004 */  swc1      $fv1, 0x4($a0)
    /* C0A90 002BFE90 3C038016 */  lui        $v1, %hi(D_auto_8015B830)
    /* C0A94 002BFE94 8C63B830 */  lw         $v1, %lo(D_auto_8015B830)($v1)
    /* C0A98 002BFE98 8C620004 */  lw         $v0, 0x4($v1)
    /* C0A9C 002BFE9C 27B00018 */  addiu      $s0, $sp, 0x18
    /* C0AA0 002BFEA0 AFA20010 */  sw         $v0, 0x10($sp)
    /* C0AA4 002BFEA4 8C620008 */  lw         $v0, 0x8($v1)
    /* C0AA8 002BFEA8 02002021 */  addu       $a0, $s0, $zero
    /* C0AAC 002BFEAC AFA20014 */  sw         $v0, 0x14($sp)
    /* C0AB0 002BFEB0 8C65000C */  lw         $a1, 0xC($v1)
    /* C0AB4 002BFEB4 8C670000 */  lw         $a3, 0x0($v1)
    /* C0AB8 002BFEB8 0C0AFEF2 */  jal        mdctFft
    /* C0ABC 002BFEBC 2406FFFF */  addiu     $a2, $zero, -0x1
    /* C0AC0 002BFEC0 3C078016 */  lui        $a3, %hi(D_auto_8015B230)
    /* C0AC4 002BFEC4 24E7B230 */  addiu      $a3, $a3, %lo(D_auto_8015B230)
    /* C0AC8 002BFEC8 3C068016 */  lui        $a2, %hi(D_auto_8015B430)
    /* C0ACC 002BFECC 24C6B430 */  addiu      $a2, $a2, %lo(D_auto_8015B430)
    /* C0AD0 002BFED0 00002821 */  addu       $a1, $zero, $zero
.Lauto_002BFED4:
    /* C0AD4 002BFED4 00051400 */  sll        $v0, $a1, 16
    /* C0AD8 002BFED8 00021403 */  sra        $v0, $v0, 16
    /* C0ADC 002BFEDC 000220C0 */  sll        $a0, $v0, 3
    /* C0AE0 002BFEE0 00902021 */  addu       $a0, $a0, $s0
    /* C0AE4 002BFEE4 00021080 */  sll        $v0, $v0, 2
    /* C0AE8 002BFEE8 00471821 */  addu       $v1, $v0, $a3
    /* C0AEC 002BFEEC C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C0AF0 002BFEF0 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C0AF4 002BFEF4 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C0AF8 002BFEF8 00461021 */  addu       $v0, $v0, $a2
    /* C0AFC 002BFEFC C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C0B00 002BFF00 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0B04 002BFF04 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C0B08 002BFF08 00000000 */  nop
    /* C0B0C 002BFF0C 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C0B10 002BFF10 00000000 */  nop
    /* C0B14 002BFF14 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C0B18 002BFF18 24A20001 */  addiu      $v0, $a1, 0x1
    /* C0B1C 002BFF1C 00402821 */  addu       $a1, $v0, $zero
    /* C0B20 002BFF20 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C0B24 002BFF24 00021400 */  sll        $v0, $v0, 16
    /* C0B28 002BFF28 00021403 */  sra        $v0, $v0, 16
    /* C0B2C 002BFF2C 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C0B30 002BFF30 28420080 */  slti       $v0, $v0, 0x80
    /* C0B34 002BFF34 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C0B38 002BFF38 1440FFE6 */  .word 0x1440FFE6
    /* C0B3C 002BFF3C E4820004 */  swc1      $fv1, 0x4($a0)
    /* C0B40 002BFF40 00003821 */  addu       $a3, $zero, $zero
    /* C0B44 002BFF44 3C0C8016 */  lui        $t4, %hi(D_auto_8015B630)
    /* C0B48 002BFF48 258CB630 */  addiu      $t4, $t4, %lo(D_auto_8015B630)
    /* C0B4C 002BFF4C 3C0B8016 */  lui        $t3, %hi(D_auto_8015AE30)
    /* C0B50 002BFF50 256BAE30 */  addiu      $t3, $t3, %lo(D_auto_8015AE30)
    /* C0B54 002BFF54 27A80018 */  addiu      $t0, $sp, 0x18
    /* C0B58 002BFF58 3C0A8016 */  lui        $t2, %hi(D_auto_8015B030)
    /* C0B5C 002BFF5C 254AB030 */  addiu      $t2, $t2, %lo(D_auto_8015B030)
    /* C0B60 002BFF60 240900FF */  addiu      $t1, $zero, 0xFF
    /* C0B64 002BFF64 44804800 */  mtc1       $zero, $ft2f
    /* C0B68 002BFF68 3C01800D */  lui        $at, %hi(D_auto_800C88CC)
    /* C0B6C 002BFF6C C42888CC */  lwc1       $ft2, %lo(D_auto_800C88CC)($at)
    /* C0B70 002BFF70 3C01800D */  lui        $at, %hi(D_auto_800C88D0)
    /* C0B74 002BFF74 C42788D0 */  lwc1       $ft1f, %lo(D_auto_800C88D0)($at)
    /* C0B78 002BFF78 3C01800D */  lui        $at, %hi(D_auto_800C88D0 + 0x4)
    /* C0B7C 002BFF7C C42688D4 */  lwc1       $ft1, %lo(D_auto_800C88D0 + 0x4)($at)
    /* C0B80 002BFF80 00071C00 */  sll        $v1, $a3, 16
.Lauto_002BFF84:
    /* C0B84 002BFF84 00031C03 */  sra        $v1, $v1, 16
    /* C0B88 002BFF88 00032080 */  sll        $a0, $v1, 2
    /* C0B8C 002BFF8C 008C3021 */  addu       $a2, $a0, $t4
    /* C0B90 002BFF90 008B2821 */  addu       $a1, $a0, $t3
    /* C0B94 002BFF94 000310C0 */  sll        $v0, $v1, 3
    /* C0B98 002BFF98 34420004 */  ori        $v0, $v0, 0x4
    /* C0B9C 002BFF9C C4C40000 */  lwc1       $ft0, 0x0($a2)
    /* C0BA0 002BFFA0 C4A50000 */  lwc1       $ft0f, 0x0($a1)
    /* C0BA4 002BFFA4 01021021 */  addu       $v0, $t0, $v0
    /* C0BA8 002BFFA8 46052042 */  mul.s      $fv0f, $ft0, $ft0f
    /* C0BAC 002BFFAC 008A2021 */  addu       $a0, $a0, $t2
    /* C0BB0 002BFFB0 C4430000 */  lwc1       $fv1f, 0x0($v0)
    /* C0BB4 002BFFB4 C4800000 */  lwc1       $fv0, 0x0($a0)
    /* C0BB8 002BFFB8 46001882 */  mul.s      $fv1, $fv1f, $fv0
    /* C0BBC 002BFFBC 00000000 */  nop
    /* C0BC0 002BFFC0 46002102 */  mul.s      $ft0, $ft0, $fv0
    /* C0BC4 002BFFC4 00000000 */  nop
    /* C0BC8 002BFFC8 460518C2 */  mul.s      $fv1f, $fv1f, $ft0f
    /* C0BCC 002BFFCC 46020840 */  add.s      $fv0f, $fv0f, $fv1
    /* C0BD0 002BFFD0 4601A042 */  mul.s      $fv0f, $fs0, $fv0f
    /* C0BD4 002BFFD4 000318C0 */  sll        $v1, $v1, 3
    /* C0BD8 002BFFD8 01031821 */  addu       $v1, $t0, $v1
    /* C0BDC 002BFFDC C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C0BE0 002BFFE0 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C0BE4 002BFFE4 E4C00000 */  swc1       $fv0, 0x0($a2)
    /* C0BE8 002BFFE8 4601483E */  c.le.s     $ft2f, $fv0f
    /* C0BEC 002BFFEC 00000000 */  nop
    /* C0BF0 002BFFF0 45000008 */  .word 0x45000008
    /* C0BF4 002BFFF4 46000806 */  mov.s     $fv0, $fv0f
    /* C0BF8 002BFFF8 46080800 */  add.s      $fv0, $fv0f, $ft2
    /* C0BFC 002BFFFC 4600383C */  c.lt.s     $ft1f, $fv0
    /* C0C00 002C0000 00000000 */  nop
    /* C0C04 002C0004 45030008 */  .word 0x45030008
    /* C0C08 002C0008 46003806 */  mov.s     $fv0, $ft1f
    /* C0C0C 002C000C 080B000A */  .word 0x080B000A
    /* C0C10 002C0010 00000000 */  nop
.Lauto_002C0014:
    /* C0C14 002C0014 46080001 */  sub.s      $fv0, $fv0, $ft2
    /* C0C18 002C0018 4606003C */  c.lt.s     $fv0, $ft1
    /* C0C1C 002C001C 00000000 */  nop
    /* C0C20 002C0020 45030001 */  .word 0x45030001
    /* C0C24 002C0024 46003006 */  mov.s     $fv0, $ft1
.Lauto_002C0028:
    /* C0C28 002C0028 4600028D */  trunc.w.s  $ft3, $fv0
    /* C0C2C 002C002C 44035000 */  mfc1       $v1, $ft3
    /* C0C30 002C0030 4604A102 */  mul.s      $ft0, $fs0, $ft0
    /* C0C34 002C0034 00071400 */  sll        $v0, $a3, 16
    /* C0C38 002C0038 00021383 */  sra        $v0, $v0, 14
    /* C0C3C 002C003C 00521021 */  addu       $v0, $v0, $s2
    /* C0C40 002C0040 A4430000 */  sh         $v1, 0x0($v0)
    /* C0C44 002C0044 4604483E */  c.le.s     $ft2f, $ft0
    /* C0C48 002C0048 00000000 */  nop
    /* C0C4C 002C004C 45000008 */  .word 0x45000008
    /* C0C50 002C0050 46002006 */  mov.s     $fv0, $ft0
    /* C0C54 002C0054 46082100 */  add.s      $ft0, $ft0, $ft2
    /* C0C58 002C0058 4604383C */  c.lt.s     $ft1f, $ft0
    /* C0C5C 002C005C 00000000 */  nop
    /* C0C60 002C0060 45030008 */  .word 0x45030008
    /* C0C64 002C0064 46003906 */  mov.s     $ft0, $ft1f
    /* C0C68 002C0068 080B0021 */  .word 0x080B0021
    /* C0C6C 002C006C 00000000 */  nop
.Lauto_002C0070:
    /* C0C70 002C0070 46080101 */  sub.s      $ft0, $fv0, $ft2
    /* C0C74 002C0074 4606203C */  c.lt.s     $ft0, $ft1
    /* C0C78 002C0078 00000000 */  nop
    /* C0C7C 002C007C 45030001 */  .word 0x45030001
    /* C0C80 002C0080 46003106 */  mov.s     $ft0, $ft1
.Lauto_002C0084:
    /* C0C84 002C0084 4600228D */  trunc.w.s  $ft3, $ft0
    /* C0C88 002C0088 44035000 */  mfc1       $v1, $ft3
    /* C0C8C 002C008C 00071400 */  sll        $v0, $a3, 16
    /* C0C90 002C0090 000213C3 */  sra        $v0, $v0, 15
    /* C0C94 002C0094 01221023 */  subu       $v0, $t1, $v0
    /* C0C98 002C0098 00021040 */  sll        $v0, $v0, 1
    /* C0C9C 002C009C 00521021 */  addu       $v0, $v0, $s2
    /* C0CA0 002C00A0 A4430000 */  sh         $v1, 0x0($v0)
    /* C0CA4 002C00A4 24E20001 */  addiu      $v0, $a3, 0x1
    /* C0CA8 002C00A8 00403821 */  addu       $a3, $v0, $zero
    /* C0CAC 002C00AC 00021400 */  sll        $v0, $v0, 16
    /* C0CB0 002C00B0 00021403 */  sra        $v0, $v0, 16
    /* C0CB4 002C00B4 28420080 */  slti       $v0, $v0, 0x80
    /* C0CB8 002C00B8 5440FFB2 */  .word 0x5440FFB2
    /* C0CBC 002C00BC 00071C00 */  sll       $v1, $a3, 16
    /* C0CC0 002C00C0 8FBF0824 */  lw         $ra, 0x824($sp)
    /* C0CC4 002C00C4 8FB20820 */  lw         $s2, 0x820($sp)
    /* C0CC8 002C00C8 8FB1081C */  lw         $s1, 0x81C($sp)
    /* C0CCC 002C00CC 8FB00818 */  lw         $s0, 0x818($sp)
    /* C0CD0 002C00D0 D7B40828 */  ldc1       $fs0, 0x828($sp)
    /* C0CD4 002C00D4 03E00008 */  jr         $ra
    /* C0CD8 002C00D8 27BD0830 */  addiu     $sp, $sp, 0x830
.globl adecDecodeFrameOk
adecDecodeFrameOk:
    /* C0CDC 002C00DC 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C0CE0 002C00E0 AFBF0010 */  sw         $ra, 0x10($sp)
    /* C0CE4 002C00E4 0C0AFD8A */  jal        adecDecodeFrame
    /* C0CE8 002C00E8 00000000 */  nop
    /* C0CEC 002C00EC 00021400 */  sll        $v0, $v0, 16
    /* C0CF0 002C00F0 00021403 */  sra        $v0, $v0, 16
    /* C0CF4 002C00F4 00021027 */  nor        $v0, $zero, $v0
    /* C0CF8 002C00F8 8FBF0010 */  lw         $ra, 0x10($sp)
    /* C0CFC 002C00FC 000217C2 */  srl        $v0, $v0, 31
    /* C0D00 002C0100 03E00008 */  jr         $ra
    /* C0D04 002C0104 27BD0018 */  addiu     $sp, $sp, 0x18
.globl mdctBuildBitrevTable
mdctBuildBitrevTable:
    /* C0D08 002C0108 00805021 */  addu       $t2, $a0, $zero
    /* C0D0C 002C010C 00A04821 */  addu       $t1, $a1, $zero
    /* C0D10 002C0110 00003821 */  addu       $a3, $zero, $zero
    /* C0D14 002C0114 19200007 */  .word 0x19200007
    /* C0D18 002C0118 00094040 */  sll       $t0, $t1, 1
    /* C0D1C 002C011C 01401821 */  addu       $v1, $t2, $zero
.Lauto_002C0120:
    /* C0D20 002C0120 AC670000 */  sw         $a3, 0x0($v1)
    /* C0D24 002C0124 24E70001 */  addiu      $a3, $a3, 0x1
    /* C0D28 002C0128 00E9102A */  slt        $v0, $a3, $t1
    /* C0D2C 002C012C 1440FFFC */  .word 0x1440FFFC
    /* C0D30 002C0130 24630004 */  addiu     $v1, $v1, 0x4
.Lauto_002C0134:
    /* C0D34 002C0134 24060001 */  addiu      $a2, $zero, 0x1
    /* C0D38 002C0138 19000023 */  .word 0x19000023
    /* C0D3C 002C013C 00C03821 */  addu      $a3, $a2, $zero
.Lauto_002C0140:
    /* C0D40 002C0140 00E6102A */  slt        $v0, $a3, $a2
    /* C0D44 002C0144 10400010 */  .word 0x10400010
    /* C0D48 002C0148 24C4FFFF */  addiu     $a0, $a2, -0x1
    /* C0D4C 002C014C 000417C2 */  srl        $v0, $a0, 31
    /* C0D50 002C0150 00822021 */  addu       $a0, $a0, $v0
    /* C0D54 002C0154 00042043 */  sra        $a0, $a0, 1
    /* C0D58 002C0158 00042080 */  sll        $a0, $a0, 2
    /* C0D5C 002C015C 008A2021 */  addu       $a0, $a0, $t2
    /* C0D60 002C0160 24E2FFFF */  addiu      $v0, $a3, -0x1
    /* C0D64 002C0164 00021FC2 */  srl        $v1, $v0, 31
    /* C0D68 002C0168 00431021 */  addu       $v0, $v0, $v1
    /* C0D6C 002C016C 00021043 */  sra        $v0, $v0, 1
    /* C0D70 002C0170 00021080 */  sll        $v0, $v0, 2
    /* C0D74 002C0174 004A1021 */  addu       $v0, $v0, $t2
    /* C0D78 002C0178 8C430000 */  lw         $v1, 0x0($v0)
    /* C0D7C 002C017C 8C850000 */  lw         $a1, 0x0($a0)
    /* C0D80 002C0180 AC830000 */  sw         $v1, 0x0($a0)
    /* C0D84 002C0184 AC450000 */  sw         $a1, 0x0($v0)
.Lauto_002C0188:
    /* C0D88 002C0188 01201821 */  addu       $v1, $t1, $zero
    /* C0D8C 002C018C 28620002 */  slti       $v0, $v1, 0x2
    /* C0D90 002C0190 5440000A */  .word 0x5440000A
    /* C0D94 002C0194 24E70002 */  addiu     $a3, $a3, 0x2
    /* C0D98 002C0198 0066102A */  slt        $v0, $v1, $a2
.Lauto_002C019C:
    /* C0D9C 002C019C 50400007 */  .word 0x50400007
    /* C0DA0 002C01A0 24E70002 */  addiu     $a3, $a3, 0x2
    /* C0DA4 002C01A4 00C33023 */  subu       $a2, $a2, $v1
    /* C0DA8 002C01A8 00031843 */  sra        $v1, $v1, 1
    /* C0DAC 002C01AC 28620002 */  slti       $v0, $v1, 0x2
    /* C0DB0 002C01B0 1040FFFA */  .word 0x1040FFFA
    /* C0DB4 002C01B4 0066102A */  slt       $v0, $v1, $a2
    /* C0DB8 002C01B8 24E70002 */  addiu      $a3, $a3, 0x2
.Lauto_002C01BC:
    /* C0DBC 002C01BC 0107102A */  slt        $v0, $t0, $a3
    /* C0DC0 002C01C0 1040FFDF */  .word 0x1040FFDF
    /* C0DC4 002C01C4 00C33021 */  addu      $a2, $a2, $v1
.Lauto_002C01C8:
    /* C0DC8 002C01C8 03E00008 */  jr         $ra
    /* C0DCC 002C01CC 00000000 */  nop
.globl mdctPackSpectrum
mdctPackSpectrum:
    /* C0DD0 002C01D0 00804021 */  addu       $t0, $a0, $zero
    /* C0DD4 002C01D4 00003021 */  addu       $a2, $zero, $zero
    /* C0DD8 002C01D8 240700FF */  addiu      $a3, $zero, 0xFF
.Lauto_002C01DC:
    /* C0DDC 002C01DC 00061C00 */  sll        $v1, $a2, 16
    /* C0DE0 002C01E0 00031C03 */  sra        $v1, $v1, 16
    /* C0DE4 002C01E4 000320C0 */  sll        $a0, $v1, 3
    /* C0DE8 002C01E8 00851021 */  addu       $v0, $a0, $a1
    /* C0DEC 002C01EC 00882021 */  addu       $a0, $a0, $t0
    /* C0DF0 002C01F0 00031840 */  sll        $v1, $v1, 1
    /* C0DF4 002C01F4 00E31823 */  subu       $v1, $a3, $v1
    /* C0DF8 002C01F8 00031880 */  sll        $v1, $v1, 2
    /* C0DFC 002C01FC 00651821 */  addu       $v1, $v1, $a1
    /* C0E00 002C0200 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0E04 002C0204 24C20001 */  addiu      $v0, $a2, 0x1
    /* C0E08 002C0208 00403021 */  addu       $a2, $v0, $zero
    /* C0E0C 002C020C 00021400 */  sll        $v0, $v0, 16
    /* C0E10 002C0210 00021403 */  sra        $v0, $v0, 16
    /* C0E14 002C0214 E4800000 */  swc1       $fv0, 0x0($a0)
    /* C0E18 002C0218 C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C0E1C 002C021C 28420080 */  slti       $v0, $v0, 0x80
    /* C0E20 002C0220 1440FFEE */  .word 0x1440FFEE
    /* C0E24 002C0224 E4800004 */  swc1      $fv0, 0x4($a0)
    /* C0E28 002C0228 03E00008 */  jr         $ra
    /* C0E2C 002C022C 00000000 */  nop
.globl mdctTwiddleMul
mdctTwiddleMul:
    /* C0E30 002C0230 00804021 */  addu       $t0, $a0, $zero
    /* C0E34 002C0234 00003821 */  addu       $a3, $zero, $zero
.Lauto_002C0238:
    /* C0E38 002C0238 00071400 */  sll        $v0, $a3, 16
    /* C0E3C 002C023C 00021403 */  sra        $v0, $v0, 16
    /* C0E40 002C0240 000220C0 */  sll        $a0, $v0, 3
    /* C0E44 002C0244 00882021 */  addu       $a0, $a0, $t0
    /* C0E48 002C0248 00021080 */  sll        $v0, $v0, 2
    /* C0E4C 002C024C 00451821 */  addu       $v1, $v0, $a1
    /* C0E50 002C0250 C4820000 */  lwc1       $fv1, 0x0($a0)
    /* C0E54 002C0254 C4650000 */  lwc1       $ft0f, 0x0($v1)
    /* C0E58 002C0258 46051102 */  mul.s      $ft0, $fv1, $ft0f
    /* C0E5C 002C025C 00461021 */  addu       $v0, $v0, $a2
    /* C0E60 002C0260 C4810004 */  lwc1       $fv0f, 0x4($a0)
    /* C0E64 002C0264 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C0E68 002C0268 460008C2 */  mul.s      $fv1f, $fv0f, $fv0
    /* C0E6C 002C026C 00000000 */  nop
    /* C0E70 002C0270 46001082 */  mul.s      $fv1, $fv1, $fv0
    /* C0E74 002C0274 00000000 */  nop
    /* C0E78 002C0278 46050842 */  mul.s      $fv0f, $fv0f, $ft0f
    /* C0E7C 002C027C 24E20001 */  addiu      $v0, $a3, 0x1
    /* C0E80 002C0280 00403821 */  addu       $a3, $v0, $zero
    /* C0E84 002C0284 46032101 */  sub.s      $ft0, $ft0, $fv1f
    /* C0E88 002C0288 00021400 */  sll        $v0, $v0, 16
    /* C0E8C 002C028C 00021403 */  sra        $v0, $v0, 16
    /* C0E90 002C0290 46011080 */  add.s      $fv1, $fv1, $fv0f
    /* C0E94 002C0294 28420080 */  slti       $v0, $v0, 0x80
    /* C0E98 002C0298 E4840000 */  swc1       $ft0, 0x0($a0)
    /* C0E9C 002C029C 1440FFE6 */  .word 0x1440FFE6
    /* C0EA0 002C02A0 E4820004 */  swc1      $fv1, 0x4($a0)
    /* C0EA4 002C02A4 03E00008 */  jr         $ra
    /* C0EA8 002C02A8 00000000 */  nop
.globl mdctFftCtx
mdctFftCtx:
    /* C0EAC 002C02AC 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* C0EB0 002C02B0 00A01021 */  addu       $v0, $a1, $zero
    /* C0EB4 002C02B4 AFBF0018 */  sw         $ra, 0x18($sp)
    /* C0EB8 002C02B8 8C430004 */  lw         $v1, 0x4($v0)
    /* C0EBC 002C02BC AFA30010 */  sw         $v1, 0x10($sp)
    /* C0EC0 002C02C0 8C430008 */  lw         $v1, 0x8($v0)
    /* C0EC4 002C02C4 AFA30014 */  sw         $v1, 0x14($sp)
    /* C0EC8 002C02C8 8C45000C */  lw         $a1, 0xC($v0)
    /* C0ECC 002C02CC 8C470000 */  lw         $a3, 0x0($v0)
    /* C0ED0 002C02D0 0C0AFEF2 */  jal        mdctFft
    /* C0ED4 002C02D4 00000000 */  nop
    /* C0ED8 002C02D8 8FBF0018 */  lw         $ra, 0x18($sp)
    /* C0EDC 002C02DC 03E00008 */  jr         $ra
    /* C0EE0 002C02E0 27BD0020 */  addiu     $sp, $sp, 0x20
.globl adecRoundClampS16
adecRoundClampS16:
    /* C0EE4 002C02E4 44800000 */  mtc1       $zero, $fv0
    /* C0EE8 002C02E8 460C003E */  c.le.s     $fv0, $fa0
    /* C0EEC 002C02EC 00000000 */  nop
    /* C0EF0 002C02F0 45000009 */  .word 0x45000009
    /* C0EF4 002C02F4 00000000 */  nop
    /* C0EF8 002C02F8 3C01800D */  lui        $at, %hi(D_auto_800C88D8)
    /* C0EFC 002C02FC C42088D8 */  lwc1       $fv0, %lo(D_auto_800C88D8)($at)
    /* C0F00 002C0300 46006300 */  add.s      $fa0, $fa0, $fv0
    /* C0F04 002C0304 3C01800D */  lui        $at, %hi(D_auto_800C88DC)
    /* C0F08 002C0308 C42088DC */  lwc1       $fv0, %lo(D_auto_800C88DC)($at)
    /* C0F0C 002C030C 460C003C */  c.lt.s     $fv0, $fa0
    /* C0F10 002C0310 080B00CC */  .word 0x080B00CC
    /* C0F14 002C0314 00000000 */  nop
.Lauto_002C0318:
    /* C0F18 002C0318 3C01800D */  lui        $at, %hi(D_auto_800C88E0)
    /* C0F1C 002C031C C42088E0 */  lwc1       $fv0, %lo(D_auto_800C88E0)($at)
    /* C0F20 002C0320 46006301 */  sub.s      $fa0, $fa0, $fv0
    /* C0F24 002C0324 3C01800D */  lui        $at, %hi(D_auto_800C88E4)
    /* C0F28 002C0328 C42088E4 */  lwc1       $fv0, %lo(D_auto_800C88E4)($at)
    /* C0F2C 002C032C 4600603C */  c.lt.s     $fa0, $fv0
.Lauto_002C0330:
    /* C0F30 002C0330 00000000 */  nop
    /* C0F34 002C0334 45030001 */  .word 0x45030001
    /* C0F38 002C0338 46000306 */  mov.s     $fa0, $fv0
.Lauto_002C033C:
    /* C0F3C 002C033C 4600604D */  trunc.w.s  $fv0f, $fa0
    /* C0F40 002C0340 44020800 */  mfc1       $v0, $fv0f
    /* C0F44 002C0344 00021400 */  sll        $v0, $v0, 16
    /* C0F48 002C0348 03E00008 */  jr         $ra
    /* C0F4C 002C034C 00021403 */  sra       $v0, $v0, 16
.globl adecStreamOpen
adecStreamOpen:
    /* C0F50 002C0350 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C0F54 002C0354 00A04021 */  addu       $t0, $a1, $zero
    /* C0F58 002C0358 3C038016 */  lui        $v1, %hi(D_auto_8015BA38)
    /* C0F5C 002C035C 2463BA38 */  addiu      $v1, $v1, %lo(D_auto_8015BA38)
    /* C0F60 002C0360 AFBF0010 */  sw         $ra, 0x10($sp)
    /* C0F64 002C0364 AC640008 */  sw         $a0, 0x8($v1)
    /* C0F68 002C0368 AC640014 */  sw         $a0, 0x14($v1)
    /* C0F6C 002C036C 8C870000 */  lw         $a3, 0x0($a0)
    /* C0F70 002C0370 24820004 */  addiu      $v0, $a0, 0x4
    /* C0F74 002C0374 AC620014 */  sw         $v0, 0x14($v1)
    /* C0F78 002C0378 AC670000 */  sw         $a3, 0x0($v1)
    /* C0F7C 002C037C 8C820004 */  lw         $v0, 0x4($a0)
    /* C0F80 002C0380 3C0A0F42 */  lui        $t2, (0xF424000 >> 16)
    /* C0F84 002C0384 AC620010 */  sw         $v0, 0x10($v1)
    /* C0F88 002C0388 8C850004 */  lw         $a1, 0x4($a0)
    /* C0F8C 002C038C 24820008 */  addiu      $v0, $a0, 0x8
    /* C0F90 002C0390 AC620014 */  sw         $v0, 0x14($v1)
    /* C0F94 002C0394 AC65000C */  sw         $a1, 0xC($v1)
    /* C0F98 002C0398 8C820008 */  lw         $v0, 0x8($a0)
    /* C0F9C 002C039C 2484000C */  addiu      $a0, $a0, 0xC
    /* C0FA0 002C03A0 AC640014 */  sw         $a0, 0x14($v1)
    /* C0FA4 002C03A4 3C01800E */  lui        $at, %hi(D_auto_800E5B3E)
    /* C0FA8 002C03A8 A4205B3E */  sh         $zero, %lo(D_auto_800E5B3E)($at)
    /* C0FAC 002C03AC 3C01800E */  lui        $at, %hi(D_auto_800E5B40)
    /* C0FB0 002C03B0 A4205B40 */  sh         $zero, %lo(D_auto_800E5B40)($at)
    /* C0FB4 002C03B4 3C01800E */  lui        $at, %hi(D_auto_800E5B38)
    /* C0FB8 002C03B8 A4205B38 */  sh         $zero, %lo(D_auto_800E5B38)($at)
    /* C0FBC 002C03BC 3C01800E */  lui        $at, %hi(D_auto_800E5B3A)
    /* C0FC0 002C03C0 A4205B3A */  sh         $zero, %lo(D_auto_800E5B3A)($at)
    /* C0FC4 002C03C4 3C01800E */  lui        $at, %hi(D_auto_800E5B3C)
    /* C0FC8 002C03C8 A4205B3C */  sh         $zero, %lo(D_auto_800E5B3C)($at)
    /* C0FCC 002C03CC AC620004 */  sw         $v0, 0x4($v1)
    /* C0FD0 002C03D0 ACC70000 */  sw         $a3, 0x0($a2)
    /* C0FD4 002C03D4 8C620010 */  lw         $v0, 0x10($v1)
    /* C0FD8 002C03D8 354A4000 */  ori        $t2, $t2, (0xF424000 & 0xFFFF)
    /* C0FDC 002C03DC 004A0018 */  mult       $v0, $t2
    /* C0FE0 002C03E0 01004821 */  addu       $t1, $t0, $zero
    /* C0FE4 002C03E4 00004021 */  addu       $t0, $zero, $zero
    /* C0FE8 002C03E8 01003021 */  addu       $a2, $t0, $zero
    /* C0FEC 002C03EC 00002010 */  mfhi       $a0
    /* C0FF0 002C03F0 00002812 */  mflo       $a1
    /* C0FF4 002C03F4 0C0B0410 */  jal        __udivdi3
    /* C0FF8 002C03F8 01203821 */  addu      $a3, $t1, $zero
    /* C0FFC 002C03FC 8FBF0010 */  lw         $ra, 0x10($sp)
    /* C1000 002C0400 00601021 */  addu       $v0, $v1, $zero
    /* C1004 002C0404 03E00008 */  jr         $ra
    /* C1008 002C0408 27BD0018 */  addiu     $sp, $sp, 0x18
.globl adecNextFrame
adecNextFrame:
    /* C100C 002C040C 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* C1010 002C0410 AFB20018 */  sw         $s2, 0x18($sp)
    /* C1014 002C0414 3C128016 */  lui        $s2, %hi(D_auto_8015BA38)
    /* C1018 002C0418 2652BA38 */  addiu      $s2, $s2, %lo(D_auto_8015BA38)
    /* C101C 002C041C AFBF001C */  sw         $ra, 0x1C($sp)
    /* C1020 002C0420 AFB10014 */  sw         $s1, 0x14($sp)
    /* C1024 002C0424 AFB00010 */  sw         $s0, 0x10($sp)
    /* C1028 002C0428 8E420010 */  lw         $v0, 0x10($s2)
    /* C102C 002C042C 10400019 */  .word 0x10400019
    /* C1030 002C0430 00001021 */  addu      $v0, $zero, $zero
    /* C1034 002C0434 0C0AFD8A */  jal        adecDecodeFrame
    /* C1038 002C0438 02402021 */  addu      $a0, $s2, $zero
    /* C103C 002C043C 3C11800E */  lui        $s1, %hi(D_auto_800E5B42)
    /* C1040 002C0440 26315B42 */  addiu      $s1, $s1, %lo(D_auto_800E5B42)
    /* C1044 002C0444 96220000 */  lhu        $v0, 0x0($s1)
    /* C1048 002C0448 24420001 */  addiu      $v0, $v0, 0x1
    /* C104C 002C044C A6220000 */  sh         $v0, 0x0($s1)
    /* C1050 002C0450 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C1054 002C0454 2C420006 */  sltiu      $v0, $v0, 0x6
    /* C1058 002C0458 50400001 */  .word 0x50400001
    /* C105C 002C045C A6200000 */  sh        $zero, 0x0($s1)
.Lauto_002C0460:
    /* C1060 002C0460 3C108016 */  lui        $s0, %hi(D_auto_8015BCF0)
    /* C1064 002C0464 2610BCF0 */  addiu      $s0, $s0, %lo(D_auto_8015BCF0)
    /* C1068 002C0468 96240000 */  lhu        $a0, 0x0($s1)
    /* C106C 002C046C 02402821 */  addu       $a1, $s2, $zero
    /* C1070 002C0470 00042240 */  sll        $a0, $a0, 9
    /* C1074 002C0474 0C0AFF53 */  jal        adecImdctFrame
    /* C1078 002C0478 00902021 */  addu      $a0, $a0, $s0
    /* C107C 002C047C 96220000 */  lhu        $v0, 0x0($s1)
    /* C1080 002C0480 8E430010 */  lw         $v1, 0x10($s2)
    /* C1084 002C0484 00021240 */  sll        $v0, $v0, 9
    /* C1088 002C0488 00501021 */  addu       $v0, $v0, $s0
    /* C108C 002C048C 2463FFFF */  addiu      $v1, $v1, -0x1
    /* C1090 002C0490 AE430010 */  sw         $v1, 0x10($s2)
.Lauto_002C0494:
    /* C1094 002C0494 8FBF001C */  lw         $ra, 0x1C($sp)
    /* C1098 002C0498 8FB20018 */  lw         $s2, 0x18($sp)
    /* C109C 002C049C 8FB10014 */  lw         $s1, 0x14($sp)
    /* C10A0 002C04A0 8FB00010 */  lw         $s0, 0x10($sp)
    /* C10A4 002C04A4 03E00008 */  jr         $ra
    /* C10A8 002C04A8 27BD0020 */  addiu     $sp, $sp, 0x20
.globl adecGetStopFlag
adecGetStopFlag:
    /* C10AC 002C04AC 3C028016 */  lui        $v0, %hi(D_auto_8015BA48)
    /* C10B0 002C04B0 8C42BA48 */  lw         $v0, %lo(D_auto_8015BA48)($v0)
    /* C10B4 002C04B4 03E00008 */  jr         $ra
    /* C10B8 002C04B8 00000000 */  nop
.globl adecClearStopFlag
adecClearStopFlag:
    /* C10BC 002C04BC 3C018016 */  lui        $at, %hi(D_auto_8015BA48)
    /* C10C0 002C04C0 AC20BA48 */  sw         $zero, %lo(D_auto_8015BA48)($at)
    /* C10C4 002C04C4 03E00008 */  jr         $ra
    /* C10C8 002C04C8 00000000 */  nop
