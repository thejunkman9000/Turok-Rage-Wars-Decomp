.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

/* linker padding: stray words between objects, ROM 0x64308 */
glabel pad_064308
    /* 64308 */  .word      0x3C02FFF6
    /* 6430C */  .word      0x3442FFF3
    /* 64310 */  .word      0x00821824
    /* 64314 */  .word      0x3C050001
    /* 64318 */  .word      0x00851024
    /* 6431C */  .word      0x10400002
    /* 64320 */  .word      0x3C060008
    /* 64324 */  .word      0x34630008
    /* 64328 */  .word      0x30820008
    /* 6432C */  .word      0x54400001
    /* 64330 */  .word      0x00651825
    /* 64334 */  .word      0x00861024
    /* 64338 */  .word      0x54400001
    /* 6433C */  .word      0x34630004
    /* 64340 */  .word      0x30820004
    /* 64344 */  .word      0x54400001
    /* 64348 */  .word      0x00661825
    /* 6434C */  .word      0x03E00008
    /* 64350 */  .word      0x00601021
    /* 64354 */  .word      0x9022F308
    /* 64358 */  .word      0x10400003
    /* 6435C */  .word      0x24630001
endlabel pad_064308
