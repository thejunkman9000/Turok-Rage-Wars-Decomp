.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5B80-0xB5BB0 (VRAM 0x002B4F80) */
glabel alCSPSetBank
    /* B5B80 002B4F80 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B5B84 002B4F84 2402000E */  addiu      $v0, $zero, 0xE
    /* B5B88 002B4F88 24840048 */  addiu      $a0, $a0, 0x48
    /* B5B8C 002B4F8C AFA50014 */  sw         $a1, 0x14($sp)
    /* B5B90 002B4F90 27A50010 */  addiu      $a1, $sp, 0x10
    /* B5B94 002B4F94 00003021 */  addu       $a2, $zero, $zero
    /* B5B98 002B4F98 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B5B9C 002B4F9C 0C0AD469 */  jal        alEvtqPostEvent
    /* B5BA0 002B4FA0 A7A20010 */   sh        $v0, 0x10($sp)
    /* B5BA4 002B4FA4 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B5BA8 002B4FA8 03E00008 */  jr         $ra
    /* B5BAC 002B4FAC 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel alCSPSetBank
