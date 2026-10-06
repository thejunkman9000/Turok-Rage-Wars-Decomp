.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0xC0554 */
glabel pad_0C0554
    /* C0554 */  .word      0x3C02A500
    /* C0558 */  .word      0x3C03A460
    /* C055C */  .word      0x34630010
endlabel pad_0C0554
