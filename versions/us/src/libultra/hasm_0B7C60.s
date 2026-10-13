.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xB7C60-0xB7DF0 (VRAM 0x002B7060) */
.globl sinf
sinf:
    /* B7C60 002B7060 E7AC0000 */  swc1       $fa0, 0x0($sp)
    /* B7C64 002B7064 8FA20000 */  lw         $v0, 0x0($sp)
    /* B7C68 002B7068 00021D83 */  sra        $v1, $v0, 22
    /* B7C6C 002B706C 306301FF */  andi       $v1, $v1, 0x1FF
    /* B7C70 002B7070 286200FF */  slti       $v0, $v1, 0xFF
    /* B7C74 002B7074 10400019 */  .word 0x10400019
    /* B7C78 002B7078 286200E6 */  slti      $v0, $v1, 0xE6
    /* B7C7C 002B707C 14400015 */  .word 0x14400015
    /* B7C80 002B7080 00000000 */  nop
    /* B7C84 002B7084 460C60C2 */  mul.s      $fv1f, $fa0, $fa0
    /* B7C88 002B7088 3C02800C */  lui        $v0, %hi(D_auto_800C77F0)
    /* B7C8C 002B708C 244277F0 */  addiu      $v0, $v0, %lo(D_auto_800C77F0)
    /* B7C90 002B7090 D4410020 */  ldc1       $fv0f, 0x20($v0)
    /* B7C94 002B7094 460018A1 */  cvt.d.s    $fv1, $fv1f
    /* B7C98 002B7098 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* B7C9C 002B709C D4400018 */  ldc1       $fv0, 0x18($v0)
    /* B7CA0 002B70A0 46200840 */  add.d      $fv0f, $fv0f, $fv0
    /* B7CA4 002B70A4 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* B7CA8 002B70A8 D4400010 */  ldc1       $fv0, 0x10($v0)
    /* B7CAC 002B70AC 46200840 */  add.d      $fv0f, $fv0f, $fv0
    /* B7CB0 002B70B0 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* B7CB4 002B70B4 00000000 */  nop
    /* B7CB8 002B70B8 46036002 */  mul.s      $fv0, $fa0, $fv1f
    /* B7CBC 002B70BC D4420008 */  ldc1       $fv1, 0x8($v0)
    /* B7CC0 002B70C0 46220840 */  add.d      $fv0f, $fv0f, $fv1
    /* B7CC4 002B70C4 46200860 */  cvt.s.d    $fv0f, $fv0f
    /* B7CC8 002B70C8 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* B7CCC 002B70CC 03E00008 */  jr         $ra
    /* B7CD0 002B70D0 46006000 */  add.s     $fv0, $fa0, $fv0
.Lauto_002B70D4:
    /* B7CD4 002B70D4 03E00008 */  jr         $ra
    /* B7CD8 002B70D8 46006006 */  mov.s     $fv0, $fa0
.Lauto_002B70DC:
    /* B7CDC 002B70DC 28620136 */  slti       $v0, $v1, 0x136
    /* B7CE0 002B70E0 1040003A */  .word 0x1040003A
    /* B7CE4 002B70E4 00000000 */  nop
    /* B7CE8 002B70E8 3C01800C */  lui        $at, %hi(D_auto_800C7818)
    /* B7CEC 002B70EC D4207818 */  ldc1       $fv0, %lo(D_auto_800C7818)($at)
    /* B7CF0 002B70F0 46006061 */  cvt.d.s    $fv0f, $fa0
    /* B7CF4 002B70F4 46200842 */  mul.d      $fv0f, $fv0f, $fv0
    /* B7CF8 002B70F8 44800000 */  mtc1       $zero, $fv0
    /* B7CFC 002B70FC 462008A0 */  cvt.s.d    $fv1, $fv0f
    /* B7D00 002B7100 4602003E */  c.le.s     $fv0, $fv1
    /* B7D04 002B7104 00000000 */  nop
    /* B7D08 002B7108 45000005 */  .word 0x45000005
    /* B7D0C 002B710C 00000000 */  nop
    /* B7D10 002B7110 3C01800C */  lui        $at, %hi(D_auto_800C7834)
    /* B7D14 002B7114 C4207834 */  lwc1       $fv0, %lo(D_auto_800C7834)($at)
    /* B7D18 002B7118 080ADC4B */  .word 0x080ADC4B
    /* B7D1C 002B711C 46001000 */  add.s     $fv0, $fv1, $fv0
.Lauto_002B7120:
    /* B7D20 002B7120 3C01800C */  lui        $at, %hi(D_auto_800C7838)
    /* B7D24 002B7124 C4207838 */  lwc1       $fv0, %lo(D_auto_800C7838)($at)
    /* B7D28 002B7128 46001001 */  sub.s      $fv0, $fv1, $fv0
.Lauto_002B712C:
    /* B7D2C 002B712C 4600010D */  trunc.w.s  $ft0, $fv0
    /* B7D30 002B7130 44032000 */  mfc1       $v1, $ft0
    /* B7D34 002B7134 44831000 */  mtc1       $v1, $fv1
    /* B7D38 002B7138 468010A0 */  cvt.s.w    $fv1, $fv1
    /* B7D3C 002B713C 3C01800C */  lui        $at, %hi(D_auto_800C7820)
    /* B7D40 002B7140 D4217820 */  ldc1       $fv0f, %lo(D_auto_800C7820)($at)
    /* B7D44 002B7144 460010A1 */  cvt.d.s    $fv1, $fv1
    /* B7D48 002B7148 46211042 */  mul.d      $fv0f, $fv1, $fv0f
    /* B7D4C 002B714C 3C01800C */  lui        $at, %hi(D_auto_800C7828)
    /* B7D50 002B7150 D4207828 */  ldc1       $fv0, %lo(D_auto_800C7828)($at)
    /* B7D54 002B7154 46201082 */  mul.d      $fv1, $fv1, $fv0
    /* B7D58 002B7158 46006021 */  cvt.d.s    $fv0, $fa0
    /* B7D5C 002B715C 46210001 */  sub.d      $fv0, $fv0, $fv0f
    /* B7D60 002B7160 46200320 */  cvt.s.d    $fa0, $fv0
    /* B7D64 002B7164 46006021 */  cvt.d.s    $fv0, $fa0
    /* B7D68 002B7168 46220001 */  sub.d      $fv0, $fv0, $fv1
    /* B7D6C 002B716C 46200320 */  cvt.s.d    $fa0, $fv0
    /* B7D70 002B7170 460C60C2 */  mul.s      $fv1f, $fa0, $fa0
    /* B7D74 002B7174 3C02800C */  lui        $v0, %hi(D_auto_800C77F0)
    /* B7D78 002B7178 244277F0 */  addiu      $v0, $v0, %lo(D_auto_800C77F0)
    /* B7D7C 002B717C D4400020 */  ldc1       $fv0, 0x20($v0)
    /* B7D80 002B7180 460018A1 */  cvt.d.s    $fv1, $fv1f
    /* B7D84 002B7184 46220002 */  mul.d      $fv0, $fv0, $fv1
    /* B7D88 002B7188 D4410018 */  ldc1       $fv0f, 0x18($v0)
    /* B7D8C 002B718C 46210000 */  add.d      $fv0, $fv0, $fv0f
    /* B7D90 002B7190 46220002 */  mul.d      $fv0, $fv0, $fv1
    /* B7D94 002B7194 D4410010 */  ldc1       $fv0f, 0x10($v0)
    /* B7D98 002B7198 46210000 */  add.d      $fv0, $fv0, $fv0f
    /* B7D9C 002B719C 46220002 */  mul.d      $fv0, $fv0, $fv1
    /* B7DA0 002B71A0 00000000 */  nop
    /* B7DA4 002B71A4 46036082 */  mul.s      $fv1, $fa0, $fv1f
    /* B7DA8 002B71A8 D4410008 */  ldc1       $fv0f, 0x8($v0)
    /* B7DAC 002B71AC 46210000 */  add.d      $fv0, $fv0, $fv0f
    /* B7DB0 002B71B0 46200060 */  cvt.s.d    $fv0f, $fv0
    /* B7DB4 002B71B4 46011082 */  mul.s      $fv1, $fv1, $fv0f
    /* B7DB8 002B71B8 30620001 */  andi       $v0, $v1, 0x1
    /* B7DBC 002B71BC 10400005 */  .word 0x10400005
    /* B7DC0 002B71C0 46026000 */  add.s     $fv0, $fa0, $fv1
    /* B7DC4 002B71C4 03E00008 */  jr         $ra
    /* B7DC8 002B71C8 46000007 */  neg.s     $fv0, $fv0
.Lauto_002B71CC:
    /* B7DCC 002B71CC 3C01800C */  lui        $at, %hi(D_auto_800C7830)
    /* B7DD0 002B71D0 C4207830 */  lwc1       $fv0, %lo(D_auto_800C7830)($at)
.Lauto_002B71D4:
    /* B7DD4 002B71D4 03E00008 */  jr         $ra
    /* B7DD8 002B71D8 00000000 */  nop
.globl D_auto_002B71DC
D_auto_002B71DC:
    /* B7DDC 002B71DC 5F426F73 */  .word 0x5F426F73
.globl sqrtf
sqrtf:
    /* B7DE0 002B71E0 46006004 */  sqrt.s     $fv0, $fa0
    /* B7DE4 002B71E4 03E00008 */  jr         $ra
    /* B7DE8 002B71E8 00000000 */  nop
    /* B7DEC 002B71EC 90000000 */  lbu        $zero, 0x0($zero)
