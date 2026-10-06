.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8B50-0xB8BA0 (VRAM 0x002B7F50) */
glabel alSndpSetPitch
    /* B8B50 002B7F50 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B8B54 002B7F54 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B8B58 002B7F58 8C860040 */  lw         $a2, 0x40($a0)
    /* B8B5C 002B7F5C 24020004 */  addiu      $v0, $zero, 0x4
    /* B8B60 002B7F60 A7A20010 */  sh         $v0, 0x10($sp)
    /* B8B64 002B7F64 8C83003C */  lw         $v1, 0x3C($a0)
    /* B8B68 002B7F68 24840014 */  addiu      $a0, $a0, 0x14
    /* B8B6C 002B7F6C AFA50018 */  sw         $a1, 0x18($sp)
    /* B8B70 002B7F70 27A50010 */  addiu      $a1, $sp, 0x10
    /* B8B74 002B7F74 00031040 */  sll        $v0, $v1, 1
    /* B8B78 002B7F78 00431021 */  addu       $v0, $v0, $v1
    /* B8B7C 002B7F7C 00021100 */  sll        $v0, $v0, 4
    /* B8B80 002B7F80 00C23021 */  addu       $a2, $a2, $v0
    /* B8B84 002B7F84 AFA60014 */  sw         $a2, 0x14($sp)
    /* B8B88 002B7F88 0C0AD469 */  jal        alEvtqPostEvent
    /* B8B8C 002B7F8C 00003021 */   addu      $a2, $zero, $zero
    /* B8B90 002B7F90 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B8B94 002B7F94 03E00008 */  jr         $ra
    /* B8B98 002B7F98 27BD0028 */   addiu     $sp, $sp, 0x28


    /* B8B9C 002B7F9C 8FB00018 */  .word      0x8FB00018 /* linker padding */
endlabel alSndpSetPitch
