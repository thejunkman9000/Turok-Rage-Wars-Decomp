.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2F50-0xB2F68 (VRAM 0x002B2350) */
glabel func_002B2350
    /* B2F50 002B2350 27BDFFF8 */  addiu      $sp, $sp, -0x8
    /* B2F54 002B2354 00042400 */  sll        $a0, $a0, 16
    /* B2F58 002B2358 AFA40000 */  sw         $a0, 0x0($sp)
    /* B2F5C 002B235C C7A00000 */  lwc1       $fv0, 0x0($sp)
    /* B2F60 002B2360 03E00008 */  jr         $ra
    /* B2F64 002B2364 27BD0008 */   addiu     $sp, $sp, 0x8
endlabel func_002B2350
