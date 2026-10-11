/* Second function of the ROM span of func_00438A08 (hidden in the manifest unit pad_1A6BA4): called through
   `func_438BA4()` by func_00286254 for game modes 1, 3 and 4 (after the 0x34 sound): re-runs the game
   initialisation and pushes menu screen 0x12.  Upstream: func_804389C4_de. */
void func_002A3224(void);
void func_002A338C(void);
void func_00299368(int screen);

void func_00438BA4(void) {
    func_002A3224();
    func_002A338C();
    func_00299368(0x12);
}
