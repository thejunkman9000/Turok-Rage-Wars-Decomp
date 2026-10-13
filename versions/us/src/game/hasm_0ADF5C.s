.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xADF5C-0xADFF0 (VRAM 0x002AD35C) */
.globl osReadAllTLBEntries
osReadAllTLBEntries:
    /* ADF5C 002AD35C 00001020 */  add        $v0, $zero, $zero /* handwritten instruction */
    /* ADF60 002AD360 2005001E */  addi       $a1, $zero, 0x1E /* handwritten instruction */
    /* ADF64 002AD364 3C04800D */  lui        $a0, %hi(D_auto_800D2C20)
    /* ADF68 002AD368 24842C20 */  addiu      $a0, $a0, %lo(D_auto_800D2C20)
    /* ADF6C 002AD36C 2006014C */  addi       $a2, $zero, 0x14C /* handwritten instruction */
.Lauto_002AD370:
    /* ADF70 002AD370 40820000 */  mtc0       $v0, $0 /* handwritten instruction */
    /* ADF74 002AD374 42000001 */  tlbr /* handwritten instruction */
    /* ADF78 002AD378 00000000 */  nop
    /* ADF7C 002AD37C 00000000 */  nop
    /* ADF80 002AD380 00000000 */  nop
    /* ADF84 002AD384 00000000 */  nop
    /* ADF88 002AD388 40032800 */  mfc0       $v1, $5 /* handwritten instruction */
    /* ADF8C 002AD38C 00000000 */  nop
    /* ADF90 002AD390 00031B42 */  srl        $v1, $v1, 13
    /* ADF94 002AD394 A4830000 */  sh         $v1, 0x0($a0)
    /* ADF98 002AD398 40035000 */  mfc0       $v1, $10 /* handwritten instruction */
    /* ADF9C 002AD39C 00000000 */  nop
    /* ADFA0 002AD3A0 00031B02 */  srl        $v1, $v1, 12
    /* ADFA4 002AD3A4 A4830002 */  sh         $v1, 0x2($a0)
    /* ADFA8 002AD3A8 40031000 */  mfc0       $v1, $2 /* handwritten instruction */
    /* ADFAC 002AD3AC 00000000 */  nop
    /* ADFB0 002AD3B0 00031982 */  srl        $v1, $v1, 6
    /* ADFB4 002AD3B4 00661822 */  sub        $v1, $v1, $a2 /* handwritten instruction */
    /* ADFB8 002AD3B8 A4830004 */  sh         $v1, 0x4($a0)
    /* ADFBC 002AD3BC 40031800 */  mfc0       $v1, $3 /* handwritten instruction */
    /* ADFC0 002AD3C0 00000000 */  nop
    /* ADFC4 002AD3C4 00031982 */  srl        $v1, $v1, 6
    /* ADFC8 002AD3C8 00661822 */  sub        $v1, $v1, $a2 /* handwritten instruction */
    /* ADFCC 002AD3CC A4830006 */  sh         $v1, 0x6($a0)
    /* ADFD0 002AD3D0 20840008 */  addi       $a0, $a0, 0x8 /* handwritten instruction */
    /* ADFD4 002AD3D4 14A2FFE6 */  .word 0x14A2FFE6
    /* ADFD8 002AD3D8 20420001 */  addi      $v0, $v0, 0x1 /* handwritten instruction */
    /* ADFDC 002AD3DC 03E00008 */  jr         $ra
    /* ADFE0 002AD3E0 00000000 */  nop
.globl D_auto_002AD3E4
D_auto_002AD3E4:
    /* ADFE4 002AD3E4 00000800 */  .word 0x00000800
    /* ADFE8 002AD3E8 0D000000 */  .word 0x0D000000
    /* ADFEC 002AD3EC 0000086D */  .word 0x0000086D
