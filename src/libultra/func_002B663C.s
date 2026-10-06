.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB723C-0xB72A0 (VRAM 0x002B663C) */
glabel func_002B663C
    /* B723C 002B663C 8C830064 */  lw         $v1, 0x64($a0)
    /* B7240 002B6640 10600015 */  beqz       $v1, .L002B6698
    /* B7244 002B6644 00003021 */   addu      $a2, $zero, $zero
    /* B7248 002B6648 24620004 */  addiu      $v0, $v1, 0x4
  .L002B664C:
    /* B724C 002B664C 5445000F */  bnel       $v0, $a1, .L002B668C
    /* B7250 002B6650 00603021 */   addu      $a2, $v1, $zero
    /* B7254 002B6654 10C00004 */  beqz       $a2, .L002B6668
    /* B7258 002B6658 00000000 */   nop
    /* B725C 002B665C 8C620000 */  lw         $v0, 0x0($v1)
    /* B7260 002B6660 080AD99C */  j          .L002B6670
    /* B7264 002B6664 ACC20000 */   sw        $v0, 0x0($a2)
  .L002B6668:
    /* B7268 002B6668 8C620000 */  lw         $v0, 0x0($v1)
    /* B726C 002B666C AC820064 */  sw         $v0, 0x64($a0)
  .L002B6670:
    /* B7270 002B6670 8C820068 */  lw         $v0, 0x68($a0)
    /* B7274 002B6674 50620001 */  beql       $v1, $v0, .L002B667C
    /* B7278 002B6678 AC860068 */   sw        $a2, 0x68($a0)
  .L002B667C:
    /* B727C 002B667C 8C82006C */  lw         $v0, 0x6C($a0)
    /* B7280 002B6680 AC620000 */  sw         $v0, 0x0($v1)
    /* B7284 002B6684 03E00008 */  jr         $ra
    /* B7288 002B6688 AC83006C */   sw        $v1, 0x6C($a0)
  .L002B668C:
    /* B728C 002B668C 8C630000 */  lw         $v1, 0x0($v1)
    /* B7290 002B6690 1460FFEE */  bnez       $v1, .L002B664C
    /* B7294 002B6694 24620004 */   addiu     $v0, $v1, 0x4
  .L002B6698:
    /* B7298 002B6698 03E00008 */  jr         $ra
    /* B729C 002B669C 00000000 */   nop
endlabel func_002B663C
