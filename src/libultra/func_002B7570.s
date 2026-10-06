.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8170-0xB81A0 (VRAM 0x002B7570) */
glabel func_002B7570
    /* B8170 002B7570 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B8174 002B7574 3C03800E */  lui        $v1, %hi(D_800D80A0)
    /* B8178 002B7578 246380A0 */  addiu      $v1, $v1, %lo(D_800D80A0)
    /* B817C 002B757C AFBF0010 */  sw         $ra, 0x10($sp)
    /* B8180 002B7580 8C620000 */  lw         $v0, 0x0($v1)
    /* B8184 002B7584 14400003 */  bnez       $v0, .L002B7594
    /* B8188 002B7588 00000000 */   nop
    /* B818C 002B758C 0C0AE210 */  jal        func_002B8840
    /* B8190 002B7590 AC640000 */   sw        $a0, 0x0($v1)
  .L002B7594:
    /* B8194 002B7594 8FBF0010 */  lw         $ra, 0x10($sp)
    /* B8198 002B7598 03E00008 */  jr         $ra
    /* B819C 002B759C 27BD0018 */   addiu     $sp, $sp, 0x18
endlabel func_002B7570
