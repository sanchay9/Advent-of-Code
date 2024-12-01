#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto parse_history = [](string &s) -> vector<int> {
        istringstream iss(s);
        vector<int> a;
        int n;
        while (iss >> n) a.push_back(n);
        return a;
    };

    auto prev_value = [](vector<int> &a) -> int {
        vector<int> b;
        while (!all_of(a.begin(), a.end(), [](int x) {
            return x == 0;
        })) {
            int n = static_cast<int>(a.size());
            assert(n != 1);

            b.push_back(a.front());
            vector<int> tmp;
            for (int i = 1; i < n; i++) {
                tmp.push_back(a[i] - a[i - 1]);
            }
            a = tmp;
        }
        reverse(b.begin(), b.end());
        int ans = 0;
        for (auto x : b) ans = x - ans;
        return ans;
    };

    int ans = 0;
    string line;
    while (getline(cin, line)) {
        vector<int> history = parse_history(line);
        ans += prev_value(history);
    }
    cout << ans << '\n';
}
