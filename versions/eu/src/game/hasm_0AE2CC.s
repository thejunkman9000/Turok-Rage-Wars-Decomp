.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xAE2CC-0xAE354 (VRAM 0x002AD6CC) */
.globl osReadAllTLBEntries
osReadAllTLBEntries:
    /* AE2CC 002AD6CC 00001020 */  add        $v0, $zero, $zero /* handwritten instruction */
    /* AE2D0 002AD6D0 2005001E */  addi       $a1, $zero, 0x1E /* handwritten instruction */
    /* AE2D4 002AD6D4 3C04800E */  lui        $a0, %hi(D_auto_800E45F0)
    /* AE2D8 002AD6D8 248445F0 */  addiu      $a0, $a0, %lo(D_auto_800E45F0)
    /* AE2DC 002AD6DC 2006015E */  addi       $a2, $zero, 0x15E /* handwritten instruction */
.Lauto_002AD6E0:
    /* AE2E0 002AD6E0 40820000 */  mtc0       $v0, $0 /* handwritten instruction */
    /* AE2E4 002AD6E4 42000001 */  tlbr /* handwritten instruction */
    /* AE2E8 002AD6E8 00000000 */  nop
    /* AE2EC 002AD6EC 00000000 */  nop
    /* AE2F0 002AD6F0 00000000 */  nop
    /* AE2F4 002AD6F4 00000000 */  nop
    /* AE2F8 002AD6F8 40032800 */  mfc0       $v1, $5 /* handwritten instruction */
    /* AE2FC 002AD6FC 00000000 */  nop
    /* AE300 002AD700 00031B42 */  srl        $v1, $v1, 13
    /* AE304 002AD704 A4830000 */  sh         $v1, 0x0($a0)
    /* AE308 002AD708 40035000 */  mfc0       $v1, $10 /* handwritten instruction */
    /* AE30C 002AD70C 00000000 */  nop
    /* AE310 002AD710 00031B02 */  srl        $v1, $v1, 12
    /* AE314 002AD714 A4830002 */  sh         $v1, 0x2($a0)
    /* AE318 002AD718 40031000 */  mfc0       $v1, $2 /* handwritten instruction */
    /* AE31C 002AD71C 00000000 */  nop
    /* AE320 002AD720 00031982 */  srl        $v1, $v1, 6
    /* AE324 002AD724 00661822 */  sub        $v1, $v1, $a2 /* handwritten instruction */
    /* AE328 002AD728 A4830004 */  sh         $v1, 0x4($a0)
    /* AE32C 002AD72C 40031800 */  mfc0       $v1, $3 /* handwritten instruction */
    /* AE330 002AD730 00000000 */  nop
    /* AE334 002AD734 00031982 */  srl        $v1, $v1, 6
    /* AE338 002AD738 00661822 */  sub        $v1, $v1, $a2 /* handwritten instruction */
    /* AE33C 002AD73C A4830006 */  sh         $v1, 0x6($a0)
    /* AE340 002AD740 20840008 */  addi       $a0, $a0, 0x8 /* handwritten instruction */
    /* AE344 002AD744 14A2FFE6 */  .word 0x14A2FFE6
    /* AE348 002AD748 20420001 */  addi      $v0, $v0, 0x1 /* handwritten instruction */
    /* AE34C 002AD74C 03E00008 */  jr         $ra
    /* AE350 002AD750 00000000 */  nop
