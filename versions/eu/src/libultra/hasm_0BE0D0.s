.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBE0D0-0xBE114 (VRAM 0x002BD4D0) */
.globl osUnmapTLBAll
osUnmapTLBAll:
    /* BE0D0 002BD4D0 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* BE0D4 002BD4D4 2409001E */  addiu      $t1, $zero, 0x1E
    /* BE0D8 002BD4D8 3C0A8000 */  lui        $t2, (0x80000000 >> 16)
.Lauto_002BD4DC:
    /* BE0DC 002BD4DC 408A5000 */  mtc0       $t2, $10 /* handwritten instruction */
    /* BE0E0 002BD4E0 40801000 */  mtc0       $zero, $2 /* handwritten instruction */
    /* BE0E4 002BD4E4 40801800 */  mtc0       $zero, $3 /* handwritten instruction */
.Lauto_002BD4E8:
    /* BE0E8 002BD4E8 40890000 */  mtc0       $t1, $0 /* handwritten instruction */
    /* BE0EC 002BD4EC 00000000 */  nop
    /* BE0F0 002BD4F0 42000002 */  tlbwi /* handwritten instruction */
    /* BE0F4 002BD4F4 00000000 */  nop
    /* BE0F8 002BD4F8 00000000 */  nop
    /* BE0FC 002BD4FC 2129FFFF */  addi       $t1, $t1, -0x1 /* handwritten instruction */
    /* BE100 002BD500 0521FFF9 */  .word 0x0521FFF9
    /* BE104 002BD504 00000000 */  nop
    /* BE108 002BD508 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* BE10C 002BD50C 03E00008 */  jr         $ra
    /* BE110 002BD510 00000000 */  nop
