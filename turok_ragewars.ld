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
        main_TEXT_END = .;
        main_TEXT_SIZE = ABSOLUTE(main_TEXT_END - main_TEXT_START);
        main_DATA_START = .;
        build/asm/entry.o(.data);
        build/assets/rsp_and_data_unsplit.o(.data);
        main_DATA_END = .;
        main_DATA_SIZE = ABSOLUTE(main_DATA_END - main_DATA_START);
        main_RODATA_START = .;
        build/asm/entry.o(.rodata);
        main_RODATA_END = .;
        main_RODATA_SIZE = ABSOLUTE(main_RODATA_END - main_RODATA_START);
    }
    main_bss_VRAM = ADDR(.main_bss);
    .main_bss (NOLOAD) : SUBALIGN(4)
    {
        FILL(0x00000000);
        main_BSS_START = .;
        build/asm/entry.o(.bss);
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
