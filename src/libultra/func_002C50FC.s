.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5CFC-0xC5D34 (VRAM 0x002C50FC) */
glabel func_002C50FC
    /* C5CFC 002C50FC 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* C5D00 002C5100 00A01021 */  addu       $v0, $a1, $zero
    /* C5D04 002C5104 AFBF0018 */  sw         $ra, 0x18($sp)
    /* C5D08 002C5108 8C430004 */  lw         $v1, 0x4($v0)
    /* C5D0C 002C510C AFA30010 */  sw         $v1, 0x10($sp)
    /* C5D10 002C5110 8C430008 */  lw         $v1, 0x8($v0)
    /* C5D14 002C5114 AFA30014 */  sw         $v1, 0x14($sp)
    /* C5D18 002C5118 8C45000C */  lw         $a1, 0xC($v0)
    /* C5D1C 002C511C 8C470000 */  lw         $a3, 0x0($v0)
    /* C5D20 002C5120 0C0B1286 */  jal        func_002C4A18
    /* C5D24 002C5124 00000000 */   nop
    /* C5D28 002C5128 8FBF0018 */  lw         $ra, 0x18($sp)
    /* C5D2C 002C512C 03E00008 */  jr         $ra
    /* C5D30 002C5130 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel func_002C50FC
