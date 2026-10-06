.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB92AC-0xB92B0 (VRAM 0x002B86AC) */
glabel synth_linker_fragment_B92AC
    /* B92AC 002B86AC 27BDFFD8 */  addiu      $sp, $sp, -0x28
endlabel synth_linker_fragment_B92AC
