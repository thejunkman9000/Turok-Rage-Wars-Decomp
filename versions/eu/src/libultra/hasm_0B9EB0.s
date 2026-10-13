.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xB9EB0-0xBA250 (VRAM 0x002B92B0) */
.globl __osDevMgrMain
__osDevMgrMain:
    /* B9EB0 002B92B0 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* B9EB4 002B92B4 AFB20030 */  sw         $s2, 0x30($sp)
    /* B9EB8 002B92B8 00809021 */  addu       $s2, $a0, $zero
    /* B9EBC 002B92BC AFB40038 */  sw         $s4, 0x38($sp)
    /* B9EC0 002B92C0 24140002 */  addiu      $s4, $zero, 0x2
    /* B9EC4 002B92C4 AFB5003C */  sw         $s5, 0x3C($sp)
    /* B9EC8 002B92C8 24150001 */  addiu      $s5, $zero, 0x1
    /* B9ECC 002B92CC AFBF0040 */  sw         $ra, 0x40($sp)
    /* B9ED0 002B92D0 AFB30034 */  sw         $s3, 0x34($sp)
    /* B9ED4 002B92D4 AFB1002C */  sw         $s1, 0x2C($sp)
    /* B9ED8 002B92D8 AFB00028 */  sw         $s0, 0x28($sp)
    /* B9EDC 002B92DC AFA00018 */  sw         $zero, 0x18($sp)
    /* B9EE0 002B92E0 27A50018 */  addiu      $a1, $sp, 0x18
.Lauto_002B92E4:
    /* B9EE4 002B92E4 8E440008 */  lw         $a0, 0x8($s2)
    /* B9EE8 002B92E8 0C0AED50 */  jal        osRecvMesg
    /* B9EEC 002B92EC 24060001 */  addiu     $a2, $zero, 0x1
    /* B9EF0 002B92F0 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9EF4 002B92F4 8C500014 */  lw         $s0, 0x14($v0)
    /* B9EF8 002B92F8 1200007C */  .word 0x1200007C
    /* B9EFC 002B92FC 00000000 */  nop
    /* B9F00 002B9300 92020004 */  lbu        $v0, 0x4($s0)
    /* B9F04 002B9304 14540078 */  .word 0x14540078
    /* B9F08 002B9308 00000000 */  nop
    /* B9F0C 002B930C 8E020014 */  lw         $v0, 0x14($s0)
    /* B9F10 002B9310 2C420002 */  sltiu      $v0, $v0, 0x2
    /* B9F14 002B9314 10400074 */  .word 0x10400074
    /* B9F18 002B9318 26040014 */  addiu     $a0, $s0, 0x14
    /* B9F1C 002B931C 9603001A */  lhu        $v1, 0x1A($s0)
    /* B9F20 002B9320 2402FFFF */  addiu      $v0, $zero, -0x1
    /* B9F24 002B9324 AE02001C */  sw         $v0, 0x1C($s0)
    /* B9F28 002B9328 000310C0 */  sll        $v0, $v1, 3
    /* B9F2C 002B932C 00431021 */  addu       $v0, $v0, $v1
    /* B9F30 002B9330 00021080 */  sll        $v0, $v0, 2
    /* B9F34 002B9334 24420018 */  addiu      $v0, $v0, 0x18
    /* B9F38 002B9338 00828821 */  addu       $s1, $a0, $v0
    /* B9F3C 002B933C 96030018 */  lhu        $v1, 0x18($s0)
    /* B9F40 002B9340 24020003 */  addiu      $v0, $zero, 0x3
    /* B9F44 002B9344 10620005 */  .word 0x10620005
    /* B9F48 002B9348 00000000 */  nop
    /* B9F4C 002B934C 8E220004 */  lw         $v0, 0x4($s1)
    /* B9F50 002B9350 8E23000C */  lw         $v1, 0xC($s1)
    /* B9F54 002B9354 00431023 */  subu       $v0, $v0, $v1
    /* B9F58 002B9358 AE220004 */  sw         $v0, 0x4($s1)
.Lauto_002B935C:
    /* B9F5C 002B935C 96020018 */  lhu        $v0, 0x18($s0)
    /* B9F60 002B9360 14540005 */  .word 0x14540005
    /* B9F64 002B9364 00009821 */  addu      $s3, $zero, $zero
    /* B9F68 002B9368 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9F6C 002B936C 8C420014 */  lw         $v0, 0x14($v0)
    /* B9F70 002B9370 8C420014 */  lw         $v0, 0x14($v0)
    /* B9F74 002B9374 2C530001 */  sltiu      $s3, $v0, 0x1
.Lauto_002B9378:
    /* B9F78 002B9378 27A5001C */  addiu      $a1, $sp, 0x1C
    /* B9F7C 002B937C 8E440010 */  lw         $a0, 0x10($s2)
    /* B9F80 002B9380 0C0AED50 */  jal        osRecvMesg
    /* B9F84 002B9384 24060001 */  addiu     $a2, $zero, 0x1
    /* B9F88 002B9388 3C040010 */  lui        $a0, (0x100401 >> 16)
    /* B9F8C 002B938C 0C0AED9C */  jal        __osResetGlobalIntMask
    /* B9F90 002B9390 34840401 */  ori       $a0, $a0, (0x100401 & 0xFFFF)
    /* B9F94 002B9394 3C050500 */  lui        $a1, (0x5000510 >> 16)
    /* B9F98 002B9398 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9F9C 002B939C 34A50510 */  ori        $a1, $a1, (0x5000510 & 0xFFFF)
    /* B9FA0 002B93A0 8C440014 */  lw         $a0, 0x14($v0)
    /* B9FA4 002B93A4 8E020024 */  lw         $v0, 0x24($s0)
    /* B9FA8 002B93A8 3C068000 */  lui        $a2, (0x80000000 >> 16)
    /* B9FAC 002B93AC 0C0AE674 */  jal        osEPiRawWriteIo
    /* B9FB0 002B93B0 00463025 */  or        $a2, $v0, $a2
.Lauto_002B93B4:
    /* B9FB4 002B93B4 27A50020 */  addiu      $a1, $sp, 0x20
    /* B9FB8 002B93B8 8E44000C */  lw         $a0, 0xC($s2)
    /* B9FBC 002B93BC 0C0AED50 */  jal        osRecvMesg
    /* B9FC0 002B93C0 24060001 */  addiu     $a2, $zero, 0x1
    /* B9FC4 002B93C4 8FA20018 */  lw         $v0, 0x18($sp)
    /* B9FC8 002B93C8 8C500014 */  lw         $s0, 0x14($v0)
    /* B9FCC 002B93CC 9603001A */  lhu        $v1, 0x1A($s0)
    /* B9FD0 002B93D0 000310C0 */  sll        $v0, $v1, 3
    /* B9FD4 002B93D4 00431021 */  addu       $v0, $v0, $v1
    /* B9FD8 002B93D8 00021080 */  sll        $v0, $v0, 2
    /* B9FDC 002B93DC 02021021 */  addu       $v0, $s0, $v0
    /* B9FE0 002B93E0 2451002C */  addiu      $s1, $v0, 0x2C
    /* B9FE4 002B93E4 8E230000 */  lw         $v1, 0x0($s1)
    /* B9FE8 002B93E8 2402001D */  addiu      $v0, $zero, 0x1D
    /* B9FEC 002B93EC 14620027 */  .word 0x14620027
    /* B9FF0 002B93F0 02002021 */  addu      $a0, $s0, $zero
    /* B9FF4 002B93F4 3C050500 */  lui        $a1, (0x5000510 >> 16)
    /* B9FF8 002B93F8 34A50510 */  ori        $a1, $a1, (0x5000510 & 0xFFFF)
    /* B9FFC 002B93FC 8E020024 */  lw         $v0, 0x24($s0)
    /* BA000 002B9400 3C061000 */  lui        $a2, (0x10000000 >> 16)
    /* BA004 002B9404 0C0AE674 */  jal        osEPiRawWriteIo
    /* BA008 002B9408 00463025 */  or        $a2, $v0, $a2
    /* BA00C 002B940C 3C050500 */  lui        $a1, (0x5000510 >> 16)
    /* BA010 002B9410 8FA20018 */  lw         $v0, 0x18($sp)
    /* BA014 002B9414 8E060024 */  lw         $a2, 0x24($s0)
    /* BA018 002B9418 8C440014 */  lw         $a0, 0x14($v0)
    /* BA01C 002B941C 0C0AE674 */  jal        osEPiRawWriteIo
    /* BA020 002B9420 34A50510 */  ori       $a1, $a1, (0x5000510 & 0xFFFF)
    /* BA024 002B9424 3C050500 */  lui        $a1, (0x5000508 >> 16)
    /* BA028 002B9428 8FA20018 */  lw         $v0, 0x18($sp)
    /* BA02C 002B942C 34A50508 */  ori        $a1, $a1, (0x5000508 & 0xFFFF)
    /* BA030 002B9430 8C440014 */  lw         $a0, 0x14($v0)
    /* BA034 002B9434 0C0AE60C */  jal        osEPiRawReadIo
    /* BA038 002B9438 27A60024 */  addiu     $a2, $sp, 0x24
    /* BA03C 002B943C 8FA20024 */  lw         $v0, 0x24($sp)
    /* BA040 002B9440 3C030200 */  lui        $v1, (0x2000000 >> 16)
    /* BA044 002B9444 00431024 */  and        $v0, $v0, $v1
    /* BA048 002B9448 10400008 */  .word 0x10400008
    /* BA04C 002B944C 3C050500 */  lui       $a1, (0x5000510 >> 16)
    /* BA050 002B9450 8FA20018 */  lw         $v0, 0x18($sp)
    /* BA054 002B9454 34A50510 */  ori        $a1, $a1, (0x5000510 & 0xFFFF)
    /* BA058 002B9458 8C440014 */  lw         $a0, 0x14($v0)
    /* BA05C 002B945C 8E020024 */  lw         $v0, 0x24($s0)
    /* BA060 002B9460 3C060100 */  lui        $a2, (0x1000000 >> 16)
    /* BA064 002B9464 0C0AE674 */  jal        osEPiRawWriteIo
    /* BA068 002B9468 00463025 */  or        $a2, $v0, $a2
.Lauto_002B946C:
    /* BA06C 002B946C 3C03A460 */  lui        $v1, %hi(PI_STATUS_REG)
    /* BA070 002B9470 34630010 */  ori        $v1, $v1, %lo(PI_STATUS_REG)
    /* BA074 002B9474 3C040010 */  lui        $a0, (0x100C01 >> 16)
    /* BA078 002B9478 24020004 */  addiu      $v0, $zero, 0x4
    /* BA07C 002B947C AE220000 */  sw         $v0, 0x0($s1)
    /* BA080 002B9480 AC740000 */  sw         $s4, 0x0($v1)
    /* BA084 002B9484 0C0AEE14 */  jal        __osSetGlobalIntMask
    /* BA088 002B9488 34840C01 */  ori       $a0, $a0, (0x100C01 & 0xFFFF)
.Lauto_002B948C:
    /* BA08C 002B948C 8FA50018 */  lw         $a1, 0x18($sp)
    /* BA090 002B9490 8CA40004 */  lw         $a0, 0x4($a1)
    /* BA094 002B9494 0C0AEDB0 */  jal        osSendMesg
    /* BA098 002B9498 00003021 */  addu      $a2, $zero, $zero
    /* BA09C 002B949C 16750006 */  .word 0x16750006
    /* BA0A0 002B94A0 00002821 */  addu      $a1, $zero, $zero
    /* BA0A4 002B94A4 8FA20018 */  lw         $v0, 0x18($sp)
    /* BA0A8 002B94A8 8C420014 */  lw         $v0, 0x14($v0)
    /* BA0AC 002B94AC 8C42002C */  lw         $v0, 0x2C($v0)
    /* BA0B0 002B94B0 1040FFC0 */  .word 0x1040FFC0
    /* BA0B4 002B94B4 00009821 */  addu      $s3, $zero, $zero
.Lauto_002B94B8:
    /* BA0B8 002B94B8 8E440010 */  lw         $a0, 0x10($s2)
    /* BA0BC 002B94BC 0C0AEDB0 */  jal        osSendMesg
    /* BA0C0 002B94C0 00A03021 */  addu      $a2, $a1, $zero
    /* BA0C4 002B94C4 8FA20018 */  lw         $v0, 0x18($sp)
    /* BA0C8 002B94C8 8C420014 */  lw         $v0, 0x14($v0)
    /* BA0CC 002B94CC 9442001A */  lhu        $v0, 0x1A($v0)
    /* BA0D0 002B94D0 1455FF84 */  .word 0x1455FF84
    /* BA0D4 002B94D4 27A50018 */  addiu     $a1, $sp, 0x18
    /* BA0D8 002B94D8 0C0AEFB0 */  jal        osYieldThread
    /* BA0DC 002B94DC 00000000 */  nop
    /* BA0E0 002B94E0 080AE4B9 */  .word 0x080AE4B9
    /* BA0E4 002B94E4 27A50018 */  addiu     $a1, $sp, 0x18
.Lauto_002B94E8:
    /* BA0E8 002B94E8 8FA20018 */  lw         $v0, 0x18($sp)
.Lauto_002B94EC:
    /* BA0EC 002B94EC 94420000 */  lhu        $v0, 0x0($v0)
    /* BA0F0 002B94F0 2443FFF6 */  addiu      $v1, $v0, -0xA
    /* BA0F4 002B94F4 2C620007 */  sltiu      $v0, $v1, 0x7
    /* BA0F8 002B94F8 10400042 */  .word 0x10400042
    /* BA0FC 002B94FC 00031080 */  sll       $v0, $v1, 2
    /* BA100 002B9500 3C01800D */  lui        $at, %hi(jtbl_auto_800C8520)
    /* BA104 002B9504 00220821 */  addu       $at, $at, $v0
    /* BA108 002B9508 8C228520 */  lw         $v0, %lo(jtbl_auto_800C8520)($at)
    /* BA10C 002B950C 00400008 */  jr         $v0
    /* BA110 002B9510 00000000 */  nop
    /* BA114 002B9514 27A5001C */  addiu      $a1, $sp, 0x1C
    /* BA118 002B9518 8E440010 */  lw         $a0, 0x10($s2)
    /* BA11C 002B951C 0C0AED50 */  jal        osRecvMesg
    /* BA120 002B9520 24060001 */  addiu     $a2, $zero, 0x1
    /* BA124 002B9524 8FA20018 */  lw         $v0, 0x18($sp)
    /* BA128 002B9528 8C45000C */  lw         $a1, 0xC($v0)
    /* BA12C 002B952C 8C460008 */  lw         $a2, 0x8($v0)
    /* BA130 002B9530 8C470010 */  lw         $a3, 0x10($v0)
    /* BA134 002B9534 8E420014 */  lw         $v0, 0x14($s2)
    /* BA138 002B9538 0040F809 */  jalr       $v0
    /* BA13C 002B953C 00002021 */  addu      $a0, $zero, $zero
    /* BA140 002B9540 080AE582 */  .word 0x080AE582
    /* BA144 002B9544 00000000 */  nop
    /* BA148 002B9548 27A5001C */  addiu      $a1, $sp, 0x1C
    /* BA14C 002B954C 8E440010 */  lw         $a0, 0x10($s2)
    /* BA150 002B9550 0C0AED50 */  jal        osRecvMesg
    /* BA154 002B9554 24060001 */  addiu     $a2, $zero, 0x1
    /* BA158 002B9558 8FA20018 */  lw         $v0, 0x18($sp)
    /* BA15C 002B955C 8C45000C */  lw         $a1, 0xC($v0)
    /* BA160 002B9560 8C460008 */  lw         $a2, 0x8($v0)
    /* BA164 002B9564 8C470010 */  lw         $a3, 0x10($v0)
    /* BA168 002B9568 8E420014 */  lw         $v0, 0x14($s2)
    /* BA16C 002B956C 0040F809 */  jalr       $v0
    /* BA170 002B9570 24040001 */  addiu     $a0, $zero, 0x1
    /* BA174 002B9574 080AE582 */  .word 0x080AE582
    /* BA178 002B9578 00000000 */  nop
    /* BA17C 002B957C 27A5001C */  addiu      $a1, $sp, 0x1C
    /* BA180 002B9580 8E440010 */  lw         $a0, 0x10($s2)
    /* BA184 002B9584 0C0AED50 */  jal        osRecvMesg
    /* BA188 002B9588 24060001 */  addiu     $a2, $zero, 0x1
    /* BA18C 002B958C 8FA20018 */  lw         $v0, 0x18($sp)
    /* BA190 002B9590 8C430010 */  lw         $v1, 0x10($v0)
    /* BA194 002B9594 AFA30010 */  sw         $v1, 0x10($sp)
    /* BA198 002B9598 8C440014 */  lw         $a0, 0x14($v0)
    /* BA19C 002B959C 8C46000C */  lw         $a2, 0xC($v0)
    /* BA1A0 002B95A0 8C470008 */  lw         $a3, 0x8($v0)
    /* BA1A4 002B95A4 8E420018 */  lw         $v0, 0x18($s2)
    /* BA1A8 002B95A8 0040F809 */  jalr       $v0
    /* BA1AC 002B95AC 00002821 */  addu      $a1, $zero, $zero
    /* BA1B0 002B95B0 080AE582 */  .word 0x080AE582
    /* BA1B4 002B95B4 00000000 */  nop
    /* BA1B8 002B95B8 27A5001C */  addiu      $a1, $sp, 0x1C
    /* BA1BC 002B95BC 8E440010 */  lw         $a0, 0x10($s2)
    /* BA1C0 002B95C0 0C0AED50 */  jal        osRecvMesg
    /* BA1C4 002B95C4 24060001 */  addiu     $a2, $zero, 0x1
    /* BA1C8 002B95C8 8FA20018 */  lw         $v0, 0x18($sp)
    /* BA1CC 002B95CC 8C430010 */  lw         $v1, 0x10($v0)
    /* BA1D0 002B95D0 AFA30010 */  sw         $v1, 0x10($sp)
    /* BA1D4 002B95D4 8C440014 */  lw         $a0, 0x14($v0)
    /* BA1D8 002B95D8 8C46000C */  lw         $a2, 0xC($v0)
    /* BA1DC 002B95DC 8C470008 */  lw         $a3, 0x8($v0)
    /* BA1E0 002B95E0 8E420018 */  lw         $v0, 0x18($s2)
    /* BA1E4 002B95E4 0040F809 */  jalr       $v0
    /* BA1E8 002B95E8 24050001 */  addiu     $a1, $zero, 0x1
    /* BA1EC 002B95EC 080AE582 */  .word 0x080AE582
    /* BA1F0 002B95F0 00000000 */  nop
    /* BA1F4 002B95F4 8FA50018 */  lw         $a1, 0x18($sp)
    /* BA1F8 002B95F8 8CA40004 */  lw         $a0, 0x4($a1)
    /* BA1FC 002B95FC 0C0AEDB0 */  jal        osSendMesg
    /* BA200 002B9600 00003021 */  addu      $a2, $zero, $zero
.Lauto_002B9604:
    /* BA204 002B9604 2402FFFF */  addiu      $v0, $zero, -0x1
.Lauto_002B9608:
    /* BA208 002B9608 1440FF36 */  .word 0x1440FF36
    /* BA20C 002B960C 27A50018 */  addiu     $a1, $sp, 0x18
    /* BA210 002B9610 27A50020 */  addiu      $a1, $sp, 0x20
    /* BA214 002B9614 8E44000C */  lw         $a0, 0xC($s2)
    /* BA218 002B9618 0C0AED50 */  jal        osRecvMesg
    /* BA21C 002B961C 24060001 */  addiu     $a2, $zero, 0x1
    /* BA220 002B9620 8FA50018 */  lw         $a1, 0x18($sp)
    /* BA224 002B9624 8CA40004 */  lw         $a0, 0x4($a1)
    /* BA228 002B9628 0C0AEDB0 */  jal        osSendMesg
    /* BA22C 002B962C 00003021 */  addu      $a2, $zero, $zero
    /* BA230 002B9630 00002821 */  addu       $a1, $zero, $zero
    /* BA234 002B9634 8E440010 */  lw         $a0, 0x10($s2)
    /* BA238 002B9638 0C0AEDB0 */  jal        osSendMesg
    /* BA23C 002B963C 00A03021 */  addu      $a2, $a1, $zero
    /* BA240 002B9640 080AE4B9 */  .word 0x080AE4B9
    /* BA244 002B9644 27A50018 */  addiu     $a1, $sp, 0x18
    /* BA248 002B9648 AFB00018 */  sw         $s0, 0x18($sp)
    /* BA24C 002B964C 00808021 */  addu       $s0, $a0, $zero
