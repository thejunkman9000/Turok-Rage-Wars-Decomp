.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC205C-0xC21F8 (VRAM 0x002C145C) */
glabel __osEnqueueAndYield
    /* C205C 002C145C 3C05800E */  lui        $a1, %hi(__osRunningThread)
    /* C2060 002C1460 8CA592A0 */  lw         $a1, %lo(__osRunningThread)($a1)
    /* C2064 002C1464 40086000 */  mfc0       $t0, $12 /* handwritten instruction */
    /* C2068 002C1468 00000000 */  nop
    /* C206C 002C146C 35080002 */  ori        $t0, $t0, 0x2
    /* C2070 002C1470 ACA80118 */  sw         $t0, 0x118($a1)
    /* C2074 002C1474 FCB00098 */  sd         $s0, 0x98($a1)
    /* C2078 002C1478 FCB100A0 */  sd         $s1, 0xA0($a1)
    /* C207C 002C147C FCB200A8 */  sd         $s2, 0xA8($a1)
    /* C2080 002C1480 FCB300B0 */  sd         $s3, 0xB0($a1)
    /* C2084 002C1484 FCB400B8 */  sd         $s4, 0xB8($a1)
    /* C2088 002C1488 FCB500C0 */  sd         $s5, 0xC0($a1)
    /* C208C 002C148C FCB600C8 */  sd         $s6, 0xC8($a1)
    /* C2090 002C1490 FCB700D0 */  sd         $s7, 0xD0($a1)
    /* C2094 002C1494 FCBC00E8 */  sd         $gp, 0xE8($a1)
    /* C2098 002C1498 FCBD00F0 */  sd         $sp, 0xF0($a1)
    /* C209C 002C149C FCBE00F8 */  sd         $fp, 0xF8($a1)
    /* C20A0 002C14A0 FCBF0100 */  sd         $ra, 0x100($a1)
    /* C20A4 002C14A4 ACBF011C */  sw         $ra, 0x11C($a1)
    /* C20A8 002C14A8 8CBB0018 */  lw         $k1, 0x18($a1) /* handwritten instruction */
    /* C20AC 002C14AC 00000000 */  nop
    /* C20B0 002C14B0 13600029 */  beqz       $k1, .L002C1558 /* handwritten instruction */
    /* C20B4 002C14B4 00000000 */   nop
    /* C20B8 002C14B8 445BF800 */  cfc1       $k1, $31
    /* C20BC 002C14BC 00000000 */  nop
    /* C20C0 002C14C0 ACBB012C */  sw         $k1, 0x12C($a1) /* handwritten instruction */
    /* C20C4 002C14C4 F4A00130 */  sdc1       $fv0, 0x130($a1)
    /* C20C8 002C14C8 F4A20138 */  sdc1       $fv1, 0x138($a1)
    /* C20CC 002C14CC F4A40140 */  sdc1       $ft0, 0x140($a1)
    /* C20D0 002C14D0 F4A80150 */  sdc1       $ft2, 0x150($a1)
    /* C20D4 002C14D4 F4AA0158 */  sdc1       $ft3, 0x158($a1)
    /* C20D8 002C14D8 F4AC0160 */  sdc1       $fa0, 0x160($a1)
    /* C20DC 002C14DC F4AE0168 */  sdc1       $fa1, 0x168($a1)
    /* C20E0 002C14E0 F4B00170 */  sdc1       $ft4, 0x170($a1)
    /* C20E4 002C14E4 F4B20178 */  sdc1       $ft5, 0x178($a1)
    /* C20E8 002C14E8 F4B40180 */  sdc1       $fs0, 0x180($a1)
    /* C20EC 002C14EC F4B60188 */  sdc1       $fs1, 0x188($a1)
    /* C20F0 002C14F0 F4B80190 */  sdc1       $fs2, 0x190($a1)
    /* C20F4 002C14F4 F4BA0198 */  sdc1       $fs3, 0x198($a1)
    /* C20F8 002C14F8 F4BC01A0 */  sdc1       $fs4, 0x1A0($a1)
    /* C20FC 002C14FC F4BE01A8 */  sdc1       $fs5, 0x1A8($a1)
    /* C2100 002C1500 8CBB0118 */  lw         $k1, 0x118($a1) /* handwritten instruction */
    /* C2104 002C1504 00000000 */  nop
    /* C2108 002C1508 3C010400 */  lui        $at, (0x4000000 >> 16)
    /* C210C 002C150C 0361D824 */  and        $k1, $k1, $at
    /* C2110 002C1510 13600011 */  beqz       $k1, .L002C1558 /* handwritten instruction */
    /* C2114 002C1514 00000000 */   nop
    /* C2118 002C1518 F4A101B0 */  sdc1       $fv0f, 0x1B0($a1)
    /* C211C 002C151C F4A301B8 */  sdc1       $fv1f, 0x1B8($a1)
    /* C2120 002C1520 F4A501C0 */  sdc1       $ft0f, 0x1C0($a1)
    /* C2124 002C1524 F4A701C8 */  sdc1       $ft1f, 0x1C8($a1)
    /* C2128 002C1528 F4A901D0 */  sdc1       $ft2f, 0x1D0($a1)
    /* C212C 002C152C F4AB01D8 */  sdc1       $ft3f, 0x1D8($a1)
    /* C2130 002C1530 F4AD01E0 */  sdc1       $fa0f, 0x1E0($a1)
    /* C2134 002C1534 F4AF01E8 */  sdc1       $fa1f, 0x1E8($a1)
    /* C2138 002C1538 F4B101F0 */  sdc1       $ft4f, 0x1F0($a1)
    /* C213C 002C153C F4B301F8 */  sdc1       $ft5f, 0x1F8($a1)
    /* C2140 002C1540 F4B50200 */  sdc1       $fs0f, 0x200($a1)
    /* C2144 002C1544 F4B70208 */  sdc1       $fs1f, 0x208($a1)
    /* C2148 002C1548 F4B90210 */  sdc1       $fs2f, 0x210($a1)
    /* C214C 002C154C F4BB0218 */  sdc1       $fs3f, 0x218($a1)
    /* C2150 002C1550 F4BD0220 */  sdc1       $fs4f, 0x220($a1)
    /* C2154 002C1554 F4BF0228 */  sdc1       $fs5f, 0x228($a1)
  .L002C1558:
    /* C2158 002C1558 8CBB0118 */  lw         $k1, 0x118($a1) /* handwritten instruction */
    /* C215C 002C155C 00000000 */  nop
    /* C2160 002C1560 3369FF00 */  andi       $t1, $k1, 0xFF00 /* handwritten instruction */
    /* C2164 002C1564 1120000F */  beqz       $t1, .L002C15A4
    /* C2168 002C1568 00000000 */   nop
    /* C216C 002C156C 3C08800E */  lui        $t0, %hi(__OSGlobalIntMask)
    /* C2170 002C1570 25089288 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* C2174 002C1574 00000000 */  nop
    /* C2178 002C1578 8D080000 */  lw         $t0, 0x0($t0)
    /* C217C 002C157C 00000000 */  nop
    /* C2180 002C1580 2401FFFF */  addiu      $at, $zero, -0x1
    /* C2184 002C1584 01014026 */  xor        $t0, $t0, $at
    /* C2188 002C1588 3108FF00 */  andi       $t0, $t0, 0xFF00
    /* C218C 002C158C 01284825 */  or         $t1, $t1, $t0
    /* C2190 002C1590 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* C2194 002C1594 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* C2198 002C1598 0361D824 */  and        $k1, $k1, $at
    /* C219C 002C159C 0369D825 */  or         $k1, $k1, $t1
    /* C21A0 002C15A0 ACBB0118 */  sw         $k1, 0x118($a1) /* handwritten instruction */
  .L002C15A4:
    /* C21A4 002C15A4 3C1BA430 */  lui        $k1, %hi(MI_INTR_MASK_REG) /* handwritten instruction */
    /* C21A8 002C15A8 8F7B000C */  lw         $k1, %lo(MI_INTR_MASK_REG)($k1) /* handwritten instruction */
    /* C21AC 002C15AC 00000000 */  nop
    /* C21B0 002C15B0 1360000C */  beqz       $k1, .L002C15E4 /* handwritten instruction */
    /* C21B4 002C15B4 00000000 */   nop
    /* C21B8 002C15B8 3C1A800E */  lui        $k0, %hi(__OSGlobalIntMask) /* handwritten instruction */
    /* C21BC 002C15BC 275A9288 */  addiu      $k0, $k0, %lo(__OSGlobalIntMask) /* handwritten instruction */
    /* C21C0 002C15C0 8F5A0000 */  lw         $k0, 0x0($k0) /* handwritten instruction */
    /* C21C4 002C15C4 00000000 */  nop
    /* C21C8 002C15C8 001AD402 */  srl        $k0, $k0, 16
    /* C21CC 002C15CC 2401FFFF */  addiu      $at, $zero, -0x1
    /* C21D0 002C15D0 0341D026 */  xor        $k0, $k0, $at
    /* C21D4 002C15D4 8CA80128 */  lw         $t0, 0x128($a1)
    /* C21D8 002C15D8 335A003F */  andi       $k0, $k0, 0x3F /* handwritten instruction */
    /* C21DC 002C15DC 0348D024 */  and        $k0, $k0, $t0
    /* C21E0 002C15E0 037AD825 */  or         $k1, $k1, $k0
  .L002C15E4:
    /* C21E4 002C15E4 10800003 */  beqz       $a0, .L002C15F4
    /* C21E8 002C15E8 ACBB0128 */   sw        $k1, 0x128($a1) /* handwritten instruction */
    /* C21EC 002C15EC 0C0B057E */  jal        __osEnqueueThread
    /* C21F0 002C15F0 00000000 */   nop
  .L002C15F4:
    /* C21F4 002C15F4 080B0598 */  j          __osDispatchThread
endlabel __osEnqueueAndYield
