; Symbols the clang-built game objects reference by their *undecorated* names (C asm labels in the sources):
; sqrtf (the C library function, cdecl, float on the x87 stack) and the data alias D_80121990
.386
.model flat
PUBLIC _sqrtf
PUBLIC sqrtf
PUBLIC D_80121990
D_80121990 EQU 80121990h
.code
_sqrtf PROC
    fld dword ptr [esp+4]
    fsqrt
    ret
_sqrtf ENDP
sqrtf PROC
    fld dword ptr [esp+4]
    fsqrt
    ret
sqrtf ENDP
END
