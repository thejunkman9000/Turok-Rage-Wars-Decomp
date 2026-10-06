.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB30FC-0xB3190 (VRAM 0x002B24FC) */
glabel osReadAllTLBEntries
    /* B30FC 002B24FC 00001020 */  add        $v0, $zero, $zero /* handwritten instruction */
    /* B3100 002B2500 2005001E */  addi       $a1, $zero, 0x1E /* handwritten instruction */
    /* B3104 002B2504 3C04800D */  lui        $a0, %hi(D_800D7FA0)
    /* B3108 002B2508 24847FA0 */  addiu      $a0, $a0, %lo(D_800D7FA0)
    /* B310C 002B250C 20060156 */  addi       $a2, $zero, 0x156 /* handwritten instruction */
  .L002B2510:
    /* B3110 002B2510 40820000 */  mtc0       $v0, $0 /* handwritten instruction */
    /* B3114 002B2514 42000001 */  tlbr /* handwritten instruction */
    /* B3118 002B2518 00000000 */  nop
    /* B311C 002B251C 00000000 */  nop
    /* B3120 002B2520 00000000 */  nop
    /* B3124 002B2524 00000000 */  nop
    /* B3128 002B2528 40032800 */  mfc0       $v1, $5 /* handwritten instruction */
    /* B312C 002B252C 00000000 */  nop
    /* B3130 002B2530 00031B42 */  srl        $v1, $v1, 13
    /* B3134 002B2534 A4830000 */  sh         $v1, 0x0($a0)
    /* B3138 002B2538 40035000 */  mfc0       $v1, $10 /* handwritten instruction */
    /* B313C 002B253C 00000000 */  nop
    /* B3140 002B2540 00031B02 */  srl        $v1, $v1, 12
    /* B3144 002B2544 A4830002 */  sh         $v1, 0x2($a0)
    /* B3148 002B2548 40031000 */  mfc0       $v1, $2 /* handwritten instruction */
    /* B314C 002B254C 00000000 */  nop
    /* B3150 002B2550 00031982 */  srl        $v1, $v1, 6
    /* B3154 002B2554 00661822 */  sub        $v1, $v1, $a2 /* handwritten instruction */
    /* B3158 002B2558 A4830004 */  sh         $v1, 0x4($a0)
    /* B315C 002B255C 40031800 */  mfc0       $v1, $3 /* handwritten instruction */
    /* B3160 002B2560 00000000 */  nop
    /* B3164 002B2564 00031982 */  srl        $v1, $v1, 6
    /* B3168 002B2568 00661822 */  sub        $v1, $v1, $a2 /* handwritten instruction */
    /* B316C 002B256C A4830006 */  sh         $v1, 0x6($a0)
    /* B3170 002B2570 20840008 */  addi       $a0, $a0, 0x8 /* handwritten instruction */
    /* B3174 002B2574 14A2FFE6 */  bne        $a1, $v0, .L002B2510
    /* B3178 002B2578 20420001 */   addi      $v0, $v0, 0x1 /* handwritten instruction */
    /* B317C 002B257C 03E00008 */  jr         $ra
    /* B3180 002B2580 00000000 */   nop


    /* B3184 002B2584 AFA20034 */  .word      0xAFA20034 /* linker padding */
    /* B3188 002B2588 24020004 */  .word      0x24020004 /* linker padding */
    /* B318C 002B258C 10620005 */  .word      0x10620005 /* linker padding */
endlabel osReadAllTLBEntries
