.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBA124-0xBA180 (VRAM 0x002B9524) */
glabel func_002B9524
    /* BA124 002B9524 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* BA128 002B9528 AFB00010 */  sw         $s0, 0x10($sp)
    /* BA12C 002B952C 00808021 */  addu       $s0, $a0, $zero
    /* BA130 002B9530 AFB20018 */  sw         $s2, 0x18($sp)
    /* BA134 002B9534 00A09021 */  addu       $s2, $a1, $zero
    /* BA138 002B9538 AFB10014 */  sw         $s1, 0x14($sp)
    /* BA13C 002B953C 00C08821 */  addu       $s1, $a2, $zero
    /* BA140 002B9540 3C05002C */  lui        $a1, %hi(D_002BA4D0)
    /* BA144 002B9544 24A5A4D0 */  addiu      $a1, $a1, %lo(D_002BA4D0)
    /* BA148 002B9548 3C06002C */  lui        $a2, %hi(func_002BA610)
    /* BA14C 002B954C 24C6A610 */  addiu      $a2, $a2, %lo(func_002BA610)
    /* BA150 002B9550 AFBF001C */  sw         $ra, 0x1C($sp)
    /* BA154 002B9554 0C0AE92C */  jal        func_002BA4B0
    /* BA158 002B9558 24070007 */   addiu     $a3, $zero, 0x7
    /* BA15C 002B955C AE000014 */  sw         $zero, 0x14($s0)
    /* BA160 002B9560 AE110018 */  sw         $s1, 0x18($s0)
    /* BA164 002B9564 AE12001C */  sw         $s2, 0x1C($s0)
    /* BA168 002B9568 8FBF001C */  lw         $ra, 0x1C($sp)
    /* BA16C 002B956C 8FB20018 */  lw         $s2, 0x18($sp)
    /* BA170 002B9570 8FB10014 */  lw         $s1, 0x14($sp)
    /* BA174 002B9574 8FB00010 */  lw         $s0, 0x10($sp)
    /* BA178 002B9578 03E00008 */  jr         $ra
    /* BA17C 002B957C 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel func_002B9524
