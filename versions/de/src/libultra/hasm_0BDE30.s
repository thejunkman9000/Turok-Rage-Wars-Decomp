.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDE30-0xBDE74 (VRAM 0x002BD230) */
.globl osUnmapTLBAll
osUnmapTLBAll:
    /* BDE30 002BD230 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* BDE34 002BD234 2409001E */  addiu      $t1, $zero, 0x1E
    /* BDE38 002BD238 3C0A8000 */  lui        $t2, (0x80000000 >> 16)
    /* BDE3C 002BD23C 408A5000 */  mtc0       $t2, $10 /* handwritten instruction */
    /* BDE40 002BD240 40801000 */  mtc0       $zero, $2 /* handwritten instruction */
    /* BDE44 002BD244 40801800 */  mtc0       $zero, $3 /* handwritten instruction */
.Lauto_002BD248:
    /* BDE48 002BD248 40890000 */  mtc0       $t1, $0 /* handwritten instruction */
    /* BDE4C 002BD24C 00000000 */  nop
    /* BDE50 002BD250 42000002 */  tlbwi /* handwritten instruction */
    /* BDE54 002BD254 00000000 */  nop
    /* BDE58 002BD258 00000000 */  nop
    /* BDE5C 002BD25C 2129FFFF */  addi       $t1, $t1, -0x1 /* handwritten instruction */
    /* BDE60 002BD260 0521FFF9 */  .word 0x0521FFF9
    /* BDE64 002BD264 00000000 */  nop
    /* BDE68 002BD268 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* BDE6C 002BD26C 03E00008 */  jr         $ra
    /* BDE70 002BD270 00000000 */  nop
