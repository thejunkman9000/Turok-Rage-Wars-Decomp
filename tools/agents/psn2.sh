#!/usr/bin/env bash
# psn2.sh <fn> <file.c rel ~/trw_s704> [xflags] : like psn.sh but target built by tools/mktgt.py (handles alabel functions)
fn=$1; cf=$2; xf=${3:-}
SRC=/mnt/d/Projects/ws/s704; R=$HOME/trw_s704; d=$HOME/perm/s704_$fn
rsync -a $SRC/include/ $R/include/; rsync -a --exclude='_v_*' $SRC/wip/ $R/wip/; rsync -a $SRC/tools/ $R/tools/
rm -rf "$d"; mkdir -p "$d"; cd "$R"
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their "$cf" > "$d/pre.c"
python3 tools/perm_strip.py "$d/pre.c" "$fn" | grep -v "^__asm__" > "$d/base.c"
(cd $SRC && python3 tools/mktgt.py $fn) > "$d/target.s"
bash tools/as.sh "$d/target.s" "$d/target.o"
cat > "$d/compile.sh" <<EOT
#!/usr/bin/env bash
export PERM_XF="$xf"
exec bash $R/tools/permcc_sn.sh "\$@"
EOT
chmod +x "$d/compile.sh"
printf 'compiler_type = "gcc"\nfunc_name = "%s"\n' "$fn" > "$d/settings.toml"
"$d/compile.sh" "$d/base.c" -o "$d/base.o" && echo "base compiles: $d"
