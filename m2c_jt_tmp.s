.include "macro.inc"
.set noat
.set noreorder
.section .text
glabel func_002BE100
    /* BED00 002BE100 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* BED04 002BE104 AFB20030 */  sw         $s2, 0x30($sp)
    /* BED08 002BE108 00809021 */  addu       $s2, $a0, $zero
    /* BED0C 002BE10C AFB40038 */  sw         $s4, 0x38($sp)
    /* BED10 002BE110 24140002 */  addiu      $s4, $zero, 0x2
    /* BED14 002BE114 AFB5003C */  sw         $s5, 0x3C($sp)
    /* BED18 002BE118 24150001 */  addiu      $s5, $zero, 0x1
    /* BED1C 002BE11C AFBF0040 */  sw         $ra, 0x40($sp)
    /* BED20 002BE120 AFB30034 */  sw         $s3, 0x34($sp)
    /* BED24 002BE124 AFB1002C */  sw         $s1, 0x2C($sp)
    /* BED28 002BE128 AFB00028 */  sw         $s0, 0x28($sp)
    /* BED2C 002BE12C AFA00018 */  sw         $zero, 0x18($sp)
    /* BED30 002BE130 27A50018 */  addiu      $a1, $sp, 0x18
  .L002BE134:
    /* BED34 002BE134 8E440008 */  lw         $a0, 0x8($s2)
    /* BED38 002BE138 0C0B00E4 */  jal        osRecvMesg
    /* BED3C 002BE13C 24060001 */   addiu     $a2, $zero, 0x1
    /* BED40 002BE140 8FA20018 */  lw         $v0, 0x18($sp)
    /* BED44 002BE144 8C500014 */  lw         $s0, 0x14($v0)
    /* BED48 002BE148 1200007C */  beqz       $s0, .L002BE33C
    /* BED4C 002BE14C 00000000 */   nop
    /* BED50 002BE150 92020004 */  lbu        $v0, 0x4($s0)
    /* BED54 002BE154 14540078 */  bne        $v0, $s4, .L002BE338
    /* BED58 002BE158 00000000 */   nop
    /* BED5C 002BE15C 8E020014 */  lw         $v0, 0x14($s0)
    /* BED60 002BE160 2C420002 */  sltiu      $v0, $v0, 0x2
    /* BED64 002BE164 10400074 */  beqz       $v0, .L002BE338
    /* BED68 002BE168 26040014 */   addiu     $a0, $s0, 0x14
    /* BED6C 002BE16C 9603001A */  lhu        $v1, 0x1A($s0)
    /* BED70 002BE170 2402FFFF */  addiu      $v0, $zero, -0x1
    /* BED74 002BE174 AE02001C */  sw         $v0, 0x1C($s0)
    /* BED78 002BE178 000310C0 */  sll        $v0, $v1, 3
    /* BED7C 002BE17C 00431021 */  addu       $v0, $v0, $v1
    /* BED80 002BE180 00021080 */  sll        $v0, $v0, 2
    /* BED84 002BE184 24420018 */  addiu      $v0, $v0, 0x18
    /* BED88 002BE188 00828821 */  addu       $s1, $a0, $v0
    /* BED8C 002BE18C 96030018 */  lhu        $v1, 0x18($s0)
    /* BED90 002BE190 24020003 */  addiu      $v0, $zero, 0x3
    /* BED94 002BE194 10620005 */  beq        $v1, $v0, .L002BE1AC
    /* BED98 002BE198 00000000 */   nop
    /* BED9C 002BE19C 8E220004 */  lw         $v0, 0x4($s1)
    /* BEDA0 002BE1A0 8E23000C */  lw         $v1, 0xC($s1)
    /* BEDA4 002BE1A4 00431023 */  subu       $v0, $v0, $v1
    /* BEDA8 002BE1A8 AE220004 */  sw         $v0, 0x4($s1)
  .L002BE1AC:
    /* BEDAC 002BE1AC 96020018 */  lhu        $v0, 0x18($s0)
    /* BEDB0 002BE1B0 14540005 */  bne        $v0, $s4, .L002BE1C8
    /* BEDB4 002BE1B4 00009821 */   addu      $s3, $zero, $zero
    /* BEDB8 002BE1B8 8FA20018 */  lw         $v0, 0x18($sp)
    /* BEDBC 002BE1BC 8C420014 */  lw         $v0, 0x14($v0)
    /* BEDC0 002BE1C0 8C420014 */  lw         $v0, 0x14($v0)
    /* BEDC4 002BE1C4 2C530001 */  sltiu      $s3, $v0, 0x1
  .L002BE1C8:
    /* BEDC8 002BE1C8 27A5001C */  addiu      $a1, $sp, 0x1C
    /* BEDCC 002BE1CC 8E440010 */  lw         $a0, 0x10($s2)
    /* BEDD0 002BE1D0 0C0B00E4 */  jal        osRecvMesg
    /* BEDD4 002BE1D4 24060001 */   addiu     $a2, $zero, 0x1
    /* BEDD8 002BE1D8 3C040010 */  lui        $a0, (0x100401 >> 16)
    /* BEDDC 002BE1DC 0C0B0130 */  jal        func_002C04C0
    /* BEDE0 002BE1E0 34840401 */   ori       $a0, $a0, (0x100401 & 0xFFFF)
    /* BEDE4 002BE1E4 3C050500 */  lui        $a1, (0x5000510 >> 16)
    /* BEDE8 002BE1E8 8FA20018 */  lw         $v0, 0x18($sp)
    /* BEDEC 002BE1EC 34A50510 */  ori        $a1, $a1, (0x5000510 & 0xFFFF)
    /* BEDF0 002BE1F0 8C440014 */  lw         $a0, 0x14($v0)
    /* BEDF4 002BE1F4 8E020024 */  lw         $v0, 0x24($s0)
    /* BEDF8 002BE1F8 3C068000 */  lui        $a2, (0x80000000 >> 16)
    /* BEDFC 002BE1FC 0C0AFA08 */  jal        osEPiRawWriteIo
    /* BEE00 002BE200 00463025 */   or        $a2, $v0, $a2
  .L002BE204:
    /* BEE04 002BE204 27A50020 */  addiu      $a1, $sp, 0x20
    /* BEE08 002BE208 8E44000C */  lw         $a0, 0xC($s2)
    /* BEE0C 002BE20C 0C0B00E4 */  jal        osRecvMesg
    /* BEE10 002BE210 24060001 */   addiu     $a2, $zero, 0x1
    /* BEE14 002BE214 8FA20018 */  lw         $v0, 0x18($sp)
    /* BEE18 002BE218 8C500014 */  lw         $s0, 0x14($v0)
    /* BEE1C 002BE21C 9603001A */  lhu        $v1, 0x1A($s0)
    /* BEE20 002BE220 000310C0 */  sll        $v0, $v1, 3
    /* BEE24 002BE224 00431021 */  addu       $v0, $v0, $v1
    /* BEE28 002BE228 00021080 */  sll        $v0, $v0, 2
    /* BEE2C 002BE22C 02021021 */  addu       $v0, $s0, $v0
    /* BEE30 002BE230 2451002C */  addiu      $s1, $v0, 0x2C
    /* BEE34 002BE234 8E230000 */  lw         $v1, 0x0($s1)
    /* BEE38 002BE238 2402001D */  addiu      $v0, $zero, 0x1D
    /* BEE3C 002BE23C 14620027 */  bne        $v1, $v0, .L002BE2DC
    /* BEE40 002BE240 02002021 */   addu      $a0, $s0, $zero
    /* BEE44 002BE244 3C050500 */  lui        $a1, (0x5000510 >> 16)
    /* BEE48 002BE248 34A50510 */  ori        $a1, $a1, (0x5000510 & 0xFFFF)
    /* BEE4C 002BE24C 8E020024 */  lw         $v0, 0x24($s0)
    /* BEE50 002BE250 3C061000 */  lui        $a2, (0x10000000 >> 16)
    /* BEE54 002BE254 0C0AFA08 */  jal        osEPiRawWriteIo
    /* BEE58 002BE258 00463025 */   or        $a2, $v0, $a2
    /* BEE5C 002BE25C 3C050500 */  lui        $a1, (0x5000510 >> 16)
    /* BEE60 002BE260 8FA20018 */  lw         $v0, 0x18($sp)
    /* BEE64 002BE264 8E060024 */  lw         $a2, 0x24($s0)
    /* BEE68 002BE268 8C440014 */  lw         $a0, 0x14($v0)
    /* BEE6C 002BE26C 0C0AFA08 */  jal        osEPiRawWriteIo
    /* BEE70 002BE270 34A50510 */   ori       $a1, $a1, (0x5000510 & 0xFFFF)
    /* BEE74 002BE274 3C050500 */  lui        $a1, (0x5000508 >> 16)
    /* BEE78 002BE278 8FA20018 */  lw         $v0, 0x18($sp)
    /* BEE7C 002BE27C 34A50508 */  ori        $a1, $a1, (0x5000508 & 0xFFFF)
    /* BEE80 002BE280 8C440014 */  lw         $a0, 0x14($v0)
    /* BEE84 002BE284 0C0AF9A0 */  jal        osEPiRawReadIo
    /* BEE88 002BE288 27A60024 */   addiu     $a2, $sp, 0x24
    /* BEE8C 002BE28C 8FA20024 */  lw         $v0, 0x24($sp)
    /* BEE90 002BE290 3C030200 */  lui        $v1, (0x2000000 >> 16)
    /* BEE94 002BE294 00431024 */  and        $v0, $v0, $v1
    /* BEE98 002BE298 10400008 */  beqz       $v0, .L002BE2BC
    /* BEE9C 002BE29C 3C050500 */   lui       $a1, (0x5000510 >> 16)
    /* BEEA0 002BE2A0 8FA20018 */  lw         $v0, 0x18($sp)
    /* BEEA4 002BE2A4 34A50510 */  ori        $a1, $a1, (0x5000510 & 0xFFFF)
    /* BEEA8 002BE2A8 8C440014 */  lw         $a0, 0x14($v0)
    /* BEEAC 002BE2AC 8E020024 */  lw         $v0, 0x24($s0)
    /* BEEB0 002BE2B0 3C060100 */  lui        $a2, (0x1000000 >> 16)
    /* BEEB4 002BE2B4 0C0AFA08 */  jal        osEPiRawWriteIo
    /* BEEB8 002BE2B8 00463025 */   or        $a2, $v0, $a2
  .L002BE2BC:
    /* BEEBC 002BE2BC 3C03A460 */  lui        $v1, %hi(PI_STATUS_REG)
    /* BEEC0 002BE2C0 34630010 */  ori        $v1, $v1, %lo(PI_STATUS_REG)
    /* BEEC4 002BE2C4 3C040010 */  lui        $a0, (0x100C01 >> 16)
    /* BEEC8 002BE2C8 24020004 */  addiu      $v0, $zero, 0x4
    /* BEECC 002BE2CC AE220000 */  sw         $v0, 0x0($s1)
    /* BEED0 002BE2D0 AC740000 */  sw         $s4, 0x0($v1)
    /* BEED4 002BE2D4 0C0B01A8 */  jal        func_002C06A0
    /* BEED8 002BE2D8 34840C01 */   ori       $a0, $a0, (0x100C01 & 0xFFFF)
  .L002BE2DC:
    /* BEEDC 002BE2DC 8FA50018 */  lw         $a1, 0x18($sp)
    /* BEEE0 002BE2E0 8CA40004 */  lw         $a0, 0x4($a1)
    /* BEEE4 002BE2E4 0C0B0144 */  jal        osSendMesg
    /* BEEE8 002BE2E8 00003021 */   addu      $a2, $zero, $zero
    /* BEEEC 002BE2EC 16750006 */  bne        $s3, $s5, .L002BE308
    /* BEEF0 002BE2F0 00002821 */   addu      $a1, $zero, $zero
    /* BEEF4 002BE2F4 8FA20018 */  lw         $v0, 0x18($sp)
    /* BEEF8 002BE2F8 8C420014 */  lw         $v0, 0x14($v0)
    /* BEEFC 002BE2FC 8C42002C */  lw         $v0, 0x2C($v0)
    /* BEF00 002BE300 1040FFC0 */  beqz       $v0, .L002BE204
    /* BEF04 002BE304 00009821 */   addu      $s3, $zero, $zero
  .L002BE308:
    /* BEF08 002BE308 8E440010 */  lw         $a0, 0x10($s2)
    /* BEF0C 002BE30C 0C0B0144 */  jal        osSendMesg
    /* BEF10 002BE310 00A03021 */   addu      $a2, $a1, $zero
    /* BEF14 002BE314 8FA20018 */  lw         $v0, 0x18($sp)
    /* BEF18 002BE318 8C420014 */  lw         $v0, 0x14($v0)
    /* BEF1C 002BE31C 9442001A */  lhu        $v0, 0x1A($v0)
    /* BEF20 002BE320 1455FF84 */  bne        $v0, $s5, .L002BE134
    /* BEF24 002BE324 27A50018 */   addiu     $a1, $sp, 0x18
    /* BEF28 002BE328 0C0B0344 */  jal        func_002C0D10
    /* BEF2C 002BE32C 00000000 */   nop
    /* BEF30 002BE330 080AF84D */  j          .L002BE134
    /* BEF34 002BE334 27A50018 */   addiu     $a1, $sp, 0x18
  .L002BE338:
    /* BEF38 002BE338 8FA20018 */  lw         $v0, 0x18($sp)
  .L002BE33C:
    /* BEF3C 002BE33C 94420000 */  lhu        $v0, 0x0($v0)
    /* BEF40 002BE340 2443FFF6 */  addiu      $v1, $v0, -0xA
    /* BEF44 002BE344 2C620007 */  sltiu      $v0, $v1, 0x7
    /* BEF48 002BE348 10400042 */  beqz       $v0, .L002BE454
    /* BEF4C 002BE34C 00031080 */   sll       $v0, $v1, 2
    /* BEF50 002BE350 3C01800D */  lui        $at, %hi(jtbl_800CCB80)
    /* BEF54 002BE354 00220821 */  addu       $at, $at, $v0
    /* BEF58 002BE358 8C22CB80 */  lw         $v0, %lo(jtbl_800CCB80)($at)
    /* BEF5C 002BE35C 00400008 */  jr         $v0
    /* BEF60 002BE360 00000000 */   nop
.L002BE364:
    /* BEF64 002BE364 27A5001C */  addiu      $a1, $sp, 0x1C
    /* BEF68 002BE368 8E440010 */  lw         $a0, 0x10($s2)
    /* BEF6C 002BE36C 0C0B00E4 */  jal        osRecvMesg
    /* BEF70 002BE370 24060001 */   addiu     $a2, $zero, 0x1
    /* BEF74 002BE374 8FA20018 */  lw         $v0, 0x18($sp)
    /* BEF78 002BE378 8C45000C */  lw         $a1, 0xC($v0)
    /* BEF7C 002BE37C 8C460008 */  lw         $a2, 0x8($v0)
    /* BEF80 002BE380 8C470010 */  lw         $a3, 0x10($v0)
    /* BEF84 002BE384 8E420014 */  lw         $v0, 0x14($s2)
    /* BEF88 002BE388 0040F809 */  jalr       $v0
    /* BEF8C 002BE38C 00002021 */   addu      $a0, $zero, $zero
    /* BEF90 002BE390 080AF916 */  j          .L002BE458
    /* BEF94 002BE394 00000000 */   nop
.L002BE398:
    /* BEF98 002BE398 27A5001C */  addiu      $a1, $sp, 0x1C
    /* BEF9C 002BE39C 8E440010 */  lw         $a0, 0x10($s2)
    /* BEFA0 002BE3A0 0C0B00E4 */  jal        osRecvMesg
    /* BEFA4 002BE3A4 24060001 */   addiu     $a2, $zero, 0x1
    /* BEFA8 002BE3A8 8FA20018 */  lw         $v0, 0x18($sp)
    /* BEFAC 002BE3AC 8C45000C */  lw         $a1, 0xC($v0)
    /* BEFB0 002BE3B0 8C460008 */  lw         $a2, 0x8($v0)
    /* BEFB4 002BE3B4 8C470010 */  lw         $a3, 0x10($v0)
    /* BEFB8 002BE3B8 8E420014 */  lw         $v0, 0x14($s2)
    /* BEFBC 002BE3BC 0040F809 */  jalr       $v0
    /* BEFC0 002BE3C0 24040001 */   addiu     $a0, $zero, 0x1
    /* BEFC4 002BE3C4 080AF916 */  j          .L002BE458
    /* BEFC8 002BE3C8 00000000 */   nop
.L002BE3CC:
    /* BEFCC 002BE3CC 27A5001C */  addiu      $a1, $sp, 0x1C
    /* BEFD0 002BE3D0 8E440010 */  lw         $a0, 0x10($s2)
    /* BEFD4 002BE3D4 0C0B00E4 */  jal        osRecvMesg
    /* BEFD8 002BE3D8 24060001 */   addiu     $a2, $zero, 0x1
    /* BEFDC 002BE3DC 8FA20018 */  lw         $v0, 0x18($sp)
    /* BEFE0 002BE3E0 8C430010 */  lw         $v1, 0x10($v0)
    /* BEFE4 002BE3E4 AFA30010 */  sw         $v1, 0x10($sp)
    /* BEFE8 002BE3E8 8C440014 */  lw         $a0, 0x14($v0)
    /* BEFEC 002BE3EC 8C46000C */  lw         $a2, 0xC($v0)
    /* BEFF0 002BE3F0 8C470008 */  lw         $a3, 0x8($v0)
    /* BEFF4 002BE3F4 8E420018 */  lw         $v0, 0x18($s2)
    /* BEFF8 002BE3F8 0040F809 */  jalr       $v0
    /* BEFFC 002BE3FC 00002821 */   addu      $a1, $zero, $zero
    /* BF000 002BE400 080AF916 */  j          .L002BE458
    /* BF004 002BE404 00000000 */   nop
.L002BE408:
    /* BF008 002BE408 27A5001C */  addiu      $a1, $sp, 0x1C
    /* BF00C 002BE40C 8E440010 */  lw         $a0, 0x10($s2)
    /* BF010 002BE410 0C0B00E4 */  jal        osRecvMesg
    /* BF014 002BE414 24060001 */   addiu     $a2, $zero, 0x1
    /* BF018 002BE418 8FA20018 */  lw         $v0, 0x18($sp)
    /* BF01C 002BE41C 8C430010 */  lw         $v1, 0x10($v0)
    /* BF020 002BE420 AFA30010 */  sw         $v1, 0x10($sp)
    /* BF024 002BE424 8C440014 */  lw         $a0, 0x14($v0)
    /* BF028 002BE428 8C46000C */  lw         $a2, 0xC($v0)
    /* BF02C 002BE42C 8C470008 */  lw         $a3, 0x8($v0)
    /* BF030 002BE430 8E420018 */  lw         $v0, 0x18($s2)
    /* BF034 002BE434 0040F809 */  jalr       $v0
    /* BF038 002BE438 24050001 */   addiu     $a1, $zero, 0x1
    /* BF03C 002BE43C 080AF916 */  j          .L002BE458
    /* BF040 002BE440 00000000 */   nop
.L002BE444:
    /* BF044 002BE444 8FA50018 */  lw         $a1, 0x18($sp)
    /* BF048 002BE448 8CA40004 */  lw         $a0, 0x4($a1)
    /* BF04C 002BE44C 0C0B0144 */  jal        osSendMesg
    /* BF050 002BE450 00003021 */   addu      $a2, $zero, $zero
  .L002BE454:
.L002BE454:
    /* BF054 002BE454 2402FFFF */  addiu      $v0, $zero, -0x1
  .L002BE458:
    /* BF058 002BE458 1440FF36 */  bnez       $v0, .L002BE134
    /* BF05C 002BE45C 27A50018 */   addiu     $a1, $sp, 0x18
    /* BF060 002BE460 27A50020 */  addiu      $a1, $sp, 0x20
    /* BF064 002BE464 8E44000C */  lw         $a0, 0xC($s2)
    /* BF068 002BE468 0C0B00E4 */  jal        osRecvMesg
    /* BF06C 002BE46C 24060001 */   addiu     $a2, $zero, 0x1
    /* BF070 002BE470 8FA50018 */  lw         $a1, 0x18($sp)
    /* BF074 002BE474 8CA40004 */  lw         $a0, 0x4($a1)
    /* BF078 002BE478 0C0B0144 */  jal        osSendMesg
    /* BF07C 002BE47C 00003021 */   addu      $a2, $zero, $zero
    /* BF080 002BE480 00002821 */  addu       $a1, $zero, $zero
    /* BF084 002BE484 8E440010 */  lw         $a0, 0x10($s2)
    /* BF088 002BE488 0C0B0144 */  jal        osSendMesg
    /* BF08C 002BE48C 00A03021 */   addu      $a2, $a1, $zero
    /* BF090 002BE490 080AF84D */  j          .L002BE134
    /* BF094 002BE494 27A50018 */   addiu     $a1, $sp, 0x18
    /* BF098 002BE498 02202821 */  addu       $a1, $s1, $zero
    /* BF09C 002BE49C 3C068015 */  lui        $a2, (0x80150000 >> 16)
  alabel func_002BE4A0
    /* BF0A0 002BE4A0 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* BF0A4 002BE4A4 AFB00010 */  sw         $s0, 0x10($sp)
    /* BF0A8 002BE4A8 00808021 */  addu       $s0, $a0, $zero
    /* BF0AC 002BE4AC AFB10014 */  sw         $s1, 0x14($sp)
    /* BF0B0 002BE4B0 00A08821 */  addu       $s1, $a1, $zero
    /* BF0B4 002BE4B4 AFB3001C */  sw         $s3, 0x1C($sp)
    /* BF0B8 002BE4B8 00C09821 */  addu       $s3, $a2, $zero
    /* BF0BC 002BE4BC 00E02021 */  addu       $a0, $a3, $zero
    /* BF0C0 002BE4C0 3C02A460 */  lui        $v0, %hi(PI_STATUS_REG)
    /* BF0C4 002BE4C4 34420010 */  ori        $v0, $v0, %lo(PI_STATUS_REG)
    /* BF0C8 002BE4C8 AFBF0020 */  sw         $ra, 0x20($sp)
    /* BF0CC 002BE4CC AFB20018 */  sw         $s2, 0x18($sp)
    /* BF0D0 002BE4D0 8C420000 */  lw         $v0, 0x0($v0)
    /* BF0D4 002BE4D4 8FB20038 */  lw         $s2, 0x38($sp)
    /* BF0D8 002BE4D8 30420003 */  andi       $v0, $v0, 0x3
    /* BF0DC 002BE4DC 10400007 */  beqz       $v0, .L002BE4FC
    /* BF0E0 002BE4E0 00000000 */   nop
    /* BF0E4 002BE4E4 3C03A460 */  lui        $v1, %hi(PI_STATUS_REG)
    /* BF0E8 002BE4E8 34630010 */  ori        $v1, $v1, %lo(PI_STATUS_REG)
  .L002BE4EC:
    /* BF0EC 002BE4EC 8C620000 */  lw         $v0, 0x0($v1)
    /* BF0F0 002BE4F0 30420003 */  andi       $v0, $v0, 0x3
    /* BF0F4 002BE4F4 1440FFFD */  bnez       $v0, .L002BE4EC
    /* BF0F8 002BE4F8 00000000 */   nop
  .L002BE4FC:
    /* BF0FC 002BE4FC 92060009 */  lbu        $a2, 0x9($s0)
    /* BF100 002BE500 00061080 */  sll        $v0, $a2, 2
    /* BF104 002BE504 3C01800E */  lui        $at, %hi(__osCurrentHandle)
    /* BF108 002BE508 00220821 */  addu       $at, $at, $v0
    /* BF10C 002BE50C 8C2583B0 */  lw         $a1, %lo(__osCurrentHandle)($at)
    /* BF110 002BE510 10B00037 */  beq        $a1, $s0, .L002BE5F0
    /* BF114 002BE514 00000000 */   nop
    /* BF118 002BE518 14C00019 */  bnez       $a2, .L002BE580
    /* BF11C 002BE51C 00000000 */   nop
    /* BF120 002BE520 90A30005 */  lbu        $v1, 0x5($a1)
    /* BF124 002BE524 92020005 */  lbu        $v0, 0x5($s0)
    /* BF128 002BE528 10620003 */  beq        $v1, $v0, .L002BE538
    /* BF12C 002BE52C 3C03A460 */   lui       $v1, %hi(PI_BSD_DOM1_LAT_REG)
    /* BF130 002BE530 34630014 */  ori        $v1, $v1, %lo(PI_BSD_DOM1_LAT_REG)
    /* BF134 002BE534 AC620000 */  sw         $v0, 0x0($v1)
  .L002BE538:
    /* BF138 002BE538 90A30006 */  lbu        $v1, 0x6($a1)
    /* BF13C 002BE53C 92020006 */  lbu        $v0, 0x6($s0)
    /* BF140 002BE540 10620003 */  beq        $v1, $v0, .L002BE550
    /* BF144 002BE544 3C03A460 */   lui       $v1, %hi(PI_BSD_DOM1_PGS_REG)
    /* BF148 002BE548 3463001C */  ori        $v1, $v1, %lo(PI_BSD_DOM1_PGS_REG)
    /* BF14C 002BE54C AC620000 */  sw         $v0, 0x0($v1)
  .L002BE550:
    /* BF150 002BE550 90A30007 */  lbu        $v1, 0x7($a1)
    /* BF154 002BE554 92020007 */  lbu        $v0, 0x7($s0)
    /* BF158 002BE558 10620003 */  beq        $v1, $v0, .L002BE568
    /* BF15C 002BE55C 3C03A460 */   lui       $v1, %hi(PI_BSD_DOM1_RLS_REG)
    /* BF160 002BE560 34630020 */  ori        $v1, $v1, %lo(PI_BSD_DOM1_RLS_REG)
    /* BF164 002BE564 AC620000 */  sw         $v0, 0x0($v1)
  .L002BE568:
    /* BF168 002BE568 90A30008 */  lbu        $v1, 0x8($a1)
    /* BF16C 002BE56C 92020008 */  lbu        $v0, 0x8($s0)
    /* BF170 002BE570 1062001B */  beq        $v1, $v0, .L002BE5E0
    /* BF174 002BE574 3C03A460 */   lui       $v1, %hi(PI_BSD_DOM1_PWD_REG)
    /* BF178 002BE578 080AF977 */  j          .L002BE5DC
    /* BF17C 002BE57C 34630018 */   ori       $v1, $v1, %lo(PI_BSD_DOM1_PWD_REG)
  .L002BE580:
    /* BF180 002BE580 90A30005 */  lbu        $v1, 0x5($a1)
    /* BF184 002BE584 92020005 */  lbu        $v0, 0x5($s0)
    /* BF188 002BE588 10620003 */  beq        $v1, $v0, .L002BE598
    /* BF18C 002BE58C 3C03A460 */   lui       $v1, %hi(PI_BSD_DOM2_LAT_REG)
    /* BF190 002BE590 34630024 */  ori        $v1, $v1, %lo(PI_BSD_DOM2_LAT_REG)
    /* BF194 002BE594 AC620000 */  sw         $v0, 0x0($v1)
  .L002BE598:
    /* BF198 002BE598 90A30006 */  lbu        $v1, 0x6($a1)
    /* BF19C 002BE59C 92020006 */  lbu        $v0, 0x6($s0)
    /* BF1A0 002BE5A0 10620003 */  beq        $v1, $v0, .L002BE5B0
    /* BF1A4 002BE5A4 3C03A460 */   lui       $v1, %hi(PI_BSD_DOM2_PGS_REG)
    /* BF1A8 002BE5A8 3463002C */  ori        $v1, $v1, %lo(PI_BSD_DOM2_PGS_REG)
    /* BF1AC 002BE5AC AC620000 */  sw         $v0, 0x0($v1)
  .L002BE5B0:
    /* BF1B0 002BE5B0 90A30007 */  lbu        $v1, 0x7($a1)
    /* BF1B4 002BE5B4 92020007 */  lbu        $v0, 0x7($s0)
    /* BF1B8 002BE5B8 10620003 */  beq        $v1, $v0, .L002BE5C8
    /* BF1BC 002BE5BC 3C03A460 */   lui       $v1, %hi(PI_BSD_DOM2_RLS_REG)
    /* BF1C0 002BE5C0 34630030 */  ori        $v1, $v1, %lo(PI_BSD_DOM2_RLS_REG)
    /* BF1C4 002BE5C4 AC620000 */  sw         $v0, 0x0($v1)
  .L002BE5C8:
    /* BF1C8 002BE5C8 90A30008 */  lbu        $v1, 0x8($a1)
    /* BF1CC 002BE5CC 92020008 */  lbu        $v0, 0x8($s0)
    /* BF1D0 002BE5D0 10620003 */  beq        $v1, $v0, .L002BE5E0
    /* BF1D4 002BE5D4 3C03A460 */   lui       $v1, %hi(PI_BSD_DOM2_LWD_REG)
    /* BF1D8 002BE5D8 34630028 */  ori        $v1, $v1, %lo(PI_BSD_DOM2_LWD_REG)
  .L002BE5DC:
    /* BF1DC 002BE5DC AC620000 */  sw         $v0, 0x0($v1)
  .L002BE5E0:
    /* BF1E0 002BE5E0 00061080 */  sll        $v0, $a2, 2
    /* BF1E4 002BE5E4 3C01800E */  lui        $at, %hi(__osCurrentHandle)
    /* BF1E8 002BE5E8 00220821 */  addu       $at, $at, $v0
    /* BF1EC 002BE5EC AC3083B0 */  sw         $s0, %lo(__osCurrentHandle)($at)
  .L002BE5F0:
    /* BF1F0 002BE5F0 0C0B032C */  jal        osVirtualToPhysical
    /* BF1F4 002BE5F4 00000000 */   nop
    /* BF1F8 002BE5F8 3C06A460 */  lui        $a2, %hi(PI_CART_ADDR_REG)
    /* BF1FC 002BE5FC 34C60004 */  ori        $a2, $a2, %lo(PI_CART_ADDR_REG)
    /* BF200 002BE600 3C051FFF */  lui        $a1, (0x1FFFFFFF >> 16)
    /* BF204 002BE604 34A5FFFF */  ori        $a1, $a1, (0x1FFFFFFF & 0xFFFF)
    /* BF208 002BE608 8E03000C */  lw         $v1, 0xC($s0)
    /* BF20C 002BE60C 3C04A460 */  lui        $a0, %hi(PI_DRAM_ADDR_REG)
    /* BF210 002BE610 AC820000 */  sw         $v0, %lo(PI_DRAM_ADDR_REG)($a0)
    /* BF214 002BE614 00731825 */  or         $v1, $v1, $s3
    /* BF218 002BE618 00651824 */  and        $v1, $v1, $a1
    /* BF21C 002BE61C ACC30000 */  sw         $v1, 0x0($a2)
    /* BF220 002BE620 52200006 */  beql       $s1, $zero, .L002BE63C
    /* BF224 002BE624 3C03A460 */   lui       $v1, %hi(PI_WR_LEN_REG)
    /* BF228 002BE628 24020001 */  addiu      $v0, $zero, 0x1
    /* BF22C 002BE62C 12220005 */  beq        $s1, $v0, .L002BE644
    /* BF230 002BE630 2402FFFF */   addiu     $v0, $zero, -0x1
    /* BF234 002BE634 080AF996 */  j          .L002BE658
    /* BF238 002BE638 00000000 */   nop
  .L002BE63C:
    /* BF23C 002BE63C 080AF993 */  j          .L002BE64C
    /* BF240 002BE640 3463000C */   ori       $v1, $v1, %lo(PI_WR_LEN_REG)
  .L002BE644:
    /* BF244 002BE644 3C03A460 */  lui        $v1, %hi(PI_RD_LEN_REG)
    /* BF248 002BE648 34630008 */  ori        $v1, $v1, %lo(PI_RD_LEN_REG)
  .L002BE64C:
    /* BF24C 002BE64C 2642FFFF */  addiu      $v0, $s2, -0x1
    /* BF250 002BE650 AC620000 */  sw         $v0, 0x0($v1)
    /* BF254 002BE654 00001021 */  addu       $v0, $zero, $zero
  .L002BE658:
    /* BF258 002BE658 8FBF0020 */  lw         $ra, 0x20($sp)
    /* BF25C 002BE65C 8FB3001C */  lw         $s3, 0x1C($sp)
    /* BF260 002BE660 8FB20018 */  lw         $s2, 0x18($sp)
    /* BF264 002BE664 8FB10014 */  lw         $s1, 0x14($sp)
    /* BF268 002BE668 8FB00010 */  lw         $s0, 0x10($sp)
    /* BF26C 002BE66C 03E00008 */  jr         $ra
    /* BF270 002BE670 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002BE100

.section .rodata
glabel jtbl_800CCB80
    .word .L002BE444
    .word .L002BE364
    .word .L002BE398
    .word .L002BE454
    .word .L002BE454
    .word .L002BE3CC
    .word .L002BE408
