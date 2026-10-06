.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2B74-0xB2BCC (VRAM 0x002B1F74) */
glabel dbgPortSetFifoRxReset
    /* B2B74 002B1F74 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B2B78 002B1F78 3C028015 */  lui        $v0, %hi(D_8014D3E2)
    /* B2B7C 002B1F7C 9042D3E2 */  lbu        $v0, %lo(D_8014D3E2)($v0)
    /* B2B80 002B1F80 00042040 */  sll        $a0, $a0, 1
    /* B2B84 002B1F84 AFBF0014 */  sw         $ra, 0x14($sp)
    /* B2B88 002B1F88 AFB00010 */  sw         $s0, 0x10($sp)
    /* B2B8C 002B1F8C 304200FD */  andi       $v0, $v0, 0xFD
    /* B2B90 002B1F90 00441025 */  or         $v0, $v0, $a0
    /* B2B94 002B1F94 00408021 */  addu       $s0, $v0, $zero
    /* B2B98 002B1F98 3C018015 */  lui        $at, %hi(D_8014D3E2)
    /* B2B9C 002B1F9C A022D3E2 */  sb         $v0, %lo(D_8014D3E2)($at)
  .L002B1FA0:
    /* B2BA0 002B1FA0 0C0AF7A8 */  jal        osPiGetStatus
    /* B2BA4 002B1FA4 00000000 */   nop
    /* B2BA8 002B1FA8 30420003 */  andi       $v0, $v0, 0x3
    /* B2BAC 002B1FAC 1440FFFC */  bnez       $v0, .L002B1FA0
    /* B2BB0 002B1FB0 320200FF */   andi      $v0, $s0, 0xFF
    /* B2BB4 002B1FB4 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B2BB8 002B1FB8 8FB00010 */  lw         $s0, 0x10($sp)
    /* B2BBC 002B1FBC 3C01B200 */  lui        $at, %hi(D_B2000008)
    /* B2BC0 002B1FC0 A4220008 */  sh         $v0, %lo(D_B2000008)($at)
    /* B2BC4 002B1FC4 03E00008 */  jr         $ra
    /* B2BC8 002B1FC8 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel dbgPortSetFifoRxReset
