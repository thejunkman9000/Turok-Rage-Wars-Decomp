import struct, rabbitizer
rom = open('baserom.us.v11.z64','rb').read()
def last_ret(lo, hi):
    last = None
    for off in range(lo, hi, 4):
        if struct.unpack_from('>I', rom, off)[0] == 0x03E00008: last = off
    return last
for lo, hi, name in [(0x1000,0x101000,'main'),(0x160000,0x1C8000,'overlay')]:
    l = last_ret(lo, hi); print(name, f"last jr ra at ROM 0x{l:X}")
    for i in range(-4, 24):
        o = l + 4*i; w = struct.unpack_from('>I', rom, o)[0]
        print(f"   {o:06X}  {w:08X}  {rabbitizer.Instruction(w, o).disassemble()}")
