.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB82F0-0xB8320 (VRAM 0x002B76F0) */
glabel func_002B76F0
    /* B82F0 002B76F0 8C83003C */  lw         $v1, 0x3C($a0)
    /* B82F4 002B76F4 00031040 */  sll        $v0, $v1, 1
    /* B82F8 002B76F8 00431021 */  addu       $v0, $v0, $v1
    /* B82FC 002B76FC 8C830040 */  lw         $v1, 0x40($a0)
    /* B8300 002B7700 00021100 */  sll        $v0, $v0, 4
    /* B8304 002B7704 00431021 */  addu       $v0, $v0, $v1
    /* B8308 002B7708 8C420028 */  lw         $v0, 0x28($v0)
    /* B830C 002B770C 03E00008 */  jr         $ra
    /* B8310 002B7710 00000000 */   nop


    /* B8314 002B7714 00111600 */  .word      0x00111600 /* linker padding */
    /* B8318 002B7718 04420001 */  .word      0x04420001 /* linker padding */
    /* B831C 002B771C 00119823 */  .word      0x00119823 /* linker padding */
endlabel func_002B76F0
