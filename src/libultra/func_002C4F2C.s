.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5B2C-0xC5B58 (VRAM 0x002C4F2C) */
glabel func_002C4F2C
    /* C5B2C 002C4F2C 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* C5B30 002C4F30 AFBF0010 */  sw         $ra, 0x10($sp)
    /* C5B34 002C4F34 0C0B111E */  jal        func_002C4478
    /* C5B38 002C4F38 00000000 */   nop
    /* C5B3C 002C4F3C 00021400 */  sll        $v0, $v0, 16
    /* C5B40 002C4F40 00021403 */  sra        $v0, $v0, 16
    /* C5B44 002C4F44 00021027 */  nor        $v0, $zero, $v0
    /* C5B48 002C4F48 8FBF0010 */  lw         $ra, 0x10($sp)
    /* C5B4C 002C4F4C 000217C2 */  srl        $v0, $v0, 31
    /* C5B50 002C4F50 03E00008 */  jr         $ra
    /* C5B54 002C4F54 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_002C4F2C
