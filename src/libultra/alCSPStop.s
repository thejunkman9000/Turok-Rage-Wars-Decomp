.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5C60-0xB5C90 (VRAM 0x002B5060) */
glabel alCSPStop
    /* B5C60 002B5060 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B5C64 002B5064 24020011 */  addiu      $v0, $zero, 0x11
    /* B5C68 002B5068 24840048 */  addiu      $a0, $a0, 0x48
    /* B5C6C 002B506C 27A50010 */  addiu      $a1, $sp, 0x10
    /* B5C70 002B5070 00003021 */  addu       $a2, $zero, $zero
    /* B5C74 002B5074 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B5C78 002B5078 0C0AD469 */  jal        alEvtqPostEvent
    /* B5C7C 002B507C A7A20010 */   sh        $v0, 0x10($sp)
    /* B5C80 002B5080 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B5C84 002B5084 03E00008 */  jr         $ra
    /* B5C88 002B5088 27BD0028 */   addiu     $sp, $sp, 0x28


    /* B5C8C 002B508C 10C0000C */  .word      0x10C0000C /* linker padding */
endlabel alCSPStop
