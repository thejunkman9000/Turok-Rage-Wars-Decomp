.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB29C0-0xB2A18 (VRAM 0x002B1DC0) */
glabel dbgPortSetParityEnable
    /* B29C0 002B1DC0 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B29C4 002B1DC4 3C028015 */  lui        $v0, %hi(D_8014D3E3)
    /* B29C8 002B1DC8 9042D3E3 */  lbu        $v0, %lo(D_8014D3E3)($v0)
    /* B29CC 002B1DCC 000420C0 */  sll        $a0, $a0, 3
    /* B29D0 002B1DD0 AFBF0014 */  sw         $ra, 0x14($sp)
    /* B29D4 002B1DD4 AFB00010 */  sw         $s0, 0x10($sp)
    /* B29D8 002B1DD8 304200F7 */  andi       $v0, $v0, 0xF7
    /* B29DC 002B1DDC 00441025 */  or         $v0, $v0, $a0
    /* B29E0 002B1DE0 00408021 */  addu       $s0, $v0, $zero
    /* B29E4 002B1DE4 3C018015 */  lui        $at, %hi(D_8014D3E3)
    /* B29E8 002B1DE8 A022D3E3 */  sb         $v0, %lo(D_8014D3E3)($at)
  .L002B1DEC:
    /* B29EC 002B1DEC 0C0AF7A8 */  jal        osPiGetStatus
    /* B29F0 002B1DF0 00000000 */   nop
    /* B29F4 002B1DF4 30420003 */  andi       $v0, $v0, 0x3
    /* B29F8 002B1DF8 1440FFFC */  bnez       $v0, .L002B1DEC
    /* B29FC 002B1DFC 320200FF */   andi      $v0, $s0, 0xFF
    /* B2A00 002B1E00 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B2A04 002B1E04 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2A08 002B1E08 3C01B200 */  lui        $at, %hi(D_B200000C)
    /* B2A0C 002B1E0C A422000C */  sh         $v0, %lo(D_B200000C)($at)
    /* B2A10 002B1E10 03E00008 */  jr         $ra
    /* B2A14 002B1E14 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel dbgPortSetParityEnable
