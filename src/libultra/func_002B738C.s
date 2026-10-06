.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7F8C-0xB7FA8 (VRAM 0x002B738C) */
glabel func_002B738C
    /* B7F8C 002B738C 8CA20000 */  lw         $v0, 0x0($a1)
    /* B7F90 002B7390 AC820008 */  sw         $v0, 0x8($a0)
    /* B7F94 002B7394 94A2000C */  lhu        $v0, 0xC($a1)
    /* B7F98 002B7398 A482001A */  sh         $v0, 0x1A($a0)
    /* B7F9C 002B739C 8CA20004 */  lw         $v0, 0x4($a1)
    /* B7FA0 002B73A0 03E00008 */  jr         $ra
    /* B7FA4 002B73A4 AC82000C */   sw        $v0, 0xC($a0)
endlabel func_002B738C
