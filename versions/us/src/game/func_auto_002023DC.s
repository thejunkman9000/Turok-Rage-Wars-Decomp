.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly (TLB dump), US v1.0 ROM 0x2FDC-0x3060 (VRAM 0x002023DC), same words as v1.1 func_002023DC except the data address (D_auto_800F1660) */
glabel func_auto_002023DC
    /* 2FDC 002023DC 23BDFFF0 */  addi       $sp, $sp, -0x10 /* handwritten instruction */
    /* 2FE0 002023E0 AFA40000 */  sw         $a0, 0x0($sp)
    /* 2FE4 002023E4 AFA50004 */  sw         $a1, 0x4($sp)
    /* 2FE8 002023E8 AFA60008 */  sw         $a2, 0x8($sp)
    /* 2FEC 002023EC AFA7000C */  sw         $a3, 0xC($sp)
    /* 2FF0 002023F0 40025000 */  mfc0       $v0, $10 /* handwritten instruction */
    /* 2FF4 002023F4 2004001F */  addi       $a0, $zero, 0x1F /* handwritten instruction */
    /* 2FF8 002023F8 3C05800F */  lui        $a1, %hi(D_auto_800F1660)
    /* 2FFC 002023FC 24A51660 */  addiu      $a1, $a1, %lo(D_auto_800F1660)
  .Lauto_00202400:
    /* 3000 00202400 40840000 */  mtc0       $a0, $0 /* handwritten instruction */
    /* 3004 00202404 2084FFFF */  addi       $a0, $a0, -0x1 /* handwritten instruction */
    /* 3008 00202408 42000001 */  tlbr /* handwritten instruction */
    /* 300C 0020240C 00000000 */  nop
    /* 3010 00202410 00000000 */  nop
    /* 3014 00202414 00000000 */  nop
    /* 3018 00202418 00000000 */  nop
    /* 301C 0020241C 40062800 */  mfc0       $a2, $5 /* handwritten instruction */
    /* 3020 00202420 40075000 */  mfc0       $a3, $10 /* handwritten instruction */
    /* 3024 00202424 ACA60000 */  sw         $a2, 0x0($a1)
    /* 3028 00202428 ACA70004 */  sw         $a3, 0x4($a1)
    /* 302C 0020242C 40061000 */  mfc0       $a2, $2 /* handwritten instruction */
    /* 3030 00202430 40071800 */  mfc0       $a3, $3 /* handwritten instruction */
    /* 3034 00202434 ACA60008 */  sw         $a2, 0x8($a1)
    /* 3038 00202438 ACA7000C */  sw         $a3, 0xC($a1)
    /* 303C 0020243C 0481FFF0 */  .word      0x0481FFF0 /* was: bgez       $a0, .Lauto_00202400 */
    /* 3040 00202440 20A5FFF0 */   addi      $a1, $a1, -0x10 /* handwritten instruction */
    /* 3044 00202444 40825000 */  mtc0       $v0, $10 /* handwritten instruction */
    /* 3048 00202448 AFA40000 */  sw         $a0, 0x0($sp)
    /* 304C 0020244C AFA50004 */  sw         $a1, 0x4($sp)
    /* 3050 00202450 AFA60008 */  sw         $a2, 0x8($sp)
    /* 3054 00202454 AFA7000C */  sw         $a3, 0xC($sp)
    /* 3058 00202458 03E00008 */  jr         $ra
    /* 305C 0020245C 23BD0010 */   addi      $sp, $sp, 0x10 /* handwritten instruction */
endlabel func_auto_002023DC
