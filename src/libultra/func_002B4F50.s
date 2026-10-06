.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5B50-0xB5B80 (VRAM 0x002B4F50) */
glabel func_002B4F50
    /* B5B50 002B4F50 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B5B54 002B4F54 2402000F */  addiu      $v0, $zero, 0xF
    /* B5B58 002B4F58 24840048 */  addiu      $a0, $a0, 0x48
    /* B5B5C 002B4F5C 27A50010 */  addiu      $a1, $sp, 0x10
    /* B5B60 002B4F60 00003021 */  addu       $a2, $zero, $zero
    /* B5B64 002B4F64 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B5B68 002B4F68 0C0AD469 */  jal        func_002B51A4
    /* B5B6C 002B4F6C A7A20010 */   sh        $v0, 0x10($sp)
    /* B5B70 002B4F70 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B5B74 002B4F74 03E00008 */  jr         $ra
    /* B5B78 002B4F78 27BD0028 */   addiu     $sp, $sp, 0x28


    /* B5B7C 002B4F7C 00151100 */  .word      0x00151100 /* linker padding */
endlabel func_002B4F50
