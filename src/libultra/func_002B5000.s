.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5C00-0xB5C30 (VRAM 0x002B5000) */
glabel func_002B5000
    /* B5C00 002B5000 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B5C04 002B5004 2402000D */  addiu      $v0, $zero, 0xD
    /* B5C08 002B5008 24840048 */  addiu      $a0, $a0, 0x48
    /* B5C0C 002B500C AFA50014 */  sw         $a1, 0x14($sp)
    /* B5C10 002B5010 27A50010 */  addiu      $a1, $sp, 0x10
    /* B5C14 002B5014 00003021 */  addu       $a2, $zero, $zero
    /* B5C18 002B5018 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B5C1C 002B501C 0C0AD469 */  jal        func_002B51A4
    /* B5C20 002B5020 A7A20010 */   sh        $v0, 0x10($sp)
    /* B5C24 002B5024 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B5C28 002B5028 03E00008 */  jr         $ra
    /* B5C2C 002B502C 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B5000
