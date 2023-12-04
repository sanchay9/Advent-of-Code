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

    string a, b, c;

    int ans = 0;
    while (cin >> a >> b >> c) {
        map<char, bool> mp1, mp2, mp3;

        for (auto x : a) mp1[x] = true;
        for (auto x : b) mp2[x] = true;
        for (auto x : c) mp3[x] = true;

        for (char i = 'a'; i <= 'z'; i++) {
            if (mp1[i] && mp2[i] && mp3[i]) {
                if (i >= 'a' && i <= 'z') ans += i - 'a' + 1;
                if (i >= 'A' && i <= 'Z') ans += i - 'A' + 27;
            }
        }
        for (char i = 'A'; i <= 'Z'; i++) {
            if (mp1[i] && mp2[i] && mp3[i]) {
                if (i >= 'a' && i <= 'z') ans += i - 'a' + 1;
                if (i >= 'A' && i <= 'Z') ans += i - 'A' + 27;
            }
        }
    }

    cout << ans << '\n';
}
