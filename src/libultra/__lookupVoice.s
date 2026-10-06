.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7350-0xB73B0 (VRAM 0x002B6750) */
glabel __lookupVoice
    /* B7350 002B6750 8C830064 */  lw         $v1, 0x64($a0)
    /* B7354 002B6754 10600012 */  beqz       $v1, .L002B67A0
    /* B7358 002B6758 30A500FF */   andi      $a1, $a1, 0xFF
    /* B735C 002B675C 30C600FF */  andi       $a2, $a2, 0xFF
    /* B7360 002B6760 24070003 */  addiu      $a3, $zero, 0x3
    /* B7364 002B6764 24040004 */  addiu      $a0, $zero, 0x4
  .L002B6768:
    /* B7368 002B6768 90620032 */  lbu        $v0, 0x32($v1)
    /* B736C 002B676C 14450009 */  bne        $v0, $a1, .L002B6794
    /* B7370 002B6770 00000000 */   nop
    /* B7374 002B6774 90620031 */  lbu        $v0, 0x31($v1)
    /* B7378 002B6778 14460006 */  bne        $v0, $a2, .L002B6794
    /* B737C 002B677C 00000000 */   nop
    /* B7380 002B6780 90620035 */  lbu        $v0, 0x35($v1)
    /* B7384 002B6784 10470003 */  beq        $v0, $a3, .L002B6794
    /* B7388 002B6788 00000000 */   nop
    /* B738C 002B678C 14440006 */  bne        $v0, $a0, .L002B67A8
    /* B7390 002B6790 00601021 */   addu      $v0, $v1, $zero
  .L002B6794:
    /* B7394 002B6794 8C630000 */  lw         $v1, 0x0($v1)
    /* B7398 002B6798 1460FFF3 */  bnez       $v1, .L002B6768
    /* B739C 002B679C 00000000 */   nop
  .L002B67A0:
    /* B73A0 002B67A0 03E00008 */  jr         $ra
    /* B73A4 002B67A4 00001021 */   addu      $v0, $zero, $zero
  .L002B67A8:
    /* B73A8 002B67A8 03E00008 */  jr         $ra
    /* B73AC 002B67AC 00000000 */   nop
endlabel __lookupVoice
