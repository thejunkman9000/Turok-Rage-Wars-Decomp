#!/usr/bin/env bash
# usage (WSL, from workspace root): bash tools/perm_sn.sh <fn> <cfile rel. to ~/trw_s705> <rom hex> <ninsns> [sn flags e.g. -fno-builtin] ; env PS_272=1 for 2.7.2
set -euo pipefail
fn=$1; cfile=$2; rom=$3; n=$4; shift 4
R=$HOME/trw_s705; d=$HOME/perm/s705_$fn
rm -rf "$d"; mkdir -p "$d"
cd "$R"
if [ $(( rom )) -ge $(( 0x16E000 )) ]; then vram=$(printf '%X' $(( rom - 0x16E000 + 0x400000 ))); else vram=$(printf '%X' $(( rom + 0x1FF400 + 0x80000000 ))); fi
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their "$cfile" > "$d/pre.c"
python3 tools/perm_strip.py "$d/pre.c" "$fn" > "$d/base.c"
python3 - "$R/baserom.us.v11.z64" $rom $n "$d/target.s" <<'P'
import sys,struct
rom=open(sys.argv[1],'rb').read(); off=int(sys.argv[2],16); n=int(sys.argv[3])
with open(sys.argv[4],'w') as f:
    f.write('.set noreorder\n.set noat\n.text\n.globl tgt\ntgt:\n')
    for i in range(n): f.write('.word 0x%08X\n'%struct.unpack_from('>I',rom,off+4*i)[0])
P
mips-linux-gnu-as -EB -march=vr4300 -mabi=32 -o "$d/t.o" "$d/target.s"
mips-linux-gnu-ld -EB -Ttext=0x$vram -e 0 -o "$d/target.o" "$d/t.o"
cat > "$d/compile.sh" <<EOF
#!/usr/bin/env bash
export PS_VRAM=$vram PS_FLAGS="$*" PS_272=${PS_272:-0}
exec bash $R/tools/permsn_cc.sh "\$@"
EOF
chmod +x "$d/compile.sh"
printf 'compiler_type = "gcc"\nfunc_name = "%s"\n' "$fn" > "$d/settings.toml"
"$d/compile.sh" "$d/base.c" -o "$d/base.o" && echo "base compiles: $d"
