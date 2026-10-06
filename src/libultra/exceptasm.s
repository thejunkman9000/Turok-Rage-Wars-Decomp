.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC1960-0xC205C (VRAM 0x002C0D60) */
glabel __osExceptionPreamble
    /* C1960 002C0D60 3C1A002C */  lui        $k0, %hi(__osException) /* handwritten instruction */
    /* C1964 002C0D64 275A0D70 */  addiu      $k0, $k0, %lo(__osException) /* handwritten instruction */
    /* C1968 002C0D68 03400008 */  jr         $k0
    /* C196C 002C0D6C 00000000 */   nop


glabel __osException
    /* C1970 002C0D70 3C1A8015 */  lui        $k0, %hi(__osThreadSave) /* handwritten instruction */
    /* C1974 002C0D74 275A0E60 */  addiu      $k0, $k0, %lo(__osThreadSave) /* handwritten instruction */
    /* C1978 002C0D78 FF410020 */  sd         $at, 0x20($k0) /* handwritten instruction */
    /* C197C 002C0D7C 401B6000 */  mfc0       $k1, $12 /* handwritten instruction */
    /* C1980 002C0D80 00000000 */  nop
    /* C1984 002C0D84 AF5B0118 */  sw         $k1, 0x118($k0) /* handwritten instruction */
    /* C1988 002C0D88 2401FFFC */  addiu      $at, $zero, -0x4
    /* C198C 002C0D8C 0361D824 */  and        $k1, $k1, $at
    /* C1990 002C0D90 409B6000 */  mtc0       $k1, $12 /* handwritten instruction */
    /* C1994 002C0D94 FF480058 */  sd         $t0, 0x58($k0) /* handwritten instruction */
    /* C1998 002C0D98 FF490060 */  sd         $t1, 0x60($k0) /* handwritten instruction */
    /* C199C 002C0D9C FF4A0068 */  sd         $t2, 0x68($k0) /* handwritten instruction */
    /* C19A0 002C0DA0 AF400018 */  sw         $zero, 0x18($k0) /* handwritten instruction */
    /* C19A4 002C0DA4 40086800 */  mfc0       $t0, $13 /* handwritten instruction */
    /* C19A8 002C0DA8 03404021 */  addu       $t0, $k0, $zero
    /* C19AC 002C0DAC 3C1A800E */  lui        $k0, %hi(__osRunningThread) /* handwritten instruction */
    /* C19B0 002C0DB0 8F5A92A0 */  lw         $k0, %lo(__osRunningThread)($k0) /* handwritten instruction */
    /* C19B4 002C0DB4 DD090020 */  ld         $t1, 0x20($t0)
    /* C19B8 002C0DB8 DD0A0118 */  ld         $t2, 0x118($t0)
    /* C19BC 002C0DBC FF490020 */  sd         $t1, 0x20($k0) /* handwritten instruction */
    /* C19C0 002C0DC0 FF4A0118 */  sd         $t2, 0x118($k0) /* handwritten instruction */
    /* C19C4 002C0DC4 DD090058 */  ld         $t1, 0x58($t0)
    /* C19C8 002C0DC8 DD0A0060 */  ld         $t2, 0x60($t0)
    /* C19CC 002C0DCC FF490058 */  sd         $t1, 0x58($k0) /* handwritten instruction */
    /* C19D0 002C0DD0 FF4A0060 */  sd         $t2, 0x60($k0) /* handwritten instruction */
    /* C19D4 002C0DD4 DD090068 */  ld         $t1, 0x68($t0)
    /* C19D8 002C0DD8 FF420028 */  sd         $v0, 0x28($k0) /* handwritten instruction */
    /* C19DC 002C0DDC FF490068 */  sd         $t1, 0x68($k0) /* handwritten instruction */
    /* C19E0 002C0DE0 FF430030 */  sd         $v1, 0x30($k0) /* handwritten instruction */
    /* C19E4 002C0DE4 FF440038 */  sd         $a0, 0x38($k0) /* handwritten instruction */
    /* C19E8 002C0DE8 FF450040 */  sd         $a1, 0x40($k0) /* handwritten instruction */
    /* C19EC 002C0DEC FF460048 */  sd         $a2, 0x48($k0) /* handwritten instruction */
    /* C19F0 002C0DF0 FF470050 */  sd         $a3, 0x50($k0) /* handwritten instruction */
    /* C19F4 002C0DF4 FF4B0070 */  sd         $t3, 0x70($k0) /* handwritten instruction */
    /* C19F8 002C0DF8 FF4C0078 */  sd         $t4, 0x78($k0) /* handwritten instruction */
    /* C19FC 002C0DFC FF4D0080 */  sd         $t5, 0x80($k0) /* handwritten instruction */
    /* C1A00 002C0E00 FF4E0088 */  sd         $t6, 0x88($k0) /* handwritten instruction */
    /* C1A04 002C0E04 FF4F0090 */  sd         $t7, 0x90($k0) /* handwritten instruction */
    /* C1A08 002C0E08 FF500098 */  sd         $s0, 0x98($k0) /* handwritten instruction */
    /* C1A0C 002C0E0C FF5100A0 */  sd         $s1, 0xA0($k0) /* handwritten instruction */
    /* C1A10 002C0E10 FF5200A8 */  sd         $s2, 0xA8($k0) /* handwritten instruction */
    /* C1A14 002C0E14 FF5300B0 */  sd         $s3, 0xB0($k0) /* handwritten instruction */
    /* C1A18 002C0E18 FF5400B8 */  sd         $s4, 0xB8($k0) /* handwritten instruction */
    /* C1A1C 002C0E1C FF5500C0 */  sd         $s5, 0xC0($k0) /* handwritten instruction */
    /* C1A20 002C0E20 FF5600C8 */  sd         $s6, 0xC8($k0) /* handwritten instruction */
    /* C1A24 002C0E24 FF5700D0 */  sd         $s7, 0xD0($k0) /* handwritten instruction */
    /* C1A28 002C0E28 FF5800D8 */  sd         $t8, 0xD8($k0) /* handwritten instruction */
    /* C1A2C 002C0E2C FF5900E0 */  sd         $t9, 0xE0($k0) /* handwritten instruction */
    /* C1A30 002C0E30 FF5C00E8 */  sd         $gp, 0xE8($k0) /* handwritten instruction */
    /* C1A34 002C0E34 FF5D00F0 */  sd         $sp, 0xF0($k0) /* handwritten instruction */
    /* C1A38 002C0E38 FF5E00F8 */  sd         $fp, 0xF8($k0) /* handwritten instruction */
    /* C1A3C 002C0E3C FF5F0100 */  sd         $ra, 0x100($k0) /* handwritten instruction */
    /* C1A40 002C0E40 00004012 */  mflo       $t0
    /* C1A44 002C0E44 FF480108 */  sd         $t0, 0x108($k0) /* handwritten instruction */
    /* C1A48 002C0E48 00004010 */  mfhi       $t0
    /* C1A4C 002C0E4C FF480110 */  sd         $t0, 0x110($k0) /* handwritten instruction */
    /* C1A50 002C0E50 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* C1A54 002C0E54 00000000 */  nop
    /* C1A58 002C0E58 3369FF00 */  andi       $t1, $k1, 0xFF00 /* handwritten instruction */
    /* C1A5C 002C0E5C 11200014 */  beqz       $t1, .L002C0EB0
    /* C1A60 002C0E60 00000000 */   nop
    /* C1A64 002C0E64 3C08800E */  lui        $t0, %hi(__OSGlobalIntMask)
    /* C1A68 002C0E68 25089288 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* C1A6C 002C0E6C 8D080000 */  lw         $t0, 0x0($t0)
    /* C1A70 002C0E70 00000000 */  nop
    /* C1A74 002C0E74 2401FFFF */  addiu      $at, $zero, -0x1
    /* C1A78 002C0E78 01015026 */  xor        $t2, $t0, $at
    /* C1A7C 002C0E7C 314AFF00 */  andi       $t2, $t2, 0xFF00
    /* C1A80 002C0E80 012A6025 */  or         $t4, $t1, $t2
    /* C1A84 002C0E84 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* C1A88 002C0E88 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* C1A8C 002C0E8C 03615824 */  and        $t3, $k1, $at
    /* C1A90 002C0E90 016C5825 */  or         $t3, $t3, $t4
    /* C1A94 002C0E94 AF4B0118 */  sw         $t3, 0x118($k0) /* handwritten instruction */
    /* C1A98 002C0E98 3108FF00 */  andi       $t0, $t0, 0xFF00
    /* C1A9C 002C0E9C 01284824 */  and        $t1, $t1, $t0
    /* C1AA0 002C0EA0 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* C1AA4 002C0EA4 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* C1AA8 002C0EA8 0361D824 */  and        $k1, $k1, $at
    /* C1AAC 002C0EAC 0369D825 */  or         $k1, $k1, $t1
  .L002C0EB0:
    /* C1AB0 002C0EB0 3C09A430 */  lui        $t1, %hi(MI_INTR_MASK_REG)
    /* C1AB4 002C0EB4 8D29000C */  lw         $t1, %lo(MI_INTR_MASK_REG)($t1)
    /* C1AB8 002C0EB8 00000000 */  nop
    /* C1ABC 002C0EBC 1120000C */  beqz       $t1, .L002C0EF0
    /* C1AC0 002C0EC0 00000000 */   nop
    /* C1AC4 002C0EC4 3C08800E */  lui        $t0, %hi(__OSGlobalIntMask)
    /* C1AC8 002C0EC8 25089288 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* C1ACC 002C0ECC 8D080000 */  lw         $t0, 0x0($t0)
    /* C1AD0 002C0ED0 00000000 */  nop
    /* C1AD4 002C0ED4 00084402 */  srl        $t0, $t0, 16
    /* C1AD8 002C0ED8 2401FFFF */  addiu      $at, $zero, -0x1
    /* C1ADC 002C0EDC 01014026 */  xor        $t0, $t0, $at
    /* C1AE0 002C0EE0 8F4C0128 */  lw         $t4, 0x128($k0) /* handwritten instruction */
    /* C1AE4 002C0EE4 3108003F */  andi       $t0, $t0, 0x3F
    /* C1AE8 002C0EE8 010C4024 */  and        $t0, $t0, $t4
    /* C1AEC 002C0EEC 01284825 */  or         $t1, $t1, $t0
  .L002C0EF0:
    /* C1AF0 002C0EF0 40087000 */  mfc0       $t0, $14 /* handwritten instruction */
    /* C1AF4 002C0EF4 AF490128 */  sw         $t1, 0x128($k0) /* handwritten instruction */
    /* C1AF8 002C0EF8 AF48011C */  sw         $t0, 0x11C($k0) /* handwritten instruction */
    /* C1AFC 002C0EFC 8F480018 */  lw         $t0, 0x18($k0) /* handwritten instruction */
    /* C1B00 002C0F00 00000000 */  nop
    /* C1B04 002C0F04 11000029 */  beqz       $t0, .L002C0FAC
    /* C1B08 002C0F08 00000000 */   nop
    /* C1B0C 002C0F0C 4448F800 */  cfc1       $t0, $31
    /* C1B10 002C0F10 00000000 */  nop
    /* C1B14 002C0F14 AF48012C */  sw         $t0, 0x12C($k0) /* handwritten instruction */
    /* C1B18 002C0F18 F7400130 */  sdc1       $fv0, 0x130($k0)
    /* C1B1C 002C0F1C F7420138 */  sdc1       $fv1, 0x138($k0)
    /* C1B20 002C0F20 F7440140 */  sdc1       $ft0, 0x140($k0)
    /* C1B24 002C0F24 F7460148 */  sdc1       $ft1, 0x148($k0)
    /* C1B28 002C0F28 F7480150 */  sdc1       $ft2, 0x150($k0)
    /* C1B2C 002C0F2C F74A0158 */  sdc1       $ft3, 0x158($k0)
    /* C1B30 002C0F30 F74C0160 */  sdc1       $fa0, 0x160($k0)
    /* C1B34 002C0F34 F74E0168 */  sdc1       $fa1, 0x168($k0)
    /* C1B38 002C0F38 F7500170 */  sdc1       $ft4, 0x170($k0)
    /* C1B3C 002C0F3C F7520178 */  sdc1       $ft5, 0x178($k0)
    /* C1B40 002C0F40 F7540180 */  sdc1       $fs0, 0x180($k0)
    /* C1B44 002C0F44 F7560188 */  sdc1       $fs1, 0x188($k0)
    /* C1B48 002C0F48 F7580190 */  sdc1       $fs2, 0x190($k0)
    /* C1B4C 002C0F4C F75A0198 */  sdc1       $fs3, 0x198($k0)
    /* C1B50 002C0F50 F75C01A0 */  sdc1       $fs4, 0x1A0($k0)
    /* C1B54 002C0F54 8F490118 */  lw         $t1, 0x118($k0) /* handwritten instruction */
    /* C1B58 002C0F58 F75E01A8 */  sdc1       $fs5, 0x1A8($k0)
    /* C1B5C 002C0F5C 3C010400 */  lui        $at, (0x4000000 >> 16)
    /* C1B60 002C0F60 01214824 */  and        $t1, $t1, $at
    /* C1B64 002C0F64 11200011 */  beqz       $t1, .L002C0FAC
    /* C1B68 002C0F68 00000000 */   nop
    /* C1B6C 002C0F6C F74101B0 */  sdc1       $fv0f, 0x1B0($k0)
    /* C1B70 002C0F70 F74301B8 */  sdc1       $fv1f, 0x1B8($k0)
    /* C1B74 002C0F74 F74501C0 */  sdc1       $ft0f, 0x1C0($k0)
    /* C1B78 002C0F78 F74701C8 */  sdc1       $ft1f, 0x1C8($k0)
    /* C1B7C 002C0F7C F74901D0 */  sdc1       $ft2f, 0x1D0($k0)
    /* C1B80 002C0F80 F74B01D8 */  sdc1       $ft3f, 0x1D8($k0)
    /* C1B84 002C0F84 F74D01E0 */  sdc1       $fa0f, 0x1E0($k0)
    /* C1B88 002C0F88 F74F01E8 */  sdc1       $fa1f, 0x1E8($k0)
    /* C1B8C 002C0F8C F75101F0 */  sdc1       $ft4f, 0x1F0($k0)
    /* C1B90 002C0F90 F75301F8 */  sdc1       $ft5f, 0x1F8($k0)
    /* C1B94 002C0F94 F7550200 */  sdc1       $fs0f, 0x200($k0)
    /* C1B98 002C0F98 F7570208 */  sdc1       $fs1f, 0x208($k0)
    /* C1B9C 002C0F9C F7590210 */  sdc1       $fs2f, 0x210($k0)
    /* C1BA0 002C0FA0 F75B0218 */  sdc1       $fs3f, 0x218($k0)
    /* C1BA4 002C0FA4 F75D0220 */  sdc1       $fs4f, 0x220($k0)
    /* C1BA8 002C0FA8 F75F0228 */  sdc1       $fs5f, 0x228($k0)
  .L002C0FAC:
    /* C1BAC 002C0FAC 40086800 */  mfc0       $t0, $13 /* handwritten instruction */
    /* C1BB0 002C0FB0 24090002 */  addiu      $t1, $zero, 0x2
    /* C1BB4 002C0FB4 AF480120 */  sw         $t0, 0x120($k0) /* handwritten instruction */
    /* C1BB8 002C0FB8 A7490010 */  sh         $t1, 0x10($k0) /* handwritten instruction */
    /* C1BBC 002C0FBC 3109007C */  andi       $t1, $t0, 0x7C
    /* C1BC0 002C0FC0 240A0024 */  addiu      $t2, $zero, 0x24
    /* C1BC4 002C0FC4 112A00BD */  beq        $t1, $t2, .L002C12BC
    /* C1BC8 002C0FC8 240A002C */   addiu     $t2, $zero, 0x2C
    /* C1BCC 002C0FCC 112A0115 */  beq        $t1, $t2, .L002C1424
    /* C1BD0 002C0FD0 240A0000 */   addiu     $t2, $zero, 0x0
    /* C1BD4 002C0FD4 152A00D4 */  bne        $t1, $t2, .L002C1328
    /* C1BD8 002C0FD8 03688024 */   and       $s0, $k1, $t0
  .L002C0FDC:
    /* C1BDC 002C0FDC 3209FF00 */  andi       $t1, $s0, 0xFF00
    /* C1BE0 002C0FE0 00095302 */  srl        $t2, $t1, 12
    /* C1BE4 002C0FE4 15400003 */  bnez       $t2, .L002C0FF4
    /* C1BE8 002C0FE8 00000000 */   nop
    /* C1BEC 002C0FEC 00095202 */  srl        $t2, $t1, 8
    /* C1BF0 002C0FF0 214A0010 */  addi       $t2, $t2, 0x10 /* handwritten instruction */
  .L002C0FF4:
    /* C1BF4 002C0FF4 3C01800D */  lui        $at, %hi(__osIntOffTable)
    /* C1BF8 002C0FF8 002A0821 */  addu       $at, $at, $t2
    /* C1BFC 002C0FFC 902ACC70 */  lbu        $t2, %lo(__osIntOffTable)($at)
    /* C1C00 002C1000 3C01800D */  lui        $at, %hi(jtbl_800CCC90)
    /* C1C04 002C1004 002A0821 */  addu       $at, $at, $t2
    /* C1C08 002C1008 8C2ACC90 */  lw         $t2, %lo(jtbl_800CCC90)($at)
    /* C1C0C 002C100C 00000000 */  nop
    /* C1C10 002C1010 01400008 */  jr         $t2
    /* C1C14 002C1014 00000000 */   nop
    /* C1C18 002C1018 2401DFFF */  addiu      $at, $zero, -0x2001
    /* C1C1C 002C101C 02018024 */  and        $s0, $s0, $at
    /* C1C20 002C1020 0401FFEE */  bgez       $zero, .L002C0FDC
    /* C1C24 002C1024 00000000 */   nop
    /* C1C28 002C1028 2401BFFF */  addiu      $at, $zero, -0x4001
    /* C1C2C 002C102C 02018024 */  and        $s0, $s0, $at
    /* C1C30 002C1030 0401FFEA */  bgez       $zero, .L002C0FDC
    /* C1C34 002C1034 00000000 */   nop
    /* C1C38 002C1038 40095800 */  mfc0       $t1, $11 /* handwritten instruction */
    /* C1C3C 002C103C 3C01FFFF */  lui        $at, (0xFFFF7FFF >> 16)
    /* C1C40 002C1040 34217FFF */  ori        $at, $at, (0xFFFF7FFF & 0xFFFF)
    /* C1C44 002C1044 02018024 */  and        $s0, $s0, $at
    /* C1C48 002C1048 40895800 */  mtc0       $t1, $11 /* handwritten instruction */
    /* C1C4C 002C104C 0C0B04D6 */  jal        send_mesg
    /* C1C50 002C1050 24040018 */   addiu     $a0, $zero, 0x18
    /* C1C54 002C1054 0401FFE1 */  bgez       $zero, .L002C0FDC
    /* C1C58 002C1058 00000000 */   nop
    /* C1C5C 002C105C 24040010 */  addiu      $a0, $zero, 0x10
    /* C1C60 002C1060 2401F7FF */  addiu      $at, $zero, -0x801
    /* C1C64 002C1064 02018024 */  and        $s0, $s0, $at
    /* C1C68 002C1068 3C1D8015 */  lui        $sp, %hi(__osHwIntStack)
    /* C1C6C 002C106C 27BDFE60 */  addiu      $sp, $sp, %lo(__osHwIntStack)
    /* C1C70 002C1070 27BD0FF0 */  addiu      $sp, $sp, 0xFF0
    /* C1C74 002C1074 240A0004 */  addiu      $t2, $zero, 0x4
    /* C1C78 002C1078 3C01800E */  lui        $at, %hi(__osHwIntTable)
    /* C1C7C 002C107C 002A0821 */  addu       $at, $at, $t2
    /* C1C80 002C1080 8C2A92C0 */  lw         $t2, %lo(__osHwIntTable)($at)
    /* C1C84 002C1084 00000000 */  nop
    /* C1C88 002C1088 11400007 */  beqz       $t2, .L002C10A8
    /* C1C8C 002C108C 00000000 */   nop
    /* C1C90 002C1090 0140F809 */  jalr       $t2
    /* C1C94 002C1094 24040010 */   addiu     $a0, $zero, 0x10
    /* C1C98 002C1098 10400003 */  beqz       $v0, .L002C10A8
    /* C1C9C 002C109C 00000000 */   nop
    /* C1CA0 002C10A0 0401008C */  bgez       $zero, .L002C12D4
    /* C1CA4 002C10A4 00000000 */   nop
  .L002C10A8:
    /* C1CA8 002C10A8 0C0B04D6 */  jal        send_mesg
    /* C1CAC 002C10AC 00000000 */   nop
    /* C1CB0 002C10B0 0401FFCA */  bgez       $zero, .L002C0FDC
    /* C1CB4 002C10B4 00000000 */   nop
    /* C1CB8 002C10B8 3C11A430 */  lui        $s1, %hi(MI_INTR_REG)
    /* C1CBC 002C10BC 8E310008 */  lw         $s1, %lo(MI_INTR_REG)($s1)
    /* C1CC0 002C10C0 3C08800E */  lui        $t0, %hi(__OSGlobalIntMask)
    /* C1CC4 002C10C4 25089288 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* C1CC8 002C10C8 8D080000 */  lw         $t0, 0x0($t0)
    /* C1CCC 002C10CC 00000000 */  nop
    /* C1CD0 002C10D0 00084402 */  srl        $t0, $t0, 16
    /* C1CD4 002C10D4 02288824 */  and        $s1, $s1, $t0
    /* C1CD8 002C10D8 32290001 */  andi       $t1, $s1, 0x1
    /* C1CDC 002C10DC 11200014 */  beqz       $t1, .L002C1130
    /* C1CE0 002C10E0 00000000 */   nop
    /* C1CE4 002C10E4 3231003E */  andi       $s1, $s1, 0x3E
    /* C1CE8 002C10E8 3C0CA404 */  lui        $t4, %hi(SP_STATUS_REG)
    /* C1CEC 002C10EC 8D8C0010 */  lw         $t4, %lo(SP_STATUS_REG)($t4)
    /* C1CF0 002C10F0 34098008 */  ori        $t1, $zero, 0x8008
    /* C1CF4 002C10F4 3C01A404 */  lui        $at, %hi(SP_STATUS_REG)
    /* C1CF8 002C10F8 AC290010 */  sw         $t1, %lo(SP_STATUS_REG)($at)
    /* C1CFC 002C10FC 318C0300 */  andi       $t4, $t4, 0x300
    /* C1D00 002C1100 11800007 */  beqz       $t4, .L002C1120
    /* C1D04 002C1104 00000000 */   nop
    /* C1D08 002C1108 0C0B04D6 */  jal        send_mesg
    /* C1D0C 002C110C 24040020 */   addiu     $a0, $zero, 0x20
    /* C1D10 002C1110 1220003A */  beqz       $s1, .L002C11FC
    /* C1D14 002C1114 00000000 */   nop
    /* C1D18 002C1118 04010005 */  bgez       $zero, .L002C1130
    /* C1D1C 002C111C 00000000 */   nop
  .L002C1120:
    /* C1D20 002C1120 0C0B04D6 */  jal        send_mesg
    /* C1D24 002C1124 24040058 */   addiu     $a0, $zero, 0x58
    /* C1D28 002C1128 12200034 */  beqz       $s1, .L002C11FC
    /* C1D2C 002C112C 00000000 */   nop
  .L002C1130:
    /* C1D30 002C1130 32290008 */  andi       $t1, $s1, 0x8
    /* C1D34 002C1134 00000000 */  nop
    /* C1D38 002C1138 11200007 */  beqz       $t1, .L002C1158
    /* C1D3C 002C113C 32310037 */   andi      $s1, $s1, 0x37
    /* C1D40 002C1140 3C01A440 */  lui        $at, %hi(VI_CURRENT_REG)
    /* C1D44 002C1144 AC200010 */  sw         $zero, %lo(VI_CURRENT_REG)($at)
    /* C1D48 002C1148 0C0B04D6 */  jal        send_mesg
    /* C1D4C 002C114C 24040038 */   addiu     $a0, $zero, 0x38
    /* C1D50 002C1150 1220002A */  beqz       $s1, .L002C11FC
    /* C1D54 002C1154 00000000 */   nop
  .L002C1158:
    /* C1D58 002C1158 32290004 */  andi       $t1, $s1, 0x4
    /* C1D5C 002C115C 11200009 */  beqz       $t1, .L002C1184
    /* C1D60 002C1160 00000000 */   nop
    /* C1D64 002C1164 3231003B */  andi       $s1, $s1, 0x3B
    /* C1D68 002C1168 24090001 */  addiu      $t1, $zero, 0x1
    /* C1D6C 002C116C 3C01A450 */  lui        $at, %hi(AI_STATUS_REG)
    /* C1D70 002C1170 AC29000C */  sw         $t1, %lo(AI_STATUS_REG)($at)
    /* C1D74 002C1174 0C0B04D6 */  jal        send_mesg
    /* C1D78 002C1178 24040030 */   addiu     $a0, $zero, 0x30
    /* C1D7C 002C117C 1220001F */  beqz       $s1, .L002C11FC
    /* C1D80 002C1180 00000000 */   nop
  .L002C1184:
    /* C1D84 002C1184 32290002 */  andi       $t1, $s1, 0x2
    /* C1D88 002C1188 11200008 */  beqz       $t1, .L002C11AC
    /* C1D8C 002C118C 00000000 */   nop
    /* C1D90 002C1190 3231003D */  andi       $s1, $s1, 0x3D
    /* C1D94 002C1194 3C01A480 */  lui        $at, %hi(SI_STATUS_REG)
    /* C1D98 002C1198 AC200018 */  sw         $zero, %lo(SI_STATUS_REG)($at)
    /* C1D9C 002C119C 0C0B04D6 */  jal        send_mesg
    /* C1DA0 002C11A0 24040028 */   addiu     $a0, $zero, 0x28
    /* C1DA4 002C11A4 12200015 */  beqz       $s1, .L002C11FC
    /* C1DA8 002C11A8 00000000 */   nop
  .L002C11AC:
    /* C1DAC 002C11AC 32290010 */  andi       $t1, $s1, 0x10
    /* C1DB0 002C11B0 11200009 */  beqz       $t1, .L002C11D8
    /* C1DB4 002C11B4 00000000 */   nop
    /* C1DB8 002C11B8 3231002F */  andi       $s1, $s1, 0x2F
    /* C1DBC 002C11BC 24090002 */  addiu      $t1, $zero, 0x2
    /* C1DC0 002C11C0 3C01A460 */  lui        $at, %hi(PI_STATUS_REG)
    /* C1DC4 002C11C4 AC290010 */  sw         $t1, %lo(PI_STATUS_REG)($at)
    /* C1DC8 002C11C8 0C0B04D6 */  jal        send_mesg
    /* C1DCC 002C11CC 24040040 */   addiu     $a0, $zero, 0x40
    /* C1DD0 002C11D0 1220000A */  beqz       $s1, .L002C11FC
    /* C1DD4 002C11D4 00000000 */   nop
  .L002C11D8:
    /* C1DD8 002C11D8 32290020 */  andi       $t1, $s1, 0x20
    /* C1DDC 002C11DC 11200007 */  beqz       $t1, .L002C11FC
    /* C1DE0 002C11E0 00000000 */   nop
    /* C1DE4 002C11E4 3231001F */  andi       $s1, $s1, 0x1F
    /* C1DE8 002C11E8 24090800 */  addiu      $t1, $zero, 0x800
    /* C1DEC 002C11EC 3C01A430 */  lui        $at, %hi(MI_MODE_REG)
    /* C1DF0 002C11F0 AC290000 */  sw         $t1, %lo(MI_MODE_REG)($at)
    /* C1DF4 002C11F4 0C0B04D6 */  jal        send_mesg
    /* C1DF8 002C11F8 24040048 */   addiu     $a0, $zero, 0x48
  .L002C11FC:
    /* C1DFC 002C11FC 2401FBFF */  addiu      $at, $zero, -0x401
    /* C1E00 002C1200 02018024 */  and        $s0, $s0, $at
    /* C1E04 002C1204 0401FF75 */  bgez       $zero, .L002C0FDC
    /* C1E08 002C1208 00000000 */   nop
    /* C1E0C 002C120C 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* C1E10 002C1210 3C09800E */  lui        $t1, %hi(__osShutdown)
    /* C1E14 002C1214 25299284 */  addiu      $t1, $t1, %lo(__osShutdown)
    /* C1E18 002C1218 2401EFFF */  addiu      $at, $zero, -0x1001
    /* C1E1C 002C121C 0361D824 */  and        $k1, $k1, $at
    /* C1E20 002C1220 8D2A0000 */  lw         $t2, 0x0($t1)
    /* C1E24 002C1224 2401EFFF */  addiu      $at, $zero, -0x1001
    /* C1E28 002C1228 02018024 */  and        $s0, $s0, $at
    /* C1E2C 002C122C 11400003 */  beqz       $t2, .L002C123C
    /* C1E30 002C1230 AF5B0118 */   sw        $k1, 0x118($k0) /* handwritten instruction */
    /* C1E34 002C1234 04010027 */  bgez       $zero, .L002C12D4
    /* C1E38 002C1238 00000000 */   nop
  .L002C123C:
    /* C1E3C 002C123C 240A0001 */  addiu      $t2, $zero, 0x1
    /* C1E40 002C1240 AD2A0000 */  sw         $t2, 0x0($t1)
    /* C1E44 002C1244 0C0B04D6 */  jal        send_mesg
    /* C1E48 002C1248 24040070 */   addiu     $a0, $zero, 0x70
    /* C1E4C 002C124C 3C0A800E */  lui        $t2, %hi(__osRunQueue)
    /* C1E50 002C1250 8D4A9298 */  lw         $t2, %lo(__osRunQueue)($t2)
    /* C1E54 002C1254 2401EFFF */  addiu      $at, $zero, -0x1001
    /* C1E58 002C1258 02018024 */  and        $s0, $s0, $at
    /* C1E5C 002C125C 8D5B0118 */  lw         $k1, 0x118($t2) /* handwritten instruction */
    /* C1E60 002C1260 00000000 */  nop
    /* C1E64 002C1264 2401EFFF */  addiu      $at, $zero, -0x1001
    /* C1E68 002C1268 0361D824 */  and        $k1, $k1, $at
    /* C1E6C 002C126C 04010019 */  bgez       $zero, .L002C12D4
    /* C1E70 002C1270 AD5B0118 */   sw        $k1, 0x118($t2) /* handwritten instruction */
    /* C1E74 002C1274 2401FDFF */  addiu      $at, $zero, -0x201
    /* C1E78 002C1278 01014024 */  and        $t0, $t0, $at
    /* C1E7C 002C127C 40886800 */  mtc0       $t0, $13 /* handwritten instruction */
    /* C1E80 002C1280 2401FDFF */  addiu      $at, $zero, -0x201
    /* C1E84 002C1284 02018024 */  and        $s0, $s0, $at
    /* C1E88 002C1288 0C0B04D6 */  jal        send_mesg
    /* C1E8C 002C128C 24040008 */   addiu     $a0, $zero, 0x8
    /* C1E90 002C1290 0401FF52 */  bgez       $zero, .L002C0FDC
    /* C1E94 002C1294 00000000 */   nop
    /* C1E98 002C1298 2401FEFF */  addiu      $at, $zero, -0x101
    /* C1E9C 002C129C 01014024 */  and        $t0, $t0, $at
    /* C1EA0 002C12A0 40886800 */  mtc0       $t0, $13 /* handwritten instruction */
    /* C1EA4 002C12A4 2401FEFF */  addiu      $at, $zero, -0x101
    /* C1EA8 002C12A8 02018024 */  and        $s0, $s0, $at
    /* C1EAC 002C12AC 0C0B04D6 */  jal        send_mesg
    /* C1EB0 002C12B0 24040000 */   addiu     $a0, $zero, 0x0
    /* C1EB4 002C12B4 0401FF49 */  bgez       $zero, .L002C0FDC
    /* C1EB8 002C12B8 00000000 */   nop
  .L002C12BC:
    /* C1EBC 002C12BC 24090001 */  addiu      $t1, $zero, 0x1
    /* C1EC0 002C12C0 A7490012 */  sh         $t1, 0x12($k0) /* handwritten instruction */
    /* C1EC4 002C12C4 0C0B04D6 */  jal        send_mesg
    /* C1EC8 002C12C8 24040050 */   addiu     $a0, $zero, 0x50
    /* C1ECC 002C12CC 04010001 */  bgez       $zero, .L002C12D4
    /* C1ED0 002C12D0 00000000 */   nop
  .L002C12D4:
    /* C1ED4 002C12D4 3C0A800E */  lui        $t2, %hi(__osRunQueue)
    /* C1ED8 002C12D8 8D4A9298 */  lw         $t2, %lo(__osRunQueue)($t2)
    /* C1EDC 002C12DC 8F490004 */  lw         $t1, 0x4($k0) /* handwritten instruction */
    /* C1EE0 002C12E0 8D4B0004 */  lw         $t3, 0x4($t2)
    /* C1EE4 002C12E4 00000000 */  nop
    /* C1EE8 002C12E8 012B082A */  slt        $at, $t1, $t3
    /* C1EEC 002C12EC 10200007 */  beqz       $at, .L002C130C
    /* C1EF0 002C12F0 00000000 */   nop
    /* C1EF4 002C12F4 3C04800E */  lui        $a0, %hi(__osRunQueue)
    /* C1EF8 002C12F8 24849298 */  addiu      $a0, $a0, %lo(__osRunQueue)
    /* C1EFC 002C12FC 0C0B057E */  jal        __osEnqueueThread
    /* C1F00 002C1300 03402821 */   addu      $a1, $k0, $zero
    /* C1F04 002C1304 080B0598 */  j          __osDispatchThread
    /* C1F08 002C1308 00000000 */   nop
  .L002C130C:
    /* C1F0C 002C130C 3C09800E */  lui        $t1, %hi(__osRunQueue)
    /* C1F10 002C1310 25299298 */  addiu      $t1, $t1, %lo(__osRunQueue)
    /* C1F14 002C1314 8D2A0000 */  lw         $t2, 0x0($t1)
    /* C1F18 002C1318 00000000 */  nop
    /* C1F1C 002C131C AF4A0000 */  sw         $t2, 0x0($k0) /* handwritten instruction */
    /* C1F20 002C1320 080B0598 */  j          __osDispatchThread
    /* C1F24 002C1324 AD3A0000 */   sw        $k0, 0x0($t1) /* handwritten instruction */
  .L002C1328:
    /* C1F28 002C1328 3C01800E */  lui        $at, %hi(__osFaultedThread)
    /* C1F2C 002C132C AC3A92A4 */  sw         $k0, %lo(__osFaultedThread)($at) /* handwritten instruction */
    /* C1F30 002C1330 24090001 */  addiu      $t1, $zero, 0x1
    /* C1F34 002C1334 A7490010 */  sh         $t1, 0x10($k0) /* handwritten instruction */
    /* C1F38 002C1338 24090002 */  addiu      $t1, $zero, 0x2
    /* C1F3C 002C133C 400A4000 */  mfc0       $t2, $8 /* handwritten instruction */
    /* C1F40 002C1340 A7490012 */  sh         $t1, 0x12($k0) /* handwritten instruction */
    /* C1F44 002C1344 AF4A0124 */  sw         $t2, 0x124($k0) /* handwritten instruction */
    /* C1F48 002C1348 0C0B04D6 */  jal        send_mesg
    /* C1F4C 002C134C 24040060 */   addiu     $a0, $zero, 0x60
    /* C1F50 002C1350 080B0598 */  j          __osDispatchThread
    /* C1F54 002C1354 00000000 */   nop


glabel send_mesg
    /* C1F58 002C1358 03E09021 */  addu       $s2, $ra, $zero
    /* C1F5C 002C135C 3C0A8015 */  lui        $t2, %hi(__osEventStateTab)
    /* C1F60 002C1360 254AFDA0 */  addiu      $t2, $t2, %lo(__osEventStateTab)
    /* C1F64 002C1364 01445021 */  addu       $t2, $t2, $a0
    /* C1F68 002C1368 8D490000 */  lw         $t1, 0x0($t2)
    /* C1F6C 002C136C 00000000 */  nop
    /* C1F70 002C1370 1120002A */  beqz       $t1, .L002C141C
    /* C1F74 002C1374 00000000 */   nop
    /* C1F78 002C1378 8D2B0008 */  lw         $t3, 0x8($t1)
    /* C1F7C 002C137C 8D2C0010 */  lw         $t4, 0x10($t1)
    /* C1F80 002C1380 00000000 */  nop
    /* C1F84 002C1384 016C082A */  slt        $at, $t3, $t4
    /* C1F88 002C1388 10200024 */  beqz       $at, .L002C141C
    /* C1F8C 002C138C 00000000 */   nop
    /* C1F90 002C1390 8D2D000C */  lw         $t5, 0xC($t1)
    /* C1F94 002C1394 00000000 */  nop
    /* C1F98 002C1398 01AB6821 */  addu       $t5, $t5, $t3
    /* C1F9C 002C139C 01AC001A */  div        $zero, $t5, $t4
    /* C1FA0 002C13A0 15800002 */  bnez       $t4, .L002C13AC
    /* C1FA4 002C13A4 00000000 */   nop
    /* C1FA8 002C13A8 0007000D */  break      7
  .L002C13AC:
    /* C1FAC 002C13AC 2401FFFF */  addiu      $at, $zero, -0x1
    /* C1FB0 002C13B0 15810004 */  bne        $t4, $at, .L002C13C4
    /* C1FB4 002C13B4 3C018000 */   lui       $at, (0x80000000 >> 16)
    /* C1FB8 002C13B8 15A10002 */  bne        $t5, $at, .L002C13C4
    /* C1FBC 002C13BC 00000000 */   nop
    /* C1FC0 002C13C0 0006000D */  break      6
  .L002C13C4:
    /* C1FC4 002C13C4 00006810 */  mfhi       $t5
    /* C1FC8 002C13C8 8D2C0014 */  lw         $t4, 0x14($t1)
    /* C1FCC 002C13CC 000D6880 */  sll        $t5, $t5, 2
    /* C1FD0 002C13D0 018D6021 */  addu       $t4, $t4, $t5
    /* C1FD4 002C13D4 8D4D0004 */  lw         $t5, 0x4($t2)
    /* C1FD8 002C13D8 00000000 */  nop
    /* C1FDC 002C13DC AD8D0000 */  sw         $t5, 0x0($t4)
    /* C1FE0 002C13E0 256A0001 */  addiu      $t2, $t3, 0x1
    /* C1FE4 002C13E4 AD2A0008 */  sw         $t2, 0x8($t1)
    /* C1FE8 002C13E8 8D2A0000 */  lw         $t2, 0x0($t1)
    /* C1FEC 002C13EC 00000000 */  nop
    /* C1FF0 002C13F0 8D4B0000 */  lw         $t3, 0x0($t2)
    /* C1FF4 002C13F4 00000000 */  nop
    /* C1FF8 002C13F8 11600008 */  beqz       $t3, .L002C141C
    /* C1FFC 002C13FC 00000000 */   nop
    /* C2000 002C1400 0C0B0592 */  jal        __osPopThread
    /* C2004 002C1404 01202021 */   addu      $a0, $t1, $zero
    /* C2008 002C1408 00405021 */  addu       $t2, $v0, $zero
    /* C200C 002C140C 3C04800E */  lui        $a0, %hi(__osRunQueue)
    /* C2010 002C1410 24849298 */  addiu      $a0, $a0, %lo(__osRunQueue)
    /* C2014 002C1414 0C0B057E */  jal        __osEnqueueThread
    /* C2018 002C1418 01402821 */   addu      $a1, $t2, $zero
  .L002C141C:
    /* C201C 002C141C 02400008 */  jr         $s2
    /* C2020 002C1420 00000000 */   nop
  .L002C1424:
    /* C2024 002C1424 3C013000 */  lui        $at, (0x30000000 >> 16)
    /* C2028 002C1428 01014824 */  and        $t1, $t0, $at
    /* C202C 002C142C 00094F02 */  srl        $t1, $t1, 28
    /* C2030 002C1430 240A0001 */  addiu      $t2, $zero, 0x1
    /* C2034 002C1434 152AFFBC */  bne        $t1, $t2, .L002C1328
    /* C2038 002C1438 24090001 */   addiu     $t1, $zero, 0x1
    /* C203C 002C143C AF490018 */  sw         $t1, 0x18($k0) /* handwritten instruction */
    /* C2040 002C1440 8F5B0118 */  lw         $k1, 0x118($k0) /* handwritten instruction */
    /* C2044 002C1444 00000000 */  nop
    /* C2048 002C1448 3C012000 */  lui        $at, (0x20000000 >> 16)
    /* C204C 002C144C 0361D825 */  or         $k1, $k1, $at
    /* C2050 002C1450 AF5B0118 */  sw         $k1, 0x118($k0) /* handwritten instruction */
    /* C2054 002C1454 0401FFAD */  bgez       $zero, .L002C130C
    /* C2058 002C1458 00000000 */   nop
endlabel __osExceptionPreamble
