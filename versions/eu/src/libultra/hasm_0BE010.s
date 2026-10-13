.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBE010-0xBE0B8 (VRAM 0x002BD410) */
.globl osSetIntMask
osSetIntMask:
    /* BE010 002BD410 400C6000 */  mfc0       $t4, $12 /* handwritten instruction */
    /* BE014 002BD414 3C08800E */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BE018 002BD418 250858D8 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BE01C 002BD41C 3182FF01 */  andi       $v0, $t4, 0xFF01
    /* BE020 002BD420 8D0B0000 */  lw         $t3, 0x0($t0)
    /* BE024 002BD424 00000000 */  nop
    /* BE028 002BD428 2401FFFF */  addiu      $at, $zero, -0x1
    /* BE02C 002BD42C 01614026 */  xor        $t0, $t3, $at
    /* BE030 002BD430 3108FF00 */  andi       $t0, $t0, 0xFF00
    /* BE034 002BD434 00481025 */  or         $v0, $v0, $t0
    /* BE038 002BD438 3C0AA430 */  lui        $t2, %hi(MI_INTR_MASK_REG)
    /* BE03C 002BD43C 8D4A000C */  lw         $t2, %lo(MI_INTR_MASK_REG)($t2)
    /* BE040 002BD440 00000000 */  nop
    /* BE044 002BD444 11400005 */  .word 0x11400005
    /* BE048 002BD448 000B4C02 */  srl       $t1, $t3, 16
    /* BE04C 002BD44C 2401FFFF */  addiu      $at, $zero, -0x1
    /* BE050 002BD450 01214826 */  xor        $t1, $t1, $at
    /* BE054 002BD454 3129003F */  andi       $t1, $t1, 0x3F
    /* BE058 002BD458 01495025 */  or         $t2, $t2, $t1
.Lauto_002BD45C:
    /* BE05C 002BD45C 000A5400 */  sll        $t2, $t2, 16
    /* BE060 002BD460 004A1025 */  or         $v0, $v0, $t2
    /* BE064 002BD464 3C01003F */  lui        $at, (0x3F0000 >> 16)
    /* BE068 002BD468 00814024 */  and        $t0, $a0, $at
    /* BE06C 002BD46C 010B4024 */  and        $t0, $t0, $t3
    /* BE070 002BD470 000843C2 */  srl        $t0, $t0, 15
    /* BE074 002BD474 3C01800D */  lui        $at, %hi(__osRcpImTable)
    /* BE078 002BD478 00280821 */  addu       $at, $at, $t0
    /* BE07C 002BD47C 942A8660 */  lhu        $t2, %lo(__osRcpImTable)($at)
    /* BE080 002BD480 3C01A430 */  lui        $at, %hi(MI_INTR_MASK_REG)
    /* BE084 002BD484 AC2A000C */  sw         $t2, %lo(MI_INTR_MASK_REG)($at)
    /* BE088 002BD488 3088FF01 */  andi       $t0, $a0, 0xFF01
    /* BE08C 002BD48C 3169FF00 */  andi       $t1, $t3, 0xFF00
    /* BE090 002BD490 01094024 */  and        $t0, $t0, $t1
    /* BE094 002BD494 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* BE098 002BD498 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* BE09C 002BD49C 01816024 */  and        $t4, $t4, $at
    /* BE0A0 002BD4A0 01886025 */  or         $t4, $t4, $t0
    /* BE0A4 002BD4A4 408C6000 */  mtc0       $t4, $12 /* handwritten instruction */
    /* BE0A8 002BD4A8 00000000 */  nop
    /* BE0AC 002BD4AC 00000000 */  nop
    /* BE0B0 002BD4B0 03E00008 */  jr         $ra
    /* BE0B4 002BD4B4 00000000 */  nop
