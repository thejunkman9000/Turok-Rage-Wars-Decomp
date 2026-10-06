.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5C30-0xB5C60 (VRAM 0x002B5030) */
glabel func_002B5030
    /* B5C30 002B5030 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B5C34 002B5034 2402000A */  addiu      $v0, $zero, 0xA
    /* B5C38 002B5038 24840048 */  addiu      $a0, $a0, 0x48
    /* B5C3C 002B503C A7A50014 */  sh         $a1, 0x14($sp)
    /* B5C40 002B5040 27A50010 */  addiu      $a1, $sp, 0x10
    /* B5C44 002B5044 00003021 */  addu       $a2, $zero, $zero
    /* B5C48 002B5048 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B5C4C 002B504C 0C0AD469 */  jal        func_002B51A4
    /* B5C50 002B5050 A7A20010 */   sh        $v0, 0x10($sp)
    /* B5C54 002B5054 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B5C58 002B5058 03E00008 */  jr         $ra
    /* B5C5C 002B505C 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel func_002B5030
