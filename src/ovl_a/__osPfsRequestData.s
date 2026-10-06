.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0x1B65EC-0x1B6688 (VRAM 0x004485EC) */
glabel __osPfsRequestData
    /* 1B65EC 004485EC 27BDFFF8 */  addiu      $sp, $sp, -0x8
    /* 1B65F0 004485F0 3C078015 */  lui        $a3, %hi(__osPfsPifRam)
    /* 1B65F4 004485F4 24E74110 */  addiu      $a3, $a3, %lo(__osPfsPifRam)
    /* 1B65F8 004485F8 00003021 */  addu       $a2, $zero, $zero
    /* 1B65FC 004485FC 24020001 */  addiu      $v0, $zero, 0x1
    /* 1B6600 00448600 240300FF */  addiu      $v1, $zero, 0xFF
    /* 1B6604 00448604 3C088015 */  lui        $t0, %hi(__osContNumControllers)
    /* 1B6608 00448608 2508D46C */  addiu      $t0, $t0, %lo(__osContNumControllers)
    /* 1B660C 0044860C 3C018015 */  lui        $at, %hi(__osContLastCmd)
    /* 1B6610 00448610 A024D4B0 */  sb         $a0, %lo(__osContLastCmd)($at)
    /* 1B6614 00448614 ACE2003C */  sw         $v0, 0x3C($a3)
    /* 1B6618 00448618 A3A30000 */  sb         $v1, 0x0($sp)
    /* 1B661C 0044861C A3A20001 */  sb         $v0, 0x1($sp)
    /* 1B6620 00448620 91050000 */  lbu        $a1, 0x0($t0)
    /* 1B6624 00448624 24020003 */  addiu      $v0, $zero, 0x3
    /* 1B6628 00448628 A3A20002 */  sb         $v0, 0x2($sp)
    /* 1B662C 0044862C A3A40003 */  sb         $a0, 0x3($sp)
    /* 1B6630 00448630 A3A30004 */  sb         $v1, 0x4($sp)
    /* 1B6634 00448634 A3A30005 */  sb         $v1, 0x5($sp)
    /* 1B6638 00448638 A3A30006 */  sb         $v1, 0x6($sp)
    /* 1B663C 0044863C 10A0000E */  beqz       $a1, .L00448678
    /* 1B6640 00448640 A3A30007 */   sb        $v1, 0x7($sp)
  .L00448644:
    /* 1B6644 00448644 8BA90000 */  lwl        $t1, 0x0($sp)
    /* 1B6648 00448648 9BA90003 */  lwr        $t1, 0x3($sp)
    /* 1B664C 0044864C 8BAA0004 */  lwl        $t2, 0x4($sp)
    /* 1B6650 00448650 9BAA0007 */  lwr        $t2, 0x7($sp)
    /* 1B6654 00448654 A8E90000 */  swl        $t1, 0x0($a3)
    /* 1B6658 00448658 B8E90003 */  swr        $t1, 0x3($a3)
    /* 1B665C 0044865C A8EA0004 */  swl        $t2, 0x4($a3)
    /* 1B6660 00448660 B8EA0007 */  swr        $t2, 0x7($a3)
    /* 1B6664 00448664 91020000 */  lbu        $v0, 0x0($t0)
    /* 1B6668 00448668 24C60001 */  addiu      $a2, $a2, 0x1
    /* 1B666C 0044866C 00C2102A */  slt        $v0, $a2, $v0
    /* 1B6670 00448670 1440FFF4 */  bnez       $v0, .L00448644
    /* 1B6674 00448674 24E70008 */   addiu     $a3, $a3, 0x8
  .L00448678:
    /* 1B6678 00448678 240200FE */  addiu      $v0, $zero, 0xFE
    /* 1B667C 0044867C A0E20000 */  sb         $v0, 0x0($a3)
    /* 1B6680 00448680 03E00008 */  jr         $ra
    /* 1B6684 00448684 27BD0008 */   addiu     $sp, $sp, 0x8
endlabel __osPfsRequestData
