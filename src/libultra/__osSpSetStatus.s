.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel __osSpSetStatus
    lui   $v0, 0xA404
    ori   $v0, $v0, 0x10
    sw    $a0, 0($v0)
    jr    $ra
     nop
endlabel __osSpSetStatus
