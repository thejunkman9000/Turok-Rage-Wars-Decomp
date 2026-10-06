.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8BE0-0xB8C30 (VRAM 0x002B7FE0) */
glabel alSndpSetVol
    /* B8BE0 002B7FE0 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B8BE4 002B7FE4 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B8BE8 002B7FE8 8C860040 */  lw         $a2, 0x40($a0)
    /* B8BEC 002B7FEC 24020003 */  addiu      $v0, $zero, 0x3
    /* B8BF0 002B7FF0 A7A20010 */  sh         $v0, 0x10($sp)
    /* B8BF4 002B7FF4 8C83003C */  lw         $v1, 0x3C($a0)
    /* B8BF8 002B7FF8 24840014 */  addiu      $a0, $a0, 0x14
    /* B8BFC 002B7FFC A7A50018 */  sh         $a1, 0x18($sp)
    /* B8C00 002B8000 27A50010 */  addiu      $a1, $sp, 0x10
    /* B8C04 002B8004 00031040 */  sll        $v0, $v1, 1
    /* B8C08 002B8008 00431021 */  addu       $v0, $v0, $v1
    /* B8C0C 002B800C 00021100 */  sll        $v0, $v0, 4
    /* B8C10 002B8010 00C23021 */  addu       $a2, $a2, $v0
    /* B8C14 002B8014 AFA60014 */  sw         $a2, 0x14($sp)
    /* B8C18 002B8018 0C0AD469 */  jal        alEvtqPostEvent
    /* B8C1C 002B801C 00003021 */   addu      $a2, $zero, $zero
    /* B8C20 002B8020 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B8C24 002B8024 03E00008 */  jr         $ra
    /* B8C28 002B8028 27BD0028 */   addiu     $sp, $sp, 0x28


    /* B8C2C 002B802C 3C02002C */  .word      0x3C02002C /* linker padding */
endlabel alSndpSetVol
