.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBC798-0xBCE9C (VRAM 0x002BBB98) */
.globl D_auto_002BBB98
D_auto_002BBB98:
    /* BC798 002BBB98 05000000 */  .word 0x05000000
    /* BC79C 002BBB9C 00000B6D */  .word 0x00000B6D
.globl __osExceptionPreamble
__osExceptionPreamble:
    /* BC7A0 002BBBA0 3C1A002C */  lui        $k0, %hi(__osException) /* handwritten instruction */
    /* BC7A4 002BBBA4 275ABBB0 */  addiu      $k0, $k0, %lo(__osException) /* handwritten instruction */
    /* BC7A8 002BBBA8 03400008 */  jr         $k0
    /* BC7AC 002BBBAC 00000000 */  nop
.globl __osException
__osException:
    /* BC7B0 002BBBB0 3C1A8015 */  lui        $k0, %hi(__osThreadSave) /* handwritten instruction */
    /* BC7B4 002BBBB4 275A8BD0 */  addiu      $k0, $k0, %lo(__osThreadSave) /* handwritten instruction */
    /* BC7B8 002BBBB8 FF410020 */  sd         $at, 0x20($k0) /* handwritten instruction */
    /* BC7BC 002BBBBC 401B6000 */  mfc0       $k1, $12 /* handwritten instruction */
    /* BC7C0 002BBBC0 00000000 */  nop
    /* BC7C4 002BBBC4 AF5B0118 */  sw         $k1, 0x118($k0) /* handwritten instruction */
    /* BC7C8 002BBBC8 2401FFFC */  addiu      $at, $zero, -0x4
    /* BC7CC 002BBBCC 0361D824 */  and        $k1, $k1, $at
    /* BC7D0 002BBBD0 409B6000 */  mtc0       $k1, $12 /* handwritten instruction */
    /* BC7D4 002BBBD4 FF480058 */  sd         $t0, 0x58($k0) /* handwritten instruction */
    /* BC7D8 002BBBD8 FF490060 */  sd         $t1, 0x60($k0) /* handwritten instruction */
    /* BC7DC 002BBBDC FF4A0068 */  sd         $t2, 0x68($k0) /* handwritten instruction */
    /* BC7E0 002BBBE0 AF400018 */  sw         $zero, 0x18($k0) /* handwritten instruction */
    /* BC7E4 002BBBE4 40086800 */  mfc0       $t0, $13 /* handwritten instruction */
    /* BC7E8 002BBBE8 03404021 */  addu       $t0, $k0, $zero
    /* BC7EC 002BBBEC 3C1A800D */  lui        $k0, %hi(__osRunningThread) /* handwritten instruction */
    /* BC7F0 002BBBF0 8F5A3F20 */  lw         $k0, %lo(__osRunningThread)($k0) /* handwritten instruction */
    /* BC7F4 002BBBF4 DD090020 */  ld         $t1, 0x20($t0)
    /* BC7F8 002BBBF8 DD0A0118 */  ld         $t2, 0x118($t0)
    /* BC7FC 002BBBFC FF490020 */  sd         $t1, 0x20($k0) /* handwritten instruction */
    /* BC800 002BBC00 FF4A0118 */  sd         $t2, 0x118($k0) /* handwritten instruction */
    /* BC804 002BBC04 DD090058 */  ld         $t1, 0x58($t0)
    /* BC808 002BBC08 DD0A0060 */  ld         $t2, 0x60($t0)
    /* BC80C 002BBC0C FF490058 */  sd         $t1, 0x58($k0) /* handwritten instruction */
    /* BC810 002BBC10 FF4A0060 */  sd         $t2, 0x60($k0) /* handwritten instruction */
    /* BC814 002BBC14 DD090068 */  ld         $t1, 0x68($t0)
    /* BC818 002BBC18 FF420028 */  sd         $v0, 0x28($k0) /* handwritten instruction */
    /* BC81C 002BBC1C FF490068 */  sd         $t1, 0x68($k0) /* handwritten instruction */
    /* BC820 002BBC20 FF430030 */  sd         $v1, 0x30($k0) /* handwritten instruction */
    /* BC824 002BBC24 FF440038 */  sd         $a0, 0x38($k0) /* handwritten instruction */
    /* BC828 002BBC28 FF450040 */  sd         $a1, 0x40($k0) /* handwritten instruction */
    /* BC82C 002BBC2C FF460048 */  sd         $a2, 0x48($k0) /* handwritten instruction */
    /* BC830 002BBC30 FF470050 */  sd         $a3, 0x50($k0) /* handwritten instruction */
    /* BC834 002BBC34 FF4B0070 */  sd         $t3, 0x70($k0) /* handwritten instruction */
    /* BC838 002BBC38 FF4C0078 */  sd         $t4, 0x78($k0) /* handwritten instruction */
    /* BC83C 002BBC3C FF4D0080 */  sd         $t5, 0x80($k0) /* handwritten instruction */
    /* BC840 002BBC40 FF4E0088 */  sd         $t6, 0x88($k0) /* handwritten instruction */
    /* BC844 002BBC44 FF4F0090 */  sd         $t7, 0x90($k0) /* handwritten instruction */
    /* BC848 002BBC48 FF500098 */  sd         $s0, 0x98($k0) /* handwritten instruction */
    /* BC84C 002BBC4C FF5100A0 */  sd         $s1, 0xA0($k0) /* handwritten instruction */
    /* BC850 002BBC50 FF5200A8 */  sd         $s2, 0xA8($k0) /* handwritten instruction */
    /* BC854 002BBC54 FF5300B0 */  sd         $s3, 0xB0($k0) /* handwritten instruction */
    /* BC858 002BBC58 FF5400B8 */  sd         $s4, 0xB8($k0) /* handwritten instruction */
    /* BC85C 002BBC5C FF5500C0 */  sd         $s5, 0xC0($k0) /* handwritten instruction */
    /* BC860 002BBC60 FF5600C8 */  sd         $s6, 0xC8($k0) /* handwritten instruction */
    /* BC864 002BBC64 FF5700D0 */  sd         $s7, 0xD0($k0) /* handwritten instruction */
    /* BC868 002BBC68 FF5800D8 */  sd         $t8, 0xD8($k0) /* handwritten instruction */
    /* BC86C 002BBC6C FF5900E0 */  sd         $t9, 0xE0($k0) /* handwritten instruction */
    /* BC870 002BBC70 FF5C00E8 */  sd         $gp, 0xE8($k0) /* handwritten instruction */
    /* BC874 002BBC74 FF5D00F0 */  sd         $sp, 0xF0($k0) /* handwritten instruction */
    /* BC878 002BBC78 FF5E00F8 */  sd         $fp, 0xF8($k0) /* handwritten instruction */
    /* BC87C 002BBC7C FF5F0100 */  sd         $ra, 0x100($k0) /* handwritten instruction */
    /* BC880 002BBC80 00004012 */  mflo       $t0
    /* BC884 002BBC84 FF480108 */  sd         $t0, 0x108($k0) /* handwritten instruction */
    /* BC888 002BBC88 00004010 */  mfhi       $t0
    /* BC88C 002BBC8C FF480110 */  sd         $t0, 0x110($k0) /* handwritten instruction */
    /* BC890 002BBC90 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* BC894 002BBC94 00000000 */  nop
    /* BC898 002BBC98 3369FF00 */  andi       $t1, $k1, 0xFF00 /* handwritten instruction */
    /* BC89C 002BBC9C 11200014 */  .word 0x11200014
    /* BC8A0 002BBCA0 00000000 */  nop
    /* BC8A4 002BBCA4 3C08800D */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BC8A8 002BBCA8 25083F08 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BC8AC 002BBCAC 8D080000 */  lw         $t0, 0x0($t0)
    /* BC8B0 002BBCB0 00000000 */  nop
    /* BC8B4 002BBCB4 2401FFFF */  addiu      $at, $zero, -0x1
    /* BC8B8 002BBCB8 01015026 */  xor        $t2, $t0, $at
    /* BC8BC 002BBCBC 314AFF00 */  andi       $t2, $t2, 0xFF00
    /* BC8C0 002BBCC0 012A6025 */  or         $t4, $t1, $t2
    /* BC8C4 002BBCC4 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* BC8C8 002BBCC8 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* BC8CC 002BBCCC 03615824 */  and        $t3, $k1, $at
    /* BC8D0 002BBCD0 016C5825 */  or         $t3, $t3, $t4
    /* BC8D4 002BBCD4 AF4B0118 */  sw         $t3, 0x118($k0) /* handwritten instruction */
    /* BC8D8 002BBCD8 3108FF00 */  andi       $t0, $t0, 0xFF00
    /* BC8DC 002BBCDC 01284824 */  and        $t1, $t1, $t0
    /* BC8E0 002BBCE0 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* BC8E4 002BBCE4 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* BC8E8 002BBCE8 0361D824 */  and        $k1, $k1, $at
    /* BC8EC 002BBCEC 0369D825 */  or         $k1, $k1, $t1
.Lauto_002BBCF0:
    /* BC8F0 002BBCF0 3C09A430 */  lui        $t1, %hi(MI_INTR_MASK_REG)
    /* BC8F4 002BBCF4 8D29000C */  lw         $t1, %lo(MI_INTR_MASK_REG)($t1)
    /* BC8F8 002BBCF8 00000000 */  nop
    /* BC8FC 002BBCFC 1120000C */  .word 0x1120000C
    /* BC900 002BBD00 00000000 */  nop
    /* BC904 002BBD04 3C08800D */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BC908 002BBD08 25083F08 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BC90C 002BBD0C 8D080000 */  lw         $t0, 0x0($t0)
    /* BC910 002BBD10 00000000 */  nop
    /* BC914 002BBD14 00084402 */  srl        $t0, $t0, 16
    /* BC918 002BBD18 2401FFFF */  addiu      $at, $zero, -0x1
    /* BC91C 002BBD1C 01014026 */  xor        $t0, $t0, $at
    /* BC920 002BBD20 8F4C0128 */  lw         $t4, 0x128($k0) /* handwritten instruction */
    /* BC924 002BBD24 3108003F */  andi       $t0, $t0, 0x3F
    /* BC928 002BBD28 010C4024 */  and        $t0, $t0, $t4
    /* BC92C 002BBD2C 01284825 */  or         $t1, $t1, $t0
.Lauto_002BBD30:
    /* BC930 002BBD30 40087000 */  mfc0       $t0, $14 /* handwritten instruction */
    /* BC934 002BBD34 AF490128 */  sw         $t1, 0x128($k0) /* handwritten instruction */
    /* BC938 002BBD38 AF48011C */  sw         $t0, 0x11C($k0) /* handwritten instruction */
    /* BC93C 002BBD3C 8F480018 */  lw         $t0, 0x18($k0) /* handwritten instruction */
    /* BC940 002BBD40 00000000 */  nop
    /* BC944 002BBD44 11000029 */  .word 0x11000029
    /* BC948 002BBD48 00000000 */  nop
    /* BC94C 002BBD4C 4448F800 */  cfc1       $t0, $31
    /* BC950 002BBD50 00000000 */  nop
    /* BC954 002BBD54 AF48012C */  sw         $t0, 0x12C($k0) /* handwritten instruction */
    /* BC958 002BBD58 F7400130 */  sdc1       $fv0, 0x130($k0)
    /* BC95C 002BBD5C F7420138 */  sdc1       $fv1, 0x138($k0)
    /* BC960 002BBD60 F7440140 */  sdc1       $ft0, 0x140($k0)
    /* BC964 002BBD64 F7460148 */  sdc1       $ft1, 0x148($k0)
    /* BC968 002BBD68 F7480150 */  sdc1       $ft2, 0x150($k0)
    /* BC96C 002BBD6C F74A0158 */  sdc1       $ft3, 0x158($k0)
    /* BC970 002BBD70 F74C0160 */  sdc1       $fa0, 0x160($k0)
    /* BC974 002BBD74 F74E0168 */  sdc1       $fa1, 0x168($k0)
    /* BC978 002BBD78 F7500170 */  sdc1       $ft4, 0x170($k0)
    /* BC97C 002BBD7C F7520178 */  sdc1       $ft5, 0x178($k0)
    /* BC980 002BBD80 F7540180 */  sdc1       $fs0, 0x180($k0)
    /* BC984 002BBD84 F7560188 */  sdc1       $fs1, 0x188($k0)
    /* BC988 002BBD88 F7580190 */  sdc1       $fs2, 0x190($k0)
    /* BC98C 002BBD8C F75A0198 */  sdc1       $fs3, 0x198($k0)
    /* BC990 002BBD90 F75C01A0 */  sdc1       $fs4, 0x1A0($k0)
    /* BC994 002BBD94 8F490118 */  lw         $t1, 0x118($k0) /* handwritten instruction */
    /* BC998 002BBD98 F75E01A8 */  sdc1       $fs5, 0x1A8($k0)
    /* BC99C 002BBD9C 3C010400 */  lui        $at, (0x4000000 >> 16)
    /* BC9A0 002BBDA0 01214824 */  and        $t1, $t1, $at
    /* BC9A4 002BBDA4 11200011 */  .word 0x11200011
    /* BC9A8 002BBDA8 00000000 */  nop
    /* BC9AC 002BBDAC F74101B0 */  sdc1       $fv0f, 0x1B0($k0)
    /* BC9B0 002BBDB0 F74301B8 */  sdc1       $fv1f, 0x1B8($k0)
    /* BC9B4 002BBDB4 F74501C0 */  sdc1       $ft0f, 0x1C0($k0)
    /* BC9B8 002BBDB8 F74701C8 */  sdc1       $ft1f, 0x1C8($k0)
    /* BC9BC 002BBDBC F74901D0 */  sdc1       $ft2f, 0x1D0($k0)
    /* BC9C0 002BBDC0 F74B01D8 */  sdc1       $ft3f, 0x1D8($k0)
    /* BC9C4 002BBDC4 F74D01E0 */  sdc1       $fa0f, 0x1E0($k0)
    /* BC9C8 002BBDC8 F74F01E8 */  sdc1       $fa1f, 0x1E8($k0)
    /* BC9CC 002BBDCC F75101F0 */  sdc1       $ft4f, 0x1F0($k0)
    /* BC9D0 002BBDD0 F75301F8 */  sdc1       $ft5f, 0x1F8($k0)
    /* BC9D4 002BBDD4 F7550200 */  sdc1       $fs0f, 0x200($k0)
    /* BC9D8 002BBDD8 F7570208 */  sdc1       $fs1f, 0x208($k0)
    /* BC9DC 002BBDDC F7590210 */  sdc1       $fs2f, 0x210($k0)
    /* BC9E0 002BBDE0 F75B0218 */  sdc1       $fs3f, 0x218($k0)
    /* BC9E4 002BBDE4 F75D0220 */  sdc1       $fs4f, 0x220($k0)
    /* BC9E8 002BBDE8 F75F0228 */  sdc1       $fs5f, 0x228($k0)
.Lauto_002BBDEC:
    /* BC9EC 002BBDEC 40086800 */  mfc0       $t0, $13 /* handwritten instruction */
    /* BC9F0 002BBDF0 24090002 */  addiu      $t1, $zero, 0x2
    /* BC9F4 002BBDF4 AF480120 */  sw         $t0, 0x120($k0) /* handwritten instruction */
    /* BC9F8 002BBDF8 A7490010 */  sh         $t1, 0x10($k0) /* handwritten instruction */
    /* BC9FC 002BBDFC 3109007C */  andi       $t1, $t0, 0x7C
    /* BCA00 002BBE00 240A0024 */  addiu      $t2, $zero, 0x24
    /* BCA04 002BBE04 112A00BD */  .word 0x112A00BD
    /* BCA08 002BBE08 240A002C */  addiu     $t2, $zero, 0x2C
    /* BCA0C 002BBE0C 112A0115 */  .word 0x112A0115
    /* BCA10 002BBE10 240A0000 */  addiu     $t2, $zero, 0x0
    /* BCA14 002BBE14 152A00D4 */  .word 0x152A00D4
    /* BCA18 002BBE18 03688024 */  and       $s0, $k1, $t0
.Lauto_002BBE1C:
    /* BCA1C 002BBE1C 3209FF00 */  andi       $t1, $s0, 0xFF00
    /* BCA20 002BBE20 00095302 */  srl        $t2, $t1, 12
    /* BCA24 002BBE24 15400003 */  .word 0x15400003
    /* BCA28 002BBE28 00000000 */  nop
    /* BCA2C 002BBE2C 00095202 */  srl        $t2, $t1, 8
    /* BCA30 002BBE30 214A0010 */  addi       $t2, $t2, 0x10 /* handwritten instruction */
.Lauto_002BBE34:
    /* BCA34 002BBE34 3C01800C */  lui        $at, %hi(__osIntOffTable)
    /* BCA38 002BBE38 002A0821 */  addu       $at, $at, $t2
    /* BCA3C 002BBE3C 902A7940 */  lbu        $t2, %lo(__osIntOffTable)($at)
    /* BCA40 002BBE40 3C01800C */  lui        $at, %hi(jtbl_auto_800C7960)
    /* BCA44 002BBE44 002A0821 */  addu       $at, $at, $t2
    /* BCA48 002BBE48 8C2A7960 */  lw         $t2, %lo(jtbl_auto_800C7960)($at)
    /* BCA4C 002BBE4C 00000000 */  nop
    /* BCA50 002BBE50 01400008 */  jr         $t2
    /* BCA54 002BBE54 00000000 */  nop
    /* BCA58 002BBE58 2401DFFF */  addiu      $at, $zero, -0x2001
    /* BCA5C 002BBE5C 02018024 */  and        $s0, $s0, $at
    /* BCA60 002BBE60 0401FFEE */  .word 0x0401FFEE
    /* BCA64 002BBE64 00000000 */  nop
    /* BCA68 002BBE68 2401BFFF */  addiu      $at, $zero, -0x4001
    /* BCA6C 002BBE6C 02018024 */  and        $s0, $s0, $at
    /* BCA70 002BBE70 0401FFEA */  .word 0x0401FFEA
    /* BCA74 002BBE74 00000000 */  nop
    /* BCA78 002BBE78 40095800 */  mfc0       $t1, $11 /* handwritten instruction */
    /* BCA7C 002BBE7C 3C01FFFF */  lui        $at, (0xFFFF7FFF >> 16)
    /* BCA80 002BBE80 34217FFF */  ori        $at, $at, (0xFFFF7FFF & 0xFFFF)
    /* BCA84 002BBE84 02018024 */  and        $s0, $s0, $at
    /* BCA88 002BBE88 40895800 */  mtc0       $t1, $11 /* handwritten instruction */
    /* BCA8C 002BBE8C 0C0AF066 */  jal        send_mesg
    /* BCA90 002BBE90 24040018 */  addiu     $a0, $zero, 0x18
    /* BCA94 002BBE94 0401FFE1 */  .word 0x0401FFE1
    /* BCA98 002BBE98 00000000 */  nop
    /* BCA9C 002BBE9C 24040010 */  addiu      $a0, $zero, 0x10
    /* BCAA0 002BBEA0 2401F7FF */  addiu      $at, $zero, -0x801
    /* BCAA4 002BBEA4 02018024 */  and        $s0, $s0, $at
    /* BCAA8 002BBEA8 3C1D8014 */  lui        $sp, %hi(__osHwIntStack)
    /* BCAAC 002BBEAC 27BD7BD0 */  addiu      $sp, $sp, %lo(__osHwIntStack)
    /* BCAB0 002BBEB0 27BD0FF0 */  addiu      $sp, $sp, 0xFF0
    /* BCAB4 002BBEB4 240A0004 */  addiu      $t2, $zero, 0x4
    /* BCAB8 002BBEB8 3C01800D */  lui        $at, %hi(__osHwIntTable)
    /* BCABC 002BBEBC 002A0821 */  addu       $at, $at, $t2
    /* BCAC0 002BBEC0 8C2A3F40 */  lw         $t2, %lo(__osHwIntTable)($at)
    /* BCAC4 002BBEC4 00000000 */  nop
    /* BCAC8 002BBEC8 11400007 */  .word 0x11400007
    /* BCACC 002BBECC 00000000 */  nop
    /* BCAD0 002BBED0 0140F809 */  jalr       $t2
    /* BCAD4 002BBED4 24040010 */  addiu     $a0, $zero, 0x10
    /* BCAD8 002BBED8 10400003 */  .word 0x10400003
    /* BCADC 002BBEDC 00000000 */  nop
    /* BCAE0 002BBEE0 0401008C */  .word 0x0401008C
    /* BCAE4 002BBEE4 00000000 */  nop
.Lauto_002BBEE8:
    /* BCAE8 002BBEE8 0C0AF066 */  jal        send_mesg
    /* BCAEC 002BBEEC 00000000 */  nop
    /* BCAF0 002BBEF0 0401FFCA */  .word 0x0401FFCA
    /* BCAF4 002BBEF4 00000000 */  nop
    /* BCAF8 002BBEF8 3C11A430 */  lui        $s1, %hi(MI_INTR_REG)
    /* BCAFC 002BBEFC 8E310008 */  lw         $s1, %lo(MI_INTR_REG)($s1)
    /* BCB00 002BBF00 3C08800D */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BCB04 002BBF04 25083F08 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BCB08 002BBF08 8D080000 */  lw         $t0, 0x0($t0)
    /* BCB0C 002BBF0C 00000000 */  nop
    /* BCB10 002BBF10 00084402 */  srl        $t0, $t0, 16
    /* BCB14 002BBF14 02288824 */  and        $s1, $s1, $t0
    /* BCB18 002BBF18 32290001 */  andi       $t1, $s1, 0x1
    /* BCB1C 002BBF1C 11200014 */  .word 0x11200014
    /* BCB20 002BBF20 00000000 */  nop
    /* BCB24 002BBF24 3231003E */  andi       $s1, $s1, 0x3E
    /* BCB28 002BBF28 3C0CA404 */  lui        $t4, %hi(SP_STATUS_REG)
    /* BCB2C 002BBF2C 8D8C0010 */  lw         $t4, %lo(SP_STATUS_REG)($t4)
    /* BCB30 002BBF30 34098008 */  ori        $t1, $zero, 0x8008
    /* BCB34 002BBF34 3C01A404 */  lui        $at, %hi(SP_STATUS_REG)
    /* BCB38 002BBF38 AC290010 */  sw         $t1, %lo(SP_STATUS_REG)($at)
    /* BCB3C 002BBF3C 318C0300 */  andi       $t4, $t4, 0x300
    /* BCB40 002BBF40 11800007 */  .word 0x11800007
    /* BCB44 002BBF44 00000000 */  nop
    /* BCB48 002BBF48 0C0AF066 */  jal        send_mesg
    /* BCB4C 002BBF4C 24040020 */  addiu     $a0, $zero, 0x20
    /* BCB50 002BBF50 1220003A */  .word 0x1220003A
    /* BCB54 002BBF54 00000000 */  nop
    /* BCB58 002BBF58 04010005 */  .word 0x04010005
    /* BCB5C 002BBF5C 00000000 */  nop
.Lauto_002BBF60:
    /* BCB60 002BBF60 0C0AF066 */  jal        send_mesg
    /* BCB64 002BBF64 24040058 */  addiu     $a0, $zero, 0x58
    /* BCB68 002BBF68 12200034 */  .word 0x12200034
    /* BCB6C 002BBF6C 00000000 */  nop
.Lauto_002BBF70:
    /* BCB70 002BBF70 32290008 */  andi       $t1, $s1, 0x8
    /* BCB74 002BBF74 00000000 */  nop
    /* BCB78 002BBF78 11200007 */  .word 0x11200007
    /* BCB7C 002BBF7C 32310037 */  andi      $s1, $s1, 0x37
    /* BCB80 002BBF80 3C01A440 */  lui        $at, %hi(VI_CURRENT_REG)
    /* BCB84 002BBF84 AC200010 */  sw         $zero, %lo(VI_CURRENT_REG)($at)
    /* BCB88 002BBF88 0C0AF066 */  jal        send_mesg
    /* BCB8C 002BBF8C 24040038 */  addiu     $a0, $zero, 0x38
    /* BCB90 002BBF90 1220002A */  .word 0x1220002A
    /* BCB94 002BBF94 00000000 */  nop
.Lauto_002BBF98:
    /* BCB98 002BBF98 32290004 */  andi       $t1, $s1, 0x4
    /* BCB9C 002BBF9C 11200009 */  .word 0x11200009
    /* BCBA0 002BBFA0 00000000 */  nop
    /* BCBA4 002BBFA4 3231003B */  andi       $s1, $s1, 0x3B
    /* BCBA8 002BBFA8 24090001 */  addiu      $t1, $zero, 0x1
    /* BCBAC 002BBFAC 3C01A450 */  lui        $at, %hi(AI_STATUS_REG)
    /* BCBB0 002BBFB0 AC29000C */  sw         $t1, %lo(AI_STATUS_REG)($at)
    /* BCBB4 002BBFB4 0C0AF066 */  jal        send_mesg
    /* BCBB8 002BBFB8 24040030 */  addiu     $a0, $zero, 0x30
    /* BCBBC 002BBFBC 1220001F */  .word 0x1220001F
    /* BCBC0 002BBFC0 00000000 */  nop
.Lauto_002BBFC4:
    /* BCBC4 002BBFC4 32290002 */  andi       $t1, $s1, 0x2
    /* BCBC8 002BBFC8 11200008 */  .word 0x11200008
    /* BCBCC 002BBFCC 00000000 */  nop
    /* BCBD0 002BBFD0 3231003D */  andi       $s1, $s1, 0x3D
    /* BCBD4 002BBFD4 3C01A480 */  lui        $at, %hi(SI_STATUS_REG)
    /* BCBD8 002BBFD8 AC200018 */  sw         $zero, %lo(SI_STATUS_REG)($at)
    /* BCBDC 002BBFDC 0C0AF066 */  jal        send_mesg
    /* BCBE0 002BBFE0 24040028 */  addiu     $a0, $zero, 0x28
    /* BCBE4 002BBFE4 12200015 */  .word 0x12200015
    /* BCBE8 002BBFE8 00000000 */  nop
.Lauto_002BBFEC:
    /* BCBEC 002BBFEC 32290010 */  andi       $t1, $s1, 0x10
    /* BCBF0 002BBFF0 11200009 */  .word 0x11200009
    /* BCBF4 002BBFF4 00000000 */  nop
    /* BCBF8 002BBFF8 3231002F */  andi       $s1, $s1, 0x2F
    /* BCBFC 002BBFFC 24090002 */  addiu      $t1, $zero, 0x2
    /* BCC00 002BC000 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* BCC04 002BC004 AC290010 */  sw         $t1, %lo(PI_STATUS_REG)($at)
    /* BCC08 002BC008 0C0AF066 */  jal        send_mesg
    /* BCC0C 002BC00C 24040040 */  addiu     $a0, $zero, 0x40
    /* BCC10 002BC010 1220000A */  .word 0x1220000A
    /* BCC14 002BC014 00000000 */  nop
.Lauto_002BC018:
    /* BCC18 002BC018 32290020 */  andi       $t1, $s1, 0x20
    /* BCC1C 002BC01C 11200007 */  .word 0x11200007
    /* BCC20 002BC020 00000000 */  nop
    /* BCC24 002BC024 3231001F */  andi       $s1, $s1, 0x1F
    /* BCC28 002BC028 24090800 */  addiu      $t1, $zero, 0x800
    /* BCC2C 002BC02C 3C01A430 */  lui        $at, %hi(MI_MODE_REG)
    /* BCC30 002BC030 AC290000 */  sw         $t1, %lo(MI_MODE_REG)($at)
    /* BCC34 002BC034 0C0AF066 */  jal        send_mesg
    /* BCC38 002BC038 24040048 */  addiu     $a0, $zero, 0x48
.Lauto_002BC03C:
    /* BCC3C 002BC03C 2401FBFF */  addiu      $at, $zero, -0x401
    /* BCC40 002BC040 02018024 */  and        $s0, $s0, $at
    /* BCC44 002BC044 0401FF75 */  .word 0x0401FF75
    /* BCC48 002BC048 00000000 */  nop
    /* BCC4C 002BC04C 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* BCC50 002BC050 3C09800D */  lui        $t1, %hi(__osShutdown)
    /* BCC54 002BC054 25293F04 */  addiu      $t1, $t1, %lo(__osShutdown)
    /* BCC58 002BC058 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BCC5C 002BC05C 0361D824 */  and        $k1, $k1, $at
    /* BCC60 002BC060 8D2A0000 */  lw         $t2, 0x0($t1)
    /* BCC64 002BC064 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BCC68 002BC068 02018024 */  and        $s0, $s0, $at
    /* BCC6C 002BC06C 11400003 */  .word 0x11400003
    /* BCC70 002BC070 AF5B0118 */  sw        $k1, 0x118($k0) /* handwritten instruction */
    /* BCC74 002BC074 04010027 */  .word 0x04010027
    /* BCC78 002BC078 00000000 */  nop
.Lauto_002BC07C:
    /* BCC7C 002BC07C 240A0001 */  addiu      $t2, $zero, 0x1
    /* BCC80 002BC080 AD2A0000 */  sw         $t2, 0x0($t1)
    /* BCC84 002BC084 0C0AF066 */  jal        send_mesg
    /* BCC88 002BC088 24040070 */  addiu     $a0, $zero, 0x70
    /* BCC8C 002BC08C 3C0A800D */  lui        $t2, %hi(__osRunQueue)
    /* BCC90 002BC090 8D4A3F18 */  lw         $t2, %lo(__osRunQueue)($t2)
    /* BCC94 002BC094 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BCC98 002BC098 02018024 */  and        $s0, $s0, $at
    /* BCC9C 002BC09C 8D5B0118 */  lw         $k1, 0x118($t2) /* handwritten instruction */
    /* BCCA0 002BC0A0 00000000 */  nop
    /* BCCA4 002BC0A4 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BCCA8 002BC0A8 0361D824 */  and        $k1, $k1, $at
    /* BCCAC 002BC0AC 04010019 */  .word 0x04010019
    /* BCCB0 002BC0B0 AD5B0118 */  sw        $k1, 0x118($t2) /* handwritten instruction */
    /* BCCB4 002BC0B4 2401FDFF */  addiu      $at, $zero, -0x201
    /* BCCB8 002BC0B8 01014024 */  and        $t0, $t0, $at
    /* BCCBC 002BC0BC 40886800 */  mtc0       $t0, $13 /* handwritten instruction */
    /* BCCC0 002BC0C0 2401FDFF */  addiu      $at, $zero, -0x201
    /* BCCC4 002BC0C4 02018024 */  and        $s0, $s0, $at
    /* BCCC8 002BC0C8 0C0AF066 */  jal        send_mesg
    /* BCCCC 002BC0CC 24040008 */  addiu     $a0, $zero, 0x8
    /* BCCD0 002BC0D0 0401FF52 */  .word 0x0401FF52
    /* BCCD4 002BC0D4 00000000 */  nop
    /* BCCD8 002BC0D8 2401FEFF */  addiu      $at, $zero, -0x101
    /* BCCDC 002BC0DC 01014024 */  and        $t0, $t0, $at
    /* BCCE0 002BC0E0 40886800 */  mtc0       $t0, $13 /* handwritten instruction */
    /* BCCE4 002BC0E4 2401FEFF */  addiu      $at, $zero, -0x101
    /* BCCE8 002BC0E8 02018024 */  and        $s0, $s0, $at
    /* BCCEC 002BC0EC 0C0AF066 */  jal        send_mesg
    /* BCCF0 002BC0F0 24040000 */  addiu     $a0, $zero, 0x0
    /* BCCF4 002BC0F4 0401FF49 */  .word 0x0401FF49
    /* BCCF8 002BC0F8 00000000 */  nop
.Lauto_002BC0FC:
    /* BCCFC 002BC0FC 24090001 */  addiu      $t1, $zero, 0x1
    /* BCD00 002BC100 A7490012 */  sh         $t1, 0x12($k0) /* handwritten instruction */
    /* BCD04 002BC104 0C0AF066 */  jal        send_mesg
    /* BCD08 002BC108 24040050 */  addiu     $a0, $zero, 0x50
    /* BCD0C 002BC10C 04010001 */  .word 0x04010001
    /* BCD10 002BC110 00000000 */  nop
.Lauto_002BC114:
    /* BCD14 002BC114 3C0A800D */  lui        $t2, %hi(__osRunQueue)
    /* BCD18 002BC118 8D4A3F18 */  lw         $t2, %lo(__osRunQueue)($t2)
    /* BCD1C 002BC11C 8F490004 */  lw         $t1, 0x4($k0) /* handwritten instruction */
    /* BCD20 002BC120 8D4B0004 */  lw         $t3, 0x4($t2)
    /* BCD24 002BC124 00000000 */  nop
    /* BCD28 002BC128 012B082A */  slt        $at, $t1, $t3
    /* BCD2C 002BC12C 10200007 */  .word 0x10200007
    /* BCD30 002BC130 00000000 */  nop
    /* BCD34 002BC134 3C04800D */  lui        $a0, %hi(__osRunQueue)
    /* BCD38 002BC138 24843F18 */  addiu      $a0, $a0, %lo(__osRunQueue)
    /* BCD3C 002BC13C 0C0AF10E */  jal        __osEnqueueThread
    /* BCD40 002BC140 03402821 */  addu      $a1, $k0, $zero
    /* BCD44 002BC144 080AF128 */  j          __osDispatchThread
    /* BCD48 002BC148 00000000 */  nop
.Lauto_002BC14C:
    /* BCD4C 002BC14C 3C09800D */  lui        $t1, %hi(__osRunQueue)
    /* BCD50 002BC150 25293F18 */  addiu      $t1, $t1, %lo(__osRunQueue)
    /* BCD54 002BC154 8D2A0000 */  lw         $t2, 0x0($t1)
    /* BCD58 002BC158 00000000 */  nop
    /* BCD5C 002BC15C AF4A0000 */  sw         $t2, 0x0($k0) /* handwritten instruction */
    /* BCD60 002BC160 080AF128 */  j          __osDispatchThread
    /* BCD64 002BC164 AD3A0000 */  sw        $k0, 0x0($t1) /* handwritten instruction */
.Lauto_002BC168:
    /* BCD68 002BC168 3C01800D */  lui        $at, %hi(__osFaultedThread)
    /* BCD6C 002BC16C AC3A3F24 */  sw         $k0, %lo(__osFaultedThread)($at) /* handwritten instruction */
    /* BCD70 002BC170 24090001 */  addiu      $t1, $zero, 0x1
    /* BCD74 002BC174 A7490010 */  sh         $t1, 0x10($k0) /* handwritten instruction */
    /* BCD78 002BC178 24090002 */  addiu      $t1, $zero, 0x2
    /* BCD7C 002BC17C 400A4000 */  mfc0       $t2, $8 /* handwritten instruction */
    /* BCD80 002BC180 A7490012 */  sh         $t1, 0x12($k0) /* handwritten instruction */
    /* BCD84 002BC184 AF4A0124 */  sw         $t2, 0x124($k0) /* handwritten instruction */
    /* BCD88 002BC188 0C0AF066 */  jal        send_mesg
    /* BCD8C 002BC18C 24040060 */  addiu     $a0, $zero, 0x60
    /* BCD90 002BC190 080AF128 */  j          __osDispatchThread
    /* BCD94 002BC194 00000000 */  nop
.globl send_mesg
send_mesg:
    /* BCD98 002BC198 03E09021 */  addu       $s2, $ra, $zero
    /* BCD9C 002BC19C 3C0A8014 */  lui        $t2, %hi(__osEventStateTab)
    /* BCDA0 002BC1A0 254A7B10 */  addiu      $t2, $t2, %lo(__osEventStateTab)
    /* BCDA4 002BC1A4 01445021 */  addu       $t2, $t2, $a0
    /* BCDA8 002BC1A8 8D490000 */  lw         $t1, 0x0($t2)
    /* BCDAC 002BC1AC 00000000 */  nop
    /* BCDB0 002BC1B0 1120002A */  .word 0x1120002A
    /* BCDB4 002BC1B4 00000000 */  nop
    /* BCDB8 002BC1B8 8D2B0008 */  lw         $t3, 0x8($t1)
    /* BCDBC 002BC1BC 8D2C0010 */  lw         $t4, 0x10($t1)
    /* BCDC0 002BC1C0 00000000 */  nop
    /* BCDC4 002BC1C4 016C082A */  slt        $at, $t3, $t4
    /* BCDC8 002BC1C8 10200024 */  .word 0x10200024
    /* BCDCC 002BC1CC 00000000 */  nop
    /* BCDD0 002BC1D0 8D2D000C */  lw         $t5, 0xC($t1)
    /* BCDD4 002BC1D4 00000000 */  nop
    /* BCDD8 002BC1D8 01AB6821 */  addu       $t5, $t5, $t3
    /* BCDDC 002BC1DC 01AC001A */  div        $zero, $t5, $t4
    /* BCDE0 002BC1E0 15800002 */  .word 0x15800002
    /* BCDE4 002BC1E4 00000000 */  nop
    /* BCDE8 002BC1E8 0007000D */  break      7
.Lauto_002BC1EC:
    /* BCDEC 002BC1EC 2401FFFF */  addiu      $at, $zero, -0x1
    /* BCDF0 002BC1F0 15810004 */  .word 0x15810004
    /* BCDF4 002BC1F4 3C018000 */  lui       $at, (0x80000000 >> 16)
    /* BCDF8 002BC1F8 15A10002 */  .word 0x15A10002
    /* BCDFC 002BC1FC 00000000 */  nop
    /* BCE00 002BC200 0006000D */  break      6
.Lauto_002BC204:
    /* BCE04 002BC204 00006810 */  mfhi       $t5
    /* BCE08 002BC208 8D2C0014 */  lw         $t4, 0x14($t1)
    /* BCE0C 002BC20C 000D6880 */  sll        $t5, $t5, 2
    /* BCE10 002BC210 018D6021 */  addu       $t4, $t4, $t5
    /* BCE14 002BC214 8D4D0004 */  lw         $t5, 0x4($t2)
    /* BCE18 002BC218 00000000 */  nop
    /* BCE1C 002BC21C AD8D0000 */  sw         $t5, 0x0($t4)
    /* BCE20 002BC220 256A0001 */  addiu      $t2, $t3, 0x1
    /* BCE24 002BC224 AD2A0008 */  sw         $t2, 0x8($t1)
    /* BCE28 002BC228 8D2A0000 */  lw         $t2, 0x0($t1)
    /* BCE2C 002BC22C 00000000 */  nop
    /* BCE30 002BC230 8D4B0000 */  lw         $t3, 0x0($t2)
    /* BCE34 002BC234 00000000 */  nop
    /* BCE38 002BC238 11600008 */  .word 0x11600008
    /* BCE3C 002BC23C 00000000 */  nop
    /* BCE40 002BC240 0C0AF122 */  jal        __osPopThread
    /* BCE44 002BC244 01202021 */  addu      $a0, $t1, $zero
    /* BCE48 002BC248 00405021 */  addu       $t2, $v0, $zero
    /* BCE4C 002BC24C 3C04800D */  lui        $a0, %hi(__osRunQueue)
    /* BCE50 002BC250 24843F18 */  addiu      $a0, $a0, %lo(__osRunQueue)
    /* BCE54 002BC254 0C0AF10E */  jal        __osEnqueueThread
    /* BCE58 002BC258 01402821 */  addu      $a1, $t2, $zero
.Lauto_002BC25C:
    /* BCE5C 002BC25C 02400008 */  jr         $s2
    /* BCE60 002BC260 00000000 */  nop
.Lauto_002BC264:
    /* BCE64 002BC264 3C013000 */  lui        $at, (0x30000000 >> 16)
    /* BCE68 002BC268 01014824 */  and        $t1, $t0, $at
    /* BCE6C 002BC26C 00094F02 */  srl        $t1, $t1, 28
    /* BCE70 002BC270 240A0001 */  addiu      $t2, $zero, 0x1
    /* BCE74 002BC274 152AFFBC */  .word 0x152AFFBC
    /* BCE78 002BC278 24090001 */  addiu     $t1, $zero, 0x1
    /* BCE7C 002BC27C AF490018 */  sw         $t1, 0x18($k0) /* handwritten instruction */
    /* BCE80 002BC280 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* BCE84 002BC284 00000000 */  nop
    /* BCE88 002BC288 3C012000 */  lui        $at, (0x20000000 >> 16)
    /* BCE8C 002BC28C 0361D825 */  or         $k1, $k1, $at
    /* BCE90 002BC290 AF5B0118 */  sw         $k1, 0x118($k0) /* handwritten instruction */
    /* BCE94 002BC294 0401FFAD */  .word 0x0401FFAD
    /* BCE98 002BC298 00000000 */  nop
