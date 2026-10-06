.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2914-0xB296C (VRAM 0x002B1D14) */
glabel dbgPortSetFifoTrigger
    /* B2914 002B1D14 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B2918 002B1D18 3C028015 */  lui        $v0, %hi(D_8014D3E2)
    /* B291C 002B1D1C 9042D3E2 */  lbu        $v0, %lo(D_8014D3E2)($v0)
    /* B2920 002B1D20 00042180 */  sll        $a0, $a0, 6
    /* B2924 002B1D24 AFBF0014 */  sw         $ra, 0x14($sp)
    /* B2928 002B1D28 AFB00010 */  sw         $s0, 0x10($sp)
    /* B292C 002B1D2C 304200BF */  andi       $v0, $v0, 0xBF
    /* B2930 002B1D30 00441025 */  or         $v0, $v0, $a0
    /* B2934 002B1D34 00408021 */  addu       $s0, $v0, $zero
    /* B2938 002B1D38 3C018015 */  lui        $at, %hi(D_8014D3E2)
    /* B293C 002B1D3C A022D3E2 */  sb         $v0, %lo(D_8014D3E2)($at)
  .L002B1D40:
    /* B2940 002B1D40 0C0AF7A8 */  jal        osPiGetStatus
    /* B2944 002B1D44 00000000 */   nop
    /* B2948 002B1D48 30420003 */  andi       $v0, $v0, 0x3
    /* B294C 002B1D4C 1440FFFC */  bnez       $v0, .L002B1D40
    /* B2950 002B1D50 320200FF */   andi      $v0, $s0, 0xFF
    /* B2954 002B1D54 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B2958 002B1D58 8FB00010 */  lw         $s0, 0x10($sp)
    /* B295C 002B1D5C 3C01B200 */  lui        $at, %hi(D_B2000008)
    /* B2960 002B1D60 A4220008 */  sh         $v0, %lo(D_B2000008)($at)
    /* B2964 002B1D64 03E00008 */  jr         $ra
    /* B2968 002B1D68 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel dbgPortSetFifoTrigger
