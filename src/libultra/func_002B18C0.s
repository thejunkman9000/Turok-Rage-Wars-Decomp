.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB24C0-0xB2504 (VRAM 0x002B18C0) */
glabel func_002B18C0
    /* B24C0 002B18C0 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B24C4 002B18C4 AFB10014 */  sw         $s1, 0x14($sp)
    /* B24C8 002B18C8 00808821 */  addu       $s1, $a0, $zero
    /* B24CC 002B18CC AFB00010 */  sw         $s0, 0x10($sp)
    /* B24D0 002B18D0 00A08021 */  addu       $s0, $a1, $zero
    /* B24D4 002B18D4 AFBF0018 */  sw         $ra, 0x18($sp)
  .L002B18D8:
    /* B24D8 002B18D8 0C0AF7A8 */  jal        osPiGetStatus
    /* B24DC 002B18DC 00000000 */   nop
    /* B24E0 002B18E0 30420003 */  andi       $v0, $v0, 0x3
    /* B24E4 002B18E4 1440FFFC */  bnez       $v0, .L002B18D8
    /* B24E8 002B18E8 320200FF */   andi      $v0, $s0, 0xFF
    /* B24EC 002B18EC A6220000 */  sh         $v0, 0x0($s1)
    /* B24F0 002B18F0 8FBF0018 */  lw         $ra, 0x18($sp)
    /* B24F4 002B18F4 8FB10014 */  lw         $s1, 0x14($sp)
    /* B24F8 002B18F8 8FB00010 */  lw         $s0, 0x10($sp)
    /* B24FC 002B18FC 03E00008 */  jr         $ra
    /* B2500 002B1900 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel func_002B18C0
