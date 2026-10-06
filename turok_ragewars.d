build/turok_ragewars.elf: \
    build/asm/header.o \
    build/assets/ipl3.o \
    build/asm/entry.o \
    build/assets/rsp_and_data_unsplit.o \
    build/asm/160000.o \
    build/asm/16E000.o \
    build/assets/ovl_a_tail.o
build/asm/header.o:
build/assets/ipl3.o:
build/asm/entry.o:
build/assets/rsp_and_data_unsplit.o:
build/asm/160000.o:
build/asm/16E000.o:
build/assets/ovl_a_tail.o:
-include build/asm/header.d build/assets/ipl3.d build/asm/entry.d build/assets/rsp_and_data_unsplit.d build/asm/160000.d build/asm/16E000.d build/assets/ovl_a_tail.d
