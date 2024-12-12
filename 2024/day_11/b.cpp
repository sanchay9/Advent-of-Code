#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int times = 75;

    map<int, int> mp;
    int stone;
    while (cin >> stone) {
        mp[stone] = 1;
    }

    for (int i = 0; i < times; i++) {
        map<int, int> tmp;
        for (auto &[k, v] : mp) {
            string s = to_string(k);
            int sz = static_cast<int>(s.size());

            if (k == 0) {
                tmp[k + 1] += v;
            } else if (sz & 1) {
                tmp[k * 2024] += v;
            } else {
                tmp[stoll(s.substr(0, sz / 2))] += v;
                tmp[stoll(s.substr(sz / 2))] += v;
            }
        }
        mp = tmp;
    }

    int ans = 0;
    for (auto x : mp) {
        ans += x.second;
    }
    cout << ans << '\n';
}
