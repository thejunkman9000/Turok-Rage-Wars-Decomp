.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* assembly kept as it is in this release, ROM 0xBD36C-0xBD380 (VRAM 0x002BC76C) */
.globl __osCleanupThread
__osCleanupThread:
    /* BD36C 002BC76C 0C0AF388 */  jal        osDestroyThread
    /* BD370 002BC770 00002021 */  addu      $a0, $zero, $zero
    /* BD374 002BC774 3C05A460 */  lui        $a1, (0xA4600000 >> 16)
    /* BD378 002BC778 3C038015 */  lui        $v1, %hi(__osDiskHandle)
    /* BD37C 002BC77C 8C6387B4 */  lw         $v1, %lo(__osDiskHandle)($v1)
