.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB5BB0-0xB5C00 (VRAM 0x002B4FB0) */
glabel alCSPSetChlFXMix
    /* B5BB0 002B4FB0 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B5BB4 002B4FB4 24020002 */  addiu      $v0, $zero, 0x2
    /* B5BB8 002B4FB8 34A500B0 */  ori        $a1, $a1, 0xB0
    /* B5BBC 002B4FBC A7A20010 */  sh         $v0, 0x10($sp)
    /* B5BC0 002B4FC0 2402005B */  addiu      $v0, $zero, 0x5B
    /* B5BC4 002B4FC4 24840048 */  addiu      $a0, $a0, 0x48
    /* B5BC8 002B4FC8 A3A50018 */  sb         $a1, 0x18($sp)
    /* B5BCC 002B4FCC 27A50010 */  addiu      $a1, $sp, 0x10
    /* B5BD0 002B4FD0 A3A6001A */  sb         $a2, 0x1A($sp)
    /* B5BD4 002B4FD4 00003021 */  addu       $a2, $zero, $zero
    /* B5BD8 002B4FD8 AFBF0020 */  sw         $ra, 0x20($sp)
    /* B5BDC 002B4FDC AFA00014 */  sw         $zero, 0x14($sp)
    /* B5BE0 002B4FE0 0C0AD469 */  jal        alEvtqPostEvent
    /* B5BE4 002B4FE4 A3A20019 */   sb        $v0, 0x19($sp)
    /* B5BE8 002B4FE8 8FBF0020 */  lw         $ra, 0x20($sp)
    /* B5BEC 002B4FEC 03E00008 */  jr         $ra
    /* B5BF0 002B4FF0 27BD0028 */   addiu     $sp, $sp, 0x28


    /* B5BF4 002B4FF4 34420001 */  .word      0x34420001 /* linker padding */
    /* B5BF8 002B4FF8 A2220037 */  .word      0xA2220037 /* linker padding */
    /* B5BFC 002B4FFC C7A0003C */  .word      0xC7A0003C /* linker padding */
endlabel alCSPSetChlFXMix
