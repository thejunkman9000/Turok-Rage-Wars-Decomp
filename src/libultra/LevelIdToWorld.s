.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2F78-0xB3040 (VRAM 0x002B2378) */
glabel LevelIdToWorld
    /* B2F78 002B2378 240207CF */  addiu      $v0, $zero, 0x7CF
    /* B2F7C 002B237C 1082000D */  beq        $a0, $v0, .L002B23B4
    /* B2F80 002B2380 24020BB7 */   addiu     $v0, $zero, 0xBB7
    /* B2F84 002B2384 1082000B */  beq        $a0, $v0, .L002B23B4
    /* B2F88 002B2388 24020F9F */   addiu     $v0, $zero, 0xF9F
    /* B2F8C 002B238C 10820009 */  beq        $a0, $v0, .L002B23B4
    /* B2F90 002B2390 24021387 */   addiu     $v0, $zero, 0x1387
    /* B2F94 002B2394 10820007 */  beq        $a0, $v0, .L002B23B4
    /* B2F98 002B2398 2402176F */   addiu     $v0, $zero, 0x176F
    /* B2F9C 002B239C 10820005 */  beq        $a0, $v0, .L002B23B4
    /* B2FA0 002B23A0 24021B57 */   addiu     $v0, $zero, 0x1B57
    /* B2FA4 002B23A4 10820003 */  beq        $a0, $v0, .L002B23B4
    /* B2FA8 002B23A8 24020063 */   addiu     $v0, $zero, 0x63
    /* B2FAC 002B23AC 14820003 */  bne        $a0, $v0, .L002B23BC
    /* B2FB0 002B23B0 2482FC18 */   addiu     $v0, $a0, -0x3E8
  .L002B23B4:
    /* B2FB4 002B23B4 03E00008 */  jr         $ra
    /* B2FB8 002B23B8 00001021 */   addu      $v0, $zero, $zero
  .L002B23BC:
    /* B2FBC 002B23BC 2C4203E8 */  sltiu      $v0, $v0, 0x3E8
    /* B2FC0 002B23C0 10400003 */  beqz       $v0, .L002B23D0
    /* B2FC4 002B23C4 2482F830 */   addiu     $v0, $a0, -0x7D0
    /* B2FC8 002B23C8 03E00008 */  jr         $ra
    /* B2FCC 002B23CC 24020001 */   addiu     $v0, $zero, 0x1
  .L002B23D0:
    /* B2FD0 002B23D0 2C4203E8 */  sltiu      $v0, $v0, 0x3E8
    /* B2FD4 002B23D4 10400003 */  beqz       $v0, .L002B23E4
    /* B2FD8 002B23D8 2482F448 */   addiu     $v0, $a0, -0xBB8
    /* B2FDC 002B23DC 03E00008 */  jr         $ra
    /* B2FE0 002B23E0 24020002 */   addiu     $v0, $zero, 0x2
  .L002B23E4:
    /* B2FE4 002B23E4 2C4203E8 */  sltiu      $v0, $v0, 0x3E8
    /* B2FE8 002B23E8 10400003 */  beqz       $v0, .L002B23F8
    /* B2FEC 002B23EC 2482F060 */   addiu     $v0, $a0, -0xFA0
    /* B2FF0 002B23F0 03E00008 */  jr         $ra
    /* B2FF4 002B23F4 24020003 */   addiu     $v0, $zero, 0x3
  .L002B23F8:
    /* B2FF8 002B23F8 2C4203E8 */  sltiu      $v0, $v0, 0x3E8
    /* B2FFC 002B23FC 10400003 */  beqz       $v0, .L002B240C
    /* B3000 002B2400 2482EC78 */   addiu     $v0, $a0, -0x1388
    /* B3004 002B2404 03E00008 */  jr         $ra
    /* B3008 002B2408 24020004 */   addiu     $v0, $zero, 0x4
  .L002B240C:
    /* B300C 002B240C 2C4203E8 */  sltiu      $v0, $v0, 0x3E8
    /* B3010 002B2410 14400007 */  bnez       $v0, .L002B2430
    /* B3014 002B2414 24020005 */   addiu     $v0, $zero, 0x5
    /* B3018 002B2418 2483E890 */  addiu      $v1, $a0, -0x1770
    /* B301C 002B241C 2C6303E8 */  sltiu      $v1, $v1, 0x3E8
    /* B3020 002B2420 14600003 */  bnez       $v1, .L002B2430
    /* B3024 002B2424 24020006 */   addiu     $v0, $zero, 0x6
    /* B3028 002B2428 03E00008 */  jr         $ra
    /* B302C 002B242C 2402FFFF */   addiu     $v0, $zero, -0x1
  .L002B2430:
    /* B3030 002B2430 03E00008 */  jr         $ra
    /* B3034 002B2434 00000000 */   nop


    /* B3038 002B2438 3C01800D */  .word      0x3C01800D /* linker padding */
    /* B303C 002B243C D420C540 */  .word      0xD420C540 /* linker padding */
endlabel LevelIdToWorld
