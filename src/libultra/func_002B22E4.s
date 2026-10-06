.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2EE4-0xB2F40 (VRAM 0x002B22E4) */
glabel func_002B22E4
    /* B2EE4 002B22E4 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B2EE8 002B22E8 24040010 */  addiu      $a0, $zero, 0x10
    /* B2EEC 002B22EC AFBF001C */  sw         $ra, 0x1C($sp)
    /* B2EF0 002B22F0 0C0AB96B */  jal        func_002AE5AC
    /* B2EF4 002B22F4 AFB00018 */   sw        $s0, 0x18($sp)
    /* B2EF8 002B22F8 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2EFC 002B22FC 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2F00 002B2300 1440000A */  bnez       $v0, .L002B232C
    /* B2F04 002B2304 00008021 */   addu      $s0, $zero, $zero
    /* B2F08 002B2308 0C0AB8E0 */  jal        func_002AE380
    /* B2F0C 002B230C 27A40010 */   addiu     $a0, $sp, 0x10
    /* B2F10 002B2310 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B2F14 002B2314 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B2F18 002B2318 14400005 */  bnez       $v0, .L002B2330
    /* B2F1C 002B231C 02001021 */   addu      $v0, $s0, $zero
    /* B2F20 002B2320 93A20010 */  lbu        $v0, 0x10($sp)
    /* B2F24 002B2324 38420011 */  xori       $v0, $v0, 0x11
    /* B2F28 002B2328 2C500001 */  sltiu      $s0, $v0, 0x1
  .L002B232C:
    /* B2F2C 002B232C 02001021 */  addu       $v0, $s0, $zero
  .L002B2330:
    /* B2F30 002B2330 8FBF001C */  lw         $ra, 0x1C($sp)
    /* B2F34 002B2334 8FB00018 */  lw         $s0, 0x18($sp)
    /* B2F38 002B2338 03E00008 */  jr         $ra
    /* B2F3C 002B233C 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel func_002B22E4
