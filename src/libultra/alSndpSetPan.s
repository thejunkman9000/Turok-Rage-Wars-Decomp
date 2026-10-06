.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8B00-0xB8B50 (VRAM 0x002B7F00) */
glabel alSndpSetPan
    /* B8B00 002B7F00 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B8B04 002B7F04 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B8B08 002B7F08 8C860040 */  lw         $a2, 0x40($a0)
    /* B8B0C 002B7F0C 24020002 */  addiu      $v0, $zero, 0x2
    /* B8B10 002B7F10 A7A20010 */  sh         $v0, 0x10($sp)
    /* B8B14 002B7F14 A3A50018 */  sb         $a1, 0x18($sp)
    /* B8B18 002B7F18 8C83003C */  lw         $v1, 0x3C($a0)
    /* B8B1C 002B7F1C 24840014 */  addiu      $a0, $a0, 0x14
    /* B8B20 002B7F20 27A50010 */  addiu      $a1, $sp, 0x10
    /* B8B24 002B7F24 00031040 */  sll        $v0, $v1, 1
    /* B8B28 002B7F28 00431021 */  addu       $v0, $v0, $v1
    /* B8B2C 002B7F2C 00021100 */  sll        $v0, $v0, 4
    /* B8B30 002B7F30 00C23021 */  addu       $a2, $a2, $v0
    /* B8B34 002B7F34 AFA60014 */  sw         $a2, 0x14($sp)
    /* B8B38 002B7F38 0C0AD469 */  jal        alEvtqPostEvent
    /* B8B3C 002B7F3C 00003021 */   addu      $a2, $zero, $zero
    /* B8B40 002B7F40 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B8B44 002B7F44 03E00008 */  jr         $ra
    /* B8B48 002B7F48 27BD0028 */   addiu     $sp, $sp, 0x28


    /* B8B4C 002B7F4C 8E020000 */  .word      0x8E020000 /* linker padding */
endlabel alSndpSetPan
