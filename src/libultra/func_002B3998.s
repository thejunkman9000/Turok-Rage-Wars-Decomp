.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB4598-0xB460C (VRAM 0x002B3998) */
glabel func_002B3998
    /* B4598 002B3998 00804821 */  addu       $t1, $a0, $zero
    /* B459C 002B399C 8CA20000 */  lw         $v0, 0x0($a1)
    /* B45A0 002B39A0 00004021 */  addu       $t0, $zero, $zero
    /* B45A4 002B39A4 AD220004 */  sw         $v0, 0x4($t1)
    /* B45A8 002B39A8 8CA20004 */  lw         $v0, 0x4($a1)
    /* B45AC 002B39AC 00A03821 */  addu       $a3, $a1, $zero
    /* B45B0 002B39B0 AD22000C */  sw         $v0, 0xC($t1)
    /* B45B4 002B39B4 8CA20008 */  lw         $v0, 0x8($a1)
    /* B45B8 002B39B8 01203021 */  addu       $a2, $t1, $zero
    /* B45BC 002B39BC AD220010 */  sw         $v0, 0x10($t1)
  .L002B39C0:
    /* B45C0 002B39C0 8CE2000C */  lw         $v0, 0xC($a3)
    /* B45C4 002B39C4 ACC20018 */  sw         $v0, 0x18($a2)
    /* B45C8 002B39C8 8CE2004C */  lw         $v0, 0x4C($a3)
    /* B45CC 002B39CC 00A81821 */  addu       $v1, $a1, $t0
    /* B45D0 002B39D0 ACC20058 */  sw         $v0, 0x58($a2)
    /* B45D4 002B39D4 9062008C */  lbu        $v0, 0x8C($v1)
    /* B45D8 002B39D8 01282021 */  addu       $a0, $t1, $t0
    /* B45DC 002B39DC A0820098 */  sb         $v0, 0x98($a0)
    /* B45E0 002B39E0 9062009C */  lbu        $v0, 0x9C($v1)
    /* B45E4 002B39E4 25080001 */  addiu      $t0, $t0, 0x1
    /* B45E8 002B39E8 A08200A8 */  sb         $v0, 0xA8($a0)
    /* B45EC 002B39EC 8CE200AC */  lw         $v0, 0xAC($a3)
    /* B45F0 002B39F0 24E70004 */  addiu      $a3, $a3, 0x4
    /* B45F4 002B39F4 ACC200B8 */  sw         $v0, 0xB8($a2)
    /* B45F8 002B39F8 29020010 */  slti       $v0, $t0, 0x10
    /* B45FC 002B39FC 1440FFF0 */  bnez       $v0, .L002B39C0
    /* B4600 002B3A00 24C60004 */   addiu     $a2, $a2, 0x4
    /* B4604 002B3A04 03E00008 */  jr         $ra
    /* B4608 002B3A08 00000000 */   nop
endlabel func_002B3998
