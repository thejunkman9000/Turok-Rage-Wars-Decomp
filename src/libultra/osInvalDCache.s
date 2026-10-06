.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2C60-0xC2D00 (VRAM 0x002C2060) */
glabel osInvalDCache
    /* C2C60 002C2060 18A0001A */  blez       $a1, .L002C20CC
    /* C2C64 002C2064 00000000 */   nop
    /* C2C68 002C2068 240B2000 */  addiu      $t3, $zero, 0x2000
    /* C2C6C 002C206C 00AB082B */  sltu       $at, $a1, $t3
    /* C2C70 002C2070 10200018 */  beqz       $at, .L002C20D4
    /* C2C74 002C2074 00804021 */   addu      $t0, $a0, $zero
    /* C2C78 002C2078 00854821 */  addu       $t1, $a0, $a1
    /* C2C7C 002C207C 0109082B */  sltu       $at, $t0, $t1
  .L002C2080:
    /* C2C80 002C2080 10200012 */  beqz       $at, .L002C20CC
    /* C2C84 002C2084 2529FFF0 */   addiu     $t1, $t1, -0x10
    /* C2C88 002C2088 310A000F */  andi       $t2, $t0, 0xF
    /* C2C8C 002C208C 11400005 */  beqz       $t2, .L002C20A4
    /* C2C90 002C2090 010A4023 */   subu      $t0, $t0, $t2
    /* C2C94 002C2094 BD150000 */  cache      0x15, 0x0($t0) /* handwritten instruction */
    /* C2C98 002C2098 0109082B */  sltu       $at, $t0, $t1
    /* C2C9C 002C209C 1020000B */  beqz       $at, .L002C20CC
    /* C2CA0 002C20A0 25080010 */   addiu     $t0, $t0, 0x10
  .L002C20A4:
    /* C2CA4 002C20A4 312A000F */  andi       $t2, $t1, 0xF
    /* C2CA8 002C20A8 11400004 */  beqz       $t2, .L002C20BC
    /* C2CAC 002C20AC 012A4823 */   subu      $t1, $t1, $t2
    /* C2CB0 002C20B0 BD350010 */  cache      0x15, 0x10($t1) /* handwritten instruction */
    /* C2CB4 002C20B4 0128082B */  sltu       $at, $t1, $t0
    /* C2CB8 002C20B8 14200004 */  bnez       $at, .L002C20CC
  .L002C20BC:
    /* C2CBC 002C20BC BD110000 */   cache     0x11, 0x0($t0) /* handwritten instruction */
    /* C2CC0 002C20C0 0109082B */  sltu       $at, $t0, $t1
    /* C2CC4 002C20C4 1420FFFD */  bnez       $at, .L002C20BC
    /* C2CC8 002C20C8 25080010 */   addiu     $t0, $t0, 0x10
  .L002C20CC:
    /* C2CCC 002C20CC 03E00008 */  jr         $ra
    /* C2CD0 002C20D0 00000000 */   nop
  .L002C20D4:
    /* C2CD4 002C20D4 3C088000 */  lui        $t0, 0x8000
    /* C2CD8 002C20D8 010B4821 */  addu       $t1, $t0, $t3
    /* C2CDC 002C20DC 2529FFF0 */  addiu      $t1, $t1, -0x10
  .L002C20E0:
    /* C2CE0 002C20E0 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* C2CE4 002C20E4 0109082B */  sltu       $at, $t0, $t1
    /* C2CE8 002C20E8 1420FFFD */  bnez       $at, .L002C20E0
    /* C2CEC 002C20EC 25080010 */   addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* C2CF0 002C20F0 03E00008 */  jr         $ra
    /* C2CF4 002C20F4 00000000 */   nop


    /* C2CF8 002C20F8 8FB70054 */  .word      0x8FB70054 /* linker padding */
    /* C2CFC 002C20FC 8FB60050 */  .word      0x8FB60050 /* linker padding */
endlabel osInvalDCache
