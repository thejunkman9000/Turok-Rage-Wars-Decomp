.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2260-0xC245C (VRAM 0x002C1660) */
glabel __osDispatchThread
    /* C2260 002C1660 3C04800E */  lui        $a0, %hi(__osRunQueue)
    /* C2264 002C1664 24849298 */  addiu      $a0, $a0, %lo(__osRunQueue)
    /* C2268 002C1668 0C0B0592 */  jal        __osPopThread
    /* C226C 002C166C 00000000 */   nop
    /* C2270 002C1670 3C01800E */  lui        $at, %hi(__osRunningThread)
    /* C2274 002C1674 AC2292A0 */  sw         $v0, %lo(__osRunningThread)($at)
    /* C2278 002C1678 24080004 */  addiu      $t0, $zero, 0x4
    /* C227C 002C167C A4480010 */  sh         $t0, 0x10($v0)
    /* C2280 002C1680 0040D021 */  addu       $k0, $v0, $zero
    /* C2284 002C1684 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* C2288 002C1688 3C08800E */  lui        $t0, %hi(__OSGlobalIntMask)
    /* C228C 002C168C 25089288 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* C2290 002C1690 8D080000 */  lw         $t0, 0x0($t0)
    /* C2294 002C1694 00000000 */  nop
    /* C2298 002C1698 3108FF00 */  andi       $t0, $t0, 0xFF00
    /* C229C 002C169C 3369FF00 */  andi       $t1, $k1, 0xFF00 /* handwritten instruction */
    /* C22A0 002C16A0 01284824 */  and        $t1, $t1, $t0
    /* C22A4 002C16A4 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* C22A8 002C16A8 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* C22AC 002C16AC 0361D824 */  and        $k1, $k1, $at
    /* C22B0 002C16B0 0369D825 */  or         $k1, $k1, $t1
    /* C22B4 002C16B4 00000000 */  nop
    /* C22B8 002C16B8 409B6000 */  mtc0       $k1, $12 /* handwritten instruction */
    /* C22BC 002C16BC 00000000 */  nop
    /* C22C0 002C16C0 DF410020 */  ld         $at, 0x20($k0) /* handwritten instruction */
    /* C22C4 002C16C4 DF420028 */  ld         $v0, 0x28($k0) /* handwritten instruction */
    /* C22C8 002C16C8 DF430030 */  ld         $v1, 0x30($k0) /* handwritten instruction */
    /* C22CC 002C16CC DF440038 */  ld         $a0, 0x38($k0) /* handwritten instruction */
    /* C22D0 002C16D0 DF450040 */  ld         $a1, 0x40($k0) /* handwritten instruction */
    /* C22D4 002C16D4 DF460048 */  ld         $a2, 0x48($k0) /* handwritten instruction */
    /* C22D8 002C16D8 DF470050 */  ld         $a3, 0x50($k0) /* handwritten instruction */
    /* C22DC 002C16DC DF480058 */  ld         $t0, 0x58($k0) /* handwritten instruction */
    /* C22E0 002C16E0 DF490060 */  ld         $t1, 0x60($k0) /* handwritten instruction */
    /* C22E4 002C16E4 DF4A0068 */  ld         $t2, 0x68($k0) /* handwritten instruction */
    /* C22E8 002C16E8 DF4B0070 */  ld         $t3, 0x70($k0) /* handwritten instruction */
    /* C22EC 002C16EC DF4C0078 */  ld         $t4, 0x78($k0) /* handwritten instruction */
    /* C22F0 002C16F0 DF4D0080 */  ld         $t5, 0x80($k0) /* handwritten instruction */
    /* C22F4 002C16F4 DF4E0088 */  ld         $t6, 0x88($k0) /* handwritten instruction */
    /* C22F8 002C16F8 DF4F0090 */  ld         $t7, 0x90($k0) /* handwritten instruction */
    /* C22FC 002C16FC DF500098 */  ld         $s0, 0x98($k0) /* handwritten instruction */
    /* C2300 002C1700 DF5100A0 */  ld         $s1, 0xA0($k0) /* handwritten instruction */
    /* C2304 002C1704 DF5200A8 */  ld         $s2, 0xA8($k0) /* handwritten instruction */
    /* C2308 002C1708 DF5300B0 */  ld         $s3, 0xB0($k0) /* handwritten instruction */
    /* C230C 002C170C DF5400B8 */  ld         $s4, 0xB8($k0) /* handwritten instruction */
    /* C2310 002C1710 DF5500C0 */  ld         $s5, 0xC0($k0) /* handwritten instruction */
    /* C2314 002C1714 DF5600C8 */  ld         $s6, 0xC8($k0) /* handwritten instruction */
    /* C2318 002C1718 DF5700D0 */  ld         $s7, 0xD0($k0) /* handwritten instruction */
    /* C231C 002C171C DF5800D8 */  ld         $t8, 0xD8($k0) /* handwritten instruction */
    /* C2320 002C1720 DF5900E0 */  ld         $t9, 0xE0($k0) /* handwritten instruction */
    /* C2324 002C1724 DF5C00E8 */  ld         $gp, 0xE8($k0) /* handwritten instruction */
    /* C2328 002C1728 DF5D00F0 */  ld         $sp, 0xF0($k0) /* handwritten instruction */
    /* C232C 002C172C DF5E00F8 */  ld         $fp, 0xF8($k0) /* handwritten instruction */
    /* C2330 002C1730 DF5F0100 */  ld         $ra, 0x100($k0) /* handwritten instruction */
    /* C2334 002C1734 DF5B0108 */  ld         $k1, 0x108($k0) /* handwritten instruction */
    /* C2338 002C1738 00000000 */  nop
    /* C233C 002C173C 03600013 */  mtlo       $k1
    /* C2340 002C1740 DF5B0110 */  ld         $k1, 0x110($k0) /* handwritten instruction */
    /* C2344 002C1744 00000000 */  nop
    /* C2348 002C1748 03600011 */  mthi       $k1
    /* C234C 002C174C 8F5B011C */  lw         $k1, 0x11C($k0) /* handwritten instruction */
    /* C2350 002C1750 00000000 */  nop
    /* C2354 002C1754 409B7000 */  mtc0       $k1, $14 /* handwritten instruction */
    /* C2358 002C1758 8F5B0018 */  lw         $k1, 0x18($k0) /* handwritten instruction */
    /* C235C 002C175C 00000000 */  nop
    /* C2360 002C1760 1360002A */  beqz       $k1, .L002C180C /* handwritten instruction */
    /* C2364 002C1764 00000000 */   nop
    /* C2368 002C1768 8F5B012C */  lw         $k1, 0x12C($k0) /* handwritten instruction */
    /* C236C 002C176C 00000000 */  nop
    /* C2370 002C1770 44DBF800 */  ctc1       $k1, $31
    /* C2374 002C1774 D7400130 */  ldc1       $fv0, 0x130($k0)
    /* C2378 002C1778 D7420138 */  ldc1       $fv1, 0x138($k0)
    /* C237C 002C177C D7440140 */  ldc1       $ft0, 0x140($k0)
    /* C2380 002C1780 D7460148 */  ldc1       $ft1, 0x148($k0)
    /* C2384 002C1784 D7480150 */  ldc1       $ft2, 0x150($k0)
    /* C2388 002C1788 D74A0158 */  ldc1       $ft3, 0x158($k0)
    /* C238C 002C178C D74C0160 */  ldc1       $fa0, 0x160($k0)
    /* C2390 002C1790 D74E0168 */  ldc1       $fa1, 0x168($k0)
    /* C2394 002C1794 D7500170 */  ldc1       $ft4, 0x170($k0)
    /* C2398 002C1798 D7520178 */  ldc1       $ft5, 0x178($k0)
    /* C239C 002C179C D7540180 */  ldc1       $fs0, 0x180($k0)
    /* C23A0 002C17A0 D7560188 */  ldc1       $fs1, 0x188($k0)
    /* C23A4 002C17A4 D7580190 */  ldc1       $fs2, 0x190($k0)
    /* C23A8 002C17A8 D75A0198 */  ldc1       $fs3, 0x198($k0)
    /* C23AC 002C17AC D75C01A0 */  ldc1       $fs4, 0x1A0($k0)
    /* C23B0 002C17B0 D75E01A8 */  ldc1       $fs5, 0x1A8($k0)
    /* C23B4 002C17B4 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* C23B8 002C17B8 00000000 */  nop
    /* C23BC 002C17BC 001BDC02 */  srl        $k1, $k1, 16
    /* C23C0 002C17C0 337B0400 */  andi       $k1, $k1, 0x400 /* handwritten instruction */
    /* C23C4 002C17C4 13600011 */  beqz       $k1, .L002C180C /* handwritten instruction */
    /* C23C8 002C17C8 00000000 */   nop
    /* C23CC 002C17CC D74101B0 */  ldc1       $fv0f, 0x1B0($k0)
    /* C23D0 002C17D0 D74301B8 */  ldc1       $fv1f, 0x1B8($k0)
    /* C23D4 002C17D4 D74501C0 */  ldc1       $ft0f, 0x1C0($k0)
    /* C23D8 002C17D8 D74701C8 */  ldc1       $ft1f, 0x1C8($k0)
    /* C23DC 002C17DC D74901D0 */  ldc1       $ft2f, 0x1D0($k0)
    /* C23E0 002C17E0 D74B01D8 */  ldc1       $ft3f, 0x1D8($k0)
    /* C23E4 002C17E4 D74D01E0 */  ldc1       $fa0f, 0x1E0($k0)
    /* C23E8 002C17E8 D74F01E8 */  ldc1       $fa1f, 0x1E8($k0)
    /* C23EC 002C17EC D75101F0 */  ldc1       $ft4f, 0x1F0($k0)
    /* C23F0 002C17F0 D75301F8 */  ldc1       $ft5f, 0x1F8($k0)
    /* C23F4 002C17F4 D7550200 */  ldc1       $fs0f, 0x200($k0)
    /* C23F8 002C17F8 D7570208 */  ldc1       $fs1f, 0x208($k0)
    /* C23FC 002C17FC D7590210 */  ldc1       $fs2f, 0x210($k0)
    /* C2400 002C1800 D75B0218 */  ldc1       $fs3f, 0x218($k0)
    /* C2404 002C1804 D75D0220 */  ldc1       $fs4f, 0x220($k0)
    /* C2408 002C1808 D75F0228 */  ldc1       $fs5f, 0x228($k0)
  .L002C180C:
    /* C240C 002C180C 8F5B0128 */  lw         $k1, 0x128($k0) /* handwritten instruction */
    /* C2410 002C1810 3C1A800E */  lui        $k0, %hi(__OSGlobalIntMask) /* handwritten instruction */
    /* C2414 002C1814 275A9288 */  addiu      $k0, $k0, %lo(__OSGlobalIntMask) /* handwritten instruction */
    /* C2418 002C1818 8F5A0000 */  lw         $k0, 0x0($k0) /* handwritten instruction */
    /* C241C 002C181C 00000000 */  nop
    /* C2420 002C1820 001AD402 */  srl        $k0, $k0, 16
    /* C2424 002C1824 037AD824 */  and        $k1, $k1, $k0
    /* C2428 002C1828 001BD840 */  sll        $k1, $k1, 1
    /* C242C 002C182C 3C1A800D */  lui        $k0, %hi(__osRcpImTable) /* handwritten instruction */
    /* C2430 002C1830 275ACCC0 */  addiu      $k0, $k0, %lo(__osRcpImTable) /* handwritten instruction */
    /* C2434 002C1834 037AD821 */  addu       $k1, $k1, $k0
    /* C2438 002C1838 977B0000 */  lhu        $k1, 0x0($k1) /* handwritten instruction */
    /* C243C 002C183C 3C1AA430 */  lui        $k0, %hi(MI_INTR_MASK_REG) /* handwritten instruction */
    /* C2440 002C1840 375A000C */  ori        $k0, $k0, %lo(MI_INTR_MASK_REG) /* handwritten instruction */
    /* C2444 002C1844 AF5B0000 */  sw         $k1, 0x0($k0) /* handwritten instruction */
    /* C2448 002C1848 00000000 */  nop
    /* C244C 002C184C 00000000 */  nop
    /* C2450 002C1850 00000000 */  nop
    /* C2454 002C1854 00000000 */  nop
    /* C2458 002C1858 42000018 */  eret /* handwritten instruction */
endlabel __osDispatchThread
