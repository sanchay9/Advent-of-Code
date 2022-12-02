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

    string line;

    int ans = 0, cur = 0;
    while (getline(cin, line)) {
        if (line.size()) {
            cur += stoll(line);
        } else {
            ans = max(ans, cur);
            cur = 0;
        }
    }

    cout << ans << '\n';
}
