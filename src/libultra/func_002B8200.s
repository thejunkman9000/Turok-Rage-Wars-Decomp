.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8E00-0xB8EC0 (VRAM 0x002B8200) */
glabel func_002B8200
    /* B8E00 002B8200 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B8E04 002B8204 AFB10014 */  sw         $s1, 0x14($sp)
    /* B8E08 002B8208 00808821 */  addu       $s1, $a0, $zero
    /* B8E0C 002B820C AFBF001C */  sw         $ra, 0x1C($sp)
    /* B8E10 002B8210 AFB20018 */  sw         $s2, 0x18($sp)
    /* B8E14 002B8214 AFB00010 */  sw         $s0, 0x10($sp)
    /* B8E18 002B8218 8E300014 */  lw         $s0, 0x14($s1)
    /* B8E1C 002B821C 16000004 */  bnez       $s0, .L002B8230
    /* B8E20 002B8220 00009021 */   addu      $s2, $zero, $zero
    /* B8E24 002B8224 8E300004 */  lw         $s0, 0x4($s1)
    /* B8E28 002B8228 12000009 */  beqz       $s0, .L002B8250
    /* B8E2C 002B822C 00000000 */   nop
  .L002B8230:
    /* B8E30 002B8230 ACB00000 */  sw         $s0, 0x0($a1)
    /* B8E34 002B8234 0C0ADD48 */  jal        func_002B7520
    /* B8E38 002B8238 02002021 */   addu      $a0, $s0, $zero
    /* B8E3C 002B823C 02002021 */  addu       $a0, $s0, $zero
    /* B8E40 002B8240 0C0ADD54 */  jal        func_002B7550
    /* B8E44 002B8244 2625000C */   addiu     $a1, $s1, 0xC
    /* B8E48 002B8248 080AE0A8 */  j          .L002B82A0
    /* B8E4C 002B824C 02401021 */   addu      $v0, $s2, $zero
  .L002B8250:
    /* B8E50 002B8250 8E30000C */  lw         $s0, 0xC($s1)
    /* B8E54 002B8254 12000012 */  beqz       $s0, .L002B82A0
    /* B8E58 002B8258 02401021 */   addu      $v0, $s2, $zero
  .L002B825C:
    /* B8E5C 002B825C 8E020008 */  lw         $v0, 0x8($s0)
    /* B8E60 002B8260 00061C00 */  sll        $v1, $a2, 16
    /* B8E64 002B8264 84420016 */  lh         $v0, 0x16($v0)
    /* B8E68 002B8268 00031C03 */  sra        $v1, $v1, 16
    /* B8E6C 002B826C 0062182A */  slt        $v1, $v1, $v0
    /* B8E70 002B8270 14600008 */  bnez       $v1, .L002B8294
    /* B8E74 002B8274 00000000 */   nop
    /* B8E78 002B8278 8E0200D8 */  lw         $v0, 0xD8($s0)
    /* B8E7C 002B827C 14400005 */  bnez       $v0, .L002B8294
    /* B8E80 002B8280 00000000 */   nop
    /* B8E84 002B8284 ACB00000 */  sw         $s0, 0x0($a1)
    /* B8E88 002B8288 8E020008 */  lw         $v0, 0x8($s0)
    /* B8E8C 002B828C 24120001 */  addiu      $s2, $zero, 0x1
    /* B8E90 002B8290 94460016 */  lhu        $a2, 0x16($v0)
  .L002B8294:
    /* B8E94 002B8294 8E100000 */  lw         $s0, 0x0($s0)
    /* B8E98 002B8298 1600FFF0 */  bnez       $s0, .L002B825C
    /* B8E9C 002B829C 02401021 */   addu      $v0, $s2, $zero
  .L002B82A0:
    /* B8EA0 002B82A0 8FBF001C */  lw         $ra, 0x1C($sp)
    /* B8EA4 002B82A4 8FB20018 */  lw         $s2, 0x18($sp)
    /* B8EA8 002B82A8 8FB10014 */  lw         $s1, 0x14($sp)
    /* B8EAC 002B82AC 8FB00010 */  lw         $s0, 0x10($sp)
    /* B8EB0 002B82B0 03E00008 */  jr         $ra
    /* B8EB4 002B82B4 27BD0020 */   addiu     $sp, $sp, 0x20


    /* B8EB8 002B82B8 C420C824 */  .word      0xC420C824 /* linker padding */
    /* B8EBC 002B82BC 24020034 */  .word      0x24020034 /* linker padding */
endlabel func_002B8200
