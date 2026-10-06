.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB802C-0xB8080 (VRAM 0x002B742C) */
glabel func_002B742C
    /* B802C 002B742C 8C820008 */  lw         $v0, 0x8($a0)
    /* B8030 002B7430 90450000 */  lbu        $a1, 0x0($v0)
    /* B8034 002B7434 24420001 */  addiu      $v0, $v0, 0x1
    /* B8038 002B7438 AC820008 */  sw         $v0, 0x8($a0)
    /* B803C 002B743C 00A01821 */  addu       $v1, $a1, $zero
    /* B8040 002B7440 30620080 */  andi       $v0, $v1, 0x80
    /* B8044 002B7444 1040000C */  beqz       $v0, .L002B7478
    /* B8048 002B7448 00000000 */   nop
    /* B804C 002B744C 3063007F */  andi       $v1, $v1, 0x7F
  .L002B7450:
    /* B8050 002B7450 8C820008 */  lw         $v0, 0x8($a0)
    /* B8054 002B7454 000319C0 */  sll        $v1, $v1, 7
    /* B8058 002B7458 90450000 */  lbu        $a1, 0x0($v0)
    /* B805C 002B745C 24420001 */  addiu      $v0, $v0, 0x1
    /* B8060 002B7460 AC820008 */  sw         $v0, 0x8($a0)
    /* B8064 002B7464 30A2007F */  andi       $v0, $a1, 0x7F
    /* B8068 002B7468 00621821 */  addu       $v1, $v1, $v0
    /* B806C 002B746C 30A20080 */  andi       $v0, $a1, 0x80
    /* B8070 002B7470 1440FFF7 */  bnez       $v0, .L002B7450
    /* B8074 002B7474 00000000 */   nop
  .L002B7478:
    /* B8078 002B7478 03E00008 */  jr         $ra
    /* B807C 002B747C 00601021 */   addu      $v0, $v1, $zero
endlabel func_002B742C
