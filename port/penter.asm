; /Gh hook: records the address of every instrumented function entry (ring buffer printed on crashes)
.386
.model flat
EXTERN _port_trace_enter:PROC
PUBLIC __penter
.code
__penter PROC
    pushad
    mov eax, [esp+32]
    push eax
    call _port_trace_enter
    add esp, 4
    popad
    ret
__penter ENDP
END
