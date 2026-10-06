.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8BA0-0xB8BD0 (VRAM 0x002B7FA0) */
glabel alSndpSetPriority
    /* B8BA0 002B7FA0 00052C00 */  sll        $a1, $a1, 16
    /* B8BA4 002B7FA4 00052C03 */  sra        $a1, $a1, 16
    /* B8BA8 002B7FA8 00051040 */  sll        $v0, $a1, 1
    /* B8BAC 002B7FAC 00451021 */  addu       $v0, $v0, $a1
    /* B8BB0 002B7FB0 00021100 */  sll        $v0, $v0, 4
    /* B8BB4 002B7FB4 8C830040 */  lw         $v1, 0x40($a0)
    /* B8BB8 002B7FB8 30C600FF */  andi       $a2, $a2, 0xFF
    /* B8BBC 002B7FBC 00431021 */  addu       $v0, $v0, $v1
    /* B8BC0 002B7FC0 03E00008 */  jr         $ra
    /* B8BC4 002B7FC4 A4460020 */   sh        $a2, 0x20($v0)


    /* B8BC8 002B7FC8 00471021 */  .word      0x00471021 /* linker padding */
    /* B8BCC 002B7FCC AC460000 */  .word      0xAC460000 /* linker padding */
endlabel alSndpSetPriority
