.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB2C10-0xB2C50 (VRAM 0x002B2010) */
glabel func_002B2010
    /* B2C10 002B2010 27BDFFE8 */  addiu      $sp, $sp, -0x18
    /* B2C14 002B2014 AFBF0010 */  sw         $ra, 0x10($sp)
  .L002B2018:
    /* B2C18 002B2018 0C0AF7A8 */  jal        osPiGetStatus
    /* B2C1C 002B201C 00000000 */   nop
    /* B2C20 002B2020 30420003 */  andi       $v0, $v0, 0x3
    /* B2C24 002B2024 1440FFFC */  bnez       $v0, .L002B2018
    /* B2C28 002B2028 00000000 */   nop
    /* B2C2C 002B202C 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B2C30 002B2030 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B2C34 002B2034 8FBF0010 */  lw         $ra, 0x10($sp)
    /* B2C38 002B2038 00021042 */  srl        $v0, $v0, 1
    /* B2C3C 002B203C 30420001 */  andi       $v0, $v0, 0x1
    /* B2C40 002B2040 03E00008 */  jr         $ra
    /* B2C44 002B2044 27BD0018 */   addiu     $sp, $sp, 0x18


glabel func_002B2048
    /* B2C48 002B2048 03E00008 */  jr         $ra
    /* B2C4C 002B204C 24020001 */   addiu     $v0, $zero, 0x1
endlabel func_002B2010
