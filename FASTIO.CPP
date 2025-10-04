#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO atexit(flushOut);
static const size_t IN_BUF_SIZE = 1 << 20;
static unsigned char inBuf[IN_BUF_SIZE];
static unsigned char* inPtr = inBuf;
static unsigned char* inEnd = inBuf;

inline void refillIn() {
    size_t n = fread(inBuf, 1, IN_BUF_SIZE, stdin);
    inPtr = inBuf;
    inEnd = inBuf + n;
    if (n == 0) inEnd = 0;
}

inline unsigned char nextChar() {
    if (inPtr >= inEnd) refillIn();
    return (inPtr < inEnd) ? *inPtr++ : 0;
}

inline bool isSpace(unsigned char c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

inline long long readLL() {
    unsigned char c;
    do { c = nextChar(); } while (c && isSpace(c));
    int neg = 0;
    if (c == '-') { neg = 1; c = nextChar(); }
    long long x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = nextChar();
    }
    return neg ? -x : x;
}

inline int readInt() { return (int)readLL(); }

static const size_t OUT_BUF_SIZE = 1 << 20;
static char outBuf[OUT_BUF_SIZE];
static size_t outPos = 0;

inline void flushOut() {
    if (outPos) {
        fwrite(outBuf, 1, outPos, stdout);
        outPos = 0;
    }
}

inline void writeChar(char c) {
    if (outPos >= OUT_BUF_SIZE) flushOut();
    outBuf[outPos++] = c;
}

inline void writeLL(long long x) {
    if (x == 0) { writeChar('0'); return; }
    if (x < 0) { writeChar('-'); x = -x; }
    char s[24]; int n = 0;
    while (x) { s[n++] = char('0' + (x % 10)); x /= 10; }
    while (n--) writeChar(s[n]);
}

signed main() {
    FAST_IO;
}
