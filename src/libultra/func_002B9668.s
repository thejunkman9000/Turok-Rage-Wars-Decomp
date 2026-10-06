.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xBA268-0xBA2AC (VRAM 0x002B9668) */
glabel func_002B9668
    /* BA268 002B9668 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* BA26C 002B966C AFB00010 */  sw         $s0, 0x10($sp)
    /* BA270 002B9670 00808021 */  addu       $s0, $a0, $zero
    /* BA274 002B9674 3C05002C */  lui        $a1, %hi(D_002BB450)
    /* BA278 002B9678 24A5B450 */  addiu      $a1, $a1, %lo(D_002BB450)
    /* BA27C 002B967C 3C06002C */  lui        $a2, %hi(func_002BB550)
    /* BA280 002B9680 24C6B550 */  addiu      $a2, $a2, %lo(func_002BB550)
    /* BA284 002B9684 AFBF0014 */  sw         $ra, 0x14($sp)
    /* BA288 002B9688 0C0AE92C */  jal        func_002BA4B0
    /* BA28C 002B968C 24070003 */   addiu     $a3, $zero, 0x3
    /* BA290 002B9690 24020001 */  addiu      $v0, $zero, 0x1
    /* BA294 002B9694 AE000014 */  sw         $zero, 0x14($s0)
    /* BA298 002B9698 AE020018 */  sw         $v0, 0x18($s0)
    /* BA29C 002B969C 8FBF0014 */  lw         $ra, 0x14($sp)
    /* BA2A0 002B96A0 8FB00010 */  lw         $s0, 0x10($sp)
    /* BA2A4 002B96A4 03E00008 */  jr         $ra
    /* BA2A8 002B96A8 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_002B9668
