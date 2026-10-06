.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xAEF80-0xAF1AC (VRAM 0x002AE380) */
glabel func_002AE380
    /* AEF80 002AE380 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AEF84 002AE384 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AEF88 002AE388 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* AEF8C 002AE38C AFB60028 */  sw         $s6, 0x28($sp)
    /* AEF90 002AE390 0080B021 */  addu       $s6, $a0, $zero
    /* AEF94 002AE394 AFB50024 */  sw         $s5, 0x24($sp)
    /* AEF98 002AE398 0000A821 */  addu       $s5, $zero, $zero
    /* AEF9C 002AE39C AFBF002C */  sw         $ra, 0x2C($sp)
    /* AEFA0 002AE3A0 AFB40020 */  sw         $s4, 0x20($sp)
    /* AEFA4 002AE3A4 AFB3001C */  sw         $s3, 0x1C($sp)
    /* AEFA8 002AE3A8 AFB20018 */  sw         $s2, 0x18($sp)
    /* AEFAC 002AE3AC AFB10014 */  sw         $s1, 0x14($sp)
    /* AEFB0 002AE3B0 AFB00010 */  sw         $s0, 0x10($sp)
    /* AEFB4 002AE3B4 304200F8 */  andi       $v0, $v0, 0xF8
    /* AEFB8 002AE3B8 34420002 */  ori        $v0, $v0, 0x2
    /* AEFBC 002AE3BC 00408021 */  addu       $s0, $v0, $zero
    /* AEFC0 002AE3C0 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AEFC4 002AE3C4 A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AE3C8:
    /* AEFC8 002AE3C8 0C0AF7A8 */  jal        osPiGetStatus
    /* AEFCC 002AE3CC 00000000 */   nop
    /* AEFD0 002AE3D0 30420003 */  andi       $v0, $v0, 0x3
    /* AEFD4 002AE3D4 1440FFFC */  bnez       $v0, .L002AE3C8
    /* AEFD8 002AE3D8 00000000 */   nop
    /* AEFDC 002AE3DC 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AEFE0 002AE3E0 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AEFE4 002AE3E4 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AEFE8 002AE3E8 A430000C */  sh         $s0, %lo(D_B200000C)($at)
    /* AEFEC 002AE3EC 34420008 */  ori        $v0, $v0, 0x8
    /* AEFF0 002AE3F0 00409021 */  addu       $s2, $v0, $zero
    /* AEFF4 002AE3F4 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AEFF8 002AE3F8 A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AE3FC:
    /* AEFFC 002AE3FC 0C0AF7A8 */  jal        osPiGetStatus
    /* AF000 002AE400 00000000 */   nop
    /* AF004 002AE404 30420003 */  andi       $v0, $v0, 0x3
    /* AF008 002AE408 1440FFFC */  bnez       $v0, .L002AE3FC
    /* AF00C 002AE40C 24140001 */   addiu     $s4, $zero, 0x1
    /* AF010 002AE410 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* AF014 002AE414 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* AF018 002AE418 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* AF01C 002AE41C 24130001 */  addiu      $s3, $zero, 0x1
    /* AF020 002AE420 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AF024 002AE424 A432000C */  sh         $s2, %lo(D_B200000C)($at)
    /* AF028 002AE428 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* AF02C 002AE42C AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
  .L002AE430:
    /* AF030 002AE430 0C0AF7A8 */  jal        osPiGetStatus
    /* AF034 002AE434 00000000 */   nop
    /* AF038 002AE438 30420003 */  andi       $v0, $v0, 0x3
    /* AF03C 002AE43C 1440FFFC */  bnez       $v0, .L002AE430
    /* AF040 002AE440 00000000 */   nop
    /* AF044 002AE444 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* AF048 002AE448 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* AF04C 002AE44C 00541024 */  and        $v0, $v0, $s4
    /* AF050 002AE450 10530009 */  beq        $v0, $s3, .L002AE478
    /* AF054 002AE454 02001021 */   addu      $v0, $s0, $zero
    /* AF058 002AE458 14400003 */  bnez       $v0, .L002AE468
    /* AF05C 002AE45C 2610FFFF */   addiu     $s0, $s0, -0x1
    /* AF060 002AE460 2631FFFF */  addiu      $s1, $s1, -0x1
    /* AF064 002AE464 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AE468:
    /* AF068 002AE468 1E20FFF1 */  bgtz       $s1, .L002AE430
    /* AF06C 002AE46C 24020001 */   addiu     $v0, $zero, 0x1
    /* AF070 002AE470 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* AF074 002AE474 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002AE478:
    /* AF078 002AE478 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AF07C 002AE47C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AF080 002AE480 14400040 */  bnez       $v0, .L002AE584
    /* AF084 002AE484 02A01021 */   addu      $v0, $s5, $zero
  .L002AE488:
    /* AF088 002AE488 0C0AF7A8 */  jal        osPiGetStatus
    /* AF08C 002AE48C 00000000 */   nop
    /* AF090 002AE490 30420003 */  andi       $v0, $v0, 0x3
    /* AF094 002AE494 1440FFFC */  bnez       $v0, .L002AE488
    /* AF098 002AE498 00000000 */   nop
    /* AF09C 002AE49C 3C02B200 */  lui        $v0, %hi(D_B2000001)
    /* AF0A0 002AE4A0 90420001 */  lbu        $v0, %lo(D_B2000001)($v0)
    /* AF0A4 002AE4A4 A2C20000 */  sb         $v0, 0x0($s6)
    /* AF0A8 002AE4A8 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AF0AC 002AE4AC 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AF0B0 002AE4B0 304200F7 */  andi       $v0, $v0, 0xF7
    /* AF0B4 002AE4B4 00409021 */  addu       $s2, $v0, $zero
    /* AF0B8 002AE4B8 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AF0BC 002AE4BC A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AE4C0:
    /* AF0C0 002AE4C0 0C0AF7A8 */  jal        osPiGetStatus
    /* AF0C4 002AE4C4 00000000 */   nop
    /* AF0C8 002AE4C8 30420003 */  andi       $v0, $v0, 0x3
    /* AF0CC 002AE4CC 1440FFFC */  bnez       $v0, .L002AE4C0
    /* AF0D0 002AE4D0 00000000 */   nop
    /* AF0D4 002AE4D4 24130001 */  addiu      $s3, $zero, 0x1
    /* AF0D8 002AE4D8 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* AF0DC 002AE4DC 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* AF0E0 002AE4E0 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* AF0E4 002AE4E4 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AF0E8 002AE4E8 A432000C */  sh         $s2, %lo(D_B200000C)($at)
  .L002AE4EC:
    /* AF0EC 002AE4EC 0C0AF7A8 */  jal        osPiGetStatus
    /* AF0F0 002AE4F0 00000000 */   nop
    /* AF0F4 002AE4F4 30420003 */  andi       $v0, $v0, 0x3
    /* AF0F8 002AE4F8 1440FFFC */  bnez       $v0, .L002AE4EC
    /* AF0FC 002AE4FC 00000000 */   nop
    /* AF100 002AE500 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* AF104 002AE504 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* AF108 002AE508 00531024 */  and        $v0, $v0, $s3
    /* AF10C 002AE50C 304200FF */  andi       $v0, $v0, 0xFF
    /* AF110 002AE510 10400009 */  beqz       $v0, .L002AE538
    /* AF114 002AE514 02001021 */   addu      $v0, $s0, $zero
    /* AF118 002AE518 14400003 */  bnez       $v0, .L002AE528
    /* AF11C 002AE51C 2610FFFF */   addiu     $s0, $s0, -0x1
    /* AF120 002AE520 2631FFFF */  addiu      $s1, $s1, -0x1
    /* AF124 002AE524 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AE528:
    /* AF128 002AE528 1E20FFF0 */  bgtz       $s1, .L002AE4EC
    /* AF12C 002AE52C 24020001 */   addiu     $v0, $zero, 0x1
    /* AF130 002AE530 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* AF134 002AE534 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002AE538:
    /* AF138 002AE538 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AF13C 002AE53C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AF140 002AE540 14400010 */  bnez       $v0, .L002AE584
    /* AF144 002AE544 02A01021 */   addu      $v0, $s5, $zero
    /* AF148 002AE548 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AF14C 002AE54C 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AF150 002AE550 304200F8 */  andi       $v0, $v0, 0xF8
    /* AF154 002AE554 00408021 */  addu       $s0, $v0, $zero
    /* AF158 002AE558 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AF15C 002AE55C A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AE560:
    /* AF160 002AE560 0C0AF7A8 */  jal        osPiGetStatus
    /* AF164 002AE564 00000000 */   nop
    /* AF168 002AE568 30420003 */  andi       $v0, $v0, 0x3
    /* AF16C 002AE56C 1440FFFC */  bnez       $v0, .L002AE560
    /* AF170 002AE570 00000000 */   nop
    /* AF174 002AE574 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AF178 002AE578 A430000C */  sh         $s0, %lo(D_B200000C)($at)
    /* AF17C 002AE57C 24150001 */  addiu      $s5, $zero, 0x1
    /* AF180 002AE580 02A01021 */  addu       $v0, $s5, $zero
  .L002AE584:
    /* AF184 002AE584 8FBF002C */  lw         $ra, 0x2C($sp)
    /* AF188 002AE588 8FB60028 */  lw         $s6, 0x28($sp)
    /* AF18C 002AE58C 8FB50024 */  lw         $s5, 0x24($sp)
    /* AF190 002AE590 8FB40020 */  lw         $s4, 0x20($sp)
    /* AF194 002AE594 8FB3001C */  lw         $s3, 0x1C($sp)
    /* AF198 002AE598 8FB20018 */  lw         $s2, 0x18($sp)
    /* AF19C 002AE59C 8FB10014 */  lw         $s1, 0x14($sp)
    /* AF1A0 002AE5A0 8FB00010 */  lw         $s0, 0x10($sp)
    /* AF1A4 002AE5A4 03E00008 */  jr         $ra
    /* AF1A8 002AE5A8 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_002AE380
