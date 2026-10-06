#!/usr/bin/env bash
# Set up a decomp-permuter directory (in WSL) for one function.
# usage (from the project root in WSL, after tools/wsl_sync.sh):
#   bash tools/perm_setup.sh <function> <src/libultra/file.c> <src/libultra/file.s> [gcc flags...]
# The .s is the target (the hand-written asm of the function, e.g. src/libultra/func_002C2A64.s); trailing
# `linker padding` words are dropped.  Then run:  cd ~/permuter && python3 permuter.py ~/perm/<function> -j 8
set -euo pipefail
fn=$1; cfile=$2; sfile=$3; shift 3
R=$HOME/trw
d=$HOME/perm/$fn
rm -rf "$d"; mkdir -p "$d"
cd "$R"
cpp -P -undef -I include -D_LANGUAGE_C -DINCLUDE_ASM_USE_MACRO_INC=1 '-D__attribute__(x)=' "$cfile" > "$d/pre.c"
python3 tools/perm_strip.py "$d/pre.c" "$fn" | grep -v "^__asm__" > "$d/base.c"
grep -v 'linker padding' "$sfile" > "$d/target.s"
bash tools/as.sh "$d/target.s" "$d/target.o"
flags="${*:--O3 -fforce-addr -fno-builtin -mcpu=r4300}"
cat > "$d/compile.sh" <<EOF
#!/usr/bin/env bash
export PERM_FLAGS="$flags"
exec bash $R/tools/permcc.sh "\$@"
EOF
chmod +x "$d/compile.sh"
printf 'compiler_type = "gcc"\nfunc_name = "%s"\n' "$fn" > "$d/settings.toml"
echo "created $d"
"$d/compile.sh" "$d/base.c" -o "$d/base.o" && echo "base.c compiles"
