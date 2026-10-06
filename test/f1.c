extern unsigned func_002023C4(void);
extern void func_002023D0(unsigned);

unsigned f1(void) {
    unsigned s = func_002023C4();
    func_002023D0(s & ~1u);
    return s & 1;
}
