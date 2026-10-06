.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB92B0-0xB93C0 (VRAM 0x002B86B0) */
glabel func_002B86B0
    /* B92B0 002B86B0 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* B92B4 002B86B4 F7B40038 */  sdc1       $fs0, 0x38($sp)
    /* B92B8 002B86B8 4487A000 */  mtc1       $a3, $fs0
    /* B92BC 002B86BC AFB10014 */  sw         $s1, 0x14($sp)
    /* B92C0 002B86C0 8FB10058 */  lw         $s1, 0x58($sp)
    /* B92C4 002B86C4 AFB60028 */  sw         $s6, 0x28($sp)
    /* B92C8 002B86C8 8FB60050 */  lw         $s6, 0x50($sp)
    /* B92CC 002B86CC AFB40020 */  sw         $s4, 0x20($sp)
    /* B92D0 002B86D0 8FB40054 */  lw         $s4, 0x54($sp)
    /* B92D4 002B86D4 AFB50024 */  sw         $s5, 0x24($sp)
    /* B92D8 002B86D8 0080A821 */  addu       $s5, $a0, $zero
    /* B92DC 002B86DC AFB20018 */  sw         $s2, 0x18($sp)
    /* B92E0 002B86E0 00A09021 */  addu       $s2, $a1, $zero
    /* B92E4 002B86E4 AFB7002C */  sw         $s7, 0x2C($sp)
    /* B92E8 002B86E8 00C0B821 */  addu       $s7, $a2, $zero
    /* B92EC 002B86EC AFBF0030 */  sw         $ra, 0x30($sp)
    /* B92F0 002B86F0 AFB3001C */  sw         $s3, 0x1C($sp)
    /* B92F4 002B86F4 AFB00010 */  sw         $s0, 0x10($sp)
    /* B92F8 002B86F8 8E420008 */  lw         $v0, 0x8($s2)
    /* B92FC 002B86FC 10400021 */  beqz       $v0, .L002B8784
    /* B9300 002B8700 02209821 */   addu      $s3, $s1, $zero
    /* B9304 002B8704 0C0AE332 */  jal        func_002B8CC8
    /* B9308 002B8708 00000000 */   nop
    /* B930C 002B870C 00408021 */  addu       $s0, $v0, $zero
    /* B9310 002B8710 1200001C */  beqz       $s0, .L002B8784
    /* B9314 002B8714 00111600 */   sll       $v0, $s1, 24
    /* B9318 002B8718 04420001 */  bltzl      $v0, .L002B8720
    /* B931C 002B871C 00119823 */   negu      $s3, $s1
  .L002B8720:
    /* B9320 002B8720 8E420008 */  lw         $v0, 0x8($s2)
    /* B9324 002B8724 8EA3001C */  lw         $v1, 0x1C($s5)
    /* B9328 002B8728 8C4500D8 */  lw         $a1, 0xD8($v0)
    /* B932C 002B872C 2402000D */  addiu      $v0, $zero, 0xD
    /* B9330 002B8730 AE000000 */  sw         $zero, 0x0($s0)
    /* B9334 002B8734 A6020008 */  sh         $v0, 0x8($s0)
    /* B9338 002B8738 00651821 */  addu       $v1, $v1, $a1
    /* B933C 002B873C AE030004 */  sw         $v1, 0x4($s0)
    /* B9340 002B8740 9642001A */  lhu        $v0, 0x1A($s2)
    /* B9344 002B8744 8FA5005C */  lw         $a1, 0x5C($sp)
    /* B9348 002B8748 02A02021 */  addu       $a0, $s5, $zero
    /* B934C 002B874C A2140012 */  sb         $s4, 0x12($s0)
    /* B9350 002B8750 A6160010 */  sh         $s6, 0x10($s0)
    /* B9354 002B8754 A2130013 */  sb         $s3, 0x13($s0)
    /* B9358 002B8758 E614000C */  swc1       $fs0, 0xC($s0)
    /* B935C 002B875C 0C0AE368 */  jal        func_002B8DA0
    /* B9360 002B8760 A602000A */   sh        $v0, 0xA($s0)
    /* B9364 002B8764 AE020014 */  sw         $v0, 0x14($s0)
    /* B9368 002B8768 AE170018 */  sw         $s7, 0x18($s0)
    /* B936C 002B876C 8E420008 */  lw         $v0, 0x8($s2)
    /* B9370 002B8770 8C44000C */  lw         $a0, 0xC($v0)
    /* B9374 002B8774 24050003 */  addiu      $a1, $zero, 0x3
    /* B9378 002B8778 8C820008 */  lw         $v0, 0x8($a0)
    /* B937C 002B877C 0040F809 */  jalr       $v0
    /* B9380 002B8780 02003021 */   addu      $a2, $s0, $zero
  .L002B8784:
    /* B9384 002B8784 8FBF0030 */  lw         $ra, 0x30($sp)
    /* B9388 002B8788 8FB7002C */  lw         $s7, 0x2C($sp)
    /* B938C 002B878C 8FB60028 */  lw         $s6, 0x28($sp)
    /* B9390 002B8790 8FB50024 */  lw         $s5, 0x24($sp)
    /* B9394 002B8794 8FB40020 */  lw         $s4, 0x20($sp)
    /* B9398 002B8798 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B939C 002B879C 8FB20018 */  lw         $s2, 0x18($sp)
    /* B93A0 002B87A0 8FB10014 */  lw         $s1, 0x14($sp)
    /* B93A4 002B87A4 8FB00010 */  lw         $s0, 0x10($sp)
    /* B93A8 002B87A8 D7B40038 */  ldc1       $fs0, 0x38($sp)
    /* B93AC 002B87AC 03E00008 */  jr         $ra
    /* B93B0 002B87B0 27BD0040 */   addiu     $sp, $sp, 0x40


    /* B93B4 002B87B4 3C01800D */  .word      0x3C01800D /* linker padding */
    /* B93B8 002B87B8 D423C840 */  .word      0xD423C840 /* linker padding */
    /* B93BC 002B87BC 24830012 */  .word      0x24830012 /* linker padding */
endlabel func_002B86B0
