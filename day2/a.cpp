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
        ans += b - 'X' + 1;

        if (b - 'X' == a - 'A') {
            ans += 3;
        }

        if ((b == 'X' && a == 'C') || (b == 'Y' && a == 'A') || (b == 'Z' && a == 'B')) {
            ans += 6;
        }
    }

    cout << ans << '\n';
}
