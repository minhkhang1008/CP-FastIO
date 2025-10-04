# CP FastIO

Ultra-fast input/output template for Competitive Programming.  
Uses `fread`/`fwrite` with buffered output.

## Usage

- Paste `FASTIO.CPP` at the top of your solution (before `main`).
- Add `FAST_IO;` at the start of `main()`.
- Use `readInt()`, `readLL()`, `writeLL()`, and `writeChar()` instead of `cin/cout`.

---

**Input**:
```
5
1 2 3 4 5

````

**Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;

// paste FASTIO.CPP here

signed main() {
    FAST_IO;

    int n = readLL();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += readLL();
    }
    writeLL(sum);
}
````

**Output**:

```
15
```

---

## Notes

* Default `#define int long long`. Remove if you need 32-bit.
* Do not mix with `cin/cout` unless necessary.
* Only integers are supported by default
