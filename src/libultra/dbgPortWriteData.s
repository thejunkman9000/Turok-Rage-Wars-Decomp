.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2BCC-0xB2C10 (VRAM 0x002B1FCC) */
glabel dbgPortWriteData
    /* B2BCC 002B1FCC 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B2BD0 002B1FD0 AFB00010 */  sw         $s0, 0x10($sp)
    /* B2BD4 002B1FD4 00808021 */  addu       $s0, $a0, $zero
    /* B2BD8 002B1FD8 AFBF0014 */  sw         $ra, 0x14($sp)
    /* B2BDC 002B1FDC 3C018015 */  lui        $at, %hi(D_8014D3E0)
    /* B2BE0 002B1FE0 A024D3E0 */  sb         $a0, %lo(D_8014D3E0)($at)
  .L002B1FE4:
    /* B2BE4 002B1FE4 0C0AF7A8 */  jal        osPiGetStatus
    /* B2BE8 002B1FE8 00000000 */   nop
    /* B2BEC 002B1FEC 30420003 */  andi       $v0, $v0, 0x3
    /* B2BF0 002B1FF0 1440FFFC */  bnez       $v0, .L002B1FE4
    /* B2BF4 002B1FF4 320200FF */   andi      $v0, $s0, 0xFF
    /* B2BF8 002B1FF8 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B2BFC 002B1FFC 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2C00 002B2000 3C01B200 */  lui        $at, %hi(D_B2000000)
    /* B2C04 002B2004 A4220000 */  sh         $v0, %lo(D_B2000000)($at)
    /* B2C08 002B2008 03E00008 */  jr         $ra
    /* B2C0C 002B200C 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel dbgPortWriteData
