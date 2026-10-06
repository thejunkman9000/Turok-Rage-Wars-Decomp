# Turok: Rage Wars (US v1.1) matching build.
# Run inside WSL on a Linux-side copy of the tree: `bash tools/wsl_build.sh` (see that script).
NAME     := turok_ragewars
BASEROM  := baserom.us.v11.z64
CROSS    := mips-linux-gnu-
AS       := $(CROSS)as
LD       := $(CROSS)ld
OBJCOPY  := $(CROSS)objcopy

ASFLAGS  := -EB -march=vr4300 -mabi=32 -mno-pdr -W -I include -I .

ASM_FILES := $(sort $(wildcard asm/*.s))
C_FILES   := $(sort $(shell find src -name '*.c' 2>/dev/null))
BIN_FILES := $(sort $(wildcard assets/*.bin))
HEADERS   := $(wildcard include/*.h include/*.inc)

OBJS := $(ASM_FILES:%.s=build/%.o) $(C_FILES:%.c=build/%.o) $(BIN_FILES:%.bin=build/%.o)

LDSCRIPTS := -T $(NAME).ld -T hardware_regs.ld -T extra_syms.ld -T build/symbols.ld \
             -T undefined_syms_auto.txt -T undefined_funcs_auto.txt

.PHONY: all verify clean
all: verify

# libultra sources and game sources get different post-processing (see tools/cc.sh)
cc_mode = $(if $(findstring src/libultra/,$<),lu,game)

build/asm/%.o: asm/%.s $(HEADERS)
	@mkdir -p $(dir $@)
	bash tools/as.sh $< $@

build/src/%.o: src/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	bash tools/cc.sh $(cc_mode) $< $@

build/assets/%.o: assets/%.bin
	@mkdir -p $(dir $@)
	$(LD) -r -b binary $< -o $@

# symbol_addrs.txt (splat format) -> linker PROVIDEs (only used when nothing else defines the symbol)
build/symbols.ld: symbol_addrs.txt
	@mkdir -p build
	sed -E '/^\/\//d; /^[[:space:]]*$$/d; s|^([A-Za-z0-9_]+)[[:space:]]*=[[:space:]]*(0x[0-9A-Fa-f]+);.*|PROVIDE(\1 = \2);|' $< > $@

build/$(NAME).elf: $(OBJS) build/symbols.ld $(NAME).ld
	$(LD) -nostdlib --no-check-sections $(LDSCRIPTS) -Map build/$(NAME).map -o $@

build/$(NAME).z64: build/$(NAME).elf
	$(OBJCOPY) -O binary $< $@

verify: build/$(NAME).z64
	@echo "built:    $$(stat -c %s $<) bytes"
	@echo "original: $$(stat -c %s $(BASEROM)) bytes"
	@if cmp -s $< $(BASEROM); then echo "OK: byte-identical to $(BASEROM)"; \
	else echo "MISMATCH:"; cmp $< $(BASEROM) | head -2; echo "differing bytes: $$(cmp -l $< $(BASEROM) | wc -l)"; exit 1; fi

clean:
	rm -rf build
