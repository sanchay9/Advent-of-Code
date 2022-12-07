#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int ans = 0;

    char a, b;
    while (cin >> a >> b) {
        if (b == 'Y') {
            ans += 3;

            ans += a - 'A' + 1;
        } else if (b == 'X') {
            if (a == 'A') ans += 3;
            if (a == 'B') ans += 1;
            if (a == 'C') ans += 2;
        } else {
            ans += 6;

            if (a == 'A') ans += 2;
            if (a == 'B') ans += 3;
            if (a == 'C') ans += 1;
        }
    }

    cout << ans << '\n';
}
