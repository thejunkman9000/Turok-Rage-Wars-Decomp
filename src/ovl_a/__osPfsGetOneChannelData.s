.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B5B34-0x1B5BB0 (VRAM 0x00447B34) */
glabel __osPfsGetOneChannelData
    /* 1B5B34 00447B34 27BDFFF8 */  addiu      $sp, $sp, -0x8
    /* 1B5B38 00447B38 3C068015 */  lui        $a2, %hi(__osPfsPifRam)
    /* 1B5B3C 00447B3C 24C64110 */  addiu      $a2, $a2, %lo(__osPfsPifRam)
    /* 1B5B40 00447B40 18800005 */  blez       $a0, .L00447B58
    /* 1B5B44 00447B44 00001821 */   addu      $v1, $zero, $zero
  .L00447B48:
    /* 1B5B48 00447B48 24630001 */  addiu      $v1, $v1, 0x1
    /* 1B5B4C 00447B4C 0064102A */  slt        $v0, $v1, $a0
    /* 1B5B50 00447B50 1440FFFD */  bnez       $v0, .L00447B48
    /* 1B5B54 00447B54 24C60001 */   addiu     $a2, $a2, 0x1
  .L00447B58:
    /* 1B5B58 00447B58 88C70000 */  lwl        $a3, 0x0($a2)
    /* 1B5B5C 00447B5C 98C70003 */  lwr        $a3, 0x3($a2)
    /* 1B5B60 00447B60 80C80004 */  lb         $t0, 0x4($a2)
    /* 1B5B64 00447B64 80C90005 */  lb         $t1, 0x5($a2)
    /* 1B5B68 00447B68 ABA70000 */  swl        $a3, 0x0($sp)
    /* 1B5B6C 00447B6C BBA70003 */  swr        $a3, 0x3($sp)
    /* 1B5B70 00447B70 A3A80004 */  sb         $t0, 0x4($sp)
    /* 1B5B74 00447B74 A3A90005 */  sb         $t1, 0x5($sp)
    /* 1B5B78 00447B78 93A20001 */  lbu        $v0, 0x1($sp)
    /* 1B5B7C 00447B7C 304200C0 */  andi       $v0, $v0, 0xC0
    /* 1B5B80 00447B80 00021102 */  srl        $v0, $v0, 4
    /* 1B5B84 00447B84 14400008 */  bnez       $v0, .L00447BA8
    /* 1B5B88 00447B88 A0A20003 */   sb        $v0, 0x3($a1)
    /* 1B5B8C 00447B8C 93A20004 */  lbu        $v0, 0x4($sp)
    /* 1B5B90 00447B90 93A30003 */  lbu        $v1, 0x3($sp)
    /* 1B5B94 00447B94 00021200 */  sll        $v0, $v0, 8
    /* 1B5B98 00447B98 00621825 */  or         $v1, $v1, $v0
    /* 1B5B9C 00447B9C A4A30000 */  sh         $v1, 0x0($a1)
    /* 1B5BA0 00447BA0 93A20005 */  lbu        $v0, 0x5($sp)
    /* 1B5BA4 00447BA4 A0A20002 */  sb         $v0, 0x2($a1)
  .L00447BA8:
    /* 1B5BA8 00447BA8 03E00008 */  jr         $ra
    /* 1B5BAC 00447BAC 27BD0008 */   addiu     $sp, $sp, 0x8
endlabel __osPfsGetOneChannelData
