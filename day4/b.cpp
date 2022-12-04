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

    string s;

    int ans = 0;
    while (cin >> s) {
        string first = s.substr(0, s.find(','));
        string second = s.substr(s.find(',') + 1);

        int l1 = stoll(first.substr(0, first.find('-'))), r1 = stoll(first.substr(first.find('-') + 1));
        int l2 = stoll(second.substr(0, second.find('-'))), r2 = stoll(second.substr(second.find('-') + 1));

        if (!((r1 < l2) || (l1 > r2))) {
            ++ans;
        }
    }

    cout << ans << '\n';
}
