.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB98F4-0xB990C (VRAM 0x002B8CF4) */
glabel __freeParam
    /* B98F4 002B8CF4 3C03800E */  lui        $v1, %hi(D_800D80A0)
    /* B98F8 002B8CF8 8C6380A0 */  lw         $v1, %lo(D_800D80A0)($v1)
    /* B98FC 002B8CFC 8C62002C */  lw         $v0, 0x2C($v1)
    /* B9900 002B8D00 AC820000 */  sw         $v0, 0x0($a0)
    /* B9904 002B8D04 03E00008 */  jr         $ra
    /* B9908 002B8D08 AC64002C */   sw        $a0, 0x2C($v1)
endlabel __freeParam
