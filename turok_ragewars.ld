SECTIONS
{
    HIDDEN(__romPos = 0);
    header_ROM_START = __romPos;
    header_VRAM = ADDR(.header);
    .header : AT(header_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        header_DATA_START = .;
        build/asm/header.o(.data);
        header_DATA_END = .;
        header_DATA_SIZE = ABSOLUTE(header_DATA_END - header_DATA_START);
    }
    __romPos += SIZEOF(.header);
    header_ROM_END = __romPos;
    header_VRAM_END = .;

    ipl3_ROM_START = __romPos;
    ipl3_VRAM = ADDR(.ipl3);
    .ipl3 : AT(ipl3_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        ipl3_DATA_START = .;
        build/assets/ipl3.o(.data);
        ipl3_DATA_END = .;
        ipl3_DATA_SIZE = ABSOLUTE(ipl3_DATA_END - ipl3_DATA_START);
    }
    __romPos += SIZEOF(.ipl3);
    ipl3_ROM_END = __romPos;
    ipl3_VRAM_END = .;

    main_ROM_START = __romPos;
    main_VRAM = ADDR(.main);
    .main 0x200400 : AT(main_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        main_TEXT_START = .;
        build/asm/entry.o(.text);
        build/src/libultra/osSetTime.o(.text);
        build/asm/A2E64.o(.text);
        build/src/libultra/osSpTaskStartGo.o(.text);
        build/asm/BFC98.o(.text);
        build/src/libultra/osSpTaskYield.o(.text);
        build/asm/BFE2C.o(.text);
        build/src/libultra/osViBlack.o(.text);
        build/asm/BFEFC.o(.text);
        build/src/libultra/osViSetEvent.o(.text);
        build/asm/C0398.o(.text);
        build/src/libultra/osViSetMode.o(.text);
        build/asm/C03EC.o(.text);
        build/src/libultra/osViSwapBuffer.o(.text);
        build/asm/C05F4.o(.text);
        build/src/libultra/osCreateMesgQueue.o(.text);
        build/asm/C0974.o(.text);
        build/src/libultra/osJamMesg.o(.text);
        build/asm/C0F84.o(.text);
        build/src/libultra/osRecvMesg.o(.text);
        build/asm/C10B4.o(.text);
        build/src/libultra/osSendMesg.o(.text);
        build/asm/C1240.o(.text);
        build/src/libultra/__osInsertTimer.o(.text);
        build/asm/C18A4.o(.text);
        main_TEXT_END = .;
        main_TEXT_SIZE = ABSOLUTE(main_TEXT_END - main_TEXT_START);
        main_DATA_START = .;
        build/asm/entry.o(.data);
        build/src/libultra/osSetTime.o(.data);
        build/asm/A2E64.o(.data);
        build/src/libultra/osSpTaskStartGo.o(.data);
        build/asm/BFC98.o(.data);
        build/src/libultra/osSpTaskYield.o(.data);
        build/asm/BFE2C.o(.data);
        build/src/libultra/osViBlack.o(.data);
        build/asm/BFEFC.o(.data);
        build/src/libultra/osViSetEvent.o(.data);
        build/asm/C0398.o(.data);
        build/src/libultra/osViSetMode.o(.data);
        build/asm/C03EC.o(.data);
        build/src/libultra/osViSwapBuffer.o(.data);
        build/asm/C05F4.o(.data);
        build/src/libultra/osCreateMesgQueue.o(.data);
        build/asm/C0974.o(.data);
        build/src/libultra/osJamMesg.o(.data);
        build/asm/C0F84.o(.data);
        build/src/libultra/osRecvMesg.o(.data);
        build/asm/C10B4.o(.data);
        build/src/libultra/osSendMesg.o(.data);
        build/asm/C1240.o(.data);
        build/src/libultra/__osInsertTimer.o(.data);
        build/asm/C18A4.o(.data);
        build/assets/rsp_and_data_unsplit.o(.data);
        main_DATA_END = .;
        main_DATA_SIZE = ABSOLUTE(main_DATA_END - main_DATA_START);
        main_RODATA_START = .;
        build/asm/entry.o(.rodata);
        build/src/libultra/osSetTime.o(.rodata);
        build/asm/A2E64.o(.rodata);
        build/src/libultra/osSpTaskStartGo.o(.rodata);
        build/asm/BFC98.o(.rodata);
        build/src/libultra/osSpTaskYield.o(.rodata);
        build/asm/BFE2C.o(.rodata);
        build/src/libultra/osViBlack.o(.rodata);
        build/asm/BFEFC.o(.rodata);
        build/src/libultra/osViSetEvent.o(.rodata);
        build/asm/C0398.o(.rodata);
        build/src/libultra/osViSetMode.o(.rodata);
        build/asm/C03EC.o(.rodata);
        build/src/libultra/osViSwapBuffer.o(.rodata);
        build/asm/C05F4.o(.rodata);
        build/src/libultra/osCreateMesgQueue.o(.rodata);
        build/asm/C0974.o(.rodata);
        build/src/libultra/osJamMesg.o(.rodata);
        build/asm/C0F84.o(.rodata);
        build/src/libultra/osRecvMesg.o(.rodata);
        build/asm/C10B4.o(.rodata);
        build/src/libultra/osSendMesg.o(.rodata);
        build/asm/C1240.o(.rodata);
        build/src/libultra/__osInsertTimer.o(.rodata);
        build/asm/C18A4.o(.rodata);
        main_RODATA_END = .;
        main_RODATA_SIZE = ABSOLUTE(main_RODATA_END - main_RODATA_START);
    }
    main_bss_VRAM = ADDR(.main_bss);
    .main_bss (NOLOAD) : SUBALIGN(4)
    {
        FILL(0x00000000);
        main_BSS_START = .;
        build/asm/entry.o(.bss);
        build/src/libultra/osSetTime.o(.bss);
        build/asm/A2E64.o(.bss);
        build/src/libultra/osSpTaskStartGo.o(.bss);
        build/asm/BFC98.o(.bss);
        build/src/libultra/osSpTaskYield.o(.bss);
        build/asm/BFE2C.o(.bss);
        build/src/libultra/osViBlack.o(.bss);
        build/asm/BFEFC.o(.bss);
        build/src/libultra/osViSetEvent.o(.bss);
        build/asm/C0398.o(.bss);
        build/src/libultra/osViSetMode.o(.bss);
        build/asm/C03EC.o(.bss);
        build/src/libultra/osViSwapBuffer.o(.bss);
        build/asm/C05F4.o(.bss);
        build/src/libultra/osCreateMesgQueue.o(.bss);
        build/asm/C0974.o(.bss);
        build/src/libultra/osJamMesg.o(.bss);
        build/asm/C0F84.o(.bss);
        build/src/libultra/osRecvMesg.o(.bss);
        build/asm/C10B4.o(.bss);
        build/src/libultra/osSendMesg.o(.bss);
        build/asm/C1240.o(.bss);
        build/src/libultra/__osInsertTimer.o(.bss);
        build/asm/C18A4.o(.bss);
        main_BSS_END = .;
        main_BSS_SIZE = ABSOLUTE(main_BSS_END - main_BSS_START);
    }
    __romPos += SIZEOF(.main);
    __romPos = ALIGN(__romPos, 16);
    main_ROM_END = __romPos;
    main_VRAM_END = .;

    ovl_unresolved_160000_ROM_START = __romPos;
    ovl_unresolved_160000_VRAM = ADDR(.ovl_unresolved_160000);
    .ovl_unresolved_160000 : AT(ovl_unresolved_160000_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        ovl_unresolved_160000_DATA_START = .;
        build/assets/ovl_unresolved_160000.o(.data);
        ovl_unresolved_160000_DATA_END = .;
        ovl_unresolved_160000_DATA_SIZE = ABSOLUTE(ovl_unresolved_160000_DATA_END - ovl_unresolved_160000_DATA_START);
    }
    __romPos += SIZEOF(.ovl_unresolved_160000);
    ovl_unresolved_160000_ROM_END = __romPos;
    ovl_unresolved_160000_VRAM_END = .;

    ovl_a_ROM_START = __romPos;
    ovl_a_VRAM = ADDR(.ovl_a);
    .ovl_a 0x400000 : AT(ovl_a_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        ovl_a_TEXT_START = .;
        build/asm/16E000.o(.text);
        ovl_a_TEXT_END = .;
        ovl_a_TEXT_SIZE = ABSOLUTE(ovl_a_TEXT_END - ovl_a_TEXT_START);
        ovl_a_DATA_START = .;
        build/asm/16E000.o(.data);
        build/assets/ovl_a_tail.o(.data);
        ovl_a_DATA_END = .;
        ovl_a_DATA_SIZE = ABSOLUTE(ovl_a_DATA_END - ovl_a_DATA_START);
        ovl_a_RODATA_START = .;
        build/asm/16E000.o(.rodata);
        ovl_a_RODATA_END = .;
        ovl_a_RODATA_SIZE = ABSOLUTE(ovl_a_RODATA_END - ovl_a_RODATA_START);
    }
    ovl_a_bss_VRAM = ADDR(.ovl_a_bss);
    .ovl_a_bss (NOLOAD) : SUBALIGN(4)
    {
        FILL(0x00000000);
        ovl_a_BSS_START = .;
        build/asm/16E000.o(.bss);
        ovl_a_BSS_END = .;
        ovl_a_BSS_SIZE = ABSOLUTE(ovl_a_BSS_END - ovl_a_BSS_START);
    }
    __romPos += SIZEOF(.ovl_a);
    __romPos = ALIGN(__romPos, 16);
    ovl_a_ROM_END = __romPos;
    ovl_a_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
