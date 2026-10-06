.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB98C8-0xB98F4 (VRAM 0x002B8CC8) */
glabel func_002B8CC8
    /* B98C8 002B8CC8 3C04800E */  lui        $a0, %hi(D_800D80A0)
    /* B98CC 002B8CCC 8C8480A0 */  lw         $a0, %lo(D_800D80A0)($a0)
    /* B98D0 002B8CD0 8C82002C */  lw         $v0, 0x2C($a0)
    /* B98D4 002B8CD4 10400005 */  beqz       $v0, .L002B8CEC
    /* B98D8 002B8CD8 00001821 */   addu      $v1, $zero, $zero
    /* B98DC 002B8CDC 00401821 */  addu       $v1, $v0, $zero
    /* B98E0 002B8CE0 8C620000 */  lw         $v0, 0x0($v1)
    /* B98E4 002B8CE4 AC82002C */  sw         $v0, 0x2C($a0)
    /* B98E8 002B8CE8 AC600000 */  sw         $zero, 0x0($v1)
  .L002B8CEC:
    /* B98EC 002B8CEC 03E00008 */  jr         $ra
    /* B98F0 002B8CF0 00601021 */   addu      $v0, $v1, $zero
endlabel func_002B8CC8
