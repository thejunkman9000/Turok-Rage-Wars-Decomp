.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2470-0xC2980 (VRAM 0x002C1870) */
glabel __osLeoInterrupt
    /* C2470 002C1870 27BDFFD0 */  addiu      $sp, $sp, -0x30
    /* C2474 002C1874 3C05A460 */  lui        $a1, %hi(PI_STATUS_REG)
    /* C2478 002C1878 3C038015 */  lui        $v1, %hi(__osDiskHandle)
    /* C247C 002C187C 8C63EA44 */  lw         $v1, %lo(__osDiskHandle)($v1)
    /* C2480 002C1880 34A50010 */  ori        $a1, $a1, %lo(PI_STATUS_REG)
    /* C2484 002C1884 AFBF002C */  sw         $ra, 0x2C($sp)
    /* C2488 002C1888 AFB20028 */  sw         $s2, 0x28($sp)
    /* C248C 002C188C AFB10024 */  sw         $s1, 0x24($sp)
    /* C2490 002C1890 AFB00020 */  sw         $s0, 0x20($sp)
    /* C2494 002C1894 8CA20000 */  lw         $v0, 0x0($a1)
    /* C2498 002C1898 24710014 */  addiu      $s1, $v1, 0x14
    /* C249C 002C189C AFA20018 */  sw         $v0, 0x18($sp)
    /* C24A0 002C18A0 9464001A */  lhu        $a0, 0x1A($v1)
    /* C24A4 002C18A4 8FA30018 */  lw         $v1, 0x18($sp)
    /* C24A8 002C18A8 000410C0 */  sll        $v0, $a0, 3
    /* C24AC 002C18AC 00441021 */  addu       $v0, $v0, $a0
    /* C24B0 002C18B0 00021080 */  sll        $v0, $v0, 2
    /* C24B4 002C18B4 24420018 */  addiu      $v0, $v0, 0x18
    /* C24B8 002C18B8 30630001 */  andi       $v1, $v1, 0x1
    /* C24BC 002C18BC 1060000C */  beqz       $v1, .L002C18F0
    /* C24C0 002C18C0 02228021 */   addu      $s0, $s1, $v0
    /* C24C4 002C18C4 2402001D */  addiu      $v0, $zero, 0x1D
    /* C24C8 002C18C8 3C04800E */  lui        $a0, %hi(__OSGlobalIntMask)
    /* C24CC 002C18CC 24849288 */  addiu      $a0, $a0, %lo(__OSGlobalIntMask)
    /* C24D0 002C18D0 AE020000 */  sw         $v0, 0x0($s0)
    /* C24D4 002C18D4 8C820000 */  lw         $v0, 0x0($a0)
    /* C24D8 002C18D8 2403F7FF */  addiu      $v1, $zero, -0x801
    /* C24DC 002C18DC 00431024 */  and        $v0, $v0, $v1
    /* C24E0 002C18E0 0C0B0795 */  jal        __osLeoResume
    /* C24E4 002C18E4 AC820000 */   sw        $v0, 0x0($a0)
    /* C24E8 002C18E8 080B075A */  j          .L002C1D68
    /* C24EC 002C18EC 24020001 */   addiu     $v0, $zero, 0x1
  .L002C18F0:
    /* C24F0 002C18F0 8CA20000 */  lw         $v0, 0x0($a1)
    /* C24F4 002C18F4 AFA20018 */  sw         $v0, 0x18($sp)
    /* C24F8 002C18F8 8FA20018 */  lw         $v0, 0x18($sp)
    /* C24FC 002C18FC 30420003 */  andi       $v0, $v0, 0x3
    /* C2500 002C1900 10400009 */  beqz       $v0, .L002C1928
    /* C2504 002C1904 3C02A500 */   lui       $v0, %hi(LEO_CMD)
    /* C2508 002C1908 3C03A460 */  lui        $v1, %hi(PI_STATUS_REG)
    /* C250C 002C190C 34630010 */  ori        $v1, $v1, %lo(PI_STATUS_REG)
  .L002C1910:
    /* C2510 002C1910 8C620000 */  lw         $v0, 0x0($v1)
    /* C2514 002C1914 AFA20018 */  sw         $v0, 0x18($sp)
    /* C2518 002C1918 8FA20018 */  lw         $v0, 0x18($sp)
    /* C251C 002C191C 30420003 */  andi       $v0, $v0, 0x3
    /* C2520 002C1920 1440FFFB */  bnez       $v0, .L002C1910
    /* C2524 002C1924 3C02A500 */   lui       $v0, %hi(LEO_CMD)
  .L002C1928:
    /* C2528 002C1928 34420508 */  ori        $v0, $v0, %lo(LEO_CMD)
    /* C252C 002C192C 8C520000 */  lw         $s2, 0x0($v0)
    /* C2530 002C1930 3C020200 */  lui        $v0, (0x2000000 >> 16)
    /* C2534 002C1934 02421024 */  and        $v0, $s2, $v0
    /* C2538 002C1938 10400018 */  beqz       $v0, .L002C199C
    /* C253C 002C193C 3C02A460 */   lui       $v0, %hi(PI_STATUS_REG)
    /* C2540 002C1940 34420010 */  ori        $v0, $v0, %lo(PI_STATUS_REG)
    /* C2544 002C1944 8C420000 */  lw         $v0, 0x0($v0)
    /* C2548 002C1948 AFA20018 */  sw         $v0, 0x18($sp)
    /* C254C 002C194C 8FA20018 */  lw         $v0, 0x18($sp)
    /* C2550 002C1950 30420003 */  andi       $v0, $v0, 0x3
    /* C2554 002C1954 10400008 */  beqz       $v0, .L002C1978
    /* C2558 002C1958 3C03A460 */   lui       $v1, %hi(PI_STATUS_REG)
    /* C255C 002C195C 34630010 */  ori        $v1, $v1, %lo(PI_STATUS_REG)
  .L002C1960:
    /* C2560 002C1960 8C620000 */  lw         $v0, 0x0($v1)
    /* C2564 002C1964 AFA20018 */  sw         $v0, 0x18($sp)
    /* C2568 002C1968 8FA20018 */  lw         $v0, 0x18($sp)
    /* C256C 002C196C 30420003 */  andi       $v0, $v0, 0x3
    /* C2570 002C1970 1440FFFB */  bnez       $v0, .L002C1960
    /* C2574 002C1974 00000000 */   nop
  .L002C1978:
    /* C2578 002C1978 3C05A500 */  lui        $a1, %hi(LEO_BM_CTL)
    /* C257C 002C197C 34A50510 */  ori        $a1, $a1, %lo(LEO_BM_CTL)
    /* C2580 002C1980 8E240010 */  lw         $a0, 0x10($s1)
    /* C2584 002C1984 3C030100 */  lui        $v1, (0x1000000 >> 16)
    /* C2588 002C1988 AE000000 */  sw         $zero, 0x0($s0)
    /* C258C 002C198C 00832025 */  or         $a0, $a0, $v1
    /* C2590 002C1990 ACA40000 */  sw         $a0, 0x0($a1)
    /* C2594 002C1994 080B075A */  j          .L002C1D68
    /* C2598 002C1998 00001021 */   addu      $v0, $zero, $zero
  .L002C199C:
    /* C259C 002C199C 8E230000 */  lw         $v1, 0x0($s1)
    /* C25A0 002C19A0 24060002 */  addiu      $a2, $zero, 0x2
    /* C25A4 002C19A4 106600F0 */  beq        $v1, $a2, .L002C1D68
    /* C25A8 002C19A8 24020001 */   addiu     $v0, $zero, 0x1
    /* C25AC 002C19AC 3C020800 */  lui        $v0, (0x8000000 >> 16)
    /* C25B0 002C19B0 02421024 */  and        $v0, $s2, $v0
    /* C25B4 002C19B4 10400022 */  beqz       $v0, .L002C1A40
    /* C25B8 002C19B8 3C02A460 */   lui       $v0, %hi(PI_STATUS_REG)
    /* C25BC 002C19BC 34420010 */  ori        $v0, $v0, %lo(PI_STATUS_REG)
    /* C25C0 002C19C0 8C420000 */  lw         $v0, 0x0($v0)
    /* C25C4 002C19C4 AFA20018 */  sw         $v0, 0x18($sp)
    /* C25C8 002C19C8 8FA20018 */  lw         $v0, 0x18($sp)
    /* C25CC 002C19CC 30420003 */  andi       $v0, $v0, 0x3
    /* C25D0 002C19D0 10400008 */  beqz       $v0, .L002C19F4
    /* C25D4 002C19D4 3C03A460 */   lui       $v1, %hi(PI_STATUS_REG)
    /* C25D8 002C19D8 34630010 */  ori        $v1, $v1, %lo(PI_STATUS_REG)
  .L002C19DC:
    /* C25DC 002C19DC 8C620000 */  lw         $v0, 0x0($v1)
    /* C25E0 002C19E0 AFA20018 */  sw         $v0, 0x18($sp)
    /* C25E4 002C19E4 8FA20018 */  lw         $v0, 0x18($sp)
    /* C25E8 002C19E8 30420003 */  andi       $v0, $v0, 0x3
    /* C25EC 002C19EC 1440FFFB */  bnez       $v0, .L002C19DC
    /* C25F0 002C19F0 00000000 */   nop
  .L002C19F4:
    /* C25F4 002C19F4 3C02A500 */  lui        $v0, %hi(LEO_CMD)
    /* C25F8 002C19F8 34420508 */  ori        $v0, $v0, %lo(LEO_CMD)
    /* C25FC 002C19FC 8C520000 */  lw         $s2, 0x0($v0)
    /* C2600 002C1A00 24020016 */  addiu      $v0, $zero, 0x16
    /* C2604 002C1A04 0C0B0795 */  jal        __osLeoResume
    /* C2608 002C1A08 AE020000 */   sw        $v0, 0x0($s0)
    /* C260C 002C1A0C 3C07A460 */  lui        $a3, %hi(PI_STATUS_REG)
    /* C2610 002C1A10 34E70010 */  ori        $a3, $a3, %lo(PI_STATUS_REG)
    /* C2614 002C1A14 3C060010 */  lui        $a2, (0x100401 >> 16)
    /* C2618 002C1A18 34C60401 */  ori        $a2, $a2, (0x100401 & 0xFFFF)
    /* C261C 002C1A1C 24020001 */  addiu      $v0, $zero, 0x1
    /* C2620 002C1A20 3C05800E */  lui        $a1, %hi(__OSGlobalIntMask)
    /* C2624 002C1A24 24A59288 */  addiu      $a1, $a1, %lo(__OSGlobalIntMask)
    /* C2628 002C1A28 8CA30000 */  lw         $v1, 0x0($a1)
    /* C262C 002C1A2C 24040002 */  addiu      $a0, $zero, 0x2
    /* C2630 002C1A30 ACE40000 */  sw         $a0, 0x0($a3)
    /* C2634 002C1A34 00661825 */  or         $v1, $v1, $a2
    /* C2638 002C1A38 080B075A */  j          .L002C1D68
    /* C263C 002C1A3C ACA30000 */   sw        $v1, 0x0($a1)
  .L002C1A40:
    /* C2640 002C1A40 24020001 */  addiu      $v0, $zero, 0x1
    /* C2644 002C1A44 1462002C */  bne        $v1, $v0, .L002C1AF8
    /* C2648 002C1A48 3C024000 */   lui       $v0, (0x40000000 >> 16)
    /* C264C 002C1A4C 02421024 */  and        $v0, $s2, $v0
    /* C2650 002C1A50 14400018 */  bnez       $v0, .L002C1AB4
    /* C2654 002C1A54 24050001 */   addiu     $a1, $zero, 0x1
    /* C2658 002C1A58 8E240008 */  lw         $a0, 0x8($s1)
    /* C265C 002C1A5C 96230004 */  lhu        $v1, 0x4($s1)
    /* C2660 002C1A60 24840001 */  addiu      $a0, $a0, 0x1
    /* C2664 002C1A64 00031080 */  sll        $v0, $v1, 2
    /* C2668 002C1A68 00431021 */  addu       $v0, $v0, $v1
    /* C266C 002C1A6C 00021900 */  sll        $v1, $v0, 4
    /* C2670 002C1A70 00431021 */  addu       $v0, $v0, $v1
    /* C2674 002C1A74 148200B8 */  bne        $a0, $v0, .L002C1D58
    /* C2678 002C1A78 24020018 */   addiu     $v0, $zero, 0x18
    /* C267C 002C1A7C 3C04A460 */  lui        $a0, %hi(PI_STATUS_REG)
    /* C2680 002C1A80 34840010 */  ori        $a0, $a0, %lo(PI_STATUS_REG)
    /* C2684 002C1A84 3C050010 */  lui        $a1, (0x100401 >> 16)
    /* C2688 002C1A88 3C03800E */  lui        $v1, %hi(__OSGlobalIntMask)
    /* C268C 002C1A8C 24639288 */  addiu      $v1, $v1, %lo(__OSGlobalIntMask)
    /* C2690 002C1A90 8C620000 */  lw         $v0, 0x0($v1)
    /* C2694 002C1A94 34A50401 */  ori        $a1, $a1, (0x100401 & 0xFFFF)
    /* C2698 002C1A98 AC860000 */  sw         $a2, 0x0($a0)
    /* C269C 002C1A9C AE000000 */  sw         $zero, 0x0($s0)
    /* C26A0 002C1AA0 00451025 */  or         $v0, $v0, $a1
    /* C26A4 002C1AA4 0C0B0795 */  jal        __osLeoResume
    /* C26A8 002C1AA8 AC620000 */   sw        $v0, 0x0($v1)
    /* C26AC 002C1AAC 080B075A */  j          .L002C1D68
    /* C26B0 002C1AB0 24020001 */   addiu     $v0, $zero, 0x1
  .L002C1AB4:
    /* C26B4 002C1AB4 8E020004 */  lw         $v0, 0x4($s0)
    /* C26B8 002C1AB8 8E03000C */  lw         $v1, 0xC($s0)
    /* C26BC 002C1ABC 00431021 */  addu       $v0, $v0, $v1
    /* C26C0 002C1AC0 AE020004 */  sw         $v0, 0x4($s0)
    /* C26C4 002C1AC4 8E220008 */  lw         $v0, 0x8($s1)
    /* C26C8 002C1AC8 3C048015 */  lui        $a0, %hi(__osDiskHandle)
    /* C26CC 002C1ACC 8C84EA44 */  lw         $a0, %lo(__osDiskHandle)($a0)
    /* C26D0 002C1AD0 00451021 */  addu       $v0, $v0, $a1
    /* C26D4 002C1AD4 AE220008 */  sw         $v0, 0x8($s1)
    /* C26D8 002C1AD8 8E02000C */  lw         $v0, 0xC($s0)
    /* C26DC 002C1ADC 3C060500 */  lui        $a2, (0x5000400 >> 16)
    /* C26E0 002C1AE0 AFA20010 */  sw         $v0, 0x10($sp)
    /* C26E4 002C1AE4 8E070004 */  lw         $a3, 0x4($s0)
    /* C26E8 002C1AE8 0C0AF928 */  jal        osEPiRawStartDma
    /* C26EC 002C1AEC 34C60400 */   ori       $a2, $a2, (0x5000400 & 0xFFFF)
    /* C26F0 002C1AF0 080B075A */  j          .L002C1D68
    /* C26F4 002C1AF4 24020001 */   addiu     $v0, $zero, 0x1
  .L002C1AF8:
    /* C26F8 002C1AF8 14600097 */  bnez       $v1, .L002C1D58
    /* C26FC 002C1AFC 24020004 */   addiu     $v0, $zero, 0x4
    /* C2700 002C1B00 96230004 */  lhu        $v1, 0x4($s1)
    /* C2704 002C1B04 24020003 */  addiu      $v0, $zero, 0x3
    /* C2708 002C1B08 1462000E */  bne        $v1, $v0, .L002C1B44
    /* C270C 002C1B0C 00000000 */   nop
    /* C2710 002C1B10 8E020010 */  lw         $v0, 0x10($s0)
    /* C2714 002C1B14 8E230008 */  lw         $v1, 0x8($s1)
    /* C2718 002C1B18 24420011 */  addiu      $v0, $v0, 0x11
    /* C271C 002C1B1C 0043102A */  slt        $v0, $v0, $v1
    /* C2720 002C1B20 10400003 */  beqz       $v0, .L002C1B30
    /* C2724 002C1B24 3C024000 */   lui       $v0, (0x40000000 >> 16)
    /* C2728 002C1B28 080B0757 */  j          .L002C1D5C
    /* C272C 002C1B2C AE000000 */   sw        $zero, 0x0($s0)
  .L002C1B30:
    /* C2730 002C1B30 02421024 */  and        $v0, $s2, $v0
    /* C2734 002C1B34 14400008 */  bnez       $v0, .L002C1B58
    /* C2738 002C1B38 3C02A500 */   lui       $v0, %hi(LEO_BM_CTL)
    /* C273C 002C1B3C 080B0756 */  j          .L002C1D58
    /* C2740 002C1B40 24020017 */   addiu     $v0, $zero, 0x17
  .L002C1B44:
    /* C2744 002C1B44 8E020004 */  lw         $v0, 0x4($s0)
    /* C2748 002C1B48 8E03000C */  lw         $v1, 0xC($s0)
    /* C274C 002C1B4C 00431021 */  addu       $v0, $v0, $v1
    /* C2750 002C1B50 AE020004 */  sw         $v0, 0x4($s0)
    /* C2754 002C1B54 3C02A500 */  lui        $v0, %hi(LEO_BM_CTL)
  .L002C1B58:
    /* C2758 002C1B58 34420510 */  ori        $v0, $v0, %lo(LEO_BM_CTL)
    /* C275C 002C1B5C 8C440000 */  lw         $a0, 0x0($v0)
    /* C2760 002C1B60 3C030060 */  lui        $v1, (0x600000 >> 16)
    /* C2764 002C1B64 00831024 */  and        $v0, $a0, $v1
    /* C2768 002C1B68 10430004 */  beq        $v0, $v1, .L002C1B7C
    /* C276C 002C1B6C 3C020200 */   lui       $v0, (0x2000000 >> 16)
    /* C2770 002C1B70 00821024 */  and        $v0, $a0, $v0
    /* C2774 002C1B74 10400017 */  beqz       $v0, .L002C1BD4
    /* C2778 002C1B78 3C021000 */   lui       $v0, (0x10000000 >> 16)
  .L002C1B7C:
    /* C277C 002C1B7C 8E030010 */  lw         $v1, 0x10($s0)
    /* C2780 002C1B80 2C620004 */  sltiu      $v0, $v1, 0x4
    /* C2784 002C1B84 1440000B */  bnez       $v0, .L002C1BB4
    /* C2788 002C1B88 00031880 */   sll       $v1, $v1, 2
    /* C278C 002C1B8C 96230004 */  lhu        $v1, 0x4($s1)
    /* C2790 002C1B90 24020003 */  addiu      $v0, $zero, 0x3
    /* C2794 002C1B94 14620070 */  bne        $v1, $v0, .L002C1D58
    /* C2798 002C1B98 24020017 */   addiu     $v0, $zero, 0x17
    /* C279C 002C1B9C 8E220008 */  lw         $v0, 0x8($s1)
    /* C27A0 002C1BA0 28420053 */  slti       $v0, $v0, 0x53
    /* C27A4 002C1BA4 14400007 */  bnez       $v0, .L002C1BC4
    /* C27A8 002C1BA8 24020017 */   addiu     $v0, $zero, 0x17
    /* C27AC 002C1BAC 080B0757 */  j          .L002C1D5C
    /* C27B0 002C1BB0 AE020000 */   sw        $v0, 0x0($s0)
  .L002C1BB4:
    /* C27B4 002C1BB4 8E220008 */  lw         $v0, 0x8($s1)
    /* C27B8 002C1BB8 02031821 */  addu       $v1, $s0, $v1
    /* C27BC 002C1BBC 24420001 */  addiu      $v0, $v0, 0x1
    /* C27C0 002C1BC0 AC620014 */  sw         $v0, 0x14($v1)
  .L002C1BC4:
    /* C27C4 002C1BC4 8E020010 */  lw         $v0, 0x10($s0)
    /* C27C8 002C1BC8 24420001 */  addiu      $v0, $v0, 0x1
    /* C27CC 002C1BCC AE020010 */  sw         $v0, 0x10($s0)
    /* C27D0 002C1BD0 3C021000 */  lui        $v0, (0x10000000 >> 16)
  .L002C1BD4:
    /* C27D4 002C1BD4 02421024 */  and        $v0, $s2, $v0
    /* C27D8 002C1BD8 1040002D */  beqz       $v0, .L002C1C90
    /* C27DC 002C1BDC 24030058 */   addiu     $v1, $zero, 0x58
    /* C27E0 002C1BE0 8E220008 */  lw         $v0, 0x8($s1)
    /* C27E4 002C1BE4 24420001 */  addiu      $v0, $v0, 0x1
    /* C27E8 002C1BE8 10430003 */  beq        $v0, $v1, .L002C1BF8
    /* C27EC 002C1BEC 24020018 */   addiu     $v0, $zero, 0x18
    /* C27F0 002C1BF0 0C0B0760 */  jal        __osLeoAbnormalResume
    /* C27F4 002C1BF4 AE020000 */   sw        $v0, 0x0($s0)
  .L002C1BF8:
    /* C27F8 002C1BF8 8E230004 */  lw         $v1, 0x4($s1)
    /* C27FC 002C1BFC 3C020002 */  lui        $v0, (0x20000 >> 16)
    /* C2800 002C1C00 1462000C */  bne        $v1, $v0, .L002C1C34
    /* C2804 002C1C04 3C05A460 */   lui       $a1, %hi(PI_STATUS_REG)
    /* C2808 002C1C08 8E230040 */  lw         $v1, 0x40($s1)
    /* C280C 002C1C0C 8E240048 */  lw         $a0, 0x48($s1)
    /* C2810 002C1C10 24020001 */  addiu      $v0, $zero, 0x1
    /* C2814 002C1C14 A6220006 */  sh         $v0, 0x6($s1)
    /* C2818 002C1C18 2402FFFF */  addiu      $v0, $zero, -0x1
    /* C281C 002C1C1C AE220008 */  sw         $v0, 0x8($s1)
    /* C2820 002C1C20 24020016 */  addiu      $v0, $zero, 0x16
    /* C2824 002C1C24 00641823 */  subu       $v1, $v1, $a0
    /* C2828 002C1C28 AE230040 */  sw         $v1, 0x40($s1)
    /* C282C 002C1C2C 080B0719 */  j          .L002C1C64
    /* C2830 002C1C30 AE020000 */   sw        $v0, 0x0($s0)
  .L002C1C34:
    /* C2834 002C1C34 34A50010 */  ori        $a1, $a1, %lo(PI_STATUS_REG)
    /* C2838 002C1C38 3C060010 */  lui        $a2, (0x100401 >> 16)
    /* C283C 002C1C3C 34C60401 */  ori        $a2, $a2, (0x100401 & 0xFFFF)
    /* C2840 002C1C40 3C04800E */  lui        $a0, %hi(__OSGlobalIntMask)
    /* C2844 002C1C44 24849288 */  addiu      $a0, $a0, %lo(__OSGlobalIntMask)
    /* C2848 002C1C48 8C830000 */  lw         $v1, 0x0($a0)
    /* C284C 002C1C4C 24020002 */  addiu      $v0, $zero, 0x2
    /* C2850 002C1C50 ACA20000 */  sw         $v0, 0x0($a1)
    /* C2854 002C1C54 AE220000 */  sw         $v0, 0x0($s1)
    /* C2858 002C1C58 AE000000 */  sw         $zero, 0x0($s0)
    /* C285C 002C1C5C 00661825 */  or         $v1, $v1, $a2
    /* C2860 002C1C60 AC830000 */  sw         $v1, 0x0($a0)
  .L002C1C64:
    /* C2864 002C1C64 00002821 */  addu       $a1, $zero, $zero
    /* C2868 002C1C68 8E02000C */  lw         $v0, 0xC($s0)
    /* C286C 002C1C6C 3C048015 */  lui        $a0, %hi(__osDiskHandle)
    /* C2870 002C1C70 8C84EA44 */  lw         $a0, %lo(__osDiskHandle)($a0)
    /* C2874 002C1C74 00021080 */  sll        $v0, $v0, 2
    /* C2878 002C1C78 AFA20010 */  sw         $v0, 0x10($sp)
    /* C287C 002C1C7C 8E070008 */  lw         $a3, 0x8($s0)
    /* C2880 002C1C80 0C0AF928 */  jal        osEPiRawStartDma
    /* C2884 002C1C84 3C060500 */   lui       $a2, (0x5000000 >> 16)
    /* C2888 002C1C88 080B075A */  j          .L002C1D68
    /* C288C 002C1C8C 24020001 */   addiu     $v0, $zero, 0x1
  .L002C1C90:
    /* C2890 002C1C90 8E230008 */  lw         $v1, 0x8($s1)
    /* C2894 002C1C94 2402FFFF */  addiu      $v0, $zero, -0x1
    /* C2898 002C1C98 14620016 */  bne        $v1, $v0, .L002C1CF4
    /* C289C 002C1C9C 3C030002 */   lui       $v1, (0x20001 >> 16)
    /* C28A0 002C1CA0 8E220004 */  lw         $v0, 0x4($s1)
    /* C28A4 002C1CA4 34630001 */  ori        $v1, $v1, (0x20001 & 0xFFFF)
    /* C28A8 002C1CA8 14430012 */  bne        $v0, $v1, .L002C1CF4
    /* C28AC 002C1CAC 00000000 */   nop
    /* C28B0 002C1CB0 8E220028 */  lw         $v0, 0x28($s1)
    /* C28B4 002C1CB4 1440000D */  bnez       $v0, .L002C1CEC
    /* C28B8 002C1CB8 26250018 */   addiu     $a1, $s1, 0x18
    /* C28BC 002C1CBC 8CA30008 */  lw         $v1, 0x8($a1)
    /* C28C0 002C1CC0 8C620000 */  lw         $v0, 0x0($v1)
    /* C28C4 002C1CC4 8C640004 */  lw         $a0, 0x4($v1)
    /* C28C8 002C1CC8 00441025 */  or         $v0, $v0, $a0
    /* C28CC 002C1CCC 8C640008 */  lw         $a0, 0x8($v1)
    /* C28D0 002C1CD0 8C63000C */  lw         $v1, 0xC($v1)
    /* C28D4 002C1CD4 00441025 */  or         $v0, $v0, $a0
    /* C28D8 002C1CD8 00431025 */  or         $v0, $v0, $v1
    /* C28DC 002C1CDC 10400003 */  beqz       $v0, .L002C1CEC
    /* C28E0 002C1CE0 24020018 */   addiu     $v0, $zero, 0x18
    /* C28E4 002C1CE4 080B0757 */  j          .L002C1D5C
    /* C28E8 002C1CE8 AE220018 */   sw        $v0, 0x18($s1)
  .L002C1CEC:
    /* C28EC 002C1CEC 0C0B0795 */  jal        __osLeoResume
    /* C28F0 002C1CF0 ACA00000 */   sw        $zero, 0x0($a1)
  .L002C1CF4:
    /* C28F4 002C1CF4 8E220008 */  lw         $v0, 0x8($s1)
    /* C28F8 002C1CF8 24430001 */  addiu      $v1, $v0, 0x1
    /* C28FC 002C1CFC 3C024000 */  lui        $v0, (0x40000000 >> 16)
    /* C2900 002C1D00 02421024 */  and        $v0, $s2, $v0
    /* C2904 002C1D04 10400011 */  beqz       $v0, .L002C1D4C
    /* C2908 002C1D08 AE230008 */   sw        $v1, 0x8($s1)
    /* C290C 002C1D0C 28620055 */  slti       $v0, $v1, 0x55
    /* C2910 002C1D10 14400003 */  bnez       $v0, .L002C1D20
    /* C2914 002C1D14 00002821 */   addu      $a1, $zero, $zero
    /* C2918 002C1D18 080B0756 */  j          .L002C1D58
    /* C291C 002C1D1C 24020018 */   addiu     $v0, $zero, 0x18
  .L002C1D20:
    /* C2920 002C1D20 3C048015 */  lui        $a0, %hi(__osDiskHandle)
    /* C2924 002C1D24 8C84EA44 */  lw         $a0, %lo(__osDiskHandle)($a0)
    /* C2928 002C1D28 8E02000C */  lw         $v0, 0xC($s0)
    /* C292C 002C1D2C 3C060500 */  lui        $a2, (0x5000400 >> 16)
    /* C2930 002C1D30 AFA20010 */  sw         $v0, 0x10($sp)
    /* C2934 002C1D34 8E070004 */  lw         $a3, 0x4($s0)
    /* C2938 002C1D38 0C0AF928 */  jal        osEPiRawStartDma
    /* C293C 002C1D3C 34C60400 */   ori       $a2, $a2, (0x5000400 & 0xFFFF)
    /* C2940 002C1D40 24020001 */  addiu      $v0, $zero, 0x1
    /* C2944 002C1D44 080B075A */  j          .L002C1D68
    /* C2948 002C1D48 AE000000 */   sw        $zero, 0x0($s0)
  .L002C1D4C:
    /* C294C 002C1D4C 28620055 */  slti       $v0, $v1, 0x55
    /* C2950 002C1D50 10400004 */  beqz       $v0, .L002C1D64
    /* C2954 002C1D54 24020018 */   addiu     $v0, $zero, 0x18
  .L002C1D58:
    /* C2958 002C1D58 AE020000 */  sw         $v0, 0x0($s0)
  .L002C1D5C:
    /* C295C 002C1D5C 0C0B0760 */  jal        __osLeoAbnormalResume
    /* C2960 002C1D60 00000000 */   nop
  .L002C1D64:
    /* C2964 002C1D64 24020001 */  addiu      $v0, $zero, 0x1
  .L002C1D68:
    /* C2968 002C1D68 8FBF002C */  lw         $ra, 0x2C($sp)
    /* C296C 002C1D6C 8FB20028 */  lw         $s2, 0x28($sp)
    /* C2970 002C1D70 8FB10024 */  lw         $s1, 0x24($sp)
    /* C2974 002C1D74 8FB00020 */  lw         $s0, 0x20($sp)
    /* C2978 002C1D78 03E00008 */  jr         $ra
    /* C297C 002C1D7C 27BD0030 */   addiu     $sp, $sp, 0x30
endlabel __osLeoInterrupt
