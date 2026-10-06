.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB81A0-0xB81E0 (VRAM 0x002B75A0) */
glabel alClose
    /* B81A0 002B75A0 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B81A4 002B75A4 AFB00010 */  sw         $s0, 0x10($sp)
    /* B81A8 002B75A8 3C10800E */  lui        $s0, %hi(D_800D80A0)
    /* B81AC 002B75AC 261080A0 */  addiu      $s0, $s0, %lo(D_800D80A0)
    /* B81B0 002B75B0 AFBF0014 */  sw         $ra, 0x14($sp)
    /* B81B4 002B75B4 8E020000 */  lw         $v0, 0x0($s0)
    /* B81B8 002B75B8 10400004 */  beqz       $v0, .L002B75CC
    /* B81BC 002B75BC 00000000 */   nop
    /* B81C0 002B75C0 0C0AE0B0 */  jal        alSynDelete
    /* B81C4 002B75C4 00000000 */   nop
    /* B81C8 002B75C8 AE000000 */  sw         $zero, 0x0($s0)
  .L002B75CC:
    /* B81CC 002B75CC 8FBF0014 */  lw         $ra, 0x14($sp)
    /* B81D0 002B75D0 8FB00010 */  lw         $s0, 0x10($sp)
    /* B81D4 002B75D4 03E00008 */  jr         $ra
    /* B81D8 002B75D8 27BD0018 */   addiu     $sp, $sp, 0x18


    /* B81DC 002B75DC 8C820008 */  .word      0x8C820008 /* linker padding */
endlabel alClose
