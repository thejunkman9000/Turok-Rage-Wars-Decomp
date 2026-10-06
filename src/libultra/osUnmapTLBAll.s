.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC2F20-0xC2F70 (VRAM 0x002C2320) */
glabel osUnmapTLBAll
    /* C2F20 002C2320 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* C2F24 002C2324 2409001E */  addiu      $t1, $zero, 0x1E
    /* C2F28 002C2328 3C0A8000 */  lui        $t2, (0x80000000 >> 16)
    /* C2F2C 002C232C 408A5000 */  mtc0       $t2, $10 /* handwritten instruction */
    /* C2F30 002C2330 40801000 */  mtc0       $zero, $2 /* handwritten instruction */
    /* C2F34 002C2334 40801800 */  mtc0       $zero, $3 /* handwritten instruction */
  .L002C2338:
    /* C2F38 002C2338 40890000 */  mtc0       $t1, $0 /* handwritten instruction */
    /* C2F3C 002C233C 00000000 */  nop
    /* C2F40 002C2340 42000002 */  tlbwi /* handwritten instruction */
    /* C2F44 002C2344 00000000 */  nop
    /* C2F48 002C2348 00000000 */  nop
    /* C2F4C 002C234C 2129FFFF */  addi       $t1, $t1, -0x1 /* handwritten instruction */
    /* C2F50 002C2350 0521FFF9 */  bgez       $t1, .L002C2338
    /* C2F54 002C2354 00000000 */   nop
    /* C2F58 002C2358 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* C2F5C 002C235C 03E00008 */  jr         $ra
    /* C2F60 002C2360 00000000 */   nop


    /* C2F64 002C2364 2402FFFF */  .word      0x2402FFFF /* linker padding */
    /* C2F68 002C2368 10620004 */  .word      0x10620004 /* linker padding */
    /* C2F6C 002C236C 02B1A823 */  .word      0x02B1A823 /* linker padding */
endlabel osUnmapTLBAll
