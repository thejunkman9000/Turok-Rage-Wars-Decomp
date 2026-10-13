.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xB9C10-0xB9FB0 (VRAM 0x002B9010) */
.globl __osDevMgrMain
__osDevMgrMain:
    /* B9C10 002B9010 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* B9C14 002B9014 AFB20030 */  sw         $s2, 0x30($sp)
    /* B9C18 002B9018 00809021 */  addu       $s2, $a0, $zero
    /* B9C1C 002B901C AFB40038 */  sw         $s4, 0x38($sp)
    /* B9C20 002B9020 24140002 */  addiu      $s4, $zero, 0x2
    /* B9C24 002B9024 AFB5003C */  sw         $s5, 0x3C($sp)
    /* B9C28 002B9028 24150001 */  addiu      $s5, $zero, 0x1
    /* B9C2C 002B902C AFBF0040 */  sw         $ra, 0x40($sp)
    /* B9C30 002B9030 AFB30034 */  sw         $s3, 0x34($sp)
    /* B9C34 002B9034 AFB1002C */  sw         $s1, 0x2C($sp)
    /* B9C38 002B9038 AFB00028 */  sw         $s0, 0x28($sp)
    /* B9C3C 002B903C AFA00018 */  sw         $zero, 0x18($sp)
    /* B9C40 002B9040 27A50018 */  addiu      $a1, $sp, 0x18
.Lauto_002B9044:
    /* B9C44 002B9044 8E440008 */  lw         $a0, 0x8($s2)
    /* B9C48 002B9048 0C0AECA8 */  jal        osRecvMesg
    /* B9C4C 002B904C 24060001 */  addiu     $a2, $zero, 0x1
    /* B9C50 002B9050 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9C54 002B9054 8C500014 */  lw         $s0, 0x14($v0)
    /* B9C58 002B9058 1200007C */  .word 0x1200007C
    /* B9C5C 002B905C 00000000 */  nop
    /* B9C60 002B9060 92020004 */  lbu        $v0, 0x4($s0)
    /* B9C64 002B9064 14540078 */  .word 0x14540078
    /* B9C68 002B9068 00000000 */  nop
    /* B9C6C 002B906C 8E020014 */  lw         $v0, 0x14($s0)
    /* B9C70 002B9070 2C420002 */  sltiu      $v0, $v0, 0x2
    /* B9C74 002B9074 10400074 */  .word 0x10400074
    /* B9C78 002B9078 26040014 */  addiu     $a0, $s0, 0x14
    /* B9C7C 002B907C 9603001A */  lhu        $v1, 0x1A($s0)
    /* B9C80 002B9080 2402FFFF */  addiu      $v0, $zero, -0x1
    /* B9C84 002B9084 AE02001C */  sw         $v0, 0x1C($s0)
    /* B9C88 002B9088 000310C0 */  sll        $v0, $v1, 3
    /* B9C8C 002B908C 00431021 */  addu       $v0, $v0, $v1
    /* B9C90 002B9090 00021080 */  sll        $v0, $v0, 2
    /* B9C94 002B9094 24420018 */  addiu      $v0, $v0, 0x18
    /* B9C98 002B9098 00828821 */  addu       $s1, $a0, $v0
    /* B9C9C 002B909C 96030018 */  lhu        $v1, 0x18($s0)
    /* B9CA0 002B90A0 24020003 */  addiu      $v0, $zero, 0x3
    /* B9CA4 002B90A4 10620005 */  .word 0x10620005
    /* B9CA8 002B90A8 00000000 */  nop
    /* B9CAC 002B90AC 8E220004 */  lw         $v0, 0x4($s1)
    /* B9CB0 002B90B0 8E23000C */  lw         $v1, 0xC($s1)
    /* B9CB4 002B90B4 00431023 */  subu       $v0, $v0, $v1
    /* B9CB8 002B90B8 AE220004 */  sw         $v0, 0x4($s1)
.Lauto_002B90BC:
    /* B9CBC 002B90BC 96020018 */  lhu        $v0, 0x18($s0)
    /* B9CC0 002B90C0 14540005 */  .word 0x14540005
    /* B9CC4 002B90C4 00009821 */  addu      $s3, $zero, $zero
    /* B9CC8 002B90C8 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9CCC 002B90CC 8C420014 */  lw         $v0, 0x14($v0)
    /* B9CD0 002B90D0 8C420014 */  lw         $v0, 0x14($v0)
    /* B9CD4 002B90D4 2C530001 */  sltiu      $s3, $v0, 0x1
.Lauto_002B90D8:
    /* B9CD8 002B90D8 27A5001C */  addiu      $a1, $sp, 0x1C
    /* B9CDC 002B90DC 8E440010 */  lw         $a0, 0x10($s2)
    /* B9CE0 002B90E0 0C0AECA8 */  jal        osRecvMesg
    /* B9CE4 002B90E4 24060001 */  addiu     $a2, $zero, 0x1
    /* B9CE8 002B90E8 3C040010 */  lui        $a0, (0x100401 >> 16)
    /* B9CEC 002B90EC 0C0AECF4 */  jal        __osResetGlobalIntMask
    /* B9CF0 002B90F0 34840401 */  ori       $a0, $a0, (0x100401 & 0xFFFF)
    /* B9CF4 002B90F4 3C050500 */  lui        $a1, (0x5000510 >> 16)
    /* B9CF8 002B90F8 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9CFC 002B90FC 34A50510 */  ori        $a1, $a1, (0x5000510 & 0xFFFF)
    /* B9D00 002B9100 8C440014 */  lw         $a0, 0x14($v0)
    /* B9D04 002B9104 8E020024 */  lw         $v0, 0x24($s0)
    /* B9D08 002B9108 3C068000 */  lui        $a2, (0x80000000 >> 16)
    /* B9D0C 002B910C 0C0AE5CC */  jal        osEPiRawWriteIo
    /* B9D10 002B9110 00463025 */  or        $a2, $v0, $a2
.Lauto_002B9114:
    /* B9D14 002B9114 27A50020 */  addiu      $a1, $sp, 0x20
    /* B9D18 002B9118 8E44000C */  lw         $a0, 0xC($s2)
    /* B9D1C 002B911C 0C0AECA8 */  jal        osRecvMesg
    /* B9D20 002B9120 24060001 */  addiu     $a2, $zero, 0x1
    /* B9D24 002B9124 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9D28 002B9128 8C500014 */  lw         $s0, 0x14($v0)
    /* B9D2C 002B912C 9603001A */  lhu        $v1, 0x1A($s0)
    /* B9D30 002B9130 000310C0 */  sll        $v0, $v1, 3
    /* B9D34 002B9134 00431021 */  addu       $v0, $v0, $v1
    /* B9D38 002B9138 00021080 */  sll        $v0, $v0, 2
    /* B9D3C 002B913C 02021021 */  addu       $v0, $s0, $v0
    /* B9D40 002B9140 2451002C */  addiu      $s1, $v0, 0x2C
    /* B9D44 002B9144 8E230000 */  lw         $v1, 0x0($s1)
    /* B9D48 002B9148 2402001D */  addiu      $v0, $zero, 0x1D
    /* B9D4C 002B914C 14620027 */  .word 0x14620027
    /* B9D50 002B9150 02002021 */  addu      $a0, $s0, $zero
    /* B9D54 002B9154 3C050500 */  lui        $a1, (0x5000510 >> 16)
    /* B9D58 002B9158 34A50510 */  ori        $a1, $a1, (0x5000510 & 0xFFFF)
    /* B9D5C 002B915C 8E020024 */  lw         $v0, 0x24($s0)
    /* B9D60 002B9160 3C061000 */  lui        $a2, (0x10000000 >> 16)
    /* B9D64 002B9164 0C0AE5CC */  jal        osEPiRawWriteIo
    /* B9D68 002B9168 00463025 */  or        $a2, $v0, $a2
    /* B9D6C 002B916C 3C050500 */  lui        $a1, (0x5000510 >> 16)
    /* B9D70 002B9170 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9D74 002B9174 8E060024 */  lw         $a2, 0x24($s0)
    /* B9D78 002B9178 8C440014 */  lw         $a0, 0x14($v0)
    /* B9D7C 002B917C 0C0AE5CC */  jal        osEPiRawWriteIo
    /* B9D80 002B9180 34A50510 */  ori       $a1, $a1, (0x5000510 & 0xFFFF)
    /* B9D84 002B9184 3C050500 */  lui        $a1, (0x5000508 >> 16)
    /* B9D88 002B9188 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9D8C 002B918C 34A50508 */  ori        $a1, $a1, (0x5000508 & 0xFFFF)
    /* B9D90 002B9190 8C440014 */  lw         $a0, 0x14($v0)
    /* B9D94 002B9194 0C0AE564 */  jal        osEPiRawReadIo
    /* B9D98 002B9198 27A60024 */  addiu     $a2, $sp, 0x24
    /* B9D9C 002B919C 8FA20024 */  lw         $v0, 0x24($sp)
    /* B9DA0 002B91A0 3C030200 */  lui        $v1, (0x2000000 >> 16)
    /* B9DA4 002B91A4 00431024 */  and        $v0, $v0, $v1
    /* B9DA8 002B91A8 10400008 */  .word 0x10400008
    /* B9DAC 002B91AC 3C050500 */  lui       $a1, (0x5000510 >> 16)
    /* B9DB0 002B91B0 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9DB4 002B91B4 34A50510 */  ori        $a1, $a1, (0x5000510 & 0xFFFF)
    /* B9DB8 002B91B8 8C440014 */  lw         $a0, 0x14($v0)
    /* B9DBC 002B91BC 8E020024 */  lw         $v0, 0x24($s0)
    /* B9DC0 002B91C0 3C060100 */  lui        $a2, (0x1000000 >> 16)
    /* B9DC4 002B91C4 0C0AE5CC */  jal        osEPiRawWriteIo
    /* B9DC8 002B91C8 00463025 */  or        $a2, $v0, $a2
.Lauto_002B91CC:
    /* B9DCC 002B91CC 3C03A460 */  lui        $v1, %hi(PI_STATUS_REG)
    /* B9DD0 002B91D0 34630010 */  ori        $v1, $v1, %lo(PI_STATUS_REG)
    /* B9DD4 002B91D4 3C040010 */  lui        $a0, (0x100C01 >> 16)
    /* B9DD8 002B91D8 24020004 */  addiu      $v0, $zero, 0x4
    /* B9DDC 002B91DC AE220000 */  sw         $v0, 0x0($s1)
    /* B9DE0 002B91E0 AC740000 */  sw         $s4, 0x0($v1)
    /* B9DE4 002B91E4 0C0AED6C */  jal        __osSetGlobalIntMask
    /* B9DE8 002B91E8 34840C01 */  ori       $a0, $a0, (0x100C01 & 0xFFFF)
.Lauto_002B91EC:
    /* B9DEC 002B91EC 8FA50018 */  lw         $a1, 0x18($sp)
    /* B9DF0 002B91F0 8CA40004 */  lw         $a0, 0x4($a1)
    /* B9DF4 002B91F4 0C0AED08 */  jal        osSendMesg
    /* B9DF8 002B91F8 00003021 */  addu      $a2, $zero, $zero
    /* B9DFC 002B91FC 16750006 */  .word 0x16750006
    /* B9E00 002B9200 00002821 */  addu      $a1, $zero, $zero
    /* B9E04 002B9204 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9E08 002B9208 8C420014 */  lw         $v0, 0x14($v0)
    /* B9E0C 002B920C 8C42002C */  lw         $v0, 0x2C($v0)
    /* B9E10 002B9210 1040FFC0 */  .word 0x1040FFC0
    /* B9E14 002B9214 00009821 */  addu      $s3, $zero, $zero
.Lauto_002B9218:
    /* B9E18 002B9218 8E440010 */  lw         $a0, 0x10($s2)
    /* B9E1C 002B921C 0C0AED08 */  jal        osSendMesg
    /* B9E20 002B9220 00A03021 */  addu      $a2, $a1, $zero
    /* B9E24 002B9224 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9E28 002B9228 8C420014 */  lw         $v0, 0x14($v0)
    /* B9E2C 002B922C 9442001A */  lhu        $v0, 0x1A($v0)
    /* B9E30 002B9230 1455FF84 */  .word 0x1455FF84
    /* B9E34 002B9234 27A50018 */  addiu     $a1, $sp, 0x18
    /* B9E38 002B9238 0C0AEF08 */  jal        osYieldThread
    /* B9E3C 002B923C 00000000 */  nop
    /* B9E40 002B9240 080AE411 */  .word 0x080AE411
    /* B9E44 002B9244 27A50018 */  addiu     $a1, $sp, 0x18
.Lauto_002B9248:
    /* B9E48 002B9248 8FA20018 */  lw         $v0, 0x18($sp)
.Lauto_002B924C:
    /* B9E4C 002B924C 94420000 */  lhu        $v0, 0x0($v0)
    /* B9E50 002B9250 2443FFF6 */  addiu      $v1, $v0, -0xA
    /* B9E54 002B9254 2C620007 */  sltiu      $v0, $v1, 0x7
    /* B9E58 002B9258 10400042 */  .word 0x10400042
    /* B9E5C 002B925C 00031080 */  sll       $v0, $v1, 2
    /* B9E60 002B9260 3C01800C */  lui        $at, %hi(jtbl_auto_800C7930)
    /* B9E64 002B9264 00220821 */  addu       $at, $at, $v0
    /* B9E68 002B9268 8C227930 */  lw         $v0, %lo(jtbl_auto_800C7930)($at)
    /* B9E6C 002B926C 00400008 */  jr         $v0
    /* B9E70 002B9270 00000000 */  nop
    /* B9E74 002B9274 27A5001C */  addiu      $a1, $sp, 0x1C
    /* B9E78 002B9278 8E440010 */  lw         $a0, 0x10($s2)
    /* B9E7C 002B927C 0C0AECA8 */  jal        osRecvMesg
    /* B9E80 002B9280 24060001 */  addiu     $a2, $zero, 0x1
    /* B9E84 002B9284 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9E88 002B9288 8C45000C */  lw         $a1, 0xC($v0)
    /* B9E8C 002B928C 8C460008 */  lw         $a2, 0x8($v0)
    /* B9E90 002B9290 8C470010 */  lw         $a3, 0x10($v0)
    /* B9E94 002B9294 8E420014 */  lw         $v0, 0x14($s2)
    /* B9E98 002B9298 0040F809 */  jalr       $v0
    /* B9E9C 002B929C 00002021 */  addu      $a0, $zero, $zero
    /* B9EA0 002B92A0 080AE4DA */  .word 0x080AE4DA
    /* B9EA4 002B92A4 00000000 */  nop
    /* B9EA8 002B92A8 27A5001C */  addiu      $a1, $sp, 0x1C
    /* B9EAC 002B92AC 8E440010 */  lw         $a0, 0x10($s2)
    /* B9EB0 002B92B0 0C0AECA8 */  jal        osRecvMesg
    /* B9EB4 002B92B4 24060001 */  addiu     $a2, $zero, 0x1
    /* B9EB8 002B92B8 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9EBC 002B92BC 8C45000C */  lw         $a1, 0xC($v0)
    /* B9EC0 002B92C0 8C460008 */  lw         $a2, 0x8($v0)
    /* B9EC4 002B92C4 8C470010 */  lw         $a3, 0x10($v0)
    /* B9EC8 002B92C8 8E420014 */  lw         $v0, 0x14($s2)
    /* B9ECC 002B92CC 0040F809 */  jalr       $v0
    /* B9ED0 002B92D0 24040001 */  addiu     $a0, $zero, 0x1
    /* B9ED4 002B92D4 080AE4DA */  .word 0x080AE4DA
    /* B9ED8 002B92D8 00000000 */  nop
    /* B9EDC 002B92DC 27A5001C */  addiu      $a1, $sp, 0x1C
    /* B9EE0 002B92E0 8E440010 */  lw         $a0, 0x10($s2)
    /* B9EE4 002B92E4 0C0AECA8 */  jal        osRecvMesg
    /* B9EE8 002B92E8 24060001 */  addiu     $a2, $zero, 0x1
    /* B9EEC 002B92EC 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9EF0 002B92F0 8C430010 */  lw         $v1, 0x10($v0)
    /* B9EF4 002B92F4 AFA30010 */  sw         $v1, 0x10($sp)
    /* B9EF8 002B92F8 8C440014 */  lw         $a0, 0x14($v0)
    /* B9EFC 002B92FC 8C46000C */  lw         $a2, 0xC($v0)
    /* B9F00 002B9300 8C470008 */  lw         $a3, 0x8($v0)
    /* B9F04 002B9304 8E420018 */  lw         $v0, 0x18($s2)
    /* B9F08 002B9308 0040F809 */  jalr       $v0
    /* B9F0C 002B930C 00002821 */  addu      $a1, $zero, $zero
    /* B9F10 002B9310 080AE4DA */  .word 0x080AE4DA
    /* B9F14 002B9314 00000000 */  nop
    /* B9F18 002B9318 27A5001C */  addiu      $a1, $sp, 0x1C
    /* B9F1C 002B931C 8E440010 */  lw         $a0, 0x10($s2)
    /* B9F20 002B9320 0C0AECA8 */  jal        osRecvMesg
    /* B9F24 002B9324 24060001 */  addiu     $a2, $zero, 0x1
    /* B9F28 002B9328 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9F2C 002B932C 8C430010 */  lw         $v1, 0x10($v0)
    /* B9F30 002B9330 AFA30010 */  sw         $v1, 0x10($sp)
    /* B9F34 002B9334 8C440014 */  lw         $a0, 0x14($v0)
    /* B9F38 002B9338 8C46000C */  lw         $a2, 0xC($v0)
    /* B9F3C 002B933C 8C470008 */  lw         $a3, 0x8($v0)
    /* B9F40 002B9340 8E420018 */  lw         $v0, 0x18($s2)
    /* B9F44 002B9344 0040F809 */  jalr       $v0
    /* B9F48 002B9348 24050001 */  addiu     $a1, $zero, 0x1
    /* B9F4C 002B934C 080AE4DA */  .word 0x080AE4DA
    /* B9F50 002B9350 00000000 */  nop
    /* B9F54 002B9354 8FA50018 */  lw         $a1, 0x18($sp)
    /* B9F58 002B9358 8CA40004 */  lw         $a0, 0x4($a1)
    /* B9F5C 002B935C 0C0AED08 */  jal        osSendMesg
    /* B9F60 002B9360 00003021 */  addu      $a2, $zero, $zero
.Lauto_002B9364:
    /* B9F64 002B9364 2402FFFF */  addiu      $v0, $zero, -0x1
.Lauto_002B9368:
    /* B9F68 002B9368 1440FF36 */  .word 0x1440FF36
    /* B9F6C 002B936C 27A50018 */  addiu     $a1, $sp, 0x18
    /* B9F70 002B9370 27A50020 */  addiu      $a1, $sp, 0x20
    /* B9F74 002B9374 8E44000C */  lw         $a0, 0xC($s2)
    /* B9F78 002B9378 0C0AECA8 */  jal        osRecvMesg
    /* B9F7C 002B937C 24060001 */  addiu     $a2, $zero, 0x1
    /* B9F80 002B9380 8FA50018 */  lw         $a1, 0x18($sp)
    /* B9F84 002B9384 8CA40004 */  lw         $a0, 0x4($a1)
    /* B9F88 002B9388 0C0AED08 */  jal        osSendMesg
    /* B9F8C 002B938C 00003021 */  addu      $a2, $zero, $zero
    /* B9F90 002B9390 00002821 */  addu       $a1, $zero, $zero
    /* B9F94 002B9394 8E440010 */  lw         $a0, 0x10($s2)
    /* B9F98 002B9398 0C0AED08 */  jal        osSendMesg
    /* B9F9C 002B939C 00A03021 */  addu      $a2, $a1, $zero
    /* B9FA0 002B93A0 080AE411 */  .word 0x080AE411
    /* B9FA4 002B93A4 27A50018 */  addiu     $a1, $sp, 0x18
    /* B9FA8 002B93A8 00808021 */  addu       $s0, $a0, $zero
    /* B9FAC 002B93AC AFB10014 */  sw         $s1, 0x14($sp)
