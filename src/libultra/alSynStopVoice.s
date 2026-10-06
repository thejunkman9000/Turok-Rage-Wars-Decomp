.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB93C0-0xB9440 (VRAM 0x002B87C0) */
glabel alSynStopVoice
    /* B93C0 002B87C0 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B93C4 002B87C4 AFB00010 */  sw         $s0, 0x10($sp)
    /* B93C8 002B87C8 00A08021 */  addu       $s0, $a1, $zero
    /* B93CC 002B87CC AFBF0018 */  sw         $ra, 0x18($sp)
    /* B93D0 002B87D0 AFB10014 */  sw         $s1, 0x14($sp)
    /* B93D4 002B87D4 8E020008 */  lw         $v0, 0x8($s0)
    /* B93D8 002B87D8 10400013 */  beqz       $v0, .L002B8828
    /* B93DC 002B87DC 00808821 */   addu      $s1, $a0, $zero
    /* B93E0 002B87E0 0C0AE332 */  jal        __allocParam
    /* B93E4 002B87E4 00000000 */   nop
    /* B93E8 002B87E8 00403021 */  addu       $a2, $v0, $zero
    /* B93EC 002B87EC 10C0000E */  beqz       $a2, .L002B8828
    /* B93F0 002B87F0 00000000 */   nop
    /* B93F4 002B87F4 8E020008 */  lw         $v0, 0x8($s0)
    /* B93F8 002B87F8 8E23001C */  lw         $v1, 0x1C($s1)
    /* B93FC 002B87FC 8C4400D8 */  lw         $a0, 0xD8($v0)
    /* B9400 002B8800 2402000F */  addiu      $v0, $zero, 0xF
    /* B9404 002B8804 A4C20008 */  sh         $v0, 0x8($a2)
    /* B9408 002B8808 ACC00000 */  sw         $zero, 0x0($a2)
    /* B940C 002B880C 00641821 */  addu       $v1, $v1, $a0
    /* B9410 002B8810 ACC30004 */  sw         $v1, 0x4($a2)
    /* B9414 002B8814 8E020008 */  lw         $v0, 0x8($s0)
    /* B9418 002B8818 8C44000C */  lw         $a0, 0xC($v0)
    /* B941C 002B881C 8C820008 */  lw         $v0, 0x8($a0)
    /* B9420 002B8820 0040F809 */  jalr       $v0
    /* B9424 002B8824 24050003 */   addiu     $a1, $zero, 0x3
  .L002B8828:
    /* B9428 002B8828 8FBF0018 */  lw         $ra, 0x18($sp)
    /* B942C 002B882C 8FB10014 */  lw         $s1, 0x14($sp)
    /* B9430 002B8830 8FB00010 */  lw         $s0, 0x10($sp)
    /* B9434 002B8834 03E00008 */  jr         $ra
    /* B9438 002B8838 27BD0020 */   addiu     $sp, $sp, 0x20


    /* B943C 002B883C 8E02003C */  .word      0x8E02003C /* linker padding */
endlabel alSynStopVoice
