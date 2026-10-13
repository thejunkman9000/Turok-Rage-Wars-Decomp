.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBCB10-0xBD20C (VRAM 0x002BBF10) */
.globl __osExceptionPreamble
__osExceptionPreamble:
    /* BCB10 002BBF10 3C1A002C */  lui        $k0, %hi(__osException) /* handwritten instruction */
    /* BCB14 002BBF14 275ABF20 */  addiu      $k0, $k0, %lo(__osException) /* handwritten instruction */
    /* BCB18 002BBF18 03400008 */  jr         $k0
    /* BCB1C 002BBF1C 00000000 */  nop
.globl __osException
__osException:
    /* BCB20 002BBF20 3C1A8016 */  lui        $k0, %hi(__osThreadSave) /* handwritten instruction */
    /* BCB24 002BBF24 275AABD0 */  addiu      $k0, $k0, %lo(__osThreadSave) /* handwritten instruction */
    /* BCB28 002BBF28 FF410020 */  sd         $at, 0x20($k0) /* handwritten instruction */
    /* BCB2C 002BBF2C 401B6000 */  mfc0       $k1, $12 /* handwritten instruction */
    /* BCB30 002BBF30 00000000 */  nop
    /* BCB34 002BBF34 AF5B0118 */  sw         $k1, 0x118($k0) /* handwritten instruction */
    /* BCB38 002BBF38 2401FFFC */  addiu      $at, $zero, -0x4
    /* BCB3C 002BBF3C 0361D824 */  and        $k1, $k1, $at
    /* BCB40 002BBF40 409B6000 */  mtc0       $k1, $12 /* handwritten instruction */
    /* BCB44 002BBF44 FF480058 */  sd         $t0, 0x58($k0) /* handwritten instruction */
    /* BCB48 002BBF48 FF490060 */  sd         $t1, 0x60($k0) /* handwritten instruction */
    /* BCB4C 002BBF4C FF4A0068 */  sd         $t2, 0x68($k0) /* handwritten instruction */
    /* BCB50 002BBF50 AF400018 */  sw         $zero, 0x18($k0) /* handwritten instruction */
    /* BCB54 002BBF54 40086800 */  mfc0       $t0, $13 /* handwritten instruction */
    /* BCB58 002BBF58 03404021 */  addu       $t0, $k0, $zero
    /* BCB5C 002BBF5C 3C1A800E */  lui        $k0, %hi(__osRunningThread) /* handwritten instruction */
    /* BCB60 002BBF60 8F5A58F0 */  lw         $k0, %lo(__osRunningThread)($k0) /* handwritten instruction */
    /* BCB64 002BBF64 DD090020 */  ld         $t1, 0x20($t0)
    /* BCB68 002BBF68 DD0A0118 */  ld         $t2, 0x118($t0)
    /* BCB6C 002BBF6C FF490020 */  sd         $t1, 0x20($k0) /* handwritten instruction */
    /* BCB70 002BBF70 FF4A0118 */  sd         $t2, 0x118($k0) /* handwritten instruction */
    /* BCB74 002BBF74 DD090058 */  ld         $t1, 0x58($t0)
    /* BCB78 002BBF78 DD0A0060 */  ld         $t2, 0x60($t0)
    /* BCB7C 002BBF7C FF490058 */  sd         $t1, 0x58($k0) /* handwritten instruction */
    /* BCB80 002BBF80 FF4A0060 */  sd         $t2, 0x60($k0) /* handwritten instruction */
    /* BCB84 002BBF84 DD090068 */  ld         $t1, 0x68($t0)
    /* BCB88 002BBF88 FF420028 */  sd         $v0, 0x28($k0) /* handwritten instruction */
    /* BCB8C 002BBF8C FF490068 */  sd         $t1, 0x68($k0) /* handwritten instruction */
    /* BCB90 002BBF90 FF430030 */  sd         $v1, 0x30($k0) /* handwritten instruction */
    /* BCB94 002BBF94 FF440038 */  sd         $a0, 0x38($k0) /* handwritten instruction */
    /* BCB98 002BBF98 FF450040 */  sd         $a1, 0x40($k0) /* handwritten instruction */
    /* BCB9C 002BBF9C FF460048 */  sd         $a2, 0x48($k0) /* handwritten instruction */
    /* BCBA0 002BBFA0 FF470050 */  sd         $a3, 0x50($k0) /* handwritten instruction */
    /* BCBA4 002BBFA4 FF4B0070 */  sd         $t3, 0x70($k0) /* handwritten instruction */
    /* BCBA8 002BBFA8 FF4C0078 */  sd         $t4, 0x78($k0) /* handwritten instruction */
    /* BCBAC 002BBFAC FF4D0080 */  sd         $t5, 0x80($k0) /* handwritten instruction */
    /* BCBB0 002BBFB0 FF4E0088 */  sd         $t6, 0x88($k0) /* handwritten instruction */
    /* BCBB4 002BBFB4 FF4F0090 */  sd         $t7, 0x90($k0) /* handwritten instruction */
    /* BCBB8 002BBFB8 FF500098 */  sd         $s0, 0x98($k0) /* handwritten instruction */
    /* BCBBC 002BBFBC FF5100A0 */  sd         $s1, 0xA0($k0) /* handwritten instruction */
    /* BCBC0 002BBFC0 FF5200A8 */  sd         $s2, 0xA8($k0) /* handwritten instruction */
    /* BCBC4 002BBFC4 FF5300B0 */  sd         $s3, 0xB0($k0) /* handwritten instruction */
    /* BCBC8 002BBFC8 FF5400B8 */  sd         $s4, 0xB8($k0) /* handwritten instruction */
    /* BCBCC 002BBFCC FF5500C0 */  sd         $s5, 0xC0($k0) /* handwritten instruction */
    /* BCBD0 002BBFD0 FF5600C8 */  sd         $s6, 0xC8($k0) /* handwritten instruction */
    /* BCBD4 002BBFD4 FF5700D0 */  sd         $s7, 0xD0($k0) /* handwritten instruction */
    /* BCBD8 002BBFD8 FF5800D8 */  sd         $t8, 0xD8($k0) /* handwritten instruction */
    /* BCBDC 002BBFDC FF5900E0 */  sd         $t9, 0xE0($k0) /* handwritten instruction */
    /* BCBE0 002BBFE0 FF5C00E8 */  sd         $gp, 0xE8($k0) /* handwritten instruction */
    /* BCBE4 002BBFE4 FF5D00F0 */  sd         $sp, 0xF0($k0) /* handwritten instruction */
    /* BCBE8 002BBFE8 FF5E00F8 */  sd         $fp, 0xF8($k0) /* handwritten instruction */
    /* BCBEC 002BBFEC FF5F0100 */  sd         $ra, 0x100($k0) /* handwritten instruction */
    /* BCBF0 002BBFF0 00004012 */  mflo       $t0
    /* BCBF4 002BBFF4 FF480108 */  sd         $t0, 0x108($k0) /* handwritten instruction */
    /* BCBF8 002BBFF8 00004010 */  mfhi       $t0
    /* BCBFC 002BBFFC FF480110 */  sd         $t0, 0x110($k0) /* handwritten instruction */
    /* BCC00 002BC000 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* BCC04 002BC004 00000000 */  nop
    /* BCC08 002BC008 3369FF00 */  andi       $t1, $k1, 0xFF00 /* handwritten instruction */
    /* BCC0C 002BC00C 11200014 */  .word 0x11200014
    /* BCC10 002BC010 00000000 */  nop
    /* BCC14 002BC014 3C08800E */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BCC18 002BC018 250858D8 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BCC1C 002BC01C 8D080000 */  lw         $t0, 0x0($t0)
    /* BCC20 002BC020 00000000 */  nop
    /* BCC24 002BC024 2401FFFF */  addiu      $at, $zero, -0x1
    /* BCC28 002BC028 01015026 */  xor        $t2, $t0, $at
    /* BCC2C 002BC02C 314AFF00 */  andi       $t2, $t2, 0xFF00
    /* BCC30 002BC030 012A6025 */  or         $t4, $t1, $t2
    /* BCC34 002BC034 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* BCC38 002BC038 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* BCC3C 002BC03C 03615824 */  and        $t3, $k1, $at
    /* BCC40 002BC040 016C5825 */  or         $t3, $t3, $t4
    /* BCC44 002BC044 AF4B0118 */  sw         $t3, 0x118($k0) /* handwritten instruction */
    /* BCC48 002BC048 3108FF00 */  andi       $t0, $t0, 0xFF00
    /* BCC4C 002BC04C 01284824 */  and        $t1, $t1, $t0
    /* BCC50 002BC050 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* BCC54 002BC054 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* BCC58 002BC058 0361D824 */  and        $k1, $k1, $at
    /* BCC5C 002BC05C 0369D825 */  or         $k1, $k1, $t1
.Lauto_002BC060:
    /* BCC60 002BC060 3C09A430 */  lui        $t1, %hi(MI_INTR_MASK_REG)
    /* BCC64 002BC064 8D29000C */  lw         $t1, %lo(MI_INTR_MASK_REG)($t1)
    /* BCC68 002BC068 00000000 */  nop
    /* BCC6C 002BC06C 1120000C */  .word 0x1120000C
    /* BCC70 002BC070 00000000 */  nop
    /* BCC74 002BC074 3C08800E */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BCC78 002BC078 250858D8 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BCC7C 002BC07C 8D080000 */  lw         $t0, 0x0($t0)
    /* BCC80 002BC080 00000000 */  nop
    /* BCC84 002BC084 00084402 */  srl        $t0, $t0, 16
    /* BCC88 002BC088 2401FFFF */  addiu      $at, $zero, -0x1
    /* BCC8C 002BC08C 01014026 */  xor        $t0, $t0, $at
    /* BCC90 002BC090 8F4C0128 */  lw         $t4, 0x128($k0) /* handwritten instruction */
    /* BCC94 002BC094 3108003F */  andi       $t0, $t0, 0x3F
    /* BCC98 002BC098 010C4024 */  and        $t0, $t0, $t4
    /* BCC9C 002BC09C 01284825 */  or         $t1, $t1, $t0
.Lauto_002BC0A0:
    /* BCCA0 002BC0A0 40087000 */  mfc0       $t0, $14 /* handwritten instruction */
    /* BCCA4 002BC0A4 AF490128 */  sw         $t1, 0x128($k0) /* handwritten instruction */
    /* BCCA8 002BC0A8 AF48011C */  sw         $t0, 0x11C($k0) /* handwritten instruction */
    /* BCCAC 002BC0AC 8F480018 */  lw         $t0, 0x18($k0) /* handwritten instruction */
    /* BCCB0 002BC0B0 00000000 */  nop
    /* BCCB4 002BC0B4 11000029 */  .word 0x11000029
    /* BCCB8 002BC0B8 00000000 */  nop
    /* BCCBC 002BC0BC 4448F800 */  cfc1       $t0, $31
    /* BCCC0 002BC0C0 00000000 */  nop
    /* BCCC4 002BC0C4 AF48012C */  sw         $t0, 0x12C($k0) /* handwritten instruction */
    /* BCCC8 002BC0C8 F7400130 */  sdc1       $fv0, 0x130($k0)
    /* BCCCC 002BC0CC F7420138 */  sdc1       $fv1, 0x138($k0)
    /* BCCD0 002BC0D0 F7440140 */  sdc1       $ft0, 0x140($k0)
    /* BCCD4 002BC0D4 F7460148 */  sdc1       $ft1, 0x148($k0)
    /* BCCD8 002BC0D8 F7480150 */  sdc1       $ft2, 0x150($k0)
    /* BCCDC 002BC0DC F74A0158 */  sdc1       $ft3, 0x158($k0)
    /* BCCE0 002BC0E0 F74C0160 */  sdc1       $fa0, 0x160($k0)
    /* BCCE4 002BC0E4 F74E0168 */  sdc1       $fa1, 0x168($k0)
    /* BCCE8 002BC0E8 F7500170 */  sdc1       $ft4, 0x170($k0)
    /* BCCEC 002BC0EC F7520178 */  sdc1       $ft5, 0x178($k0)
    /* BCCF0 002BC0F0 F7540180 */  sdc1       $fs0, 0x180($k0)
    /* BCCF4 002BC0F4 F7560188 */  sdc1       $fs1, 0x188($k0)
    /* BCCF8 002BC0F8 F7580190 */  sdc1       $fs2, 0x190($k0)
    /* BCCFC 002BC0FC F75A0198 */  sdc1       $fs3, 0x198($k0)
    /* BCD00 002BC100 F75C01A0 */  sdc1       $fs4, 0x1A0($k0)
    /* BCD04 002BC104 8F490118 */  lw         $t1, 0x118($k0) /* handwritten instruction */
    /* BCD08 002BC108 F75E01A8 */  sdc1       $fs5, 0x1A8($k0)
    /* BCD0C 002BC10C 3C010400 */  lui        $at, (0x4000000 >> 16)
    /* BCD10 002BC110 01214824 */  and        $t1, $t1, $at
    /* BCD14 002BC114 11200011 */  .word 0x11200011
    /* BCD18 002BC118 00000000 */  nop
    /* BCD1C 002BC11C F74101B0 */  sdc1       $fv0f, 0x1B0($k0)
    /* BCD20 002BC120 F74301B8 */  sdc1       $fv1f, 0x1B8($k0)
    /* BCD24 002BC124 F74501C0 */  sdc1       $ft0f, 0x1C0($k0)
    /* BCD28 002BC128 F74701C8 */  sdc1       $ft1f, 0x1C8($k0)
    /* BCD2C 002BC12C F74901D0 */  sdc1       $ft2f, 0x1D0($k0)
    /* BCD30 002BC130 F74B01D8 */  sdc1       $ft3f, 0x1D8($k0)
    /* BCD34 002BC134 F74D01E0 */  sdc1       $fa0f, 0x1E0($k0)
    /* BCD38 002BC138 F74F01E8 */  sdc1       $fa1f, 0x1E8($k0)
    /* BCD3C 002BC13C F75101F0 */  sdc1       $ft4f, 0x1F0($k0)
    /* BCD40 002BC140 F75301F8 */  sdc1       $ft5f, 0x1F8($k0)
    /* BCD44 002BC144 F7550200 */  sdc1       $fs0f, 0x200($k0)
    /* BCD48 002BC148 F7570208 */  sdc1       $fs1f, 0x208($k0)
    /* BCD4C 002BC14C F7590210 */  sdc1       $fs2f, 0x210($k0)
    /* BCD50 002BC150 F75B0218 */  sdc1       $fs3f, 0x218($k0)
    /* BCD54 002BC154 F75D0220 */  sdc1       $fs4f, 0x220($k0)
    /* BCD58 002BC158 F75F0228 */  sdc1       $fs5f, 0x228($k0)
.Lauto_002BC15C:
    /* BCD5C 002BC15C 40086800 */  mfc0       $t0, $13 /* handwritten instruction */
    /* BCD60 002BC160 24090002 */  addiu      $t1, $zero, 0x2
    /* BCD64 002BC164 AF480120 */  sw         $t0, 0x120($k0) /* handwritten instruction */
    /* BCD68 002BC168 A7490010 */  sh         $t1, 0x10($k0) /* handwritten instruction */
    /* BCD6C 002BC16C 3109007C */  andi       $t1, $t0, 0x7C
    /* BCD70 002BC170 240A0024 */  addiu      $t2, $zero, 0x24
    /* BCD74 002BC174 112A00BD */  .word 0x112A00BD
    /* BCD78 002BC178 240A002C */  addiu     $t2, $zero, 0x2C
    /* BCD7C 002BC17C 112A0115 */  .word 0x112A0115
    /* BCD80 002BC180 240A0000 */  addiu     $t2, $zero, 0x0
    /* BCD84 002BC184 152A00D4 */  .word 0x152A00D4
    /* BCD88 002BC188 03688024 */  and       $s0, $k1, $t0
.Lauto_002BC18C:
    /* BCD8C 002BC18C 3209FF00 */  andi       $t1, $s0, 0xFF00
    /* BCD90 002BC190 00095302 */  srl        $t2, $t1, 12
    /* BCD94 002BC194 15400003 */  .word 0x15400003
    /* BCD98 002BC198 00000000 */  nop
    /* BCD9C 002BC19C 00095202 */  srl        $t2, $t1, 8
    /* BCDA0 002BC1A0 214A0010 */  addi       $t2, $t2, 0x10 /* handwritten instruction */
.Lauto_002BC1A4:
    /* BCDA4 002BC1A4 3C01800D */  lui        $at, %hi(__osIntOffTable)
    /* BCDA8 002BC1A8 002A0821 */  addu       $at, $at, $t2
    /* BCDAC 002BC1AC 902A8610 */  lbu        $t2, %lo(__osIntOffTable)($at)
    /* BCDB0 002BC1B0 3C01800D */  lui        $at, %hi(jtbl_auto_800C8630)
    /* BCDB4 002BC1B4 002A0821 */  addu       $at, $at, $t2
    /* BCDB8 002BC1B8 8C2A8630 */  lw         $t2, %lo(jtbl_auto_800C8630)($at)
    /* BCDBC 002BC1BC 00000000 */  nop
    /* BCDC0 002BC1C0 01400008 */  jr         $t2
    /* BCDC4 002BC1C4 00000000 */  nop
    /* BCDC8 002BC1C8 2401DFFF */  addiu      $at, $zero, -0x2001
    /* BCDCC 002BC1CC 02018024 */  and        $s0, $s0, $at
    /* BCDD0 002BC1D0 0401FFEE */  .word 0x0401FFEE
    /* BCDD4 002BC1D4 00000000 */  nop
    /* BCDD8 002BC1D8 2401BFFF */  addiu      $at, $zero, -0x4001
    /* BCDDC 002BC1DC 02018024 */  and        $s0, $s0, $at
    /* BCDE0 002BC1E0 0401FFEA */  .word 0x0401FFEA
    /* BCDE4 002BC1E4 00000000 */  nop
    /* BCDE8 002BC1E8 40095800 */  mfc0       $t1, $11 /* handwritten instruction */
    /* BCDEC 002BC1EC 3C01FFFF */  lui        $at, (0xFFFF7FFF >> 16)
    /* BCDF0 002BC1F0 34217FFF */  ori        $at, $at, (0xFFFF7FFF & 0xFFFF)
    /* BCDF4 002BC1F4 02018024 */  and        $s0, $s0, $at
    /* BCDF8 002BC1F8 40895800 */  mtc0       $t1, $11 /* handwritten instruction */
    /* BCDFC 002BC1FC 0C0AF142 */  jal        send_mesg
    /* BCE00 002BC200 24040018 */  addiu     $a0, $zero, 0x18
    /* BCE04 002BC204 0401FFE1 */  .word 0x0401FFE1
    /* BCE08 002BC208 00000000 */  nop
    /* BCE0C 002BC20C 24040010 */  addiu      $a0, $zero, 0x10
    /* BCE10 002BC210 2401F7FF */  addiu      $at, $zero, -0x801
    /* BCE14 002BC214 02018024 */  and        $s0, $s0, $at
    /* BCE18 002BC218 3C1D8016 */  lui        $sp, %hi(__osHwIntStack)
    /* BCE1C 002BC21C 27BD9BD0 */  addiu      $sp, $sp, %lo(__osHwIntStack)
    /* BCE20 002BC220 27BD0FF0 */  addiu      $sp, $sp, 0xFF0
    /* BCE24 002BC224 240A0004 */  addiu      $t2, $zero, 0x4
    /* BCE28 002BC228 3C01800E */  lui        $at, %hi(__osHwIntTable)
    /* BCE2C 002BC22C 002A0821 */  addu       $at, $at, $t2
    /* BCE30 002BC230 8C2A5910 */  lw         $t2, %lo(__osHwIntTable)($at)
    /* BCE34 002BC234 00000000 */  nop
    /* BCE38 002BC238 11400007 */  .word 0x11400007
    /* BCE3C 002BC23C 00000000 */  nop
    /* BCE40 002BC240 0140F809 */  jalr       $t2
    /* BCE44 002BC244 24040010 */  addiu     $a0, $zero, 0x10
    /* BCE48 002BC248 10400003 */  .word 0x10400003
    /* BCE4C 002BC24C 00000000 */  nop
    /* BCE50 002BC250 0401008C */  .word 0x0401008C
    /* BCE54 002BC254 00000000 */  nop
.Lauto_002BC258:
    /* BCE58 002BC258 0C0AF142 */  jal        send_mesg
    /* BCE5C 002BC25C 00000000 */  nop
    /* BCE60 002BC260 0401FFCA */  .word 0x0401FFCA
    /* BCE64 002BC264 00000000 */  nop
    /* BCE68 002BC268 3C11A430 */  lui        $s1, %hi(MI_INTR_REG)
    /* BCE6C 002BC26C 8E310008 */  lw         $s1, %lo(MI_INTR_REG)($s1)
    /* BCE70 002BC270 3C08800E */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BCE74 002BC274 250858D8 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BCE78 002BC278 8D080000 */  lw         $t0, 0x0($t0)
    /* BCE7C 002BC27C 00000000 */  nop
    /* BCE80 002BC280 00084402 */  srl        $t0, $t0, 16
    /* BCE84 002BC284 02288824 */  and        $s1, $s1, $t0
    /* BCE88 002BC288 32290001 */  andi       $t1, $s1, 0x1
    /* BCE8C 002BC28C 11200014 */  .word 0x11200014
    /* BCE90 002BC290 00000000 */  nop
    /* BCE94 002BC294 3231003E */  andi       $s1, $s1, 0x3E
    /* BCE98 002BC298 3C0CA404 */  lui        $t4, %hi(SP_STATUS_REG)
    /* BCE9C 002BC29C 8D8C0010 */  lw         $t4, %lo(SP_STATUS_REG)($t4)
    /* BCEA0 002BC2A0 34098008 */  ori        $t1, $zero, 0x8008
    /* BCEA4 002BC2A4 3C01A404 */  lui        $at, %hi(SP_STATUS_REG)
    /* BCEA8 002BC2A8 AC290010 */  sw         $t1, %lo(SP_STATUS_REG)($at)
    /* BCEAC 002BC2AC 318C0300 */  andi       $t4, $t4, 0x300
    /* BCEB0 002BC2B0 11800007 */  .word 0x11800007
    /* BCEB4 002BC2B4 00000000 */  nop
    /* BCEB8 002BC2B8 0C0AF142 */  jal        send_mesg
    /* BCEBC 002BC2BC 24040020 */  addiu     $a0, $zero, 0x20
    /* BCEC0 002BC2C0 1220003A */  .word 0x1220003A
    /* BCEC4 002BC2C4 00000000 */  nop
    /* BCEC8 002BC2C8 04010005 */  .word 0x04010005
    /* BCECC 002BC2CC 00000000 */  nop
.Lauto_002BC2D0:
    /* BCED0 002BC2D0 0C0AF142 */  jal        send_mesg
    /* BCED4 002BC2D4 24040058 */  addiu     $a0, $zero, 0x58
    /* BCED8 002BC2D8 12200034 */  .word 0x12200034
    /* BCEDC 002BC2DC 00000000 */  nop
.Lauto_002BC2E0:
    /* BCEE0 002BC2E0 32290008 */  andi       $t1, $s1, 0x8
    /* BCEE4 002BC2E4 00000000 */  nop
    /* BCEE8 002BC2E8 11200007 */  .word 0x11200007
    /* BCEEC 002BC2EC 32310037 */  andi      $s1, $s1, 0x37
    /* BCEF0 002BC2F0 3C01A440 */  lui        $at, %hi(VI_CURRENT_REG)
    /* BCEF4 002BC2F4 AC200010 */  sw         $zero, %lo(VI_CURRENT_REG)($at)
    /* BCEF8 002BC2F8 0C0AF142 */  jal        send_mesg
    /* BCEFC 002BC2FC 24040038 */  addiu     $a0, $zero, 0x38
    /* BCF00 002BC300 1220002A */  .word 0x1220002A
    /* BCF04 002BC304 00000000 */  nop
.Lauto_002BC308:
    /* BCF08 002BC308 32290004 */  andi       $t1, $s1, 0x4
    /* BCF0C 002BC30C 11200009 */  .word 0x11200009
    /* BCF10 002BC310 00000000 */  nop
    /* BCF14 002BC314 3231003B */  andi       $s1, $s1, 0x3B
    /* BCF18 002BC318 24090001 */  addiu      $t1, $zero, 0x1
    /* BCF1C 002BC31C 3C01A450 */  lui        $at, %hi(AI_STATUS_REG)
    /* BCF20 002BC320 AC29000C */  sw         $t1, %lo(AI_STATUS_REG)($at)
    /* BCF24 002BC324 0C0AF142 */  jal        send_mesg
    /* BCF28 002BC328 24040030 */  addiu     $a0, $zero, 0x30
    /* BCF2C 002BC32C 1220001F */  .word 0x1220001F
    /* BCF30 002BC330 00000000 */  nop
.Lauto_002BC334:
    /* BCF34 002BC334 32290002 */  andi       $t1, $s1, 0x2
    /* BCF38 002BC338 11200008 */  .word 0x11200008
    /* BCF3C 002BC33C 00000000 */  nop
    /* BCF40 002BC340 3231003D */  andi       $s1, $s1, 0x3D
    /* BCF44 002BC344 3C01A480 */  lui        $at, %hi(SI_STATUS_REG)
    /* BCF48 002BC348 AC200018 */  sw         $zero, %lo(SI_STATUS_REG)($at)
    /* BCF4C 002BC34C 0C0AF142 */  jal        send_mesg
    /* BCF50 002BC350 24040028 */  addiu     $a0, $zero, 0x28
    /* BCF54 002BC354 12200015 */  .word 0x12200015
    /* BCF58 002BC358 00000000 */  nop
.Lauto_002BC35C:
    /* BCF5C 002BC35C 32290010 */  andi       $t1, $s1, 0x10
    /* BCF60 002BC360 11200009 */  .word 0x11200009
    /* BCF64 002BC364 00000000 */  nop
    /* BCF68 002BC368 3231002F */  andi       $s1, $s1, 0x2F
    /* BCF6C 002BC36C 24090002 */  addiu      $t1, $zero, 0x2
    /* BCF70 002BC370 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* BCF74 002BC374 AC290010 */  sw         $t1, %lo(PI_STATUS_REG)($at)
    /* BCF78 002BC378 0C0AF142 */  jal        send_mesg
    /* BCF7C 002BC37C 24040040 */  addiu     $a0, $zero, 0x40
    /* BCF80 002BC380 1220000A */  .word 0x1220000A
    /* BCF84 002BC384 00000000 */  nop
.Lauto_002BC388:
    /* BCF88 002BC388 32290020 */  andi       $t1, $s1, 0x20
    /* BCF8C 002BC38C 11200007 */  .word 0x11200007
    /* BCF90 002BC390 00000000 */  nop
    /* BCF94 002BC394 3231001F */  andi       $s1, $s1, 0x1F
    /* BCF98 002BC398 24090800 */  addiu      $t1, $zero, 0x800
    /* BCF9C 002BC39C 3C01A430 */  lui        $at, %hi(MI_MODE_REG)
    /* BCFA0 002BC3A0 AC290000 */  sw         $t1, %lo(MI_MODE_REG)($at)
    /* BCFA4 002BC3A4 0C0AF142 */  jal        send_mesg
    /* BCFA8 002BC3A8 24040048 */  addiu     $a0, $zero, 0x48
.Lauto_002BC3AC:
    /* BCFAC 002BC3AC 2401FBFF */  addiu      $at, $zero, -0x401
    /* BCFB0 002BC3B0 02018024 */  and        $s0, $s0, $at
    /* BCFB4 002BC3B4 0401FF75 */  .word 0x0401FF75
    /* BCFB8 002BC3B8 00000000 */  nop
    /* BCFBC 002BC3BC 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* BCFC0 002BC3C0 3C09800E */  lui        $t1, %hi(__osShutdown)
    /* BCFC4 002BC3C4 252958D4 */  addiu      $t1, $t1, %lo(__osShutdown)
    /* BCFC8 002BC3C8 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BCFCC 002BC3CC 0361D824 */  and        $k1, $k1, $at
    /* BCFD0 002BC3D0 8D2A0000 */  lw         $t2, 0x0($t1)
    /* BCFD4 002BC3D4 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BCFD8 002BC3D8 02018024 */  and        $s0, $s0, $at
    /* BCFDC 002BC3DC 11400003 */  .word 0x11400003
    /* BCFE0 002BC3E0 AF5B0118 */  sw        $k1, 0x118($k0) /* handwritten instruction */
    /* BCFE4 002BC3E4 04010027 */  .word 0x04010027
    /* BCFE8 002BC3E8 00000000 */  nop
.Lauto_002BC3EC:
    /* BCFEC 002BC3EC 240A0001 */  addiu      $t2, $zero, 0x1
    /* BCFF0 002BC3F0 AD2A0000 */  sw         $t2, 0x0($t1)
    /* BCFF4 002BC3F4 0C0AF142 */  jal        send_mesg
    /* BCFF8 002BC3F8 24040070 */  addiu     $a0, $zero, 0x70
    /* BCFFC 002BC3FC 3C0A800E */  lui        $t2, %hi(__osRunQueue)
    /* BD000 002BC400 8D4A58E8 */  lw         $t2, %lo(__osRunQueue)($t2)
    /* BD004 002BC404 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BD008 002BC408 02018024 */  and        $s0, $s0, $at
    /* BD00C 002BC40C 8D5B0118 */  lw         $k1, 0x118($t2) /* handwritten instruction */
    /* BD010 002BC410 00000000 */  nop
    /* BD014 002BC414 2401EFFF */  addiu      $at, $zero, -0x1001
    /* BD018 002BC418 0361D824 */  and        $k1, $k1, $at
    /* BD01C 002BC41C 04010019 */  .word 0x04010019
    /* BD020 002BC420 AD5B0118 */  sw        $k1, 0x118($t2) /* handwritten instruction */
    /* BD024 002BC424 2401FDFF */  addiu      $at, $zero, -0x201
    /* BD028 002BC428 01014024 */  and        $t0, $t0, $at
    /* BD02C 002BC42C 40886800 */  mtc0       $t0, $13 /* handwritten instruction */
    /* BD030 002BC430 2401FDFF */  addiu      $at, $zero, -0x201
    /* BD034 002BC434 02018024 */  and        $s0, $s0, $at
    /* BD038 002BC438 0C0AF142 */  jal        send_mesg
    /* BD03C 002BC43C 24040008 */  addiu     $a0, $zero, 0x8
    /* BD040 002BC440 0401FF52 */  .word 0x0401FF52
    /* BD044 002BC444 00000000 */  nop
    /* BD048 002BC448 2401FEFF */  addiu      $at, $zero, -0x101
    /* BD04C 002BC44C 01014024 */  and        $t0, $t0, $at
    /* BD050 002BC450 40886800 */  mtc0       $t0, $13 /* handwritten instruction */
    /* BD054 002BC454 2401FEFF */  addiu      $at, $zero, -0x101
    /* BD058 002BC458 02018024 */  and        $s0, $s0, $at
    /* BD05C 002BC45C 0C0AF142 */  jal        send_mesg
    /* BD060 002BC460 24040000 */  addiu     $a0, $zero, 0x0
    /* BD064 002BC464 0401FF49 */  .word 0x0401FF49
    /* BD068 002BC468 00000000 */  nop
.Lauto_002BC46C:
    /* BD06C 002BC46C 24090001 */  addiu      $t1, $zero, 0x1
    /* BD070 002BC470 A7490012 */  sh         $t1, 0x12($k0) /* handwritten instruction */
    /* BD074 002BC474 0C0AF142 */  jal        send_mesg
    /* BD078 002BC478 24040050 */  addiu     $a0, $zero, 0x50
    /* BD07C 002BC47C 04010001 */  .word 0x04010001
    /* BD080 002BC480 00000000 */  nop
.Lauto_002BC484:
    /* BD084 002BC484 3C0A800E */  lui        $t2, %hi(__osRunQueue)
    /* BD088 002BC488 8D4A58E8 */  lw         $t2, %lo(__osRunQueue)($t2)
    /* BD08C 002BC48C 8F490004 */  lw         $t1, 0x4($k0) /* handwritten instruction */
    /* BD090 002BC490 8D4B0004 */  lw         $t3, 0x4($t2)
    /* BD094 002BC494 00000000 */  nop
    /* BD098 002BC498 012B082A */  slt        $at, $t1, $t3
    /* BD09C 002BC49C 10200007 */  .word 0x10200007
    /* BD0A0 002BC4A0 00000000 */  nop
    /* BD0A4 002BC4A4 3C04800E */  lui        $a0, %hi(__osRunQueue)
    /* BD0A8 002BC4A8 248458E8 */  addiu      $a0, $a0, %lo(__osRunQueue)
    /* BD0AC 002BC4AC 0C0AF1EA */  jal        __osEnqueueThread
    /* BD0B0 002BC4B0 03402821 */  addu      $a1, $k0, $zero
    /* BD0B4 002BC4B4 080AF204 */  j          __osDispatchThread
    /* BD0B8 002BC4B8 00000000 */  nop
.Lauto_002BC4BC:
    /* BD0BC 002BC4BC 3C09800E */  lui        $t1, %hi(__osRunQueue)
    /* BD0C0 002BC4C0 252958E8 */  addiu      $t1, $t1, %lo(__osRunQueue)
    /* BD0C4 002BC4C4 8D2A0000 */  lw         $t2, 0x0($t1)
    /* BD0C8 002BC4C8 00000000 */  nop
    /* BD0CC 002BC4CC AF4A0000 */  sw         $t2, 0x0($k0) /* handwritten instruction */
    /* BD0D0 002BC4D0 080AF204 */  j          __osDispatchThread
    /* BD0D4 002BC4D4 AD3A0000 */  sw        $k0, 0x0($t1) /* handwritten instruction */
.Lauto_002BC4D8:
    /* BD0D8 002BC4D8 3C01800E */  lui        $at, %hi(__osFaultedThread)
    /* BD0DC 002BC4DC AC3A58F4 */  sw         $k0, %lo(__osFaultedThread)($at) /* handwritten instruction */
    /* BD0E0 002BC4E0 24090001 */  addiu      $t1, $zero, 0x1
    /* BD0E4 002BC4E4 A7490010 */  sh         $t1, 0x10($k0) /* handwritten instruction */
    /* BD0E8 002BC4E8 24090002 */  addiu      $t1, $zero, 0x2
    /* BD0EC 002BC4EC 400A4000 */  mfc0       $t2, $8 /* handwritten instruction */
    /* BD0F0 002BC4F0 A7490012 */  sh         $t1, 0x12($k0) /* handwritten instruction */
    /* BD0F4 002BC4F4 AF4A0124 */  sw         $t2, 0x124($k0) /* handwritten instruction */
    /* BD0F8 002BC4F8 0C0AF142 */  jal        send_mesg
    /* BD0FC 002BC4FC 24040060 */  addiu     $a0, $zero, 0x60
    /* BD100 002BC500 080AF204 */  j          __osDispatchThread
    /* BD104 002BC504 00000000 */  nop
.globl send_mesg
send_mesg:
    /* BD108 002BC508 03E09021 */  addu       $s2, $ra, $zero
    /* BD10C 002BC50C 3C0A8016 */  lui        $t2, %hi(__osEventStateTab)
    /* BD110 002BC510 254A9B10 */  addiu      $t2, $t2, %lo(__osEventStateTab)
    /* BD114 002BC514 01445021 */  addu       $t2, $t2, $a0
    /* BD118 002BC518 8D490000 */  lw         $t1, 0x0($t2)
    /* BD11C 002BC51C 00000000 */  nop
    /* BD120 002BC520 1120002A */  .word 0x1120002A
    /* BD124 002BC524 00000000 */  nop
    /* BD128 002BC528 8D2B0008 */  lw         $t3, 0x8($t1)
    /* BD12C 002BC52C 8D2C0010 */  lw         $t4, 0x10($t1)
    /* BD130 002BC530 00000000 */  nop
    /* BD134 002BC534 016C082A */  slt        $at, $t3, $t4
    /* BD138 002BC538 10200024 */  .word 0x10200024
    /* BD13C 002BC53C 00000000 */  nop
    /* BD140 002BC540 8D2D000C */  lw         $t5, 0xC($t1)
    /* BD144 002BC544 00000000 */  nop
    /* BD148 002BC548 01AB6821 */  addu       $t5, $t5, $t3
    /* BD14C 002BC54C 01AC001A */  div        $zero, $t5, $t4
    /* BD150 002BC550 15800002 */  .word 0x15800002
    /* BD154 002BC554 00000000 */  nop
    /* BD158 002BC558 0007000D */  break      7
.Lauto_002BC55C:
    /* BD15C 002BC55C 2401FFFF */  addiu      $at, $zero, -0x1
    /* BD160 002BC560 15810004 */  .word 0x15810004
    /* BD164 002BC564 3C018000 */  lui       $at, (0x80000000 >> 16)
    /* BD168 002BC568 15A10002 */  .word 0x15A10002
    /* BD16C 002BC56C 00000000 */  nop
    /* BD170 002BC570 0006000D */  break      6
.Lauto_002BC574:
    /* BD174 002BC574 00006810 */  mfhi       $t5
    /* BD178 002BC578 8D2C0014 */  lw         $t4, 0x14($t1)
    /* BD17C 002BC57C 000D6880 */  sll        $t5, $t5, 2
    /* BD180 002BC580 018D6021 */  addu       $t4, $t4, $t5
    /* BD184 002BC584 8D4D0004 */  lw         $t5, 0x4($t2)
    /* BD188 002BC588 00000000 */  nop
    /* BD18C 002BC58C AD8D0000 */  sw         $t5, 0x0($t4)
    /* BD190 002BC590 256A0001 */  addiu      $t2, $t3, 0x1
    /* BD194 002BC594 AD2A0008 */  sw         $t2, 0x8($t1)
    /* BD198 002BC598 8D2A0000 */  lw         $t2, 0x0($t1)
    /* BD19C 002BC59C 00000000 */  nop
    /* BD1A0 002BC5A0 8D4B0000 */  lw         $t3, 0x0($t2)
    /* BD1A4 002BC5A4 00000000 */  nop
    /* BD1A8 002BC5A8 11600008 */  .word 0x11600008
    /* BD1AC 002BC5AC 00000000 */  nop
    /* BD1B0 002BC5B0 0C0AF1FE */  jal        __osPopThread
    /* BD1B4 002BC5B4 01202021 */  addu      $a0, $t1, $zero
    /* BD1B8 002BC5B8 00405021 */  addu       $t2, $v0, $zero
    /* BD1BC 002BC5BC 3C04800E */  lui        $a0, %hi(__osRunQueue)
    /* BD1C0 002BC5C0 248458E8 */  addiu      $a0, $a0, %lo(__osRunQueue)
    /* BD1C4 002BC5C4 0C0AF1EA */  jal        __osEnqueueThread
    /* BD1C8 002BC5C8 01402821 */  addu      $a1, $t2, $zero
.Lauto_002BC5CC:
    /* BD1CC 002BC5CC 02400008 */  jr         $s2
    /* BD1D0 002BC5D0 00000000 */  nop
.Lauto_002BC5D4:
    /* BD1D4 002BC5D4 3C013000 */  lui        $at, (0x30000000 >> 16)
    /* BD1D8 002BC5D8 01014824 */  and        $t1, $t0, $at
    /* BD1DC 002BC5DC 00094F02 */  srl        $t1, $t1, 28
    /* BD1E0 002BC5E0 240A0001 */  addiu      $t2, $zero, 0x1
    /* BD1E4 002BC5E4 152AFFBC */  .word 0x152AFFBC
    /* BD1E8 002BC5E8 24090001 */  addiu     $t1, $zero, 0x1
    /* BD1EC 002BC5EC AF490018 */  sw         $t1, 0x18($k0) /* handwritten instruction */
    /* BD1F0 002BC5F0 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* BD1F4 002BC5F4 00000000 */  nop
    /* BD1F8 002BC5F8 3C012000 */  lui        $at, (0x20000000 >> 16)
    /* BD1FC 002BC5FC 0361D825 */  or         $k1, $k1, $at
    /* BD200 002BC600 AF5B0118 */  sw         $k1, 0x118($k0) /* handwritten instruction */
    /* BD204 002BC604 0401FFAD */  .word 0x0401FFAD
    /* BD208 002BC608 00000000 */  nop
