.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBC870-0xBCF6C (VRAM 0x002BBC70) */
.globl __osExceptionPreamble
__osExceptionPreamble:
    /* BC870 002BBC70 3C1A002C */  lui        $k0, %hi(__osException) /* handwritten instruction */
    /* BC874 002BBC74 275ABC80 */  addiu      $k0, $k0, %lo(__osException) /* handwritten instruction */
    /* BC878 002BBC78 03400008 */  jr         $k0
    /* BC87C 002BBC7C 00000000 */  nop
.globl __osException
__osException:
    /* BC880 002BBC80 3C1A8015 */  lui        $k0, %hi(__osThreadSave) /* handwritten instruction */
    /* BC884 002BBC84 275AABD0 */  addiu      $k0, $k0, %lo(__osThreadSave) /* handwritten instruction */
    /* BC888 002BBC88 FF410020 */  sd         $at, 0x20($k0) /* handwritten instruction */
    /* BC88C 002BBC8C 401B6000 */  mfc0       $k1, $12 /* handwritten instruction */
    /* BC890 002BBC90 00000000 */  nop
    /* BC894 002BBC94 AF5B0118 */  sw         $k1, 0x118($k0) /* handwritten instruction */
    /* BC898 002BBC98 2401FFFC */  addiu      $at, $zero, -0x4
    /* BC89C 002BBC9C 0361D824 */  and        $k1, $k1, $at
    /* BC8A0 002BBCA0 409B6000 */  mtc0       $k1, $12 /* handwritten instruction */
    /* BC8A4 002BBCA4 FF480058 */  sd         $t0, 0x58($k0) /* handwritten instruction */
    /* BC8A8 002BBCA8 FF490060 */  sd         $t1, 0x60($k0) /* handwritten instruction */
    /* BC8AC 002BBCAC FF4A0068 */  sd         $t2, 0x68($k0) /* handwritten instruction */
    /* BC8B0 002BBCB0 AF400018 */  sw         $zero, 0x18($k0) /* handwritten instruction */
    /* BC8B4 002BBCB4 40086800 */  mfc0       $t0, $13 /* handwritten instruction */
    /* BC8B8 002BBCB8 03404021 */  addu       $t0, $k0, $zero
    /* BC8BC 002BBCBC 3C1A800D */  lui        $k0, %hi(__osRunningThread) /* handwritten instruction */
    /* BC8C0 002BBCC0 8F5A5270 */  lw         $k0, %lo(__osRunningThread)($k0) /* handwritten instruction */
    /* BC8C4 002BBCC4 DD090020 */  ld         $t1, 0x20($t0)
    /* BC8C8 002BBCC8 DD0A0118 */  ld         $t2, 0x118($t0)
    /* BC8CC 002BBCCC FF490020 */  sd         $t1, 0x20($k0) /* handwritten instruction */
    /* BC8D0 002BBCD0 FF4A0118 */  sd         $t2, 0x118($k0) /* handwritten instruction */
    /* BC8D4 002BBCD4 DD090058 */  ld         $t1, 0x58($t0)
    /* BC8D8 002BBCD8 DD0A0060 */  ld         $t2, 0x60($t0)
    /* BC8DC 002BBCDC FF490058 */  sd         $t1, 0x58($k0) /* handwritten instruction */
    /* BC8E0 002BBCE0 FF4A0060 */  sd         $t2, 0x60($k0) /* handwritten instruction */
    /* BC8E4 002BBCE4 DD090068 */  ld         $t1, 0x68($t0)
    /* BC8E8 002BBCE8 FF420028 */  sd         $v0, 0x28($k0) /* handwritten instruction */
    /* BC8EC 002BBCEC FF490068 */  sd         $t1, 0x68($k0) /* handwritten instruction */
    /* BC8F0 002BBCF0 FF430030 */  sd         $v1, 0x30($k0) /* handwritten instruction */
    /* BC8F4 002BBCF4 FF440038 */  sd         $a0, 0x38($k0) /* handwritten instruction */
    /* BC8F8 002BBCF8 FF450040 */  sd         $a1, 0x40($k0) /* handwritten instruction */
    /* BC8FC 002BBCFC FF460048 */  sd         $a2, 0x48($k0) /* handwritten instruction */
    /* BC900 002BBD00 FF470050 */  sd         $a3, 0x50($k0) /* handwritten instruction */
    /* BC904 002BBD04 FF4B0070 */  sd         $t3, 0x70($k0) /* handwritten instruction */
    /* BC908 002BBD08 FF4C0078 */  sd         $t4, 0x78($k0) /* handwritten instruction */
    /* BC90C 002BBD0C FF4D0080 */  sd         $t5, 0x80($k0) /* handwritten instruction */
    /* BC910 002BBD10 FF4E0088 */  sd         $t6, 0x88($k0) /* handwritten instruction */
    /* BC914 002BBD14 FF4F0090 */  sd         $t7, 0x90($k0) /* handwritten instruction */
    /* BC918 002BBD18 FF500098 */  sd         $s0, 0x98($k0) /* handwritten instruction */
    /* BC91C 002BBD1C FF5100A0 */  sd         $s1, 0xA0($k0) /* handwritten instruction */
    /* BC920 002BBD20 FF5200A8 */  sd         $s2, 0xA8($k0) /* handwritten instruction */
    /* BC924 002BBD24 FF5300B0 */  sd         $s3, 0xB0($k0) /* handwritten instruction */
    /* BC928 002BBD28 FF5400B8 */  sd         $s4, 0xB8($k0) /* handwritten instruction */
    /* BC92C 002BBD2C FF5500C0 */  sd         $s5, 0xC0($k0) /* handwritten instruction */
    /* BC930 002BBD30 FF5600C8 */  sd         $s6, 0xC8($k0) /* handwritten instruction */
    /* BC934 002BBD34 FF5700D0 */  sd         $s7, 0xD0($k0) /* handwritten instruction */
    /* BC938 002BBD38 FF5800D8 */  sd         $t8, 0xD8($k0) /* handwritten instruction */
    /* BC93C 002BBD3C FF5900E0 */  sd         $t9, 0xE0($k0) /* handwritten instruction */
    /* BC940 002BBD40 FF5C00E8 */  sd         $gp, 0xE8($k0) /* handwritten instruction */
    /* BC944 002BBD44 FF5D00F0 */  sd         $sp, 0xF0($k0) /* handwritten instruction */
    /* BC948 002BBD48 FF5E00F8 */  sd         $fp, 0xF8($k0) /* handwritten instruction */
    /* BC94C 002BBD4C FF5F0100 */  sd         $ra, 0x100($k0) /* handwritten instruction */
    /* BC950 002BBD50 00004012 */  mflo       $t0
    /* BC954 002BBD54 FF480108 */  sd         $t0, 0x108($k0) /* handwritten instruction */
    /* BC958 002BBD58 00004010 */  mfhi       $t0
    /* BC95C 002BBD5C FF480110 */  sd         $t0, 0x110($k0) /* handwritten instruction */
    /* BC960 002BBD60 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* BC964 002BBD64 00000000 */  nop
    /* BC968 002BBD68 3369FF00 */  andi       $t1, $k1, 0xFF00 /* handwritten instruction */
    /* BC96C 002BBD6C 11200014 */  .word 0x11200014
    /* BC970 002BBD70 00000000 */  nop
    /* BC974 002BBD74 3C08800D */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BC978 002BBD78 25085258 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BC97C 002BBD7C 8D080000 */  lw         $t0, 0x0($t0)
    /* BC980 002BBD80 00000000 */  nop
    /* BC984 002BBD84 2401FFFF */  addiu      $at, $zero, -0x1
    /* BC988 002BBD88 01015026 */  xor        $t2, $t0, $at
    /* BC98C 002BBD8C 314AFF00 */  andi       $t2, $t2, 0xFF00
    /* BC990 002BBD90 012A6025 */  or         $t4, $t1, $t2
    /* BC994 002BBD94 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* BC998 002BBD98 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* BC99C 002BBD9C 03615824 */  and        $t3, $k1, $at
    /* BC9A0 002BBDA0 016C5825 */  or         $t3, $t3, $t4
    /* BC9A4 002BBDA4 AF4B0118 */  sw         $t3, 0x118($k0) /* handwritten instruction */
    /* BC9A8 002BBDA8 3108FF00 */  andi       $t0, $t0, 0xFF00
    /* BC9AC 002BBDAC 01284824 */  and        $t1, $t1, $t0
    /* BC9B0 002BBDB0 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* BC9B4 002BBDB4 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* BC9B8 002BBDB8 0361D824 */  and        $k1, $k1, $at
    /* BC9BC 002BBDBC 0369D825 */  or         $k1, $k1, $t1
.Lauto_002BBDC0:
    /* BC9C0 002BBDC0 3C09A430 */  lui        $t1, %hi(MI_INTR_MASK_REG)
    /* BC9C4 002BBDC4 8D29000C */  lw         $t1, %lo(MI_INTR_MASK_REG)($t1)
    /* BC9C8 002BBDC8 00000000 */  nop
    /* BC9CC 002BBDCC 1120000C */  .word 0x1120000C
    /* BC9D0 002BBDD0 00000000 */  nop
    /* BC9D4 002BBDD4 3C08800D */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BC9D8 002BBDD8 25085258 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BC9DC 002BBDDC 8D080000 */  lw         $t0, 0x0($t0)
    /* BC9E0 002BBDE0 00000000 */  nop
    /* BC9E4 002BBDE4 00084402 */  srl        $t0, $t0, 16
    /* BC9E8 002BBDE8 2401FFFF */  addiu      $at, $zero, -0x1
    /* BC9EC 002BBDEC 01014026 */  xor        $t0, $t0, $at
    /* BC9F0 002BBDF0 8F4C0128 */  lw         $t4, 0x128($k0) /* handwritten instruction */
    /* BC9F4 002BBDF4 3108003F */  andi       $t0, $t0, 0x3F
    /* BC9F8 002BBDF8 010C4024 */  and        $t0, $t0, $t4
    /* BC9FC 002BBDFC 01284825 */  or         $t1, $t1, $t0
.Lauto_002BBE00:
    /* BCA00 002BBE00 40087000 */  mfc0       $t0, $14 /* handwritten instruction */
    /* BCA04 002BBE04 AF490128 */  sw         $t1, 0x128($k0) /* handwritten instruction */
    /* BCA08 002BBE08 AF48011C */  sw         $t0, 0x11C($k0) /* handwritten instruction */
    /* BCA0C 002BBE0C 8F480018 */  lw         $t0, 0x18($k0) /* handwritten instruction */
    /* BCA10 002BBE10 00000000 */  nop
    /* BCA14 002BBE14 11000029 */  .word 0x11000029
    /* BCA18 002BBE18 00000000 */  nop
    /* BCA1C 002BBE1C 4448F800 */  cfc1       $t0, $31
    /* BCA20 002BBE20 00000000 */  nop
    /* BCA24 002BBE24 AF48012C */  sw         $t0, 0x12C($k0) /* handwritten instruction */
    /* BCA28 002BBE28 F7400130 */  sdc1       $fv0, 0x130($k0)
    /* BCA2C 002BBE2C F7420138 */  sdc1       $fv1, 0x138($k0)
    /* BCA30 002BBE30 F7440140 */  sdc1       $ft0, 0x140($k0)
    /* BCA34 002BBE34 F7460148 */  sdc1       $ft1, 0x148($k0)
    /* BCA38 002BBE38 F7480150 */  sdc1       $ft2, 0x150($k0)
    /* BCA3C 002BBE3C F74A0158 */  sdc1       $ft3, 0x158($k0)
    /* BCA40 002BBE40 F74C0160 */  sdc1       $fa0, 0x160($k0)
    /* BCA44 002BBE44 F74E0168 */  sdc1       $fa1, 0x168($k0)
    /* BCA48 002BBE48 F7500170 */  sdc1       $ft4, 0x170($k0)
    /* BCA4C 002BBE4C F7520178 */  sdc1       $ft5, 0x178($k0)
    /* BCA50 002BBE50 F7540180 */  sdc1       $fs0, 0x180($k0)
    /* BCA54 002BBE54 F7560188 */  sdc1       $fs1, 0x188($k0)
    /* BCA58 002BBE58 F7580190 */  sdc1       $fs2, 0x190($k0)
    /* BCA5C 002BBE5C F75A0198 */  sdc1       $fs3, 0x198($k0)
    /* BCA60 002BBE60 F75C01A0 */  sdc1       $fs4, 0x1A0($k0)
    /* BCA64 002BBE64 8F490118 */  lw         $t1, 0x118($k0) /* handwritten instruction */
    /* BCA68 002BBE68 F75E01A8 */  sdc1       $fs5, 0x1A8($k0)
    /* BCA6C 002BBE6C 3C010400 */  lui        $at, (0x4000000 >> 16)
    /* BCA70 002BBE70 01214824 */  and        $t1, $t1, $at
    /* BCA74 002BBE74 11200011 */  .word 0x11200011
    /* BCA78 002BBE78 00000000 */  nop
    /* BCA7C 002BBE7C F74101B0 */  sdc1       $fv0f, 0x1B0($k0)
    /* BCA80 002BBE80 F74301B8 */  sdc1       $fv1f, 0x1B8($k0)
    /* BCA84 002BBE84 F74501C0 */  sdc1       $ft0f, 0x1C0($k0)
    /* BCA88 002BBE88 F74701C8 */  sdc1       $ft1f, 0x1C8($k0)
    /* BCA8C 002BBE8C F74901D0 */  sdc1       $ft2f, 0x1D0($k0)
    /* BCA90 002BBE90 F74B01D8 */  sdc1       $ft3f, 0x1D8($k0)
    /* BCA94 002BBE94 F74D01E0 */  sdc1       $fa0f, 0x1E0($k0)
    /* BCA98 002BBE98 F74F01E8 */  sdc1       $fa1f, 0x1E8($k0)
    /* BCA9C 002BBE9C F75101F0 */  sdc1       $ft4f, 0x1F0($k0)
    /* BCAA0 002BBEA0 F75301F8 */  sdc1       $ft5f, 0x1F8($k0)
    /* BCAA4 002BBEA4 F7550200 */  sdc1       $fs0f, 0x200($k0)
    /* BCAA8 002BBEA8 F7570208 */  sdc1       $fs1f, 0x208($k0)
    /* BCAAC 002BBEAC F7590210 */  sdc1       $fs2f, 0x210($k0)
    /* BCAB0 002BBEB0 F75B0218 */  sdc1       $fs3f, 0x218($k0)
    /* BCAB4 002BBEB4 F75D0220 */  sdc1       $fs4f, 0x220($k0)
    /* BCAB8 002BBEB8 F75F0228 */  sdc1       $fs5f, 0x228($k0)
.Lauto_002BBEBC:
    /* BCABC 002BBEBC 40086800 */  mfc0       $t0, $13 /* handwritten instruction */
    /* BCAC0 002BBEC0 24090002 */  addiu      $t1, $zero, 0x2
    /* BCAC4 002BBEC4 AF480120 */  sw         $t0, 0x120($k0) /* handwritten instruction */
    /* BCAC8 002BBEC8 A7490010 */  sh         $t1, 0x10($k0) /* handwritten instruction */
    /* BCACC 002BBECC 3109007C */  andi       $t1, $t0, 0x7C
    /* BCAD0 002BBED0 240A0024 */  addiu      $t2, $zero, 0x24
    /* BCAD4 002BBED4 112A00BD */  .word 0x112A00BD
    /* BCAD8 002BBED8 240A002C */  addiu     $t2, $zero, 0x2C
    /* BCADC 002BBEDC 112A0115 */  .word 0x112A0115
    /* BCAE0 002BBEE0 240A0000 */  addiu     $t2, $zero, 0x0
    /* BCAE4 002BBEE4 152A00D4 */  .word 0x152A00D4
    /* BCAE8 002BBEE8 03688024 */  and       $s0, $k1, $t0
.Lauto_002BBEEC:
    /* BCAEC 002BBEEC 3209FF00 */  andi       $t1, $s0, 0xFF00
    /* BCAF0 002BBEF0 00095302 */  srl        $t2, $t1, 12
    /* BCAF4 002BBEF4 15400003 */  .word 0x15400003
    /* BCAF8 002BBEF8 00000000 */  nop
    /* BCAFC 002BBEFC 00095202 */  srl        $t2, $t1, 8
    /* BCB00 002BBF00 214A0010 */  addi       $t2, $t2, 0x10 /* handwritten instruction */
.Lauto_002BBF04:
    /* BCB04 002BBF04 3C01800C */  lui        $at, %hi(__osIntOffTable)
    /* BCB08 002BBF08 002A0821 */  addu       $at, $at, $t2
    /* BCB0C 002BBF0C 902A7A20 */  lbu        $t2, %lo(__osIntOffTable)($at)
    /* BCB10 002BBF10 3C01800C */  lui        $at, %hi(jtbl_auto_800C7A40)
    /* BCB14 002BBF14 002A0821 */  addu       $at, $at, $t2
    /* BCB18 002BBF18 8C2A7A40 */  lw         $t2, %lo(jtbl_auto_800C7A40)($at)
    /* BCB1C 002BBF1C 00000000 */  nop
    /* BCB20 002BBF20 01400008 */  jr         $t2
    /* BCB24 002BBF24 00000000 */  nop
    /* BCB28 002BBF28 2401DFFF */  addiu      $at, $zero, -0x2001
    /* BCB2C 002BBF2C 02018024 */  and        $s0, $s0, $at
    /* BCB30 002BBF30 0401FFEE */  .word 0x0401FFEE
    /* BCB34 002BBF34 00000000 */  nop
    /* BCB38 002BBF38 2401BFFF */  addiu      $at, $zero, -0x4001
    /* BCB3C 002BBF3C 02018024 */  and        $s0, $s0, $at
    /* BCB40 002BBF40 0401FFEA */  .word 0x0401FFEA
    /* BCB44 002BBF44 00000000 */  nop
    /* BCB48 002BBF48 40095800 */  mfc0       $t1, $11 /* handwritten instruction */
    /* BCB4C 002BBF4C 3C01FFFF */  lui        $at, (0xFFFF7FFF >> 16)
    /* BCB50 002BBF50 34217FFF */  ori        $at, $at, (0xFFFF7FFF & 0xFFFF)
    /* BCB54 002BBF54 02018024 */  and        $s0, $s0, $at
    /* BCB58 002BBF58 40895800 */  mtc0       $t1, $11 /* handwritten instruction */
    /* BCB5C 002BBF5C 0C0AF09A */  jal        send_mesg
    /* BCB60 002BBF60 24040018 */  addiu     $a0, $zero, 0x18
    /* BCB64 002BBF64 0401FFE1 */  .word 0x0401FFE1
    /* BCB68 002BBF68 00000000 */  nop
    /* BCB6C 002BBF6C 24040010 */  addiu      $a0, $zero, 0x10
    /* BCB70 002BBF70 2401F7FF */  addiu      $at, $zero, -0x801
    /* BCB74 002BBF74 02018024 */  and        $s0, $s0, $at
    /* BCB78 002BBF78 3C1D8015 */  lui        $sp, %hi(__osHwIntStack)
    /* BCB7C 002BBF7C 27BD9BD0 */  addiu      $sp, $sp, %lo(__osHwIntStack)
    /* BCB80 002BBF80 27BD0FF0 */  addiu      $sp, $sp, 0xFF0
    /* BCB84 002BBF84 240A0004 */  addiu      $t2, $zero, 0x4
    /* BCB88 002BBF88 3C01800D */  lui        $at, %hi(__osHwIntTable)
    /* BCB8C 002BBF8C 002A0821 */  addu       $at, $at, $t2
    /* BCB90 002BBF90 8C2A5290 */  lw         $t2, %lo(__osHwIntTable)($at)
    /* BCB94 002BBF94 00000000 */  nop
    /* BCB98 002BBF98 11400007 */  .word 0x11400007
    /* BCB9C 002BBF9C 00000000 */  nop
    /* BCBA0 002BBFA0 0140F809 */  jalr       $t2
    /* BCBA4 002BBFA4 24040010 */  addiu     $a0, $zero, 0x10
    /* BCBA8 002BBFA8 10400003 */  .word 0x10400003
    /* BCBAC 002BBFAC 00000000 */  nop
    /* BCBB0 002BBFB0 0401008C */  .word 0x0401008C
    /* BCBB4 002BBFB4 00000000 */  nop
.Lauto_002BBFB8:
    /* BCBB8 002BBFB8 0C0AF09A */  jal        send_mesg
    /* BCBBC 002BBFBC 00000000 */  nop
    /* BCBC0 002BBFC0 0401FFCA */  .word 0x0401FFCA
    /* BCBC4 002BBFC4 00000000 */  nop
    /* BCBC8 002BBFC8 3C11A430 */  lui        $s1, %hi(MI_INTR_REG)
    /* BCBCC 002BBFCC 8E310008 */  lw         $s1, %lo(MI_INTR_REG)($s1)
    /* BCBD0 002BBFD0 3C08800D */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BCBD4 002BBFD4 25085258 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BCBD8 002BBFD8 8D080000 */  lw         $t0, 0x0($t0)
    /* BCBDC 002BBFDC 00000000 */  nop
    /* BCBE0 002BBFE0 00084402 */  srl        $t0, $t0, 16
    /* BCBE4 002BBFE4 02288824 */  and        $s1, $s1, $t0
    /* BCBE8 002BBFE8 32290001 */  andi       $t1, $s1, 0x1
    /* BCBEC 002BBFEC 11200014 */  .word 0x11200014
    /* BCBF0 002BBFF0 00000000 */  nop
    /* BCBF4 002BBFF4 3231003E */  andi       $s1, $s1, 0x3E
    /* BCBF8 002BBFF8 3C0CA404 */  lui        $t4, %hi(SP_STATUS_REG)
    /* BCBFC 002BBFFC 8D8C0010 */  lw         $t4, %lo(SP_STATUS_REG)($t4)
    /* BCC00 002BC000 34098008 */  ori        $t1, $zero, 0x8008
    /* BCC04 002BC004 3C01A404 */  lui        $at, %hi(SP_STATUS_REG)
    /* BCC08 002BC008 AC290010 */  sw         $t1, %lo(SP_STATUS_REG)($at)
    /* BCC0C 002BC00C 318C0300 */  andi       $t4, $t4, 0x300
    /* BCC10 002BC010 11800007 */  .word 0x11800007
    /* BCC14 002BC014 00000000 */  nop
    /* BCC18 002BC018 0C0AF09A */  jal        send_mesg
    /* BCC1C 002BC01C 24040020 */  addiu     $a0, $zero, 0x20
    /* BCC20 002BC020 1220003A */  .word 0x1220003A
    /* BCC24 002BC024 00000000 */  nop
    /* BCC28 002BC028 04010005 */  .word 0x04010005
    /* BCC2C 002BC02C 00000000 */  nop
.Lauto_002BC030:
    /* BCC30 002BC030 0C0AF09A */  jal        send_mesg
    /* BCC34 002BC034 24040058 */  addiu     $a0, $zero, 0x58
    /* BCC38 002BC038 12200034 */  .word 0x12200034
    /* BCC3C 002BC03C 00000000 */  nop
.Lauto_002BC040:
    /* BCC40 002BC040 32290008 */  andi       $t1, $s1, 0x8
    /* BCC44 002BC044 00000000 */  nop
    /* BCC48 002BC048 11200007 */  .word 0x11200007
    /* BCC4C 002BC04C 32310037 */  andi      $s1, $s1, 0x37
    /* BCC50 002BC050 3C01A440 */  lui        $at, %hi(VI_CURRENT_REG)
    /* BCC54 002BC054 AC200010 */  sw         $zero, %lo(VI_CURRENT_REG)($at)
    /* BCC58 002BC058 0C0AF09A */  jal        send_mesg
    /* BCC5C 002BC05C 24040038 */  addiu     $a0, $zero, 0x38
    /* BCC60 002BC060 1220002A */  .word 0x1220002A
    /* BCC64 002BC064 00000000 */  nop
.Lauto_002BC068:
    /* BCC68 002BC068 32290004 */  andi       $t1, $s1, 0x4
    /* BCC6C 002BC06C 11200009 */  .word 0x11200009
    /* BCC70 002BC070 00000000 */  nop
    /* BCC74 002BC074 3231003B */  andi       $s1, $s1, 0x3B
    /* BCC78 002BC078 24090001 */  addiu      $t1, $zero, 0x1
    /* BCC7C 002BC07C 3C01A450 */  lui        $at, %hi(AI_STATUS_REG)
    /* BCC80 002BC080 AC29000C */  sw         $t1, %lo(AI_STATUS_REG)($at)
    /* BCC84 002BC084 0C0AF09A */  jal        send_mesg
    /* BCC88 002BC088 24040030 */  addiu     $a0, $zero, 0x30
    /* BCC8C 002BC08C 1220001F */  .word 0x1220001F
    /* BCC90 002BC090 00000000 */  nop
.Lauto_002BC094:
    /* BCC94 002BC094 32290002 */  andi       $t1, $s1, 0x2
    /* BCC98 002BC098 11200008 */  .word 0x11200008
    /* BCC9C 002BC09C 00000000 */  nop
    /* BCCA0 002BC0A0 3231003D */  andi       $s1, $s1, 0x3D
    /* BCCA4 002BC0A4 3C01A480 */  lui        $at, %hi(SI_STATUS_REG)
    /* BCCA8 002BC0A8 AC200018 */  sw         $zero, %lo(SI_STATUS_REG)($at)
    /* BCCAC 002BC0AC 0C0AF09A */  jal        send_mesg
    /* BCCB0 002BC0B0 24040028 */  addiu     $a0, $zero, 0x28
    /* BCCB4 002BC0B4 12200015 */  .word 0x12200015
    /* BCCB8 002BC0B8 00000000 */  nop
.Lauto_002BC0BC:
    /* BCCBC 002BC0BC 32290010 */  andi       $t1, $s1, 0x10
    /* BCCC0 002BC0C0 11200009 */  .word 0x11200009
    /* BCCC4 002BC0C4 00000000 */  nop
    /* BCCC8 002BC0C8 3231002F */  andi       $s1, $s1, 0x2F
    /* BCCCC 002BC0CC 24090002 */  addiu      $t1, $zero, 0x2
    /* BCCD0 002BC0D0 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* BCCD4 002BC0D4 AC290010 */  sw         $t1, %lo(PI_STATUS_REG)($at)
    /* BCCD8 002BC0D8 0C0AF09A */  jal        send_mesg
    /* BCCDC 002BC0DC 24040040 */  addiu     $a0, $zero, 0x40
    /* BCCE0 002BC0E0 1220000A */  .word 0x1220000A
    /* BCCE4 002BC0E4 00000000 */  nop
.Lauto_002BC0E8:
    /* BCCE8 002BC0E8 32290020 */  andi       $t1, $s1, 0x20
    /* BCCEC 002BC0EC 11200007 */  .word 0x11200007
    /* BCCF0 002BC0F0 00000000 */  nop
    /* BCCF4 002BC0F4 3231001F */  andi       $s1, $s1, 0x1F
    /* BCCF8 002BC0F8 24090800 */  addiu      $t1, $zero, 0x800
    /* BCCFC 002BC0FC 3C01A430 */  lui        $at, %hi(MI_MODE_REG)
    /* BCD00 002BC100 AC290000 */  sw         $t1, %lo(MI_MODE_REG)($at)
    /* BCD04 002BC104 0C0AF09A */  jal        send_mesg
    /* BCD08 002BC108 24040048 */  addiu     $a0, $zero, 0x48
.Lauto_002BC10C:
    /* BCD0C 002BC10C 2401FBFF */  addiu      $at, $zero, -0x401
    /* BCD10 002BC110 02018024 */  and        $s0, $s0, $at
    /* BCD14 002BC114 0401FF75 */  .word 0x0401FF75
    /* BCD18 002BC118 00000000 */  nop
    /* BCD1C 002BC11C 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* BCD20 002BC120 3C09800D */  lui        $t1, %hi(__osShutdown)
    /* BCD24 002BC124 25295254 */  addiu      $t1, $t1, %lo(__osShutdown)
    /* BCD28 002BC128 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BCD2C 002BC12C 0361D824 */  and        $k1, $k1, $at
    /* BCD30 002BC130 8D2A0000 */  lw         $t2, 0x0($t1)
    /* BCD34 002BC134 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BCD38 002BC138 02018024 */  and        $s0, $s0, $at
    /* BCD3C 002BC13C 11400003 */  .word 0x11400003
    /* BCD40 002BC140 AF5B0118 */  sw        $k1, 0x118($k0) /* handwritten instruction */
    /* BCD44 002BC144 04010027 */  .word 0x04010027
    /* BCD48 002BC148 00000000 */  nop
.Lauto_002BC14C:
    /* BCD4C 002BC14C 240A0001 */  addiu      $t2, $zero, 0x1
    /* BCD50 002BC150 AD2A0000 */  sw         $t2, 0x0($t1)
    /* BCD54 002BC154 0C0AF09A */  jal        send_mesg
    /* BCD58 002BC158 24040070 */  addiu     $a0, $zero, 0x70
    /* BCD5C 002BC15C 3C0A800D */  lui        $t2, %hi(__osRunQueue)
    /* BCD60 002BC160 8D4A5268 */  lw         $t2, %lo(__osRunQueue)($t2)
    /* BCD64 002BC164 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BCD68 002BC168 02018024 */  and        $s0, $s0, $at
    /* BCD6C 002BC16C 8D5B0118 */  lw         $k1, 0x118($t2) /* handwritten instruction */
    /* BCD70 002BC170 00000000 */  nop
    /* BCD74 002BC174 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BCD78 002BC178 0361D824 */  and        $k1, $k1, $at
    /* BCD7C 002BC17C 04010019 */  .word 0x04010019
    /* BCD80 002BC180 AD5B0118 */  sw        $k1, 0x118($t2) /* handwritten instruction */
    /* BCD84 002BC184 2401FDFF */  addiu      $at, $zero, -0x201
    /* BCD88 002BC188 01014024 */  and        $t0, $t0, $at
    /* BCD8C 002BC18C 40886800 */  mtc0       $t0, $13 /* handwritten instruction */
    /* BCD90 002BC190 2401FDFF */  addiu      $at, $zero, -0x201
    /* BCD94 002BC194 02018024 */  and        $s0, $s0, $at
    /* BCD98 002BC198 0C0AF09A */  jal        send_mesg
    /* BCD9C 002BC19C 24040008 */  addiu     $a0, $zero, 0x8
    /* BCDA0 002BC1A0 0401FF52 */  .word 0x0401FF52
    /* BCDA4 002BC1A4 00000000 */  nop
    /* BCDA8 002BC1A8 2401FEFF */  addiu      $at, $zero, -0x101
    /* BCDAC 002BC1AC 01014024 */  and        $t0, $t0, $at
    /* BCDB0 002BC1B0 40886800 */  mtc0       $t0, $13 /* handwritten instruction */
    /* BCDB4 002BC1B4 2401FEFF */  addiu      $at, $zero, -0x101
    /* BCDB8 002BC1B8 02018024 */  and        $s0, $s0, $at
    /* BCDBC 002BC1BC 0C0AF09A */  jal        send_mesg
    /* BCDC0 002BC1C0 24040000 */  addiu     $a0, $zero, 0x0
    /* BCDC4 002BC1C4 0401FF49 */  .word 0x0401FF49
    /* BCDC8 002BC1C8 00000000 */  nop
.Lauto_002BC1CC:
    /* BCDCC 002BC1CC 24090001 */  addiu      $t1, $zero, 0x1
    /* BCDD0 002BC1D0 A7490012 */  sh         $t1, 0x12($k0) /* handwritten instruction */
    /* BCDD4 002BC1D4 0C0AF09A */  jal        send_mesg
    /* BCDD8 002BC1D8 24040050 */  addiu     $a0, $zero, 0x50
    /* BCDDC 002BC1DC 04010001 */  .word 0x04010001
    /* BCDE0 002BC1E0 00000000 */  nop
.Lauto_002BC1E4:
    /* BCDE4 002BC1E4 3C0A800D */  lui        $t2, %hi(__osRunQueue)
    /* BCDE8 002BC1E8 8D4A5268 */  lw         $t2, %lo(__osRunQueue)($t2)
    /* BCDEC 002BC1EC 8F490004 */  lw         $t1, 0x4($k0) /* handwritten instruction */
    /* BCDF0 002BC1F0 8D4B0004 */  lw         $t3, 0x4($t2)
    /* BCDF4 002BC1F4 00000000 */  nop
    /* BCDF8 002BC1F8 012B082A */  slt        $at, $t1, $t3
    /* BCDFC 002BC1FC 10200007 */  .word 0x10200007
    /* BCE00 002BC200 00000000 */  nop
    /* BCE04 002BC204 3C04800D */  lui        $a0, %hi(__osRunQueue)
    /* BCE08 002BC208 24845268 */  addiu      $a0, $a0, %lo(__osRunQueue)
    /* BCE0C 002BC20C 0C0AF142 */  jal        __osEnqueueThread
    /* BCE10 002BC210 03402821 */  addu      $a1, $k0, $zero
    /* BCE14 002BC214 080AF15C */  j          __osDispatchThread
    /* BCE18 002BC218 00000000 */  nop
.Lauto_002BC21C:
    /* BCE1C 002BC21C 3C09800D */  lui        $t1, %hi(__osRunQueue)
    /* BCE20 002BC220 25295268 */  addiu      $t1, $t1, %lo(__osRunQueue)
    /* BCE24 002BC224 8D2A0000 */  lw         $t2, 0x0($t1)
    /* BCE28 002BC228 00000000 */  nop
    /* BCE2C 002BC22C AF4A0000 */  sw         $t2, 0x0($k0) /* handwritten instruction */
    /* BCE30 002BC230 080AF15C */  j          __osDispatchThread
    /* BCE34 002BC234 AD3A0000 */  sw        $k0, 0x0($t1) /* handwritten instruction */
.Lauto_002BC238:
    /* BCE38 002BC238 3C01800D */  lui        $at, %hi(__osFaultedThread)
    /* BCE3C 002BC23C AC3A5274 */  sw         $k0, %lo(__osFaultedThread)($at) /* handwritten instruction */
    /* BCE40 002BC240 24090001 */  addiu      $t1, $zero, 0x1
    /* BCE44 002BC244 A7490010 */  sh         $t1, 0x10($k0) /* handwritten instruction */
    /* BCE48 002BC248 24090002 */  addiu      $t1, $zero, 0x2
    /* BCE4C 002BC24C 400A4000 */  mfc0       $t2, $8 /* handwritten instruction */
    /* BCE50 002BC250 A7490012 */  sh         $t1, 0x12($k0) /* handwritten instruction */
    /* BCE54 002BC254 AF4A0124 */  sw         $t2, 0x124($k0) /* handwritten instruction */
    /* BCE58 002BC258 0C0AF09A */  jal        send_mesg
    /* BCE5C 002BC25C 24040060 */  addiu     $a0, $zero, 0x60
    /* BCE60 002BC260 080AF15C */  j          __osDispatchThread
    /* BCE64 002BC264 00000000 */  nop
.globl send_mesg
send_mesg:
    /* BCE68 002BC268 03E09021 */  addu       $s2, $ra, $zero
    /* BCE6C 002BC26C 3C0A8015 */  lui        $t2, %hi(__osEventStateTab)
    /* BCE70 002BC270 254A9B10 */  addiu      $t2, $t2, %lo(__osEventStateTab)
    /* BCE74 002BC274 01445021 */  addu       $t2, $t2, $a0
    /* BCE78 002BC278 8D490000 */  lw         $t1, 0x0($t2)
    /* BCE7C 002BC27C 00000000 */  nop
    /* BCE80 002BC280 1120002A */  .word 0x1120002A
    /* BCE84 002BC284 00000000 */  nop
    /* BCE88 002BC288 8D2B0008 */  lw         $t3, 0x8($t1)
    /* BCE8C 002BC28C 8D2C0010 */  lw         $t4, 0x10($t1)
    /* BCE90 002BC290 00000000 */  nop
    /* BCE94 002BC294 016C082A */  slt        $at, $t3, $t4
    /* BCE98 002BC298 10200024 */  .word 0x10200024
    /* BCE9C 002BC29C 00000000 */  nop
    /* BCEA0 002BC2A0 8D2D000C */  lw         $t5, 0xC($t1)
    /* BCEA4 002BC2A4 00000000 */  nop
    /* BCEA8 002BC2A8 01AB6821 */  addu       $t5, $t5, $t3
    /* BCEAC 002BC2AC 01AC001A */  div        $zero, $t5, $t4
    /* BCEB0 002BC2B0 15800002 */  .word 0x15800002
    /* BCEB4 002BC2B4 00000000 */  nop
    /* BCEB8 002BC2B8 0007000D */  break      7
.Lauto_002BC2BC:
    /* BCEBC 002BC2BC 2401FFFF */  addiu      $at, $zero, -0x1
    /* BCEC0 002BC2C0 15810004 */  .word 0x15810004
    /* BCEC4 002BC2C4 3C018000 */  lui       $at, (0x80000000 >> 16)
    /* BCEC8 002BC2C8 15A10002 */  .word 0x15A10002
    /* BCECC 002BC2CC 00000000 */  nop
    /* BCED0 002BC2D0 0006000D */  break      6
.Lauto_002BC2D4:
    /* BCED4 002BC2D4 00006810 */  mfhi       $t5
    /* BCED8 002BC2D8 8D2C0014 */  lw         $t4, 0x14($t1)
    /* BCEDC 002BC2DC 000D6880 */  sll        $t5, $t5, 2
    /* BCEE0 002BC2E0 018D6021 */  addu       $t4, $t4, $t5
    /* BCEE4 002BC2E4 8D4D0004 */  lw         $t5, 0x4($t2)
    /* BCEE8 002BC2E8 00000000 */  nop
    /* BCEEC 002BC2EC AD8D0000 */  sw         $t5, 0x0($t4)
    /* BCEF0 002BC2F0 256A0001 */  addiu      $t2, $t3, 0x1
    /* BCEF4 002BC2F4 AD2A0008 */  sw         $t2, 0x8($t1)
    /* BCEF8 002BC2F8 8D2A0000 */  lw         $t2, 0x0($t1)
    /* BCEFC 002BC2FC 00000000 */  nop
    /* BCF00 002BC300 8D4B0000 */  lw         $t3, 0x0($t2)
    /* BCF04 002BC304 00000000 */  nop
    /* BCF08 002BC308 11600008 */  .word 0x11600008
    /* BCF0C 002BC30C 00000000 */  nop
    /* BCF10 002BC310 0C0AF156 */  jal        __osPopThread
    /* BCF14 002BC314 01202021 */  addu      $a0, $t1, $zero
    /* BCF18 002BC318 00405021 */  addu       $t2, $v0, $zero
    /* BCF1C 002BC31C 3C04800D */  lui        $a0, %hi(__osRunQueue)
    /* BCF20 002BC320 24845268 */  addiu      $a0, $a0, %lo(__osRunQueue)
    /* BCF24 002BC324 0C0AF142 */  jal        __osEnqueueThread
    /* BCF28 002BC328 01402821 */  addu      $a1, $t2, $zero
.Lauto_002BC32C:
    /* BCF2C 002BC32C 02400008 */  jr         $s2
    /* BCF30 002BC330 00000000 */  nop
.Lauto_002BC334:
    /* BCF34 002BC334 3C013000 */  lui        $at, (0x30000000 >> 16)
    /* BCF38 002BC338 01014824 */  and        $t1, $t0, $at
    /* BCF3C 002BC33C 00094F02 */  srl        $t1, $t1, 28
    /* BCF40 002BC340 240A0001 */  addiu      $t2, $zero, 0x1
    /* BCF44 002BC344 152AFFBC */  .word 0x152AFFBC
    /* BCF48 002BC348 24090001 */  addiu     $t1, $zero, 0x1
    /* BCF4C 002BC34C AF490018 */  sw         $t1, 0x18($k0) /* handwritten instruction */
    /* BCF50 002BC350 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* BCF54 002BC354 00000000 */  nop
    /* BCF58 002BC358 3C012000 */  lui        $at, (0x20000000 >> 16)
    /* BCF5C 002BC35C 0361D825 */  or         $k1, $k1, $at
    /* BCF60 002BC360 AF5B0118 */  sw         $k1, 0x118($k0) /* handwritten instruction */
    /* BCF64 002BC364 0401FFAD */  .word 0x0401FFAD
    /* BCF68 002BC368 00000000 */  nop
