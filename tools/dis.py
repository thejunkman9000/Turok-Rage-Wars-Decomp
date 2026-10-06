import sys, struct, rabbitizer
rom = open('baserom.us.v11.z64','rb').read()
def dis(off, n, vram=None):
    for i in range(n):
        w = struct.unpack_from('>I', rom, off+4*i)[0]
        v = (vram + 4*i) if vram is not None else off+4*i
        print(f"{v:08X}  {w:08X}  {rabbitizer.Instruction(w, v).disassemble()}")
if __name__ == '__main__':
    off = int(sys.argv[1], 0); n = int(sys.argv[2], 0)
    vram = int(sys.argv[3], 0) if len(sys.argv) > 3 else None
    dis(off, n, vram)
