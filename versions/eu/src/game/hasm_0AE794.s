.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xAE794-0xAE7DC (VRAM 0x002ADB94) */
.globl dbgSetWatchpoint
dbgSetWatchpoint:
    /* AE794 002ADB94 00042100 */  sll        $a0, $a0, 4
    /* AE798 002ADB98 00042102 */  srl        $a0, $a0, 4
    /* AE79C 002ADB9C 2002FFF8 */  addi       $v0, $zero, -0x8 /* handwritten instruction */
    /* AE7A0 002ADBA0 00442024 */  and        $a0, $v0, $a0
    /* AE7A4 002ADBA4 30A50003 */  andi       $a1, $a1, 0x3
    /* AE7A8 002ADBA8 00A42025 */  or         $a0, $a1, $a0
    /* AE7AC 002ADBAC 40849000 */  mtc0       $a0, $18 /* handwritten instruction */
    /* AE7B0 002ADBB0 00000000 */  nop
    /* AE7B4 002ADBB4 00000000 */  nop
    /* AE7B8 002ADBB8 00000000 */  nop
    /* AE7BC 002ADBBC 00000000 */  nop
    /* AE7C0 002ADBC0 40009800 */  mfc0       $zero, $19 /* handwritten instruction */
    /* AE7C4 002ADBC4 00000000 */  nop
    /* AE7C8 002ADBC8 00000000 */  nop
    /* AE7CC 002ADBCC 00000000 */  nop
    /* AE7D0 002ADBD0 03E00008 */  jr         $ra
    /* AE7D4 002ADBD4 00000000 */  nop
    /* AE7D8 002ADBD8 00000000 */  nop
