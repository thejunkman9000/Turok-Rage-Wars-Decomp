.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xAF1AC-0xAF434 (VRAM 0x002AE5AC) */
glabel func_002AE5AC
    /* AF1AC 002AE5AC 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AF1B0 002AE5B0 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AF1B4 002AE5B4 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* AF1B8 002AE5B8 AFB00010 */  sw         $s0, 0x10($sp)
    /* AF1BC 002AE5BC 00808021 */  addu       $s0, $a0, $zero
    /* AF1C0 002AE5C0 AFB50024 */  sw         $s5, 0x24($sp)
    /* AF1C4 002AE5C4 0000A821 */  addu       $s5, $zero, $zero
    /* AF1C8 002AE5C8 AFBF0028 */  sw         $ra, 0x28($sp)
    /* AF1CC 002AE5CC AFB40020 */  sw         $s4, 0x20($sp)
    /* AF1D0 002AE5D0 AFB3001C */  sw         $s3, 0x1C($sp)
    /* AF1D4 002AE5D4 AFB20018 */  sw         $s2, 0x18($sp)
    /* AF1D8 002AE5D8 AFB10014 */  sw         $s1, 0x14($sp)
    /* AF1DC 002AE5DC 304200F8 */  andi       $v0, $v0, 0xF8
    /* AF1E0 002AE5E0 34420003 */  ori        $v0, $v0, 0x3
    /* AF1E4 002AE5E4 00408821 */  addu       $s1, $v0, $zero
    /* AF1E8 002AE5E8 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AF1EC 002AE5EC A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AE5F0:
    /* AF1F0 002AE5F0 0C0AF7A8 */  jal        osPiGetStatus
    /* AF1F4 002AE5F4 00000000 */   nop
    /* AF1F8 002AE5F8 30420003 */  andi       $v0, $v0, 0x3
    /* AF1FC 002AE5FC 1440FFFC */  bnez       $v0, .L002AE5F0
    /* AF200 002AE600 00000000 */   nop
    /* AF204 002AE604 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AF208 002AE608 A431000C */  sh         $s1, %lo(D_B200000C)($at)
    /* AF20C 002AE60C 3C018015 */  lui        $at, %hi(D_8014D3E0)
    /* AF210 002AE610 A030D3E0 */  sb         $s0, %lo(D_8014D3E0)($at)
  .L002AE614:
    /* AF214 002AE614 0C0AF7A8 */  jal        osPiGetStatus
    /* AF218 002AE618 00000000 */   nop
    /* AF21C 002AE61C 30420003 */  andi       $v0, $v0, 0x3
    /* AF220 002AE620 1440FFFC */  bnez       $v0, .L002AE614
    /* AF224 002AE624 320300FF */   andi      $v1, $s0, 0xFF
    /* AF228 002AE628 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* AF22C 002AE62C 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* AF230 002AE630 3C01B200 */  lui        $at, %hi(D_B2000000)
    /* AF234 002AE634 A4230000 */  sh         $v1, %lo(D_B2000000)($at)
    /* AF238 002AE638 34420001 */  ori        $v0, $v0, 0x1
    /* AF23C 002AE63C 00408021 */  addu       $s0, $v0, $zero
    /* AF240 002AE640 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* AF244 002AE644 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002AE648:
    /* AF248 002AE648 0C0AF7A8 */  jal        osPiGetStatus
    /* AF24C 002AE64C 00000000 */   nop
    /* AF250 002AE650 30420003 */  andi       $v0, $v0, 0x3
    /* AF254 002AE654 1440FFFC */  bnez       $v0, .L002AE648
    /* AF258 002AE658 00000000 */   nop
    /* AF25C 002AE65C 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AF260 002AE660 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AF264 002AE664 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* AF268 002AE668 A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* AF26C 002AE66C 34420008 */  ori        $v0, $v0, 0x8
    /* AF270 002AE670 00409021 */  addu       $s2, $v0, $zero
    /* AF274 002AE674 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AF278 002AE678 A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AE67C:
    /* AF27C 002AE67C 0C0AF7A8 */  jal        osPiGetStatus
    /* AF280 002AE680 00000000 */   nop
    /* AF284 002AE684 30420003 */  andi       $v0, $v0, 0x3
    /* AF288 002AE688 1440FFFC */  bnez       $v0, .L002AE67C
    /* AF28C 002AE68C 24140001 */   addiu     $s4, $zero, 0x1
    /* AF290 002AE690 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* AF294 002AE694 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* AF298 002AE698 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* AF29C 002AE69C 24130001 */  addiu      $s3, $zero, 0x1
    /* AF2A0 002AE6A0 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AF2A4 002AE6A4 A432000C */  sh         $s2, %lo(D_B200000C)($at)
  .L002AE6A8:
    /* AF2A8 002AE6A8 0C0AF7A8 */  jal        osPiGetStatus
    /* AF2AC 002AE6AC 00000000 */   nop
    /* AF2B0 002AE6B0 30420003 */  andi       $v0, $v0, 0x3
    /* AF2B4 002AE6B4 1440FFFC */  bnez       $v0, .L002AE6A8
    /* AF2B8 002AE6B8 00000000 */   nop
    /* AF2BC 002AE6BC 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* AF2C0 002AE6C0 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* AF2C4 002AE6C4 00541024 */  and        $v0, $v0, $s4
    /* AF2C8 002AE6C8 10530009 */  beq        $v0, $s3, .L002AE6F0
    /* AF2CC 002AE6CC 02001021 */   addu      $v0, $s0, $zero
    /* AF2D0 002AE6D0 14400003 */  bnez       $v0, .L002AE6E0
    /* AF2D4 002AE6D4 2610FFFF */   addiu     $s0, $s0, -0x1
    /* AF2D8 002AE6D8 2631FFFF */  addiu      $s1, $s1, -0x1
    /* AF2DC 002AE6DC 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AE6E0:
    /* AF2E0 002AE6E0 1E20FFF1 */  bgtz       $s1, .L002AE6A8
    /* AF2E4 002AE6E4 24020001 */   addiu     $v0, $zero, 0x1
    /* AF2E8 002AE6E8 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* AF2EC 002AE6EC AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002AE6F0:
    /* AF2F0 002AE6F0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AF2F4 002AE6F4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AF2F8 002AE6F8 14400045 */  bnez       $v0, .L002AE810
    /* AF2FC 002AE6FC 02A01021 */   addu      $v0, $s5, $zero
    /* AF300 002AE700 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AF304 002AE704 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AF308 002AE708 304200F7 */  andi       $v0, $v0, 0xF7
    /* AF30C 002AE70C 00409021 */  addu       $s2, $v0, $zero
    /* AF310 002AE710 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AF314 002AE714 A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AE718:
    /* AF318 002AE718 0C0AF7A8 */  jal        osPiGetStatus
    /* AF31C 002AE71C 00000000 */   nop
    /* AF320 002AE720 30420003 */  andi       $v0, $v0, 0x3
    /* AF324 002AE724 1440FFFC */  bnez       $v0, .L002AE718
    /* AF328 002AE728 00000000 */   nop
    /* AF32C 002AE72C 24130001 */  addiu      $s3, $zero, 0x1
    /* AF330 002AE730 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* AF334 002AE734 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* AF338 002AE738 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* AF33C 002AE73C 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AF340 002AE740 A432000C */  sh         $s2, %lo(D_B200000C)($at)
  .L002AE744:
    /* AF344 002AE744 0C0AF7A8 */  jal        osPiGetStatus
    /* AF348 002AE748 00000000 */   nop
    /* AF34C 002AE74C 30420003 */  andi       $v0, $v0, 0x3
    /* AF350 002AE750 1440FFFC */  bnez       $v0, .L002AE744
    /* AF354 002AE754 00000000 */   nop
    /* AF358 002AE758 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* AF35C 002AE75C 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* AF360 002AE760 00531024 */  and        $v0, $v0, $s3
    /* AF364 002AE764 304200FF */  andi       $v0, $v0, 0xFF
    /* AF368 002AE768 10400009 */  beqz       $v0, .L002AE790
    /* AF36C 002AE76C 02001021 */   addu      $v0, $s0, $zero
    /* AF370 002AE770 14400003 */  bnez       $v0, .L002AE780
    /* AF374 002AE774 2610FFFF */   addiu     $s0, $s0, -0x1
    /* AF378 002AE778 2631FFFF */  addiu      $s1, $s1, -0x1
    /* AF37C 002AE77C 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002AE780:
    /* AF380 002AE780 1E20FFF0 */  bgtz       $s1, .L002AE744
    /* AF384 002AE784 24020001 */   addiu     $v0, $zero, 0x1
    /* AF388 002AE788 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* AF38C 002AE78C AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002AE790:
    /* AF390 002AE790 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* AF394 002AE794 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* AF398 002AE798 1440001D */  bnez       $v0, .L002AE810
    /* AF39C 002AE79C 02A01021 */   addu      $v0, $s5, $zero
    /* AF3A0 002AE7A0 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* AF3A4 002AE7A4 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* AF3A8 002AE7A8 304200FE */  andi       $v0, $v0, 0xFE
    /* AF3AC 002AE7AC 00408021 */  addu       $s0, $v0, $zero
    /* AF3B0 002AE7B0 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* AF3B4 002AE7B4 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002AE7B8:
    /* AF3B8 002AE7B8 0C0AF7A8 */  jal        osPiGetStatus
    /* AF3BC 002AE7BC 00000000 */   nop
    /* AF3C0 002AE7C0 30420003 */  andi       $v0, $v0, 0x3
    /* AF3C4 002AE7C4 1440FFFC */  bnez       $v0, .L002AE7B8
    /* AF3C8 002AE7C8 00000000 */   nop
    /* AF3CC 002AE7CC 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* AF3D0 002AE7D0 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* AF3D4 002AE7D4 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* AF3D8 002AE7D8 A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* AF3DC 002AE7DC 304200F8 */  andi       $v0, $v0, 0xF8
    /* AF3E0 002AE7E0 00408021 */  addu       $s0, $v0, $zero
    /* AF3E4 002AE7E4 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* AF3E8 002AE7E8 A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002AE7EC:
    /* AF3EC 002AE7EC 0C0AF7A8 */  jal        osPiGetStatus
    /* AF3F0 002AE7F0 00000000 */   nop
    /* AF3F4 002AE7F4 30420003 */  andi       $v0, $v0, 0x3
    /* AF3F8 002AE7F8 1440FFFC */  bnez       $v0, .L002AE7EC
    /* AF3FC 002AE7FC 00000000 */   nop
    /* AF400 002AE800 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* AF404 002AE804 A430000C */  sh         $s0, %lo(D_B200000C)($at)
    /* AF408 002AE808 24150001 */  addiu      $s5, $zero, 0x1
    /* AF40C 002AE80C 02A01021 */  addu       $v0, $s5, $zero
  .L002AE810:
    /* AF410 002AE810 8FBF0028 */  lw         $ra, 0x28($sp)
    /* AF414 002AE814 8FB50024 */  lw         $s5, 0x24($sp)
    /* AF418 002AE818 8FB40020 */  lw         $s4, 0x20($sp)
    /* AF41C 002AE81C 8FB3001C */  lw         $s3, 0x1C($sp)
    /* AF420 002AE820 8FB20018 */  lw         $s2, 0x18($sp)
    /* AF424 002AE824 8FB10014 */  lw         $s1, 0x14($sp)
    /* AF428 002AE828 8FB00010 */  lw         $s0, 0x10($sp)
    /* AF42C 002AE82C 03E00008 */  jr         $ra
    /* AF430 002AE830 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel func_002AE5AC
