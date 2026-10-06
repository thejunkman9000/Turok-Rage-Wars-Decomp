.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8C80-0xB8CD0 (VRAM 0x002B8080) */
glabel alSynAddPlayer
    /* B8C80 002B8080 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B8C84 002B8084 AFB10014 */  sw         $s1, 0x14($sp)
    /* B8C88 002B8088 00808821 */  addu       $s1, $a0, $zero
    /* B8C8C 002B808C AFB00010 */  sw         $s0, 0x10($sp)
    /* B8C90 002B8090 00A08021 */  addu       $s0, $a1, $zero
    /* B8C94 002B8094 AFBF0018 */  sw         $ra, 0x18($sp)
    /* B8C98 002B8098 0C0B0898 */  jal        osSetIntMask
    /* B8C9C 002B809C 24040001 */   addiu     $a0, $zero, 0x1
    /* B8CA0 002B80A0 8E230020 */  lw         $v1, 0x20($s1)
    /* B8CA4 002B80A4 AE030010 */  sw         $v1, 0x10($s0)
    /* B8CA8 002B80A8 8E230000 */  lw         $v1, 0x0($s1)
    /* B8CAC 002B80AC 00402021 */  addu       $a0, $v0, $zero
    /* B8CB0 002B80B0 AE030000 */  sw         $v1, 0x0($s0)
    /* B8CB4 002B80B4 0C0B0898 */  jal        osSetIntMask
    /* B8CB8 002B80B8 AE300000 */   sw        $s0, 0x0($s1)
    /* B8CBC 002B80BC 8FBF0018 */  lw         $ra, 0x18($sp)
    /* B8CC0 002B80C0 8FB10014 */  lw         $s1, 0x14($sp)
    /* B8CC4 002B80C4 8FB00010 */  lw         $s0, 0x10($sp)
    /* B8CC8 002B80C8 03E00008 */  jr         $ra
    /* B8CCC 002B80CC 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel alSynAddPlayer
