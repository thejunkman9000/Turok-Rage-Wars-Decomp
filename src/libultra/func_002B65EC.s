.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB71EC-0xB723C (VRAM 0x002B65EC) */
glabel func_002B65EC
    /* B71EC 002B65EC 8C83006C */  lw         $v1, 0x6C($a0)
    /* B71F0 002B65F0 10600010 */  beqz       $v1, .L002B6634
    /* B71F4 002B65F4 00000000 */   nop
    /* B71F8 002B65F8 8C620000 */  lw         $v0, 0x0($v1)
    /* B71FC 002B65FC AC82006C */  sw         $v0, 0x6C($a0)
    /* B7200 002B6600 AC600000 */  sw         $zero, 0x0($v1)
    /* B7204 002B6604 8C820064 */  lw         $v0, 0x64($a0)
    /* B7208 002B6608 14400003 */  bnez       $v0, .L002B6618
    /* B720C 002B660C 00000000 */   nop
    /* B7210 002B6610 080AD988 */  j          .L002B6620
    /* B7214 002B6614 AC830064 */   sw        $v1, 0x64($a0)
  .L002B6618:
    /* B7218 002B6618 8C820068 */  lw         $v0, 0x68($a0)
    /* B721C 002B661C AC430000 */  sw         $v1, 0x0($v0)
  .L002B6620:
    /* B7220 002B6620 AC830068 */  sw         $v1, 0x68($a0)
    /* B7224 002B6624 A0670031 */  sb         $a3, 0x31($v1)
    /* B7228 002B6628 A0650032 */  sb         $a1, 0x32($v1)
    /* B722C 002B662C A0660033 */  sb         $a2, 0x33($v1)
    /* B7230 002B6630 AC630014 */  sw         $v1, 0x14($v1)
  .L002B6634:
    /* B7234 002B6634 03E00008 */  jr         $ra
    /* B7238 002B6638 00601021 */   addu      $v0, $v1, $zero
endlabel func_002B65EC
