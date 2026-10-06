.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB0BEC-0xB0E6C (VRAM 0x002AFFEC) */
glabel dbgHostFclose
    /* B0BEC 002AFFEC 27BDFFC8 */  addiu      $sp, $sp, -0x38
    /* B0BF0 002AFFF0 AFB5002C */  sw         $s5, 0x2C($sp)
    /* B0BF4 002AFFF4 0080A821 */  addu       $s5, $a0, $zero
    /* B0BF8 002AFFF8 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B0BFC 002AFFFC 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B0C00 002B0000 24030064 */  addiu      $v1, $zero, 0x64
    /* B0C04 002B0004 AFBF0030 */  sw         $ra, 0x30($sp)
    /* B0C08 002B0008 AFB40028 */  sw         $s4, 0x28($sp)
    /* B0C0C 002B000C AFB30024 */  sw         $s3, 0x24($sp)
    /* B0C10 002B0010 AFB20020 */  sw         $s2, 0x20($sp)
    /* B0C14 002B0014 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B0C18 002B0018 AFB00018 */  sw         $s0, 0x18($sp)
    /* B0C1C 002B001C 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B0C20 002B0020 AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B0C24 002B0024 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B0C28 002B0028 AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B0C2C 002B002C 34420004 */  ori        $v0, $v0, 0x4
    /* B0C30 002B0030 00409021 */  addu       $s2, $v0, $zero
    /* B0C34 002B0034 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B0C38 002B0038 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B003C:
    /* B0C3C 002B003C 0C0AF7A8 */  jal        osPiGetStatus
    /* B0C40 002B0040 00000000 */   nop
    /* B0C44 002B0044 30420003 */  andi       $v0, $v0, 0x3
    /* B0C48 002B0048 1440FFFC */  bnez       $v0, .L002B003C
    /* B0C4C 002B004C 24140002 */   addiu     $s4, $zero, 0x2
    /* B0C50 002B0050 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B0C54 002B0054 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B0C58 002B0058 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B0C5C 002B005C 24130002 */  addiu      $s3, $zero, 0x2
    /* B0C60 002B0060 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B0C64 002B0064 A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002B0068:
    /* B0C68 002B0068 0C0AF7A8 */  jal        osPiGetStatus
    /* B0C6C 002B006C 00000000 */   nop
    /* B0C70 002B0070 30420003 */  andi       $v0, $v0, 0x3
    /* B0C74 002B0074 1440FFFC */  bnez       $v0, .L002B0068
    /* B0C78 002B0078 00000000 */   nop
    /* B0C7C 002B007C 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B0C80 002B0080 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B0C84 002B0084 00541024 */  and        $v0, $v0, $s4
    /* B0C88 002B0088 10530009 */  beq        $v0, $s3, .L002B00B0
    /* B0C8C 002B008C 02001021 */   addu      $v0, $s0, $zero
    /* B0C90 002B0090 14400003 */  bnez       $v0, .L002B00A0
    /* B0C94 002B0094 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B0C98 002B0098 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B0C9C 002B009C 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B00A0:
    /* B0CA0 002B00A0 1E20FFF1 */  bgtz       $s1, .L002B0068
    /* B0CA4 002B00A4 24020001 */   addiu     $v0, $zero, 0x1
    /* B0CA8 002B00A8 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B0CAC 002B00AC AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B00B0:
    /* B0CB0 002B00B0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0CB4 002B00B4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0CB8 002B00B8 14400053 */  bnez       $v0, .L002B0208
    /* B0CBC 002B00BC 00000000 */   nop
    /* B0CC0 002B00C0 0C0AB96B */  jal        dbgLinkSendByte
    /* B0CC4 002B00C4 24040010 */   addiu     $a0, $zero, 0x10
    /* B0CC8 002B00C8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0CCC 002B00CC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0CD0 002B00D0 1440000A */  bnez       $v0, .L002B00FC
    /* B0CD4 002B00D4 00008021 */   addu      $s0, $zero, $zero
    /* B0CD8 002B00D8 0C0AB8E0 */  jal        dbgLinkRecvByte
    /* B0CDC 002B00DC 27A40010 */   addiu     $a0, $sp, 0x10
    /* B0CE0 002B00E0 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0CE4 002B00E4 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0CE8 002B00E8 14400004 */  bnez       $v0, .L002B00FC
    /* B0CEC 002B00EC 00000000 */   nop
    /* B0CF0 002B00F0 93A20010 */  lbu        $v0, 0x10($sp)
    /* B0CF4 002B00F4 38420011 */  xori       $v0, $v0, 0x11
    /* B0CF8 002B00F8 2C500001 */  sltiu      $s0, $v0, 0x1
  .L002B00FC:
    /* B0CFC 002B00FC 12000042 */  beqz       $s0, .L002B0208
    /* B0D00 002B0100 00000000 */   nop
    /* B0D04 002B0104 0C0AB96B */  jal        dbgLinkSendByte
    /* B0D08 002B0108 24040081 */   addiu     $a0, $zero, 0x81
    /* B0D0C 002B010C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0D10 002B0110 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0D14 002B0114 1440003C */  bnez       $v0, .L002B0208
    /* B0D18 002B0118 00000000 */   nop
    /* B0D1C 002B011C 0C0AB96B */  jal        dbgLinkSendByte
    /* B0D20 002B0120 00152602 */   srl       $a0, $s5, 24
    /* B0D24 002B0124 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0D28 002B0128 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0D2C 002B012C 14400036 */  bnez       $v0, .L002B0208
    /* B0D30 002B0130 00152402 */   srl       $a0, $s5, 16
    /* B0D34 002B0134 0C0AB96B */  jal        dbgLinkSendByte
    /* B0D38 002B0138 308400FF */   andi      $a0, $a0, 0xFF
    /* B0D3C 002B013C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0D40 002B0140 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0D44 002B0144 14400030 */  bnez       $v0, .L002B0208
    /* B0D48 002B0148 00152202 */   srl       $a0, $s5, 8
    /* B0D4C 002B014C 0C0AB96B */  jal        dbgLinkSendByte
    /* B0D50 002B0150 308400FF */   andi      $a0, $a0, 0xFF
    /* B0D54 002B0154 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0D58 002B0158 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0D5C 002B015C 1440002A */  bnez       $v0, .L002B0208
    /* B0D60 002B0160 00000000 */   nop
    /* B0D64 002B0164 0C0AB96B */  jal        dbgLinkSendByte
    /* B0D68 002B0168 32A400FF */   andi      $a0, $s5, 0xFF
    /* B0D6C 002B016C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B0D70 002B0170 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B0D74 002B0174 14400024 */  bnez       $v0, .L002B0208
    /* B0D78 002B0178 00000000 */   nop
    /* B0D7C 002B017C 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B0D80 002B0180 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B0D84 002B0184 304200FB */  andi       $v0, $v0, 0xFB
    /* B0D88 002B0188 00409021 */  addu       $s2, $v0, $zero
    /* B0D8C 002B018C 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B0D90 002B0190 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B0194:
    /* B0D94 002B0194 0C0AF7A8 */  jal        osPiGetStatus
    /* B0D98 002B0198 00000000 */   nop
    /* B0D9C 002B019C 30420003 */  andi       $v0, $v0, 0x3
    /* B0DA0 002B01A0 1440FFFC */  bnez       $v0, .L002B0194
    /* B0DA4 002B01A4 24104E20 */   addiu     $s0, $zero, 0x4E20
    /* B0DA8 002B01A8 24140002 */  addiu      $s4, $zero, 0x2
    /* B0DAC 002B01AC 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B0DB0 002B01B0 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B0DB4 002B01B4 00009821 */  addu       $s3, $zero, $zero
    /* B0DB8 002B01B8 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B0DBC 002B01BC A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002B01C0:
    /* B0DC0 002B01C0 0C0AF7A8 */  jal        osPiGetStatus
    /* B0DC4 002B01C4 00000000 */   nop
    /* B0DC8 002B01C8 30420003 */  andi       $v0, $v0, 0x3
    /* B0DCC 002B01CC 1440FFFC */  bnez       $v0, .L002B01C0
    /* B0DD0 002B01D0 00000000 */   nop
    /* B0DD4 002B01D4 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B0DD8 002B01D8 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B0DDC 002B01DC 00541024 */  and        $v0, $v0, $s4
    /* B0DE0 002B01E0 10530009 */  beq        $v0, $s3, .L002B0208
    /* B0DE4 002B01E4 02001021 */   addu      $v0, $s0, $zero
    /* B0DE8 002B01E8 14400003 */  bnez       $v0, .L002B01F8
    /* B0DEC 002B01EC 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B0DF0 002B01F0 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B0DF4 002B01F4 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B01F8:
    /* B0DF8 002B01F8 1E20FFF1 */  bgtz       $s1, .L002B01C0
    /* B0DFC 002B01FC 24020001 */   addiu     $v0, $zero, 0x1
    /* B0E00 002B0200 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B0E04 002B0204 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B0208:
    /* B0E08 002B0208 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B0E0C 002B020C 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B0E10 002B0210 304200FB */  andi       $v0, $v0, 0xFB
    /* B0E14 002B0214 00408021 */  addu       $s0, $v0, $zero
    /* B0E18 002B0218 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B0E1C 002B021C A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B0220:
    /* B0E20 002B0220 0C0AF7A8 */  jal        osPiGetStatus
    /* B0E24 002B0224 00000000 */   nop
    /* B0E28 002B0228 30420003 */  andi       $v0, $v0, 0x3
    /* B0E2C 002B022C 1440FFFC */  bnez       $v0, .L002B0220
    /* B0E30 002B0230 00001021 */   addu      $v0, $zero, $zero
    /* B0E34 002B0234 8FBF0030 */  lw         $ra, 0x30($sp)
    /* B0E38 002B0238 8FB5002C */  lw         $s5, 0x2C($sp)
    /* B0E3C 002B023C 8FB40028 */  lw         $s4, 0x28($sp)
    /* B0E40 002B0240 8FB30024 */  lw         $s3, 0x24($sp)
    /* B0E44 002B0244 8FB20020 */  lw         $s2, 0x20($sp)
    /* B0E48 002B0248 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B0E4C 002B024C 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B0E50 002B0250 A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* B0E54 002B0254 8FB00018 */  lw         $s0, 0x18($sp)
    /* B0E58 002B0258 24030001 */  addiu      $v1, $zero, 0x1
    /* B0E5C 002B025C 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B0E60 002B0260 AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B0E64 002B0264 03E00008 */  jr         $ra
    /* B0E68 002B0268 27BD0038 */   addiu     $sp, $sp, 0x38
endlabel dbgHostFclose
