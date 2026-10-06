.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B77D4-0x1B7804 (VRAM 0x004497D4) */
glabel __osSumcalc
    /* 1B77D4 004497D4 00003021 */  addu       $a2, $zero, $zero
    /* 1B77D8 004497D8 18A00008 */  blez       $a1, .L004497FC
    /* 1B77DC 004497DC 00C01821 */   addu      $v1, $a2, $zero
  .L004497E0:
    /* 1B77E0 004497E0 90820000 */  lbu        $v0, 0x0($a0)
    /* 1B77E4 004497E4 24840001 */  addiu      $a0, $a0, 0x1
    /* 1B77E8 004497E8 24C60001 */  addiu      $a2, $a2, 0x1
    /* 1B77EC 004497EC 00621821 */  addu       $v1, $v1, $v0
    /* 1B77F0 004497F0 00C5102A */  slt        $v0, $a2, $a1
    /* 1B77F4 004497F4 1440FFFA */  bnez       $v0, .L004497E0
    /* 1B77F8 004497F8 3063FFFF */   andi      $v1, $v1, 0xFFFF
  .L004497FC:
    /* 1B77FC 004497FC 03E00008 */  jr         $ra
    /* 1B7800 00449800 3062FFFF */   andi      $v0, $v1, 0xFFFF
endlabel __osSumcalc
