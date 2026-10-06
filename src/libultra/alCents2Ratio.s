.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5B00-0xB5B50 (VRAM 0x002B4F00) */
glabel alCents2Ratio
    /* B5B00 002B4F00 3C01800D */  lui        $at, %hi(D_800CC680)
    /* B5B04 002B4F04 C420C680 */  lwc1       $fv0, %lo(D_800CC680)($at)
    /* B5B08 002B4F08 3C01800D */  lui        $at, %hi(D_800CC680 + 0x4)
    /* B5B0C 002B4F0C C421C684 */  lwc1       $fv0f, %lo(D_800CC680 + 0x4)($at)
    /* B5B10 002B4F10 04810004 */  bgez       $a0, .L002B4F24
    /* B5B14 002B4F14 00000000 */   nop
    /* B5B18 002B4F18 3C01800D */  lui        $at, %hi(D_800CC688)
    /* B5B1C 002B4F1C C421C688 */  lwc1       $fv0f, %lo(D_800CC688)($at)
    /* B5B20 002B4F20 00042023 */  negu       $a0, $a0
  .L002B4F24:
    /* B5B24 002B4F24 10800008 */  beqz       $a0, .L002B4F48
    /* B5B28 002B4F28 30820001 */   andi      $v0, $a0, 0x1
  .L002B4F2C:
    /* B5B2C 002B4F2C 10400002 */  beqz       $v0, .L002B4F38
    /* B5B30 002B4F30 00042043 */   sra       $a0, $a0, 1
    /* B5B34 002B4F34 46010002 */  mul.s      $fv0, $fv0, $fv0f
  .L002B4F38:
    /* B5B38 002B4F38 00000000 */  nop
    /* B5B3C 002B4F3C 46010842 */  mul.s      $fv0f, $fv0f, $fv0f
    /* B5B40 002B4F40 1480FFFA */  bnez       $a0, .L002B4F2C
    /* B5B44 002B4F44 30820001 */   andi      $v0, $a0, 0x1
  .L002B4F48:
    /* B5B48 002B4F48 03E00008 */  jr         $ra
    /* B5B4C 002B4F4C 00000000 */   nop
endlabel alCents2Ratio
