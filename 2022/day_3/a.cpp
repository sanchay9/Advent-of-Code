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
        int n = s.size();

        map<char, bool> mp;
        for (int i = 0; i < n / 2; i++) {
            mp[s[i]] = true;
        }

        for (int i = n / 2; i < n; i++) {
            if (mp[s[i]]) {
                if (s[i] >= 'a' && s[i] <= 'z') ans += s[i] - 'a' + 1;
                if (s[i] >= 'A' && s[i] <= 'Z') ans += s[i] - 'A' + 27;
                break;
            }
        }
    }

    cout << ans << '\n';
}
