.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B4BD0-0x1B4F74 (VRAM 0x00446BD0) */
glabel func_00446BD0
    /* 1B4BD0 00446BD0 27BDFD68 */  addiu      $sp, $sp, -0x298
    /* 1B4BD4 00446BD4 AFB7028C */  sw         $s7, 0x28C($sp)
    /* 1B4BD8 00446BD8 8FB702A8 */  lw         $s7, 0x2A8($sp)
    /* 1B4BDC 00446BDC AFB10274 */  sw         $s1, 0x274($sp)
    /* 1B4BE0 00446BE0 8FB102AC */  lw         $s1, 0x2AC($sp)
    /* 1B4BE4 00446BE4 AFB3027C */  sw         $s3, 0x27C($sp)
    /* 1B4BE8 00446BE8 00809821 */  addu       $s3, $a0, $zero
    /* 1B4BEC 00446BEC AFB60288 */  sw         $s6, 0x288($sp)
    /* 1B4BF0 00446BF0 00E0B021 */  addu       $s6, $a3, $zero
    /* 1B4BF4 00446BF4 AFBE0290 */  sw         $fp, 0x290($sp)
    /* 1B4BF8 00446BF8 0000F021 */  addu       $fp, $zero, $zero
    /* 1B4BFC 00446BFC AFB00270 */  sw         $s0, 0x270($sp)
    /* 1B4C00 00446C00 A7A50250 */  sh         $a1, 0x250($sp)
    /* 1B4C04 00446C04 30B0FFFF */  andi       $s0, $a1, 0xFFFF
    /* 1B4C08 00446C08 AFBF0294 */  sw         $ra, 0x294($sp)
    /* 1B4C0C 00446C0C AFB50284 */  sw         $s5, 0x284($sp)
    /* 1B4C10 00446C10 AFB40280 */  sw         $s4, 0x280($sp)
    /* 1B4C14 00446C14 AFB20278 */  sw         $s2, 0x278($sp)
    /* 1B4C18 00446C18 AFA00254 */  sw         $zero, 0x254($sp)
    /* 1B4C1C 00446C1C A3A00258 */  sb         $zero, 0x258($sp)
    /* 1B4C20 00446C20 120000C7 */  beqz       $s0, .L00446F40
    /* 1B4C24 00446C24 AFA602A0 */   sw        $a2, 0x2A0($sp)
    /* 1B4C28 00446C28 10C000C5 */  beqz       $a2, .L00446F40
    /* 1B4C2C 00446C2C 262600FF */   addiu     $a2, $s1, 0xFF
    /* 1B4C30 00446C30 04C20001 */  bltzl      $a2, .L00446C38
    /* 1B4C34 00446C34 262601FE */   addiu     $a2, $s1, 0x1FE
  .L00446C38:
    /* 1B4C38 00446C38 8E620000 */  lw         $v0, 0x0($s3)
    /* 1B4C3C 00446C3C 30420001 */  andi       $v0, $v0, 0x1
    /* 1B4C40 00446C40 104000BF */  beqz       $v0, .L00446F40
    /* 1B4C44 00446C44 00069203 */   sra       $s2, $a2, 8
    /* 1B4C48 00446C48 0C112613 */  jal        func_0044984C
    /* 1B4C4C 00446C4C 02602021 */   addu      $a0, $s3, $zero
    /* 1B4C50 00446C50 24030002 */  addiu      $v1, $zero, 0x2
    /* 1B4C54 00446C54 104300B8 */  beq        $v0, $v1, .L00446F38
    /* 1B4C58 00446C58 02602021 */   addu      $a0, $s3, $zero
    /* 1B4C5C 00446C5C 02002821 */  addu       $a1, $s0, $zero
    /* 1B4C60 00446C60 8FA602A0 */  lw         $a2, 0x2A0($sp)
    /* 1B4C64 00446C64 8FA802B0 */  lw         $t0, 0x2B0($sp)
    /* 1B4C68 00446C68 02C03821 */  addu       $a3, $s6, $zero
    /* 1B4C6C 00446C6C AFB70010 */  sw         $s7, 0x10($sp)
    /* 1B4C70 00446C70 0C11234C */  jal        func_00448D30
    /* 1B4C74 00446C74 AFA80014 */   sw        $t0, 0x14($sp)
    /* 1B4C78 00446C78 00401821 */  addu       $v1, $v0, $zero
    /* 1B4C7C 00446C7C 10600003 */  beqz       $v1, .L00446C8C
    /* 1B4C80 00446C80 24020005 */   addiu     $v0, $zero, 0x5
    /* 1B4C84 00446C84 146200AF */  bne        $v1, $v0, .L00446F44
    /* 1B4C88 00446C88 00601021 */   addu      $v0, $v1, $zero
  .L00446C8C:
    /* 1B4C8C 00446C8C 8FA802B0 */  lw         $t0, 0x2B0($sp)
    /* 1B4C90 00446C90 8D030000 */  lw         $v1, 0x0($t0)
    /* 1B4C94 00446C94 2402FFFF */  addiu      $v0, $zero, -0x1
    /* 1B4C98 00446C98 146200AA */  bne        $v1, $v0, .L00446F44
    /* 1B4C9C 00446C9C 24020009 */   addiu     $v0, $zero, 0x9
    /* 1B4CA0 00446CA0 02602021 */  addu       $a0, $s3, $zero
    /* 1B4CA4 00446CA4 0C111E2C */  jal        func_004478B0
    /* 1B4CA8 00446CA8 27A50240 */   addiu     $a1, $sp, 0x240
    /* 1B4CAC 00446CAC 8FA20240 */  lw         $v0, 0x240($sp)
    /* 1B4CB0 00446CB0 0051102A */  slt        $v0, $v0, $s1
    /* 1B4CB4 00446CB4 144000A3 */  bnez       $v0, .L00446F44
    /* 1B4CB8 00446CB8 24020007 */   addiu     $v0, $zero, 0x7
    /* 1B4CBC 00446CBC 124000A0 */  beqz       $s2, .L00446F40
    /* 1B4CC0 00446CC0 02602021 */   addu      $a0, $s3, $zero
    /* 1B4CC4 00446CC4 00002821 */  addu       $a1, $zero, $zero
    /* 1B4CC8 00446CC8 00A03021 */  addu       $a2, $a1, $zero
    /* 1B4CCC 00446CCC 8FA802B0 */  lw         $t0, 0x2B0($sp)
    /* 1B4CD0 00446CD0 00A03821 */  addu       $a3, $a1, $zero
    /* 1B4CD4 00446CD4 AFA00010 */  sw         $zero, 0x10($sp)
    /* 1B4CD8 00446CD8 0C11234C */  jal        func_00448D30
    /* 1B4CDC 00446CDC AFA80014 */   sw        $t0, 0x14($sp)
    /* 1B4CE0 00446CE0 00401821 */  addu       $v1, $v0, $zero
    /* 1B4CE4 00446CE4 10600003 */  beqz       $v1, .L00446CF4
    /* 1B4CE8 00446CE8 24020005 */   addiu     $v0, $zero, 0x5
    /* 1B4CEC 00446CEC 14620095 */  bne        $v1, $v0, .L00446F44
    /* 1B4CF0 00446CF0 00601021 */   addu      $v0, $v1, $zero
  .L00446CF4:
    /* 1B4CF4 00446CF4 8FA802B0 */  lw         $t0, 0x2B0($sp)
    /* 1B4CF8 00446CF8 8D030000 */  lw         $v1, 0x0($t0)
    /* 1B4CFC 00446CFC 2402FFFF */  addiu      $v0, $zero, -0x1
    /* 1B4D00 00446D00 14620005 */  bne        $v1, $v0, .L00446D18
    /* 1B4D04 00446D04 24020008 */   addiu     $v0, $zero, 0x8
    /* 1B4D08 00446D08 08111BD1 */  j          .L00446F44
    /* 1B4D0C 00446D0C 00000000 */   nop
  .L00446D10:
    /* 1B4D10 00446D10 08111B92 */  j          .L00446E48
    /* 1B4D14 00446D14 00009021 */   addu      $s2, $zero, $zero
  .L00446D18:
    /* 1B4D18 00446D18 92620064 */  lbu        $v0, 0x64($s3)
    /* 1B4D1C 00446D1C 1040004A */  beqz       $v0, .L00446E48
    /* 1B4D20 00446D20 00008821 */   addu      $s1, $zero, $zero
    /* 1B4D24 00446D24 27B50244 */  addiu      $s5, $sp, 0x244
    /* 1B4D28 00446D28 27B40120 */  addiu      $s4, $sp, 0x120
    /* 1B4D2C 00446D2C 27A80020 */  addiu      $t0, $sp, 0x20
    /* 1B4D30 00446D30 AFA8026C */  sw         $t0, 0x26C($sp)
    /* 1B4D34 00446D34 02602021 */  addu       $a0, $s3, $zero
  .L00446D38:
    /* 1B4D38 00446D38 27A50020 */  addiu      $a1, $sp, 0x20
    /* 1B4D3C 00446D3C 00003021 */  addu       $a2, $zero, $zero
    /* 1B4D40 00446D40 323000FF */  andi       $s0, $s1, 0xFF
    /* 1B4D44 00446D44 0C11253D */  jal        func_004494F4
    /* 1B4D48 00446D48 02003821 */   addu      $a3, $s0, $zero
    /* 1B4D4C 00446D4C 00401821 */  addu       $v1, $v0, $zero
    /* 1B4D50 00446D50 14600079 */  bnez       $v1, .L00446F38
    /* 1B4D54 00446D54 02602021 */   addu      $a0, $s3, $zero
    /* 1B4D58 00446D58 27A50020 */  addiu      $a1, $sp, 0x20
    /* 1B4D5C 00446D5C 02403021 */  addu       $a2, $s2, $zero
    /* 1B4D60 00446D60 02A03821 */  addu       $a3, $s5, $zero
    /* 1B4D64 00446D64 27A20248 */  addiu      $v0, $sp, 0x248
    /* 1B4D68 00446D68 AFA20014 */  sw         $v0, 0x14($sp)
    /* 1B4D6C 00446D6C 27A2024C */  addiu      $v0, $sp, 0x24C
    /* 1B4D70 00446D70 AFB00010 */  sw         $s0, 0x10($sp)
    /* 1B4D74 00446D74 0C111BDD */  jal        func_00446F74
    /* 1B4D78 00446D78 AFA20018 */   sw        $v0, 0x18($sp)
    /* 1B4D7C 00446D7C 00401821 */  addu       $v1, $v0, $zero
    /* 1B4D80 00446D80 1460006D */  bnez       $v1, .L00446F38
    /* 1B4D84 00446D84 2402FFFF */   addiu     $v0, $zero, -0x1
    /* 1B4D88 00446D88 8FA30244 */  lw         $v1, 0x244($sp)
    /* 1B4D8C 00446D8C 50620029 */  beql       $v1, $v0, .L00446E34
    /* 1B4D90 00446D90 26310001 */   addiu     $s1, $s1, 0x1
    /* 1B4D94 00446D94 13C00010 */  beqz       $fp, .L00446DD8
    /* 1B4D98 00446D98 24060001 */   addiu     $a2, $zero, 0x1
    /* 1B4D9C 00446D9C 02602021 */  addu       $a0, $s3, $zero
    /* 1B4DA0 00446DA0 8FA80254 */  lw         $t0, 0x254($sp)
    /* 1B4DA4 00446DA4 00C81004 */  sllv       $v0, $t0, $a2
    /* 1B4DA8 00446DA8 02821021 */  addu       $v0, $s4, $v0
    /* 1B4DAC 00446DAC A0510000 */  sb         $s1, 0x0($v0)
    /* 1B4DB0 00446DB0 92A30003 */  lbu        $v1, 0x3($s5)
    /* 1B4DB4 00446DB4 93A70258 */  lbu        $a3, 0x258($sp)
    /* 1B4DB8 00446DB8 02802821 */  addu       $a1, $s4, $zero
    /* 1B4DBC 00446DBC 0C11253D */  jal        func_004494F4
    /* 1B4DC0 00446DC0 A0430001 */   sb        $v1, 0x1($v0)
    /* 1B4DC4 00446DC4 00401821 */  addu       $v1, $v0, $zero
    /* 1B4DC8 00446DC8 10600008 */  beqz       $v1, .L00446DEC
    /* 1B4DCC 00446DCC 00002821 */   addu      $a1, $zero, $zero
    /* 1B4DD0 00446DD0 08111BD1 */  j          .L00446F44
    /* 1B4DD4 00446DD4 00000000 */   nop
  .L00446DD8:
    /* 1B4DD8 00446DD8 92A30003 */  lbu        $v1, 0x3($s5)
    /* 1B4DDC 00446DDC 00111200 */  sll        $v0, $s1, 8
    /* 1B4DE0 00446DE0 00431025 */  or         $v0, $v0, $v1
    /* 1B4DE4 00446DE4 A7A20266 */  sh         $v0, 0x266($sp)
    /* 1B4DE8 00446DE8 00002821 */  addu       $a1, $zero, $zero
  .L00446DEC:
    /* 1B4DEC 00446DEC 02802021 */  addu       $a0, $s4, $zero
    /* 1B4DF0 00446DF0 8FA3026C */  lw         $v1, 0x26C($sp)
  .L00446DF4:
    /* 1B4DF4 00446DF4 94620000 */  lhu        $v0, 0x0($v1)
    /* 1B4DF8 00446DF8 24630002 */  addiu      $v1, $v1, 0x2
    /* 1B4DFC 00446DFC 24A50001 */  addiu      $a1, $a1, 0x1
    /* 1B4E00 00446E00 A4820000 */  sh         $v0, 0x0($a0)
    /* 1B4E04 00446E04 28A20080 */  slti       $v0, $a1, 0x80
    /* 1B4E08 00446E08 1440FFFA */  bnez       $v0, .L00446DF4
    /* 1B4E0C 00446E0C 24840002 */   addiu     $a0, $a0, 0x2
    /* 1B4E10 00446E10 8FA30248 */  lw         $v1, 0x248($sp)
    /* 1B4E14 00446E14 8FA8024C */  lw         $t0, 0x24C($sp)
    /* 1B4E18 00446E18 27DE0001 */  addiu      $fp, $fp, 0x1
    /* 1B4E1C 00446E1C A3B10258 */  sb         $s1, 0x258($sp)
    /* 1B4E20 00446E20 0072102A */  slt        $v0, $v1, $s2
    /* 1B4E24 00446E24 1040FFBA */  beqz       $v0, .L00446D10
    /* 1B4E28 00446E28 AFA80254 */   sw        $t0, 0x254($sp)
    /* 1B4E2C 00446E2C 02439023 */  subu       $s2, $s2, $v1
    /* 1B4E30 00446E30 26310001 */  addiu      $s1, $s1, 0x1
  .L00446E34:
    /* 1B4E34 00446E34 92630064 */  lbu        $v1, 0x64($s3)
    /* 1B4E38 00446E38 322200FF */  andi       $v0, $s1, 0xFF
    /* 1B4E3C 00446E3C 0043102B */  sltu       $v0, $v0, $v1
    /* 1B4E40 00446E40 5440FFBD */  bnel       $v0, $zero, .L00446D38
    /* 1B4E44 00446E44 02602021 */   addu      $a0, $s3, $zero
  .L00446E48:
    /* 1B4E48 00446E48 1E40003E */  bgtz       $s2, .L00446F44
    /* 1B4E4C 00446E4C 24020003 */   addiu     $v0, $zero, 0x3
    /* 1B4E50 00446E50 8FA30244 */  lw         $v1, 0x244($sp)
    /* 1B4E54 00446E54 2402FFFF */  addiu      $v0, $zero, -0x1
    /* 1B4E58 00446E58 14620003 */  bne        $v1, $v0, .L00446E68
    /* 1B4E5C 00446E5C 27A50120 */   addiu     $a1, $sp, 0x120
    /* 1B4E60 00446E60 08111BD1 */  j          .L00446F44
    /* 1B4E64 00446E64 24020003 */   addiu     $v0, $zero, 0x3
  .L00446E68:
    /* 1B4E68 00446E68 8FA80254 */  lw         $t0, 0x254($sp)
    /* 1B4E6C 00446E6C 24060001 */  addiu      $a2, $zero, 0x1
    /* 1B4E70 00446E70 00C81004 */  sllv       $v0, $t0, $a2
    /* 1B4E74 00446E74 00A21821 */  addu       $v1, $a1, $v0
    /* 1B4E78 00446E78 A0710000 */  sb         $s1, 0x0($v1)
    /* 1B4E7C 00446E7C 93A20247 */  lbu        $v0, 0x247($sp)
    /* 1B4E80 00446E80 93A70258 */  lbu        $a3, 0x258($sp)
    /* 1B4E84 00446E84 02602021 */  addu       $a0, $s3, $zero
    /* 1B4E88 00446E88 0C11253D */  jal        func_004494F4
    /* 1B4E8C 00446E8C A0620001 */   sb        $v0, 0x1($v1)
    /* 1B4E90 00446E90 00401821 */  addu       $v1, $v0, $zero
    /* 1B4E94 00446E94 1460002B */  bnez       $v1, .L00446F44
    /* 1B4E98 00446E98 00002821 */   addu      $a1, $zero, $zero
    /* 1B4E9C 00446E9C 97A80266 */  lhu        $t0, 0x266($sp)
    /* 1B4EA0 00446EA0 A7A80226 */  sh         $t0, 0x226($sp)
    /* 1B4EA4 00446EA4 97A80250 */  lhu        $t0, 0x250($sp)
    /* 1B4EA8 00446EA8 A7A80224 */  sh         $t0, 0x224($sp)
    /* 1B4EAC 00446EAC 8FA802A0 */  lw         $t0, 0x2A0($sp)
    /* 1B4EB0 00446EB0 27A40220 */  addiu      $a0, $sp, 0x220
    /* 1B4EB4 00446EB4 A7A0022A */  sh         $zero, 0x22A($sp)
    /* 1B4EB8 00446EB8 AFA80220 */  sw         $t0, 0x220($sp)
  .L00446EBC:
    /* 1B4EBC 00446EBC 92C30000 */  lbu        $v1, 0x0($s6)
    /* 1B4EC0 00446EC0 00851021 */  addu       $v0, $a0, $a1
    /* 1B4EC4 00446EC4 24A50001 */  addiu      $a1, $a1, 0x1
    /* 1B4EC8 00446EC8 A0430010 */  sb         $v1, 0x10($v0)
    /* 1B4ECC 00446ECC 28A20010 */  slti       $v0, $a1, 0x10
    /* 1B4ED0 00446ED0 1440FFFA */  bnez       $v0, .L00446EBC
    /* 1B4ED4 00446ED4 26D60001 */   addiu     $s6, $s6, 0x1
    /* 1B4ED8 00446ED8 00002821 */  addu       $a1, $zero, $zero
    /* 1B4EDC 00446EDC 27A40220 */  addiu      $a0, $sp, 0x220
  .L00446EE0:
    /* 1B4EE0 00446EE0 92E30000 */  lbu        $v1, 0x0($s7)
    /* 1B4EE4 00446EE4 00851021 */  addu       $v0, $a0, $a1
    /* 1B4EE8 00446EE8 24A50001 */  addiu      $a1, $a1, 0x1
    /* 1B4EEC 00446EEC A043000C */  sb         $v1, 0xC($v0)
    /* 1B4EF0 00446EF0 28A20004 */  slti       $v0, $a1, 0x4
    /* 1B4EF4 00446EF4 1440FFFA */  bnez       $v0, .L00446EE0
    /* 1B4EF8 00446EF8 26F70001 */   addiu     $s7, $s7, 0x1
    /* 1B4EFC 00446EFC 8FA802B0 */  lw         $t0, 0x2B0($sp)
    /* 1B4F00 00446F00 9666005E */  lhu        $a2, 0x5E($s3)
    /* 1B4F04 00446F04 95020002 */  lhu        $v0, 0x2($t0)
    /* 1B4F08 00446F08 27A70220 */  addiu      $a3, $sp, 0x220
    /* 1B4F0C 00446F0C AFA00010 */  sw         $zero, 0x10($sp)
    /* 1B4F10 00446F10 8E640004 */  lw         $a0, 0x4($s3)
    /* 1B4F14 00446F14 8E650008 */  lw         $a1, 0x8($s3)
    /* 1B4F18 00446F18 00C23021 */  addu       $a2, $a2, $v0
    /* 1B4F1C 00446F1C 0C0AF654 */  jal        __osContRamWrite
    /* 1B4F20 00446F20 30C6FFFF */   andi      $a2, $a2, 0xFFFF
    /* 1B4F24 00446F24 00401821 */  addu       $v1, $v0, $zero
    /* 1B4F28 00446F28 50600006 */  beql       $v1, $zero, .L00446F44
    /* 1B4F2C 00446F2C 00001021 */   addu      $v0, $zero, $zero
    /* 1B4F30 00446F30 08111BD1 */  j          .L00446F44
    /* 1B4F34 00446F34 00000000 */   nop
  .L00446F38:
    /* 1B4F38 00446F38 08111BD1 */  j          .L00446F44
    /* 1B4F3C 00446F3C 00601021 */   addu      $v0, $v1, $zero
  .L00446F40:
    /* 1B4F40 00446F40 24020005 */  addiu      $v0, $zero, 0x5
  .L00446F44:
    /* 1B4F44 00446F44 8FBF0294 */  lw         $ra, 0x294($sp)
    /* 1B4F48 00446F48 8FBE0290 */  lw         $fp, 0x290($sp)
    /* 1B4F4C 00446F4C 8FB7028C */  lw         $s7, 0x28C($sp)
    /* 1B4F50 00446F50 8FB60288 */  lw         $s6, 0x288($sp)
    /* 1B4F54 00446F54 8FB50284 */  lw         $s5, 0x284($sp)
    /* 1B4F58 00446F58 8FB40280 */  lw         $s4, 0x280($sp)
    /* 1B4F5C 00446F5C 8FB3027C */  lw         $s3, 0x27C($sp)
    /* 1B4F60 00446F60 8FB20278 */  lw         $s2, 0x278($sp)
    /* 1B4F64 00446F64 8FB10274 */  lw         $s1, 0x274($sp)
    /* 1B4F68 00446F68 8FB00270 */  lw         $s0, 0x270($sp)
    /* 1B4F6C 00446F6C 03E00008 */  jr         $ra
    /* 1B4F70 00446F70 27BD0298 */   addiu     $sp, $sp, 0x298
endlabel func_00446BD0
