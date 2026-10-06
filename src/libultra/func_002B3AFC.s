.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB46FC-0xB4770 (VRAM 0x002B3AFC) */
glabel func_002B3AFC
    /* B46FC 002B3AFC 27BDFFE0 */  addiu      $sp, $sp, -0x20
    /* B4700 002B3B00 AFB10014 */  sw         $s1, 0x14($sp)
    /* B4704 002B3B04 00808821 */  addu       $s1, $a0, $zero
    /* B4708 002B3B08 AFB20018 */  sw         $s2, 0x18($sp)
    /* B470C 002B3B0C 00A09021 */  addu       $s2, $a1, $zero
    /* B4710 002B3B10 AFBF001C */  sw         $ra, 0x1C($sp)
    /* B4714 002B3B14 0C0ACD74 */  jal        func_002B35D0
    /* B4718 002B3B18 AFB00010 */   sw        $s0, 0x10($sp)
    /* B471C 002B3B1C 305000FF */  andi       $s0, $v0, 0xFF
    /* B4720 002B3B20 32020080 */  andi       $v0, $s0, 0x80
    /* B4724 002B3B24 1040000C */  beqz       $v0, .L002B3B58
    /* B4728 002B3B28 02001021 */   addu      $v0, $s0, $zero
    /* B472C 002B3B2C 3210007F */  andi       $s0, $s0, 0x7F
  .L002B3B30:
    /* B4730 002B3B30 02202021 */  addu       $a0, $s1, $zero
    /* B4734 002B3B34 0C0ACD74 */  jal        func_002B35D0
    /* B4738 002B3B38 02402821 */   addu      $a1, $s2, $zero
    /* B473C 002B3B3C 304200FF */  andi       $v0, $v0, 0xFF
    /* B4740 002B3B40 001021C0 */  sll        $a0, $s0, 7
    /* B4744 002B3B44 3043007F */  andi       $v1, $v0, 0x7F
    /* B4748 002B3B48 30420080 */  andi       $v0, $v0, 0x80
    /* B474C 002B3B4C 1440FFF8 */  bnez       $v0, .L002B3B30
    /* B4750 002B3B50 00838021 */   addu      $s0, $a0, $v1
    /* B4754 002B3B54 02001021 */  addu       $v0, $s0, $zero
  .L002B3B58:
    /* B4758 002B3B58 8FBF001C */  lw         $ra, 0x1C($sp)
    /* B475C 002B3B5C 8FB20018 */  lw         $s2, 0x18($sp)
    /* B4760 002B3B60 8FB10014 */  lw         $s1, 0x14($sp)
    /* B4764 002B3B64 8FB00010 */  lw         $s0, 0x10($sp)
    /* B4768 002B3B68 03E00008 */  jr         $ra
    /* B476C 002B3B6C 27BD0020 */   addiu     $sp, $sp, 0x20
endlabel func_002B3AFC
