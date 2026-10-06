.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8080-0xB8094 (VRAM 0x002B7480) */
glabel __alSeqReadByte
    /* B8080 002B7480 8C830008 */  lw         $v1, 0x8($a0)
    /* B8084 002B7484 90620000 */  lbu        $v0, 0x0($v1)
    /* B8088 002B7488 24630001 */  addiu      $v1, $v1, 0x1
    /* B808C 002B748C 03E00008 */  jr         $ra
    /* B8090 002B7490 AC830008 */   sw        $v1, 0x8($a0)
endlabel __alSeqReadByte
