.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB8ED0-0xB8F6C (VRAM 0x002B82D0) */
glabel func_002B82D0
    /* B8ED0 002B82D0 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B8ED4 002B82D4 AFB00010 */  sw         $s0, 0x10($sp)
    /* B8ED8 002B82D8 00A08021 */  addu       $s0, $a1, $zero
    /* B8EDC 002B82DC AFBF0018 */  sw         $ra, 0x18($sp)
    /* B8EE0 002B82E0 AFB10014 */  sw         $s1, 0x14($sp)
    /* B8EE4 002B82E4 8E050008 */  lw         $a1, 0x8($s0)
    /* B8EE8 002B82E8 10A0001B */  beqz       $a1, .L002B8358
    /* B8EEC 002B82EC 00808821 */   addu      $s1, $a0, $zero
    /* B8EF0 002B82F0 8CA200D8 */  lw         $v0, 0xD8($a1)
    /* B8EF4 002B82F4 10400015 */  beqz       $v0, .L002B834C
    /* B8EF8 002B82F8 00000000 */   nop
    /* B8EFC 002B82FC 0C0AE332 */  jal        func_002B8CC8
    /* B8F00 002B8300 00000000 */   nop
    /* B8F04 002B8304 00403021 */  addu       $a2, $v0, $zero
    /* B8F08 002B8308 10C00013 */  beqz       $a2, .L002B8358
    /* B8F0C 002B830C 00000000 */   nop
    /* B8F10 002B8310 8E030008 */  lw         $v1, 0x8($s0)
    /* B8F14 002B8314 8E22001C */  lw         $v0, 0x1C($s1)
    /* B8F18 002B8318 8C6300D8 */  lw         $v1, 0xD8($v1)
    /* B8F1C 002B831C A4C00008 */  sh         $zero, 0x8($a2)
    /* B8F20 002B8320 00431021 */  addu       $v0, $v0, $v1
    /* B8F24 002B8324 ACC20004 */  sw         $v0, 0x4($a2)
    /* B8F28 002B8328 8E020008 */  lw         $v0, 0x8($s0)
    /* B8F2C 002B832C ACC2000C */  sw         $v0, 0xC($a2)
    /* B8F30 002B8330 8E020008 */  lw         $v0, 0x8($s0)
    /* B8F34 002B8334 8C44000C */  lw         $a0, 0xC($v0)
    /* B8F38 002B8338 8C820008 */  lw         $v0, 0x8($a0)
    /* B8F3C 002B833C 0040F809 */  jalr       $v0
    /* B8F40 002B8340 24050003 */   addiu     $a1, $zero, 0x3
    /* B8F44 002B8344 080AE0D6 */  j          .L002B8358
    /* B8F48 002B8348 AE000008 */   sw        $zero, 0x8($s0)
  .L002B834C:
    /* B8F4C 002B834C 0C0AE343 */  jal        func_002B8D0C
    /* B8F50 002B8350 02202021 */   addu      $a0, $s1, $zero
    /* B8F54 002B8354 AE000008 */  sw         $zero, 0x8($s0)
  .L002B8358:
    /* B8F58 002B8358 8FBF0018 */  lw         $ra, 0x18($sp)
    /* B8F5C 002B835C 8FB10014 */  lw         $s1, 0x14($sp)
    /* B8F60 002B8360 8FB00010 */  lw         $s0, 0x10($sp)
    /* B8F64 002B8364 03E00008 */  jr         $ra
    /* B8F68 002B8368 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel func_002B82D0
