#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;
    string line;
    while (getline(cin, line)) {
        int first = -1, last = -1;
        for (auto x : line) {
            if (x >= '0' && x <= '9') {
                if (first == -1) first = x - '0';
                last = x - '0';
            }
        }
        assert(first != -1);
        ans += first * 10 + last;
    }
    cout << ans << '\n';
}
