.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* hand-written assembly, ROM 0xB3D00-0xB3F60 (VRAM 0x002B3100) */
glabel __alCSeqGetTrackEvent
    /* B3D00 002B3100 27BDFFD8 */  addiu      $sp, $sp, -0x28
    /* B3D04 002B3104 AFB10014 */  sw         $s1, 0x14($sp)
    /* B3D08 002B3108 00808821 */  addu       $s1, $a0, $zero
    /* B3D0C 002B310C AFB3001C */  sw         $s3, 0x1C($sp)
    /* B3D10 002B3110 00A09821 */  addu       $s3, $a1, $zero
    /* B3D14 002B3114 AFB20018 */  sw         $s2, 0x18($sp)
    /* B3D18 002B3118 00C09021 */  addu       $s2, $a2, $zero
    /* B3D1C 002B311C AFBF0024 */  sw         $ra, 0x24($sp)
    /* B3D20 002B3120 AFB40020 */  sw         $s4, 0x20($sp)
    /* B3D24 002B3124 0C0ACD74 */  jal        __getTrackByte
    /* B3D28 002B3128 AFB00010 */   sw        $s0, 0x10($sp)
    /* B3D2C 002B312C 00408021 */  addu       $s0, $v0, $zero
    /* B3D30 002B3130 321400FF */  andi       $s4, $s0, 0xFF
    /* B3D34 002B3134 240200FF */  addiu      $v0, $zero, 0xFF
    /* B3D38 002B3138 1682005D */  bne        $s4, $v0, .L002B32B0
    /* B3D3C 002B313C 24020001 */   addiu     $v0, $zero, 0x1
    /* B3D40 002B3140 02202021 */  addu       $a0, $s1, $zero
    /* B3D44 002B3144 0C0ACD74 */  jal        __getTrackByte
    /* B3D48 002B3148 02602821 */   addu      $a1, $s3, $zero
    /* B3D4C 002B314C 00403021 */  addu       $a2, $v0, $zero
    /* B3D50 002B3150 30C300FF */  andi       $v1, $a2, 0xFF
    /* B3D54 002B3154 24020051 */  addiu      $v0, $zero, 0x51
    /* B3D58 002B3158 14620014 */  bne        $v1, $v0, .L002B31AC
    /* B3D5C 002B315C 2402002F */   addiu     $v0, $zero, 0x2F
    /* B3D60 002B3160 02202021 */  addu       $a0, $s1, $zero
    /* B3D64 002B3164 02602821 */  addu       $a1, $s3, $zero
    /* B3D68 002B3168 24020003 */  addiu      $v0, $zero, 0x3
    /* B3D6C 002B316C A6420000 */  sh         $v0, 0x0($s2)
    /* B3D70 002B3170 A2500008 */  sb         $s0, 0x8($s2)
    /* B3D74 002B3174 0C0ACD74 */  jal        __getTrackByte
    /* B3D78 002B3178 A2460009 */   sb        $a2, 0x9($s2)
    /* B3D7C 002B317C 02202021 */  addu       $a0, $s1, $zero
    /* B3D80 002B3180 02602821 */  addu       $a1, $s3, $zero
    /* B3D84 002B3184 0C0ACD74 */  jal        __getTrackByte
    /* B3D88 002B3188 A242000B */   sb        $v0, 0xB($s2)
    /* B3D8C 002B318C 02202021 */  addu       $a0, $s1, $zero
    /* B3D90 002B3190 02602821 */  addu       $a1, $s3, $zero
    /* B3D94 002B3194 0C0ACD74 */  jal        __getTrackByte
    /* B3D98 002B3198 A242000C */   sb        $v0, 0xC($s2)
    /* B3D9C 002B319C A242000D */  sb         $v0, 0xD($s2)
    /* B3DA0 002B31A0 02331021 */  addu       $v0, $s1, $s3
    /* B3DA4 002B31A4 080ACCCF */  j          .L002B333C
    /* B3DA8 002B31A8 A04000A8 */   sb        $zero, 0xA8($v0)
  .L002B31AC:
    /* B3DAC 002B31AC 1462000D */  bne        $v1, $v0, .L002B31E4
    /* B3DB0 002B31B0 2402002E */   addiu     $v0, $zero, 0x2E
    /* B3DB4 002B31B4 24020001 */  addiu      $v0, $zero, 0x1
    /* B3DB8 002B31B8 8E230004 */  lw         $v1, 0x4($s1)
    /* B3DBC 002B31BC 02621004 */  sllv       $v0, $v0, $s3
    /* B3DC0 002B31C0 00621826 */  xor        $v1, $v1, $v0
    /* B3DC4 002B31C4 10600004 */  beqz       $v1, .L002B31D8
    /* B3DC8 002B31C8 AE230004 */   sw        $v1, 0x4($s1)
    /* B3DCC 002B31CC 24020012 */  addiu      $v0, $zero, 0x12
    /* B3DD0 002B31D0 080ACCCF */  j          .L002B333C
    /* B3DD4 002B31D4 A6420000 */   sh        $v0, 0x0($s2)
  .L002B31D8:
    /* B3DD8 002B31D8 24020004 */  addiu      $v0, $zero, 0x4
    /* B3DDC 002B31DC 080ACCCF */  j          .L002B333C
    /* B3DE0 002B31E0 A6420000 */   sh        $v0, 0x0($s2)
  .L002B31E4:
    /* B3DE4 002B31E4 1462000C */  bne        $v1, $v0, .L002B3218
    /* B3DE8 002B31E8 2402002D */   addiu     $v0, $zero, 0x2D
    /* B3DEC 002B31EC 02202021 */  addu       $a0, $s1, $zero
    /* B3DF0 002B31F0 0C0ACD74 */  jal        __getTrackByte
    /* B3DF4 002B31F4 02602821 */   addu      $a1, $s3, $zero
    /* B3DF8 002B31F8 02202021 */  addu       $a0, $s1, $zero
    /* B3DFC 002B31FC 0C0ACD74 */  jal        __getTrackByte
    /* B3E00 002B3200 02602821 */   addu      $a1, $s3, $zero
    /* B3E04 002B3204 02331021 */  addu       $v0, $s1, $s3
    /* B3E08 002B3208 A04000A8 */  sb         $zero, 0xA8($v0)
    /* B3E0C 002B320C 24020013 */  addiu      $v0, $zero, 0x13
    /* B3E10 002B3210 080ACCCF */  j          .L002B333C
    /* B3E14 002B3214 A6420000 */   sh        $v0, 0x0($s2)
  .L002B3218:
    /* B3E18 002B3218 14620048 */  bne        $v1, $v0, .L002B333C
    /* B3E1C 002B321C 00131080 */   sll       $v0, $s3, 2
    /* B3E20 002B3220 02223821 */  addu       $a3, $s1, $v0
    /* B3E24 002B3224 8CE60018 */  lw         $a2, 0x18($a3)
    /* B3E28 002B3228 90C40000 */  lbu        $a0, 0x0($a2)
    /* B3E2C 002B322C 24C60001 */  addiu      $a2, $a2, 0x1
    /* B3E30 002B3230 90C20000 */  lbu        $v0, 0x0($a2)
    /* B3E34 002B3234 304300FF */  andi       $v1, $v0, 0xFF
    /* B3E38 002B3238 14600004 */  bnez       $v1, .L002B324C
    /* B3E3C 002B323C 00000000 */   nop
    /* B3E40 002B3240 24C20005 */  addiu      $v0, $a2, 0x5
    /* B3E44 002B3244 080ACCA6 */  j          .L002B3298
    /* B3E48 002B3248 A0C40000 */   sb        $a0, 0x0($a2)
  .L002B324C:
    /* B3E4C 002B324C 10740002 */  beq        $v1, $s4, .L002B3258
    /* B3E50 002B3250 2442FFFF */   addiu     $v0, $v0, -0x1
    /* B3E54 002B3254 A0C20000 */  sb         $v0, 0x0($a2)
  .L002B3258:
    /* B3E58 002B3258 24C60001 */  addiu      $a2, $a2, 0x1
    /* B3E5C 002B325C 90C20000 */  lbu        $v0, 0x0($a2)
    /* B3E60 002B3260 24C60001 */  addiu      $a2, $a2, 0x1
    /* B3E64 002B3264 90C30000 */  lbu        $v1, 0x0($a2)
    /* B3E68 002B3268 24C60001 */  addiu      $a2, $a2, 0x1
    /* B3E6C 002B326C 90C40000 */  lbu        $a0, 0x0($a2)
    /* B3E70 002B3270 24C60001 */  addiu      $a2, $a2, 0x1
    /* B3E74 002B3274 90C50000 */  lbu        $a1, 0x0($a2)
    /* B3E78 002B3278 24C60001 */  addiu      $a2, $a2, 0x1
    /* B3E7C 002B327C 00021600 */  sll        $v0, $v0, 24
    /* B3E80 002B3280 00031C00 */  sll        $v1, $v1, 16
    /* B3E84 002B3284 00431021 */  addu       $v0, $v0, $v1
    /* B3E88 002B3288 00042200 */  sll        $a0, $a0, 8
    /* B3E8C 002B328C 00441021 */  addu       $v0, $v0, $a0
    /* B3E90 002B3290 00451021 */  addu       $v0, $v0, $a1
    /* B3E94 002B3294 00C21023 */  subu       $v0, $a2, $v0
  .L002B3298:
    /* B3E98 002B3298 ACE20018 */  sw         $v0, 0x18($a3)
    /* B3E9C 002B329C 02331021 */  addu       $v0, $s1, $s3
    /* B3EA0 002B32A0 A04000A8 */  sb         $zero, 0xA8($v0)
    /* B3EA4 002B32A4 24020014 */  addiu      $v0, $zero, 0x14
    /* B3EA8 002B32A8 080ACCCF */  j          .L002B333C
    /* B3EAC 002B32AC A6420000 */   sh        $v0, 0x0($s2)
  .L002B32B0:
    /* B3EB0 002B32B0 A6420000 */  sh         $v0, 0x0($s2)
    /* B3EB4 002B32B4 32020080 */  andi       $v0, $s0, 0x80
    /* B3EB8 002B32B8 10400008 */  beqz       $v0, .L002B32DC
    /* B3EBC 002B32BC 02202021 */   addu      $a0, $s1, $zero
    /* B3EC0 002B32C0 02602821 */  addu       $a1, $s3, $zero
    /* B3EC4 002B32C4 0C0ACD74 */  jal        __getTrackByte
    /* B3EC8 002B32C8 A2500008 */   sb        $s0, 0x8($s2)
    /* B3ECC 002B32CC A2420009 */  sb         $v0, 0x9($s2)
    /* B3ED0 002B32D0 02331021 */  addu       $v0, $s1, $s3
    /* B3ED4 002B32D4 080ACCBB */  j          .L002B32EC
    /* B3ED8 002B32D8 A05000A8 */   sb        $s0, 0xA8($v0)
  .L002B32DC:
    /* B3EDC 002B32DC 02331021 */  addu       $v0, $s1, $s3
    /* B3EE0 002B32E0 904200A8 */  lbu        $v0, 0xA8($v0)
    /* B3EE4 002B32E4 A2500009 */  sb         $s0, 0x9($s2)
    /* B3EE8 002B32E8 A2420008 */  sb         $v0, 0x8($s2)
  .L002B32EC:
    /* B3EEC 002B32EC 92420008 */  lbu        $v0, 0x8($s2)
    /* B3EF0 002B32F0 304300F0 */  andi       $v1, $v0, 0xF0
    /* B3EF4 002B32F4 240200C0 */  addiu      $v0, $zero, 0xC0
    /* B3EF8 002B32F8 1062000F */  beq        $v1, $v0, .L002B3338
    /* B3EFC 002B32FC 240200D0 */   addiu     $v0, $zero, 0xD0
    /* B3F00 002B3300 1062000D */  beq        $v1, $v0, .L002B3338
    /* B3F04 002B3304 02202021 */   addu      $a0, $s1, $zero
    /* B3F08 002B3308 0C0ACD74 */  jal        __getTrackByte
    /* B3F0C 002B330C 02602821 */   addu      $a1, $s3, $zero
    /* B3F10 002B3310 92430008 */  lbu        $v1, 0x8($s2)
    /* B3F14 002B3314 A242000A */  sb         $v0, 0xA($s2)
    /* B3F18 002B3318 24020090 */  addiu      $v0, $zero, 0x90
    /* B3F1C 002B331C 306300F0 */  andi       $v1, $v1, 0xF0
    /* B3F20 002B3320 14620006 */  bne        $v1, $v0, .L002B333C
    /* B3F24 002B3324 02202021 */   addu      $a0, $s1, $zero
    /* B3F28 002B3328 0C0ACEBF */  jal        __readVarLen
    /* B3F2C 002B332C 02602821 */   addu      $a1, $s3, $zero
    /* B3F30 002B3330 080ACCCF */  j          .L002B333C
    /* B3F34 002B3334 AE42000C */   sw        $v0, 0xC($s2)
  .L002B3338:
    /* B3F38 002B3338 A240000A */  sb         $zero, 0xA($s2)
  .L002B333C:
    /* B3F3C 002B333C 8FBF0024 */  lw         $ra, 0x24($sp)
    /* B3F40 002B3340 8FB40020 */  lw         $s4, 0x20($sp)
    /* B3F44 002B3344 8FB3001C */  lw         $s3, 0x1C($sp)
    /* B3F48 002B3348 8FB20018 */  lw         $s2, 0x18($sp)
    /* B3F4C 002B334C 8FB10014 */  lw         $s1, 0x14($sp)
    /* B3F50 002B3350 8FB00010 */  lw         $s0, 0x10($sp)
    /* B3F54 002B3354 24020001 */  addiu      $v0, $zero, 0x1
    /* B3F58 002B3358 03E00008 */  jr         $ra
    /* B3F5C 002B335C 27BD0028 */   addiu     $sp, $sp, 0x28
endlabel __alCSeqGetTrackEvent
