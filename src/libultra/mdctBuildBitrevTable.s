.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC5B58-0xC5C20 (VRAM 0x002C4F58) */
glabel mdctBuildBitrevTable
    /* C5B58 002C4F58 00805021 */  addu       $t2, $a0, $zero
    /* C5B5C 002C4F5C 00A04821 */  addu       $t1, $a1, $zero
    /* C5B60 002C4F60 00003821 */  addu       $a3, $zero, $zero
    /* C5B64 002C4F64 19200007 */  blez       $t1, .L002C4F84
    /* C5B68 002C4F68 00094040 */   sll       $t0, $t1, 1
    /* C5B6C 002C4F6C 01401821 */  addu       $v1, $t2, $zero
  .L002C4F70:
    /* C5B70 002C4F70 AC670000 */  sw         $a3, 0x0($v1)
    /* C5B74 002C4F74 24E70001 */  addiu      $a3, $a3, 0x1
    /* C5B78 002C4F78 00E9102A */  slt        $v0, $a3, $t1
    /* C5B7C 002C4F7C 1440FFFC */  bnez       $v0, .L002C4F70
    /* C5B80 002C4F80 24630004 */   addiu     $v1, $v1, 0x4
  .L002C4F84:
    /* C5B84 002C4F84 24060001 */  addiu      $a2, $zero, 0x1
    /* C5B88 002C4F88 19000023 */  blez       $t0, .L002C5018
    /* C5B8C 002C4F8C 00C03821 */   addu      $a3, $a2, $zero
  .L002C4F90:
    /* C5B90 002C4F90 00E6102A */  slt        $v0, $a3, $a2
    /* C5B94 002C4F94 10400010 */  beqz       $v0, .L002C4FD8
    /* C5B98 002C4F98 24C4FFFF */   addiu     $a0, $a2, -0x1
    /* C5B9C 002C4F9C 000417C2 */  srl        $v0, $a0, 31
    /* C5BA0 002C4FA0 00822021 */  addu       $a0, $a0, $v0
    /* C5BA4 002C4FA4 00042043 */  sra        $a0, $a0, 1
    /* C5BA8 002C4FA8 00042080 */  sll        $a0, $a0, 2
    /* C5BAC 002C4FAC 008A2021 */  addu       $a0, $a0, $t2
    /* C5BB0 002C4FB0 24E2FFFF */  addiu      $v0, $a3, -0x1
    /* C5BB4 002C4FB4 00021FC2 */  srl        $v1, $v0, 31
    /* C5BB8 002C4FB8 00431021 */  addu       $v0, $v0, $v1
    /* C5BBC 002C4FBC 00021043 */  sra        $v0, $v0, 1
    /* C5BC0 002C4FC0 00021080 */  sll        $v0, $v0, 2
    /* C5BC4 002C4FC4 004A1021 */  addu       $v0, $v0, $t2
    /* C5BC8 002C4FC8 8C430000 */  lw         $v1, 0x0($v0)
    /* C5BCC 002C4FCC 8C850000 */  lw         $a1, 0x0($a0)
    /* C5BD0 002C4FD0 AC830000 */  sw         $v1, 0x0($a0)
    /* C5BD4 002C4FD4 AC450000 */  sw         $a1, 0x0($v0)
  .L002C4FD8:
    /* C5BD8 002C4FD8 01201821 */  addu       $v1, $t1, $zero
    /* C5BDC 002C4FDC 28620002 */  slti       $v0, $v1, 0x2
    /* C5BE0 002C4FE0 5440000A */  bnel       $v0, $zero, .L002C500C
    /* C5BE4 002C4FE4 24E70002 */   addiu     $a3, $a3, 0x2
    /* C5BE8 002C4FE8 0066102A */  slt        $v0, $v1, $a2
  .L002C4FEC:
    /* C5BEC 002C4FEC 50400007 */  beql       $v0, $zero, .L002C500C
    /* C5BF0 002C4FF0 24E70002 */   addiu     $a3, $a3, 0x2
    /* C5BF4 002C4FF4 00C33023 */  subu       $a2, $a2, $v1
    /* C5BF8 002C4FF8 00031843 */  sra        $v1, $v1, 1
    /* C5BFC 002C4FFC 28620002 */  slti       $v0, $v1, 0x2
    /* C5C00 002C5000 1040FFFA */  beqz       $v0, .L002C4FEC
    /* C5C04 002C5004 0066102A */   slt       $v0, $v1, $a2
    /* C5C08 002C5008 24E70002 */  addiu      $a3, $a3, 0x2
  .L002C500C:
    /* C5C0C 002C500C 0107102A */  slt        $v0, $t0, $a3
    /* C5C10 002C5010 1040FFDF */  beqz       $v0, .L002C4F90
    /* C5C14 002C5014 00C33021 */   addu      $a2, $a2, $v1
  .L002C5018:
    /* C5C18 002C5018 03E00008 */  jr         $ra
    /* C5C1C 002C501C 00000000 */   nop
endlabel mdctBuildBitrevTable
