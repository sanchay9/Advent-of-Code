#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int n = 101, m = 103;

    vector<int> cnt(5);

    auto quadrant = [&](int x, int y) {
        if (x < n / 2 && y < m / 2) {
            return 1;
        }
        if (x < n / 2 && y > m / 2) {
            return 2;
        }
        if (x > n / 2 && y < m / 2) {
            return 3;
        }
        if (x > n / 2 && y > m / 2) {
            return 4;
        }
        return 0;
    };

    string p, v;
    while (cin >> p >> v) {
        int idxequals = static_cast<int>(p.find('='));
        int idxcomma = static_cast<int>(p.find(','));
        int sx = stoll(p.substr(idxequals + 1, idxcomma - idxequals - 1));
        int sy = stoll(p.substr(idxcomma + 1));

        idxequals = static_cast<int>(v.find('='));
        idxcomma = static_cast<int>(v.find(','));
        int vx = stoll(v.substr(idxequals + 1, idxcomma - idxequals - 1));
        int vy = stoll(v.substr(idxcomma + 1));

        sx = (sx + ((vx + n) * 100)) % n;
        sy = (sy + ((vy + m) * 100)) % m;

        ++cnt[quadrant(sx, sy)];
    }

    cout << cnt[1] * cnt[2] * cnt[3] * cnt[4] << '\n';
}
