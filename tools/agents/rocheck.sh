cd ~/trw_s901
rsync -a /mnt/d/Projects/ws/s901/wip/ ~/trw_s901/wip/ --exclude='_v_*' >/dev/null
CC_RO_OFF=$((0xCA2B4)) CC_RO_SIZE=160 bash tools/cc.sh sn wip/c/f269_e2.c /tmp/ro_o.o 2>&1 | grep -v Warn | head -3
mips-linux-gnu-objdump -s -j .rodata /tmp/ro_o.o | head -30
mips-linux-gnu-objdump -r -j .rodata /tmp/ro_o.o | head -40
echo ROM:
python3 - <<'PY'
import struct
rom = open('baserom.us.v11.z64','rb').read()
off = 0xCA2B4
for i in range(0, 176, 4):
    print('%03x %08x' % (i, struct.unpack('>I', rom[off+i:off+i+4])[0]), end='  ')
    if (i//4) % 4 == 3: print()
PY
