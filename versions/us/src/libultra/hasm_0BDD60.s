.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDD60-0xBDE50 (VRAM 0x002BD160) */
.globl osUnmapTLBAll
osUnmapTLBAll:
    /* BDD60 002BD160 40085000 */  mfc0       $t0, $10 /* handwritten instruction */
    /* BDD64 002BD164 2409001E */  addiu      $t1, $zero, 0x1E
    /* BDD68 002BD168 3C0A8000 */  lui        $t2, (0x80000000 >> 16)
    /* BDD6C 002BD16C 408A5000 */  mtc0       $t2, $10 /* handwritten instruction */
    /* BDD70 002BD170 40801000 */  mtc0       $zero, $2 /* handwritten instruction */
    /* BDD74 002BD174 40801800 */  mtc0       $zero, $3 /* handwritten instruction */
.Lauto_002BD178:
    /* BDD78 002BD178 40890000 */  mtc0       $t1, $0 /* handwritten instruction */
    /* BDD7C 002BD17C 00000000 */  nop
    /* BDD80 002BD180 42000002 */  tlbwi /* handwritten instruction */
    /* BDD84 002BD184 00000000 */  nop
    /* BDD88 002BD188 00000000 */  nop
    /* BDD8C 002BD18C 2129FFFF */  addi       $t1, $t1, -0x1 /* handwritten instruction */
    /* BDD90 002BD190 0521FFF9 */  .word 0x0521FFF9
    /* BDD94 002BD194 00000000 */  nop
    /* BDD98 002BD198 40885000 */  mtc0       $t0, $10 /* handwritten instruction */
    /* BDD9C 002BD19C 03E00008 */  jr         $ra
    /* BDDA0 002BD1A0 00000000 */  nop
.globl func_auto_002BD1A4
func_auto_002BD1A4:
    /* BDDA4 002BD1A4 0000000B */  .word 0x0000000B
    /* BDDA8 002BD1A8 6D5F4661 */  ldr        $ra, 0x4661($t2)
    /* BDDAC 002BD1AC 64654672 */  daddiu     $a1, $v1, 0x4672
.globl osWritebackDCache
osWritebackDCache:
    /* BDDB0 002BD1B0 18A0000E */  .word 0x18A0000E
    /* BDDB4 002BD1B4 240B2000 */  addiu     $t3, $zero, 0x2000
    /* BDDB8 002BD1B8 00AB082B */  sltu       $at, $a1, $t3
    /* BDDBC 002BD1BC 1020000D */  .word 0x1020000D
    /* BDDC0 002BD1C0 00804021 */  addu      $t0, $a0, $zero
    /* BDDC4 002BD1C4 00854821 */  addu       $t1, $a0, $a1
    /* BDDC8 002BD1C8 0109082B */  sltu       $at, $t0, $t1
    /* BDDCC 002BD1CC 10200007 */  .word 0x10200007
    /* BDDD0 002BD1D0 2529FFF0 */  addiu     $t1, $t1, -0x10
    /* BDDD4 002BD1D4 310A000F */  andi       $t2, $t0, 0xF
    /* BDDD8 002BD1D8 010A4023 */  subu       $t0, $t0, $t2
.Lauto_002BD1DC:
    /* BDDDC 002BD1DC BD190000 */  cache      0x19, 0x0($t0) /* handwritten instruction */
    /* BDDE0 002BD1E0 0109082B */  sltu       $at, $t0, $t1
    /* BDDE4 002BD1E4 1420FFFD */  .word 0x1420FFFD
    /* BDDE8 002BD1E8 25080010 */  addiu     $t0, $t0, 0x10
.Lauto_002BD1EC:
    /* BDDEC 002BD1EC 03E00008 */  jr         $ra
    /* BDDF0 002BD1F0 00000000 */  nop
.Lauto_002BD1F4:
    /* BDDF4 002BD1F4 3C088000 */  lui        $t0, 0x8000
    /* BDDF8 002BD1F8 010B4821 */  addu       $t1, $t0, $t3
    /* BDDFC 002BD1FC 2529FFF0 */  addiu      $t1, $t1, -0x10
.Lauto_002BD200:
    /* BDE00 002BD200 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* BDE04 002BD204 0109082B */  sltu       $at, $t0, $t1
    /* BDE08 002BD208 1420FFFD */  .word 0x1420FFFD
    /* BDE0C 002BD20C 25080010 */  addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* BDE10 002BD210 03E00008 */  jr         $ra
    /* BDE14 002BD214 00000000 */  nop
.globl func_auto_002BD218
func_auto_002BD218:
    /* BDE18 002BD218 656F7354 */  daddiu     $t7, $t3, 0x7354
    /* BDE1C 002BD21C 00000000 */  nop
.globl osWritebackDCacheAll
osWritebackDCacheAll:
    /* BDE20 002BD220 3C088000 */  lui        $t0, 0x8000
    /* BDE24 002BD224 240A2000 */  addiu      $t2, $zero, 0x2000
    /* BDE28 002BD228 010A4821 */  addu       $t1, $t0, $t2
    /* BDE2C 002BD22C 2529FFF0 */  addiu      $t1, $t1, -0x10
.Lauto_002BD230:
    /* BDE30 002BD230 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* BDE34 002BD234 0109082B */  sltu       $at, $t0, $t1
    /* BDE38 002BD238 1420FFFD */  .word 0x1420FFFD
    /* BDE3C 002BD23C 25080010 */  addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* BDE40 002BD240 03E00008 */  jr         $ra
    /* BDE44 002BD244 00000000 */  nop
.globl func_auto_002BD248
func_auto_002BD248:
    /* BDE48 002BD248 53746174 */  .word 0x53746174
    /* BDE4C 002BD24C 6963496E */  ldl       $v1, 0x496E($t3)
