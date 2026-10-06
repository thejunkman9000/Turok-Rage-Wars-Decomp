.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xC7520-0xC7600 (VRAM 0x002C6920) */
glabel __floatdidf
    /* C7520 002C6920 0086102A */  slt        $v0, $a0, $a2
    /* C7524 002C6924 10400003 */  beqz       $v0, .L002C6934
    /* C7528 002C6928 00C4102A */   slt       $v0, $a2, $a0
    /* C752C 002C692C 03E00008 */  jr         $ra
    /* C7530 002C6930 00001021 */   addu      $v0, $zero, $zero
  .L002C6934:
    /* C7534 002C6934 10400003 */  beqz       $v0, .L002C6944
    /* C7538 002C6938 00A7102B */   sltu      $v0, $a1, $a3
    /* C753C 002C693C 03E00008 */  jr         $ra
    /* C7540 002C6940 24020002 */   addiu     $v0, $zero, 0x2
  .L002C6944:
    /* C7544 002C6944 14400006 */  bnez       $v0, .L002C6960
    /* C7548 002C6948 00001021 */   addu      $v0, $zero, $zero
    /* C754C 002C694C 00E5182B */  sltu       $v1, $a3, $a1
    /* C7550 002C6950 14600003 */  bnez       $v1, .L002C6960
    /* C7554 002C6954 24020002 */   addiu     $v0, $zero, 0x2
    /* C7558 002C6958 03E00008 */  jr         $ra
    /* C755C 002C695C 24020001 */   addiu     $v0, $zero, 0x1
  .L002C6960:
    /* C7560 002C6960 03E00008 */  jr         $ra
    /* C7564 002C6964 00000000 */   nop


dlabel D_002C6968
    /* C7568 002C6968 41F00000 */ .word 0x41F00000 /* invalid instruction */
    /* C756C 002C696C 3F7D70A4 */ .word 0x3F7D70A4 /* invalid instruction */


alabel func_002C6970
    /* C7570 002C6970 00803021 */ .word 0x00803021
    /* C7574 002C6974 00A03821 */ .word 0x00A03821
    /* C7578 002C6978 04C10006 */ .word 0x04C10006
    /* C757C 002C697C 00002821 */ .word 0x00002821
    /* C7580 002C6980 00073823 */ .word 0x00073823
    /* C7584 002C6984 00063023 */ .word 0x00063023
    /* C7588 002C6988 0007102B */ .word 0x0007102B
    /* C758C 002C698C 00C23023 */ .word 0x00C23023
    /* C7590 002C6990 24050001 */ .word 0x24050001
    /* C7594 002C6994 00061803 */ .word 0x00061803
    /* C7598 002C6998 000617C3 */ .word 0x000617C3
    /* C759C 002C699C 44831000 */ .word 0x44831000
    /* C75A0 002C69A0 468010A1 */ .word 0x468010A1
    /* C75A4 002C69A4 04610004 */ .word 0x04610004
    /* C75A8 002C69A8 00000000 */ .word 0x00000000
    /* C75AC 002C69AC 3C01800D */ .word 0x3C01800D
    /* C75B0 002C69B0 D420D350 */ .word 0xD420D350
    /* C75B4 002C69B4 46201080 */ .word 0x46201080
    /* C75B8 002C69B8 3C01800D */ .word 0x3C01800D
    /* C75BC 002C69BC D420D358 */ .word 0xD420D358
    /* C75C0 002C69C0 46201082 */ .word 0x46201082
    /* C75C4 002C69C4 44872000 */ .word 0x44872000
    /* C75C8 002C69C8 46802121 */ .word 0x46802121
    /* C75CC 002C69CC 46201082 */ .word 0x46201082
    /* C75D0 002C69D0 04E10004 */ .word 0x04E10004
    /* C75D4 002C69D4 00000000 */ .word 0x00000000
    /* C75D8 002C69D8 3C01800D */ .word 0x3C01800D
    /* C75DC 002C69DC D420D360 */ .word 0xD420D360
    /* C75E0 002C69E0 46202100 */ .word 0x46202100
    /* C75E4 002C69E4 10A00002 */ .word 0x10A00002
    /* C75E8 002C69E8 46241000 */ .word 0x46241000
    /* C75EC 002C69EC 46200007 */ .word 0x46200007
    /* C75F0 002C69F0 03E00008 */ .word 0x03E00008
    /* C75F4 002C69F4 00000000 */ .word 0x00000000
enddlabel D_002C6968


dlabel D_002C69F8
    /* C75F8 002C69F8 41800000 */ .word 0x41800000 /* invalid instruction */
    /* C75FC 002C69FC 3C8EFA36 */ .word 0x3C8EFA36 /* invalid instruction */
endlabel __floatdidf
