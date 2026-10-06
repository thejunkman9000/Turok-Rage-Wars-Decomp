.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB11C8-0xB151C (VRAM 0x002B05C8) */
glabel func_002B05C8
    /* B11C8 002B05C8 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B11CC 002B05CC 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B11D0 002B05D0 27BDFFC0 */  addiu      $sp, $sp, -0x40
    /* B11D4 002B05D4 AFBE0038 */  sw         $fp, 0x38($sp)
    /* B11D8 002B05D8 0080F021 */  addu       $fp, $a0, $zero
    /* B11DC 002B05DC AFB70034 */  sw         $s7, 0x34($sp)
    /* B11E0 002B05E0 00A0B821 */  addu       $s7, $a1, $zero
    /* B11E4 002B05E4 AFB60030 */  sw         $s6, 0x30($sp)
    /* B11E8 002B05E8 00E0B021 */  addu       $s6, $a3, $zero
    /* B11EC 002B05EC AFB20020 */  sw         $s2, 0x20($sp)
    /* B11F0 002B05F0 24120064 */  addiu      $s2, $zero, 0x64
    /* B11F4 002B05F4 AFBF003C */  sw         $ra, 0x3C($sp)
    /* B11F8 002B05F8 AFB5002C */  sw         $s5, 0x2C($sp)
    /* B11FC 002B05FC AFB40028 */  sw         $s4, 0x28($sp)
    /* B1200 002B0600 AFB30024 */  sw         $s3, 0x24($sp)
    /* B1204 002B0604 AFB1001C */  sw         $s1, 0x1C($sp)
    /* B1208 002B0608 AFB00018 */  sw         $s0, 0x18($sp)
    /* B120C 002B060C AFA60048 */  sw         $a2, 0x48($sp)
    /* B1210 002B0610 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B1214 002B0614 AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B1218 002B0618 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B121C 002B061C AC323650 */  sw         $s2, %lo(D_800D3650)($at)
    /* B1220 002B0620 34420004 */  ori        $v0, $v0, 0x4
    /* B1224 002B0624 00409821 */  addu       $s3, $v0, $zero
    /* B1228 002B0628 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B122C 002B062C A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B0630:
    /* B1230 002B0630 0C0AF7A8 */  jal        osPiGetStatus
    /* B1234 002B0634 00000000 */   nop
    /* B1238 002B0638 30420003 */  andi       $v0, $v0, 0x3
    /* B123C 002B063C 1440FFFC */  bnez       $v0, .L002B0630
    /* B1240 002B0640 24150002 */   addiu     $s5, $zero, 0x2
    /* B1244 002B0644 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B1248 002B0648 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B124C 002B064C 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B1250 002B0650 24140002 */  addiu      $s4, $zero, 0x2
    /* B1254 002B0654 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B1258 002B0658 A4330004 */  sh         $s3, %lo(D_B2000004)($at)
  .L002B065C:
    /* B125C 002B065C 0C0AF7A8 */  jal        osPiGetStatus
    /* B1260 002B0660 00000000 */   nop
    /* B1264 002B0664 30420003 */  andi       $v0, $v0, 0x3
    /* B1268 002B0668 1440FFFC */  bnez       $v0, .L002B065C
    /* B126C 002B066C 00000000 */   nop
    /* B1270 002B0670 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B1274 002B0674 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B1278 002B0678 00551024 */  and        $v0, $v0, $s5
    /* B127C 002B067C 10540009 */  beq        $v0, $s4, .L002B06A4
    /* B1280 002B0680 02001021 */   addu      $v0, $s0, $zero
    /* B1284 002B0684 14400003 */  bnez       $v0, .L002B0694
    /* B1288 002B0688 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B128C 002B068C 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B1290 002B0690 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B0694:
    /* B1294 002B0694 1E20FFF1 */  bgtz       $s1, .L002B065C
    /* B1298 002B0698 24020001 */   addiu     $v0, $zero, 0x1
    /* B129C 002B069C 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B12A0 002B06A0 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B06A4:
    /* B12A4 002B06A4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B12A8 002B06A8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B12AC 002B06AC 1440007F */  bnez       $v0, .L002B08AC
    /* B12B0 002B06B0 00000000 */   nop
    /* B12B4 002B06B4 0C0AB96B */  jal        func_002AE5AC
    /* B12B8 002B06B8 24040010 */   addiu     $a0, $zero, 0x10
    /* B12BC 002B06BC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B12C0 002B06C0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B12C4 002B06C4 1440000A */  bnez       $v0, .L002B06F0
    /* B12C8 002B06C8 00008021 */   addu      $s0, $zero, $zero
    /* B12CC 002B06CC 0C0AB8E0 */  jal        func_002AE380
    /* B12D0 002B06D0 27A40010 */   addiu     $a0, $sp, 0x10
    /* B12D4 002B06D4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B12D8 002B06D8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B12DC 002B06DC 14400004 */  bnez       $v0, .L002B06F0
    /* B12E0 002B06E0 00000000 */   nop
    /* B12E4 002B06E4 93A20010 */  lbu        $v0, 0x10($sp)
    /* B12E8 002B06E8 38420011 */  xori       $v0, $v0, 0x11
    /* B12EC 002B06EC 2C500001 */  sltiu      $s0, $v0, 0x1
  .L002B06F0:
    /* B12F0 002B06F0 1200006E */  beqz       $s0, .L002B08AC
    /* B12F4 002B06F4 00000000 */   nop
    /* B12F8 002B06F8 0C0AB96B */  jal        func_002AE5AC
    /* B12FC 002B06FC 24040083 */   addiu     $a0, $zero, 0x83
    /* B1300 002B0700 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1304 002B0704 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1308 002B0708 14400068 */  bnez       $v0, .L002B08AC
    /* B130C 002B070C 00000000 */   nop
    /* B1310 002B0710 0C0AB96B */  jal        func_002AE5AC
    /* B1314 002B0714 00162602 */   srl       $a0, $s6, 24
    /* B1318 002B0718 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B131C 002B071C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1320 002B0720 14400062 */  bnez       $v0, .L002B08AC
    /* B1324 002B0724 00162402 */   srl       $a0, $s6, 16
    /* B1328 002B0728 0C0AB96B */  jal        func_002AE5AC
    /* B132C 002B072C 308400FF */   andi      $a0, $a0, 0xFF
    /* B1330 002B0730 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1334 002B0734 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1338 002B0738 1440005C */  bnez       $v0, .L002B08AC
    /* B133C 002B073C 00162202 */   srl       $a0, $s6, 8
    /* B1340 002B0740 0C0AB96B */  jal        func_002AE5AC
    /* B1344 002B0744 308400FF */   andi      $a0, $a0, 0xFF
    /* B1348 002B0748 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B134C 002B074C 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1350 002B0750 14400056 */  bnez       $v0, .L002B08AC
    /* B1354 002B0754 00000000 */   nop
    /* B1358 002B0758 0C0AB96B */  jal        func_002AE5AC
    /* B135C 002B075C 32C400FF */   andi      $a0, $s6, 0xFF
    /* B1360 002B0760 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1364 002B0764 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1368 002B0768 14400050 */  bnez       $v0, .L002B08AC
    /* B136C 002B076C 00000000 */   nop
    /* B1370 002B0770 8FA80048 */  lw         $t0, 0x48($sp)
    /* B1374 002B0774 02E80018 */  mult       $s7, $t0
    /* B1378 002B0778 00008012 */  mflo       $s0
    /* B137C 002B077C 0C0AB96B */  jal        func_002AE5AC
    /* B1380 002B0780 00102602 */   srl       $a0, $s0, 24
    /* B1384 002B0784 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1388 002B0788 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B138C 002B078C 14400047 */  bnez       $v0, .L002B08AC
    /* B1390 002B0790 00102402 */   srl       $a0, $s0, 16
    /* B1394 002B0794 0C0AB96B */  jal        func_002AE5AC
    /* B1398 002B0798 308400FF */   andi      $a0, $a0, 0xFF
    /* B139C 002B079C 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B13A0 002B07A0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B13A4 002B07A4 14400041 */  bnez       $v0, .L002B08AC
    /* B13A8 002B07A8 00102202 */   srl       $a0, $s0, 8
    /* B13AC 002B07AC 0C0AB96B */  jal        func_002AE5AC
    /* B13B0 002B07B0 308400FF */   andi      $a0, $a0, 0xFF
    /* B13B4 002B07B4 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B13B8 002B07B8 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B13BC 002B07BC 1440003B */  bnez       $v0, .L002B08AC
    /* B13C0 002B07C0 00000000 */   nop
    /* B13C4 002B07C4 0C0AB96B */  jal        func_002AE5AC
    /* B13C8 002B07C8 320400FF */   andi      $a0, $s0, 0xFF
    /* B13CC 002B07CC 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B13D0 002B07D0 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B13D4 002B07D4 14400035 */  bnez       $v0, .L002B08AC
    /* B13D8 002B07D8 03C02021 */   addu      $a0, $fp, $zero
    /* B13DC 002B07DC 0C0ABAAD */  jal        func_002AEAB4
    /* B13E0 002B07E0 02002821 */   addu      $a1, $s0, $zero
  .L002B07E4:
    /* B13E4 002B07E4 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B13E8 002B07E8 AC20D3E8 */  sw         $zero, %lo(D_8014D3E8)($at)
    /* B13EC 002B07EC 0C0AB8E0 */  jal        func_002AE380
    /* B13F0 002B07F0 27A40011 */   addiu     $a0, $sp, 0x11
    /* B13F4 002B07F4 02401021 */  addu       $v0, $s2, $zero
    /* B13F8 002B07F8 18400005 */  blez       $v0, .L002B0810
    /* B13FC 002B07FC 2652FFFF */   addiu     $s2, $s2, -0x1
    /* B1400 002B0800 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1404 002B0804 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1408 002B0808 1440FFF6 */  bnez       $v0, .L002B07E4
    /* B140C 002B080C 00000000 */   nop
  .L002B0810:
    /* B1410 002B0810 3C028015 */  lui        $v0, %hi(D_8014D3E8)
    /* B1414 002B0814 8C42D3E8 */  lw         $v0, %lo(D_8014D3E8)($v0)
    /* B1418 002B0818 14400024 */  bnez       $v0, .L002B08AC
    /* B141C 002B081C 00000000 */   nop
    /* B1420 002B0820 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B1424 002B0824 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B1428 002B0828 304200FB */  andi       $v0, $v0, 0xFB
    /* B142C 002B082C 00409021 */  addu       $s2, $v0, $zero
    /* B1430 002B0830 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B1434 002B0834 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B0838:
    /* B1438 002B0838 0C0AF7A8 */  jal        osPiGetStatus
    /* B143C 002B083C 00000000 */   nop
    /* B1440 002B0840 30420003 */  andi       $v0, $v0, 0x3
    /* B1444 002B0844 1440FFFC */  bnez       $v0, .L002B0838
    /* B1448 002B0848 00009821 */   addu      $s3, $zero, $zero
    /* B144C 002B084C 24140002 */  addiu      $s4, $zero, 0x2
    /* B1450 002B0850 24104E20 */  addiu      $s0, $zero, 0x4E20
    /* B1454 002B0854 3C11800D */  lui        $s1, %hi(D_800D3650)
    /* B1458 002B0858 8E313650 */  lw         $s1, %lo(D_800D3650)($s1)
    /* B145C 002B085C 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B1460 002B0860 A4320004 */  sh         $s2, %lo(D_B2000004)($at)
  .L002B0864:
    /* B1464 002B0864 0C0AF7A8 */  jal        osPiGetStatus
    /* B1468 002B0868 00000000 */   nop
    /* B146C 002B086C 30420003 */  andi       $v0, $v0, 0x3
    /* B1470 002B0870 1440FFFC */  bnez       $v0, .L002B0864
    /* B1474 002B0874 00000000 */   nop
    /* B1478 002B0878 3C02B200 */  lui        $v0, %hi(D_B2000015)
    /* B147C 002B087C 90420015 */  lbu        $v0, %lo(D_B2000015)($v0)
    /* B1480 002B0880 00541024 */  and        $v0, $v0, $s4
    /* B1484 002B0884 10530009 */  beq        $v0, $s3, .L002B08AC
    /* B1488 002B0888 02001021 */   addu      $v0, $s0, $zero
    /* B148C 002B088C 14400003 */  bnez       $v0, .L002B089C
    /* B1490 002B0890 2610FFFF */   addiu     $s0, $s0, -0x1
    /* B1494 002B0894 2631FFFF */  addiu      $s1, $s1, -0x1
    /* B1498 002B0898 24104E20 */  addiu      $s0, $zero, 0x4E20
  .L002B089C:
    /* B149C 002B089C 1E20FFF1 */  bgtz       $s1, .L002B0864
    /* B14A0 002B08A0 24020001 */   addiu     $v0, $zero, 0x1
    /* B14A4 002B08A4 3C018015 */  lui        $at, %hi(D_8014D3E8)
    /* B14A8 002B08A8 AC22D3E8 */  sw         $v0, %lo(D_8014D3E8)($at)
  .L002B08AC:
    /* B14AC 002B08AC 3C028015 */  lui        $v0, %hi(D_8014D3E1)
    /* B14B0 002B08B0 9042D3E1 */  lbu        $v0, %lo(D_8014D3E1)($v0)
    /* B14B4 002B08B4 304200FB */  andi       $v0, $v0, 0xFB
    /* B14B8 002B08B8 00408021 */  addu       $s0, $v0, $zero
    /* B14BC 002B08BC 3C018015 */  lui        $at, %hi(D_8014D3E1)
    /* B14C0 002B08C0 A022D3E1 */  sb         $v0, %lo(D_8014D3E1)($at)
  .L002B08C4:
    /* B14C4 002B08C4 0C0AF7A8 */  jal        osPiGetStatus
    /* B14C8 002B08C8 00000000 */   nop
    /* B14CC 002B08CC 30420003 */  andi       $v0, $v0, 0x3
    /* B14D0 002B08D0 1440FFFC */  bnez       $v0, .L002B08C4
    /* B14D4 002B08D4 24030001 */   addiu     $v1, $zero, 0x1
    /* B14D8 002B08D8 8FA20048 */  lw         $v0, 0x48($sp)
    /* B14DC 002B08DC 8FBF003C */  lw         $ra, 0x3C($sp)
    /* B14E0 002B08E0 8FBE0038 */  lw         $fp, 0x38($sp)
    /* B14E4 002B08E4 8FB70034 */  lw         $s7, 0x34($sp)
    /* B14E8 002B08E8 8FB60030 */  lw         $s6, 0x30($sp)
    /* B14EC 002B08EC 8FB5002C */  lw         $s5, 0x2C($sp)
    /* B14F0 002B08F0 8FB40028 */  lw         $s4, 0x28($sp)
    /* B14F4 002B08F4 8FB30024 */  lw         $s3, 0x24($sp)
    /* B14F8 002B08F8 8FB20020 */  lw         $s2, 0x20($sp)
    /* B14FC 002B08FC 8FB1001C */  lw         $s1, 0x1C($sp)
    /* B1500 002B0900 3C01B200 */  lui        $at, %hi(D_B2000004)
    /* B1504 002B0904 A4300004 */  sh         $s0, %lo(D_B2000004)($at)
    /* B1508 002B0908 8FB00018 */  lw         $s0, 0x18($sp)
    /* B150C 002B090C 3C01800D */  lui        $at, %hi(D_800D3650)
    /* B1510 002B0910 AC233650 */  sw         $v1, %lo(D_800D3650)($at)
    /* B1514 002B0914 03E00008 */  jr         $ra
    /* B1518 002B0918 27BD0040 */   addiu     $sp, $sp, 0x40
endlabel func_002B05C8
