.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBC224-0xBC230 (VRAM 0x002BB624) */
glabel libaudio_fragment_0BC224
    /* BC224 002BB624 27BD0020 */  addiu      $sp, $sp, 0x20
    /* BC228 002BB628 02802021 */  addu       $a0, $s4, $zero
    /* BC22C 002BB62C 3C018015 */  lui        $at, (0x80150000 >> 16)
endlabel libaudio_fragment_0BC224
