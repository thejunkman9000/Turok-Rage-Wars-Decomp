.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xB7D30-0xB7EAC (VRAM 0x002B7130) */
.globl sinf
sinf:
    /* B7D30 002B7130 E7AC0000 */  swc1       $fa0, 0x0($sp)
    /* B7D34 002B7134 8FA20000 */  lw         $v0, 0x0($sp)
    /* B7D38 002B7138 00021D83 */  sra        $v1, $v0, 22
    /* B7D3C 002B713C 306301FF */  andi       $v1, $v1, 0x1FF
    /* B7D40 002B7140 286200FF */  slti       $v0, $v1, 0xFF
    /* B7D44 002B7144 10400019 */  .word 0x10400019
    /* B7D48 002B7148 286200E6 */  slti      $v0, $v1, 0xE6
    /* B7D4C 002B714C 14400015 */  .word 0x14400015
    /* B7D50 002B7150 00000000 */  nop
    /* B7D54 002B7154 460C60C2 */  mul.s      $fv1f, $fa0, $fa0
    /* B7D58 002B7158 3C02800C */  lui        $v0, %hi(D_auto_800C78D0)
    /* B7D5C 002B715C 244278D0 */  addiu      $v0, $v0, %lo(D_auto_800C78D0)
    /* B7D60 002B7160 D4410020 */  ldc1       $fv0f, 0x20($v0)
    /* B7D64 002B7164 460018A1 */  cvt.d.s    $fv1, $fv1f
    /* B7D68 002B7168 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* B7D6C 002B716C D4400018 */  ldc1       $fv0, 0x18($v0)
    /* B7D70 002B7170 46200840 */  add.d      $fv0f, $fv0f, $fv0
    /* B7D74 002B7174 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* B7D78 002B7178 D4400010 */  ldc1       $fv0, 0x10($v0)
    /* B7D7C 002B717C 46200840 */  add.d      $fv0f, $fv0f, $fv0
    /* B7D80 002B7180 46220842 */  mul.d      $fv0f, $fv0f, $fv1
    /* B7D84 002B7184 00000000 */  nop
    /* B7D88 002B7188 46036002 */  mul.s      $fv0, $fa0, $fv1f
    /* B7D8C 002B718C D4420008 */  ldc1       $fv1, 0x8($v0)
    /* B7D90 002B7190 46220840 */  add.d      $fv0f, $fv0f, $fv1
    /* B7D94 002B7194 46200860 */  cvt.s.d    $fv0f, $fv0f
    /* B7D98 002B7198 46010002 */  mul.s      $fv0, $fv0, $fv0f
    /* B7D9C 002B719C 03E00008 */  jr         $ra
    /* B7DA0 002B71A0 46006000 */  add.s     $fv0, $fa0, $fv0
.Lauto_002B71A4:
    /* B7DA4 002B71A4 03E00008 */  jr         $ra
    /* B7DA8 002B71A8 46006006 */  mov.s     $fv0, $fa0
.Lauto_002B71AC:
    /* B7DAC 002B71AC 28620136 */  slti       $v0, $v1, 0x136
    /* B7DB0 002B71B0 1040003A */  .word 0x1040003A
    /* B7DB4 002B71B4 00000000 */  nop
    /* B7DB8 002B71B8 3C01800C */  lui        $at, %hi(D_auto_800C78F8)
    /* B7DBC 002B71BC D42078F8 */  ldc1       $fv0, %lo(D_auto_800C78F8)($at)
    /* B7DC0 002B71C0 46006061 */  cvt.d.s    $fv0f, $fa0
    /* B7DC4 002B71C4 46200842 */  mul.d      $fv0f, $fv0f, $fv0
    /* B7DC8 002B71C8 44800000 */  mtc1       $zero, $fv0
    /* B7DCC 002B71CC 462008A0 */  cvt.s.d    $fv1, $fv0f
    /* B7DD0 002B71D0 4602003E */  c.le.s     $fv0, $fv1
    /* B7DD4 002B71D4 00000000 */  nop
    /* B7DD8 002B71D8 45000005 */  .word 0x45000005
    /* B7DDC 002B71DC 00000000 */  nop
    /* B7DE0 002B71E0 3C01800C */  lui        $at, %hi(D_auto_800C7914)
    /* B7DE4 002B71E4 C4207914 */  lwc1       $fv0, %lo(D_auto_800C7914)($at)
    /* B7DE8 002B71E8 080ADC7F */  .word 0x080ADC7F
    /* B7DEC 002B71EC 46001000 */  add.s     $fv0, $fv1, $fv0
.Lauto_002B71F0:
    /* B7DF0 002B71F0 3C01800C */  lui        $at, %hi(D_auto_800C7918)
    /* B7DF4 002B71F4 C4207918 */  lwc1       $fv0, %lo(D_auto_800C7918)($at)
    /* B7DF8 002B71F8 46001001 */  sub.s      $fv0, $fv1, $fv0
.Lauto_002B71FC:
    /* B7DFC 002B71FC 4600010D */  trunc.w.s  $ft0, $fv0
    /* B7E00 002B7200 44032000 */  mfc1       $v1, $ft0
    /* B7E04 002B7204 44831000 */  mtc1       $v1, $fv1
    /* B7E08 002B7208 468010A0 */  cvt.s.w    $fv1, $fv1
    /* B7E0C 002B720C 3C01800C */  lui        $at, %hi(D_auto_800C7900)
    /* B7E10 002B7210 D4217900 */  ldc1       $fv0f, %lo(D_auto_800C7900)($at)
    /* B7E14 002B7214 460010A1 */  cvt.d.s    $fv1, $fv1
    /* B7E18 002B7218 46211042 */  mul.d      $fv0f, $fv1, $fv0f
    /* B7E1C 002B721C 3C01800C */  lui        $at, %hi(D_auto_800C7908)
    /* B7E20 002B7220 D4207908 */  ldc1       $fv0, %lo(D_auto_800C7908)($at)
    /* B7E24 002B7224 46201082 */  mul.d      $fv1, $fv1, $fv0
    /* B7E28 002B7228 46006021 */  cvt.d.s    $fv0, $fa0
    /* B7E2C 002B722C 46210001 */  sub.d      $fv0, $fv0, $fv0f
    /* B7E30 002B7230 46200320 */  cvt.s.d    $fa0, $fv0
    /* B7E34 002B7234 46006021 */  cvt.d.s    $fv0, $fa0
    /* B7E38 002B7238 46220001 */  sub.d      $fv0, $fv0, $fv1
    /* B7E3C 002B723C 46200320 */  cvt.s.d    $fa0, $fv0
    /* B7E40 002B7240 460C60C2 */  mul.s      $fv1f, $fa0, $fa0
    /* B7E44 002B7244 3C02800C */  lui        $v0, %hi(D_auto_800C78D0)
    /* B7E48 002B7248 244278D0 */  addiu      $v0, $v0, %lo(D_auto_800C78D0)
    /* B7E4C 002B724C D4400020 */  ldc1       $fv0, 0x20($v0)
    /* B7E50 002B7250 460018A1 */  cvt.d.s    $fv1, $fv1f
    /* B7E54 002B7254 46220002 */  mul.d      $fv0, $fv0, $fv1
    /* B7E58 002B7258 D4410018 */  ldc1       $fv0f, 0x18($v0)
    /* B7E5C 002B725C 46210000 */  add.d      $fv0, $fv0, $fv0f
    /* B7E60 002B7260 46220002 */  mul.d      $fv0, $fv0, $fv1
    /* B7E64 002B7264 D4410010 */  ldc1       $fv0f, 0x10($v0)
    /* B7E68 002B7268 46210000 */  add.d      $fv0, $fv0, $fv0f
    /* B7E6C 002B726C 46220002 */  mul.d      $fv0, $fv0, $fv1
    /* B7E70 002B7270 00000000 */  nop
    /* B7E74 002B7274 46036082 */  mul.s      $fv1, $fa0, $fv1f
    /* B7E78 002B7278 D4410008 */  ldc1       $fv0f, 0x8($v0)
    /* B7E7C 002B727C 46210000 */  add.d      $fv0, $fv0, $fv0f
    /* B7E80 002B7280 46200060 */  cvt.s.d    $fv0f, $fv0
    /* B7E84 002B7284 46011082 */  mul.s      $fv1, $fv1, $fv0f
    /* B7E88 002B7288 30620001 */  andi       $v0, $v1, 0x1
    /* B7E8C 002B728C 10400005 */  .word 0x10400005
    /* B7E90 002B7290 46026000 */  add.s     $fv0, $fa0, $fv1
    /* B7E94 002B7294 03E00008 */  jr         $ra
    /* B7E98 002B7298 46000007 */  neg.s     $fv0, $fv0
.Lauto_002B729C:
    /* B7E9C 002B729C 3C01800C */  lui        $at, %hi(D_auto_800C7910)
    /* B7EA0 002B72A0 C4207910 */  lwc1       $fv0, %lo(D_auto_800C7910)($at)
.Lauto_002B72A4:
    /* B7EA4 002B72A4 03E00008 */  jr         $ra
    /* B7EA8 002B72A8 00000000 */  nop
