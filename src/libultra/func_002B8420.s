.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB9020-0xB90B0 (VRAM 0x002B8420) */
glabel func_002B8420
    /* B9020 002B8420 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B9024 002B8424 AFB20018 */  sw         $s2, 0x18($sp)
    /* B9028 002B8428 00809021 */  addu       $s2, $a0, $zero
    /* B902C 002B842C AFB00010 */  sw         $s0, 0x10($sp)
    /* B9030 002B8430 00A08021 */  addu       $s0, $a1, $zero
    /* B9034 002B8434 AFBF001C */  sw         $ra, 0x1C($sp)
    /* B9038 002B8438 AFB10014 */  sw         $s1, 0x14($sp)
    /* B903C 002B843C 8E020008 */  lw         $v0, 0x8($s0)
    /* B9040 002B8440 10400015 */  beqz       $v0, .L002B8498
    /* B9044 002B8444 00C08821 */   addu      $s1, $a2, $zero
    /* B9048 002B8448 0C0AE332 */  jal        func_002B8CC8
    /* B904C 002B844C 00000000 */   nop
    /* B9050 002B8450 00403021 */  addu       $a2, $v0, $zero
    /* B9054 002B8454 10C00010 */  beqz       $a2, .L002B8498
    /* B9058 002B8458 00000000 */   nop
    /* B905C 002B845C 8E020008 */  lw         $v0, 0x8($s0)
    /* B9060 002B8460 8E43001C */  lw         $v1, 0x1C($s2)
    /* B9064 002B8464 8C4400D8 */  lw         $a0, 0xD8($v0)
    /* B9068 002B8468 2402000C */  addiu      $v0, $zero, 0xC
    /* B906C 002B846C A4C20008 */  sh         $v0, 0x8($a2)
    /* B9070 002B8470 322200FF */  andi       $v0, $s1, 0xFF
    /* B9074 002B8474 ACC2000C */  sw         $v0, 0xC($a2)
    /* B9078 002B8478 ACC00000 */  sw         $zero, 0x0($a2)
    /* B907C 002B847C 00641821 */  addu       $v1, $v1, $a0
    /* B9080 002B8480 ACC30004 */  sw         $v1, 0x4($a2)
    /* B9084 002B8484 8E020008 */  lw         $v0, 0x8($s0)
    /* B9088 002B8488 8C44000C */  lw         $a0, 0xC($v0)
    /* B908C 002B848C 8C820008 */  lw         $v0, 0x8($a0)
    /* B9090 002B8490 0040F809 */  jalr       $v0
    /* B9094 002B8494 24050003 */   addiu     $a1, $zero, 0x3
  .L002B8498:
    /* B9098 002B8498 8FBF001C */  lw         $ra, 0x1C($sp)
    /* B909C 002B849C 8FB20018 */  lw         $s2, 0x18($sp)
    /* B90A0 002B84A0 8FB10014 */  lw         $s1, 0x14($sp)
    /* B90A4 002B84A4 8FB00010 */  lw         $s0, 0x10($sp)
    /* B90A8 002B84A8 03E00008 */  jr         $ra
    /* B90AC 002B84AC 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel func_002B8420
