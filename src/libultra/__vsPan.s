.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB7574-0xB75B4 (VRAM 0x002B6974) */
glabel __vsPan
    /* B7574 002B6974 90830031 */  lbu        $v1, 0x31($a0)
    /* B7578 002B6978 8CA20060 */  lw         $v0, 0x60($a1)
    /* B757C 002B697C 8C840020 */  lw         $a0, 0x20($a0)
    /* B7580 002B6980 00031900 */  sll        $v1, $v1, 4
    /* B7584 002B6984 00621821 */  addu       $v1, $v1, $v0
    /* B7588 002B6988 9082000C */  lbu        $v0, 0xC($a0)
    /* B758C 002B698C 90630007 */  lbu        $v1, 0x7($v1)
    /* B7590 002B6990 2442FFC0 */  addiu      $v0, $v0, -0x40
    /* B7594 002B6994 00621821 */  addu       $v1, $v1, $v0
    /* B7598 002B6998 04620001 */  bltzl      $v1, .L002B69A0
    /* B759C 002B699C 00001821 */   addu      $v1, $zero, $zero
  .L002B69A0:
    /* B75A0 002B69A0 28620080 */  slti       $v0, $v1, 0x80
    /* B75A4 002B69A4 50400001 */  beql       $v0, $zero, .L002B69AC
    /* B75A8 002B69A8 2403007F */   addiu     $v1, $zero, 0x7F
  .L002B69AC:
    /* B75AC 002B69AC 03E00008 */  jr         $ra
    /* B75B0 002B69B0 306200FF */   andi      $v0, $v1, 0xFF
endlabel __vsPan
