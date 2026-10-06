.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8AB0-0xB8B00 (VRAM 0x002B7EB0) */
glabel func_002B7EB0
    /* B8AB0 002B7EB0 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B8AB4 002B7EB4 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B8AB8 002B7EB8 8C860040 */  lw         $a2, 0x40($a0)
    /* B8ABC 002B7EBC 24020008 */  addiu      $v0, $zero, 0x8
    /* B8AC0 002B7EC0 A7A20010 */  sh         $v0, 0x10($sp)
    /* B8AC4 002B7EC4 8C83003C */  lw         $v1, 0x3C($a0)
    /* B8AC8 002B7EC8 24840014 */  addiu      $a0, $a0, 0x14
    /* B8ACC 002B7ECC A3A50018 */  sb         $a1, 0x18($sp)
    /* B8AD0 002B7ED0 27A50010 */  addiu      $a1, $sp, 0x10
    /* B8AD4 002B7ED4 00031040 */  sll        $v0, $v1, 1
    /* B8AD8 002B7ED8 00431021 */  addu       $v0, $v0, $v1
    /* B8ADC 002B7EDC 00021100 */  sll        $v0, $v0, 4
    /* B8AE0 002B7EE0 00C23021 */  addu       $a2, $a2, $v0
    /* B8AE4 002B7EE4 AFA60014 */  sw         $a2, 0x14($sp)
    /* B8AE8 002B7EE8 0C0AD469 */  jal        func_002B51A4
    /* B8AEC 002B7EEC 00003021 */   addu      $a2, $zero, $zero
    /* B8AF0 002B7EF0 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B8AF4 002B7EF4 03E00008 */  jr         $ra
    /* B8AF8 002B7EF8 27BD0028 */   addiu     $sp, $sp, 0x28


    /* B8AFC 002B7EFC 34A50800 */  .word      0x34A50800 /* linker padding */
endlabel func_002B7EB0
