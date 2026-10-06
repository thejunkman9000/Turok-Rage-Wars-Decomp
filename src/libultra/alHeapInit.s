.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB6060-0xB6094 (VRAM 0x002B5460) */
glabel alHeapInit
    /* B6060 002B5460 30A3000F */  andi       $v1, $a1, 0xF
    /* B6064 002B5464 24020010 */  addiu      $v0, $zero, 0x10
    /* B6068 002B5468 00431823 */  subu       $v1, $v0, $v1
    /* B606C 002B546C 10620003 */  beq        $v1, $v0, .L002B547C
    /* B6070 002B5470 00A31021 */   addu      $v0, $a1, $v1
    /* B6074 002B5474 080AD520 */  j          .L002B5480
    /* B6078 002B5478 AC820000 */   sw        $v0, 0x0($a0)
  .L002B547C:
    /* B607C 002B547C AC850000 */  sw         $a1, 0x0($a0)
  .L002B5480:
    /* B6080 002B5480 8C820000 */  lw         $v0, 0x0($a0)
    /* B6084 002B5484 AC860008 */  sw         $a2, 0x8($a0)
    /* B6088 002B5488 AC80000C */  sw         $zero, 0xC($a0)
    /* B608C 002B548C 03E00008 */  jr         $ra
    /* B6090 002B5490 AC820004 */   sw        $v0, 0x4($a0)
endlabel alHeapInit
