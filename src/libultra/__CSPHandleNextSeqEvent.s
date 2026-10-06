.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB4E20-0xB4FB0 (VRAM 0x002B4220) */
glabel __CSPHandleNextSeqEvent
    /* B4E20 002B4220 27BDFFB8 */  addiu      $sp, $sp, -0x48
    /* B4E24 002B4224 AFB00040 */  sw         $s0, 0x40($sp)
    /* B4E28 002B4228 00808021 */  addu       $s0, $a0, $zero
    /* B4E2C 002B422C AFBF0044 */  sw         $ra, 0x44($sp)
    /* B4E30 002B4230 8E040018 */  lw         $a0, 0x18($s0)
    /* B4E34 002B4234 1080005A */  beqz       $a0, .L002B43A0
    /* B4E38 002B4238 00000000 */   nop
    /* B4E3C 002B423C 0C0ACDE3 */  jal        alCSeqNextEvent
    /* B4E40 002B4240 27A50010 */   addiu     $a1, $sp, 0x10
    /* B4E44 002B4244 97A20010 */  lhu        $v0, 0x10($sp)
    /* B4E48 002B4248 2442FFFF */  addiu      $v0, $v0, -0x1
    /* B4E4C 002B424C 00021400 */  sll        $v0, $v0, 16
    /* B4E50 002B4250 00021C03 */  sra        $v1, $v0, 16
    /* B4E54 002B4254 2C620014 */  sltiu      $v0, $v1, 0x14
    /* B4E58 002B4258 1040004B */  beqz       $v0, .L002B4388
    /* B4E5C 002B425C 00031080 */   sll       $v0, $v1, 2
    /* B4E60 002B4260 3C01800D */  lui        $at, %hi(jtbl_800CC620)
    /* B4E64 002B4264 00220821 */  addu       $at, $at, $v0
    /* B4E68 002B4268 8C22C620 */  lw         $v0, %lo(jtbl_800CC620)($at)
    /* B4E6C 002B426C 00400008 */  jr         $v0
    /* B4E70 002B4270 00000000 */   nop
    /* B4E74 002B4274 02002021 */  addu       $a0, $s0, $zero
    /* B4E78 002B4278 0C0AD0EC */  jal        __CSPHandleMIDIMsg
    /* B4E7C 002B427C 27A50010 */   addiu     $a1, $sp, 0x10
    /* B4E80 002B4280 8E03002C */  lw         $v1, 0x2C($s0)
    /* B4E84 002B4284 24020001 */  addiu      $v0, $zero, 0x1
    /* B4E88 002B4288 14620045 */  bne        $v1, $v0, .L002B43A0
    /* B4E8C 002B428C 00000000 */   nop
    /* B4E90 002B4290 8E040018 */  lw         $a0, 0x18($s0)
    /* B4E94 002B4294 10800042 */  beqz       $a0, .L002B43A0
    /* B4E98 002B4298 00000000 */   nop
    /* B4E9C 002B429C 0C0ACEA0 */  jal        __alCSeqNextDelta
    /* B4EA0 002B42A0 27A50030 */   addiu     $a1, $sp, 0x30
    /* B4EA4 002B42A4 304200FF */  andi       $v0, $v0, 0xFF
    /* B4EA8 002B42A8 1040003D */  beqz       $v0, .L002B43A0
    /* B4EAC 002B42AC 00000000 */   nop
    /* B4EB0 002B42B0 8FA20030 */  lw         $v0, 0x30($sp)
    /* B4EB4 002B42B4 080AD0DA */  j          .L002B4368
    /* B4EB8 002B42B8 A7A00020 */   sh        $zero, 0x20($sp)
    /* B4EBC 002B42BC 02002021 */  addu       $a0, $s0, $zero
    /* B4EC0 002B42C0 0C0AD30F */  jal        __CSPHandleMetaMsg
    /* B4EC4 002B42C4 27A50010 */   addiu     $a1, $sp, 0x10
    /* B4EC8 002B42C8 8E03002C */  lw         $v1, 0x2C($s0)
    /* B4ECC 002B42CC 24020001 */  addiu      $v0, $zero, 0x1
    /* B4ED0 002B42D0 14620033 */  bne        $v1, $v0, .L002B43A0
    /* B4ED4 002B42D4 00000000 */   nop
    /* B4ED8 002B42D8 8E040018 */  lw         $a0, 0x18($s0)
    /* B4EDC 002B42DC 10800030 */  beqz       $a0, .L002B43A0
    /* B4EE0 002B42E0 00000000 */   nop
    /* B4EE4 002B42E4 0C0ACEA0 */  jal        __alCSeqNextDelta
    /* B4EE8 002B42E8 27A50034 */   addiu     $a1, $sp, 0x34
    /* B4EEC 002B42EC 304200FF */  andi       $v0, $v0, 0xFF
    /* B4EF0 002B42F0 1040002B */  beqz       $v0, .L002B43A0
    /* B4EF4 002B42F4 00000000 */   nop
    /* B4EF8 002B42F8 8FA20034 */  lw         $v0, 0x34($sp)
    /* B4EFC 002B42FC 080AD0DA */  j          .L002B4368
    /* B4F00 002B4300 A7A00020 */   sh        $zero, 0x20($sp)
    /* B4F04 002B4304 26040048 */  addiu      $a0, $s0, 0x48
    /* B4F08 002B4308 27A50010 */  addiu      $a1, $sp, 0x10
    /* B4F0C 002B430C 3C067FFF */  lui        $a2, (0x7FFFFFFF >> 16)
    /* B4F10 002B4310 34C6FFFF */  ori        $a2, $a2, (0x7FFFFFFF & 0xFFFF)
    /* B4F14 002B4314 24020002 */  addiu      $v0, $zero, 0x2
    /* B4F18 002B4318 AE02002C */  sw         $v0, 0x2C($s0)
    /* B4F1C 002B431C 24020010 */  addiu      $v0, $zero, 0x10
    /* B4F20 002B4320 0C0AD469 */  jal        alEvtqPostEvent
    /* B4F24 002B4324 A7A20010 */   sh        $v0, 0x10($sp)
    /* B4F28 002B4328 080AD0E8 */  j          .L002B43A0
    /* B4F2C 002B432C 00000000 */   nop
    /* B4F30 002B4330 8E03002C */  lw         $v1, 0x2C($s0)
    /* B4F34 002B4334 24020001 */  addiu      $v0, $zero, 0x1
    /* B4F38 002B4338 14620019 */  bne        $v1, $v0, .L002B43A0
    /* B4F3C 002B433C 00000000 */   nop
    /* B4F40 002B4340 8E040018 */  lw         $a0, 0x18($s0)
    /* B4F44 002B4344 10800016 */  beqz       $a0, .L002B43A0
    /* B4F48 002B4348 00000000 */   nop
    /* B4F4C 002B434C 0C0ACEA0 */  jal        __alCSeqNextDelta
    /* B4F50 002B4350 27A50038 */   addiu     $a1, $sp, 0x38
    /* B4F54 002B4354 304200FF */  andi       $v0, $v0, 0xFF
    /* B4F58 002B4358 10400011 */  beqz       $v0, .L002B43A0
    /* B4F5C 002B435C 00000000 */   nop
    /* B4F60 002B4360 8FA20038 */  lw         $v0, 0x38($sp)
    /* B4F64 002B4364 A7A00020 */  sh         $zero, 0x20($sp)
  .L002B4368:
    /* B4F68 002B4368 8E060024 */  lw         $a2, 0x24($s0)
    /* B4F6C 002B436C 00460018 */  mult       $v0, $a2
    /* B4F70 002B4370 26040048 */  addiu      $a0, $s0, 0x48
    /* B4F74 002B4374 00003012 */  mflo       $a2
    /* B4F78 002B4378 0C0AD469 */  jal        alEvtqPostEvent
    /* B4F7C 002B437C 27A50020 */   addiu     $a1, $sp, 0x20
    /* B4F80 002B4380 080AD0E8 */  j          .L002B43A0
    /* B4F84 002B4384 00000000 */   nop
  .L002B4388:
    /* B4F88 002B4388 3C04800D */  lui        $a0, %hi(D_800CC5A0)
    /* B4F8C 002B438C 2484C5A0 */  addiu      $a0, $a0, %lo(D_800CC5A0)
    /* B4F90 002B4390 3C05800D */  lui        $a1, %hi(D_800CC5A4)
    /* B4F94 002B4394 24A5C5A4 */  addiu      $a1, $a1, %lo(D_800CC5A4)
    /* B4F98 002B4398 0C0AFF50 */  jal        __assert
    /* B4F9C 002B439C 24060190 */   addiu     $a2, $zero, 0x190
  .L002B43A0:
    /* B4FA0 002B43A0 8FBF0044 */  lw         $ra, 0x44($sp)
    /* B4FA4 002B43A4 8FB00040 */  lw         $s0, 0x40($sp)
    /* B4FA8 002B43A8 03E00008 */  jr         $ra
    /* B4FAC 002B43AC 27BD0048 */   addiu     $sp, $sp, 0x48
endlabel __CSPHandleNextSeqEvent
