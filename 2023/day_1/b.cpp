#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> mp = {
        {"one",   1},
        {"two",   2},
        {"three", 3},
        {"four",  4},
        {"five",  5},
        {"six",   6},
        {"seven", 7},
        {"eight", 8},
        {"nine",  9}
    };

    auto isLetter = [&](string& line, int idx) -> int {
        for (auto [k, v] : mp) {
            if (k == line.substr(idx, k.size()) || line[idx] - '0' == v) {
                return v;
            }
        }
        return -1;
    };

    int ans = 0;
    string line;
    while (getline(cin, line)) {
        int first = -1, last = -1;
        for (int i = 0; i < static_cast<int>(line.size()); i++) {
            if (isLetter(line, i) != -1) {
                if (first == -1) first = isLetter(line, i);
                last = isLetter(line, i);
            }
        }
        assert(first != -1);
        ans += first * 10 + last;
    }
    cout << ans << '\n';
}
