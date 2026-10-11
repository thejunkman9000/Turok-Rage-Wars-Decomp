.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x34D0-0x3594 (VRAM 0x002028D0) */
glabel func_002028D0
    /* 34D0 002028D0 3C038000 */  lui        $v1, (0x80000180 >> 16)
    /* 34D4 002028D4 34630180 */  ori        $v1, $v1, (0x80000180 & 0xFFFF)
    /* 34D8 002028D8 3C020020 */  lui        $v0, %hi(func_00202268 + 0x1C)
    /* 34DC 002028DC 24422284 */  addiu      $v0, $v0, %lo(func_00202268 + 0x1C)
    /* 34E0 002028E0 20440014 */  addi       $a0, $v0, 0x14 /* handwritten instruction */
  .L002028E4:
    /* 34E4 002028E4 8C410000 */  lw         $at, 0x0($v0)
    /* 34E8 002028E8 20420004 */  addi       $v0, $v0, 0x4 /* handwritten instruction */
    /* 34EC 002028EC AC610000 */  sw         $at, 0x0($v1)
    /* 34F0 002028F0 20630004 */  addi       $v1, $v1, 0x4 /* handwritten instruction */
    /* 34F4 002028F4 1444FFFB */  bne        $v0, $a0, .L002028E4
    /* 34F8 002028F8 00000000 */   nop
    /* 34FC 002028FC 3C038000 */  lui        $v1, %hi(D_80000000)
    /* 3500 00202900 3C020020 */  lui        $v0, %hi(func_00202268 + 0x54)
    /* 3504 00202904 244222BC */  addiu      $v0, $v0, %lo(func_00202268 + 0x54)
    /* 3508 00202908 20440014 */  addi       $a0, $v0, 0x14 /* handwritten instruction */
  .L0020290C:
    /* 350C 0020290C 8C410000 */  lw         $at, 0x0($v0)
    /* 3510 00202910 20420004 */  addi       $v0, $v0, 0x4 /* handwritten instruction */
    /* 3514 00202914 AC610000 */  sw         $at, %lo(D_80000000)($v1)
    /* 3518 00202918 20630004 */  addi       $v1, $v1, %lo(D_80000004) /* handwritten instruction */
    /* 351C 0020291C 1444FFFB */  bne        $v0, $a0, .L0020290C
    /* 3520 00202920 00000000 */   nop
    /* 3524 00202924 0C0808E3 */  jal        func_0020238C
    /* 3528 00202928 00000000 */   nop
    /* 352C 0020292C 0C0808EA */  jal        func_002023A8
    /* 3530 00202930 00000000 */   nop
    /* 3534 00202934 03E00008 */  jr         $ra
    /* 3538 00202938 00000000 */   nop
    /* 353C 0020293C AF440338 */  sw         $a0, 0x338($k0) /* handwritten instruction */
    /* 3540 00202940 08080A5D */  j          .L00202974
    /* 3544 00202944 00000000 */   nop
    /* 3548 00202948 40017000 */  mfc0       $at, $14 /* handwritten instruction */
    /* 354C 0020294C 00000000 */  nop
    /* 3550 00202950 24210004 */  addiu      $at, $at, 0x4
    /* 3554 00202954 40817000 */  mtc0       $at, $14 /* handwritten instruction */
    /* 3558 00202958 24010000 */  addiu      $at, $zero, 0x0
    /* 355C 0020295C 08080984 */  .word      0x08080984 /* was: j          .L00202610 */
    /* 3560 00202960 00000000 */   nop
    /* 3564 00202964 3C020020 */  lui        $v0, %hi(func_002013D8)
    /* 3568 00202968 244213D8 */  addiu      $v0, $v0, %lo(func_002013D8)
    /* 356C 0020296C 08080A5E */  j          .L00202978
    /* 3570 00202970 00000000 */   nop
  .L00202974:
    /* 3574 00202974 DF420330 */  ld         $v0, 0x330($k0) /* handwritten instruction */
  .L00202978:
    /* 3578 00202978 40017000 */  mfc0       $at, $14 /* handwritten instruction */
    /* 357C 0020297C 00000000 */  nop
    /* 3580 00202980 24210004 */  addiu      $at, $at, 0x4
    /* 3584 00202984 40817000 */  mtc0       $at, $14 /* handwritten instruction */
    /* 3588 00202988 DF410328 */  ld         $at, 0x328($k0) /* handwritten instruction */
    /* 358C 0020298C 401AF000 */  mfc0       $k0, $30 /* handwritten instruction */
    /* 3590 00202990 42000018 */  eret /* handwritten instruction */
endlabel func_002028D0
