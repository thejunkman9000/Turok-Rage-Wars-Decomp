.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2F40-0xB2F50 (VRAM 0x002B2340) */
glabel func_002B2340
    /* B2F40 002B2340 E7AC0000 */  swc1       $fa0, 0x0($sp)
    /* B2F44 002B2344 97A20000 */  lhu        $v0, 0x0($sp)
    /* B2F48 002B2348 03E00008 */  jr         $ra
    /* B2F4C 002B234C 00000000 */   nop
endlabel func_002B2340
