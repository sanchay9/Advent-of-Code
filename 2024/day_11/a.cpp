#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int times = 25;

    int ans = 0;
    function<void(int, int)> f = [&](int stone, int blinks) -> void {
        if (blinks == 0) {
            ++ans;
            return;
        }

        string s = to_string(stone);
        int sz = static_cast<int>(s.size());

        if (stone == 0) {
            f(1, blinks - 1);
        } else if (s.size() & 1) {
            f(stone * 2024, blinks - 1);
        } else {
            f(stoll(s.substr(0, sz / 2)), blinks - 1);
            f(stoll(s.substr(sz / 2)), blinks - 1);
        }
    };

    int stone;
    while (cin >> stone) {
        f(stone, times);
    }

    cout << ans << '\n';
}
