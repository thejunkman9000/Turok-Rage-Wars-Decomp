.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2488-0xB24C0 (VRAM 0x002B1888) */
glabel dbgPortReadReg
    /* B2488 002B1888 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B248C 002B188C AFB00010 */  sw         $s0, 0x10($sp)
    /* B2490 002B1890 00808021 */  addu       $s0, $a0, $zero
    /* B2494 002B1894 AFBF0014 */  sw         $ra, 0x14($sp)
  .L002B1898:
    /* B2498 002B1898 0C0AF7A8 */  jal        osPiGetStatus
    /* B249C 002B189C 00000000 */   nop
    /* B24A0 002B18A0 30420003 */  andi       $v0, $v0, 0x3
    /* B24A4 002B18A4 1440FFFC */  bnez       $v0, .L002B1898
    /* B24A8 002B18A8 00000000 */   nop
    /* B24AC 002B18AC 92020001 */  lbu        $v0, 0x1($s0)
    /* B24B0 002B18B0 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B24B4 002B18B4 8FB00010 */  lw         $s0, 0x10($sp)
    /* B24B8 002B18B8 03E00008 */  jr         $ra
    /* B24BC 002B18BC 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel dbgPortReadReg
