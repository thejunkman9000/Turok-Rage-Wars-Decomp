.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC4C74-0xC5078 (VRAM 0x002C4074) */
glabel func_002C4074
    /* C4C74 002C4074 27BDFFA8 */  addiu      $sp, $sp, -0x58
    /* C4C78 002C4078 00805021 */  addu       $t2, $a0, $zero
    /* C4C7C 002C407C 00A04821 */  addu       $t1, $a1, $zero
    /* C4C80 002C4080 AFB50044 */  sw         $s5, 0x44($sp)
    /* C4C84 002C4084 0000A821 */  addu       $s5, $zero, $zero
    /* C4C88 002C4088 AFB20038 */  sw         $s2, 0x38($sp)
    /* C4C8C 002C408C 02A09021 */  addu       $s2, $s5, $zero
    /* C4C90 002C4090 00E04021 */  addu       $t0, $a3, $zero
    /* C4C94 002C4094 AFB10034 */  sw         $s1, 0x34($sp)
    /* C4C98 002C4098 00061400 */  sll        $v0, $a2, 16
    /* C4C9C 002C409C AFBF0054 */  sw         $ra, 0x54($sp)
    /* C4CA0 002C40A0 AFBE0050 */  sw         $fp, 0x50($sp)
    /* C4CA4 002C40A4 AFB7004C */  sw         $s7, 0x4C($sp)
    /* C4CA8 002C40A8 AFB60048 */  sw         $s6, 0x48($sp)
    /* C4CAC 002C40AC AFB40040 */  sw         $s4, 0x40($sp)
    /* C4CB0 002C40B0 AFB3003C */  sw         $s3, 0x3C($sp)
    /* C4CB4 002C40B4 AFB00030 */  sw         $s0, 0x30($sp)
    /* C4CB8 002C40B8 A5000000 */  sh         $zero, 0x0($t0)
    /* C4CBC 002C40BC 8D530010 */  lw         $s3, 0x10($t2)
    /* C4CC0 002C40C0 00021C03 */  sra        $v1, $v0, 16
    /* C4CC4 002C40C4 8E740020 */  lw         $s4, 0x20($s3)
    /* C4CC8 002C40C8 186000DD */  blez       $v1, .L002C4440
    /* C4CCC 002C40CC 02A08821 */   addu      $s1, $s5, $zero
    /* C4CD0 002C40D0 3C1E800E */  lui        $fp, %hi(D_800D94EC)
    /* C4CD4 002C40D4 27DE94EC */  addiu      $fp, $fp, %lo(D_800D94EC)
    /* C4CD8 002C40D8 3C17800E */  lui        $s7, %hi(D_800D94EA)
    /* C4CDC 002C40DC 26F794EA */  addiu      $s7, $s7, %lo(D_800D94EA)
    /* C4CE0 002C40E0 AFA20018 */  sw         $v0, 0x18($sp)
    /* C4CE4 002C40E4 0060B021 */  addu       $s6, $v1, $zero
  .L002C40E8:
    /* C4CE8 002C40E8 97C30000 */  lhu        $v1, 0x0($fp)
    /* C4CEC 002C40EC 106000B9 */  beqz       $v1, .L002C43D4
    /* C4CF0 002C40F0 2463FFFF */   addiu     $v1, $v1, -0x1
    /* C4CF4 002C40F4 96E20000 */  lhu        $v0, 0x0($s7)
    /* C4CF8 002C40F8 A7C30000 */  sh         $v1, 0x0($fp)
    /* C4CFC 002C40FC 30438000 */  andi       $v1, $v0, 0x8000
    /* C4D00 002C4100 00021040 */  sll        $v0, $v0, 1
    /* C4D04 002C4104 10600007 */  beqz       $v1, .L002C4124
    /* C4D08 002C4108 A6E20000 */   sh        $v0, 0x0($s7)
    /* C4D0C 002C410C 00151400 */  sll        $v0, $s5, 16
    /* C4D10 002C4110 00021383 */  sra        $v0, $v0, 14
    /* C4D14 002C4114 00541021 */  addu       $v0, $v0, $s4
    /* C4D18 002C4118 94440002 */  lhu        $a0, 0x2($v0)
    /* C4D1C 002C411C 080B104E */  j          .L002C4138
    /* C4D20 002C4120 00041400 */   sll       $v0, $a0, 16
  .L002C4124:
    /* C4D24 002C4124 00151400 */  sll        $v0, $s5, 16
    /* C4D28 002C4128 00021383 */  sra        $v0, $v0, 14
    /* C4D2C 002C412C 00541021 */  addu       $v0, $v0, $s4
    /* C4D30 002C4130 94440000 */  lhu        $a0, 0x0($v0)
    /* C4D34 002C4134 00041400 */  sll        $v0, $a0, 16
  .L002C4138:
    /* C4D38 002C4138 00021383 */  sra        $v0, $v0, 14
    /* C4D3C 002C413C 00542821 */  addu       $a1, $v0, $s4
    /* C4D40 002C4140 94A30000 */  lhu        $v1, 0x0($a1)
    /* C4D44 002C4144 24020800 */  addiu      $v0, $zero, 0x800
    /* C4D48 002C4148 146200B8 */  bne        $v1, $v0, .L002C442C
    /* C4D4C 002C414C 0080A821 */   addu      $s5, $a0, $zero
    /* C4D50 002C4150 94B00002 */  lhu        $s0, 0x2($a1)
    /* C4D54 002C4154 32040F00 */  andi       $a0, $s0, 0xF00
    /* C4D58 002C4158 10800004 */  beqz       $a0, .L002C416C
    /* C4D5C 002C415C 0000A821 */   addu      $s5, $zero, $zero
    /* C4D60 002C4160 24020F00 */  addiu      $v0, $zero, 0xF00
    /* C4D64 002C4164 14820007 */  bne        $a0, $v0, .L002C4184
    /* C4D68 002C4168 00101400 */   sll       $v0, $s0, 16
  .L002C416C:
    /* C4D6C 002C416C 00111400 */  sll        $v0, $s1, 16
    /* C4D70 002C4170 000213C3 */  sra        $v0, $v0, 15
    /* C4D74 002C4174 00491021 */  addu       $v0, $v0, $t1
    /* C4D78 002C4178 A4500000 */  sh         $s0, 0x0($v0)
    /* C4D7C 002C417C 080B10D9 */  j          .L002C4364
    /* C4D80 002C4180 26310001 */   addiu     $s1, $s1, 0x1
  .L002C4184:
    /* C4D84 002C4184 00021403 */  sra        $v0, $v0, 16
    /* C4D88 002C4188 24030900 */  addiu      $v1, $zero, 0x900
    /* C4D8C 002C418C 14430020 */  bne        $v0, $v1, .L002C4210
    /* C4D90 002C4190 24020A00 */   addiu     $v0, $zero, 0xA00
    /* C4D94 002C4194 02E02021 */  addu       $a0, $s7, $zero
    /* C4D98 002C4198 24060001 */  addiu      $a2, $zero, 0x1
    /* C4D9C 002C419C 96F00000 */  lhu        $s0, 0x0($s7)
    /* C4DA0 002C41A0 9665000E */  lhu        $a1, 0xE($s3)
    /* C4DA4 002C41A4 8FAB0068 */  lw         $t3, 0x68($sp)
    /* C4DA8 002C41A8 00003821 */  addu       $a3, $zero, $zero
    /* C4DAC 002C41AC AFA80020 */  sw         $t0, 0x20($sp)
    /* C4DB0 002C41B0 AFA90024 */  sw         $t1, 0x24($sp)
    /* C4DB4 002C41B4 AFAA0028 */  sw         $t2, 0x28($sp)
    /* C4DB8 002C41B8 0C0B0FA8 */  jal        func_002C3EA0
    /* C4DBC 002C41BC AFAB0010 */   sw        $t3, 0x10($sp)
    /* C4DC0 002C41C0 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C4DC4 002C41C4 8FA80020 */  lw         $t0, 0x20($sp)
    /* C4DC8 002C41C8 8FA90024 */  lw         $t1, 0x24($sp)
    /* C4DCC 002C41CC 8FAA0028 */  lw         $t2, 0x28($sp)
    /* C4DD0 002C41D0 10400091 */  beqz       $v0, .L002C4418
    /* C4DD4 002C41D4 00112400 */   sll       $a0, $s1, 16
    /* C4DD8 002C41D8 26310001 */  addiu      $s1, $s1, 0x1
    /* C4DDC 002C41DC 24020010 */  addiu      $v0, $zero, 0x10
    /* C4DE0 002C41E0 000423C3 */  sra        $a0, $a0, 15
    /* C4DE4 002C41E4 00892021 */  addu       $a0, $a0, $t1
    /* C4DE8 002C41E8 3C05800E */  lui        $a1, %hi(D_800D94EC)
    /* C4DEC 002C41EC 94A594EC */  lhu        $a1, %lo(D_800D94EC)($a1)
    /* C4DF0 002C41F0 96E30000 */  lhu        $v1, 0x0($s7)
    /* C4DF4 002C41F4 00451023 */  subu       $v0, $v0, $a1
    /* C4DF8 002C41F8 00431004 */  sllv       $v0, $v1, $v0
    /* C4DFC 002C41FC 00A31807 */  srav       $v1, $v1, $a1
    /* C4E00 002C4200 02031825 */  or         $v1, $s0, $v1
    /* C4E04 002C4204 A6E20000 */  sh         $v0, 0x0($s7)
    /* C4E08 002C4208 080B10D9 */  j          .L002C4364
    /* C4E0C 002C420C A4830000 */   sh        $v1, 0x0($a0)
  .L002C4210:
    /* C4E10 002C4210 14820023 */  bne        $a0, $v0, .L002C42A0
    /* C4E14 002C4214 24020B00 */   addiu     $v0, $zero, 0xB00
    /* C4E18 002C4218 00003021 */  addu       $a2, $zero, $zero
    /* C4E1C 002C421C 320300FF */  andi       $v1, $s0, 0xFF
    /* C4E20 002C4220 000310C0 */  sll        $v0, $v1, 3
    /* C4E24 002C4224 00431023 */  subu       $v0, $v0, $v1
    /* C4E28 002C4228 000210C0 */  sll        $v0, $v0, 3
    /* C4E2C 002C422C 00431023 */  subu       $v0, $v0, $v1
    /* C4E30 002C4230 000210C0 */  sll        $v0, $v0, 3
    /* C4E34 002C4234 00111C00 */  sll        $v1, $s1, 16
    /* C4E38 002C4238 8E64001C */  lw         $a0, 0x1C($s3)
    /* C4E3C 002C423C 00031BC3 */  sra        $v1, $v1, 15
    /* C4E40 002C4240 00442821 */  addu       $a1, $v0, $a0
    /* C4E44 002C4244 8CA201A0 */  lw         $v0, 0x1A0($a1)
    /* C4E48 002C4248 18400011 */  blez       $v0, .L002C4290
    /* C4E4C 002C424C 00693821 */   addu      $a3, $v1, $t1
    /* C4E50 002C4250 00061400 */  sll        $v0, $a2, 16
  .L002C4254:
    /* C4E54 002C4254 24C30001 */  addiu      $v1, $a2, 0x1
    /* C4E58 002C4258 00603021 */  addu       $a2, $v1, $zero
    /* C4E5C 002C425C 00021403 */  sra        $v0, $v0, 16
    /* C4E60 002C4260 00022040 */  sll        $a0, $v0, 1
    /* C4E64 002C4264 00021080 */  sll        $v0, $v0, 2
    /* C4E68 002C4268 00A21021 */  addu       $v0, $a1, $v0
    /* C4E6C 002C426C 00872021 */  addu       $a0, $a0, $a3
    /* C4E70 002C4270 944200A2 */  lhu        $v0, 0xA2($v0)
    /* C4E74 002C4274 00031C00 */  sll        $v1, $v1, 16
    /* C4E78 002C4278 A4820000 */  sh         $v0, 0x0($a0)
    /* C4E7C 002C427C 8CA201A0 */  lw         $v0, 0x1A0($a1)
    /* C4E80 002C4280 00031C03 */  sra        $v1, $v1, 16
    /* C4E84 002C4284 0062182A */  slt        $v1, $v1, $v0
    /* C4E88 002C4288 1460FFF2 */  bnez       $v1, .L002C4254
    /* C4E8C 002C428C 00061400 */   sll       $v0, $a2, 16
  .L002C4290:
    /* C4E90 002C4290 00061400 */  sll        $v0, $a2, 16
    /* C4E94 002C4294 00021403 */  sra        $v0, $v0, 16
    /* C4E98 002C4298 080B10D9 */  j          .L002C4364
    /* C4E9C 002C429C 02228821 */   addu      $s1, $s1, $v0
  .L002C42A0:
    /* C4EA0 002C42A0 14820031 */  bne        $a0, $v0, .L002C4368
    /* C4EA4 002C42A4 00112400 */   sll       $a0, $s1, 16
    /* C4EA8 002C42A8 00111400 */  sll        $v0, $s1, 16
    /* C4EAC 002C42AC 00021403 */  sra        $v0, $v0, 16
    /* C4EB0 002C42B0 0056102A */  slt        $v0, $v0, $s6
    /* C4EB4 002C42B4 1040000F */  beqz       $v0, .L002C42F4
    /* C4EB8 002C42B8 00121C00 */   sll       $v1, $s2, 16
    /* C4EBC 002C42BC 8FAB0018 */  lw         $t3, 0x18($sp)
    /* C4EC0 002C42C0 000B2403 */  sra        $a0, $t3, 16
  .L002C42C4:
    /* C4EC4 002C42C4 02201021 */  addu       $v0, $s1, $zero
    /* C4EC8 002C42C8 24430001 */  addiu      $v1, $v0, 0x1
    /* C4ECC 002C42CC 00608821 */  addu       $s1, $v1, $zero
    /* C4ED0 002C42D0 00021400 */  sll        $v0, $v0, 16
    /* C4ED4 002C42D4 000213C3 */  sra        $v0, $v0, 15
    /* C4ED8 002C42D8 00491021 */  addu       $v0, $v0, $t1
    /* C4EDC 002C42DC 00031C00 */  sll        $v1, $v1, 16
    /* C4EE0 002C42E0 00031C03 */  sra        $v1, $v1, 16
    /* C4EE4 002C42E4 0064182A */  slt        $v1, $v1, $a0
    /* C4EE8 002C42E8 1460FFF6 */  bnez       $v1, .L002C42C4
    /* C4EEC 002C42EC A4400000 */   sh        $zero, 0x0($v0)
    /* C4EF0 002C42F0 00121C00 */  sll        $v1, $s2, 16
  .L002C42F4:
    /* C4EF4 002C42F4 00031C03 */  sra        $v1, $v1, 16
    /* C4EF8 002C42F8 00031080 */  sll        $v0, $v1, 2
    /* C4EFC 002C42FC 00431021 */  addu       $v0, $v0, $v1
    /* C4F00 002C4300 00021080 */  sll        $v0, $v0, 2
    /* C4F04 002C4304 004A1021 */  addu       $v0, $v0, $t2
    /* C4F08 002C4308 8C430004 */  lw         $v1, 0x4($v0)
    /* C4F0C 002C430C 8C420008 */  lw         $v0, 0x8($v0)
    /* C4F10 002C4310 080B10D3 */  j          .L002C434C
    /* C4F14 002C4314 00621821 */   addu      $v1, $v1, $v0
  .L002C4318:
    /* C4F18 002C4318 00041C00 */  sll        $v1, $a0, 16
    /* C4F1C 002C431C 95020000 */  lhu        $v0, 0x0($t0)
    /* C4F20 002C4320 00031C03 */  sra        $v1, $v1, 16
    /* C4F24 002C4324 24420001 */  addiu      $v0, $v0, 0x1
    /* C4F28 002C4328 A5020000 */  sh         $v0, 0x0($t0)
    /* C4F2C 002C432C 00031080 */  sll        $v0, $v1, 2
    /* C4F30 002C4330 00431021 */  addu       $v0, $v0, $v1
    /* C4F34 002C4334 00021080 */  sll        $v0, $v0, 2
    /* C4F38 002C4338 004A1021 */  addu       $v0, $v0, $t2
    /* C4F3C 002C433C 8C430004 */  lw         $v1, 0x4($v0)
    /* C4F40 002C4340 8C420008 */  lw         $v0, 0x8($v0)
    /* C4F44 002C4344 00809021 */  addu       $s2, $a0, $zero
    /* C4F48 002C4348 00621821 */  addu       $v1, $v1, $v0
  .L002C434C:
    /* C4F4C 002C434C 02C3182A */  slt        $v1, $s6, $v1
    /* C4F50 002C4350 1060FFF1 */  beqz       $v1, .L002C4318
    /* C4F54 002C4354 26440001 */   addiu     $a0, $s2, 0x1
    /* C4F58 002C4358 8FAB0018 */  lw         $t3, 0x18($sp)
    /* C4F5C 002C435C 080B1112 */  j          .L002C4448
    /* C4F60 002C4360 000B1403 */   sra       $v0, $t3, 16
  .L002C4364:
    /* C4F64 002C4364 00112400 */  sll        $a0, $s1, 16
  .L002C4368:
    /* C4F68 002C4368 00121C00 */  sll        $v1, $s2, 16
    /* C4F6C 002C436C 00031C03 */  sra        $v1, $v1, 16
    /* C4F70 002C4370 00031080 */  sll        $v0, $v1, 2
    /* C4F74 002C4374 00431021 */  addu       $v0, $v0, $v1
    /* C4F78 002C4378 00021080 */  sll        $v0, $v0, 2
    /* C4F7C 002C437C 004A1021 */  addu       $v0, $v0, $t2
    /* C4F80 002C4380 8C430004 */  lw         $v1, 0x4($v0)
    /* C4F84 002C4384 8C420008 */  lw         $v0, 0x8($v0)
    /* C4F88 002C4388 00042403 */  sra        $a0, $a0, 16
    /* C4F8C 002C438C 00621821 */  addu       $v1, $v1, $v0
    /* C4F90 002C4390 0083202A */  slt        $a0, $a0, $v1
    /* C4F94 002C4394 14800026 */  bnez       $a0, .L002C4430
    /* C4F98 002C4398 00111400 */   sll       $v0, $s1, 16
    /* C4F9C 002C439C 26440001 */  addiu      $a0, $s2, 0x1
    /* C4FA0 002C43A0 00041C00 */  sll        $v1, $a0, 16
    /* C4FA4 002C43A4 95020000 */  lhu        $v0, 0x0($t0)
    /* C4FA8 002C43A8 00031C03 */  sra        $v1, $v1, 16
    /* C4FAC 002C43AC 24420001 */  addiu      $v0, $v0, 0x1
    /* C4FB0 002C43B0 A5020000 */  sh         $v0, 0x0($t0)
    /* C4FB4 002C43B4 00031080 */  sll        $v0, $v1, 2
    /* C4FB8 002C43B8 00431021 */  addu       $v0, $v0, $v1
    /* C4FBC 002C43BC 00021080 */  sll        $v0, $v0, 2
    /* C4FC0 002C43C0 004A1021 */  addu       $v0, $v0, $t2
    /* C4FC4 002C43C4 8C530010 */  lw         $s3, 0x10($v0)
    /* C4FC8 002C43C8 8E740020 */  lw         $s4, 0x20($s3)
    /* C4FCC 002C43CC 080B110B */  j          .L002C442C
    /* C4FD0 002C43D0 00809021 */   addu      $s2, $a0, $zero
  .L002C43D4:
    /* C4FD4 002C43D4 3C04800E */  lui        $a0, %hi(D_800D94EA)
    /* C4FD8 002C43D8 248494EA */  addiu      $a0, $a0, %lo(D_800D94EA)
    /* C4FDC 002C43DC 24050010 */  addiu      $a1, $zero, 0x10
    /* C4FE0 002C43E0 24060001 */  addiu      $a2, $zero, 0x1
    /* C4FE4 002C43E4 8FAB0068 */  lw         $t3, 0x68($sp)
    /* C4FE8 002C43E8 00003821 */  addu       $a3, $zero, $zero
    /* C4FEC 002C43EC AFA80020 */  sw         $t0, 0x20($sp)
    /* C4FF0 002C43F0 AFA90024 */  sw         $t1, 0x24($sp)
    /* C4FF4 002C43F4 AFAA0028 */  sw         $t2, 0x28($sp)
    /* C4FF8 002C43F8 0C0B0FA8 */  jal        func_002C3EA0
    /* C4FFC 002C43FC AFAB0010 */   sw        $t3, 0x10($sp)
    /* C5000 002C4400 3042FFFF */  andi       $v0, $v0, 0xFFFF
    /* C5004 002C4404 8FA80020 */  lw         $t0, 0x20($sp)
    /* C5008 002C4408 8FA90024 */  lw         $t1, 0x24($sp)
    /* C500C 002C440C 8FAA0028 */  lw         $t2, 0x28($sp)
    /* C5010 002C4410 14400003 */  bnez       $v0, .L002C4420
    /* C5014 002C4414 00000000 */   nop
  .L002C4418:
    /* C5018 002C4418 080B1112 */  j          .L002C4448
    /* C501C 002C441C 2402FFFF */   addiu     $v0, $zero, -0x1
  .L002C4420:
    /* C5020 002C4420 97C20000 */  lhu        $v0, 0x0($fp)
    /* C5024 002C4424 24420010 */  addiu      $v0, $v0, 0x10
    /* C5028 002C4428 A7C20000 */  sh         $v0, 0x0($fp)
  .L002C442C:
    /* C502C 002C442C 00111400 */  sll        $v0, $s1, 16
  .L002C4430:
    /* C5030 002C4430 00021403 */  sra        $v0, $v0, 16
    /* C5034 002C4434 0056102A */  slt        $v0, $v0, $s6
    /* C5038 002C4438 1440FF2B */  bnez       $v0, .L002C40E8
    /* C503C 002C443C 00000000 */   nop
  .L002C4440:
    /* C5040 002C4440 00111400 */  sll        $v0, $s1, 16
    /* C5044 002C4444 00021403 */  sra        $v0, $v0, 16
  .L002C4448:
    /* C5048 002C4448 8FBF0054 */  lw         $ra, 0x54($sp)
    /* C504C 002C444C 8FBE0050 */  lw         $fp, 0x50($sp)
    /* C5050 002C4450 8FB7004C */  lw         $s7, 0x4C($sp)
    /* C5054 002C4454 8FB60048 */  lw         $s6, 0x48($sp)
    /* C5058 002C4458 8FB50044 */  lw         $s5, 0x44($sp)
    /* C505C 002C445C 8FB40040 */  lw         $s4, 0x40($sp)
    /* C5060 002C4460 8FB3003C */  lw         $s3, 0x3C($sp)
    /* C5064 002C4464 8FB20038 */  lw         $s2, 0x38($sp)
    /* C5068 002C4468 8FB10034 */  lw         $s1, 0x34($sp)
    /* C506C 002C446C 8FB00030 */  lw         $s0, 0x30($sp)
    /* C5070 002C4470 03E00008 */  jr         $ra
    /* C5074 002C4474 27BD0058 */   addiu     $sp, $sp, 0x58
endlabel func_002C4074
