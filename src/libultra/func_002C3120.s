.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC3D20-0xC3DB0 (VRAM 0x002C3120) */
glabel func_002C3120
    /* C3D20 002C3120 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* C3D24 002C3124 AFB40020 */  sw         $s4, 0x20($sp)
    /* C3D28 002C3128 0080A021 */  addu       $s4, $a0, $zero
    /* C3D2C 002C312C AFB10014 */  sw         $s1, 0x14($sp)
    /* C3D30 002C3130 AFB00010 */  sw         $s0, 0x10($sp)
    /* C3D34 002C3134 00C08021 */  addu       $s0, $a2, $zero
    /* C3D38 002C3138 00E08821 */  addu       $s1, $a3, $zero
    /* C3D3C 002C313C AFB3001C */  sw         $s3, 0x1C($sp)
    /* C3D40 002C3140 AFB20018 */  sw         $s2, 0x18($sp)
    /* C3D44 002C3144 8FB20038 */  lw         $s2, 0x38($sp)
    /* C3D48 002C3148 8FB3003C */  lw         $s3, 0x3C($sp)
    /* C3D4C 002C314C 02002021 */  addu       $a0, $s0, $zero
    /* C3D50 002C3150 02202821 */  addu       $a1, $s1, $zero
    /* C3D54 002C3154 AFBF0024 */  sw         $ra, 0x24($sp)
    /* C3D58 002C3158 02403021 */  addu       $a2, $s2, $zero
    /* C3D5C 002C315C 0C0B14C8 */  jal        __divdi3
    /* C3D60 002C3160 02603821 */   addu      $a3, $s3, $zero
    /* C3D64 002C3164 02002021 */  addu       $a0, $s0, $zero
    /* C3D68 002C3168 02202821 */  addu       $a1, $s1, $zero
    /* C3D6C 002C316C 02403021 */  addu       $a2, $s2, $zero
    /* C3D70 002C3170 AE820000 */  sw         $v0, 0x0($s4)
    /* C3D74 002C3174 AE830004 */  sw         $v1, 0x4($s4)
    /* C3D78 002C3178 0C0B1644 */  jal        __moddi3
    /* C3D7C 002C317C 02603821 */   addu      $a3, $s3, $zero
    /* C3D80 002C3180 AE820008 */  sw         $v0, 0x8($s4)
    /* C3D84 002C3184 AE83000C */  sw         $v1, 0xC($s4)
    /* C3D88 002C3188 8FBF0024 */  lw         $ra, 0x24($sp)
    /* C3D8C 002C318C 8FB40020 */  lw         $s4, 0x20($sp)
    /* C3D90 002C3190 8FB3001C */  lw         $s3, 0x1C($sp)
    /* C3D94 002C3194 8FB20018 */  lw         $s2, 0x18($sp)
    /* C3D98 002C3198 8FB10014 */  lw         $s1, 0x14($sp)
    /* C3D9C 002C319C 8FB00010 */  lw         $s0, 0x10($sp)
    /* C3DA0 002C31A0 03E00008 */  jr         $ra
    /* C3DA4 002C31A4 27BD0028 */   addiu     $sp, $sp, 0x28


    /* C3DA8 002C31A8 00003821 */  .word      0x00003821 /* linker padding */
    /* C3DAC 002C31AC AFA80020 */  .word      0xAFA80020 /* linker padding */
endlabel func_002C3120
