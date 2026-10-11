typedef long long s64;
extern s64 osClockRate;
s64 osGetTime(void);
double func_00414430(void) {
    return (double)osGetTime() / (double)osClockRate;
}
