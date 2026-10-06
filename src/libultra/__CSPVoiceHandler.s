.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB48F0-0xB4E20 (VRAM 0x002B3CF0) */
glabel __CSPVoiceHandler
    /* B48F0 002B3CF0 27BDFFB0 */  addiu      $sp, $sp, -0x50
    /* B48F4 002B3CF4 F7B40048 */  sdc1       $fs0, 0x48($sp)
    /* B48F8 002B3CF8 3C01800D */  lui        $at, %hi(D_800CC5B8)
    /* B48FC 002B3CFC C434C5B8 */  lwc1       $fs0, %lo(D_800CC5B8)($at)
    /* B4900 002B3D00 AFB20030 */  sw         $s2, 0x30($sp)
    /* B4904 002B3D04 00809021 */  addu       $s2, $a0, $zero
    /* B4908 002B3D08 AFB60040 */  sw         $s6, 0x40($sp)
    /* B490C 002B3D0C 24160001 */  addiu      $s6, $zero, 0x1
    /* B4910 002B3D10 AFB5003C */  sw         $s5, 0x3C($sp)
    /* B4914 002B3D14 26550048 */  addiu      $s5, $s2, 0x48
    /* B4918 002B3D18 AFBF0044 */  sw         $ra, 0x44($sp)
    /* B491C 002B3D1C AFB40038 */  sw         $s4, 0x38($sp)
    /* B4920 002B3D20 AFB30034 */  sw         $s3, 0x34($sp)
    /* B4924 002B3D24 AFB1002C */  sw         $s1, 0x2C($sp)
    /* B4928 002B3D28 AFB00028 */  sw         $s0, 0x28($sp)
  .L002B3D2C:
    /* B492C 002B3D2C 86430038 */  lh         $v1, 0x38($s2)
    /* B4930 002B3D30 2C620018 */  sltiu      $v0, $v1, 0x18
    /* B4934 002B3D34 10400126 */  beqz       $v0, .L002B41D0
    /* B4938 002B3D38 00031080 */   sll       $v0, $v1, 2
    /* B493C 002B3D3C 3C01800D */  lui        $at, %hi(jtbl_800CC5C0)
    /* B4940 002B3D40 00220821 */  addu       $at, $at, $v0
    /* B4944 002B3D44 8C22C5C0 */  lw         $v0, %lo(jtbl_800CC5C0)($at)
    /* B4948 002B3D48 00400008 */  jr         $v0
    /* B494C 002B3D4C 00000000 */   nop
    /* B4950 002B3D50 0C0AD088 */  jal        __CSPHandleNextSeqEvent
    /* B4954 002B3D54 02402021 */   addu      $a0, $s2, $zero
    /* B4958 002B3D58 080AD075 */  j          .L002B41D4
    /* B495C 002B3D5C 26440048 */   addiu     $a0, $s2, 0x48
    /* B4960 002B3D60 26440048 */  addiu      $a0, $s2, 0x48
    /* B4964 002B3D64 24020009 */  addiu      $v0, $zero, 0x9
    /* B4968 002B3D68 A7A20010 */  sh         $v0, 0x10($sp)
    /* B496C 002B3D6C 8E46005C */  lw         $a2, 0x5C($s2)
    /* B4970 002B3D70 0C0AD469 */  jal        alEvtqPostEvent
    /* B4974 002B3D74 27A50010 */   addiu     $a1, $sp, 0x10
    /* B4978 002B3D78 080AD075 */  j          .L002B41D4
    /* B497C 002B3D7C 26440048 */   addiu     $a0, $s2, 0x48
    /* B4980 002B3D80 8E50003C */  lw         $s0, 0x3C($s2)
    /* B4984 002B3D84 8E440014 */  lw         $a0, 0x14($s2)
    /* B4988 002B3D88 0C0AE1F0 */  jal        alSynStopVoice
    /* B498C 002B3D8C 02002821 */   addu      $a1, $s0, $zero
    /* B4990 002B3D90 8E440014 */  lw         $a0, 0x14($s2)
    /* B4994 002B3D94 0C0AE0B4 */  jal        alSynFreeVoice
    /* B4998 002B3D98 02002821 */   addu      $a1, $s0, $zero
    /* B499C 002B3D9C 8E110010 */  lw         $s1, 0x10($s0)
    /* B49A0 002B3DA0 92220037 */  lbu        $v0, 0x37($s1)
    /* B49A4 002B3DA4 10400003 */  beqz       $v0, .L002B3DB4
    /* B49A8 002B3DA8 02402021 */   addu      $a0, $s2, $zero
    /* B49AC 002B3DAC 0C0ADB41 */  jal        __seqpStopOsc
    /* B49B0 002B3DB0 02202821 */   addu      $a1, $s1, $zero
  .L002B3DB4:
    /* B49B4 002B3DB4 02402021 */  addu       $a0, $s2, $zero
    /* B49B8 002B3DB8 0C0AD98F */  jal        __unmapVoice
    /* B49BC 002B3DBC 02002821 */   addu      $a1, $s0, $zero
    /* B49C0 002B3DC0 080AD075 */  j          .L002B41D4
    /* B49C4 002B3DC4 26440048 */   addiu     $a0, $s2, 0x48
    /* B49C8 002B3DC8 8E50003C */  lw         $s0, 0x3C($s2)
    /* B49CC 002B3DCC 8E110010 */  lw         $s1, 0x10($s0)
    /* B49D0 002B3DD0 92220034 */  lbu        $v0, 0x34($s1)
    /* B49D4 002B3DD4 14400002 */  bnez       $v0, .L002B3DE0
    /* B49D8 002B3DD8 24020001 */   addiu     $v0, $zero, 0x1
    /* B49DC 002B3DDC A2220034 */  sb         $v0, 0x34($s1)
  .L002B3DE0:
    /* B49E0 002B3DE0 8E530040 */  lw         $s3, 0x40($s2)
    /* B49E4 002B3DE4 8E42001C */  lw         $v0, 0x1C($s2)
    /* B49E8 002B3DE8 02202021 */  addu       $a0, $s1, $zero
    /* B49EC 002B3DEC 00531021 */  addu       $v0, $v0, $s3
    /* B49F0 002B3DF0 AC820024 */  sw         $v0, 0x24($a0)
    /* B49F4 002B3DF4 92420044 */  lbu        $v0, 0x44($s2)
    /* B49F8 002B3DF8 02402821 */  addu       $a1, $s2, $zero
    /* B49FC 002B3DFC 0C0ADA39 */  jal        __vsVol
    /* B4A00 002B3E00 A0820030 */   sb        $v0, 0x30($a0)
    /* B4A04 002B3E04 02002821 */  addu       $a1, $s0, $zero
    /* B4A08 002B3E08 00021400 */  sll        $v0, $v0, 16
    /* B4A0C 002B3E0C 00023403 */  sra        $a2, $v0, 16
    /* B4A10 002B3E10 8E440014 */  lw         $a0, 0x14($s2)
    /* B4A14 002B3E14 0C0AE154 */  jal        alSynSetVol
    /* B4A18 002B3E18 02603821 */   addu      $a3, $s3, $zero
    /* B4A1C 002B3E1C 080AD075 */  j          .L002B41D4
    /* B4A20 002B3E20 26440048 */   addiu     $a0, $s2, 0x48
    /* B4A24 002B3E24 27A50020 */  addiu      $a1, $sp, 0x20
    /* B4A28 002B3E28 8E51003C */  lw         $s1, 0x3C($s2)
    /* B4A2C 002B3E2C 8E540040 */  lw         $s4, 0x40($s2)
    /* B4A30 002B3E30 8E420074 */  lw         $v0, 0x74($s2)
    /* B4A34 002B3E34 0040F809 */  jalr       $v0
    /* B4A38 002B3E38 02802021 */   addu      $a0, $s4, $zero
    /* B4A3C 002B3E3C 00409821 */  addu       $s3, $v0, $zero
    /* B4A40 002B3E40 C7A00020 */  lwc1       $fv0, 0x20($sp)
    /* B4A44 002B3E44 4600A03E */  c.le.s     $fs0, $fv0
    /* B4A48 002B3E48 00000000 */  nop
    /* B4A4C 002B3E4C 45010005 */  bc1t       .L002B3E64
    /* B4A50 002B3E50 26260036 */   addiu     $a2, $s1, 0x36
    /* B4A54 002B3E54 4600008D */  trunc.w.s  $fv1, $fv0
    /* B4A58 002B3E58 44031000 */  mfc1       $v1, $fv1
    /* B4A5C 002B3E5C 080ACF9F */  j          .L002B3E7C
    /* B4A60 002B3E60 02202021 */   addu      $a0, $s1, $zero
  .L002B3E64:
    /* B4A64 002B3E64 46140001 */  sub.s      $fv0, $fv0, $fs0
    /* B4A68 002B3E68 3C028000 */  lui        $v0, (0x80000000 >> 16)
    /* B4A6C 002B3E6C 4600008D */  trunc.w.s  $fv1, $fv0
    /* B4A70 002B3E70 44031000 */  mfc1       $v1, $fv1
    /* B4A74 002B3E74 00621825 */  or         $v1, $v1, $v0
    /* B4A78 002B3E78 02202021 */  addu       $a0, $s1, $zero
  .L002B3E7C:
    /* B4A7C 002B3E7C 02402821 */  addu       $a1, $s2, $zero
    /* B4A80 002B3E80 0C0ADA39 */  jal        __vsVol
    /* B4A84 002B3E84 A0C30000 */   sb        $v1, 0x0($a2)
    /* B4A88 002B3E88 02202021 */  addu       $a0, $s1, $zero
    /* B4A8C 002B3E8C 00028400 */  sll        $s0, $v0, 16
    /* B4A90 002B3E90 8E45001C */  lw         $a1, 0x1C($s2)
    /* B4A94 002B3E94 0C0ADA56 */  jal        __vsDelta
    /* B4A98 002B3E98 00108403 */   sra       $s0, $s0, 16
    /* B4A9C 002B3E9C 26250004 */  addiu      $a1, $s1, 0x4
    /* B4AA0 002B3EA0 02003021 */  addu       $a2, $s0, $zero
    /* B4AA4 002B3EA4 8E440014 */  lw         $a0, 0x14($s2)
    /* B4AA8 002B3EA8 0C0AE154 */  jal        alSynSetVol
    /* B4AAC 002B3EAC 00403821 */   addu      $a3, $v0, $zero
    /* B4AB0 002B3EB0 26440048 */  addiu      $a0, $s2, 0x48
    /* B4AB4 002B3EB4 27A50010 */  addiu      $a1, $sp, 0x10
    /* B4AB8 002B3EB8 02603021 */  addu       $a2, $s3, $zero
    /* B4ABC 002B3EBC 24020016 */  addiu      $v0, $zero, 0x16
    /* B4AC0 002B3EC0 A7A20010 */  sh         $v0, 0x10($sp)
    /* B4AC4 002B3EC4 AFB10014 */  sw         $s1, 0x14($sp)
    /* B4AC8 002B3EC8 0C0AD469 */  jal        alEvtqPostEvent
    /* B4ACC 002B3ECC AFB40018 */   sw        $s4, 0x18($sp)
    /* B4AD0 002B3ED0 080AD075 */  j          .L002B41D4
    /* B4AD4 002B3ED4 26440048 */   addiu     $a0, $s2, 0x48
    /* B4AD8 002B3ED8 27A50020 */  addiu      $a1, $sp, 0x20
    /* B4ADC 002B3EDC 8E540040 */  lw         $s4, 0x40($s2)
    /* B4AE0 002B3EE0 8E51003C */  lw         $s1, 0x3C($s2)
    /* B4AE4 002B3EE4 8E420074 */  lw         $v0, 0x74($s2)
    /* B4AE8 002B3EE8 92500044 */  lbu        $s0, 0x44($s2)
    /* B4AEC 002B3EEC 0040F809 */  jalr       $v0
    /* B4AF0 002B3EF0 02802021 */   addu      $a0, $s4, $zero
    /* B4AF4 002B3EF4 C7A00020 */  lwc1       $fv0, 0x20($sp)
    /* B4AF8 002B3EF8 C6210028 */  lwc1       $fv0f, 0x28($s1)
    /* B4AFC 002B3EFC 320300FF */  andi       $v1, $s0, 0xFF
    /* B4B00 002B3F00 46000842 */  mul.s      $fv0f, $fv0f, $fv0
    /* B4B04 002B3F04 E620002C */  swc1       $fv0, 0x2C($s1)
    /* B4B08 002B3F08 8E440060 */  lw         $a0, 0x60($s2)
    /* B4B0C 002B3F0C 00031900 */  sll        $v1, $v1, 4
    /* B4B10 002B3F10 00641821 */  addu       $v1, $v1, $a0
    /* B4B14 002B3F14 C460000C */  lwc1       $fv0, 0xC($v1)
    /* B4B18 002B3F18 46000842 */  mul.s      $fv0f, $fv0f, $fv0
    /* B4B1C 002B3F1C 00409821 */  addu       $s3, $v0, $zero
    /* B4B20 002B3F20 8E440014 */  lw         $a0, 0x14($s2)
    /* B4B24 002B3F24 44060800 */  mfc1       $a2, $fv0f
    /* B4B28 002B3F28 0C0AE12C */  jal        alSynSetPitch
    /* B4B2C 002B3F2C 26250004 */   addiu     $a1, $s1, 0x4
    /* B4B30 002B3F30 26440048 */  addiu      $a0, $s2, 0x48
    /* B4B34 002B3F34 27A50010 */  addiu      $a1, $sp, 0x10
    /* B4B38 002B3F38 02603021 */  addu       $a2, $s3, $zero
    /* B4B3C 002B3F3C 24020017 */  addiu      $v0, $zero, 0x17
    /* B4B40 002B3F40 A7A20010 */  sh         $v0, 0x10($sp)
    /* B4B44 002B3F44 AFB10014 */  sw         $s1, 0x14($sp)
    /* B4B48 002B3F48 AFB40018 */  sw         $s4, 0x18($sp)
    /* B4B4C 002B3F4C 0C0AD469 */  jal        alEvtqPostEvent
    /* B4B50 002B3F50 A3B0001C */   sb        $s0, 0x1C($sp)
    /* B4B54 002B3F54 080AD075 */  j          .L002B41D4
    /* B4B58 002B3F58 26440048 */   addiu     $a0, $s2, 0x48
    /* B4B5C 002B3F5C 02402021 */  addu       $a0, $s2, $zero
    /* B4B60 002B3F60 0C0AD0EC */  jal        __CSPHandleMIDIMsg
    /* B4B64 002B3F64 26450038 */   addiu     $a1, $s2, 0x38
    /* B4B68 002B3F68 080AD075 */  j          .L002B41D4
    /* B4B6C 002B3F6C 26440048 */   addiu     $a0, $s2, 0x48
    /* B4B70 002B3F70 02402021 */  addu       $a0, $s2, $zero
    /* B4B74 002B3F74 0C0AD30F */  jal        __CSPHandleMetaMsg
    /* B4B78 002B3F78 26450038 */   addiu     $a1, $s2, 0x38
    /* B4B7C 002B3F7C 080AD075 */  j          .L002B41D4
    /* B4B80 002B3F80 26440048 */   addiu     $a0, $s2, 0x48
    /* B4B84 002B3F84 9642003C */  lhu        $v0, 0x3C($s2)
    /* B4B88 002B3F88 8E510064 */  lw         $s1, 0x64($s2)
    /* B4B8C 002B3F8C 12200090 */  beqz       $s1, .L002B41D0
    /* B4B90 002B3F90 A6420032 */   sh        $v0, 0x32($s2)
    /* B4B94 002B3F94 02202021 */  addu       $a0, $s1, $zero
  .L002B3F98:
    /* B4B98 002B3F98 0C0ADA39 */  jal        __vsVol
    /* B4B9C 002B3F9C 02402821 */   addu      $a1, $s2, $zero
    /* B4BA0 002B3FA0 02202021 */  addu       $a0, $s1, $zero
    /* B4BA4 002B3FA4 00028400 */  sll        $s0, $v0, 16
    /* B4BA8 002B3FA8 8E45001C */  lw         $a1, 0x1C($s2)
    /* B4BAC 002B3FAC 0C0ADA56 */  jal        __vsDelta
    /* B4BB0 002B3FB0 00108403 */   sra       $s0, $s0, 16
    /* B4BB4 002B3FB4 26250004 */  addiu      $a1, $s1, 0x4
    /* B4BB8 002B3FB8 02003021 */  addu       $a2, $s0, $zero
    /* B4BBC 002B3FBC 8E440014 */  lw         $a0, 0x14($s2)
    /* B4BC0 002B3FC0 0C0AE154 */  jal        alSynSetVol
    /* B4BC4 002B3FC4 00403821 */   addu      $a3, $v0, $zero
    /* B4BC8 002B3FC8 8E310000 */  lw         $s1, 0x0($s1)
    /* B4BCC 002B3FCC 1620FFF2 */  bnez       $s1, .L002B3F98
    /* B4BD0 002B3FD0 02202021 */   addu      $a0, $s1, $zero
    /* B4BD4 002B3FD4 080AD075 */  j          .L002B41D4
    /* B4BD8 002B3FD8 26440048 */   addiu     $a0, $s2, 0x48
    /* B4BDC 002B3FDC 8E42002C */  lw         $v0, 0x2C($s2)
    /* B4BE0 002B3FE0 1056007C */  beq        $v0, $s6, .L002B41D4
    /* B4BE4 002B3FE4 26440048 */   addiu     $a0, $s2, 0x48
    /* B4BE8 002B3FE8 AE56002C */  sw         $s6, 0x2C($s2)
    /* B4BEC 002B3FEC 0C0AD374 */  jal        __CSPPostNextSeqEvent
    /* B4BF0 002B3FF0 02402021 */   addu      $a0, $s2, $zero
    /* B4BF4 002B3FF4 080AD075 */  j          .L002B41D4
    /* B4BF8 002B3FF8 26440048 */   addiu     $a0, $s2, 0x48
    /* B4BFC 002B3FFC 8E43002C */  lw         $v1, 0x2C($s2)
    /* B4C00 002B4000 24020002 */  addiu      $v0, $zero, 0x2
    /* B4C04 002B4004 14620073 */  bne        $v1, $v0, .L002B41D4
    /* B4C08 002B4008 26440048 */   addiu     $a0, $s2, 0x48
    /* B4C0C 002B400C 8E510064 */  lw         $s1, 0x64($s2)
    /* B4C10 002B4010 52200070 */  beql       $s1, $zero, .L002B41D4
    /* B4C14 002B4014 AE40002C */   sw        $zero, 0x2C($s2)
    /* B4C18 002B4018 26300004 */  addiu      $s0, $s1, 0x4
  .L002B401C:
    /* B4C1C 002B401C 8E440014 */  lw         $a0, 0x14($s2)
    /* B4C20 002B4020 0C0AE1F0 */  jal        alSynStopVoice
    /* B4C24 002B4024 02002821 */   addu      $a1, $s0, $zero
    /* B4C28 002B4028 8E440014 */  lw         $a0, 0x14($s2)
    /* B4C2C 002B402C 0C0AE0B4 */  jal        alSynFreeVoice
    /* B4C30 002B4030 02002821 */   addu      $a1, $s0, $zero
    /* B4C34 002B4034 92220037 */  lbu        $v0, 0x37($s1)
    /* B4C38 002B4038 10400003 */  beqz       $v0, .L002B4048
    /* B4C3C 002B403C 02402021 */   addu      $a0, $s2, $zero
    /* B4C40 002B4040 0C0ADB41 */  jal        __seqpStopOsc
    /* B4C44 002B4044 02202821 */   addu      $a1, $s1, $zero
  .L002B4048:
    /* B4C48 002B4048 02402021 */  addu       $a0, $s2, $zero
    /* B4C4C 002B404C 0C0AD98F */  jal        __unmapVoice
    /* B4C50 002B4050 02002821 */   addu      $a1, $s0, $zero
    /* B4C54 002B4054 8E510064 */  lw         $s1, 0x64($s2)
    /* B4C58 002B4058 1620FFF0 */  bnez       $s1, .L002B401C
    /* B4C5C 002B405C 26300004 */   addiu     $s0, $s1, 0x4
    /* B4C60 002B4060 080AD074 */  j          .L002B41D0
    /* B4C64 002B4064 AE40002C */   sw        $zero, 0x2C($s2)
    /* B4C68 002B4068 8E42002C */  lw         $v0, 0x2C($s2)
    /* B4C6C 002B406C 14560059 */  bne        $v0, $s6, .L002B41D4
    /* B4C70 002B4070 26440048 */   addiu     $a0, $s2, 0x48
    /* B4C74 002B4074 02A02021 */  addu       $a0, $s5, $zero
    /* B4C78 002B4078 0C0AD4CA */  jal        alEvtqFlushType
    /* B4C7C 002B407C 00002821 */   addu      $a1, $zero, $zero
    /* B4C80 002B4080 02A02021 */  addu       $a0, $s5, $zero
    /* B4C84 002B4084 0C0AD4CA */  jal        alEvtqFlushType
    /* B4C88 002B4088 24050015 */   addiu     $a1, $zero, 0x15
    /* B4C8C 002B408C 02A02021 */  addu       $a0, $s5, $zero
    /* B4C90 002B4090 0C0AD4CA */  jal        alEvtqFlushType
    /* B4C94 002B4094 24050002 */   addiu     $a1, $zero, 0x2
    /* B4C98 002B4098 8E510064 */  lw         $s1, 0x64($s2)
    /* B4C9C 002B409C 12200010 */  beqz       $s1, .L002B40E0
    /* B4CA0 002B40A0 26440048 */   addiu     $a0, $s2, 0x48
    /* B4CA4 002B40A4 02402021 */  addu       $a0, $s2, $zero
  .L002B40A8:
    /* B4CA8 002B40A8 26300004 */  addiu      $s0, $s1, 0x4
    /* B4CAC 002B40AC 02002821 */  addu       $a1, $s0, $zero
    /* B4CB0 002B40B0 0C0AD9A8 */  jal        __voiceNeedsNoteKillOff
    /* B4CB4 002B40B4 3406C350 */   ori       $a2, $zero, 0xC350
    /* B4CB8 002B40B8 304200FF */  andi       $v0, $v0, 0xFF
    /* B4CBC 002B40BC 10400004 */  beqz       $v0, .L002B40D0
    /* B4CC0 002B40C0 02402021 */   addu      $a0, $s2, $zero
    /* B4CC4 002B40C4 02002821 */  addu       $a1, $s0, $zero
    /* B4CC8 002B40C8 0C0ADAF9 */  jal        __seqpReleaseVoice
    /* B4CCC 002B40CC 3406C350 */   ori       $a2, $zero, 0xC350
  .L002B40D0:
    /* B4CD0 002B40D0 8E310000 */  lw         $s1, 0x0($s1)
    /* B4CD4 002B40D4 1620FFF4 */  bnez       $s1, .L002B40A8
    /* B4CD8 002B40D8 02402021 */   addu      $a0, $s2, $zero
    /* B4CDC 002B40DC 26440048 */  addiu      $a0, $s2, 0x48
  .L002B40E0:
    /* B4CE0 002B40E0 27A50010 */  addiu      $a1, $sp, 0x10
    /* B4CE4 002B40E4 3C067FFF */  lui        $a2, (0x7FFFFFFF >> 16)
    /* B4CE8 002B40E8 34C6FFFF */  ori        $a2, $a2, (0x7FFFFFFF & 0xFFFF)
    /* B4CEC 002B40EC 24020002 */  addiu      $v0, $zero, 0x2
    /* B4CF0 002B40F0 AE42002C */  sw         $v0, 0x2C($s2)
    /* B4CF4 002B40F4 24020010 */  addiu      $v0, $zero, 0x10
    /* B4CF8 002B40F8 0C0AD469 */  jal        alEvtqPostEvent
    /* B4CFC 002B40FC A7A20010 */   sh        $v0, 0x10($sp)
    /* B4D00 002B4100 080AD075 */  j          .L002B41D4
    /* B4D04 002B4104 26440048 */   addiu     $a0, $s2, 0x48
    /* B4D08 002B4108 9242003C */  lbu        $v0, 0x3C($s2)
    /* B4D0C 002B410C 8E430060 */  lw         $v1, 0x60($s2)
    /* B4D10 002B4110 9244003D */  lbu        $a0, 0x3D($s2)
    /* B4D14 002B4114 00021100 */  sll        $v0, $v0, 4
    /* B4D18 002B4118 00431021 */  addu       $v0, $v0, $v1
    /* B4D1C 002B411C 080AD074 */  j          .L002B41D0
    /* B4D20 002B4120 A0440008 */   sb        $a0, 0x8($v0)
    /* B4D24 002B4124 8E42002C */  lw         $v0, 0x2C($s2)
    /* B4D28 002B4128 14560007 */  bne        $v0, $s6, .L002B4148
    /* B4D2C 002B412C 00000000 */   nop
    /* B4D30 002B4130 3C04800D */  lui        $a0, %hi(D_800CC5A0)
    /* B4D34 002B4134 2484C5A0 */  addiu      $a0, $a0, %lo(D_800CC5A0)
    /* B4D38 002B4138 3C05800D */  lui        $a1, %hi(D_800CC5A4)
    /* B4D3C 002B413C 24A5C5A4 */  addiu      $a1, $a1, %lo(D_800CC5A4)
    /* B4D40 002B4140 0C0AFF50 */  jal        __assert
    /* B4D44 002B4144 24060127 */   addiu     $a2, $zero, 0x127
  .L002B4148:
    /* B4D48 002B4148 3C0548F4 */  lui        $a1, (0x48F42400 >> 16)
    /* B4D4C 002B414C 34A52400 */  ori        $a1, $a1, (0x48F42400 & 0xFFFF)
    /* B4D50 002B4150 8E42003C */  lw         $v0, 0x3C($s2)
    /* B4D54 002B4154 02402021 */  addu       $a0, $s2, $zero
    /* B4D58 002B4158 0C0AD3B3 */  jal        __setUsptFromTempo_2
    /* B4D5C 002B415C AE420018 */   sw        $v0, 0x18($s2)
    /* B4D60 002B4160 8E450020 */  lw         $a1, 0x20($s2)
    /* B4D64 002B4164 10A0001B */  beqz       $a1, .L002B41D4
    /* B4D68 002B4168 26440048 */   addiu     $a0, $s2, 0x48
    /* B4D6C 002B416C 0C0ADA6D */  jal        __initFromBank
    /* B4D70 002B4170 02402021 */   addu      $a0, $s2, $zero
    /* B4D74 002B4174 080AD075 */  j          .L002B41D4
    /* B4D78 002B4178 26440048 */   addiu     $a0, $s2, 0x48
    /* B4D7C 002B417C 8E42002C */  lw         $v0, 0x2C($s2)
    /* B4D80 002B4180 10400007 */  beqz       $v0, .L002B41A0
    /* B4D84 002B4184 00000000 */   nop
    /* B4D88 002B4188 3C04800D */  lui        $a0, %hi(D_800CC5A0)
    /* B4D8C 002B418C 2484C5A0 */  addiu      $a0, $a0, %lo(D_800CC5A0)
    /* B4D90 002B4190 3C05800D */  lui        $a1, %hi(D_800CC5A4)
    /* B4D94 002B4194 24A5C5A4 */  addiu      $a1, $a1, %lo(D_800CC5A4)
    /* B4D98 002B4198 0C0AFF50 */  jal        __assert
    /* B4D9C 002B419C 24060130 */   addiu     $a2, $zero, 0x130
  .L002B41A0:
    /* B4DA0 002B41A0 8E45003C */  lw         $a1, 0x3C($s2)
    /* B4DA4 002B41A4 02402021 */  addu       $a0, $s2, $zero
    /* B4DA8 002B41A8 0C0ADA6D */  jal        __initFromBank
    /* B4DAC 002B41AC AE450020 */   sw        $a1, 0x20($s2)
    /* B4DB0 002B41B0 080AD075 */  j          .L002B41D4
    /* B4DB4 002B41B4 26440048 */   addiu     $a0, $s2, 0x48
    /* B4DB8 002B41B8 3C04800D */  lui        $a0, %hi(D_800CC5A0)
    /* B4DBC 002B41BC 2484C5A0 */  addiu      $a0, $a0, %lo(D_800CC5A0)
    /* B4DC0 002B41C0 3C05800D */  lui        $a1, %hi(D_800CC5A4)
    /* B4DC4 002B41C4 24A5C5A4 */  addiu      $a1, $a1, %lo(D_800CC5A4)
    /* B4DC8 002B41C8 0C0AFF50 */  jal        __assert
    /* B4DCC 002B41CC 2406013A */   addiu     $a2, $zero, 0x13A
  .L002B41D0:
    /* B4DD0 002B41D0 26440048 */  addiu      $a0, $s2, 0x48
  .L002B41D4:
    /* B4DD4 002B41D4 0C0AD443 */  jal        alEvtqNextEvent
    /* B4DD8 002B41D8 26450038 */   addiu     $a1, $s2, 0x38
    /* B4DDC 002B41DC 00402021 */  addu       $a0, $v0, $zero
    /* B4DE0 002B41E0 1080FED2 */  beqz       $a0, .L002B3D2C
    /* B4DE4 002B41E4 AE440028 */   sw        $a0, 0x28($s2)
    /* B4DE8 002B41E8 8E43001C */  lw         $v1, 0x1C($s2)
    /* B4DEC 002B41EC 00641821 */  addu       $v1, $v1, $a0
    /* B4DF0 002B41F0 AE43001C */  sw         $v1, 0x1C($s2)
    /* B4DF4 002B41F4 8FBF0044 */  lw         $ra, 0x44($sp)
    /* B4DF8 002B41F8 8FB60040 */  lw         $s6, 0x40($sp)
    /* B4DFC 002B41FC 8FB5003C */  lw         $s5, 0x3C($sp)
    /* B4E00 002B4200 8FB40038 */  lw         $s4, 0x38($sp)
    /* B4E04 002B4204 8FB30034 */  lw         $s3, 0x34($sp)
    /* B4E08 002B4208 8FB20030 */  lw         $s2, 0x30($sp)
    /* B4E0C 002B420C 8FB1002C */  lw         $s1, 0x2C($sp)
    /* B4E10 002B4210 8FB00028 */  lw         $s0, 0x28($sp)
    /* B4E14 002B4214 D7B40048 */  ldc1       $fs0, 0x48($sp)
    /* B4E18 002B4218 03E00008 */  jr         $ra
    /* B4E1C 002B421C 27BD0050 */   addiu     $sp, $sp, 0x50
endlabel __CSPVoiceHandler
