// Benchmark: cin/cout vs FastIO
// Author: Nguyen Hoang Minh Khang
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// ===== FastIO =====
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
// ===== End FastIO =====

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. Generate random input file
    int n = 5e6; 
    {
        ofstream fout("input.txt");
        fout << n << "\n";
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<long long> dist(-1000000, 1000000);
        for (int i = 0; i < n; i++) {
            fout << dist(rng) << " ";
        }
        fout.close();
    }

    // 2. Benchmark with cin/cout
    {
        freopen("input.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);

        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        auto start = high_resolution_clock::now();

        int n;
        cin >> n;
        long long sum = 0, x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            sum += x;
        }
        cout << sum << "\n";

        auto end = high_resolution_clock::now();
        cerr << "cin/cout: "
             << duration_cast<milliseconds>(end - start).count()
             << " ms\n";
    }

    // 3. Benchmark with FastIO
    {
        freopen("input.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);

        FAST_IO;

        auto start = high_resolution_clock::now();

        int n = readInt();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += readLL();
        }
        writeLL(sum);
        writeChar('\n');

        auto end = high_resolution_clock::now();
        cerr << "FastIO:  "
             << duration_cast<milliseconds>(end - start).count()
             << " ms\n";
    }
}
