.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B5AA8-0x1B5B34 (VRAM 0x00447AA8) */
glabel __osPfsRequestOneChannel
    /* 1B5AA8 00447AA8 27BDFFF8 */  addiu      $sp, $sp, -0x8
    /* 1B5AAC 00447AAC 3C028015 */  lui        $v0, %hi(__osPfsPifRam)
    /* 1B5AB0 00447AB0 24424110 */  addiu      $v0, $v0, %lo(__osPfsPifRam)
    /* 1B5AB4 00447AB4 00401821 */  addu       $v1, $v0, $zero
    /* 1B5AB8 00447AB8 00002821 */  addu       $a1, $zero, $zero
    /* 1B5ABC 00447ABC 24020001 */  addiu      $v0, $zero, 0x1
    /* 1B5AC0 00447AC0 AC62003C */  sw         $v0, 0x3C($v1)
    /* 1B5AC4 00447AC4 A3A20000 */  sb         $v0, 0x0($sp)
    /* 1B5AC8 00447AC8 24020003 */  addiu      $v0, $zero, 0x3
    /* 1B5ACC 00447ACC A3A20001 */  sb         $v0, 0x1($sp)
    /* 1B5AD0 00447AD0 240200FF */  addiu      $v0, $zero, 0xFF
    /* 1B5AD4 00447AD4 3C018015 */  lui        $at, %hi(__osContLastCmd)
    /* 1B5AD8 00447AD8 A020D4B0 */  sb         $zero, %lo(__osContLastCmd)($at)
    /* 1B5ADC 00447ADC A3A00002 */  sb         $zero, 0x2($sp)
    /* 1B5AE0 00447AE0 A3A20003 */  sb         $v0, 0x3($sp)
    /* 1B5AE4 00447AE4 A3A20004 */  sb         $v0, 0x4($sp)
    /* 1B5AE8 00447AE8 18800006 */  blez       $a0, .L00447B04
    /* 1B5AEC 00447AEC A3A20005 */   sb        $v0, 0x5($sp)
  .L00447AF0:
    /* 1B5AF0 00447AF0 A0600000 */  sb         $zero, 0x0($v1)
    /* 1B5AF4 00447AF4 24A50001 */  addiu      $a1, $a1, 0x1
    /* 1B5AF8 00447AF8 00A4102A */  slt        $v0, $a1, $a0
    /* 1B5AFC 00447AFC 1440FFFC */  bnez       $v0, .L00447AF0
    /* 1B5B00 00447B00 24630001 */   addiu     $v1, $v1, 0x1
  .L00447B04:
    /* 1B5B04 00447B04 240200FE */  addiu      $v0, $zero, 0xFE
    /* 1B5B08 00447B08 8BA60000 */  lwl        $a2, 0x0($sp)
    /* 1B5B0C 00447B0C 9BA60003 */  lwr        $a2, 0x3($sp)
    /* 1B5B10 00447B10 83A70004 */  lb         $a3, 0x4($sp)
    /* 1B5B14 00447B14 83A80005 */  lb         $t0, 0x5($sp)
    /* 1B5B18 00447B18 A8660000 */  swl        $a2, 0x0($v1)
    /* 1B5B1C 00447B1C B8660003 */  swr        $a2, 0x3($v1)
    /* 1B5B20 00447B20 A0670004 */  sb         $a3, 0x4($v1)
    /* 1B5B24 00447B24 A0680005 */  sb         $t0, 0x5($v1)
    /* 1B5B28 00447B28 A0620006 */  sb         $v0, 0x6($v1)
    /* 1B5B2C 00447B2C 03E00008 */  jr         $ra
    /* 1B5B30 00447B30 27BD0008 */   addiu     $sp, $sp, 0x8
endlabel __osPfsRequestOneChannel
