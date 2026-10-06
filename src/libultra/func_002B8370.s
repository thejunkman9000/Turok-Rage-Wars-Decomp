.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8F70-0xB9020 (VRAM 0x002B8370) */
glabel func_002B8370
    /* B8F70 002B8370 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B8F74 002B8374 AFB20018 */  sw         $s2, 0x18($sp)
    /* B8F78 002B8378 00809021 */  addu       $s2, $a0, $zero
    /* B8F7C 002B837C AFB10014 */  sw         $s1, 0x14($sp)
    /* B8F80 002B8380 00A08821 */  addu       $s1, $a1, $zero
    /* B8F84 002B8384 AFB00010 */  sw         $s0, 0x10($sp)
    /* B8F88 002B8388 00C08021 */  addu       $s0, $a2, $zero
    /* B8F8C 002B838C AFBF0020 */  sw         $ra, 0x20($sp)
    /* B8F90 002B8390 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B8F94 002B8394 8E220008 */  lw         $v0, 0x8($s1)
    /* B8F98 002B8398 1040001A */  beqz       $v0, .L002B8404
    /* B8F9C 002B839C 02009821 */   addu      $s3, $s0, $zero
    /* B8FA0 002B83A0 0C0AE332 */  jal        func_002B8CC8
    /* B8FA4 002B83A4 00000000 */   nop
    /* B8FA8 002B83A8 00403021 */  addu       $a2, $v0, $zero
    /* B8FAC 002B83AC 10C00015 */  beqz       $a2, .L002B8404
    /* B8FB0 002B83B0 00000000 */   nop
    /* B8FB4 002B83B4 8E220008 */  lw         $v0, 0x8($s1)
    /* B8FB8 002B83B8 8E43001C */  lw         $v1, 0x1C($s2)
    /* B8FBC 002B83BC 8C4400D8 */  lw         $a0, 0xD8($v0)
    /* B8FC0 002B83C0 24020010 */  addiu      $v0, $zero, 0x10
    /* B8FC4 002B83C4 A4C20008 */  sh         $v0, 0x8($a2)
    /* B8FC8 002B83C8 00101600 */  sll        $v0, $s0, 24
    /* B8FCC 002B83CC 00021603 */  sra        $v0, $v0, 24
    /* B8FD0 002B83D0 00641821 */  addu       $v1, $v1, $a0
    /* B8FD4 002B83D4 04410003 */  bgez       $v0, .L002B83E4
    /* B8FD8 002B83D8 ACC30004 */   sw        $v1, 0x4($a2)
    /* B8FDC 002B83DC 080AE0FA */  j          .L002B83E8
    /* B8FE0 002B83E0 00021023 */   negu      $v0, $v0
  .L002B83E4:
    /* B8FE4 002B83E4 326200FF */  andi       $v0, $s3, 0xFF
  .L002B83E8:
    /* B8FE8 002B83E8 ACC2000C */  sw         $v0, 0xC($a2)
    /* B8FEC 002B83EC ACC00000 */  sw         $zero, 0x0($a2)
    /* B8FF0 002B83F0 8E220008 */  lw         $v0, 0x8($s1)
    /* B8FF4 002B83F4 8C44000C */  lw         $a0, 0xC($v0)
    /* B8FF8 002B83F8 8C820008 */  lw         $v0, 0x8($a0)
    /* B8FFC 002B83FC 0040F809 */  jalr       $v0
    /* B9000 002B8400 24050003 */   addiu     $a1, $zero, 0x3
  .L002B8404:
    /* B9004 002B8404 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B9008 002B8408 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B900C 002B840C 8FB20018 */  lw         $s2, 0x18($sp)
    /* B9010 002B8410 8FB10014 */  lw         $s1, 0x14($sp)
    /* B9014 002B8414 8FB00010 */  lw         $s0, 0x10($sp)
    /* B9018 002B8418 03E00008 */  jr         $ra
    /* B901C 002B841C 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B8370
