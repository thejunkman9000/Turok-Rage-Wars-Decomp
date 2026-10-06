.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5C20-0xC5C80 (VRAM 0x002C5020) */
glabel mdctPackSpectrum
    /* C5C20 002C5020 00804021 */  addu       $t0, $a0, $zero
    /* C5C24 002C5024 00003021 */  addu       $a2, $zero, $zero
    /* C5C28 002C5028 240700FF */  addiu      $a3, $zero, 0xFF
  .L002C502C:
    /* C5C2C 002C502C 00061C00 */  sll        $v1, $a2, 16
    /* C5C30 002C5030 00031C03 */  sra        $v1, $v1, 16
    /* C5C34 002C5034 000320C0 */  sll        $a0, $v1, 3
    /* C5C38 002C5038 00851021 */  addu       $v0, $a0, $a1
    /* C5C3C 002C503C 00882021 */  addu       $a0, $a0, $t0
    /* C5C40 002C5040 00031840 */  sll        $v1, $v1, 1
    /* C5C44 002C5044 00E31823 */  subu       $v1, $a3, $v1
    /* C5C48 002C5048 00031880 */  sll        $v1, $v1, 2
    /* C5C4C 002C504C 00651821 */  addu       $v1, $v1, $a1
    /* C5C50 002C5050 C4400000 */  lwc1       $fv0, 0x0($v0)
    /* C5C54 002C5054 24C20001 */  addiu      $v0, $a2, 0x1
    /* C5C58 002C5058 00403021 */  addu       $a2, $v0, $zero
    /* C5C5C 002C505C 00021400 */  sll        $v0, $v0, 16
    /* C5C60 002C5060 00021403 */  sra        $v0, $v0, 16
    /* C5C64 002C5064 E4800000 */  swc1       $fv0, 0x0($a0)
    /* C5C68 002C5068 C4600000 */  lwc1       $fv0, 0x0($v1)
    /* C5C6C 002C506C 28420080 */  slti       $v0, $v0, 0x80
    /* C5C70 002C5070 1440FFEE */  bnez       $v0, .L002C502C
    /* C5C74 002C5074 E4800004 */   swc1      $fv0, 0x4($a0)
    /* C5C78 002C5078 03E00008 */  jr         $ra
    /* C5C7C 002C507C 00000000 */   nop
endlabel mdctPackSpectrum
