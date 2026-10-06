.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB9150-0xB9208 (VRAM 0x002B8550) */
glabel func_002B8550
    /* B9150 002B8550 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B9154 002B8554 AFB40020 */  sw         $s4, 0x20($sp)
    /* B9158 002B8558 0080A021 */  addu       $s4, $a0, $zero
    /* B915C 002B855C AFB10014 */  sw         $s1, 0x14($sp)
    /* B9160 002B8560 00A08821 */  addu       $s1, $a1, $zero
    /* B9164 002B8564 AFB20018 */  sw         $s2, 0x18($sp)
    /* B9168 002B8568 00C09021 */  addu       $s2, $a2, $zero
    /* B916C 002B856C AFBF0024 */  sw         $ra, 0x24($sp)
    /* B9170 002B8570 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B9174 002B8574 AFB00010 */  sw         $s0, 0x10($sp)
    /* B9178 002B8578 8E220008 */  lw         $v0, 0x8($s1)
    /* B917C 002B857C 1040001A */  beqz       $v0, .L002B85E8
    /* B9180 002B8580 00E09821 */   addu      $s3, $a3, $zero
    /* B9184 002B8584 0C0AE332 */  jal        func_002B8CC8
    /* B9188 002B8588 00000000 */   nop
    /* B918C 002B858C 00408021 */  addu       $s0, $v0, $zero
    /* B9190 002B8590 12000015 */  beqz       $s0, .L002B85E8
    /* B9194 002B8594 02802021 */   addu      $a0, $s4, $zero
    /* B9198 002B8598 02602821 */  addu       $a1, $s3, $zero
    /* B919C 002B859C 8E220008 */  lw         $v0, 0x8($s1)
    /* B91A0 002B85A0 8C83001C */  lw         $v1, 0x1C($a0)
    /* B91A4 002B85A4 8C4600D8 */  lw         $a2, 0xD8($v0)
    /* B91A8 002B85A8 2402000B */  addiu      $v0, $zero, 0xB
    /* B91AC 002B85AC A6020008 */  sh         $v0, 0x8($s0)
    /* B91B0 002B85B0 00121400 */  sll        $v0, $s2, 16
    /* B91B4 002B85B4 00021403 */  sra        $v0, $v0, 16
    /* B91B8 002B85B8 AE02000C */  sw         $v0, 0xC($s0)
    /* B91BC 002B85BC 00661821 */  addu       $v1, $v1, $a2
    /* B91C0 002B85C0 0C0AE368 */  jal        func_002B8DA0
    /* B91C4 002B85C4 AE030004 */   sw        $v1, 0x4($s0)
    /* B91C8 002B85C8 AE020010 */  sw         $v0, 0x10($s0)
    /* B91CC 002B85CC AE000000 */  sw         $zero, 0x0($s0)
    /* B91D0 002B85D0 8E220008 */  lw         $v0, 0x8($s1)
    /* B91D4 002B85D4 8C44000C */  lw         $a0, 0xC($v0)
    /* B91D8 002B85D8 24050003 */  addiu      $a1, $zero, 0x3
    /* B91DC 002B85DC 8C820008 */  lw         $v0, 0x8($a0)
    /* B91E0 002B85E0 0040F809 */  jalr       $v0
    /* B91E4 002B85E4 02003021 */   addu      $a2, $s0, $zero
  .L002B85E8:
    /* B91E8 002B85E8 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B91EC 002B85EC 8FB40020 */  lw         $s4, 0x20($sp)
    /* B91F0 002B85F0 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B91F4 002B85F4 8FB20018 */  lw         $s2, 0x18($sp)
    /* B91F8 002B85F8 8FB10014 */  lw         $s1, 0x14($sp)
    /* B91FC 002B85FC 8FB00010 */  lw         $s0, 0x10($sp)
    /* B9200 002B8600 03E00008 */  jr         $ra
    /* B9204 002B8604 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B8550
