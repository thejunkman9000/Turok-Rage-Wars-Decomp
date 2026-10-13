.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly (exception vector stub blob, 2 stray pad words + 28 words), ROM 0x2E68-0x2EE0 (VRAM 0x00202268) */
glabel func_auto_00202268
    .word      0x38622561
    .word      0xB9257728
    mtc0       $k0, $30
    lui        $k0, %hi(D_auto_00202460)
    addiu      $k0, $k0, %lo(D_auto_00202460)
    jr         $k0
    nop
    nop
    nop
    nop
    nop
    nop
    lui        $k0, (0x80000194 >> 16)
    ori        $k0, $k0, (0x80000194 & 0xFFFF)
    jr         $k0
    nop
    mtc0       $k0, $30
    lui        $k0, %hi(D_auto_00202460)
    addiu      $k0, $k0, %lo(D_auto_00202460)
    jr         $k0
    nop
    nop
    nop
    nop
    nop
    nop
    lui        $k0, (0x80000014 >> 16)
    ori        $k0, $k0, (0x80000014 & 0xFFFF)
    jr         $k0
    nop
endlabel func_auto_00202268
