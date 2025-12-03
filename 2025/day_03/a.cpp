#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int BATTERIES_REQUIRED = 2;
    int64_t ans = 0;
    string line;
    while (getline(cin, line)) {
        string mx;
        int N = BATTERIES_REQUIRED, lo = 0, hi = line.size() - N + 1;
        while (N--) {
            auto it = max_element(line.begin() + lo, line.begin() + hi);
            mx.push_back(*it);
            lo = it - line.begin() + 1;
            ++hi;
        }
        ans += stol(mx);
    }
    cout << ans << '\n';
}
