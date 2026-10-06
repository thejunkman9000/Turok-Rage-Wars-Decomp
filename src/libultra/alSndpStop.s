.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8C30-0xB8C78 (VRAM 0x002B8030) */
glabel alSndpStop
    /* B8C30 002B8030 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B8C34 002B8034 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B8C38 002B8038 8C850040 */  lw         $a1, 0x40($a0)
    /* B8C3C 002B803C 24020001 */  addiu      $v0, $zero, 0x1
    /* B8C40 002B8040 A7A20010 */  sh         $v0, 0x10($sp)
    /* B8C44 002B8044 8C83003C */  lw         $v1, 0x3C($a0)
    /* B8C48 002B8048 24840014 */  addiu      $a0, $a0, 0x14
    /* B8C4C 002B804C 00003021 */  addu       $a2, $zero, $zero
    /* B8C50 002B8050 00031040 */  sll        $v0, $v1, 1
    /* B8C54 002B8054 00431021 */  addu       $v0, $v0, $v1
    /* B8C58 002B8058 00021100 */  sll        $v0, $v0, 4
    /* B8C5C 002B805C 00A22821 */  addu       $a1, $a1, $v0
    /* B8C60 002B8060 AFA50014 */  sw         $a1, 0x14($sp)
    /* B8C64 002B8064 0C0AD469 */  jal        alEvtqPostEvent
    /* B8C68 002B8068 27A50010 */   addiu     $a1, $sp, 0x10
    /* B8C6C 002B806C 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B8C70 002B8070 03E00008 */  jr         $ra
    /* B8C74 002B8074 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel alSndpStop
