.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB151C-0xB193C (VRAM 0x002B091C) */
glabel dbgHostFseek
    /* B151C 002B091C 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B1520 002B0920 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B1524 002B0924 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* B1528 002B0928 AFB60038 */  sw         $s6, 0x38($sp)
    /* B152C 002B092C 0080B021 */  addu       $s6, $a0, $zero
    /* B1530 002B0930 AFB7003C */  sw         $s7, 0x3C($sp)
    /* B1534 002B0934 00A0B821 */  addu       $s7, $a1, $zero
    /* B1538 002B0938 AFBE0040 */  sw         $fp, 0x40($sp)
    /* B153C 002B093C 00C0F021 */  addu       $fp, $a2, $zero
    /* B1540 002B0940 AFB3002C */  sw         $s3, 0x2C($sp)
    /* B1544 002B0944 24130064 */  addiu      $s3, $zero, 0x64
    /* B1548 002B0948 AFBF0044 */  sw         $ra, 0x44($sp)
    /* B154C 002B094C AFB50034 */  sw         $s5, 0x34($sp)
    /* B1550 002B0950 AFB40030 */  sw         $s4, 0x30($sp)
    /* B1554 002B0954 AFB20028 */  sw         $s2, 0x28($sp)
    /* B1558 002B0958 AFB10024 */  sw         $s1, 0x24($sp)
    /* B155C 002B095C AFB00020 */  sw         $s0, 0x20($sp)
    /* B1560 002B0960 AFA00014 */  sw         $zero, 0x14($sp)
    /* B1564 002B0964 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1568 002B0968 AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B156C 002B096C 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B1570 002B0970 AC333650 */  sw         $s3, %lo(D_800D3650)($at)
    /* B1574 002B0974 34420004 */  ori        $v0, $v0, 0x4
    /* B1578 002B0978 00409021 */  addu       $s2, $v0, $zero
    /* B157C 002B097C 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B1580 002B0980 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B0984:
    /* B1584 002B0984 0C0AF7A8 */  jal        osPiGetStatus
    /* B1588 002B0988 00000000 */   nop
    /* B158C 002B098C 30420003 */  andi       $v0, $v0, 0x3
    /* B1590 002B0990 1440FFFC */  bnez       $v0, .L002B0984
    /* B1594 002B0994 24150002 */   addiu     $s5, $zero, 0x2
    /* B1598 002B0998 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B159C 002B099C 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B15A0 002B09A0 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B15A4 002B09A4 24140002 */  addiu      $s4, $zero, 0x2
    /* B15A8 002B09A8 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B15AC 002B09AC A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002B09B0:
    /* B15B0 002B09B0 0C0AF7A8 */  jal        osPiGetStatus
    /* B15B4 002B09B4 00000000 */   nop
    /* B15B8 002B09B8 30420003 */  andi       $v0, $v0, 0x3
    /* B15BC 002B09BC 1440FFFC */  bnez       $v0, .L002B09B0
    /* B15C0 002B09C0 00000000 */   nop
    /* B15C4 002B09C4 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B15C8 002B09C8 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B15CC 002B09CC 00551024 */  and        $v0, $v0, $s5
    /* B15D0 002B09D0 10540009 */  beq        $v0, $s4, .L002B09F8
    /* B15D4 002B09D4 02001021 */   addu      $v0, $s0, $zero
    /* B15D8 002B09D8 14400003 */  bnez       $v0, .L002B09E8
    /* B15DC 002B09DC 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B15E0 002B09E0 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B15E4 002B09E4 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B09E8:
    /* B15E8 002B09E8 1E20FFF1 */  bgtz       $s1, .L002B09B0
    /* B15EC 002B09EC 24020001 */   addiu     $v0, $zero, 0x1
    /* B15F0 002B09F0 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B15F4 002B09F4 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B09F8:
    /* B15F8 002B09F8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B15FC 002B09FC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1600 002B0A00 144000B2 */  bnez       $v0, .L002B0CCC
    /* B1604 002B0A04 00000000 */   nop
    /* B1608 002B0A08 0C0AB96B */  jal        dbgLinkSendByte
    /* B160C 002B0A0C 24040010 */   addiu     $a0, $zero, 0x10
    /* B1610 002B0A10 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1614 002B0A14 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1618 002B0A18 1440000A */  bnez       $v0, .L002B0A44
    /* B161C 002B0A1C 00008021 */   addu      $s0, $zero, $zero
    /* B1620 002B0A20 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B1624 002B0A24 27A40010 */   addiu     $a0, $sp, 0x10
    /* B1628 002B0A28 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B162C 002B0A2C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1630 002B0A30 14400004 */  bnez       $v0, .L002B0A44
    /* B1634 002B0A34 00000000 */   nop
    /* B1638 002B0A38 93A20010 */  lbu        $v0, 0x10($sp)
    /* B163C 002B0A3C 38420011 */  xori       $v0, $v0, 0x11
    /* B1640 002B0A40 2C500001 */  sltiu      $s0, $v0, 0x1
  .L002B0A44:
    /* B1644 002B0A44 120000A1 */  beqz       $s0, .L002B0CCC
    /* B1648 002B0A48 00000000 */   nop
    /* B164C 002B0A4C 0C0AB96B */  jal        dbgLinkSendByte
    /* B1650 002B0A50 24040084 */   addiu     $a0, $zero, 0x84
    /* B1654 002B0A54 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1658 002B0A58 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B165C 002B0A5C 1440009B */  bnez       $v0, .L002B0CCC
    /* B1660 002B0A60 00000000 */   nop
    /* B1664 002B0A64 0C0AB96B */  jal        dbgLinkSendByte
    /* B1668 002B0A68 00162602 */   srl       $a0, $s6, 24
    /* B166C 002B0A6C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1670 002B0A70 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1674 002B0A74 14400095 */  bnez       $v0, .L002B0CCC
    /* B1678 002B0A78 00162402 */   srl       $a0, $s6, 16
    /* B167C 002B0A7C 0C0AB96B */  jal        dbgLinkSendByte
    /* B1680 002B0A80 308400FF */   andi      $a0, $a0, 0xFF
    /* B1684 002B0A84 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1688 002B0A88 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B168C 002B0A8C 1440008F */  bnez       $v0, .L002B0CCC
    /* B1690 002B0A90 00162202 */   srl       $a0, $s6, 8
    /* B1694 002B0A94 0C0AB96B */  jal        dbgLinkSendByte
    /* B1698 002B0A98 308400FF */   andi      $a0, $a0, 0xFF
    /* B169C 002B0A9C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B16A0 002B0AA0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B16A4 002B0AA4 14400089 */  bnez       $v0, .L002B0CCC
    /* B16A8 002B0AA8 00000000 */   nop
    /* B16AC 002B0AAC 0C0AB96B */  jal        dbgLinkSendByte
    /* B16B0 002B0AB0 32C400FF */   andi      $a0, $s6, 0xFF
    /* B16B4 002B0AB4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B16B8 002B0AB8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B16BC 002B0ABC 14400083 */  bnez       $v0, .L002B0CCC
    /* B16C0 002B0AC0 00000000 */   nop
    /* B16C4 002B0AC4 0C0AB96B */  jal        dbgLinkSendByte
    /* B16C8 002B0AC8 00172602 */   srl       $a0, $s7, 24
    /* B16CC 002B0ACC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B16D0 002B0AD0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B16D4 002B0AD4 1440007D */  bnez       $v0, .L002B0CCC
    /* B16D8 002B0AD8 00172402 */   srl       $a0, $s7, 16
    /* B16DC 002B0ADC 0C0AB96B */  jal        dbgLinkSendByte
    /* B16E0 002B0AE0 308400FF */   andi      $a0, $a0, 0xFF
    /* B16E4 002B0AE4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B16E8 002B0AE8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B16EC 002B0AEC 14400077 */  bnez       $v0, .L002B0CCC
    /* B16F0 002B0AF0 00172202 */   srl       $a0, $s7, 8
    /* B16F4 002B0AF4 0C0AB96B */  jal        dbgLinkSendByte
    /* B16F8 002B0AF8 308400FF */   andi      $a0, $a0, 0xFF
    /* B16FC 002B0AFC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1700 002B0B00 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1704 002B0B04 14400071 */  bnez       $v0, .L002B0CCC
    /* B1708 002B0B08 00000000 */   nop
    /* B170C 002B0B0C 0C0AB96B */  jal        dbgLinkSendByte
    /* B1710 002B0B10 32E400FF */   andi      $a0, $s7, 0xFF
    /* B1714 002B0B14 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1718 002B0B18 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B171C 002B0B1C 1440006B */  bnez       $v0, .L002B0CCC
    /* B1720 002B0B20 00000000 */   nop
    /* B1724 002B0B24 0C0AB96B */  jal        dbgLinkSendByte
    /* B1728 002B0B28 001E2602 */   srl       $a0, $fp, 24
    /* B172C 002B0B2C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1730 002B0B30 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1734 002B0B34 14400065 */  bnez       $v0, .L002B0CCC
    /* B1738 002B0B38 001E2402 */   srl       $a0, $fp, 16
    /* B173C 002B0B3C 0C0AB96B */  jal        dbgLinkSendByte
    /* B1740 002B0B40 308400FF */   andi      $a0, $a0, 0xFF
    /* B1744 002B0B44 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1748 002B0B48 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B174C 002B0B4C 1440005F */  bnez       $v0, .L002B0CCC
    /* B1750 002B0B50 001E2202 */   srl       $a0, $fp, 8
    /* B1754 002B0B54 0C0AB96B */  jal        dbgLinkSendByte
    /* B1758 002B0B58 308400FF */   andi      $a0, $a0, 0xFF
    /* B175C 002B0B5C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1760 002B0B60 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1764 002B0B64 14400059 */  bnez       $v0, .L002B0CCC
    /* B1768 002B0B68 00000000 */   nop
    /* B176C 002B0B6C 0C0AB96B */  jal        dbgLinkSendByte
    /* B1770 002B0B70 33C400FF */   andi      $a0, $fp, 0xFF
    /* B1774 002B0B74 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1778 002B0B78 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B177C 002B0B7C 14400053 */  bnez       $v0, .L002B0CCC
    /* B1780 002B0B80 27B20014 */   addiu     $s2, $sp, 0x14
    /* B1784 002B0B84 27B10018 */  addiu      $s1, $sp, 0x18
  .L002B0B88:
    /* B1788 002B0B88 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B178C 002B0B8C AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B1790 002B0B90 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B1794 002B0B94 02202021 */   addu      $a0, $s1, $zero
    /* B1798 002B0B98 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B179C 002B0B9C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B17A0 002B0BA0 1440001D */  bnez       $v0, .L002B0C18
    /* B17A4 002B0BA4 02601021 */   addu      $v0, $s3, $zero
    /* B17A8 002B0BA8 93A20018 */  lbu        $v0, 0x18($sp)
    /* B17AC 002B0BAC 02202021 */  addu       $a0, $s1, $zero
    /* B17B0 002B0BB0 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B17B4 002B0BB4 00028200 */   sll       $s0, $v0, 8
    /* B17B8 002B0BB8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B17BC 002B0BBC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B17C0 002B0BC0 14400015 */  bnez       $v0, .L002B0C18
    /* B17C4 002B0BC4 02601021 */   addu      $v0, $s3, $zero
    /* B17C8 002B0BC8 93A20018 */  lbu        $v0, 0x18($sp)
    /* B17CC 002B0BCC 02202021 */  addu       $a0, $s1, $zero
    /* B17D0 002B0BD0 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B17D4 002B0BD4 02028025 */   or        $s0, $s0, $v0
    /* B17D8 002B0BD8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B17DC 002B0BDC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B17E0 002B0BE0 1440000C */  bnez       $v0, .L002B0C14
    /* B17E4 002B0BE4 00108200 */   sll       $s0, $s0, 8
    /* B17E8 002B0BE8 93A20018 */  lbu        $v0, 0x18($sp)
    /* B17EC 002B0BEC 02202021 */  addu       $a0, $s1, $zero
    /* B17F0 002B0BF0 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B17F4 002B0BF4 02028025 */   or        $s0, $s0, $v0
    /* B17F8 002B0BF8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B17FC 002B0BFC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1800 002B0C00 14400004 */  bnez       $v0, .L002B0C14
    /* B1804 002B0C04 00108200 */   sll       $s0, $s0, 8
    /* B1808 002B0C08 93A20018 */  lbu        $v0, 0x18($sp)
    /* B180C 002B0C0C 02028025 */  or         $s0, $s0, $v0
    /* B1810 002B0C10 AE500000 */  sw         $s0, 0x0($s2)
  .L002B0C14:
    /* B1814 002B0C14 02601021 */  addu       $v0, $s3, $zero
  .L002B0C18:
    /* B1818 002B0C18 18400005 */  blez       $v0, .L002B0C30
    /* B181C 002B0C1C 2673FFFF */   addiu     $s3, $s3, -0x1
    /* B1820 002B0C20 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1824 002B0C24 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1828 002B0C28 1440FFD7 */  bnez       $v0, .L002B0B88
    /* B182C 002B0C2C 00000000 */   nop
  .L002B0C30:
    /* B1830 002B0C30 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1834 002B0C34 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1838 002B0C38 14400024 */  bnez       $v0, .L002B0CCC
    /* B183C 002B0C3C 00000000 */   nop
    /* B1840 002B0C40 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B1844 002B0C44 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B1848 002B0C48 304200FB */  andi       $v0, $v0, 0xFB
    /* B184C 002B0C4C 00409021 */  addu       $s2, $v0, $zero
    /* B1850 002B0C50 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B1854 002B0C54 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B0C58:
    /* B1858 002B0C58 0C0AF7A8 */  jal        osPiGetStatus
    /* B185C 002B0C5C 00000000 */   nop
    /* B1860 002B0C60 30420003 */  andi       $v0, $v0, 0x3
    /* B1864 002B0C64 1440FFFC */  bnez       $v0, .L002B0C58
    /* B1868 002B0C68 24104E20 */   addiu     $s0, $zero, 0x4E20
    /* B186C 002B0C6C 24140002 */  addiu      $s4, $zero, 0x2
    /* B1870 002B0C70 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B1874 002B0C74 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B1878 002B0C78 00009821 */  addu       $s3, $zero, $zero
    /* B187C 002B0C7C 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B1880 002B0C80 A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002B0C84:
    /* B1884 002B0C84 0C0AF7A8 */  jal        osPiGetStatus
    /* B1888 002B0C88 00000000 */   nop
    /* B188C 002B0C8C 30420003 */  andi       $v0, $v0, 0x3
    /* B1890 002B0C90 1440FFFC */  bnez       $v0, .L002B0C84
    /* B1894 002B0C94 00000000 */   nop
    /* B1898 002B0C98 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B189C 002B0C9C 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B18A0 002B0CA0 00541024 */  and        $v0, $v0, $s4
    /* B18A4 002B0CA4 10530009 */  beq        $v0, $s3, .L002B0CCC
    /* B18A8 002B0CA8 02001021 */   addu      $v0, $s0, $zero
    /* B18AC 002B0CAC 14400003 */  bnez       $v0, .L002B0CBC
    /* B18B0 002B0CB0 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B18B4 002B0CB4 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B18B8 002B0CB8 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B0CBC:
    /* B18BC 002B0CBC 1E20FFF1 */  bgtz       $s1, .L002B0C84
    /* B18C0 002B0CC0 24020001 */   addiu     $v0, $zero, 0x1
    /* B18C4 002B0CC4 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B18C8 002B0CC8 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B0CCC:
    /* B18CC 002B0CCC 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B18D0 002B0CD0 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B18D4 002B0CD4 304200FB */  andi       $v0, $v0, 0xFB
    /* B18D8 002B0CD8 00408021 */  addu       $s0, $v0, $zero
    /* B18DC 002B0CDC 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B18E0 002B0CE0 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B0CE4:
    /* B18E4 002B0CE4 0C0AF7A8 */  jal        osPiGetStatus
    /* B18E8 002B0CE8 00000000 */   nop
    /* B18EC 002B0CEC 30420003 */  andi       $v0, $v0, 0x3
    /* B18F0 002B0CF0 1440FFFC */  bnez       $v0, .L002B0CE4
    /* B18F4 002B0CF4 24030001 */   addiu     $v1, $zero, 0x1
    /* B18F8 002B0CF8 8FA20014 */  lw         $v0, 0x14($sp)
    /* B18FC 002B0CFC 8FBF0044 */  lw         $ra, 0x44($sp)
    /* B1900 002B0D00 8FBE0040 */  lw         $fp, 0x40($sp)
    /* B1904 002B0D04 8FB7003C */  lw         $s7, 0x3C($sp)
    /* B1908 002B0D08 8FB60038 */  lw         $s6, 0x38($sp)
    /* B190C 002B0D0C 8FB50034 */  lw         $s5, 0x34($sp)
    /* B1910 002B0D10 8FB40030 */  lw         $s4, 0x30($sp)
    /* B1914 002B0D14 8FB3002C */  lw         $s3, 0x2C($sp)
    /* B1918 002B0D18 8FB20028 */  lw         $s2, 0x28($sp)
    /* B191C 002B0D1C 8FB10024 */  lw         $s1, 0x24($sp)
    /* B1920 002B0D20 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B1924 002B0D24 A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* B1928 002B0D28 8FB00020 */  lw         $s0, 0x20($sp)
    /* B192C 002B0D2C 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B1930 002B0D30 AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B1934 002B0D34 03E00008 */  jr         $ra
    /* B1938 002B0D38 27BD0048 */   addiu     $sp, $sp, 0x48
endlabel dbgHostFseek
