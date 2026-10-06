.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B6470-0x1B65EC (VRAM 0x00448470) */
glabel osPfsIsPlug
    /* 1B6470 00448470 27BDFFB0 */  addiu      $sp, $sp, -0x50
    /* 1B6474 00448474 AFB40038 */  sw         $s4, 0x38($sp)
    /* 1B6478 00448478 0080A021 */  addu       $s4, $a0, $zero
    /* 1B647C 0044847C AFB70044 */  sw         $s7, 0x44($sp)
    /* 1B6480 00448480 00A0B821 */  addu       $s7, $a1, $zero
    /* 1B6484 00448484 AFB20030 */  sw         $s2, 0x30($sp)
    /* 1B6488 00448488 00009021 */  addu       $s2, $zero, $zero
    /* 1B648C 0044848C AFB00028 */  sw         $s0, 0x28($sp)
    /* 1B6490 00448490 24100003 */  addiu      $s0, $zero, 0x3
    /* 1B6494 00448494 AFBF0048 */  sw         $ra, 0x48($sp)
    /* 1B6498 00448498 AFB60040 */  sw         $s6, 0x40($sp)
    /* 1B649C 0044849C AFB5003C */  sw         $s5, 0x3C($sp)
    /* 1B64A0 004484A0 AFB30034 */  sw         $s3, 0x34($sp)
    /* 1B64A4 004484A4 0C0AFB41 */  jal        __osSiGetAccess
    /* 1B64A8 004484A8 AFB1002C */   sw        $s1, 0x2C($sp)
    /* 1B64AC 004484AC 3C138015 */  lui        $s3, %hi(__osPfsPifRam)
    /* 1B64B0 004484B0 26734110 */  addiu      $s3, $s3, %lo(__osPfsPifRam)
    /* 1B64B4 004484B4 27B10020 */  addiu      $s1, $sp, 0x20
    /* 1B64B8 004484B8 27B50010 */  addiu      $s5, $sp, 0x10
  .L004484BC:
    /* 1B64BC 004484BC 0C11217B */  jal        __osPfsRequestData
    /* 1B64C0 004484C0 00002021 */   addu      $a0, $zero, $zero
    /* 1B64C4 004484C4 24040001 */  addiu      $a0, $zero, 0x1
    /* 1B64C8 004484C8 0C0AFB68 */  jal        __osSiRawStartDma
    /* 1B64CC 004484CC 02602821 */   addu      $a1, $s3, $zero
    /* 1B64D0 004484D0 02802021 */  addu       $a0, $s4, $zero
    /* 1B64D4 004484D4 02202821 */  addu       $a1, $s1, $zero
    /* 1B64D8 004484D8 0C0B00E4 */  jal        osRecvMesg
    /* 1B64DC 004484DC 24060001 */   addiu     $a2, $zero, 0x1
    /* 1B64E0 004484E0 00002021 */  addu       $a0, $zero, $zero
    /* 1B64E4 004484E4 0C0AFB68 */  jal        __osSiRawStartDma
    /* 1B64E8 004484E8 02602821 */   addu      $a1, $s3, $zero
    /* 1B64EC 004484EC 02802021 */  addu       $a0, $s4, $zero
    /* 1B64F0 004484F0 02202821 */  addu       $a1, $s1, $zero
    /* 1B64F4 004484F4 24060001 */  addiu      $a2, $zero, 0x1
    /* 1B64F8 004484F8 0C0B00E4 */  jal        osRecvMesg
    /* 1B64FC 004484FC 0040B021 */   addu      $s6, $v0, $zero
    /* 1B6500 00448500 27A40024 */  addiu      $a0, $sp, 0x24
    /* 1B6504 00448504 0C1121A2 */  jal        __osPfsGetInitData
    /* 1B6508 00448508 27A50010 */   addiu     $a1, $sp, 0x10
    /* 1B650C 0044850C 3C028015 */  lui        $v0, %hi(__osContNumControllers)
    /* 1B6510 00448510 9042D46C */  lbu        $v0, %lo(__osContNumControllers)($v0)
    /* 1B6514 00448514 1040000E */  beqz       $v0, .L00448550
    /* 1B6518 00448518 00002021 */   addu      $a0, $zero, $zero
    /* 1B651C 0044851C 00402821 */  addu       $a1, $v0, $zero
    /* 1B6520 00448520 02A01821 */  addu       $v1, $s5, $zero
  .L00448524:
    /* 1B6524 00448524 90620002 */  lbu        $v0, 0x2($v1)
    /* 1B6528 00448528 30420004 */  andi       $v0, $v0, 0x4
    /* 1B652C 0044852C 54400003 */  bnel       $v0, $zero, .L0044853C
    /* 1B6530 00448530 24840001 */   addiu     $a0, $a0, 0x1
    /* 1B6534 00448534 08112152 */  j          .L00448548
    /* 1B6538 00448538 2610FFFF */   addiu     $s0, $s0, -0x1
  .L0044853C:
    /* 1B653C 0044853C 0085102A */  slt        $v0, $a0, $a1
    /* 1B6540 00448540 1440FFF8 */  bnez       $v0, .L00448524
    /* 1B6544 00448544 24630004 */   addiu     $v1, $v1, 0x4
  .L00448548:
    /* 1B6548 00448548 3C028015 */  lui        $v0, %hi(__osContNumControllers)
    /* 1B654C 0044854C 9042D46C */  lbu        $v0, %lo(__osContNumControllers)($v0)
  .L00448550:
    /* 1B6550 00448550 50820001 */  beql       $a0, $v0, .L00448558
    /* 1B6554 00448554 00008021 */   addu      $s0, $zero, $zero
  .L00448558:
    /* 1B6558 00448558 1E00FFD8 */  bgtz       $s0, .L004484BC
    /* 1B655C 0044855C 00000000 */   nop
    /* 1B6560 00448560 3C028015 */  lui        $v0, %hi(__osContNumControllers)
    /* 1B6564 00448564 9042D46C */  lbu        $v0, %lo(__osContNumControllers)($v0)
    /* 1B6568 00448568 10400011 */  beqz       $v0, .L004485B0
    /* 1B656C 0044856C 00002021 */   addu      $a0, $zero, $zero
    /* 1B6570 00448570 24060001 */  addiu      $a2, $zero, 0x1
    /* 1B6574 00448574 00402821 */  addu       $a1, $v0, $zero
    /* 1B6578 00448578 27A30010 */  addiu      $v1, $sp, 0x10
  .L0044857C:
    /* 1B657C 0044857C 90620003 */  lbu        $v0, 0x3($v1)
    /* 1B6580 00448580 54400008 */  bnel       $v0, $zero, .L004485A4
    /* 1B6584 00448584 24840001 */   addiu     $a0, $a0, 0x1
    /* 1B6588 00448588 90620002 */  lbu        $v0, 0x2($v1)
    /* 1B658C 0044858C 30420001 */  andi       $v0, $v0, 0x1
    /* 1B6590 00448590 50400004 */  beql       $v0, $zero, .L004485A4
    /* 1B6594 00448594 24840001 */   addiu     $a0, $a0, 0x1
    /* 1B6598 00448598 00861004 */  sllv       $v0, $a2, $a0
    /* 1B659C 0044859C 02429025 */  or         $s2, $s2, $v0
    /* 1B65A0 004485A0 24840001 */  addiu      $a0, $a0, 0x1
  .L004485A4:
    /* 1B65A4 004485A4 0085102A */  slt        $v0, $a0, $a1
    /* 1B65A8 004485A8 1440FFF4 */  bnez       $v0, .L0044857C
    /* 1B65AC 004485AC 24630004 */   addiu     $v1, $v1, 0x4
  .L004485B0:
    /* 1B65B0 004485B0 0C0AFB5C */  jal        __osSiRelAccess
    /* 1B65B4 004485B4 00000000 */   nop
    /* 1B65B8 004485B8 02C01021 */  addu       $v0, $s6, $zero
    /* 1B65BC 004485BC A2F20000 */  sb         $s2, 0x0($s7)
    /* 1B65C0 004485C0 8FBF0048 */  lw         $ra, 0x48($sp)
    /* 1B65C4 004485C4 8FB70044 */  lw         $s7, 0x44($sp)
    /* 1B65C8 004485C8 8FB60040 */  lw         $s6, 0x40($sp)
    /* 1B65CC 004485CC 8FB5003C */  lw         $s5, 0x3C($sp)
    /* 1B65D0 004485D0 8FB40038 */  lw         $s4, 0x38($sp)
    /* 1B65D4 004485D4 8FB30034 */  lw         $s3, 0x34($sp)
    /* 1B65D8 004485D8 8FB20030 */  lw         $s2, 0x30($sp)
    /* 1B65DC 004485DC 8FB1002C */  lw         $s1, 0x2C($sp)
    /* 1B65E0 004485E0 8FB00028 */  lw         $s0, 0x28($sp)
    /* 1B65E4 004485E4 03E00008 */  jr         $ra
    /* 1B65E8 004485E8 27BD0050 */   addiu     $sp, $sp, 0x50
endlabel osPfsIsPlug
