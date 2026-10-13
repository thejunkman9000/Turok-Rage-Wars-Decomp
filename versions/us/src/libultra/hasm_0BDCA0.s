.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDCA0-0xBDD48 (VRAM 0x002BD0A0) */
.globl osSetIntMask
osSetIntMask:
    /* BDCA0 002BD0A0 400C6000 */  mfc0       $t4, $12 /* handwritten instruction */
    /* BDCA4 002BD0A4 3C08800D */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BDCA8 002BD0A8 25083F08 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BDCAC 002BD0AC 3182FF01 */  andi       $v0, $t4, 0xFF01
    /* BDCB0 002BD0B0 8D0B0000 */  lw         $t3, 0x0($t0)
    /* BDCB4 002BD0B4 00000000 */  nop
    /* BDCB8 002BD0B8 2401FFFF */  addiu      $at, $zero, -0x1
    /* BDCBC 002BD0BC 01614026 */  xor        $t0, $t3, $at
    /* BDCC0 002BD0C0 3108FF00 */  andi       $t0, $t0, 0xFF00
    /* BDCC4 002BD0C4 00481025 */  or         $v0, $v0, $t0
    /* BDCC8 002BD0C8 3C0AA430 */  lui        $t2, %hi(MI_INTR_MASK_REG)
    /* BDCCC 002BD0CC 8D4A000C */  lw         $t2, %lo(MI_INTR_MASK_REG)($t2)
    /* BDCD0 002BD0D0 00000000 */  nop
    /* BDCD4 002BD0D4 11400005 */  .word 0x11400005
    /* BDCD8 002BD0D8 000B4C02 */  srl       $t1, $t3, 16
    /* BDCDC 002BD0DC 2401FFFF */  addiu      $at, $zero, -0x1
    /* BDCE0 002BD0E0 01214826 */  xor        $t1, $t1, $at
    /* BDCE4 002BD0E4 3129003F */  andi       $t1, $t1, 0x3F
    /* BDCE8 002BD0E8 01495025 */  or         $t2, $t2, $t1
.Lauto_002BD0EC:
    /* BDCEC 002BD0EC 000A5400 */  sll        $t2, $t2, 16
    /* BDCF0 002BD0F0 004A1025 */  or         $v0, $v0, $t2
    /* BDCF4 002BD0F4 3C01003F */  lui        $at, (0x3F0000 >> 16)
    /* BDCF8 002BD0F8 00814024 */  and        $t0, $a0, $at
    /* BDCFC 002BD0FC 010B4024 */  and        $t0, $t0, $t3
    /* BDD00 002BD100 000843C2 */  srl        $t0, $t0, 15
    /* BDD04 002BD104 3C01800C */  lui        $at, %hi(__osRcpImTable)
    /* BDD08 002BD108 00280821 */  addu       $at, $at, $t0
    /* BDD0C 002BD10C 942A7990 */  lhu        $t2, %lo(__osRcpImTable)($at)
    /* BDD10 002BD110 3C01A430 */  lui        $at, %hi(MI_INTR_MASK_REG)
    /* BDD14 002BD114 AC2A000C */  sw         $t2, %lo(MI_INTR_MASK_REG)($at)
    /* BDD18 002BD118 3088FF01 */  andi       $t0, $a0, 0xFF01
    /* BDD1C 002BD11C 3169FF00 */  andi       $t1, $t3, 0xFF00
    /* BDD20 002BD120 01094024 */  and        $t0, $t0, $t1
    /* BDD24 002BD124 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* BDD28 002BD128 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* BDD2C 002BD12C 01816024 */  and        $t4, $t4, $at
    /* BDD30 002BD130 01886025 */  or         $t4, $t4, $t0
    /* BDD34 002BD134 408C6000 */  mtc0       $t4, $12 /* handwritten instruction */
    /* BDD38 002BD138 00000000 */  nop
    /* BDD3C 002BD13C 00000000 */  nop
    /* BDD40 002BD140 03E00008 */  jr         $ra
    /* BDD44 002BD144 00000000 */  nop
