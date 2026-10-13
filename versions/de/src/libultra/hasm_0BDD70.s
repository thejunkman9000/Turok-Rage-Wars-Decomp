.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBDD70-0xBDE18 (VRAM 0x002BD170) */
.globl osSetIntMask
osSetIntMask:
    /* BDD70 002BD170 400C6000 */  mfc0       $t4, $12 /* handwritten instruction */
    /* BDD74 002BD174 3C08800D */  lui        $t0, %hi(__OSGlobalIntMask)
    /* BDD78 002BD178 25085258 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    /* BDD7C 002BD17C 3182FF01 */  andi       $v0, $t4, 0xFF01
    /* BDD80 002BD180 8D0B0000 */  lw         $t3, 0x0($t0)
    /* BDD84 002BD184 00000000 */  nop
    /* BDD88 002BD188 2401FFFF */  addiu      $at, $zero, -0x1
    /* BDD8C 002BD18C 01614026 */  xor        $t0, $t3, $at
    /* BDD90 002BD190 3108FF00 */  andi       $t0, $t0, 0xFF00
    /* BDD94 002BD194 00481025 */  or         $v0, $v0, $t0
    /* BDD98 002BD198 3C0AA430 */  lui        $t2, %hi(MI_INTR_MASK_REG)
    /* BDD9C 002BD19C 8D4A000C */  lw         $t2, %lo(MI_INTR_MASK_REG)($t2)
    /* BDDA0 002BD1A0 00000000 */  nop
    /* BDDA4 002BD1A4 11400005 */  .word 0x11400005
    /* BDDA8 002BD1A8 000B4C02 */  srl       $t1, $t3, 16
    /* BDDAC 002BD1AC 2401FFFF */  addiu      $at, $zero, -0x1
    /* BDDB0 002BD1B0 01214826 */  xor        $t1, $t1, $at
    /* BDDB4 002BD1B4 3129003F */  andi       $t1, $t1, 0x3F
    /* BDDB8 002BD1B8 01495025 */  or         $t2, $t2, $t1
.Lauto_002BD1BC:
    /* BDDBC 002BD1BC 000A5400 */  sll        $t2, $t2, 16
    /* BDDC0 002BD1C0 004A1025 */  or         $v0, $v0, $t2
    /* BDDC4 002BD1C4 3C01003F */  lui        $at, (0x3F0000 >> 16)
    /* BDDC8 002BD1C8 00814024 */  and        $t0, $a0, $at
    /* BDDCC 002BD1CC 010B4024 */  and        $t0, $t0, $t3
    /* BDDD0 002BD1D0 000843C2 */  srl        $t0, $t0, 15
    /* BDDD4 002BD1D4 3C01800C */  lui        $at, %hi(__osRcpImTable)
    /* BDDD8 002BD1D8 00280821 */  addu       $at, $at, $t0
    /* BDDDC 002BD1DC 942A7A70 */  lhu        $t2, %lo(__osRcpImTable)($at)
    /* BDDE0 002BD1E0 3C01A430 */  lui        $at, %hi(MI_INTR_MASK_REG)
    /* BDDE4 002BD1E4 AC2A000C */  sw         $t2, %lo(MI_INTR_MASK_REG)($at)
    /* BDDE8 002BD1E8 3088FF01 */  andi       $t0, $a0, 0xFF01
    /* BDDEC 002BD1EC 3169FF00 */  andi       $t1, $t3, 0xFF00
    /* BDDF0 002BD1F0 01094024 */  and        $t0, $t0, $t1
    /* BDDF4 002BD1F4 3C01FFFF */  lui        $at, (0xFFFF00FF >> 16)
    /* BDDF8 002BD1F8 342100FF */  ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    /* BDDFC 002BD1FC 01816024 */  and        $t4, $t4, $at
    /* BDE00 002BD200 01886025 */  or         $t4, $t4, $t0
    /* BDE04 002BD204 408C6000 */  mtc0       $t4, $12 /* handwritten instruction */
    /* BDE08 002BD208 00000000 */  nop
    /* BDE0C 002BD20C 00000000 */  nop
    /* BDE10 002BD210 03E00008 */  jr         $ra
    /* BDE14 002BD214 00000000 */  nop
